#include "mock_qcap_serial.h"
#include <cstdio> // For fprintf, stderr

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SERIAL_PORT_ENUMERATION(UINT * pAvailablePortNum , BOOL bNext )
{
    (void)pAvailablePortNum;
    (void)bNext;
    fprintf(stderr, "Mock function called: QCAP_SERIAL_PORT_ENUMERATION(%s)\n", "pAvailablePortNum, bNext");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_SERIAL_PORT(UINT iPortNum , PVOID * ppPort , ULONG nBaudRate , ULONG nDataBits , ULONG nParityCheck , ULONG nStopBits , ULONG nFlowControl , BOOL bAsynchronousIO )
{
    (void)iPortNum;
    (void)ppPort;
    (void)nBaudRate;
    (void)nDataBits;
    (void)nParityCheck;
    (void)nStopBits;
    (void)nFlowControl;
    (void)bAsynchronousIO;
    fprintf(stderr, "Mock function called: QCAP_CREATE_SERIAL_PORT(%s)\n", "iPortNum, ppPort, nBaudRate, nDataBits, nParityCheck, nStopBits, nFlowControl, bAsynchronousIO");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_SERIAL_PELCO_PORT(UINT iPortNum , BYTE bDevAddr , PVOID * ppPort , ULONG nBaudRate , ULONG nDataBits , ULONG nParityCheck , ULONG nStopBits , ULONG nFlowControl , BOOL bAsynchronousIO )
{
    (void)iPortNum;
    (void)bDevAddr;
    (void)ppPort;
    (void)nBaudRate;
    (void)nDataBits;
    (void)nParityCheck;
    (void)nStopBits;
    (void)nFlowControl;
    (void)bAsynchronousIO;
    fprintf(stderr, "Mock function called: QCAP_CREATE_SERIAL_PELCO_PORT(%s)\n", "iPortNum, bDevAddr, ppPort, nBaudRate, nDataBits, nParityCheck, nStopBits, nFlowControl, bAsynchronousIO");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_SERIAL_PORT(PVOID pPort )
{
    (void)pPort;
    fprintf(stderr, "Mock function called: QCAP_DESTROY_SERIAL_PORT(%s)\n", "pPort");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_SERIAL_PORT(PVOID pPort )
{
    (void)pPort;
    fprintf(stderr, "Mock function called: QCAP_START_SERIAL_PORT(%s)\n", "pPort");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_SERIAL_PORT(PVOID pPort )
{
    (void)pPort;
    fprintf(stderr, "Mock function called: QCAP_STOP_SERIAL_PORT(%s)\n", "pPort");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SEND_SERIAL_PORT_SIGNAL(PVOID pPort , ULONG nSignalType )
{
    (void)pPort;
    (void)nSignalType;
    fprintf(stderr, "Mock function called: QCAP_SEND_SERIAL_PORT_SIGNAL(%s)\n", "pPort, nSignalType");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SEND_SERIAL_PORT_DATA(PVOID pPort , BYTE * pDataBuffer , ULONG nDataBufferLen )
{
    (void)pPort;
    (void)pDataBuffer;
    (void)nDataBufferLen;
    fprintf(stderr, "Mock function called: QCAP_SEND_SERIAL_PORT_DATA(%s)\n", "pPort, pDataBuffer, nDataBufferLen");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_SERIAL_PORT_RECEIVED_DATA_CALLBACK(PVOID pPort , PF_SERIAL_PORT_RECEIVED_DATA_CALLBACK pCB , PVOID pUserData )
{
    (void)pPort;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_SERIAL_PORT_RECEIVED_DATA_CALLBACK(%s)\n", "pPort, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

