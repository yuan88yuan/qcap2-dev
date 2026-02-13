#include "mock_qcap_common.h"
#include <cstdio> // For fprintf, stderr

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_INITIALIZE()
{
    fprintf(stderr, "Mock function called: QCAP_INITIALIZE(%s)\n", "");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_UNINITIALIZE()
{
    fprintf(stderr, "Mock function called: QCAP_UNINITIALIZE(%s)\n", "");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_CUSTOM_PROPERTY(ULONG nProperty, BYTE* pValue, ULONG nBytes)
{
    fprintf(stderr, "Mock function called: QCAP_SET_CUSTOM_PROPERTY(%s)\n", "nProperty, pValue, nBytes");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_CUSTOM_PROPERTY(ULONG nProperty, BYTE* pValue, ULONG nBytes)
{
    fprintf(stderr, "Mock function called: QCAP_GET_CUSTOM_PROPERTY(%s)\n", "nProperty, pValue, nBytes");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SYNCHRONIZED_SNAPSHOT_BMP(ULONG nFileArgs, CHAR * pszFilePathName1, PVOID pDevice1, CHAR * pszFilePathName2, PVOID pDevice2, ...)
{
    fprintf(stderr, "Mock function called: QCAP_SYNCHRONIZED_SNAPSHOT_BMP(%s)\n", "nFileArgs, pszFilePathName1, pDevice1, pszFilePathName2, pDevice2");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SYNCHRONIZED_SNAPSHOT_JPG(ULONG nFileArgs, CHAR * pszFilePathName1, ULONG nQuality1, PVOID pDevice1, CHAR * pszFilePathName2, ULONG nQuality2, PVOID pDevice2, ...)
{
    fprintf(stderr, "Mock function called: QCAP_SYNCHRONIZED_SNAPSHOT_JPG(%s)\n", "nFileArgs, pszFilePathName1, nQuality1, pDevice1, pszFilePathName2, nQuality2, pDevice2");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_RGB24_TO_YUY2(BYTE * pSrcFrameBuffer, ULONG nSrcWidth, ULONG nSrcHeight, ULONG nSrcPitch, BYTE * pDstFrameBuffer, ULONG nDstWidth, ULONG nDstHeight, ULONG nDstPitch, BOOL bHorizontalMirror, BOOL bVerticalMirror)
{
    fprintf(stderr, "Mock function called: QCAP_COLORSPACE_RGB24_TO_YUY2(%s)\n", "pSrcFrameBuffer, nSrcWidth, nSrcHeight, nSrcPitch, pDstFrameBuffer, nDstWidth, nDstHeight, nDstPitch, bHorizontalMirror, bVerticalMirror");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_RGB24_TO_YV12(BYTE * pSrcFrameBuffer, ULONG nSrcWidth, ULONG nSrcHeight, ULONG nSrcPitch, BYTE * pDstFrameBuffer, ULONG nDstWidth, ULONG nDstHeight, ULONG nDstPitch, BOOL bHorizontalMirror, BOOL bVerticalMirror)
{
    fprintf(stderr, "Mock function called: QCAP_COLORSPACE_RGB24_TO_YV12(%s)\n", "pSrcFrameBuffer, nSrcWidth, nSrcHeight, nSrcPitch, pDstFrameBuffer, nDstWidth, nDstHeight, nDstPitch, bHorizontalMirror, bVerticalMirror");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_ARGB32_TO_YUY2(BYTE * pSrcFrameBuffer, ULONG nSrcWidth, ULONG nSrcHeight, ULONG nSrcPitch, BYTE * pDstFrameBuffer, ULONG nDstWidth, ULONG nDstHeight, ULONG nDstPitch, BOOL bHorizontalMirror, BOOL bVerticalMirror)
{
    fprintf(stderr, "Mock function called: QCAP_COLORSPACE_ARGB32_TO_YUY2(%s)\n", "pSrcFrameBuffer, nSrcWidth, nSrcHeight, nSrcPitch, pDstFrameBuffer, nDstWidth, nDstHeight, nDstPitch, bHorizontalMirror, bVerticalMirror");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_ARGB32_TO_YV12(BYTE * pSrcFrameBuffer, ULONG nSrcWidth, ULONG nSrcHeight, ULONG nSrcPitch, BYTE * pDstFrameBuffer, ULONG nDstWidth, ULONG nDstHeight, ULONG nDstPitch, BOOL bHorizontalMirror, BOOL bVerticalMirror)
{
    fprintf(stderr, "Mock function called: QCAP_COLORSPACE_ARGB32_TO_YV12(%s)\n", "pSrcFrameBuffer, nSrcWidth, nSrcHeight, nSrcPitch, pDstFrameBuffer, nDstWidth, nDstHeight, nDstPitch, bHorizontalMirror, bVerticalMirror");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_YUY2_TO_UYVY(BYTE * pSrcFrameBuffer, ULONG nSrcWidth, ULONG nSrcHeight, ULONG nSrcPitch, BYTE * pDstFrameBuffer, ULONG nDstWidth, ULONG nDstHeight, ULONG nDstPitch, BOOL bHorizontalMirror, BOOL bVerticalMirror)
{
    fprintf(stderr, "Mock function called: QCAP_COLORSPACE_YUY2_TO_UYVY(%s)\n", "pSrcFrameBuffer, nSrcWidth, nSrcHeight, nSrcPitch, pDstFrameBuffer, nDstWidth, nDstHeight, nDstPitch, bHorizontalMirror, bVerticalMirror");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_YV12_TO_UYVY(BYTE * pSrcFrameBuffer, ULONG nSrcWidth, ULONG nSrcHeight, ULONG nSrcPitch, BYTE * pDstFrameBuffer, ULONG nDstWidth, ULONG nDstHeight, ULONG nDstPitch, BOOL bHorizontalMirror, BOOL bVerticalMirror)
{
    fprintf(stderr, "Mock function called: QCAP_COLORSPACE_YV12_TO_UYVY(%s)\n", "pSrcFrameBuffer, nSrcWidth, nSrcHeight, nSrcPitch, pDstFrameBuffer, nDstWidth, nDstHeight, nDstPitch, bHorizontalMirror, bVerticalMirror");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_NV12_TO_UYVY(BYTE * pSrcFrameBuffer, ULONG nSrcWidth, ULONG nSrcHeight, ULONG nSrcPitch, BYTE * pDstFrameBuffer, ULONG nDstWidth, ULONG nDstHeight, ULONG nDstPitch, BOOL bHorizontalMirror, BOOL bVerticalMirror)
{
    fprintf(stderr, "Mock function called: QCAP_COLORSPACE_NV12_TO_UYVY(%s)\n", "pSrcFrameBuffer, nSrcWidth, nSrcHeight, nSrcPitch, pDstFrameBuffer, nDstWidth, nDstHeight, nDstPitch, bHorizontalMirror, bVerticalMirror");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COLORSPACE_CONVERT(ULONG nSrcColorSpaceType, BYTE * pSrcFrameBuffer, ULONG nSrcWidth, ULONG nSrcHeight, ULONG nSrcPitch, ULONG nDstColorSpaceType, BYTE * pDstFrameBuffer, ULONG nDstWidth, ULONG nDstHeight, ULONG nDstPitch, BOOL bHorizontalMirror, BOOL bVerticalMirror)
{
    fprintf(stderr, "Mock function called: QCAP_COLORSPACE_CONVERT(%s)\n", "nSrcColorSpaceType, pSrcFrameBuffer, nSrcWidth, nSrcHeight, nSrcPitch, nDstColorSpaceType, pDstFrameBuffer, nDstWidth, nDstHeight, nDstPitch, bHorizontalMirror, bVerticalMirror");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CROP_VIDEO_FRAME(BYTE* pSrcFrameBuffer, ULONG nSrcFrameBufferLen, ULONG nCropX, ULONG nCropY, ULONG nCropW, ULONG nCropH, BYTE* pDstFrameBuffer, ULONG nDstFrameBufferLen)
{
    fprintf(stderr, "Mock function called: QCAP_CROP_VIDEO_FRAME(%s)\n", "pSrcFrameBuffer, nSrcFrameBufferLen, nCropX, nCropY, nCropW, nCropH, pDstFrameBuffer, nDstFrameBufferLen");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_BUFFER(BYTE** ppBuffer, ULONG* pBufferLen)
{
    fprintf(stderr, "Mock function called: QCAP_CREATE_BUFFER(%s)\n", "ppBuffer, pBufferLen");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_BUFFER(BYTE* pBuffer, ULONG nBufferLen)
{
    fprintf(stderr, "Mock function called: QCAP_DESTROY_BUFFER(%s)\n", "pBuffer, nBufferLen");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_FRAME_BUFFER(BYTE** ppBuffer, ULONG* pBufferLen)
{
    fprintf(stderr, "Mock function called: QCAP_CREATE_FRAME_BUFFER(%s)\n", "ppBuffer, pBufferLen");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESOTRY_FRAME_BUFFER(BYTE * pBuffer, ULONG nBufferLen)
{
    fprintf(stderr, "Mock function called: QCAP_DESOTRY_FRAME_BUFFER(%s)\n", "pBuffer, nBufferLen");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_BLOCK_LOCK(PVOID* ppBlockLock)
{
    fprintf(stderr, "Mock function called: QCAP_CREATE_BLOCK_LOCK(%s)\n", "ppBlockLock");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_BLOCK_LOCK(PVOID pBlockLock)
{
    fprintf(stderr, "Mock function called: QCAP_DESTROY_BLOCK_LOCK(%s)\n", "pBlockLock");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GRANT_BLOCK_LOCK(PVOID pBlockLock, BOOL bGrant)
{
    fprintf(stderr, "Mock function called: QCAP_GRANT_BLOCK_LOCK(%s)\n", "pBlockLock, bGrant");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_ENTER_BLOCK_LOCK(PVOID pBlockLock)
{
    fprintf(stderr, "Mock function called: QCAP_ENTER_BLOCK_LOCK(%s)\n", "pBlockLock");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_LEAVE_BLOCK_LOCK(PVOID pBlockLock)
{
    fprintf(stderr, "Mock function called: QCAP_LEAVE_BLOCK_LOCK(%s)\n", "pBlockLock");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_VIDEO_FRAME_POOL(ULONG nColorSpaceType, ULONG nFrameWidth, ULONG nFrameHeight, ULONG nFrames, PVOID* ppFramePool)
{
    fprintf(stderr, "Mock function called: QCAP_CREATE_VIDEO_FRAME_POOL(%s)\n", "nColorSpaceType, nFrameWidth, nFrameHeight, nFrames, ppFramePool");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_VIDEO_FRAME_POOL_EX(ULONG nColorSpaceType, ULONG nFrameWidth, ULONG nFrameHeight, ULONG nFrames, BOOL bMapped, PVOID* ppFramePool)
{
    fprintf(stderr, "Mock function called: QCAP_CREATE_VIDEO_FRAME_POOL_EX(%s)\n", "nColorSpaceType, nFrameWidth, nFrameHeight, nFrames, bMapped, ppFramePool");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_AUDIO_FRAME_POOL(ULONG nChannels, ULONG nBitsPerSample, ULONG nSampleFrequency, ULONG nFrameSize, ULONG nFrames, PVOID* ppFramePool)
{
    fprintf(stderr, "Mock function called: QCAP_CREATE_AUDIO_FRAME_POOL(%s)\n", "nChannels, nBitsPerSample, nSampleFrequency, nFrameSize, nFrames, ppFramePool");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_AUDIO_FRAME_POOL_EX(ULONG nChannels, ULONG nSampleFmt, ULONG nSampleFrequency, ULONG nFrameSize, ULONG nFrames, PVOID* ppFramePool)
{
    fprintf(stderr, "Mock function called: QCAP_CREATE_AUDIO_FRAME_POOL_EX(%s)\n", "nChannels, nSampleFmt, nSampleFrequency, nFrameSize, nFrames, ppFramePool");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_FRAME_BUFFER(PVOID pFramePool, BYTE** ppFrameBuffer, ULONG* pFrameBufferSize)
{
    fprintf(stderr, "Mock function called: QCAP_GET_FRAME_BUFFER(%s)\n", "pFramePool, ppFrameBuffer, pFrameBufferSize");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_FRAME_POOL(PVOID pFramePool)
{
    fprintf(stderr, "Mock function called: QCAP_DESTROY_FRAME_POOL(%s)\n", "pFramePool");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_AUDIO_RESAMPLER(ULONG nSrcChannels, ULONG nSrcBitsPerSample, ULONG nSrcSampleFrequency, ULONG nDstChannels, ULONG nDstBitsPerSample, ULONG nDstSampleFrequency, PVOID* ppAudioResampler)
{
    fprintf(stderr, "Mock function called: QCAP_CREATE_AUDIO_RESAMPLER(%s)\n", "nSrcChannels, nSrcBitsPerSample, nSrcSampleFrequency, nDstChannels, nDstBitsPerSample, nDstSampleFrequency, ppAudioResampler");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_AUDIO_RESAMPLER(PVOID pAudioResampler)
{
    fprintf(stderr, "Mock function called: QCAP_DESTROY_AUDIO_RESAMPLER(%s)\n", "pAudioResampler");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_AUDIO_RESAMPLER_SET_AUDIO_BUFFER(PVOID pAudioResampler, BYTE * pSrcFrameBuffer, ULONG nSrcFrameBufferLen, double dSampleTime)
{
    fprintf(stderr, "Mock function called: QCAP_AUDIO_RESAMPLER_SET_AUDIO_BUFFER(%s)\n", "pAudioResampler, pSrcFrameBuffer, nSrcFrameBufferLen, dSampleTime");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_AUDIO_RESAMPLER_GET_RESAMPLED_AUDIO_BUFFER(PVOID pAudioResampler, BYTE * pDstFrameBuffer, ULONG nDstFrameBufferLen, double * pSampleTime)
{
    fprintf(stderr, "Mock function called: QCAP_AUDIO_RESAMPLER_GET_RESAMPLED_AUDIO_BUFFER(%s)\n", "pAudioResampler, pDstFrameBuffer, nDstFrameBufferLen, pSampleTime");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_STREAM_BUFFER_POOL(ULONG nCount, PVOID* ppStreamBufferPool)
{
    fprintf(stderr, "Mock function called: QCAP_CREATE_STREAM_BUFFER_POOL(%s)\n", "nCount, ppStreamBufferPool");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_STREAM_BUFFER(PVOID pStreamBufferPool, BYTE** ppStreamBuffer, ULONG* pStreamBufferLen)
{
    fprintf(stderr, "Mock function called: QCAP_GET_STREAM_BUFFER(%s)\n", "pStreamBufferPool, ppStreamBuffer, pStreamBufferLen");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_STREAM_BUFFER_POOL(PVOID pStreamBufferPool)
{
    fprintf(stderr, "Mock function called: QCAP_DESTROY_STREAM_BUFFER_POOL(%s)\n", "pStreamBufferPool");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COPY_NATIVE_STREAM_BUFFER(BYTE* pDstStreamBuffer, ULONG nDstStreamBufferLen, BYTE* pSrcStreamBuffer, ULONG nSrcStreamBufferLen, BOOL bIsKeyFrame, double dSrcSampleTime)
{
    fprintf(stderr, "Mock function called: QCAP_COPY_NATIVE_STREAM_BUFFER(%s)\n", "pDstStreamBuffer, nDstStreamBufferLen, pSrcStreamBuffer, nSrcStreamBufferLen, bIsKeyFrame, dSrcSampleTime");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_AUDIO_DELAY_QUEUE(PVOID* ppFrameQueue)
{
    fprintf(stderr, "Mock function called: QCAP_CREATE_AUDIO_DELAY_QUEUE(%s)\n", "ppFrameQueue");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_DELAY(PVOID pFrameQueue, ULONG nMaxDelayInMS)
{
    fprintf(stderr, "Mock function called: QCAP_SET_AUDIO_DELAY(%s)\n", "pFrameQueue, nMaxDelayInMS");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_PUSH_AUDIO_FRAME_BUFFER(PVOID pFrameQueue, BYTE* pSrcFrameBuffer, ULONG nSrcFrameBufferSize, BYTE** ppDstFrameBuffer, ULONG* pDstFrameBufferSize)
{
    fprintf(stderr, "Mock function called: QCAP_PUSH_AUDIO_FRAME_BUFFER(%s)\n", "pFrameQueue, pSrcFrameBuffer, nSrcFrameBufferSize, ppDstFrameBuffer, pDstFrameBufferSize");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_AUDIO_DELAY_QUEUE(PVOID pFrameQueue)
{
    fprintf(stderr, "Mock function called: QCAP_DESTROY_AUDIO_DELAY_QUEUE(%s)\n", "pFrameQueue");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STEP_ANIMATION_CLIP2(PVOID pClip, UINT * pFrameNum, BYTE * pFrameBuffer, ULONG nFrameBufferLen)
{
    fprintf(stderr, "Mock function called: QCAP_STEP_ANIMATION_CLIP2(%s)\n", "pClip, pFrameNum, pFrameBuffer, nFrameBufferLen");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_ANIMATION_CLIP_BKCOLOR_PROPERTY(PVOID pClip, float* pR, float* pG, float* pB)
{
    fprintf(stderr, "Mock function called: QCAP_GET_ANIMATION_CLIP_BKCOLOR_PROPERTY(%s)\n", "pClip, pR, pG, pB");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_ANIMATION_CLIP_BKCOLOR_PROPERTY(PVOID pClip, float r, float g, float b)
{
    fprintf(stderr, "Mock function called: QCAP_SET_ANIMATION_CLIP_BKCOLOR_PROPERTY(%s)\n", "pClip, r, g, b");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_ANIMATION_CLIP_SPRITE_SCALE_STYLE(PVOID pClip, UINT iSpriteNum, ULONG* pScaleStyle)
{
    fprintf(stderr, "Mock function called: QCAP_GET_ANIMATION_CLIP_SPRITE_SCALE_STYLE(%s)\n", "pClip, iSpriteNum, pScaleStyle");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_ANIMATION_CLIP_SPRITE_SCALE_STYLE(PVOID pClip, UINT iSpriteNum, ULONG nScaleStyle)
{
    fprintf(stderr, "Mock function called: QCAP_SET_ANIMATION_CLIP_SPRITE_SCALE_STYLE(%s)\n", "pClip, iSpriteNum, nScaleStyle");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_ANIMATION_CLIP_SPRITE_BKCOLOR(PVOID pClip, UINT iSpriteNum, float* pR, float* pG, float* pB)
{
    fprintf(stderr, "Mock function called: QCAP_GET_ANIMATION_CLIP_SPRITE_BKCOLOR(%s)\n", "pClip, iSpriteNum, pR, pG, pB");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_ANIMATION_CLIP_SPRITE_BKCOLOR(PVOID pClip, UINT iSpriteNum, float r, float g, float b)
{
    fprintf(stderr, "Mock function called: QCAP_SET_ANIMATION_CLIP_SPRITE_BKCOLOR(%s)\n", "pClip, iSpriteNum, r, g, b");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_ANIMATION_CLIP_SPRITE_STATIC(PVOID pClip, UINT iSpriteNum, BOOL* pStatic)
{
    fprintf(stderr, "Mock function called: QCAP_GET_ANIMATION_CLIP_SPRITE_STATIC(%s)\n", "pClip, iSpriteNum, pStatic");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_ANIMATION_CLIP_SPRITE_STATIC(PVOID pClip, UINT iSpriteNum, BOOL bStatic)
{
    fprintf(stderr, "Mock function called: QCAP_SET_ANIMATION_CLIP_SPRITE_STATIC(%s)\n", "pClip, iSpriteNum, bStatic");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_BROADCAST_TS_OVER_UDP_SERVER_EX(UINT iSvrNum /*0 ~ 63*/, CHAR * pszURL, PVOID * ppServer, CHAR * pszNetworkAdapterIP , ULONG nServiceID , CHAR * pszServiceName , CHAR * pszServiceProviderName , BOOL bEnableCBRMode , ULONG nTransferBitRate , ULONG nOriginalNetworkID , ULONG nTransportStreamID , ULONG nPMT_PID , ULONG nPCR_PID , ULONG nVideo_PID , ULONG nAudio_PID , ULONG nVideo_CodecID , ULONG nAudio_CodecID , ULONG nPCRInterval , ULONG nTTL )
{
    fprintf(stderr, "Mock function called: QCAP_CREATE_BROADCAST_TS_OVER_UDP_SERVER_EX(%s)\n", "pszURL, ppServer, pszNetworkAdapterIP, nServiceID, pszServiceName, pszServiceProviderName, bEnableCBRMode, nTransferBitRate, nOriginalNetworkID, nTransportStreamID, nPMT_PID, nPCR_PID, nVideo_PID, nAudio_PID, nVideo_CodecID, nAudio_CodecID, nPCRInterval, nTTL");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_BROADCAST_TS_OVER_SRT_SERVER_EX(UINT iSvrNum /*0 ~ 63*/, PVOID * ppServer, ULONG nNetworkPort_SRT , CHAR * pszPassPhrase , ULONG nPBKeyLen ,  CHAR * pszNetworkAdapterIP , ULONG nServiceID  , CHAR * pszServiceName , CHAR * pszServiceProviderName  , ULONG nTransferBitRate  , ULONG nOriginalNetworkID  , ULONG nTransportStreamID , ULONG nPMT_PID , ULONG nPCR_PID , ULONG nVideo_PID , ULONG nAudio_PID , ULONG nVideo_CodecID  /*0 = AUTO*/, ULONG nAudio_CodecID  /*0 = AUTO*/, ULONG nPCRInterval  /*ms*/, ULONG nSRTLatency  /*ms*/, ULONG nSRTBandwidth )
{
    fprintf(stderr, "Mock function called: QCAP_CREATE_BROADCAST_TS_OVER_SRT_SERVER_EX(%s)\n", "ppServer, nNetworkPort_SRT, pszPassPhrase, nPBKeyLen, pszNetworkAdapterIP, nServiceID, pszServiceName, pszServiceProviderName, nTransferBitRate, nOriginalNetworkID, nTransportStreamID, nPMT_PID, nPCR_PID, nVideo_PID, nAudio_PID, nSRTBandwidth");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_BROADCAST_TS_OVER_SRT_WEB_PORTAL_SERVER_EX(UINT iSvrNum /*0 ~ 63*/, CHAR * pszURL, PVOID * ppServer, CHAR * pszPassPhrase ,  ULONG nPBKeyLen , ULONG nServiceID , CHAR * pszServiceName , CHAR * pszServiceProviderName , ULONG nTransferBitRate  /*0 , ULONG nTransportStreamID , ULONG nPMT_PID , ULONG nPCR_PID , ULONG nVideo_PID , ULONG nAudio_PID , ULONG nVideo_CodecID  /*0 = AUTO*/, ULONG nAudio_CodecID  /*0 = AUTO*/, ULONG nPCRInterval  /*ms*/, ULONG nSRTLatency  /*ms*/, ULONG nSRTOverheadBandwidth  /*100%*/)
{
    fprintf(stderr, "Mock function called: QCAP_CREATE_BROADCAST_TS_OVER_SRT_WEB_PORTAL_SERVER_EX(%s)\n", "pszURL, ppServer, pszPassPhrase, nPBKeyLen, nServiceID, pszServiceName, pszServiceProviderName, nTransportStreamID, nPMT_PID, nPCR_PID, nVideo_PID, nAudio_PID");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_BROADCAST_RTP_SERVER(UINT iSvrNum /*0 ~ 63*/, CHAR* pszIPorSDP, PVOID * ppServer, ULONG nNetworkPort -1 ))
{
    fprintf(stderr, "Mock function called: QCAP_CREATE_BROADCAST_RTP_SERVER(%s)\n", "pszIPorSDP, ppServer");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_BROADCAST_QCAP_SERVER(UINT iSvrNum /*0 ~ 63*/, ULONG nNetworkPort, PVOID * ppServer)
{
    fprintf(stderr, "Mock function called: QCAP_CREATE_BROADCAST_QCAP_SERVER(%s)\n", "nNetworkPort, ppServer");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_MEDIA_BROADCAST_SERVER_CALLBACK(PVOID pServer, UINT iSessionNum, PF_MEDIA_BROADCAST_SERVER_CALLBACK pCB, PVOID pUserData)
{
    fprintf(stderr, "Mock function called: QCAP_REGISTER_MEDIA_BROADCAST_SERVER_CALLBACK(%s)\n", "pServer, iSessionNum, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_CLIENT_CONNECTED_BROADCAST_SERVER_CALLBACK(PVOID pServer, UINT iSessionNum, PF_CLIENT_CONNECTED_BROADCAST_SERVER_CALLBACK pCB, PVOID pUserData)
{
    fprintf(stderr, "Mock function called: QCAP_REGISTER_CLIENT_CONNECTED_BROADCAST_SERVER_CALLBACK(%s)\n", "pServer, iSessionNum, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_CLIENT_DISCONNECTED_BROADCAST_SERVER_CALLBACK(PVOID pServer, UINT iSessionNum, PF_CLIENT_DISCONNECTED_BROADCAST_SERVER_CALLBACK pCB, PVOID pUserData)
{
    fprintf(stderr, "Mock function called: QCAP_REGISTER_CLIENT_DISCONNECTED_BROADCAST_SERVER_CALLBACK(%s)\n", "pServer, iSessionNum, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_BROADCAST_SERVER_INFO(PVOID pServer, UINT iSessionNum, ULONG * pConnections)
{
    fprintf(stderr, "Mock function called: QCAP_GET_BROADCAST_SERVER_INFO(%s)\n", "pServer, iSessionNum, pConnections");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_BROADCAST_SERVER_CUSTOM_PROPERTY(PVOID pServer, ULONG nProperty, BYTE* pValue, ULONG nBytes)
{
    fprintf(stderr, "Mock function called: QCAP_SET_BROADCAST_SERVER_CUSTOM_PROPERTY(%s)\n", "pServer, nProperty, pValue, nBytes");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_BROADCAST_SERVER_CUSTOM_PROPERTY(PVOID pServer, ULONG nProperty, BYTE* pValue, ULONG* pBytes)
{
    fprintf(stderr, "Mock function called: QCAP_GET_BROADCAST_SERVER_CUSTOM_PROPERTY(%s)\n", "pServer, nProperty, pValue, pBytes");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_SESSION_BROADCAST_SERVER_CUSTOM_PROPERTY(PVOID pServer, UINT iSessionNum, ULONG nProperty, BYTE* pValue, ULONG nBytes)
{
    fprintf(stderr, "Mock function called: QCAP_SET_SESSION_BROADCAST_SERVER_CUSTOM_PROPERTY(%s)\n", "pServer, iSessionNum, nProperty, pValue, nBytes");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_SESSION_BROADCAST_SERVER_CUSTOM_PROPERTY(PVOID pServer, UINT iSessionNum, ULONG nProperty, BYTE* pValue, ULONG* pBytes)
{
    fprintf(stderr, "Mock function called: QCAP_GET_SESSION_BROADCAST_SERVER_CUSTOM_PROPERTY(%s)\n", "pServer, iSessionNum, nProperty, pValue, pBytes");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_ID3_BROADCAST_SERVER_COMPRESSION_BUFFER(PVOID pServer, UINT iSessionNum, BYTE * pStreamBuffer, ULONG nStreamBufferLen, double dSampleTime )
{
    fprintf(stderr, "Mock function called: QCAP_SET_ID3_BROADCAST_SERVER_COMPRESSION_BUFFER(%s)\n", "pServer, iSessionNum, pStreamBuffer, nStreamBufferLen, dSampleTime");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_BROADCAST_SRT_CLIENT_EX(UINT iCliNum /*0 ~ 63*/, CHAR * pszURL, PVOID * ppClient, ULONG nSRTLatency  , ULONG nSRTOverheadBandwidth , ULONG nDecoderType  , HWND hAttachedWindow , BOOL bThumbDraw , BOOL bMaintainAspectRatio , CHAR * pszPassPhrase ,  ULONG nPBKeyLen )
{
    fprintf(stderr, "Mock function called: QCAP_CREATE_BROADCAST_SRT_CLIENT_EX(%s)\n", "pszURL, ppClient, nSRTLatency, nSRTOverheadBandwidth, nDecoderType, hAttachedWindow, bThumbDraw, bMaintainAspectRatio, pszPassPhrase, nPBKeyLen");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_BROADCAST_CLIENT_CUSTOM_PROPERTY_EX(PVOID pClient, ULONG nProperty, BYTE* pValue, ULONG nBytes)
{
    fprintf(stderr, "Mock function called: QCAP_SET_BROADCAST_CLIENT_CUSTOM_PROPERTY_EX(%s)\n", "pClient, nProperty, pValue, nBytes");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_BROADCAST_CLIENT_CUSTOM_PROPERTY_EX(PVOID pClient, ULONG nProperty, BYTE* pValue, ULONG* pBytes)
{
    fprintf(stderr, "Mock function called: QCAP_GET_BROADCAST_CLIENT_CUSTOM_PROPERTY_EX(%s)\n", "pClient, nProperty, pValue, pBytes");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_BROADCAST_NDI_CLIENT_ENUMERATION1(CHAR * * ppszNDIName /*OUT*/, CHAR * * ppszGroupName /*OUT*/, BOOL bShowLocalSource  /*IN*/, CHAR* pszGroups /*IN*/, CHAR* pszExtraIp /*IN*/, BOOL bNext )
{
    fprintf(stderr, "Mock function called: QCAP_BROADCAST_NDI_CLIENT_ENUMERATION1(%s)\n", "ppszNDIName, ppszGroupName, bShowLocalSource, pszGroups, pszExtraIp, bNext");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_NDI_METADATA_BROADCAST_CLIENT_CALLBACK(PVOID pClient /*IN*/, PF_NDI_METADATA_BROADCAST_CLIENT_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/)
{
    fprintf(stderr, "Mock function called: QCAP_REGISTER_NDI_METADATA_BROADCAST_CLIENT_CALLBACK(%s)\n", "pClient, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_BROADCAST_NDI_CLIENT1(UINT iCliNum /*IN*/ /*0 ~ 63*/, CHAR * pszDiscoveryServiceIp /*IN*/, PVOID * ppClient /*OUT*/, BOOL bEnableNDIProxy , ULONG nDecoderType , HWND hAttachedWindow , BOOL bThumbDraw , BOOL bMaintainAspectRatio )
{
    fprintf(stderr, "Mock function called: QCAP_CREATE_BROADCAST_NDI_CLIENT1(%s)\n", "pszDiscoveryServiceIp, ppClient, bEnableNDIProxy, nDecoderType, hAttachedWindow, bThumbDraw, bMaintainAspectRatio");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_NDI_DISCOVERY_SERVICE_CONNECTED_BROADCAST_CLIENT_CALLBACK(PVOID pClient /*IN*/, PF_NDI_DISCOVERY_SERVICE_CONNECTED_BROADCAST_CLIENT_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/)
{
    fprintf(stderr, "Mock function called: QCAP_REGISTER_NDI_DISCOVERY_SERVICE_CONNECTED_BROADCAST_CLIENT_CALLBACK(%s)\n", "pClient, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_SHARE_RECORD_CUSTOM_PROPERTY(UINT iRecNum, ULONG nProperty, BYTE* pValue, ULONG nBytes)
{
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_SHARE_RECORD_CUSTOM_PROPERTY(%s)\n", "iRecNum, nProperty, pValue, nBytes");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_SHARE_RECORD_CUSTOM_PROPERTY(UINT iRecNum, ULONG nProperty, BYTE* pValue, ULONG* pBytes)
{
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_SHARE_RECORD_CUSTOM_PROPERTY(%s)\n", "iRecNum, nProperty, pValue, pBytes");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_MX_SHARE_RECORD_VOLUME(UINT iRecNum, ULONG nTracks, UINT iMixNum, ULONG  nVolume)
{
    fprintf(stderr, "Mock function called: QCAP_SET_AUDIO_MX_SHARE_RECORD_VOLUME(%s)\n", "iRecNum, nTracks, iMixNum, nVolume");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_AUDIO_MX_SHARE_RECORD_VOLUME(UINT iRecNum, ULONG nTracks, UINT iMixNum, ULONG* pVolume)
{
    fprintf(stderr, "Mock function called: QCAP_GET_AUDIO_MX_SHARE_RECORD_VOLUME(%s)\n", "iRecNum, nTracks, iMixNum, pVolume");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_SHARE_RECORD_CALLBACK(UINT iRecNum /*IN*/, PF_SHARE_RECORD_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/)
{
    fprintf(stderr, "Mock function called: QCAP_REGISTER_SHARE_RECORD_CALLBACK(%s)\n", "iRecNum, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_FILE_CUSTOM_PROPERTY_EX(PVOID pFile, ULONG nProperty, BYTE * pValue, ULONG* pBytes)
{
    fprintf(stderr, "Mock function called: QCAP_GET_FILE_CUSTOM_PROPERTY_EX(%s)\n", "pFile, nProperty, pValue, pBytes");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_FILE_CUSTOM_PROPERTY_EX(PVOID pFile, ULONG nProperty, BYTE * pValue, ULONG nBytes)
{
    fprintf(stderr, "Mock function called: QCAP_SET_FILE_CUSTOM_PROPERTY_EX(%s)\n", "pFile, nProperty, pValue, nBytes");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_VIDEO_FILE_CALLBACK(PVOID pFile, PF_VIDEO_FILE_CALLBACK pCB, PVOID pUserData)
{
    fprintf(stderr, "Mock function called: QCAP_REGISTER_VIDEO_FILE_CALLBACK(%s)\n", "pFile, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_AUDIO_FILE_CALLBACK(PVOID pFile, PF_AUDIO_FILE_CALLBACK pCB, PVOID pUserData)
{
    fprintf(stderr, "Mock function called: QCAP_REGISTER_AUDIO_FILE_CALLBACK(%s)\n", "pFile, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_RINGBUFFER(ULONG nMaxSize, PVOID* ppRingBuffer)
{
    fprintf(stderr, "Mock function called: QCAP_CREATE_RINGBUFFER(%s)\n", "nMaxSize, ppRingBuffer");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_RINGBUFFER(PVOID pRingbuffer)
{
    fprintf(stderr, "Mock function called: QCAP_DESTROY_RINGBUFFER(%s)\n", "pRingbuffer");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_ENQUEUE_RINGBUFFER(PVOID pRingbuffer, BYTE* pFrameBuffer, ULONG nFrameBufferLen)
{
    fprintf(stderr, "Mock function called: QCAP_ENQUEUE_RINGBUFFER(%s)\n", "pRingbuffer, pFrameBuffer, nFrameBufferLen");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_RINGBUFFER_FRAME_BUFFER(PVOID pRingbuffer, INT nOffset, BYTE** ppFrameBuffer, ULONG* pFrameBufferLen)
{
    fprintf(stderr, "Mock function called: QCAP_GET_RINGBUFFER_FRAME_BUFFER(%s)\n", "pRingbuffer, nOffset, ppFrameBuffer, pFrameBufferLen");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_RESET_RINGBUFFER(PVOID pRingbuffer)
{
    fprintf(stderr, "Mock function called: QCAP_RESET_RINGBUFFER(%s)\n", "pRingbuffer");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_COMPOSITOR(PVOID* ppCompositor)
{
    fprintf(stderr, "Mock function called: QCAP_CREATE_COMPOSITOR(%s)\n", "ppCompositor");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_COMPOSITOR(PVOID pCompositor)
{
    fprintf(stderr, "Mock function called: QCAP_DESTROY_COMPOSITOR(%s)\n", "pCompositor");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_BEGIN_COMPOSITE(PVOID pCompositor, BYTE* pFrameBuffer, ULONG nFrameBufferLen)
{
    fprintf(stderr, "Mock function called: QCAP_BEGIN_COMPOSITE(%s)\n", "pCompositor, pFrameBuffer, nFrameBufferLen");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COMPOSITE_VIDEO_FRAME(PVOID pCompositor, BYTE* pSrcFrameBuffer, ULONG nSrcFrameBufferLen,
	ULONG nSrcCropX, ULONG nSrcCropY, ULONG nSrcCropW, ULONG nSrcCropH,
	ULONG nDstCropX, ULONG nDstCropY, ULONG nDstCropW, ULONG nDstCropH)
{
    fprintf(stderr, "Mock function called: QCAP_COMPOSITE_VIDEO_FRAME(%s)\n", "pCompositor, pSrcFrameBuffer, nSrcFrameBufferLen, nSrcCropX, nSrcCropY, nSrcCropW, nSrcCropH, nDstCropX, nDstCropY, nDstCropW, nDstCropH");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_BLENDOVER_VIDEO_FRAME(PVOID pCompositor, BYTE* pSrcFrameBuffer, ULONG nSrcFrameBufferLen,
	ULONG nSrcCropX, ULONG nSrcCropY, ULONG nSrcCropW, ULONG nSrcCropH,
	ULONG nDstCropX, ULONG nDstCropY, ULONG nDstCropW, ULONG nDstCropH)
{
    fprintf(stderr, "Mock function called: QCAP_BLENDOVER_VIDEO_FRAME(%s)\n", "pCompositor, pSrcFrameBuffer, nSrcFrameBufferLen, nSrcCropX, nSrcCropY, nSrcCropW, nSrcCropH, nDstCropX, nDstCropY, nDstCropW, nDstCropH");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_END_COMPOSITE(PVOID pCompositor)
{
    fprintf(stderr, "Mock function called: QCAP_END_COMPOSITE(%s)\n", "pCompositor");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_DANTE_SERVER(PVOID * ppServer /*OUT*/)
{
    fprintf(stderr, "Mock function called: QCAP_CREATE_DANTE_SERVER(%s)\n", "ppServer");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_DANTE_SERVER(PVOID pServer /*IN*/)
{
    fprintf(stderr, "Mock function called: QCAP_START_DANTE_SERVER(%s)\n", "pServer");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_DANTE_SERVER(PVOID pServer /*IN*/)
{
    fprintf(stderr, "Mock function called: QCAP_STOP_DANTE_SERVER(%s)\n", "pServer");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_DANTE_SERVER(PVOID pServer /*IN*/)
{
    fprintf(stderr, "Mock function called: QCAP_DESTROY_DANTE_SERVER(%s)\n", "pServer");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SEND_DANTE_SERVER_MESSAGE(PVOID pServer, ULONG nVideoTxChannel, ULONG nVideoRxChannel, ULONG nMessage)
{
    fprintf(stderr, "Mock function called: QCAP_SEND_DANTE_SERVER_MESSAGE(%s)\n", "pServer, nVideoTxChannel, nVideoRxChannel, nMessage");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_DANTE_SENDER(PVOID pServer /*IN*/, UINT iSvrNum /*IN*/ /*0 ~ 63*/, PVOID * ppSender /*OUT*/, UINT nVideoChannel /*IN*/, UINT nAudioChannel /*IN*/, CHAR * pszNetworkAdapterIP )
{
    fprintf(stderr, "Mock function called: QCAP_CREATE_DANTE_SENDER(%s)\n", "pServer, ppSender, nVideoChannel, nAudioChannel, pszNetworkAdapterIP");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_DANTE_RECEIVER(PVOID pServer /*IN*/, UINT nVideoChannel /*IN*/, UINT nAudioChannel /*IN*/, UINT iCliNum /*IN*/ /*0 ~ 63*/, PVOID * ppClient /*OUT*/, ULONG nDecoderType , HWND hAttachedWindow , BOOL bThumbDraw , BOOL bMaintainAspectRatio )
{
    fprintf(stderr, "Mock function called: QCAP_CREATE_DANTE_RECEIVER(%s)\n", "pServer, nVideoChannel, nAudioChannel, ppClient, nDecoderType, hAttachedWindow, bThumbDraw, bMaintainAspectRatio");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_DANTE_SERVER_CUSTOM_PROPERTY(PVOID pServer /*IN*/, ULONG nTotalVideoSenderChannels, ULONG nTotalVideoReceiverChannels)
{
    fprintf(stderr, "Mock function called: QCAP_SET_DANTE_SERVER_CUSTOM_PROPERTY(%s)\n", "pServer, nTotalVideoSenderChannels, nTotalVideoReceiverChannels");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_DANTE_SERVER_CUSTOM_PROPERTY(PVOID pServer /*IN*/, ULONG* nTotalVideoSenderChannels /*OUT*/, ULONG* nTotalVideoReceiverChannels /*OUT*/, ULONG* nTotalAudioSenderChannels /*OUT*/, ULONG* nTotalAudioReceiverChannels /*OUT*/)
{
    fprintf(stderr, "Mock function called: QCAP_GET_DANTE_SERVER_CUSTOM_PROPERTY(%s)\n", "pServer, nTotalVideoSenderChannels, nTotalVideoReceiverChannels, nTotalAudioSenderChannels, nTotalAudioReceiverChannels");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_DANTE_SERVER_MESSAGE_CALLBACK(PVOID pServer /*IN*/, PF_DANTE_SERVER_MESSAGE_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/)
{
    fprintf(stderr, "Mock function called: QCAP_REGISTER_DANTE_SERVER_MESSAGE_CALLBACK(%s)\n", "pServer, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_DANTE_SERVER_TX_AUDIO_REQUEST_CALLBACK(PVOID pServer /*IN*/, PF_DANTE_SERVER_TX_AUDIO_REQUEST_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/)
{
    fprintf(stderr, "Mock function called: QCAP_REGISTER_DANTE_SERVER_TX_AUDIO_REQUEST_CALLBACK(%s)\n", "pServer, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_DANTE_SERVER_NO_RESPOND_CALLBACK(PVOID pServer /*IN*/, PF_DANTE_SERVER_NO_RESPOND_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/)
{
    fprintf(stderr, "Mock function called: QCAP_REGISTER_DANTE_SERVER_NO_RESPOND_CALLBACK(%s)\n", "pServer, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_DANTE_SERVER_MESSAGE_CALLBACK1(PVOID pServer /*IN*/, PF_DANTE_SERVER_MESSAGE_CALLBACK1 pCB /*IN*/, PVOID pUserData /*IN*/)
{
    fprintf(stderr, "Mock function called: QCAP_REGISTER_DANTE_SERVER_MESSAGE_CALLBACK1(%s)\n", "pServer, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_BROADCAST_NDI_SERVER2(UINT iSvrNum, ULONG nTotalSessions, PVOID * ppServer, CHAR * pszNDIName, CHAR * pszGroupName, BOOL bEnablePTZ, CHAR * pszConnectionMetadata)
{
    fprintf(stderr, "Mock function called: QCAP_CREATE_BROADCAST_NDI_SERVER2(%s)\n", "iSvrNum, nTotalSessions, ppServer, pszNDIName, pszGroupName, bEnablePTZ, pszConnectionMetadata");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_PATGEN(PVOID* ppPatGen)
{
    fprintf(stderr, "Mock function called: QCAP_CREATE_PATGEN(%s)\n", "ppPatGen");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_PATGEN(PVOID pPatGen)
{
    fprintf(stderr, "Mock function called: QCAP_DESTROY_PATGEN(%s)\n", "pPatGen");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_RUN_PATGEN(PVOID pPatGen)
{
    fprintf(stderr, "Mock function called: QCAP_RUN_PATGEN(%s)\n", "pPatGen");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_PATGEN(PVOID pPatGen)
{
    fprintf(stderr, "Mock function called: QCAP_STOP_PATGEN(%s)\n", "pPatGen");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_PATGEN_VIDEO_OUTPUT_FORMAT(PVOID pPatGen, ULONG nColorSpaceType, ULONG nWidth, ULONG nHeight, BOOL bIsInterleaved, double dFrameRate)
{
    fprintf(stderr, "Mock function called: QCAP_SET_PATGEN_VIDEO_OUTPUT_FORMAT(%s)\n", "pPatGen, nColorSpaceType, nWidth, nHeight, bIsInterleaved, dFrameRate");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_PATGEN_AUDIO_OUTPUT_FORMAT(PVOID pPatGen, ULONG nChannels, ULONG nBitsPerSample, ULONG nSampleFrequency)
{
    fprintf(stderr, "Mock function called: QCAP_SET_PATGEN_AUDIO_OUTPUT_FORMAT(%s)\n", "pPatGen, nChannels, nBitsPerSample, nSampleFrequency");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_PATGEN_CUSTOM_PROPERTY(PVOID pPatGen, ULONG nProperty, BYTE* pValue, ULONG nBytes)
{
    fprintf(stderr, "Mock function called: QCAP_SET_PATGEN_CUSTOM_PROPERTY(%s)\n", "pPatGen, nProperty, pValue, nBytes");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_PATGEN_CUSTOM_PROPERTY(PVOID pPatGen, ULONG nProperty, BYTE* pValue, ULONG nBytes)
{
    fprintf(stderr, "Mock function called: QCAP_GET_PATGEN_CUSTOM_PROPERTY(%s)\n", "pPatGen, nProperty, pValue, nBytes");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_PATGEN_FORMAT_CHANGED_CALLBACK(PVOID pPatGen, PF_PATGEN_FORMAT_CHANGED_CALLBACK pCB, PVOID pUserData)
{
    fprintf(stderr, "Mock function called: QCAP_REGISTER_PATGEN_FORMAT_CHANGED_CALLBACK(%s)\n", "pPatGen, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_PATGEN_VIDEO_PREVIEW_CALLBACK(PVOID pPatGen, PF_PATGEN_VIDEO_PREVIEW_CALLBACK pCB, PVOID pUserData)
{
    fprintf(stderr, "Mock function called: QCAP_REGISTER_PATGEN_VIDEO_PREVIEW_CALLBACK(%s)\n", "pPatGen, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_PATGEN_AUDIO_PREVIEW_CALLBACK(PVOID pPatGen, PF_PATGEN_AUDIO_PREVIEW_CALLBACK pCB, PVOID pUserData)
{
    fprintf(stderr, "Mock function called: QCAP_REGISTER_PATGEN_AUDIO_PREVIEW_CALLBACK(%s)\n", "pPatGen, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_UDEVMON(PVOID* ppUdevMonitor)
{
    fprintf(stderr, "Mock function called: QCAP_CREATE_UDEVMON(%s)\n", "ppUdevMonitor");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_UDEVMON(PVOID pUdevMonitor)
{
    fprintf(stderr, "Mock function called: QCAP_DESTROY_UDEVMON(%s)\n", "pUdevMonitor");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_RUN_UDEVMON(PVOID pUdevMonitor)
{
    fprintf(stderr, "Mock function called: QCAP_RUN_UDEVMON(%s)\n", "pUdevMonitor");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_UDEVMON(PVOID pUdevMonitor)
{
    fprintf(stderr, "Mock function called: QCAP_STOP_UDEVMON(%s)\n", "pUdevMonitor");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_UDEVMON_BIND_CALLBACK(PVOID pUdevMonitor, PF_UDEVMON_BIND_CALLBACK pCB, PVOID pUserData)
{
    fprintf(stderr, "Mock function called: QCAP_REGISTER_UDEVMON_BIND_CALLBACK(%s)\n", "pUdevMonitor, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_UDEVMON_UNBIND_CALLBACK(PVOID pUdevMonitor, PF_UDEVMON_UNBIND_CALLBACK pCB, PVOID pUserData)
{
    fprintf(stderr, "Mock function called: QCAP_REGISTER_UDEVMON_UNBIND_CALLBACK(%s)\n", "pUdevMonitor, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_SERVER_AUDIO_DECODER(PVOID pServer, UINT iAudDecNum, ULONG * pDecoderFormat, ULONG * pChannels, ULONG * pBitsPerSample, ULONG * pSampleFrequency, ULONG * pBitRate_Min, ULONG * pBitRate_Max, ULONG * pBitRate_Default)
{
    fprintf(stderr, "Mock function called: QCAP_GET_COMMUNICATION_SERVER_AUDIO_DECODER(%s)\n", "pServer, iAudDecNum, pDecoderFormat, pChannels, pBitsPerSample, pSampleFrequency, pBitRate_Min, pBitRate_Max, pBitRate_Default");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_COMMUNICATION_SERVER_AUDIO_DECODER(PVOID pServer, UINT iAudEncNum, ULONG nEncoderFormat, ULONG nChannels, ULONG nBitsPerSample, ULONG nSampleFrequency, ULONG nBitRate_Min, ULONG nBitRate_Max, ULONG nBitRate_Default)
{
    fprintf(stderr, "Mock function called: QCAP_SET_COMMUNICATION_SERVER_AUDIO_DECODER(%s)\n", "pServer, iAudEncNum, nEncoderFormat, nChannels, nBitsPerSample, nSampleFrequency, nBitRate_Min, nBitRate_Max, nBitRate_Default");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_EMULATOR_SERVER_INFO_EX(PVOID pEmulator, UINT iSvrNum, CHAR * * ppszNetworkIP, ULONG * pNetworkPort, CHAR * * ppszNetworkURL, CHAR * * ppszName, CHAR * * ppszLocation)
{
    fprintf(stderr, "Mock function called: QCAP_GET_COMMUNICATION_EMULATOR_SERVER_INFO_EX(%s)\n", "pEmulator, iSvrNum, ppszNetworkIP, pNetworkPort, ppszNetworkURL, ppszName, ppszLocation");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CAMERA_ENUMERATION2(CHAR * * ppszCameraDevName /*OUT*/, BOOL bNext /*IN*/, ULONG pEncoderFormat /*IN*/, BOOL * bIncluded /*OUT*/)
{
    fprintf(stderr, "Mock function called: QCAP_CAMERA_ENUMERATION2(%s)\n", "ppszCameraDevName, bNext, pEncoderFormat, bIncluded");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_ALLOC_VIDEO_GPUDIRECT_PREVIEW_BUFFER_EX(PVOID pDevice /*IN*/, BYTE * * ppFrameBuffer /*OUT*/, ULONG nFrameBufferLen /*IN*/, ULONG nAllocMode = QCAP_CUDAHOST_ALLOC_MAPPED)
{
    fprintf(stderr, "Mock function called: QCAP_ALLOC_VIDEO_GPUDIRECT_PREVIEW_BUFFER_EX(%s)\n", "pDevice, ppFrameBuffer, nFrameBufferLen, QCAP_CUDAHOST_ALLOC_MAPPED");
    return QCAP_RS_SUCCESSFUL;
}

