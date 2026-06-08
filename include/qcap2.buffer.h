#ifndef __QCAP2_BUFFER_H__
#define __QCAP2_BUFFER_H__

#include "qcap2.types.h"
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

// qcap2_rcbuffer_t
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

typedef struct qcap2_rcbuffer_audio_info_t {
	size_t cb;
	ULONG channels;
	ULONG sample_fmt;
	ULONG sample_frequency;
	ULONG frame_size;
	int64_t pts;
	double sample_time;
} qcap2_rcbuffer_audio_info_t;

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
	QRESULT (*get_audio_info)(void* owner, void* user_data, qcap2_rcbuffer_audio_info_t* info);
	QRESULT (*set_audio_info)(void* owner, void* user_data, const qcap2_rcbuffer_audio_info_t* info);
};

// factory structures
typedef struct qcap2_video_frame_create_info_t {
	size_t cb;
	ULONG color_space_type;
	ULONG width;
	ULONG height;
	int align;
	int valign;
} qcap2_video_frame_create_info_t;

typedef struct qcap2_dmabuf_frame_create_info_t {
	size_t cb;
	ULONG color_space_type;
	ULONG width;
	ULONG height;
	int align;
	int valign;
	int prot;
} qcap2_dmabuf_frame_create_info_t;

typedef struct qcap2_cuda_frame_create_info_t {
	size_t cb;
	ULONG color_space_type;
	ULONG width;
	ULONG height;
} qcap2_cuda_frame_create_info_t;

qcap2_rcbuffer_t* qcap2_rcbuffer_new(const qcap2_rcbuffer_create_info_t* info);
qcap2_rcbuffer_t* qcap2_rcbuffer_new_from_av_frame(qcap2_av_frame_t* pFrame, void* owner, qcap2_rcbuffer_destroy_t destroy);
qcap2_rcbuffer_t* qcap2_rcbuffer_new_from_av_packet(qcap2_av_packet_t* pPacket, void* owner, qcap2_rcbuffer_destroy_t destroy);

void qcap2_rcbuffer_delete(qcap2_rcbuffer_t* pRCBuffer);
void qcap2_rcbuffer_add_ref(qcap2_rcbuffer_t* pRCBuffer);
void qcap2_rcbuffer_release(qcap2_rcbuffer_t* pRCBuffer);
int32_t qcap2_rcbuffer_use_count(qcap2_rcbuffer_t* pRCBuffer);
int32_t qcap2_rcbuffer_res_count(qcap2_rcbuffer_t* pRCBuffer);

QRESULT qcap2_rcbuffer_begin_access(qcap2_rcbuffer_t* buf, uint32_t flags, qcap2_rcbuffer_access_t* access);
void qcap2_rcbuffer_end_access(qcap2_rcbuffer_t* buf, qcap2_rcbuffer_access_t* access);
QRESULT qcap2_rcbuffer_query(qcap2_rcbuffer_t* buf, qcap2_rcbuffer_info_t* info);
QRESULT qcap2_rcbuffer_get_video_info(qcap2_rcbuffer_t* buf, qcap2_rcbuffer_video_info_t* info);
QRESULT qcap2_rcbuffer_set_video_info(qcap2_rcbuffer_t* buf, const qcap2_rcbuffer_video_info_t* info);
QRESULT qcap2_rcbuffer_get_plane(qcap2_rcbuffer_t* buf, int plane, qcap2_rcbuffer_plane_t* out);
QRESULT qcap2_rcbuffer_get_packet_info(qcap2_rcbuffer_t* buf, qcap2_rcbuffer_packet_info_t* info);
QRESULT qcap2_rcbuffer_set_packet_info(qcap2_rcbuffer_t* buf, const qcap2_rcbuffer_packet_info_t* info);
QRESULT qcap2_rcbuffer_get_handle(qcap2_rcbuffer_t* buf, qcap2_rcbuffer_handle_type_t type, qcap2_rcbuffer_handle_t* out);
QRESULT qcap2_rcbuffer_get_audio_info(qcap2_rcbuffer_t* buf, qcap2_rcbuffer_audio_info_t* info);
QRESULT qcap2_rcbuffer_set_audio_info(qcap2_rcbuffer_t* buf, const qcap2_rcbuffer_audio_info_t* info);

// factory functions
qcap2_rcbuffer_t* qcap2_rcbuffer_new_system_video_frame(const qcap2_video_frame_create_info_t* info);
qcap2_rcbuffer_t* qcap2_rcbuffer_new_system_packet(size_t capacity);
qcap2_rcbuffer_t* qcap2_rcbuffer_new_dmabuf_video_frame(const qcap2_dmabuf_frame_create_info_t* info);
qcap2_rcbuffer_t* qcap2_rcbuffer_new_cuda_video_frame(const qcap2_cuda_frame_create_info_t* info);





