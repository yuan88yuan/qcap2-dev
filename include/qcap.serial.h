#ifndef QCAP_SERIAL_H
#define QCAP_SERIAL_H

#include "qcap.types.h"

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

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SERIAL_PORT_ENUMERATION( UINT * pAvailablePortNum /*OUT*/, BOOL bNext DEFVAL( FALSE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_SERIAL_PORT( UINT iPortNum /*IN*/, PVOID * ppPort /*OUT*/, ULONG nBaudRate DEFVAL( 9600 /*IN*/), ULONG nDataBits DEFVAL( 8 /*IN*/), ULONG nParityCheck DEFVAL( QCAP_SERIAL_PORT_PARITY_CHECK_NONE /*IN*/), ULONG nStopBits DEFVAL( QCAP_SERIAL_PORT_STOP_BITS_ONE /*IN*/), ULONG nFlowControl DEFVAL( QCAP_SERIAL_PORT_FLOW_CONTROL_NONE /*IN*/), BOOL bAsynchronousIO DEFVAL( FALSE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_SERIAL_PELCO_PORT( UINT iPortNum /*IN*/, BYTE bDevAddr /*IN*/, PVOID * ppPort /*OUT*/, ULONG nBaudRate DEFVAL( 9600 /*IN*/), ULONG nDataBits DEFVAL( 8 /*IN*/), ULONG nParityCheck DEFVAL( QCAP_SERIAL_PORT_PARITY_CHECK_NONE /*IN*/), ULONG nStopBits DEFVAL( QCAP_SERIAL_PORT_STOP_BITS_ONE /*IN*/), ULONG nFlowControl DEFVAL( QCAP_SERIAL_PORT_FLOW_CONTROL_NONE /*IN*/), BOOL bAsynchronousIO DEFVAL( TRUE /*IN*/ ));

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
