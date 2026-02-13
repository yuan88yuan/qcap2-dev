#include "mock_qcap_ccvt.h"
#include <cstdio> // For fprintf, stderr

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_CCVT(ULONG nSrcW , ULONG nSrcH , ULONG nSrcColorSpaceType, ULONG nCropX , ULONG nCropY , ULONG nCropW , ULONG nCropH, ULONG nDstW , ULONG nDstH , ULONG nDstColorSpaceType, PVOID* ppCCVT)
{
    (void)nSrcW;
    (void)nSrcH;
    (void)nSrcColorSpaceType;
    (void)nCropX;
    (void)nCropY;
    (void)nCropW;
    (void)nCropH;
    (void)nDstW;
    (void)nDstH;
    (void)nDstColorSpaceType;
    (void)ppCCVT;
    fprintf(stderr, "Mock function called: QCAP_CREATE_CCVT(%s)\n", "nSrcW, nSrcH, nSrcColorSpaceType, nCropX, nCropY, nCropW, nCropH, nDstW, nDstH, nDstColorSpaceType, ppCCVT");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_CCVT(PVOID pCCVT)
{
    (void)pCCVT;
    fprintf(stderr, "Mock function called: QCAP_DESTROY_CCVT(%s)\n", "pCCVT");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_CCVT(PVOID pCCVT)
{
    (void)pCCVT;
    fprintf(stderr, "Mock function called: QCAP_START_CCVT(%s)\n", "pCCVT");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_CCVT(PVOID pCCVT)
{
    (void)pCCVT;
    fprintf(stderr, "Mock function called: QCAP_STOP_CCVT(%s)\n", "pCCVT");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_VIDEO_CCVT_CALLBACK(PVOID pCCVT , PF_VIDEO_CCVT_CALLBACK pCB , PVOID pUserData )
{
    (void)pCCVT;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_VIDEO_CCVT_CALLBACK(%s)\n", "pCCVT, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_CCVT_UNCOMPRESSION_BUFFER(PVOID pCCVT , BYTE * pFrameBuffer , ULONG nFrameBufferLen )
{
    (void)pCCVT;
    (void)pFrameBuffer;
    (void)nFrameBufferLen;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_CCVT_UNCOMPRESSION_BUFFER(%s)\n", "pCCVT, pFrameBuffer, nFrameBufferLen");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_CCVT_CUSTOM_PROPERTY(PVOID pCCVT , ULONG nProperty, BYTE* pValue, ULONG nBytes)
{
    (void)pCCVT;
    (void)nProperty;
    (void)pValue;
    (void)nBytes;
    fprintf(stderr, "Mock function called: QCAP_SET_CCVT_CUSTOM_PROPERTY(%s)\n", "pCCVT, nProperty, pValue, nBytes");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_CCVT_CUSTOM_PROPERTY(PVOID pCCVT , ULONG nProperty, BYTE* pValue, ULONG nBytes)
{
    (void)pCCVT;
    (void)nProperty;
    (void)pValue;
    (void)nBytes;
    fprintf(stderr, "Mock function called: QCAP_GET_CCVT_CUSTOM_PROPERTY(%s)\n", "pCCVT, nProperty, pValue, nBytes");
    return QCAP_RS_SUCCESSFUL;
}

