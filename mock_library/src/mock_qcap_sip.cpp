#include "mock_qcap_sip.h"
#include <cstdio> // For fprintf, stderr

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_SIP_CHATTER(CHAR * pszChatRoomLoginIP , CHAR * pszChatRoomLoginDomain , ULONG nChatRoomLoginPort , CHAR * pszUserName , CHAR * pszLoginID , CHAR * pszLoginPassword , PVOID * ppChatter , CHAR * pszNetworkAdapterIP , ULONG nTransportProtocol , ULONG nConnectionTimeout , BOOL bIsAudioOnly )
{
    (void)pszChatRoomLoginIP;
    (void)pszChatRoomLoginDomain;
    (void)nChatRoomLoginPort;
    (void)pszUserName;
    (void)pszLoginID;
    (void)pszLoginPassword;
    (void)ppChatter;
    (void)pszNetworkAdapterIP;
    (void)nTransportProtocol;
    (void)nConnectionTimeout;
    (void)bIsAudioOnly;
    fprintf(stderr, "Mock function called: QCAP_CREATE_SIP_CHATTER(%s)\n", "pszChatRoomLoginIP, pszChatRoomLoginDomain, nChatRoomLoginPort, pszUserName, pszLoginID, pszLoginPassword, ppChatter, pszNetworkAdapterIP, nTransportProtocol, nConnectionTimeout, bIsAudioOnly");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_SIP_CHATTER(PVOID pChatter )
{
    (void)pChatter;
    fprintf(stderr, "Mock function called: QCAP_DESTROY_SIP_CHATTER(%s)\n", "pChatter");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_SIP_CHAT(PVOID pChatter , CHAR * pszPeerID )
{
    (void)pChatter;
    (void)pszPeerID;
    fprintf(stderr, "Mock function called: QCAP_START_SIP_CHAT(%s)\n", "pChatter, pszPeerID");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_SIP_CHAT(PVOID pChatter )
{
    (void)pChatter;
    fprintf(stderr, "Mock function called: QCAP_STOP_SIP_CHAT(%s)\n", "pChatter");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_SIP_SENDER(PVOID pChatter , UINT iSvrNum  /*0 ~ 63*/, PVOID * ppServer )
{
    (void)pChatter;
    (void)ppServer;
    fprintf(stderr, "Mock function called: QCAP_CREATE_SIP_SENDER(%s)\n", "pChatter, ppServer");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_SIP_RECEIVER(PVOID pChatter , UINT iCliNum  /*0 ~ 63*/, PVOID * ppClient , ULONG nDecoderType , HWND hAttachedWindow , BOOL bThumbDraw , BOOL bMaintainAspectRatio )
{
    (void)pChatter;
    (void)ppClient;
    (void)nDecoderType;
    (void)hAttachedWindow;
    (void)bThumbDraw;
    (void)bMaintainAspectRatio;
    fprintf(stderr, "Mock function called: QCAP_CREATE_SIP_RECEIVER(%s)\n", "pChatter, ppClient, nDecoderType, hAttachedWindow, bThumbDraw, bMaintainAspectRatio");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_ACCEPT_SIP_CALL(PVOID pChatter )
{
    (void)pChatter;
    fprintf(stderr, "Mock function called: QCAP_ACCEPT_SIP_CALL(%s)\n", "pChatter");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_SIP_PEER_CONNECTED_CALLBACK(PVOID pChatter , PF_SIP_PEER_CONNECTED_CALLBACK pCB , PVOID pUserData )
{
    (void)pChatter;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_SIP_PEER_CONNECTED_CALLBACK(%s)\n", "pChatter, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_SIP_PEER_DISCONNECTED_CALLBACK(PVOID pChatter , PF_SIP_PEER_DISCONNECTED_CALLBACK pCB , PVOID pUserData )
{
    (void)pChatter;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_SIP_PEER_DISCONNECTED_CALLBACK(%s)\n", "pChatter, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

