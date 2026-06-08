#include "qcap2_rcbuffer.h"
#include "qcap2_rcbuffer_priv.h"

#include <iostream>
#include <unistd.h>
#include <sys/mman.h>
#include <atomic>

// Forward declaration of an AVFrame struct, simulating FFmpeg's <libavutil/frame.h>
extern "C" {
    struct AVFrame {
        uint8_t *data[8];
        int linesize[8];
        int width, height;
        // ... many other fields
    };

    // Simulate FFmpeg API calls
    void av_frame_free(AVFrame **frame) {
        if (frame && *frame) {
            std::cout << "[Mock FFmpeg] av_frame_free called.\n";
            delete *frame; // For mocking purposes
            *frame = nullptr;
        }
    }
}

namespace qcap2 {
namespace buffer {

// ==============================================================================
// Derived Backend: DmaBufBuffer
// ==============================================================================
class DmaBufBuffer : public RcBufferBase {
private:
    int m_fd;
    size_t m_size;
    void* m_mapped_addr;

public:
    DmaBufBuffer(int fd, size_t size)
        : m_fd(fd), m_size(size), m_mapped_addr(nullptr) {
        std::cout << "[DmaBufBuffer] Created with fd: " << fd << "\n";
    }

    ~DmaBufBuffer() override {
        if (m_mapped_addr && m_mapped_addr != MAP_FAILED) {
            munmap(m_mapped_addr, m_size);
        }
        if (m_fd >= 0) {
            close(m_fd);
        }
        std::cout << "[DmaBufBuffer] Destroyed fd: " << m_fd << "\n";
    }

    uint32_t get_capabilities() const override {
        return QCAP2_BUFCAP_DMA_BUF | QCAP2_BUFCAP_SYSTEM_MEMORY;
    }

    size_t get_size() const override {
        return m_size;
    }

    void* get_data() override {
        return m_mapped_addr;
    }

    int get_dmabuf_fd() const override {
        return m_fd;
    }

    int begin_cpu_access(qcap2_access_flag_t flags) override {
        // Mock sync logic: In a real scenario, this would call ioctl(fd, DMA_BUF_IOCTL_SYNC, ...)
        std::cout << "[DmaBufBuffer] begin_cpu_access (sync for CPU)\n";

        if (!m_mapped_addr) {
            int prot = 0;
            if (flags & QCAP2_ACCESS_READ) prot |= PROT_READ;
            if (flags & QCAP2_ACCESS_WRITE) prot |= PROT_WRITE;

            m_mapped_addr = mmap(nullptr, m_size, prot, MAP_SHARED, m_fd, 0);
            if (m_mapped_addr == MAP_FAILED) {
                m_mapped_addr = nullptr;
                return -1;
            }
        }
        return 0;
    }

    int end_cpu_access(qcap2_access_flag_t flags) override {
        // Mock sync logic: In a real scenario, this would call ioctl(fd, DMA_BUF_IOCTL_SYNC, ...)
        std::cout << "[DmaBufBuffer] end_cpu_access (sync for Device)\n";
        return 0;
    }
};

// ==============================================================================
// Derived Backend: FFmpegBuffer
// ==============================================================================
class FFmpegBuffer : public RcBufferBase {
private:
    AVFrame* m_frame;

public:
    // Takes ownership of the AVFrame reference
    explicit FFmpegBuffer(AVFrame* frame) : m_frame(frame) {
        std::cout << "[FFmpegBuffer] Created with AVFrame ptr: " << frame << "\n";
    }

    ~FFmpegBuffer() override {
        // Release the FFmpeg internal reference
        if (m_frame) {
            av_frame_free(&m_frame);
        }
        std::cout << "[FFmpegBuffer] Destroyed and released AVFrame.\n";
    }

    uint32_t get_capabilities() const override {
        return QCAP2_BUFCAP_FFMPEG_FRAME | QCAP2_BUFCAP_SYSTEM_MEMORY;
        // Note: Could also check if frame->format is hardware (e.g. AV_PIX_FMT_CUDA)
    }

    size_t get_size() const override {
        if (!m_frame) return 0;
        // Approximation for mockup
        return (size_t)(m_frame->width * m_frame->height * 3 / 2);
    }

    void* get_data() override {
        if (!m_frame) return nullptr;
        return m_frame->data[0];
    }

    void* get_avframe() const override {
        return m_frame;
    }
};

/**
 * We extend RcBufferWrapper to include an atomic ref count.
 * The inner std::shared_ptr is useful for C++ consumers who want to share
 * the backend without dealing with the C wrapper pointer directly.
 * But for the C API (qcap2_rcbuffer_t*), we need an atomic counter.
 */
struct RefCountedWrapper {
    std::shared_ptr<RcBufferBase> backend;
    std::atomic<int> ref_count;

