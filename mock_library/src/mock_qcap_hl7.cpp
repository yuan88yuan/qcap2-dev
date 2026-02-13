#include "mock_qcap_hl7.h"
#include <cstdio> // For fprintf, stderr

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_HL7_CONNECTION(CHAR * pszHL7ServerIP , ULONG nServerPort , CHAR * pszServerApplicationEntityTitle , CHAR * pszClientApplicationEntityTitle , PVOID * ppConnect , ULONG nHL7Version )
{
    (void)pszHL7ServerIP;
    (void)nServerPort;
    (void)pszServerApplicationEntityTitle;
    (void)pszClientApplicationEntityTitle;
    (void)ppConnect;
    (void)nHL7Version;
    fprintf(stderr, "Mock function called: QCAP_CREATE_HL7_CONNECTION(%s)\n", "pszHL7ServerIP, nServerPort, pszServerApplicationEntityTitle, pszClientApplicationEntityTitle, ppConnect, nHL7Version");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_HL7_CONNECTION(PVOID pConnect )
{
    (void)pConnect;
    fprintf(stderr, "Mock function called: QCAP_DESTROY_HL7_CONNECTION(%s)\n", "pConnect");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_HL7_CONNECTION(PVOID pConnect )
{
    (void)pConnect;
    fprintf(stderr, "Mock function called: QCAP_START_HL7_CONNECTION(%s)\n", "pConnect");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_HL7_CONNECTION(PVOID pConnect )
{
    (void)pConnect;
    fprintf(stderr, "Mock function called: QCAP_STOP_HL7_CONNECTION(%s)\n", "pConnect");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_HL7_PATIENT_CONDITION(PVOID  pConnect,				

																 CHAR * pszPatientID,			

																 CHAR * pszPatientName,			

																 CHAR * pszBirthday,			

																 CHAR * pszGender,				

																 CHAR * pszPatientClass,		

																 CHAR * pszPhysicianName,		

																 CHAR * pszAccessionNumber,		

																 CHAR * pszStudyDescription,	

																 CHAR * pszStudyDateTime)
{
    (void)pConnect;
    (void)pszPatientID;
    (void)pszPatientName;
    (void)pszBirthday;
    (void)pszGender;
    (void)pszPatientClass;
    (void)pszPhysicianName;
    (void)pszAccessionNumber;
    (void)pszStudyDescription;
    (void)pszStudyDateTime;
    fprintf(stderr, "Mock function called: QCAP_SET_HL7_PATIENT_CONDITION(%s)\n", "pConnect, pszPatientID, pszPatientName, pszBirthday, pszGender, pszPatientClass, pszPhysicianName, pszAccessionNumber, pszStudyDescription, pszStudyDateTime");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_HL7_PATIENT_ADT_MANAGEMENT_SERVICE(PVOID pConnect , ULONG nPatientADTType )
{
    (void)pConnect;
    (void)nPatientADTType;
    fprintf(stderr, "Mock function called: QCAP_SET_HL7_PATIENT_ADT_MANAGEMENT_SERVICE(%s)\n", "pConnect, nPatientADTType");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_HL7_PATIENT_INFO(PVOID pConnect , CHAR * pszPatientID , CHAR * * ppszPatientInformation , ULONG * pPatientInformationSize )
{
    (void)pConnect;
    (void)pszPatientID;
    (void)ppszPatientInformation;
    (void)pPatientInformationSize;
    fprintf(stderr, "Mock function called: QCAP_GET_HL7_PATIENT_INFO(%s)\n", "pConnect, pszPatientID, ppszPatientInformation, pPatientInformationSize");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SEND_HL7_CLINICAL_ORDER(PVOID pConnect , CHAR * pszDepartmentID , ULONG nClinicalOrderType , CHAR * pszEnterUserID , CHAR * pszEnterUserName , CHAR * pszModality , CHAR * pszClinicalOrderComment )
{
    (void)pConnect;
    (void)pszDepartmentID;
    (void)nClinicalOrderType;
    (void)pszEnterUserID;
    (void)pszEnterUserName;
    (void)pszModality;
    (void)pszClinicalOrderComment;
    fprintf(stderr, "Mock function called: QCAP_SEND_HL7_CLINICAL_ORDER(%s)\n", "pConnect, pszDepartmentID, nClinicalOrderType, pszEnterUserID, pszEnterUserName, pszModality, pszClinicalOrderComment");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_UPLOAD_HL7_PATIENT_FILE(PVOID pConnect , CHAR * pszUploadFilePathName )
{
    (void)pConnect;
    (void)pszUploadFilePathName;
    fprintf(stderr, "Mock function called: QCAP_UPLOAD_HL7_PATIENT_FILE(%s)\n", "pConnect, pszUploadFilePathName");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_HL7_UPLOAD_PATIENT_REPORT_OPERATION(PVOID pConnect )
{
    (void)pConnect;
    fprintf(stderr, "Mock function called: QCAP_START_HL7_UPLOAD_PATIENT_REPORT_OPERATION(%s)\n", "pConnect");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_HL7_UPLOAD_PATIENT_REPORT_OPERATION(PVOID pConnect )
{
    (void)pConnect;
    fprintf(stderr, "Mock function called: QCAP_STOP_HL7_UPLOAD_PATIENT_REPORT_OPERATION(%s)\n", "pConnect");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SEND_HL7_UPLOAD_PATIENT_REPORT_DATA(PVOID pConnect , CHAR * pszFieldName , CHAR * pszContent )
{
    (void)pConnect;
    (void)pszFieldName;
    (void)pszContent;
    fprintf(stderr, "Mock function called: QCAP_SEND_HL7_UPLOAD_PATIENT_REPORT_DATA(%s)\n", "pConnect, pszFieldName, pszContent");
    return QCAP_RS_SUCCESSFUL;
}

