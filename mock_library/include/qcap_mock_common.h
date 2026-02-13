
#pragma once

#include <cstddef> // For size_t, nullptr
#include <cstdint> // For intptr_t, uintptr_t
#include <cstdio>  // For fprintf, stderr

// Define QCAP_EXT_API and QCAP_EXPORT for mocking
#ifndef QCAP_EXT_API
#define QCAP_EXT_API
#endif

#ifndef QCAP_EXPORT
#define QCAP_EXPORT
#endif

// Define DEFVAL macro for C++ compatibility
#ifndef DEFVAL
#ifdef __cplusplus
#define DEFVAL(value) = value
#else
#define DEFVAL(value)
#endif
#endif

// Dummy QRESULT definition for mocking. QRETURN will be taken from qcap.types.h
// typedef int QRESULT; // Removed here, will be parsed from qcap.types.h or similar if exists.
#define QCAP_RS_SUCCESSFUL 0
#define QCAP_RS_FAILED 1

// Dummy WSTRING and PVOID definitions
#ifndef WSTRING
typedef wchar_t* WSTRING;
#endif

#ifndef PVOID
typedef void* PVOID;
#endif

// Dummy HWND definition
#ifndef HWND
typedef void* HWND; // Mock HWND as a void pointer
#endif

// Add other common types if necessary, e.g., ULONG, ULONGLONG, DWORD
#ifndef ULONG
typedef unsigned long ULONG;
#endif

#ifndef ULONGLONG
typedef unsigned long long ULONGLONG;
#endif

#ifndef DWORD
typedef unsigned long DWORD;
#endif

#ifndef BOOL
typedef int BOOL;
#define TRUE 1
#define FALSE 0
#endif

#ifndef CHAR
typedef char CHAR;
#endif

#ifndef BYTE
typedef unsigned char BYTE;
#endif

#ifndef UINT
typedef unsigned int UINT;
#endif

#ifndef INT
typedef int INT;
#endif

#ifndef LONG
typedef long LONG;
#endif

// Mock missing constants/enum members found during compilation
#ifndef BASELINE
#define BASELINE 0
#endif

#ifndef CAVLC
#define CAVLC 0
#endif

#ifndef QCAP_ENUM_TYPE_DEVICE_NAME
#define QCAP_ENUM_TYPE_DEVICE_NAME 0
#endif

#ifndef QCAP_CUDAHOST_ALLOC_MAPPED
#define QCAP_CUDAHOST_ALLOC_MAPPED 0
#endif

#ifndef QCAP_STRING_ALIGNMENT_STYLE_LEFT
#define QCAP_STRING_ALIGNMENT_STYLE_LEFT 0
#endif

#ifndef QCAP_SEQUENCE_STYLE_FOREMOST
#define QCAP_SEQUENCE_STYLE_FOREMOST 0
#endif

#ifndef QCAP_RECORD_FLAG_FULL
#define QCAP_RECORD_FLAG_FULL 0
#endif

#ifndef QCAP_3D_STEREO_BUFFER_SIDE_BY_SIDE
#define QCAP_3D_STEREO_BUFFER_SIDE_BY_SIDE 0
#endif

#ifndef QCAP_SCALE_STYLE_STRETCH
#define QCAP_SCALE_STYLE_STRETCH 0
#endif

#ifndef QCAP_SIP_TRANSPORT_PROTOCOL_UDP
#define QCAP_SIP_TRANSPORT_PROTOCOL_UDP 0
#endif

#ifndef QCAP_DECODER_TYPE_SOFTWARE
#define QCAP_DECODER_TYPE_SOFTWARE 0
#endif

#ifndef QCAP_FILE_TIMEUNIT_FRAME
#define QCAP_FILE_TIMEUNIT_FRAME 0
#endif

#ifndef QCAP_HL7_VERSION_24
#define QCAP_HL7_VERSION_24 0
#endif

#ifndef QCAP_ANIMATION_CLIP_MIRROR_TYPE_NONE
#define QCAP_ANIMATION_CLIP_MIRROR_TYPE_NONE 0
#endif

