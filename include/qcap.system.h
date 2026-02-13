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

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_SYSTEM_DEBUG_LEVEL( ULONG nDebugMsgLevel /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_SYSTEM_CONFIGURATION( BOOL   bEnableMultipleUsersAccess,					 /*IN*/
															    BOOL   bEnableVideoPreviewDevice,					 /*IN*/
															    BOOL   bEnableAudioPreviewDevice,					 /*IN*/
															    BOOL   bEnableVideoHardwareMainEncoderDevice,		 /*IN*/
															    BOOL   bEnableVideoHardwareSubEncoderDevice,			 /*IN*/
															    ULONG  nAutoInputDetectionTimeout,					 /*IN*/
															    BOOL   bEnableSCF,									 /*IN*/
															    CHAR * pszDB3,										 /*IN*/
															    BOOL   bEnableAsyncBackgroundSnapshot,				 /*IN*/
															    BOOL   bEnableEnhancedVideoRenderer,					 /*IN*/
															    BOOL   bEnableSystemTimeCallback,					 /*IN*/
															    BOOL   bEnableFileRepairFunction,					 /*IN*/
															    BOOL   bEnableNewRTSPLibrary,						 /*IN*/
																CHAR * pszWebServerRootFolderPath,					 /*IN*/
																CHAR * pszWebServerIP,								 /*IN*/
																ULONG  nSystemColorRangeType,    /*IN*/
																BOOL   bEnableVideoMixingRendererBugPatch,            /*IN*/
																ULONG  nEnableCustomVideoRenderer,              /*IN*/
																BOOL   bEnableGraphicMemoryForVideoEncoder,          /*IN*/
																BOOL   bEnableSingleGraphCaptureMode,				 /*IN*/
																ULONG  nSignalDetectionDuration,                      /*IN*/
																BOOL   bEnableNewChromaKeyLibrary,                   /*IN*/
																BOOL   bEnableNewSnapshotLibrary,                     /*IN*/
																BOOL   bEnableAppleOnFlyMP4Editing,                  /*IN*/
																BOOL   bEnableNewSoftwareEncoderLibrary );           /*IN*/
																	
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_QUERY_ENCODER_TYPE_CAP( UINT iGpuNum /*IN*/, ULONG nEncoderType /*IN*/, ULONG nEncoderFormat /*IN*/, CHAR * * ppszGpuDevName /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_QUERY_DECODER_TYPE_CAP( UINT iGpuNum /*IN*/, ULONG nDecoderType /*IN*/, ULONG nDecoderFormat /*IN*/, CHAR * * ppszGpuDevName /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_QUERY_ENCODER_STATUS( UINT iGpuNum /*IN*/, ULONG nEncoderType /*IN*/, ULONG * pExistInstances /*OUT*/ );

#ifdef __cplusplus
}
#endif

#endif // QCAP_SYSTEM_H
