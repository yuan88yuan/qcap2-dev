#include "qcap2.buffer.h"
#undef qcap2_rcbuffer_new
#include "qcap2.user.h"
#include "qcap2.dmabuf.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <atomic>
#include <new>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _qcap2_rcbuffer_priv_t {
    // New model fields:
    void* owner;
    void* user_data;
    qcap2_rcbuffer_destroy_t destroy;

    qcap2_rcbuffer_content_type_t content_type;
    uint32_t memory_flags;
    uint32_t capability_flags;

    const qcap2_rcbuffer_ops_t* ops;

    // Refcounts:
    std::atomic<int32_t> use_count;
    std::atomic<int32_t> res_count;
    std::atomic<bool> resource_freed;
} qcap2_rcbuffer_priv_t;

// A simple internal definition to overlay on the opaque struct arrays.
typedef struct _qcap2_av_frame_priv_t {
    ULONG nColorSpaceType;
    ULONG nWidth;
    ULONG nHeight;

    ULONG nChannels;
    ULONG nSampleFmt;
    ULONG nSampleFrequency;
    ULONG nFrameSize;

    int nFieldType;
    double dSampleTime;
    int64_t nPTS;
    int64_t nPktPos;

    int64_t nVideoBits;
    int64_t nAudioBits;

    uint8_t* pBuffer[4];
    int pStride[4];
    bool bOwnsBuffer;

    qcap2_dmabuf_t* pDMABuf;
    bool bOwnsDMABuf;
} qcap2_av_frame_priv_t;

typedef struct _qcap2_av_packet_priv_t {
    int nStreamIndex;
    BOOL bIsKeyFrame;
    double dSampleTime;
    int64_t nPTS;
    int64_t nDTS;

    uint8_t* pBuffer;
    int nSize;
    bool bOwnsBuffer;
} qcap2_av_packet_priv_t;

static int32_t qcap2_atomic_inc_if_positive(std::atomic<int32_t>& value) {
    int32_t n = value.load(std::memory_order_acquire);
    while (n > 0) {
        if (value.compare_exchange_weak(n, n + 1, std::memory_order_acq_rel, std::memory_order_acquire)) {
            return n + 1;
        }
    }
    return 0;
}

static int32_t qcap2_atomic_dec_if_positive(std::atomic<int32_t>& value) {
    int32_t n = value.load(std::memory_order_acquire);
    while (n > 0) {
        if (value.compare_exchange_weak(n, n - 1, std::memory_order_acq_rel, std::memory_order_acquire)) {
            return n - 1;
        }
    }
    return -1;
}

static void qcap2_rcbuffer_maybe_delete(qcap2_rcbuffer_priv_t* p) {
    if (p &&
        p->use_count.load(std::memory_order_acquire) == 0 &&
        p->res_count.load(std::memory_order_acquire) == 0) {
        delete p;
    }
}

static void qcap2_rcbuffer_release_resource(qcap2_rcbuffer_priv_t* p) {
    if (!p) return;

    int32_t nResCount = qcap2_atomic_dec_if_positive(p->res_count);
    if (nResCount == 0) {
        bool bExpected = false;
        if (p->resource_freed.compare_exchange_strong(bExpected, true, std::memory_order_acq_rel, std::memory_order_acquire)) {
            if (p->destroy) {
                p->destroy(p->owner, p->user_data);
            }
        }
    }

    qcap2_rcbuffer_maybe_delete(p);
}

// --- qcap2_rcbuffer_t ---

qcap2_rcbuffer_t* qcap2_rcbuffer_new(const qcap2_rcbuffer_create_info_t* info) {
    if (!info || info->cb < sizeof(qcap2_rcbuffer_create_info_t)) return NULL;
    qcap2_rcbuffer_priv_t* p = new (std::nothrow) qcap2_rcbuffer_priv_t();
    if (p) {
        p->owner = info->owner;
        p->user_data = info->user_data;
        p->destroy = info->destroy;
        p->content_type = info->content_type;
        p->memory_flags = info->memory_flags;
        p->capability_flags = info->capability_flags;
        p->ops = info->ops;

        p->use_count.store(1, std::memory_order_release);
        p->res_count.store(1, std::memory_order_release);
        p->resource_freed.store(false, std::memory_order_release);
    }
    return (qcap2_rcbuffer_t*)p;
}



void qcap2_rcbuffer_delete(qcap2_rcbuffer_t* pRCBuffer) {
    qcap2_rcbuffer_release(pRCBuffer);
}

void qcap2_rcbuffer_add_ref(qcap2_rcbuffer_t* pRCBuffer) {
    if (pRCBuffer) {
        qcap2_rcbuffer_priv_t* p = (qcap2_rcbuffer_priv_t*)pRCBuffer;
        qcap2_atomic_inc_if_positive(p->use_count);
    }
}

void qcap2_rcbuffer_release(qcap2_rcbuffer_t* pRCBuffer) {
    if (pRCBuffer) {
        qcap2_rcbuffer_priv_t* p = (qcap2_rcbuffer_priv_t*)pRCBuffer;
        int32_t nUseCount = qcap2_atomic_dec_if_positive(p->use_count);
        if (nUseCount == 0) {
            qcap2_rcbuffer_release_resource(p);
        }
    }
}

int32_t qcap2_rcbuffer_use_count(qcap2_rcbuffer_t* pRCBuffer) {
    if (pRCBuffer) {
        return ((qcap2_rcbuffer_priv_t*)pRCBuffer)->use_count.load(std::memory_order_acquire);
    }
    return 0;
}

int32_t qcap2_rcbuffer_res_count(qcap2_rcbuffer_t* pRCBuffer) {
    if (pRCBuffer) {
        return ((qcap2_rcbuffer_priv_t*)pRCBuffer)->res_count.load(std::memory_order_acquire);
    }
    return 0;
}

static QRESULT qcap2_rcbuffer_validate_access(const qcap2_rcbuffer_priv_t* p, uint32_t flags) {
    if (!p) return QCAP_RS_ERROR_INVALID_PARAMETER;

    if ((flags & QCAP2_RCBUFFER_ACCESS_CPU) &&
        (flags & QCAP2_RCBUFFER_ACCESS_READ) &&
        !(p->capability_flags & QCAP2_RCBUFFER_CAP_CPU_READ)) {
        return QCAP_RS_ERROR_NON_SUPPORT;
    }

    if ((flags & QCAP2_RCBUFFER_ACCESS_CPU) &&
        (flags & QCAP2_RCBUFFER_ACCESS_WRITE) &&
        !(p->capability_flags & QCAP2_RCBUFFER_CAP_CPU_WRITE)) {
        return QCAP_RS_ERROR_NON_SUPPORT;
    }

    if ((flags & QCAP2_RCBUFFER_ACCESS_ZERO_COPY) &&
        !(p->capability_flags & QCAP2_RCBUFFER_CAP_ZERO_COPY)) {
        return QCAP_RS_ERROR_NON_SUPPORT;
    }

    if ((flags & QCAP2_RCBUFFER_ACCESS_DEVICE) &&
        !(p->capability_flags & (QCAP2_RCBUFFER_CAP_NATIVE_HANDLE |
                                 QCAP2_RCBUFFER_CAP_DEVICE_SYNC |
                                 QCAP2_RCBUFFER_CAP_ZERO_COPY))) {
        return QCAP_RS_ERROR_NON_SUPPORT;
    }

    return QCAP_RS_SUCCESSFUL;
}

QRESULT qcap2_rcbuffer_begin_access(qcap2_rcbuffer_t* buf, uint32_t flags, qcap2_rcbuffer_access_t* access) {
    if (!buf || !access || access->cb < sizeof(qcap2_rcbuffer_access_t)) return QCAP_RS_ERROR_INVALID_PARAMETER;
    qcap2_rcbuffer_priv_t* p = (qcap2_rcbuffer_priv_t*)buf;

    QRESULT res = qcap2_rcbuffer_validate_access(p, flags);
    if (res != QCAP_RS_SUCCESSFUL) return res;

    if (p->resource_freed.load(std::memory_order_acquire) ||
        qcap2_atomic_inc_if_positive(p->res_count) <= 0) {
        return QCAP_RS_ERROR_GENERAL;
    }

    access->requested_flags = flags;
    access->granted_flags = 0;
    access->memory_flags = p->memory_flags;
    access->backend_state = NULL;

    if (p->ops && p->ops->begin_access) {
        res = p->ops->begin_access(p->owner, p->user_data, flags, access);
    } else {
        access->granted_flags = flags;
    }

    if (res != QCAP_RS_SUCCESSFUL) {
        qcap2_rcbuffer_release_resource(p);
    }
    return res;
}

void qcap2_rcbuffer_end_access(qcap2_rcbuffer_t* buf, qcap2_rcbuffer_access_t* access) {
    if (!buf || !access) return;
    qcap2_rcbuffer_priv_t* p = (qcap2_rcbuffer_priv_t*)buf;

    if (p->ops && p->ops->end_access) {
        p->ops->end_access(p->owner, p->user_data, access);
    }

    qcap2_rcbuffer_release_resource(p);
}

QRESULT qcap2_rcbuffer_query(qcap2_rcbuffer_t* buf, qcap2_rcbuffer_info_t* info) {
    if (!buf || !info || info->cb < sizeof(qcap2_rcbuffer_info_t)) return QCAP_RS_ERROR_INVALID_PARAMETER;
    qcap2_rcbuffer_priv_t* p = (qcap2_rcbuffer_priv_t*)buf;

    if (p->ops && p->ops->query) {
        return p->ops->query(p->owner, p->user_data, info);
    }

    info->content_type = p->content_type;
    info->memory_flags = p->memory_flags;
    info->capability_flags = p->capability_flags;
    info->owner = p->owner;
    return QCAP_RS_SUCCESSFUL;
}

