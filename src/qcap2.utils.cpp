#include "qcap2.h"
#include "qcap2.utils.h"
#include "qcap2.buffer.h"
#include <time.h>
#include <string.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

int64_t qcap2_get_time() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (int64_t)ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
}

void qcap2_get_build_config(qcap2_build_config_t* pBuildConfig) {
    if (!pBuildConfig) return;
    pBuildConfig->major = QCAP2_VERSION_MAJOR;
    pBuildConfig->minor = QCAP2_VERSION_MINOR;
    pBuildConfig->patch = QCAP2_VERSION_PATCH;
    pBuildConfig->qcap_major = QCAP_API_VERSION_MAJOR;
    pBuildConfig->qcap_minor = QCAP_API_VERSION_MINOR;
    pBuildConfig->qcap_patch = QCAP_API_VERSION_PATCH;
    pBuildConfig->build_date = __DATE__;
    pBuildConfig->build_time = __TIME__;
    pBuildConfig->branch = QCAP2_BUILD_BRANCH;
    pBuildConfig->commit = QCAP2_BUILD_COMMIT;
    pBuildConfig->mods = "";
}

QRESULT qcap2_save_raw_video_frame(qcap2_rcbuffer_t* pRCBuffer, const char* prefix) {
    if (!pRCBuffer || !prefix) return QCAP_RS_ERROR_GENERAL;

    qcap2_rcbuffer_access_t access;
    memset(&access, 0, sizeof(access));
    access.cb = sizeof(access);
    QRESULT r = qcap2_rcbuffer_begin_access(pRCBuffer, QCAP2_RCBUFFER_ACCESS_READ | QCAP2_RCBUFFER_ACCESS_CPU, &access);
    if (r != QCAP_RS_SUCCESSFUL) return QCAP_RS_ERROR_GENERAL;

    qcap2_rcbuffer_video_info_t vinfo;
    memset(&vinfo, 0, sizeof(vinfo));
    vinfo.cb = sizeof(vinfo);
    if (qcap2_rcbuffer_get_video_info(pRCBuffer, &vinfo) == QCAP_RS_SUCCESSFUL) {
        qcap2_rcbuffer_plane_t plane0;
        memset(&plane0, 0, sizeof(plane0));
        plane0.cb = sizeof(plane0);
        if (qcap2_rcbuffer_get_plane(pRCBuffer, 0, &plane0) == QCAP_RS_SUCCESSFUL && plane0.data) {
            char filename[256];
            snprintf(filename, sizeof(filename), "%s_%dx%d.raw", prefix, (int)vinfo.width, (int)vinfo.height);
            FILE* fp = fopen(filename, "wb");
            if (fp) {
                size_t size = plane0.size > 0 ? plane0.size : (size_t)plane0.stride * vinfo.height;
                fwrite(plane0.data, 1, size, fp);
                fclose(fp);
            }
        }
    }

    qcap2_rcbuffer_end_access(pRCBuffer, &access);
    return QCAP_RS_SUCCESSFUL;
}

QRESULT qcap2_print_video_frame_info(qcap2_rcbuffer_t* pRCBuffer, const char* prefix) {
    if (!pRCBuffer || !prefix) return QCAP_RS_ERROR_GENERAL;

    qcap2_rcbuffer_video_info_t vinfo;
    memset(&vinfo, 0, sizeof(vinfo));
    vinfo.cb = sizeof(vinfo);
    if (qcap2_rcbuffer_get_video_info(pRCBuffer, &vinfo) == QCAP_RS_SUCCESSFUL) {
        printf("[%s] Video Frame Info: ColorSpaceType=%lu, Width=%lu, Height=%lu, PTS=%lld\n",
               prefix, vinfo.color_space_type, vinfo.width, vinfo.height, (long long)vinfo.pts);
        return QCAP_RS_SUCCESSFUL;
    }
    return QCAP_RS_ERROR_GENERAL;
}

QRESULT qcap2_print_audio_sample_info(qcap2_rcbuffer_t* pRCBuffer, const char* prefix) {
    if (!pRCBuffer || !prefix) return QCAP_RS_ERROR_GENERAL;

    qcap2_rcbuffer_audio_info_t ainfo;
    memset(&ainfo, 0, sizeof(ainfo));
    ainfo.cb = sizeof(ainfo);
    if (qcap2_rcbuffer_get_audio_info(pRCBuffer, &ainfo) == QCAP_RS_SUCCESSFUL) {
        printf("[%s] Audio Sample Info: Channels=%lu, SampleFmt=%lu, SampleFreq=%lu, FrameSize=%lu, PTS=%lld\n",
               prefix, ainfo.channels, ainfo.sample_fmt, ainfo.sample_frequency, ainfo.frame_size, (long long)ainfo.pts);
        return QCAP_RS_SUCCESSFUL;
    }
    return QCAP_RS_ERROR_GENERAL;
}

QRESULT qcap2_print_packet_info(qcap2_rcbuffer_t* pRCBuffer, const char* prefix) {
    if (!pRCBuffer || !prefix) return QCAP_RS_ERROR_GENERAL;
    printf("[%s] Packet Info: Data pointer %p\n", prefix, pRCBuffer);
    return QCAP_RS_SUCCESSFUL;
}

