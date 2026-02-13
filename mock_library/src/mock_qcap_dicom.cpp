#include "mock_qcap_dicom.h"
#include <cstdio> // For fprintf, stderr

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_DICOM_WORKSTATION(CHAR * pszServerIP , ULONG nServerPort , CHAR * pszServerApplicationEntityTitle , CHAR * pszClientApplicationEntityTitle , PVOID * ppStation )
{
    (void)pszServerIP;
    (void)nServerPort;
    (void)pszServerApplicationEntityTitle;
    (void)pszClientApplicationEntityTitle;
    (void)ppStation;
    fprintf(stderr, "Mock function called: QCAP_CREATE_DICOM_WORKSTATION(%s)\n", "pszServerIP, nServerPort, pszServerApplicationEntityTitle, pszClientApplicationEntityTitle, ppStation");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_DICOM_WORKSTATION(PVOID pStation )
{
    (void)pStation;
    fprintf(stderr, "Mock function called: QCAP_DESTROY_DICOM_WORKSTATION(%s)\n", "pStation");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_DICOM_WORKSTATION(PVOID pStation )
{
    (void)pStation;
    fprintf(stderr, "Mock function called: QCAP_START_DICOM_WORKSTATION(%s)\n", "pStation");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_DICOM_WORKSTATION(PVOID pStation )
{
    (void)pStation;
    fprintf(stderr, "Mock function called: QCAP_STOP_DICOM_WORKSTATION(%s)\n", "pStation");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_DICOM_QUERY_OPERATION_CONDITION_100(PVOID   pStation,                     
																							    							  
																				  CHAR *  pszAccessionNumber,           
																		 	    								
																				  CHAR *  pszReferringPhysicianName,    
																		 	    								
																				  CHAR *  pszPatientName,               
																		 	    								
																				  CHAR *  pszPatientID,                 
  																		 	    								
																				  CHAR *  pszPerformingPhysicianName,   
																				  	    											  
																				  CHAR *  pszModality,                  	
																		 	    									    											  
																				  CHAR *  pszProcedureStepStartDate)
{
    (void)pStation;
    (void)pszAccessionNumber;
    (void)pszReferringPhysicianName;
    (void)pszPatientName;
    (void)pszPatientID;
    (void)pszPerformingPhysicianName;
    (void)pszModality;
    (void)pszProcedureStepStartDate;
    fprintf(stderr, "Mock function called: QCAP_SET_DICOM_QUERY_OPERATION_CONDITION_100(%s)\n", "pStation, pszAccessionNumber, pszReferringPhysicianName, pszPatientName, pszPatientID, pszPerformingPhysicianName, pszModality, pszProcedureStepStartDate");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_DICOM_QUERY_OPERATION_CONDITION_192(PVOID   pStation,                     
																							    							  
																				  WSTRING pwszAccessionNumber,          
																		 											
																				  WSTRING pwszReferringPhysicianName,   
																		 											
																				  WSTRING pwszPatientName,              
																		 											
																				  WSTRING pwszPatientID,                
  																		 											
																				  WSTRING pwszPerformingPhysicianName,  
																		 																								  	    											  
																				  WSTRING pwszModality,                 	
					    													
																				  WSTRING pwszProcedureStepStartDate)
{
    (void)pStation;
    (void)pwszAccessionNumber;
    (void)pwszReferringPhysicianName;
    (void)pwszPatientName;
    (void)pwszPatientID;
    (void)pwszPerformingPhysicianName;
    (void)pwszModality;
    (void)pwszProcedureStepStartDate;
    fprintf(stderr, "Mock function called: QCAP_SET_DICOM_QUERY_OPERATION_CONDITION_192(%s)\n", "pStation, pwszAccessionNumber, pwszReferringPhysicianName, pwszPatientName, pwszPatientID, pwszPerformingPhysicianName, pwszModality, pwszProcedureStepStartDate");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_DICOM_DOWNLOAD_OPERATION_CONDITION_100(PVOID   pStation,                     
																							    							  
																				  CHAR *  pszAccessionNumber,           
																		 	    								
																				  CHAR *  pszReferringPhysicianName,    
																		 	    								
																				  CHAR *  pszPatientName,               
																		 	    								
																				  CHAR *  pszPatientID,                 
  																		 	    								
																				  CHAR *  pszPerformingPhysicianName,   
																		 	    									    											  
																				  CHAR *  pszProcedureStepStartDate,    
																		 	    								
																				  CHAR *  pszStudyInstanceUID)
{
    (void)pStation;
    (void)pszAccessionNumber;
    (void)pszReferringPhysicianName;
    (void)pszPatientName;
    (void)pszPatientID;
    (void)pszPerformingPhysicianName;
    (void)pszProcedureStepStartDate;
    (void)pszStudyInstanceUID;
    fprintf(stderr, "Mock function called: QCAP_SET_DICOM_DOWNLOAD_OPERATION_CONDITION_100(%s)\n", "pStation, pszAccessionNumber, pszReferringPhysicianName, pszPatientName, pszPatientID, pszPerformingPhysicianName, pszProcedureStepStartDate, pszStudyInstanceUID");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_DICOM_DOWNLOAD_OPERATION_CONDITION_192(PVOID   pStation,                     
																							    							  
																				  WSTRING pwszAccessionNumber,          
																		 	    										
																				  WSTRING pwszReferringPhysicianName,   
																		 	    										
																				  WSTRING pwszPatientName,              
																		 	    										
																				  WSTRING pwszPatientID,                
  																		 	    										
																				  WSTRING pwszPerformingPhysicianName,  
																		 	    								    													  
																				  WSTRING pwszProcedureStepStartDate,   
																		 	    										
																				  WSTRING pwszStudyInstanceUID)
{
    (void)pStation;
    (void)pwszAccessionNumber;
    (void)pwszReferringPhysicianName;
    (void)pwszPatientName;
    (void)pwszPatientID;
    (void)pwszPerformingPhysicianName;
    (void)pwszProcedureStepStartDate;
    (void)pwszStudyInstanceUID;
    fprintf(stderr, "Mock function called: QCAP_SET_DICOM_DOWNLOAD_OPERATION_CONDITION_192(%s)\n", "pStation, pwszAccessionNumber, pwszReferringPhysicianName, pwszPatientName, pwszPatientID, pwszPerformingPhysicianName, pwszProcedureStepStartDate, pwszStudyInstanceUID");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_DICOM_QUERY_OPERATION(PVOID pStation , CHAR * pszClientApplicationEntityTitle , BOOL bReplyFullData , BOOL bReplyDataAtOneTime , BOOL bReplyDataByJSON )
{
    (void)pStation;
    (void)pszClientApplicationEntityTitle;
    (void)bReplyFullData;
    (void)bReplyDataAtOneTime;
    (void)bReplyDataByJSON;
    fprintf(stderr, "Mock function called: QCAP_START_DICOM_QUERY_OPERATION(%s)\n", "pStation, pszClientApplicationEntityTitle, bReplyFullData, bReplyDataAtOneTime, bReplyDataByJSON");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_DICOM_QUERY_OPERATION(PVOID pStation )
{
    (void)pStation;
    fprintf(stderr, "Mock function called: QCAP_STOP_DICOM_QUERY_OPERATION(%s)\n", "pStation");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_DICOM_DOWNLOAD_OPERATION(PVOID pStation , CHAR * pszClientApplicationEntityTitle , ULONG nClientPort , CHAR * pszDownloadFolderPath )
{
    (void)pStation;
    (void)pszClientApplicationEntityTitle;
    (void)nClientPort;
    (void)pszDownloadFolderPath;
    fprintf(stderr, "Mock function called: QCAP_START_DICOM_DOWNLOAD_OPERATION(%s)\n", "pStation, pszClientApplicationEntityTitle, nClientPort, pszDownloadFolderPath");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_DICOM_DOWNLOAD_OPERATION(PVOID pStation )
{
    (void)pStation;
    fprintf(stderr, "Mock function called: QCAP_STOP_DICOM_DOWNLOAD_OPERATION(%s)\n", "pStation");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_DICOM_UPLOAD_FOLDER_OPERATION(PVOID pStation , CHAR * pszClientApplicationEntityTitle , CHAR * pszUploadFolderPath , BOOL bBypassWhenErrorOccured , BOOL bAllFilesInOneConnection , BOOL bAutoChangeDCMFormat )
{
    (void)pStation;
    (void)pszClientApplicationEntityTitle;
    (void)pszUploadFolderPath;
    (void)bBypassWhenErrorOccured;
    (void)bAllFilesInOneConnection;
    (void)bAutoChangeDCMFormat;
    fprintf(stderr, "Mock function called: QCAP_START_DICOM_UPLOAD_FOLDER_OPERATION(%s)\n", "pStation, pszClientApplicationEntityTitle, pszUploadFolderPath, bBypassWhenErrorOccured, bAllFilesInOneConnection, bAutoChangeDCMFormat");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_DICOM_UPLOAD_FOLDER_OPERATION(PVOID pStation )
{
    (void)pStation;
    fprintf(stderr, "Mock function called: QCAP_STOP_DICOM_UPLOAD_FOLDER_OPERATION(%s)\n", "pStation");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_DICOM_UPLOAD_FILE_OPERATION(PVOID pStation , CHAR * pszClientApplicationEntityTitle , CHAR * pszUploadFilePathName , BOOL bAutoChangeDCMFormat )
{
    (void)pStation;
    (void)pszClientApplicationEntityTitle;
    (void)pszUploadFilePathName;
    (void)bAutoChangeDCMFormat;
    fprintf(stderr, "Mock function called: QCAP_START_DICOM_UPLOAD_FILE_OPERATION(%s)\n", "pStation, pszClientApplicationEntityTitle, pszUploadFilePathName, bAutoChangeDCMFormat");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_DICOM_UPLOAD_FILE_OPERATION(PVOID pStation )
{
    (void)pStation;
    fprintf(stderr, "Mock function called: QCAP_STOP_DICOM_UPLOAD_FILE_OPERATION(%s)\n", "pStation");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_DICOM_QUERY_RESULT_CALLBACK_100(PVOID pStation , PF_DICOM_QUERY_RESULT_CALLBACK_100 pCB , PVOID pUserData )
{
    (void)pStation;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_DICOM_QUERY_RESULT_CALLBACK_100(%s)\n", "pStation, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_DICOM_QUERY_RESULT_CALLBACK_192(PVOID pStation , PF_DICOM_QUERY_RESULT_CALLBACK_192 pCB , PVOID pUserData )
{
    (void)pStation;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_DICOM_QUERY_RESULT_CALLBACK_192(%s)\n", "pStation, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_DICOM_DOWNLOAD_STATUS_CALLBACK(PVOID pStation , PF_DICOM_DOWNLOAD_STATUS_CALLBACK pCB , PVOID pUserData )
{
    (void)pStation;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_DICOM_DOWNLOAD_STATUS_CALLBACK(%s)\n", "pStation, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_DICOM_UPLOAD_STATUS_CALLBACK(PVOID pStation , PF_DICOM_UPLOAD_STATUS_CALLBACK pCB , PVOID pUserData )
{
    (void)pStation;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_DICOM_UPLOAD_STATUS_CALLBACK(%s)\n", "pStation, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_DICOM_WORKLIST_CONNECTION(CHAR * pszServerIP , ULONG nServerPort , CHAR * pszServerApplicationEntityTitle , CHAR * pszClientApplicationEntityTitle , PVOID * ppConnect )
{
    (void)pszServerIP;
    (void)nServerPort;
    (void)pszServerApplicationEntityTitle;
    (void)pszClientApplicationEntityTitle;
    (void)ppConnect;
    fprintf(stderr, "Mock function called: QCAP_CREATE_DICOM_WORKLIST_CONNECTION(%s)\n", "pszServerIP, nServerPort, pszServerApplicationEntityTitle, pszClientApplicationEntityTitle, ppConnect");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_DICOM_WORKLIST_CONNECTION(PVOID pConnect )
{
    (void)pConnect;
    fprintf(stderr, "Mock function called: QCAP_DESTROY_DICOM_WORKLIST_CONNECTION(%s)\n", "pConnect");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_DICOM_WORKLIST_CONNECTION(PVOID pConnect )
{
    (void)pConnect;
    fprintf(stderr, "Mock function called: QCAP_START_DICOM_WORKLIST_CONNECTION(%s)\n", "pConnect");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_DICOM_WORKLIST_CONNECTION(PVOID pConnect )
{
    (void)pConnect;
    fprintf(stderr, "Mock function called: QCAP_STOP_DICOM_WORKLIST_CONNECTION(%s)\n", "pConnect");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_DICOM_WORKLIST_QUERY_OPERATION_CONDITION_100(PVOID   pConnect,                                     
																							    											  
																						CHAR *  pszAccessionNumber,                           
																				  	    										  
																						CHAR *  pszReferringPhysicianName,                    
																				  	    										  
																						CHAR *  pszPatientName,                               
																				  	    										  
																						CHAR *  pszPatientID,                                 
  																				  	    										  
																						CHAR *  pszPerformingPhysicianName,                   
																				  	    										  
																						CHAR *  pszModality,                                  	
																				  	    										  
																						CHAR *  pszProcedureStepStartDate,                    
																				  	    										  
																						CHAR *  pszRequestedProcedureID,                      
																				  	    										  
																						CHAR *  pszScheduledStationApplicationEntityTitle)
{
    (void)pConnect;
    (void)pszAccessionNumber;
    (void)pszReferringPhysicianName;
    (void)pszPatientName;
    (void)pszPatientID;
    (void)pszPerformingPhysicianName;
    (void)pszModality;
    (void)pszProcedureStepStartDate;
    (void)pszRequestedProcedureID;
    (void)pszScheduledStationApplicationEntityTitle;
    fprintf(stderr, "Mock function called: QCAP_SET_DICOM_WORKLIST_QUERY_OPERATION_CONDITION_100(%s)\n", "pConnect, pszAccessionNumber, pszReferringPhysicianName, pszPatientName, pszPatientID, pszPerformingPhysicianName, pszModality, pszProcedureStepStartDate, pszRequestedProcedureID, pszScheduledStationApplicationEntityTitle");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_DICOM_WORKLIST_QUERY_OPERATION_CONDITION_192(PVOID   pConnect,                                     

																						WSTRING pwszAccessionNumber,                          
																				  
																						WSTRING pwszReferringPhysicianName,                   
																				  
																						WSTRING pwszPatientName,                              
																				  
																						WSTRING pwszPatientID,                                
																				  
																						WSTRING pwszPerformingPhysicianName,                  
																				  
																						WSTRING pwszModality,                                 	
																				  
																						WSTRING pwszProcedureStepStartDate,                   
																				  
																						WSTRING pwszRequestedProcedureID,                     
																				  
																						WSTRING pwszScheduledStationApplicationEntityTitle)
{
    (void)pConnect;
    (void)pwszAccessionNumber;
    (void)pwszReferringPhysicianName;
    (void)pwszPatientName;
    (void)pwszPatientID;
    (void)pwszPerformingPhysicianName;
    (void)pwszModality;
    (void)pwszProcedureStepStartDate;
    (void)pwszRequestedProcedureID;
    (void)pwszScheduledStationApplicationEntityTitle;
    fprintf(stderr, "Mock function called: QCAP_SET_DICOM_WORKLIST_QUERY_OPERATION_CONDITION_192(%s)\n", "pConnect, pwszAccessionNumber, pwszReferringPhysicianName, pwszPatientName, pwszPatientID, pwszPerformingPhysicianName, pwszModality, pwszProcedureStepStartDate, pwszRequestedProcedureID, pwszScheduledStationApplicationEntityTitle");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_DICOM_WORKLIST_QUERY_OPERATION(PVOID pConnect , BOOL bReplyFullData , BOOL bReplyDataAtOneTime , BOOL bReplyDataByJSON )
{
    (void)pConnect;
    (void)bReplyFullData;
    (void)bReplyDataAtOneTime;
    (void)bReplyDataByJSON;
    fprintf(stderr, "Mock function called: QCAP_START_DICOM_WORKLIST_QUERY_OPERATION(%s)\n", "pConnect, bReplyFullData, bReplyDataAtOneTime, bReplyDataByJSON");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_DICOM_WORKLIST_QUERY_OPERATION(PVOID pConnect )
{
    (void)pConnect;
    fprintf(stderr, "Mock function called: QCAP_STOP_DICOM_WORKLIST_QUERY_OPERATION(%s)\n", "pConnect");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_DICOM_WORKLIST_QUERY_RESULT_CALLBACK_100(PVOID pConnect , PF_DICOM_WORKLIST_QUERY_RESULT_CALLBACK_100 pCB , PVOID pUserData )
{
    (void)pConnect;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_DICOM_WORKLIST_QUERY_RESULT_CALLBACK_100(%s)\n", "pConnect, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_DICOM_WORKLIST_QUERY_RESULT_CALLBACK_192(PVOID pConnect , PF_DICOM_WORKLIST_QUERY_RESULT_CALLBACK_192 pCB , PVOID pUserData )
{
    (void)pConnect;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_DICOM_WORKLIST_QUERY_RESULT_CALLBACK_192(%s)\n", "pConnect, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_DICOM_FILE_INFO_100(CHAR * pszFilePathName , CHAR * * ppszInformation , ULONG * pInformationSize , CHAR * * ppszMetadataInformation , ULONG * pMetadataInformationSize )
{
    (void)pszFilePathName;
    (void)ppszInformation;
    (void)pInformationSize;
    (void)ppszMetadataInformation;
    (void)pMetadataInformationSize;
    fprintf(stderr, "Mock function called: QCAP_GET_DICOM_FILE_INFO_100(%s)\n", "pszFilePathName, ppszInformation, pInformationSize, ppszMetadataInformation, pMetadataInformationSize");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_DICOM_FILE_INFO_192(WSTRING pwszFilePathName , WSTRING * ppwszInformation , ULONG * pInformationSize )
{
    (void)pwszFilePathName;
    (void)ppwszInformation;
    (void)pInformationSize;
    fprintf(stderr, "Mock function called: QCAP_GET_DICOM_FILE_INFO_192(%s)\n", "pwszFilePathName, ppwszInformation, pInformationSize");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DICOM_DCM_TO_BMP(CHAR * pszSrcFilePathName , CHAR * pszDstFilePathName , UINT iFrameNum )
{
    (void)pszSrcFilePathName;
    (void)pszDstFilePathName;
    (void)iFrameNum;
    fprintf(stderr, "Mock function called: QCAP_DICOM_DCM_TO_BMP(%s)\n", "pszSrcFilePathName, pszDstFilePathName, iFrameNum");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DICOM_DCM_TO_JPG(CHAR * pszSrcFilePathName , CHAR * pszDstFilePathName , ULONG nQuality , UINT iFrameNum )
{
    (void)pszSrcFilePathName;
    (void)pszDstFilePathName;
    (void)nQuality;
    (void)iFrameNum;
    fprintf(stderr, "Mock function called: QCAP_DICOM_DCM_TO_JPG(%s)\n", "pszSrcFilePathName, pszDstFilePathName, nQuality, iFrameNum");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DICOM_DCM_TO_BUF(CHAR * pszSrcFilePathName , BYTE * pDstBGRFrameBuffer , ULONG * pDstBGRFrameBufferLen /*IN/OUT*/, ULONG * pWidth , ULONG * pHeight , UINT iFrameNum )
{
    (void)pszSrcFilePathName;
    (void)pDstBGRFrameBuffer;
    (void)pWidth;
    (void)pHeight;
    (void)iFrameNum;
    fprintf(stderr, "Mock function called: QCAP_DICOM_DCM_TO_BUF(%s)\n", "pszSrcFilePathName, pDstBGRFrameBuffer, pWidth, pHeight, iFrameNum");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DICOM_BMP_TO_DCM(CHAR * pszSrcFilePathName , CHAR * pszDstFilePathName )
{
    (void)pszSrcFilePathName;
    (void)pszDstFilePathName;
    fprintf(stderr, "Mock function called: QCAP_DICOM_BMP_TO_DCM(%s)\n", "pszSrcFilePathName, pszDstFilePathName");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DICOM_JPG_TO_DCM(CHAR * pszSrcFilePathName , CHAR * pszDstFilePathName )
{
    (void)pszSrcFilePathName;
    (void)pszDstFilePathName;
    fprintf(stderr, "Mock function called: QCAP_DICOM_JPG_TO_DCM(%s)\n", "pszSrcFilePathName, pszDstFilePathName");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DICOM_MP4_TO_DCM(CHAR * pszSrcFilePathName , CHAR * pszDstFilePathName , double * pConvertProgress )
{
    (void)pszSrcFilePathName;
    (void)pszDstFilePathName;
    (void)pConvertProgress;
    fprintf(stderr, "Mock function called: QCAP_DICOM_MP4_TO_DCM(%s)\n", "pszSrcFilePathName, pszDstFilePathName, pConvertProgress");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DICOM_FOLDER_TO_DCM(CHAR * pszSrcFolderPath , CHAR * pszDstFilePathName , double * pConvertProgress , BOOL bIsMultiFramesDCM )
{
    (void)pszSrcFolderPath;
    (void)pszDstFilePathName;
    (void)pConvertProgress;
    (void)bIsMultiFramesDCM;
    fprintf(stderr, "Mock function called: QCAP_DICOM_FOLDER_TO_DCM(%s)\n", "pszSrcFolderPath, pszDstFilePathName, pConvertProgress, bIsMultiFramesDCM");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DICOM_DCM_TO_DICOMDIR(CHAR * pszSrcFolderPath , CHAR * pszDstFolderPath , CHAR * pszFileSetID  )
{
    (void)pszSrcFolderPath;
    (void)pszDstFolderPath;
    (void)pszFileSetID;
    fprintf(stderr, "Mock function called: QCAP_DICOM_DCM_TO_DICOMDIR(%s)\n", "pszSrcFolderPath, pszDstFolderPath, pszFileSetID");
    return QCAP_RS_SUCCESSFUL;
}