QRESULT qcap2_rcbuffer_get_video_info(qcap2_rcbuffer_t* buf, qcap2_rcbuffer_video_info_t* info) {
    if (!buf || !info || info->cb < sizeof(qcap2_rcbuffer_video_info_t)) return QCAP_RS_ERROR_INVALID_PARAMETER;
    qcap2_rcbuffer_priv_t* p = (qcap2_rcbuffer_priv_t*)buf;

    if (p->ops && p->ops->get_video_info) {
        return p->ops->get_video_info(p->owner, p->user_data, info);
    }
    return QCAP_RS_ERROR_GENERAL;
}

QRESULT qcap2_rcbuffer_set_video_info(qcap2_rcbuffer_t* buf, const qcap2_rcbuffer_video_info_t* info) {
    if (!buf || !info || info->cb < sizeof(qcap2_rcbuffer_video_info_t)) return QCAP_RS_ERROR_INVALID_PARAMETER;
    qcap2_rcbuffer_priv_t* p = (qcap2_rcbuffer_priv_t*)buf;

    if (p->ops && p->ops->set_video_info) {
        return p->ops->set_video_info(p->owner, p->user_data, info);
    }
    return QCAP_RS_ERROR_GENERAL;
}

QRESULT qcap2_rcbuffer_get_plane(qcap2_rcbuffer_t* buf, int plane, qcap2_rcbuffer_plane_t* out) {
    if (!buf || !out || out->cb < sizeof(qcap2_rcbuffer_plane_t)) return QCAP_RS_ERROR_INVALID_PARAMETER;
    qcap2_rcbuffer_priv_t* p = (qcap2_rcbuffer_priv_t*)buf;

    if (p->ops && p->ops->get_plane) {
        return p->ops->get_plane(p->owner, p->user_data, plane, out);
    }
    return QCAP_RS_ERROR_GENERAL;
}

QRESULT qcap2_rcbuffer_get_packet_info(qcap2_rcbuffer_t* buf, qcap2_rcbuffer_packet_info_t* info) {
    if (!buf || !info || info->cb < sizeof(qcap2_rcbuffer_packet_info_t)) return QCAP_RS_ERROR_INVALID_PARAMETER;
    qcap2_rcbuffer_priv_t* p = (qcap2_rcbuffer_priv_t*)buf;

    if (p->ops && p->ops->get_packet_info) {
        return p->ops->get_packet_info(p->owner, p->user_data, info);
    }
    return QCAP_RS_ERROR_GENERAL;
}

QRESULT qcap2_rcbuffer_set_packet_info(qcap2_rcbuffer_t* buf, const qcap2_rcbuffer_packet_info_t* info) {
    if (!buf || !info || info->cb < sizeof(qcap2_rcbuffer_packet_info_t)) return QCAP_RS_ERROR_INVALID_PARAMETER;
    qcap2_rcbuffer_priv_t* p = (qcap2_rcbuffer_priv_t*)buf;

    if (p->ops && p->ops->set_packet_info) {
        return p->ops->set_packet_info(p->owner, p->user_data, info);
    }
    return QCAP_RS_ERROR_GENERAL;
}

QRESULT qcap2_rcbuffer_get_handle(qcap2_rcbuffer_t* buf, qcap2_rcbuffer_handle_type_t type, qcap2_rcbuffer_handle_t* out) {
    if (!buf || !out || out->cb < sizeof(qcap2_rcbuffer_handle_t)) return QCAP_RS_ERROR_INVALID_PARAMETER;
    qcap2_rcbuffer_priv_t* p = (qcap2_rcbuffer_priv_t*)buf;

    if (p->ops && p->ops->get_handle) {
        return p->ops->get_handle(p->owner, p->user_data, type, out);
    }
    return QCAP_RS_ERROR_GENERAL;
}

QRESULT qcap2_rcbuffer_get_audio_info(qcap2_rcbuffer_t* buf, qcap2_rcbuffer_audio_info_t* info) {
    if (!buf || !info || info->cb < sizeof(qcap2_rcbuffer_audio_info_t)) return QCAP_RS_ERROR_INVALID_PARAMETER;
    qcap2_rcbuffer_priv_t* p = (qcap2_rcbuffer_priv_t*)buf;

    if (p->ops && p->ops->get_audio_info) {
        return p->ops->get_audio_info(p->owner, p->user_data, info);
    }
    return QCAP_RS_ERROR_GENERAL;
}

QRESULT qcap2_rcbuffer_set_audio_info(qcap2_rcbuffer_t* buf, const qcap2_rcbuffer_audio_info_t* info) {
    if (!buf || !info || info->cb < sizeof(qcap2_rcbuffer_audio_info_t)) return QCAP_RS_ERROR_INVALID_PARAMETER;
    qcap2_rcbuffer_priv_t* p = (qcap2_rcbuffer_priv_t*)buf;

    if (p->ops && p->ops->set_audio_info) {
        return p->ops->set_audio_info(p->owner, p->user_data, info);
    }
    return QCAP_RS_ERROR_GENERAL;
}

// --- qcap2_av_frame_t ---

void qcap2_av_frame_init(qcap2_av_frame_t* pFrame) {
    if (pFrame) {
        memset(pFrame, 0, sizeof(qcap2_av_frame_t));
    }
}

void qcap2_av_frame_set_video_property(qcap2_av_frame_t* pFrame, ULONG nColorSpaceType, ULONG nWidth, ULONG nHeight) {
    if (pFrame) {
        qcap2_av_frame_priv_t* p = (qcap2_av_frame_priv_t*)pFrame;
        p->nColorSpaceType = nColorSpaceType;
        p->nWidth = nWidth;
        p->nHeight = nHeight;
    }
}

void qcap2_av_frame_get_video_property(qcap2_av_frame_t* pFrame, ULONG* pColorSpaceType, ULONG* pWidth, ULONG* pHeight) {
    if (pFrame) {
        qcap2_av_frame_priv_t* p = (qcap2_av_frame_priv_t*)pFrame;
        if (pColorSpaceType) *pColorSpaceType = p->nColorSpaceType;
        if (pWidth) *pWidth = p->nWidth;
        if (pHeight) *pHeight = p->nHeight;
    }
}

void qcap2_av_frame_set_audio_property(qcap2_av_frame_t* pFrame, ULONG nChannels, ULONG nSampleFmt, ULONG nSampleFrequency, ULONG nFrameSize) {
    if (pFrame) {
        qcap2_av_frame_priv_t* p = (qcap2_av_frame_priv_t*)pFrame;
        p->nChannels = nChannels;
        p->nSampleFmt = nSampleFmt;
        p->nSampleFrequency = nSampleFrequency;
        p->nFrameSize = nFrameSize;
    }
}

void qcap2_av_frame_get_audio_property(qcap2_av_frame_t* pFrame, ULONG* pChannels, ULONG* pSampleFmt, ULONG* pSampleFrequency, ULONG* pFrameSize) {
    if (pFrame) {
        qcap2_av_frame_priv_t* p = (qcap2_av_frame_priv_t*)pFrame;
        if (pChannels) *pChannels = p->nChannels;
        if (pSampleFmt) *pSampleFmt = p->nSampleFmt;
        if (pSampleFrequency) *pSampleFrequency = p->nSampleFrequency;
        if (pFrameSize) *pFrameSize = p->nFrameSize;
    }
}

void qcap2_av_frame_set_field_type(qcap2_av_frame_t* pFrame, int nFieldType) {
    if (pFrame) {
        qcap2_av_frame_priv_t* p = (qcap2_av_frame_priv_t*)pFrame;
        p->nFieldType = nFieldType;
    }
}

void qcap2_av_frame_get_field_type(qcap2_av_frame_t* pFrame, int* pFieldType) {
    if (pFrame) {
        qcap2_av_frame_priv_t* p = (qcap2_av_frame_priv_t*)pFrame;
        if (pFieldType) *pFieldType = p->nFieldType;
    }
}

void qcap2_av_frame_set_sample_time(qcap2_av_frame_t* pFrame, double dSampleTime) {
    if (pFrame) {
        qcap2_av_frame_priv_t* p = (qcap2_av_frame_priv_t*)pFrame;
        p->dSampleTime = dSampleTime;
    }
}

void qcap2_av_frame_get_sample_time(qcap2_av_frame_t* pFrame, double* pSampleTime) {
    if (pFrame) {
        qcap2_av_frame_priv_t* p = (qcap2_av_frame_priv_t*)pFrame;
        if (pSampleTime) *pSampleTime = p->dSampleTime;
    }
}

void qcap2_av_frame_set_pts(qcap2_av_frame_t* pFrame, int64_t nPTS) {
    if (pFrame) {
        qcap2_av_frame_priv_t* p = (qcap2_av_frame_priv_t*)pFrame;
        p->nPTS = nPTS;
    }
}

void qcap2_av_frame_get_pts(qcap2_av_frame_t* pFrame, int64_t* pPTS) {
    if (pFrame) {
        qcap2_av_frame_priv_t* p = (qcap2_av_frame_priv_t*)pFrame;
        if (pPTS) *pPTS = p->nPTS;
    }
}

void qcap2_av_frame_set_pkt_pos(qcap2_av_frame_t* pFrame, int64_t nPktPos) {
    if (pFrame) {
        qcap2_av_frame_priv_t* p = (qcap2_av_frame_priv_t*)pFrame;
        p->nPktPos = nPktPos;
    }
}

