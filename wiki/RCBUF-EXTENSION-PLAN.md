# rcbuf 擴充性修正計畫（無 legacy 約束版）

## 1. 重新分析後的結論

此專案仍在開發階段，沒有 ABI/API legacy 需要維持，因此應把 `qcap2_rcbuffer_t` 設計成 media pipeline 的穩定 buffer 抽象，而不是維持目前「ref-counted `void*` + direct cast」模式。

針對 `qcap2_rcbuffer_lock_data()` / `qcap2_rcbuffer_unlock_data()`、`qcap2_rcbuffer_get_data()` 與 `qcap2_container_of()` 的必要性，結論如下：

| 現有機制 | 是否必要 | 修正方向 |
|---|---:|---|
| `qcap2_rcbuffer_lock_data()` / `unlock_data()` | **名稱與 raw-pointer 語意不必要**；但「access scope」必要 | 移除或不推薦 `lock_data`。改成 `qcap2_rcbuffer_begin_access()` / `qcap2_rcbuffer_end_access()`，負責 lifetime pin、map/unmap、sync、capability negotiation。 |
| `qcap2_rcbuffer_get_data()` | **不必要，且會妨礙擴充性** | 移除 public payload accessor。改用 typed media views、native handles、metadata API。 |
| `qcap2_container_of()` for rcbuf owner recovery | **不必要，且高風險** | rcbuf 建立時明確提供 `owner` / `user_data` / destroy callback，不用 embedded-member pointer + offset 回推 owner。 |

最重要的設計修正：

> `qcap2_rcbuffer_t` 不應暴露「資料其實是一個 `qcap2_av_frame_t*` 或 `qcap2_av_packet_t*`」這種假設。  
> media pipeline 應只依賴 rcbuf 的 **content type、memory type、capability、view、native handle**。

---

## 2. 為什麼不應保留 `get_data()` / direct cast

目前 pipeline 常見寫法是：

```c
PVOID data = qcap2_rcbuffer_lock_data(buf);
qcap2_av_frame_t* frame = (qcap2_av_frame_t*)data;
// use frame fields / helper functions
qcap2_rcbuffer_unlock_data(buf);
```

這個模式只適合 system-memory struct payload，對下列 buffer type 會變成錯誤抽象：

- dmabuf：payload 的本質是 fd、offset、stride、map/sync 狀態，不是單純 CPU pointer。
- CUDA device memory：payload 可能完全不能 CPU dereference。
- NvBufSurface：payload 是 native surface object，CPU access 需要 map/sync，device access 需要另一套 handle。
- V4L2 buffer slot：payload 常常是 driver queue slot，free 行為可能是 requeue，而不是 delete。

若保留 `get_data()`，component 很容易繼續寫出：

```c
qcap2_av_frame_t* f = (qcap2_av_frame_t*)qcap2_rcbuffer_get_data(buf);
```

這會把 rcbuf 的抽象固定在「某個 C struct pointer」，使 dmabuf / cuda / nvbuf 後端必須偽裝成 `qcap2_av_frame_t`，最後又回到大量 type check、side-channel getter、特殊分支。

因此無 legacy 約束下，`get_data()` 應從 public media API 移除。若內部 backend 需要 private payload，可存在於 private implementation，不應暴露給 component / user hot path。

---

## 3. 為什麼不應依賴 `container_of()`

`container_of()` 的用途是讓 free callback 從 embedded member pointer 回推 owner：

```c
struct MyFrameOwner {
	int index;
	qcap2_av_frame_t frame;
};

qcap2_rcbuffer_new(&owner->frame, on_free);

static void on_free(PVOID pData) {
	MyFrameOwner* owner = qcap2_container_of(pData, MyFrameOwner, frame);
	// cleanup owner
}
```

這種模式有幾個問題：

1. **pointer identity 變成 API contract**：rcbuf 必須永遠保存 embedded member address，不能重包裝、不能轉換 payload。
2. **owner recovery 隱含且脆弱**：只要傳錯 member、struct layout 變動、或 pData 不是該 member，就會 memory corruption。
3. **硬體 buffer 不自然**：dmabuf / CUDA / NvBufSurface 的 owner 通常是 allocator、driver slot、surface pool 或 backend object，不一定有一個可公開的 embedded `qcap2_av_frame_t` member。
4. **阻礙 C API 清晰化**：callback 應直接拿到明確的 `owner` / `user_data`，而不是靠 offset 推導。

