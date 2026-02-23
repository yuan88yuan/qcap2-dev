#ifndef QCAP_HELPER_H
#define QCAP_HELPER_H

#include "qcap.types.h"

#ifdef __cplusplus
extern "C"
{
#endif

// ##########################################################################################################################################################################################
// #
// # HELPER FUNCTIONS (ENCODER/VIDEO/AUDIO/DEVELOPER)
// #
// ##########################################################################################################################################################################################
//
// HELPER FUNCTIONS PART.1 (FOR ENCODER) ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_H264_BUFFER_LAYER_ID( BYTE * pStreamBuffer /*IN*/, ULONG nStreamBufferLen /*IN*/, ULONG * pLayerID /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_H264_BUFFER_COLOR_INFO( BYTE * pStreamBuffer /*IN*/, ULONG nStreamBufferLen /*IN*/, ULONG * pColorRangeType /*OUT*/ );

// HELPER FUNCTIONS PART.2 (FOR VIDEO) //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_ABGR32_TO_YUY2( BYTE * pSrcFrameBuffer /*IN*/, ULONG nSrcWidth /*IN*/, ULONG nSrcHeight /*IN*/, ULONG nSrcPitch /*IN*/, BYTE * pDstFrameBuffer /*OUT*/, ULONG nDstWidth /*IN*/, ULONG nDstHeight /*IN*/, ULONG nDstPitch /*IN*/, BOOL bHorizontalMirror DEFVAL( FALSE /*IN*/), BOOL bVerticalMirror DEFVAL( FALSE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_ABGR32_TO_YV12( BYTE * pSrcFrameBuffer /*IN*/, ULONG nSrcWidth /*IN*/, ULONG nSrcHeight /*IN*/, ULONG nSrcPitch /*IN*/, BYTE * pDstFrameBuffer /*OUT*/, ULONG nDstWidth /*IN*/, ULONG nDstHeight /*IN*/, ULONG nDstPitch /*IN*/, BOOL bHorizontalMirror DEFVAL( FALSE /*IN*/), BOOL bVerticalMirror DEFVAL( FALSE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_BGR24_TO_YUY2(  BYTE * pSrcFrameBuffer /*IN*/, ULONG nSrcWidth /*IN*/, ULONG nSrcHeight /*IN*/, ULONG nSrcPitch /*IN*/, BYTE * pDstFrameBuffer /*OUT*/, ULONG nDstWidth /*IN*/, ULONG nDstHeight /*IN*/, ULONG nDstPitch /*IN*/, BOOL bHorizontalMirror DEFVAL( FALSE /*IN*/), BOOL bVerticalMirror DEFVAL( FALSE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_BGR24_TO_YV12(  BYTE * pSrcFrameBuffer /*IN*/, ULONG nSrcWidth /*IN*/, ULONG nSrcHeight /*IN*/, ULONG nSrcPitch /*IN*/, BYTE * pDstFrameBuffer /*OUT*/, ULONG nDstWidth /*IN*/, ULONG nDstHeight /*IN*/, ULONG nDstPitch /*IN*/, BOOL bHorizontalMirror DEFVAL( FALSE /*IN*/), BOOL bVerticalMirror DEFVAL( FALSE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_BGR24_TO_RGB24( BYTE * pSrcFrameBuffer /*IN*/, ULONG nSrcWidth /*IN*/, ULONG nSrcHeight /*IN*/, ULONG nSrcPitch /*IN*/, BYTE * pDstFrameBuffer /*OUT*/, ULONG nDstWidth /*IN*/, ULONG nDstHeight /*IN*/, ULONG nDstPitch /*IN*/, BOOL bHorizontalMirror DEFVAL( FALSE /*IN*/), BOOL bVerticalMirror DEFVAL( FALSE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_RGB24_TO_BGR24( BYTE * pSrcFrameBuffer /*IN*/, ULONG nSrcWidth /*IN*/, ULONG nSrcHeight /*IN*/, ULONG nSrcPitch /*IN*/, BYTE * pDstFrameBuffer /*OUT*/, ULONG nDstWidth /*IN*/, ULONG nDstHeight /*IN*/, ULONG nDstPitch /*IN*/, BOOL bHorizontalMirror DEFVAL( FALSE /*IN*/), BOOL bVerticalMirror DEFVAL( FALSE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_YUY2_TO_ABGR32( BYTE * pSrcFrameBuffer /*IN*/, ULONG nSrcWidth /*IN*/, ULONG nSrcHeight /*IN*/, ULONG nSrcPitch /*IN*/, BYTE bAlpah DEFVAL( 0x00 /*IN*/), BOOL bHorizontalMirror DEFVAL( FALSE /*IN*/), BOOL bVerticalMirror DEFVAL( FALSE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_YV12_TO_ABGR32( BYTE * pSrcFrameBuffer /*IN*/, ULONG nSrcWidth /*IN*/, ULONG nSrcHeight /*IN*/, ULONG nSrcPitch /*IN*/, BYTE bAlpah DEFVAL( 0x00 /*IN*/), BOOL bHorizontalMirror DEFVAL( FALSE /*IN*/), BOOL bVerticalMirror DEFVAL( FALSE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_YUY2_TO_ARGB32( BYTE * pSrcFrameBuffer /*IN*/, ULONG nSrcWidth /*IN*/, ULONG nSrcHeight /*IN*/, ULONG nSrcPitch /*IN*/, BYTE bAlpah DEFVAL( 0x00 /*IN*/), BOOL bHorizontalMirror DEFVAL( FALSE /*IN*/), BOOL bVerticalMirror DEFVAL( FALSE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_YV12_TO_ARGB32( BYTE * pSrcFrameBuffer /*IN*/, ULONG nSrcWidth /*IN*/, ULONG nSrcHeight /*IN*/, ULONG nSrcPitch /*IN*/, BYTE bAlpah DEFVAL( 0x00 /*IN*/), BOOL bHorizontalMirror DEFVAL( FALSE /*IN*/), BOOL bVerticalMirror DEFVAL( FALSE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_YUY2_TO_BGR24(  BYTE * pSrcFrameBuffer /*IN*/, ULONG nSrcWidth /*IN*/, ULONG nSrcHeight /*IN*/, ULONG nSrcPitch /*IN*/, BYTE * pDstFrameBuffer /*OUT*/, ULONG nDstWidth /*IN*/, ULONG nDstHeight /*IN*/, ULONG nDstPitch /*IN*/, BOOL bHorizontalMirror DEFVAL( FALSE /*IN*/), BOOL bVerticalMirror DEFVAL( FALSE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_YV12_TO_BGR24(  BYTE * pSrcFrameBuffer /*IN*/, ULONG nSrcWidth /*IN*/, ULONG nSrcHeight /*IN*/, ULONG nSrcPitch /*IN*/, BYTE * pDstFrameBuffer /*OUT*/, ULONG nDstWidth /*IN*/, ULONG nDstHeight /*IN*/, ULONG nDstPitch /*IN*/, BOOL bHorizontalMirror DEFVAL( FALSE /*IN*/), BOOL bVerticalMirror DEFVAL( FALSE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_YUY2_TO_RGB24(  BYTE * pSrcFrameBuffer /*IN*/, ULONG nSrcWidth /*IN*/, ULONG nSrcHeight /*IN*/, ULONG nSrcPitch /*IN*/, BYTE * pDstFrameBuffer /*OUT*/, ULONG nDstWidth /*IN*/, ULONG nDstHeight /*IN*/, ULONG nDstPitch /*IN*/, BOOL bHorizontalMirror DEFVAL( FALSE /*IN*/), BOOL bVerticalMirror DEFVAL( FALSE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_YV12_TO_RGB24(  BYTE * pSrcFrameBuffer /*IN*/, ULONG nSrcWidth /*IN*/, ULONG nSrcHeight /*IN*/, ULONG nSrcPitch /*IN*/, BYTE * pDstFrameBuffer /*OUT*/, ULONG nDstWidth /*IN*/, ULONG nDstHeight /*IN*/, ULONG nDstPitch /*IN*/, BOOL bHorizontalMirror DEFVAL( FALSE /*IN*/), BOOL bVerticalMirror DEFVAL( FALSE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_YUY2_TO_YV12(   BYTE * pSrcFrameBuffer /*IN*/, ULONG nSrcWidth /*IN*/, ULONG nSrcHeight /*IN*/, ULONG nSrcPitch /*IN*/, BYTE * pDstFrameBuffer /*OUT*/, ULONG nDstWidth /*IN*/, ULONG nDstHeight /*IN*/, ULONG nDstPitch /*IN*/, BOOL bHorizontalMirror DEFVAL( FALSE /*IN*/), BOOL bVerticalMirror DEFVAL( FALSE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_YV12_TO_YUY2(   BYTE * pSrcFrameBuffer /*IN*/, ULONG nSrcWidth /*IN*/, ULONG nSrcHeight /*IN*/, ULONG nSrcPitch /*IN*/, BYTE * pDstFrameBuffer /*OUT*/, ULONG nDstWidth /*IN*/, ULONG nDstHeight /*IN*/, ULONG nDstPitch /*IN*/, BOOL bHorizontalMirror DEFVAL( FALSE /*IN*/), BOOL bVerticalMirror DEFVAL( FALSE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_YV12_TO_UYVY(   BYTE * pSrcFrameBuffer /*IN*/, ULONG nSrcWidth /*IN*/, ULONG nSrcHeight /*IN*/, ULONG nSrcPitch /*IN*/, BYTE * pDstFrameBuffer /*OUT*/, ULONG nDstWidth /*IN*/, ULONG nDstHeight /*IN*/, ULONG nDstPitch /*IN*/, BOOL bHorizontalMirror DEFVAL( FALSE /*IN*/), BOOL bVerticalMirror DEFVAL( FALSE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_P010_TO_YV12(   BYTE * pSrcFrameBuffer /*IN*/, ULONG nSrcWidth /*IN*/, ULONG nSrcHeight /*IN*/, ULONG nSrcPitch /*IN*/, BYTE * pDstFrameBuffer /*OUT*/, ULONG nDstWidth /*IN*/, ULONG nDstHeight /*IN*/, ULONG nDstPitch /*IN*/, BOOL bHorizontalMirror DEFVAL( FALSE /*IN*/), BOOL bVerticalMirror DEFVAL( FALSE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_YV12_TO_P010(   BYTE * pSrcFrameBuffer /*IN*/, ULONG nSrcWidth /*IN*/, ULONG nSrcHeight /*IN*/, ULONG nSrcPitch /*IN*/, BYTE * pDstFrameBuffer /*OUT*/, ULONG nDstWidth /*IN*/, ULONG nDstHeight /*IN*/, ULONG nDstPitch /*IN*/, BOOL bHorizontalMirror DEFVAL( FALSE /*IN*/), BOOL bVerticalMirror DEFVAL( FALSE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SNAPSHOT_BUFFER_TO_BMP_EX( CHAR * pszFilePathName /*IN*/, ULONG nColorSpaceType /*IN*/, BYTE * pSrcFrameBuffer /*IN*/, ULONG nSrcWidth /*IN*/, ULONG nSrcHeight /*IN*/, ULONG nSrcPitch /*IN*/, UINT nCropX /*IN*/, UINT nCropY /*IN*/, UINT nCropW /*IN*/, UINT nCropH /*IN*/, UINT nDstW /*IN*/, UINT nDstH /*IN*/, BOOL bIsAsync DEFVAL( TRUE /*IN*/), ULONG nMilliseconds DEFVAL( 0 /*IN*/), BYTE * pszDstStreamBuffer DEFVAL( NULL /*OUT*/), ULONG * pDstStreamBufferLen DEFVAL( NULL /*IN/OUT*/), PF_SNAPSHOT_DONE_CALLBACK pCB DEFVAL( NULL /*IN*/), PVOID pUserData DEFVAL( NULL /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SNAPSHOT_BUFFER_TO_JPG_EX( CHAR * pszFilePathName /*IN*/, ULONG nColorSpaceType /*IN*/, BYTE * pSrcFrameBuffer /*IN*/, ULONG nSrcWidth /*IN*/, ULONG nSrcHeight /*IN*/, ULONG nSrcPitch /*IN*/, UINT nCropX /*IN*/, UINT nCropY /*IN*/, UINT nCropW /*IN*/, UINT nCropH /*IN*/, UINT nDstW /*IN*/, UINT nDstH /*IN*/, ULONG nQuality /*IN*/, BOOL bIsAsync DEFVAL( TRUE /*IN*/), ULONG nMilliseconds DEFVAL( 0 /*IN*/), BYTE * pszDstStreamBuffer DEFVAL( NULL /*OUT*/), ULONG * pDstStreamBufferLen DEFVAL( NULL /*IN/OUT*/), PF_SNAPSHOT_DONE_CALLBACK pCB DEFVAL( NULL /*IN*/), PVOID pUserData DEFVAL( NULL /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CONVERT_3D_STEREO_BUFFER( ULONG nColorSpaceType /*IN*/, ULONG nSrcStereoDisplayMode /*IN*/, BYTE * pSrcFrameBuffer /*IN*/, ULONG nSrcWidth /*IN*/, ULONG nSrcHeight /*IN*/, ULONG nSrcPitch /*IN*/, ULONG nDstStereoDisplayMode /*IN*/, BYTE * pDstFrameBuffer /*OUT*/, ULONG nDstWidth /*IN*/, ULONG nDstHeight /*IN*/, ULONG nDstPitch /*IN*/, BOOL bLeftRightSwap DEFVAL( FALSE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_RESIZE_VIDEO_BUFFER( ULONG nColorSpaceType /*IN*/, BYTE * pSrcFrameBuffer /*IN*/, ULONG nSrcWidth /*IN*/, ULONG nSrcHeight /*IN*/, ULONG nSrcPitch /*IN*/, BYTE * pDstFrameBuffer /*OUT*/, ULONG nDstWidth /*IN*/, ULONG nDstHeight /*IN*/, ULONG nDstPitch /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_ROTATE_VIDEO_BUFFER_BOUNDARY( ULONG nSrcWidth /*IN*/, ULONG nSrcHeight /*IN*/, ULONG * pDstWidth /*OUT*/, ULONG * pDstHeight /*OUT*/, double dAngle /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_ROTATE_VIDEO_BUFFER( ULONG nColorSpaceType /*IN*/, BYTE * pSrcFrameBuffer /*IN*/, ULONG nSrcWidth /*IN*/, ULONG nSrcHeight /*IN*/, ULONG nSrcPitch /*IN*/, BYTE * pDstFrameBuffer /*OUT*/, ULONG nDstWidth /*IN*/, ULONG nDstHeight /*IN*/, ULONG nDstPitch /*IN*/, double dAngle /*IN*/, BYTE * pSrcTempFrameBuffer DEFVAL( NULL /*IN*/), BYTE * pDstTempFrameBuffer DEFVAL( NULL /*IN*/), BOOL bClearBackground DEFVAL( TRUE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_WARP_VIDEO_BUFFER( ULONG nColorSpaceType /*IN*/, BYTE * pSrcFrameBuffer /*IN*/, ULONG nSrcWidth /*IN*/, ULONG nSrcHeight /*IN*/, ULONG nSrcPitch /*IN*/, BYTE * pDstFrameBuffer /*OUT*/, ULONG nDstWidth /*IN*/, ULONG nDstHeight /*IN*/, ULONG nDstPitch /*IN*/, LONG nWarpDstX1 /*IN*/, LONG nWarpDstY1 /*IN*/, LONG nWarpDstX2 /*IN*/, LONG nWarpDstY2 /*IN*/, LONG nWarpDstX3 /*IN*/, LONG nWarpDstY3 /*IN*/, LONG nWarpDstX4 /*IN*/, LONG nWarpDstY4 /*IN*/, BYTE * pSrcTempFrameBuffer DEFVAL( NULL /*IN*/), BYTE * pDstTempFrameBuffer DEFVAL( NULL /*IN*/), BOOL bClearBackground DEFVAL( TRUE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_LOAD_PICTURE_BUFFER( CHAR * pszFilePathName /*IN*/, ULONG * pColorSpaceType /*OUT*/, BYTE * pFrameBuffer /*OUT*/, ULONG * pFrameBufferLen /*IN/OUT*/, ULONG * pFrameWidth /*OUT*/, ULONG * pFrameHeight /*OUT*/, ULONG * pFramePitch /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CALCULATE_CHROMAKEY( UINT iRecNum /*IN*/, ULONG nColorSpaceType /*IN*/, BYTE * pSrcFrameBuffer /*IN*/, ULONG nSrcWidth /*IN*/, ULONG nSrcHeight /*IN*/, ULONG nSrcPitch /*IN*/, ULONG nSrcCropX /*IN*/, ULONG nSrcCropY /*IN*/, ULONG nSrcCropW /*IN*/, ULONG nSrcCropH /*IN*/, BYTE * pDstAlpahBuffer /*OUT*/, BYTE * pDstYBuffer /*OUT*/, BYTE * pDstCbBuffer /*OUT*/, BYTE * pDstCrBuffer /*OUT*/, BYTE * pDstABGRBuffer /*OUT*/, ULONG nDstWidth /*IN*/, ULONG nDstHeight /*IN*/, ULONG nDstPitch /*IN*/, ULONG nTransparent /*IN*/, DWORD dwKeyColor DEFVAL( 0xFFFFFFFF /*IN*/ /*0xFFFFFFFF (OFF) / 0x00FF0000 (BLUE) / 0x0000FF00 (GREEN)*/), ULONG nKeyColorThreshold DEFVAL( 25 /*IN*/ /*0 ~ 128*/), ULONG nKeyColorBlurLevel DEFVAL( 2 /*IN*/ /*0 ~ 2*/), BOOL bKeyColorSpillSuppress DEFVAL( TRUE /*IN*/), ULONG nKeyColorSpillSuppressThreshold DEFVAL( 22 /*IN*/), ULONG nBackgroundColorSpaceType DEFVAL( QCAP_COLORSPACE_TYPE_ABGR32 /*IN*/), BYTE * pBackgroundFrameBuffer DEFVAL( NULL /*IN/OUT*/), ULONG nBackgroundFrameBufferSize DEFVAL( 0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CALCULATE_CHROMAKEY_MT( UINT iRecNum /*IN*/, ULONG nColorSpaceType /*IN*/, BYTE * pSrcFrameBuffer /*IN*/, ULONG nSrcWidth /*IN*/, ULONG nSrcHeight /*IN*/, ULONG nSrcPitch /*IN*/, ULONG nSrcCropX /*IN*/, ULONG nSrcCropY /*IN*/, ULONG nSrcCropW /*IN*/, ULONG nSrcCropH /*IN*/, BYTE * pDstAlpahBuffer /*OUT*/, BYTE * pDstYBuffer /*OUT*/, BYTE * pDstCbBuffer /*OUT*/, BYTE * pDstCrBuffer /*OUT*/, BYTE * pDstABGRBuffer /*OUT*/, ULONG nDstWidth /*IN*/, ULONG nDstHeight /*IN*/, ULONG nDstPitch /*IN*/, ULONG nTransparent /*IN*/, DWORD dwKeyColor DEFVAL( 0xFFFFFFFF /*IN*/ /*0xFFFFFFFF (OFF) / 0x00FF0000 (BLUE) / 0x0000FF00 (GREEN)*/), ULONG nKeyColorThreshold DEFVAL( 25 /*IN*/ /*0 ~ 128*/), ULONG nKeyColorBlurLevel DEFVAL( 2 /*IN*/ /*0 ~ 2*/), BOOL bKeyColorSpillSuppress DEFVAL( TRUE /*IN*/), ULONG nKeyColorSpillSuppressThreshold DEFVAL( 22 /*IN*/), ULONG nBackgroundColorSpaceType DEFVAL( QCAP_COLORSPACE_TYPE_ABGR32 /*IN*/), BYTE * pBackgroundFrameBuffer DEFVAL( NULL /*IN/OUT*/), ULONG nBackgroundFrameBufferSize DEFVAL( 0 /*IN*/), ULONG nMultiThreads DEFVAL( 0 /*IN*/ ));

// HELPER FUNCTIONS PART.3 (FOR AUDIO) //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_AUDIO_BUFFER_VOLUME_DB( BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, ULONG nChannels /*IN*/, ULONG nBitsPerSample /*IN*/, ULONG nSampleFrequency /*IN*/, UINT iChNum /*IN*/, double * pVolumeDB /*OUT*/ /*RANGE = -100 ~ 0 (DB)*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_AUDIO_BUFFER_FAST_FOURIER_TRANSFORM_DATA( BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, ULONG nChannels /*IN*/, ULONG nBitsPerSample /*IN*/, ULONG nSampleFrequency /*IN*/, UINT iChNum /*IN*/, double * pPeakFrq /*OUT*/, double * pPeakFrqAmp /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_RESAMPLE_AUDIO_BUFFER( BYTE * pSrcFrameBuffer /*IN*/, ULONG nSrcFrameBufferLen /*IN*/, ULONG nSrcChannels /*IN*/, ULONG nSrcBitsPerSample /*IN*/, ULONG nSrcSampleFrequency /*IN*/, BYTE * pDstFrameBuffer /*OUT*/, ULONG * pDstFrameBufferLen /*IN/OUT*/, ULONG nDstChannels /*IN*/, ULONG nDstBitsPerSample /*IN*/, ULONG nDstSampleFrequency /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_RESCALE_AUDIO_BUFFER( BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, ULONG nChannels /*IN*/, ULONG nBitsPerSample /*IN*/, ULONG nSampleFrequency /*IN*/, ULONG nVolume /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SOUNDRENDERER_ENUMERATION( CHAR * * ppszSoundRendererDevName /*OUT*/, BOOL bNext DEFVAL( FALSE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SOUNDRENDERER_ENUMERATION_W( WSTRING * ppwszSoundRendererDevName /*OUT*/, BOOL bNext DEFVAL( FALSE /*IN*/ ));

// HELPER FUNCTIONS PART.4 (FOR SYSTEM) /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SYSTEM_ENABLE_HARDWARE_DEVICE( DWORD dwVendorID /*IN*/, DWORD dwProductID /*IN*/, CHAR * pszDevicePath DEFVAL( NULL /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SYSTEM_DISABLE_HARDWARE_DEVICE( DWORD dwVendorID /*IN*/, DWORD dwProductID /*IN*/, CHAR * pszDevicePath DEFVAL( NULL /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SYSTEM_RECOVER_HARDWARE_DEVICE( DWORD dwVendorID /*IN*/, DWORD dwProductID /*IN*/, CHAR * pszFirmwarePathName /*IN*/, double * pRecoverProgress /*OUT*/ );

// HELPER FUNCTIONS PART.5 (FOR MATRIX) /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_MATRIX_QUAD_MAPPING( double * pMatrixA /*IN*/ /*(x1, y1) ~ (x4, y4)*/, double * pMatrixB /*IN*/ /*(X1, Y1) ~ (X4, Y4)*/, double * pSrcA /*IN*/ /*(x, y)*/, double * pDstB /*OUT*/ /*(X, Y)*/ );

// HELPER FUNCTIONS PART.6 (FOR .NET DEVELOPER) /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
QCAP_EXT_API ULONGLONG QCAP_EXPORT QCAP_HELPER_OBJPTR( PVOID pObj /*IN*/ );

#ifdef __cplusplus
}
#endif

#endif // QCAP_HELPER_H