void qcap2_av_frame_get_pkt_pos(qcap2_av_frame_t* pFrame, int64_t* pPktPos) {
    if (pFrame) {
        qcap2_av_frame_priv_t* p = (qcap2_av_frame_priv_t*)pFrame;
        if (pPktPos) *pPktPos = p->nPktPos;
    }
}

void qcap2_av_frame_get_video_bits(qcap2_av_frame_t* pFrame, int64_t* pBits) {
    if (pFrame) {
        qcap2_av_frame_priv_t* p = (qcap2_av_frame_priv_t*)pFrame;
        if (pBits) *pBits = p->nVideoBits;
    }
}

void qcap2_av_frame_get_audio_bits(qcap2_av_frame_t* pFrame, int64_t* pBits) {
    if (pFrame) {
        qcap2_av_frame_priv_t* p = (qcap2_av_frame_priv_t*)pFrame;
        if (pBits) *pBits = p->nAudioBits;
    }
}

void qcap2_av_frame_set_buffer(qcap2_av_frame_t* pFrame, uint8_t* pBuffer, int nStride) {
    if (pFrame) {
        qcap2_av_frame_priv_t* p = (qcap2_av_frame_priv_t*)pFrame;
        p->pBuffer[0] = pBuffer;
        p->pStride[0] = nStride;
    }
}

void qcap2_av_frame_get_buffer(qcap2_av_frame_t* pFrame, uint8_t** ppBuffer, int* pStride) {
    if (pFrame) {
        qcap2_av_frame_priv_t* p = (qcap2_av_frame_priv_t*)pFrame;
        if (ppBuffer) *ppBuffer = p->pBuffer[0];
        if (pStride) *pStride = p->pStride[0];
    }
}

void qcap2_av_frame_set_buffer1(qcap2_av_frame_t* pFrame, uint8_t* pBuffer[4], int pStride[4]) {
    if (pFrame) {
        qcap2_av_frame_priv_t* p = (qcap2_av_frame_priv_t*)pFrame;
        for (int i = 0; i < 4; i++) {
            p->pBuffer[i] = pBuffer[i];
            p->pStride[i] = pStride[i];
        }
    }
}

void qcap2_av_frame_get_buffer1(qcap2_av_frame_t* pFrame, uint8_t* pBuffer[4], int pStride[4]) {
    if (pFrame) {
        qcap2_av_frame_priv_t* p = (qcap2_av_frame_priv_t*)pFrame;
        for (int i = 0; i < 4; i++) {
            if (pBuffer) pBuffer[i] = p->pBuffer[i];
            if (pStride) pStride[i] = p->pStride[i];
        }
    }
}

static int qcap2_align_value(int value, int alignment) {
    if (value <= 0) return 0;
    if (alignment <= 1) return value;
    return ((value + alignment - 1) / alignment) * alignment;
}

static bool qcap2_av_frame_set_owned_layout(qcap2_av_frame_priv_t* p, size_t nTotalSize, int nPlanes, const size_t nPlaneOffset[4], const int nStride[4]) {
    if (!p || nTotalSize == 0 || nPlanes <= 0 || nPlanes > 4) return false;

    uint8_t* pMemory = (uint8_t*)malloc(nTotalSize);
    if (!pMemory) return false;

    memset(p->pBuffer, 0, sizeof(p->pBuffer));
    memset(p->pStride, 0, sizeof(p->pStride));
    for (int i = 0; i < nPlanes; ++i) {
        p->pBuffer[i] = pMemory + nPlaneOffset[i];
        p->pStride[i] = nStride[i];
    }
    p->bOwnsBuffer = true;
    p->nVideoBits = (int64_t)nTotalSize * 8;
    return true;
}

bool qcap2_av_frame_alloc_buffer(qcap2_av_frame_t* pFrame, int align, int valign) {
    if (!pFrame) return false;
    qcap2_av_frame_priv_t* p = (qcap2_av_frame_priv_t*)pFrame;

    qcap2_av_frame_free_buffer(pFrame);

    int nWidth = (int)p->nWidth;
    int nHeight = (int)p->nHeight;
    if (nWidth <= 0 || nHeight <= 0) return false;

    int nAlignedHeight = qcap2_align_value(nHeight, valign);
    int nChromaWidth = (nWidth + 1) / 2;
    int nChromaHeight = (nHeight + 1) / 2;
    int nAlignedChromaHeight = qcap2_align_value(nChromaHeight, valign);

    size_t nOffset[4] = { 0, 0, 0, 0 };
    int nStride[4] = { 0, 0, 0, 0 };
    size_t nSize[4] = { 0, 0, 0, 0 };

    switch (p->nColorSpaceType) {
    case QCAP_COLORSPACE_TYPE_RGB24:
    case QCAP_COLORSPACE_TYPE_BGR24:
        nStride[0] = qcap2_align_value(nWidth * 3, align);
        nSize[0] = (size_t)nStride[0] * nAlignedHeight;
        return qcap2_av_frame_set_owned_layout(p, nSize[0], 1, nOffset, nStride);

    case QCAP_COLORSPACE_TYPE_ARGB32:
    case QCAP_COLORSPACE_TYPE_ABGR32:
        nStride[0] = qcap2_align_value(nWidth * 4, align);
        nSize[0] = (size_t)nStride[0] * nAlignedHeight;
        return qcap2_av_frame_set_owned_layout(p, nSize[0], 1, nOffset, nStride);

    case QCAP_COLORSPACE_TYPE_Y416:
        nStride[0] = qcap2_align_value(nWidth * 8, align);
        nSize[0] = (size_t)nStride[0] * nAlignedHeight;
        return qcap2_av_frame_set_owned_layout(p, nSize[0], 1, nOffset, nStride);

    case QCAP_COLORSPACE_TYPE_YUY2:
    case QCAP_COLORSPACE_TYPE_UYVY:
        nStride[0] = qcap2_align_value(nWidth * 2, align);
        nSize[0] = (size_t)nStride[0] * nAlignedHeight;
        return qcap2_av_frame_set_owned_layout(p, nSize[0], 1, nOffset, nStride);

    case QCAP_COLORSPACE_TYPE_Y800:
        nStride[0] = qcap2_align_value(nWidth, align);
        nSize[0] = (size_t)nStride[0] * nAlignedHeight;
        return qcap2_av_frame_set_owned_layout(p, nSize[0], 1, nOffset, nStride);

    case QCAP_COLORSPACE_TYPE_YV12:
    case QCAP_COLORSPACE_TYPE_I420:
        nStride[0] = qcap2_align_value(nWidth, align);
        nStride[1] = qcap2_align_value(nChromaWidth, align);
        nStride[2] = nStride[1];
        nSize[0] = (size_t)nStride[0] * nAlignedHeight;
        nSize[1] = (size_t)nStride[1] * nAlignedChromaHeight;
        nSize[2] = nSize[1];
        nOffset[1] = nSize[0];
        nOffset[2] = nSize[0] + nSize[1];
        return qcap2_av_frame_set_owned_layout(p, nSize[0] + nSize[1] + nSize[2], 3, nOffset, nStride);

    case QCAP_COLORSPACE_TYPE_YV24:
        nStride[0] = qcap2_align_value(nWidth, align);
        nStride[1] = nStride[0];
        nStride[2] = nStride[0];
        nSize[0] = (size_t)nStride[0] * nAlignedHeight;
        nSize[1] = nSize[0];
        nSize[2] = nSize[0];
        nOffset[1] = nSize[0];
        nOffset[2] = nSize[0] + nSize[1];
        return qcap2_av_frame_set_owned_layout(p, nSize[0] + nSize[1] + nSize[2], 3, nOffset, nStride);

    case QCAP_COLORSPACE_TYPE_NV12:
        nStride[0] = qcap2_align_value(nWidth, align);
        nStride[1] = nStride[0];
        nSize[0] = (size_t)nStride[0] * nAlignedHeight;
        nSize[1] = (size_t)nStride[1] * nAlignedChromaHeight;
        nOffset[1] = nSize[0];
        return qcap2_av_frame_set_owned_layout(p, nSize[0] + nSize[1], 2, nOffset, nStride);

    case QCAP_COLORSPACE_TYPE_P010:
        nStride[0] = qcap2_align_value(nWidth * 2, align);
        nStride[1] = nStride[0];
        nSize[0] = (size_t)nStride[0] * nAlignedHeight;
        nSize[1] = (size_t)nStride[1] * nAlignedChromaHeight;
        nOffset[1] = nSize[0];
        return qcap2_av_frame_set_owned_layout(p, nSize[0] + nSize[1], 2, nOffset, nStride);

    case QCAP_COLORSPACE_TYPE_P210:
        nStride[0] = qcap2_align_value(nWidth * 2, align);
        nStride[1] = nStride[0];
        nSize[0] = (size_t)nStride[0] * nAlignedHeight;
        nSize[1] = (size_t)nStride[1] * nAlignedHeight;
        nOffset[1] = nSize[0];
        return qcap2_av_frame_set_owned_layout(p, nSize[0] + nSize[1], 2, nOffset, nStride);

    default:
        return false;
    }
}

void qcap2_av_frame_free_buffer(qcap2_av_frame_t* pFrame) {
    if (!pFrame) return;
    qcap2_av_frame_priv_t* p = (qcap2_av_frame_priv_t*)pFrame;
    qcap2_av_frame_free_mapped_dmabuf(pFrame);
    if (p->bOwnsBuffer && p->pBuffer[0]) {
        free(p->pBuffer[0]);
    }
    memset(p->pBuffer, 0, sizeof(p->pBuffer));
    memset(p->pStride, 0, sizeof(p->pStride));
    p->bOwnsBuffer = false;
    p->nVideoBits = 0;
}

