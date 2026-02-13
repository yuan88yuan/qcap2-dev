#ifndef MOCK_QCAP_PLAYBACK_H
#define MOCK_QCAP_PLAYBACK_H

#include "qcap_mock_common.h"

#ifdef __cplusplus
extern "C"
{
#endif

// Function Declarations
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_EXPORT_FILE(PVOID pFile /*IN*/, double dStartSampleTime /*IN*/, double dStopSampleTime /*IN*/, CHAR * pszExportedFileName /*IN*/, double * pExportedProgress /*OUT*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_EXPORT_FILE_EX(PVOID pFile /*IN*/, CHAR * pszExportedFileName /*IN*/, double * pExportedProgress /*OUT*/, ULONG nFileArgs /*IN*/, double dStartSampleTime1 /*IN*/, double dStopSampleTime1 /*IN*/, double dStartSampleTime2 /*IN*/, double dStopSampleTime2 /*IN*/, ...);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_EXPORT_FILE_EX_C(PVOID pFile /*IN*/, CHAR * pszExportedFileName /*IN*/, double * pExportedProgress /*OUT*/, ULONG nFileArgs /*IN*/, double dStartSampleTimes[ ] /*IN*/, double dStopSampleTimes[ ] /*IN*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_EXPORT_FILES_EX(PVOID pFile /*IN*/, ULONG nFileArgs /*IN*/, double dStartSampleTime1 /*IN*/, double dStopSampleTime1 /*IN*/, CHAR * pszExportedFileName1 /*IN*/, double * pExportedProgress1 /*OUT*/, double dStartSampleTime2 /*IN*/, double dStopSampleTime2 /*IN*/, CHAR * pszExportedFileName2 /*IN*/, double * pExportedProgress2 /*OUT*/, ...);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_EXPORT_FILES_EX_C(PVOID pFile /*IN*/, ULONG nFileArgs /*IN*/, double dStartSampleTimes[ ] /*IN*/, double dStopSampleTimes[ ] /*IN*/, CHAR * pszExportedFileNames[ ] /*IN*/, double * pExportedProgress[ ] /*OUT*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_MERGE_FILES(CHAR * pszFrontEndFileName /*IN*/, CHAR * pszBackEndFileName /*IN*/, CHAR * pszMergedFileName /*IN*/, double * pMergedProgress /*OUT*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_MERGE_FILES_EX(CHAR * pszMergedFileName /*IN*/, double * pMergedProgress /*OUT*/, ULONG nFileArgs /*IN*/, CHAR * pszSourceFileName1 /*IN*/, CHAR * pszSourceFileName2 /*IN*/, ...);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_MERGE_FILES_EX_C(CHAR * pszMergedFileName /*IN*/, double * pMergedProgress /*OUT*/, ULONG nFileArgs /*IN*/, CHAR * pszSourceFileNames[ ] /*IN*/ /*OUT*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_MERGE_FILES_BY_EDL(CHAR * pszEDLFileName /*IN*/, double * pMergedProgress /*OUT*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_BUILD_VIDEO_ON_DEMAND_FILE(CHAR * pszOriginalFileName /*IN*/, CHAR * pszVideoOnDemandFileName /*IN*/, double * pConvertProgress /*OUT*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_UPLOAD_FILE_TO_YOUTUBE(CHAR * pszUploadFileName /*IN*/, CHAR * pszAccount /*IN*/, CHAR * pszPassword /*IN*/, double * pUploadProgress /*OUT*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DIAGNOSE_FILE(CHAR * pszFileName /*IN*/, BOOL * pIsHealthy /*OUT*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DIAGNOSE_FILE_W(WSTRING pwszFileName /*IN*/, BOOL * pIsHealthy /*OUT*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REPAIR_FILE(CHAR * pszBadFileName /*IN*/, CHAR * pszRepairedFileName /*IN*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REPAIR_FILE_W(WSTRING pwszBadFileName /*IN*/, WSTRING pwszRepairedFileName /*IN*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_FILE_TRANSCODER(CHAR * pszSrcFileName /*IN*/, PVOID * ppFileTranscoder /*OUT*/, ULONG nDecoderType /*IN*/, ULONG * pVideoEncoderFormat /*OUT*/, ULONG * pVideoWidth /*OUT*/, ULONG * pVideoHeight /*OUT*/, double * pVideoFrameRate /*OUT*/, ULONG * pAudioEncoderFormat /*OUT*/, ULONG * pAudioChannels /*OUT*/, ULONG * pAudioBitsPerSample /*OUT*/, ULONG * pAudioSampleFrequency /*OUT*/, double * pTotalDurationTimes /*OUT*/, ULONG * pTotalVideoFrames /*OUT*/, ULONG * pTotalAudioFrames /*OUT*/, ULONG * pTotalMetadataFrames /*OUT*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_FILE_TRANSCODER(PVOID pFileTranscoder /*IN*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_FILE_TRANSCODER_PROPERTY(PVOID pFileTranscoder /*IN*/, ULONG * pEncoderType /*OUT*/, ULONG * pEncoderFormat /*OUT*/, ULONG * pWidth /*OUT*/, ULONG * pHeight /*OUT*/, double * pFrameRate /*OUT*/, ULONG * pRecordMode /*OUT*/, ULONG * pQuality /*OUT*/, ULONG * pBitRate /*OUT*/, ULONG * pGOP /*OUT*/, ULONG * pAspectRatioX /*OUT*/, ULONG * pAspectRatioY /*OUT*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_FILE_TRANSCODER_PROPERTY(PVOID pFileTranscoder /*IN*/, ULONG   nEncoderType /*IN*/,  ULONG   nEncoderFormat /*IN*/,  ULONG   nWidth /*IN*/,  ULONG   nHeight /*IN*/,  double   dFrameRate /*IN*/,  ULONG   nRecordMode /*IN*/,  ULONG   nQuality /*IN*/,  ULONG   nBitRate /*IN*/,  ULONG   nGOP /*IN*/,  ULONG   nAspectRatioX /*IN*/,  ULONG   nAspectRatioY /*IN*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_FILE_TRANSCODER_PROPERTY_EX(PVOID pFileTranscoder /*IN*/, UINT * pGpuNum /*OUT*/, ULONG * pEncoderType /*OUT*/, ULONG * pEncoderFormat /*OUT*/, ULONG * pWidth /*OUT*/, ULONG * pHeight /*OUT*/, double * pFrameRate /*OUT*/, ULONG * pRecordProfile /*OUT*/, ULONG * pRecordLevel /*OUT*/, ULONG * pRecordEntropy /*OUT*/, ULONG * pRecordComplexity /*OUT*/, ULONG * pRecordMode /*OUT*/, ULONG * pQuality /*OUT*/, ULONG * pBitRate /*OUT*/, ULONG * pGOP /*OUT*/, ULONG * pBFrames /*OUT*/, BOOL * pIsInterleaved /*OUT*/, ULONG * pSlices /*OUT*/, ULONG * pLayers /*OUT*/, ULONG * pSceneCut /*OUT*/, BOOL * pMultiThread /*OUT*/, BOOL * pMBBRC /*OUT*/, BOOL * pExtBRC /*OUT*/, ULONG * pMinQP /*OUT*/, ULONG * pMaxQP /*OUT*/, ULONG * pVBVMaxRate /*OUT*/, ULONG * pVBVBufSize /*OUT*/, ULONG * pCBRVariation /*OUT*/, ULONG * pAspectRatioX /*OUT*/, ULONG * pAspectRatioY /*OUT*/, ULONG * pScaleStyle /*OUT*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_FILE_TRANSCODER_PROPERTY_EX(PVOID pFileTranscoder /*IN*/, UINT   iGpuNum /*IN*/,  ULONG   nEncoderType /*IN*/,  ULONG   nEncoderFormat /*IN*/,  ULONG   nWidth /*IN*/,  ULONG   nHeight /*IN*/,  double   dFrameRate /*IN*/,  ULONG   nRecordProfile /*IN*/, ULONG   nRecordLevel /*IN*/, ULONG   nRecordEntropy /*IN*/, ULONG   nRecordComplexity /*IN*/, ULONG   nRecordMode /*IN*/,  ULONG   nQuality /*IN*/,  ULONG   nBitRate /*IN*/,  ULONG   nGOP /*IN*/,  ULONG   nBFrames /*IN*/, BOOL   bIsInterleaved /*IN*/, ULONG   nSlices /*IN*/, ULONG   nLayers /*IN*/, ULONG   nSceneCut /*IN*/, BOOL   bMultiThread /*IN*/, BOOL   bMBBRC /*IN*/, BOOL   bExtBRC /*IN*/, ULONG   nMinQP /*IN*/, ULONG   nMaxQP /*IN*/, ULONG   nVBVMaxRate /*IN*/, ULONG   nVBVBufSize /*IN*/, ULONG   nCBRVariation /*IN*/, ULONG   nAspectRatioX /*IN*/,  ULONG   nAspectRatioY /*IN*/,  ULONG   nScaleStyle /*IN*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_FILE_TRANSCODER(PVOID pFileTranscoder /*IN*/, CHAR * pszDstFileName /*IN*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_FILE_TRANSCODER(PVOID pFileTranscoder /*IN*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_FILE_TRANSCODER_CALLBACK(PVOID pFileTranscoder /*IN*/, PF_FILE_TRANSCODER_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/);

#ifdef __cplusplus
}
#endif

#endif // MOCK_QCAP_PLAYBACK_H
