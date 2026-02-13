#include "mock_qcap_animation.h"
#include <cstdio> // For fprintf, stderr

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_ANIMATION_CLIP(CHAR * pszAniFilePathName , PVOID * ppClip , ULONG * pTotalFrames , ULONG * pTotalSprites , ULONG * pColorSpaceType , ULONG * pWidth , ULONG * pHeight )
{
    (void)pszAniFilePathName;
    (void)ppClip;
    (void)pTotalFrames;
    (void)pTotalSprites;
    (void)pColorSpaceType;
    (void)pWidth;
    (void)pHeight;
    fprintf(stderr, "Mock function called: QCAP_CREATE_ANIMATION_CLIP(%s)\n", "pszAniFilePathName, ppClip, pTotalFrames, pTotalSprites, pColorSpaceType, pWidth, pHeight");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_ANIMATION_CLIP(PVOID pClip )
{
    (void)pClip;
    fprintf(stderr, "Mock function called: QCAP_DESTROY_ANIMATION_CLIP(%s)\n", "pClip");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_ANIMATION_CLIP(PVOID pClip )
{
    (void)pClip;
    fprintf(stderr, "Mock function called: QCAP_START_ANIMATION_CLIP(%s)\n", "pClip");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_ANIMATION_CLIP(PVOID pClip )
{
    (void)pClip;
    fprintf(stderr, "Mock function called: QCAP_STOP_ANIMATION_CLIP(%s)\n", "pClip");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STEP_ANIMATION_CLIP(PVOID pClip , UINT * pFrameNum , BYTE * * ppFrameBuffer , ULONG * pFrameBufferLen , BOOL bClearBackground )
{
    (void)pClip;
    (void)pFrameNum;
    (void)ppFrameBuffer;
    (void)pFrameBufferLen;
    (void)bClearBackground;
    fprintf(stderr, "Mock function called: QCAP_STEP_ANIMATION_CLIP(%s)\n", "pClip, pFrameNum, ppFrameBuffer, pFrameBufferLen, bClearBackground");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SEEK_ANIMATION_CLIP(PVOID pClip , UINT iFrameNum , BYTE * * ppFrameBuffer , ULONG * pFrameBufferLen , BOOL bClearBackground )
{
    (void)pClip;
    (void)iFrameNum;
    (void)ppFrameBuffer;
    (void)pFrameBufferLen;
    (void)bClearBackground;
    fprintf(stderr, "Mock function called: QCAP_SEEK_ANIMATION_CLIP(%s)\n", "pClip, iFrameNum, ppFrameBuffer, pFrameBufferLen, bClearBackground");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_ANIMATION_CLIP_SPRITE_TRANSFORM_PROPERTY(PVOID pClip , UINT iSpriteNum , UINT iFrameNum , INT * pPositionX , INT * pPositionY , INT * pScaleW , INT * pScaleH )
{
    (void)pClip;
    (void)iSpriteNum;
    (void)iFrameNum;
    (void)pPositionX;
    (void)pPositionY;
    (void)pScaleW;
    (void)pScaleH;
    fprintf(stderr, "Mock function called: QCAP_GET_ANIMATION_CLIP_SPRITE_TRANSFORM_PROPERTY(%s)\n", "pClip, iSpriteNum, iFrameNum, pPositionX, pPositionY, pScaleW, pScaleH");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_ANIMATION_CLIP_SPRITE_TRANSFORM_PROPERTY(PVOID pClip , UINT iSpriteNum , UINT iFrameNum , INT nPositionX , INT nPositionY , INT nScaleW , INT nScaleH )
{
    (void)pClip;
    (void)iSpriteNum;
    (void)iFrameNum;
    (void)nPositionX;
    (void)nPositionY;
    (void)nScaleW;
    (void)nScaleH;
    fprintf(stderr, "Mock function called: QCAP_SET_ANIMATION_CLIP_SPRITE_TRANSFORM_PROPERTY(%s)\n", "pClip, iSpriteNum, iFrameNum, nPositionX, nPositionY, nScaleW, nScaleH");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_ANIMATION_CLIP_SPRITE_ALPHA_PROPERTY(PVOID pClip , UINT iSpriteNum , UINT iFrameNum , double * pAlpha )
{
    (void)pClip;
    (void)iSpriteNum;
    (void)iFrameNum;
    (void)pAlpha;
    fprintf(stderr, "Mock function called: QCAP_GET_ANIMATION_CLIP_SPRITE_ALPHA_PROPERTY(%s)\n", "pClip, iSpriteNum, iFrameNum, pAlpha");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_ANIMATION_CLIP_SPRITE_ALPHA_PROPERTY(PVOID pClip , UINT iSpriteNum , UINT iFrameNum , double dAlpha )
{
    (void)pClip;
    (void)iSpriteNum;
    (void)iFrameNum;
    (void)dAlpha;
    fprintf(stderr, "Mock function called: QCAP_SET_ANIMATION_CLIP_SPRITE_ALPHA_PROPERTY(%s)\n", "pClip, iSpriteNum, iFrameNum, dAlpha");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_ANIMATION_CLIP_SPRITE_ZORDER_PROPERTY(PVOID pClip , UINT iSpriteNum , INT * pZOrder )
{
    (void)pClip;
    (void)iSpriteNum;
    (void)pZOrder;
    fprintf(stderr, "Mock function called: QCAP_GET_ANIMATION_CLIP_SPRITE_ZORDER_PROPERTY(%s)\n", "pClip, iSpriteNum, pZOrder");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_ANIMATION_CLIP_SPRITE_ZORDER_PROPERTY(PVOID pClip , UINT iSpriteNum , INT nZOrder )
{
    (void)pClip;
    (void)iSpriteNum;
    (void)nZOrder;
    fprintf(stderr, "Mock function called: QCAP_SET_ANIMATION_CLIP_SPRITE_ZORDER_PROPERTY(%s)\n", "pClip, iSpriteNum, nZOrder");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_ANIMATION_CLIP_SPRITE_SCALE_PROPERTY(PVOID pClip , UINT iSpriteNum , ULONG * pScaleStyle )
{
    (void)pClip;
    (void)iSpriteNum;
    (void)pScaleStyle;
    fprintf(stderr, "Mock function called: QCAP_GET_ANIMATION_CLIP_SPRITE_SCALE_PROPERTY(%s)\n", "pClip, iSpriteNum, pScaleStyle");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_ANIMATION_CLIP_SPRITE_SCALE_PROPERTY(PVOID pClip , UINT iSpriteNum , ULONG nScaleStyle )
{
    (void)pClip;
    (void)iSpriteNum;
    (void)nScaleStyle;
    fprintf(stderr, "Mock function called: QCAP_SET_ANIMATION_CLIP_SPRITE_SCALE_PROPERTY(%s)\n", "pClip, iSpriteNum, nScaleStyle");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_ANIMATION_CLIP_SPRITE_BLINDS_PROPERTY(PVOID pClip , UINT iSpriteNum , ULONG * pBlindsType , ULONG * pSlices , ULONG * pDirection )
{
    (void)pClip;
    (void)iSpriteNum;
    (void)pBlindsType;
    (void)pSlices;
    (void)pDirection;
    fprintf(stderr, "Mock function called: QCAP_GET_ANIMATION_CLIP_SPRITE_BLINDS_PROPERTY(%s)\n", "pClip, iSpriteNum, pBlindsType, pSlices, pDirection");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_ANIMATION_CLIP_SPRITE_BLINDS_PROPERTY(PVOID pClip , UINT iSpriteNum , ULONG nBlindsType , ULONG nSlices , ULONG nDirection )
{
    (void)pClip;
    (void)iSpriteNum;
    (void)nBlindsType;
    (void)nSlices;
    (void)nDirection;
    fprintf(stderr, "Mock function called: QCAP_SET_ANIMATION_CLIP_SPRITE_BLINDS_PROPERTY(%s)\n", "pClip, iSpriteNum, nBlindsType, nSlices, nDirection");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_ANIMATION_CLIP_SPRITE_MIRROR_PROPERTY(PVOID pClip , UINT iSpriteNum , ULONG * pMirrorType )
{
    (void)pClip;
    (void)iSpriteNum;
    (void)pMirrorType;
    fprintf(stderr, "Mock function called: QCAP_GET_ANIMATION_CLIP_SPRITE_MIRROR_PROPERTY(%s)\n", "pClip, iSpriteNum, pMirrorType");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_ANIMATION_CLIP_SPRITE_MIRROR_PROPERTY(PVOID pClip , UINT iSpriteNum , ULONG nMirrorType )
{
    (void)pClip;
    (void)iSpriteNum;
    (void)nMirrorType;
    fprintf(stderr, "Mock function called: QCAP_SET_ANIMATION_CLIP_SPRITE_MIRROR_PROPERTY(%s)\n", "pClip, iSpriteNum, nMirrorType");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_ANIMATION_CLIP_SPRITE_PICTURE(PVOID pClip , UINT iSpriteNum , CHAR * pszFilePathName )
{
    (void)pClip;
    (void)iSpriteNum;
    (void)pszFilePathName;
    fprintf(stderr, "Mock function called: QCAP_SET_ANIMATION_CLIP_SPRITE_PICTURE(%s)\n", "pClip, iSpriteNum, pszFilePathName");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_ANIMATION_CLIP_SPRITE_BUFFER(PVOID pClip , UINT iSpriteNum , ULONG nColorSpaceType , ULONG nWidth , ULONG nHeight , BYTE * pFrameBuffer , ULONG nFrameBufferLen , BOOL bCloneCopy )
{
    (void)pClip;
    (void)iSpriteNum;
    (void)nColorSpaceType;
    (void)nWidth;
    (void)nHeight;
    (void)pFrameBuffer;
    (void)nFrameBufferLen;
    (void)bCloneCopy;
    fprintf(stderr, "Mock function called: QCAP_SET_ANIMATION_CLIP_SPRITE_BUFFER(%s)\n", "pClip, iSpriteNum, nColorSpaceType, nWidth, nHeight, pFrameBuffer, nFrameBufferLen, bCloneCopy");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_ANIMATION_CLIP_SPRITE_BUFFER_EX(PVOID pClip , UINT iSpriteNum , ULONG nColorSpaceType , ULONG nWidth , ULONG nHeight , BYTE * pFrameBuffer , ULONG nFrameBufferLen , ULONG nCropX , ULONG nCropY , ULONG nCropW , ULONG nCropH , BOOL bCloneCopy )
{
    (void)pClip;
    (void)iSpriteNum;
    (void)nColorSpaceType;
    (void)nWidth;
    (void)nHeight;
    (void)pFrameBuffer;
    (void)nFrameBufferLen;
    (void)nCropX;
    (void)nCropY;
    (void)nCropW;
    (void)nCropH;
    (void)bCloneCopy;
    fprintf(stderr, "Mock function called: QCAP_SET_ANIMATION_CLIP_SPRITE_BUFFER_EX(%s)\n", "pClip, iSpriteNum, nColorSpaceType, nWidth, nHeight, pFrameBuffer, nFrameBufferLen, nCropX, nCropY, nCropW, nCropH, bCloneCopy");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_ANIMATION_CLIP_SPRITE_SOURCE(PVOID pClip , UINT iSpriteNum , PVOID pDevice , ULONG nSequenceStyle , BOOL bCloneCopy )
{
    (void)pClip;
    (void)iSpriteNum;
    (void)pDevice;
    (void)nSequenceStyle;
    (void)bCloneCopy;
    fprintf(stderr, "Mock function called: QCAP_SET_ANIMATION_CLIP_SPRITE_SOURCE(%s)\n", "pClip, iSpriteNum, pDevice, nSequenceStyle, bCloneCopy");
    return QCAP_RS_SUCCESSFUL;
}

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_ANIMATION_CLIP_SPRITE_SOURCE_EX(PVOID pClip , UINT iSpriteNum , PVOID pDevice , ULONG nCropX , ULONG nCropY , ULONG nCropW , ULONG nCropH , ULONG nSequenceStyle , BOOL bCloneCopy )
{
    (void)pClip;
    (void)iSpriteNum;
    (void)pDevice;
    (void)nCropX;
    (void)nCropY;
    (void)nCropW;
    (void)nCropH;
    (void)nSequenceStyle;
    (void)bCloneCopy;
    fprintf(stderr, "Mock function called: QCAP_SET_ANIMATION_CLIP_SPRITE_SOURCE_EX(%s)\n", "pClip, iSpriteNum, pDevice, nCropX, nCropY, nCropW, nCropH, nSequenceStyle, bCloneCopy");
    return QCAP_RS_SUCCESSFUL;
}

