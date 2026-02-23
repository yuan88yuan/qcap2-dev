#ifndef QCAP_SIP_H
#define QCAP_SIP_H

#include "qcap.types.h"

#ifdef __cplusplus
extern "C"
{
#endif

// ##########################################################################################################################################################################################
// #
// # SIP FUNCTIONS
// #
// ##########################################################################################################################################################################################
//
typedef QRETURN (QCAP_EXPORT *PF_SIP_PEER_CONNECTED_CALLBACK)( PVOID pChatter /*IN*/, CHAR * pszPeerID /*IN*/, PVOID pUserData /*IN*/ );

typedef QRETURN (QCAP_EXPORT *PF_SIP_PEER_DISCONNECTED_CALLBACK)( PVOID pChatter /*IN*/, CHAR * pszPeerID /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_SIP_CHATTER( CHAR * pszChatRoomLoginIP /*IN*/, CHAR * pszChatRoomLoginDomain /*IN*/, ULONG nChatRoomLoginPort /*IN*/, CHAR * pszUserName /*IN*/, CHAR * pszLoginID /*IN*/, CHAR * pszLoginPassword /*IN*/, PVOID * ppChatter /*OUT*/, CHAR * pszNetworkAdapterIP DEFVAL( NULL /*IN*/), ULONG nTransportProtocol DEFVAL( QCAP_SIP_TRANSPORT_PROTOCOL_UDP /*IN*/), ULONG nConnectionTimeout DEFVAL( 5000 /*IN*/ /*ms*/), BOOL bIsAudioOnly DEFVAL( FALSE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_SIP_CHATTER( PVOID pChatter /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_SIP_CHAT( PVOID pChatter /*IN*/, CHAR * pszPeerID /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_SIP_CHAT( PVOID pChatter /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_SIP_SENDER( PVOID pChatter /*IN*/, UINT iSvrNum /*IN*/ /*0 ~ 63*/, PVOID * ppServer /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_SIP_RECEIVER( PVOID pChatter /*IN*/, UINT iCliNum /*IN*/ /*0 ~ 63*/, PVOID * ppClient /*OUT*/, ULONG nDecoderType DEFVAL( QCAP_DECODER_TYPE_SOFTWARE /*IN*/), HWND hAttachedWindow DEFVAL( NULL /*IN*/), BOOL bThumbDraw DEFVAL( FALSE /*IN*/), BOOL bMaintainAspectRatio DEFVAL( FALSE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_ACCEPT_SIP_CALL( PVOID pChatter /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_SIP_PEER_CONNECTED_CALLBACK( PVOID pChatter /*IN*/, PF_SIP_PEER_CONNECTED_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_SIP_PEER_DISCONNECTED_CALLBACK( PVOID pChatter /*IN*/, PF_SIP_PEER_DISCONNECTED_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

#ifdef __cplusplus
}
#endif

#endif // QCAP_SIP_H