QRESULT qcap2_av_frame_copy(qcap2_av_frame_t* pSrcFrame, qcap2_av_frame_t* pDstFrame) {
    if (!pSrcFrame || !pDstFrame) return QCAP_RS_ERROR_GENERAL;
    memcpy(pDstFrame, pSrcFrame, sizeof(qcap2_av_frame_t));

    // Deep copy buffer
    qcap2_av_frame_priv_t* pSrc = (qcap2_av_frame_priv_t*)pSrcFrame;
    qcap2_av_frame_priv_t* pDst = (qcap2_av_frame_priv_t*)pDstFrame;

    if (pSrc->pBuffer[0] && pSrc->pStride[0] > 0 && pSrc->nHeight > 0) {
        int size = pSrc->nHeight * pSrc->pStride[0];
        pDst->pBuffer[0] = (uint8_t*)malloc(size);
        if (pDst->pBuffer[0]) {
            memcpy(pDst->pBuffer[0], pSrc->pBuffer[0], size);
            pDst->bOwnsBuffer = true;
        } else {
            pDst->bOwnsBuffer = false;
        }
    }

    return QCAP_RS_SUCCESSFUL;
}

QRESULT qcap2_av_frame_color_range_expand(qcap2_av_frame_t* pSrcFrame, qcap2_av_frame_t* pDstFrame) {
    if (!pSrcFrame || !pDstFrame) return QCAP_RS_ERROR_GENERAL;
    // Just copy for now, as we don't have a real image processing library attached
    return qcap2_av_frame_copy(pSrcFrame, pDstFrame);
}

QRESULT qcap2_av_frame_store_picture(qcap2_av_frame_t* pFrame, const char* strFilePath) {
    if (!pFrame || !strFilePath) return QCAP_RS_ERROR_GENERAL;
    FILE* f = fopen(strFilePath, "wb");
    if (!f) return QCAP_RS_ERROR_GENERAL;

    qcap2_av_frame_priv_t* p = (qcap2_av_frame_priv_t*)pFrame;
    if (p->pBuffer[0] && p->nHeight > 0 && p->pStride[0] > 0) {
        fwrite(p->pBuffer[0], 1, p->nHeight * p->pStride[0], f);
    }

    fclose(f);
    return QCAP_RS_SUCCESSFUL;
}

QRESULT qcap2_av_frame_store_picture2(qcap2_av_frame_t* pFrame, const char* strFilePath, int nQuality) {
    return qcap2_av_frame_store_picture(pFrame, strFilePath);
}


// --- qcap2_av_packet_t ---

void qcap2_av_packet_init(qcap2_av_packet_t* pPacket) {
    if (pPacket) {
        memset(pPacket, 0, sizeof(qcap2_av_packet_t));
    }
}

void qcap2_av_packet_set_property(qcap2_av_packet_t* pPacket, int nStreamIndex, BOOL bIsKeyFrame) {
    if (pPacket) {
        qcap2_av_packet_priv_t* p = (qcap2_av_packet_priv_t*)pPacket;
        p->nStreamIndex = nStreamIndex;
        p->bIsKeyFrame = bIsKeyFrame;
    }
}

void qcap2_av_packet_get_property(qcap2_av_packet_t* pPacket, int* pStreamIndex, BOOL* pIsKeyFrame) {
    if (pPacket) {
        qcap2_av_packet_priv_t* p = (qcap2_av_packet_priv_t*)pPacket;
        if (pStreamIndex) *pStreamIndex = p->nStreamIndex;
        if (pIsKeyFrame) *pIsKeyFrame = p->bIsKeyFrame;
    }
}

void qcap2_av_packet_set_sample_time(qcap2_av_packet_t* pPacket, double dSampleTime) {
    if (pPacket) {
        qcap2_av_packet_priv_t* p = (qcap2_av_packet_priv_t*)pPacket;
        p->dSampleTime = dSampleTime;
    }
}

void qcap2_av_packet_get_sample_time(qcap2_av_packet_t* pPacket, double* pSampleTime) {
    if (pPacket) {
        qcap2_av_packet_priv_t* p = (qcap2_av_packet_priv_t*)pPacket;
        if (pSampleTime) *pSampleTime = p->dSampleTime;
    }
}

void qcap2_av_packet_set_pts(qcap2_av_packet_t* pPacket, int64_t nPTS) {
    if (pPacket) {
        qcap2_av_packet_priv_t* p = (qcap2_av_packet_priv_t*)pPacket;
        p->nPTS = nPTS;
    }
}

void qcap2_av_packet_get_pts(qcap2_av_packet_t* pPacket, int64_t* pPTS) {
    if (pPacket) {
        qcap2_av_packet_priv_t* p = (qcap2_av_packet_priv_t*)pPacket;
        if (pPTS) *pPTS = p->nPTS;
    }
}

void qcap2_av_packet_set_dts(qcap2_av_packet_t* pPacket, int64_t nDTS) {
    if (pPacket) {
        qcap2_av_packet_priv_t* p = (qcap2_av_packet_priv_t*)pPacket;
        p->nDTS = nDTS;
    }
}

void qcap2_av_packet_get_dts(qcap2_av_packet_t* pPacket, int64_t* pDTS) {
    if (pPacket) {
        qcap2_av_packet_priv_t* p = (qcap2_av_packet_priv_t*)pPacket;
        if (pDTS) *pDTS = p->nDTS;
    }
}

void qcap2_av_packet_set_buffer(qcap2_av_packet_t* pPacket, uint8_t* pBuffer, int nSize) {
    if (pPacket) {
        qcap2_av_packet_priv_t* p = (qcap2_av_packet_priv_t*)pPacket;
        p->pBuffer = pBuffer;
        p->nSize = nSize;
    }
}

void qcap2_av_packet_get_buffer(qcap2_av_packet_t* pPacket, uint8_t** ppBuffer, int* pSize) {
    if (pPacket) {
        qcap2_av_packet_priv_t* p = (qcap2_av_packet_priv_t*)pPacket;
        if (ppBuffer) *ppBuffer = p->pBuffer;
        if (pSize) *pSize = p->nSize;
    }
}

bool qcap2_av_packet_alloc_buffer(qcap2_av_packet_t* pPacket, int nSize) {
    if (!pPacket) return false;
    qcap2_av_packet_priv_t* p = (qcap2_av_packet_priv_t*)pPacket;
    if (p->bOwnsBuffer && p->pBuffer) {
        free(p->pBuffer);
    }
    p->pBuffer = (uint8_t*)malloc(nSize);
    p->nSize = nSize;
    p->bOwnsBuffer = true;
    return p->pBuffer != NULL;
}

void qcap2_av_packet_free_buffer(qcap2_av_packet_t* pPacket) {
    if (!pPacket) return;
    qcap2_av_packet_priv_t* p = (qcap2_av_packet_priv_t*)pPacket;
    if (p->bOwnsBuffer && p->pBuffer) {
        free(p->pBuffer);
        p->pBuffer = NULL;
    }
    p->bOwnsBuffer = false;
    p->nSize = 0;
}


// --- qcap2.user.h rc-buffer helpers ---

struct WrappedFrameBackend {
    qcap2_av_frame_t* frame;
    void* user_data;
    qcap2_rcbuffer_destroy_t destroy;
};

static void wrapped_frame_destroy(void* owner, void* user_data) {
    (void)user_data;
    WrappedFrameBackend* b = (WrappedFrameBackend*)owner;
    if (b->destroy) {
        void* callback_owner = b->user_data ? b->user_data : b->frame;
        b->destroy(callback_owner, b->user_data);
    }
    delete b;
}

static QRESULT wrapped_frame_query(void* owner, void* user_data, qcap2_rcbuffer_info_t* info) {
    (void)user_data;
    WrappedFrameBackend* b = (WrappedFrameBackend*)owner;
    ULONG channels = 0, sample_fmt = 0, sample_freq = 0, frame_size = 0;
    qcap2_av_frame_get_audio_property(b->frame, &channels, &sample_fmt, &sample_freq, &frame_size);
    if (channels > 0 || frame_size > 0) {
        info->content_type = QCAP2_RCBUFFER_CONTENT_AUDIO_FRAME;
    } else {
        info->content_type = QCAP2_RCBUFFER_CONTENT_VIDEO_FRAME;
    }
    info->memory_flags = QCAP2_RCBUFFER_MEMORY_SYSTEM;
    info->capability_flags = QCAP2_RCBUFFER_CAP_CPU_READ | QCAP2_RCBUFFER_CAP_CPU_WRITE | QCAP2_RCBUFFER_CAP_VIDEO_PLANES;
    info->owner = b->user_data;
    return QCAP_RS_SUCCESSFUL;
}

static QRESULT wrapped_frame_get_video_info(void* owner, void* user_data, qcap2_rcbuffer_video_info_t* info) {
    (void)user_data;
    WrappedFrameBackend* b = (WrappedFrameBackend*)owner;
    ULONG color_space = 0, width = 0, height = 0;
    qcap2_av_frame_get_video_property(b->frame, &color_space, &width, &height);
    int field_type = 0;
    qcap2_av_frame_get_field_type(b->frame, &field_type);
    int64_t pts = 0;
    qcap2_av_frame_get_pts(b->frame, &pts);
    double sample_time = 0.0;
    qcap2_av_frame_get_sample_time(b->frame, &sample_time);

    info->color_space_type = color_space;
    info->width = width;
    info->height = height;
    info->field_type = field_type;
    info->pts = pts;
    info->sample_time = sample_time;
    switch (color_space) {
    case QCAP_COLORSPACE_TYPE_NV12:
    case QCAP_COLORSPACE_TYPE_P010:
    case QCAP_COLORSPACE_TYPE_P210:
        info->plane_count = 2;
        break;
    case QCAP_COLORSPACE_TYPE_YV12:
    case QCAP_COLORSPACE_TYPE_I420:
    case QCAP_COLORSPACE_TYPE_YV24:
        info->plane_count = 3;
        break;
    default:
        info->plane_count = 1;
        break;
    }
    return QCAP_RS_SUCCESSFUL;
}

