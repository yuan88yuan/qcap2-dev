#ifndef __QCAP2_UTILS_H__
#define __QCAP2_UTILS_H__

#include "qcap2.types.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

// utilities
int64_t qcap2_get_time();
void qcap2_get_build_config(qcap2_build_config_t* pBuildConfig);
QRESULT qcap2_save_raw_video_frame(qcap2_rcbuffer_t* pRCBuffer, const char* prefix);
QRESULT qcap2_print_video_frame_info(qcap2_rcbuffer_t* pRCBuffer, const char* prefix);
QRESULT qcap2_print_audio_sample_info(qcap2_rcbuffer_t* pRCBuffer, const char* prefix);
QRESULT qcap2_print_packet_info(qcap2_rcbuffer_t* pRCBuffer, const char* prefix);
QRESULT qcap2_fill_video_test_pattern(qcap2_rcbuffer_t* pRCBuffer, int nType); // qcap2_test_pattern_type_t
QRESULT qcap2_load_picture(qcap2_rcbuffer_t* pRCBuffer, const char* strFilePath);
QRESULT qcap2_get_picture_info(const char* strFilePath, qcap2_video_format_t* pVideoFormat);
const char* qcap2_get_pix_fmt_name(int nFormat);
const char* qcap2_get_sample_fmt_name(int nFormat);
qcap2_rational_t qcap2_d2q(double d, int nMax);

// debug
int qcap2_debug_get(int n);
void qcap2_debug_set(int n, int v);
int qcap2_debug_fetch_add(int n, int v);
int qcap2_debug_fetch_sub(int n, int v);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif // __QCAP2_UTILS_H__
