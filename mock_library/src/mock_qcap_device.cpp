#include "mock_qcap_device.h"
#include <cstdio> // For fprintf, stderr

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DEVICE_ENUMERATION(ULONGLONG * * ppVideoDeviceList , ULONG * pVideoDeviceSize , ULONGLONG * * ppVideoEncoderDeviceList , ULONG * pVideoEncoderDeviceSize , ULONGLONG * * ppAudioDeviceList , ULONG * pAudioDeviceSize , ULONGLONG * * ppAudioEncoderDeviceList , ULONG * pAudioEncoderDeviceSize , ULONG nDeviceEnumType )
{
    (void)ppVideoDeviceList;
    (void)pVideoDeviceSize;
    (void)ppVideoEncoderDeviceList;
    (void)pVideoEncoderDeviceSize;
    (void)ppAudioDeviceList;
    (void)pAudioDeviceSize;
    (void)ppAudioEncoderDeviceList;
    (void)pAudioEncoderDeviceSize;
    (void)nDeviceEnumType;
    fprintf(stderr, "Mock function called: QCAP_DEVICE_ENUMERATION(%s)\n", "ppVideoDeviceList, pVideoDeviceSize, ppVideoEncoderDeviceList, pVideoEncoderDeviceSize, ppAudioDeviceList, pAudioDeviceSize, ppAudioEncoderDeviceList, pAudioEncoderDeviceSize, nDeviceEnumType");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_DEVICE_ENUMERATION_ITEM_INFO(UINT iDevNum , ULONGLONG * pDeviceList , ULONG * pDeviceInfoH , ULONG * pDeviceInfoL )
{
    (void)iDevNum;
    (void)pDeviceList;
    (void)pDeviceInfoH;
    (void)pDeviceInfoL;
    fprintf(stderr, "Mock function called: QCAP_GET_DEVICE_ENUMERATION_ITEM_INFO(%s)\n", "iDevNum, pDeviceList, pDeviceInfoH, pDeviceInfoL");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_DEFAULT_CUSTOM_DEVICE(CHAR * pszVideoDevName , CHAR * pszAudioDevName )
{
    (void)pszVideoDevName;
    (void)pszAudioDevName;
    fprintf(stderr, "Mock function called: QCAP_SET_DEFAULT_CUSTOM_DEVICE(%s)\n", "pszVideoDevName, pszAudioDevName");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE(CHAR * pszDevName , UINT iDevNum , HWND hAttachedWindow , PVOID * ppDevice , BOOL bThumbDraw , BOOL bMaintainAspectRatio )
{
    (void)pszDevName;
    (void)iDevNum;
    (void)hAttachedWindow;
    (void)ppDevice;
    (void)bThumbDraw;
    (void)bMaintainAspectRatio;
    fprintf(stderr, "Mock function called: QCAP_CREATE(%s)\n", "pszDevName, iDevNum, hAttachedWindow, ppDevice, bThumbDraw, bMaintainAspectRatio");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY(PVOID pDevice )
{
    (void)pDevice;
    fprintf(stderr, "Mock function called: QCAP_DESTROY(%s)\n", "pDevice");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_RUN(PVOID pDevice )
{
    (void)pDevice;
    fprintf(stderr, "Mock function called: QCAP_RUN(%s)\n", "pDevice");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_RUN_EX(PVOID pDevice , BOOL bStopAfterSignalRemoved )
{
    (void)pDevice;
    (void)bStopAfterSignalRemoved;
    fprintf(stderr, "Mock function called: QCAP_RUN_EX(%s)\n", "pDevice, bStopAfterSignalRemoved");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP(PVOID pDevice )
{
    (void)pDevice;
    fprintf(stderr, "Mock function called: QCAP_STOP(%s)\n", "pDevice");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_QUERY_DEVICE_CAP(PVOID pDevice , DWORD * pDeviceSerialNumber , CHAR * pszDeviceSystemPath , BOOL * pHasHardwareMainEncoder , BOOL * pHasHardwareSubEncoder )
{
    (void)pDevice;
    (void)pDeviceSerialNumber;
    (void)pszDeviceSystemPath;
    (void)pHasHardwareMainEncoder;
    (void)pHasHardwareSubEncoder;
    fprintf(stderr, "Mock function called: QCAP_QUERY_DEVICE_CAP(%s)\n", "pDevice, pDeviceSerialNumber, pszDeviceSystemPath, pHasHardwareMainEncoder, pHasHardwareSubEncoder");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_INPUT_CONFIG(PVOID pDevice , DWORD * pConfig )
{
    (void)pDevice;
    (void)pConfig;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_INPUT_CONFIG(%s)\n", "pDevice, pConfig");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_INPUT_CONFIG(PVOID pDevice , DWORD dwConfig )
{
    (void)pDevice;
    (void)dwConfig;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_INPUT_CONFIG(%s)\n", "pDevice, dwConfig");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_INPUT(PVOID pDevice , ULONG * pInput )
{
    (void)pDevice;
    (void)pInput;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_INPUT(%s)\n", "pDevice, pInput");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_INPUT(PVOID pDevice , ULONG nInput )
{
    (void)pDevice;
    (void)nInput;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_INPUT(%s)\n", "pDevice, nInput");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_AUDIO_INPUT_CONFIG(PVOID pDevice , DWORD * pConfig )
{
    (void)pDevice;
    (void)pConfig;
    fprintf(stderr, "Mock function called: QCAP_GET_AUDIO_INPUT_CONFIG(%s)\n", "pDevice, pConfig");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_INPUT_CONFIG(PVOID pDevice , DWORD dwConfig )
{
    (void)pDevice;
    (void)dwConfig;
    fprintf(stderr, "Mock function called: QCAP_SET_AUDIO_INPUT_CONFIG(%s)\n", "pDevice, dwConfig");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_AUDIO_INPUT(PVOID pDevice , ULONG * pInput )
{
    (void)pDevice;
    (void)pInput;
    fprintf(stderr, "Mock function called: QCAP_GET_AUDIO_INPUT(%s)\n", "pDevice, pInput");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_INPUT(PVOID pDevice , ULONG nInput )
{
    (void)pDevice;
    (void)nInput;
    fprintf(stderr, "Mock function called: QCAP_SET_AUDIO_INPUT(%s)\n", "pDevice, nInput");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_STANDARD(PVOID pDevice , ULONG * pStandard )
{
    (void)pDevice;
    (void)pStandard;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_STANDARD(%s)\n", "pDevice, pStandard");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_STANDARD(PVOID pDevice , ULONG nStandard )
{
    (void)pDevice;
    (void)nStandard;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_STANDARD(%s)\n", "pDevice, nStandard");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_CURRENT_CONTENT_PROTECTION_STATUS(PVOID pDevice , ULONG * pStatus )
{
    (void)pDevice;
    (void)pStatus;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_CURRENT_CONTENT_PROTECTION_STATUS(%s)\n", "pDevice, pStatus");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_COUNT_OF_SUPPORT_OUTPUT_FORMATS(PVOID pDevice , ULONG * pCount )
{
    (void)pDevice;
    (void)pCount;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_COUNT_OF_SUPPORT_OUTPUT_FORMATS(%s)\n", "pDevice, pCount");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_SUPPORT_OUTPUT_FORMAT(PVOID pDevice , UINT iFmtNum , ULONG * pColorSpaceType , ULONG * pWidth , ULONG * pHeight , BOOL * pIsInterleaved , double * pFrameRate )
{
    (void)pDevice;
    (void)iFmtNum;
    (void)pColorSpaceType;
    (void)pWidth;
    (void)pHeight;
    (void)pIsInterleaved;
    (void)pFrameRate;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_SUPPORT_OUTPUT_FORMAT(%s)\n", "pDevice, iFmtNum, pColorSpaceType, pWidth, pHeight, pIsInterleaved, pFrameRate");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_AUDIO_COUNT_OF_SUPPORT_OUTPUT_FORMATS(PVOID pDevice , ULONG * pCount )
{
    (void)pDevice;
    (void)pCount;
    fprintf(stderr, "Mock function called: QCAP_GET_AUDIO_COUNT_OF_SUPPORT_OUTPUT_FORMATS(%s)\n", "pDevice, pCount");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_AUDIO_SUPPORT_OUTPUT_FORMAT(PVOID pDevice , UINT iFmtNum , ULONG * pChannels , ULONG * pBitsPerSample , ULONG * pSampleFrequency )
{
    (void)pDevice;
    (void)iFmtNum;
    (void)pChannels;
    (void)pBitsPerSample;
    (void)pSampleFrequency;
    fprintf(stderr, "Mock function called: QCAP_GET_AUDIO_SUPPORT_OUTPUT_FORMAT(%s)\n", "pDevice, iFmtNum, pChannels, pBitsPerSample, pSampleFrequency");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_CURRENT_INPUT_FORMAT(PVOID pDevice , ULONG * pColorSpaceType , ULONG * pWidth , ULONG * pHeight , BOOL * pIsInterleaved , double * pFrameRate )
{
    (void)pDevice;
    (void)pColorSpaceType;
    (void)pWidth;
    (void)pHeight;
    (void)pIsInterleaved;
    (void)pFrameRate;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_CURRENT_INPUT_FORMAT(%s)\n", "pDevice, pColorSpaceType, pWidth, pHeight, pIsInterleaved, pFrameRate");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_CURRENT_INPUT_FORMAT_EX(PVOID pDevice , ULONG * pColorSpaceType , ULONG * pWidth , ULONG * pHeight , BOOL * pIsInterleaved , double * pNativeFrameRate , double * pGrabFrameRate )
{
    (void)pDevice;
    (void)pColorSpaceType;
    (void)pWidth;
    (void)pHeight;
    (void)pIsInterleaved;
    (void)pNativeFrameRate;
    (void)pGrabFrameRate;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_CURRENT_INPUT_FORMAT_EX(%s)\n", "pDevice, pColorSpaceType, pWidth, pHeight, pIsInterleaved, pNativeFrameRate, pGrabFrameRate");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_AUDIO_CURRENT_INPUT_FORMAT(PVOID pDevice , ULONG * pChannels , ULONG * pBitsPerSample , ULONG * pSampleFrequency )
{
    (void)pDevice;
    (void)pChannels;
    (void)pBitsPerSample;
    (void)pSampleFrequency;
    fprintf(stderr, "Mock function called: QCAP_GET_AUDIO_CURRENT_INPUT_FORMAT(%s)\n", "pDevice, pChannels, pBitsPerSample, pSampleFrequency");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_DEFAULT_OUTPUT_FORMAT(PVOID pDevice , ULONG * pColorSpaceType , ULONG * pWidth , ULONG * pHeight , BOOL * pIsInterleaved , double * pFrameRate )
{
    (void)pDevice;
    (void)pColorSpaceType;
    (void)pWidth;
    (void)pHeight;
    (void)pIsInterleaved;
    (void)pFrameRate;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_DEFAULT_OUTPUT_FORMAT(%s)\n", "pDevice, pColorSpaceType, pWidth, pHeight, pIsInterleaved, pFrameRate");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_DEFAULT_OUTPUT_FORMAT(PVOID pDevice , ULONG nColorSpaceType , ULONG nWidth , ULONG nHeight , BOOL bIsInterleaved , double dFrameRate )
{
    (void)pDevice;
    (void)nColorSpaceType;
    (void)nWidth;
    (void)nHeight;
    (void)bIsInterleaved;
    (void)dFrameRate;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_DEFAULT_OUTPUT_FORMAT(%s)\n", "pDevice, nColorSpaceType, nWidth, nHeight, bIsInterleaved, dFrameRate");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_AUDIO_DEFAULT_OUTPUT_FORMAT(PVOID pDevice , ULONG * pChannels , ULONG * pBitsPerSample , ULONG * pSampleFrequency )
{
    (void)pDevice;
    (void)pChannels;
    (void)pBitsPerSample;
    (void)pSampleFrequency;
    fprintf(stderr, "Mock function called: QCAP_GET_AUDIO_DEFAULT_OUTPUT_FORMAT(%s)\n", "pDevice, pChannels, pBitsPerSample, pSampleFrequency");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_DEFAULT_OUTPUT_FORMAT(PVOID pDevice , ULONG nChannels , ULONG nBitsPerSample , ULONG nSampleFrequency )
{
    (void)pDevice;
    (void)nChannels;
    (void)nBitsPerSample;
    (void)nSampleFrequency;
    fprintf(stderr, "Mock function called: QCAP_SET_AUDIO_DEFAULT_OUTPUT_FORMAT(%s)\n", "pDevice, nChannels, nBitsPerSample, nSampleFrequency");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_VERTICAL_ANCILLARY_DATA_GRABBED_LINES(PVOID pDevice , ULONG * pLines )
{
    (void)pDevice;
    (void)pLines;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_VERTICAL_ANCILLARY_DATA_GRABBED_LINES(%s)\n", "pDevice, pLines");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_VERTICAL_ANCILLARY_DATA_GRABBED_LINES(PVOID pDevice , ULONG nLines )
{
    (void)pDevice;
    (void)nLines;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_VERTICAL_ANCILLARY_DATA_GRABBED_LINES(%s)\n", "pDevice, nLines");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_DEINTERLACE_TYPE(PVOID pDevice , ULONG * pType )
{
    (void)pDevice;
    (void)pType;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_DEINTERLACE_TYPE(%s)\n", "pDevice, pType");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_DEINTERLACE_TYPE(PVOID pDevice , ULONG nType )
{
    (void)pDevice;
    (void)nType;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_DEINTERLACE_TYPE(%s)\n", "pDevice, nType");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_DEINTERLACE(PVOID pDevice , BOOL * pEnable )
{
    (void)pDevice;
    (void)pEnable;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_DEINTERLACE(%s)\n", "pDevice, pEnable");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_DEINTERLACE(PVOID pDevice , BOOL bEnable )
{
    (void)pDevice;
    (void)bEnable;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_DEINTERLACE(%s)\n", "pDevice, bEnable");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_HDR(PVOID pDevice , BOOL * pPhysicalEnable , BOOL * pDisplayEnable , BOOL * pIsDisplaySupported )
{
    (void)pDevice;
    (void)pPhysicalEnable;
    (void)pDisplayEnable;
    (void)pIsDisplaySupported;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_HDR(%s)\n", "pDevice, pPhysicalEnable, pDisplayEnable, pIsDisplaySupported");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_HDR(PVOID pDevice , BOOL bPhysicalEnable , BOOL bDisplayEnable )
{
    (void)pDevice;
    (void)bPhysicalEnable;
    (void)bDisplayEnable;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_HDR(%s)\n", "pDevice, bPhysicalEnable, bDisplayEnable");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_REGION_DISPLAY(PVOID pDevice , ULONG * pCropX , ULONG * pCropY , ULONG * pCropW , ULONG * pCropH )
{
    (void)pDevice;
    (void)pCropX;
    (void)pCropY;
    (void)pCropW;
    (void)pCropH;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_REGION_DISPLAY(%s)\n", "pDevice, pCropX, pCropY, pCropW, pCropH");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_REGION_DISPLAY(PVOID pDevice , ULONG nCropX , ULONG nCropY , ULONG nCropW , ULONG nCropH )
{
    (void)pDevice;
    (void)nCropX;
    (void)nCropY;
    (void)nCropW;
    (void)nCropH;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_REGION_DISPLAY(%s)\n", "pDevice, nCropX, nCropY, nCropW, nCropH");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_MIRROR(PVOID pDevice , BOOL * pHorizontalMirror , BOOL * pVerticalMirror )
{
    (void)pDevice;
    (void)pHorizontalMirror;
    (void)pVerticalMirror;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_MIRROR(%s)\n", "pDevice, pHorizontalMirror, pVerticalMirror");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_MIRROR(PVOID pDevice , BOOL bHorizontalMirror , BOOL bVerticalMirror )
{
    (void)pDevice;
    (void)bHorizontalMirror;
    (void)bVerticalMirror;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_MIRROR(%s)\n", "pDevice, bHorizontalMirror, bVerticalMirror");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_ASPECT_RATIO(PVOID pDevice , BOOL * pMaintainAspectRatio )
{
    (void)pDevice;
    (void)pMaintainAspectRatio;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_ASPECT_RATIO(%s)\n", "pDevice, pMaintainAspectRatio");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_ASPECT_RATIO(PVOID pDevice , BOOL bMaintainAspectRatio )
{
    (void)pDevice;
    (void)bMaintainAspectRatio;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_ASPECT_RATIO(%s)\n", "pDevice, bMaintainAspectRatio");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_BRIGHTNESS(PVOID pDevice , ULONG * pValue  /*PHYSICAL VALUE 0 ~ 255*/)
{
    (void)pDevice;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_BRIGHTNESS(%s)\n", "pDevice");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_BRIGHTNESS(PVOID pDevice , ULONG nValue  /*PHYSICAL VALUE 0 ~ 255*/)
{
    (void)pDevice;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_BRIGHTNESS(%s)\n", "pDevice");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_CONTRAST(PVOID pDevice , ULONG * pValue  /*PHYSICAL VALUE 0 ~ 255*/)
{
    (void)pDevice;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_CONTRAST(%s)\n", "pDevice");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_CONTRAST(PVOID pDevice , ULONG nValue  /*PHYSICAL VALUE 0 ~ 255*/)
{
    (void)pDevice;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_CONTRAST(%s)\n", "pDevice");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_HUE(PVOID pDevice , ULONG * pValue  /*PHYSICAL VALUE 0 ~ 255*/)
{
    (void)pDevice;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_HUE(%s)\n", "pDevice");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_HUE(PVOID pDevice , ULONG nValue  /*PHYSICAL VALUE 0 ~ 255*/)
{
    (void)pDevice;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_HUE(%s)\n", "pDevice");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_SATURATION(PVOID pDevice , ULONG * pValue  /*PHYSICAL VALUE 0 ~ 255*/)
{
    (void)pDevice;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_SATURATION(%s)\n", "pDevice");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_SATURATION(PVOID pDevice , ULONG nValue  /*PHYSICAL VALUE 0 ~ 255*/)
{
    (void)pDevice;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_SATURATION(%s)\n", "pDevice");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_SHARPNESS(PVOID pDevice , ULONG * pValue  /*PHYSICAL VALUE 0 ~ 255*/)
{
    (void)pDevice;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_SHARPNESS(%s)\n", "pDevice");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_SHARPNESS(PVOID pDevice , ULONG nValue  /*PHYSICAL VALUE 0 ~ 255*/)
{
    (void)pDevice;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_SHARPNESS(%s)\n", "pDevice");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_BRIGHTNESS_EX(PVOID pDevice , ULONG * pPhysicalValue  /*0 ~ 255*/, ULONG * pDisplayValue  /*0 ~ 255*/)
{
    (void)pDevice;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_BRIGHTNESS_EX(%s)\n", "pDevice");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_BRIGHTNESS_EX(PVOID pDevice , ULONG nPhysicalValue  /*0 ~ 255*/, ULONG nDisplayValue  /*0 ~ 255*/)
{
    (void)pDevice;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_BRIGHTNESS_EX(%s)\n", "pDevice");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_CONTRAST_EX(PVOID pDevice , ULONG * pPhysicalValue  /*0 ~ 255*/, ULONG * pDisplayValue  /*0 ~ 255*/)
{
    (void)pDevice;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_CONTRAST_EX(%s)\n", "pDevice");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_CONTRAST_EX(PVOID pDevice , ULONG nPhysicalValue  /*0 ~ 255*/, ULONG nDisplayValue  /*0 ~ 255*/)
{
    (void)pDevice;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_CONTRAST_EX(%s)\n", "pDevice");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_HUE_EX(PVOID pDevice , ULONG * pPhysicalValue  /*0 ~ 255*/, ULONG * pDisplayValue  /*0 ~ 255*/)
{
    (void)pDevice;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_HUE_EX(%s)\n", "pDevice");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_HUE_EX(PVOID pDevice , ULONG nPhysicalValue  /*0 ~ 255*/, ULONG nDisplayValue  /*0 ~ 255*/)
{
    (void)pDevice;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_HUE_EX(%s)\n", "pDevice");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_SATURATION_EX(PVOID pDevice , ULONG * pPhysicalValue  /*0 ~ 255*/, ULONG * pDisplayValue  /*0 ~ 255*/)
{
    (void)pDevice;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_SATURATION_EX(%s)\n", "pDevice");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_SATURATION_EX(PVOID pDevice , ULONG nPhysicalValue  /*0 ~ 255*/, ULONG nDisplayValue  /*0 ~ 255*/)
{
    (void)pDevice;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_SATURATION_EX(%s)\n", "pDevice");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_SHARPNESS_EX(PVOID pDevice , ULONG * pPhysicalValue  /*0 ~ 255*/, ULONG * pDisplayValue  /*0 ~ 255*/)
{
    (void)pDevice;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_SHARPNESS_EX(%s)\n", "pDevice");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_SHARPNESS_EX(PVOID pDevice , ULONG nPhysicalValue  /*0 ~ 255*/, ULONG nDisplayValue  /*0 ~ 255*/)
{
    (void)pDevice;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_SHARPNESS_EX(%s)\n", "pDevice");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_PROCAMP_PROPERTY_RANGE_EX(PVOID pDevice , ULONG nProperty , ULONG * pValue_Min , ULONG * pValue_Max , ULONG * pValue_Default )
{
    (void)pDevice;
    (void)nProperty;
    (void)pValue_Min;
    (void)pValue_Max;
    (void)pValue_Default;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_PROCAMP_PROPERTY_RANGE_EX(%s)\n", "pDevice, nProperty, pValue_Min, pValue_Max, pValue_Default");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_AUDIO_SOUND_RENDERER(PVOID pDevice , UINT * pSoundNum )
{
    (void)pDevice;
    (void)pSoundNum;
    fprintf(stderr, "Mock function called: QCAP_GET_AUDIO_SOUND_RENDERER(%s)\n", "pDevice, pSoundNum");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_SOUND_RENDERER(PVOID pDevice , UINT iSoundNum )
{
    (void)pDevice;
    (void)iSoundNum;
    fprintf(stderr, "Mock function called: QCAP_SET_AUDIO_SOUND_RENDERER(%s)\n", "pDevice, iSoundNum");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_AUDIO_VOLUME(PVOID pDevice , ULONG * pVolume )
{
    (void)pDevice;
    (void)pVolume;
    fprintf(stderr, "Mock function called: QCAP_GET_AUDIO_VOLUME(%s)\n", "pDevice, pVolume");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_VOLUME(PVOID pDevice , ULONG nVolume )
{
    (void)pDevice;
    (void)nVolume;
    fprintf(stderr, "Mock function called: QCAP_SET_AUDIO_VOLUME(%s)\n", "pDevice, nVolume");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_AUDIO_NOISE_REMOVAL(PVOID pDevice , ULONG * pStrength )
{
    (void)pDevice;
    (void)pStrength;
    fprintf(stderr, "Mock function called: QCAP_GET_AUDIO_NOISE_REMOVAL(%s)\n", "pDevice, pStrength");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_AUDIO_NOISE_REMOVAL(PVOID pDevice , ULONG nStrength )
{
    (void)pDevice;
    (void)nStrength;
    fprintf(stderr, "Mock function called: QCAP_SET_AUDIO_NOISE_REMOVAL(%s)\n", "pDevice, nStrength");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_KVM_KEYBOARD(PVOID pDevice , ULONG nVirtualKey , ULONG nInputKey )
{
    (void)pDevice;
    (void)nVirtualKey;
    (void)nInputKey;
    fprintf(stderr, "Mock function called: QCAP_SET_KVM_KEYBOARD(%s)\n", "pDevice, nVirtualKey, nInputKey");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_KVM_MOUSE(PVOID pDevice , ULONG nVirtualKey , INT nShiftX , INT nShiftY , INT nShiftScroll )
{
    (void)pDevice;
    (void)nVirtualKey;
    (void)nShiftX;
    (void)nShiftY;
    (void)nShiftScroll;
    fprintf(stderr, "Mock function called: QCAP_SET_KVM_MOUSE(%s)\n", "pDevice, nVirtualKey, nShiftX, nShiftY, nShiftScroll");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_KVM_TOUCH(PVOID pDevice , ULONG nPoints , INT * pPointX , INT * pPointY , BOOL * pIsPointTouch )
{
    (void)pDevice;
    (void)nPoints;
    (void)pPointX;
    (void)pPointY;
    (void)pIsPointTouch;
    fprintf(stderr, "Mock function called: QCAP_SET_KVM_TOUCH(%s)\n", "pDevice, nPoints, pPointX, pPointY, pIsPointTouch");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_DEVICE_CUSTOM_PROPERTY_PAGE(PVOID pDevice , HWND hAttachedWindow , UINT iPageNum )
{
    (void)pDevice;
    (void)hAttachedWindow;
    (void)iPageNum;
    fprintf(stderr, "Mock function called: QCAP_GET_DEVICE_CUSTOM_PROPERTY_PAGE(%s)\n", "pDevice, hAttachedWindow, iPageNum");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_DEVICE_CUSTOM_PROPERTY(PVOID pDevice , ULONG nProperty , ULONG * pValue )
{
    (void)pDevice;
    (void)nProperty;
    (void)pValue;
    fprintf(stderr, "Mock function called: QCAP_GET_DEVICE_CUSTOM_PROPERTY(%s)\n", "pDevice, nProperty, pValue");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_DEVICE_CUSTOM_PROPERTY(PVOID pDevice , ULONG nProperty , ULONG nValue )
{
    (void)pDevice;
    (void)nProperty;
    (void)nValue;
    fprintf(stderr, "Mock function called: QCAP_SET_DEVICE_CUSTOM_PROPERTY(%s)\n", "pDevice, nProperty, nValue");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_DEVICE_CUSTOM_PROPERTY_EX(PVOID pDevice , ULONG nProperty , BYTE * pValue , ULONG nBytes )
{
    (void)pDevice;
    (void)nProperty;
    (void)pValue;
    (void)nBytes;
    fprintf(stderr, "Mock function called: QCAP_GET_DEVICE_CUSTOM_PROPERTY_EX(%s)\n", "pDevice, nProperty, pValue, nBytes");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_DEVICE_CUSTOM_PROPERTY_EX(PVOID pDevice , ULONG nProperty , BYTE * pValue , ULONG nBytes )
{
    (void)pDevice;
    (void)nProperty;
    (void)pValue;
    (void)nBytes;
    fprintf(stderr, "Mock function called: QCAP_SET_DEVICE_CUSTOM_PROPERTY_EX(%s)\n", "pDevice, nProperty, pValue, nBytes");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DIAGNOSE_VIDEO_STREAM_DIFF_SHIFT(PVOID pDevice , double * pShiftX , double * pShiftY , ULONG nScanWindowSize , ULONG nScanStepSize )
{
    (void)pDevice;
    (void)pShiftX;
    (void)pShiftY;
    (void)nScanWindowSize;
    (void)nScanStepSize;
    fprintf(stderr, "Mock function called: QCAP_DIAGNOSE_VIDEO_STREAM_DIFF_SHIFT(%s)\n", "pDevice, pShiftX, pShiftY, nScanWindowSize, nScanStepSize");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DIAGNOSE_VIDEO_STREAM_STATUS(PVOID pDevice , BOOL * pIsStill , ULONG nStillThreshold )
{
    (void)pDevice;
    (void)pIsStill;
    (void)nStillThreshold;
    fprintf(stderr, "Mock function called: QCAP_DIAGNOSE_VIDEO_STREAM_STATUS(%s)\n", "pDevice, pIsStill, nStillThreshold");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DIAGNOSE_AUDIO_STREAM_STATUS(PVOID pDevice , double * pVolumeDB_L  /*RANGE = -100 ~ 0 (DB)*/, double * pVolumeDB_R  /*RANGE = -100 ~ 0 (DB)*/)
{
    (void)pDevice;
    fprintf(stderr, "Mock function called: QCAP_DIAGNOSE_AUDIO_STREAM_STATUS(%s)\n", "pDevice");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_NO_SIGNAL_DETECTED_CALLBACK(PVOID pDevice , PF_NO_SIGNAL_DETECTED_CALLBACK pCB , PVOID pUserData )
{
    (void)pDevice;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_NO_SIGNAL_DETECTED_CALLBACK(%s)\n", "pDevice, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_SIGNAL_REMOVED_CALLBACK(PVOID pDevice , PF_SIGNAL_REMOVED_CALLBACK pCB , PVOID pUserData )
{
    (void)pDevice;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_SIGNAL_REMOVED_CALLBACK(%s)\n", "pDevice, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_FORMAT_CHANGED_CALLBACK(PVOID pDevice , PF_FORMAT_CHANGED_CALLBACK pCB , PVOID pUserData )
{
    (void)pDevice;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_FORMAT_CHANGED_CALLBACK(%s)\n", "pDevice, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_FORMAT_CHANGED_CALLBACK_EX(PVOID pDevice , PF_FORMAT_CHANGED_CALLBACK_EX pCB , PVOID pUserData )
{
    (void)pDevice;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_FORMAT_CHANGED_CALLBACK_EX(%s)\n", "pDevice, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_VIDEO_VERTICAL_ANCILLARY_DATA_CALLBACK(PVOID pDevice , PF_VIDEO_VERTICAL_ANCILLARY_DATA_CALLBACK pCB , PVOID pUserData )
{
    (void)pDevice;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_VIDEO_VERTICAL_ANCILLARY_DATA_CALLBACK(%s)\n", "pDevice, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_VIDEO_PREVIEW_CALLBACK(PVOID pDevice , PF_VIDEO_PREVIEW_CALLBACK pCB , PVOID pUserData )
{
    (void)pDevice;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_VIDEO_PREVIEW_CALLBACK(%s)\n", "pDevice, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_AUDIO_PREVIEW_CALLBACK(PVOID pDevice , PF_AUDIO_PREVIEW_CALLBACK pCB , PVOID pUserData )
{
    (void)pDevice;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_AUDIO_PREVIEW_CALLBACK(%s)\n", "pDevice, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_VIDEO_HARDWARE_ENCODER_CALLBACK(PVOID pDevice , UINT iRecNum , PF_VIDEO_HARDWARE_ENCODER_CALLBACK pCB , PVOID pUserData )
{
    (void)pDevice;
    (void)iRecNum;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_VIDEO_HARDWARE_ENCODER_CALLBACK(%s)\n", "pDevice, iRecNum, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_ALLOC_VIDEO_GPUDIRECT_PREVIEW_BUFFER(PVOID pDevice , BYTE * * ppFrameBuffer , ULONG nFrameBufferLen )
{
    (void)pDevice;
    (void)ppFrameBuffer;
    (void)nFrameBufferLen;
    fprintf(stderr, "Mock function called: QCAP_ALLOC_VIDEO_GPUDIRECT_PREVIEW_BUFFER(%s)\n", "pDevice, ppFrameBuffer, nFrameBufferLen");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_FREE_VIDEO_GPUDIRECT_PREVIEW_BUFFER(PVOID pDevice , BYTE * pFrameBuffer , ULONG nFrameBufferLen )
{
    (void)pDevice;
    (void)pFrameBuffer;
    (void)nFrameBufferLen;
    fprintf(stderr, "Mock function called: QCAP_FREE_VIDEO_GPUDIRECT_PREVIEW_BUFFER(%s)\n", "pDevice, pFrameBuffer, nFrameBufferLen");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_BIND_VIDEO_GPUDIRECT_PREVIEW_BUFFER(PVOID pDevice , UINT iFrameNum , BYTE * pFrameBuffer , ULONG nFrameBufferLen )
{
    (void)pDevice;
    (void)iFrameNum;
    (void)pFrameBuffer;
    (void)nFrameBufferLen;
    fprintf(stderr, "Mock function called: QCAP_BIND_VIDEO_GPUDIRECT_PREVIEW_BUFFER(%s)\n", "pDevice, iFrameNum, pFrameBuffer, nFrameBufferLen");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_UNBIND_VIDEO_GPUDIRECT_PREVIEW_BUFFER(PVOID pDevice , UINT iFrameNum , BYTE * pFrameBuffer , ULONG nFrameBufferLen )
{
    (void)pDevice;
    (void)iFrameNum;
    (void)pFrameBuffer;
    (void)nFrameBufferLen;
    fprintf(stderr, "Mock function called: QCAP_UNBIND_VIDEO_GPUDIRECT_PREVIEW_BUFFER(%s)\n", "pDevice, iFrameNum, pFrameBuffer, nFrameBufferLen");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VIDEO_GPUDIRECT_PREVIEW_QUEUE_SIZE(PVOID pDevice , ULONG * pTotalFrames )
{
    (void)pDevice;
    (void)pTotalFrames;
    fprintf(stderr, "Mock function called: QCAP_GET_VIDEO_GPUDIRECT_PREVIEW_QUEUE_SIZE(%s)\n", "pDevice, pTotalFrames");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_VIDEO_GPUDIRECT_PREVIEW_QUEUE_SIZE(PVOID pDevice , ULONG nTotalFrames )
{
    (void)pDevice;
    (void)nTotalFrames;
    fprintf(stderr, "Mock function called: QCAP_SET_VIDEO_GPUDIRECT_PREVIEW_QUEUE_SIZE(%s)\n", "pDevice, nTotalFrames");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COPY_VIDEO_PREVIEW_BUFFER(PVOID pDevice , double * pSampleTime , ULONG nColorSpaceType , VOID * pFrameBuffer , ULONG * pFrameBufferLen /*IN/OUT*/)
{
    (void)pDevice;
    (void)pSampleTime;
    (void)nColorSpaceType;
    (void)pFrameBuffer;
    fprintf(stderr, "Mock function called: QCAP_COPY_VIDEO_PREVIEW_BUFFER(%s)\n", "pDevice, pSampleTime, nColorSpaceType, pFrameBuffer");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_COPY_AUDIO_PREVIEW_BUFFER(PVOID pDevice , double * pSampleTime , VOID * pFrameBuffer , ULONG * pFrameBufferLen /*IN/OUT*/)
{
    (void)pDevice;
    (void)pSampleTime;
    (void)pFrameBuffer;
    fprintf(stderr, "Mock function called: QCAP_COPY_AUDIO_PREVIEW_BUFFER(%s)\n", "pDevice, pSampleTime, pFrameBuffer");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_LOCK_VIDEO_PREVIEW_BUFFER(PVOID pDevice , double * pSampleTime , VOID * * ppFrameBuffer , ULONG * pFrameBufferLen )
{
    (void)pDevice;
    (void)pSampleTime;
    (void)ppFrameBuffer;
    (void)pFrameBufferLen;
    fprintf(stderr, "Mock function called: QCAP_LOCK_VIDEO_PREVIEW_BUFFER(%s)\n", "pDevice, pSampleTime, ppFrameBuffer, pFrameBufferLen");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_UNLOCK_VIDEO_PREVIEW_BUFFER(PVOID pDevice )
{
    (void)pDevice;
    fprintf(stderr, "Mock function called: QCAP_UNLOCK_VIDEO_PREVIEW_BUFFER(%s)\n", "pDevice");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_LOCK_AUDIO_PREVIEW_BUFFER(PVOID pDevice , double * pSampleTime , VOID * * ppFrameBuffer , ULONG * pFrameBufferLen )
{
    (void)pDevice;
    (void)pSampleTime;
    (void)ppFrameBuffer;
    (void)pFrameBufferLen;
    fprintf(stderr, "Mock function called: QCAP_LOCK_AUDIO_PREVIEW_BUFFER(%s)\n", "pDevice, pSampleTime, ppFrameBuffer, pFrameBufferLen");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_UNLOCK_AUDIO_PREVIEW_BUFFER(PVOID pDevice )
{
    (void)pDevice;
    fprintf(stderr, "Mock function called: QCAP_UNLOCK_AUDIO_PREVIEW_BUFFER(%s)\n", "pDevice");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SNAPSHOT_BMP(PVOID pDevice , CHAR * pszFilePathName , BOOL bIsAsync , ULONG nMilliseconds )
{
    (void)pDevice;
    (void)pszFilePathName;
    (void)bIsAsync;
    (void)nMilliseconds;
    fprintf(stderr, "Mock function called: QCAP_SNAPSHOT_BMP(%s)\n", "pDevice, pszFilePathName, bIsAsync, nMilliseconds");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SNAPSHOT_JPG(PVOID pDevice , CHAR * pszFilePathName , ULONG nQuality , BOOL bIsAsync , ULONG nMilliseconds )
{
    (void)pDevice;
    (void)pszFilePathName;
    (void)nQuality;
    (void)bIsAsync;
    (void)nMilliseconds;
    fprintf(stderr, "Mock function called: QCAP_SNAPSHOT_JPG(%s)\n", "pDevice, pszFilePathName, nQuality, bIsAsync, nMilliseconds");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SNAPSHOT_BMP_EX(PVOID pDevice , CHAR * pszFilePathName , ULONG nCropX , ULONG nCropY , ULONG nCropW , ULONG nCropH , ULONG nDstW , ULONG nDstH , BOOL bIsAsync , ULONG nMilliseconds )
{
    (void)pDevice;
    (void)pszFilePathName;
    (void)nCropX;
    (void)nCropY;
    (void)nCropW;
    (void)nCropH;
    (void)nDstW;
    (void)nDstH;
    (void)bIsAsync;
    (void)nMilliseconds;
    fprintf(stderr, "Mock function called: QCAP_SNAPSHOT_BMP_EX(%s)\n", "pDevice, pszFilePathName, nCropX, nCropY, nCropW, nCropH, nDstW, nDstH, bIsAsync, nMilliseconds");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SNAPSHOT_JPG_EX(PVOID pDevice , CHAR * pszFilePathName , ULONG nCropX , ULONG nCropY , ULONG nCropW , ULONG nCropH , ULONG nDstW , ULONG nDstH , ULONG nQuality , BOOL bIsAsync , ULONG nMilliseconds )
{
    (void)pDevice;
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
    fprintf(stderr, "Mock function called: QCAP_SNAPSHOT_JPG_EX(%s)\n", "pDevice, pszFilePathName, nCropX, nCropY, nCropW, nCropH, nDstW, nDstH, nQuality, bIsAsync, nMilliseconds");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_SNAPSHOT_DONE_CALLBACK(PVOID pDevice , PF_SNAPSHOT_DONE_CALLBACK pCB , PVOID pUserData )
{
    (void)pDevice;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_SNAPSHOT_DONE_CALLBACK(%s)\n", "pDevice, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_SNAPSHOT_STREAM_CALLBACK(PVOID pDevice , PF_SNAPSHOT_STREAM_CALLBACK pCB , PVOID pUserData )
{
    (void)pDevice;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_SNAPSHOT_STREAM_CALLBACK(%s)\n", "pDevice, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_CLONE(PVOID pDevice , HWND hAttachedWindow , PVOID * ppCloneDevice , BOOL bThumbDraw , BOOL bMaintainAspectRatio )
{
    (void)pDevice;
    (void)hAttachedWindow;
    (void)ppCloneDevice;
    (void)bThumbDraw;
    (void)bMaintainAspectRatio;
    fprintf(stderr, "Mock function called: QCAP_CREATE_CLONE(%s)\n", "pDevice, hAttachedWindow, ppCloneDevice, bThumbDraw, bMaintainAspectRatio");
    return QCAP_RS_SUCCESSFUL;
}