QRESULT qcap2_fill_video_test_pattern(qcap2_rcbuffer_t* pRCBuffer, int nType) {
    if (!pRCBuffer) return QCAP_RS_ERROR_GENERAL;

    qcap2_rcbuffer_access_t access;
    memset(&access, 0, sizeof(access));
    access.cb = sizeof(access);
    QRESULT r = qcap2_rcbuffer_begin_access(pRCBuffer, QCAP2_RCBUFFER_ACCESS_WRITE | QCAP2_RCBUFFER_ACCESS_CPU, &access);
    if (r != QCAP_RS_SUCCESSFUL) return QCAP_RS_ERROR_GENERAL;

    qcap2_rcbuffer_video_info_t vinfo;
    memset(&vinfo, 0, sizeof(vinfo));
    vinfo.cb = sizeof(vinfo);
    if (qcap2_rcbuffer_get_video_info(pRCBuffer, &vinfo) == QCAP_RS_SUCCESSFUL) {
        qcap2_rcbuffer_plane_t plane0;
        memset(&plane0, 0, sizeof(plane0));
        plane0.cb = sizeof(plane0);
        if (qcap2_rcbuffer_get_plane(pRCBuffer, 0, &plane0) == QCAP_RS_SUCCESSFUL && plane0.data) {
            uint8_t fill_val = (uint8_t)(nType & 0xFF);
            size_t size = plane0.size > 0 ? plane0.size : (size_t)plane0.stride * vinfo.height;
            memset(plane0.data, fill_val, size);
        }
    }

    qcap2_rcbuffer_end_access(pRCBuffer, &access);
    return QCAP_RS_SUCCESSFUL;
}

QRESULT qcap2_load_picture(qcap2_rcbuffer_t* pRCBuffer, const char* strFilePath) {
    if (!pRCBuffer || !strFilePath) return QCAP_RS_ERROR_GENERAL;
    // Mock implementation of loading a picture
    return QCAP_RS_SUCCESSFUL;
}

QRESULT qcap2_get_picture_info(const char* strFilePath, qcap2_video_format_t* pVideoFormat) {
    if (!strFilePath || !pVideoFormat) return QCAP_RS_ERROR_GENERAL;
    // Mock implementation
    return QCAP_RS_SUCCESSFUL;
}

const char* qcap2_get_pix_fmt_name(int nFormat) {
    switch (nFormat) {
        case 0: return "PIX_FMT_RGB24";
        case 1: return "PIX_FMT_YUV420P";
        case 2: return "PIX_FMT_NV12";
        case 3: return "PIX_FMT_YUYV422";
        default: return "UNKNOWN_PIX_FMT";
    }
}

const char* qcap2_get_sample_fmt_name(int nFormat) {
    switch (nFormat) {
        case 0: return "SAMPLE_FMT_S16";
        case 1: return "SAMPLE_FMT_FLT";
        case 2: return "SAMPLE_FMT_S32";
        default: return "UNKNOWN_SAMPLE_FMT";
    }
}

qcap2_rational_t qcap2_d2q(double d, int nMax) {
    qcap2_rational_t r;
    int sign = (d < 0) ? -1 : 1;
    d = (d < 0) ? -d : d;

    if (d == 0) {
        r.num = 0;
        r.den = 1;
        return r;
    }

    if (d > nMax) {
        r.num = sign * nMax;
        r.den = 1;
        return r;
    }

    int best_num = 0, best_den = 1;
    double best_err = d;

    for (int den = 1; den <= nMax; den++) {
        int num = (int)(d * den + 0.5);
        if (num > nMax) break;
        double err = (double)num / den - d;
        if (err < 0) err = -err;

        if (err < best_err) {
            best_num = num;
            best_den = den;
            best_err = err;
            if (err == 0) break;
        }
    }

    r.num = sign * best_num;
    r.den = best_den;
    return r;
}

#define MAX_DEBUG_VALUES 64
static int g_debug_values[MAX_DEBUG_VALUES] = {0};

int qcap2_debug_get(int n) {
    if (n >= 0 && n < MAX_DEBUG_VALUES) {
        return __sync_fetch_and_add(&g_debug_values[n], 0);
    }
    return 0;
}

void qcap2_debug_set(int n, int v) {
    if (n >= 0 && n < MAX_DEBUG_VALUES) {
        __sync_lock_test_and_set(&g_debug_values[n], v);
    }
}

int qcap2_debug_fetch_add(int n, int v) {
    if (n >= 0 && n < MAX_DEBUG_VALUES) {
        return __sync_fetch_and_add(&g_debug_values[n], v);
    }
    return 0;
}

int qcap2_debug_fetch_sub(int n, int v) {
    if (n >= 0 && n < MAX_DEBUG_VALUES) {
        return __sync_fetch_and_sub(&g_debug_values[n], v);
    }
    return 0;
}

#ifdef __cplusplus
}
#endif /* __cplusplus */
