#include "mock_qcap_playback.h"
#include <cstdio> // For fprintf, stderr

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_EXPORT_FILE(PVOID pFile , double dStartSampleTime , double dStopSampleTime , CHAR * pszExportedFileName , double * pExportedProgress )
{
    (void)pFile;
    (void)dStartSampleTime;
    (void)dStopSampleTime;
    (void)pszExportedFileName;
    (void)pExportedProgress;
    fprintf(stderr, "Mock function called: QCAP_EXPORT_FILE(%s)\n", "pFile, dStartSampleTime, dStopSampleTime, pszExportedFileName, pExportedProgress");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_EXPORT_FILE_EX(PVOID pFile , CHAR * pszExportedFileName , double * pExportedProgress , ULONG nFileArgs , double dStartSampleTime1 , double dStopSampleTime1 , double dStartSampleTime2 , double dStopSampleTime2 , ...)
{
    (void)pFile;
    (void)pszExportedFileName;
    (void)pExportedProgress;
    (void)nFileArgs;
    (void)dStartSampleTime1;
    (void)dStopSampleTime1;
    (void)dStartSampleTime2;
    (void)dStopSampleTime2;
    fprintf(stderr, "Mock function called: QCAP_EXPORT_FILE_EX(%s)\n", "pFile, pszExportedFileName, pExportedProgress, nFileArgs, dStartSampleTime1, dStopSampleTime1, dStartSampleTime2, dStopSampleTime2");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_EXPORT_FILE_EX_C(PVOID pFile , CHAR * pszExportedFileName , double * pExportedProgress , ULONG nFileArgs , double dStartSampleTimes[ ] , double dStopSampleTimes[ ] )
{
    (void)pFile;
    (void)pszExportedFileName;
    (void)pExportedProgress;
    (void)nFileArgs;
    (void)dStartSampleTimes;
    (void)dStopSampleTimes;
    fprintf(stderr, "Mock function called: QCAP_EXPORT_FILE_EX_C(%s)\n", "pFile, pszExportedFileName, pExportedProgress, nFileArgs, dStartSampleTimes, dStopSampleTimes");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_EXPORT_FILES_EX(PVOID pFile , ULONG nFileArgs , double dStartSampleTime1 , double dStopSampleTime1 , CHAR * pszExportedFileName1 , double * pExportedProgress1 , double dStartSampleTime2 , double dStopSampleTime2 , CHAR * pszExportedFileName2 , double * pExportedProgress2 , ...)
{
    (void)pFile;
    (void)nFileArgs;
    (void)dStartSampleTime1;
    (void)dStopSampleTime1;
    (void)pszExportedFileName1;
    (void)pExportedProgress1;
    (void)dStartSampleTime2;
    (void)dStopSampleTime2;
    (void)pszExportedFileName2;
    (void)pExportedProgress2;
    fprintf(stderr, "Mock function called: QCAP_EXPORT_FILES_EX(%s)\n", "pFile, nFileArgs, dStartSampleTime1, dStopSampleTime1, pszExportedFileName1, pExportedProgress1, dStartSampleTime2, dStopSampleTime2, pszExportedFileName2, pExportedProgress2");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_EXPORT_FILES_EX_C(PVOID pFile , ULONG nFileArgs , double dStartSampleTimes[ ] , double dStopSampleTimes[ ] , CHAR * pszExportedFileNames[ ] , double * pExportedProgress[ ] )
{
    (void)pFile;
    (void)nFileArgs;
    (void)dStartSampleTimes;
    (void)dStopSampleTimes;
    (void)pszExportedFileNames;
    (void)pExportedProgress;
    fprintf(stderr, "Mock function called: QCAP_EXPORT_FILES_EX_C(%s)\n", "pFile, nFileArgs, dStartSampleTimes, dStopSampleTimes, pszExportedFileNames, pExportedProgress");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_MERGE_FILES(CHAR * pszFrontEndFileName , CHAR * pszBackEndFileName , CHAR * pszMergedFileName , double * pMergedProgress )
{
    (void)pszFrontEndFileName;
    (void)pszBackEndFileName;
    (void)pszMergedFileName;
    (void)pMergedProgress;
    fprintf(stderr, "Mock function called: QCAP_MERGE_FILES(%s)\n", "pszFrontEndFileName, pszBackEndFileName, pszMergedFileName, pMergedProgress");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_MERGE_FILES_EX(CHAR * pszMergedFileName , double * pMergedProgress , ULONG nFileArgs , CHAR * pszSourceFileName1 , CHAR * pszSourceFileName2 , ...)
{
    (void)pszMergedFileName;
    (void)pMergedProgress;
    (void)nFileArgs;
    (void)pszSourceFileName1;
    (void)pszSourceFileName2;
    fprintf(stderr, "Mock function called: QCAP_MERGE_FILES_EX(%s)\n", "pszMergedFileName, pMergedProgress, nFileArgs, pszSourceFileName1, pszSourceFileName2");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_MERGE_FILES_EX_C(CHAR * pszMergedFileName , double * pMergedProgress , ULONG nFileArgs , CHAR * pszSourceFileNames[ ]  )
{
    (void)pszMergedFileName;
    (void)pMergedProgress;
    (void)nFileArgs;
    (void)pszSourceFileNames;
    fprintf(stderr, "Mock function called: QCAP_MERGE_FILES_EX_C(%s)\n", "pszMergedFileName, pMergedProgress, nFileArgs, pszSourceFileNames");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_MERGE_FILES_BY_EDL(CHAR * pszEDLFileName , double * pMergedProgress )
{
    (void)pszEDLFileName;
    (void)pMergedProgress;
    fprintf(stderr, "Mock function called: QCAP_MERGE_FILES_BY_EDL(%s)\n", "pszEDLFileName, pMergedProgress");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_BUILD_VIDEO_ON_DEMAND_FILE(CHAR * pszOriginalFileName , CHAR * pszVideoOnDemandFileName , double * pConvertProgress )
{
    (void)pszOriginalFileName;
    (void)pszVideoOnDemandFileName;
    (void)pConvertProgress;
    fprintf(stderr, "Mock function called: QCAP_BUILD_VIDEO_ON_DEMAND_FILE(%s)\n", "pszOriginalFileName, pszVideoOnDemandFileName, pConvertProgress");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_UPLOAD_FILE_TO_YOUTUBE(CHAR * pszUploadFileName , CHAR * pszAccount , CHAR * pszPassword , double * pUploadProgress )
{
    (void)pszUploadFileName;
    (void)pszAccount;
    (void)pszPassword;
    (void)pUploadProgress;
    fprintf(stderr, "Mock function called: QCAP_UPLOAD_FILE_TO_YOUTUBE(%s)\n", "pszUploadFileName, pszAccount, pszPassword, pUploadProgress");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DIAGNOSE_FILE(CHAR * pszFileName , BOOL * pIsHealthy )
{
    (void)pszFileName;
    (void)pIsHealthy;
    fprintf(stderr, "Mock function called: QCAP_DIAGNOSE_FILE(%s)\n", "pszFileName, pIsHealthy");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DIAGNOSE_FILE_W(WSTRING pwszFileName , BOOL * pIsHealthy )
{
    (void)pwszFileName;
    (void)pIsHealthy;
    fprintf(stderr, "Mock function called: QCAP_DIAGNOSE_FILE_W(%s)\n", "pwszFileName, pIsHealthy");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REPAIR_FILE(CHAR * pszBadFileName , CHAR * pszRepairedFileName )
{
    (void)pszBadFileName;
    (void)pszRepairedFileName;
    fprintf(stderr, "Mock function called: QCAP_REPAIR_FILE(%s)\n", "pszBadFileName, pszRepairedFileName");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REPAIR_FILE_W(WSTRING pwszBadFileName , WSTRING pwszRepairedFileName )
{
    (void)pwszBadFileName;
    (void)pwszRepairedFileName;
    fprintf(stderr, "Mock function called: QCAP_REPAIR_FILE_W(%s)\n", "pwszBadFileName, pwszRepairedFileName");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_FILE_TRANSCODER(CHAR * pszSrcFileName , PVOID * ppFileTranscoder , ULONG nDecoderType , ULONG * pVideoEncoderFormat , ULONG * pVideoWidth , ULONG * pVideoHeight , double * pVideoFrameRate , ULONG * pAudioEncoderFormat , ULONG * pAudioChannels , ULONG * pAudioBitsPerSample , ULONG * pAudioSampleFrequency , double * pTotalDurationTimes , ULONG * pTotalVideoFrames , ULONG * pTotalAudioFrames , ULONG * pTotalMetadataFrames )
{
    (void)pszSrcFileName;
    (void)ppFileTranscoder;
    (void)nDecoderType;
    (void)pVideoEncoderFormat;
    (void)pVideoWidth;
    (void)pVideoHeight;
    (void)pVideoFrameRate;
    (void)pAudioEncoderFormat;
    (void)pAudioChannels;
    (void)pAudioBitsPerSample;
    (void)pAudioSampleFrequency;
    (void)pTotalDurationTimes;
    (void)pTotalVideoFrames;
    (void)pTotalAudioFrames;
    (void)pTotalMetadataFrames;
    fprintf(stderr, "Mock function called: QCAP_CREATE_FILE_TRANSCODER(%s)\n", "pszSrcFileName, ppFileTranscoder, nDecoderType, pVideoEncoderFormat, pVideoWidth, pVideoHeight, pVideoFrameRate, pAudioEncoderFormat, pAudioChannels, pAudioBitsPerSample, pAudioSampleFrequency, pTotalDurationTimes, pTotalVideoFrames, pTotalAudioFrames, pTotalMetadataFrames");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_FILE_TRANSCODER(PVOID pFileTranscoder )
{
    (void)pFileTranscoder;
    fprintf(stderr, "Mock function called: QCAP_DESTROY_FILE_TRANSCODER(%s)\n", "pFileTranscoder");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_FILE_TRANSCODER_PROPERTY(PVOID pFileTranscoder , ULONG * pEncoderType , ULONG * pEncoderFormat , ULONG * pWidth , ULONG * pHeight , double * pFrameRate , ULONG * pRecordMode , ULONG * pQuality , ULONG * pBitRate , ULONG * pGOP , ULONG * pAspectRatioX , ULONG * pAspectRatioY )
{
    (void)pFileTranscoder;
    (void)pEncoderType;
    (void)pEncoderFormat;
    (void)pWidth;
    (void)pHeight;
    (void)pFrameRate;
    (void)pRecordMode;
    (void)pQuality;
    (void)pBitRate;
    (void)pGOP;
    (void)pAspectRatioX;
    (void)pAspectRatioY;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_FILE_TRANSCODER_PROPERTY(%s)\n", "pFileTranscoder, pEncoderType, pEncoderFormat, pWidth, pHeight, pFrameRate, pRecordMode, pQuality, pBitRate, pGOP, pAspectRatioX, pAspectRatioY");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_FILE_TRANSCODER_PROPERTY(PVOID pFileTranscoder , ULONG   nEncoderType ,  ULONG   nEncoderFormat ,  ULONG   nWidth ,  ULONG   nHeight ,  double   dFrameRate ,  ULONG   nRecordMode ,  ULONG   nQuality ,  ULONG   nBitRate ,  ULONG   nGOP ,  ULONG   nAspectRatioX ,  ULONG   nAspectRatioY )
{
    (void)pFileTranscoder;
    (void)nEncoderType;
    (void)nEncoderFormat;
    (void)nWidth;
    (void)nHeight;
    (void)dFrameRate;
    (void)nRecordMode;
    (void)nQuality;
    (void)nBitRate;
    (void)nGOP;
    (void)nAspectRatioX;
    (void)nAspectRatioY;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_FILE_TRANSCODER_PROPERTY(%s)\n", "pFileTranscoder, nEncoderType, nEncoderFormat, nWidth, nHeight, dFrameRate, nRecordMode, nQuality, nBitRate, nGOP, nAspectRatioX, nAspectRatioY");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_FILE_TRANSCODER_PROPERTY_EX(PVOID pFileTranscoder , UINT * pGpuNum , ULONG * pEncoderType , ULONG * pEncoderFormat , ULONG * pWidth , ULONG * pHeight , double * pFrameRate , ULONG * pRecordProfile , ULONG * pRecordLevel , ULONG * pRecordEntropy , ULONG * pRecordComplexity , ULONG * pRecordMode , ULONG * pQuality , ULONG * pBitRate , ULONG * pGOP , ULONG * pBFrames , BOOL * pIsInterleaved , ULONG * pSlices , ULONG * pLayers , ULONG * pSceneCut , BOOL * pMultiThread , BOOL * pMBBRC , BOOL * pExtBRC , ULONG * pMinQP , ULONG * pMaxQP , ULONG * pVBVMaxRate , ULONG * pVBVBufSize , ULONG * pCBRVariation , ULONG * pAspectRatioX , ULONG * pAspectRatioY , ULONG * pScaleStyle )
{
    (void)pFileTranscoder;
    (void)pGpuNum;
    (void)pEncoderType;
    (void)pEncoderFormat;
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
    (void)pScaleStyle;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_FILE_TRANSCODER_PROPERTY_EX(%s)\n", "pFileTranscoder, pGpuNum, pEncoderType, pEncoderFormat, pWidth, pHeight, pFrameRate, pRecordProfile, pRecordLevel, pRecordEntropy, pRecordComplexity, pRecordMode, pQuality, pBitRate, pGOP, pBFrames, pIsInterleaved, pSlices, pLayers, pSceneCut, pMultiThread, pMBBRC, pExtBRC, pMinQP, pMaxQP, pVBVMaxRate, pVBVBufSize, pCBRVariation, pAspectRatioX, pAspectRatioY, pScaleStyle");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_FILE_TRANSCODER_PROPERTY_EX(PVOID pFileTranscoder , UINT   iGpuNum ,  ULONG   nEncoderType ,  ULONG   nEncoderFormat ,  ULONG   nWidth ,  ULONG   nHeight ,  double   dFrameRate ,  ULONG   nRecordProfile , ULONG   nRecordLevel , ULONG   nRecordEntropy , ULONG   nRecordComplexity , ULONG   nRecordMode ,  ULONG   nQuality ,  ULONG   nBitRate ,  ULONG   nGOP ,  ULONG   nBFrames , BOOL   bIsInterleaved , ULONG   nSlices , ULONG   nLayers , ULONG   nSceneCut , BOOL   bMultiThread , BOOL   bMBBRC , BOOL   bExtBRC , ULONG   nMinQP , ULONG   nMaxQP , ULONG   nVBVMaxRate , ULONG   nVBVBufSize , ULONG   nCBRVariation , ULONG   nAspectRatioX ,  ULONG   nAspectRatioY ,  ULONG   nScaleStyle )
{
    (void)pFileTranscoder;
    (void)iGpuNum;
    (void)nEncoderType;
    (void)nEncoderFormat;
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
    (void)nScaleStyle;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_FILE_TRANSCODER_PROPERTY_EX(%s)\n", "pFileTranscoder, iGpuNum, nEncoderType, nEncoderFormat, nWidth, nHeight, dFrameRate, nRecordProfile, nRecordLevel, nRecordEntropy, nRecordComplexity, nRecordMode, nQuality, nBitRate, nGOP, nBFrames, bIsInterleaved, nSlices, nLayers, nSceneCut, bMultiThread, bMBBRC, bExtBRC, nMinQP, nMaxQP, nVBVMaxRate, nVBVBufSize, nCBRVariation, nAspectRatioX, nAspectRatioY, nScaleStyle");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_FILE_TRANSCODER(PVOID pFileTranscoder , CHAR * pszDstFileName )
{
    (void)pFileTranscoder;
    (void)pszDstFileName;
    fprintf(stderr, "Mock function called: QCAP_START_FILE_TRANSCODER(%s)\n", "pFileTranscoder, pszDstFileName");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_FILE_TRANSCODER(PVOID pFileTranscoder )
{
    (void)pFileTranscoder;
    fprintf(stderr, "Mock function called: QCAP_STOP_FILE_TRANSCODER(%s)\n", "pFileTranscoder");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_FILE_TRANSCODER_CALLBACK(PVOID pFileTranscoder , PF_FILE_TRANSCODER_CALLBACK pCB , PVOID pUserData )
{
    (void)pFileTranscoder;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_FILE_TRANSCODER_CALLBACK(%s)\n", "pFileTranscoder, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

