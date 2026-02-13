#include "mock_qcap_h2.h"
#include <cstdio> // For fprintf, stderr

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_H2_INITIALIZE()
{
    fprintf(stderr, "Mock function called: QCAP_H2_INITIALIZE(%s)\n", "");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_H2_UNINITIALIZE()
{
    fprintf(stderr, "Mock function called: QCAP_H2_UNINITIALIZE(%s)\n", "");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_BUFFER_ADD_REF(BYTE * pBuffer, ULONG nBufferLen)
{
    fprintf(stderr, "Mock function called: QCAP_BUFFER_ADD_REF(%s)\n", "pBuffer, nBufferLen");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_BUFFER_RELEASE(BYTE * pBuffer, ULONG nBufferLen)
{
    fprintf(stderr, "Mock function called: QCAP_BUFFER_RELEASE(%s)\n", "pBuffer, nBufferLen");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_BUFFER_GET_DATA(BYTE * pBuffer, ULONG nBufferLen, PVOID* ppData)
{
    fprintf(stderr, "Mock function called: QCAP_BUFFER_GET_DATA(%s)\n", "pBuffer, nBufferLen, ppData");
    return QCAP_RS_SUCCESSFUL;
}