#ifndef QCAP_COLORSPACE_TYPE_ABGR32
#define QCAP_COLORSPACE_TYPE_ABGR32 0
#endif

#ifndef QCAP_3D_STEREO_DISPLAY_MODE_LINE_BY_LINE
#define QCAP_3D_STEREO_DISPLAY_MODE_LINE_BY_LINE 0
#endif

#ifndef QCAP_SERIAL_PORT_PARITY_CHECK_NONE
#define QCAP_SERIAL_PORT_PARITY_CHECK_NONE 0
#endif

#ifndef QCAP_SERIAL_PORT_STOP_BITS_ONE
#define QCAP_SERIAL_PORT_STOP_BITS_ONE 0
#endif

#ifndef QCAP_SERIAL_PORT_FLOW_CONTROL_NONE
#define QCAP_SERIAL_PORT_FLOW_CONTROL_NONE 0
#endif

#ifndef QCAP_COLORRANGE_TYPE_FULL
#define QCAP_COLORRANGE_TYPE_FULL 0
#endif

// Windows specific types mocking (from qcap.windef.h)
#ifndef ULONG_PTR
typedef unsigned long ULONG_PTR;
#endif
#ifndef DWORD_PTR
typedef unsigned long DWORD_PTR;
#endif
#ifndef _W64
#define _W64
#endif
#ifndef WORD
typedef unsigned short WORD;
#endif
#ifndef CRITICAL_SECTION
typedef void* CRITICAL_SECTION; // Mock as void*
#endif
#ifndef VOID
#define VOID void
#endif

// Mock for complex structs that might cause issues, simplifying them
// These are often found in qcap.windef.h
#ifndef BITMAPFILEHEADER_DEFINED
#define BITMAPFILEHEADER_DEFINED
typedef struct tagBITMAPFILEHEADER {
  WORD    bfType;
  DWORD   bfSize;
  WORD    bfReserved1;
  WORD    bfReserved2;
  DWORD   bfOffBits;
} BITMAPFILEHEADER;
#endif

#ifndef BITMAPINFOHEADER_DEFINED
#define BITMAPINFOHEADER_DEFINED
typedef struct tagBITMAPINFOHEADER {
  DWORD  biSize;
  LONG   biWidth;
  LONG   biHeight;
  WORD   biPlanes;
  WORD   biBitCount;
  DWORD  biCompression;
  DWORD  biSizeImage;
  LONG   biXPelsPerMeter;
  LONG   biYPelsPerMeter;
  DWORD  biClrUsed;
  DWORD  biClrImportant;
} BITMAPINFOHEADER;
#endif

// Mock for complex types from qcap.hi3531a.h
#ifndef qcap_generic_av_frame_t
typedef struct qcap_generic_av_frame_t {
    // Simplified structure for mocking
    PVOID  pData[4];
    int    iLineSize[4];
    int    iWidth;
    int    iHeight;
    int    iFormat;
    long long  llPTS;
} qcap_generic_av_frame_t;
#endif

#ifndef PBYTE
typedef unsigned char* PBYTE;
#endif

