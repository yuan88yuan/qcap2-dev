#ifndef __QCAP2_DRM_H__
#define __QCAP2_DRM_H__

#include "qcap2.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

// utilities
int qcap2_get_drm_fd();
void qcap2_put_drm_fd(int fd);

// qcap2_video_sink_t
void qcap2_video_sink_set_connector_id(qcap2_video_sink_t* pThis, uint32_t nConnectorId);
void qcap2_video_sink_set_crtc_id(qcap2_video_sink_t* pThis, uint32_t nCrtcId);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif // __QCAP2_DRM_H__