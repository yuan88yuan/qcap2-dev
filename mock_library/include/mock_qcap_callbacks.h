#ifndef MOCK_QCAP_CALLBACKS_H
#define MOCK_QCAP_CALLBACKS_H

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
#include "mock_qcap_h2.h"
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
#include "mock_qcap_system.h"
#include "mock_qcap_serial.h"
#include "mock_qcap_virtualcamera.h"
#include "mock_qcap_playback.h"

#ifdef __cplusplus
extern "C"
{
#endif

// Typedefs
typedef QRETURN (QCAP_EXPORT *PF_AUDIO_DECODER_MX_SHARE_RECORD_CALLBACK)( UINT iRecNum /*IN*/, UINT iTrackNum /*IN*/, double dSampleTime /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, PVOID pUserData /*IN*/ );
typedef QRETURN (QCAP_EXPORT *PF_AUDIO_DECODER_SHARE_RECORD_CALLBACK)( UINT iRecNum /*IN*/, double dSampleTime /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, PVOID pUserData /*IN*/ );
typedef QRETURN (QCAP_EXPORT *PF_AUDIO_DISPLAY_SHARE_RECORD_CALLBACK)( UINT iRecNum /*IN*/, double dSampleTime /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, PVOID pUserData /*IN*/ );
typedef QRETURN (QCAP_EXPORT *PF_AUDIO_MX_SHARE_RECORD_CALLBACK)( UINT iRecNum /*IN*/, UINT iTrackNum /*IN*/, double dSampleTime /*IN*/, BYTE * pStreamBuffer /*IN*/, ULONG nStreamBufferLen /*IN*/, PVOID pUserData /*IN*/ );
typedef QRETURN (QCAP_EXPORT *PF_AUDIO_PREVIEW_CALLBACK)( PVOID pDevice /*IN*/, double dSampleTime /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, PVOID pUserData /*IN*/ );
typedef QRETURN (QCAP_EXPORT *PF_AUDIO_RECORD_CALLBACK)( PVOID pDevice /*IN*/, UINT iRecNum /*IN*/, double dSampleTime /*IN*/, BYTE * pStreamBuffer /*IN*/, ULONG nStreamBufferLen /*IN*/, PVOID pUserData /*IN*/ );
typedef QRETURN (QCAP_EXPORT *PF_AUDIO_SHARE_RECORD_CALLBACK)( UINT iRecNum /*IN*/, double dSampleTime /*IN*/, BYTE * pStreamBuffer /*IN*/, ULONG nStreamBufferLen /*IN*/, PVOID pUserData /*IN*/ );
typedef QRETURN (QCAP_EXPORT *PF_AUDIO_SHARE_RECORD_MEDIA_TIMER_CALLBACK)( UINT iRecNum /*IN*/, double dSampleTime /*IN*/, double dDelayTime /*IN*/, PVOID pUserData /*IN*/ );
typedef QRETURN (QCAP_EXPORT *PF_FORMAT_CHANGED_CALLBACK)( PVOID pDevice /*IN*/, ULONG nVideoInput /*IN*/, ULONG nAudioInput /*IN*/, ULONG nVideoWidth /*IN*/, ULONG nVideoHeight /*IN*/, BOOL bVideoIsInterleaved /*IN*/, double dVideoFrameRate /*IN*/, ULONG nAudioChannels /*IN*/, ULONG nAudioBitsPerSample /*IN*/, ULONG nAudioSampleFrequency /*IN*/, PVOID pUserData /*IN*/ );
typedef QRETURN (QCAP_EXPORT *PF_FORMAT_CHANGED_CALLBACK_EX)( PVOID pDevice /*IN*/, ULONG nVideoInput /*IN*/, ULONG nAudioInput /*IN*/, ULONG nVideoWidth /*IN*/, ULONG nVideoHeight /*IN*/, BOOL bVideoIsInterleaved /*IN*/, double dVideoNativeFrameRate /*IN*/, double dVideoGrabFrameRate /*IN*/, ULONG nAudioChannels /*IN*/, ULONG nAudioBitsPerSample /*IN*/, ULONG nAudioSampleFrequency /*IN*/, PVOID pUserData /*IN*/ );
typedef QRETURN (QCAP_EXPORT *PF_MEDIA_RECORD_CALLBACK)( PVOID pDevice /*IN*/, UINT iRecNum /*IN*/, double dSampleTime /*IN*/, BYTE * pStreamBuffer /*IN*/, ULONG nStreamBufferLen /*IN*/, PVOID pUserData /*IN*/ );
typedef QRETURN (QCAP_EXPORT *PF_MEDIA_SHARE_RECORD_CALLBACK)( UINT iRecNum /*IN*/, double dSampleTime /*IN*/, BYTE * pStreamBuffer /*IN*/, ULONG nStreamBufferLen /*IN*/, PVOID pUserData /*IN*/ );
typedef QRETURN (QCAP_EXPORT *PF_NO_SIGNAL_DETECTED_CALLBACK)( PVOID pDevice /*IN*/, ULONG nVideoInput /*IN*/, ULONG nAudioInput /*IN*/, PVOID pUserData /*IN*/ );
typedef QRETURN (QCAP_EXPORT *PF_RECORD_DONE_CALLBACK)( PVOID pDevice /*IN*/, UINT iRecNum /*IN*/, CHAR * pszFilePathName /*IN*/, PVOID pUserData /*IN*/ );
typedef QRETURN (QCAP_EXPORT *PF_RECORD_FAIL_CALLBACK)( PVOID pDevice /*IN*/, UINT iRecNum /*IN*/, CHAR * pszFilePathName /*IN*/, QRESULT nErrorStatus /*IN*/, PVOID pUserData /*IN*/ );
typedef QRETURN (QCAP_EXPORT *PF_SHARE_RECORD_DONE_CALLBACK)( UINT iRecNum /*IN*/, CHAR * pszFilePathName /*IN*/, PVOID pUserData /*IN*/ );
typedef QRETURN (QCAP_EXPORT *PF_SHARE_RECORD_FAIL_CALLBACK)( UINT iRecNum /*IN*/, CHAR * pszFilePathName /*IN*/, QRESULT nErrorStatus /*IN*/, PVOID pUserData /*IN*/ );
typedef QRETURN (QCAP_EXPORT *PF_SHARE_RECORD_SNAPSHOT_DONE_CALLBACK)( UINT iRecNum /*IN*/, CHAR * pszFilePathName /*IN*/, PVOID pUserData /*IN*/ );
typedef QRETURN (QCAP_EXPORT *PF_SHARE_RECORD_SNAPSHOT_STREAM_CALLBACK)( UINT iRecNum /*IN*/, CHAR * pszFilePathName /*IN*/, BYTE * pStreamBuffer /*IN*/, ULONG nStreamBufferLen /*IN*/, PVOID pUserData /*IN*/ );
typedef QRETURN (QCAP_EXPORT *PF_SIGNAL_REMOVED_CALLBACK)( PVOID pDevice /*IN*/, ULONG nVideoInput /*IN*/, ULONG nAudioInput /*IN*/, PVOID pUserData /*IN*/ );
typedef QRETURN (QCAP_EXPORT *PF_SNAPSHOT_DONE_CALLBACK)( PVOID pDevice /*IN*/, CHAR * pszFilePathName /*IN*/, PVOID pUserData /*IN*/ );
typedef QRETURN (QCAP_EXPORT *PF_SNAPSHOT_STREAM_CALLBACK)( PVOID pDevice /*IN*/, CHAR * pszFilePathName /*IN*/, BYTE * pStreamBuffer /*IN*/, ULONG nStreamBufferLen /*IN*/, PVOID pUserData /*IN*/ );
typedef QRETURN (QCAP_EXPORT *PF_VIDEO_DECODER_SHARE_RECORD_CALLBACK)( UINT iRecNum /*IN*/, double dSampleTime /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, PVOID pUserData /*IN*/ );
typedef QRETURN (QCAP_EXPORT *PF_VIDEO_DISPLAY_SHARE_RECORD_CALLBACK)( UINT iRecNum /*IN*/, double dSampleTime /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, PVOID pUserData /*IN*/ );
typedef QRETURN (QCAP_EXPORT *PF_VIDEO_HARDWARE_ENCODER_CALLBACK)( PVOID pDevice /*IN*/, UINT iRecNum /*IN*/, double dSampleTime /*IN*/, BYTE * pStreamBuffer /*IN*/, ULONG nStreamBufferLen /*IN*/, BOOL bIsKeyFrame /*IN*/, PVOID pUserData /*IN*/ );
typedef QRETURN (QCAP_EXPORT *PF_VIDEO_PREVIEW_CALLBACK)( PVOID pDevice /*IN*/, double dSampleTime /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, PVOID pUserData /*IN*/ );
typedef QRETURN (QCAP_EXPORT *PF_VIDEO_RECORD_CALLBACK)( PVOID pDevice /*IN*/, UINT iRecNum /*IN*/, double dSampleTime /*IN*/, BYTE * pStreamBuffer /*IN*/, ULONG nStreamBufferLen /*IN*/, BOOL bIsKeyFrame /*IN*/, PVOID pUserData /*IN*/ );
typedef QRETURN (QCAP_EXPORT *PF_VIDEO_SHARE_RECORD_CALLBACK)( UINT iRecNum /*IN*/, double dSampleTime /*IN*/, BYTE * pStreamBuffer /*IN*/, ULONG nStreamBufferLen /*IN*/, BOOL bIsKeyFrame /*IN*/, PVOID pUserData /*IN*/ );
typedef QRETURN (QCAP_EXPORT *PF_VIDEO_SHARE_RECORD_MEDIA_TIMER_CALLBACK)( UINT iRecNum /*IN*/, double dSampleTime /*IN*/, double dDelayTime /*IN*/, PVOID pUserData /*IN*/ );
typedef QRETURN (QCAP_EXPORT *PF_VIDEO_VERTICAL_ANCILLARY_DATA_CALLBACK)( PVOID pDevice /*IN*/, double dSampleTime /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, PVOID pUserData /*IN*/ );

// Function Declarations

#ifdef __cplusplus
}
#endif

#endif // MOCK_QCAP_CALLBACKS_H