#ifndef QCAP_PROPERTY_MCU_VERSION_RESPONSE
typedef struct QCAP_PROPERTY_MCU_VERSION_RESPONSE_mock {} QCAP_PROPERTY_MCU_VERSION_RESPONSE;
#endif
#ifndef QCAP_PROPERTY_SC632N8_MCU_VERSION_RESPONSE
typedef QCAP_PROPERTY_MCU_VERSION_RESPONSE QCAP_PROPERTY_SC632N8_MCU_VERSION_RESPONSE;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4HDMI_MCU_VERSION_OUT
typedef QCAP_PROPERTY_MCU_VERSION_RESPONSE QCAP_PROPERTY_SC6D0N4HDMI_MCU_VERSION_OUT;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4SDI_MCU_VERSION_OUT
typedef QCAP_PROPERTY_MCU_VERSION_RESPONSE QCAP_PROPERTY_SC6D0N4SDI_MCU_VERSION_OUT;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4_MCU_VERSION_RESPONSE
typedef QCAP_PROPERTY_MCU_VERSION_RESPONSE QCAP_PROPERTY_SC6D0N4_MCU_VERSION_RESPONSE;
#endif
#ifndef QCAP_PROPERTY_SC6D0N8_MCU_VERSION_OUT
typedef QCAP_PROPERTY_MCU_VERSION_RESPONSE QCAP_PROPERTY_SC6D0N8_MCU_VERSION_OUT;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4HDMI_LED_IN
typedef struct QCAP_PROPERTY_SC6D0N4HDMI_LED_IN_mock {} QCAP_PROPERTY_SC6D0N4HDMI_LED_IN;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4HDMIQL_LED_IN
typedef QCAP_PROPERTY_SC6D0N4HDMI_LED_IN QCAP_PROPERTY_SC6D0N4HDMIQL_LED_IN;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4HDMIQL_MCU_VERSION_OUT
typedef QCAP_PROPERTY_MCU_VERSION_RESPONSE QCAP_PROPERTY_SC6D0N4HDMIQL_MCU_VERSION_OUT;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4SDI_AUDIO_MIXER_IN
typedef struct QCAP_PROPERTY_SC6D0N4SDI_AUDIO_MIXER_IN_mock {} QCAP_PROPERTY_SC6D0N4SDI_AUDIO_MIXER_IN;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4HDMI_AUDIO_MIXER_IN
typedef QCAP_PROPERTY_SC6D0N4SDI_AUDIO_MIXER_IN QCAP_PROPERTY_SC6D0N4HDMI_AUDIO_MIXER_IN;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4SDI_AUDIO_MIXER_VOLUME_IN
typedef struct QCAP_PROPERTY_SC6D0N4SDI_AUDIO_MIXER_VOLUME_IN_mock {} QCAP_PROPERTY_SC6D0N4SDI_AUDIO_MIXER_VOLUME_IN;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4HDMI_AUDIO_MIXER_VOLUME_IN
typedef QCAP_PROPERTY_SC6D0N4SDI_AUDIO_MIXER_VOLUME_IN QCAP_PROPERTY_SC6D0N4HDMI_AUDIO_MIXER_VOLUME_IN;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4SDI_BUTTON_BACKLIGHT_IN
typedef struct QCAP_PROPERTY_SC6D0N4SDI_BUTTON_BACKLIGHT_IN_mock {} QCAP_PROPERTY_SC6D0N4SDI_BUTTON_BACKLIGHT_IN;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4HDMI_BUTTON_BACKLIGHT_IN
typedef QCAP_PROPERTY_SC6D0N4SDI_BUTTON_BACKLIGHT_IN QCAP_PROPERTY_SC6D0N4HDMI_BUTTON_BACKLIGHT_IN;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4SDI_BUTTON_OUT
typedef struct QCAP_PROPERTY_SC6D0N4SDI_BUTTON_OUT_mock {} QCAP_PROPERTY_SC6D0N4SDI_BUTTON_OUT;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4HDMI40_BUTTON_OUT
typedef QCAP_PROPERTY_SC6D0N4SDI_BUTTON_OUT QCAP_PROPERTY_SC6D0N4HDMI40_BUTTON_OUT;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4HDMI_BUTTON_OUT
typedef QCAP_PROPERTY_SC6D0N4SDI_BUTTON_OUT QCAP_PROPERTY_SC6D0N4HDMI_BUTTON_OUT;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4SDI_LED_IN
typedef struct QCAP_PROPERTY_SC6D0N4SDI_LED_IN_mock {} QCAP_PROPERTY_SC6D0N4SDI_LED_IN;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4HDMI40_LED_IN
typedef QCAP_PROPERTY_SC6D0N4SDI_LED_IN QCAP_PROPERTY_SC6D0N4HDMI40_LED_IN;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4HDMI_LED_IN
typedef QCAP_PROPERTY_SC6D0N4SDI_LED_IN QCAP_PROPERTY_SC6D0N4HDMI_LED_IN;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4SDIQL_LED_IN
typedef QCAP_PROPERTY_SC6D0N4SDI_LED_IN QCAP_PROPERTY_SC6D0N4SDIQL_LED_IN;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4HDMI40_MCU_VERSION_OUT
typedef QCAP_PROPERTY_MCU_VERSION_RESPONSE QCAP_PROPERTY_SC6D0N4HDMI40_MCU_VERSION_OUT;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4SDIQL_MCU_VERSION_OUT
typedef QCAP_PROPERTY_MCU_VERSION_RESPONSE QCAP_PROPERTY_SC6D0N4SDIQL_MCU_VERSION_OUT;
#endif

