#ifndef MOCK_QCAP_H2_H
#define MOCK_QCAP_H2_H

#include "qcap_mock_common.h"
#include "mock_qcap_osd.h"
#include "mock_qcap_linux.h"
#include "mock_qcap_common.h"
#include "mock_qcap_burning.h"
#include "mock_qcap_timer.h"
#include "mock_qcap_helper.h"
#include "mock_qcap_device.h"
#include "mock_qcap_onvif.h"
#include "mock_qcap_recording.h"
#include "mock_qcap_hl7.h"
#include "mock_qcap_ccvt.h"
#include "mock_qcap_types.h"
#include "mock_qcap_broadcast.h"
#include "mock_qcap_dicom.h"
#include "mock_qcap_h.h"
#include "mock_qcap_windef.h"
#include "mock_qcap_hi3531a.h"
#include "mock_qcap_animation.h"
#include "mock_qcap_webrtc.h"
#include "mock_qcap_sip.h"
#include "mock_qcap_callbacks.h"
#include "mock_qcap_system.h"
#include "mock_qcap_serial.h"
#include "mock_qcap_virtualcamera.h"
#include "mock_qcap_playback.h"

#ifdef __cplusplus
extern "C"
{
#endif

// Typedefs
typedef QRETURN (QCAP_EXPORT *PF_MEDIA_BROADCAST_SERVER_CALLBACK)( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, double dSampleTime /*IN*/, BYTE * pStreamBuffer /*IN*/, ULONG nStreamBufferLen /*IN*/, PVOID pUserData /*IN*/ );

// Function Declarations
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_H2_INITIALIZE();
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_H2_UNINITIALIZE();
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_BUFFER_ADD_REF(BYTE * pBuffer, ULONG nBufferLen);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_BUFFER_RELEASE(BYTE * pBuffer, ULONG nBufferLen);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_BUFFER_GET_DATA(BYTE * pBuffer, ULONG nBufferLen, PVOID* ppData);

#ifdef __cplusplus
}
#endif

#endif // MOCK_QCAP_H2_H
