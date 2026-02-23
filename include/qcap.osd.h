#ifndef QCAP_OSD_H
#define QCAP_OSD_H

#include "qcap.types.h"

#ifdef __cplusplus
extern "C"
{
#endif

// OSD FUNCTIONS (SUPPORT MULTIPLE-LAYERS OSD OBJECTS) (OSDNUM: 0 ~ 511) ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_MOVE_OSD_OBJECT( PVOID pDevice /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, ULONG nSequenceStyle DEFVAL( QCAP_SEQUENCE_STYLE_FOREMOST /*IN*/), double dLifeTime DEFVAL( 0.0 /*IN*/ )); // FOR SCROLLING TEXT/PICTURE

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_OSD_TEXT_BOUNDARY( PVOID pDevice /*IN*/, UINT iOsdNum /*IN*/, CHAR * pszString /*IN*/, CHAR * pszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, ULONG * pBoundaryWidth /*OUT*/, ULONG * pBoundaryHeight /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_OSD_TEXT_BOUNDARY_W( PVOID pDevice /*IN*/, UINT iOsdNum /*IN*/, WSTRING pwszString /*IN*/, WSTRING pwszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, ULONG * pBoundaryWidth /*OUT*/, ULONG * pBoundaryHeight /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_OSD_TEXT( PVOID pDevice /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, CHAR * pszString /*IN*/, CHAR * pszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, DWORD dwFontColor /*IN*/, DWORD dwBackgroundColor /*IN*/, ULONG nTransparent /*IN*/, INT nTextStartPosX DEFVAL( 0 /*IN*/), INT nTextStartPosY DEFVAL( 0 /*IN*/), ULONG nSequenceStyle DEFVAL( QCAP_SEQUENCE_STYLE_FOREMOST /*IN*/), double dLifeTime DEFVAL( 0.0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_OSD_TEXT_W( PVOID pDevice /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, WSTRING pwszString /*IN*/, WSTRING pwszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, DWORD dwFontColor /*IN*/, DWORD dwBackgroundColor /*IN*/, ULONG nTransparent /*IN*/, INT nTextStartPosX DEFVAL( 0 /*IN*/), INT nTextStartPosY DEFVAL( 0 /*IN*/), ULONG nSequenceStyle DEFVAL( QCAP_SEQUENCE_STYLE_FOREMOST /*IN*/), double dLifeTime DEFVAL( 0.0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_OSD_TEXT_EX( PVOID pDevice /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, CHAR * pszString /*IN*/, CHAR * pszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, DWORD dwFontColor /*IN*/, DWORD dwBackgroundColor /*IN*/, DWORD dwBorderColor /*IN*/, ULONG nBorderWidth /*IN*/, ULONG nTransparent /*IN*/, INT nTextStartPosX DEFVAL( 0 /*IN*/), INT nTextStartPosY DEFVAL( 0 /*IN*/), ULONG nStringAlignmentStyle DEFVAL( QCAP_STRING_ALIGNMENT_STYLE_LEFT /*IN*/), ULONG nSequenceStyle DEFVAL( QCAP_SEQUENCE_STYLE_FOREMOST /*IN*/), double dLifeTime DEFVAL( 0.0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_OSD_TEXT_EX_W( PVOID pDevice /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, WSTRING pwszString /*IN*/, WSTRING pwszFontFamilyName /*IN*/, ULONG nFontStyle /*IN*/, ULONG nFontSize /*IN*/, DWORD dwFontColor /*IN*/, DWORD dwBackgroundColor /*IN*/, DWORD dwBorderColor /*IN*/, ULONG nBorderWidth /*IN*/, ULONG nTransparent /*IN*/, INT nTextStartPosX DEFVAL( 0 /*IN*/), INT nTextStartPosY DEFVAL( 0 /*IN*/), ULONG nStringAlignmentStyle DEFVAL( QCAP_STRING_ALIGNMENT_STYLE_LEFT /*IN*/), ULONG nSequenceStyle DEFVAL( QCAP_SEQUENCE_STYLE_FOREMOST /*IN*/), double dLifeTime DEFVAL( 0.0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_OSD_PICTURE( PVOID pDevice /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, CHAR * pszFilePathName /*IN*/, ULONG nTransparent /*IN*/, ULONG nSequenceStyle DEFVAL( QCAP_SEQUENCE_STYLE_FOREMOST /*IN*/), double dLifeTime DEFVAL( 0.0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_OSD_BUFFER( PVOID pDevice /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, ULONG nColorSpaceType /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameWidth /*IN*/, ULONG nFrameHeight /*IN*/, ULONG nFramePitch /*IN*/, ULONG nTransparent /*IN*/, DWORD dwKeyColor DEFVAL( 0xFFFFFFFF /*IN*/ /*0xFFFFFFFF (OFF) / 0x00FF0000 (BLUE) / 0x0000FF00 (GREEN)*/), ULONG nKeyColorThreshold DEFVAL( 25 /*IN*/ /*0 ~ 128*/), ULONG nKeyColorBlurLevel DEFVAL( 2 /*IN*/ /*0 ~ 2*/), BOOL bKeyColorSpillSuppress DEFVAL( TRUE /*IN*/), ULONG nKeyColorSpillSuppressThreshold DEFVAL( 22 /*IN*/), BYTE * pMaskBuffer DEFVAL( NULL /*IN*/), ULONG nSequenceStyle DEFVAL( QCAP_SEQUENCE_STYLE_FOREMOST /*IN*/), double dLifeTime DEFVAL( 0.0 /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_OSD_BUFFER_EX( PVOID pDevice /*IN*/, UINT iOsdNum /*IN*/, INT x /*IN*/, INT y /*IN*/, INT w /*IN*/, INT h /*IN*/, ULONG nColorSpaceType /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameWidth /*IN*/, ULONG nFrameHeight /*IN*/, ULONG nFramePitch /*IN*/, ULONG nCropX /*IN*/, ULONG nCropY /*IN*/, ULONG nCropW /*IN*/, ULONG nCropH /*IN*/, DWORD dwBorderColor /*IN*/, ULONG nBorderWidth /*IN*/, ULONG nTransparent /*IN*/, DWORD dwKeyColor DEFVAL( 0xFFFFFFFF /*IN*/ /*0xFFFFFFFF (OFF) / 0x00FF0000 (BLUE) / 0x0000FF00 (GREEN)*/), ULONG nKeyColorThreshold DEFVAL( 25 /*IN*/ /*0 ~ 128*/), ULONG nKeyColorBlurLevel DEFVAL( 2 /*IN*/ /*0 ~ 2*/), BOOL bKeyColorSpillSuppress DEFVAL( TRUE /*IN*/), ULONG nKeyColorSpillSuppressThreshold DEFVAL( 22 /*IN*/), BYTE * pMaskBuffer DEFVAL( NULL /*IN*/), ULONG nSequenceStyle DEFVAL( QCAP_SEQUENCE_STYLE_FOREMOST /*IN*/), double dLifeTime DEFVAL( 0.0 /*IN*/ ));

#ifdef __cplusplus
}
#endif

#endif // QCAP_OSD_H
