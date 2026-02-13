#ifndef QCAP_SERIAL_H
#define QCAP_SERIAL_H

#include "qcap.virtualcamera.h"

#ifdef __cplusplus
extern "C"
{
#endif

// ##########################################################################################################################################################################################
// #
// # SERIAL PORT I/O FUNCTIONS (RS232/RS485)
// #
// ##########################################################################################################################################################################################
//
typedef QRETURN (QCAP_EXPORT *PF_SERIAL_PORT_RECEIVED_DATA_CALLBACK)( PVOID pPort /*IN*/, UINT iPortNum /*IN*/, BYTE * pDataBuffer /*IN*/, ULONG nDataBufferLen /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SERIAL_PORT_ENUMERATION( UINT * pAvailablePortNum /*OUT*/, BOOL bNext /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_SERIAL_PORT( UINT iPortNum /*IN*/, PVOID * ppPort /*OUT*/, ULONG nBaudRate /*IN*/, ULONG nDataBits /*IN*/, ULONG nParityCheck /*IN*/, ULONG nStopBits /*IN*/, ULONG nFlowControl /*IN*/, BOOL bAsynchronousIO /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_SERIAL_PELCO_PORT( UINT iPortNum /*IN*/, BYTE bDevAddr /*IN*/, PVOID * ppPort /*OUT*/, ULONG nBaudRate /*IN*/, ULONG nDataBits /*IN*/, ULONG nParityCheck /*IN*/, ULONG nStopBits /*IN*/, ULONG nFlowControl /*IN*/, BOOL bAsynchronousIO /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_SERIAL_PORT( PVOID pPort /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_SERIAL_PORT( PVOID pPort /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_SERIAL_PORT( PVOID pPort /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SEND_SERIAL_PORT_SIGNAL( PVOID pPort /*IN*/, ULONG nSignalType /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SEND_SERIAL_PORT_DATA( PVOID pPort /*IN*/, BYTE * pDataBuffer /*IN*/, ULONG nDataBufferLen /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_SERIAL_PORT_RECEIVED_DATA_CALLBACK( PVOID pPort /*IN*/, PF_SERIAL_PORT_RECEIVED_DATA_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

#ifdef __cplusplus
}
#endif

#endif // QCAP_SERIAL_H
