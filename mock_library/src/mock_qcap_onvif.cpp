#include "mock_qcap_onvif.h"
#include <cstdio> // For fprintf, stderr

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_COMMUNICATION_ONVIF_SERVER(ULONG nTotalVideoSources , ULONG nTotalAudioSources , ULONG nTotalVideoEncoders , ULONG nTotalAudioEncoders , ULONG nTotalProfiles , PVOID * ppServer , CHAR * pszName , CHAR * pszLocation , CHAR * pszManufacturer , CHAR * pszModel , CHAR * pszHardwareVersion , CHAR * pszFirmwareVersion , CHAR * pszDeviceID , CHAR * pszRootAccount , CHAR * pszRootPassword , CHAR * pszNetworkAdapterIP )
{
    (void)nTotalVideoSources;
    (void)nTotalAudioSources;
    (void)nTotalVideoEncoders;
    (void)nTotalAudioEncoders;
    (void)nTotalProfiles;
    (void)ppServer;
    (void)pszName;
    (void)pszLocation;
    (void)pszManufacturer;
    (void)pszModel;
    (void)pszHardwareVersion;
    (void)pszFirmwareVersion;
    (void)pszDeviceID;
    (void)pszRootAccount;
    (void)pszRootPassword;
    (void)pszNetworkAdapterIP;
    fprintf(stderr, "Mock function called: QCAP_CREATE_COMMUNICATION_ONVIF_SERVER(%s)\n", "nTotalVideoSources, nTotalAudioSources, nTotalVideoEncoders, nTotalAudioEncoders, nTotalProfiles, ppServer, pszName, pszLocation, pszManufacturer, pszModel, pszHardwareVersion, pszFirmwareVersion, pszDeviceID, pszRootAccount, pszRootPassword, pszNetworkAdapterIP");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_COMMUNICATION_SERVER(PVOID pServer )
{
    (void)pServer;
    fprintf(stderr, "Mock function called: QCAP_DESTROY_COMMUNICATION_SERVER(%s)\n", "pServer");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_COMMUNICATION_SERVER(PVOID pServer , ULONG nNetworkPort )
{
    (void)pServer;
    (void)nNetworkPort;
    fprintf(stderr, "Mock function called: QCAP_START_COMMUNICATION_SERVER(%s)\n", "pServer, nNetworkPort");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_COMMUNICATION_SERVER(PVOID pServer )
{
    (void)pServer;
    fprintf(stderr, "Mock function called: QCAP_STOP_COMMUNICATION_SERVER(%s)\n", "pServer");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_SERVER_VIDEO_SOURCE(PVOID pServer , UINT iVidSrcNum , ULONG * pWidth , ULONG * pHeight , ULONG * pFrameRate )
{
    (void)pServer;
    (void)iVidSrcNum;
    (void)pWidth;
    (void)pHeight;
    (void)pFrameRate;
    fprintf(stderr, "Mock function called: QCAP_GET_COMMUNICATION_SERVER_VIDEO_SOURCE(%s)\n", "pServer, iVidSrcNum, pWidth, pHeight, pFrameRate");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_COMMUNICATION_SERVER_VIDEO_SOURCE(PVOID pServer , UINT iVidSrcNum , ULONG   nWidth ,  ULONG   nHeight ,  ULONG   nFrameRate )
{
    (void)pServer;
    (void)iVidSrcNum;
    (void)nWidth;
    (void)nHeight;
    (void)nFrameRate;
    fprintf(stderr, "Mock function called: QCAP_SET_COMMUNICATION_SERVER_VIDEO_SOURCE(%s)\n", "pServer, iVidSrcNum, nWidth, nHeight, nFrameRate");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_SERVER_AUDIO_SOURCE(PVOID pServer , UINT iAudSrcNum , ULONG * pChannels , ULONG * pBitsPerSample , ULONG * pSampleFrequency )
{
    (void)pServer;
    (void)iAudSrcNum;
    (void)pChannels;
    (void)pBitsPerSample;
    (void)pSampleFrequency;
    fprintf(stderr, "Mock function called: QCAP_GET_COMMUNICATION_SERVER_AUDIO_SOURCE(%s)\n", "pServer, iAudSrcNum, pChannels, pBitsPerSample, pSampleFrequency");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_COMMUNICATION_SERVER_AUDIO_SOURCE(PVOID pServer , UINT iAudSrcNum , ULONG   nChannels ,  ULONG   nBitsPerSample ,  ULONG   nSampleFrequency )
{
    (void)pServer;
    (void)iAudSrcNum;
    (void)nChannels;
    (void)nBitsPerSample;
    (void)nSampleFrequency;
    fprintf(stderr, "Mock function called: QCAP_SET_COMMUNICATION_SERVER_AUDIO_SOURCE(%s)\n", "pServer, iAudSrcNum, nChannels, nBitsPerSample, nSampleFrequency");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_SERVER_VIDEO_ENCODER(PVOID pServer , UINT iVidEncNum , ULONG * pEncoderFormat , ULONG * pWidth , ULONG * pHeight , ULONG * pFrameRate_Min , ULONG * pFrameRate_Max , ULONG * pFrameRate_Default , ULONG * pRecordMode_Min , ULONG * pRecordMode_Max , ULONG * pRecordMode_Default , ULONG * pQuality_Min , ULONG * pQuality_Max , ULONG * pQuality_Default , ULONG * pBitRate_Min , ULONG * pBitRate_Max , ULONG * pBitRate_Default , ULONG * pGOP_Min , ULONG * pGOP_Max , ULONG * pGOP_Default )
{
    (void)pServer;
    (void)iVidEncNum;
    (void)pEncoderFormat;
    (void)pWidth;
    (void)pHeight;
    (void)pFrameRate_Min;
    (void)pFrameRate_Max;
    (void)pFrameRate_Default;
    (void)pRecordMode_Min;
    (void)pRecordMode_Max;
    (void)pRecordMode_Default;
    (void)pQuality_Min;
    (void)pQuality_Max;
    (void)pQuality_Default;
    (void)pBitRate_Min;
    (void)pBitRate_Max;
    (void)pBitRate_Default;
    (void)pGOP_Min;
    (void)pGOP_Max;
    (void)pGOP_Default;
    fprintf(stderr, "Mock function called: QCAP_GET_COMMUNICATION_SERVER_VIDEO_ENCODER(%s)\n", "pServer, iVidEncNum, pEncoderFormat, pWidth, pHeight, pFrameRate_Min, pFrameRate_Max, pFrameRate_Default, pRecordMode_Min, pRecordMode_Max, pRecordMode_Default, pQuality_Min, pQuality_Max, pQuality_Default, pBitRate_Min, pBitRate_Max, pBitRate_Default, pGOP_Min, pGOP_Max, pGOP_Default");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_COMMUNICATION_SERVER_VIDEO_ENCODER(PVOID pServer , UINT iVidEncNum , ULONG   nEncoderFormat ,  ULONG   nWidth ,  ULONG   nHeight ,  ULONG   nFrameRate_Min ,  ULONG   nFrameRate_Max ,  ULONG   nFrameRate_Default ,  ULONG   nRecordMode_Min ,  ULONG   nRecordMode_Max ,  ULONG   nRecordMode_Default ,  ULONG   nQuality_Min ,  ULONG   nQuality_Max ,  ULONG   nQuality_Default ,  ULONG   nBitRate_Min ,  ULONG   nBitRate_Max ,  ULONG   nBitRate_Default ,  ULONG   nGOP_Min ,  ULONG   nGOP_Max ,  ULONG   nGOP_Default )
{
    (void)pServer;
    (void)iVidEncNum;
    (void)nEncoderFormat;
    (void)nWidth;
    (void)nHeight;
    (void)nFrameRate_Min;
    (void)nFrameRate_Max;
    (void)nFrameRate_Default;
    (void)nRecordMode_Min;
    (void)nRecordMode_Max;
    (void)nRecordMode_Default;
    (void)nQuality_Min;
    (void)nQuality_Max;
    (void)nQuality_Default;
    (void)nBitRate_Min;
    (void)nBitRate_Max;
    (void)nBitRate_Default;
    (void)nGOP_Min;
    (void)nGOP_Max;
    (void)nGOP_Default;
    fprintf(stderr, "Mock function called: QCAP_SET_COMMUNICATION_SERVER_VIDEO_ENCODER(%s)\n", "pServer, iVidEncNum, nEncoderFormat, nWidth, nHeight, nFrameRate_Min, nFrameRate_Max, nFrameRate_Default, nRecordMode_Min, nRecordMode_Max, nRecordMode_Default, nQuality_Min, nQuality_Max, nQuality_Default, nBitRate_Min, nBitRate_Max, nBitRate_Default, nGOP_Min, nGOP_Max, nGOP_Default");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_SERVER_AUDIO_ENCODER(PVOID pServer , UINT iAudEncNum , ULONG * pEncoderFormat , ULONG * pChannels , ULONG * pBitsPerSample , ULONG * pSampleFrequency , ULONG * pBitRate_Min , ULONG * pBitRate_Max , ULONG * pBitRate_Default )
{
    (void)pServer;
    (void)iAudEncNum;
    (void)pEncoderFormat;
    (void)pChannels;
    (void)pBitsPerSample;
    (void)pSampleFrequency;
    (void)pBitRate_Min;
    (void)pBitRate_Max;
    (void)pBitRate_Default;
    fprintf(stderr, "Mock function called: QCAP_GET_COMMUNICATION_SERVER_AUDIO_ENCODER(%s)\n", "pServer, iAudEncNum, pEncoderFormat, pChannels, pBitsPerSample, pSampleFrequency, pBitRate_Min, pBitRate_Max, pBitRate_Default");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_COMMUNICATION_SERVER_AUDIO_ENCODER(PVOID pServer , UINT iAudEncNum , ULONG   nEncoderFormat ,  ULONG   nChannels ,  ULONG   nBitsPerSample ,  ULONG   nSampleFrequency ,  ULONG   nBitRate_Min ,  ULONG   nBitRate_Max ,  ULONG   nBitRate_Default )
{
    (void)pServer;
    (void)iAudEncNum;
    (void)nEncoderFormat;
    (void)nChannels;
    (void)nBitsPerSample;
    (void)nSampleFrequency;
    (void)nBitRate_Min;
    (void)nBitRate_Max;
    (void)nBitRate_Default;
    fprintf(stderr, "Mock function called: QCAP_SET_COMMUNICATION_SERVER_AUDIO_ENCODER(%s)\n", "pServer, iAudEncNum, nEncoderFormat, nChannels, nBitsPerSample, nSampleFrequency, nBitRate_Min, nBitRate_Max, nBitRate_Default");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_SERVER_AUDIO_DECODER(PVOID pServer , UINT iAudDecNum , ULONG * pDecoderFormat , ULONG * pChannels , ULONG * pBitsPerSample , ULONG * pSampleFrequency , ULONG * pBitRate_Min , ULONG * pBitRate_Max , ULONG * pBitRate_Default )
{
    (void)pServer;
    (void)iAudDecNum;
    (void)pDecoderFormat;
    (void)pChannels;
    (void)pBitsPerSample;
    (void)pSampleFrequency;
    (void)pBitRate_Min;
    (void)pBitRate_Max;
    (void)pBitRate_Default;
    fprintf(stderr, "Mock function called: QCAP_GET_COMMUNICATION_SERVER_AUDIO_DECODER(%s)\n", "pServer, iAudDecNum, pDecoderFormat, pChannels, pBitsPerSample, pSampleFrequency, pBitRate_Min, pBitRate_Max, pBitRate_Default");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_COMMUNICATION_SERVER_AUDIO_DECODER(PVOID pServer , UINT iAudDecNum , ULONG   nDecoderFormat ,  ULONG   nChannels ,  ULONG   nBitsPerSample ,  ULONG   nSampleFrequency ,  ULONG   nBitRate_Min ,  ULONG   nBitRate_Max ,  ULONG   nBitRate_Default )
{
    (void)pServer;
    (void)iAudDecNum;
    (void)nDecoderFormat;
    (void)nChannels;
    (void)nBitsPerSample;
    (void)nSampleFrequency;
    (void)nBitRate_Min;
    (void)nBitRate_Max;
    (void)nBitRate_Default;
    fprintf(stderr, "Mock function called: QCAP_SET_COMMUNICATION_SERVER_AUDIO_DECODER(%s)\n", "pServer, iAudDecNum, nDecoderFormat, nChannels, nBitsPerSample, nSampleFrequency, nBitRate_Min, nBitRate_Max, nBitRate_Default");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_SERVER_PROFILE(PVOID pServer , UINT iProNum , CHAR * * ppszURL , UINT * pVidSrcNum , UINT * pAudSrcNum , UINT * pVidEncNum , UINT * pAudEncNum )
{
    (void)pServer;
    (void)iProNum;
    (void)ppszURL;
    (void)pVidSrcNum;
    (void)pAudSrcNum;
    (void)pVidEncNum;
    (void)pAudEncNum;
    fprintf(stderr, "Mock function called: QCAP_GET_COMMUNICATION_SERVER_PROFILE(%s)\n", "pServer, iProNum, ppszURL, pVidSrcNum, pAudSrcNum, pVidEncNum, pAudEncNum");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_COMMUNICATION_SERVER_PROFILE(PVOID pServer , UINT iProNum , CHAR *   pszURL ,   UINT   iVidSrcNum ,  UINT   iAudSrcNum ,  UINT   iVidEncNum ,  UINT   iAudEncNum )
{
    (void)pServer;
    (void)iProNum;
    (void)pszURL;
    (void)iVidSrcNum;
    (void)iAudSrcNum;
    (void)iVidEncNum;
    (void)iAudEncNum;
    fprintf(stderr, "Mock function called: QCAP_SET_COMMUNICATION_SERVER_PROFILE(%s)\n", "pServer, iProNum, pszURL, iVidSrcNum, iAudSrcNum, iVidEncNum, iAudEncNum");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_SERVER_PTZ(PVOID pServer , UINT iProNum , double * pPanRange_Min , double * pPanRange_Max , double * pTiltRange_Min , double * pTiltRange_Max , double * pZoomRange_Min , double * pZoomRange_Max , double * pPanTiltSpeed_Min , double * pPanTiltSpeed_Max , double * pPanTiltSpeed_Default , double * pZoomSpeed_Min , double * pZoomSpeed_Max , double * pZoomSpeed_Default )
{
    (void)pServer;
    (void)iProNum;
    (void)pPanRange_Min;
    (void)pPanRange_Max;
    (void)pTiltRange_Min;
    (void)pTiltRange_Max;
    (void)pZoomRange_Min;
    (void)pZoomRange_Max;
    (void)pPanTiltSpeed_Min;
    (void)pPanTiltSpeed_Max;
    (void)pPanTiltSpeed_Default;
    (void)pZoomSpeed_Min;
    (void)pZoomSpeed_Max;
    (void)pZoomSpeed_Default;
    fprintf(stderr, "Mock function called: QCAP_GET_COMMUNICATION_SERVER_PTZ(%s)\n", "pServer, iProNum, pPanRange_Min, pPanRange_Max, pTiltRange_Min, pTiltRange_Max, pZoomRange_Min, pZoomRange_Max, pPanTiltSpeed_Min, pPanTiltSpeed_Max, pPanTiltSpeed_Default, pZoomSpeed_Min, pZoomSpeed_Max, pZoomSpeed_Default");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_COMMUNICATION_SERVER_PTZ(PVOID pServer , UINT iProNum , double   dPanRange_Min ,  double   dPanRange_Max ,  double   dTiltRange_Min ,  double   dTiltRange_Max ,  double   dZoomRange_Min ,  double   dZoomRange_Max ,  double   dPanTiltSpeed_Min ,  double   dPanTiltSpeed_Max ,  double   dPanTiltSpeed_Default ,  double   dZoomSpeed_Min ,  double   dZoomSpeed_Max ,  double   dZoomSpeed_Default )
{
    (void)pServer;
    (void)iProNum;
    (void)dPanRange_Min;
    (void)dPanRange_Max;
    (void)dTiltRange_Min;
    (void)dTiltRange_Max;
    (void)dZoomRange_Min;
    (void)dZoomRange_Max;
    (void)dPanTiltSpeed_Min;
    (void)dPanTiltSpeed_Max;
    (void)dPanTiltSpeed_Default;
    (void)dZoomSpeed_Min;
    (void)dZoomSpeed_Max;
    (void)dZoomSpeed_Default;
    fprintf(stderr, "Mock function called: QCAP_SET_COMMUNICATION_SERVER_PTZ(%s)\n", "pServer, iProNum, dPanRange_Min, dPanRange_Max, dTiltRange_Min, dTiltRange_Max, dZoomRange_Min, dZoomRange_Max, dPanTiltSpeed_Min, dPanTiltSpeed_Max, dPanTiltSpeed_Default, dZoomSpeed_Min, dZoomSpeed_Max, dZoomSpeed_Default");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_LOAD_COMMUNICATION_SERVER_PTZ_LOCAL_PRESET(PVOID pServer , UINT iProNum , UINT iPresetNum , CHAR * pszPresetTokenName )
{
    (void)pServer;
    (void)iProNum;
    (void)iPresetNum;
    (void)pszPresetTokenName;
    fprintf(stderr, "Mock function called: QCAP_LOAD_COMMUNICATION_SERVER_PTZ_LOCAL_PRESET(%s)\n", "pServer, iProNum, iPresetNum, pszPresetTokenName");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_LOAD_COMMUNICATION_SERVER_PTZ_LOCAL_TOUR(PVOID pServer , UINT iProNum , UINT iTourNum , CHAR * pszTourTokenName , UINT * pPresetArray , double * pPresetPanSpeedArray , double * pPresetTiltSpeedArray , double * pArrayPresetZoomArray , ULONG nPresetArraySize )
{
    (void)pServer;
    (void)iProNum;
    (void)iTourNum;
    (void)pszTourTokenName;
    (void)pPresetArray;
    (void)pPresetPanSpeedArray;
    (void)pPresetTiltSpeedArray;
    (void)pArrayPresetZoomArray;
    (void)nPresetArraySize;
    fprintf(stderr, "Mock function called: QCAP_LOAD_COMMUNICATION_SERVER_PTZ_LOCAL_TOUR(%s)\n", "pServer, iProNum, iTourNum, pszTourTokenName, pPresetArray, pPresetPanSpeedArray, pPresetTiltSpeedArray, pArrayPresetZoomArray, nPresetArraySize");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_COMMUNICATION_SERVER_GET_CUSTOM_PROPERTY_CALLBACK(PVOID pServer , PF_COMMUNICATION_SERVER_GET_CUSTOM_PROPERTY_CALLBACK pCB , PVOID pUserData )
{
    (void)pServer;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_COMMUNICATION_SERVER_GET_CUSTOM_PROPERTY_CALLBACK(%s)\n", "pServer, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_COMMUNICATION_SERVER_SET_CUSTOM_PROPERTY_CALLBACK(PVOID pServer , PF_COMMUNICATION_SERVER_SET_CUSTOM_PROPERTY_CALLBACK pCB , PVOID pUserData )
{
    (void)pServer;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_COMMUNICATION_SERVER_SET_CUSTOM_PROPERTY_CALLBACK(%s)\n", "pServer, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_COMMUNICATION_SERVER_PROFILE_VIDEO_SETUP_CALLBACK(PVOID pServer , PF_COMMUNICATION_SERVER_PROFILE_VIDEO_SETUP_CALLBACK pCB , PVOID pUserData )
{
    (void)pServer;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_COMMUNICATION_SERVER_PROFILE_VIDEO_SETUP_CALLBACK(%s)\n", "pServer, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_COMMUNICATION_SERVER_PROFILE_AUDIO_SETUP_CALLBACK(PVOID pServer , PF_COMMUNICATION_SERVER_PROFILE_AUDIO_SETUP_CALLBACK pCB , PVOID pUserData )
{
    (void)pServer;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_COMMUNICATION_SERVER_PROFILE_AUDIO_SETUP_CALLBACK(%s)\n", "pServer, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_COMMUNICATION_SERVER_PTZ_SET_HOME_CALLBACK(PVOID pServer , PF_COMMUNICATION_SERVER_PTZ_SET_HOME_CALLBACK pCB , PVOID pUserData )
{
    (void)pServer;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_COMMUNICATION_SERVER_PTZ_SET_HOME_CALLBACK(%s)\n", "pServer, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_COMMUNICATION_SERVER_PTZ_SET_PRESET_CALLBACK(PVOID pServer , PF_COMMUNICATION_SERVER_PTZ_SET_PRESET_CALLBACK pCB , PVOID pUserData )
{
    (void)pServer;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_COMMUNICATION_SERVER_PTZ_SET_PRESET_CALLBACK(%s)\n", "pServer, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_COMMUNICATION_SERVER_PTZ_SET_TOUR_CALLBACK(PVOID pServer , PF_COMMUNICATION_SERVER_PTZ_SET_TOUR_CALLBACK pCB , PVOID pUserData )
{
    (void)pServer;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_COMMUNICATION_SERVER_PTZ_SET_TOUR_CALLBACK(%s)\n", "pServer, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_COMMUNICATION_SERVER_PTZ_GOTO_HOME_CALLBACK(PVOID pServer , PF_COMMUNICATION_SERVER_PTZ_GOTO_HOME_CALLBACK pCB , PVOID pUserData )
{
    (void)pServer;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_COMMUNICATION_SERVER_PTZ_GOTO_HOME_CALLBACK(%s)\n", "pServer, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_COMMUNICATION_SERVER_PTZ_GOTO_PRESET_CALLBACK(PVOID pServer , PF_COMMUNICATION_SERVER_PTZ_GOTO_PRESET_CALLBACK pCB , PVOID pUserData )
{
    (void)pServer;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_COMMUNICATION_SERVER_PTZ_GOTO_PRESET_CALLBACK(%s)\n", "pServer, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_COMMUNICATION_SERVER_PTZ_GOTO_TOUR_CALLBACK(PVOID pServer , PF_COMMUNICATION_SERVER_PTZ_GOTO_TOUR_CALLBACK pCB , PVOID pUserData )
{
    (void)pServer;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_COMMUNICATION_SERVER_PTZ_GOTO_TOUR_CALLBACK(%s)\n", "pServer, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_COMMUNICATION_SERVER_PTZ_MOVE_CONTINUOUS_CALLBACK(PVOID pServer , PF_COMMUNICATION_SERVER_PTZ_MOVE_CONTINUOUS_CALLBACK pCB , PVOID pUserData )
{
    (void)pServer;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_COMMUNICATION_SERVER_PTZ_MOVE_CONTINUOUS_CALLBACK(%s)\n", "pServer, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_COMMUNICATION_SERVER_PTZ_MOVE_RELATIVE_CALLBACK(PVOID pServer , PF_COMMUNICATION_SERVER_PTZ_MOVE_RELATIVE_CALLBACK pCB , PVOID pUserData )
{
    (void)pServer;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_COMMUNICATION_SERVER_PTZ_MOVE_RELATIVE_CALLBACK(%s)\n", "pServer, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_COMMUNICATION_SERVER_PTZ_MOVE_ABSOLUTE_CALLBACK(PVOID pServer , PF_COMMUNICATION_SERVER_PTZ_MOVE_ABSOLUTE_CALLBACK pCB , PVOID pUserData )
{
    (void)pServer;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_COMMUNICATION_SERVER_PTZ_MOVE_ABSOLUTE_CALLBACK(%s)\n", "pServer, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_COMMUNICATION_SERVER_PTZ_MOVE_STOP_CALLBACK(PVOID pServer , PF_COMMUNICATION_SERVER_PTZ_MOVE_STOP_CALLBACK pCB , PVOID pUserData )
{
    (void)pServer;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_COMMUNICATION_SERVER_PTZ_MOVE_STOP_CALLBACK(%s)\n", "pServer, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_COMMUNICATION_ONVIF_EMULATOR(PVOID * ppEmulator , ULONG nEmulatorPort )
{
    (void)ppEmulator;
    (void)nEmulatorPort;
    fprintf(stderr, "Mock function called: QCAP_CREATE_COMMUNICATION_ONVIF_EMULATOR(%s)\n", "ppEmulator, nEmulatorPort");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_COMMUNICATION_EMULATOR(PVOID pEmulator )
{
    (void)pEmulator;
    fprintf(stderr, "Mock function called: QCAP_DESTROY_COMMUNICATION_EMULATOR(%s)\n", "pEmulator");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_COMMUNICATION_EMULATOR(PVOID pEmulator )
{
    (void)pEmulator;
    fprintf(stderr, "Mock function called: QCAP_START_COMMUNICATION_EMULATOR(%s)\n", "pEmulator");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_COMMUNICATION_EMULATOR(PVOID pEmulator )
{
    (void)pEmulator;
    fprintf(stderr, "Mock function called: QCAP_STOP_COMMUNICATION_EMULATOR(%s)\n", "pEmulator");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_EMULATOR_SERVER_INFO(PVOID pEmulator , UINT iSvrNum , CHAR * * ppszNetworkIP , ULONG * pNetworkPort , CHAR * * ppszNetworkURL )
{
    (void)pEmulator;
    (void)iSvrNum;
    (void)ppszNetworkIP;
    (void)pNetworkPort;
    (void)ppszNetworkURL;
    fprintf(stderr, "Mock function called: QCAP_GET_COMMUNICATION_EMULATOR_SERVER_INFO(%s)\n", "pEmulator, iSvrNum, ppszNetworkIP, pNetworkPort, ppszNetworkURL");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_COMMUNICATION_EMULATOR_SCAN_DONE_CALLBACK(PVOID pEmulator , PF_COMMUNICATION_EMULATOR_SCAN_DONE_CALLBACK pCB , PVOID pUserData )
{
    (void)pEmulator;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_COMMUNICATION_EMULATOR_SCAN_DONE_CALLBACK(%s)\n", "pEmulator, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_COMMUNICATION_ONVIF_CLIENT(CHAR * pszNetworkURL , PVOID * ppClient , CHAR * pszAccount , CHAR * pszPassword )
{
    (void)pszNetworkURL;
    (void)ppClient;
    (void)pszAccount;
    (void)pszPassword;
    fprintf(stderr, "Mock function called: QCAP_CREATE_COMMUNICATION_ONVIF_CLIENT(%s)\n", "pszNetworkURL, ppClient, pszAccount, pszPassword");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_COMMUNICATION_CLIENT(PVOID pClient )
{
    (void)pClient;
    fprintf(stderr, "Mock function called: QCAP_DESTROY_COMMUNICATION_CLIENT(%s)\n", "pClient");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_COMMUNICATION_CLIENT(PVOID pClient )
{
    (void)pClient;
    fprintf(stderr, "Mock function called: QCAP_START_COMMUNICATION_CLIENT(%s)\n", "pClient");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_COMMUNICATION_CLIENT(PVOID pClient )
{
    (void)pClient;
    fprintf(stderr, "Mock function called: QCAP_STOP_COMMUNICATION_CLIENT(%s)\n", "pClient");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_CLIENT_VIDEO_SOURCE_INFO(PVOID pClient , UINT iVidSrcNum , ULONG * pWidth , ULONG * pHeight , ULONG * pFrameRate )
{
    (void)pClient;
    (void)iVidSrcNum;
    (void)pWidth;
    (void)pHeight;
    (void)pFrameRate;
    fprintf(stderr, "Mock function called: QCAP_GET_COMMUNICATION_CLIENT_VIDEO_SOURCE_INFO(%s)\n", "pClient, iVidSrcNum, pWidth, pHeight, pFrameRate");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_CLIENT_AUDIO_SOURCE_INFO(PVOID pClient , UINT iAudSrcNum , ULONG * pChannels , ULONG * pBitsPerSample , ULONG * pSampleFrequency )
{
    (void)pClient;
    (void)iAudSrcNum;
    (void)pChannels;
    (void)pBitsPerSample;
    (void)pSampleFrequency;
    fprintf(stderr, "Mock function called: QCAP_GET_COMMUNICATION_CLIENT_AUDIO_SOURCE_INFO(%s)\n", "pClient, iAudSrcNum, pChannels, pBitsPerSample, pSampleFrequency");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_CLIENT_VIDEO_ENCODER_INFO(PVOID pClient , UINT iVidEncNum , ULONG * pTotalVidEncOptions , UINT * pVidEncOptionNum_Default )
{
    (void)pClient;
    (void)iVidEncNum;
    (void)pTotalVidEncOptions;
    (void)pVidEncOptionNum_Default;
    fprintf(stderr, "Mock function called: QCAP_GET_COMMUNICATION_CLIENT_VIDEO_ENCODER_INFO(%s)\n", "pClient, iVidEncNum, pTotalVidEncOptions, pVidEncOptionNum_Default");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_CLIENT_AUDIO_ENCODER_INFO(PVOID pClient , UINT iAudEncNum , ULONG * pTotalAudEncOptions , UINT * pAudEncOptionNum_Default )
{
    (void)pClient;
    (void)iAudEncNum;
    (void)pTotalAudEncOptions;
    (void)pAudEncOptionNum_Default;
    fprintf(stderr, "Mock function called: QCAP_GET_COMMUNICATION_CLIENT_AUDIO_ENCODER_INFO(%s)\n", "pClient, iAudEncNum, pTotalAudEncOptions, pAudEncOptionNum_Default");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_CLIENT_VIDEO_ENCODER_OPTION_INFO(PVOID pClient , UINT iVidEncNum , UINT iVidEncOptionNum , ULONG * pEncoderFormat , ULONG * pWidthList , ULONG * pWidthListSize , ULONG * pWidth_Default , ULONG * pHeightList , ULONG * pHeightListSize , ULONG * pHeight_Default , ULONG * pFrameRate_Min , ULONG * pFrameRate_Max , ULONG * pFrameRate_Default , ULONG * pRecordMode_Min , ULONG * pRecordMode_Max , ULONG * pRecordMode_Default , ULONG * pQuality_Min , ULONG * pQuality_Max , ULONG * pQuality_Default , ULONG * pBitRate_Min , ULONG * pBitRate_Max , ULONG * pBitRate_Default , ULONG * pGOP_Min , ULONG * pGOP_Max , ULONG * pGOP_Default )
{
    (void)pClient;
    (void)iVidEncNum;
    (void)iVidEncOptionNum;
    (void)pEncoderFormat;
    (void)pWidthList;
    (void)pWidthListSize;
    (void)pWidth_Default;
    (void)pHeightList;
    (void)pHeightListSize;
    (void)pHeight_Default;
    (void)pFrameRate_Min;
    (void)pFrameRate_Max;
    (void)pFrameRate_Default;
    (void)pRecordMode_Min;
    (void)pRecordMode_Max;
    (void)pRecordMode_Default;
    (void)pQuality_Min;
    (void)pQuality_Max;
    (void)pQuality_Default;
    (void)pBitRate_Min;
    (void)pBitRate_Max;
    (void)pBitRate_Default;
    (void)pGOP_Min;
    (void)pGOP_Max;
    (void)pGOP_Default;
    fprintf(stderr, "Mock function called: QCAP_GET_COMMUNICATION_CLIENT_VIDEO_ENCODER_OPTION_INFO(%s)\n", "pClient, iVidEncNum, iVidEncOptionNum, pEncoderFormat, pWidthList, pWidthListSize, pWidth_Default, pHeightList, pHeightListSize, pHeight_Default, pFrameRate_Min, pFrameRate_Max, pFrameRate_Default, pRecordMode_Min, pRecordMode_Max, pRecordMode_Default, pQuality_Min, pQuality_Max, pQuality_Default, pBitRate_Min, pBitRate_Max, pBitRate_Default, pGOP_Min, pGOP_Max, pGOP_Default");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_CLIENT_AUDIO_ENCODER_OPTION_INFO(PVOID pClient , UINT iAudEncNum , UINT iAudEncOptionNum , ULONG * pEncoderFormat , ULONG * pChannelsList , ULONG * pChannelsListSize , ULONG * pChannels_Default , ULONG * pBitsPerSampleList , ULONG * pBitsPerSampleListSize , ULONG * pBitsPerSample_Default , ULONG * pSampleFrequencyList , ULONG * pSampleFrequencyListSize , ULONG * pSampleFrequency_Default , ULONG * pBitRate_Min , ULONG * pBitRate_Max , ULONG * pBitRate_Default )
{
    (void)pClient;
    (void)iAudEncNum;
    (void)iAudEncOptionNum;
    (void)pEncoderFormat;
    (void)pChannelsList;
    (void)pChannelsListSize;
    (void)pChannels_Default;
    (void)pBitsPerSampleList;
    (void)pBitsPerSampleListSize;
    (void)pBitsPerSample_Default;
    (void)pSampleFrequencyList;
    (void)pSampleFrequencyListSize;
    (void)pSampleFrequency_Default;
    (void)pBitRate_Min;
    (void)pBitRate_Max;
    (void)pBitRate_Default;
    fprintf(stderr, "Mock function called: QCAP_GET_COMMUNICATION_CLIENT_AUDIO_ENCODER_OPTION_INFO(%s)\n", "pClient, iAudEncNum, iAudEncOptionNum, pEncoderFormat, pChannelsList, pChannelsListSize, pChannels_Default, pBitsPerSampleList, pBitsPerSampleListSize, pBitsPerSample_Default, pSampleFrequencyList, pSampleFrequencyListSize, pSampleFrequency_Default, pBitRate_Min, pBitRate_Max, pBitRate_Default");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_CLIENT_PROFILE_INFO(PVOID pClient , UINT iProNum , CHAR * * ppszURL , UINT * pVidSrcNum , UINT * pAudSrcNum , UINT * pVidEncNum , UINT * pAudEncNum )
{
    (void)pClient;
    (void)iProNum;
    (void)ppszURL;
    (void)pVidSrcNum;
    (void)pAudSrcNum;
    (void)pVidEncNum;
    (void)pAudEncNum;
    fprintf(stderr, "Mock function called: QCAP_GET_COMMUNICATION_CLIENT_PROFILE_INFO(%s)\n", "pClient, iProNum, ppszURL, pVidSrcNum, pAudSrcNum, pVidEncNum, pAudEncNum");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_CLIENT_PROFILE_VIDEO_PROPERTY(PVOID pClient , UINT iProNum , ULONG * pEncoderFormat , ULONG * pWidth , ULONG * pHeight , ULONG * pFrameRate , ULONG * pRecordMode , ULONG * pQuality , ULONG * pBitRate , ULONG * pGOP )
{
    (void)pClient;
    (void)iProNum;
    (void)pEncoderFormat;
    (void)pWidth;
    (void)pHeight;
    (void)pFrameRate;
    (void)pRecordMode;
    (void)pQuality;
    (void)pBitRate;
    (void)pGOP;
    fprintf(stderr, "Mock function called: QCAP_GET_COMMUNICATION_CLIENT_PROFILE_VIDEO_PROPERTY(%s)\n", "pClient, iProNum, pEncoderFormat, pWidth, pHeight, pFrameRate, pRecordMode, pQuality, pBitRate, pGOP");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_COMMUNICATION_CLIENT_PROFILE_VIDEO_PROPERTY(PVOID pClient , UINT iProNum , ULONG   nEncoderFormat ,  ULONG   nWidth ,  ULONG   nHeight ,  ULONG   nFrameRate ,  ULONG   nRecordMode ,  ULONG   nQuality ,  ULONG   nBitRate ,  ULONG   nGOP )
{
    (void)pClient;
    (void)iProNum;
    (void)nEncoderFormat;
    (void)nWidth;
    (void)nHeight;
    (void)nFrameRate;
    (void)nRecordMode;
    (void)nQuality;
    (void)nBitRate;
    (void)nGOP;
    fprintf(stderr, "Mock function called: QCAP_SET_COMMUNICATION_CLIENT_PROFILE_VIDEO_PROPERTY(%s)\n", "pClient, iProNum, nEncoderFormat, nWidth, nHeight, nFrameRate, nRecordMode, nQuality, nBitRate, nGOP");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_CLIENT_PROFILE_AUDIO_PROPERTY(PVOID pClient , UINT iProNum , ULONG * pEncoderFormat , ULONG * pChannels , ULONG * pBitsPerSample , ULONG * pSampleFrequency , ULONG * pBitRate )
{
    (void)pClient;
    (void)iProNum;
    (void)pEncoderFormat;
    (void)pChannels;
    (void)pBitsPerSample;
    (void)pSampleFrequency;
    (void)pBitRate;
    fprintf(stderr, "Mock function called: QCAP_GET_COMMUNICATION_CLIENT_PROFILE_AUDIO_PROPERTY(%s)\n", "pClient, iProNum, pEncoderFormat, pChannels, pBitsPerSample, pSampleFrequency, pBitRate");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_COMMUNICATION_CLIENT_PROFILE_AUDIO_PROPERTY(PVOID pClient , UINT iProNum , ULONG   nEncoderFormat ,  ULONG   nChannels ,  ULONG   nBitsPerSample ,  ULONG   nSampleFrequency ,  ULONG   nBitRate )
{
    (void)pClient;
    (void)iProNum;
    (void)nEncoderFormat;
    (void)nChannels;
    (void)nBitsPerSample;
    (void)nSampleFrequency;
    (void)nBitRate;
    fprintf(stderr, "Mock function called: QCAP_SET_COMMUNICATION_CLIENT_PROFILE_AUDIO_PROPERTY(%s)\n", "pClient, iProNum, nEncoderFormat, nChannels, nBitsPerSample, nSampleFrequency, nBitRate");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_CLIENT_PTZ_INFO(PVOID pClient , UINT iProNum , ULONG * pTotalPresets , ULONG * pTotalTours , double * pPanRange_Min , double * pPanRange_Max , double * pTiltRange_Min , double * pTiltRange_Max , double * pZoomRange_Min , double * pZoomRange_Max , double * pPanSpeed_Min , double * pPanSpeed_Max , double * pPanSpeed_Default , double * pTiltSpeed_Min , double * pTiltSpeed_Max , double * pTiltSpeed_Default , double * pZoomSpeed_Min , double * pZoomSpeed_Max , double * pZoomSpeed_Default )
{
    (void)pClient;
    (void)iProNum;
    (void)pTotalPresets;
    (void)pTotalTours;
    (void)pPanRange_Min;
    (void)pPanRange_Max;
    (void)pTiltRange_Min;
    (void)pTiltRange_Max;
    (void)pZoomRange_Min;
    (void)pZoomRange_Max;
    (void)pPanSpeed_Min;
    (void)pPanSpeed_Max;
    (void)pPanSpeed_Default;
    (void)pTiltSpeed_Min;
    (void)pTiltSpeed_Max;
    (void)pTiltSpeed_Default;
    (void)pZoomSpeed_Min;
    (void)pZoomSpeed_Max;
    (void)pZoomSpeed_Default;
    fprintf(stderr, "Mock function called: QCAP_GET_COMMUNICATION_CLIENT_PTZ_INFO(%s)\n", "pClient, iProNum, pTotalPresets, pTotalTours, pPanRange_Min, pPanRange_Max, pTiltRange_Min, pTiltRange_Max, pZoomRange_Min, pZoomRange_Max, pPanSpeed_Min, pPanSpeed_Max, pPanSpeed_Default, pTiltSpeed_Min, pTiltSpeed_Max, pTiltSpeed_Default, pZoomSpeed_Min, pZoomSpeed_Max, pZoomSpeed_Default");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_COMMUNICATION_CLIENT_PTZ_HOME(PVOID pClient , UINT iProNum )
{
    (void)pClient;
    (void)iProNum;
    fprintf(stderr, "Mock function called: QCAP_SET_COMMUNICATION_CLIENT_PTZ_HOME(%s)\n", "pClient, iProNum");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_CLIENT_PTZ_PRESET(PVOID pClient , UINT iProNum , UINT iPresetNum , CHAR * pszPresetTokenName )
{
    (void)pClient;
    (void)iProNum;
    (void)iPresetNum;
    (void)pszPresetTokenName;
    fprintf(stderr, "Mock function called: QCAP_GET_COMMUNICATION_CLIENT_PTZ_PRESET(%s)\n", "pClient, iProNum, iPresetNum, pszPresetTokenName");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_COMMUNICATION_CLIENT_PTZ_PRESET(PVOID pClient , UINT iProNum , UINT iPresetNum , CHAR * pszPresetTokenName )
{
    (void)pClient;
    (void)iProNum;
    (void)iPresetNum;
    (void)pszPresetTokenName;
    fprintf(stderr, "Mock function called: QCAP_SET_COMMUNICATION_CLIENT_PTZ_PRESET(%s)\n", "pClient, iProNum, iPresetNum, pszPresetTokenName");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_CLIENT_PTZ_TOUR(PVOID pClient , UINT iProNum , UINT iTourNum , CHAR * pszTourTokenName , UINT * pPresetArray , double * pPresetPanSpeedArray , double * pPresetTiltSpeedArray , double * pPresetZoomSpeedArray , ULONG * pPresetArraySize /*IN/OUT*/)
{
    (void)pClient;
    (void)iProNum;
    (void)iTourNum;
    (void)pszTourTokenName;
    (void)pPresetArray;
    (void)pPresetPanSpeedArray;
    (void)pPresetTiltSpeedArray;
    (void)pPresetZoomSpeedArray;
    fprintf(stderr, "Mock function called: QCAP_GET_COMMUNICATION_CLIENT_PTZ_TOUR(%s)\n", "pClient, iProNum, iTourNum, pszTourTokenName, pPresetArray, pPresetPanSpeedArray, pPresetTiltSpeedArray, pPresetZoomSpeedArray");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_COMMUNICATION_CLIENT_PTZ_TOUR(PVOID pClient , UINT iProNum , UINT iTourNum , CHAR * pszTourTokenName , UINT * pPresetArray , double * pPresetPanSpeedArray , double * pPresetTiltSpeedArray , double * pPresetZoomSpeedArray , ULONG nPresetArraySize )
{
    (void)pClient;
    (void)iProNum;
    (void)iTourNum;
    (void)pszTourTokenName;
    (void)pPresetArray;
    (void)pPresetPanSpeedArray;
    (void)pPresetTiltSpeedArray;
    (void)pPresetZoomSpeedArray;
    (void)nPresetArraySize;
    fprintf(stderr, "Mock function called: QCAP_SET_COMMUNICATION_CLIENT_PTZ_TOUR(%s)\n", "pClient, iProNum, iTourNum, pszTourTokenName, pPresetArray, pPresetPanSpeedArray, pPresetTiltSpeedArray, pPresetZoomSpeedArray, nPresetArraySize");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GOTO_COMMUNICATION_CLIENT_PTZ_HOME(PVOID pClient , UINT iProNum , double dPanSpeed , double dTiltSpeed , double dZoomSpeed )
{
    (void)pClient;
    (void)iProNum;
    (void)dPanSpeed;
    (void)dTiltSpeed;
    (void)dZoomSpeed;
    fprintf(stderr, "Mock function called: QCAP_GOTO_COMMUNICATION_CLIENT_PTZ_HOME(%s)\n", "pClient, iProNum, dPanSpeed, dTiltSpeed, dZoomSpeed");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GOTO_COMMUNICATION_CLIENT_PTZ_PRESET(PVOID pClient , UINT iProNum , UINT iPresetNum , double dPanSpeed , double dTiltSpeed , double dZoomSpeed )
{
    (void)pClient;
    (void)iProNum;
    (void)iPresetNum;
    (void)dPanSpeed;
    (void)dTiltSpeed;
    (void)dZoomSpeed;
    fprintf(stderr, "Mock function called: QCAP_GOTO_COMMUNICATION_CLIENT_PTZ_PRESET(%s)\n", "pClient, iProNum, iPresetNum, dPanSpeed, dTiltSpeed, dZoomSpeed");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GOTO_COMMUNICATION_CLIENT_PTZ_TOUR(PVOID pClient , UINT iProNum , UINT iTourNum )
{
    (void)pClient;
    (void)iProNum;
    (void)iTourNum;
    fprintf(stderr, "Mock function called: QCAP_GOTO_COMMUNICATION_CLIENT_PTZ_TOUR(%s)\n", "pClient, iProNum, iTourNum");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_MOVE_COMMUNICATION_CLIENT_PTZ_CONTINUOUS(PVOID pClient , UINT iProNum , double dPanSpeed , double dTiltSpeed , double dZoomSpeed )
{
    (void)pClient;
    (void)iProNum;
    (void)dPanSpeed;
    (void)dTiltSpeed;
    (void)dZoomSpeed;
    fprintf(stderr, "Mock function called: QCAP_MOVE_COMMUNICATION_CLIENT_PTZ_CONTINUOUS(%s)\n", "pClient, iProNum, dPanSpeed, dTiltSpeed, dZoomSpeed");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_MOVE_COMMUNICATION_CLIENT_PTZ_RELATIVE(PVOID pClient , UINT iProNum , double dPan , double dTilt , double dZoom , double dPanSpeed , double dTiltSpeed , double dZoomSpeed )
{
    (void)pClient;
    (void)iProNum;
    (void)dPan;
    (void)dTilt;
    (void)dZoom;
    (void)dPanSpeed;
    (void)dTiltSpeed;
    (void)dZoomSpeed;
    fprintf(stderr, "Mock function called: QCAP_MOVE_COMMUNICATION_CLIENT_PTZ_RELATIVE(%s)\n", "pClient, iProNum, dPan, dTilt, dZoom, dPanSpeed, dTiltSpeed, dZoomSpeed");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_MOVE_COMMUNICATION_CLIENT_PTZ_ABSOLUTE(PVOID pClient , UINT iProNum , double dPan , double dTilt , double dZoom , double dPanSpeed , double dTiltSpeed , double dZoomSpeed )
{
    (void)pClient;
    (void)iProNum;
    (void)dPan;
    (void)dTilt;
    (void)dZoom;
    (void)dPanSpeed;
    (void)dTiltSpeed;
    (void)dZoomSpeed;
    fprintf(stderr, "Mock function called: QCAP_MOVE_COMMUNICATION_CLIENT_PTZ_ABSOLUTE(%s)\n", "pClient, iProNum, dPan, dTilt, dZoom, dPanSpeed, dTiltSpeed, dZoomSpeed");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_MOVE_COMMUNICATION_CLIENT_PTZ_STOP(PVOID pClient , UINT iProNum )
{
    (void)pClient;
    (void)iProNum;
    fprintf(stderr, "Mock function called: QCAP_MOVE_COMMUNICATION_CLIENT_PTZ_STOP(%s)\n", "pClient, iProNum");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_COMMUNICATION_CLIENT_CUSTOM_PROPERTY(PVOID pClient , CHAR * pszProperty , CHAR * * ppszValue )
{
    (void)pClient;
    (void)pszProperty;
    (void)ppszValue;
    fprintf(stderr, "Mock function called: QCAP_GET_COMMUNICATION_CLIENT_CUSTOM_PROPERTY(%s)\n", "pClient, pszProperty, ppszValue");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_COMMUNICATION_CLIENT_CUSTOM_PROPERTY(PVOID pClient , CHAR * pszProperty , CHAR * pszValue )
{
    (void)pClient;
    (void)pszProperty;
    (void)pszValue;
    fprintf(stderr, "Mock function called: QCAP_SET_COMMUNICATION_CLIENT_CUSTOM_PROPERTY(%s)\n", "pClient, pszProperty, pszValue");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_COMMUNICATION_CLIENT_CONNECTED_CALLBACK(PVOID pClient , PF_COMMUNICATION_CLIENT_CONNECTED_CALLBACK pCB , PVOID pUserData )
{
    (void)pClient;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_COMMUNICATION_CLIENT_CONNECTED_CALLBACK(%s)\n", "pClient, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

