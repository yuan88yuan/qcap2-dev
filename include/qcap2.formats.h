#ifndef __QCAP2_FORMATS_H__
#define __QCAP2_FORMATS_H__

#include "qcap2.types.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

// qcap2_input_format_t
qcap2_input_format_t* qcap2_input_format_new();
void qcap2_input_format_delete(qcap2_input_format_t* pThis);

// qcap2_video_format_t
qcap2_video_format_t* qcap2_video_format_new();
void qcap2_video_format_delete(qcap2_video_format_t* pThis);
void qcap2_video_format_get_property(qcap2_video_format_t* pThis, ULONG * pColorSpaceType, ULONG * pVideoWidth, ULONG * pVideoHeight, BOOL * pVideoIsInterleaved, double * pVideoFrameRate);
void qcap2_video_format_set_property(qcap2_video_format_t* pThis, ULONG nColorSpaceType, ULONG nVideoWidth, ULONG nVideoHeight, BOOL bVideoIsInterleaved, double dVideoFrameRate);
void qcap2_video_format_get_input(qcap2_video_format_t* pThis, ULONG * pInput);
void qcap2_video_format_set_input(qcap2_video_format_t* pThis, ULONG nInput);

// qcap2_audio_format_t
qcap2_audio_format_t* qcap2_audio_format_new();
void qcap2_audio_format_delete(qcap2_audio_format_t* pThis);
void qcap2_audio_format_get_property(qcap2_audio_format_t* pThis, ULONG * pAudioChannels, ULONG * pAudioBitsPerSample, ULONG * pAudioSampleFrequency);
void qcap2_audio_format_set_property(qcap2_audio_format_t* pThis, ULONG   nAudioChannels, ULONG   nAudioBitsPerSample, ULONG   nAudioSampleFrequency);
void qcap2_audio_format_get_input(qcap2_audio_format_t* pThis, ULONG * pInput);
void qcap2_audio_format_set_input(qcap2_audio_format_t* pThis, ULONG nInput);

