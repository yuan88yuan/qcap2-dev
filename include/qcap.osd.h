#ifndef QCAP_OSD_H
#define QCAP_OSD_H

#include "qcap.recording.h"

#ifdef __cplusplus
extern "C"
{
#endif

// OSD FUNCTIONS (SUPPORT MULTIPLE-LAYERS OSD OBJECTS) (OSDNUM: 0 ~ 511) ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_MOVE_OSD_OBJECT( PVOID pDevice /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, ULONG nSequenceStyle /*IN*/, double dLifeTime /*IN*/ ); // FOR SCROLLING TEXT/PICTURE

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_OSD_TEXT_BOUNDARY( PVOID pDevice /*IN*/, UINT iOsdNum /*IN*/, CHAR * pszString /*IN*/, CHAR * pszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, ULONG * pBoundaryWidth /*OUT*/, ULONG * pBoundaryHeight /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_OSD_TEXT_BOUNDARY_W( PVOID pDevice /*IN*/, UINT iOsdNum /*IN*/, WSTRING pwszString /*IN*/, WSTRING pwszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, ULONG * pBoundaryWidth /*OUT*/, ULONG * pBoundaryHeight /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_OSD_TEXT( PVOID pDevice /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, CHAR * pszString /*IN*/, CHAR * pszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, DWORD dwFontColor /*IN*/, DWORD dwBackgroundColor /*IN*/, ULONG nTransparent /*IN*/, INT nTextStartPosX /*IN*/, INT nTextStartPosY /*IN*/, ULONG nSequenceStyle /*IN*/, double dLifeTime /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_OSD_TEXT_W( PVOID pDevice /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, WSTRING pwszString /*IN*/, WSTRING pwszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, DWORD dwFontColor /*IN*/, DWORD dwBackgroundColor /*IN*/, ULONG nTransparent /*IN*/, INT nTextStartPosX /*IN*/, INT nTextStartPosY /*IN*/, ULONG nSequenceStyle /*IN*/, double dLifeTime /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_OSD_TEXT_EX( PVOID pDevice /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, CHAR * pszString /*IN*/, CHAR * pszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, DWORD dwFontColor /*IN*/, DWORD dwBackgroundColor /*IN*/, DWORD dwBorderColor /*IN*/, ULONG nBorderWidth /*IN*/, ULONG nTransparent /*IN*/, INT nTextStartPosX /*IN*/, INT nTextStartPosY /*IN*/, ULONG nStringAlignmentStyle /*IN*/, ULONG nSequenceStyle /*IN*/, double dLifeTime /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_OSD_TEXT_EX_W( PVOID pDevice /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, WSTRING pwszString /*IN*/, WSTRING pwszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, DWORD dwFontColor /*IN*/, DWORD dwBackgroundColor /*IN*/, DWORD dwBorderColor /*IN*/, ULONG nBorderWidth /*IN*/, ULONG nTransparent /*IN*/, INT nTextStartPosX /*IN*/, INT nTextStartPosY /*IN*/, ULONG nStringAlignmentStyle /*IN*/, ULONG nSequenceStyle /*IN*/, double dLifeTime /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_OSD_PICTURE( PVOID pDevice /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, CHAR * pszFilePathName /*IN*/, ULONG nTransparent /*IN*/, ULONG nSequenceStyle /*IN*/, double dLifeTime /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_OSD_BUFFER( PVOID pDevice /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, ULONG nColorSpaceType /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameWidth /*IN*/, ULONG nFrameHeight /*IN*/, ULONG nFramePitch /*IN*/, ULONG nTransparent /*IN*/, DWORD dwKeyColor /*IN*/, ULONG nKeyColorThreshold /*IN*/, ULONG nKeyColorBlurLevel /*IN*/, BOOL bKeyColorSpillSuppress /*IN*/, ULONG nKeyColorSpillSuppressThreshold /*IN*/, BYTE * pMaskBuffer /*IN*/, ULONG nSequenceStyle /*IN*/, double dLifeTime /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_OSD_BUFFER_EX( PVOID pDevice /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, ULONG nColorSpaceType /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameWidth /*IN*/, ULONG nFrameHeight /*IN*/, ULONG nFramePitch /*IN*/, ULONG nCropX /*IN*/, ULONG nCropY /*IN*/, ULONG nCropW /*IN*/, ULONG nCropH /*IN*/, DWORD dwBorderColor /*IN*/, ULONG nBorderWidth /*IN*/, ULONG nTransparent /*IN*/, DWORD dwKeyColor /*IN*/, ULONG nKeyColorThreshold /*IN*/, ULONG nKeyColorBlurLevel /*IN*/, BOOL bKeyColorSpillSuppress /*IN*/, ULONG nKeyColorSpillSuppressThreshold /*IN*/, BYTE * pMaskBuffer /*IN*/, ULONG nSequenceStyle /*IN*/, double dLifeTime /*IN*/ );

#ifdef __cplusplus
}
#endif

#endif // QCAP_OSD_H
