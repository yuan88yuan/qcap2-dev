#ifndef MOCK_QCAP_TYPES_H
#define MOCK_QCAP_TYPES_H

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
#include "mock_qcap_broadcast.h"
#include "mock_qcap_dicom.h"
#include "mock_qcap_h.h"
#include "mock_qcap_windef.h"
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
typedef enum {

	QCAP_RT_OK					= 0x00000000,
	
	QCAP_RT_FAIL				= 0x00000001,

	QCAP_RT_SKIP_RECORD_NUM_00	= 0x00010002, // ONLY FOR PF_VIDEO_PREVIEW_CALLBACK / PF_AUDIO_PREVIEW_CALLBACK

	QCAP_RT_SKIP_RECORD_NUM_01	= 0x00020002, // ONLY FOR PF_VIDEO_PREVIEW_CALLBACK / PF_AUDIO_PREVIEW_CALLBACK

	QCAP_RT_SKIP_RECORD_NUM_02	= 0x00040002, // ONLY FOR PF_VIDEO_PREVIEW_CALLBACK / PF_AUDIO_PREVIEW_CALLBACK

	QCAP_RT_SKIP_RECORD_NUM_03	= 0x00080002, // ONLY FOR PF_VIDEO_PREVIEW_CALLBACK / PF_AUDIO_PREVIEW_CALLBACK

	QCAP_RT_SKIP_DISPLAY		= 0x00000004, // ONLY FOR PF_VIDEO_PREVIEW_CALLBACK / PF_AUDIO_PREVIEW_CALLBACK / 
											  //
											  //		  PF_VIDEO_BROADCAST_CLIENT_CALLBACK / PF_AUDIO_BROADCAST_CLIENT_CALLBACK / 
											  //
											  //		  PF_VIDEO_DECODER_BROADCAST_CLIENT_CALLBACK / PF_AUDIO_DECODER_BROADCAST_CLIENT_CALLBACK /
											  //
											  //		  PF_VIDEO_DECODER_FILE_CALLBACK / PF_AUDIO_DECODER_FILE_CALLBACK
											  
	QCAP_RT_SKIP_CLONE_DISPLAY	= 0x00000008, // ONLY FOR PF_VIDEO_PREVIEW_CALLBACK / PF_AUDIO_PREVIEW_CALLBACK

	QCAP_RT_RESET_RECORD_NUM_00	= 0x01000010, // ONLY FOR PF_VIDEO_PREVIEW_CALLBACK / PF_AUDIO_PREVIEW_CALLBACK

	QCAP_RT_RESET_RECORD_NUM_01	= 0x02000010, // ONLY FOR PF_VIDEO_PREVIEW_CALLBACK / PF_AUDIO_PREVIEW_CALLBACK

	QCAP_RT_RESET_RECORD_NUM_02	= 0x04000010, // ONLY FOR PF_VIDEO_PREVIEW_CALLBACK / PF_AUDIO_PREVIEW_CALLBACK

	QCAP_RT_RESET_RECORD_NUM_03	= 0x08000010, // ONLY FOR PF_VIDEO_PREVIEW_CALLBACK / PF_AUDIO_PREVIEW_CALLBACK

} QRETURN;

// Function Declarations

#ifdef __cplusplus
}
#endif

#endif // MOCK_QCAP_TYPES_H