    explicit RefCountedWrapper(std::shared_ptr<RcBufferBase> b)
        : backend(std::move(b)), ref_count(1) {}
};

} // namespace buffer
} // namespace qcap2

// ==============================================================================
// Bridge Layer: extern "C" APIs Implementation
// ==============================================================================

using qcap2::buffer::RefCountedWrapper;
using qcap2::buffer::RcBufferBase;

extern "C" {

static inline RefCountedWrapper* qcap2_to_wrapper(qcap2_rcbuffer_t* pBuf) {
    return reinterpret_cast<RefCountedWrapper*>(pBuf);
}

static inline const RefCountedWrapper* qcap2_to_wrapper_const(const qcap2_rcbuffer_t* pBuf) {
    return reinterpret_cast<const RefCountedWrapper*>(pBuf);
}

void qcap2_rcbuffer_ref(qcap2_rcbuffer_t* pBuf) {
    if (!pBuf) return;
    auto* wrapper = qcap2_to_wrapper(pBuf);
    wrapper->ref_count.fetch_add(1, std::memory_order_relaxed);
}

void qcap2_rcbuffer_unref(qcap2_rcbuffer_t* pBuf) {
    if (!pBuf) return;
    auto* wrapper = qcap2_to_wrapper(pBuf);
    if (wrapper->ref_count.fetch_sub(1, std::memory_order_acq_rel) == 1) {
        // Last C-reference to the wrapper
        // The inner std::shared_ptr will release the backend if no C++ component holds it.
        delete wrapper;
    }
}

uint32_t qcap2_rcbuffer_get_capabilities(const qcap2_rcbuffer_t* pBuf) {
    if (!pBuf) return QCAP2_BUFCAP_NONE;
    return qcap2_to_wrapper_const(pBuf)->backend->get_capabilities();
}

bool qcap2_rcbuffer_has_capability(const qcap2_rcbuffer_t* pBuf, qcap2_buffer_capability_t cap) {
    return (qcap2_rcbuffer_get_capabilities(pBuf) & cap) != 0;
}

void* qcap2_rcbuffer_get_data(qcap2_rcbuffer_t* pBuf) {
    if (!pBuf) return nullptr;
    return qcap2_to_wrapper(pBuf)->backend->get_data();
}

size_t qcap2_rcbuffer_get_size(const qcap2_rcbuffer_t* pBuf) {
    if (!pBuf) return 0;
    return qcap2_to_wrapper_const(pBuf)->backend->get_size();
}

int qcap2_rcbuffer_get_dmabuf_fd(const qcap2_rcbuffer_t* pBuf) {
    if (!pBuf || !qcap2_rcbuffer_has_capability(pBuf, QCAP2_BUFCAP_DMA_BUF)) return -1;
    return qcap2_to_wrapper_const(pBuf)->backend->get_dmabuf_fd();
}

uint64_t qcap2_rcbuffer_get_physical_address(const qcap2_rcbuffer_t* pBuf) {
    if (!pBuf || !qcap2_rcbuffer_has_capability(pBuf, QCAP2_BUFCAP_PHYSICAL_ADDR)) return 0;
    return qcap2_to_wrapper_const(pBuf)->backend->get_physical_address();
}

void* qcap2_rcbuffer_get_avframe(const qcap2_rcbuffer_t* pBuf) {
    if (!pBuf || !qcap2_rcbuffer_has_capability(pBuf, QCAP2_BUFCAP_FFMPEG_FRAME)) return nullptr;
    return qcap2_to_wrapper_const(pBuf)->backend->get_avframe();
}

int qcap2_rcbuffer_begin_cpu_access(qcap2_rcbuffer_t* pBuf, qcap2_access_flag_t flags) {
    if (!pBuf) return -1;
    return qcap2_to_wrapper(pBuf)->backend->begin_cpu_access(flags);
}

int qcap2_rcbuffer_end_cpu_access(qcap2_rcbuffer_t* pBuf, qcap2_access_flag_t flags) {
    if (!pBuf) return -1;
    return qcap2_to_wrapper(pBuf)->backend->end_cpu_access(flags);
}

// Example Factory Functions for testing
qcap2_rcbuffer_t* qcap2_rcbuffer_new_dmabuf(int fd, size_t size) {
    auto backend = std::make_shared<qcap2::buffer::DmaBufBuffer>(fd, size);
    auto* wrapper = new RefCountedWrapper(backend);
    return reinterpret_cast<qcap2_rcbuffer_t*>(wrapper);
}

qcap2_rcbuffer_t* qcap2_rcbuffer_new_avframe(AVFrame* frame) {
    auto backend = std::make_shared<qcap2::buffer::FFmpegBuffer>(frame);
    auto* wrapper = new RefCountedWrapper(backend);
    return reinterpret_cast<qcap2_rcbuffer_t*>(wrapper);
}

} // extern "C"
