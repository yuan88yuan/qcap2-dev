#ifndef QCAP_PLAYBACK_H
#define QCAP_PLAYBACK_H

#include "qcap.sip.h"

#ifdef __cplusplus
extern "C"
{
#endif

// ##########################################################################################################################################################################################
// #
// # FILE PLAYBACK FUNCTIONS (PLAYBACK/EDITING/REPAIR/FILE)
// #
// ##########################################################################################################################################################################################
//
// FILE PLAYBACK FUNCTIONS //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
typedef QRETURN (QCAP_EXPORT *PF_FILE_SNAPSHOT_DONE_CALLBACK)( PVOID pFile /*IN*/, CHAR * pszFilePathName /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_FILE_SNAPSHOT_STREAM_CALLBACK)( PVOID pFile /*IN*/, CHAR * pszFilePathName /*IN*/, BYTE * pStreamBuffer /*IN*/, ULONG nStreamBufferLen /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_VIDEO_DECODER_FILE_CALLBACK)( PVOID pFile /*IN*/, double dSampleTime /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_AUDIO_DECODER_FILE_CALLBACK)( PVOID pFile /*IN*/, double dSampleTime /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_VIDEO_DECODER_FILE_CALLBACK_EX)( PVOID pFile /*IN*/, UINT iFrameNum /*IN*/, double dSampleTime /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, PVOID pUserData /*IN*/ ); // ONLY FOR QCAP_OPEN_FILE_EX & QCAP_OPEN_TIMESHIFT_FILE_EX

typedef QRETURN (QCAP_EXPORT *PF_AUDIO_DECODER_FILE_CALLBACK_EX)( PVOID pFile /*IN*/, UINT iFrameNum /*IN*/, double dSampleTime /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, PVOID pUserData /*IN*/ ); // ONLY FOR QCAP_OPEN_FILE_EX & QCAP_OPEN_TIMESHIFT_FILE_EX

typedef QRETURN (QCAP_EXPORT *PF_VIDEO_DECODER_3D_FILE_CALLBACK)( PVOID pFile /*IN*/, UINT iChNum /*IN*/, double dSampleTime /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_VIDEO_DECODER_3D_FILE_CALLBACK_EX)( PVOID pFile /*IN*/, UINT iChNum /*IN*/, UINT iFrameNum /*IN*/, double dSampleTime /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|   |  |  |   |*/ QCAP_OPEN_FILE( CHAR * pszFileName /*IN*/, PVOID * ppFile /*OUT*/, ULONG nDecoderType /*IN*/, ULONG * pVideoEncoderFormat /*OUT*/, ULONG * pVideoWidth /*OUT*/, ULONG * pVideoHeight /*OUT*/, double * pVideoFrameRate /*OUT*/, ULONG * pAudioEncoderFormat /*OUT*/, ULONG * pAudioChannels /*OUT*/, ULONG * pAudioBitsPerSample /*OUT*/, ULONG * pAudioSampleFrequency /*OUT*/, double * pTotalDurationTimes /*OUT*/, ULONG * pTotalVideoFrames /*OUT*/, ULONG * pTotalAudioFrames /*OUT*/, ULONG * pTotalMetadataFrames /*OUT*/, HWND hAttachedWindow /*IN*/, BOOL bThumbDraw DEFVAL( FALSE /*IN*/), BOOL bMaintainAspectRatio DEFVAL( FALSE /*IN*/), BOOL bEnableEditFunction DEFVAL( TRUE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |2D+|  |  |   |*/ QCAP_OPEN_FILE_EX( CHAR * pszFileName /*IN*/, PVOID * ppFile /*OUT*/, ULONG nDecoderType /*IN*/, ULONG * pVideoEncoderFormat /*OUT*/, ULONG * pVideoWidth /*OUT*/, ULONG * pVideoHeight /*OUT*/, double * pVideoFrameRate /*OUT*/, ULONG * pAudioEncoderFormat /*OUT*/, ULONG * pAudioChannels /*OUT*/, ULONG * pAudioBitsPerSample /*OUT*/, ULONG * pAudioSampleFrequency /*OUT*/, double * pTotalDurationTimes /*OUT*/, ULONG * pTotalVideoFrames /*OUT*/, ULONG * pTotalAudioFrames /*OUT*/, ULONG * pTotalMetadataFrames /*OUT*/, HWND hAttachedWindow /*IN*/, BOOL bThumbDraw DEFVAL( FALSE /*IN*/), BOOL bMaintainAspectRatio DEFVAL( FALSE /*IN*/), CHAR * pszEncryptKey DEFVAL( NULL /*IN*/), BOOL bEnableRewindFunction DEFVAL( FALSE /*IN*/ )); // MP4 ONLY, NOW

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |   |3D|  |   |*/ QCAP_OPEN_3D_FILE( CHAR * pszFileName /*IN*/, PVOID * ppFile /*OUT*/, BOOL * pIs3D /*OUT*/, ULONG nDecoderType /*IN*/, ULONG * pVideoEncoderFormat /*OUT*/, ULONG * pVideoWidth /*OUT*/, ULONG * pVideoHeight /*OUT*/, double * pVideoFrameRate /*OUT*/, ULONG * pAudioEncoderFormat /*OUT*/, ULONG * pAudioChannels /*OUT*/, ULONG * pAudioBitsPerSample /*OUT*/, ULONG * pAudioSampleFrequency /*OUT*/, double * pTotalDurationTimes /*OUT*/, ULONG * pTotalVideoFrames /*OUT*/, ULONG * pTotalAudioFrames /*OUT*/, ULONG * pTotalMetadataFrames /*OUT*/, HWND hAttachedWindowL /*IN*/, BOOL bThumbDrawL DEFVAL( FALSE /*IN*/), BOOL bMaintainAspectRatioL DEFVAL( FALSE /*IN*/), HWND hAttachedWindowR DEFVAL( NULL /*IN*/), BOOL bThumbDrawR DEFVAL( FALSE /*IN*/), BOOL bMaintainAspectRatioR DEFVAL( FALSE /*IN*/), BOOL bEnableEditFunction DEFVAL( TRUE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |2D+|3D|  |   |*/ QCAP_OPEN_3D_FILE_EX( CHAR * pszFileName /*IN*/, PVOID * ppFile /*OUT*/, BOOL * pIs3D /*OUT*/, ULONG nDecoderType /*IN*/, ULONG * pVideoEncoderFormat /*OUT*/, ULONG * pVideoWidth /*OUT*/, ULONG * pVideoHeight /*OUT*/, double * pVideoFrameRate /*OUT*/, ULONG * pAudioEncoderFormat /*OUT*/, ULONG * pAudioChannels /*OUT*/, ULONG * pAudioBitsPerSample /*OUT*/, ULONG * pAudioSampleFrequency /*OUT*/, double * pTotalDurationTimes /*OUT*/, ULONG * pTotalVideoFrames /*OUT*/, ULONG * pTotalAudioFrames /*OUT*/, ULONG * pTotalMetadataFrames /*OUT*/, HWND hAttachedWindowL /*IN*/, BOOL bThumbDrawL DEFVAL( FALSE /*IN*/), BOOL bMaintainAspectRatioL DEFVAL( FALSE /*IN*/), HWND hAttachedWindowR DEFVAL( NULL /*IN*/), BOOL bThumbDrawR DEFVAL( FALSE /*IN*/), BOOL bMaintainAspectRatioR DEFVAL( FALSE /*IN*/), CHAR * pszEncryptKey DEFVAL( NULL /*IN*/), BOOL bEnableRewindFunction DEFVAL( FALSE /*IN*/ )); // MP4 ONLY, NOW

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |   |  |TS|   |*/ QCAP_OPEN_TIMESHIFT_FILE_EX( PVOID pPhysicalFileWriter /*IN*/, PVOID * ppFile /*OUT*/, ULONG nDecoderType /*IN*/, ULONG * pVideoEncoderFormat /*OUT*/, ULONG * pVideoWidth /*OUT*/, ULONG * pVideoHeight /*OUT*/, double * pVideoFrameRate /*OUT*/, ULONG * pAudioEncoderFormat /*OUT*/, ULONG * pAudioChannels /*OUT*/, ULONG * pAudioBitsPerSample /*OUT*/, ULONG * pAudioSampleFrequency /*OUT*/, double * pTotalDurationTimes /*OUT*/, ULONG * pTotalVideoFrames /*OUT*/, ULONG * pTotalAudioFrames /*OUT*/, ULONG * pTotalMetadataFrames /*OUT*/, HWND hAttachedWindow /*IN*/, BOOL bThumbDraw DEFVAL( FALSE /*IN*/), BOOL bMaintainAspectRatio DEFVAL( FALSE /*IN*/), CHAR * pszEncryptKey DEFVAL( NULL /*IN*/), BOOL bEnableRewindFunction DEFVAL( FALSE /*IN*/ )); // MP4 ONLY, NOW

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |   |  |  |SCF|*/ QCAP_OPEN_SCF_FILE( UINT iChNum /*IN*/, PVOID * ppFile /*OUT*/, ULONG nDecoderType /*IN*/, HWND hAttachedWindow /*IN*/, BOOL bThumbDraw DEFVAL( FALSE /*IN*/), BOOL bMaintainAspectRatio DEFVAL( FALSE /*IN*/), double dStartSampleTime DEFVAL( 0.0 /*IN*/), double dStopSampleTime DEFVAL( 0.0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_DESTROY_FILE( PVOID pFile /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_PLAY_FILE( PVOID pFile /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_PLAY_FILE_EX( PVOID pFile /*IN*/, double dStartSampleTime /*IN*/, double dStopSampleTime /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_PAUSE_FILE( PVOID pFile /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_STOP_FILE( PVOID pFile /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |   |  |  |SCF|*/ QCAP_PLAY_GLOBAL_SCF_FILE();

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |   |  |  |SCF|*/ QCAP_PAUSE_GLOBAL_SCF_FILE();

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |   |  |  |SCF|*/ QCAP_STOP_GLOBAL_SCF_FILE();

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |   |  |TS|   |*/ QCAP_REFRESH_TIMESHIFT_FILE_INFO( PVOID pFile /*IN*/, double * pTotalDurationTimes /*OUT*/, ULONG * pTotalVideoFrames /*OUT*/, ULONG * pTotalAudioFrames /*OUT*/, ULONG * pTotalMetadataFrames /*OUT*/ ); // QCAP_OPEN_TIMESHIFT_FILE_EX

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |   |  |  |SCF|*/ QCAP_SCF_FILE_ENUMERATION( UINT iChNum /*IN*/, double dStartSearchTime /*IN*/, double dStopSearchTime /*IN*/, ULONG * pFileSizeHigh /*OUT*/, ULONG * pFileSizeLow /*OUT*/, double * pFileStartTime /*OUT*/, double * pFileStopTime /*OUT*/, double * pVideoStartTime /*OUT*/, double * pVideoStopTime /*OUT*/, double * pAudioStartTime /*OUT*/, double * pAudioStopTime /*OUT*/, ULONG * pVideoEncoderFormat /*OUT*/, ULONG * pVideoWidth /*OUT*/, ULONG * pVideoHeight /*OUT*/, double * pVideoFrameRate /*OUT*/, ULONG * pAudioEncoderFormat /*OUT*/, ULONG * pAudioChannels /*OUT*/, ULONG * pAudioBitsPerSample /*OUT*/, ULONG * pAudioSampleFrequency /*OUT*/, double * pTotalDurationTimes /*OUT*/, ULONG * pTotalVideoFrames /*OUT*/, ULONG * pTotalAudioFrames /*OUT*/, ULONG * pTotalMetadataFrames /*OUT*/, BOOL bNext DEFVAL( FALSE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |   |  |  |SCF|*/ QCAP_SET_SCF_FILE_TIMER( UINT iChNum /*IN*/, BOOL bEnableGlobalTimer /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_GET_FILE_INFO_EX( PVOID pFile /*IN*/, BOOL * pIsHDR /*OUT*/, BOOL * pIs3D /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_GET_FILE_POSITION( PVOID pFile /*IN*/, double * pSampleTime /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_SET_FILE_POSITION( PVOID pFile /*IN*/, double dSampleTime /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |2D+|  |TS|   |*/ QCAP_GET_FILE_POSITION_EX( PVOID pFile /*IN*/, double * pSampleTime /*OUT*/, ULONG nTimeUnit DEFVAL( QCAP_FILE_TIMEUNIT_FRAME /*IN*/ )); // ONLY FOR QCAP_OPEN_FILE_EX & QCAP_OPEN_TIMESHIFT_FILE_EX

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |2D+|  |TS|   |*/ QCAP_SET_FILE_POSITION_EX( PVOID pFile /*IN*/, double dSampleTime /*IN*/, ULONG nTimeUnit DEFVAL( QCAP_FILE_TIMEUNIT_FRAME /*IN*/ )); // ONLY FOR QCAP_OPEN_FILE_EX & QCAP_OPEN_TIMESHIFT_FILE_EX

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |   |  |  |SCF|*/ QCAP_GET_GLOBAL_SCF_FILE_POSITION( double * pSampleTime /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |   |  |  |SCF|*/ QCAP_SET_GLOBAL_SCF_FILE_POSITION( double dSampleTime /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_GET_FILE_PLAYBACK_PROPERTY( PVOID pFile /*IN*/, ULONG * pRepeatTimes /*OUT*/ /*-1 = FOREVER, 0 = DISABLE (DEFAULT)*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_SET_FILE_PLAYBACK_PROPERTY( PVOID pFile /*IN*/, ULONG nRepeatTimes /*IN*/ /*-1 = FOREVER, 0 = DISABLE (DEFAULT)*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_GET_FILE_PLAYBACK_SPEED( PVOID pFile /*IN*/, double * pSpeed /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_SET_FILE_PLAYBACK_SPEED( PVOID pFile /*IN*/, double dSpeed /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_GET_VIDEO_FILE_STREAM_BUFFER( PVOID pFile /*IN*/, UINT iFrameNum /*IN*/, BYTE * pStreamBuffer /*OUT*/, ULONG * pStreamBufferLen /*IN/OUT*/, BOOL * pIsKeyFrame /*OUT*/, double * pSampleTime /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_GET_AUDIO_FILE_STREAM_BUFFER( PVOID pFile /*IN*/, UINT iFrameNum /*IN*/, BYTE * pStreamBuffer /*OUT*/, ULONG * pStreamBufferLen /*IN/OUT*/, double * pSampleTime /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_GET_METADATA_FILE_DATA_BUFFER( PVOID pFile /*IN*/, UINT iFrameNum /*IN*/, BYTE * pDataBuffer /*OUT*/, ULONG * pDataBufferLen /*IN/OUT*/, double * pSampleTime /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_GET_METADATA_FILE_HEADER( PVOID pFile /*IN*/, CHAR * * ppszTitle /*OUT*/, CHAR * * ppszArtist /*OUT*/, CHAR * * ppszComments /*OUT*/, CHAR * * ppszGenre /*OUT*/, CHAR * * ppszComposer /*OUT*/, CHAR * pszThumbnailPathName /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_GET_METADATA_FILE_HEADER_W( PVOID pFile /*IN*/, WSTRING * ppwszTitle /*OUT*/, WSTRING * ppwszArtist /*OUT*/, WSTRING * ppwszComments /*OUT*/, WSTRING * ppwszGenre /*OUT*/, WSTRING * ppwszComposer /*OUT*/, WSTRING pwszThumbnailPathName /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |   |3D|  |   |*/ QCAP_GET_VIDEO_3D_FILE_DISPLAY_MODE( PVOID pFile /*IN*/, ULONG * pStereoDisplayMode /*OUT*/, BOOL * pLeftRightSwap /*OUT*/ );  // ONLY FOR QCAP_OPEN_3D_FILE

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |   |3D|  |   |*/ QCAP_SET_VIDEO_3D_FILE_DISPLAY_MODE( PVOID pFile /*IN*/, ULONG nStereoDisplayMode DEFVAL( QCAP_3D_STEREO_DISPLAY_MODE_LINE_BY_LINE /*IN*/), BOOL bLeftRightSwap DEFVAL( FALSE /*IN*/ )); // ONLY FOR QCAP_OPEN_3D_FILE

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_GET_VIDEO_FILE_DEINTERLACE_TYPE( PVOID pFile /*IN*/, ULONG * pType /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_SET_VIDEO_FILE_DEINTERLACE_TYPE( PVOID pFile /*IN*/, ULONG nType /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_GET_VIDEO_FILE_DEINTERLACE( PVOID pFile /*IN*/, BOOL * pEnable /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_SET_VIDEO_FILE_DEINTERLACE( PVOID pFile /*IN*/, BOOL bEnable /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_GET_VIDEO_FILE_REGION_DISPLAY( PVOID pFile /*IN*/, ULONG * pCropX /*OUT*/, ULONG * pCropY /*OUT*/, ULONG * pCropW /*OUT*/, ULONG * pCropH /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_SET_VIDEO_FILE_REGION_DISPLAY( PVOID pFile /*IN*/, ULONG nCropX /*IN*/, ULONG nCropY /*IN*/, ULONG nCropW /*IN*/, ULONG nCropH /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_GET_VIDEO_FILE_MIRROR( PVOID pFile /*IN*/, BOOL * pHorizontalMirror /*OUT*/, BOOL * pVerticalMirror /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_SET_VIDEO_FILE_MIRROR( PVOID pFile /*IN*/, BOOL bHorizontalMirror /*IN*/, BOOL bVerticalMirror /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_GET_VIDEO_FILE_ASPECT_RATIO( PVOID pFile /*IN*/, BOOL * pMaintainAspectRatio /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_SET_VIDEO_FILE_ASPECT_RATIO( PVOID pFile /*IN*/, BOOL bMaintainAspectRatio /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_GET_VIDEO_FILE_BRIGHTNESS( PVOID pFile /*IN*/, ULONG * pValue /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_SET_VIDEO_FILE_BRIGHTNESS( PVOID pFile /*IN*/, ULONG nValue /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_GET_VIDEO_FILE_CONTRAST( PVOID pFile /*IN*/, ULONG * pValue /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_SET_VIDEO_FILE_CONTRAST( PVOID pFile /*IN*/, ULONG nValue /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_GET_VIDEO_FILE_HUE( PVOID pFile /*IN*/, ULONG * pValue /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_SET_VIDEO_FILE_HUE( PVOID pFile /*IN*/, ULONG nValue /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_GET_VIDEO_FILE_SATURATION( PVOID pFile /*IN*/, ULONG * pValue /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_SET_VIDEO_FILE_SATURATION( PVOID pFile /*IN*/, ULONG nValue /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_GET_AUDIO_FILE_SOUND_RENDERER( PVOID pFile /*IN*/, UINT * pSoundNum /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_SET_AUDIO_FILE_SOUND_RENDERER( PVOID pFile /*IN*/, UINT iSoundNum /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_GET_AUDIO_FILE_VOLUME( PVOID pFile /*IN*/, ULONG * pVolume /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_SET_AUDIO_FILE_VOLUME( PVOID pFile /*IN*/, ULONG nVolume /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_SNAPSHOT_FILE_BMP( PVOID pFile /*IN*/, CHAR * pszFilePathName /*IN*/, BOOL bIsAsync DEFVAL( TRUE /*IN*/), ULONG nMilliseconds DEFVAL( 0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_SNAPSHOT_FILE_JPG( PVOID pFile /*IN*/, CHAR * pszFilePathName /*IN*/, ULONG nQuality /*IN*/, BOOL bIsAsync DEFVAL( TRUE /*IN*/), ULONG nMilliseconds DEFVAL( 0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_SNAPSHOT_FILE_BMP_EX( PVOID pFile /*IN*/, CHAR * pszFilePathName /*IN*/, ULONG nCropX /*IN*/, ULONG nCropY /*IN*/, ULONG nCropW /*IN*/, ULONG nCropH /*IN*/, ULONG nDstW /*IN*/, ULONG nDstH /*IN*/, BOOL bIsAsync DEFVAL( TRUE /*IN*/), ULONG nMilliseconds DEFVAL( 0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_SNAPSHOT_FILE_JPG_EX( PVOID pFile /*IN*/, CHAR * pszFilePathName /*IN*/, ULONG nCropX /*IN*/, ULONG nCropY /*IN*/, ULONG nCropW /*IN*/, ULONG nCropH /*IN*/, ULONG nDstW /*IN*/, ULONG nDstH /*IN*/, ULONG nQuality /*IN*/, BOOL bIsAsync DEFVAL( TRUE /*IN*/), ULONG nMilliseconds DEFVAL( 0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_MOVE_OSD_FILE_OBJECT( PVOID pFile /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, ULONG nSequenceStyle DEFVAL( QCAP_SEQUENCE_STYLE_FOREMOST /*IN*/), double dLifeTime DEFVAL( 0.0 /*IN*/ )); // FOR SCROLLING TEXT/PICTURE

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_GET_OSD_FILE_TEXT_BOUNDARY( PVOID pFile /*IN*/, UINT iOsdNum /*IN*/, CHAR * pszString /*IN*/, CHAR * pszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, ULONG * pBoundaryWidth /*OUT*/, ULONG * pBoundaryHeight /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_GET_OSD_FILE_TEXT_BOUNDARY_W( PVOID pFile /*IN*/, UINT iOsdNum /*IN*/, WSTRING pwszString /*IN*/, WSTRING pwszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, ULONG * pBoundaryWidth /*OUT*/, ULONG * pBoundaryHeight /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_SET_OSD_FILE_TEXT( PVOID pFile /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, CHAR * pszString /*IN*/, CHAR * pszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, DWORD dwFontColor /*IN*/, DWORD dwBackgroundColor /*IN*/, ULONG nTransparent /*IN*/, INT nTextStartPosX DEFVAL( 0 /*IN*/), INT nTextStartPosY DEFVAL( 0 /*IN*/), ULONG nSequenceStyle DEFVAL( QCAP_SEQUENCE_STYLE_FOREMOST /*IN*/), double dLifeTime DEFVAL( 0.0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_SET_OSD_FILE_TEXT_W( PVOID pFile /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, WSTRING pwszString /*IN*/, WSTRING pwszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, DWORD dwFontColor /*IN*/, DWORD dwBackgroundColor /*IN*/, ULONG nTransparent /*IN*/, INT nTextStartPosX DEFVAL( 0 /*IN*/), INT nTextStartPosY DEFVAL( 0 /*IN*/), ULONG nSequenceStyle DEFVAL( QCAP_SEQUENCE_STYLE_FOREMOST /*IN*/), double dLifeTime DEFVAL( 0.0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_SET_OSD_FILE_TEXT_EX( PVOID pFile /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, CHAR * pszString /*IN*/, CHAR * pszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, DWORD dwFontColor /*IN*/, DWORD dwBackgroundColor /*IN*/, DWORD dwBorderColor /*IN*/, ULONG nBorderWidth /*IN*/, ULONG nTransparent /*IN*/, INT nTextStartPosX DEFVAL( 0 /*IN*/), INT nTextStartPosY DEFVAL( 0 /*IN*/), ULONG nStringAlignmentStyle DEFVAL( QCAP_STRING_ALIGNMENT_STYLE_LEFT /*IN*/), ULONG nSequenceStyle DEFVAL( QCAP_SEQUENCE_STYLE_FOREMOST /*IN*/), double dLifeTime DEFVAL( 0.0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_SET_OSD_FILE_TEXT_EX_W( PVOID pFile /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, WSTRING pwszString /*IN*/, WSTRING pwszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, DWORD dwFontColor /*IN*/, DWORD dwBackgroundColor /*IN*/, DWORD dwBorderColor /*IN*/, ULONG nBorderWidth /*IN*/, ULONG nTransparent /*IN*/, INT nTextStartPosX DEFVAL( 0 /*IN*/), INT nTextStartPosY DEFVAL( 0 /*IN*/), ULONG nStringAlignmentStyle DEFVAL( QCAP_STRING_ALIGNMENT_STYLE_LEFT /*IN*/), ULONG nSequenceStyle DEFVAL( QCAP_SEQUENCE_STYLE_FOREMOST /*IN*/), double dLifeTime DEFVAL( 0.0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_SET_OSD_FILE_PICTURE( PVOID pFile /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, CHAR * pszFilePathName /*IN*/, ULONG nTransparent /*IN*/, ULONG nSequenceStyle DEFVAL( QCAP_SEQUENCE_STYLE_FOREMOST /*IN*/), double dLifeTime DEFVAL( 0.0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_SET_OSD_FILE_BUFFER( PVOID pFile /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, ULONG nColorSpaceType /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameWidth /*IN*/, ULONG nFrameHeight /*IN*/, ULONG nFramePitch /*IN*/, ULONG nTransparent /*IN*/, DWORD dwKeyColor DEFVAL( 0xFFFFFFFF /*IN*/ /*0xFFFFFFFF (OFF) / 0x00FF0000 (BLUE) / 0x0000FF00 (GREEN)*/), ULONG nKeyColorThreshold DEFVAL( 25 /*IN*/ /*0 ~ 128*/), ULONG nKeyColorBlurLevel DEFVAL( 2 /*IN*/ /*0 ~ 2*/), BOOL bKeyColorSpillSuppress DEFVAL( TRUE /*IN*/), ULONG nKeyColorSpillSuppressThreshold DEFVAL( 22 /*IN*/), BYTE * pMaskBuffer DEFVAL( NULL /*IN*/), ULONG nSequenceStyle DEFVAL( QCAP_SEQUENCE_STYLE_FOREMOST /*IN*/), double dLifeTime DEFVAL( 0.0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_SET_OSD_FILE_BUFFER_EX( PVOID pFile /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, ULONG nColorSpaceType /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameWidth /*IN*/, ULONG nFrameHeight /*IN*/, ULONG nFramePitch /*IN*/, ULONG nCropX /*IN*/, ULONG nCropY /*IN*/, ULONG nCropW /*IN*/, ULONG nCropH /*IN*/, DWORD dwBorderColor /*IN*/, ULONG nBorderWidth /*IN*/, ULONG nTransparent /*IN*/, DWORD dwKeyColor DEFVAL( 0xFFFFFFFF /*IN*/ /*0xFFFFFFFF (OFF) / 0x00FF0000 (BLUE) / 0x0000FF00 (GREEN)*/), ULONG nKeyColorThreshold DEFVAL( 25 /*IN*/ /*0 ~ 128*/), ULONG nKeyColorBlurLevel DEFVAL( 2 /*IN*/ /*0 ~ 2*/), BOOL bKeyColorSpillSuppress DEFVAL( TRUE /*IN*/), ULONG nKeyColorSpillSuppressThreshold DEFVAL( 22 /*IN*/), BYTE * pMaskBuffer DEFVAL( NULL /*IN*/), ULONG nSequenceStyle DEFVAL( QCAP_SEQUENCE_STYLE_FOREMOST /*IN*/), double dLifeTime DEFVAL( 0.0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_REGISTER_FILE_SNAPSHOT_DONE_CALLBACK( PVOID pFile /*IN*/, PF_FILE_SNAPSHOT_DONE_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_REGISTER_FILE_SNAPSHOT_STREAM_CALLBACK( PVOID pFile /*IN*/, PF_FILE_SNAPSHOT_STREAM_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_REGISTER_VIDEO_DECODER_FILE_CALLBACK( PVOID pFile /*IN*/, PF_VIDEO_DECODER_FILE_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|2D|2D+|3D|TS|SCF|*/ QCAP_REGISTER_AUDIO_DECODER_FILE_CALLBACK( PVOID pFile /*IN*/, PF_AUDIO_DECODER_FILE_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |2D+|  |TS|   |*/ QCAP_REGISTER_VIDEO_DECODER_FILE_CALLBACK_EX( PVOID pFile /*IN*/, PF_VIDEO_DECODER_FILE_CALLBACK_EX pCB /*IN*/, PVOID pUserData /*IN*/ ); // ONLY FOR QCAP_OPEN_FILE_EX & QCAP_OPEN_TIMESHIFT_FILE_EX

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |2D+|  |TS|   |*/ QCAP_REGISTER_AUDIO_DECODER_FILE_CALLBACK_EX( PVOID pFile /*IN*/, PF_AUDIO_DECODER_FILE_CALLBACK_EX pCB /*IN*/, PVOID pUserData /*IN*/ ); // ONLY FOR QCAP_OPEN_FILE_EX & QCAP_OPEN_TIMESHIFT_FILE_EX

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |   |3D|  |   |*/ QCAP_REGISTER_VIDEO_DECODER_3D_FILE_CALLBACK( PVOID pFile /*IN*/, PF_VIDEO_DECODER_3D_FILE_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ ); // ONLY FOR QCAP_OPEN_3D_FILE

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |2D+|3D|  |   |*/ QCAP_REGISTER_VIDEO_DECODER_3D_FILE_CALLBACK_EX( PVOID pFile /*IN*/, PF_VIDEO_DECODER_3D_FILE_CALLBACK_EX pCB /*IN*/, PVOID pUserData /*IN*/ ); // ONLY FOR QCAP_OPEN_3D_FILE_EX

// FILE EDITING FUNCTIONS ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_EXPORT_FILE( PVOID pFile /*IN*/, double dStartSampleTime /*IN*/, double dStopSampleTime /*IN*/, CHAR * pszExportedFileName /*IN*/, double * pExportedProgress /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_EXPORT_FILE_EX( PVOID pFile /*IN*/, CHAR * pszExportedFileName /*IN*/, double * pExportedProgress /*OUT*/, ULONG nFileArgs /*IN*/, double dStartSampleTime1 /*IN*/, double dStopSampleTime1 /*IN*/, double dStartSampleTime2 /*IN*/, double dStopSampleTime2 /*IN*/, ... );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_EXPORT_FILE_EX_C( PVOID pFile /*IN*/, CHAR * pszExportedFileName /*IN*/, double * pExportedProgress /*OUT*/, ULONG nFileArgs /*IN*/, double dStartSampleTimes[ ] /*IN*/, double dStopSampleTimes[ ] /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_EXPORT_FILES_EX( PVOID pFile /*IN*/, ULONG nFileArgs /*IN*/, double dStartSampleTime1 /*IN*/, double dStopSampleTime1 /*IN*/, CHAR * pszExportedFileName1 /*IN*/, double * pExportedProgress1 /*OUT*/, double dStartSampleTime2 /*IN*/, double dStopSampleTime2 /*IN*/, CHAR * pszExportedFileName2 /*IN*/, double * pExportedProgress2 /*OUT*/, ... );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_EXPORT_FILES_EX_C( PVOID pFile /*IN*/, ULONG nFileArgs /*IN*/, double dStartSampleTimes[ ] /*IN*/, double dStopSampleTimes[ ] /*IN*/, CHAR * pszExportedFileNames[ ] /*IN*/, double * pExportedProgress[ ] /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_MERGE_FILES( CHAR * pszFrontEndFileName /*IN*/, CHAR * pszBackEndFileName /*IN*/, CHAR * pszMergedFileName /*IN*/, double * pMergedProgress /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_MERGE_FILES_EX( CHAR * pszMergedFileName /*IN*/, double * pMergedProgress /*OUT*/, ULONG nFileArgs /*IN*/, CHAR * pszSourceFileName1 /*IN*/, CHAR * pszSourceFileName2 /*IN*/, ... );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_MERGE_FILES_EX_C( CHAR * pszMergedFileName /*IN*/, double * pMergedProgress /*OUT*/, ULONG nFileArgs /*IN*/, CHAR * pszSourceFileNames[ ] /*IN*/ /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_MERGE_FILES_BY_EDL( CHAR * pszEDLFileName /*IN*/, double * pMergedProgress /*OUT*/ ); // PLEASE REFERENCE DOC\MANUALS\13. FILE\MERGE.EDL.EXAMPLE.INI

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_BUILD_VIDEO_ON_DEMAND_FILE( CHAR * pszOriginalFileName /*IN*/, CHAR * pszVideoOnDemandFileName /*IN*/, double * pConvertProgress /*OUT*/ ); // ONLY FOR MP4 FILE BOXING

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_UPLOAD_FILE_TO_YOUTUBE( CHAR * pszUploadFileName /*IN*/, CHAR * pszAccount /*IN*/, CHAR * pszPassword /*IN*/, double * pUploadProgress /*OUT*/ ); // ONLY FOR MP4 FILE UPLOAD

// FILE REPAIR FUNCTIONS ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DIAGNOSE_FILE( CHAR * pszFileName /*IN*/, BOOL * pIsHealthy /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DIAGNOSE_FILE_W( WSTRING pwszFileName /*IN*/, BOOL * pIsHealthy /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REPAIR_FILE( CHAR * pszBadFileName /*IN*/, CHAR * pszRepairedFileName /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REPAIR_FILE_W( WSTRING pwszBadFileName /*IN*/, WSTRING pwszRepairedFileName /*IN*/ );

// FILE TRANSCODING FUNCTIONS ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
typedef QRETURN (QCAP_EXPORT *PF_FILE_TRANSCODER_CALLBACK)( PVOID pFileTranscoder /*IN*/, double dTransferProgress /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_FILE_TRANSCODER( CHAR * pszSrcFileName /*IN*/, PVOID * ppFileTranscoder /*OUT*/, ULONG nDecoderType /*IN*/, ULONG * pVideoEncoderFormat /*OUT*/, ULONG * pVideoWidth /*OUT*/, ULONG * pVideoHeight /*OUT*/, double * pVideoFrameRate /*OUT*/, ULONG * pAudioEncoderFormat /*OUT*/, ULONG * pAudioChannels /*OUT*/, ULONG * pAudioBitsPerSample /*OUT*/, ULONG * pAudioSampleFrequency /*OUT*/, double * pTotalDurationTimes /*OUT*/, ULONG * pTotalVideoFrames /*OUT*/, ULONG * pTotalAudioFrames /*OUT*/, ULONG * pTotalMetadataFrames /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_FILE_TRANSCODER( PVOID pFileTranscoder /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_FILE_TRANSCODER_PROPERTY( PVOID pFileTranscoder /*IN*/, ULONG * pEncoderType /*OUT*/, ULONG * pEncoderFormat /*OUT*/, ULONG * pWidth /*OUT*/, ULONG * pHeight /*OUT*/, double * pFrameRate /*OUT*/, ULONG * pRecordMode /*OUT*/, ULONG * pQuality /*OUT*/, ULONG * pBitRate /*OUT*/, ULONG * pGOP /*OUT*/, ULONG * pAspectRatioX /*OUT*/, ULONG * pAspectRatioY /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_FILE_TRANSCODER_PROPERTY( PVOID pFileTranscoder /*IN*/, ULONG   nEncoderType /*IN*/,  ULONG   nEncoderFormat /*IN*/,  ULONG   nWidth /*IN*/,  ULONG   nHeight /*IN*/,  double   dFrameRate /*IN*/,  ULONG   nRecordMode /*IN*/,  ULONG   nQuality /*IN*/,  ULONG   nBitRate /*IN*/,  ULONG   nGOP /*IN*/,  ULONG   nAspectRatioX /*IN*/,  ULONG   nAspectRatioY /*IN*/  );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_FILE_TRANSCODER_PROPERTY_EX( PVOID pFileTranscoder /*IN*/, UINT * pGpuNum /*OUT*/, ULONG * pEncoderType /*OUT*/, ULONG * pEncoderFormat /*OUT*/, ULONG * pWidth /*OUT*/, ULONG * pHeight /*OUT*/, double * pFrameRate /*OUT*/, ULONG * pRecordProfile /*OUT*/, ULONG * pRecordLevel /*OUT*/, ULONG * pRecordEntropy /*OUT*/, ULONG * pRecordComplexity /*OUT*/, ULONG * pRecordMode /*OUT*/, ULONG * pQuality /*OUT*/, ULONG * pBitRate /*OUT*/, ULONG * pGOP /*OUT*/, ULONG * pBFrames /*OUT*/, BOOL * pIsInterleaved /*OUT*/, ULONG * pSlices /*OUT*/, ULONG * pLayers /*OUT*/, ULONG * pSceneCut /*OUT*/, BOOL * pMultiThread /*OUT*/, BOOL * pMBBRC /*OUT*/, BOOL * pExtBRC /*OUT*/, ULONG * pMinQP /*OUT*/, ULONG * pMaxQP /*OUT*/, ULONG * pVBVMaxRate /*OUT*/, ULONG * pVBVBufSize /*OUT*/, ULONG * pCBRVariation /*OUT*/, ULONG * pAspectRatioX /*OUT*/, ULONG * pAspectRatioY /*OUT*/, ULONG * pScaleStyle /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_FILE_TRANSCODER_PROPERTY_EX( PVOID pFileTranscoder /*IN*/, UINT   iGpuNum /*IN*/,  ULONG   nEncoderType /*IN*/,  ULONG   nEncoderFormat /*IN*/,  ULONG   nWidth /*IN*/,  ULONG   nHeight /*IN*/,  double   dFrameRate /*IN*/,  ULONG   nRecordProfile /*IN*/, ULONG   nRecordLevel /*IN*/, ULONG   nRecordEntropy /*IN*/, ULONG   nRecordComplexity /*IN*/, ULONG   nRecordMode /*IN*/,  ULONG   nQuality /*IN*/,  ULONG   nBitRate /*IN*/,  ULONG   nGOP /*IN*/,  ULONG   nBFrames /*IN*/, BOOL   bIsInterleaved /*IN*/, ULONG   nSlices /*IN*/, ULONG   nLayers /*IN*/, ULONG   nSceneCut /*IN*/, BOOL   bMultiThread /*IN*/, BOOL   bMBBRC /*IN*/, BOOL   bExtBRC /*IN*/, ULONG   nMinQP /*IN*/, ULONG   nMaxQP /*IN*/, ULONG   nVBVMaxRate /*IN*/, ULONG   nVBVBufSize /*IN*/, ULONG   nCBRVariation /*IN*/, ULONG   nAspectRatioX /*IN*/,  ULONG   nAspectRatioY /*IN*/,  ULONG   nScaleStyle /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_FILE_TRANSCODER( PVOID pFileTranscoder /*IN*/, CHAR * pszDstFileName /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_FILE_TRANSCODER( PVOID pFileTranscoder /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_FILE_TRANSCODER_CALLBACK( PVOID pFileTranscoder /*IN*/, PF_FILE_TRANSCODER_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

#ifdef __cplusplus
}
#endif

#endif // QCAP_PLAYBACK_H
