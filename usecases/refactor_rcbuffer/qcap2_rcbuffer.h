#ifndef __QCAP2_RCBUFFER_H__
#define __QCAP2_RCBUFFER_H__

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

// ==============================================================================
// 1. Opaque Type Definition
// ==============================================================================
/**
 * @brief Opaque handle for the unified reference-counted buffer.
 */
typedef struct qcap2_rcbuffer qcap2_rcbuffer_t;

// ==============================================================================
// 2. Constants & Capabilities Enums
// ==============================================================================

/**
 * @brief Buffer Capability Flags to represent what memory features are available.
 */
typedef enum {
    QCAP2_BUFCAP_NONE           = 0,
    QCAP2_BUFCAP_SYSTEM_MEMORY  = (1 << 0), // Standard Heap/Stack memory
    QCAP2_BUFCAP_DMA_BUF        = (1 << 1), // Linux dma-buf FD available
    QCAP2_BUFCAP_PHYSICAL_ADDR  = (1 << 2), // Physical contiguous address
    QCAP2_BUFCAP_CUDA_MEMORY    = (1 << 3), // NVIDIA GPU CUDA memory
    QCAP2_BUFCAP_FFMPEG_FRAME   = (1 << 4), // Wraps an AVFrame / AVPacket
} qcap2_buffer_capability_t;

/**
 * @brief Access flags for CPU synchronization & mapping.
 */
typedef enum {
    QCAP2_ACCESS_READ       = (1 << 0),
    QCAP2_ACCESS_WRITE      = (1 << 1),
    QCAP2_ACCESS_READ_WRITE = (QCAP2_ACCESS_READ | QCAP2_ACCESS_WRITE)
} qcap2_access_flag_t;

// ==============================================================================
// 3. Lifecycle Management (Ref Counting)
// ==============================================================================

/**
 * @brief Increases the reference count of the buffer.
 */
void qcap2_rcbuffer_ref(qcap2_rcbuffer_t* pBuf);

/**
 * @brief Decreases the reference count of the buffer.
 * If the reference count drops to 0, the internal memory and resources are released.
 */
void qcap2_rcbuffer_unref(qcap2_rcbuffer_t* pBuf);

// ==============================================================================
// 4. Feature & Memory Capability Queries
// ==============================================================================

/**
 * @brief Get the bitmask of capabilities this buffer supports.
 */
uint32_t qcap2_rcbuffer_get_capabilities(const qcap2_rcbuffer_t* pBuf);

/**
 * @brief Check if a specific capability is supported.
 */
bool qcap2_rcbuffer_has_capability(const qcap2_rcbuffer_t* pBuf, qcap2_buffer_capability_t cap);

/**
 * @brief Get standard CPU-accessible data pointer if available.
 * Warning: for DMA/CUDA buffers, this might require map/unmap or sync first.
 */
void* qcap2_rcbuffer_get_data(qcap2_rcbuffer_t* pBuf);

/**
 * @brief Get total buffer size.
 */
size_t qcap2_rcbuffer_get_size(const qcap2_rcbuffer_t* pBuf);

// ==============================================================================
// 5. Backend-Specific Queries (Valid only if Capability exists)
// ==============================================================================

/**
 * @brief Gets the dma-buf file descriptor. Returns -1 if not supported.
 */
int qcap2_rcbuffer_get_dmabuf_fd(const qcap2_rcbuffer_t* pBuf);

/**
 * @brief Gets the physical address of the buffer. Returns 0 if not supported.
 */
uint64_t qcap2_rcbuffer_get_physical_address(const qcap2_rcbuffer_t* pBuf);

/**
 * @brief Gets the underlying FFmpeg AVFrame. Returns NULL if not supported.
 * (Returns void* here to keep the C header free of FFmpeg dependency if desired).
 */
void* qcap2_rcbuffer_get_avframe(const qcap2_rcbuffer_t* pBuf);

// ==============================================================================
// 6. Cache & Access Synchronization
// ==============================================================================

/**
 * @brief Prepares the buffer for CPU access.
 * Performs necessary cache invalidation or mapping from GPU/DMA memory.
 * @param flags Specifies whether the access will be READ, WRITE, or both.
 * @return 0 on success, negative error code on failure.
 */
int qcap2_rcbuffer_begin_cpu_access(qcap2_rcbuffer_t* pBuf, qcap2_access_flag_t flags);

/**
 * @brief Ends CPU access to the buffer.
 * Performs necessary cache flushes or unmapping back to GPU/DMA memory.
 * @param flags Specifies what type of access was performed (to flush if WRITTEN).
 * @return 0 on success, negative error code on failure.
 */
int qcap2_rcbuffer_end_cpu_access(qcap2_rcbuffer_t* pBuf, qcap2_access_flag_t flags);

#ifdef __cplusplus
}
#endif

#endif // __QCAP2_RCBUFFER_H__
