#ifndef __QCAP2_RCBUFFER_PRIV_H__
#define __QCAP2_RCBUFFER_PRIV_H__

#include "qcap2_rcbuffer.h"
#include <memory>
#include <cstdint>
#include <cstddef>

namespace qcap2 {
namespace buffer {

/**
 * @brief Base class for all polymorphic buffer backends.
 * It provides a virtual interface corresponding to the C API.
 */
class RcBufferBase {
public:
    virtual ~RcBufferBase() = default;

    // Feature queries
    virtual uint32_t get_capabilities() const = 0;
    virtual size_t get_size() const = 0;

    // General CPU mapping / fallback data ptr
    virtual void* get_data() = 0;

    // Backend-specific specific getters (default return invalid/null)
    virtual int get_dmabuf_fd() const { return -1; }
    virtual uint64_t get_physical_address() const { return 0; }
    virtual void* get_avframe() const { return nullptr; }

    // Cache & Access Synchronization
    virtual int begin_cpu_access(qcap2_access_flag_t flags) { return 0; }
    virtual int end_cpu_access(qcap2_access_flag_t flags) { return 0; }
};

/**
 * @brief The internal structure behind the opaque qcap2_rcbuffer_t.
 * By holding a std::shared_ptr, we leverage standard C++ ref-counting,
 * ensuring the derived RcBufferBase class is destructed cleanly when
 * the count hits zero.
 */
struct RcBufferWrapper {
    std::shared_ptr<RcBufferBase> backend;

    // We can also store extra metadata or a secondary cache mechanism here if needed.
    // For now, the shared_ptr provides lock-free, atomic ref-counting.

    explicit RcBufferWrapper(std::shared_ptr<RcBufferBase> b) : backend(std::move(b)) {}
};

} // namespace buffer
} // namespace qcap2

#endif // __QCAP2_RCBUFFER_PRIV_H__
