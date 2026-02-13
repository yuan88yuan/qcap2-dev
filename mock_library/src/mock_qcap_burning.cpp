#include "mock_qcap_burning.h"
#include <cstdio> // For fprintf, stderr

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_BURNING_DRIVE(CHAR cDriveName , CHAR * pVolumeName , PVOID * ppDrive )
{
    (void)cDriveName;
    (void)pVolumeName;
    (void)ppDrive;
    fprintf(stderr, "Mock function called: QCAP_CREATE_BURNING_DRIVE(%s)\n", "cDriveName, pVolumeName, ppDrive");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_BURNING_DRIVE(PVOID pDrive )
{
    (void)pDrive;
    fprintf(stderr, "Mock function called: QCAP_DESTROY_BURNING_DRIVE(%s)\n", "pDrive");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_BURNING_DRIVE(PVOID pDrive )
{
    (void)pDrive;
    fprintf(stderr, "Mock function called: QCAP_START_BURNING_DRIVE(%s)\n", "pDrive");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_BURNING_DRIVE(PVOID pDrive )
{
    (void)pDrive;
    fprintf(stderr, "Mock function called: QCAP_STOP_BURNING_DRIVE(%s)\n", "pDrive");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_UNLOAD_DISC(PVOID pDrive )
{
    (void)pDrive;
    fprintf(stderr, "Mock function called: QCAP_UNLOAD_DISC(%s)\n", "pDrive");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_LOAD_DISC(PVOID pDrive )
{
    (void)pDrive;
    fprintf(stderr, "Mock function called: QCAP_LOAD_DISC(%s)\n", "pDrive");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_DISC_INFO(PVOID pDrive , BOOL * pIsDiscBlank , BOOL * pIsDiscWriteable , DWORD * pDiscType , ULONGLONG * pDiscRemainCapability )
{
    (void)pDrive;
    (void)pIsDiscBlank;
    (void)pIsDiscWriteable;
    (void)pDiscType;
    (void)pDiscRemainCapability;
    fprintf(stderr, "Mock function called: QCAP_GET_DISC_INFO(%s)\n", "pDrive, pIsDiscBlank, pIsDiscWriteable, pDiscType, pDiscRemainCapability");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_ERASE_DISC(PVOID pDrive )
{
    (void)pDrive;
    fprintf(stderr, "Mock function called: QCAP_ERASE_DISC(%s)\n", "pDrive");
    return QCAP_RS_SUCCESSFUL;
}