替代設計：

```c
typedef void (*qcap2_rcbuffer_destroy_t)(void* owner, void* user_data);

typedef struct qcap2_rcbuffer_create_info_t {
	size_t cb;
	void* owner;             // explicit owner object / slot / allocation
	void* user_data;         // callback context
	qcap2_rcbuffer_destroy_t destroy;
	const qcap2_rcbuffer_ops_t* ops;
} qcap2_rcbuffer_create_info_t;
```

free/recycle 時：

```c
if (destroy) {
	destroy(owner, user_data);
}
```

這比 `container_of()` 更明確、安全，也不限制 payload representation。

> `qcap2_container_of()` 可以作為一般 utility macro 留在專案中，但不應是 rcbuf owner lifecycle 的必要機制。

---

## 4. `lock_data()` / `unlock_data()` 的重新定位

### 4.1 目前 `lock_data()` 真正提供的是 resource pin

目前 implementation 中，`lock_data()` 做了兩件事：

1. 增加 `res_count`，避免最後一個 `release()` 立刻 free/recycle resource。
2. 回傳 `pData`。

其中第 1 件事仍然重要；第 2 件事不應保留為通用 API。

在 media pipeline 中，component access buffer 時需要一個明確 scope：

- system memory：取得 CPU plane pointer。
- dmabuf：可能要 `mmap()` / sync for CPU。
- NvBufSurface：可能要 `NvBufSurfaceMap()` / `SyncForCpu()`。
- CUDA：可能要取得 device pointer / EGL frame，或拒絕 CPU access。
- V4L2：access 期間不得 requeue slot。

這不是「lock data pointer」，而是「begin an access session」。

### 4.2 建議移除 `lock_data()`，改為 begin/end access

```c
typedef enum qcap2_rcbuffer_access_flag_t {
	QCAP2_RCBUFFER_ACCESS_READ       = 1u << 0,
	QCAP2_RCBUFFER_ACCESS_WRITE      = 1u << 1,
	QCAP2_RCBUFFER_ACCESS_CPU        = 1u << 2,
	QCAP2_RCBUFFER_ACCESS_DEVICE     = 1u << 3,
	QCAP2_RCBUFFER_ACCESS_ZERO_COPY  = 1u << 4,
} qcap2_rcbuffer_access_flag_t;

typedef struct qcap2_rcbuffer_access_t {
	size_t cb;
	uint32_t requested_flags;
	uint32_t granted_flags;
	uint32_t memory_flags;
	void* backend_state;        // opaque map/sync token
} qcap2_rcbuffer_access_t;

QRESULT qcap2_rcbuffer_begin_access(
	qcap2_rcbuffer_t* buf,
	uint32_t flags,
	qcap2_rcbuffer_access_t* access);

void qcap2_rcbuffer_end_access(
	qcap2_rcbuffer_t* buf,
	qcap2_rcbuffer_access_t* access);
```

`begin_access()` 的語意：

- 成功後 resource 在 `end_access()` 前不可被 destroy/recycle。
- 根據 flags 做 map/sync/handle preparation。
- 若 backend 不支援要求能力，回傳 `QCAP_RS_ERROR_NON_SUPPORT`。
- 不直接回傳 untyped `void*`。

`end_access()` 的語意：

- 做 unmap/sync-for-device/cleanup。
- 釋放 access pin。

如此即可保留 `res_count` 的價值，但避免 `lock_data()` 暗示「一定有一個可 cast 的 data pointer」。

---

## 5. 新 rcbuf 應暴露的抽象

### 5.1 Content / memory / capability query

