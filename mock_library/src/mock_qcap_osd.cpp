#include "mock_qcap_osd.h"
#include <cstdio> // For fprintf, stderr

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_MOVE_OSD_OBJECT(PVOID pDevice , UINT iOsdNum , INT x , INT y , ULONG nSequenceStyle , double dLifeTime )
{
    (void)pDevice;
    (void)iOsdNum;
    (void)x;
    (void)y;
    (void)nSequenceStyle;
    (void)dLifeTime;
    fprintf(stderr, "Mock function called: QCAP_MOVE_OSD_OBJECT(%s)\n", "pDevice, iOsdNum, x, y, nSequenceStyle, dLifeTime");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_OSD_TEXT_BOUNDARY(PVOID pDevice , UINT iOsdNum , CHAR * pszString , CHAR * pszFontFamilyName , ULONG nFontStyle , ULONG nFontSize , ULONG * pBoundaryWidth , ULONG * pBoundaryHeight )
{
    (void)pDevice;
    (void)iOsdNum;
    (void)pszString;
    (void)pszFontFamilyName;
    (void)nFontStyle;
    (void)nFontSize;
    (void)pBoundaryWidth;
    (void)pBoundaryHeight;
    fprintf(stderr, "Mock function called: QCAP_GET_OSD_TEXT_BOUNDARY(%s)\n", "pDevice, iOsdNum, pszString, pszFontFamilyName, nFontStyle, nFontSize, pBoundaryWidth, pBoundaryHeight");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_OSD_TEXT_BOUNDARY_W(PVOID pDevice , UINT iOsdNum , WSTRING pwszString , WSTRING pwszFontFamilyName , ULONG nFontStyle , ULONG nFontSize , ULONG * pBoundaryWidth , ULONG * pBoundaryHeight )
{
    (void)pDevice;
    (void)iOsdNum;
    (void)pwszString;
    (void)pwszFontFamilyName;
    (void)nFontStyle;
    (void)nFontSize;
    (void)pBoundaryWidth;
    (void)pBoundaryHeight;
    fprintf(stderr, "Mock function called: QCAP_GET_OSD_TEXT_BOUNDARY_W(%s)\n", "pDevice, iOsdNum, pwszString, pwszFontFamilyName, nFontStyle, nFontSize, pBoundaryWidth, pBoundaryHeight");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_OSD_TEXT(PVOID pDevice , UINT iOsdNum , INT x , INT y , INT w , INT h , CHAR * pszString , CHAR * pszFontFamilyName , ULONG nFontStyle , ULONG nFontSize , DWORD dwFontColor , DWORD dwBackgroundColor , ULONG nTransparent , INT nTextStartPosX , INT nTextStartPosY , ULONG nSequenceStyle , double dLifeTime )
{
    (void)pDevice;
    (void)iOsdNum;
    (void)x;
    (void)y;
    (void)w;
    (void)h;
    (void)pszString;
    (void)pszFontFamilyName;
    (void)nFontStyle;
    (void)nFontSize;
    (void)dwFontColor;
    (void)dwBackgroundColor;
    (void)nTransparent;
    (void)nTextStartPosX;
    (void)nTextStartPosY;
    (void)nSequenceStyle;
    (void)dLifeTime;
    fprintf(stderr, "Mock function called: QCAP_SET_OSD_TEXT(%s)\n", "pDevice, iOsdNum, x, y, w, h, pszString, pszFontFamilyName, nFontStyle, nFontSize, dwFontColor, dwBackgroundColor, nTransparent, nTextStartPosX, nTextStartPosY, nSequenceStyle, dLifeTime");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_OSD_TEXT_W(PVOID pDevice , UINT iOsdNum , INT x , INT y , INT w , INT h , WSTRING pwszString , WSTRING pwszFontFamilyName , ULONG nFontStyle , ULONG nFontSize , DWORD dwFontColor , DWORD dwBackgroundColor , ULONG nTransparent , INT nTextStartPosX , INT nTextStartPosY , ULONG nSequenceStyle , double dLifeTime )
{
    (void)pDevice;
    (void)iOsdNum;
    (void)x;
    (void)y;
    (void)w;
    (void)h;
    (void)pwszString;
    (void)pwszFontFamilyName;
    (void)nFontStyle;
    (void)nFontSize;
    (void)dwFontColor;
    (void)dwBackgroundColor;
    (void)nTransparent;
    (void)nTextStartPosX;
    (void)nTextStartPosY;
    (void)nSequenceStyle;
    (void)dLifeTime;
    fprintf(stderr, "Mock function called: QCAP_SET_OSD_TEXT_W(%s)\n", "pDevice, iOsdNum, x, y, w, h, pwszString, pwszFontFamilyName, nFontStyle, nFontSize, dwFontColor, dwBackgroundColor, nTransparent, nTextStartPosX, nTextStartPosY, nSequenceStyle, dLifeTime");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_OSD_TEXT_EX(PVOID pDevice , UINT iOsdNum , INT x , INT y , INT w , INT h , CHAR * pszString , CHAR * pszFontFamilyName , ULONG nFontStyle , ULONG nFontSize , DWORD dwFontColor , DWORD dwBackgroundColor , DWORD dwBorderColor , ULONG nBorderWidth , ULONG nTransparent , INT nTextStartPosX , INT nTextStartPosY , ULONG nStringAlignmentStyle , ULONG nSequenceStyle , double dLifeTime )
{
    (void)pDevice;
    (void)iOsdNum;
    (void)x;
    (void)y;
    (void)w;
    (void)h;
    (void)pszString;
    (void)pszFontFamilyName;
    (void)nFontStyle;
    (void)nFontSize;
    (void)dwFontColor;
    (void)dwBackgroundColor;
    (void)dwBorderColor;
    (void)nBorderWidth;
    (void)nTransparent;
    (void)nTextStartPosX;
    (void)nTextStartPosY;
    (void)nStringAlignmentStyle;
    (void)nSequenceStyle;
    (void)dLifeTime;
    fprintf(stderr, "Mock function called: QCAP_SET_OSD_TEXT_EX(%s)\n", "pDevice, iOsdNum, x, y, w, h, pszString, pszFontFamilyName, nFontStyle, nFontSize, dwFontColor, dwBackgroundColor, dwBorderColor, nBorderWidth, nTransparent, nTextStartPosX, nTextStartPosY, nStringAlignmentStyle, nSequenceStyle, dLifeTime");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_OSD_TEXT_EX_W(PVOID pDevice , UINT iOsdNum , INT x , INT y , INT w , INT h , WSTRING pwszString , WSTRING pwszFontFamilyName , ULONG nFontStyle , ULONG nFontSize , DWORD dwFontColor , DWORD dwBackgroundColor , DWORD dwBorderColor , ULONG nBorderWidth , ULONG nTransparent , INT nTextStartPosX , INT nTextStartPosY , ULONG nStringAlignmentStyle , ULONG nSequenceStyle , double dLifeTime )
{
    (void)pDevice;
    (void)iOsdNum;
    (void)x;
    (void)y;
    (void)w;
    (void)h;
    (void)pwszString;
    (void)pwszFontFamilyName;
    (void)nFontStyle;
    (void)nFontSize;
    (void)dwFontColor;
    (void)dwBackgroundColor;
    (void)dwBorderColor;
    (void)nBorderWidth;
    (void)nTransparent;
    (void)nTextStartPosX;
    (void)nTextStartPosY;
    (void)nStringAlignmentStyle;
    (void)nSequenceStyle;
    (void)dLifeTime;
    fprintf(stderr, "Mock function called: QCAP_SET_OSD_TEXT_EX_W(%s)\n", "pDevice, iOsdNum, x, y, w, h, pwszString, pwszFontFamilyName, nFontStyle, nFontSize, dwFontColor, dwBackgroundColor, dwBorderColor, nBorderWidth, nTransparent, nTextStartPosX, nTextStartPosY, nStringAlignmentStyle, nSequenceStyle, dLifeTime");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_OSD_PICTURE(PVOID pDevice , UINT iOsdNum , INT x , INT y , INT w , INT h , CHAR * pszFilePathName , ULONG nTransparent , ULONG nSequenceStyle , double dLifeTime )
{
    (void)pDevice;
    (void)iOsdNum;
    (void)x;
    (void)y;
    (void)w;
    (void)h;
    (void)pszFilePathName;
    (void)nTransparent;
    (void)nSequenceStyle;
    (void)dLifeTime;
    fprintf(stderr, "Mock function called: QCAP_SET_OSD_PICTURE(%s)\n", "pDevice, iOsdNum, x, y, w, h, pszFilePathName, nTransparent, nSequenceStyle, dLifeTime");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_OSD_BUFFER(PVOID pDevice , UINT iOsdNum , INT x , INT y , INT w , INT h , ULONG nColorSpaceType , BYTE * pFrameBuffer , ULONG nFrameWidth , ULONG nFrameHeight , ULONG nFramePitch , ULONG nTransparent , DWORD dwKeyColor  / 0x00FF0000 (BLUE) / 0x0000FF00 (GREEN)*/), ULONG nKeyColorThreshold , ULONG nKeyColorBlurLevel , BOOL bKeyColorSpillSuppress , ULONG nKeyColorSpillSuppressThreshold , BYTE * pMaskBuffer , ULONG nSequenceStyle , double dLifeTime )
{
    (void)pDevice;
    (void)iOsdNum;
    (void)x;
    (void)y;
    (void)w;
    (void)h;
    (void)nColorSpaceType;
    (void)pFrameBuffer;
    (void)nFrameWidth;
    (void)nFrameHeight;
    (void)nFramePitch;
    (void)nTransparent;
    (void)dLifeTime;
    fprintf(stderr, "Mock function called: QCAP_SET_OSD_BUFFER(%s)\n", "pDevice, iOsdNum, x, y, w, h, nColorSpaceType, pFrameBuffer, nFrameWidth, nFrameHeight, nFramePitch, nTransparent, dLifeTime");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_OSD_BUFFER_EX(PVOID pDevice , UINT iOsdNum , INT x , INT y , INT w , INT h , ULONG nColorSpaceType , BYTE * pFrameBuffer , ULONG nFrameWidth , ULONG nFrameHeight , ULONG nFramePitch , ULONG nCropX , ULONG nCropY , ULONG nCropW , ULONG nCropH , DWORD dwBorderColor , ULONG nBorderWidth , ULONG nTransparent , DWORD dwKeyColor  / 0x00FF0000 (BLUE) / 0x0000FF00 (GREEN)*/), ULONG nKeyColorThreshold , ULONG nKeyColorBlurLevel , BOOL bKeyColorSpillSuppress , ULONG nKeyColorSpillSuppressThreshold , BYTE * pMaskBuffer , ULONG nSequenceStyle , double dLifeTime )
{
    (void)pDevice;
    (void)iOsdNum;
    (void)x;
    (void)y;
    (void)w;
    (void)h;
    (void)nColorSpaceType;
    (void)pFrameBuffer;
    (void)nFrameWidth;
    (void)nFrameHeight;
    (void)nFramePitch;
    (void)nCropX;
    (void)nCropY;
    (void)nCropW;
    (void)nCropH;
    (void)dwBorderColor;
    (void)nBorderWidth;
    (void)nTransparent;
    (void)dLifeTime;
    fprintf(stderr, "Mock function called: QCAP_SET_OSD_BUFFER_EX(%s)\n", "pDevice, iOsdNum, x, y, w, h, nColorSpaceType, pFrameBuffer, nFrameWidth, nFrameHeight, nFramePitch, nCropX, nCropY, nCropW, nCropH, dwBorderColor, nBorderWidth, nTransparent, dLifeTime");
    return QCAP_RS_SUCCESSFUL;
}

