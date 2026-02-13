#ifndef QCAP_VIRTUALCAMERA_H
#define QCAP_VIRTUALCAMERA_H

#include "qcap.animation.h"

#ifdef __cplusplus
extern "C"
{
#endif

// ##########################################################################################################################################################################################
// #
// # VIRTUAL CAMERA FUNCTIONS
// #
// ##########################################################################################################################################################################################
//
typedef QRETURN (QCAP_EXPORT *PF_VIRTUAL_CAMERA_SNAPSHOT_DONE_CALLBACK)( PVOID pCamera /*IN*/, CHAR * pszFilePathName /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_VIRTUAL_CAMERA_SNAPSHOT_STREAM_CALLBACK)( PVOID pCamera /*IN*/, CHAR * pszFilePathName /*IN*/, BYTE * pStreamBuffer /*IN*/, ULONG nStreamBufferLen /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |*/ QCAP_SET_DEFAULT_VIRTUAL_CAMERA( CHAR * pszCameraDevName /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |*/ QCAP_CREATE_VIRTUAL_CAMERA( UINT iCamNum /*IN*/ /*0 ~ 63*/, PVOID * ppCamera /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |*/ QCAP_DESTROY_VIRTUAL_CAMERA( PVOID pCamera /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |*/ QCAP_GET_VIDEO_VIRTUAL_CAMERA_PROPERTY( PVOID pCamera /*IN*/, ULONG * pColorSpaceType /*OUT*/, ULONG * pWidth /*OUT*/, ULONG * pHeight /*OUT*/, double * pFrameRate /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |*/ QCAP_SET_VIDEO_VIRTUAL_CAMERA_PROPERTY( PVOID pCamera /*IN*/, ULONG   nColorSpaceType /*IN*/,  ULONG   nWidth /*IN*/,  ULONG   nHeight /*IN*/,  double   dFrameRate /*IN*/  );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |*/ QCAP_GET_AUDIO_VIRTUAL_CAMERA_PROPERTY( PVOID pCamera /*IN*/, ULONG * pChannels /*OUT*/, ULONG * pBitsPerSample /*OUT*/, ULONG * pSampleFrequency /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |*/ QCAP_SET_AUDIO_VIRTUAL_CAMERA_PROPERTY( PVOID pCamera /*IN*/, ULONG   nChannels /*IN*/,  ULONG   nBitsPerSample /*IN*/,  ULONG   nSampleFrequency /*IN*/  );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |*/ QCAP_SET_VIDEO_VIRTUAL_CAMERA_UNCOMPRESSION_BUFFER( PVOID pCamera /*IN*/, ULONG nColorSpaceType /*IN*/, ULONG nWidth /*IN*/, ULONG nHeight /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, double dSampleTime /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |*/ QCAP_SET_VIDEO_VIRTUAL_CAMERA_UNCOMPRESSION_BUFFER_EX( PVOID pCamera /*IN*/, ULONG nColorSpaceType /*IN*/, ULONG nWidth /*IN*/, ULONG nHeight /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, ULONG nCropX /*IN*/, ULONG nCropY /*IN*/, ULONG nCropW /*IN*/, ULONG nCropH /*IN*/, ULONG nScaleStyle /*IN*/, double dSampleTime /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |*/ QCAP_SET_AUDIO_VIRTUAL_CAMERA_UNCOMPRESSION_BUFFER( PVOID pCamera /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, double dSampleTime /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |*/ QCAP_SET_AUDIO_VIRTUAL_CAMERA_UNCOMPRESSION_BUFFER_EX( PVOID pCamera /*IN*/, ULONG nChannels /*IN*/, ULONG nBitsPerSample /*IN*/, ULONG nSampleFrequency /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, double dSampleTime /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|MX|*/ QCAP_SET_AUDIO_MX_VIRTUAL_CAMERA_MIXING_UNCOMPRESSION_BUFFER( PVOID pCamera /*IN*/, UINT iMixNum /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/ ); // ONLY FOR AUDIO MIXING

QCAP_EXT_API QRESULT QCAP_EXPORT /*|MX|*/ QCAP_SET_AUDIO_MX_VIRTUAL_CAMERA_MIXING_UNCOMPRESSION_BUFFER_EX( PVOID pCamera /*IN*/, UINT iMixNum /*IN*/, ULONG nChannels /*IN*/, ULONG nBitsPerSample /*IN*/, ULONG nSampleFrequency /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/ ); // ONLY FOR AUDIO MIXING

QCAP_EXT_API QRESULT QCAP_EXPORT /*|MX|*/ QCAP_SET_AUDIO_MX_VIRTUAL_CAMERA_UNCOMPRESSION_BUFFER( PVOID pCamera /*IN*/, double dSampleTime /*IN*/, BOOL bEnableSyncMixer /*IN*/ ); // ONLY FOR AUDIO MIXING

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |*/ QCAP_START_VIRTUAL_CAMERA( PVOID pCamera /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |*/ QCAP_STOP_VIRTUAL_CAMERA( PVOID pCamera /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |*/ QCAP_SNAPSHOT_VIRTUAL_CAMERA_BMP( PVOID pCamera /*IN*/, CHAR * pszFilePathName /*IN*/, BOOL bIsAsync /*IN*/, ULONG nMilliseconds /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |*/ QCAP_SNAPSHOT_VIRTUAL_CAMERA_JPG( PVOID pCamera /*IN*/, CHAR * pszFilePathName /*IN*/, ULONG nQuality /*IN*/, BOOL bIsAsync /*IN*/, ULONG nMilliseconds /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |*/ QCAP_SNAPSHOT_VIRTUAL_CAMERA_BMP_EX( PVOID pCamera /*IN*/, CHAR * pszFilePathName /*IN*/, ULONG nCropX /*IN*/, ULONG nCropY /*IN*/, ULONG nCropW /*IN*/, ULONG nCropH /*IN*/, ULONG nDstW /*IN*/, ULONG nDstH /*IN*/, BOOL bIsAsync /*IN*/, ULONG nMilliseconds /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |*/ QCAP_SNAPSHOT_VIRTUAL_CAMERA_JPG_EX( PVOID pCamera /*IN*/, CHAR * pszFilePathName /*IN*/, ULONG nCropX /*IN*/, ULONG nCropY /*IN*/, ULONG nCropW /*IN*/, ULONG nCropH /*IN*/, ULONG nDstW /*IN*/, ULONG nDstH /*IN*/, ULONG nQuality /*IN*/, BOOL bIsAsync /*IN*/, ULONG nMilliseconds /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |*/ QCAP_MOVE_OSD_VIRTUAL_CAMERA_OBJECT( PVOID pCamera /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, ULONG nSequenceStyle /*IN*/, double dLifeTime /*IN*/ ); // FOR SCROLLING TEXT/PICTURE

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |*/ QCAP_GET_OSD_VIRTUAL_CAMERA_TEXT_BOUNDARY( PVOID pCamera /*IN*/, UINT iOsdNum /*IN*/, CHAR * pszString /*IN*/, CHAR * pszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, ULONG * pBoundaryWidth /*OUT*/, ULONG * pBoundaryHeight /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |*/ QCAP_GET_OSD_VIRTUAL_CAMERA_TEXT_BOUNDARY_W( PVOID pCamera /*IN*/, UINT iOsdNum /*IN*/, WSTRING pwszString /*IN*/, WSTRING pwszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, ULONG * pBoundaryWidth /*OUT*/, ULONG * pBoundaryHeight /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |*/ QCAP_SET_OSD_VIRTUAL_CAMERA_TEXT( PVOID pCamera /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, CHAR * pszString /*IN*/, CHAR * pszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, DWORD dwFontColor /*IN*/, DWORD dwBackgroundColor /*IN*/, ULONG nTransparent /*IN*/, INT nTextStartPosX /*IN*/, INT nTextStartPosY /*IN*/, ULONG nSequenceStyle /*IN*/, double dLifeTime /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |*/ QCAP_SET_OSD_VIRTUAL_CAMERA_TEXT_W( PVOID pCamera /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, WSTRING pwszString /*IN*/, WSTRING pwszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, DWORD dwFontColor /*IN*/, DWORD dwBackgroundColor /*IN*/, ULONG nTransparent /*IN*/, INT nTextStartPosX /*IN*/, INT nTextStartPosY /*IN*/, ULONG nSequenceStyle /*IN*/, double dLifeTime /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |*/ QCAP_SET_OSD_VIRTUAL_CAMERA_TEXT_EX( PVOID pCamera /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, CHAR * pszString /*IN*/, CHAR * pszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, DWORD dwFontColor /*IN*/, DWORD dwBackgroundColor /*IN*/, DWORD dwBorderColor /*IN*/, ULONG nBorderWidth /*IN*/, ULONG nTransparent /*IN*/, INT nTextStartPosX /*IN*/, INT nTextStartPosY /*IN*/, ULONG nStringAlignmentStyle /*IN*/, ULONG nSequenceStyle /*IN*/, double dLifeTime /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |*/ QCAP_SET_OSD_VIRTUAL_CAMERA_TEXT_EX_W( PVOID pCamera /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, WSTRING pwszString /*IN*/, WSTRING pwszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, DWORD dwFontColor /*IN*/, DWORD dwBackgroundColor /*IN*/, DWORD dwBorderColor /*IN*/, ULONG nBorderWidth /*IN*/, ULONG nTransparent /*IN*/, INT nTextStartPosX /*IN*/, INT nTextStartPosY /*IN*/, ULONG nStringAlignmentStyle /*IN*/, ULONG nSequenceStyle /*IN*/, double dLifeTime /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |*/ QCAP_SET_OSD_VIRTUAL_CAMERA_PICTURE( PVOID pCamera /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, CHAR * pszFilePathName /*IN*/, ULONG nTransparent /*IN*/, ULONG nSequenceStyle /*IN*/, double dLifeTime /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |*/ QCAP_SET_OSD_VIRTUAL_CAMERA_BUFFER( PVOID pCamera /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, ULONG nColorSpaceType /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameWidth /*IN*/, ULONG nFrameHeight /*IN*/, ULONG nFramePitch /*IN*/, ULONG nTransparent /*IN*/, DWORD dwKeyColor /*IN*/, ULONG nKeyColorThreshold /*IN*/, ULONG nKeyColorBlurLevel /*IN*/, BOOL bKeyColorSpillSuppress /*IN*/, ULONG nKeyColorSpillSuppressThreshold /*IN*/, BYTE * pMaskBuffer /*IN*/, ULONG nSequenceStyle /*IN*/, double dLifeTime /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |*/ QCAP_SET_OSD_VIRTUAL_CAMERA_BUFFER_EX( PVOID pCamera /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, ULONG nColorSpaceType /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameWidth /*IN*/, ULONG nFrameHeight /*IN*/, ULONG nFramePitch /*IN*/, ULONG nCropX /*IN*/, ULONG nCropY /*IN*/, ULONG nCropW /*IN*/, ULONG nCropH /*IN*/, DWORD dwBorderColor /*IN*/, ULONG nBorderWidth /*IN*/, ULONG nTransparent /*IN*/, DWORD dwKeyColor /*IN*/, ULONG nKeyColorThreshold /*IN*/, ULONG nKeyColorBlurLevel /*IN*/, BOOL bKeyColorSpillSuppress /*IN*/, ULONG nKeyColorSpillSuppressThreshold /*IN*/, BYTE * pMaskBuffer /*IN*/, ULONG nSequenceStyle /*IN*/, double dLifeTime /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |*/ QCAP_REGISTER_VIRTUAL_CAMERA_SNAPSHOT_DONE_CALLBACK( PVOID pCamera /*IN*/, PF_VIRTUAL_CAMERA_SNAPSHOT_DONE_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT /*|  |*/ QCAP_REGISTER_VIRTUAL_CAMERA_SNAPSHOT_STREAM_CALLBACK( PVOID pCamera /*IN*/, PF_VIRTUAL_CAMERA_SNAPSHOT_STREAM_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

#ifdef __cplusplus
}
#endif

#endif // QCAP_VIRTUALCAMERA_H