```c
typedef enum qcap2_rcbuffer_content_type_t {
	QCAP2_RCBUFFER_CONTENT_UNKNOWN = 0,
	QCAP2_RCBUFFER_CONTENT_RAW_BYTES,
	QCAP2_RCBUFFER_CONTENT_VIDEO_FRAME,
	QCAP2_RCBUFFER_CONTENT_AUDIO_FRAME,
	QCAP2_RCBUFFER_CONTENT_PACKET,
	QCAP2_RCBUFFER_CONTENT_CUSTOM,
} qcap2_rcbuffer_content_type_t;

typedef enum qcap2_rcbuffer_memory_type_t {
	QCAP2_RCBUFFER_MEMORY_SYSTEM       = 1u << 0,
	QCAP2_RCBUFFER_MEMORY_DMABUF       = 1u << 1,
	QCAP2_RCBUFFER_MEMORY_CUDA_DEVICE  = 1u << 2,
	QCAP2_RCBUFFER_MEMORY_CUDA_HOST    = 1u << 3,
	QCAP2_RCBUFFER_MEMORY_CUDA_MANAGED = 1u << 4,
	QCAP2_RCBUFFER_MEMORY_NVBUF        = 1u << 5,
	QCAP2_RCBUFFER_MEMORY_V4L2         = 1u << 6,
	QCAP2_RCBUFFER_MEMORY_CUSTOM       = 1u << 31,
} qcap2_rcbuffer_memory_type_t;

typedef enum qcap2_rcbuffer_capability_t {
	QCAP2_RCBUFFER_CAP_CPU_READ        = 1u << 0,
	QCAP2_RCBUFFER_CAP_CPU_WRITE       = 1u << 1,
	QCAP2_RCBUFFER_CAP_VIDEO_PLANES    = 1u << 2,
	QCAP2_RCBUFFER_CAP_PACKET_BYTES    = 1u << 3,
	QCAP2_RCBUFFER_CAP_NATIVE_HANDLE   = 1u << 4,
	QCAP2_RCBUFFER_CAP_DEVICE_SYNC     = 1u << 5,
	QCAP2_RCBUFFER_CAP_ZERO_COPY       = 1u << 6,
} qcap2_rcbuffer_capability_t;

typedef struct qcap2_rcbuffer_info_t {
	size_t cb;
	qcap2_rcbuffer_content_type_t content_type;
	uint32_t memory_flags;
	uint32_t capability_flags;
	void* owner;
} qcap2_rcbuffer_info_t;

QRESULT qcap2_rcbuffer_query(qcap2_rcbuffer_t* buf, qcap2_rcbuffer_info_t* info);
```

### 5.2 Typed media views

```c
typedef struct qcap2_rcbuffer_video_info_t {
	size_t cb;
	ULONG color_space_type;
	ULONG width;
	ULONG height;
	int field_type;
	int64_t pts;
	double sample_time;
	int plane_count;
} qcap2_rcbuffer_video_info_t;

typedef struct qcap2_rcbuffer_plane_t {
	size_t cb;
	uint8_t* data;       // valid only when CPU access was granted
	int stride;
	size_t size;
	int fd;              // valid for dmabuf-like plane, else -1
	uintptr_t offset;
	void* native_handle;
} qcap2_rcbuffer_plane_t;

typedef struct qcap2_rcbuffer_packet_info_t {
	size_t cb;
	int stream_index;
	BOOL is_keyframe;
	int64_t pts;
	int64_t dts;
	double sample_time;
	uint8_t* data;       // valid only when CPU access was granted
	int size;
} qcap2_rcbuffer_packet_info_t;

QRESULT qcap2_rcbuffer_get_video_info(qcap2_rcbuffer_t* buf, qcap2_rcbuffer_video_info_t* info);
QRESULT qcap2_rcbuffer_set_video_info(qcap2_rcbuffer_t* buf, const qcap2_rcbuffer_video_info_t* info);
QRESULT qcap2_rcbuffer_get_plane(qcap2_rcbuffer_t* buf, int plane, qcap2_rcbuffer_plane_t* out);
QRESULT qcap2_rcbuffer_get_packet_info(qcap2_rcbuffer_t* buf, qcap2_rcbuffer_packet_info_t* info);
QRESULT qcap2_rcbuffer_set_packet_info(qcap2_rcbuffer_t* buf, const qcap2_rcbuffer_packet_info_t* info);
```

