#include "mock_qcap_hi3531a.h"
#include <cstdio> // For fprintf, stderr

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_INITIALIZE() __attribute__ ((deprecated))
{
    fprintf(stderr, "Mock function called: QCAP_HI_INITIALIZE(%s)\n", "");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_UNINITIALIZE() __attribute__ ((deprecated))
{
    fprintf(stderr, "Mock function called: QCAP_HI_UNINITIALIZE(%s)\n", "");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_SET_CUSTOM_PROPERTY(ULONG nProperty, BYTE* pValue, ULONG nBytes)
{
    (void)nProperty;
    (void)pValue;
    (void)nBytes;
    fprintf(stderr, "Mock function called: QCAP_HI_SET_CUSTOM_PROPERTY(%s)\n", "nProperty, pValue, nBytes");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_GET_CUSTOM_PROPERTY(ULONG nProperty, BYTE* pValue, ULONG nBytes)
{
    (void)nProperty;
    (void)pValue;
    (void)nBytes;
    fprintf(stderr, "Mock function called: QCAP_HI_GET_CUSTOM_PROPERTY(%s)\n", "nProperty, pValue, nBytes");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_CREATE_WINDOW(int x, int y, int w, int h, HWND hParent, HWND* pWnd)
{
    (void)x;
    (void)y;
    (void)w;
    (void)h;
    (void)hParent;
    (void)pWnd;
    fprintf(stderr, "Mock function called: QCAP_HI_CREATE_WINDOW(%s)\n", "x, y, w, h, hParent, pWnd");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_DESTROY_WINDOW(HWND hWnd)
{
    (void)hWnd;
    fprintf(stderr, "Mock function called: QCAP_HI_DESTROY_WINDOW(%s)\n", "hWnd");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_SHOW_WINDOW(HWND hWnd)
{
    (void)hWnd;
    fprintf(stderr, "Mock function called: QCAP_HI_SHOW_WINDOW(%s)\n", "hWnd");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_HIDE_WINDOW(HWND hWnd)
{
    (void)hWnd;
    fprintf(stderr, "Mock function called: QCAP_HI_HIDE_WINDOW(%s)\n", "hWnd");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_MOVE_WINDOW(HWND hWnd, int x, int y, int w, int h)
{
    (void)hWnd;
    (void)x;
    (void)y;
    (void)w;
    (void)h;
    fprintf(stderr, "Mock function called: QCAP_HI_MOVE_WINDOW(%s)\n", "hWnd, x, y, w, h");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_GET_WINDOW_RECT(HWND hWnd, int* px, int* py, int* pw, int* ph)
{
    (void)hWnd;
    (void)px;
    (void)py;
    (void)pw;
    (void)ph;
    fprintf(stderr, "Mock function called: QCAP_HI_GET_WINDOW_RECT(%s)\n", "hWnd, px, py, pw, ph");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_WINDOW_BRING_TO_FRONT(HWND hWnd)
{
    (void)hWnd;
    fprintf(stderr, "Mock function called: QCAP_HI_WINDOW_BRING_TO_FRONT(%s)\n", "hWnd");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_WINDOW_SEND_TO_BACK(HWND hWnd)
{
    (void)hWnd;
    fprintf(stderr, "Mock function called: QCAP_HI_WINDOW_SEND_TO_BACK(%s)\n", "hWnd");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_WINDOW_BRING_FORWARD(HWND hWnd)
{
    (void)hWnd;
    fprintf(stderr, "Mock function called: QCAP_HI_WINDOW_BRING_FORWARD(%s)\n", "hWnd");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_WINDOW_SEND_BACKWARD(HWND hWnd)
{
    (void)hWnd;
    fprintf(stderr, "Mock function called: QCAP_HI_WINDOW_SEND_BACKWARD(%s)\n", "hWnd");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_SET_WINDOW_ASPECT_RATIO(HWND hWnd, int flags, int bgColor)
{
    (void)hWnd;
    (void)flags;
    (void)bgColor;
    fprintf(stderr, "Mock function called: QCAP_HI_SET_WINDOW_ASPECT_RATIO(%s)\n", "hWnd, flags, bgColor");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_ENABLE_WINDOW_SPLIT_MODE(HWND hWnd, BOOL bEnable)
{
    (void)hWnd;
    (void)bEnable;
    fprintf(stderr, "Mock function called: QCAP_HI_ENABLE_WINDOW_SPLIT_MODE(%s)\n", "hWnd, bEnable");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_SET_VIDEO_WINDOW_UNCOMPRESSION_BUFFER(HWND hWnd, BYTE * pFrameBuffer , ULONG nFrameBufferLen , double dSampleTime)
{
    (void)hWnd;
    (void)pFrameBuffer;
    (void)nFrameBufferLen;
    (void)dSampleTime;
    fprintf(stderr, "Mock function called: QCAP_HI_SET_VIDEO_WINDOW_UNCOMPRESSION_BUFFER(%s)\n", "hWnd, pFrameBuffer, nFrameBufferLen, dSampleTime");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_SET_VIDEO_WINDOW_FRAME(HWND hWnd, qcap_generic_av_frame_t* pAVFrame)
{
    (void)hWnd;
    (void)pAVFrame;
    fprintf(stderr, "Mock function called: QCAP_HI_SET_VIDEO_WINDOW_FRAME(%s)\n", "hWnd, pAVFrame");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_GET_WINDOW_PROPERTY(HWND hWnd, ULONG nProperty, BYTE * pValue , ULONG nBytes )
{
    (void)hWnd;
    (void)nProperty;
    (void)pValue;
    (void)nBytes;
    fprintf(stderr, "Mock function called: QCAP_HI_GET_WINDOW_PROPERTY(%s)\n", "hWnd, nProperty, pValue, nBytes");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_SET_WINDOW_PROPERTY(HWND hWnd, ULONG nProperty, BYTE * pValue , ULONG nBytes )
{
    (void)hWnd;
    (void)nProperty;
    (void)pValue;
    (void)nBytes;
    fprintf(stderr, "Mock function called: QCAP_HI_SET_WINDOW_PROPERTY(%s)\n", "hWnd, nProperty, pValue, nBytes");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_RESET_BROADCAST_SERVER(PVOID pServer, UINT iSessionNum)
{
    (void)pServer;
    (void)iSessionNum;
    fprintf(stderr, "Mock function called: QCAP_HI_RESET_BROADCAST_SERVER(%s)\n", "pServer, iSessionNum");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_RESET_SHARE_RECORD(UINT iRecodNum)
{
    (void)iRecodNum;
    fprintf(stderr, "Mock function called: QCAP_HI_RESET_SHARE_RECORD(%s)\n", "iRecodNum");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_BUFFER_ADD_REF(BYTE * pBuffer, ULONG nBufferLen ) __attribute__ ((deprecated))
{
    (void)pBuffer;
    fprintf(stderr, "Mock function called: QCAP_BUFFER_ADD_REF(%s)\n", "pBuffer");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_BUFFER_RELEASE(BYTE * pBuffer, ULONG nBufferLen ) __attribute__ ((deprecated))
{
    (void)pBuffer;
    fprintf(stderr, "Mock function called: QCAP_BUFFER_RELEASE(%s)\n", "pBuffer");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_ALPHA_BLEND(ULONG nSrcColorSpaceType , ULONG nSrcWidth , ULONG nSrcHeight , BYTE * pSrcFrameBuffer, ULONG nSrcFrameBufferLen, ULONG nDstColorSpaceType , ULONG nDstWidth , ULONG nDstHeight , BYTE * pDstFrameBuffer, ULONG nDstFrameBufferLen, BYTE bAlpha)
{
    (void)nSrcColorSpaceType;
    (void)nSrcWidth;
    (void)nSrcHeight;
    (void)pSrcFrameBuffer;
    (void)nSrcFrameBufferLen;
    (void)nDstColorSpaceType;
    (void)nDstWidth;
    (void)nDstHeight;
    (void)pDstFrameBuffer;
    (void)nDstFrameBufferLen;
    (void)bAlpha;
    fprintf(stderr, "Mock function called: QCAP_HI_ALPHA_BLEND(%s)\n", "nSrcColorSpaceType, nSrcWidth, nSrcHeight, pSrcFrameBuffer, nSrcFrameBufferLen, nDstColorSpaceType, nDstWidth, nDstHeight, pDstFrameBuffer, nDstFrameBufferLen, bAlpha");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_CLONE_VIDEO_FRAME(ULONG nColorSpaceType , BYTE * pFrameBuffer , ULONG nFrameWidth , ULONG nFrameHeight , ULONG nFramePitch , BYTE ** ppDstFrameBuffer, ULONG* pDstFrameBufferLen)
{
    (void)nColorSpaceType;
    (void)pFrameBuffer;
    (void)nFrameWidth;
    (void)nFrameHeight;
    (void)nFramePitch;
    (void)ppDstFrameBuffer;
    (void)pDstFrameBufferLen;
    fprintf(stderr, "Mock function called: QCAP_HI_CLONE_VIDEO_FRAME(%s)\n", "nColorSpaceType, pFrameBuffer, nFrameWidth, nFrameHeight, nFramePitch, ppDstFrameBuffer, pDstFrameBufferLen");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_CREATE_FRAME_POOL(ULONG nColorSpaceType , ULONG nFrameWidth , ULONG nFrameHeight , ULONG nFrames, PVOID* ppFramePool ) __attribute__ ((deprecated))
{
    (void)nColorSpaceType;
    (void)nFrameWidth;
    (void)nFrameHeight;
    (void)nFrames;
    fprintf(stderr, "Mock function called: QCAP_HI_CREATE_FRAME_POOL(%s)\n", "nColorSpaceType, nFrameWidth, nFrameHeight, nFrames");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_GET_FRAME_BUFFER(PVOID pFramePool, BYTE** ppFrameBuffer , ULONG* pFrameBufferSize ) __attribute__ ((deprecated))
{
    (void)pFramePool;
    (void)ppFrameBuffer;
    fprintf(stderr, "Mock function called: QCAP_HI_GET_FRAME_BUFFER(%s)\n", "pFramePool, ppFrameBuffer");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_DESTROY_FRAME_POOL(PVOID pFramePool ) __attribute__ ((deprecated))
{
    fprintf(stderr, "Mock function called: QCAP_HI_DESTROY_FRAME_POOL(%s)\n", "");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_COPY_VIDEO_FRAME(BYTE * pSrcFrameBuffer , ULONG nSrcFrameBufferLen , BYTE * pDstFrameBuffer, ULONG nDstFrameBufferLen)
{
    (void)pSrcFrameBuffer;
    (void)nSrcFrameBufferLen;
    (void)pDstFrameBuffer;
    (void)nDstFrameBufferLen;
    fprintf(stderr, "Mock function called: QCAP_HI_COPY_VIDEO_FRAME(%s)\n", "pSrcFrameBuffer, nSrcFrameBufferLen, pDstFrameBuffer, nDstFrameBufferLen");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_SET_NATIVE_AUDIO_RENDERER_VOLUME(UINT nSoundNum , ULONG nVolume )
{
    (void)nSoundNum;
    (void)nVolume;
    fprintf(stderr, "Mock function called: QCAP_HI_SET_NATIVE_AUDIO_RENDERER_VOLUME(%s)\n", "nSoundNum, nVolume");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_GET_NATIVE_AUDIO_RENDERER_VOLUME(UINT nSoundNum , ULONG* pVolume )
{
    (void)nSoundNum;
    (void)pVolume;
    fprintf(stderr, "Mock function called: QCAP_HI_GET_NATIVE_AUDIO_RENDERER_VOLUME(%s)\n", "nSoundNum, pVolume");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_REGISTER_MOTION_DETECT_CALLBACK(PVOID pVDAHandle , PF_MOTION_DETECT_CALLBACK pCB , PVOID pUserData )
{
    (void)pVDAHandle;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_HI_REGISTER_MOTION_DETECT_CALLBACK(%s)\n", "pVDAHandle, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_CREATE_MOTION_MONITOR(PVOID *pVDAHandle , ULONG nFrameWidth , ULONG nFrameHeight , ULONG VdaAlg , ULONG *nBlockWidth , ULONG *nBlockHeight )
{
    (void)pVDAHandle;
    (void)nFrameWidth;
    (void)nFrameHeight;
    (void)VdaAlg;
    (void)nBlockWidth;
    (void)nBlockHeight;
    fprintf(stderr, "Mock function called: QCAP_HI_CREATE_MOTION_MONITOR(%s)\n", "pVDAHandle, nFrameWidth, nFrameHeight, VdaAlg, nBlockWidth, nBlockHeight");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_DESTROY_MOTION_MONITOR(PVOID pVDAHandle )
{
    (void)pVDAHandle;
    fprintf(stderr, "Mock function called: QCAP_HI_DESTROY_MOTION_MONITOR(%s)\n", "pVDAHandle");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_START_MOTION_MONITOR(PVOID pVDAHandle )
{
    (void)pVDAHandle;
    fprintf(stderr, "Mock function called: QCAP_HI_START_MOTION_MONITOR(%s)\n", "pVDAHandle");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_STOP_MOTION_MONITOR(PVOID pVDAHandle )
{
    (void)pVDAHandle;
    fprintf(stderr, "Mock function called: QCAP_HI_STOP_MOTION_MONITOR(%s)\n", "pVDAHandle");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_SET_MOTION_DETECT_BUFFER(PVOID pVDAHandle , BYTE * pFrameBuffer , ULONG nFrameBufferLen )
{
    (void)pVDAHandle;
    (void)pFrameBuffer;
    (void)nFrameBufferLen;
    fprintf(stderr, "Mock function called: QCAP_HI_SET_MOTION_DETECT_BUFFER(%s)\n", "pVDAHandle, pFrameBuffer, nFrameBufferLen");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_SET_MOTION_PROPERTY(PVOID pVDAHandle , ULONG nVdaIntvl , ULONG nBgUpSrcWgt , ULONG nSadTh )
{
    (void)pVDAHandle;
    (void)nVdaIntvl;
    (void)nBgUpSrcWgt;
    (void)nSadTh;
    fprintf(stderr, "Mock function called: QCAP_HI_SET_MOTION_PROPERTY(%s)\n", "pVDAHandle, nVdaIntvl, nBgUpSrcWgt, nSadTh");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_GET_MOTION_PROPERTY(PVOID pVDAHandle , ULONG *nVdaIntvl , ULONG *nBgUpSrcWgt , ULONG *nSadTh )
{
    (void)pVDAHandle;
    (void)nVdaIntvl;
    (void)nBgUpSrcWgt;
    (void)nSadTh;
    fprintf(stderr, "Mock function called: QCAP_HI_GET_MOTION_PROPERTY(%s)\n", "pVDAHandle, nVdaIntvl, nBgUpSrcWgt, nSadTh");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_REGISTER_HDMI_SINK_CALLBACK(PF_HDMI_SINK_CALLBACK pCB , PVOID pUserData )
{
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_HI_REGISTER_HDMI_SINK_CALLBACK(%s)\n", "pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_GET_HDMI_SINK_CAPS(PBYTE pData, ULONG nBytes)
{
    (void)pData;
    (void)nBytes;
    fprintf(stderr, "Mock function called: QCAP_HI_GET_HDMI_SINK_CAPS(%s)\n", "pData, nBytes");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_HI_GET_HDMI_SINK_EDID(PBYTE pData, ULONG nBytes)
{
    (void)pData;
    (void)nBytes;
    fprintf(stderr, "Mock function called: QCAP_HI_GET_HDMI_SINK_EDID(%s)\n", "pData, nBytes");
    return QCAP_RS_SUCCESSFUL;
}

