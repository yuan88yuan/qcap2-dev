#ifndef QCAP_ONVIF_H
#define QCAP_ONVIF_H

#include "qcap.broadcast.h"

#ifdef __cplusplus
extern "C"
{
#endif

// ##########################################################################################################################################################################################
// #
// # ONVIF COMMUNICATION FUNCTIONS (SERVER/EMULATOR/CLIENT)
// #
// ##########################################################################################################################################################################################
//
// COMMUNICATION SERVER FUNCTIONS ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
typedef QRETURN (QCAP_EXPORT *PF_COMMUNICATION_SERVER_GET_CUSTOM_PROPERTY_CALLBACK)( PVOID pServer /*IN*/, CHAR * pszProperty /*IN*/, CHAR * pszValue /*OUT*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_COMMUNICATION_SERVER_SET_CUSTOM_PROPERTY_CALLBACK)( PVOID pServer /*IN*/, CHAR * pszProperty /*IN*/, CHAR * pszValue /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_COMMUNICATION_SERVER_PROFILE_VIDEO_SETUP_CALLBACK)( PVOID pServer /*IN*/, UINT iProNum /*IN*/, ULONG nEncoderFormat /*IN*/, ULONG nWidth /*IN*/, ULONG nHeight /*IN*/, ULONG nFrameRate /*IN*/, ULONG nRecordMode /*IN*/, ULONG nQuality /*IN*/, ULONG nBitRate /*IN*/, ULONG nGOP /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_COMMUNICATION_SERVER_PROFILE_AUDIO_SETUP_CALLBACK)( PVOID pServer /*IN*/, UINT iProNum /*IN*/, ULONG nEncoderFormat /*IN*/, ULONG nChannels /*IN*/, ULONG nBitsPerSample /*IN*/, ULONG nSampleFrequency /*IN*/, ULONG nBitRate /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_COMMUNICATION_SERVER_PTZ_SET_HOME_CALLBACK)( PVOID pServer /*IN*/, UINT iProNum /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_COMMUNICATION_SERVER_PTZ_SET_PRESET_CALLBACK)( PVOID pServer /*IN*/, UINT iProNum /*IN*/, UINT iPresetNum /*IN*/, CHAR * pszPresetTokenName /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_COMMUNICATION_SERVER_PTZ_SET_TOUR_CALLBACK)( PVOID pServer /*IN*/, UINT iProNum /*IN*/, UINT iTourNum /*IN*/, CHAR * pszTourTokenName /*IN*/, UINT * pPresetArray /*IN*/, double * pPresetPanSpeedArray /*IN*/, double * pPresetTiltSpeedArray /*IN*/, double * pPresetZoomSpeedArray /*IN*/, ULONG nPresetArraySize /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_COMMUNICATION_SERVER_PTZ_GOTO_HOME_CALLBACK)( PVOID pServer /*IN*/, UINT iProNum /*IN*/, double dPanSpeed /*IN*/, double dTiltSpeed /*IN*/, double dZoomSpeed /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_COMMUNICATION_SERVER_PTZ_GOTO_PRESET_CALLBACK)( PVOID pServer /*IN*/, UINT iProNum /*IN*/, UINT iPresetNum /*IN*/, double dPanSpeed /*IN*/, double dTiltSpeed /*IN*/, double dZoomSpeed /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_COMMUNICATION_SERVER_PTZ_GOTO_TOUR_CALLBACK)( PVOID pServer /*IN*/, UINT iProNum /*IN*/, UINT iTourNum /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_COMMUNICATION_SERVER_PTZ_MOVE_CONTINUOUS_CALLBACK)( PVOID pServer /*IN*/, UINT iProNum /*IN*/, double dPanSpeed /*IN*/, double dTiltSpeed /*IN*/, double dZoomSpeed /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_COMMUNICATION_SERVER_PTZ_MOVE_RELATIVE_CALLBACK)( PVOID pServer /*IN*/, UINT iProNum /*IN*/, double dPan /*IN*/, double dTilt /*IN*/, double dZoom /*IN*/, double dPanSpeed /*IN*/, double dTiltSpeed /*IN*/, double dZoomSpeed /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_COMMUNICATION_SERVER_PTZ_MOVE_ABSOLUTE_CALLBACK)( PVOID pServer /*IN*/, UINT iProNum /*IN*/, double dPan /*IN*/, double dTilt /*IN*/, double dZoom /*IN*/, double dPanSpeed /*IN*/, double dTiltSpeed /*IN*/, double dZoomSpeed /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_COMMUNICATION_SERVER_PTZ_MOVE_STOP_CALLBACK)( PVOID pServer /*IN*/, UINT iProNum /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_COMMUNICATION_ONVIF_SERVER( ULONG nTotalVideoSources /*IN*/, ULONG nTotalAudioSources /*IN*/, ULONG nTotalVideoEncoders /*IN*/, ULONG nTotalAudioEncoders /*IN*/, ULONG nTotalProfiles /*IN*/, PVOID * ppServer /*OUT*/, CHAR * pszName DEFVAL( NULL /*IN*/), CHAR * pszLocation DEFVAL( NULL /*IN*/), CHAR * pszManufacturer DEFVAL( NULL /*IN*/), CHAR * pszModel DEFVAL( NULL /*IN*/), CHAR * pszHardwareVersion DEFVAL( NULL /*IN*/), CHAR * pszFirmwareVersion DEFVAL( NULL /*IN*/), CHAR * pszDeviceID DEFVAL( NULL /*IN*/), CHAR * pszRootAccount DEFVAL( NULL /*IN*/), CHAR * pszRootPassword DEFVAL( NULL /*IN*/), CHAR * pszNetworkAdapterIP DEFVAL( NULL /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_COMMUNICATION_SERVER( PVOID pServer /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_COMMUNICATION_SERVER( PVOID pServer /*IN*/, ULONG nNetworkPort DEFVAL( 8001 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_COMMUNICATION_SERVER( PVOID pServer /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_SERVER_VIDEO_SOURCE( PVOID pServer /*IN*/, UINT iVidSrcNum /*IN*/, ULONG * pWidth /*OUT*/, ULONG * pHeight /*OUT*/, ULONG * pFrameRate /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_COMMUNICATION_SERVER_VIDEO_SOURCE( PVOID pServer /*IN*/, UINT iVidSrcNum /*IN*/, ULONG   nWidth /*IN*/,  ULONG   nHeight /*IN*/,  ULONG   nFrameRate /*IN*/  );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_SERVER_AUDIO_SOURCE( PVOID pServer /*IN*/, UINT iAudSrcNum /*IN*/, ULONG * pChannels /*OUT*/, ULONG * pBitsPerSample /*OUT*/, ULONG * pSampleFrequency /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_COMMUNICATION_SERVER_AUDIO_SOURCE( PVOID pServer /*IN*/, UINT iAudSrcNum /*IN*/, ULONG   nChannels /*IN*/,  ULONG   nBitsPerSample /*IN*/,  ULONG   nSampleFrequency /*IN*/  );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_SERVER_VIDEO_ENCODER( PVOID pServer /*IN*/, UINT iVidEncNum /*IN*/, ULONG * pEncoderFormat /*OUT*/, ULONG * pWidth /*OUT*/, ULONG * pHeight /*OUT*/, ULONG * pFrameRate_Min /*OUT*/, ULONG * pFrameRate_Max /*OUT*/, ULONG * pFrameRate_Default /*OUT*/, ULONG * pRecordMode_Min /*OUT*/, ULONG * pRecordMode_Max /*OUT*/, ULONG * pRecordMode_Default /*OUT*/, ULONG * pQuality_Min /*OUT*/, ULONG * pQuality_Max /*OUT*/, ULONG * pQuality_Default /*OUT*/, ULONG * pBitRate_Min /*OUT*/, ULONG * pBitRate_Max /*OUT*/, ULONG * pBitRate_Default /*OUT*/, ULONG * pGOP_Min /*OUT*/, ULONG * pGOP_Max /*OUT*/, ULONG * pGOP_Default /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_COMMUNICATION_SERVER_VIDEO_ENCODER( PVOID pServer /*IN*/, UINT iVidEncNum /*IN*/, ULONG   nEncoderFormat /*IN*/,  ULONG   nWidth /*IN*/,  ULONG   nHeight /*IN*/,  ULONG   nFrameRate_Min /*IN*/,  ULONG   nFrameRate_Max /*IN*/,  ULONG   nFrameRate_Default /*IN*/,  ULONG   nRecordMode_Min /*IN*/,  ULONG   nRecordMode_Max /*IN*/,  ULONG   nRecordMode_Default /*IN*/,  ULONG   nQuality_Min /*IN*/,  ULONG   nQuality_Max /*IN*/,  ULONG   nQuality_Default /*IN*/,  ULONG   nBitRate_Min /*IN*/,  ULONG   nBitRate_Max /*IN*/,  ULONG   nBitRate_Default /*IN*/,  ULONG   nGOP_Min /*IN*/,  ULONG   nGOP_Max /*IN*/,  ULONG   nGOP_Default /*IN*/  );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_SERVER_AUDIO_ENCODER( PVOID pServer /*IN*/, UINT iAudEncNum /*IN*/, ULONG * pEncoderFormat /*OUT*/, ULONG * pChannels /*OUT*/, ULONG * pBitsPerSample /*OUT*/, ULONG * pSampleFrequency /*OUT*/, ULONG * pBitRate_Min /*OUT*/, ULONG * pBitRate_Max /*OUT*/, ULONG * pBitRate_Default /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_COMMUNICATION_SERVER_AUDIO_ENCODER( PVOID pServer /*IN*/, UINT iAudEncNum /*IN*/, ULONG   nEncoderFormat /*IN*/,  ULONG   nChannels /*IN*/,  ULONG   nBitsPerSample /*IN*/,  ULONG   nSampleFrequency /*IN*/,  ULONG   nBitRate_Min /*IN*/,  ULONG   nBitRate_Max /*IN*/,  ULONG   nBitRate_Default /*IN*/  );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_SERVER_AUDIO_DECODER( PVOID pServer /*IN*/, UINT iAudDecNum /*IN*/, ULONG * pDecoderFormat /*OUT*/, ULONG * pChannels /*OUT*/, ULONG * pBitsPerSample /*OUT*/, ULONG * pSampleFrequency /*OUT*/, ULONG * pBitRate_Min /*OUT*/, ULONG * pBitRate_Max /*OUT*/, ULONG * pBitRate_Default /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_COMMUNICATION_SERVER_AUDIO_DECODER( PVOID pServer /*IN*/, UINT iAudDecNum /*IN*/, ULONG   nDecoderFormat /*IN*/,  ULONG   nChannels /*IN*/,  ULONG   nBitsPerSample /*IN*/,  ULONG   nSampleFrequency /*IN*/,  ULONG   nBitRate_Min /*IN*/,  ULONG   nBitRate_Max /*IN*/,  ULONG   nBitRate_Default /*IN*/  );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_SERVER_PROFILE( PVOID pServer /*IN*/, UINT iProNum /*IN*/, CHAR * * ppszURL /*OUT*/, UINT * pVidSrcNum /*OUT*/, UINT * pAudSrcNum /*OUT*/, UINT * pVidEncNum /*OUT*/, UINT * pAudEncNum /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_COMMUNICATION_SERVER_PROFILE( PVOID pServer /*IN*/, UINT iProNum /*IN*/, CHAR *   pszURL /*IN*/,   UINT   iVidSrcNum /*IN*/,  UINT   iAudSrcNum /*IN*/,  UINT   iVidEncNum /*IN*/,  UINT   iAudEncNum /*IN*/  );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_SERVER_PTZ( PVOID pServer /*IN*/, UINT iProNum /*IN*/, double * pPanRange_Min /*OUT*/, double * pPanRange_Max /*OUT*/, double * pTiltRange_Min /*OUT*/, double * pTiltRange_Max /*OUT*/, double * pZoomRange_Min /*OUT*/, double * pZoomRange_Max /*OUT*/, double * pPanTiltSpeed_Min /*OUT*/, double * pPanTiltSpeed_Max /*OUT*/, double * pPanTiltSpeed_Default /*OUT*/, double * pZoomSpeed_Min /*OUT*/, double * pZoomSpeed_Max /*OUT*/, double * pZoomSpeed_Default /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_COMMUNICATION_SERVER_PTZ( PVOID pServer /*IN*/, UINT iProNum /*IN*/, double   dPanRange_Min /*IN*/,  double   dPanRange_Max /*IN*/,  double   dTiltRange_Min /*IN*/,  double   dTiltRange_Max /*IN*/,  double   dZoomRange_Min /*IN*/,  double   dZoomRange_Max /*IN*/,  double   dPanTiltSpeed_Min /*IN*/,  double   dPanTiltSpeed_Max /*IN*/,  double   dPanTiltSpeed_Default /*IN*/,  double   dZoomSpeed_Min /*IN*/,  double   dZoomSpeed_Max /*IN*/,  double   dZoomSpeed_Default /*IN*/  );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_LOAD_COMMUNICATION_SERVER_PTZ_LOCAL_PRESET( PVOID pServer /*IN*/, UINT iProNum /*IN*/, UINT iPresetNum /*IN*/, CHAR * pszPresetTokenName /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_LOAD_COMMUNICATION_SERVER_PTZ_LOCAL_TOUR( PVOID pServer /*IN*/, UINT iProNum /*IN*/, UINT iTourNum /*IN*/, CHAR * pszTourTokenName /*IN*/, UINT * pPresetArray /*IN*/, double * pPresetPanSpeedArray /*IN*/, double * pPresetTiltSpeedArray /*IN*/, double * pArrayPresetZoomArray /*IN*/, ULONG nPresetArraySize /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_COMMUNICATION_SERVER_GET_CUSTOM_PROPERTY_CALLBACK( PVOID pServer /*IN*/, PF_COMMUNICATION_SERVER_GET_CUSTOM_PROPERTY_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_COMMUNICATION_SERVER_SET_CUSTOM_PROPERTY_CALLBACK( PVOID pServer /*IN*/, PF_COMMUNICATION_SERVER_SET_CUSTOM_PROPERTY_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_COMMUNICATION_SERVER_PROFILE_VIDEO_SETUP_CALLBACK( PVOID pServer /*IN*/, PF_COMMUNICATION_SERVER_PROFILE_VIDEO_SETUP_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_COMMUNICATION_SERVER_PROFILE_AUDIO_SETUP_CALLBACK( PVOID pServer /*IN*/, PF_COMMUNICATION_SERVER_PROFILE_AUDIO_SETUP_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_COMMUNICATION_SERVER_PTZ_SET_HOME_CALLBACK( PVOID pServer /*IN*/, PF_COMMUNICATION_SERVER_PTZ_SET_HOME_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_COMMUNICATION_SERVER_PTZ_SET_PRESET_CALLBACK( PVOID pServer /*IN*/, PF_COMMUNICATION_SERVER_PTZ_SET_PRESET_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_COMMUNICATION_SERVER_PTZ_SET_TOUR_CALLBACK( PVOID pServer /*IN*/, PF_COMMUNICATION_SERVER_PTZ_SET_TOUR_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_COMMUNICATION_SERVER_PTZ_GOTO_HOME_CALLBACK( PVOID pServer /*IN*/, PF_COMMUNICATION_SERVER_PTZ_GOTO_HOME_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_COMMUNICATION_SERVER_PTZ_GOTO_PRESET_CALLBACK( PVOID pServer /*IN*/, PF_COMMUNICATION_SERVER_PTZ_GOTO_PRESET_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_COMMUNICATION_SERVER_PTZ_GOTO_TOUR_CALLBACK( PVOID pServer /*IN*/, PF_COMMUNICATION_SERVER_PTZ_GOTO_TOUR_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_COMMUNICATION_SERVER_PTZ_MOVE_CONTINUOUS_CALLBACK( PVOID pServer /*IN*/, PF_COMMUNICATION_SERVER_PTZ_MOVE_CONTINUOUS_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_COMMUNICATION_SERVER_PTZ_MOVE_RELATIVE_CALLBACK( PVOID pServer /*IN*/, PF_COMMUNICATION_SERVER_PTZ_MOVE_RELATIVE_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_COMMUNICATION_SERVER_PTZ_MOVE_ABSOLUTE_CALLBACK( PVOID pServer /*IN*/, PF_COMMUNICATION_SERVER_PTZ_MOVE_ABSOLUTE_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_COMMUNICATION_SERVER_PTZ_MOVE_STOP_CALLBACK( PVOID pServer /*IN*/, PF_COMMUNICATION_SERVER_PTZ_MOVE_STOP_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

// COMMUNICATION EMULATOR FUNCTIONS /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
typedef QRETURN (QCAP_EXPORT *PF_COMMUNICATION_EMULATOR_SCAN_DONE_CALLBACK)( PVOID pEmulator /*IN*/, ULONG nTotalServers /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_COMMUNICATION_ONVIF_EMULATOR( PVOID * ppEmulator /*OUT*/, ULONG nEmulatorPort DEFVAL( 3702 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_COMMUNICATION_EMULATOR( PVOID pEmulator /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_COMMUNICATION_EMULATOR( PVOID pEmulator /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_COMMUNICATION_EMULATOR( PVOID pEmulator /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_EMULATOR_SERVER_INFO( PVOID pEmulator /*IN*/, UINT iSvrNum /*IN*/, CHAR * * ppszNetworkIP /*OUT*/, ULONG * pNetworkPort /*OUT*/, CHAR * * ppszNetworkURL /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_COMMUNICATION_EMULATOR_SCAN_DONE_CALLBACK( PVOID pEmulator /*IN*/, PF_COMMUNICATION_EMULATOR_SCAN_DONE_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

// COMMUNICATION CLIENT FUNCTIONS ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
typedef QRETURN (QCAP_EXPORT *PF_COMMUNICATION_CLIENT_CONNECTED_CALLBACK)( PVOID pClient /*IN*/, ULONG nTotalVideoSources /*IN*/, ULONG nTotalAudioSources /*IN*/, ULONG nTotalVideoEncoders /*IN*/, ULONG nTotalAudioEncoders /*IN*/, ULONG nTotalProfiles /*IN*/, DWORD dwServiceTypes /*IN*/, CHAR * pszName /*IN*/, CHAR * pszLocationr /*IN*/, CHAR * pszManufacturer /*IN*/, CHAR * pszModel /*IN*/, CHAR * pszHardwareVersion /*IN*/, CHAR * pszFirmwareVersion /*IN*/, CHAR * pszDeviceID /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_COMMUNICATION_ONVIF_CLIENT( CHAR * pszNetworkURL /*IN*/, PVOID * ppClient /*OUT*/, CHAR * pszAccount DEFVAL( NULL /*IN*/ /*DEFAULT = root*/), CHAR * pszPassword DEFVAL( NULL /*IN*/ /*DEFAULT = root*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_COMMUNICATION_CLIENT( PVOID pClient /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_COMMUNICATION_CLIENT( PVOID pClient /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_COMMUNICATION_CLIENT( PVOID pClient /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_CLIENT_VIDEO_SOURCE_INFO( PVOID pClient /*IN*/, UINT iVidSrcNum /*IN*/, ULONG * pWidth /*OUT*/, ULONG * pHeight /*OUT*/, ULONG * pFrameRate /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_CLIENT_AUDIO_SOURCE_INFO( PVOID pClient /*IN*/, UINT iAudSrcNum /*IN*/, ULONG * pChannels /*OUT*/, ULONG * pBitsPerSample /*OUT*/, ULONG * pSampleFrequency /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_CLIENT_VIDEO_ENCODER_INFO( PVOID pClient /*IN*/, UINT iVidEncNum /*IN*/, ULONG * pTotalVidEncOptions /*OUT*/, UINT * pVidEncOptionNum_Default /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_CLIENT_AUDIO_ENCODER_INFO( PVOID pClient /*IN*/, UINT iAudEncNum /*IN*/, ULONG * pTotalAudEncOptions /*OUT*/, UINT * pAudEncOptionNum_Default /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_CLIENT_VIDEO_ENCODER_OPTION_INFO( PVOID pClient /*IN*/, UINT iVidEncNum /*IN*/, UINT iVidEncOptionNum /*IN*/, ULONG * pEncoderFormat /*OUT*/, ULONG * pWidthList /*OUT*/, ULONG * pWidthListSize /*OUT*/, ULONG * pWidth_Default /*OUT*/, ULONG * pHeightList /*OUT*/, ULONG * pHeightListSize /*OUT*/, ULONG * pHeight_Default /*OUT*/, ULONG * pFrameRate_Min /*OUT*/, ULONG * pFrameRate_Max /*OUT*/, ULONG * pFrameRate_Default /*OUT*/, ULONG * pRecordMode_Min /*OUT*/, ULONG * pRecordMode_Max /*OUT*/, ULONG * pRecordMode_Default /*OUT*/, ULONG * pQuality_Min /*OUT*/, ULONG * pQuality_Max /*OUT*/, ULONG * pQuality_Default /*OUT*/, ULONG * pBitRate_Min /*OUT*/, ULONG * pBitRate_Max /*OUT*/, ULONG * pBitRate_Default /*OUT*/, ULONG * pGOP_Min /*OUT*/, ULONG * pGOP_Max /*OUT*/, ULONG * pGOP_Default /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_CLIENT_AUDIO_ENCODER_OPTION_INFO( PVOID pClient /*IN*/, UINT iAudEncNum /*IN*/, UINT iAudEncOptionNum /*IN*/, ULONG * pEncoderFormat /*OUT*/, ULONG * pChannelsList /*OUT*/, ULONG * pChannelsListSize /*OUT*/, ULONG * pChannels_Default /*OUT*/, ULONG * pBitsPerSampleList /*OUT*/, ULONG * pBitsPerSampleListSize /*OUT*/, ULONG * pBitsPerSample_Default /*OUT*/, ULONG * pSampleFrequencyList /*OUT*/, ULONG * pSampleFrequencyListSize /*OUT*/, ULONG * pSampleFrequency_Default /*OUT*/, ULONG * pBitRate_Min /*OUT*/, ULONG * pBitRate_Max /*OUT*/, ULONG * pBitRate_Default /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_CLIENT_PROFILE_INFO( PVOID pClient /*IN*/, UINT iProNum /*IN*/, CHAR * * ppszURL /*OUT*/, UINT * pVidSrcNum /*OUT*/, UINT * pAudSrcNum /*OUT*/, UINT * pVidEncNum /*OUT*/, UINT * pAudEncNum /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_CLIENT_PROFILE_VIDEO_PROPERTY( PVOID pClient /*IN*/, UINT iProNum /*IN*/, ULONG * pEncoderFormat /*OUT*/, ULONG * pWidth /*OUT*/, ULONG * pHeight /*OUT*/, ULONG * pFrameRate /*OUT*/, ULONG * pRecordMode /*OUT*/, ULONG * pQuality /*OUT*/, ULONG * pBitRate /*OUT*/, ULONG * pGOP /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_COMMUNICATION_CLIENT_PROFILE_VIDEO_PROPERTY( PVOID pClient /*IN*/, UINT iProNum /*IN*/, ULONG   nEncoderFormat /*IN*/,  ULONG   nWidth /*IN*/,  ULONG   nHeight /*IN*/,  ULONG   nFrameRate /*IN*/,  ULONG   nRecordMode /*IN*/,  ULONG   nQuality /*IN*/,  ULONG   nBitRate /*IN*/,  ULONG   nGOP /*IN*/  );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_CLIENT_PROFILE_AUDIO_PROPERTY( PVOID pClient /*IN*/, UINT iProNum /*IN*/, ULONG * pEncoderFormat /*OUT*/, ULONG * pChannels /*OUT*/, ULONG * pBitsPerSample /*OUT*/, ULONG * pSampleFrequency /*OUT*/, ULONG * pBitRate /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_COMMUNICATION_CLIENT_PROFILE_AUDIO_PROPERTY( PVOID pClient /*IN*/, UINT iProNum /*IN*/, ULONG   nEncoderFormat /*IN*/,  ULONG   nChannels /*IN*/,  ULONG   nBitsPerSample /*IN*/,  ULONG   nSampleFrequency /*IN*/,  ULONG   nBitRate /*IN*/  );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_CLIENT_PTZ_INFO( PVOID pClient /*IN*/, UINT iProNum /*IN*/, ULONG * pTotalPresets /*OUT*/, ULONG * pTotalTours /*OUT*/, double * pPanRange_Min /*OUT*/, double * pPanRange_Max /*OUT*/, double * pTiltRange_Min /*OUT*/, double * pTiltRange_Max /*OUT*/, double * pZoomRange_Min /*OUT*/, double * pZoomRange_Max /*OUT*/, double * pPanSpeed_Min /*OUT*/, double * pPanSpeed_Max /*OUT*/, double * pPanSpeed_Default /*OUT*/, double * pTiltSpeed_Min /*OUT*/, double * pTiltSpeed_Max /*OUT*/, double * pTiltSpeed_Default /*OUT*/, double * pZoomSpeed_Min /*OUT*/, double * pZoomSpeed_Max /*OUT*/, double * pZoomSpeed_Default /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_COMMUNICATION_CLIENT_PTZ_HOME( PVOID pClient /*IN*/, UINT iProNum /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_CLIENT_PTZ_PRESET( PVOID pClient /*IN*/, UINT iProNum /*IN*/, UINT iPresetNum /*IN*/, CHAR * pszPresetTokenName /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_COMMUNICATION_CLIENT_PTZ_PRESET( PVOID pClient /*IN*/, UINT iProNum /*IN*/, UINT iPresetNum /*IN*/, CHAR * pszPresetTokenName /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_CLIENT_PTZ_TOUR( PVOID pClient /*IN*/, UINT iProNum /*IN*/, UINT iTourNum /*IN*/, CHAR * pszTourTokenName /*OUT*/, UINT * pPresetArray /*OUT*/, double * pPresetPanSpeedArray /*OUT*/, double * pPresetTiltSpeedArray /*OUT*/, double * pPresetZoomSpeedArray /*OUT*/, ULONG * pPresetArraySize /*IN/OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_COMMUNICATION_CLIENT_PTZ_TOUR( PVOID pClient /*IN*/, UINT iProNum /*IN*/, UINT iTourNum /*IN*/, CHAR * pszTourTokenName /*IN*/, UINT * pPresetArray /*IN*/, double * pPresetPanSpeedArray /*IN*/, double * pPresetTiltSpeedArray /*IN*/, double * pPresetZoomSpeedArray /*IN*/, ULONG nPresetArraySize /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GOTO_COMMUNICATION_CLIENT_PTZ_HOME( PVOID pClient /*IN*/, UINT iProNum /*IN*/, double dPanSpeed /*IN*/, double dTiltSpeed /*IN*/, double dZoomSpeed /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GOTO_COMMUNICATION_CLIENT_PTZ_PRESET( PVOID pClient /*IN*/, UINT iProNum /*IN*/, UINT iPresetNum /*IN*/, double dPanSpeed /*IN*/, double dTiltSpeed /*IN*/, double dZoomSpeed /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GOTO_COMMUNICATION_CLIENT_PTZ_TOUR( PVOID pClient /*IN*/, UINT iProNum /*IN*/, UINT iTourNum /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_MOVE_COMMUNICATION_CLIENT_PTZ_CONTINUOUS( PVOID pClient /*IN*/, UINT iProNum /*IN*/, double dPanSpeed /*IN*/, double dTiltSpeed /*IN*/, double dZoomSpeed /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_MOVE_COMMUNICATION_CLIENT_PTZ_RELATIVE( PVOID pClient /*IN*/, UINT iProNum /*IN*/, double dPan /*IN*/, double dTilt /*IN*/, double dZoom /*IN*/, double dPanSpeed /*IN*/, double dTiltSpeed /*IN*/, double dZoomSpeed /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_MOVE_COMMUNICATION_CLIENT_PTZ_ABSOLUTE( PVOID pClient /*IN*/, UINT iProNum /*IN*/, double dPan /*IN*/, double dTilt /*IN*/, double dZoom /*IN*/, double dPanSpeed /*IN*/, double dTiltSpeed /*IN*/, double dZoomSpeed /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_MOVE_COMMUNICATION_CLIENT_PTZ_STOP( PVOID pClient /*IN*/, UINT iProNum /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_CLIENT_CUSTOM_PROPERTY( PVOID pClient /*IN*/, CHAR * pszProperty /*IN*/, CHAR * * ppszValue /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_COMMUNICATION_CLIENT_CUSTOM_PROPERTY( PVOID pClient /*IN*/, CHAR * pszProperty /*IN*/, CHAR * pszValue /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_COMMUNICATION_CLIENT_CONNECTED_CALLBACK( PVOID pClient /*IN*/, PF_COMMUNICATION_CLIENT_CONNECTED_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );


#ifdef __cplusplus
}
#endif

#endif // QCAP_ONVIF_H
