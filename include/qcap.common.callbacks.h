#ifndef __QCAP_COMMON_CALLBACKS_H__
#define __QCAP_COMMON_CALLBACKS_H__

#include "qcap.common.core.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef QRETURN (QCAP_EXPORT *PF_MEDIA_BROADCAST_SERVER_CALLBACK)( PVOID pServer, UINT iSessionNum, double dSampleTime, BYTE * pStreamBuffer, ULONG nStreamBufferLen, PVOID pUserData );
typedef QRETURN (QCAP_EXPORT *PF_BACKCHANNEL_BROADCAST_SERVER_PLAY_CALLBACK)( PVOID pServer, UINT iSessionNum, PVOID pUserData );
typedef QRETURN (QCAP_EXPORT *PF_BACKCHANNEL_BROADCAST_SERVER_STOP_CALLBACK)( PVOID pServer, UINT iSessionNum, PVOID pUserData );
typedef QRETURN (QCAP_EXPORT *PF_BACKCHANNEL_BROADCAST_SERVER_AUDIO_DECODED_CALLBACK)( PVOID pServer, UINT iSessionNum, double dSampleTime, BYTE * pFrameBuffer, ULONG nFrameBufferLen, PVOID pUserData );

typedef QRETURN (QCAP_EXPORT *PF_CLIENT_CONNECTED_BROADCAST_SERVER_CALLBACK)( PVOID pServer, UINT iSessionNum, PVOID pConnectionInfos, PVOID pUserData );
typedef QRETURN (QCAP_EXPORT *PF_CLIENT_DISCONNECTED_BROADCAST_SERVER_CALLBACK)( PVOID pServer, UINT iSessionNum, PVOID pConnectionInfos, PVOID pUserData );
typedef QRETURN (QCAP_EXPORT *PF_DANTE_SERVER_MESSAGE_CALLBACK)( PVOID pServer /*IN*/, UINT nVideoChannel /*IN*/, DWORD dwFlags /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_NDI_METADATA_BROADCAST_CLIENT_CALLBACK)( PVOID pClient, UINT iSessionNum, int length, int64_t timecode, const char* p_data, PVOID pUserData );
typedef QRETURN (QCAP_EXPORT *PF_NDI_DISCOVERY_SERVICE_CONNECTED_BROADCAST_CLIENT_CALLBACK)( PVOID pClient, UINT iSessionNum, BOOL bServiceConnected, CHAR * pszNDIName, CHAR * pszGroupName, PVOID pUserData );

typedef QRETURN (QCAP_EXPORT *PF_SHARE_RECORD_CALLBACK)( UINT iRecNum /*IN*/, BYTE * pStreamBuffer /*IN*/, ULONG nStreamBufferLen /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_PATGEN_FORMAT_CHANGED_CALLBACK)(PVOID pPatGen, ULONG nColorSpaceType, ULONG nVideoWidth, ULONG nVideoHeight, BOOL bVideoIsInterleaved, double dVideoFrameRate, ULONG nAudioChannels, ULONG nAudioBitsPerSample, ULONG nAudioSampleFrequency, PVOID pUserData);
typedef QRETURN (QCAP_EXPORT *PF_PATGEN_VIDEO_PREVIEW_CALLBACK)(PVOID pPatGen, double dSampleTime, BYTE * pFrameBuffer, ULONG nFrameBufferLen, PVOID pUserData);
typedef QRETURN (QCAP_EXPORT *PF_PATGEN_AUDIO_PREVIEW_CALLBACK)(PVOID pPatGen, double dSampleTime, BYTE * pFrameBuffer, ULONG nFrameBufferLen, PVOID pUserData);

typedef QRETURN (QCAP_EXPORT *PF_UDEVMON_BIND_CALLBACK)(PVOID pUdevMonitor, ULONG pDeviceInfos[3], PVOID pUserData);
typedef QRETURN (QCAP_EXPORT *PF_UDEVMON_UNBIND_CALLBACK)(PVOID pUdevMonitor, PVOID pUserData);

typedef QRETURN (QCAP_EXPORT *PF_VIDEO_FILE_CALLBACK)( PVOID pFile, double dSampleTime, BYTE * pStreamBuffer, ULONG nStreamBufferLen, BOOL bIsKeyFrame, PVOID pUserData);
typedef QRETURN (QCAP_EXPORT *PF_AUDIO_FILE_CALLBACK)( PVOID pFile, double dSampleTime, BYTE * pStreamBuffer, ULONG nStreamBufferLen, PVOID pUserData);
typedef QRETURN (QCAP_EXPORT *PF_DANTE_SERVER_TX_AUDIO_REQUEST_CALLBACK)( PVOID pServer /*IN*/, double dSampleTime /*IN*/, PVOID pUserData /*IN*/ );
typedef QRETURN (QCAP_EXPORT *PF_DANTE_SERVER_NO_RESPOND_CALLBACK)( PVOID pServer /*IN*/, BOOL bActivate, PVOID pUserData /*IN*/ );
typedef QRETURN (QCAP_EXPORT *PF_DANTE_SERVER_MESSAGE_CALLBACK1)( PVOID pServer /*IN*/, UINT nVideoChannel /*IN*/, DWORD dwFlags /*IN*/, CHAR* pszTransmitterIp /*IN*/, CHAR* pszReceiverIp /*IN*/, UINT nPort /*IN*/, PVOID pUserData /*IN*/ );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif // __QCAP_COMMON_CALLBACKS_H__
