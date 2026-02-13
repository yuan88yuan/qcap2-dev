#ifndef MOCK_QCAP_DICOM_H
#define MOCK_QCAP_DICOM_H

#include "qcap_mock_common.h"

#ifdef __cplusplus
extern "C"
{
#endif

// Function Declarations
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_DICOM_WORKSTATION(CHAR * pszServerIP /*IN*/, ULONG nServerPort /*IN*/, CHAR * pszServerApplicationEntityTitle /*IN*/, CHAR * pszClientApplicationEntityTitle /*IN*/, PVOID * ppStation /*OUT*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_DICOM_WORKSTATION(PVOID pStation /*IN*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_DICOM_WORKSTATION(PVOID pStation /*IN*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_DICOM_WORKSTATION(PVOID pStation /*IN*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_DICOM_QUERY_OPERATION_CONDITION_100(PVOID   pStation,                     /*IN*/
																							    							  
																				  CHAR *  pszAccessionNumber,           /*IN*/
																		 	    								
																				  CHAR *  pszReferringPhysicianName,    /*IN*/
																		 	    								
																				  CHAR *  pszPatientName,               /*IN*/
																		 	    								
																				  CHAR *  pszPatientID,                 /*IN*/
  																		 	    								
																				  CHAR *  pszPerformingPhysicianName,   /*IN*/
																				  	    											  
																				  CHAR *  pszModality,                  /*IN*/	
																		 	    									    											  
																				  CHAR *  pszProcedureStepStartDate);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_DICOM_QUERY_OPERATION_CONDITION_192(PVOID   pStation,                     /*IN*/
																							    							  
																				  WSTRING pwszAccessionNumber,          /*IN*/
																		 											
																				  WSTRING pwszReferringPhysicianName,   /*IN*/
																		 											
																				  WSTRING pwszPatientName,              /*IN*/
																		 											
																				  WSTRING pwszPatientID,                /*IN*/
  																		 											
																				  WSTRING pwszPerformingPhysicianName,  /*IN*/
																		 																								  	    											  
																				  WSTRING pwszModality,                 /*IN*/	
					    													
																				  WSTRING pwszProcedureStepStartDate);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_DICOM_DOWNLOAD_OPERATION_CONDITION_100(PVOID   pStation,                     /*IN*/
																							    							  
																				  CHAR *  pszAccessionNumber,           /*IN*/
																		 	    								
																				  CHAR *  pszReferringPhysicianName,    /*IN*/
																		 	    								
																				  CHAR *  pszPatientName,               /*IN*/
																		 	    								
																				  CHAR *  pszPatientID,                 /*IN*/
  																		 	    								
																				  CHAR *  pszPerformingPhysicianName,   /*IN*/
																		 	    									    											  
																				  CHAR *  pszProcedureStepStartDate,    /*IN*/
																		 	    								
																				  CHAR *  pszStudyInstanceUID);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_DICOM_DOWNLOAD_OPERATION_CONDITION_192(PVOID   pStation,                     /*IN*/
																							    							  
																				  WSTRING pwszAccessionNumber,          /*IN*/
																		 	    										
																				  WSTRING pwszReferringPhysicianName,   /*IN*/
																		 	    										
																				  WSTRING pwszPatientName,              /*IN*/
																		 	    										
																				  WSTRING pwszPatientID,                /*IN*/
  																		 	    										
																				  WSTRING pwszPerformingPhysicianName,  /*IN*/
																		 	    								    													  
																				  WSTRING pwszProcedureStepStartDate,   /*IN*/
																		 	    										
																				  WSTRING pwszStudyInstanceUID);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_DICOM_QUERY_OPERATION(PVOID pStation /*IN*/, CHAR * pszClientApplicationEntityTitle /*IN*/, BOOL bReplyFullData DEFVAL( FALSE /*IN*/), BOOL bReplyDataAtOneTime DEFVAL( FALSE /*IN*/), BOOL bReplyDataByJSON DEFVAL( FALSE /*IN*/ /*0 = TEXT, 1 = JSON*/ ));
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_DICOM_QUERY_OPERATION(PVOID pStation /*IN*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_DICOM_DOWNLOAD_OPERATION(PVOID pStation /*IN*/, CHAR * pszClientApplicationEntityTitle /*IN*/, ULONG nClientPort /*IN*/, CHAR * pszDownloadFolderPath /*IN*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_DICOM_DOWNLOAD_OPERATION(PVOID pStation /*IN*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_DICOM_UPLOAD_FOLDER_OPERATION(PVOID pStation /*IN*/, CHAR * pszClientApplicationEntityTitle /*IN*/, CHAR * pszUploadFolderPath /*IN*/, BOOL bBypassWhenErrorOccured DEFVAL( FALSE /*IN*/), BOOL bAllFilesInOneConnection DEFVAL( TRUE /*IN*/), BOOL bAutoChangeDCMFormat DEFVAL( TRUE /*IN*/ ));
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_DICOM_UPLOAD_FOLDER_OPERATION(PVOID pStation /*IN*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_DICOM_UPLOAD_FILE_OPERATION(PVOID pStation /*IN*/, CHAR * pszClientApplicationEntityTitle /*IN*/, CHAR * pszUploadFilePathName /*IN*/, BOOL bAutoChangeDCMFormat DEFVAL( TRUE /*IN*/ ));
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_DICOM_UPLOAD_FILE_OPERATION(PVOID pStation /*IN*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_DICOM_QUERY_RESULT_CALLBACK_100(PVOID pStation /*IN*/, PF_DICOM_QUERY_RESULT_CALLBACK_100 pCB /*IN*/, PVOID pUserData /*IN*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_DICOM_QUERY_RESULT_CALLBACK_192(PVOID pStation /*IN*/, PF_DICOM_QUERY_RESULT_CALLBACK_192 pCB /*IN*/, PVOID pUserData /*IN*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_DICOM_DOWNLOAD_STATUS_CALLBACK(PVOID pStation /*IN*/, PF_DICOM_DOWNLOAD_STATUS_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_DICOM_UPLOAD_STATUS_CALLBACK(PVOID pStation /*IN*/, PF_DICOM_UPLOAD_STATUS_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_DICOM_WORKLIST_CONNECTION(CHAR * pszServerIP /*IN*/, ULONG nServerPort /*IN*/, CHAR * pszServerApplicationEntityTitle /*IN*/, CHAR * pszClientApplicationEntityTitle /*IN*/, PVOID * ppConnect /*OUT*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_DICOM_WORKLIST_CONNECTION(PVOID pConnect /*IN*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_DICOM_WORKLIST_CONNECTION(PVOID pConnect /*IN*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_DICOM_WORKLIST_CONNECTION(PVOID pConnect /*IN*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_DICOM_WORKLIST_QUERY_OPERATION_CONDITION_100(PVOID   pConnect,                                     /*IN*/
																							    											  
																						CHAR *  pszAccessionNumber,                           /*IN*/
																				  	    										  
																						CHAR *  pszReferringPhysicianName,                    /*IN*/
																				  	    										  
																						CHAR *  pszPatientName,                               /*IN*/
																				  	    										  
																						CHAR *  pszPatientID,                                 /*IN*/
  																				  	    										  
																						CHAR *  pszPerformingPhysicianName,                   /*IN*/
																				  	    										  
																						CHAR *  pszModality,                                  /*IN*/	
																				  	    										  
																						CHAR *  pszProcedureStepStartDate,                    /*IN*/
																				  	    										  
																						CHAR *  pszRequestedProcedureID,                      /*IN*/
																				  	    										  
																						CHAR *  pszScheduledStationApplicationEntityTitle);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_DICOM_WORKLIST_QUERY_OPERATION_CONDITION_192(PVOID   pConnect,                                     /*IN*/

																						WSTRING pwszAccessionNumber,                          /*IN*/
																				  
																						WSTRING pwszReferringPhysicianName,                   /*IN*/
																				  
																						WSTRING pwszPatientName,                              /*IN*/
																				  
																						WSTRING pwszPatientID,                                /*IN*/
																				  
																						WSTRING pwszPerformingPhysicianName,                  /*IN*/
																				  
																						WSTRING pwszModality,                                 /*IN*/	
																				  
																						WSTRING pwszProcedureStepStartDate,                   /*IN*/
																				  
																						WSTRING pwszRequestedProcedureID,                     /*IN*/
																				  
																						WSTRING pwszScheduledStationApplicationEntityTitle);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_DICOM_WORKLIST_QUERY_OPERATION(PVOID pConnect /*IN*/, BOOL bReplyFullData DEFVAL( FALSE /*IN*/), BOOL bReplyDataAtOneTime DEFVAL( FALSE /*IN*/), BOOL bReplyDataByJSON DEFVAL( FALSE /*IN*/ /*0 = TEXT, 1 = JSON*/ ));
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_DICOM_WORKLIST_QUERY_OPERATION(PVOID pConnect /*IN*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_DICOM_WORKLIST_QUERY_RESULT_CALLBACK_100(PVOID pConnect /*IN*/, PF_DICOM_WORKLIST_QUERY_RESULT_CALLBACK_100 pCB /*IN*/, PVOID pUserData /*IN*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_DICOM_WORKLIST_QUERY_RESULT_CALLBACK_192(PVOID pConnect /*IN*/, PF_DICOM_WORKLIST_QUERY_RESULT_CALLBACK_192 pCB /*IN*/, PVOID pUserData /*IN*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_DICOM_FILE_INFO_100(CHAR * pszFilePathName /*IN*/, CHAR * * ppszInformation /*OUT*/, ULONG * pInformationSize /*OUT*/, CHAR * * ppszMetadataInformation DEFVAL( NULL /*OUT*/), ULONG * pMetadataInformationSize DEFVAL( NULL /*OUT*/ ));
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_DICOM_FILE_INFO_192(WSTRING pwszFilePathName /*IN*/, WSTRING * ppwszInformation /*OUT*/, ULONG * pInformationSize /*OUT*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DICOM_DCM_TO_BMP(CHAR * pszSrcFilePathName /*IN*/, CHAR * pszDstFilePathName /*IN*/, UINT iFrameNum DEFVAL( 0 /*IN*/ ));
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DICOM_DCM_TO_JPG(CHAR * pszSrcFilePathName /*IN*/, CHAR * pszDstFilePathName /*IN*/, ULONG nQuality /*IN*/, UINT iFrameNum DEFVAL( 0 /*IN*/ ));
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DICOM_DCM_TO_BUF(CHAR * pszSrcFilePathName /*IN*/, BYTE * pDstBGRFrameBuffer /*OUT*/, ULONG * pDstBGRFrameBufferLen /*IN/OUT*/, ULONG * pWidth /*OUT*/, ULONG * pHeight /*OUT*/, UINT iFrameNum DEFVAL( 0 /*IN*/ ));
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DICOM_BMP_TO_DCM(CHAR * pszSrcFilePathName /*IN*/, CHAR * pszDstFilePathName /*IN*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DICOM_JPG_TO_DCM(CHAR * pszSrcFilePathName /*IN*/, CHAR * pszDstFilePathName /*IN*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DICOM_MP4_TO_DCM(CHAR * pszSrcFilePathName /*IN*/, CHAR * pszDstFilePathName /*IN*/, double * pConvertProgress /*OUT*/);
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DICOM_FOLDER_TO_DCM(CHAR * pszSrcFolderPath /*IN*/, CHAR * pszDstFilePathName /*IN*/, double * pConvertProgress /*OUT*/, BOOL bIsMultiFramesDCM DEFVAL( TRUE /*IN*/ ));
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DICOM_DCM_TO_DICOMDIR(CHAR * pszSrcFolderPath /*IN*/, CHAR * pszDstFolderPath /*IN*/, CHAR * pszFileSetID  /*IN*/);

#ifdef __cplusplus
}
#endif

#endif // MOCK_QCAP_DICOM_H