// Collected Typedefs from original headers
typedef LONG HRESULT;
typedef char TCHAR;
typedef const TCHAR *LPCTSTR;
typedef enum  {
  KS_AnalogVideo_None         = 0x00000000,
  KS_AnalogVideo_NTSC_M       = 0x00000001,
  KS_AnalogVideo_NTSC_M_J     = 0x00000002,
  KS_AnalogVideo_NTSC_433     = 0x00000004,
  KS_AnalogVideo_PAL_B        = 0x00000010,
  KS_AnalogVideo_PAL_D        = 0x00000020,
  KS_AnalogVideo_PAL_G        = 0x00000040,
  KS_AnalogVideo_PAL_H        = 0x00000080,
  KS_AnalogVideo_PAL_I        = 0x00000100,
  KS_AnalogVideo_PAL_M        = 0x00000200,
  KS_AnalogVideo_PAL_N        = 0x00000400,
  KS_AnalogVideo_PAL_60       = 0x00000800,
  KS_AnalogVideo_SECAM_B      = 0x00001000,
  KS_AnalogVideo_SECAM_D      = 0x00002000,
  KS_AnalogVideo_SECAM_G      = 0x00004000,
  KS_AnalogVideo_SECAM_H      = 0x00008000,
  KS_AnalogVideo_SECAM_K      = 0x00010000,
  KS_AnalogVideo_SECAM_K1     = 0x00020000,
  KS_AnalogVideo_SECAM_L      = 0x00040000,
  KS_AnalogVideo_SECAM_L1     = 0x00080000,
  KS_AnalogVideo_PAL_N_COMBO  = 0x00100000
} KS_AnalogVideoStandard;
typedef enum {

	QCAP_RT_OK					= 0x00000000,
	
	QCAP_RT_FAIL				= 0x00000001,

	QCAP_RT_SKIP_RECORD_NUM_00	= 0x00010002, 

	QCAP_RT_SKIP_RECORD_NUM_01	= 0x00020002, 

	QCAP_RT_SKIP_RECORD_NUM_02	= 0x00040002, 

	QCAP_RT_SKIP_RECORD_NUM_03	= 0x00080002, 

	QCAP_RT_SKIP_DISPLAY		= 0x00000004, 
											  
											  
											  
											  
											  
											  
											  
	QCAP_RT_SKIP_CLONE_DISPLAY	= 0x00000008, 

	QCAP_RT_RESET_RECORD_NUM_00	= 0x01000010, 

	QCAP_RT_RESET_RECORD_NUM_01	= 0x02000010, 

	QCAP_RT_RESET_RECORD_NUM_02	= 0x04000010, 

	QCAP_RT_RESET_RECORD_NUM_03	= 0x08000010, 

} QRETURN;
typedef int BOOL;
typedef int BOOLEAN;
typedef int INT;
typedef int SOCKET;
typedef int32_t NTSTATUS;
typedef int64_t __int64;
typedef long long LONGLONG;
typedef long long REFERENCE_TIME;
typedef struct sockaddr_in SOCKADDR_IN;
typedef uint8_t byte;
typedef unsigned int UINT;
typedef unsigned long long ULONGLONG;
