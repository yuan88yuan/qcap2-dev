#ifndef MOCK_QCAP_WINDEF_H
#define MOCK_QCAP_WINDEF_H

#include "qcap_mock_common.h"
#include "mock_qcap_osd.h"
#include "mock_qcap_linux.h"
#include "mock_qcap_common.h"
#include "mock_qcap_burning.h"
#include "mock_qcap_timer.h"
#include "mock_qcap_helper.h"
#include "mock_qcap_device.h"
#include "mock_qcap_onvif.h"
#include "mock_qcap_recording.h"
#include "mock_qcap_h2.h"
#include "mock_qcap_hl7.h"
#include "mock_qcap_ccvt.h"
#include "mock_qcap_types.h"
#include "mock_qcap_broadcast.h"
#include "mock_qcap_dicom.h"
#include "mock_qcap_h.h"
#include "mock_qcap_hi3531a.h"
#include "mock_qcap_animation.h"
#include "mock_qcap_webrtc.h"
#include "mock_qcap_sip.h"
#include "mock_qcap_callbacks.h"
#include "mock_qcap_system.h"
#include "mock_qcap_serial.h"
#include "mock_qcap_virtualcamera.h"
#include "mock_qcap_playback.h"

#ifdef __cplusplus
extern "C"
{
#endif

// Typedefs
typedef LONG HRESULT;
typedef PVOID HANDLE;
typedef PVOID HWND;
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

// Function Declarations

#ifdef __cplusplus
}
#endif

#endif // MOCK_QCAP_WINDEF_H