static QRESULT wrapped_frame_set_video_info(void* owner, void* user_data, const qcap2_rcbuffer_video_info_t* info) {
    (void)user_data;
    WrappedFrameBackend* b = (WrappedFrameBackend*)owner;
    qcap2_av_frame_set_video_property(b->frame, info->color_space_type, info->width, info->height);
    qcap2_av_frame_set_field_type(b->frame, info->field_type);
    qcap2_av_frame_set_pts(b->frame, info->pts);
    qcap2_av_frame_set_sample_time(b->frame, info->sample_time);
    return QCAP_RS_SUCCESSFUL;
}

static QRESULT wrapped_frame_get_plane(void* owner, void* user_data, int plane, qcap2_rcbuffer_plane_t* out) {
    (void)user_data;
    WrappedFrameBackend* b = (WrappedFrameBackend*)owner;
    uint8_t* buffers[4] = {0};
    int strides[4] = {0};
    qcap2_av_frame_get_buffer1(b->frame, buffers, strides);

    if (plane < 0 || plane >= 4 || !buffers[plane]) {
        return QCAP_RS_ERROR_INVALID_PARAMETER;
    }

    out->data = buffers[plane];
    out->stride = strides[plane];
    out->size = 0;
    out->fd = -1;
    out->offset = 0;
    out->native_handle = NULL;
    return QCAP_RS_SUCCESSFUL;
}

static QRESULT wrapped_frame_get_audio_info(void* owner, void* user_data, qcap2_rcbuffer_audio_info_t* info) {
    (void)user_data;
    WrappedFrameBackend* b = (WrappedFrameBackend*)owner;
    ULONG channels = 0, sample_fmt = 0, sample_freq = 0, frame_size = 0;
    qcap2_av_frame_get_audio_property(b->frame, &channels, &sample_fmt, &sample_freq, &frame_size);
    int64_t pts = 0;
    qcap2_av_frame_get_pts(b->frame, &pts);
    double sample_time = 0.0;
    qcap2_av_frame_get_sample_time(b->frame, &sample_time);

    info->channels = channels;
    info->sample_fmt = sample_fmt;
    info->sample_frequency = sample_freq;
    info->frame_size = frame_size;
    info->pts = pts;
    info->sample_time = sample_time;
    return QCAP_RS_SUCCESSFUL;
}

static QRESULT wrapped_frame_set_audio_info(void* owner, void* user_data, const qcap2_rcbuffer_audio_info_t* info) {
    (void)user_data;
    WrappedFrameBackend* b = (WrappedFrameBackend*)owner;
    qcap2_av_frame_set_audio_property(b->frame, info->channels, info->sample_fmt, info->sample_frequency, info->frame_size);
    qcap2_av_frame_set_pts(b->frame, info->pts);
    qcap2_av_frame_set_sample_time(b->frame, info->sample_time);
    return QCAP_RS_SUCCESSFUL;
}

static const qcap2_rcbuffer_ops_t wrapped_frame_ops = {
    sizeof(qcap2_rcbuffer_ops_t),
    NULL, NULL,
    wrapped_frame_query,
    wrapped_frame_get_video_info,
    wrapped_frame_set_video_info,
    wrapped_frame_get_plane,
    NULL, NULL, NULL,
    wrapped_frame_get_audio_info,
    wrapped_frame_set_audio_info
};

qcap2_rcbuffer_t* qcap2_rcbuffer_new_from_av_frame(qcap2_av_frame_t* pFrame, void* owner, qcap2_rcbuffer_destroy_t destroy) {
    if (!pFrame) return NULL;
    WrappedFrameBackend* b = new (std::nothrow) WrappedFrameBackend();
    if (!b) return NULL;
    b->frame = pFrame;
    b->user_data = owner;
    b->destroy = destroy;

    qcap2_rcbuffer_create_info_t info = {
        sizeof(info),
        b,
        NULL,
        wrapped_frame_destroy,
        QCAP2_RCBUFFER_CONTENT_VIDEO_FRAME,
        QCAP2_RCBUFFER_MEMORY_SYSTEM,
        QCAP2_RCBUFFER_CAP_CPU_READ | QCAP2_RCBUFFER_CAP_CPU_WRITE | QCAP2_RCBUFFER_CAP_VIDEO_PLANES,
        &wrapped_frame_ops
    };
    return qcap2_rcbuffer_new(&info);
}

struct WrappedPacketBackend {
    qcap2_av_packet_t* packet;
    void* user_data;
    qcap2_rcbuffer_destroy_t destroy;
};

static void wrapped_packet_destroy(void* owner, void* user_data) {
    (void)user_data;
    WrappedPacketBackend* b = (WrappedPacketBackend*)owner;
    if (b->destroy) {
        void* callback_owner = b->user_data ? b->user_data : b->packet;
        b->destroy(callback_owner, b->user_data);
    }
    delete b;
}

static QRESULT wrapped_packet_query(void* owner, void* user_data, qcap2_rcbuffer_info_t* info) {
    (void)user_data;
    WrappedPacketBackend* b = (WrappedPacketBackend*)owner;
    info->content_type = QCAP2_RCBUFFER_CONTENT_PACKET;
    info->memory_flags = QCAP2_RCBUFFER_MEMORY_SYSTEM;
    info->capability_flags = QCAP2_RCBUFFER_CAP_CPU_READ | QCAP2_RCBUFFER_CAP_CPU_WRITE | QCAP2_RCBUFFER_CAP_PACKET_BYTES;
    info->owner = b->user_data;
    return QCAP_RS_SUCCESSFUL;
}

static QRESULT wrapped_packet_get_packet_info(void* owner, void* user_data, qcap2_rcbuffer_packet_info_t* info) {
    (void)user_data;
    WrappedPacketBackend* b = (WrappedPacketBackend*)owner;
    int stream_idx = 0;
    BOOL is_key = FALSE;
    qcap2_av_packet_get_property(b->packet, &stream_idx, &is_key);
    int64_t pts = 0, dts = 0;
    qcap2_av_packet_get_pts(b->packet, &pts);
    qcap2_av_packet_get_dts(b->packet, &dts);
    double stime = 0.0;
    qcap2_av_packet_get_sample_time(b->packet, &stime);
    uint8_t* data = NULL;
    int size = 0;
    qcap2_av_packet_get_buffer(b->packet, &data, &size);

    info->stream_index = stream_idx;
    info->is_keyframe = is_key;
    info->pts = pts;
    info->dts = dts;
    info->sample_time = stime;
    info->data = data;
    info->size = size;
    return QCAP_RS_SUCCESSFUL;
}

static QRESULT wrapped_packet_set_packet_info(void* owner, void* user_data, const qcap2_rcbuffer_packet_info_t* info) {
    (void)user_data;
    WrappedPacketBackend* b = (WrappedPacketBackend*)owner;
    qcap2_av_packet_set_property(b->packet, info->stream_index, info->is_keyframe);
    qcap2_av_packet_set_pts(b->packet, info->pts);
    qcap2_av_packet_set_dts(b->packet, info->dts);
    qcap2_av_packet_set_sample_time(b->packet, info->sample_time);
    if (info->data && info->size > 0) {
        qcap2_av_packet_set_buffer(b->packet, info->data, info->size);
    }
    return QCAP_RS_SUCCESSFUL;
}

static const qcap2_rcbuffer_ops_t wrapped_packet_ops = {
    sizeof(qcap2_rcbuffer_ops_t),
    NULL, NULL,
    wrapped_packet_query,
    NULL, NULL, NULL,
    wrapped_packet_get_packet_info,
    wrapped_packet_set_packet_info,
    NULL, NULL, NULL
};

qcap2_rcbuffer_t* qcap2_rcbuffer_new_from_av_packet(qcap2_av_packet_t* pPacket, void* owner, qcap2_rcbuffer_destroy_t destroy) {
    if (!pPacket) return NULL;
    WrappedPacketBackend* b = new (std::nothrow) WrappedPacketBackend();
    if (!b) return NULL;
    b->packet = pPacket;
    b->user_data = owner;
    b->destroy = destroy;

    qcap2_rcbuffer_create_info_t info = {
        sizeof(info),
        b,
        NULL,
        wrapped_packet_destroy,
        QCAP2_RCBUFFER_CONTENT_PACKET,
        QCAP2_RCBUFFER_MEMORY_SYSTEM,
        QCAP2_RCBUFFER_CAP_CPU_READ | QCAP2_RCBUFFER_CAP_CPU_WRITE | QCAP2_RCBUFFER_CAP_PACKET_BYTES,
        &wrapped_packet_ops
    };
    return qcap2_rcbuffer_new(&info);
}

QRESULT qcap2_av_frame_set_dmabuf(qcap2_av_frame_t* pFrame, qcap2_dmabuf_t* pDMABuf) {
    if (!pFrame) return QCAP_RS_ERROR_INVALID_PARAMETER;
    qcap2_av_frame_priv_t* p = (qcap2_av_frame_priv_t*)pFrame;

    if (p->pDMABuf) {
        qcap2_av_frame_free_mapped_dmabuf(pFrame);
    }

    p->pDMABuf = pDMABuf;
    p->bOwnsDMABuf = false;
    return QCAP_RS_SUCCESSFUL;
}