// qcap2_av_frame_t
void qcap2_av_frame_init(qcap2_av_frame_t* pFrame);
void qcap2_av_frame_set_video_property(qcap2_av_frame_t* pFrame, ULONG nColorSpaceType, ULONG nWidth, ULONG nHeight);
void qcap2_av_frame_get_video_property(qcap2_av_frame_t* pFrame, ULONG* pColorSpaceType, ULONG* pWidth, ULONG* pHeight);
void qcap2_av_frame_set_audio_property(qcap2_av_frame_t* pFrame, ULONG nChannels, ULONG nSampleFmt, ULONG nSampleFrequency, ULONG nFrameSize);
void qcap2_av_frame_get_audio_property(qcap2_av_frame_t* pFrame, ULONG* pChannels, ULONG* pSampleFmt, ULONG* pSampleFrequency, ULONG* pFrameSize);
void qcap2_av_frame_set_field_type(qcap2_av_frame_t* pFrame, int nFieldType); // refer to qcap2_field_type_t
void qcap2_av_frame_get_field_type(qcap2_av_frame_t* pFrame, int* pFieldType); // refer to qcap2_field_type_t
void qcap2_av_frame_set_sample_time(qcap2_av_frame_t* pFrame, double dSampleTime);
void qcap2_av_frame_get_sample_time(qcap2_av_frame_t* pFrame, double* pSampleTime);
void qcap2_av_frame_set_pts(qcap2_av_frame_t* pFrame, int64_t nPTS);
void qcap2_av_frame_get_pts(qcap2_av_frame_t* pFrame, int64_t* pPTS);
void qcap2_av_frame_set_pkt_pos(qcap2_av_frame_t* pFrame, int64_t nPktPos);
void qcap2_av_frame_get_pkt_pos(qcap2_av_frame_t* pFrame, int64_t* pPktPos);
void qcap2_av_frame_get_video_bits(qcap2_av_frame_t* pFrame, int64_t* pBits);
void qcap2_av_frame_get_audio_bits(qcap2_av_frame_t* pFrame, int64_t* pBits);
void qcap2_av_frame_set_buffer(qcap2_av_frame_t* pFrame, uint8_t* pBuffer, int nStride);
void qcap2_av_frame_get_buffer(qcap2_av_frame_t* pFrame, uint8_t** ppBuffer, int* pStride);
void qcap2_av_frame_set_buffer1(qcap2_av_frame_t* pFrame, uint8_t* pBuffer[4], int pStride[4]);
void qcap2_av_frame_get_buffer1(qcap2_av_frame_t* pFrame, uint8_t* pBuffer[4], int pStride[4]);
bool qcap2_av_frame_alloc_buffer(qcap2_av_frame_t* pFrame, int align, int valign);
void qcap2_av_frame_free_buffer(qcap2_av_frame_t* pFrame);
QRESULT qcap2_av_frame_copy(qcap2_av_frame_t* pSrcFrame, qcap2_av_frame_t* pDstFrame);
QRESULT qcap2_av_frame_color_range_expand(qcap2_av_frame_t* pSrcFrame, qcap2_av_frame_t* pDstFrame); // limited-range -> full-range
QRESULT qcap2_av_frame_store_picture(qcap2_av_frame_t* pFrame, const char* strFilePath);
QRESULT qcap2_av_frame_store_picture2(qcap2_av_frame_t* pFrame, const char* strFilePath, int nQuality);

// qcap2_av_packet_t
void qcap2_av_packet_init(qcap2_av_packet_t* pPacket);
void qcap2_av_packet_set_property(qcap2_av_packet_t* pPacket, int nStreamIndex, BOOL bIsKeyFrame);
void qcap2_av_packet_get_property(qcap2_av_packet_t* pPacket, int* pStreamIndex, BOOL* pIsKeyFrame);
void qcap2_av_packet_set_sample_time(qcap2_av_packet_t* pPacket, double dSampleTime);
void qcap2_av_packet_get_sample_time(qcap2_av_packet_t* pPacket, double* pSampleTime);
void qcap2_av_packet_set_pts(qcap2_av_packet_t* pPacket, int64_t nPTS);
void qcap2_av_packet_get_pts(qcap2_av_packet_t* pPacket, int64_t* pPTS);
void qcap2_av_packet_set_dts(qcap2_av_packet_t* pPacket, int64_t nDTS);
void qcap2_av_packet_get_dts(qcap2_av_packet_t* pPacket, int64_t* pDTS);
void qcap2_av_packet_set_buffer(qcap2_av_packet_t* pPacket, uint8_t* pBuffer, int nSize);
void qcap2_av_packet_get_buffer(qcap2_av_packet_t* pPacket, uint8_t** ppBuffer, int* pSize);
bool qcap2_av_packet_alloc_buffer(qcap2_av_packet_t* pPacket, int nSize);
void qcap2_av_packet_free_buffer(qcap2_av_packet_t* pPacket);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif // __QCAP2_BUFFER_H__
