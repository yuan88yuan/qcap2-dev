#include "mock_qcap_timer.h"
#include <cstdio> // For fprintf, stderr

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_MEDIA_TIMER(ULONG nElapseTimeNum , ULONG nElapseTimeDeno , PVOID * ppTimer )
{
    (void)nElapseTimeNum;
    (void)nElapseTimeDeno;
    (void)ppTimer;
    fprintf(stderr, "Mock function called: QCAP_CREATE_MEDIA_TIMER(%s)\n", "nElapseTimeNum, nElapseTimeDeno, ppTimer");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_MEDIA_TIMER(PVOID pTimer )
{
    (void)pTimer;
    fprintf(stderr, "Mock function called: QCAP_DESTROY_MEDIA_TIMER(%s)\n", "pTimer");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_MEDIA_TIMER(PVOID pTimer )
{
    (void)pTimer;
    fprintf(stderr, "Mock function called: QCAP_START_MEDIA_TIMER(%s)\n", "pTimer");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_MEDIA_TIMER(PVOID pTimer )
{
    (void)pTimer;
    fprintf(stderr, "Mock function called: QCAP_STOP_MEDIA_TIMER(%s)\n", "pTimer");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_MEDIA_TIMER_CALLBACK(PVOID pTimer , PF_MEDIA_TIMER_CALLBACK pCB , PVOID pUserData )
{
    (void)pTimer;
    (void)pCB;
    (void)pUserData;
    fprintf(stderr, "Mock function called: QCAP_REGISTER_MEDIA_TIMER_CALLBACK(%s)\n", "pTimer, pCB, pUserData");
    return QCAP_RS_SUCCESSFUL;
}

