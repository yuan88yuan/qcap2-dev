#ifndef QCAP_ANIMATION_H
#define QCAP_ANIMATION_H

#include "qcap.types.h"

#ifdef __cplusplus
extern "C"
{
#endif

// ##########################################################################################################################################################################################
// #
// # ANIMATION FUNCTIONS
// #
// ##########################################################################################################################################################################################
//
QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_CREATE_ANIMATION_CLIP( CHAR * pszAniFilePathName /*IN*/, PVOID * ppClip /*OUT*/, ULONG * pTotalFrames /*OUT*/, ULONG * pTotalSprites /*OUT*/, ULONG * pColorSpaceType /*OUT*/, ULONG * pWidth /*OUT*/, ULONG * pHeight /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_DESTROY_ANIMATION_CLIP( PVOID pClip /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_START_ANIMATION_CLIP( PVOID pClip /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STOP_ANIMATION_CLIP( PVOID pClip /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_STEP_ANIMATION_CLIP( PVOID pClip /*IN*/, UINT * pFrameNum /*OUT*/, BYTE * * ppFrameBuffer /*OUT*/, ULONG * pFrameBufferLen /*OUT*/, BOOL bClearBackground DEFVAL( TRUE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SEEK_ANIMATION_CLIP( PVOID pClip /*IN*/, UINT iFrameNum /*IN*/, BYTE * * ppFrameBuffer /*OUT*/, ULONG * pFrameBufferLen /*OUT*/, BOOL bClearBackground DEFVAL( TRUE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_ANIMATION_CLIP_SPRITE_TRANSFORM_PROPERTY( PVOID pClip /*IN*/, UINT iSpriteNum /*IN*/, UINT iFrameNum /*IN*/, INT * pPositionX /*OUT*/, INT * pPositionY /*OUT*/, INT * pScaleW /*OUT*/, INT * pScaleH /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_ANIMATION_CLIP_SPRITE_TRANSFORM_PROPERTY( PVOID pClip /*IN*/, UINT iSpriteNum /*IN*/, UINT iFrameNum /*IN*/, INT nPositionX /*IN*/, INT nPositionY /*IN*/, INT nScaleW /*IN*/, INT nScaleH /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_ANIMATION_CLIP_SPRITE_ALPHA_PROPERTY( PVOID pClip /*IN*/, UINT iSpriteNum /*IN*/, UINT iFrameNum /*IN*/, double * pAlpha /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_ANIMATION_CLIP_SPRITE_ALPHA_PROPERTY( PVOID pClip /*IN*/, UINT iSpriteNum /*IN*/, UINT iFrameNum /*IN*/, double dAlpha /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_ANIMATION_CLIP_SPRITE_ZORDER_PROPERTY( PVOID pClip /*IN*/, UINT iSpriteNum /*IN*/, INT * pZOrder /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_ANIMATION_CLIP_SPRITE_ZORDER_PROPERTY( PVOID pClip /*IN*/, UINT iSpriteNum /*IN*/, INT nZOrder /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_ANIMATION_CLIP_SPRITE_SCALE_PROPERTY( PVOID pClip /*IN*/, UINT iSpriteNum /*IN*/, ULONG * pScaleStyle /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_ANIMATION_CLIP_SPRITE_SCALE_PROPERTY( PVOID pClip /*IN*/, UINT iSpriteNum /*IN*/, ULONG nScaleStyle /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_ANIMATION_CLIP_SPRITE_BLINDS_PROPERTY( PVOID pClip /*IN*/, UINT iSpriteNum /*IN*/, ULONG * pBlindsType /*OUT*/, ULONG * pSlices /*OUT*/, ULONG * pDirection /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_ANIMATION_CLIP_SPRITE_BLINDS_PROPERTY( PVOID pClip /*IN*/, UINT iSpriteNum /*IN*/, ULONG nBlindsType /*IN*/, ULONG nSlices /*IN*/, ULONG nDirection /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_GET_ANIMATION_CLIP_SPRITE_MIRROR_PROPERTY( PVOID pClip /*IN*/, UINT iSpriteNum /*IN*/, ULONG * pMirrorType /*OUT*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_ANIMATION_CLIP_SPRITE_MIRROR_PROPERTY( PVOID pClip /*IN*/, UINT iSpriteNum /*IN*/, ULONG nMirrorType DEFVAL( QCAP_ANIMATION_CLIP_MIRROR_TYPE_NONE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_ANIMATION_CLIP_SPRITE_PICTURE( PVOID pClip /*IN*/, UINT iSpriteNum /*IN*/, CHAR * pszFilePathName /*IN*/ );

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_ANIMATION_CLIP_SPRITE_BUFFER( PVOID pClip /*IN*/, UINT iSpriteNum /*IN*/, ULONG nColorSpaceType /*IN*/, ULONG nWidth /*IN*/, ULONG nHeight /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, BOOL bCloneCopy DEFVAL( FALSE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_ANIMATION_CLIP_SPRITE_BUFFER_EX( PVOID pClip /*IN*/, UINT iSpriteNum /*IN*/, ULONG nColorSpaceType /*IN*/, ULONG nWidth /*IN*/, ULONG nHeight /*IN*/, BYTE * pFrameBuffer /*IN*/, ULONG nFrameBufferLen /*IN*/, ULONG nCropX /*IN*/, ULONG nCropY /*IN*/, ULONG nCropW /*IN*/, ULONG nCropH /*IN*/, BOOL bCloneCopy DEFVAL( FALSE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_ANIMATION_CLIP_SPRITE_SOURCE( PVOID pClip /*IN*/, UINT iSpriteNum /*IN*/, PVOID pDevice /*IN*/, ULONG nSequenceStyle DEFVAL( QCAP_SEQUENCE_STYLE_FOREMOST /*IN*/), BOOL bCloneCopy DEFVAL( FALSE /*IN*/ ));

QCAP_EXT_API QRESULT QCAP_EXPORT QCAP_SET_ANIMATION_CLIP_SPRITE_SOURCE_EX( PVOID pClip /*IN*/, UINT iSpriteNum /*IN*/, PVOID pDevice /*IN*/, ULONG nCropX /*IN*/, ULONG nCropY /*IN*/, ULONG nCropW /*IN*/, ULONG nCropH /*IN*/, ULONG nSequenceStyle DEFVAL( QCAP_SEQUENCE_STYLE_FOREMOST /*IN*/), BOOL bCloneCopy DEFVAL( FALSE /*IN*/ ));

#ifdef __cplusplus
}
#endif

#endif // QCAP_ANIMATION_H
