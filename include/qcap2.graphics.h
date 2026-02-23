#ifndef __QCAP2_GRAPHICS_H__
#define __QCAP2_GRAPHICS_H__

#include "qcap2.types.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

// qcap2_font_atlas_t
qcap2_font_atlas_t* qcap2_font_atlas_new();
void qcap2_font_atlas_delete(qcap2_font_atlas_t* pThis);
void qcap2_font_atlas_set_font_file(qcap2_font_atlas_t* pThis, const char* strFontFile);
void qcap2_font_atlas_set_family_name(qcap2_font_atlas_t* pThis, const char* strFamilyName);
void qcap2_font_atlas_set_style(qcap2_font_atlas_t* pThis, int nStyle); // refer to QCAP_FONT_STYLE_XXX
void qcap2_font_atlas_set_char_size(qcap2_font_atlas_t* pThis, int nCharSize); // point size
void qcap2_font_atlas_set_dpi(qcap2_font_atlas_t* pThis, int nDPI);
void qcap2_font_atlas_set_atlas_size(qcap2_font_atlas_t* pThis, int nWidth, int nHeight);
QRESULT qcap2_font_atlas_start(qcap2_font_atlas_t* pThis);
QRESULT qcap2_font_atlas_stop(qcap2_font_atlas_t* pThis);
float qcap2_font_atlas_get_ascender(qcap2_font_atlas_t* pThis);
float qcap2_font_atlas_get_descender(qcap2_font_atlas_t* pThis);
float qcap2_font_atlas_get_height(qcap2_font_atlas_t* pThis);

// qcap2_graphics_t
qcap2_graphics_t* qcap2_graphics_new();
void qcap2_graphics_delete(qcap2_graphics_t* pThis);
void qcap2_graphics_set_backend_type(qcap2_graphics_t* pThis, int nBackendType);
QRESULT qcap2_graphics_start(qcap2_graphics_t* pThis);
QRESULT qcap2_graphics_stop(qcap2_graphics_t* pThis);
QRESULT qcap2_graphics_begin(qcap2_graphics_t* pThis, qcap2_rcbuffer_t* pRCBuffer);
QRESULT qcap2_graphics_end(qcap2_graphics_t* pThis);
void qcap2_graphics_set_font_atlas(qcap2_graphics_t* pThis, qcap2_font_atlas_t* pFontAtlas);
void qcap2_graphics_set_color(qcap2_graphics_t* pThis, int32_t nColor); // 0xAARRGGBB
QRESULT qcap2_graphics_fill_rect(qcap2_graphics_t* pThis, int x, int y, int w, int h);
QRESULT qcap2_graphics_draw_text(qcap2_graphics_t* pThis, const char* strText, int x, int y, int w, int h);
QRESULT qcap2_graphics_get_text_size(qcap2_graphics_t* pThis, const char* strText, int* x, int* y, int* w, int* h);
// QRESULT qcap2_graphics_draw_sprite(qcap2_graphics_t* pThis, qcap2_rcbuffer_t* pRCBuffer, int x, int y, int w, int h);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif // __QCAP2_GRAPHICS_H__
