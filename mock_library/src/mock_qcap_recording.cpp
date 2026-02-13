#include "mock_qcap_recording.h"
#include <cstdio> // For fprintf, stderr

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_RECORD_PROPERTY(PVOID pDevice , UINT iRecNum , ULONG * pEncoderType , ULONG * pEncoderFormat , ULONG * pRecordMode , ULONG * pQuality , ULONG * pBitRate , ULONG * pGOP , ULONG * pAspectRatioX , ULONG * pAspectRatioY , ULONG * pDownscaleMode )
{
    (void)pDevice;
    (void)iRecNum;
    (void)pEncoderType;
    (void)pEncoderFormat;
    (void)pRecordMode;
    (void)pQuality;
    (void)pBitRate;
    (void)pGOP;
    (void)pAspectRatioX;
    (void)pAspectRatioY;
    (void)pDownscaleMode;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_RECORD_PROPERTY(%s)\n", "pDevice, iRecNum, pEncoderType, pEncoderFormat, pRecordMode, pQuality, pBitRate, pGOP, pAspectRatioX, pAspectRatioY, pDownscaleMode");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_RECORD_PROPERTY(PVOID pDevice , UINT iRecNum , ULONG   nEncoderType ,  ULONG   nEncoderFormat ,  ULONG   nRecordMode ,  ULONG   nQuality ,  ULONG   nBitRate ,  ULONG   nGOP ,  ULONG   nAspectRatioX ,  ULONG   nAspectRatioY ,  ULONG   nDownscaleMode )
{
    (void)pDevice;
    (void)iRecNum;
    (void)nEncoderType;
    (void)nEncoderFormat;
    (void)nRecordMode;
    (void)nQuality;
    (void)nBitRate;
    (void)nGOP;
    (void)nAspectRatioX;
    (void)nAspectRatioY;
    (void)nDownscaleMode;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_RECORD_PROPERTY(%s)\n", "pDevice, iRecNum, nEncoderType, nEncoderFormat, nRecordMode, nQuality, nBitRate, nGOP, nAspectRatioX, nAspectRatioY, nDownscaleMode");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_RECORD_PROPERTY_EX(PVOID pDevice , UINT iRecNum , UINT * pGpuNum , ULONG * pEncoderType , ULONG * pEncoderFormat , ULONG * pRecordProfile  , ULONG * pRecordLevel  , ULONG * pRecordEntropy  , ULONG * pRecordComplexity  , ULONG * pRecordMode , ULONG * pQuality , ULONG * pBitRate , ULONG * pGOP , ULONG * pBFrames  , BOOL * pIsInterleaved  , ULONG * pSlices  , ULONG * pLayers  , ULONG * pSceneCut  , BOOL * pMultiThread  , BOOL * pMBBRC  , BOOL * pExtBRC  , ULONG * pMinQP  , ULONG * pMaxQP  , ULONG * pVBVMaxRate  , ULONG * pVBVBufSize  , ULONG * pCBRVariation  , ULONG * pAspectRatioX , ULONG * pAspectRatioY , ULONG * pCropX , ULONG * pCropY , ULONG * pCropW , ULONG * pCropH , ULONG * pDstW , ULONG * pDstH , ULONG * pPostSkipFrameRate  , ULONG * pPostAvgFrameRate  )
{
    (void)pDevice;
    (void)iRecNum;
    (void)pGpuNum;
    (void)pEncoderType;
    (void)pEncoderFormat;
    (void)pRecordProfile;
    (void)pRecordLevel;
    (void)pRecordEntropy;
    (void)pRecordComplexity;
    (void)pRecordMode;
    (void)pQuality;
    (void)pBitRate;
    (void)pGOP;
    (void)pBFrames;
    (void)pIsInterleaved;
    (void)pSlices;
    (void)pLayers;
    (void)pSceneCut;
    (void)pMultiThread;
    (void)pMBBRC;
    (void)pExtBRC;
    (void)pMinQP;
    (void)pMaxQP;
    (void)pVBVMaxRate;
    (void)pVBVBufSize;
    (void)pCBRVariation;
    (void)pAspectRatioX;
    (void)pAspectRatioY;
    (void)pCropX;
    (void)pCropY;
    (void)pCropW;
    (void)pCropH;
    (void)pDstW;
    (void)pDstH;
    (void)pPostSkipFrameRate;
    (void)pPostAvgFrameRate;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_RECORD_PROPERTY_EX(%s)\n", "pDevice, iRecNum, pGpuNum, pEncoderType, pEncoderFormat, pRecordProfile, pRecordLevel, pRecordEntropy, pRecordComplexity, pRecordMode, pQuality, pBitRate, pGOP, pBFrames, pIsInterleaved, pSlices, pLayers, pSceneCut, pMultiThread, pMBBRC, pExtBRC, pMinQP, pMaxQP, pVBVMaxRate, pVBVBufSize, pCBRVariation, pAspectRatioX, pAspectRatioY, pCropX, pCropY, pCropW, pCropH, pDstW, pDstH, pPostSkipFrameRate, pPostAvgFrameRate");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_RECORD_PROPERTY_EX(PVOID pDevice , UINT iRecNum , UINT   iGpuNum ,  ULONG   nEncoderType ,  ULONG   nEncoderFormat ,  ULONG   nRecordProfile   , ULONG   nRecordLevel   , ULONG   nRecordEntropy   , ULONG   nRecordComplexity   , ULONG   nRecordMode ,  ULONG   nQuality ,  ULONG   nBitRate ,  ULONG   nGOP ,  ULONG   nBFrames   , BOOL   bIsInterleaved   , ULONG   nSlices   , ULONG   nLayers   , ULONG   nSceneCut   , BOOL   bMultiThread   , BOOL   bMBBRC   , BOOL   bExtBRC   , ULONG   nMinQP   , ULONG   nMaxQP   , ULONG   nVBVMaxRate   , ULONG   nVBVBufSize   , ULONG   nCBRVariation   , ULONG   nAspectRatioX ,  ULONG   nAspectRatioY ,  ULONG   nCropX ,  ULONG   nCropY ,  ULONG   nCropW ,  ULONG   nCropH ,  ULONG   nDstW ,  ULONG   nDstH ,  ULONG   nPostSkipFrameRate   , ULONG   nPostAvgFrameRate   )
{
    (void)pDevice;
    (void)iRecNum;
    (void)iGpuNum;
    (void)nEncoderType;
    (void)nEncoderFormat;
    (void)nRecordProfile;
    (void)nRecordLevel;
    (void)nRecordEntropy;
    (void)nRecordComplexity;
    (void)nRecordMode;
    (void)nQuality;
    (void)nBitRate;
    (void)nGOP;
    (void)nBFrames;
    (void)bIsInterleaved;
    (void)nSlices;
    (void)nLayers;
    (void)nSceneCut;
    (void)bMultiThread;
    (void)bMBBRC;
    (void)bExtBRC;
    (void)nMinQP;
    (void)nMaxQP;
    (void)nVBVMaxRate;
    (void)nVBVBufSize;
    (void)nCBRVariation;
    (void)nAspectRatioX;
    (void)nAspectRatioY;
    (void)nCropX;
    (void)nCropY;
    (void)nCropW;
    (void)nCropH;
    (void)nDstW;
    (void)nDstH;
    (void)nPostSkipFrameRate;
    (void)nPostAvgFrameRate;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_RECORD_PROPERTY_EX(%s)\n", "pDevice, iRecNum, iGpuNum, nEncoderType, nEncoderFormat, nRecordProfile, nRecordLevel, nRecordEntropy, nRecordComplexity, nRecordMode, nQuality, nBitRate, nGOP, nBFrames, bIsInterleaved, nSlices, nLayers, nSceneCut, bMultiThread, bMBBRC, bExtBRC, nMinQP, nMaxQP, nVBVMaxRate, nVBVBufSize, nCBRVariation, nAspectRatioX, nAspectRatioY, nCropX, nCropY, nCropW, nCropH, nDstW, nDstH, nPostSkipFrameRate, nPostAvgFrameRate");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_AUDIO_RECORD_PROPERTY(PVOID pDevice , UINT iRecNum , ULONG * pEncoderType , ULONG * pEncoderFormat )
{
    (void)pDevice;
    (void)iRecNum;
    (void)pEncoderType;
    (void)pEncoderFormat;
    fprintf(stderr, "Mock function called: QCAP_GET_AUDIO_RECORD_PROPERTY(%s)\n", "pDevice, iRecNum, pEncoderType, pEncoderFormat");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_RECORD_PROPERTY(PVOID pDevice , UINT iRecNum , ULONG   nEncoderType ,  ULONG   nEncoderFormat )
{
    (void)pDevice;
    (void)iRecNum;
    (void)nEncoderType;
    (void)nEncoderFormat;
    fprintf(stderr, "Mock function called: QCAP_SET_AUDIO_RECORD_PROPERTY(%s)\n", "pDevice, iRecNum, nEncoderType, nEncoderFormat");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_AUDIO_RECORD_PROPERTY_EX(PVOID pDevice , UINT iRecNum , ULONG * pEncoderType , ULONG * pEncoderFormat , ULONG * pBitRate )
{
    (void)pDevice;
    (void)iRecNum;
    (void)pEncoderType;
    (void)pEncoderFormat;
    (void)pBitRate;
    fprintf(stderr, "Mock function called: QCAP_GET_AUDIO_RECORD_PROPERTY_EX(%s)\n", "pDevice, iRecNum, pEncoderType, pEncoderFormat, pBitRate");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_RECORD_PROPERTY_EX(PVOID pDevice , UINT iRecNum , ULONG   nEncoderType ,  ULONG   nEncoderFormat ,  ULONG   nBitRate )
{
    (void)pDevice;
    (void)iRecNum;
    (void)nEncoderType;
    (void)nEncoderFormat;
    (void)nBitRate;
    fprintf(stderr, "Mock function called: QCAP_SET_AUDIO_RECORD_PROPERTY_EX(%s)\n", "pDevice, iRecNum, nEncoderType, nEncoderFormat, nBitRate");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_RECORD_DYNAMIC_PROPERTY_EX(PVOID pDevice , UINT iRecNum , ULONG * pRecordMode , ULONG * pQuality , ULONG * pBitRate , ULONG * pGOP )
{
    (void)pDevice;
    (void)iRecNum;
    (void)pRecordMode;
    (void)pQuality;
    (void)pBitRate;
    (void)pGOP;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_RECORD_DYNAMIC_PROPERTY_EX(%s)\n", "pDevice, iRecNum, pRecordMode, pQuality, pBitRate, pGOP");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_RECORD_DYNAMIC_PROPERTY_EX(PVOID pDevice , UINT iRecNum , ULONG   nRecordMode ,  ULONG   nQuality ,  ULONG   nBitRate ,  ULONG   nGOP )
{
    (void)pDevice;
    (void)iRecNum;
    (void)nRecordMode;
    (void)nQuality;
    (void)nBitRate;
    (void)nGOP;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_RECORD_DYNAMIC_PROPERTY_EX(%s)\n", "pDevice, iRecNum, nRecordMode, nQuality, nBitRate, nGOP");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_METADATA_RECORD_HEADER(PVOID pDevice , UINT iRecNum , CHAR * pszTitle , CHAR * pszArtist , CHAR * pszComments , CHAR * pszGenre , CHAR * pszComposer , CHAR * pszThumbnailPathName )
{
    (void)pDevice;
    (void)iRecNum;
    (void)pszTitle;
    (void)pszArtist;
    (void)pszComments;
    (void)pszGenre;
    (void)pszComposer;
    (void)pszThumbnailPathName;
    fprintf(stderr, "Mock function called: QCAP_SET_METADATA_RECORD_HEADER(%s)\n", "pDevice, iRecNum, pszTitle, pszArtist, pszComments, pszGenre, pszComposer, pszThumbnailPathName");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_METADATA_RECORD_HEADER_W(PVOID pDevice , UINT iRecNum , WSTRING pwszTitle , WSTRING pwszArtist , WSTRING pwszComments , WSTRING pwszGenre , WSTRING pwszComposer , WSTRING pwszThumbnailPathName )
{
    (void)pDevice;
    (void)iRecNum;
    (void)pwszTitle;
    (void)pwszArtist;
    (void)pwszComments;
    (void)pwszGenre;
    (void)pwszComposer;
    (void)pwszThumbnailPathName;
    fprintf(stderr, "Mock function called: QCAP_SET_METADATA_RECORD_HEADER_W(%s)\n", "pDevice, iRecNum, pwszTitle, pwszArtist, pwszComments, pwszGenre, pwszComposer, pwszThumbnailPathName");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_METADATA_RECORD_DATA_BUFFER(PVOID pDevice , UINT iRecNum , BYTE * pDataBuffer , ULONG nDataBufferLen , double dSampleTime , BOOL bIsSubtitle )
{
    (void)pDevice;
    (void)iRecNum;
    (void)pDataBuffer;
    (void)nDataBufferLen;
    (void)dSampleTime;
    (void)bIsSubtitle;
    fprintf(stderr, "Mock function called: QCAP_SET_METADATA_RECORD_DATA_BUFFER(%s)\n", "pDevice, iRecNum, pDataBuffer, nDataBufferLen, dSampleTime, bIsSubtitle");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_CLONE_RECORD(PVOID pDevice , UINT iRecNum , CHAR * pszFilePathNameA , CHAR * pszFilePathNameB , DWORD dwFlags , double dVideoDelayTime , double dAudioDelayTime , double dSegmentDurationTime , ULONG nSegmentDurationSizeKB , CHAR * pszEncryptKey )
{
    (void)pDevice;
    (void)iRecNum;
    (void)pszFilePathNameA;
    (void)pszFilePathNameB;
    (void)dwFlags;
    (void)dVideoDelayTime;
    (void)dAudioDelayTime;
    (void)dSegmentDurationTime;
    (void)nSegmentDurationSizeKB;
    (void)pszEncryptKey;
    fprintf(stderr, "Mock function called: QCAP_START_CLONE_RECORD(%s)\n", "pDevice, iRecNum, pszFilePathNameA, pszFilePathNameB, dwFlags, dVideoDelayTime, dAudioDelayTime, dSegmentDurationTime, nSegmentDurationSizeKB, pszEncryptKey");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_TIMESHIFT_RECORD(PVOID pDevice , UINT iRecNum , CHAR * pszFilePathName , PVOID * ppPhysicalFileWriter , DWORD dwFlags , double dVideoDelayTime , double dAudioDelayTime , CHAR * pszEncryptKey )
{
    (void)pDevice;
    (void)iRecNum;
    (void)pszFilePathName;
    (void)ppPhysicalFileWriter;
    (void)dwFlags;
    (void)dVideoDelayTime;
    (void)dAudioDelayTime;
    (void)pszEncryptKey;
    fprintf(stderr, "Mock function called: QCAP_START_TIMESHIFT_RECORD(%s)\n", "pDevice, iRecNum, pszFilePathName, ppPhysicalFileWriter, dwFlags, dVideoDelayTime, dAudioDelayTime, pszEncryptKey");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_FAILSAFE_RECORD(PVOID pDevice , UINT iRecNum , CHAR * pszFilePathName , UINT iLinkRecNum , PVOID pLinkPhysicalFileWriter , double dPreRecordTime , CHAR * pszEncryptKey )
{
    (void)pDevice;
    (void)iRecNum;
    (void)pszFilePathName;
    (void)iLinkRecNum;
    (void)pLinkPhysicalFileWriter;
    (void)dPreRecordTime;
    (void)pszEncryptKey;
    fprintf(stderr, "Mock function called: QCAP_START_FAILSAFE_RECORD(%s)\n", "pDevice, iRecNum, pszFilePathName, iLinkRecNum, pLinkPhysicalFileWriter, dPreRecordTime, pszEncryptKey");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_RECORD(PVOID pDevice , UINT iRecNum , CHAR * pszFilePathName , DWORD dwFlags , double dVideoDelayTime , double dAudioDelayTime , double dSegmentDurationTime , ULONG nSegmentDurationSizeKB , CHAR * pszEncryptKey )
{
    (void)pDevice;
    (void)iRecNum;
    (void)pszFilePathName;
    (void)dwFlags;
    (void)dVideoDelayTime;
    (void)dAudioDelayTime;
    (void)dSegmentDurationTime;
    (void)nSegmentDurationSizeKB;
    (void)pszEncryptKey;
    fprintf(stderr, "Mock function called: QCAP_START_RECORD(%s)\n", "pDevice, iRecNum, pszFilePathName, dwFlags, dVideoDelayTime, dAudioDelayTime, dSegmentDurationTime, nSegmentDurationSizeKB, pszEncryptKey");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_RECORD(PVOID pDevice , UINT iRecNum , BOOL bIsAsync , ULONG nMilliseconds )
{
    (void)pDevice;
    (void)iRecNum;
    (void)bIsAsync;
    (void)nMilliseconds;
    fprintf(stderr, "Mock function called: QCAP_STOP_RECORD(%s)\n", "pDevice, iRecNum, bIsAsync, nMilliseconds");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_RESUME_RECORD(PVOID pDevice , UINT iRecNum )
{
    (void)pDevice;
    (void)iRecNum;
    fprintf(stderr, "Mock function called: QCAP_RESUME_RECORD(%s)\n", "pDevice, iRecNum");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_PAUSE_RECORD(PVOID pDevice , UINT iRecNum )
{
    (void)pDevice;
    (void)iRecNum;
    fprintf(stderr, "Mock function called: QCAP_PAUSE_RECORD(%s)\n", "pDevice, iRecNum");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SEGMENT_RECORD(PVOID pDevice , UINT iRecNum )
{
    (void)pDevice;
    (void)iRecNum;
    fprintf(stderr, "Mock function called: QCAP_SEGMENT_RECORD(%s)\n", "pDevice, iRecNum");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_RECORD_DONE_CALLBACK(PVOID pDevice , UINT iRecNum , PF_RECORD_DONE_CALLBACK  pCB , PVOID pUserData )
{
    (void)pDevice;
    (void)iRecNum;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_RECORD_DONE_CALLBACK(%s)\n", "pDevice, iRecNum, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_RECORD_FAIL_CALLBACK(PVOID pDevice , UINT iRecNum , PF_RECORD_FAIL_CALLBACK  pCB , PVOID pUserData )
{
    (void)pDevice;
    (void)iRecNum;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_RECORD_FAIL_CALLBACK(%s)\n", "pDevice, iRecNum, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_VIDEO_RECORD_CALLBACK(PVOID pDevice , UINT iRecNum , PF_VIDEO_RECORD_CALLBACK pCB , PVOID pUserData )
{
    (void)pDevice;
    (void)iRecNum;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_VIDEO_RECORD_CALLBACK(%s)\n", "pDevice, iRecNum, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_AUDIO_RECORD_CALLBACK(PVOID pDevice , UINT iRecNum , PF_AUDIO_RECORD_CALLBACK pCB , PVOID pUserData )
{
    (void)pDevice;
    (void)iRecNum;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_AUDIO_RECORD_CALLBACK(%s)\n", "pDevice, iRecNum, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_MEDIA_RECORD_CALLBACK(PVOID pDevice , UINT iRecNum , PF_MEDIA_RECORD_CALLBACK pCB , PVOID pUserData )
{
    (void)pDevice;
    (void)iRecNum;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_MEDIA_RECORD_CALLBACK(%s)\n", "pDevice, iRecNum, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_SHARE_RECORD_STATUS(UINT iRecNum , BOOL * pIsValid )
{
    (void)iRecNum;
    (void)pIsValid;
    fprintf(stderr, "Mock function called: QCAP_GET_SHARE_RECORD_STATUS(%s)\n", "iRecNum, pIsValid");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_SHARE_RECORD_PROPERTY(UINT iRecNum , ULONG * pEncoderType , ULONG * pEncoderFormat , ULONG * pColorSpaceType , ULONG * pWidth , ULONG * pHeight , double * pFrameRate , ULONG * pRecordMode , ULONG * pQuality , ULONG * pBitRate , ULONG * pGOP , ULONG * pAspectRatioX , ULONG * pAspectRatioY , HWND * pAttachedWindow , BOOL * pThumbDraw , BOOL * pMaintainAspectRatio )
{
    (void)iRecNum;
    (void)pEncoderType;
    (void)pEncoderFormat;
    (void)pColorSpaceType;
    (void)pWidth;
    (void)pHeight;
    (void)pFrameRate;
    (void)pRecordMode;
    (void)pQuality;
    (void)pBitRate;
    (void)pGOP;
    (void)pAspectRatioX;
    (void)pAspectRatioY;
    (void)pAttachedWindow;
    (void)pThumbDraw;
    (void)pMaintainAspectRatio;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_SHARE_RECORD_PROPERTY(%s)\n", "iRecNum, pEncoderType, pEncoderFormat, pColorSpaceType, pWidth, pHeight, pFrameRate, pRecordMode, pQuality, pBitRate, pGOP, pAspectRatioX, pAspectRatioY, pAttachedWindow, pThumbDraw, pMaintainAspectRatio");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_SHARE_RECORD_PROPERTY(UINT iRecNum , ULONG   nEncoderType ,  ULONG   nEncoderFormat ,  ULONG   nColorSpaceType ,  ULONG   nWidth ,  ULONG   nHeight ,  double   dFrameRate ,  ULONG   nRecordMode ,  ULONG   nQuality ,  ULONG   nBitRate ,  ULONG   nGOP ,  ULONG   nAspectRatioX ,  ULONG   nAspectRatioY ,  HWND   hAttachedWindow ,  BOOL   bThumbDraw , BOOL   bMaintainAspectRatio )
{
    (void)iRecNum;
    (void)nEncoderType;
    (void)nEncoderFormat;
    (void)nColorSpaceType;
    (void)nWidth;
    (void)nHeight;
    (void)dFrameRate;
    (void)nRecordMode;
    (void)nQuality;
    (void)nBitRate;
    (void)nGOP;
    (void)nAspectRatioX;
    (void)nAspectRatioY;
    (void)hAttachedWindow;
    (void)bThumbDraw;
    (void)bMaintainAspectRatio;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_SHARE_RECORD_PROPERTY(%s)\n", "iRecNum, nEncoderType, nEncoderFormat, nColorSpaceType, nWidth, nHeight, dFrameRate, nRecordMode, nQuality, nBitRate, nGOP, nAspectRatioX, nAspectRatioY, hAttachedWindow, bThumbDraw, bMaintainAspectRatio");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_SHARE_RECORD_PROPERTY_EX(UINT iRecNum , UINT * pGpuNum , ULONG * pEncoderType , ULONG * pEncoderFormat , ULONG * pColorSpaceType , ULONG * pWidth , ULONG * pHeight , double * pFrameRate , ULONG * pRecordProfile  , ULONG * pRecordLevel  , ULONG * pRecordEntropy  , ULONG * pRecordComplexity  , ULONG * pRecordMode , ULONG * pQuality , ULONG * pBitRate , ULONG * pGOP , ULONG * pBFrames  , BOOL * pIsInterleaved  , ULONG * pSlices  , ULONG * pLayers  , ULONG * pSceneCut  , BOOL * pMultiThread  , BOOL * pMBBRC  , BOOL * pExtBRC  , ULONG * pMinQP  , ULONG * pMaxQP  , ULONG * pVBVMaxRate  , ULONG * pVBVBufSize  , ULONG * pCBRVariation  , ULONG * pAspectRatioX , ULONG * pAspectRatioY , HWND * pAttachedWindow , BOOL * pThumbDraw , BOOL * pMaintainAspectRatio )
{
    (void)iRecNum;
    (void)pGpuNum;
    (void)pEncoderType;
    (void)pEncoderFormat;
    (void)pColorSpaceType;
    (void)pWidth;
    (void)pHeight;
    (void)pFrameRate;
    (void)pRecordProfile;
    (void)pRecordLevel;
    (void)pRecordEntropy;
    (void)pRecordComplexity;
    (void)pRecordMode;
    (void)pQuality;
    (void)pBitRate;
    (void)pGOP;
    (void)pBFrames;
    (void)pIsInterleaved;
    (void)pSlices;
    (void)pLayers;
    (void)pSceneCut;
    (void)pMultiThread;
    (void)pMBBRC;
    (void)pExtBRC;
    (void)pMinQP;
    (void)pMaxQP;
    (void)pVBVMaxRate;
    (void)pVBVBufSize;
    (void)pCBRVariation;
    (void)pAspectRatioX;
    (void)pAspectRatioY;
    (void)pAttachedWindow;
    (void)pThumbDraw;
    (void)pMaintainAspectRatio;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_SHARE_RECORD_PROPERTY_EX(%s)\n", "iRecNum, pGpuNum, pEncoderType, pEncoderFormat, pColorSpaceType, pWidth, pHeight, pFrameRate, pRecordProfile, pRecordLevel, pRecordEntropy, pRecordComplexity, pRecordMode, pQuality, pBitRate, pGOP, pBFrames, pIsInterleaved, pSlices, pLayers, pSceneCut, pMultiThread, pMBBRC, pExtBRC, pMinQP, pMaxQP, pVBVMaxRate, pVBVBufSize, pCBRVariation, pAspectRatioX, pAspectRatioY, pAttachedWindow, pThumbDraw, pMaintainAspectRatio");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_SHARE_RECORD_PROPERTY_EX(UINT iRecNum , UINT   iGpuNum ,  ULONG   nEncoderType ,  ULONG   nEncoderFormat ,  ULONG   nColorSpaceType ,  ULONG   nWidth ,  ULONG   nHeight ,  double   dFrameRate ,  ULONG   nRecordProfile   , ULONG   nRecordLevel   , ULONG   nRecordEntropy   , ULONG   nRecordComplexity   , ULONG   nRecordMode ,  ULONG   nQuality ,  ULONG   nBitRate ,  ULONG   nGOP ,  ULONG   nBFrames   , BOOL   bIsInterleaved   , ULONG   nSlices   , ULONG   nLayers   , ULONG   nSceneCut   , BOOL   bMultiThread   , BOOL   bMBBRC   , BOOL   bExtBRC   , ULONG   nMinQP   , ULONG   nMaxQP   , ULONG   nVBVMaxRate   , ULONG   nVBVBufSize   , ULONG   nCBRVariation   , ULONG   nAspectRatioX ,  ULONG   nAspectRatioY ,  HWND   hAttachedWindow ,  BOOL   bThumbDraw , BOOL   bMaintainAspectRatio )
{
    (void)iRecNum;
    (void)iGpuNum;
    (void)nEncoderType;
    (void)nEncoderFormat;
    (void)nColorSpaceType;
    (void)nWidth;
    (void)nHeight;
    (void)dFrameRate;
    (void)nRecordProfile;
    (void)nRecordLevel;
    (void)nRecordEntropy;
    (void)nRecordComplexity;
    (void)nRecordMode;
    (void)nQuality;
    (void)nBitRate;
    (void)nGOP;
    (void)nBFrames;
    (void)bIsInterleaved;
    (void)nSlices;
    (void)nLayers;
    (void)nSceneCut;
    (void)bMultiThread;
    (void)bMBBRC;
    (void)bExtBRC;
    (void)nMinQP;
    (void)nMaxQP;
    (void)nVBVMaxRate;
    (void)nVBVBufSize;
    (void)nCBRVariation;
    (void)nAspectRatioX;
    (void)nAspectRatioY;
    (void)hAttachedWindow;
    (void)bThumbDraw;
    (void)bMaintainAspectRatio;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_SHARE_RECORD_PROPERTY_EX(%s)\n", "iRecNum, iGpuNum, nEncoderType, nEncoderFormat, nColorSpaceType, nWidth, nHeight, dFrameRate, nRecordProfile, nRecordLevel, nRecordEntropy, nRecordComplexity, nRecordMode, nQuality, nBitRate, nGOP, nBFrames, bIsInterleaved, nSlices, nLayers, nSceneCut, bMultiThread, bMBBRC, bExtBRC, nMinQP, nMaxQP, nVBVMaxRate, nVBVBufSize, nCBRVariation, nAspectRatioX, nAspectRatioY, hAttachedWindow, bThumbDraw, bMaintainAspectRatio");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_SHARE_RECORD_DYNAMIC_PROPERTY_EX(UINT iRecNum , ULONG * pRecordMode , ULONG * pQuality , ULONG * pBitRate , ULONG * pGOP )
{
    (void)iRecNum;
    (void)pRecordMode;
    (void)pQuality;
    (void)pBitRate;
    (void)pGOP;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_SHARE_RECORD_DYNAMIC_PROPERTY_EX(%s)\n", "iRecNum, pRecordMode, pQuality, pBitRate, pGOP");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_SHARE_RECORD_DYNAMIC_PROPERTY_EX(UINT iRecNum , ULONG   nRecordMode ,  ULONG   nQuality ,  ULONG   nBitRate ,  ULONG   nGOP )
{
    (void)iRecNum;
    (void)nRecordMode;
    (void)nQuality;
    (void)nBitRate;
    (void)nGOP;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_SHARE_RECORD_DYNAMIC_PROPERTY_EX(%s)\n", "iRecNum, nRecordMode, nQuality, nBitRate, nGOP");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_SHARE_RECORD_HDR(UINT iRecNum , BOOL * pPhysicalEnable , BOOL * pDisplayEnable , BOOL * pIsDisplaySupported )
{
    (void)iRecNum;
    (void)pPhysicalEnable;
    (void)pDisplayEnable;
    (void)pIsDisplaySupported;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_SHARE_RECORD_HDR(%s)\n", "iRecNum, pPhysicalEnable, pDisplayEnable, pIsDisplaySupported");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_SHARE_RECORD_HDR(UINT iRecNum , BOOL bPhysicalEnable , BOOL bDisplayEnable , PVOID pDevice )
{
    (void)iRecNum;
    (void)bPhysicalEnable;
    (void)bDisplayEnable;
    (void)pDevice;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_SHARE_RECORD_HDR(%s)\n", "iRecNum, bPhysicalEnable, bDisplayEnable, pDevice");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_SHARE_RECORD_COPP(UINT iRecNum , BOOL * pEnable )
{
    (void)iRecNum;
    (void)pEnable;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_SHARE_RECORD_COPP(%s)\n", "iRecNum, pEnable");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_SHARE_RECORD_COPP(UINT iRecNum , BOOL   bEnable )
{
    (void)iRecNum;
    (void)bEnable;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_SHARE_RECORD_COPP(%s)\n", "iRecNum, bEnable");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_SHARE_RECORD_BRIGHTNESS(UINT iRecNum , ULONG * pValue )
{
    (void)iRecNum;
    (void)pValue;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_SHARE_RECORD_BRIGHTNESS(%s)\n", "iRecNum, pValue");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_SHARE_RECORD_BRIGHTNESS(UINT iRecNum , ULONG nValue )
{
    (void)iRecNum;
    (void)nValue;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_SHARE_RECORD_BRIGHTNESS(%s)\n", "iRecNum, nValue");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_SHARE_RECORD_CONTRAST(UINT iRecNum , ULONG * pValue )
{
    (void)iRecNum;
    (void)pValue;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_SHARE_RECORD_CONTRAST(%s)\n", "iRecNum, pValue");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_SHARE_RECORD_CONTRAST(UINT iRecNum , ULONG nValue )
{
    (void)iRecNum;
    (void)nValue;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_SHARE_RECORD_CONTRAST(%s)\n", "iRecNum, nValue");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_SHARE_RECORD_HUE(UINT iRecNum , ULONG * pValue )
{
    (void)iRecNum;
    (void)pValue;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_SHARE_RECORD_HUE(%s)\n", "iRecNum, pValue");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_SHARE_RECORD_HUE(UINT iRecNum , ULONG nValue )
{
    (void)iRecNum;
    (void)nValue;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_SHARE_RECORD_HUE(%s)\n", "iRecNum, nValue");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_SHARE_RECORD_SATURATION(UINT iRecNum , ULONG * pValue )
{
    (void)iRecNum;
    (void)pValue;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_SHARE_RECORD_SATURATION(%s)\n", "iRecNum, pValue");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_SHARE_RECORD_SATURATION(UINT iRecNum , ULONG nValue )
{
    (void)iRecNum;
    (void)nValue;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_SHARE_RECORD_SATURATION(%s)\n", "iRecNum, nValue");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_AUDIO_SHARE_RECORD_PROPERTY(UINT iRecNum , ULONG * pEncoderType , ULONG * pEncoderFormat , ULONG * pChannels , ULONG * pBitsPerSample , ULONG * pSampleFrequency )
{
    (void)iRecNum;
    (void)pEncoderType;
    (void)pEncoderFormat;
    (void)pChannels;
    (void)pBitsPerSample;
    (void)pSampleFrequency;
    fprintf(stderr, "Mock function called: QCAP_GET_AUDIO_SHARE_RECORD_PROPERTY(%s)\n", "iRecNum, pEncoderType, pEncoderFormat, pChannels, pBitsPerSample, pSampleFrequency");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_SHARE_RECORD_PROPERTY(UINT iRecNum , ULONG   nEncoderType ,  ULONG   nEncoderFormat ,  ULONG   nChannels ,  ULONG   nBitsPerSample ,  ULONG   nSampleFrequency )
{
    (void)iRecNum;
    (void)nEncoderType;
    (void)nEncoderFormat;
    (void)nChannels;
    (void)nBitsPerSample;
    (void)nSampleFrequency;
    fprintf(stderr, "Mock function called: QCAP_SET_AUDIO_SHARE_RECORD_PROPERTY(%s)\n", "iRecNum, nEncoderType, nEncoderFormat, nChannels, nBitsPerSample, nSampleFrequency");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_AUDIO_SHARE_RECORD_PROPERTY_EX(UINT iRecNum , ULONG * pEncoderType , ULONG * pEncoderFormat , ULONG * pChannels , ULONG * pBitsPerSample , ULONG * pSampleFrequency , ULONG * pBitRate )
{
    (void)iRecNum;
    (void)pEncoderType;
    (void)pEncoderFormat;
    (void)pChannels;
    (void)pBitsPerSample;
    (void)pSampleFrequency;
    (void)pBitRate;
    fprintf(stderr, "Mock function called: QCAP_GET_AUDIO_SHARE_RECORD_PROPERTY_EX(%s)\n", "iRecNum, pEncoderType, pEncoderFormat, pChannels, pBitsPerSample, pSampleFrequency, pBitRate");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_SHARE_RECORD_PROPERTY_EX(UINT iRecNum , ULONG   nEncoderType ,  ULONG   nEncoderFormat ,  ULONG   nChannels ,  ULONG   nBitsPerSample ,  ULONG   nSampleFrequency ,  ULONG   nBitRate )
{
    (void)iRecNum;
    (void)nEncoderType;
    (void)nEncoderFormat;
    (void)nChannels;
    (void)nBitsPerSample;
    (void)nSampleFrequency;
    (void)nBitRate;
    fprintf(stderr, "Mock function called: QCAP_SET_AUDIO_SHARE_RECORD_PROPERTY_EX(%s)\n", "iRecNum, nEncoderType, nEncoderFormat, nChannels, nBitsPerSample, nSampleFrequency, nBitRate");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_AUDIO_SHARE_RECORD_SOUND_RENDERER(UINT iRecNum , UINT * pSoundNum )
{
    (void)iRecNum;
    (void)pSoundNum;
    fprintf(stderr, "Mock function called: QCAP_GET_AUDIO_SHARE_RECORD_SOUND_RENDERER(%s)\n", "iRecNum, pSoundNum");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_SHARE_RECORD_SOUND_RENDERER(UINT iRecNum , UINT   iSoundNum )
{
    (void)iRecNum;
    (void)iSoundNum;
    fprintf(stderr, "Mock function called: QCAP_SET_AUDIO_SHARE_RECORD_SOUND_RENDERER(%s)\n", "iRecNum, iSoundNum");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_AUDIO_SHARE_RECORD_VOLUME(UINT iRecNum , ULONG * pVolume )
{
    (void)iRecNum;
    (void)pVolume;
    fprintf(stderr, "Mock function called: QCAP_GET_AUDIO_SHARE_RECORD_VOLUME(%s)\n", "iRecNum, pVolume");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_SHARE_RECORD_VOLUME(UINT iRecNum , ULONG   nVolume )
{
    (void)iRecNum;
    (void)nVolume;
    fprintf(stderr, "Mock function called: QCAP_SET_AUDIO_SHARE_RECORD_VOLUME(%s)\n", "iRecNum, nVolume");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_AUDIO_SHARE_RECORD_NOISE_REMOVAL(UINT iRecNum , ULONG * pStrength )
{
    (void)iRecNum;
    (void)pStrength;
    fprintf(stderr, "Mock function called: QCAP_GET_AUDIO_SHARE_RECORD_NOISE_REMOVAL(%s)\n", "iRecNum, pStrength");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_SHARE_RECORD_NOISE_REMOVAL(UINT iRecNum , ULONG   nStrength )
{
    (void)iRecNum;
    (void)nStrength;
    fprintf(stderr, "Mock function called: QCAP_SET_AUDIO_SHARE_RECORD_NOISE_REMOVAL(%s)\n", "iRecNum, nStrength");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_SHARE_RECORD_UNCOMPRESSION_BUFFER(UINT iRecNum , ULONG nColorSpaceType , ULONG nWidth , ULONG nHeight , BYTE * pFrameBuffer , ULONG nFrameBufferLen , double dSampleTime )
{
    (void)iRecNum;
    (void)nColorSpaceType;
    (void)nWidth;
    (void)nHeight;
    (void)pFrameBuffer;
    (void)nFrameBufferLen;
    (void)dSampleTime;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_SHARE_RECORD_UNCOMPRESSION_BUFFER(%s)\n", "iRecNum, nColorSpaceType, nWidth, nHeight, pFrameBuffer, nFrameBufferLen, dSampleTime");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_SHARE_RECORD_UNCOMPRESSION_BUFFER_EX(UINT iRecNum , ULONG nColorSpaceType , ULONG nWidth , ULONG nHeight , BYTE * pFrameBuffer , ULONG nFrameBufferLen , ULONG nCropX , ULONG nCropY , ULONG nCropW , ULONG nCropH , ULONG nScaleStyle , BOOL bForceKeyFrame , double dSampleTime )
{
    (void)iRecNum;
    (void)nColorSpaceType;
    (void)nWidth;
    (void)nHeight;
    (void)pFrameBuffer;
    (void)nFrameBufferLen;
    (void)nCropX;
    (void)nCropY;
    (void)nCropW;
    (void)nCropH;
    (void)nScaleStyle;
    (void)bForceKeyFrame;
    (void)dSampleTime;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_SHARE_RECORD_UNCOMPRESSION_BUFFER_EX(%s)\n", "iRecNum, nColorSpaceType, nWidth, nHeight, pFrameBuffer, nFrameBufferLen, nCropX, nCropY, nCropW, nCropH, nScaleStyle, bForceKeyFrame, dSampleTime");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_SHARE_RECORD_UNCOMPRESSION_BUFFER(UINT iRecNum , BYTE * pFrameBuffer , ULONG nFrameBufferLen , double dSampleTime )
{
    (void)iRecNum;
    (void)pFrameBuffer;
    (void)nFrameBufferLen;
    (void)dSampleTime;
    fprintf(stderr, "Mock function called: QCAP_SET_AUDIO_SHARE_RECORD_UNCOMPRESSION_BUFFER(%s)\n", "iRecNum, pFrameBuffer, nFrameBufferLen, dSampleTime");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_SHARE_RECORD_UNCOMPRESSION_BUFFER_EX(UINT iRecNum , ULONG nChannels , ULONG nBitsPerSample , ULONG nSampleFrequency , BYTE * pFrameBuffer , ULONG nFrameBufferLen , double dSampleTime )
{
    (void)iRecNum;
    (void)nChannels;
    (void)nBitsPerSample;
    (void)nSampleFrequency;
    (void)pFrameBuffer;
    (void)nFrameBufferLen;
    (void)dSampleTime;
    fprintf(stderr, "Mock function called: QCAP_SET_AUDIO_SHARE_RECORD_UNCOMPRESSION_BUFFER_EX(%s)\n", "iRecNum, nChannels, nBitsPerSample, nSampleFrequency, pFrameBuffer, nFrameBufferLen, dSampleTime");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_SHARE_RECORD_COMPRESSION_BUFFER(UINT iRecNum , BYTE * pStreamBuffer , ULONG nStreamBufferLen , ULONG bIsKeyFrame , double dSampleTime )
{
    (void)iRecNum;
    (void)pStreamBuffer;
    (void)nStreamBufferLen;
    (void)bIsKeyFrame;
    (void)dSampleTime;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_SHARE_RECORD_COMPRESSION_BUFFER(%s)\n", "iRecNum, pStreamBuffer, nStreamBufferLen, bIsKeyFrame, dSampleTime");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_SHARE_RECORD_COMPRESSION_BUFFER(UINT iRecNum , BYTE * pStreamBuffer , ULONG nStreamBufferLen , double dSampleTime )
{
    (void)iRecNum;
    (void)pStreamBuffer;
    (void)nStreamBufferLen;
    (void)dSampleTime;
    fprintf(stderr, "Mock function called: QCAP_SET_AUDIO_SHARE_RECORD_COMPRESSION_BUFFER(%s)\n", "iRecNum, pStreamBuffer, nStreamBufferLen, dSampleTime");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_METADATA_SHARE_RECORD_HEADER(UINT iRecNum , CHAR * pszTitle , CHAR * pszArtist , CHAR * pszComments , CHAR * pszGenre , CHAR * pszComposer , CHAR * pszThumbnailPathName )
{
    (void)iRecNum;
    (void)pszTitle;
    (void)pszArtist;
    (void)pszComments;
    (void)pszGenre;
    (void)pszComposer;
    (void)pszThumbnailPathName;
    fprintf(stderr, "Mock function called: QCAP_SET_METADATA_SHARE_RECORD_HEADER(%s)\n", "iRecNum, pszTitle, pszArtist, pszComments, pszGenre, pszComposer, pszThumbnailPathName");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_METADATA_SHARE_RECORD_HEADER_W(UINT iRecNum , WSTRING pwszTitle , WSTRING pwszArtist , WSTRING pwszComments , WSTRING pwszGenre , WSTRING pwszComposer , WSTRING pwszThumbnailPathName )
{
    (void)iRecNum;
    (void)pwszTitle;
    (void)pwszArtist;
    (void)pwszComments;
    (void)pwszGenre;
    (void)pwszComposer;
    (void)pwszThumbnailPathName;
    fprintf(stderr, "Mock function called: QCAP_SET_METADATA_SHARE_RECORD_HEADER_W(%s)\n", "iRecNum, pwszTitle, pwszArtist, pwszComments, pwszGenre, pwszComposer, pwszThumbnailPathName");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_METADATA_SHARE_RECORD_DATA_BUFFER(UINT iRecNum , BYTE * pDataBuffer , ULONG nDataBufferLen , double dSampleTime , BOOL bIsSubtitle )
{
    (void)iRecNum;
    (void)pDataBuffer;
    (void)nDataBufferLen;
    (void)dSampleTime;
    (void)bIsSubtitle;
    fprintf(stderr, "Mock function called: QCAP_SET_METADATA_SHARE_RECORD_DATA_BUFFER(%s)\n", "iRecNum, pDataBuffer, nDataBufferLen, dSampleTime, bIsSubtitle");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_TIMESHIFT_SHARE_RECORD(UINT iRecNum , CHAR * pszFilePathName , PVOID * ppPhysicalFileWriter , DWORD dwFlags , double dVideoDelayTime , double dAudioDelayTime , CHAR * pszEncryptKey )
{
    (void)iRecNum;
    (void)pszFilePathName;
    (void)ppPhysicalFileWriter;
    (void)dwFlags;
    (void)dVideoDelayTime;
    (void)dAudioDelayTime;
    (void)pszEncryptKey;
    fprintf(stderr, "Mock function called: QCAP_START_TIMESHIFT_SHARE_RECORD(%s)\n", "iRecNum, pszFilePathName, ppPhysicalFileWriter, dwFlags, dVideoDelayTime, dAudioDelayTime, pszEncryptKey");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_FAILSAFE_SHARE_RECORD(UINT iRecNum , CHAR * pszFilePathName , UINT iLinkRecNum , PVOID pLinkPhysicalFileWriter , double dPreRecordTime , CHAR * pszEncryptKey )
{
    (void)iRecNum;
    (void)pszFilePathName;
    (void)iLinkRecNum;
    (void)pLinkPhysicalFileWriter;
    (void)dPreRecordTime;
    (void)pszEncryptKey;
    fprintf(stderr, "Mock function called: QCAP_START_FAILSAFE_SHARE_RECORD(%s)\n", "iRecNum, pszFilePathName, iLinkRecNum, pLinkPhysicalFileWriter, dPreRecordTime, pszEncryptKey");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_SHARE_RECORD(UINT iRecNum , CHAR * pszFilePathName , DWORD dwFlags , double dVideoDelayTime , double dAudioDelayTime , double dSegmentDurationTime , ULONG nSegmentDurationSizeKB , CHAR * pszEncryptKey )
{
    (void)iRecNum;
    (void)pszFilePathName;
    (void)dwFlags;
    (void)dVideoDelayTime;
    (void)dAudioDelayTime;
    (void)dSegmentDurationTime;
    (void)nSegmentDurationSizeKB;
    (void)pszEncryptKey;
    fprintf(stderr, "Mock function called: QCAP_START_SHARE_RECORD(%s)\n", "iRecNum, pszFilePathName, dwFlags, dVideoDelayTime, dAudioDelayTime, dSegmentDurationTime, nSegmentDurationSizeKB, pszEncryptKey");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_SHARE_RECORD(UINT iRecNum , BOOL bIsAsync , ULONG nMilliseconds )
{
    (void)iRecNum;
    (void)bIsAsync;
    (void)nMilliseconds;
    fprintf(stderr, "Mock function called: QCAP_STOP_SHARE_RECORD(%s)\n", "iRecNum, bIsAsync, nMilliseconds");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_RESUME_SHARE_RECORD(UINT iRecNum )
{
    (void)iRecNum;
    fprintf(stderr, "Mock function called: QCAP_RESUME_SHARE_RECORD(%s)\n", "iRecNum");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_PAUSE_SHARE_RECORD(UINT iRecNum )
{
    (void)iRecNum;
    fprintf(stderr, "Mock function called: QCAP_PAUSE_SHARE_RECORD(%s)\n", "iRecNum");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SEGMENT_SHARE_RECORD(UINT iRecNum )
{
    (void)iRecNum;
    fprintf(stderr, "Mock function called: QCAP_SEGMENT_SHARE_RECORD(%s)\n", "iRecNum");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SNAPSHOT_SHARE_RECORD_BMP(UINT iRecNum , CHAR * pszFilePathName , BOOL bIsAsync , ULONG nMilliseconds )
{
    (void)iRecNum;
    (void)pszFilePathName;
    (void)bIsAsync;
    (void)nMilliseconds;
    fprintf(stderr, "Mock function called: QCAP_SNAPSHOT_SHARE_RECORD_BMP(%s)\n", "iRecNum, pszFilePathName, bIsAsync, nMilliseconds");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SNAPSHOT_SHARE_RECORD_JPG(UINT iRecNum , CHAR * pszFilePathName , ULONG nQuality , BOOL bIsAsync , ULONG nMilliseconds )
{
    (void)iRecNum;
    (void)pszFilePathName;
    (void)nQuality;
    (void)bIsAsync;
    (void)nMilliseconds;
    fprintf(stderr, "Mock function called: QCAP_SNAPSHOT_SHARE_RECORD_JPG(%s)\n", "iRecNum, pszFilePathName, nQuality, bIsAsync, nMilliseconds");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SNAPSHOT_SHARE_RECORD_BMP_EX(UINT iRecNum , CHAR * pszFilePathName , ULONG nCropX , ULONG nCropY , ULONG nCropW , ULONG nCropH , ULONG nDstW , ULONG nDstH , BOOL bIsAsync , ULONG nMilliseconds )
{
    (void)iRecNum;
    (void)pszFilePathName;
    (void)nCropX;
    (void)nCropY;
    (void)nCropW;
    (void)nCropH;
    (void)nDstW;
    (void)nDstH;
    (void)bIsAsync;
    (void)nMilliseconds;
    fprintf(stderr, "Mock function called: QCAP_SNAPSHOT_SHARE_RECORD_BMP_EX(%s)\n", "iRecNum, pszFilePathName, nCropX, nCropY, nCropW, nCropH, nDstW, nDstH, bIsAsync, nMilliseconds");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SNAPSHOT_SHARE_RECORD_JPG_EX(UINT iRecNum , CHAR * pszFilePathName , ULONG nCropX , ULONG nCropY , ULONG nCropW , ULONG nCropH , ULONG nDstW , ULONG nDstH , ULONG nQuality , BOOL bIsAsync , ULONG nMilliseconds )
{
    (void)iRecNum;
    (void)pszFilePathName;
    (void)nCropX;
    (void)nCropY;
    (void)nCropW;
    (void)nCropH;
    (void)nDstW;
    (void)nDstH;
    (void)nQuality;
    (void)bIsAsync;
    (void)nMilliseconds;
    fprintf(stderr, "Mock function called: QCAP_SNAPSHOT_SHARE_RECORD_JPG_EX(%s)\n", "iRecNum, pszFilePathName, nCropX, nCropY, nCropW, nCropH, nDstW, nDstH, nQuality, bIsAsync, nMilliseconds");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_SHARE_RECORD_DONE_CALLBACK(UINT iRecNum , PF_SHARE_RECORD_DONE_CALLBACK pCB , PVOID pUserData )
{
    (void)iRecNum;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_SHARE_RECORD_DONE_CALLBACK(%s)\n", "iRecNum, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_SHARE_RECORD_FAIL_CALLBACK(UINT iRecNum , PF_SHARE_RECORD_FAIL_CALLBACK pCB , PVOID pUserData )
{
    (void)iRecNum;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_SHARE_RECORD_FAIL_CALLBACK(%s)\n", "iRecNum, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_SHARE_RECORD_SNAPSHOT_DONE_CALLBACK(UINT iRecNum , PF_SHARE_RECORD_SNAPSHOT_DONE_CALLBACK pCB , PVOID pUserData )
{
    (void)iRecNum;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_SHARE_RECORD_SNAPSHOT_DONE_CALLBACK(%s)\n", "iRecNum, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_SHARE_RECORD_SNAPSHOT_STREAM_CALLBACK(UINT iRecNum , PF_SHARE_RECORD_SNAPSHOT_STREAM_CALLBACK pCB , PVOID pUserData )
{
    (void)iRecNum;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_SHARE_RECORD_SNAPSHOT_STREAM_CALLBACK(%s)\n", "iRecNum, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_VIDEO_SHARE_RECORD_CALLBACK(UINT iRecNum , PF_VIDEO_SHARE_RECORD_CALLBACK pCB , PVOID pUserData )
{
    (void)iRecNum;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_VIDEO_SHARE_RECORD_CALLBACK(%s)\n", "iRecNum, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_AUDIO_SHARE_RECORD_CALLBACK(UINT iRecNum , PF_AUDIO_SHARE_RECORD_CALLBACK pCB , PVOID pUserData )
{
    (void)iRecNum;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_AUDIO_SHARE_RECORD_CALLBACK(%s)\n", "iRecNum, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_MEDIA_SHARE_RECORD_CALLBACK(UINT iRecNum , PF_MEDIA_SHARE_RECORD_CALLBACK pCB , PVOID pUserData )
{
    (void)iRecNum;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_MEDIA_SHARE_RECORD_CALLBACK(%s)\n", "iRecNum, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_VIDEO_DECODER_SHARE_RECORD_CALLBACK(UINT iRecNum , PF_VIDEO_DECODER_SHARE_RECORD_CALLBACK pCB , PVOID pUserData )
{
    (void)iRecNum;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_VIDEO_DECODER_SHARE_RECORD_CALLBACK(%s)\n", "iRecNum, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_AUDIO_DECODER_SHARE_RECORD_CALLBACK(UINT iRecNum , PF_AUDIO_DECODER_SHARE_RECORD_CALLBACK pCB , PVOID pUserData )
{
    (void)iRecNum;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_AUDIO_DECODER_SHARE_RECORD_CALLBACK(%s)\n", "iRecNum, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_VIDEO_DISPLAY_SHARE_RECORD_CALLBACK(UINT iRecNum , PF_VIDEO_DISPLAY_SHARE_RECORD_CALLBACK pCB , PVOID pUserData )
{
    (void)iRecNum;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_VIDEO_DISPLAY_SHARE_RECORD_CALLBACK(%s)\n", "iRecNum, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_AUDIO_DISPLAY_SHARE_RECORD_CALLBACK(UINT iRecNum , PF_AUDIO_DISPLAY_SHARE_RECORD_CALLBACK pCB , PVOID pUserData )
{
    (void)iRecNum;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_AUDIO_DISPLAY_SHARE_RECORD_CALLBACK(%s)\n", "iRecNum, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_VIDEO_SHARE_RECORD_MEDIA_TIMER_CALLBACK(UINT iRecNum , PF_VIDEO_SHARE_RECORD_MEDIA_TIMER_CALLBACK pCB , PVOID pUserData )
{
    (void)iRecNum;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_VIDEO_SHARE_RECORD_MEDIA_TIMER_CALLBACK(%s)\n", "iRecNum, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_AUDIO_SHARE_RECORD_MEDIA_TIMER_CALLBACK(UINT iRecNum , PF_AUDIO_SHARE_RECORD_MEDIA_TIMER_CALLBACK pCB , PVOID pUserData )
{
    (void)iRecNum;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_AUDIO_SHARE_RECORD_MEDIA_TIMER_CALLBACK(%s)\n", "iRecNum, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_3D_SHARE_RECORD_STEREO_UNCOMPRESSION_BUFFER(UINT iRecNum , ULONG nColorSpaceType , ULONG nWidth , ULONG nHeight , BYTE * pFrameBuffer , ULONG nFrameBufferLen , ULONG nStereoBufferType )
{
    (void)iRecNum;
    (void)nColorSpaceType;
    (void)nWidth;
    (void)nHeight;
    (void)pFrameBuffer;
    (void)nFrameBufferLen;
    (void)nStereoBufferType;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_3D_SHARE_RECORD_STEREO_UNCOMPRESSION_BUFFER(%s)\n", "iRecNum, nColorSpaceType, nWidth, nHeight, pFrameBuffer, nFrameBufferLen, nStereoBufferType");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_3D_SHARE_RECORD_STEREO_UNCOMPRESSION_BUFFER_EX(UINT iRecNum , ULONG nColorSpaceType , ULONG nWidth , ULONG nHeight , BYTE * pFrameBuffer , ULONG nFrameBufferLen , ULONG nCropX , ULONG nCropY , ULONG nCropW , ULONG nCropH , ULONG nScaleStyle , ULONG nStereoBufferType )
{
    (void)iRecNum;
    (void)nColorSpaceType;
    (void)nWidth;
    (void)nHeight;
    (void)pFrameBuffer;
    (void)nFrameBufferLen;
    (void)nCropX;
    (void)nCropY;
    (void)nCropW;
    (void)nCropH;
    (void)nScaleStyle;
    (void)nStereoBufferType;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_3D_SHARE_RECORD_STEREO_UNCOMPRESSION_BUFFER_EX(%s)\n", "iRecNum, nColorSpaceType, nWidth, nHeight, pFrameBuffer, nFrameBufferLen, nCropX, nCropY, nCropW, nCropH, nScaleStyle, nStereoBufferType");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_3D_SHARE_RECORD_L_UNCOMPRESSION_BUFFER(UINT iRecNum , ULONG nColorSpaceType , ULONG nWidth , ULONG nHeight , BYTE * pFrameBuffer , ULONG nFrameBufferLen )
{
    (void)iRecNum;
    (void)nColorSpaceType;
    (void)nWidth;
    (void)nHeight;
    (void)pFrameBuffer;
    (void)nFrameBufferLen;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_3D_SHARE_RECORD_L_UNCOMPRESSION_BUFFER(%s)\n", "iRecNum, nColorSpaceType, nWidth, nHeight, pFrameBuffer, nFrameBufferLen");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_3D_SHARE_RECORD_L_UNCOMPRESSION_BUFFER_EX(UINT iRecNum , ULONG nColorSpaceType , ULONG nWidth , ULONG nHeight , BYTE * pFrameBuffer , ULONG nFrameBufferLen , ULONG nCropX , ULONG nCropY , ULONG nCropW , ULONG nCropH , ULONG nScaleStyle )
{
    (void)iRecNum;
    (void)nColorSpaceType;
    (void)nWidth;
    (void)nHeight;
    (void)pFrameBuffer;
    (void)nFrameBufferLen;
    (void)nCropX;
    (void)nCropY;
    (void)nCropW;
    (void)nCropH;
    (void)nScaleStyle;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_3D_SHARE_RECORD_L_UNCOMPRESSION_BUFFER_EX(%s)\n", "iRecNum, nColorSpaceType, nWidth, nHeight, pFrameBuffer, nFrameBufferLen, nCropX, nCropY, nCropW, nCropH, nScaleStyle");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_3D_SHARE_RECORD_R_UNCOMPRESSION_BUFFER(UINT iRecNum , ULONG nColorSpaceType , ULONG nWidth , ULONG nHeight , BYTE * pFrameBuffer , ULONG nFrameBufferLen )
{
    (void)iRecNum;
    (void)nColorSpaceType;
    (void)nWidth;
    (void)nHeight;
    (void)pFrameBuffer;
    (void)nFrameBufferLen;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_3D_SHARE_RECORD_R_UNCOMPRESSION_BUFFER(%s)\n", "iRecNum, nColorSpaceType, nWidth, nHeight, pFrameBuffer, nFrameBufferLen");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_3D_SHARE_RECORD_R_UNCOMPRESSION_BUFFER_EX(UINT iRecNum , ULONG nColorSpaceType , ULONG nWidth , ULONG nHeight , BYTE * pFrameBuffer , ULONG nFrameBufferLen , ULONG nCropX , ULONG nCropY , ULONG nCropW , ULONG nCropH , ULONG nScaleStyle )
{
    (void)iRecNum;
    (void)nColorSpaceType;
    (void)nWidth;
    (void)nHeight;
    (void)pFrameBuffer;
    (void)nFrameBufferLen;
    (void)nCropX;
    (void)nCropY;
    (void)nCropW;
    (void)nCropH;
    (void)nScaleStyle;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_3D_SHARE_RECORD_R_UNCOMPRESSION_BUFFER_EX(%s)\n", "iRecNum, nColorSpaceType, nWidth, nHeight, pFrameBuffer, nFrameBufferLen, nCropX, nCropY, nCropW, nCropH, nScaleStyle");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_3D_SHARE_RECORD_UNCOMPRESSION_BUFFER(UINT iRecNum , ULONG nStereoDisplayMode , BOOL bLeftRightSwap , BOOL bForceKeyFrame , double dSampleTime )
{
    (void)iRecNum;
    (void)nStereoDisplayMode;
    (void)bLeftRightSwap;
    (void)bForceKeyFrame;
    (void)dSampleTime;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_3D_SHARE_RECORD_UNCOMPRESSION_BUFFER(%s)\n", "iRecNum, nStereoDisplayMode, bLeftRightSwap, bForceKeyFrame, dSampleTime");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_AUDIO_MX_SHARE_RECORD_PROPERTY_EX(UINT iRecNum , ULONG * pTracks , ULONG * pEncoderType , ULONG * pEncoderFormat , ULONG * pChannels , ULONG * pBitsPerSample , ULONG * pSampleFrequency , ULONG * pBitRate )
{
    (void)iRecNum;
    (void)pTracks;
    (void)pEncoderType;
    (void)pEncoderFormat;
    (void)pChannels;
    (void)pBitsPerSample;
    (void)pSampleFrequency;
    (void)pBitRate;
    fprintf(stderr, "Mock function called: QCAP_GET_AUDIO_MX_SHARE_RECORD_PROPERTY_EX(%s)\n", "iRecNum, pTracks, pEncoderType, pEncoderFormat, pChannels, pBitsPerSample, pSampleFrequency, pBitRate");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_MX_SHARE_RECORD_PROPERTY_EX(UINT iRecNum , ULONG   nTracks ,  ULONG   nEncoderType ,  ULONG   nEncoderFormat ,  ULONG   nChannels ,  ULONG   nBitsPerSample ,  ULONG   nSampleFrequency ,  ULONG   nBitRate )
{
    (void)iRecNum;
    (void)nTracks;
    (void)nEncoderType;
    (void)nEncoderFormat;
    (void)nChannels;
    (void)nBitsPerSample;
    (void)nSampleFrequency;
    (void)nBitRate;
    fprintf(stderr, "Mock function called: QCAP_SET_AUDIO_MX_SHARE_RECORD_PROPERTY_EX(%s)\n", "iRecNum, nTracks, nEncoderType, nEncoderFormat, nChannels, nBitsPerSample, nSampleFrequency, nBitRate");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_MX_SHARE_RECORD_MIXING_UNCOMPRESSION_BUFFER(UINT iRecNum , UINT iTrackNum , UINT iMixNum , BYTE * pFrameBuffer , ULONG nFrameBufferLen )
{
    (void)iRecNum;
    (void)iTrackNum;
    (void)iMixNum;
    (void)pFrameBuffer;
    (void)nFrameBufferLen;
    fprintf(stderr, "Mock function called: QCAP_SET_AUDIO_MX_SHARE_RECORD_MIXING_UNCOMPRESSION_BUFFER(%s)\n", "iRecNum, iTrackNum, iMixNum, pFrameBuffer, nFrameBufferLen");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_MX_SHARE_RECORD_MIXING_UNCOMPRESSION_BUFFER_EX(UINT iRecNum , UINT iTrackNum , UINT iMixNum , ULONG nChannels , ULONG nBitsPerSample , ULONG nSampleFrequency , BYTE * pFrameBuffer , ULONG nFrameBufferLen )
{
    (void)iRecNum;
    (void)iTrackNum;
    (void)iMixNum;
    (void)nChannels;
    (void)nBitsPerSample;
    (void)nSampleFrequency;
    (void)pFrameBuffer;
    (void)nFrameBufferLen;
    fprintf(stderr, "Mock function called: QCAP_SET_AUDIO_MX_SHARE_RECORD_MIXING_UNCOMPRESSION_BUFFER_EX(%s)\n", "iRecNum, iTrackNum, iMixNum, nChannels, nBitsPerSample, nSampleFrequency, pFrameBuffer, nFrameBufferLen");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_MX_SHARE_RECORD_UNCOMPRESSION_BUFFER(UINT iRecNum , UINT iTrackNum , double dSampleTime , BOOL bEnableSyncMixer )
{
    (void)iRecNum;
    (void)iTrackNum;
    (void)dSampleTime;
    (void)bEnableSyncMixer;
    fprintf(stderr, "Mock function called: QCAP_SET_AUDIO_MX_SHARE_RECORD_UNCOMPRESSION_BUFFER(%s)\n", "iRecNum, iTrackNum, dSampleTime, bEnableSyncMixer");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_MX_SHARE_RECORD_COMPRESSION_BUFFER(UINT iRecNum , UINT iTrackNum , BYTE * pStreamBuffer , ULONG nStreamBufferLen , double dSampleTime )
{
    (void)iRecNum;
    (void)iTrackNum;
    (void)pStreamBuffer;
    (void)nStreamBufferLen;
    (void)dSampleTime;
    fprintf(stderr, "Mock function called: QCAP_SET_AUDIO_MX_SHARE_RECORD_COMPRESSION_BUFFER(%s)\n", "iRecNum, iTrackNum, pStreamBuffer, nStreamBufferLen, dSampleTime");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_AUDIO_MX_SHARE_RECORD_CALLBACK(UINT iRecNum , PF_AUDIO_MX_SHARE_RECORD_CALLBACK pCB , PVOID pUserData )
{
    (void)iRecNum;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_AUDIO_MX_SHARE_RECORD_CALLBACK(%s)\n", "iRecNum, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_AUDIO_DECODER_MX_SHARE_RECORD_CALLBACK(UINT iRecNum , PF_AUDIO_DECODER_MX_SHARE_RECORD_CALLBACK pCB , PVOID pUserData )
{
    (void)iRecNum;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_AUDIO_DECODER_MX_SHARE_RECORD_CALLBACK(%s)\n", "iRecNum, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_SYNCHRONIZED_RECORD(PVOID * ppSyncRecorder , ULONG nFileArgs , CHAR * pszFilePathName1 , PVOID pDevice1 , UINT iRecNum1 , CHAR * pszFilePathName2 , PVOID pDevice2 , UINT iRecNum2 , ...)
{
    (void)ppSyncRecorder;
    (void)nFileArgs;
    (void)pszFilePathName1;
    (void)pDevice1;
    (void)iRecNum1;
    (void)pszFilePathName2;
    (void)pDevice2;
    (void)iRecNum2;
    fprintf(stderr, "Mock function called: QCAP_CREATE_SYNCHRONIZED_RECORD(%s)\n", "ppSyncRecorder, nFileArgs, pszFilePathName1, pDevice1, iRecNum1, pszFilePathName2, pDevice2, iRecNum2");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_SYNCHRONIZED_RECORD(PVOID pSyncRecorder )
{
    (void)pSyncRecorder;
    fprintf(stderr, "Mock function called: QCAP_DESTROY_SYNCHRONIZED_RECORD(%s)\n", "pSyncRecorder");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_SYNCHRONIZED_TIMESHIFT_RECORD(PVOID pSyncRecorder , PVOID * ppPhysicalFileWriters , DWORD dwFlags , double dSegmentDurationTime , ULONG nSegmentDurationSizeKB , CHAR * pszEncryptKey )
{
    (void)pSyncRecorder;
    (void)ppPhysicalFileWriters;
    (void)dwFlags;
    (void)dSegmentDurationTime;
    (void)nSegmentDurationSizeKB;
    (void)pszEncryptKey;
    fprintf(stderr, "Mock function called: QCAP_START_SYNCHRONIZED_TIMESHIFT_RECORD(%s)\n", "pSyncRecorder, ppPhysicalFileWriters, dwFlags, dSegmentDurationTime, nSegmentDurationSizeKB, pszEncryptKey");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_SYNCHRONIZED_RECORD(PVOID pSyncRecorder , DWORD dwFlags , double dSegmentDurationTime , ULONG nSegmentDurationSizeKB , CHAR * pszEncryptKey )
{
    (void)pSyncRecorder;
    (void)dwFlags;
    (void)dSegmentDurationTime;
    (void)nSegmentDurationSizeKB;
    (void)pszEncryptKey;
    fprintf(stderr, "Mock function called: QCAP_START_SYNCHRONIZED_RECORD(%s)\n", "pSyncRecorder, dwFlags, dSegmentDurationTime, nSegmentDurationSizeKB, pszEncryptKey");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_SYNCHRONIZED_RECORD(PVOID pSyncRecorder , BOOL bIsAsync , ULONG nMilliseconds )
{
    (void)pSyncRecorder;
    (void)bIsAsync;
    (void)nMilliseconds;
    fprintf(stderr, "Mock function called: QCAP_STOP_SYNCHRONIZED_RECORD(%s)\n", "pSyncRecorder, bIsAsync, nMilliseconds");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_RESUME_SYNCHRONIZED_RECORD(PVOID pSyncRecorder )
{
    (void)pSyncRecorder;
    fprintf(stderr, "Mock function called: QCAP_RESUME_SYNCHRONIZED_RECORD(%s)\n", "pSyncRecorder");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_PAUSE_SYNCHRONIZED_RECORD(PVOID pSyncRecorder )
{
    (void)pSyncRecorder;
    fprintf(stderr, "Mock function called: QCAP_PAUSE_SYNCHRONIZED_RECORD(%s)\n", "pSyncRecorder");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SEGMENT_SYNCHRONIZED_RECORD(PVOID pSyncRecorder )
{
    (void)pSyncRecorder;
    fprintf(stderr, "Mock function called: QCAP_SEGMENT_SYNCHRONIZED_RECORD(%s)\n", "pSyncRecorder");
    return QCAP_RS_SUCCESSFUL;
}