### 5.3 Typed native handles

```c
typedef enum qcap2_rcbuffer_handle_type_t {
	QCAP2_RCBUFFER_HANDLE_DMABUF_FD = 1,
	QCAP2_RCBUFFER_HANDLE_CUDA_DEVICE_PTR,
	QCAP2_RCBUFFER_HANDLE_CUDA_GRAPHICS_RESOURCE,
	QCAP2_RCBUFFER_HANDLE_CUDA_EGL_FRAME,
	QCAP2_RCBUFFER_HANDLE_NVBUF_SURFACE,
	QCAP2_RCBUFFER_HANDLE_V4L2_BUFFER_INDEX,
	QCAP2_RCBUFFER_HANDLE_CUSTOM = 1000,
} qcap2_rcbuffer_handle_type_t;

typedef struct qcap2_rcbuffer_handle_t {
	size_t cb;
	qcap2_rcbuffer_handle_type_t type;
	union {
		int fd;
		int index;
		uintptr_t value;
		void* ptr;
	} u;
	size_t size;
} qcap2_rcbuffer_handle_t;

QRESULT qcap2_rcbuffer_get_handle(
	qcap2_rcbuffer_t* buf,
	qcap2_rcbuffer_handle_type_t type,
	qcap2_rcbuffer_handle_t* out);
```

---

## 6. 建議新的 construction API

取代：

```c
qcap2_rcbuffer_new(PVOID pData, qcap2_on_free_resource_t cb);
```

改為：

```c
typedef struct qcap2_rcbuffer_ops_t qcap2_rcbuffer_ops_t;

typedef void (*qcap2_rcbuffer_destroy_t)(void* owner, void* user_data);

typedef struct qcap2_rcbuffer_create_info_t {
	size_t cb;
	void* owner;
	void* user_data;
	qcap2_rcbuffer_destroy_t destroy;

	qcap2_rcbuffer_content_type_t content_type;
	uint32_t memory_flags;
	uint32_t capability_flags;

	const qcap2_rcbuffer_ops_t* ops;
} qcap2_rcbuffer_create_info_t;

struct qcap2_rcbuffer_ops_t {
	size_t cb;
	QRESULT (*begin_access)(void* owner, void* user_data, uint32_t flags, qcap2_rcbuffer_access_t* access);
	void    (*end_access)(void* owner, void* user_data, qcap2_rcbuffer_access_t* access);
	QRESULT (*query)(void* owner, void* user_data, qcap2_rcbuffer_info_t* info);
	QRESULT (*get_video_info)(void* owner, void* user_data, qcap2_rcbuffer_video_info_t* info);
	QRESULT (*set_video_info)(void* owner, void* user_data, const qcap2_rcbuffer_video_info_t* info);
	QRESULT (*get_plane)(void* owner, void* user_data, int plane, qcap2_rcbuffer_plane_t* out);
	QRESULT (*get_packet_info)(void* owner, void* user_data, qcap2_rcbuffer_packet_info_t* info);
	QRESULT (*set_packet_info)(void* owner, void* user_data, const qcap2_rcbuffer_packet_info_t* info);
	QRESULT (*get_handle)(void* owner, void* user_data, qcap2_rcbuffer_handle_type_t type, qcap2_rcbuffer_handle_t* out);
};

qcap2_rcbuffer_t* qcap2_rcbuffer_new(const qcap2_rcbuffer_create_info_t* info);
```

若仍需要方便建立 system memory frame / packet，可提供 factory：

```c
qcap2_rcbuffer_t* qcap2_rcbuffer_new_system_video_frame(const qcap2_video_frame_create_info_t* info);
qcap2_rcbuffer_t* qcap2_rcbuffer_new_system_packet(size_t capacity);
qcap2_rcbuffer_t* qcap2_rcbuffer_new_dmabuf_video_frame(const qcap2_dmabuf_frame_create_info_t* info);
qcap2_rcbuffer_t* qcap2_rcbuffer_new_cuda_video_frame(const qcap2_cuda_frame_create_info_t* info);
```

---

## 7. Pipeline 使用方式應一致

### 7.1 CPU producer fill input