QRESULT qcap2_av_frame_get_dmabuf(qcap2_av_frame_t* pFrame, qcap2_dmabuf_t** ppDMABuf) {
    if (!pFrame || !ppDMABuf) return QCAP_RS_ERROR_INVALID_PARAMETER;
    qcap2_av_frame_priv_t* p = (qcap2_av_frame_priv_t*)pFrame;
    *ppDMABuf = p->pDMABuf;
    return QCAP_RS_SUCCESSFUL;
}

QRESULT qcap2_av_frame_alloc_dmabuf(qcap2_av_frame_t* pFrame, int nSize, int nProt) {
    (void)nProt;
    if (!pFrame || nSize <= 0) return QCAP_RS_ERROR_INVALID_PARAMETER;
    qcap2_av_frame_priv_t* p = (qcap2_av_frame_priv_t*)pFrame;

    if (p->pDMABuf) {
        qcap2_av_frame_free_dmabuf(pFrame);
    }

    qcap2_dmabuf_t* pDMABuf = (qcap2_dmabuf_t*)calloc(1, sizeof(qcap2_dmabuf_t));
    if (!pDMABuf) return QCAP_RS_ERROR_OUT_OF_MEMORY;

    char pathTemplate[] = "/tmp/qcap2-dmabuf-XXXXXX";
    int fd = mkstemp(pathTemplate);
    if (fd < 0) {
        free(pDMABuf);
        return QCAP_RS_ERROR_OUT_OF_RESOURCE;
    }
    unlink(pathTemplate);

    if (ftruncate(fd, nSize) < 0) {
        close(fd);
        free(pDMABuf);
        return QCAP_RS_ERROR_GENERAL;
    }

    pDMABuf->fd = fd;
    pDMABuf->dmabuf_size = nSize;
    pDMABuf->pVirAddr = nullptr;
    pDMABuf->nPhyAddr = 0;
    pDMABuf->nSize = nSize;

    p->pDMABuf = pDMABuf;
    p->bOwnsDMABuf = true;
    return QCAP_RS_SUCCESSFUL;
}

QRESULT qcap2_av_frame_free_dmabuf(qcap2_av_frame_t* pFrame) {
    if (!pFrame) return QCAP_RS_ERROR_INVALID_PARAMETER;
    qcap2_av_frame_priv_t* p = (qcap2_av_frame_priv_t*)pFrame;
    if (!p->pDMABuf) return QCAP_RS_SUCCESSFUL;

    if (p->pDMABuf->pVirAddr) {
        qcap2_av_frame_unmap_dmabuf(pFrame);
    }

    if (p->pDMABuf->fd >= 0) {
        close(p->pDMABuf->fd);
        p->pDMABuf->fd = -1;
    }

    if (p->bOwnsDMABuf) {
        free(p->pDMABuf);
    }

    p->pDMABuf = nullptr;
    p->bOwnsDMABuf = false;
    return QCAP_RS_SUCCESSFUL;
}

QRESULT qcap2_av_frame_map_dmabuf(qcap2_av_frame_t* pFrame, int nProt) {
    if (!pFrame) return QCAP_RS_ERROR_INVALID_PARAMETER;
    qcap2_av_frame_priv_t* p = (qcap2_av_frame_priv_t*)pFrame;
    if (!p->pDMABuf || p->pDMABuf->fd < 0) return QCAP_RS_ERROR_GENERAL;

    if (p->pDMABuf->pVirAddr) return QCAP_RS_SUCCESSFUL;

    void* addr = mmap(nullptr, p->pDMABuf->dmabuf_size, nProt, MAP_SHARED, p->pDMABuf->fd, 0);
    if (addr == MAP_FAILED) {
        return QCAP_RS_ERROR_GENERAL;
    }

    p->pDMABuf->pVirAddr = addr;
    return QCAP_RS_SUCCESSFUL;
}

QRESULT qcap2_av_frame_unmap_dmabuf(qcap2_av_frame_t* pFrame) {
    if (!pFrame) return QCAP_RS_ERROR_INVALID_PARAMETER;
    qcap2_av_frame_priv_t* p = (qcap2_av_frame_priv_t*)pFrame;
    if (!p->pDMABuf) return QCAP_RS_SUCCESSFUL;
    if (!p->pDMABuf->pVirAddr) return QCAP_RS_SUCCESSFUL;

    if (munmap(p->pDMABuf->pVirAddr, p->pDMABuf->dmabuf_size) < 0) {
        return QCAP_RS_ERROR_GENERAL;
    }

    p->pDMABuf->pVirAddr = nullptr;
    return QCAP_RS_SUCCESSFUL;
}

QRESULT qcap2_av_frame_alloc_mapped_dmabuf(qcap2_av_frame_t* pFrame, int nSize, int nProt) {
    QRESULT res = qcap2_av_frame_alloc_dmabuf(pFrame, nSize, nProt);
    if (res != QCAP_RS_SUCCESSFUL) return res;

    res = qcap2_av_frame_map_dmabuf(pFrame, nProt);
    if (res != QCAP_RS_SUCCESSFUL) {
        qcap2_av_frame_free_dmabuf(pFrame);
        return res;
    }

    return QCAP_RS_SUCCESSFUL;
}

QRESULT qcap2_av_frame_free_mapped_dmabuf(qcap2_av_frame_t* pFrame) {
    return qcap2_av_frame_free_dmabuf(pFrame);
}

// factory implementations

struct SystemVideoFrameBackend {
    qcap2_av_frame_t frame;
    qcap2_rcbuffer_video_info_t video_info;
    
    SystemVideoFrameBackend() {
        qcap2_av_frame_init(&frame);
        memset(&video_info, 0, sizeof(video_info));
        video_info.cb = sizeof(video_info);
    }
    ~SystemVideoFrameBackend() {
        qcap2_av_frame_free_buffer(&frame);
    }
};

static void system_video_frame_destroy(void* owner, void* user_data) {
    (void)user_data;
    delete (SystemVideoFrameBackend*)owner;
}

static QRESULT system_video_frame_query(void* owner, void* user_data, qcap2_rcbuffer_info_t* info) {
    (void)user_data;
    info->content_type = QCAP2_RCBUFFER_CONTENT_VIDEO_FRAME;
    info->memory_flags = QCAP2_RCBUFFER_MEMORY_SYSTEM;
    info->capability_flags = QCAP2_RCBUFFER_CAP_CPU_READ | QCAP2_RCBUFFER_CAP_CPU_WRITE | QCAP2_RCBUFFER_CAP_VIDEO_PLANES;
    info->owner = owner;
    return QCAP_RS_SUCCESSFUL;
}

static QRESULT system_video_frame_get_video_info(void* owner, void* user_data, qcap2_rcbuffer_video_info_t* info) {
    (void)user_data;
    SystemVideoFrameBackend* b = (SystemVideoFrameBackend*)owner;
    *info = b->video_info;
    return QCAP_RS_SUCCESSFUL;
}

static QRESULT system_video_frame_set_video_info(void* owner, void* user_data, const qcap2_rcbuffer_video_info_t* info) {
    (void)user_data;
    SystemVideoFrameBackend* b = (SystemVideoFrameBackend*)owner;
    b->video_info = *info;
    qcap2_av_frame_set_video_property(&b->frame, info->color_space_type, info->width, info->height);
    qcap2_av_frame_set_field_type(&b->frame, info->field_type);
    qcap2_av_frame_set_pts(&b->frame, info->pts);
    qcap2_av_frame_set_sample_time(&b->frame, info->sample_time);
    return QCAP_RS_SUCCESSFUL;
}

static QRESULT system_video_frame_get_plane(void* owner, void* user_data, int plane, qcap2_rcbuffer_plane_t* out) {
    (void)user_data;
    SystemVideoFrameBackend* b = (SystemVideoFrameBackend*)owner;
    uint8_t* buffers[4] = {0};
    int strides[4] = {0};
    qcap2_av_frame_get_buffer1(&b->frame, buffers, strides);

    if (plane < 0 || plane >= 4 || !buffers[plane]) {
        return QCAP_RS_ERROR_INVALID_PARAMETER;
    }

    out->data = buffers[plane];
    out->stride = strides[plane];
    out->size = 0;
    out->fd = -1;
    out->offset = 0;
    out->native_handle = NULL;
    return QCAP_RS_SUCCESSFUL;
}

static const qcap2_rcbuffer_ops_t system_video_frame_ops = {
    sizeof(qcap2_rcbuffer_ops_t),
    NULL, // begin_access
    NULL, // end_access
    system_video_frame_query,
    system_video_frame_get_video_info,
    system_video_frame_set_video_info,
    system_video_frame_get_plane,
    NULL, // get_packet_info
    NULL, // set_packet_info
    NULL, // get_handle
    NULL, // get_audio_info
    NULL  // set_audio_info
};