// qcap2_video_encoder_property_t
qcap2_video_encoder_property_t* qcap2_video_encoder_property_new();
void qcap2_video_encoder_property_delete(qcap2_video_encoder_property_t* pThis);
void qcap2_video_encoder_property_get_property(qcap2_video_encoder_property_t* pThis, ULONG * pEncoderType, ULONG * pEncoderFormat, ULONG * pColorSpaceType, ULONG * pWidth, ULONG * pHeight, double * pFrameRate, ULONG * pRecordMode, ULONG * pQuality, ULONG * pBitRate, ULONG * pGOP, ULONG * pAspectRatioX, ULONG * pAspectRatioY);
void qcap2_video_encoder_property_set_property(qcap2_video_encoder_property_t* pThis, ULONG   nEncoderType, ULONG   nEncoderFormat, ULONG   nColorSpaceType, ULONG   nWidth, ULONG   nHeight, double   dFrameRate, ULONG   nRecordMode, ULONG   nQuality, ULONG   nBitRate, ULONG   nGOP, ULONG   nAspectRatioX, ULONG   nAspectRatioY);
void qcap2_video_encoder_property_get_property1(qcap2_video_encoder_property_t* pThis, UINT* pGpuNum, ULONG * pEncoderType, ULONG * pEncoderFormat, ULONG * pColorSpaceType, ULONG * pWidth, ULONG * pHeight, double * pFrameRate, ULONG * pRecordProfile, ULONG * pRecordLevel, ULONG * pRecordEntropy, ULONG * pRecordComplexity, ULONG * pRecordMode, ULONG * pQuality, ULONG * pBitRate, ULONG * pGOP, ULONG * pBFrames, BOOL * pIsInterleaved, ULONG * pSlices, ULONG * pLayers, ULONG * pSceneCut, BOOL * pMultiThread, BOOL * pMBBRC, BOOL * pExtBRC, ULONG * pMinQP, ULONG * pMaxQP, ULONG * pVBVMaxRate, ULONG * pVBVBufSize, ULONG * pAspectRatioX, ULONG * pAspectRatioY);
void qcap2_video_encoder_property_set_property1(qcap2_video_encoder_property_t* pThis, UINT nGpuNum, ULONG   nEncoderType, ULONG   nEncoderFormat, ULONG   nColorSpaceType, ULONG   nWidth, ULONG   nHeight, double   dFrameRate, ULONG   nRecordProfile , ULONG   nRecordLevel, ULONG   nRecordEntropy, ULONG   nRecordComplexity, ULONG   nRecordMode, ULONG   nQuality, ULONG   nBitRate, ULONG   nGOP, ULONG   nBFrames, BOOL   bIsInterleaved, ULONG   nSlices, ULONG   nLayers, ULONG   nSceneCut, BOOL   bMultiThread, BOOL   bMBBRC, BOOL   bExtBRC, ULONG   nMinQP , ULONG   nMaxQP, ULONG   nVBVMaxRate , ULONG   nVBVBufSize, ULONG   nAspectRatioX, ULONG   nAspectRatioY);
void qcap2_video_encoder_property_get_type(qcap2_video_encoder_property_t* pThis, ULONG * pEncoderType);
void qcap2_video_encoder_property_set_type(qcap2_video_encoder_property_t* pThis, ULONG   nEncoderType);
void qcap2_video_encoder_property_get_format(qcap2_video_encoder_property_t* pThis, ULONG * pEncoderFormat);
void qcap2_video_encoder_property_set_format(qcap2_video_encoder_property_t* pThis, ULONG   nEncoderFormat);
void qcap2_video_encoder_property_get_resolution(qcap2_video_encoder_property_t* pThis, ULONG * pWidth, ULONG * pHeight);
void qcap2_video_encoder_property_set_resolution(qcap2_video_encoder_property_t* pThis, ULONG   nWidth, ULONG   nHeight);
void qcap2_video_encoder_property_get_bitrate(qcap2_video_encoder_property_t* pThis, ULONG * pBitRate);
void qcap2_video_encoder_property_set_bitrate(qcap2_video_encoder_property_t* pThis, ULONG   nBitRate);
void qcap2_video_encoder_property_set_cbr_variation(qcap2_video_encoder_property_t* pThis, ULONG nCBRVariation);
void qcap2_video_encoder_property_get_cbr_variation(qcap2_video_encoder_property_t* pThis, ULONG* pCBRVariation);
void qcap2_video_encoder_property_set_color_range(qcap2_video_encoder_property_t* pThis, ULONG nColorRange);
void qcap2_video_encoder_property_get_color_range(qcap2_video_encoder_property_t* pThis, ULONG* pColorRange);
void qcap2_video_encoder_property_set_source_frame_rate(qcap2_video_encoder_property_t* pThis, double dSourceFrameRate);
void qcap2_video_encoder_property_get_source_frame_rate(qcap2_video_encoder_property_t* pThis, double* pSourceFrameRate);
void qcap2_video_encoder_property_set_rotation(qcap2_video_encoder_property_t* pThis, ULONG nRotation);
void qcap2_video_encoder_property_get_rotation(qcap2_video_encoder_property_t* pThis, ULONG* pRotation);
void qcap2_video_encoder_property_set_ideal_timestamp(qcap2_video_encoder_property_t* pThis, BOOL bIdealTimestamp);
void qcap2_video_encoder_property_get_ideal_timestamp(qcap2_video_encoder_property_t* pThis, BOOL* pIdealTimestamp);
void qcap2_video_encoder_property_set_encoder_osd(qcap2_video_encoder_property_t* pThis, BOOL bEncoderOSD);
void qcap2_video_encoder_property_get_encoder_osd(qcap2_video_encoder_property_t* pThis, BOOL* pEncoderOSD);
void qcap2_video_encoder_property_set_fixed_function(qcap2_video_encoder_property_t* pThis, BOOL bEnableFF);
void qcap2_video_encoder_property_get_fixed_function(qcap2_video_encoder_property_t* pThis, BOOL* pEnableFF);
void qcap2_video_encoder_property_set_low_delay(qcap2_video_encoder_property_t* pThis, BOOL bEnableLowDelay);
void qcap2_video_encoder_property_get_low_delay(qcap2_video_encoder_property_t* pThis, BOOL* pEnableLowDelay);
void qcap2_video_encoder_property_set_rtmp_compat(qcap2_video_encoder_property_t* pThis, BOOL bEnableRTMPCompatible);
void qcap2_video_encoder_property_get_rtmp_compat(qcap2_video_encoder_property_t* pThis, BOOL* pEnableRTMPCompatible);
void qcap2_video_encoder_property_set_time_scale_factor(qcap2_video_encoder_property_t* pThis, ULONG nTimeScaleFactor);
void qcap2_video_encoder_property_get_time_scale_factor(qcap2_video_encoder_property_t* pThis, ULONG* pTimeScaleFactor);
void qcap2_video_encoder_property_set_high_perf(qcap2_video_encoder_property_t* pThis, BOOL bEnableHighPerf);
void qcap2_video_encoder_property_get_high_perf(qcap2_video_encoder_property_t* pThis, BOOL* pEnableHighPerf);

