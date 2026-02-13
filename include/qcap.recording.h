#ifndef QCAP_RECORDING_H
#define QCAP_RECORDING_H

#include "qcap.device.h"

#ifdef __cplusplus
extern "C"
{
#endif

// CHANNEL RECORDING FUNCTIONS (SUPPORT MULTIPLE-STREAMS CHANNEL RECORDING) (RECNUM: 0 ~ 3) /////////////////////////////////////////////////////////////////////////////////////////////////
// 
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_RECORD_PROPERTY( PVOID pDevice /*IN*/, UINT iRecNum /*IN*/, ULONG * pEncoderType /*OUT*/, ULONG * pEncoderFormat /*OUT*/, ULONG * pRecordMode /*OUT*/, ULONG * pQuality /*OUT*/, ULONG * pBitRate /*OUT*/, ULONG * pGOP /*OUT*/, ULONG * pAspectRatioX /*OUT*/, ULONG * pAspectRatioY /*OUT*/, ULONG * pDownscaleMode /*OUT*/ ); // HARDWARE ENCODER NEED USE QCAP_GET_VIDEO_HARDWARE_ENCODER_PROPERTY

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_RECORD_PROPERTY( PVOID pDevice /*IN*/, UINT iRecNum /*IN*/, ULONG   nEncoderType /*IN*/,  ULONG   nEncoderFormat /*IN*/,  ULONG   nRecordMode /*IN*/,  ULONG   nQuality /*IN*/,  ULONG   nBitRate /*IN*/,  ULONG   nGOP /*IN*/,  ULONG   nAspectRatioX /*IN*/,  ULONG   nAspectRatioY /*IN*/,  ULONG   nDownscaleMode /*IN*/  ); // HARDWARE ENCODER NEED USE QCAP_SET_VIDEO_HARDWARE_ENCODER_PROPERTY

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_RECORD_PROPERTY_EX( PVOID pDevice /*IN*/, UINT iRecNum /*IN*/, UINT * pGpuNum /*OUT*/, ULONG * pEncoderType /*OUT*/, ULONG * pEncoderFormat /*OUT*/, ULONG * pRecordProfile /*OUT*/ /*DEFAULT = BASELINE*/, ULONG * pRecordLevel /*OUT*/ /*DEFAULT = 41*/, ULONG * pRecordEntropy /*OUT*/ /*DEFAULT = CAVLC*/, ULONG * pRecordComplexity /*OUT*/ /*DEFAULT = 0*/, ULONG * pRecordMode /*OUT*/, ULONG * pQuality /*OUT*/, ULONG * pBitRate /*OUT*/, ULONG * pGOP /*OUT*/, ULONG * pBFrames /*OUT*/ /*DEFAULT = 0*/, BOOL * pIsInterleaved /*OUT*/ /*DEFAULT = FALSE*/, ULONG * pSlices /*OUT*/ /*DEFAULT = 0*/, ULONG * pLayers /*OUT*/ /*DEFAULT = 0*/, ULONG * pSceneCut /*OUT*/ /*DEFAULT = 0*/, BOOL * pMultiThread /*OUT*/ /*DEFAULT = TRUE*/, BOOL * pMBBRC /*OUT*/ /*DEFAULT = FALSE*/, BOOL * pExtBRC /*OUT*/ /*DEFAULT = FALSE*/, ULONG * pMinQP /*OUT*/ /*DEFAULT = 0*/, ULONG * pMaxQP /*OUT*/ /*DEFAULT = 0*/, ULONG * pVBVMaxRate /*OUT*/ /*DEFAULT = 0*/, ULONG * pVBVBufSize /*OUT*/ /*DEFAULT = 0*/, ULONG * pCBRVariation /*OUT*/ /*DEFAULT = 0*/, ULONG * pAspectRatioX /*OUT*/, ULONG * pAspectRatioY /*OUT*/, ULONG * pCropX /*OUT*/, ULONG * pCropY /*OUT*/, ULONG * pCropW /*OUT*/, ULONG * pCropH /*OUT*/, ULONG * pDstW /*OUT*/, ULONG * pDstH /*OUT*/, ULONG * pPostSkipFrameRate /*OUT*/ /*DEFAULT = 0*/, ULONG * pPostAvgFrameRate /*OUT*/ /*DEFAULT = 0*/ ); // HARDWARE ENCODER NEED USE QCAP_GET_VIDEO_HARDWARE_ENCODER_PROPERTY_EX

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_RECORD_PROPERTY_EX( PVOID pDevice /*IN*/, UINT iRecNum /*IN*/, UINT   iGpuNum /*IN*/,  ULONG   nEncoderType /*IN*/,  ULONG   nEncoderFormat /*IN*/,  ULONG   nRecordProfile /*IN*/  /*DEFAULT = BASELINE*/, ULONG   nRecordLevel /*IN*/  /*DEFAULT = 41*/, ULONG   nRecordEntropy /*IN*/  /*DEFAULT = CAVLC*/, ULONG   nRecordComplexity /*IN*/  /*DEFAULT = 0*/, ULONG   nRecordMode /*IN*/,  ULONG   nQuality /*IN*/,  ULONG   nBitRate /*IN*/,  ULONG   nGOP /*IN*/,  ULONG   nBFrames /*IN*/  /*DEFAULT = 0*/, BOOL   bIsInterleaved /*IN*/  /*DEFAULT = FALSE*/, ULONG   nSlices /*IN*/  /*DEFAULT = 0*/, ULONG   nLayers /*IN*/  /*DEFAULT = 0*/, ULONG   nSceneCut /*IN*/  /*DEFAULT = 0*/, BOOL   bMultiThread /*IN*/  /*DEFAULT = TRUE*/, BOOL   bMBBRC /*IN*/  /*DEFAULT = FALSE*/, BOOL   bExtBRC /*IN*/  /*DEFAULT = FALSE*/, ULONG   nMinQP /*IN*/  /*DEFAULT = 0*/, ULONG   nMaxQP /*IN*/  /*DEFAULT = 0*/, ULONG   nVBVMaxRate /*IN*/  /*DEFAULT = 0*/, ULONG   nVBVBufSize /*IN*/  /*DEFAULT = 0*/, ULONG   nCBRVariation /*IN*/  /*DEFAULT = 0*/, ULONG   nAspectRatioX /*IN*/,  ULONG   nAspectRatioY /*IN*/,  ULONG   nCropX /*IN*/,  ULONG   nCropY /*IN*/,  ULONG   nCropW /*IN*/,  ULONG   nCropH /*IN*/,  ULONG   nDstW /*IN*/,  ULONG   nDstH /*IN*/,  ULONG   nPostSkipFrameRate /*IN*/  /*DEFAULT = 0*/, ULONG   nPostAvgFrameRate /*IN*/  /*DEFAULT = 0*/ ); // HARDWARE ENCODER NEED USE QCAP_SET_VIDEO_HARDWARE_ENCODER_PROPERTY_EX

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_AUDIO_RECORD_PROPERTY( PVOID pDevice /*IN*/, UINT iRecNum /*IN*/, ULONG * pEncoderType /*OUT*/, ULONG * pEncoderFormat /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_RECORD_PROPERTY( PVOID pDevice /*IN*/, UINT iRecNum /*IN*/, ULONG   nEncoderType /*IN*/,  ULONG   nEncoderFormat /*IN*/  );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_AUDIO_RECORD_PROPERTY_EX( PVOID pDevice /*IN*/, UINT iRecNum /*IN*/, ULONG * pEncoderType /*OUT*/, ULONG * pEncoderFormat /*OUT*/, ULONG * pBitRate /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_RECORD_PROPERTY_EX( PVOID pDevice /*IN*/, UINT iRecNum /*IN*/, ULONG   nEncoderType /*IN*/,  ULONG   nEncoderFormat /*IN*/,  ULONG   nBitRate /*IN*/  );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_RECORD_DYNAMIC_PROPERTY_EX( PVOID pDevice /*IN*/, UINT iRecNum /*IN*/, ULONG * pRecordMode /*OUT*/, ULONG * pQuality /*OUT*/, ULONG * pBitRate /*OUT*/, ULONG * pGOP /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_RECORD_DYNAMIC_PROPERTY_EX( PVOID pDevice /*IN*/, UINT iRecNum /*IN*/, ULONG   nRecordMode /*IN*/,  ULONG   nQuality /*IN*/,  ULONG   nBitRate /*IN*/,  ULONG   nGOP /*IN*/  );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_METADATA_RECORD_HEADER( PVOID pDevice /*IN*/, UINT iRecNum /*IN*/, CHAR * pszTitle /*IN*/, CHAR * pszArtist /*IN*/, CHAR * pszComments /*IN*/, CHAR * pszGenre /*IN*/, CHAR * pszComposer /*IN*/, CHAR * pszThumbnailPathName /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_METADATA_RECORD_HEADER_W( PVOID pDevice /*IN*/, UINT iRecNum /*IN*/, WSTRING pwszTitle /*IN*/, WSTRING pwszArtist /*IN*/, WSTRING pwszComments /*IN*/, WSTRING pwszGenre /*IN*/, WSTRING pwszComposer /*IN*/, WSTRING pwszThumbnailPathName /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_METADATA_RECORD_DATA_BUFFER( PVOID pDevice /*IN*/, UINT iRecNum /*IN*/, BYTE * pDataBuffer /*IN*/, ULONG nDataBufferLen /*IN*/, double dSampleTime /*IN*/, BOOL bIsSubtitle /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_CLONE_RECORD( PVOID pDevice /*IN*/, UINT iRecNum /*IN*/, CHAR * pszFilePathNameA /*IN*/, CHAR * pszFilePathNameB /*IN*/, DWORD dwFlags /*IN*/, double dVideoDelayTime /*IN*/, double dAudioDelayTime /*IN*/, double dSegmentDurationTime /*IN*/, ULONG nSegmentDurationSizeKB /*IN*/, CHAR * pszEncryptKey /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_TIMESHIFT_RECORD( PVOID pDevice /*IN*/, UINT iRecNum /*IN*/, CHAR * pszFilePathName /*IN*/, PVOID * ppPhysicalFileWriter /*OUT*/, DWORD dwFlags /*IN*/, double dVideoDelayTime /*IN*/, double dAudioDelayTime /*IN*/, CHAR * pszEncryptKey /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_FAILSAFE_RECORD( PVOID pDevice /*IN*/, UINT iRecNum /*IN*/, CHAR * pszFilePathName /*IN*/, UINT iLinkRecNum /*IN*/, PVOID pLinkPhysicalFileWriter /*IN*/, double dPreRecordTime /*IN*/, CHAR * pszEncryptKey /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_RECORD( PVOID pDevice /*IN*/, UINT iRecNum /*IN*/, CHAR * pszFilePathName /*IN*/, DWORD dwFlags /*IN*/, double dVideoDelayTime /*IN*/, double dAudioDelayTime /*IN*/, double dSegmentDurationTime /*IN*/, ULONG nSegmentDurationSizeKB /*IN*/, CHAR * pszEncryptKey /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_RECORD( PVOID pDevice /*IN*/, UINT iRecNum /*IN*/, BOOL bIsAsync /*IN*/, ULONG nMilliseconds /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_RESUME_RECORD( PVOID pDevice /*IN*/, UINT iRecNum /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_PAUSE_RECORD( PVOID pDevice /*IN*/, UINT iRecNum /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SEGMENT_RECORD( PVOID pDevice /*IN*/, UINT iRecNum /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_RECORD_DONE_CALLBACK(  PVOID pDevice /*IN*/, UINT iRecNum /*IN*/, PF_RECORD_DONE_CALLBACK  pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_RECORD_FAIL_CALLBACK(  PVOID pDevice /*IN*/, UINT iRecNum /*IN*/, PF_RECORD_FAIL_CALLBACK  pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_VIDEO_RECORD_CALLBACK( PVOID pDevice /*IN*/, UINT iRecNum /*IN*/, PF_VIDEO_RECORD_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_AUDIO_RECORD_CALLBACK( PVOID pDevice /*IN*/, UINT iRecNum /*IN*/, PF_AUDIO_RECORD_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_MEDIA_RECORD_CALLBACK( PVOID pDevice /*IN*/, UINT iRecNum /*IN*/, PF_MEDIA_RECORD_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ ); // ONLY FOR TS & FLV FILE FORMAT

// SHARE RECORDING FUNCTIONS (SUPPORT MULTIPLE-STREAMS SHARE RECORDING) (RECNUM: 0 ~ 63) ////////////////////////////////////////////////////////////////////////////////////////////////////
// 
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_SHARE_RECORD_STATUS( UINT iRecNum /*IN*/, BOOL * pIsValid /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_SHARE_RECORD_PROPERTY( UINT iRecNum /*IN*/, ULONG * pEncoderType /*OUT*/, ULONG * pEncoderFormat /*OUT*/, ULONG * pColorSpaceType /*OUT*/, ULONG * pWidth /*OUT*/, ULONG * pHeight /*OUT*/, double * pFrameRate /*OUT*/, ULONG * pRecordMode /*OUT*/, ULONG * pQuality /*OUT*/, ULONG * pBitRate /*OUT*/, ULONG * pGOP /*OUT*/, ULONG * pAspectRatioX /*OUT*/, ULONG * pAspectRatioY /*OUT*/, HWND * pAttachedWindow /*OUT*/, BOOL * pThumbDraw /*OUT*/, BOOL * pMaintainAspectRatio /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_SHARE_RECORD_PROPERTY( UINT iRecNum /*IN*/, ULONG   nEncoderType /*IN*/,  ULONG   nEncoderFormat /*IN*/,  ULONG   nColorSpaceType /*IN*/,  ULONG   nWidth /*IN*/,  ULONG   nHeight /*IN*/,  double   dFrameRate /*IN*/,  ULONG   nRecordMode /*IN*/,  ULONG   nQuality /*IN*/,  ULONG   nBitRate /*IN*/,  ULONG   nGOP /*IN*/,  ULONG   nAspectRatioX /*IN*/,  ULONG   nAspectRatioY /*IN*/,  HWND   hAttachedWindow /*IN*/,  BOOL   bThumbDraw /*IN*/, BOOL   bMaintainAspectRatio /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_SHARE_RECORD_PROPERTY_EX( UINT iRecNum /*IN*/, UINT * pGpuNum /*OUT*/, ULONG * pEncoderType /*OUT*/, ULONG * pEncoderFormat /*OUT*/, ULONG * pColorSpaceType /*OUT*/, ULONG * pWidth /*OUT*/, ULONG * pHeight /*OUT*/, double * pFrameRate /*OUT*/, ULONG * pRecordProfile /*OUT*/ /*DEFAULT = BASELINE*/, ULONG * pRecordLevel /*OUT*/ /*DEFAULT = 41*/, ULONG * pRecordEntropy /*OUT*/ /*DEFAULT = CAVLC*/, ULONG * pRecordComplexity /*OUT*/ /*DEFAULT = 0*/, ULONG * pRecordMode /*OUT*/, ULONG * pQuality /*OUT*/, ULONG * pBitRate /*OUT*/, ULONG * pGOP /*OUT*/, ULONG * pBFrames /*OUT*/ /*DEFAULT = 0*/, BOOL * pIsInterleaved /*OUT*/ /*DEFAULT = FALSE*/, ULONG * pSlices /*OUT*/ /*DEFAULT = 0*/, ULONG * pLayers /*OUT*/ /*DEFAULT = 0*/, ULONG * pSceneCut /*OUT*/ /*DEFAULT = 0*/, BOOL * pMultiThread /*OUT*/ /*DEFAULT = TRUE*/, BOOL * pMBBRC /*OUT*/ /*DEFAULT = FALSE*/, BOOL * pExtBRC /*OUT*/ /*DEFAULT = FALSE*/, ULONG * pMinQP /*OUT*/ /*DEFAULT = 0*/, ULONG * pMaxQP /*OUT*/ /*DEFAULT = 0*/, ULONG * pVBVMaxRate /*OUT*/ /*DEFAULT = 0*/, ULONG * pVBVBufSize /*OUT*/ /*DEFAULT = 0*/, ULONG * pCBRVariation /*OUT*/ /*DEFAULT = 0*/, ULONG * pAspectRatioX /*OUT*/, ULONG * pAspectRatioY /*OUT*/, HWND * pAttachedWindow /*OUT*/, BOOL * pThumbDraw /*OUT*/, BOOL * pMaintainAspectRatio /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_SHARE_RECORD_PROPERTY_EX( UINT iRecNum /*IN*/, UINT   iGpuNum /*IN*/,  ULONG   nEncoderType /*IN*/,  ULONG   nEncoderFormat /*IN*/,  ULONG   nColorSpaceType /*IN*/,  ULONG   nWidth /*IN*/,  ULONG   nHeight /*IN*/,  double   dFrameRate /*IN*/,  ULONG   nRecordProfile /*IN*/  /*DEFAULT = BASELINE*/, ULONG   nRecordLevel /*IN*/  /*DEFAULT = 41*/, ULONG   nRecordEntropy /*IN*/  /*DEFAULT = CAVLC*/, ULONG   nRecordComplexity /*IN*/  /*DEFAULT = 0*/, ULONG   nRecordMode /*IN*/,  ULONG   nQuality /*IN*/,  ULONG   nBitRate /*IN*/,  ULONG   nGOP /*IN*/,  ULONG   nBFrames /*IN*/  /*DEFAULT = 0*/, BOOL   bIsInterleaved /*IN*/  /*DEFAULT = FALSE*/, ULONG   nSlices /*IN*/  /*DEFAULT = 0*/, ULONG   nLayers /*IN*/  /*DEFAULT = 0*/, ULONG   nSceneCut /*IN*/  /*DEFAULT = 0*/, BOOL   bMultiThread /*IN*/  /*DEFAULT = TRUE*/, BOOL   bMBBRC /*IN*/  /*DEFAULT = FALSE*/, BOOL   bExtBRC /*IN*/  /*DEFAULT = FALSE*/, ULONG   nMinQP /*IN*/  /*DEFAULT = 0*/, ULONG   nMaxQP /*IN*/  /*DEFAULT = 0*/, ULONG   nVBVMaxRate /*IN*/  /*DEFAULT = 0*/, ULONG   nVBVBufSize /*IN*/  /*DEFAULT = 0*/, ULONG   nCBRVariation /*IN*/  /*DEFAULT = 0*/, ULONG   nAspectRatioX /*IN*/,  ULONG   nAspectRatioY /*IN*/,  HWND   hAttachedWindow /*IN*/,  BOOL   bThumbDraw /*IN*/, BOOL   bMaintainAspectRatio /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_SHARE_RECORD_DYNAMIC_PROPERTY_EX( UINT iRecNum /*IN*/, ULONG * pRecordMode /*OUT*/, ULONG * pQuality /*OUT*/, ULONG * pBitRate /*OUT*/, ULONG * pGOP /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_SHARE_RECORD_DYNAMIC_PROPERTY_EX( UINT iRecNum /*IN*/, ULONG   nRecordMode /*IN*/,  ULONG   nQuality /*IN*/,  ULONG   nBitRate /*IN*/,  ULONG   nGOP /*IN*/  );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_SHARE_RECORD_HDR( UINT iRecNum /*IN*/, BOOL * pPhysicalEnable /*OUT*/, BOOL * pDisplayEnable /*OUT*/, BOOL * pIsDisplaySupported /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_SHARE_RECORD_HDR( UINT iRecNum /*IN*/, BOOL bPhysicalEnable /*IN*/, BOOL bDisplayEnable /*IN*/, PVOID pDevice /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_SHARE_RECORD_COPP( UINT iRecNum /*IN*/, BOOL * pEnable /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_SHARE_RECORD_COPP( UINT iRecNum /*IN*/, BOOL   bEnable /*IN*/  );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_SHARE_RECORD_BRIGHTNESS( UINT iRecNum /*IN*/, ULONG * pValue /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_SHARE_RECORD_BRIGHTNESS( UINT iRecNum /*IN*/, ULONG nValue /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_SHARE_RECORD_CONTRAST( UINT iRecNum /*IN*/, ULONG * pValue /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_SHARE_RECORD_CONTRAST( UINT iRecNum /*IN*/, ULONG nValue /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_SHARE_RECORD_HUE( UINT iRecNum /*IN*/, ULONG * pValue /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_SHARE_RECORD_HUE( UINT iRecNum /*IN*/, ULONG nValue /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_SHARE_RECORD_SATURATION( UINT iRecNum /*IN*/, ULONG * pValue /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_SHARE_RECORD_SATURATION( UINT iRecNum /*IN*/, ULONG nValue /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_AUDIO_SHARE_RECORD_PROPERTY( UINT iRecNum /*IN*/, ULONG * pEncoderType /*OUT*/, ULONG * pEncoderFormat /*OUT*/, ULONG * pChannels /*OUT*/, ULONG * pBitsPerSample /*OUT*/, ULONG * pSampleFrequency /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_SHARE_RECORD_PROPERTY( UINT iRecNum /*IN*/, ULONG   nEncoderType /*IN*/,  ULONG   nEncoderFormat /*IN*/,  ULONG   nChannels /*IN*/,  ULONG   nBitsPerSample /*IN*/,  ULONG   nSampleFrequency /*IN*/  );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_AUDIO_SHARE_RECORD_PROPERTY_EX( UINT iRecNum /*IN*/, ULONG * pEncoderType /*OUT*/, ULONG * pEncoderFormat /*OUT*/, ULONG * pChannels /*OUT*/, ULONG * pBitsPerSample /*OUT*/, ULONG * pSampleFrequency /*OUT*/, ULONG * pBitRate /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_SHARE_RECORD_PROPERTY_EX( UINT iRecNum /*IN*/, ULONG   nEncoderType /*IN*/,  ULONG   nEncoderFormat /*IN*/,  ULONG   nChannels /*IN*/,  ULONG   nBitsPerSample /*IN*/,  ULONG   nSampleFrequency /*IN*/,  ULONG   nBitRate /*IN*/  );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_AUDIO_SHARE_RECORD_SOUND_RENDERER( UINT iRecNum /*IN*/, UINT * pSoundNum /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_SHARE_RECORD_SOUND_RENDERER( UINT iRecNum /*IN*/, UINT   iSoundNum /*IN*/  );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_AUDIO_SHARE_RECORD_VOLUME( UINT iRecNum /*IN*/, ULONG * pVolume /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_SHARE_RECORD_VOLUME( UINT iRecNum /*IN*/, ULONG   nVolume /*IN*/  );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_AUDIO_SHARE_RECORD_NOISE_REMOVAL( UINT iRecNum /*IN*/, ULONG * pStrength /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_SHARE_RECORD_NOISE_REMOVAL( UINT iRecNum /*IN*/, ULONG   nStrength /*IN*/  );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_SHARE_RECORD_UNCOMPRESSION_BUFFER( UINT iRecNum /*IN*/, ULONG nColorSpaceType /*IN*/, ULONG nWidth /*IN*/, ULONG nHeight /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, double dSampleTime /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_SHARE_RECORD_UNCOMPRESSION_BUFFER_EX( UINT iRecNum /*IN*/, ULONG nColorSpaceType /*IN*/, ULONG nWidth /*IN*/, ULONG nHeight /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, ULONG nCropX /*IN*/, ULONG nCropY /*IN*/, ULONG nCropW /*IN*/, ULONG nCropH /*IN*/, ULONG nScaleStyle /*IN*/, BOOL bForceKeyFrame /*IN*/, double dSampleTime /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_SHARE_RECORD_UNCOMPRESSION_BUFFER( UINT iRecNum /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, double dSampleTime /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_SHARE_RECORD_UNCOMPRESSION_BUFFER_EX( UINT iRecNum /*IN*/, ULONG nChannels /*IN*/, ULONG nBitsPerSample /*IN*/, ULONG nSampleFrequency /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, double dSampleTime /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_SHARE_RECORD_COMPRESSION_BUFFER( UINT iRecNum /*IN*/, BYTE * pStreamBuffer /*IN*/, ULONG nStreamBufferLen /*IN*/, ULONG bIsKeyFrame /*IN*/, double dSampleTime /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_SHARE_RECORD_COMPRESSION_BUFFER( UINT iRecNum /*IN*/, BYTE * pStreamBuffer /*IN*/, ULONG nStreamBufferLen /*IN*/, double dSampleTime /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_METADATA_SHARE_RECORD_HEADER( UINT iRecNum /*IN*/, CHAR * pszTitle /*IN*/, CHAR * pszArtist /*IN*/, CHAR * pszComments /*IN*/, CHAR * pszGenre /*IN*/, CHAR * pszComposer /*IN*/, CHAR * pszThumbnailPathName /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_METADATA_SHARE_RECORD_HEADER_W( UINT iRecNum /*IN*/, WSTRING pwszTitle /*IN*/, WSTRING pwszArtist /*IN*/, WSTRING pwszComments /*IN*/, WSTRING pwszGenre /*IN*/, WSTRING pwszComposer /*IN*/, WSTRING pwszThumbnailPathName /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_METADATA_SHARE_RECORD_DATA_BUFFER( UINT iRecNum /*IN*/, BYTE * pDataBuffer /*IN*/, ULONG nDataBufferLen /*IN*/, double dSampleTime /*IN*/, BOOL bIsSubtitle /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_TIMESHIFT_SHARE_RECORD( UINT iRecNum /*IN*/, CHAR * pszFilePathName /*IN*/, PVOID * ppPhysicalFileWriter /*OUT*/, DWORD dwFlags /*IN*/, double dVideoDelayTime /*IN*/, double dAudioDelayTime /*IN*/, CHAR * pszEncryptKey /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_FAILSAFE_SHARE_RECORD( UINT iRecNum /*IN*/, CHAR * pszFilePathName /*IN*/, UINT iLinkRecNum /*IN*/, PVOID pLinkPhysicalFileWriter /*IN*/, double dPreRecordTime /*IN*/, CHAR * pszEncryptKey /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_SHARE_RECORD( UINT iRecNum /*IN*/, CHAR * pszFilePathName /*IN*/, DWORD dwFlags /*IN*/, double dVideoDelayTime /*IN*/, double dAudioDelayTime /*IN*/, double dSegmentDurationTime /*IN*/, ULONG nSegmentDurationSizeKB /*IN*/, CHAR * pszEncryptKey /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_SHARE_RECORD( UINT iRecNum /*IN*/, BOOL bIsAsync /*IN*/, ULONG nMilliseconds /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_RESUME_SHARE_RECORD( UINT iRecNum /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_PAUSE_SHARE_RECORD( UINT iRecNum /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SEGMENT_SHARE_RECORD( UINT iRecNum /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SNAPSHOT_SHARE_RECORD_BMP( UINT iRecNum /*IN*/, CHAR * pszFilePathName /*IN*/, BOOL bIsAsync /*IN*/, ULONG nMilliseconds /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SNAPSHOT_SHARE_RECORD_JPG( UINT iRecNum /*IN*/, CHAR * pszFilePathName /*IN*/, ULONG nQuality /*IN*/, BOOL bIsAsync /*IN*/, ULONG nMilliseconds /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SNAPSHOT_SHARE_RECORD_BMP_EX( UINT iRecNum /*IN*/, CHAR * pszFilePathName /*IN*/, ULONG nCropX /*IN*/, ULONG nCropY /*IN*/, ULONG nCropW /*IN*/, ULONG nCropH /*IN*/, ULONG nDstW /*IN*/, ULONG nDstH /*IN*/, BOOL bIsAsync /*IN*/, ULONG nMilliseconds /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SNAPSHOT_SHARE_RECORD_JPG_EX( UINT iRecNum /*IN*/, CHAR * pszFilePathName /*IN*/, ULONG nCropX /*IN*/, ULONG nCropY /*IN*/, ULONG nCropW /*IN*/, ULONG nCropH /*IN*/, ULONG nDstW /*IN*/, ULONG nDstH /*IN*/, ULONG nQuality /*IN*/, BOOL bIsAsync /*IN*/, ULONG nMilliseconds /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_SHARE_RECORD_DONE_CALLBACK( UINT iRecNum /*IN*/, PF_SHARE_RECORD_DONE_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_SHARE_RECORD_FAIL_CALLBACK( UINT iRecNum /*IN*/, PF_SHARE_RECORD_FAIL_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_SHARE_RECORD_SNAPSHOT_DONE_CALLBACK( UINT iRecNum /*IN*/, PF_SHARE_RECORD_SNAPSHOT_DONE_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_SHARE_RECORD_SNAPSHOT_STREAM_CALLBACK( UINT iRecNum /*IN*/, PF_SHARE_RECORD_SNAPSHOT_STREAM_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_VIDEO_SHARE_RECORD_CALLBACK( UINT iRecNum /*IN*/, PF_VIDEO_SHARE_RECORD_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_AUDIO_SHARE_RECORD_CALLBACK( UINT iRecNum /*IN*/, PF_AUDIO_SHARE_RECORD_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_MEDIA_SHARE_RECORD_CALLBACK( UINT iRecNum /*IN*/, PF_MEDIA_SHARE_RECORD_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ ); // ONLY FOR TS & FLV FILE FORMAT

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_VIDEO_DECODER_SHARE_RECORD_CALLBACK( UINT iRecNum /*IN*/, PF_VIDEO_DECODER_SHARE_RECORD_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_AUDIO_DECODER_SHARE_RECORD_CALLBACK( UINT iRecNum /*IN*/, PF_AUDIO_DECODER_SHARE_RECORD_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_VIDEO_DISPLAY_SHARE_RECORD_CALLBACK( UINT iRecNum /*IN*/, PF_VIDEO_DISPLAY_SHARE_RECORD_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_AUDIO_DISPLAY_SHARE_RECORD_CALLBACK( UINT iRecNum /*IN*/, PF_AUDIO_DISPLAY_SHARE_RECORD_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_VIDEO_SHARE_RECORD_MEDIA_TIMER_CALLBACK( UINT iRecNum /*IN*/, PF_VIDEO_SHARE_RECORD_MEDIA_TIMER_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_AUDIO_SHARE_RECORD_MEDIA_TIMER_CALLBACK( UINT iRecNum /*IN*/, PF_AUDIO_SHARE_RECORD_MEDIA_TIMER_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

// VIDEO 3D SHARE RECORDING FUNCTIONS (SUPPORT MULTIPLE-STREAMS SHARE RECORDING) (RECNUM: 0 ~ 63) ///////////////////////////////////////////////////////////////////////////////////////////
// 
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_3D_SHARE_RECORD_STEREO_UNCOMPRESSION_BUFFER( UINT iRecNum /*IN*/, ULONG nColorSpaceType /*IN*/, ULONG nWidth /*IN*/, ULONG nHeight /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, ULONG nStereoBufferType /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_3D_SHARE_RECORD_STEREO_UNCOMPRESSION_BUFFER_EX( UINT iRecNum /*IN*/, ULONG nColorSpaceType /*IN*/, ULONG nWidth /*IN*/, ULONG nHeight /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, ULONG nCropX /*IN*/, ULONG nCropY /*IN*/, ULONG nCropW /*IN*/, ULONG nCropH /*IN*/, ULONG nScaleStyle /*IN*/, ULONG nStereoBufferType /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_3D_SHARE_RECORD_L_UNCOMPRESSION_BUFFER( UINT iRecNum /*IN*/, ULONG nColorSpaceType /*IN*/, ULONG nWidth /*IN*/, ULONG nHeight /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_3D_SHARE_RECORD_L_UNCOMPRESSION_BUFFER_EX( UINT iRecNum /*IN*/, ULONG nColorSpaceType /*IN*/, ULONG nWidth /*IN*/, ULONG nHeight /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, ULONG nCropX /*IN*/, ULONG nCropY /*IN*/, ULONG nCropW /*IN*/, ULONG nCropH /*IN*/, ULONG nScaleStyle /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_3D_SHARE_RECORD_R_UNCOMPRESSION_BUFFER( UINT iRecNum /*IN*/, ULONG nColorSpaceType /*IN*/, ULONG nWidth /*IN*/, ULONG nHeight /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_3D_SHARE_RECORD_R_UNCOMPRESSION_BUFFER_EX( UINT iRecNum /*IN*/, ULONG nColorSpaceType /*IN*/, ULONG nWidth /*IN*/, ULONG nHeight /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, ULONG nCropX /*IN*/, ULONG nCropY /*IN*/, ULONG nCropW /*IN*/, ULONG nCropH /*IN*/, ULONG nScaleStyle /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_3D_SHARE_RECORD_UNCOMPRESSION_BUFFER( UINT iRecNum /*IN*/, ULONG nStereoDisplayMode /*IN*/, BOOL bLeftRightSwap /*IN*/, BOOL bForceKeyFrame /*IN*/, double dSampleTime /*IN*/ );

// AUDIO MIXING/TRACKS SHARE RECORDING FUNCTIONS (SUPPORT MULTIPLE-STREAMS SHARE RECORDING) (RECNUM: 0 ~ 63) (TRACKNUM: 0 ~ 3) //////////////////////////////////////////////////////////////////////
//
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_AUDIO_MX_SHARE_RECORD_PROPERTY_EX( UINT iRecNum /*IN*/, ULONG * pTracks /*OUT*/, ULONG * pEncoderType /*OUT*/, ULONG * pEncoderFormat /*OUT*/, ULONG * pChannels /*OUT*/, ULONG * pBitsPerSample /*OUT*/, ULONG * pSampleFrequency /*OUT*/, ULONG * pBitRate /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_MX_SHARE_RECORD_PROPERTY_EX( UINT iRecNum /*IN*/, ULONG   nTracks /*IN*/,  ULONG   nEncoderType /*IN*/,  ULONG   nEncoderFormat /*IN*/,  ULONG   nChannels /*IN*/,  ULONG   nBitsPerSample /*IN*/,  ULONG   nSampleFrequency /*IN*/,  ULONG   nBitRate /*IN*/  );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_MX_SHARE_RECORD_MIXING_UNCOMPRESSION_BUFFER( UINT iRecNum /*IN*/, UINT iTrackNum /*IN*/, UINT iMixNum /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_MX_SHARE_RECORD_MIXING_UNCOMPRESSION_BUFFER_EX( UINT iRecNum /*IN*/, UINT iTrackNum /*IN*/, UINT iMixNum /*IN*/, ULONG nChannels /*IN*/, ULONG nBitsPerSample /*IN*/, ULONG nSampleFrequency /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_MX_SHARE_RECORD_UNCOMPRESSION_BUFFER( UINT iRecNum /*IN*/, UINT iTrackNum /*IN*/, double dSampleTime /*IN*/, BOOL bEnableSyncMixer /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_MX_SHARE_RECORD_COMPRESSION_BUFFER( UINT iRecNum /*IN*/, UINT iTrackNum /*IN*/, BYTE * pStreamBuffer /*IN*/, ULONG nStreamBufferLen /*IN*/, double dSampleTime /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_AUDIO_MX_SHARE_RECORD_CALLBACK( UINT iRecNum /*IN*/, PF_AUDIO_MX_SHARE_RECORD_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_AUDIO_DECODER_MX_SHARE_RECORD_CALLBACK( UINT iRecNum /*IN*/, PF_AUDIO_DECODER_MX_SHARE_RECORD_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

// MULTIPLE CHANNELS SYNCHRONIZED RECORDING/PLAYBACK FUNCTIONS (SYNCHRONIZED RECORDING/PLAYBACK) ////////////////////////////////////////////////////////////////////////////////
//
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_SYNCHRONIZED_RECORD( PVOID * ppSyncRecorder /*IN*/, ULONG nFileArgs /*IN*/, CHAR * pszFilePathName1 /*IN*/, PVOID pDevice1 /*IN*/, UINT iRecNum1 /*IN*/, CHAR * pszFilePathName2 /*IN*/, PVOID pDevice2 /*IN*/, UINT iRecNum2 /*IN*/, ... );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_SYNCHRONIZED_RECORD( PVOID pSyncRecorder /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_SYNCHRONIZED_TIMESHIFT_RECORD( PVOID pSyncRecorder /*IN*/, PVOID * ppPhysicalFileWriters /*OUT*/, DWORD dwFlags /*IN*/, double dSegmentDurationTime /*IN*/, ULONG nSegmentDurationSizeKB /*IN*/, CHAR * pszEncryptKey /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_SYNCHRONIZED_RECORD( PVOID pSyncRecorder /*IN*/, DWORD dwFlags /*IN*/, double dSegmentDurationTime /*IN*/, ULONG nSegmentDurationSizeKB /*IN*/, CHAR * pszEncryptKey /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_SYNCHRONIZED_RECORD( PVOID pSyncRecorder /*IN*/, BOOL bIsAsync /*IN*/, ULONG nMilliseconds /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_RESUME_SYNCHRONIZED_RECORD( PVOID pSyncRecorder /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_PAUSE_SYNCHRONIZED_RECORD( PVOID pSyncRecorder /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SEGMENT_SYNCHRONIZED_RECORD( PVOID pSyncRecorder /*IN*/ );

#ifdef __cplusplus
}
#endif

#endif // QCAP_RECORDING_H