```c
qcap2_rcbuffer_access_t access = { sizeof(access) };
QRESULT r = qcap2_rcbuffer_begin_access(
	buf,
	QCAP2_RCBUFFER_ACCESS_WRITE | QCAP2_RCBUFFER_ACCESS_CPU,
	&access);

if (r == QCAP_RS_SUCCESSFUL) {
	qcap2_rcbuffer_plane_t p0 = { sizeof(p0) };
	qcap2_rcbuffer_get_plane(buf, 0, &p0);
	// fill p0.data
	qcap2_rcbuffer_end_access(buf, &access);
}

qcap2_video_encoder_push(enc, buf);
qcap2_rcbuffer_release(buf);
```

### 7.2 Device producer / zero-copy path

```c
qcap2_rcbuffer_access_t access = { sizeof(access) };
QRESULT r = qcap2_rcbuffer_begin_access(
	buf,
	QCAP2_RCBUFFER_ACCESS_WRITE | QCAP2_RCBUFFER_ACCESS_DEVICE | QCAP2_RCBUFFER_ACCESS_ZERO_COPY,
	&access);

if (r == QCAP_RS_SUCCESSFUL) {
	qcap2_rcbuffer_handle_t h = { sizeof(h) };
	qcap2_rcbuffer_get_handle(buf, QCAP2_RCBUFFER_HANDLE_CUDA_DEVICE_PTR, &h);
	// launch CUDA kernel with h.u.value
	qcap2_rcbuffer_end_access(buf, &access);
}
```

### 7.3 Component processing

Component 不應 cast payload，而是：

1. `qcap2_rcbuffer_query()` 檢查 content/memory/capability。
2. `qcap2_rcbuffer_begin_access()` 要求 CPU 或 DEVICE access。
3. 使用 `get_video_info()` / `get_plane()` / `get_packet_info()` / `get_handle()`。
4. `qcap2_rcbuffer_end_access()`。
5. 既有 HPR/PPR recycle 流程不變。

---

## 8. Implementation roadmap

### Phase 1 — 破壞式重整 public API

1. 移除或不再宣告：
   - `qcap2_rcbuffer_get_data()`
   - `qcap2_rcbuffer_lock_data()`
   - `qcap2_rcbuffer_unlock_data()`
   - `qcap2_rcbuffer_new(PVOID, callback)` 舊簽名
2. 新增：
   - `qcap2_rcbuffer_new(const qcap2_rcbuffer_create_info_t*)`
   - `qcap2_rcbuffer_begin_access()` / `qcap2_rcbuffer_end_access()`
   - query/view/handle API
3. `qcap2_container_of()` 不再出現在 rcbuf lifecycle 文件或 rcbuf tests 中。

### Phase 2 — 內部 backend adapter

1. system-memory video frame backend。
2. system-memory packet backend。
3. dmabuf video frame backend。
4. CUDA / NvBufSurface backend skeleton。

### Phase 3 — Port media components

1. scaler / encoder / decoder / muxer 全部移除 direct cast。
2. CPU software components 要求 `CPU_READ` / `CPU_WRITE`。
3. hardware components 優先要求 `DEVICE` / `ZERO_COPY`，必要時 fallback 到 CPU staging。

### Phase 4 — Pool / recycle 重整

1. frame pool / packet pool 改成產生特定 backend rcbuf。
2. HPR/PPR queue 仍只傳 `qcap2_rcbuffer_t*`。
3. `release()` 不再需要知道 payload type；只觸發 backend destroy/recycle。

---

## 9. Acceptance criteria

- public media code 沒有 `(qcap2_av_frame_t*)qcap2_rcbuffer_get_data(...)` 這類 cast。
- public media code 沒有 `qcap2_container_of()` 來回推 rcbuf owner。
- 所有 buffer type 都透過同一套 push/pop/recycle 傳遞 `qcap2_rcbuffer_t*`。
- CPU access、device access、zero-copy handle 由 capability negotiation 決定。
- dmabuf / CUDA / NvBufSurface backend 不需要偽裝成 system-memory `qcap2_av_frame_t`。
- resource 不會在 active access scope 結束前被 destroy 或 requeue。