// qcap2_audio_encoder_property_t
qcap2_audio_encoder_property_t* qcap2_audio_encoder_property_new();
void qcap2_audio_encoder_property_delete(qcap2_audio_encoder_property_t* pThis);
void qcap2_audio_encoder_property_get_property(qcap2_audio_encoder_property_t* pThis, ULONG * pEncoderType, ULONG * pEncoderFormat, ULONG * pChannels, ULONG * pBitsPerSample, ULONG * pSampleFrequency);
void qcap2_audio_encoder_property_set_property(qcap2_audio_encoder_property_t* pThis, ULONG   nEncoderType, ULONG   nEncoderFormat, ULONG   nChannels, ULONG   nBitsPerSample, ULONG   nSampleFrequency);
void qcap2_audio_encoder_property_get_property1(qcap2_audio_encoder_property_t* pThis, ULONG * pEncoderType, ULONG * pEncoderFormat, ULONG * pChannels, ULONG * pBitsPerSample, ULONG * pSampleFrequency, ULONG * pBitRate);
void qcap2_audio_encoder_property_set_property1(qcap2_audio_encoder_property_t* pThis, ULONG   nEncoderType, ULONG   nEncoderFormat, ULONG   nChannels, ULONG   nBitsPerSample, ULONG   nSampleFrequency, ULONG   nBitRate);
void qcap2_audio_encoder_property_set_ideal_timestamp(qcap2_audio_encoder_property_t* pThis, BOOL bIdealTimestamp);
void qcap2_audio_encoder_property_get_ideal_timestamp(qcap2_audio_encoder_property_t* pThis, BOOL* pIdealTimestamp);

// qcap2_video_encoder_dynamic_property_t
qcap2_video_encoder_dynamic_property_t* qcap2_video_encoder_dynamic_property_new();
void qcap2_video_encoder_dynamic_property_delete(qcap2_video_encoder_dynamic_property_t* pThis);
void qcap2_video_encoder_dynamic_get_property(qcap2_video_encoder_dynamic_property_t* pThis, ULONG * pRecordMode, ULONG * pQuality, ULONG * pBitRate, ULONG * pGOP);
void qcap2_video_encoder_dynamic_set_property(qcap2_video_encoder_dynamic_property_t* pThis, ULONG   nRecordMode, ULONG   nQuality, ULONG   nBitRate, ULONG   nGOP);

// qcap2_media_info_t
qcap2_media_info_t* qcap2_media_info_lock_from(qcap2_rcbuffer_t* pMediaInfo);
int qcap2_media_info_get_video_count(qcap2_media_info_t* pThis);
int qcap2_media_info_get_audio_count(qcap2_media_info_t* pThis);
int qcap2_media_info_get_video_encoder_count(qcap2_media_info_t* pThis);
int qcap2_media_info_get_audio_encoder_count(qcap2_media_info_t* pThis);
qcap2_video_format_t* qcap2_media_info_get_video_format(qcap2_media_info_t* pThis, int nIndex);
qcap2_audio_format_t* qcap2_media_info_get_audio_format(qcap2_media_info_t* pThis, int nIndex);
qcap2_video_encoder_property_t* qcap2_media_info_get_video_encoder_property(qcap2_media_info_t* pThis, int nIndex);
qcap2_audio_encoder_property_t* qcap2_media_info_get_audio_encoder_property(qcap2_media_info_t* pThis, int nIndex);