qcap2_rcbuffer_t* qcap2_rcbuffer_new_system_video_frame(const qcap2_video_frame_create_info_t* info) {
    if (!info || info->cb < sizeof(qcap2_video_frame_create_info_t)) return NULL;
    
    SystemVideoFrameBackend* b = new (std::nothrow) SystemVideoFrameBackend();
    if (!b) return NULL;
    
    qcap2_av_frame_set_video_property(&b->frame, info->color_space_type, info->width, info->height);
    if (!qcap2_av_frame_alloc_buffer(&b->frame, info->align, info->valign)) {
        delete b;
        return NULL;
    }

    b->video_info.color_space_type = info->color_space_type;
    b->video_info.width = info->width;
    b->video_info.height = info->height;
    b->video_info.field_type = QCAP2_FIELD_NONE;
    b->video_info.pts = 0;
    b->video_info.sample_time = 0.0;
    switch (info->color_space_type) {
    case QCAP_COLORSPACE_TYPE_NV12:
    case QCAP_COLORSPACE_TYPE_P010:
    case QCAP_COLORSPACE_TYPE_P210:
        b->video_info.plane_count = 2;
        break;
    case QCAP_COLORSPACE_TYPE_YV12:
    case QCAP_COLORSPACE_TYPE_I420:
    case QCAP_COLORSPACE_TYPE_YV24:
        b->video_info.plane_count = 3;
        break;
    default:
        b->video_info.plane_count = 1;
        break;
    }

    qcap2_rcbuffer_create_info_t create_info = {
        sizeof(create_info),
        b,
        NULL,
        system_video_frame_destroy,
        QCAP2_RCBUFFER_CONTENT_VIDEO_FRAME,
        QCAP2_RCBUFFER_MEMORY_SYSTEM,
        QCAP2_RCBUFFER_CAP_CPU_READ | QCAP2_RCBUFFER_CAP_CPU_WRITE | QCAP2_RCBUFFER_CAP_VIDEO_PLANES,
        &system_video_frame_ops
    };

    qcap2_rcbuffer_t* buf = qcap2_rcbuffer_new(&create_info);
    if (!buf) {
        delete b;
    }
    return buf;
}

struct SystemPacketBackend {
    qcap2_av_packet_t packet;
    qcap2_rcbuffer_packet_info_t packet_info;

    SystemPacketBackend() {
        qcap2_av_packet_init(&packet);
        memset(&packet_info, 0, sizeof(packet_info));
        packet_info.cb = sizeof(packet_info);
    }
    ~SystemPacketBackend() {
        qcap2_av_packet_free_buffer(&packet);
    }
};

static void system_packet_destroy(void* owner, void* user_data) {
    (void)user_data;
    delete (SystemPacketBackend*)owner;
}

static QRESULT system_packet_query(void* owner, void* user_data, qcap2_rcbuffer_info_t* info) {
    (void)user_data;
    info->content_type = QCAP2_RCBUFFER_CONTENT_PACKET;
    info->memory_flags = QCAP2_RCBUFFER_MEMORY_SYSTEM;
    info->capability_flags = QCAP2_RCBUFFER_CAP_CPU_READ | QCAP2_RCBUFFER_CAP_CPU_WRITE | QCAP2_RCBUFFER_CAP_PACKET_BYTES;
    info->owner = owner;
    return QCAP_RS_SUCCESSFUL;
}

static QRESULT system_packet_get_packet_info(void* owner, void* user_data, qcap2_rcbuffer_packet_info_t* info) {
    (void)user_data;
    SystemPacketBackend* b = (SystemPacketBackend*)owner;
    *info = b->packet_info;
    return QCAP_RS_SUCCESSFUL;
}

static QRESULT system_packet_set_packet_info(void* owner, void* user_data, const qcap2_rcbuffer_packet_info_t* info) {
    (void)user_data;
    SystemPacketBackend* b = (SystemPacketBackend*)owner;
    b->packet_info = *info;
    qcap2_av_packet_set_property(&b->packet, info->stream_index, info->is_keyframe);
    qcap2_av_packet_set_pts(&b->packet, info->pts);
    qcap2_av_packet_set_dts(&b->packet, info->dts);
    qcap2_av_packet_set_sample_time(&b->packet, info->sample_time);
    if (info->data && info->size > 0) {
        qcap2_av_packet_set_buffer(&b->packet, info->data, info->size);
    }
    return QCAP_RS_SUCCESSFUL;
}

static const qcap2_rcbuffer_ops_t system_packet_ops = {
    sizeof(qcap2_rcbuffer_ops_t),
    NULL, // begin_access
    NULL, // end_access
    system_packet_query,
    NULL, // get_video_info
    NULL, // set_video_info
    NULL, // get_plane
    system_packet_get_packet_info,
    system_packet_set_packet_info,
    NULL, // get_handle
    NULL, // get_audio_info
    NULL  // set_audio_info
};

qcap2_rcbuffer_t* qcap2_rcbuffer_new_system_packet(size_t capacity) {
    SystemPacketBackend* b = new (std::nothrow) SystemPacketBackend();
    if (!b) return NULL;

    if (capacity > 0) {
        if (!qcap2_av_packet_alloc_buffer(&b->packet, (int)capacity)) {
            delete b;
            return NULL;
        }
        uint8_t* buf_ptr = NULL;
        int buf_size = 0;
        qcap2_av_packet_get_buffer(&b->packet, &buf_ptr, &buf_size);
        b->packet_info.data = buf_ptr;
        b->packet_info.size = buf_size;
    }

    qcap2_rcbuffer_create_info_t create_info = {
        sizeof(create_info),
        b,
        NULL,
        system_packet_destroy,
        QCAP2_RCBUFFER_CONTENT_PACKET,
        QCAP2_RCBUFFER_MEMORY_SYSTEM,
        QCAP2_RCBUFFER_CAP_CPU_READ | QCAP2_RCBUFFER_CAP_CPU_WRITE | QCAP2_RCBUFFER_CAP_PACKET_BYTES,
        &system_packet_ops
    };

    qcap2_rcbuffer_t* buf = qcap2_rcbuffer_new(&create_info);
    if (!buf) {
        delete b;
    }
    return buf;
}

struct DmaBufVideoFrameBackend {
    qcap2_av_frame_t frame;
    qcap2_rcbuffer_video_info_t video_info;
    int prot;

    DmaBufVideoFrameBackend() {
        qcap2_av_frame_init(&frame);
        memset(&video_info, 0, sizeof(video_info));
        video_info.cb = sizeof(video_info);
        prot = PROT_READ | PROT_WRITE;
    }
    ~DmaBufVideoFrameBackend() {
        qcap2_av_frame_free_buffer(&frame);
    }
};

static void dmabuf_video_frame_destroy(void* owner, void* user_data) {
    (void)user_data;
    delete (DmaBufVideoFrameBackend*)owner;
}

static QRESULT dmabuf_video_frame_begin_access(void* owner, void* user_data, uint32_t flags, qcap2_rcbuffer_access_t* access) {
    (void)user_data;
    DmaBufVideoFrameBackend* b = (DmaBufVideoFrameBackend*)owner;
    
    if (flags & QCAP2_RCBUFFER_ACCESS_CPU) {
        QRESULT res = qcap2_av_frame_map_dmabuf(&b->frame, b->prot);
        if (res != QCAP_RS_SUCCESSFUL) return res;
        
        qcap2_dmabuf_t* dmabuf = NULL;
        if (qcap2_av_frame_get_dmabuf(&b->frame, &dmabuf) == QCAP_RS_SUCCESSFUL && dmabuf) {
            qcap2_av_frame_set_buffer(&b->frame, (uint8_t*)dmabuf->pVirAddr, (int)b->video_info.width);
        }
    }
    
    access->granted_flags = flags & (QCAP2_RCBUFFER_ACCESS_READ | QCAP2_RCBUFFER_ACCESS_WRITE | QCAP2_RCBUFFER_ACCESS_CPU | QCAP2_RCBUFFER_ACCESS_DEVICE | QCAP2_RCBUFFER_ACCESS_ZERO_COPY);
    return QCAP_RS_SUCCESSFUL;
}

static void dmabuf_video_frame_end_access(void* owner, void* user_data, qcap2_rcbuffer_access_t* access) {
    (void)user_data;
    DmaBufVideoFrameBackend* b = (DmaBufVideoFrameBackend*)owner;
    if (access->requested_flags & QCAP2_RCBUFFER_ACCESS_CPU) {
        qcap2_av_frame_unmap_dmabuf(&b->frame);
        qcap2_av_frame_set_buffer(&b->frame, NULL, 0);
    }
}

static QRESULT dmabuf_video_frame_query(void* owner, void* user_data, qcap2_rcbuffer_info_t* info) {
    (void)user_data;
    info->content_type = QCAP2_RCBUFFER_CONTENT_VIDEO_FRAME;
    info->memory_flags = QCAP2_RCBUFFER_MEMORY_DMABUF;
    info->capability_flags = QCAP2_RCBUFFER_CAP_CPU_READ | QCAP2_RCBUFFER_CAP_CPU_WRITE | QCAP2_RCBUFFER_CAP_VIDEO_PLANES | QCAP2_RCBUFFER_CAP_NATIVE_HANDLE | QCAP2_RCBUFFER_CAP_ZERO_COPY;
    info->owner = owner;
    return QCAP_RS_SUCCESSFUL;
}

static QRESULT dmabuf_video_frame_get_video_info(void* owner, void* user_data, qcap2_rcbuffer_video_info_t* info) {
    (void)user_data;
    DmaBufVideoFrameBackend* b = (DmaBufVideoFrameBackend*)owner;
    *info = b->video_info;
    return QCAP_RS_SUCCESSFUL;
}

static QRESULT dmabuf_video_frame_set_video_info(void* owner, void* user_data, const qcap2_rcbuffer_video_info_t* info) {
    (void)user_data;
    DmaBufVideoFrameBackend* b = (DmaBufVideoFrameBackend*)owner;
    b->video_info = *info;
    qcap2_av_frame_set_video_property(&b->frame, info->color_space_type, info->width, info->height);
    qcap2_av_frame_set_field_type(&b->frame, info->field_type);
    qcap2_av_frame_set_pts(&b->frame, info->pts);
    qcap2_av_frame_set_sample_time(&b->frame, info->sample_time);
    return QCAP_RS_SUCCESSFUL;
}

