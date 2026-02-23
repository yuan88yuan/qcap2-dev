#ifndef QCAP_TIMER_H
#define QCAP_TIMER_H

#include "qcap.types.h"

#ifdef __cplusplus
extern "C"
{
#endif

// ##########################################################################################################################################################################################
// #
// # MEDIA TIMER FUNCTIONS (QCAP_RECORD_PROFILE_HIGH PRECISION)
// #
// ##########################################################################################################################################################################################
//
typedef QRETURN (QCAP_EXPORT *PF_MEDIA_TIMER_CALLBACK)( PVOID pTimer /*IN*/, double dSampleTime /*IN*/, double dDelayTime /*IN*/, PVOID pUserData /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_MEDIA_TIMER( ULONG nElapseTimeNum /*IN*/, ULONG nElapseTimeDeno /*IN*/, PVOID * ppTimer /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_MEDIA_TIMER( PVOID pTimer /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_MEDIA_TIMER( PVOID pTimer /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_MEDIA_TIMER( PVOID pTimer /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_REGISTER_MEDIA_TIMER_CALLBACK( PVOID pTimer /*IN*/, PF_MEDIA_TIMER_CALLBACK pCB /*IN*/, PVOID pUserData /*IN*/ );

#ifdef __cplusplus
}
#endif

#endif // QCAP_TIMER_H
