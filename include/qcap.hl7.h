#ifndef QCAP_HL7_H
#define QCAP_HL7_H

#include "qcap.types.h"

#ifdef __cplusplus
extern "C"
{
#endif

// ##########################################################################################################################################################################################
// #
// # HL7 FUNCTIONS
// #
// ##########################################################################################################################################################################################
//
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_HL7_CONNECTION( CHAR * pszHL7ServerIP /*IN*/, ULONG nServerPort /*IN*/, CHAR * pszServerApplicationEntityTitle /*IN*/, CHAR * pszClientApplicationEntityTitle /*IN*/, PVOID * ppConnect /*OUT*/, ULONG nHL7Version DEFVAL( QCAP_HL7_VERSION_24 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_HL7_CONNECTION( PVOID pConnect /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_HL7_CONNECTION( PVOID pConnect /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_HL7_CONNECTION( PVOID pConnect /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_HL7_PATIENT_CONDITION( PVOID  pConnect,				/*IN*/

																 CHAR * pszPatientID,			/*IN*/

																 CHAR * pszPatientName,			/*IN*/

																 CHAR * pszBirthday,			/*IN*/

																 CHAR * pszGender,				/*IN*/

																 CHAR * pszPatientClass,		/*IN*/

																 CHAR * pszPhysicianName,		/*IN*/

																 CHAR * pszAccessionNumber,		/*IN*/

																 CHAR * pszStudyDescription,	/*IN*/

																 CHAR * pszStudyDateTime );		/*IN*/

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_HL7_PATIENT_ADT_MANAGEMENT_SERVICE( PVOID pConnect /*IN*/, ULONG nPatientADTType /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_HL7_PATIENT_INFO( PVOID pConnect /*IN*/, CHAR * pszPatientID /*IN*/, CHAR * * ppszPatientInformation /*OUT*/, ULONG * pPatientInformationSize /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SEND_HL7_CLINICAL_ORDER( PVOID pConnect /*IN*/, CHAR * pszDepartmentID /*IN*/, ULONG nClinicalOrderType /*IN*/, CHAR * pszEnterUserID /*IN*/, CHAR * pszEnterUserName /*IN*/, CHAR * pszModality /*IN*/, CHAR * pszClinicalOrderComment /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_UPLOAD_HL7_PATIENT_FILE( PVOID pConnect /*IN*/, CHAR * pszUploadFilePathName /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_HL7_UPLOAD_PATIENT_REPORT_OPERATION( PVOID pConnect /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_HL7_UPLOAD_PATIENT_REPORT_OPERATION( PVOID pConnect /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SEND_HL7_UPLOAD_PATIENT_REPORT_DATA( PVOID pConnect /*IN*/, CHAR * pszFieldName /*IN*/, CHAR * pszContent /*IN*/ );

#ifdef __cplusplus
}
#endif

#endif // QCAP_HL7_H
