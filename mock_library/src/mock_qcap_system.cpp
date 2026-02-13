#include "mock_qcap_system.h"
#include <cstdio> // For fprintf, stderr

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_EXTERNAL_DEBUG_FUNCTION(PF_EXTERNAL_DEBUG_CALLBACK pDebugCB )
{
    (void)pDebugCB;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_EXTERNAL_DEBUG_FUNCTION(%s)\n", "pDebugCB");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VERSION(ULONG * pMajorVersion , ULONG * pMinorVersion )
{
    (void)pMajorVersion;
    (void)pMinorVersion;
    fprintf(stderr, "Mock function called: QCAP_GET_VERSION(%s)\n", "pMajorVersion, pMinorVersion");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_SYSTEM_DEBUG_LEVEL(ULONG nDebugMsgLevel )
{
    (void)nDebugMsgLevel;
    fprintf(stderr, "Mock function called: QCAP_SET_SYSTEM_DEBUG_LEVEL(%s)\n", "nDebugMsgLevel");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_SYSTEM_CONFIGURATION(BOOL   bEnableMultipleUsersAccess ,					  // If true, qcap will alllow multiple users to access the device.
															    BOOL   bEnableVideoPreviewDevice ,					  // If true, the video capture device will be enabled.
															    BOOL   bEnableAudioPreviewDevice ,					  // If true, the audio capture device will be enabled.
															    BOOL   bEnableVideoHardwareMainEncoderDevice ,		  // If true, the main hardware encoder will be enabled.
															    BOOL   bEnableVideoHardwareSubEncoderDevice ,			  // If true, the sub hardware encoder will be enabled.
															    ULONG  nAutoInputDetectionTimeout ,					  // The parameter allows you to specify the timeout duration of the auto input detection, default is 3sec.
															    BOOL   bEnableSCF ,									  // If true, the SCF file recording function will be turned on.
															    CHAR * pszDB3 ,										  // The parameter allows you to specify the file path of SQL database.
															    BOOL   bEnableAsyncBackgroundSnapshot ,				  // If true, snapshot function will be moved from preview callback into another thread. 
															    BOOL   bEnableEnhancedVideoRenderer ,					  // If true, QCAP will enable the DirectShow's Enhanced Video Renderer Filter.
															    BOOL   bEnableSystemTimeCallback ,					  // If true, the preview's and encoder's callbacks will return one local system time at dSampleTime.
															    BOOL   bEnableFileRepairFunction ,					  // If true, the recording file will own self-repaired ability.
															    BOOL   bEnableNewRTSPLibrary ,						  // If true, we will use new rtsp lib to repalce old one after 1.1.0.130.0
																CHAR * pszWebServerRootFolderPath ,					  // The parameter allows you to specify the web server's root folder path.
																CHAR * pszWebServerIP ,								  // The parameter allows you to specify the web server's ip address.
																ULONG  nSystemColorRangeType ,     // The parameter allows you to specify the system color range setting.
																BOOL   bEnableVideoMixingRendererBugPatch ,             // If true, QCAP will enable the bug patch for DirectShow's Video Mixing Renderer, but it will delay the device's initialized time.
																ULONG  nEnableCustomVideoRenderer ,               // If non-zero, QCAP will enable the Custom Video Renderer as major display engine.
																BOOL   bEnableGraphicMemoryForVideoEncoder ,           // If true, QCAP will use the graph memory for all gpu encoders.
																BOOL   bEnableSingleGraphCaptureMode ,				  // If true, QCAP will use single DirectShow's graph to capture video and audio streams.
																ULONG  nSignalDetectionDuration ,                       // The parameter allows you to specify the duration of the signal detection, default is 1sec.
																BOOL   bEnableNewChromaKeyLibrary ,                    // If true, we will use new chroma key lib to repalce old one after 1.1.0.183.5            
																BOOL   bEnableNewSnapshotLibrary ,                      // If true, we will use new chroma key lib to repalce old one after 1.1.0.183.5            
																BOOL   bEnableAppleOnFlyMP4Editing ,                   // If true, we will enable mp4 file to support onfly editing function for apple             
																BOOL   bEnableNewSoftwareEncoderLibrary )
{
    (void)bEnableMultipleUsersAccess;
    (void)true;
    (void)bEnableVideoPreviewDevice;
    (void)true;
    (void)bEnableAudioPreviewDevice;
    (void)true;
    (void)bEnableVideoHardwareMainEncoderDevice;
    (void)true;
    (void)bEnableVideoHardwareSubEncoderDevice;
    (void)true;
    (void)nAutoInputDetectionTimeout;
    (void)detection;
    (void)bEnableSCF;
    (void)true;
    (void)pszDB3;
    (void)bEnableAsyncBackgroundSnapshot;
    (void)true;
    (void)bEnableEnhancedVideoRenderer;
    (void)true;
    (void)bEnableSystemTimeCallback;
    (void)true;
    (void)bEnableFileRepairFunction;
    (void)true;
    (void)bEnableNewRTSPLibrary;
    (void)true;
    (void)pszWebServerRootFolderPath;
    (void)pszWebServerIP;
    (void)nSystemColorRangeType;
    (void)bEnableVideoMixingRendererBugPatch;
    (void)true;
    (void)Renderer;
    (void)nEnableCustomVideoRenderer;
    (void)zero;
    (void)bEnableGraphicMemoryForVideoEncoder;
    (void)true;
    (void)bEnableSingleGraphCaptureMode;
    (void)true;
    (void)nSignalDetectionDuration;
    (void)detection;
    (void)bEnableNewChromaKeyLibrary;
    (void)true;
    (void)bEnableNewSnapshotLibrary;
    (void)true;
    (void)bEnableAppleOnFlyMP4Editing;
    (void)true;
    (void)bEnableNewSoftwareEncoderLibrary;
    fprintf(stderr, "Mock function called: QCAP_SET_SYSTEM_CONFIGURATION(%s)\n", "bEnableMultipleUsersAccess, true, bEnableVideoPreviewDevice, true, bEnableAudioPreviewDevice, true, bEnableVideoHardwareMainEncoderDevice, true, bEnableVideoHardwareSubEncoderDevice, true, nAutoInputDetectionTimeout, detection, bEnableSCF, true, pszDB3, bEnableAsyncBackgroundSnapshot, true, bEnableEnhancedVideoRenderer, true, bEnableSystemTimeCallback, true, bEnableFileRepairFunction, true, bEnableNewRTSPLibrary, true, pszWebServerRootFolderPath, pszWebServerIP, nSystemColorRangeType, bEnableVideoMixingRendererBugPatch, true, Renderer, nEnableCustomVideoRenderer, zero, bEnableGraphicMemoryForVideoEncoder, true, bEnableSingleGraphCaptureMode, true, nSignalDetectionDuration, detection, bEnableNewChromaKeyLibrary, true, bEnableNewSnapshotLibrary, true, bEnableAppleOnFlyMP4Editing, true, bEnableNewSoftwareEncoderLibrary");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_QUERY_ENCODER_TYPE_CAP(UINT iGpuNum , ULONG nEncoderType , ULONG nEncoderFormat , CHAR * * ppszGpuDevName )
{
    (void)iGpuNum;
    (void)nEncoderType;
    (void)nEncoderFormat;
    (void)ppszGpuDevName;
    fprintf(stderr, "Mock function called: QCAP_QUERY_ENCODER_TYPE_CAP(%s)\n", "iGpuNum, nEncoderType, nEncoderFormat, ppszGpuDevName");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_QUERY_DECODER_TYPE_CAP(UINT iGpuNum , ULONG nDecoderType , ULONG nDecoderFormat , CHAR * * ppszGpuDevName )
{
    (void)iGpuNum;
    (void)nDecoderType;
    (void)nDecoderFormat;
    (void)ppszGpuDevName;
    fprintf(stderr, "Mock function called: QCAP_QUERY_DECODER_TYPE_CAP(%s)\n", "iGpuNum, nDecoderType, nDecoderFormat, ppszGpuDevName");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_QUERY_ENCODER_STATUS(UINT iGpuNum , ULONG nEncoderType , ULONG * pExistInstances )
{
    (void)iGpuNum;
    (void)nEncoderType;
    (void)pExistInstances;
    fprintf(stderr, "Mock function called: QCAP_QUERY_ENCODER_STATUS(%s)\n", "iGpuNum, nEncoderType, pExistInstances");
    return QCAP_RS_SUCCESSFUL;
}

