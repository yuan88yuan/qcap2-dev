#pragma once
#include "qcap2.buffer.h"
#include <atomic>


struct qcap2_rcbuffer_t {
public:
    std::atomic<int32_t> use_count_{1};
    std::atomic<int32_t> res_count_{1};
    std::atomic<bool> resource_freed_{false};

    virtual ~qcap2_rcbuffer_t() = default;
    virtual void on_release_resource() = 0;

private:
    void maybe_delete() {
        if (use_count_.load(std::memory_order_acquire) == 0 &&
            res_count_.load(std::memory_order_acquire) == 0) {
            delete this;
        }
    }
    void release_resource() {
        int32_t r = res_count_.load(std::memory_order_acquire);
        while (r > 0) {
            if (res_count_.compare_exchange_weak(r, r - 1, std::memory_order_acq_rel, std::memory_order_acquire)) {
                if (r - 1 == 0) {
                    bool expected = false;
                    if (resource_freed_.compare_exchange_strong(expected, true, std::memory_order_acq_rel, std::memory_order_acquire)) {
                        on_release_resource();
                    }
                }
                break;
            }
        }
        maybe_delete();
    }


public:
    void add_ref() {
        int32_t n = use_count_.load(std::memory_order_acquire);
        while (n > 0) {
            if (use_count_.compare_exchange_weak(n, n + 1, std::memory_order_acq_rel, std::memory_order_acquire)) {
                break;
            }
        }
    }

    void release() {
        int32_t n = use_count_.load(std::memory_order_acquire);
        while (n > 0) {
            if (use_count_.compare_exchange_weak(n, n - 1, std::memory_order_acq_rel, std::memory_order_acquire)) {
                if (n - 1 == 0) {
                    release_resource();
                }
                break;
            }
        }
    }

    int32_t use_count() const {
        return use_count_.load(std::memory_order_acquire);
    }

    int32_t res_count() const {
        return res_count_.load(std::memory_order_acquire);
    }

    PVOID lock_data() {
        int32_t current_use = use_count_.load(std::memory_order_acquire);
        if (current_use > 0) {
            int32_t r = res_count_.load(std::memory_order_acquire);
            while (r > 0) {
                if (res_count_.compare_exchange_weak(r, r + 1, std::memory_order_acq_rel, std::memory_order_acquire)) {
                    return get_data();
                }
            }
        }
        return nullptr;
    }

    void unlock_data() {
        release_resource();
    }

    // Virtual interfaces overridden by concrete backends
    virtual PVOID get_data() const = 0;
    virtual qcap2_buffer_type_t get_type() const = 0;
    virtual PVOID get_native_handle() const = 0;
    virtual ULONG get_size() const { return 0; }

    virtual QRESULT get_pts(int64_t* pts) = 0;
    virtual QRESULT set_pts(int64_t pts) = 0;
    virtual QRESULT get_dts(int64_t* dts) = 0;
    virtual QRESULT set_dts(int64_t dts) = 0;
    virtual QRESULT get_stream_index(int* idx) = 0;
    virtual QRESULT set_stream_index(int idx) = 0;
    virtual QRESULT is_keyframe(BOOL* key) = 0;
    virtual QRESULT set_keyframe(BOOL key) = 0;

    virtual QRESULT get_data_ptr(uint8_t** data, int* size) = 0;
    virtual QRESULT get_video_property(ULONG* colorspace, ULONG* width, ULONG* height) = 0;
    virtual QRESULT get_plane(int plane, uint8_t** data, int* stride) = 0;

    virtual QRESULT map_system_memory(PVOID* ppDataOut) { return QCAP_RS_ERROR_NON_SUPPORT; }
    virtual QRESULT unmap_system_memory() { return QCAP_RS_ERROR_NON_SUPPORT; }
};

struct qcap2_system_buffer : public qcap2_rcbuffer_t {
    PVOID pData;
    ULONG nDataSize;
    qcap2_on_free_resource_t pOnFreeResource;

    qcap2_system_buffer(PVOID data, ULONG size, qcap2_on_free_resource_t on_free)
        : pData(data), nDataSize(size), pOnFreeResource(on_free) {}

    ~qcap2_system_buffer() override {
        // Cleanup if resource was not freed yet
        bool expected = false;
        if (resource_freed_.compare_exchange_strong(expected, true, std::memory_order_acq_rel)) {
            on_release_resource();
        }
    }

    void on_release_resource() override {
        if (pOnFreeResource) {
            pOnFreeResource(pData);
        }
    }

    PVOID get_data() const override { return pData; }
    qcap2_buffer_type_t get_type() const override { return QCAP2_BUFFER_TYPE_SYSTEM; }
    PVOID get_native_handle() const override { return nullptr; }
    ULONG get_size() const override { return nDataSize; }

    QRESULT get_pts(int64_t* pts) override { return QCAP_RS_ERROR_NON_SUPPORT; }
    QRESULT set_pts(int64_t pts) override { return QCAP_RS_ERROR_NON_SUPPORT; }
    QRESULT get_dts(int64_t* dts) override { return QCAP_RS_ERROR_NON_SUPPORT; }
    QRESULT set_dts(int64_t dts) override { return QCAP_RS_ERROR_NON_SUPPORT; }
    QRESULT get_stream_index(int* idx) override { return QCAP_RS_ERROR_NON_SUPPORT; }
    QRESULT set_stream_index(int idx) override { return QCAP_RS_ERROR_NON_SUPPORT; }
    QRESULT is_keyframe(BOOL* key) override { return QCAP_RS_ERROR_NON_SUPPORT; }
    QRESULT set_keyframe(BOOL key) override { return QCAP_RS_ERROR_NON_SUPPORT; }

    QRESULT get_data_ptr(uint8_t** data, int* size) override { return QCAP_RS_ERROR_NON_SUPPORT; }
    QRESULT get_video_property(ULONG* colorspace, ULONG* width, ULONG* height) override { return QCAP_RS_ERROR_NON_SUPPORT; }
    QRESULT get_plane(int plane, uint8_t** data, int* stride) override { return QCAP_RS_ERROR_NON_SUPPORT; }
};