static QRESULT dmabuf_video_frame_get_plane(void* owner, void* user_data, int plane, qcap2_rcbuffer_plane_t* out) {
    (void)user_data;
    DmaBufVideoFrameBackend* b = (DmaBufVideoFrameBackend*)owner;
    
    if (plane < 0 || plane >= b->video_info.plane_count) {
        return QCAP_RS_ERROR_INVALID_PARAMETER;
    }

    uint8_t* buffers[4] = {0};
    int strides[4] = {0};
    qcap2_av_frame_get_buffer1(&b->frame, buffers, strides);

    qcap2_dmabuf_t* dmabuf = NULL;
    if (qcap2_av_frame_get_dmabuf(&b->frame, &dmabuf) != QCAP_RS_SUCCESSFUL || !dmabuf) {
        return QCAP_RS_ERROR_GENERAL;
    }

    out->data = buffers[plane];
    out->stride = strides[plane] > 0 ? strides[plane] : (int)b->video_info.width;
    out->size = dmabuf->dmabuf_size;
    out->fd = dmabuf->fd;
    out->offset = 0;
    out->native_handle = (void*)(uintptr_t)dmabuf->fd;
    return QCAP_RS_SUCCESSFUL;
}

static QRESULT dmabuf_video_frame_get_handle(void* owner, void* user_data, qcap2_rcbuffer_handle_type_t type, qcap2_rcbuffer_handle_t* out) {
    (void)user_data;
    DmaBufVideoFrameBackend* b = (DmaBufVideoFrameBackend*)owner;
    
    qcap2_dmabuf_t* dmabuf = NULL;
    if (qcap2_av_frame_get_dmabuf(&b->frame, &dmabuf) != QCAP_RS_SUCCESSFUL || !dmabuf) {
        return QCAP_RS_ERROR_GENERAL;
    }

    if (type == QCAP2_RCBUFFER_HANDLE_DMABUF_FD) {
        out->type = QCAP2_RCBUFFER_HANDLE_DMABUF_FD;
        out->u.fd = dmabuf->fd;
        out->size = dmabuf->dmabuf_size;
        return QCAP_RS_SUCCESSFUL;
    }
    return QCAP_RS_ERROR_NON_SUPPORT;
}

static const qcap2_rcbuffer_ops_t dmabuf_video_frame_ops = {
    sizeof(qcap2_rcbuffer_ops_t),
    dmabuf_video_frame_begin_access,
    dmabuf_video_frame_end_access,
    dmabuf_video_frame_query,
    dmabuf_video_frame_get_video_info,
    dmabuf_video_frame_set_video_info,
    dmabuf_video_frame_get_plane,
    NULL, // get_packet_info
    NULL, // set_packet_info
    dmabuf_video_frame_get_handle,
    NULL, // get_audio_info
    NULL  // set_audio_info
};

qcap2_rcbuffer_t* qcap2_rcbuffer_new_dmabuf_video_frame(const qcap2_dmabuf_frame_create_info_t* info) {
    if (!info || info->cb < sizeof(qcap2_dmabuf_frame_create_info_t)) return NULL;

    DmaBufVideoFrameBackend* b = new (std::nothrow) DmaBufVideoFrameBackend();
    if (!b) return NULL;

    b->prot = info->prot;
    qcap2_av_frame_set_video_property(&b->frame, info->color_space_type, info->width, info->height);
    
    int size = (int)(info->width * info->height * 4);
    if (qcap2_av_frame_alloc_dmabuf(&b->frame, size, info->prot) != QCAP_RS_SUCCESSFUL) {
        delete b;
        return NULL;
    }

    b->video_info.color_space_type = info->color_space_type;
    b->video_info.width = info->width;
    b->video_info.height = info->height;
    b->video_info.field_type = QCAP2_FIELD_NONE;
    b->video_info.pts = 0;
    b->video_info.sample_time = 0.0;
    b->video_info.plane_count = 1;

    qcap2_rcbuffer_create_info_t create_info = {
        sizeof(create_info),
        b,
        NULL,
        dmabuf_video_frame_destroy,
        QCAP2_RCBUFFER_CONTENT_VIDEO_FRAME,
        QCAP2_RCBUFFER_MEMORY_DMABUF,
        QCAP2_RCBUFFER_CAP_CPU_READ | QCAP2_RCBUFFER_CAP_CPU_WRITE | QCAP2_RCBUFFER_CAP_VIDEO_PLANES | QCAP2_RCBUFFER_CAP_NATIVE_HANDLE | QCAP2_RCBUFFER_CAP_ZERO_COPY,
        &dmabuf_video_frame_ops
    };

    qcap2_rcbuffer_t* buf = qcap2_rcbuffer_new(&create_info);
    if (!buf) {
        delete b;
    }
    return buf;
}

struct CudaVideoFrameBackend {
    qcap2_rcbuffer_video_info_t video_info;
    uintptr_t fake_cuda_ptr;

    CudaVideoFrameBackend() {
        memset(&video_info, 0, sizeof(video_info));
        video_info.cb = sizeof(video_info);
        fake_cuda_ptr = 0xDEADE000;
    }
};

static void cuda_video_frame_destroy(void* owner, void* user_data) {
    (void)user_data;
    delete (CudaVideoFrameBackend*)owner;
}

static QRESULT cuda_video_frame_query(void* owner, void* user_data, qcap2_rcbuffer_info_t* info) {
    (void)user_data;
    info->content_type = QCAP2_RCBUFFER_CONTENT_VIDEO_FRAME;
    info->memory_flags = QCAP2_RCBUFFER_MEMORY_CUDA_DEVICE;
    info->capability_flags = QCAP2_RCBUFFER_CAP_VIDEO_PLANES | QCAP2_RCBUFFER_CAP_NATIVE_HANDLE | QCAP2_RCBUFFER_CAP_ZERO_COPY;
    info->owner = owner;
    return QCAP_RS_SUCCESSFUL;
}

static QRESULT cuda_video_frame_get_video_info(void* owner, void* user_data, qcap2_rcbuffer_video_info_t* info) {
    (void)user_data;
    CudaVideoFrameBackend* b = (CudaVideoFrameBackend*)owner;
    *info = b->video_info;
    return QCAP_RS_SUCCESSFUL;
}

static QRESULT cuda_video_frame_set_video_info(void* owner, void* user_data, const qcap2_rcbuffer_video_info_t* info) {
    (void)user_data;
    CudaVideoFrameBackend* b = (CudaVideoFrameBackend*)owner;
    b->video_info = *info;
    return QCAP_RS_SUCCESSFUL;
}

static QRESULT cuda_video_frame_get_plane(void* owner, void* user_data, int plane, qcap2_rcbuffer_plane_t* out) {
    (void)user_data;
    CudaVideoFrameBackend* b = (CudaVideoFrameBackend*)owner;
    if (plane < 0 || plane >= b->video_info.plane_count) {
        return QCAP_RS_ERROR_INVALID_PARAMETER;
    }
    out->data = NULL;
    out->stride = (int)b->video_info.width * 4;
    out->size = out->stride * b->video_info.height;
    out->fd = -1;
    out->offset = 0;
    out->native_handle = (void*)b->fake_cuda_ptr;
    return QCAP_RS_SUCCESSFUL;
}

static QRESULT cuda_video_frame_get_handle(void* owner, void* user_data, qcap2_rcbuffer_handle_type_t type, qcap2_rcbuffer_handle_t* out) {
    (void)user_data;
    CudaVideoFrameBackend* b = (CudaVideoFrameBackend*)owner;
    if (type == QCAP2_RCBUFFER_HANDLE_CUDA_DEVICE_PTR) {
        out->type = QCAP2_RCBUFFER_HANDLE_CUDA_DEVICE_PTR;
        out->u.value = b->fake_cuda_ptr;
        out->size = b->video_info.width * b->video_info.height * 4;
        return QCAP_RS_SUCCESSFUL;
    }
    return QCAP_RS_ERROR_NON_SUPPORT;
}

static const qcap2_rcbuffer_ops_t cuda_video_frame_ops = {
    sizeof(qcap2_rcbuffer_ops_t),
    NULL, // begin_access
    NULL, // end_access
    cuda_video_frame_query,
    cuda_video_frame_get_video_info,
    cuda_video_frame_set_video_info,
    cuda_video_frame_get_plane,
    NULL, // get_packet_info
    NULL, // set_packet_info
    cuda_video_frame_get_handle,
    NULL, // get_audio_info
    NULL  // set_audio_info
};

qcap2_rcbuffer_t* qcap2_rcbuffer_new_cuda_video_frame(const qcap2_cuda_frame_create_info_t* info) {
    if (!info || info->cb < sizeof(qcap2_cuda_frame_create_info_t)) return NULL;

    CudaVideoFrameBackend* b = new (std::nothrow) CudaVideoFrameBackend();
    if (!b) return NULL;

    b->video_info.color_space_type = info->color_space_type;
    b->video_info.width = info->width;
    b->video_info.height = info->height;
    b->video_info.field_type = QCAP2_FIELD_NONE;
    b->video_info.pts = 0;
    b->video_info.sample_time = 0.0;
    b->video_info.plane_count = 1;

    qcap2_rcbuffer_create_info_t create_info = {
        sizeof(create_info),
        b,
        NULL,
        cuda_video_frame_destroy,
        QCAP2_RCBUFFER_CONTENT_VIDEO_FRAME,
        QCAP2_RCBUFFER_MEMORY_CUDA_DEVICE,
        QCAP2_RCBUFFER_CAP_VIDEO_PLANES | QCAP2_RCBUFFER_CAP_NATIVE_HANDLE | QCAP2_RCBUFFER_CAP_ZERO_COPY,
        &cuda_video_frame_ops
    };

    qcap2_rcbuffer_t* buf = qcap2_rcbuffer_new(&create_info);
    if (!buf) {
        delete b;
    }
    return buf;
}

#ifdef __cplusplus
}
#endif
