#include "mock_qcap_helper.h"
#include <cstdio> // For fprintf, stderr

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_H264_BUFFER_LAYER_ID(BYTE * pStreamBuffer , ULONG nStreamBufferLen , ULONG * pLayerID )
{
    (void)pStreamBuffer;
    (void)nStreamBufferLen;
    (void)pLayerID;
    fprintf(stderr, "Mock function called: QCAP_GET_H264_BUFFER_LAYER_ID(%s)\n", "pStreamBuffer, nStreamBufferLen, pLayerID");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_H264_BUFFER_COLOR_INFO(BYTE * pStreamBuffer , ULONG nStreamBufferLen , ULONG * pColorRangeType )
{
    (void)pStreamBuffer;
    (void)nStreamBufferLen;
    (void)pColorRangeType;
    fprintf(stderr, "Mock function called: QCAP_GET_H264_BUFFER_COLOR_INFO(%s)\n", "pStreamBuffer, nStreamBufferLen, pColorRangeType");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_ABGR32_TO_YUY2(BYTE * pSrcFrameBuffer , ULONG nSrcWidth , ULONG nSrcHeight , ULONG nSrcPitch , BYTE * pDstFrameBuffer , ULONG nDstWidth , ULONG nDstHeight , ULONG nDstPitch , BOOL bHorizontalMirror , BOOL bVerticalMirror )
{
    (void)pSrcFrameBuffer;
    (void)nSrcWidth;
    (void)nSrcHeight;
    (void)nSrcPitch;
    (void)pDstFrameBuffer;
    (void)nDstWidth;
    (void)nDstHeight;
    (void)nDstPitch;
    (void)bHorizontalMirror;
    (void)bVerticalMirror;
    fprintf(stderr, "Mock function called: QCAP_COLORSPACE_ABGR32_TO_YUY2(%s)\n", "pSrcFrameBuffer, nSrcWidth, nSrcHeight, nSrcPitch, pDstFrameBuffer, nDstWidth, nDstHeight, nDstPitch, bHorizontalMirror, bVerticalMirror");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_ABGR32_TO_YV12(BYTE * pSrcFrameBuffer , ULONG nSrcWidth , ULONG nSrcHeight , ULONG nSrcPitch , BYTE * pDstFrameBuffer , ULONG nDstWidth , ULONG nDstHeight , ULONG nDstPitch , BOOL bHorizontalMirror , BOOL bVerticalMirror )
{
    (void)pSrcFrameBuffer;
    (void)nSrcWidth;
    (void)nSrcHeight;
    (void)nSrcPitch;
    (void)pDstFrameBuffer;
    (void)nDstWidth;
    (void)nDstHeight;
    (void)nDstPitch;
    (void)bHorizontalMirror;
    (void)bVerticalMirror;
    fprintf(stderr, "Mock function called: QCAP_COLORSPACE_ABGR32_TO_YV12(%s)\n", "pSrcFrameBuffer, nSrcWidth, nSrcHeight, nSrcPitch, pDstFrameBuffer, nDstWidth, nDstHeight, nDstPitch, bHorizontalMirror, bVerticalMirror");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_BGR24_TO_YUY2(BYTE * pSrcFrameBuffer , ULONG nSrcWidth , ULONG nSrcHeight , ULONG nSrcPitch , BYTE * pDstFrameBuffer , ULONG nDstWidth , ULONG nDstHeight , ULONG nDstPitch , BOOL bHorizontalMirror , BOOL bVerticalMirror )
{
    (void)pSrcFrameBuffer;
    (void)nSrcWidth;
    (void)nSrcHeight;
    (void)nSrcPitch;
    (void)pDstFrameBuffer;
    (void)nDstWidth;
    (void)nDstHeight;
    (void)nDstPitch;
    (void)bHorizontalMirror;
    (void)bVerticalMirror;
    fprintf(stderr, "Mock function called: QCAP_COLORSPACE_BGR24_TO_YUY2(%s)\n", "pSrcFrameBuffer, nSrcWidth, nSrcHeight, nSrcPitch, pDstFrameBuffer, nDstWidth, nDstHeight, nDstPitch, bHorizontalMirror, bVerticalMirror");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_BGR24_TO_YV12(BYTE * pSrcFrameBuffer , ULONG nSrcWidth , ULONG nSrcHeight , ULONG nSrcPitch , BYTE * pDstFrameBuffer , ULONG nDstWidth , ULONG nDstHeight , ULONG nDstPitch , BOOL bHorizontalMirror , BOOL bVerticalMirror )
{
    (void)pSrcFrameBuffer;
    (void)nSrcWidth;
    (void)nSrcHeight;
    (void)nSrcPitch;
    (void)pDstFrameBuffer;
    (void)nDstWidth;
    (void)nDstHeight;
    (void)nDstPitch;
    (void)bHorizontalMirror;
    (void)bVerticalMirror;
    fprintf(stderr, "Mock function called: QCAP_COLORSPACE_BGR24_TO_YV12(%s)\n", "pSrcFrameBuffer, nSrcWidth, nSrcHeight, nSrcPitch, pDstFrameBuffer, nDstWidth, nDstHeight, nDstPitch, bHorizontalMirror, bVerticalMirror");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_BGR24_TO_RGB24(BYTE * pSrcFrameBuffer , ULONG nSrcWidth , ULONG nSrcHeight , ULONG nSrcPitch , BYTE * pDstFrameBuffer , ULONG nDstWidth , ULONG nDstHeight , ULONG nDstPitch , BOOL bHorizontalMirror , BOOL bVerticalMirror )
{
    (void)pSrcFrameBuffer;
    (void)nSrcWidth;
    (void)nSrcHeight;
    (void)nSrcPitch;
    (void)pDstFrameBuffer;
    (void)nDstWidth;
    (void)nDstHeight;
    (void)nDstPitch;
    (void)bHorizontalMirror;
    (void)bVerticalMirror;
    fprintf(stderr, "Mock function called: QCAP_COLORSPACE_BGR24_TO_RGB24(%s)\n", "pSrcFrameBuffer, nSrcWidth, nSrcHeight, nSrcPitch, pDstFrameBuffer, nDstWidth, nDstHeight, nDstPitch, bHorizontalMirror, bVerticalMirror");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_RGB24_TO_BGR24(BYTE * pSrcFrameBuffer , ULONG nSrcWidth , ULONG nSrcHeight , ULONG nSrcPitch , BYTE * pDstFrameBuffer , ULONG nDstWidth , ULONG nDstHeight , ULONG nDstPitch , BOOL bHorizontalMirror , BOOL bVerticalMirror )
{
    (void)pSrcFrameBuffer;
    (void)nSrcWidth;
    (void)nSrcHeight;
    (void)nSrcPitch;
    (void)pDstFrameBuffer;
    (void)nDstWidth;
    (void)nDstHeight;
    (void)nDstPitch;
    (void)bHorizontalMirror;
    (void)bVerticalMirror;
    fprintf(stderr, "Mock function called: QCAP_COLORSPACE_RGB24_TO_BGR24(%s)\n", "pSrcFrameBuffer, nSrcWidth, nSrcHeight, nSrcPitch, pDstFrameBuffer, nDstWidth, nDstHeight, nDstPitch, bHorizontalMirror, bVerticalMirror");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_YUY2_TO_ABGR32(BYTE * pSrcFrameBuffer , ULONG nSrcWidth , ULONG nSrcHeight , ULONG nSrcPitch , BYTE bAlpah , BOOL bHorizontalMirror , BOOL bVerticalMirror )
{
    (void)pSrcFrameBuffer;
    (void)nSrcWidth;
    (void)nSrcHeight;
    (void)nSrcPitch;
    (void)bAlpah;
    (void)bHorizontalMirror;
    (void)bVerticalMirror;
    fprintf(stderr, "Mock function called: QCAP_COLORSPACE_YUY2_TO_ABGR32(%s)\n", "pSrcFrameBuffer, nSrcWidth, nSrcHeight, nSrcPitch, bAlpah, bHorizontalMirror, bVerticalMirror");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_YV12_TO_ABGR32(BYTE * pSrcFrameBuffer , ULONG nSrcWidth , ULONG nSrcHeight , ULONG nSrcPitch , BYTE bAlpah , BOOL bHorizontalMirror , BOOL bVerticalMirror )
{
    (void)pSrcFrameBuffer;
    (void)nSrcWidth;
    (void)nSrcHeight;
    (void)nSrcPitch;
    (void)bAlpah;
    (void)bHorizontalMirror;
    (void)bVerticalMirror;
    fprintf(stderr, "Mock function called: QCAP_COLORSPACE_YV12_TO_ABGR32(%s)\n", "pSrcFrameBuffer, nSrcWidth, nSrcHeight, nSrcPitch, bAlpah, bHorizontalMirror, bVerticalMirror");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_YUY2_TO_ARGB32(BYTE * pSrcFrameBuffer , ULONG nSrcWidth , ULONG nSrcHeight , ULONG nSrcPitch , BYTE bAlpah , BOOL bHorizontalMirror , BOOL bVerticalMirror )
{
    (void)pSrcFrameBuffer;
    (void)nSrcWidth;
    (void)nSrcHeight;
    (void)nSrcPitch;
    (void)bAlpah;
    (void)bHorizontalMirror;
    (void)bVerticalMirror;
    fprintf(stderr, "Mock function called: QCAP_COLORSPACE_YUY2_TO_ARGB32(%s)\n", "pSrcFrameBuffer, nSrcWidth, nSrcHeight, nSrcPitch, bAlpah, bHorizontalMirror, bVerticalMirror");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_YV12_TO_ARGB32(BYTE * pSrcFrameBuffer , ULONG nSrcWidth , ULONG nSrcHeight , ULONG nSrcPitch , BYTE bAlpah , BOOL bHorizontalMirror , BOOL bVerticalMirror )
{
    (void)pSrcFrameBuffer;
    (void)nSrcWidth;
    (void)nSrcHeight;
    (void)nSrcPitch;
    (void)bAlpah;
    (void)bHorizontalMirror;
    (void)bVerticalMirror;
    fprintf(stderr, "Mock function called: QCAP_COLORSPACE_YV12_TO_ARGB32(%s)\n", "pSrcFrameBuffer, nSrcWidth, nSrcHeight, nSrcPitch, bAlpah, bHorizontalMirror, bVerticalMirror");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_YUY2_TO_BGR24(BYTE * pSrcFrameBuffer , ULONG nSrcWidth , ULONG nSrcHeight , ULONG nSrcPitch , BYTE * pDstFrameBuffer , ULONG nDstWidth , ULONG nDstHeight , ULONG nDstPitch , BOOL bHorizontalMirror , BOOL bVerticalMirror )
{
    (void)pSrcFrameBuffer;
    (void)nSrcWidth;
    (void)nSrcHeight;
    (void)nSrcPitch;
    (void)pDstFrameBuffer;
    (void)nDstWidth;
    (void)nDstHeight;
    (void)nDstPitch;
    (void)bHorizontalMirror;
    (void)bVerticalMirror;
    fprintf(stderr, "Mock function called: QCAP_COLORSPACE_YUY2_TO_BGR24(%s)\n", "pSrcFrameBuffer, nSrcWidth, nSrcHeight, nSrcPitch, pDstFrameBuffer, nDstWidth, nDstHeight, nDstPitch, bHorizontalMirror, bVerticalMirror");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_YV12_TO_BGR24(BYTE * pSrcFrameBuffer , ULONG nSrcWidth , ULONG nSrcHeight , ULONG nSrcPitch , BYTE * pDstFrameBuffer , ULONG nDstWidth , ULONG nDstHeight , ULONG nDstPitch , BOOL bHorizontalMirror , BOOL bVerticalMirror )
{
    (void)pSrcFrameBuffer;
    (void)nSrcWidth;
    (void)nSrcHeight;
    (void)nSrcPitch;
    (void)pDstFrameBuffer;
    (void)nDstWidth;
    (void)nDstHeight;
    (void)nDstPitch;
    (void)bHorizontalMirror;
    (void)bVerticalMirror;
    fprintf(stderr, "Mock function called: QCAP_COLORSPACE_YV12_TO_BGR24(%s)\n", "pSrcFrameBuffer, nSrcWidth, nSrcHeight, nSrcPitch, pDstFrameBuffer, nDstWidth, nDstHeight, nDstPitch, bHorizontalMirror, bVerticalMirror");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_YUY2_TO_RGB24(BYTE * pSrcFrameBuffer , ULONG nSrcWidth , ULONG nSrcHeight , ULONG nSrcPitch , BYTE * pDstFrameBuffer , ULONG nDstWidth , ULONG nDstHeight , ULONG nDstPitch , BOOL bHorizontalMirror , BOOL bVerticalMirror )
{
    (void)pSrcFrameBuffer;
    (void)nSrcWidth;
    (void)nSrcHeight;
    (void)nSrcPitch;
    (void)pDstFrameBuffer;
    (void)nDstWidth;
    (void)nDstHeight;
    (void)nDstPitch;
    (void)bHorizontalMirror;
    (void)bVerticalMirror;
    fprintf(stderr, "Mock function called: QCAP_COLORSPACE_YUY2_TO_RGB24(%s)\n", "pSrcFrameBuffer, nSrcWidth, nSrcHeight, nSrcPitch, pDstFrameBuffer, nDstWidth, nDstHeight, nDstPitch, bHorizontalMirror, bVerticalMirror");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_YV12_TO_RGB24(BYTE * pSrcFrameBuffer , ULONG nSrcWidth , ULONG nSrcHeight , ULONG nSrcPitch , BYTE * pDstFrameBuffer , ULONG nDstWidth , ULONG nDstHeight , ULONG nDstPitch , BOOL bHorizontalMirror , BOOL bVerticalMirror )
{
    (void)pSrcFrameBuffer;
    (void)nSrcWidth;
    (void)nSrcHeight;
    (void)nSrcPitch;
    (void)pDstFrameBuffer;
    (void)nDstWidth;
    (void)nDstHeight;
    (void)nDstPitch;
    (void)bHorizontalMirror;
    (void)bVerticalMirror;
    fprintf(stderr, "Mock function called: QCAP_COLORSPACE_YV12_TO_RGB24(%s)\n", "pSrcFrameBuffer, nSrcWidth, nSrcHeight, nSrcPitch, pDstFrameBuffer, nDstWidth, nDstHeight, nDstPitch, bHorizontalMirror, bVerticalMirror");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_YUY2_TO_YV12(BYTE * pSrcFrameBuffer , ULONG nSrcWidth , ULONG nSrcHeight , ULONG nSrcPitch , BYTE * pDstFrameBuffer , ULONG nDstWidth , ULONG nDstHeight , ULONG nDstPitch , BOOL bHorizontalMirror , BOOL bVerticalMirror )
{
    (void)pSrcFrameBuffer;
    (void)nSrcWidth;
    (void)nSrcHeight;
    (void)nSrcPitch;
    (void)pDstFrameBuffer;
    (void)nDstWidth;
    (void)nDstHeight;
    (void)nDstPitch;
    (void)bHorizontalMirror;
    (void)bVerticalMirror;
    fprintf(stderr, "Mock function called: QCAP_COLORSPACE_YUY2_TO_YV12(%s)\n", "pSrcFrameBuffer, nSrcWidth, nSrcHeight, nSrcPitch, pDstFrameBuffer, nDstWidth, nDstHeight, nDstPitch, bHorizontalMirror, bVerticalMirror");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_YV12_TO_YUY2(BYTE * pSrcFrameBuffer , ULONG nSrcWidth , ULONG nSrcHeight , ULONG nSrcPitch , BYTE * pDstFrameBuffer , ULONG nDstWidth , ULONG nDstHeight , ULONG nDstPitch , BOOL bHorizontalMirror , BOOL bVerticalMirror )
{
    (void)pSrcFrameBuffer;
    (void)nSrcWidth;
    (void)nSrcHeight;
    (void)nSrcPitch;
    (void)pDstFrameBuffer;
    (void)nDstWidth;
    (void)nDstHeight;
    (void)nDstPitch;
    (void)bHorizontalMirror;
    (void)bVerticalMirror;
    fprintf(stderr, "Mock function called: QCAP_COLORSPACE_YV12_TO_YUY2(%s)\n", "pSrcFrameBuffer, nSrcWidth, nSrcHeight, nSrcPitch, pDstFrameBuffer, nDstWidth, nDstHeight, nDstPitch, bHorizontalMirror, bVerticalMirror");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_YV12_TO_UYVY(BYTE * pSrcFrameBuffer , ULONG nSrcWidth , ULONG nSrcHeight , ULONG nSrcPitch , BYTE * pDstFrameBuffer , ULONG nDstWidth , ULONG nDstHeight , ULONG nDstPitch , BOOL bHorizontalMirror , BOOL bVerticalMirror )
{
    (void)pSrcFrameBuffer;
    (void)nSrcWidth;
    (void)nSrcHeight;
    (void)nSrcPitch;
    (void)pDstFrameBuffer;
    (void)nDstWidth;
    (void)nDstHeight;
    (void)nDstPitch;
    (void)bHorizontalMirror;
    (void)bVerticalMirror;
    fprintf(stderr, "Mock function called: QCAP_COLORSPACE_YV12_TO_UYVY(%s)\n", "pSrcFrameBuffer, nSrcWidth, nSrcHeight, nSrcPitch, pDstFrameBuffer, nDstWidth, nDstHeight, nDstPitch, bHorizontalMirror, bVerticalMirror");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_P010_TO_YV12(BYTE * pSrcFrameBuffer , ULONG nSrcWidth , ULONG nSrcHeight , ULONG nSrcPitch , BYTE * pDstFrameBuffer , ULONG nDstWidth , ULONG nDstHeight , ULONG nDstPitch , BOOL bHorizontalMirror , BOOL bVerticalMirror )
{
    (void)pSrcFrameBuffer;
    (void)nSrcWidth;
    (void)nSrcHeight;
    (void)nSrcPitch;
    (void)pDstFrameBuffer;
    (void)nDstWidth;
    (void)nDstHeight;
    (void)nDstPitch;
    (void)bHorizontalMirror;
    (void)bVerticalMirror;
    fprintf(stderr, "Mock function called: QCAP_COLORSPACE_P010_TO_YV12(%s)\n", "pSrcFrameBuffer, nSrcWidth, nSrcHeight, nSrcPitch, pDstFrameBuffer, nDstWidth, nDstHeight, nDstPitch, bHorizontalMirror, bVerticalMirror");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_YV12_TO_P010(BYTE * pSrcFrameBuffer , ULONG nSrcWidth , ULONG nSrcHeight , ULONG nSrcPitch , BYTE * pDstFrameBuffer , ULONG nDstWidth , ULONG nDstHeight , ULONG nDstPitch , BOOL bHorizontalMirror , BOOL bVerticalMirror )
{
    (void)pSrcFrameBuffer;
    (void)nSrcWidth;
    (void)nSrcHeight;
    (void)nSrcPitch;
    (void)pDstFrameBuffer;
    (void)nDstWidth;
    (void)nDstHeight;
    (void)nDstPitch;
    (void)bHorizontalMirror;
    (void)bVerticalMirror;
    fprintf(stderr, "Mock function called: QCAP_COLORSPACE_YV12_TO_P010(%s)\n", "pSrcFrameBuffer, nSrcWidth, nSrcHeight, nSrcPitch, pDstFrameBuffer, nDstWidth, nDstHeight, nDstPitch, bHorizontalMirror, bVerticalMirror");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SNAPSHOT_BUFFER_TO_BMP_EX(CHAR * pszFilePathName , ULONG nColorSpaceType , BYTE * pSrcFrameBuffer , ULONG nSrcWidth , ULONG nSrcHeight , ULONG nSrcPitch , UINT nCropX , UINT nCropY , UINT nCropW , UINT nCropH , UINT nDstW , UINT nDstH , BOOL bIsAsync , ULONG nMilliseconds , BYTE * pszDstStreamBuffer , ULONG * pDstStreamBufferLen , PF_SNAPSHOT_DONE_CALLBACK pCB , PVOID pUserData )
{
    (void)pszFilePathName;
    (void)nColorSpaceType;
    (void)pSrcFrameBuffer;
    (void)nSrcWidth;
    (void)nSrcHeight;
    (void)nSrcPitch;
    (void)nCropX;
    (void)nCropY;
    (void)nCropW;
    (void)nCropH;
    (void)nDstW;
    (void)nDstH;
    (void)bIsAsync;
    (void)nMilliseconds;
    (void)pszDstStreamBuffer;
    (void)pDstStreamBufferLen;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_SNAPSHOT_BUFFER_TO_BMP_EX(%s)\n", "pszFilePathName, nColorSpaceType, pSrcFrameBuffer, nSrcWidth, nSrcHeight, nSrcPitch, nCropX, nCropY, nCropW, nCropH, nDstW, nDstH, bIsAsync, nMilliseconds, pszDstStreamBuffer, pDstStreamBufferLen, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SNAPSHOT_BUFFER_TO_JPG_EX(CHAR * pszFilePathName , ULONG nColorSpaceType , BYTE * pSrcFrameBuffer , ULONG nSrcWidth , ULONG nSrcHeight , ULONG nSrcPitch , UINT nCropX , UINT nCropY , UINT nCropW , UINT nCropH , UINT nDstW , UINT nDstH , ULONG nQuality , BOOL bIsAsync , ULONG nMilliseconds , BYTE * pszDstStreamBuffer , ULONG * pDstStreamBufferLen , PF_SNAPSHOT_DONE_CALLBACK pCB , PVOID pUserData )
{
    (void)pszFilePathName;
    (void)nColorSpaceType;
    (void)pSrcFrameBuffer;
    (void)nSrcWidth;
    (void)nSrcHeight;
    (void)nSrcPitch;
    (void)nCropX;
    (void)nCropY;
    (void)nCropW;
    (void)nCropH;
    (void)nDstW;
    (void)nDstH;
    (void)nQuality;
    (void)bIsAsync;
    (void)nMilliseconds;
    (void)pszDstStreamBuffer;
    (void)pDstStreamBufferLen;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_SNAPSHOT_BUFFER_TO_JPG_EX(%s)\n", "pszFilePathName, nColorSpaceType, pSrcFrameBuffer, nSrcWidth, nSrcHeight, nSrcPitch, nCropX, nCropY, nCropW, nCropH, nDstW, nDstH, nQuality, bIsAsync, nMilliseconds, pszDstStreamBuffer, pDstStreamBufferLen, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CONVERT_3D_STEREO_BUFFER(ULONG nColorSpaceType , ULONG nSrcStereoDisplayMode , BYTE * pSrcFrameBuffer , ULONG nSrcWidth , ULONG nSrcHeight , ULONG nSrcPitch , ULONG nDstStereoDisplayMode , BYTE * pDstFrameBuffer , ULONG nDstWidth , ULONG nDstHeight , ULONG nDstPitch , BOOL bLeftRightSwap )
{
    (void)nColorSpaceType;
    (void)nSrcStereoDisplayMode;
    (void)pSrcFrameBuffer;
    (void)nSrcWidth;
    (void)nSrcHeight;
    (void)nSrcPitch;
    (void)nDstStereoDisplayMode;
    (void)pDstFrameBuffer;
    (void)nDstWidth;
    (void)nDstHeight;
    (void)nDstPitch;
    (void)bLeftRightSwap;
    fprintf(stderr, "Mock function called: QCAP_CONVERT_3D_STEREO_BUFFER(%s)\n", "nColorSpaceType, nSrcStereoDisplayMode, pSrcFrameBuffer, nSrcWidth, nSrcHeight, nSrcPitch, nDstStereoDisplayMode, pDstFrameBuffer, nDstWidth, nDstHeight, nDstPitch, bLeftRightSwap");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_RESIZE_VIDEO_BUFFER(ULONG nColorSpaceType , BYTE * pSrcFrameBuffer , ULONG nSrcWidth , ULONG nSrcHeight , ULONG nSrcPitch , BYTE * pDstFrameBuffer , ULONG nDstWidth , ULONG nDstHeight , ULONG nDstPitch )
{
    (void)nColorSpaceType;
    (void)pSrcFrameBuffer;
    (void)nSrcWidth;
    (void)nSrcHeight;
    (void)nSrcPitch;
    (void)pDstFrameBuffer;
    (void)nDstWidth;
    (void)nDstHeight;
    (void)nDstPitch;
    fprintf(stderr, "Mock function called: QCAP_RESIZE_VIDEO_BUFFER(%s)\n", "nColorSpaceType, pSrcFrameBuffer, nSrcWidth, nSrcHeight, nSrcPitch, pDstFrameBuffer, nDstWidth, nDstHeight, nDstPitch");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_ROTATE_VIDEO_BUFFER_BOUNDARY(ULONG nSrcWidth , ULONG nSrcHeight , ULONG * pDstWidth , ULONG * pDstHeight , double dAngle )
{
    (void)nSrcWidth;
    (void)nSrcHeight;
    (void)pDstWidth;
    (void)pDstHeight;
    (void)dAngle;
    fprintf(stderr, "Mock function called: QCAP_GET_ROTATE_VIDEO_BUFFER_BOUNDARY(%s)\n", "nSrcWidth, nSrcHeight, pDstWidth, pDstHeight, dAngle");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_ROTATE_VIDEO_BUFFER(ULONG nColorSpaceType , BYTE * pSrcFrameBuffer , ULONG nSrcWidth , ULONG nSrcHeight , ULONG nSrcPitch , BYTE * pDstFrameBuffer , ULONG nDstWidth , ULONG nDstHeight , ULONG nDstPitch , double dAngle , BYTE * pSrcTempFrameBuffer , BYTE * pDstTempFrameBuffer , BOOL bClearBackground )
{
    (void)nColorSpaceType;
    (void)pSrcFrameBuffer;
    (void)nSrcWidth;
    (void)nSrcHeight;
    (void)nSrcPitch;
    (void)pDstFrameBuffer;
    (void)nDstWidth;
    (void)nDstHeight;
    (void)nDstPitch;
    (void)dAngle;
    (void)pSrcTempFrameBuffer;
    (void)pDstTempFrameBuffer;
    (void)bClearBackground;
    fprintf(stderr, "Mock function called: QCAP_ROTATE_VIDEO_BUFFER(%s)\n", "nColorSpaceType, pSrcFrameBuffer, nSrcWidth, nSrcHeight, nSrcPitch, pDstFrameBuffer, nDstWidth, nDstHeight, nDstPitch, dAngle, pSrcTempFrameBuffer, pDstTempFrameBuffer, bClearBackground");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_WARP_VIDEO_BUFFER(ULONG nColorSpaceType , BYTE * pSrcFrameBuffer , ULONG nSrcWidth , ULONG nSrcHeight , ULONG nSrcPitch , BYTE * pDstFrameBuffer , ULONG nDstWidth , ULONG nDstHeight , ULONG nDstPitch , LONG nWarpDstX1 , LONG nWarpDstY1 , LONG nWarpDstX2 , LONG nWarpDstY2 , LONG nWarpDstX3 , LONG nWarpDstY3 , LONG nWarpDstX4 , LONG nWarpDstY4 , BYTE * pSrcTempFrameBuffer , BYTE * pDstTempFrameBuffer , BOOL bClearBackground )
{
    (void)nColorSpaceType;
    (void)pSrcFrameBuffer;
    (void)nSrcWidth;
    (void)nSrcHeight;
    (void)nSrcPitch;
    (void)pDstFrameBuffer;
    (void)nDstWidth;
    (void)nDstHeight;
    (void)nDstPitch;
    (void)nWarpDstX1;
    (void)nWarpDstY1;
    (void)nWarpDstX2;
    (void)nWarpDstY2;
    (void)nWarpDstX3;
    (void)nWarpDstY3;
    (void)nWarpDstX4;
    (void)nWarpDstY4;
    (void)pSrcTempFrameBuffer;
    (void)pDstTempFrameBuffer;
    (void)bClearBackground;
    fprintf(stderr, "Mock function called: QCAP_WARP_VIDEO_BUFFER(%s)\n", "nColorSpaceType, pSrcFrameBuffer, nSrcWidth, nSrcHeight, nSrcPitch, pDstFrameBuffer, nDstWidth, nDstHeight, nDstPitch, nWarpDstX1, nWarpDstY1, nWarpDstX2, nWarpDstY2, nWarpDstX3, nWarpDstY3, nWarpDstX4, nWarpDstY4, pSrcTempFrameBuffer, pDstTempFrameBuffer, bClearBackground");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_LOAD_PICTURE_BUFFER(CHAR * pszFilePathName , ULONG * pColorSpaceType , BYTE * pFrameBuffer , ULONG * pFrameBufferLen /*IN/OUT*/, ULONG * pFrameWidth , ULONG * pFrameHeight , ULONG * pFramePitch )
{
    (void)pszFilePathName;
    (void)pColorSpaceType;
    (void)pFrameBuffer;
    (void)pFrameWidth;
    (void)pFrameHeight;
    (void)pFramePitch;
    fprintf(stderr, "Mock function called: QCAP_LOAD_PICTURE_BUFFER(%s)\n", "pszFilePathName, pColorSpaceType, pFrameBuffer, pFrameWidth, pFrameHeight, pFramePitch");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CALCULATE_CHROMAKEY(UINT iRecNum , ULONG nColorSpaceType , BYTE * pSrcFrameBuffer , ULONG nSrcWidth , ULONG nSrcHeight , ULONG nSrcPitch , ULONG nSrcCropX , ULONG nSrcCropY , ULONG nSrcCropW , ULONG nSrcCropH , BYTE * pDstAlpahBuffer , BYTE * pDstYBuffer , BYTE * pDstCbBuffer , BYTE * pDstCrBuffer , BYTE * pDstABGRBuffer , ULONG nDstWidth , ULONG nDstHeight , ULONG nDstPitch , ULONG nTransparent , DWORD dwKeyColor  / 0x00FF0000 (BLUE) / 0x0000FF00 (GREEN)*/), ULONG nKeyColorThreshold , ULONG nKeyColorBlurLevel , BOOL bKeyColorSpillSuppress , ULONG nKeyColorSpillSuppressThreshold , ULONG nBackgroundColorSpaceType , BYTE * pBackgroundFrameBuffer , ULONG nBackgroundFrameBufferSize )
{
    (void)iRecNum;
    (void)nColorSpaceType;
    (void)pSrcFrameBuffer;
    (void)nSrcWidth;
    (void)nSrcHeight;
    (void)nSrcPitch;
    (void)nSrcCropX;
    (void)nSrcCropY;
    (void)nSrcCropW;
    (void)nSrcCropH;
    (void)pDstAlpahBuffer;
    (void)pDstYBuffer;
    (void)pDstCbBuffer;
    (void)pDstCrBuffer;
    (void)pDstABGRBuffer;
    (void)nDstWidth;
    (void)nDstHeight;
    (void)nDstPitch;
    (void)nTransparent;
    (void)nBackgroundFrameBufferSize;
    fprintf(stderr, "Mock function called: QCAP_CALCULATE_CHROMAKEY(%s)\n", "iRecNum, nColorSpaceType, pSrcFrameBuffer, nSrcWidth, nSrcHeight, nSrcPitch, nSrcCropX, nSrcCropY, nSrcCropW, nSrcCropH, pDstAlpahBuffer, pDstYBuffer, pDstCbBuffer, pDstCrBuffer, pDstABGRBuffer, nDstWidth, nDstHeight, nDstPitch, nTransparent, nBackgroundFrameBufferSize");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CALCULATE_CHROMAKEY_MT(UINT iRecNum , ULONG nColorSpaceType , BYTE * pSrcFrameBuffer , ULONG nSrcWidth , ULONG nSrcHeight , ULONG nSrcPitch , ULONG nSrcCropX , ULONG nSrcCropY , ULONG nSrcCropW , ULONG nSrcCropH , BYTE * pDstAlpahBuffer , BYTE * pDstYBuffer , BYTE * pDstCbBuffer , BYTE * pDstCrBuffer , BYTE * pDstABGRBuffer , ULONG nDstWidth , ULONG nDstHeight , ULONG nDstPitch , ULONG nTransparent , DWORD dwKeyColor  / 0x00FF0000 (BLUE) / 0x0000FF00 (GREEN)*/), ULONG nKeyColorThreshold , ULONG nKeyColorBlurLevel , BOOL bKeyColorSpillSuppress , ULONG nKeyColorSpillSuppressThreshold , ULONG nBackgroundColorSpaceType , BYTE * pBackgroundFrameBuffer , ULONG nBackgroundFrameBufferSize , ULONG nMultiThreads )
{
    (void)iRecNum;
    (void)nColorSpaceType;
    (void)pSrcFrameBuffer;
    (void)nSrcWidth;
    (void)nSrcHeight;
    (void)nSrcPitch;
    (void)nSrcCropX;
    (void)nSrcCropY;
    (void)nSrcCropW;
    (void)nSrcCropH;
    (void)pDstAlpahBuffer;
    (void)pDstYBuffer;
    (void)pDstCbBuffer;
    (void)pDstCrBuffer;
    (void)pDstABGRBuffer;
    (void)nDstWidth;
    (void)nDstHeight;
    (void)nDstPitch;
    (void)nTransparent;
    (void)nMultiThreads;
    fprintf(stderr, "Mock function called: QCAP_CALCULATE_CHROMAKEY_MT(%s)\n", "iRecNum, nColorSpaceType, pSrcFrameBuffer, nSrcWidth, nSrcHeight, nSrcPitch, nSrcCropX, nSrcCropY, nSrcCropW, nSrcCropH, pDstAlpahBuffer, pDstYBuffer, pDstCbBuffer, pDstCrBuffer, pDstABGRBuffer, nDstWidth, nDstHeight, nDstPitch, nTransparent, nMultiThreads");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_AUDIO_BUFFER_VOLUME_DB(BYTE * pFrameBuffer , ULONG nFrameBufferLen , ULONG nChannels , ULONG nBitsPerSample , ULONG nSampleFrequency , UINT iChNum , double * pVolumeDB  /*RANGE = -100 ~ 0 (DB)*/)
{
    (void)pFrameBuffer;
    (void)nFrameBufferLen;
    (void)nChannels;
    (void)nBitsPerSample;
    (void)nSampleFrequency;
    (void)iChNum;
    fprintf(stderr, "Mock function called: QCAP_GET_AUDIO_BUFFER_VOLUME_DB(%s)\n", "pFrameBuffer, nFrameBufferLen, nChannels, nBitsPerSample, nSampleFrequency, iChNum");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_AUDIO_BUFFER_FAST_FOURIER_TRANSFORM_DATA(BYTE * pFrameBuffer , ULONG nFrameBufferLen , ULONG nChannels , ULONG nBitsPerSample , ULONG nSampleFrequency , UINT iChNum , double * pPeakFrq , double * pPeakFrqAmp )
{
    (void)pFrameBuffer;
    (void)nFrameBufferLen;
    (void)nChannels;
    (void)nBitsPerSample;
    (void)nSampleFrequency;
    (void)iChNum;
    (void)pPeakFrq;
    (void)pPeakFrqAmp;
    fprintf(stderr, "Mock function called: QCAP_GET_AUDIO_BUFFER_FAST_FOURIER_TRANSFORM_DATA(%s)\n", "pFrameBuffer, nFrameBufferLen, nChannels, nBitsPerSample, nSampleFrequency, iChNum, pPeakFrq, pPeakFrqAmp");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_RESAMPLE_AUDIO_BUFFER(BYTE * pSrcFrameBuffer , ULONG nSrcFrameBufferLen , ULONG nSrcChannels , ULONG nSrcBitsPerSample , ULONG nSrcSampleFrequency , BYTE * pDstFrameBuffer , ULONG * pDstFrameBufferLen /*IN/OUT*/, ULONG nDstChannels , ULONG nDstBitsPerSample , ULONG nDstSampleFrequency )
{
    (void)pSrcFrameBuffer;
    (void)nSrcFrameBufferLen;
    (void)nSrcChannels;
    (void)nSrcBitsPerSample;
    (void)nSrcSampleFrequency;
    (void)pDstFrameBuffer;
    (void)nDstChannels;
    (void)nDstBitsPerSample;
    (void)nDstSampleFrequency;
    fprintf(stderr, "Mock function called: QCAP_RESAMPLE_AUDIO_BUFFER(%s)\n", "pSrcFrameBuffer, nSrcFrameBufferLen, nSrcChannels, nSrcBitsPerSample, nSrcSampleFrequency, pDstFrameBuffer, nDstChannels, nDstBitsPerSample, nDstSampleFrequency");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_RESCALE_AUDIO_BUFFER(BYTE * pFrameBuffer , ULONG nFrameBufferLen , ULONG nChannels , ULONG nBitsPerSample , ULONG nSampleFrequency , ULONG nVolume )
{
    (void)pFrameBuffer;
    (void)nFrameBufferLen;
    (void)nChannels;
    (void)nBitsPerSample;
    (void)nSampleFrequency;
    (void)nVolume;
    fprintf(stderr, "Mock function called: QCAP_RESCALE_AUDIO_BUFFER(%s)\n", "pFrameBuffer, nFrameBufferLen, nChannels, nBitsPerSample, nSampleFrequency, nVolume");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SOUNDRENDERER_ENUMERATION(CHAR * * ppszSoundRendererDevName , BOOL bNext )
{
    (void)ppszSoundRendererDevName;
    (void)bNext;
    fprintf(stderr, "Mock function called: QCAP_SOUNDRENDERER_ENUMERATION(%s)\n", "ppszSoundRendererDevName, bNext");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SOUNDRENDERER_ENUMERATION_W(WSTRING * ppwszSoundRendererDevName , BOOL bNext )
{
    (void)ppwszSoundRendererDevName;
    (void)bNext;
    fprintf(stderr, "Mock function called: QCAP_SOUNDRENDERER_ENUMERATION_W(%s)\n", "ppwszSoundRendererDevName, bNext");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SYSTEM_ENABLE_HARDWARE_DEVICE(DWORD dwVendorID , DWORD dwProductID , CHAR * pszDevicePath )
{
    (void)dwVendorID;
    (void)dwProductID;
    (void)pszDevicePath;
    fprintf(stderr, "Mock function called: QCAP_SYSTEM_ENABLE_HARDWARE_DEVICE(%s)\n", "dwVendorID, dwProductID, pszDevicePath");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SYSTEM_DISABLE_HARDWARE_DEVICE(DWORD dwVendorID , DWORD dwProductID , CHAR * pszDevicePath )
{
    (void)dwVendorID;
    (void)dwProductID;
    (void)pszDevicePath;
    fprintf(stderr, "Mock function called: QCAP_SYSTEM_DISABLE_HARDWARE_DEVICE(%s)\n", "dwVendorID, dwProductID, pszDevicePath");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SYSTEM_RECOVER_HARDWARE_DEVICE(DWORD dwVendorID , DWORD dwProductID , CHAR * pszFirmwarePathName , double * pRecoverProgress )
{
    (void)dwVendorID;
    (void)dwProductID;
    (void)pszFirmwarePathName;
    (void)pRecoverProgress;
    fprintf(stderr, "Mock function called: QCAP_SYSTEM_RECOVER_HARDWARE_DEVICE(%s)\n", "dwVendorID, dwProductID, pszFirmwarePathName, pRecoverProgress");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_MATRIX_QUAD_MAPPING(double * pMatrixA  /*(x1, y1) ~ (x4, y4)*/, double * pMatrixB  /*(X1, Y1) ~ (X4, Y4)*/, double * pSrcA  /*(x, y)*/, double * pDstB  /*(X, Y)*/)
{
    fprintf(stderr, "Mock function called: QCAP_MATRIX_QUAD_MAPPING(%s)\n", "");
    return QCAP_RS_SUCCESSFUL;
}