// qcap2_program_info_t
qcap2_program_info_t* qcap2_program_info_new();
void qcap2_program_info_delete(qcap2_program_info_t* pThis);
int qcap2_program_info_get_id(qcap2_program_info_t* pThis);
void qcap2_program_info_set_id(qcap2_program_info_t* pThis, int nId);
int qcap2_program_info_get_number(qcap2_program_info_t* pThis);
void qcap2_program_info_set_number(qcap2_program_info_t* pThis, int nNumber);
int qcap2_program_info_get_video_source_count(qcap2_program_info_t* pThis);
void qcap2_program_info_set_video_source_count(qcap2_program_info_t* pThis, int nCount);
int qcap2_program_info_get_video_source_index(qcap2_program_info_t* pThis, int nIndex);
void qcap2_program_info_set_video_source_index(qcap2_program_info_t* pThis, int nIndex, int nValue);
int qcap2_program_info_get_audio_source_count(qcap2_program_info_t* pThis);
void qcap2_program_info_set_audio_source_count(qcap2_program_info_t* pThis, int nCount);
int qcap2_program_info_get_audio_source_index(qcap2_program_info_t* pThis, int nIndex);
void qcap2_program_info_set_audio_source_index(qcap2_program_info_t* pThis, int nIndex, int nValue);
int qcap2_program_info_get_video_encoder_count(qcap2_program_info_t* pThis);
void qcap2_program_info_set_video_encoder_count(qcap2_program_info_t* pThis, int nCount);
int qcap2_program_info_get_video_encoder_index(qcap2_program_info_t* pThis, int nIndex);
void qcap2_program_info_set_video_encoder_index(qcap2_program_info_t* pThis, int nIndex, int nValue);
int qcap2_program_info_get_audio_encoder_count(qcap2_program_info_t* pThis);
void qcap2_program_info_set_audio_encoder_count(qcap2_program_info_t* pThis, int nCount);
int qcap2_program_info_get_audio_encoder_index(qcap2_program_info_t* pThis, int nIndex);
void qcap2_program_info_set_audio_encoder_index(qcap2_program_info_t* pThis, int nIndex, int nValue);
int qcap2_program_info_get_video_sink_count(qcap2_program_info_t* pThis);
void qcap2_program_info_set_video_sink_count(qcap2_program_info_t* pThis, int nCount);
int qcap2_program_info_get_video_sink_index(qcap2_program_info_t* pThis, int nIndex);
void qcap2_program_info_set_video_sink_index(qcap2_program_info_t* pThis, int nIndex, int nValue);
int qcap2_program_info_get_audio_sink_count(qcap2_program_info_t* pThis);
void qcap2_program_info_set_audio_sink_count(qcap2_program_info_t* pThis, int nCount);
int qcap2_program_info_get_audio_sink_index(qcap2_program_info_t* pThis, int nIndex);
void qcap2_program_info_set_audio_sink_index(qcap2_program_info_t* pThis, int nIndex, int nValue);
int qcap2_program_info_get_video_decoder_count(qcap2_program_info_t* pThis);
void qcap2_program_info_set_video_decoder_count(qcap2_program_info_t* pThis, int nCount);
int qcap2_program_info_get_video_decoder_index(qcap2_program_info_t* pThis, int nIndex);
void qcap2_program_info_set_video_decoder_index(qcap2_program_info_t* pThis, int nIndex, int nValue);
int qcap2_program_info_get_audio_decoder_count(qcap2_program_info_t* pThis);
void qcap2_program_info_set_audio_decoder_count(qcap2_program_info_t* pThis, int nCount);
int qcap2_program_info_get_audio_decoder_index(qcap2_program_info_t* pThis, int nIndex);
void qcap2_program_info_set_audio_decoder_index(qcap2_program_info_t* pThis, int nIndex, int nValue);
const char* qcap2_program_info_get_metadata(qcap2_program_info_t* pThis, const char* strKey);
void qcap2_program_info_set_metadata(qcap2_program_info_t* pThis, const char* strKey, const char* strValue);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif // __QCAP2_FORMATS_H__
