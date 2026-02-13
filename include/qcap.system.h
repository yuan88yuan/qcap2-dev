#ifndef QCAP_SYSTEM_H
#define QCAP_SYSTEM_H

#include "qcap.callbacks.h"

#ifdef __cplusplus
extern "C"
{
#endif

// SYSTEM FUNCTIONS /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
typedef VOID (QCAP_EXPORT *PF_EXTERNAL_DEBUG_CALLBACK)( CHAR * pszDebugDumpMessage );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_EXTERNAL_DEBUG_FUNCTION( PF_EXTERNAL_DEBUG_CALLBACK pDebugCB /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_VERSION( ULONG * pMajorVersion /*OUT*/, ULONG * pMinorVersion /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_SYSTEM_DEBUG_LEVEL( ULONG nDebugMsgLevel DEFVAL( 0x00000000 /*IN*/ /*SHOW = 0 / HIDE = 1*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_SYSTEM_CONFIGURATION( BOOL   bEnableMultipleUsersAccess DEFVAL( TRUE),					 /*IN*/ // If true, qcap will alllow multiple users to access the device.
															    BOOL   bEnableVideoPreviewDevice DEFVAL( TRUE),					 /*IN*/ // If true, the video capture device will be enabled.
															    BOOL   bEnableAudioPreviewDevice DEFVAL( TRUE),					 /*IN*/ // If true, the audio capture device will be enabled.
															    BOOL   bEnableVideoHardwareMainEncoderDevice DEFVAL( TRUE),		 /*IN*/ // If true, the main hardware encoder will be enabled.
															    BOOL   bEnableVideoHardwareSubEncoderDevice DEFVAL( TRUE),			 /*IN*/ // If true, the sub hardware encoder will be enabled.
															    ULONG  nAutoInputDetectionTimeout DEFVAL( 3000),					 /*IN*/ // The parameter allows you to specify the timeout duration of the auto input detection, default is 3sec.
															    BOOL   bEnableSCF DEFVAL( FALSE),									 /*IN*/ // If true, the SCF file recording function will be turned on.
															    CHAR * pszDB3 DEFVAL( NULL),										 /*IN*/ // The parameter allows you to specify the file path of SQL database.
															    BOOL   bEnableAsyncBackgroundSnapshot DEFVAL( FALSE),				 /*IN*/ // If true, snapshot function will be moved from preview callback into another thread. 
															    BOOL   bEnableEnhancedVideoRenderer DEFVAL( TRUE),					 /*IN*/ // If true, QCAP will enable the DirectShow's Enhanced Video Renderer Filter.
															    BOOL   bEnableSystemTimeCallback DEFVAL( FALSE),					 /*IN*/ // If true, the preview's and encoder's callbacks will return one local system time at dSampleTime.
															    BOOL   bEnableFileRepairFunction DEFVAL( TRUE),					 /*IN*/ // If true, the recording file will own self-repaired ability.
															    BOOL   bEnableNewRTSPLibrary DEFVAL( TRUE),						 /*IN*/ // If true, we will use new rtsp lib to repalce old one after 1.1.0.130.0
																CHAR * pszWebServerRootFolderPath DEFVAL( NULL),					 /*IN*/ // The parameter allows you to specify the web server's root folder path.
																CHAR * pszWebServerIP DEFVAL( NULL),								 /*IN*/ // The parameter allows you to specify the web server's ip address.
																ULONG  nSystemColorRangeType DEFVAL( QCAP_COLORRANGE_TYPE_FULL),    /*IN*/ // The parameter allows you to specify the system color range setting.
																BOOL   bEnableVideoMixingRendererBugPatch DEFVAL( TRUE),            /*IN*/ // If true, QCAP will enable the bug patch for DirectShow's Video Mixing Renderer, but it will delay the device's initialized time.
																ULONG  nEnableCustomVideoRenderer DEFVAL( 0x00000000),              /*IN*/ // If non-zero, QCAP will enable the Custom Video Renderer as major display engine.
																BOOL   bEnableGraphicMemoryForVideoEncoder DEFVAL( FALSE),          /*IN*/ // If true, QCAP will use the graph memory for all gpu encoders.
																BOOL   bEnableSingleGraphCaptureMode DEFVAL( FALSE),				 /*IN*/ // If true, QCAP will use single DirectShow's graph to capture video and audio streams.
																ULONG  nSignalDetectionDuration DEFVAL( 1000),                      /*IN*/ // The parameter allows you to specify the duration of the signal detection, default is 1sec.
																BOOL   bEnableNewChromaKeyLibrary DEFVAL( FALSE),                   /*IN*/ // If true, we will use new chroma key lib to repalce old one after 1.1.0.183.5            
																BOOL   bEnableNewSnapshotLibrary DEFVAL( TRUE),                     /*IN*/ // If true, we will use new chroma key lib to repalce old one after 1.1.0.183.5            
																BOOL   bEnableAppleOnFlyMP4Editing DEFVAL( FALSE),                  /*IN*/ // If true, we will enable mp4 file to support onfly editing function for apple             
																BOOL   bEnableNewSoftwareEncoderLibrary DEFVAL( FALSE ));           /*IN*/ // If true, we will use new software encoder lib to repalce old one after 1.1.0.192.3                 
																	
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_QUERY_ENCODER_TYPE_CAP( UINT iGpuNum /*IN*/, ULONG nEncoderType /*IN*/, ULONG nEncoderFormat /*IN*/, CHAR * * ppszGpuDevName DEFVAL( NULL /*OUT*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_QUERY_DECODER_TYPE_CAP( UINT iGpuNum /*IN*/, ULONG nDecoderType /*IN*/, ULONG nDecoderFormat /*IN*/, CHAR * * ppszGpuDevName DEFVAL( NULL /*OUT*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_QUERY_ENCODER_STATUS( UINT iGpuNum /*IN*/, ULONG nEncoderType /*IN*/, ULONG * pExistInstances /*OUT*/ );

#ifdef __cplusplus
}
#endif

#endif // QCAP_SYSTEM_H
