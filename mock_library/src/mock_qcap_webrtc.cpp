#include "mock_qcap_webrtc.h"
#include <cstdio> // For fprintf, stderr

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_WEBRTC_CHATROOM(ULONG nNetworkPort , PVOID * ppChatRoom , CHAR * pszNetworkAdapterIP )
{
    (void)nNetworkPort;
    (void)ppChatRoom;
    (void)pszNetworkAdapterIP;
    fprintf(stderr, "Mock function called: QCAP_CREATE_WEBRTC_CHATROOM(%s)\n", "nNetworkPort, ppChatRoom, pszNetworkAdapterIP");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_WEBRTC_CHATROOM(PVOID pChatRoom )
{
    (void)pChatRoom;
    fprintf(stderr, "Mock function called: QCAP_DESTROY_WEBRTC_CHATROOM(%s)\n", "pChatRoom");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_WEBRTC_CHATROOM_LOGIN_CALLBACK_EX(PVOID pChatRoom , PF_WEBRTC_CHATROOM_LOGIN_CALLBACK_EX pCB , PVOID pUserData )
{
    (void)pChatRoom;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_WEBRTC_CHATROOM_LOGIN_CALLBACK_EX(%s)\n", "pChatRoom, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_WEBRTC_CHATROOM_LOGOUT_CALLBACK_EX(PVOID pChatRoom , PF_WEBRTC_CHATROOM_LOGOUT_CALLBACK_EX pCB , PVOID pUserData )
{
    (void)pChatRoom;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_WEBRTC_CHATROOM_LOGOUT_CALLBACK_EX(%s)\n", "pChatRoom, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_WEBRTC_CHATROOM_GET_CUSTOM_PROPERTY_CALLBACK(PVOID pChatRoom , PF_WEBRTC_CHATROOM_GET_CUSTOM_PROPERTY_CALLBACK pCB , PVOID pUserData )
{
    (void)pChatRoom;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_WEBRTC_CHATROOM_GET_CUSTOM_PROPERTY_CALLBACK(%s)\n", "pChatRoom, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_WEBRTC_CHATROOM_SET_CUSTOM_PROPERTY_CALLBACK(PVOID pChatRoom , PF_WEBRTC_CHATROOM_SET_CUSTOM_PROPERTY_CALLBACK pCB , PVOID pUserData )
{
    (void)pChatRoom;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_WEBRTC_CHATROOM_SET_CUSTOM_PROPERTY_CALLBACK(%s)\n", "pChatRoom, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_WEBRTC_CHATTER(CHAR * pszChatRoomLoginIP , ULONG nChatRoomLoginPort , CHAR * pszUserName , PVOID * ppChatter , ULONG * pLoginID , ULONG nConnectionTimeout , CHAR * pszIceURL , CHAR * pszIceUserName , CHAR * pszIcePassword , CHAR * pszReceivedFileFolderPath )
{
    (void)pszChatRoomLoginIP;
    (void)nChatRoomLoginPort;
    (void)pszUserName;
    (void)ppChatter;
    (void)pLoginID;
    (void)nConnectionTimeout;
    (void)pszIceURL;
    (void)pszIceUserName;
    (void)pszIcePassword;
    (void)pszReceivedFileFolderPath;
    fprintf(stderr, "Mock function called: QCAP_CREATE_WEBRTC_CHATTER(%s)\n", "pszChatRoomLoginIP, nChatRoomLoginPort, pszUserName, ppChatter, pLoginID, nConnectionTimeout, pszIceURL, pszIceUserName, pszIcePassword, pszReceivedFileFolderPath");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_WEBRTC_CHATTER(PVOID pChatter )
{
    (void)pChatter;
    fprintf(stderr, "Mock function called: QCAP_DESTROY_WEBRTC_CHATTER(%s)\n", "pChatter");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_WEBRTC_CHAT(PVOID pChatter , ULONG nPeerID )
{
    (void)pChatter;
    (void)nPeerID;
    fprintf(stderr, "Mock function called: QCAP_START_WEBRTC_CHAT(%s)\n", "pChatter, nPeerID");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_WEBRTC_CHAT(PVOID pChatter )
{
    (void)pChatter;
    fprintf(stderr, "Mock function called: QCAP_STOP_WEBRTC_CHAT(%s)\n", "pChatter");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_WEBRTC_SENDER(PVOID pChatter , UINT iSvrNum  /*0 ~ 63*/, ULONG nTotalSessions , PVOID * ppServer )
{
    (void)pChatter;
    (void)nTotalSessions;
    (void)ppServer;
    fprintf(stderr, "Mock function called: QCAP_CREATE_WEBRTC_SENDER(%s)\n", "pChatter, nTotalSessions, ppServer");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_WEBRTC_RECEIVER(PVOID pChatter , UINT iCliNum  /*0 ~ 63*/, PVOID * ppClient , ULONG nDecoderType , HWND hAttachedWindow , BOOL bThumbDraw , BOOL bMaintainAspectRatio )
{
    (void)pChatter;
    (void)ppClient;
    (void)nDecoderType;
    (void)hAttachedWindow;
    (void)bThumbDraw;
    (void)bMaintainAspectRatio;
    fprintf(stderr, "Mock function called: QCAP_CREATE_WEBRTC_RECEIVER(%s)\n", "pChatter, ppClient, nDecoderType, hAttachedWindow, bThumbDraw, bMaintainAspectRatio");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_WEBRTC_PRIVATE_SDP_PROPERTY(PVOID pChatter , ULONG nPeerID , CHAR * pszSDP )
{
    (void)pChatter;
    (void)nPeerID;
    (void)pszSDP;
    fprintf(stderr, "Mock function called: QCAP_SET_WEBRTC_PRIVATE_SDP_PROPERTY(%s)\n", "pChatter, nPeerID, pszSDP");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_WEBRTC_CHATROOM_CUSTOM_PROPERTY(PVOID pChatter , CHAR * pszProperty , CHAR * * ppszValue )
{
    (void)pChatter;
    (void)pszProperty;
    (void)ppszValue;
    fprintf(stderr, "Mock function called: QCAP_GET_WEBRTC_CHATROOM_CUSTOM_PROPERTY(%s)\n", "pChatter, pszProperty, ppszValue");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_WEBRTC_CHATROOM_CUSTOM_PROPERTY(PVOID pChatter , CHAR * pszProperty , CHAR * pszValue )
{
    (void)pChatter;
    (void)pszProperty;
    (void)pszValue;
    fprintf(stderr, "Mock function called: QCAP_SET_WEBRTC_CHATROOM_CUSTOM_PROPERTY(%s)\n", "pChatter, pszProperty, pszValue");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_ENUM_WEBRTC_USER_IN_CHATROOM(PVOID pChatter , ULONG * pPeerID , CHAR * * ppszPeerUserName , BOOL bNext )
{
    (void)pChatter;
    (void)pPeerID;
    (void)ppszPeerUserName;
    (void)bNext;
    fprintf(stderr, "Mock function called: QCAP_ENUM_WEBRTC_USER_IN_CHATROOM(%s)\n", "pChatter, pPeerID, ppszPeerUserName, bNext");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SEND_WEBRTC_DATA(PVOID pChatter , CHAR * pszData )
{
    (void)pChatter;
    (void)pszData;
    fprintf(stderr, "Mock function called: QCAP_SEND_WEBRTC_DATA(%s)\n", "pChatter, pszData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SEND_WEBRTC_FILE(PVOID pChatter , CHAR * pszFilePathName )
{
    (void)pChatter;
    (void)pszFilePathName;
    fprintf(stderr, "Mock function called: QCAP_SEND_WEBRTC_FILE(%s)\n", "pChatter, pszFilePathName");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_WEBRTC_CHATROOM_LOGIN_CALLBACK(PVOID pChatter , PF_WEBRTC_CHATROOM_LOGIN_CALLBACK pCB , PVOID pUserData )
{
    (void)pChatter;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_WEBRTC_CHATROOM_LOGIN_CALLBACK(%s)\n", "pChatter, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_WEBRTC_CHATROOM_LOGOUT_CALLBACK(PVOID pChatter , PF_WEBRTC_CHATROOM_LOGOUT_CALLBACK pCB , PVOID pUserData )
{
    (void)pChatter;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_WEBRTC_CHATROOM_LOGOUT_CALLBACK(%s)\n", "pChatter, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_WEBRTC_PRIVATE_SDP_PROPERTY_CALLBACK(PVOID pChatter , PF_WEBRTC_PRIVATE_SDP_PROPERTY_CALLBACK pCB , PVOID pUserData )
{
    (void)pChatter;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_WEBRTC_PRIVATE_SDP_PROPERTY_CALLBACK(%s)\n", "pChatter, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_WEBRTC_PEER_CONNECTED_CALLBACK(PVOID pChatter , PF_WEBRTC_PEER_CONNECTED_CALLBACK pCB , PVOID pUserData )
{
    (void)pChatter;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_WEBRTC_PEER_CONNECTED_CALLBACK(%s)\n", "pChatter, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_WEBRTC_PEER_DISCONNECTED_CALLBACK(PVOID pChatter , PF_WEBRTC_PEER_DISCONNECTED_CALLBACK pCB , PVOID pUserData )
{
    (void)pChatter;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_WEBRTC_PEER_DISCONNECTED_CALLBACK(%s)\n", "pChatter, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_WEBRTC_SEND_DATA_DONE_CALLBACK(PVOID pChatter , PF_WEBRTC_SEND_DATA_DONE_CALLBACK pCB , PVOID pUserData )
{
    (void)pChatter;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_WEBRTC_SEND_DATA_DONE_CALLBACK(%s)\n", "pChatter, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_WEBRTC_SEND_FILE_DONE_CALLBACK(PVOID pChatter , PF_WEBRTC_SEND_FILE_DONE_CALLBACK pCB , PVOID pUserData )
{
    (void)pChatter;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_WEBRTC_SEND_FILE_DONE_CALLBACK(%s)\n", "pChatter, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_WEBRTC_RECEIVED_DATA_DONE_CALLBACK(PVOID pChatter , PF_WEBRTC_RECEIVED_DATA_DONE_CALLBACK pCB , PVOID pUserData )
{
    (void)pChatter;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_WEBRTC_RECEIVED_DATA_DONE_CALLBACK(%s)\n", "pChatter, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_WEBRTC_RECEIVED_FILE_DONE_CALLBACK(PVOID pChatter , PF_WEBRTC_RECEIVED_FILE_DONE_CALLBACK pCB , PVOID pUserData )
{
    (void)pChatter;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_WEBRTC_RECEIVED_FILE_DONE_CALLBACK(%s)\n", "pChatter, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_WEBRTC_RECEIVED_FILE_STATUS_CALLBACK(PVOID pChatter , PF_WEBRTC_RECEIVED_FILE_STATUS_CALLBACK pCB , PVOID pUserData )
{
    (void)pChatter;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_WEBRTC_RECEIVED_FILE_STATUS_CALLBACK(%s)\n", "pChatter, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_WEBRTC_NETWORK_QOS_STATUS_CALLBACK(PVOID pChatter , UINT iSessionNum , ULONG nExpectedBitRate , ULONG nExpectedFrameRate , PVOID pUserData )
{
    (void)pChatter;
    (void)iSessionNum;
    (void)nExpectedBitRate;
    (void)nExpectedFrameRate;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_WEBRTC_NETWORK_QOS_STATUS_CALLBACK(%s)\n", "pChatter, iSessionNum, nExpectedBitRate, nExpectedFrameRate, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

