#ifndef QCAP_BROADCAST_H
#define QCAP_BROADCAST_H

#include "qcap.types.h"

#ifdef __cplusplus
extern "C"
{
#endif

// ##########################################################################################################################################################################################
// #
// # BROADCASTING SERVER FUNCTIONS (RTSP/RTMP/HLS/TS/MMS/NDI) (2D/3D)
// #
// ##########################################################################################################################################################################################
//
typedef QRETURN (QCAP_EXPORT *PF_BROADCAST_SERVER_PTZ_COMMAND_CALLBACK)( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, ULONG nCommand /*IN*/, double dParam1 /*IN*/, double dParam2 /*IN*/, double dParam3 /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_BROADCAST_SERVER_BACKCHANNEL_CALLBACK)( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, ULONG nBackChannelID /*IN*/, ULONG nAudioEncoderFormat /*IN*/, ULONG nAudioChannels /*IN*/, ULONG nAudioBitsPerSample /*IN*/, ULONG nAudioSampleFrequency /*IN*/, double dSampleTime /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_BROADCAST_SERVER_GET_CUSTOM_PROPERTY_CALLBACK)( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, CHAR * pszProperty /*IN*/, CHAR * pszValue /*OUT*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_BROADCAST_SERVER_SET_CUSTOM_PROPERTY_CALLBACK)( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, CHAR * pszProperty /*IN*/, CHAR * pszValue /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_BROADCAST_SERVER_SNAPSHOT_DONE_CALLBACK)( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, CHAR * pszFilePathName /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_BROADCAST_SERVER_SNAPSHOT_STREAM_CALLBACK)( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, CHAR * pszFilePathName /*IN*/, BYTE * pStreamBuffer /*IN*/, ULONG nStreamBufferLen /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_VIDEO_BROADCAST_SERVER_CALLBACK)( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, double dSampleTime /*IN*/, BYTE * pStreamBuffer /*IN*/, ULONG nStreamBufferLen /*IN*/, BOOL bIsKeyFrame /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_AUDIO_BROADCAST_SERVER_CALLBACK)( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, double dSampleTime /*IN*/, BYTE * pStreamBuffer /*IN*/, ULONG nStreamBufferLen /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_AUDIO_MX_BROADCAST_SERVER_CALLBACK)( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, UINT iTrackNum /*IN*/, double dSampleTime /*IN*/, BYTE * pStreamBuffer /*IN*/, ULONG nStreamBufferLen /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_VIDEO_DECODER_BROADCAST_SERVER_CALLBACK)( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, double dSampleTime /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_AUDIO_DECODER_BROADCAST_SERVER_CALLBACK)( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, double dSampleTime /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_AUDIO_DECODER_MX_BROADCAST_SERVER_CALLBACK)( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, UINT iTrackNum /*IN*/, double dSampleTime /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_VIDEO_BROADCAST_SERVER_MEDIA_TIMER_CALLBACK)( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, double dSampleTime /*IN*/, double dDelayTime /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_AUDIO_BROADCAST_SERVER_MEDIA_TIMER_CALLBACK)( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, double dSampleTime /*IN*/, double dDelayTime /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_GET_BROADCAST_SERVER_STATUS( UINT iSvrNum /*IN*/ /*0 ~ 63*/, BOOL * pIsValid /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|    |   |  |   |   |2D|3D|  |*/ QCAP_CREATE_BROADCAST_RTSP_SERVER( UINT iSvrNum /*IN*/ /*0 ~ 63*/, ULONG nTotalSessions /*IN*/, PVOID * ppServer /*OUT*/, CHAR * pszAccount DEFVAL( NULL /*IN*/), CHAR * pszPassword DEFVAL( NULL /*IN*/), ULONG nNetworkPort_RTSP DEFVAL( 554 /*IN*/), ULONG nNetworkPort_RTSPOverHTTP DEFVAL( 0 /*IN*/ /*DEFAULT = TURN OFF*/), BOOL bEnableUltraLowLatency DEFVAL( FALSE /*IN*/), CHAR * pszMulticastIP DEFVAL( NULL /*IN*/ /*NULL = DISABLE*/), CHAR * pszNetworkAdapterIP DEFVAL( NULL /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|    |   |  |   |   |2D|3D|  |*/ QCAP_CREATE_BROADCAST_RTSP_RAW_UDP_SERVER( UINT iSvrNum /*IN*/ /*0 ~ 63*/, ULONG nTotalSessions /*IN*/, PVOID * ppServer /*OUT*/, CHAR * pszAccount DEFVAL( NULL /*IN*/), CHAR * pszPassword DEFVAL( NULL /*IN*/), ULONG nNetworkPort_RTSP DEFVAL( 554 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|    |   |  |   |   |2D|  |  |*/ QCAP_CREATE_BROADCAST_RTSP_WEB_PORTAL_SERVER( UINT iSvrNum /*IN*/ /*0 ~ 63*/, CHAR * pszURL /*IN*/, PVOID * ppServer /*OUT*/, CHAR * pszAccount DEFVAL( NULL /*IN*/), CHAR * pszPassword DEFVAL( NULL /*IN*/ )); // TOTOAL SESSION = 1

QCAP_EXT_API QRESULT QCAP_EXPORT /*|    |    |HLS|  |   |   |2D|  |  |*/ QCAP_CREATE_BROADCAST_HLS_SERVER( UINT iSvrNum /*IN*/ /*0 ~ 63*/, ULONG nTotalSessions /*IN*/, PVOID * ppServer /*OUT*/, CHAR * pszWebServerRootFolderPath /*IN*/, CHAR * pszSubFolderPath /*IN*/, ULONG nSegmentDuration DEFVAL( 1000 /*IN*/), BOOL bResumeSegmentNum DEFVAL( FALSE /*IN*/), ULONG nSegmentPlaylistCount DEFVAL( 3 /*IN*/), BOOL bSegmentPreserveAll DEFVAL( FALSE /*IN*/), CHAR * pszWebServerIP DEFVAL( NULL /*IN*/), BOOL bEnableAllowCacheForHLS DEFVAL( TRUE /*IN*/), BOOL bEnablePlayListTypeVOD DEFVAL( FALSE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|    |RTMP|   |  |   |   |2D|  |  |*/ QCAP_CREATE_BROADCAST_RTMP_SERVER( UINT iSvrNum /*IN*/ /*0 ~ 63*/, ULONG nTotalSessions /*IN*/, PVOID * ppServer /*OUT*/, CHAR * pszAccount DEFVAL( NULL /*IN*/), CHAR * pszPassword DEFVAL( NULL /*IN*/), ULONG nNetworkPort_RTMP DEFVAL( 1935 /*IN*/), ULONG nNetworkPort_RTMPOverHTTP DEFVAL( 0 /*IN*/ /*DEFAULT = TURN OFF*/), CHAR * pszServerName DEFVAL( NULL /*IN*/ /*DEFAULT = flvplayback*/), CHAR * pszMediaFolderPath DEFVAL( NULL /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|    |RTMP|   |  |   |   |2D|  |  |*/ QCAP_CREATE_BROADCAST_RTMP_SERVER_EX( UINT iSvrNum /*IN*/ /*0 ~ 63*/, ULONG nTotalSessions /*IN*/, PVOID * ppServer /*OUT*/, CHAR * pszAccount DEFVAL( NULL /*IN*/), CHAR * pszPassword DEFVAL( NULL /*IN*/), ULONG nNetworkPort_RTMP DEFVAL( 1935 /*IN*/), ULONG nNetworkPort_RTMPOverHTTP DEFVAL( 0 /*IN*/ /*DEFAULT = TURN OFF*/), CHAR * pszServerName DEFVAL( NULL /*IN*/ /*DEFAULT = flvplayback*/), CHAR * pszMediaFolderPath DEFVAL( NULL /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|    |RTMP|   |  |   |   |2D|  |  |*/ QCAP_CREATE_BROADCAST_RTMP_WEB_PORTAL_SERVER( UINT iSvrNum /*IN*/ /*0 ~ 63*/, CHAR * pszURL /*IN*/, PVOID * ppServer /*OUT*/, CHAR * pszAccount DEFVAL( NULL /*IN*/), CHAR * pszPassword DEFVAL( NULL /*IN*/), ULONG nConnectionTimeout DEFVAL( 10000 /*IN*/ /*ms*/ )); // TOTOAL SESSION = 1

QCAP_EXT_API QRESULT QCAP_EXPORT /*|    |RTMP|   |  |   |   |2D|  |  |*/ QCAP_CREATE_BROADCAST_RTMP_WEB_PORTAL_SERVER_EX( UINT iSvrNum /*IN*/ /*0 ~ 63*/, CHAR * pszURL /*IN*/, PVOID * ppServer /*OUT*/, CHAR * pszAccount DEFVAL( NULL /*IN*/), CHAR * pszPassword DEFVAL( NULL /*IN*/), ULONG nConnectionTimeout DEFVAL( 10000 /*IN*/ /*ms*/), CHAR * pszNetworkAdapterIP DEFVAL( NULL /*IN*/ )); // TOTOAL SESSION = 1

QCAP_EXT_API QRESULT QCAP_EXPORT /*|    |RTMP|   |  |   |   |2D|  |  |*/ QCAP_CREATE_BROADCAST_FACEBOOK_RTMP_WEB_PORTAL_SERVER( UINT iSvrNum /*IN*/, CHAR * pszAccount /*IN*/, CHAR * pszPassword /*IN*/, PVOID * ppServer /*OUT*/, ULONG nConnectionTimeout DEFVAL( 10000 /*IN*/ /*ms*/ )); // TOTOAL SESSION = 1

QCAP_EXT_API QRESULT QCAP_EXPORT /*|    |RTMP|   |  |   |   |2D|  |  |*/ QCAP_CREATE_BROADCAST_FACEBOOK_RTMP_WEB_PORTAL_SERVER_EX( UINT iSvrNum /*IN*/, CHAR * pszAccount /*IN*/, CHAR * pszPassword /*IN*/, PVOID * ppServer /*OUT*/, ULONG nConnectionTimeout DEFVAL( 10000 /*IN*/ /*ms*/ )); // TOTOAL SESSION = 1

QCAP_EXT_API QRESULT QCAP_EXPORT /*|    |RTMP|   |  |   |   |2D|  |  |*/ QCAP_CREATE_BROADCAST_YOUTUBE_RTMP_WEB_PORTAL_SERVER( UINT iSvrNum /*IN*/, CHAR * pszAccount /*IN*/, CHAR * pszPassword /*IN*/, PVOID * ppServer /*OUT*/, ULONG nConnectionTimeout DEFVAL( 10000 /*IN*/ /*ms*/), BOOL bEnableNewLiveBroadcast DEFVAL( TRUE /*IN*/ )); // TOTOAL SESSION = 1

QCAP_EXT_API QRESULT QCAP_EXPORT /*|    |RTMP|   |  |   |   |2D|  |  |*/ QCAP_CREATE_BROADCAST_YOUTUBE_RTMP_WEB_PORTAL_SERVER_EX( UINT iSvrNum /*IN*/, CHAR * pszAccount /*IN*/, CHAR * pszPassword /*IN*/, PVOID * ppServer /*OUT*/, ULONG nConnectionTimeout DEFVAL( 10000 /*IN*/ /*ms*/), BOOL bEnableNewLiveBroadcast DEFVAL( TRUE /*IN*/ )); // TOTOAL SESSION = 1

QCAP_EXT_API QRESULT QCAP_EXPORT /*|    |RTMP|   |  |   |   |2D|  |  |*/ QCAP_CREATE_BROADCAST_TWITCH_RTMP_WEB_PORTAL_SERVER( UINT iSvrNum /*IN*/, CHAR * pszAccount /*IN*/, CHAR * pszPassword /*IN*/, PVOID * ppServer /*OUT*/, ULONG nConnectionTimeout DEFVAL( 10000 /*IN*/ /*ms*/ )); // TOTOAL SESSION = 1

QCAP_EXT_API QRESULT QCAP_EXPORT /*|    |RTMP|   |  |   |   |2D|  |  |*/ QCAP_CREATE_BROADCAST_TWITCH_RTMP_WEB_PORTAL_SERVER_EX( UINT iSvrNum /*IN*/, CHAR * pszAccount /*IN*/, CHAR * pszPassword /*IN*/, PVOID * ppServer /*OUT*/, ULONG nConnectionTimeout DEFVAL( 10000 /*IN*/ /*ms*/ )); // TOTOAL SESSION = 1

QCAP_EXT_API QRESULT QCAP_EXPORT /*|    |    |   |  |MMS|   |2D|  |  |*/ QCAP_CREATE_BROADCAST_MMS_WEB_PORTAL_SERVER( UINT iSvrNum /*IN*/ /*0 ~ 63*/, CHAR * pszURL /*IN*/, PVOID * ppServer /*OUT*/, CHAR * pszAccount DEFVAL( NULL /*IN*/), CHAR * pszPassword DEFVAL( NULL /*IN*/ )); // TOTOAL SESSION = 1

QCAP_EXT_API QRESULT QCAP_EXPORT /*|    |    |   |TS|   |   |2D|  |  |*/ QCAP_CREATE_BROADCAST_TS_OVER_RTP_SERVER( UINT iSvrNum /*IN*/ /*0 ~ 63*/, CHAR * pszURL /*IN*/, PVOID * ppServer /*OUT*/, CHAR * pszNetworkAdapterIP DEFVAL( NULL /*IN*/), ULONG nServiceID DEFVAL( 1 /*IN*/), CHAR * pszServiceName DEFVAL( NULL /*IN*/), CHAR * pszServiceProviderName DEFVAL( NULL /*IN*/), BOOL bEnableCBRMode DEFVAL( TRUE /*IN*/), ULONG nTransferBitRate DEFVAL( 0 /*IN*/ /*0 = FREE*/), ULONG nOriginalNetworkID DEFVAL( 1 /*IN*/), ULONG nTransportStreamID DEFVAL( 1 /*IN*/), ULONG nPMT_PID DEFVAL( 4096 /*IN*/), ULONG nPCR_PID DEFVAL( 4097 /*IN*/), ULONG nVideo_PID DEFVAL( 256 /*IN*/), ULONG nAudio_PID DEFVAL( 257 /*IN*/), ULONG nVideo_CodecID DEFVAL( 0 /*IN*/ /*0 = AUTO*/), ULONG nAudio_CodecID DEFVAL( 0 /*IN*/ /*0 = AUTO*/), ULONG nPCRInterval DEFVAL( 0 /*IN*/ /*ms*/ )); // TOTOAL SESSION = 1

QCAP_EXT_API QRESULT QCAP_EXPORT /*|    |    |   |TS|   |   |2D|  |  |*/ QCAP_CREATE_BROADCAST_TS_OVER_UDP_SERVER( UINT iSvrNum /*IN*/ /*0 ~ 63*/, CHAR * pszURL /*IN*/, PVOID * ppServer /*OUT*/, CHAR * pszNetworkAdapterIP DEFVAL( NULL /*IN*/), ULONG nServiceID DEFVAL( 1 /*IN*/), CHAR * pszServiceName DEFVAL( NULL /*IN*/), CHAR * pszServiceProviderName DEFVAL( NULL /*IN*/), BOOL bEnableCBRMode DEFVAL( TRUE /*IN*/), ULONG nTransferBitRate DEFVAL( 0 /*IN*/ /*0 = FREE*/), ULONG nOriginalNetworkID DEFVAL( 1 /*IN*/), ULONG nTransportStreamID DEFVAL( 1 /*IN*/), ULONG nPMT_PID DEFVAL( 4096 /*IN*/), ULONG nPCR_PID DEFVAL( 4097 /*IN*/), ULONG nVideo_PID DEFVAL( 256 /*IN*/), ULONG nAudio_PID DEFVAL( 257 /*IN*/), ULONG nVideo_CodecID DEFVAL( 0 /*IN*/ /*0 = AUTO*/), ULONG nAudio_CodecID DEFVAL( 0 /*IN*/ /*0 = AUTO*/), ULONG nPCRInterval DEFVAL( 0 /*IN*/ /*ms*/ )); // TOTOAL SESSION = 1

QCAP_EXT_API QRESULT QCAP_EXPORT /*|    |    |   |TS|   |   |2D|  |  |*/ QCAP_CREATE_BROADCAST_TS_OVER_TCP_SERVER( UINT iSvrNum /*IN*/ /*0 ~ 63*/, PVOID * ppServer /*OUT*/, ULONG nNetworkPort_TCP DEFVAL( 1234 /*IN*/), CHAR * pszNetworkAdapterIP DEFVAL( NULL /*IN*/), ULONG nServiceID DEFVAL( 1 /*IN*/), CHAR * pszServiceName DEFVAL( NULL /*IN*/), CHAR * pszServiceProviderName DEFVAL( NULL /*IN*/), ULONG nTransferBitRate DEFVAL( 0 /*IN*/ /*0 = FREE*/), ULONG nOriginalNetworkID DEFVAL( 1 /*IN*/), ULONG nTransportStreamID DEFVAL( 1 /*IN*/), ULONG nPMT_PID DEFVAL( 4096 /*IN*/), ULONG nPCR_PID DEFVAL( 4097 /*IN*/), ULONG nVideo_PID DEFVAL( 256 /*IN*/), ULONG nAudio_PID DEFVAL( 257 /*IN*/), ULONG nVideo_CodecID DEFVAL( 0 /*IN*/ /*0 = AUTO*/), ULONG nAudio_CodecID DEFVAL( 0 /*IN*/ /*0 = AUTO*/), ULONG nPCRInterval DEFVAL( 0 /*IN*/ /*ms*/ )); // TOTOAL SESSION = 1

QCAP_EXT_API QRESULT QCAP_EXPORT /*|    |    |   |TS|   |   |2D|  |  |*/ QCAP_CREATE_BROADCAST_TS_OVER_HTTP_SERVER( UINT iSvrNum /*IN*/ /*0 ~ 63*/, PVOID * ppServer /*OUT*/, ULONG nNetworkPort_HTTP DEFVAL( 8888 /*IN*/), CHAR * pszNetworkAdapterIP DEFVAL( NULL /*IN*/), ULONG nServiceID DEFVAL( 1 /*IN*/), CHAR * pszServiceName DEFVAL( NULL /*IN*/), CHAR * pszServiceProviderName DEFVAL( NULL /*IN*/), ULONG nTransferBitRate DEFVAL( 0 /*IN*/ /*0 = FREE*/), ULONG nOriginalNetworkID DEFVAL( 1 /*IN*/), ULONG nTransportStreamID DEFVAL( 1 /*IN*/), ULONG nPMT_PID DEFVAL( 4096 /*IN*/), ULONG nPCR_PID DEFVAL( 4097 /*IN*/), ULONG nVideo_PID DEFVAL( 256 /*IN*/), ULONG nAudio_PID DEFVAL( 257 /*IN*/), ULONG nVideo_CodecID DEFVAL( 0 /*IN*/ /*0 = AUTO*/), ULONG nAudio_CodecID DEFVAL( 0 /*IN*/ /*0 = AUTO*/), ULONG nPCRInterval DEFVAL( 0 /*IN*/ /*ms*/ )); // TOTOAL SESSION = 1

QCAP_EXT_API QRESULT QCAP_EXPORT /*|    |    |   |TS|   |   |2D|  |  |*/ QCAP_CREATE_BROADCAST_TS_OVER_SRT_SERVER( UINT iSvrNum /*IN*/ /*0 ~ 63*/, PVOID * ppServer /*OUT*/, ULONG nNetworkPort_SRT DEFVAL( 1234 /*IN*/), CHAR * pszNetworkAdapterIP DEFVAL( NULL /*IN*/), ULONG nServiceID DEFVAL( 1 /*IN*/), CHAR * pszServiceName DEFVAL( NULL /*IN*/), CHAR * pszServiceProviderName DEFVAL( NULL /*IN*/), ULONG nTransferBitRate DEFVAL( 0 /*IN*/ /*0 = FREE*/), ULONG nOriginalNetworkID DEFVAL( 1 /*IN*/), ULONG nTransportStreamID DEFVAL( 1 /*IN*/), ULONG nPMT_PID DEFVAL( 4096 /*IN*/), ULONG nPCR_PID DEFVAL( 4097 /*IN*/), ULONG nVideo_PID DEFVAL( 256 /*IN*/), ULONG nAudio_PID DEFVAL( 257 /*IN*/), ULONG nVideo_CodecID DEFVAL( 0 /*IN*/ /*0 = AUTO*/), ULONG nAudio_CodecID DEFVAL( 0 /*IN*/ /*0 = AUTO*/), ULONG nPCRInterval DEFVAL( 0 /*IN*/ /*ms*/), ULONG nSRTLatency DEFVAL( 120 /*IN*/ /*ms*/), ULONG nSRTOverheadBandwidth DEFVAL( 25 /*IN*/ /*100%*/), CHAR * pszSRTStreamID DEFVAL( NULL /*IN*/ )); // TOTOAL SESSION = 1

QCAP_EXT_API QRESULT QCAP_EXPORT /*|    |    |   |TS|   |   |2D|  |  |*/ QCAP_CREATE_BROADCAST_TS_OVER_SRT_WEB_PORTAL_SERVER( UINT iSvrNum /*IN*/ /*0 ~ 63*/, CHAR * pszURL /*IN*/, PVOID * ppServer /*OUT*/, CHAR * pszAccount DEFVAL( NULL /*IN*/), CHAR * pszPassword DEFVAL( NULL /*IN*/), ULONG nServiceID DEFVAL( 1 /*IN*/), CHAR * pszServiceName DEFVAL( NULL /*IN*/), CHAR * pszServiceProviderName DEFVAL( NULL /*IN*/), ULONG nTransferBitRate DEFVAL( 0 /*IN*/ /*0 = FREE*/), ULONG nOriginalNetworkID DEFVAL( 1 /*IN*/), ULONG nTransportStreamID DEFVAL( 1 /*IN*/), ULONG nPMT_PID DEFVAL( 4096 /*IN*/), ULONG nPCR_PID DEFVAL( 4097 /*IN*/), ULONG nVideo_PID DEFVAL( 256 /*IN*/), ULONG nAudio_PID DEFVAL( 257 /*IN*/), ULONG nVideo_CodecID DEFVAL( 0 /*IN*/ /*0 = AUTO*/), ULONG nAudio_CodecID DEFVAL( 0 /*IN*/ /*0 = AUTO*/), ULONG nPCRInterval DEFVAL( 0 /*IN*/ /*ms*/), ULONG nSRTLatency DEFVAL( 120 /*IN*/ /*ms*/), ULONG nSRTOverheadBandwidth DEFVAL( 25 /*IN*/ /*100%*/ )); // TOTOAL SESSION = 1

QCAP_EXT_API QRESULT QCAP_EXPORT /*|    |    |   |TS|   |   |2D|  |  |*/ QCAP_CREATE_BROADCAST_TS_OVER_TCP_PASSIVE_SERVER( UINT iSvrNum /*IN*/ /*0 ~ 63*/, CHAR * pszURL /*IN*/, PVOID * ppServer /*OUT*/, ULONG nServiceID DEFVAL( 1 /*IN*/), CHAR * pszServiceName DEFVAL( NULL /*IN*/), CHAR * pszServiceProviderName DEFVAL( NULL /*IN*/), ULONG nTransferBitRate DEFVAL( 0 /*IN*/ /*0 = FREE*/), ULONG nOriginalNetworkID DEFVAL( 1 /*IN*/), ULONG nTransportStreamID DEFVAL( 1 /*IN*/), ULONG nPMT_PID DEFVAL( 4096 /*IN*/), ULONG nPCR_PID DEFVAL( 4097 /*IN*/), ULONG nVideo_PID DEFVAL( 256 /*IN*/), ULONG nAudio_PID DEFVAL( 257 /*IN*/), ULONG nVideo_CodecID DEFVAL( 0 /*IN*/ /*0 = AUTO*/), ULONG nAudio_CodecID DEFVAL( 0 /*IN*/ /*0 = AUTO*/), ULONG nPCRInterval DEFVAL( 0 /*IN*/ /*ms*/ )); // TOTOAL SESSION = 1

QCAP_EXT_API QRESULT QCAP_EXPORT /*|    |    |   |  |   |NDI|2D|  |  |*/ QCAP_CREATE_BROADCAST_NDI_SERVER( UINT iSvrNum /*IN*/ /*0 ~ 63*/, CHAR * pszNDIName /*IN*/, CHAR * pszGroupName /*IN*/, PVOID * ppServer /*OUT*/, BOOL bEnableNDIProxy DEFVAL( FALSE /*IN*/), BOOL bEnablePTZ DEFVAL( FALSE /*IN*/), CHAR * pszConnectionMetadata DEFVAL( NULL /*IN*/ /*XML*/ )); // TOTOAL SESSION = 1 / 2

QCAP_EXT_API QRESULT QCAP_EXPORT /*|    |    |   |  |   |NDI|2D|  |  |*/ QCAP_CREATE_BROADCAST_NDI_HX_SERVER( UINT iSvrNum /*IN*/ /*0 ~ 63*/, CHAR * pszNDIName /*IN*/, CHAR * pszGroupName /*IN*/, PVOID * ppServer /*OUT*/, BOOL bEnableNDIProxy DEFVAL( FALSE /*IN*/), BOOL bEnablePTZ DEFVAL( FALSE /*IN*/), CHAR * pszConnectionMetadata DEFVAL( NULL /*IN*/ /*XML*/ )); // TOTOAL SESSION = 1 / 2

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_DESTROY_BROADCAST_SERVER( PVOID pServer /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_START_BROADCAST_SERVER( PVOID pServer /*IN*/, CHAR * pszEncryptKey DEFVAL( NULL /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_STOP_BROADCAST_SERVER( PVOID pServer /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|  |  |*/ QCAP_SET_SESSION_BROADCAST_SERVER_SOURCE( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, PVOID pDevice /*IN*/, ULONG nSequenceStyle DEFVAL( QCAP_SEQUENCE_STYLE_FOREMOST /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|  |  |*/ QCAP_SET_SESSION_BROADCAST_SERVER_SOURCE_EX( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, PVOID pDevice /*IN*/, ULONG nCropX /*IN*/, ULONG nCropY /*IN*/, ULONG nCropW /*IN*/, ULONG nCropH /*IN*/, ULONG nScaleStyle DEFVAL( QCAP_SCALE_STYLE_STRETCH /*IN*/), ULONG nSequenceStyle DEFVAL( QCAP_SEQUENCE_STYLE_FOREMOST /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_SET_SESSION_BROADCAST_SERVER_PROPERTY( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, CHAR * pszSessionName /*IN*/, ULONG nVideoDelayLiveDuration /*IN*/, ULONG nAudioDelayLiveDuration /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_GET_VIDEO_BROADCAST_SERVER_PROPERTY( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, ULONG * pEncoderType /*OUT*/, ULONG * pEncoderFormat /*OUT*/, ULONG * pColorSpaceType /*OUT*/, ULONG * pWidth /*OUT*/, ULONG * pHeight /*OUT*/, double * pFrameRate /*OUT*/, ULONG * pRecordMode /*OUT*/, ULONG * pQuality /*OUT*/, ULONG * pBitRate /*OUT*/, ULONG * pGOP /*OUT*/, ULONG * pAspectRatioX /*OUT*/, ULONG * pAspectRatioY /*OUT*/, HWND * pAttachedWindow DEFVAL( NULL /*OUT*/), BOOL * pThumbDraw DEFVAL( NULL /*OUT*/), BOOL * pMaintainAspectRatio DEFVAL( NULL /*OUT*/), DWORD * pFlags DEFVAL( NULL /*OUT*/                    ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_SET_VIDEO_BROADCAST_SERVER_PROPERTY( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, ULONG   nEncoderType /*IN*/,  ULONG   nEncoderFormat /*IN*/,  ULONG   nColorSpaceType /*IN*/,  ULONG   nWidth /*IN*/,  ULONG   nHeight /*IN*/,  double   dFrameRate /*IN*/,  ULONG   nRecordMode /*IN*/,  ULONG   nQuality /*IN*/,  ULONG   nBitRate /*IN*/,  ULONG   nGOP /*IN*/,  ULONG   nAspectRatioX /*IN*/,  ULONG   nAspectRatioY /*IN*/,  HWND   hAttachedWindow DEFVAL( NULL /*IN*/),  BOOL   bThumbDraw DEFVAL( FALSE /*IN*/), BOOL   bMaintainAspectRatio DEFVAL( FALSE /*IN*/), DWORD  dwFlags DEFVAL( QCAP_BROADCAST_FLAG_FULL /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_GET_VIDEO_BROADCAST_SERVER_PROPERTY_EX( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, UINT * pGpuNum /*OUT*/, ULONG * pEncoderType /*OUT*/, ULONG * pEncoderFormat /*OUT*/, ULONG * pColorSpaceType /*OUT*/, ULONG * pWidth /*OUT*/, ULONG * pHeight /*OUT*/, double * pFrameRate /*OUT*/, ULONG * pRecordProfile /*OUT*/ DEFVAL( QCAP_RECORD_PROFILE_BASELINE /*OUT*/), ULONG * pRecordLevel /*OUT*/ DEFVAL( 41 /*OUT*/), ULONG * pRecordEntropy /*OUT*/ DEFVAL( QCAP_RECORD_ENTROPY_CAVLC /*OUT*/), ULONG * pRecordComplexity /*OUT*/ DEFVAL( 0 /*OUT*/), ULONG * pRecordMode /*OUT*/, ULONG * pQuality /*OUT*/, ULONG * pBitRate /*OUT*/, ULONG * pGOP /*OUT*/, ULONG * pBFrames /*OUT*/ DEFVAL( 0 /*OUT*/), BOOL * pIsInterleaved /*OUT*/ DEFVAL( FALSE /*OUT*/), ULONG * pSlices /*OUT*/ DEFVAL( 0 /*OUT*/), ULONG * pLayers /*OUT*/ DEFVAL( 0 /*OUT*/), ULONG * pSceneCut /*OUT*/ DEFVAL( 0 /*OUT*/), BOOL * pMultiThread /*OUT*/ DEFVAL( TRUE /*OUT*/), BOOL * pMBBRC /*OUT*/ DEFVAL( FALSE /*OUT*/), BOOL * pExtBRC /*OUT*/ DEFVAL( FALSE /*OUT*/), ULONG * pMinQP /*OUT*/ DEFVAL( 0 /*OUT*/), ULONG * pMaxQP /*OUT*/ DEFVAL( 0 /*OUT*/), ULONG * pVBVMaxRate /*OUT*/ DEFVAL( 0 /*OUT*/), ULONG * pVBVBufSize /*OUT*/ DEFVAL( 0 /*OUT*/), ULONG * pCBRVariation /*OUT*/ DEFVAL( 0 /*OUT*/), ULONG * pAspectRatioX /*OUT*/, ULONG * pAspectRatioY /*OUT*/, HWND * pAttachedWindow DEFVAL( NULL /*OUT*/), BOOL * pThumbDraw DEFVAL( NULL /*OUT*/), BOOL * pMaintainAspectRatio DEFVAL( NULL /*OUT*/), DWORD * pFlags DEFVAL( NULL /*OUT*/                    ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_SET_VIDEO_BROADCAST_SERVER_PROPERTY_EX( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, UINT   iGpuNum /*IN*/,  ULONG   nEncoderType /*IN*/,  ULONG   nEncoderFormat /*IN*/,  ULONG   nColorSpaceType /*IN*/,  ULONG   nWidth /*IN*/,  ULONG   nHeight /*IN*/,  double   dFrameRate /*IN*/,  ULONG   nRecordProfile /*IN*/  DEFVAL( QCAP_RECORD_PROFILE_BASELINE /*IN*/), ULONG   nRecordLevel /*IN*/  DEFVAL( 41 /*IN*/), ULONG   nRecordEntropy /*IN*/  DEFVAL( QCAP_RECORD_ENTROPY_CAVLC /*IN*/), ULONG   nRecordComplexity /*IN*/  DEFVAL( 0 /*IN*/), ULONG   nRecordMode /*IN*/,  ULONG   nQuality /*IN*/,  ULONG   nBitRate /*IN*/,  ULONG   nGOP /*IN*/,  ULONG   nBFrames /*IN*/  DEFVAL( 0 /*IN*/), BOOL   bIsInterleaved /*IN*/  DEFVAL( FALSE /*IN*/), ULONG   nSlices /*IN*/  DEFVAL( 0 /*IN*/), ULONG   nLayers /*IN*/  DEFVAL( 0 /*IN*/), ULONG   nSceneCut /*IN*/  DEFVAL( 0 /*IN*/), BOOL   bMultiThread /*IN*/  DEFVAL( TRUE /*IN*/), BOOL   bMBBRC /*IN*/  DEFVAL( FALSE /*IN*/), BOOL   bExtBRC /*IN*/  DEFVAL( FALSE /*IN*/), ULONG   nMinQP /*IN*/  DEFVAL( 0 /*IN*/), ULONG   nMaxQP /*IN*/  DEFVAL( 0 /*IN*/), ULONG   nVBVMaxRate /*IN*/  DEFVAL( 0 /*IN*/), ULONG   nVBVBufSize /*IN*/  DEFVAL( 0 /*IN*/), ULONG   nCBRVariation /*IN*/  DEFVAL( 0 /*IN*/), ULONG   nAspectRatioX /*IN*/,  ULONG   nAspectRatioY /*IN*/,  HWND   hAttachedWindow DEFVAL( NULL /*IN*/),  BOOL   bThumbDraw DEFVAL( FALSE /*IN*/), BOOL   bMaintainAspectRatio DEFVAL( FALSE /*IN*/), DWORD  dwFlags DEFVAL( QCAP_BROADCAST_FLAG_FULL /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_GET_VIDEO_BROADCAST_SERVER_DYNAMIC_PROPERTY_EX( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, ULONG * pRecordMode /*OUT*/, ULONG * pQuality /*OUT*/, ULONG * pBitRate /*OUT*/, ULONG * pGOP /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_SET_VIDEO_BROADCAST_SERVER_DYNAMIC_PROPERTY_EX( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, ULONG   nRecordMode /*IN*/,  ULONG   nQuality /*IN*/,  ULONG   nBitRate /*IN*/,  ULONG   nGOP /*IN*/  );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_GET_AUDIO_BROADCAST_SERVER_PROPERTY( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, ULONG * pEncoderType /*OUT*/, ULONG * pEncoderFormat /*OUT*/, ULONG * pChannels /*OUT*/, ULONG * pBitsPerSample /*OUT*/, ULONG * pSampleFrequency /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_SET_AUDIO_BROADCAST_SERVER_PROPERTY( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, ULONG   nEncoderType /*IN*/,  ULONG   nEncoderFormat /*IN*/,  ULONG   nChannels /*IN*/,  ULONG   nBitsPerSample /*IN*/,  ULONG   nSampleFrequency /*IN*/  );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_GET_AUDIO_BROADCAST_SERVER_PROPERTY_EX( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, ULONG * pEncoderType /*OUT*/, ULONG * pEncoderFormat /*OUT*/, ULONG * pChannels /*OUT*/, ULONG * pBitsPerSample /*OUT*/, ULONG * pSampleFrequency /*OUT*/, ULONG * pBitRate /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_SET_AUDIO_BROADCAST_SERVER_PROPERTY_EX( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, ULONG   nEncoderType /*IN*/,  ULONG   nEncoderFormat /*IN*/,  ULONG   nChannels /*IN*/,  ULONG   nBitsPerSample /*IN*/,  ULONG   nSampleFrequency /*IN*/,  ULONG   nBitRate /*IN*/  );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|MX|*/ QCAP_GET_AUDIO_MX_BROADCAST_SERVER_PROPERTY_EX( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, ULONG * pTracks /*OUT*/, ULONG * pEncoderType /*OUT*/, ULONG * pEncoderFormat /*OUT*/, ULONG * pChannels /*OUT*/, ULONG * pBitsPerSample /*OUT*/, ULONG * pSampleFrequency /*OUT*/, ULONG * pBitRate /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|MX|*/ QCAP_SET_AUDIO_MX_BROADCAST_SERVER_PROPERTY_EX( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, ULONG   nTracks /*IN*/,  ULONG   nEncoderType /*IN*/,  ULONG   nEncoderFormat /*IN*/,  ULONG   nChannels /*IN*/,  ULONG   nBitsPerSample /*IN*/,  ULONG   nSampleFrequency /*IN*/,  ULONG   nBitRate /*IN*/  );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_GET_AUDIO_BROADCAST_SERVER_SOUND_RENDERER( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, UINT * pSoundNum /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_SET_AUDIO_BROADCAST_SERVER_SOUND_RENDERER( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, UINT   iSoundNum /*IN*/  );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_GET_AUDIO_BROADCAST_SERVER_VOLUME( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, ULONG * pVolume /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_SET_AUDIO_BROADCAST_SERVER_VOLUME( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, ULONG   nVolume /*IN*/  );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_GET_AUDIO_BROADCAST_SERVER_NOISE_REMOVAL( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, ULONG * pStrength /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_SET_AUDIO_BROADCAST_SERVER_NOISE_REMOVAL( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, ULONG   nStrength /*IN*/  );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_GET_VIDEO_BROADCAST_SERVER_NETWORK_QOS_STATUS( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, BOOL * pIsTransferBusy /*OUT*/, ULONG * pQueueFrames /*OUT*/, ULONG * pQueueBytes /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_GET_AUDIO_BROADCAST_SERVER_NETWORK_QOS_STATUS( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, BOOL * pIsTransferBusy /*OUT*/, ULONG * pQueueFrames /*OUT*/, ULONG * pQueueBytes /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_SET_VIDEO_BROADCAST_SERVER_UNCOMPRESSION_BUFFER( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, ULONG nColorSpaceType /*IN*/, ULONG nWidth /*IN*/, ULONG nHeight /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, double dSampleTime DEFVAL( 0.0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_SET_VIDEO_BROADCAST_SERVER_UNCOMPRESSION_BUFFER_EX( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, ULONG nColorSpaceType /*IN*/, ULONG nWidth /*IN*/, ULONG nHeight /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, ULONG nCropX /*IN*/, ULONG nCropY /*IN*/, ULONG nCropW /*IN*/, ULONG nCropH /*IN*/, ULONG nScaleStyle DEFVAL( QCAP_SCALE_STYLE_STRETCH /*IN*/), BOOL bForceKeyFrame DEFVAL( FALSE /*IN*/), BYTE * pMetadataBuffer DEFVAL( NULL /*IN*/), ULONG nMetadataBufferLen DEFVAL( 0 /*IN*/), double dSampleTime DEFVAL( 0.0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_SET_AUDIO_BROADCAST_SERVER_UNCOMPRESSION_BUFFER( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, double dSampleTime DEFVAL( 0.0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_SET_AUDIO_BROADCAST_SERVER_UNCOMPRESSION_BUFFER_EX( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, ULONG nChannels /*IN*/, ULONG nBitsPerSample /*IN*/, ULONG nSampleFrequency /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, BYTE * pMetadataBuffer DEFVAL( NULL /*IN*/), ULONG nMetadataBufferLen DEFVAL( 0 /*IN*/), double dSampleTime DEFVAL( 0.0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_SET_VIDEO_BROADCAST_SERVER_COMPRESSION_BUFFER( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, BYTE * pStreamBuffer /*IN*/, ULONG nStreamBufferLen /*IN*/, ULONG bIsKeyFrame /*IN*/, double dSampleTime DEFVAL( 0.0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_SET_VIDEO_BROADCAST_SERVER_COMPRESSION_BUFFER_EX( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, BYTE * pStreamBuffer /*IN*/, ULONG nStreamBufferLen /*IN*/, ULONG bIsKeyFrame /*IN*/, BYTE * pMetadataBuffer DEFVAL( NULL /*IN*/), ULONG nMetadataBufferLen DEFVAL( 0 /*IN*/), double dSampleTime DEFVAL( 0.0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_SET_AUDIO_BROADCAST_SERVER_COMPRESSION_BUFFER( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, BYTE * pStreamBuffer /*IN*/, ULONG nStreamBufferLen /*IN*/, double dSampleTime DEFVAL( 0.0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_SET_AUDIO_BROADCAST_SERVER_COMPRESSION_BUFFER_EX( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, BYTE * pStreamBuffer /*IN*/, ULONG nStreamBufferLen /*IN*/,  BYTE * pMetadataBuffer DEFVAL( NULL /*IN*/), ULONG nMetadataBufferLen DEFVAL( 0 /*IN*/), double dSampleTime DEFVAL( 0.0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|    |   |  |   |   |  |3D|  |*/ QCAP_SET_VIDEO_3D_BROADCAST_SERVER_STEREO_UNCOMPRESSION_BUFFER( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, ULONG nColorSpaceType /*IN*/, ULONG nWidth /*IN*/, ULONG nHeight /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, ULONG nStereoBufferType DEFVAL( QCAP_3D_STEREO_BUFFER_SIDE_BY_SIDE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|    |   |  |   |   |  |3D|  |*/ QCAP_SET_VIDEO_3D_BROADCAST_SERVER_STEREO_UNCOMPRESSION_BUFFER_EX( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, ULONG nColorSpaceType /*IN*/, ULONG nWidth /*IN*/, ULONG nHeight /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, ULONG nCropX /*IN*/, ULONG nCropY /*IN*/, ULONG nCropW /*IN*/, ULONG nCropH /*IN*/, ULONG nScaleStyle DEFVAL( QCAP_SCALE_STYLE_STRETCH /*IN*/), ULONG nStereoBufferType DEFVAL( QCAP_3D_STEREO_BUFFER_SIDE_BY_SIDE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|    |   |  |   |   |  |3D|  |*/ QCAP_SET_VIDEO_3D_BROADCAST_SERVER_L_UNCOMPRESSION_BUFFER( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, ULONG nColorSpaceType /*IN*/, ULONG nWidth /*IN*/, ULONG nHeight /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|    |   |  |   |   |  |3D|  |*/ QCAP_SET_VIDEO_3D_BROADCAST_SERVER_L_UNCOMPRESSION_BUFFER_EX( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, ULONG nColorSpaceType /*IN*/, ULONG nWidth /*IN*/, ULONG nHeight /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, ULONG nCropX /*IN*/, ULONG nCropY /*IN*/, ULONG nCropW /*IN*/, ULONG nCropH /*IN*/, ULONG nScaleStyle DEFVAL( QCAP_SCALE_STYLE_STRETCH /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|    |   |  |   |   |  |3D|  |*/ QCAP_SET_VIDEO_3D_BROADCAST_SERVER_R_UNCOMPRESSION_BUFFER( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, ULONG nColorSpaceType /*IN*/, ULONG nWidth /*IN*/, ULONG nHeight /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|    |   |  |   |   |  |3D|  |*/ QCAP_SET_VIDEO_3D_BROADCAST_SERVER_R_UNCOMPRESSION_BUFFER_EX( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, ULONG nColorSpaceType /*IN*/, ULONG nWidth /*IN*/, ULONG nHeight /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, ULONG nCropX /*IN*/, ULONG nCropY /*IN*/, ULONG nCropW /*IN*/, ULONG nCropH /*IN*/, ULONG nScaleStyle DEFVAL( QCAP_SCALE_STYLE_STRETCH /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|    |   |  |   |   |  |3D|  |*/ QCAP_SET_VIDEO_3D_BROADCAST_SERVER_UNCOMPRESSION_BUFFER( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, ULONG nStereoDisplayMode DEFVAL( QCAP_3D_STEREO_DISPLAY_MODE_LINE_BY_LINE /*IN*/), BOOL bLeftRightSwap DEFVAL( FALSE /*IN*/), BOOL bForceKeyFrame DEFVAL( FALSE /*IN*/), double dSampleTime DEFVAL( 0.0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|MX|*/ QCAP_SET_AUDIO_MX_BROADCAST_SERVER_MIXING_UNCOMPRESSION_BUFFER( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, UINT iTrackNum /*IN*/, UINT iMixNum /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|MX|*/ QCAP_SET_AUDIO_MX_BROADCAST_SERVER_MIXING_UNCOMPRESSION_BUFFER_EX( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, UINT iTrackNum /*IN*/, UINT iMixNum /*IN*/, ULONG nChannels /*IN*/, ULONG nBitsPerSample /*IN*/, ULONG nSampleFrequency /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|MX|*/ QCAP_SET_AUDIO_MX_BROADCAST_SERVER_UNCOMPRESSION_BUFFER( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, UINT iTrackNum /*IN*/, double dSampleTime DEFVAL( 0.0 /*IN*/), BOOL bEnableSyncMixer DEFVAL( TRUE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|MX|*/ QCAP_SET_AUDIO_MX_BROADCAST_SERVER_COMPRESSION_BUFFER( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, UINT iTrackNum /*IN*/, BYTE * pStreamBuffer /*IN*/, ULONG nStreamBufferLen /*IN*/, double dSampleTime DEFVAL( 0.0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_CLEAR_VIDEO_BROADCAST_SERVER_DELAY_LIVE_BUFFER( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, BOOL bEnableClear /*IN*/, BYTE * pStreamBuffer /*IN*/, ULONG nStreamBufferLen /*IN*/, ULONG bIsKeyFrame /*IN*/, double dSampleTime DEFVAL( 0.0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_CLEAR_AUDIO_BROADCAST_SERVER_DELAY_LIVE_BUFFER( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, BOOL bEnableClear /*IN*/, BYTE * pStreamBuffer /*IN*/, ULONG nStreamBufferLen /*IN*/, double dSampleTime DEFVAL( 0.0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|MX|*/ QCAP_CLEAR_AUDIO_MX_BROADCAST_SERVER_DELAY_LIVE_BUFFER( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, UINT iTrackNum /*IN*/, BOOL bEnableClear /*IN*/, BYTE * pStreamBuffer /*IN*/, ULONG nStreamBufferLen /*IN*/, double dSampleTime DEFVAL( 0.0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_SNAPSHOT_BROADCAST_SERVER_BMP( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, CHAR * pszFilePathName /*IN*/, BOOL bIsAsync DEFVAL( TRUE /*IN*/), ULONG nMilliseconds DEFVAL( 0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_SNAPSHOT_BROADCAST_SERVER_JPG( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, CHAR * pszFilePathName /*IN*/, ULONG nQuality /*IN*/, BOOL bIsAsync DEFVAL( TRUE /*IN*/), ULONG nMilliseconds DEFVAL( 0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_SNAPSHOT_BROADCAST_SERVER_BMP_EX( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, CHAR * pszFilePathName /*IN*/, ULONG nCropX /*IN*/, ULONG nCropY /*IN*/, ULONG nCropW /*IN*/, ULONG nCropH /*IN*/, ULONG nDstW /*IN*/, ULONG nDstH /*IN*/, BOOL bIsAsync DEFVAL( TRUE /*IN*/), ULONG nMilliseconds DEFVAL( 0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_SNAPSHOT_BROADCAST_SERVER_JPG_EX( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, CHAR * pszFilePathName /*IN*/, ULONG nCropX /*IN*/, ULONG nCropY /*IN*/, ULONG nCropW /*IN*/, ULONG nCropH /*IN*/, ULONG nDstW /*IN*/, ULONG nDstH /*IN*/, ULONG nQuality /*IN*/, BOOL bIsAsync DEFVAL( TRUE /*IN*/), ULONG nMilliseconds DEFVAL( 0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_MOVE_OSD_BROADCAST_SERVER_OBJECT( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, ULONG nSequenceStyle DEFVAL( QCAP_SEQUENCE_STYLE_FOREMOST /*IN*/), double dLifeTime DEFVAL( 0.0 /*IN*/ )); // FOR SCROLLING TEXT/PICTURE

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_GET_OSD_BROADCAST_SERVER_TEXT_BOUNDARY( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, UINT iOsdNum /*IN*/, CHAR * pszString /*IN*/, CHAR * pszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, ULONG * pBoundaryWidth /*OUT*/, ULONG * pBoundaryHeight /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_GET_OSD_BROADCAST_SERVER_TEXT_BOUNDARY_W( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, UINT iOsdNum /*IN*/, WSTRING pwszString /*IN*/, WSTRING pwszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, ULONG * pBoundaryWidth /*OUT*/, ULONG * pBoundaryHeight /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_SET_OSD_BROADCAST_SERVER_TEXT( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, CHAR * pszString /*IN*/, CHAR * pszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, DWORD dwFontColor /*IN*/, DWORD dwBackgroundColor /*IN*/, ULONG nTransparent /*IN*/, INT nTextStartPosX DEFVAL( 0 /*IN*/), INT nTextStartPosY DEFVAL( 0 /*IN*/), ULONG nSequenceStyle DEFVAL( QCAP_SEQUENCE_STYLE_FOREMOST /*IN*/), double dLifeTime DEFVAL( 0.0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_SET_OSD_BROADCAST_SERVER_TEXT_W( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, WSTRING pwszString /*IN*/, WSTRING pwszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, DWORD dwFontColor /*IN*/, DWORD dwBackgroundColor /*IN*/, ULONG nTransparent /*IN*/, INT nTextStartPosX DEFVAL( 0 /*IN*/), INT nTextStartPosY DEFVAL( 0 /*IN*/), ULONG nSequenceStyle DEFVAL( QCAP_SEQUENCE_STYLE_FOREMOST /*IN*/), double dLifeTime DEFVAL( 0.0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_SET_OSD_BROADCAST_SERVER_TEXT_EX( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, CHAR * pszString /*IN*/, CHAR * pszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, DWORD dwFontColor /*IN*/, DWORD dwBackgroundColor /*IN*/, DWORD dwBorderColor /*IN*/, ULONG nBorderWidth /*IN*/, ULONG nTransparent /*IN*/, INT nTextStartPosX DEFVAL( 0 /*IN*/), INT nTextStartPosY DEFVAL( 0 /*IN*/), ULONG nStringAlignmentStyle DEFVAL( QCAP_STRING_ALIGNMENT_STYLE_LEFT /*IN*/), ULONG nSequenceStyle DEFVAL( QCAP_SEQUENCE_STYLE_FOREMOST /*IN*/), double dLifeTime DEFVAL( 0.0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_SET_OSD_BROADCAST_SERVER_TEXT_EX_W( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, WSTRING pwszString /*IN*/, WSTRING pwszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, DWORD dwFontColor /*IN*/, DWORD dwBackgroundColor /*IN*/, DWORD dwBorderColor /*IN*/, ULONG nBorderWidth /*IN*/, ULONG nTransparent /*IN*/, INT nTextStartPosX DEFVAL( 0 /*IN*/), INT nTextStartPosY DEFVAL( 0 /*IN*/), ULONG nStringAlignmentStyle DEFVAL( QCAP_STRING_ALIGNMENT_STYLE_LEFT /*IN*/), ULONG nSequenceStyle DEFVAL( QCAP_SEQUENCE_STYLE_FOREMOST /*IN*/), double dLifeTime DEFVAL( 0.0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_SET_OSD_BROADCAST_SERVER_PICTURE( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, CHAR * pszFilePathName /*IN*/, ULONG nTransparent /*IN*/, ULONG nSequenceStyle DEFVAL( QCAP_SEQUENCE_STYLE_FOREMOST /*IN*/), double dLifeTime DEFVAL( 0.0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_SET_OSD_BROADCAST_SERVER_BUFFER( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, ULONG nColorSpaceType /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameWidth /*IN*/, ULONG nFrameHeight /*IN*/, ULONG nFramePitch /*IN*/, ULONG nTransparent /*IN*/, DWORD dwKeyColor DEFVAL( 0xFFFFFFFF /*IN*/ /*0xFFFFFFFF (OFF) / 0x00FF0000 (BLUE) / 0x0000FF00 (GREEN)*/), ULONG nKeyColorThreshold DEFVAL( 25 /*IN*/ /*0 ~ 128*/), ULONG nKeyColorBlurLevel DEFVAL( 2 /*IN*/ /*0 ~ 2*/), BOOL bKeyColorSpillSuppress DEFVAL( TRUE /*IN*/), ULONG nKeyColorSpillSuppressThreshold DEFVAL( 22 /*IN*/), BYTE * pMaskBuffer DEFVAL( NULL /*IN*/), ULONG nSequenceStyle DEFVAL( QCAP_SEQUENCE_STYLE_FOREMOST /*IN*/), double dLifeTime DEFVAL( 0.0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_SET_OSD_BROADCAST_SERVER_BUFFER_EX( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, ULONG nColorSpaceType /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameWidth /*IN*/, ULONG nFrameHeight /*IN*/, ULONG nFramePitch /*IN*/, ULONG nCropX /*IN*/, ULONG nCropY /*IN*/, ULONG nCropW /*IN*/, ULONG nCropH /*IN*/, DWORD dwBorderColor /*IN*/, ULONG nBorderWidth /*IN*/, ULONG nTransparent /*IN*/, DWORD dwKeyColor DEFVAL( 0xFFFFFFFF /*IN*/ /*0xFFFFFFFF (OFF) / 0x00FF0000 (BLUE) / 0x0000FF00 (GREEN)*/), ULONG nKeyColorThreshold DEFVAL( 25 /*IN*/ /*0 ~ 128*/), ULONG nKeyColorBlurLevel DEFVAL( 2 /*IN*/ /*0 ~ 2*/), BOOL bKeyColorSpillSuppress DEFVAL( TRUE /*IN*/), ULONG nKeyColorSpillSuppressThreshold DEFVAL( 22 /*IN*/), BYTE * pMaskBuffer DEFVAL( NULL /*IN*/), ULONG nSequenceStyle DEFVAL( QCAP_SEQUENCE_STYLE_FOREMOST /*IN*/), double dLifeTime DEFVAL( 0.0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|    |    |   |  |   |NDI|2D|3D|  |*/ QCAP_REGISTER_BROADCAST_SERVER_PTZ_COMMAND_CALLBACK( PVOID pServer /*IN*/, PF_BROADCAST_SERVER_PTZ_COMMAND_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|    |   |  |   |   |2D|3D|  |*/ QCAP_REGISTER_BROADCAST_SERVER_BACKCHANNEL_CALLBACK( PVOID pServer /*IN*/, PF_BROADCAST_SERVER_BACKCHANNEL_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|    |   |  |   |   |2D|3D|  |*/ QCAP_REGISTER_BROADCAST_SERVER_GET_CUSTOM_PROPERTY_CALLBACK( PVOID pServer /*IN*/, PF_BROADCAST_SERVER_GET_CUSTOM_PROPERTY_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|    |   |  |   |   |2D|3D|  |*/ QCAP_REGISTER_BROADCAST_SERVER_SET_CUSTOM_PROPERTY_CALLBACK( PVOID pServer /*IN*/, PF_BROADCAST_SERVER_SET_CUSTOM_PROPERTY_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_REGISTER_BROADCAST_SERVER_SNAPSHOT_DONE_CALLBACK( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, PF_BROADCAST_SERVER_SNAPSHOT_DONE_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_REGISTER_BROADCAST_SERVER_SNAPSHOT_STREAM_CALLBACK( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, PF_BROADCAST_SERVER_SNAPSHOT_STREAM_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_REGISTER_VIDEO_BROADCAST_SERVER_CALLBACK( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, PF_VIDEO_BROADCAST_SERVER_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_REGISTER_AUDIO_BROADCAST_SERVER_CALLBACK( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, PF_AUDIO_BROADCAST_SERVER_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_REGISTER_VIDEO_DECODER_BROADCAST_SERVER_CALLBACK( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, PF_VIDEO_DECODER_BROADCAST_SERVER_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_REGISTER_AUDIO_DECODER_BROADCAST_SERVER_CALLBACK( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, PF_AUDIO_DECODER_BROADCAST_SERVER_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|MX|*/ QCAP_REGISTER_AUDIO_MX_BROADCAST_SERVER_CALLBACK( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, PF_AUDIO_MX_BROADCAST_SERVER_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|MX|*/ QCAP_REGISTER_AUDIO_DECODER_MX_BROADCAST_SERVER_CALLBACK( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, PF_AUDIO_DECODER_MX_BROADCAST_SERVER_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_REGISTER_VIDEO_BROADCAST_SERVER_MEDIA_TIMER_CALLBACK( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, PF_VIDEO_BROADCAST_SERVER_MEDIA_TIMER_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|NDI|2D|3D|  |*/ QCAP_REGISTER_AUDIO_BROADCAST_SERVER_MEDIA_TIMER_CALLBACK( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, PF_AUDIO_BROADCAST_SERVER_MEDIA_TIMER_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

// ##########################################################################################################################################################################################
// #
// # BROADCASTING CLIENT FUNCTIONS (RTSP/RTMP/TS) (2D/3D)
// #
// ##########################################################################################################################################################################################
//
typedef QRETURN (QCAP_EXPORT *PF_BROADCAST_CLIENT_MEDIAINFO_CALLBACK)( PVOID pClient /*IN*/, ULONG nTotalStreams /*IN*/, UINT iStreamNum /*IN*/, ULONG nStream_PID /*IN*/, ULONG nProgram_PID /*IN*/, ULONG nVideoWidth /*IN*/, ULONG nVideoHeight /*IN*/, BOOL bVideoIsInterleaved /*IN*/, double dVideoFrameRate /*IN*/, ULONG nAudioChannels /*IN*/, ULONG nAudioBitsPerSample /*IN*/, ULONG nAudioSampleFrequency /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_BROADCAST_CLIENT_CONNECTED_CALLBACK)( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, ULONG nVideoEncoderFormat /*IN*/, ULONG nVideoWidth /*IN*/, ULONG nVideoHeight /*IN*/, BOOL bVideoIsInterleaved /*IN*/, double dVideoFrameRate /*IN*/, ULONG nAudioEncoderFormat /*IN*/, ULONG nAudioChannels /*IN*/, ULONG nAudioBitsPerSample /*IN*/, ULONG nAudioSampleFrequency /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_BROADCAST_CLIENT_FAIL_CALLBACK)( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, QRESULT nErrorStatus /*IN*/, DWORD nErrorCode /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_BROADCAST_CLIENT_RECORD_DONE_CALLBACK)( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, CHAR * pszFilePathName /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_BROADCAST_CLIENT_RECORD_FAIL_CALLBACK)( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, CHAR * pszFilePathName /*IN*/, QRESULT nErrorStatus /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_BROADCAST_CLIENT_SNAPSHOT_DONE_CALLBACK)( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, CHAR * pszFilePathName /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_BROADCAST_CLIENT_SNAPSHOT_STREAM_CALLBACK)( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, CHAR * pszFilePathName /*IN*/, BYTE * pStreamBuffer /*IN*/, ULONG nStreamBufferLen /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_BROADCAST_CLIENT_VISCA_COMMAND_CALLBACK)( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, BYTE * pCommand /*IN*/, ULONG nCommandSize /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_BROADCAST_CLIENT_PELCO_COMMAND_CALLBACK)( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, BYTE * pCommand /*IN*/, ULONG nCommandSize /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_VIDEO_BROADCAST_CLIENT_CALLBACK)( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, double dSampleTime /*IN*/, BYTE * pStreamBuffer /*IN*/, ULONG nStreamBufferLen /*IN*/, BOOL bIsKeyFrame /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_AUDIO_BROADCAST_CLIENT_CALLBACK)( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, double dSampleTime /*IN*/, BYTE * pStreamBuffer /*IN*/, ULONG nStreamBufferLen /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_VIDEO_DECODER_BROADCAST_CLIENT_CALLBACK)( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, double dSampleTime /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_AUDIO_DECODER_BROADCAST_CLIENT_CALLBACK)( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, double dSampleTime /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_VIDEO_METADATA_BROADCAST_CLIENT_CALLBACK)( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, double dSampleTime /*IN*/, BYTE * pMetadataBuffer /*IN*/, ULONG nMetadataBufferLen /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_AUDIO_METADATA_BROADCAST_CLIENT_CALLBACK)( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, double dSampleTime /*IN*/, BYTE * pMetadataBuffer /*IN*/, ULONG nMetadataBufferLen /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_VIDEO_DECODER_3D_BROADCAST_CLIENT_CALLBACK)( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, UINT iChNum /*IN*/, double dSampleTime /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|    |    |  |    |NDI|  |  |*/ QCAP_BROADCAST_NDI_CLIENT_ENUMERATION( CHAR * * ppszNDIName /*OUT*/, CHAR * * ppszGroupName /*OUT*/, BOOL bNext /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|   |2D|  |*/ QCAP_CREATE_BROADCAST_CLIENT( UINT iCliNum /*IN*/ /*0 ~ 63*/, CHAR * pszURL /*IN*/, PVOID * ppClient /*OUT*/, ULONG nDecoderType /*IN*/, HWND hAttachedWindow /*IN*/, BOOL bThumbDraw /*IN*/, BOOL bMaintainAspectRatio /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|   |2D|  |*/ QCAP_CREATE_BROADCAST_CLIENT_EX( UINT iCliNum /*IN*/ /*0 ~ 63*/, CHAR * pszURL /*IN*/, PVOID * ppClient /*OUT*/, ULONG nDecoderType /*IN*/, CHAR * pszNetworkAdapterIP /*IN*/, HWND hAttachedWindow /*IN*/, BOOL bThumbDraw /*IN*/, BOOL bMaintainAspectRatio /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|    |  |    |   |  |3D|*/ QCAP_CREATE_3D_BROADCAST_CLIENT( UINT iCliNum /*IN*/ /*0 ~ 63*/, CHAR * pszURL /*IN*/, PVOID * ppClient /*OUT*/, ULONG nDecoderType /*IN*/, HWND hAttachedWindowL /*IN*/, BOOL bThumbDrawL /*IN*/, BOOL bMaintainAspectRatioL /*IN*/, HWND hAttachedWindowR /*IN*/, BOOL bThumbDrawR /*IN*/, BOOL bMaintainAspectRatioR /*IN*/ ); // ONLY FOR RTSP

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|    |  |    |   |  |3D|*/ QCAP_CREATE_3D_BROADCAST_CLIENT_EX( UINT iCliNum /*IN*/ /*0 ~ 63*/, CHAR * pszURL /*IN*/, PVOID * ppClient /*OUT*/, ULONG nDecoderType /*IN*/, CHAR * pszNetworkAdapterIP /*IN*/, HWND hAttachedWindowL /*IN*/, BOOL bThumbDrawL /*IN*/, BOOL bMaintainAspectRatioL /*IN*/, HWND hAttachedWindowR /*IN*/, BOOL bThumbDrawR /*IN*/, BOOL bMaintainAspectRatioR /*IN*/ ); // ONLY FOR RTSP

QCAP_EXT_API QRESULT QCAP_EXPORT /*|    |    |  |    |NDI|2D|  |*/ QCAP_CREATE_BROADCAST_NDI_CLIENT( UINT iCliNum /*IN*/ /*0 ~ 63*/, CHAR * pszNDIName /*IN*/, CHAR * pszGroupName /*IN*/, PVOID * ppClient /*OUT*/, BOOL bEnableNDIProxy /*IN*/, ULONG nDecoderType /*IN*/, HWND hAttachedWindow /*IN*/, BOOL bThumbDraw /*IN*/, BOOL bMaintainAspectRatio /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|    |    |  |    |NDI|2D|  |*/ QCAP_CREATE_BROADCAST_NDI_HX_CLIENT( UINT iCliNum /*IN*/ /*0 ~ 63*/, CHAR * pszNDIName /*IN*/, CHAR * pszGroupName /*IN*/, PVOID * ppClient /*OUT*/, BOOL bEnableNDIProxy /*IN*/, ULONG nDecoderType /*IN*/, HWND hAttachedWindow /*IN*/, BOOL bThumbDraw /*IN*/, BOOL bMaintainAspectRatio /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|    |    |TS|    |   |2D|  |*/ QCAP_CREATE_BROADCAST_SRT_CLIENT( UINT iCliNum /*IN*/ /*0 ~ 63*/, CHAR * pszURL /*IN*/, PVOID * ppClient /*OUT*/, ULONG nSRTLatency /*IN*/, ULONG nSRTOverheadBandwidth /*IN*/, ULONG nDecoderType /*IN*/, HWND hAttachedWindow /*IN*/, BOOL bThumbDraw /*IN*/, BOOL bMaintainAspectRatio /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_DESTROY_BROADCAST_CLIENT( PVOID pClient /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_START_BROADCAST_CLIENT( PVOID pClient /*IN*/, ULONG nProtocol /*IN*/, ULONG nReconnectionTimeout /*IN*/, ULONG nDelayQueueDuration /*IN*/ ); // BPS >= 12MBPS, SUGGEST TO SUE QCAP_BROADCAST_PROTOCOL_TCP

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_START_BROADCAST_CLIENT_EX( PVOID pClient /*IN*/, ULONG nProtocol /*IN*/, ULONG nReconnectionTimeout /*IN*/, ULONG nVideoDelayQueueDuration /*IN*/, ULONG nAudioDelayQueueDuration /*IN*/, BOOL bEnableUltraLowLatency /*IN*/, ULONG nAnalyzeDuration /*IN*/, ULONG nProbeDurationSizeKB /*IN*/, CHAR * pszEncryptKey /*IN*/ ); // BPS >= 12MBPS, SUGGEST TO SUE QCAP_BROADCAST_PROTOCOL_TCP

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_STOP_BROADCAST_CLIENT( PVOID pClient /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|    |    |TS|MPTS|   |2D|  |*/ QCAP_GET_BROADCAST_CLIENT_OUTPUT_STREAMS( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, ULONG * pVideoStream_PID /*OUT*/, ULONG * pAudioStream_PID /*OUT*/, HWND * pAttachedWindow /*OUT*/, BOOL * pThumbDraw /*OUT*/, BOOL * pMaintainAspectRatio /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|    |    |TS|MPTS|   |2D|  |*/ QCAP_SET_BROADCAST_CLIENT_OUTPUT_STREAMS( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, ULONG nVideoStream_PID /*IN*/, ULONG nAudioStream_PID /*IN*/, HWND hAttachedWindow /*IN*/, BOOL bThumbDraw /*IN*/, BOOL bMaintainAspectRatio /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|    |  |    |   |2D|3D|*/ QCAP_GET_BROADCAST_CLIENT_VISCA_CONNECTION( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, BYTE * pDevAddr /*OUT*/, CHAR * pszDevIP /*OUT*/, ULONG * pDevPort /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|    |  |    |   |2D|3D|*/ QCAP_SET_BROADCAST_CLIENT_VISCA_CONNECTION( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, BYTE bDevAddr /*IN*/, CHAR * pszDevIP /*IN*/, ULONG nDevPort /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|    |  |    |   |2D|3D|*/ QCAP_GET_BROADCAST_CLIENT_PELCO_CONNECTION( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, BYTE * pDevAddr /*OUT*/, ULONG * pComPort /*OUT*/, ULONG * pBaudRate /*OUT*/, ULONG * pDataBits /*OUT*/, ULONG * pParityCheck /*OUT*/, ULONG * pStopBits /*OUT*/, ULONG * pFlowControl /*OUT*/, BOOL * pAsynchronousIO /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|    |  |    |   |2D|3D|*/ QCAP_SET_BROADCAST_CLIENT_PELCO_CONNECTION( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, BYTE bDevAddr /*IN*/, ULONG nComPort /*IN*/, ULONG nBaudRate /*IN*/, ULONG nDataBits /*IN*/, ULONG nParityCheck /*IN*/, ULONG nStopBits /*IN*/, ULONG nFlowControl /*IN*/, BOOL bAsynchronousIO /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_DIAGNOSE_VIDEO_BROADCAST_CLIENT_STREAM_STATUS( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, BOOL * pIsStill /*OUT*/, ULONG nStillThreshold /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_DIAGNOSE_AUDIO_BROADCAST_CLIENT_STREAM_STATUS( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, double * pVolumeDB_L /*OUT*/ /*RANGE = -100 ~ 0 (DB)*/, double * pVolumeDB_R /*OUT*/ /*RANGE = -100 ~ 0 (DB)*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|    |  |    |   |  |3D|*/ QCAP_GET_VIDEO_3D_BROADCAST_CLIENT_DISPLAY_MODE( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, ULONG * pStereoDisplayMode /*OUT*/, BOOL * pLeftRightSwap /*OUT*/ ); 

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|    |  |    |   |  |3D|*/ QCAP_SET_VIDEO_3D_BROADCAST_CLIENT_DISPLAY_MODE( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, ULONG nStereoDisplayMode /*IN*/, BOOL bLeftRightSwap /*IN*/ ); 

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_GET_VIDEO_BROADCAST_CLIENT_DEINTERLACE_TYPE( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, ULONG * pType /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_SET_VIDEO_BROADCAST_CLIENT_DEINTERLACE_TYPE( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, ULONG nType /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_GET_VIDEO_BROADCAST_CLIENT_DEINTERLACE( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, BOOL * pEnable /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_SET_VIDEO_BROADCAST_CLIENT_DEINTERLACE( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, BOOL bEnable /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_GET_VIDEO_BROADCAST_CLIENT_REGION_DISPLAY( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, ULONG * pCropX /*OUT*/, ULONG * pCropY /*OUT*/, ULONG * pCropW /*OUT*/, ULONG * pCropH /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_SET_VIDEO_BROADCAST_CLIENT_REGION_DISPLAY( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, ULONG nCropX /*IN*/, ULONG nCropY /*IN*/, ULONG nCropW /*IN*/, ULONG nCropH /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_GET_VIDEO_BROADCAST_CLIENT_MIRROR( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, BOOL * pHorizontalMirror /*OUT*/, BOOL * pVerticalMirror /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_SET_VIDEO_BROADCAST_CLIENT_MIRROR( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, BOOL bHorizontalMirror /*IN*/, BOOL bVerticalMirror /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_GET_VIDEO_BROADCAST_CLIENT_ASPECT_RATIO( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, BOOL * pMaintainAspectRatio /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_SET_VIDEO_BROADCAST_CLIENT_ASPECT_RATIO( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, BOOL bMaintainAspectRatio /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_GET_VIDEO_BROADCAST_CLIENT_BRIGHTNESS( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, ULONG * pValue /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_SET_VIDEO_BROADCAST_CLIENT_BRIGHTNESS( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, ULONG nValue /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_GET_VIDEO_BROADCAST_CLIENT_CONTRAST( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, ULONG * pValue /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_SET_VIDEO_BROADCAST_CLIENT_CONTRAST( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, ULONG nValue /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_GET_VIDEO_BROADCAST_CLIENT_HUE( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, ULONG * pValue /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_SET_VIDEO_BROADCAST_CLIENT_HUE( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, ULONG nValue /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_GET_VIDEO_BROADCAST_CLIENT_SATURATION( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, ULONG * pValue /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_SET_VIDEO_BROADCAST_CLIENT_SATURATION( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, ULONG nValue /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_GET_AUDIO_BROADCAST_CLIENT_SOUND_RENDERER( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, UINT * pSoundNum /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_SET_AUDIO_BROADCAST_CLIENT_SOUND_RENDERER( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, UINT iSoundNum /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_GET_AUDIO_BROADCAST_CLIENT_VOLUME( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, ULONG * pVolume /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_SET_AUDIO_BROADCAST_CLIENT_VOLUME( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, ULONG nVolume /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_START_BROADCAST_CLIENT_CLONE_RECORD( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, CHAR * pszFilePathNameA /*IN*/, CHAR * pszFilePathNameB /*IN*/, double dVideoDelayTime /*IN*/, double dAudioDelayTime /*IN*/, double dSegmentDurationTime /*IN*/, ULONG nSegmentDurationSizeKB /*IN*/, BOOL bIsSaveMetadata /*IN*/, BOOL bIsSubtitle /*IN*/, CHAR * pszEncryptKey /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_START_BROADCAST_CLIENT_TIMESHIFT_RECORD( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, CHAR * pszFilePathName /*IN*/, PVOID * ppPhysicalFileWriter /*OUT*/, double dVideoDelayTime /*IN*/, double dAudioDelayTime /*IN*/, BOOL bIsSaveMetadata /*IN*/, BOOL bIsSubtitle /*IN*/, CHAR * pszEncryptKey /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_START_BROADCAST_CLIENT_RECORD( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, CHAR * pszFilePathName /*IN*/, double dVideoDelayTime /*IN*/, double dAudioDelayTime /*IN*/, double dSegmentDurationTime /*IN*/, ULONG nSegmentDurationSizeKB /*IN*/, BOOL bIsSaveMetadata /*IN*/, BOOL bIsSubtitle /*IN*/, CHAR * pszEncryptKey /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_STOP_BROADCAST_CLIENT_RECORD( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, BOOL bIsAsync /*IN*/, ULONG nMilliseconds /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_RESUME_BROADCAST_CLIENT_RECORD( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_PAUSE_BROADCAST_CLIENT_RECORD( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_SEGMENT_BROADCAST_CLIENT_RECORD( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_SNAPSHOT_BROADCAST_CLIENT_BMP( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, CHAR * pszFilePathName /*IN*/, BOOL bIsAsync /*IN*/, ULONG nMilliseconds /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_SNAPSHOT_BROADCAST_CLIENT_JPG( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, CHAR * pszFilePathName /*IN*/, ULONG nQuality /*IN*/, BOOL bIsAsync /*IN*/, ULONG nMilliseconds /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_SNAPSHOT_BROADCAST_CLIENT_BMP_EX( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, CHAR * pszFilePathName /*IN*/, ULONG nCropX /*IN*/, ULONG nCropY /*IN*/, ULONG nCropW /*IN*/, ULONG nCropH /*IN*/, ULONG nDstW /*IN*/, ULONG nDstH /*IN*/, BOOL bIsAsync /*IN*/, ULONG nMilliseconds /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_SNAPSHOT_BROADCAST_CLIENT_JPG_EX( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, CHAR * pszFilePathName /*IN*/, ULONG nCropX /*IN*/, ULONG nCropY /*IN*/, ULONG nCropW /*IN*/, ULONG nCropH /*IN*/, ULONG nDstW /*IN*/, ULONG nDstH /*IN*/, ULONG nQuality /*IN*/, BOOL bIsAsync /*IN*/, ULONG nMilliseconds /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_MOVE_OSD_BROADCAST_CLIENT_OBJECT( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, ULONG nSequenceStyle /*IN*/, double dLifeTime /*IN*/ ); // FOR SCROLLING TEXT/PICTURE

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_GET_OSD_BROADCAST_CLIENT_TEXT_BOUNDARY( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, UINT iOsdNum /*IN*/, CHAR * pszString /*IN*/, CHAR * pszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, ULONG * pBoundaryWidth /*OUT*/, ULONG * pBoundaryHeight /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_GET_OSD_BROADCAST_CLIENT_TEXT_BOUNDARY_W( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, UINT iOsdNum /*IN*/, WSTRING pwszString /*IN*/, WSTRING pwszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, ULONG * pBoundaryWidth /*OUT*/, ULONG * pBoundaryHeight /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_SET_OSD_BROADCAST_CLIENT_TEXT( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, CHAR * pszString /*IN*/, CHAR * pszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, DWORD dwFontColor /*IN*/, DWORD dwBackgroundColor /*IN*/, ULONG nTransparent /*IN*/, INT nTextStartPosX /*IN*/, INT nTextStartPosY /*IN*/, ULONG nSequenceStyle /*IN*/, double dLifeTime /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_SET_OSD_BROADCAST_CLIENT_TEXT_W( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, WSTRING pwszString /*IN*/, WSTRING pwszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, DWORD dwFontColor /*IN*/, DWORD dwBackgroundColor /*IN*/, ULONG nTransparent /*IN*/, INT nTextStartPosX /*IN*/, INT nTextStartPosY /*IN*/, ULONG nSequenceStyle /*IN*/, double dLifeTime /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_SET_OSD_BROADCAST_CLIENT_TEXT_EX( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, CHAR * pszString /*IN*/, CHAR * pszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, DWORD dwFontColor /*IN*/, DWORD dwBackgroundColor /*IN*/, DWORD dwBorderColor /*IN*/, ULONG nBorderWidth /*IN*/, ULONG nTransparent /*IN*/, INT nTextStartPosX /*IN*/, INT nTextStartPosY /*IN*/, ULONG nStringAlignmentStyle /*IN*/, ULONG nSequenceStyle /*IN*/, double dLifeTime /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_SET_OSD_BROADCAST_CLIENT_TEXT_EX_W( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, WSTRING pwszString /*IN*/, WSTRING pwszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, DWORD dwFontColor /*IN*/, DWORD dwBackgroundColor /*IN*/, DWORD dwBorderColor /*IN*/, ULONG nBorderWidth /*IN*/, ULONG nTransparent /*IN*/, INT nTextStartPosX /*IN*/, INT nTextStartPosY /*IN*/, ULONG nStringAlignmentStyle /*IN*/, ULONG nSequenceStyle /*IN*/, double dLifeTime /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_SET_OSD_BROADCAST_CLIENT_PICTURE( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, CHAR * pszFilePathName /*IN*/, ULONG nTransparent /*IN*/, ULONG nSequenceStyle /*IN*/, double dLifeTime /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_SET_OSD_BROADCAST_CLIENT_BUFFER( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, ULONG nColorSpaceType /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameWidth /*IN*/, ULONG nFrameHeight /*IN*/, ULONG nFramePitch /*IN*/, ULONG nTransparent /*IN*/, DWORD dwKeyColor /*IN*/, ULONG nKeyColorThreshold /*IN*/, ULONG nKeyColorBlurLevel /*IN*/, BOOL bKeyColorSpillSuppress /*IN*/, ULONG nKeyColorSpillSuppressThreshold /*IN*/, BYTE * pMaskBuffer /*IN*/, ULONG nSequenceStyle /*IN*/, double dLifeTime /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_SET_OSD_BROADCAST_CLIENT_BUFFER_EX( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, ULONG nColorSpaceType /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameWidth /*IN*/, ULONG nFrameHeight /*IN*/, ULONG nFramePitch /*IN*/, ULONG nCropX /*IN*/, ULONG nCropY /*IN*/, ULONG nCropW /*IN*/, ULONG nCropH /*IN*/, DWORD dwBorderColor /*IN*/, ULONG nBorderWidth /*IN*/, ULONG nTransparent /*IN*/, DWORD dwKeyColor /*IN*/, ULONG nKeyColorThreshold /*IN*/, ULONG nKeyColorBlurLevel /*IN*/, BOOL bKeyColorSpillSuppress /*IN*/, ULONG nKeyColorSpillSuppressThreshold /*IN*/, BYTE * pMaskBuffer /*IN*/, ULONG nSequenceStyle /*IN*/, double dLifeTime /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|    |  |    |   |2D|3D|*/ QCAP_SET_BROADCAST_CLIENT_VISCA_COMMAND( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, BYTE * pCommand /*IN*/, ULONG nCommandSize /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|    |  |    |   |2D|3D|*/ QCAP_SET_BROADCAST_CLIENT_PELCO_COMMAND( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, BYTE * pCommand /*IN*/, ULONG nCommandSize /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|    |    |  |    |NDI|2D|  |*/ QCAP_SET_BROADCAST_CLIENT_PTZ_COMMAND( PVOID pClient /*IN*/, UINT iSessionNum /*IN*/, ULONG nCommand /*IN*/, double dParam1 /*IN*/, double dParam2 /*IN*/, double dParam3 /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|    |  |    |   |2D|3D|*/ QCAP_GET_BROADCAST_CLIENT_CUSTOM_PROPERTY( PVOID pClient /*IN*/, CHAR * pszProperty /*IN*/, CHAR * * ppszValue /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|    |  |    |   |2D|3D|*/ QCAP_SET_BROADCAST_CLIENT_CUSTOM_PROPERTY( PVOID pClient /*IN*/, CHAR * pszProperty /*IN*/, CHAR * pszValue /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_REGISTER_BROADCAST_CLIENT_MEDIAINFO_CALLBACK( PVOID pClient /*IN*/, PF_BROADCAST_CLIENT_MEDIAINFO_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_REGISTER_BROADCAST_CLIENT_CONNECTED_CALLBACK( PVOID pClient /*IN*/, PF_BROADCAST_CLIENT_CONNECTED_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_REGISTER_BROADCAST_CLIENT_FAIL_CALLBACK( PVOID pClient /*IN*/, PF_BROADCAST_CLIENT_FAIL_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_REGISTER_BROADCAST_CLIENT_RECORD_DONE_CALLBACK( PVOID pClient /*IN*/, PF_BROADCAST_CLIENT_RECORD_DONE_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_REGISTER_BROADCAST_CLIENT_RECORD_FAIL_CALLBACK( PVOID pClient /*IN*/, PF_BROADCAST_CLIENT_RECORD_FAIL_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_REGISTER_BROADCAST_CLIENT_SNAPSHOT_DONE_CALLBACK( PVOID pClient /*IN*/, PF_BROADCAST_CLIENT_SNAPSHOT_DONE_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_REGISTER_BROADCAST_CLIENT_SNAPSHOT_STREAM_CALLBACK( PVOID pClient /*IN*/, PF_BROADCAST_CLIENT_SNAPSHOT_STREAM_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|    |  |    |   |2D|3D|*/ QCAP_REGISTER_BROADCAST_CLIENT_VISCA_COMMAND_CALLBACK( PVOID pClient /*IN*/, PF_BROADCAST_CLIENT_VISCA_COMMAND_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|    |  |    |   |2D|3D|*/ QCAP_REGISTER_BROADCAST_CLIENT_PELCO_COMMAND_CALLBACK( PVOID pClient /*IN*/, PF_BROADCAST_CLIENT_PELCO_COMMAND_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_REGISTER_VIDEO_BROADCAST_CLIENT_CALLBACK( PVOID pClient /*IN*/, PF_VIDEO_BROADCAST_CLIENT_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_REGISTER_AUDIO_BROADCAST_CLIENT_CALLBACK( PVOID pClient /*IN*/, PF_AUDIO_BROADCAST_CLIENT_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_REGISTER_VIDEO_DECODER_BROADCAST_CLIENT_CALLBACK( PVOID pClient /*IN*/, PF_VIDEO_DECODER_BROADCAST_CLIENT_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_REGISTER_AUDIO_DECODER_BROADCAST_CLIENT_CALLBACK( PVOID pClient /*IN*/, PF_AUDIO_DECODER_BROADCAST_CLIENT_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|    |  |    |   |  |3D|*/ QCAP_REGISTER_VIDEO_DECODER_3D_BROADCAST_CLIENT_CALLBACK( PVOID pClient /*IN*/, PF_VIDEO_DECODER_3D_BROADCAST_CLIENT_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_REGISTER_VIDEO_METADATA_BROADCAST_CLIENT_CALLBACK( PVOID pClient /*IN*/, PF_VIDEO_METADATA_BROADCAST_CLIENT_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|TS|MPTS|NDI|2D|3D|*/ QCAP_REGISTER_AUDIO_METADATA_BROADCAST_CLIENT_CALLBACK( PVOID pClient /*IN*/, PF_AUDIO_METADATA_BROADCAST_CLIENT_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );


#ifdef __cplusplus
}
#endif

#endif // QCAP_BROADCAST_H
