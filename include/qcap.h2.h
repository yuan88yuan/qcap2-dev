#ifndef __QCAP_H2_H__
#define __QCAP_H2_H__

#include "qcap.types.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef QRETURN (QCAP_EXPORT *PF_MEDIA_BROADCAST_SERVER_CALLBACK)( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, double dSampleTime /*IN*/, BYTE * pStreamBuffer /*IN*/, ULONG nStreamBufferLen /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_H2_INITIALIZE();
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_H2_UNINITIALIZE();

QCAP_EXT_API QRESULT QCAP_EXPORT /*|RTSP|RTMP|HLS|TS|MMS|2D|3D|  |*/ QCAP_REGISTER_MEDIA_BROADCAST_SERVER_CALLBACK( PVOID pServer /*IN*/, UINT iSessionNum /*IN*/, PF_MEDIA_BROADCAST_SERVER_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_BUFFER_ADD_REF( BYTE * pBuffer, ULONG nBufferLen );
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_BUFFER_RELEASE( BYTE * pBuffer, ULONG nBufferLen );
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_BUFFER_GET_DATA( BYTE * pBuffer, ULONG nBufferLen, PVOID* ppData );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif // __QCAP_H2_H__