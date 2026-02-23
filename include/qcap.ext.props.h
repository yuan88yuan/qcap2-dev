#ifndef __QCAP_EXT_PROPS_H__
#define __QCAP_EXT_PROPS_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

enum {
	// for linux_base
	QCAP_PROPERTY_DISPLAY_SYSTEM = 10000,			// in,out: ULONG
	QCAP_PROPERTY_GRAPHIC_WINDOW_SYSTEM,			// in,out: ULONG
	QCAP_PROPERTY_BUTTON_EVENT,						// out: QCAP_PROPERTY_BUTTON_EVENT_RESPONSE
	QCAP_PROPERTY_UB3300_DEVINFO,					// in, ULONG[3]: [HIDRAW, VIDEO4LINUX, ALSA]

	// for hisiv_base
	QCAP_PROPERTY_FILE_PIPELINE_MODE = 20000,		// in,out: ULONG
	QCAP_PROPERTY_TSENSOR_DETECT,					// in,out: ULONG
	QCAP_PROPERTY_HDMI_VO_PARAM,
	QCAP_PROPERTY_COLOR_RANGE,
	QCAP_PROPERTY_VO_PARAM,
	QCAP_PROPERTY_VO_CSC_PARAM,
	QCAP_PROPERTY_MCU_VERSION,
	QCAP_PROPERTY_COPY_PROTECT_KEY,
	QCAP_PROPERTY_COPY_PROTECT_CHECK,
	QCAP_PROPERTY_GPIO_OUTPUT,
	QCAP_PROPERTY_AUDIO_MIXER_SOURCE_VOLUME,
	QCAP_PROPERTY_LED,								// in: QCAP_PROPERTY_LED_VALUE
	QCAP_PROPERTY_BUTTON,							// out: QCAP_PROPERTY_BUTTON_RESPONSE
	QCAP_PROPERTY_VOLUME,							// in: QCAP_PROPERTY_VOLUME_VALUE
	QCAP_PROPERTY_NDI_MODE,							// out: QCAP_PROPERTY_NDI_MODE_RESPONSE
	QCAP_PROPERTY_NOISE_GATE,						// in: QCAP_PROPERTY_NOISE_GATE_VALUE
	QCAP_PROPERTY_NDI_KEY,							// in/out: QCAP_PROPERTY_NDI_KEY_VALUE
	QCAP_PROPERTY_BUTTON_EX,						// out: QCAP_PROPERTY_BUTTON_EX_RESPONSE
	QCAP_PROPERTY_MENU,								// in: QCAP_PROPERTY_MENU_VALUE

	// for both use
	QCAP_PROPERTY_LED_EX = 30000,					// in: QCAP_PROPERTY_LED_EX_VALUE
	QCAP_PROPERTY_BUTTON_FD,						// out: int
	QCAP_PROPERTY_ACTIVATE,							// in: ULONG
	QCAP_PROPERTY_VERSION,							// in: int
	QCAP_PROPERTY_VO_BACKEND,						// [in/out, ULONG] 0:sdl, 1:gstreamer, 2:davmf, 3:vitis
};

// device custom property
enum {
	// compatible with QCAP-WIN
	QCAP_DEVPROP_FIRMWARE_VERSION = 6,				// [out, ULONG]
	QCAP_DEVPROP_TRANSFER_MODE = 10,				// [in/out, ULONG] 0:bulk, 1:isoc
	QCAP_DEVPROP_HARDWARE_VERSION = 15,				// [out, ULONG]
	QCAP_DEVPROP_DEVICE_ALIAS = 20,					// [out, char*] C-string (null terminated)
	QCAP_DEVPROP_SERIAL_NUMBER = 27,				// [in, char [17]] 16 chars C-string (null terminated)
	QCAP_DEVPROP_HARDWARE_DEINTERLACE = 200,		// [in, ULONG] 0:enabled, 1:disabled
	QCAP_DEVPROP_720_OUTPUT = 214,					// [in, ULONG] 0:960, 1:720
	QCAP_DEVPROP_CAMERA_TYPE = 226,					// [in, ULONG] 0:TVI, 1:AHD, 2:CVI
	QCAP_DEVPROP_OUTPUT_COLORRANGE = 231,			// [in, ULONG] 0:bypass, 1:expand, 2:shrink
	QCAP_DEVPROP_AUDIO_VOLUME = 251,				// [in/out, ULONG]
	QCAP_DEVPROP_AUDIO_LINE_IN_MODE = 252,			// [in, ULONG] 0:phonejack, 1:pin
	QCAP_DEVPROP_AUDIO_INPUT = 255,					// [in, ULONG] 0:HDMI, 1:Line-in, 2:Mic-in, 3:HDMI+Line-in, 4:HDMI+Mic-in
	QCAP_DEVPROP_AUDIO_CHANNEL = 257,				// [in, ULONG] 0:normal, 8:8ch
	QCAP_DEVPROP_MEDICAL_MODE = 276,				// [in, ULONG] 0:normal, 1:medical
	QCAP_DEVPROP_MUTE_LOOPTHROUGH = 344,			// [in/out, ULONG] 0:unmute, 1:mute
	QCAP_DEVPROP_COLORSPACE = 370,					// [out, ULONG] 2:REC709, 1: SMPTE170M,  3:BT2020
	QCAP_DEVPROP_BITRATE = 403,						// [in, ULONG]
	QCAP_DEVPROP_SURROUND_MODE = 610,				// [in/out, ULONG] 0:normal, 2:two-span-mode, 3:three-span-mode 4:quad-mode
	QCAP_DEVPROP_SDI12G_MODE = 613,					// [in, ULONG] 0:2SI, 1:SQD
	QCAP_DEVPROP_SIGNAL_MODE = 613,					// [in, ULONG] 0:MST, 1:SST
	QCAP_DEVPROP_FIRMWARE_PATH = 800,				// [in, char*]
	QCAP_DEVPROP_FIRMWARE_UPDATE = 801,				// [in, ULONG] 1:start update, 2:recovery mode update FW
	QCAP_DEVPROP_OSD_X = 915,						// [in, LONG]
	QCAP_DEVPROP_OSD_Y = 916,						// [in, LONG]
	QCAP_DEVPROP_OSD_FONT_SIZE = 917,				// [in, LONG]
	QCAP_DEVPROP_OSD_NUMBER = 920,					// [in, LONG]
	QCAP_DEVPROP_OSD_TEXT = 921,					// [in, char*, NULL-terminated]
	QCAP_DEVPROP_OSD_FONT_STYLE = 929,				// [in, LONG]
	QCAP_DEVPROP_BOARD_MEMORY = 958,				// [in/out: BYTE*, <= 16 bytes]
	QCAP_DEVPROP_BOARD_MEMORY_ACCESS = 959,			// [in, LONG]
	QCAP_DEVPROP_VBI_LINES_ENABLE = 236,			// [in, ULONG] 0:disable, 1:enable
	QCAP_DEVPROP_VBI_LINES = 237,					// [in, ULONG] 0~84
	QCAP_DEVPROP_VBI_MIX_MODE = 229,				// [in, ULONG] 0:VANC, 1:HANC
	QCAP_DEVPROP_UPDATE_EDID = 965,					// PCIE capture card ==> [in, ULONG] 0:end, 1:begin
	QCAP_DEVPROP_UVC_EDID_DATA = 965,				// UVC capture card ==> [in/out, char[256]]
	QCAP_DEVPROP_EDID_OFFSET = 966,					// [in, ULONG] byte offset of EDID data
	QCAP_DEVPROP_EDID_DATA = 967,					// [in, ULONG] byte data of EDID data corresponds to offset
	QCAP_DEVPROP_READ_EDID_DATA = 967,				// [in, ULONG] byte data of EDID data corresponds to offset
	QCAP_DEVPROP_EDID_ACCESS = 968,					// [in, ULONG]
	QCAP_DEVPROP_EDID_TYPE = 978,					// [in, ULONG] 1:HDMI, 2:VGA, 3:DVI, 4:DP
	QCAP_DEVPROP_VIDEO_DEVICE_NAME = 1201,			// [in/out, char []] C-string (null terminated)
	QCAP_DEVPROP_AUDIO_DEVICE_NAME = 1202,			// [in/out, char []] C-string (null terminated)
	QCAP_DEVPROP_FLASH_DATA = 1200,					// [in, ULONG] 1:write data to flash rom
	QCAP_DEVPROP_VIDEO_MULTICH_MASK = 269,			// [in, ULONG] bitmask for channel selection
	QCAP_DEVPROP_VIDEO_MULTICH_SUPPORT = 397,		// [in, ULONG] 0:single, 1:multi
	QCAP_DEVPROP_VIDEO_VGA_OFFSET_X = 221,			// [in, LONG]
	QCAP_DEVPROP_VIDEO_VGA_OFFSET_Y = 222,			// [in, LONG]
	QCAP_DEVPROP_ANALOG_PTZ_COMMAND = 810,			// [in, LONG]

	// for linux_base
	QCAP_DEVPROP_TIME_ZONE = 10000,					// [in, LONG]
	QCAP_DEVPROP_NO_SIGNAL_NO_OUTPUT,				// [in, ULONG] 0:no-signal image, 1:freeze
	QCAP_DEVPROP_NO_SIGNAL_YUV_PATTERN,				// [in, ULONG] 0x00YYVVUU
	QCAP_DEVPROP_DOUBLE_FRAME_RATE,					// [in/out, ULONG] boolean value
	QCAP_DEVPROP_IO_METHOD,							// [in/out, ULONG] 0:mmap, 1:userptr
	QCAP_DEVPROP_VO_BACKEND,						// [in/out, ULONG] 0:sdl, 1:gstreamer, 2:davmf, 3:vitis
	QCAP_DEVPROP_PSF,								// [out, ULONG] 0:progressive, 1:PSF
	QCAP_DEVPROP_AUDIO_PERIOD_SIZE,					// [in, ULONG] ALSA period size
	QCAP_DEVPROP_SONY_CAMERA_RESET,					// [in, ULONG] 0: disable, 1:enable
	QCAP_DEVPROP_SWITCH_PCIE_SLOT,					// [in, ULONG] 6T0 0:PCIE(HDMI), 1:M2(SDI)
	QCAP_DEVPROP_DRM_POS_X,							// [in/out: ULONG] boolean value
	QCAP_DEVPROP_DRM_POS_Y,							// [in/out: ULONG] boolean value
	QCAP_DEVPROP_DRM_WIDTH,							// [in/out: ULONG] boolean value
	QCAP_DEVPROP_DRM_HEIGHT,						// [in/out: ULONG] boolean value
	QCAP_DEVPROP_CV0830_DEVINFO,					// in, ULONG[2]: [VIDEO4LINUX, ALSA]
	QCAP_DEVPROP_ANALOG_VIDEO_WIDTH,				// [in, ULONG] 0:960, other:720
	QCAP_DEVPROP_VIDEO_SOURCE_FORMAT,				// [out, ULONG] 0:YUV422, 1:YUV444, 2:RGB
	QCAP_DEVPROP_RESET_570_DEVICE,					// [in, ULONG] 1: reset
	QCAP_DEVPROP_DMA_ERROR,							// [out, ULONG]
	QCAP_DEVPROP_FORCE_WIDTH,						// [in, ULONG]
	QCAP_DEVPROP_FORCE_HEIGHT,						// [in, ULONG]
	QCAP_DEVPROP_FORCE_USERPTR,						// [in, ULONG]
	QCAP_DEVPROP_INTERLACED_FIELD_MODE,				// [in, ULONG]
	QCAP_DEVPROP_SURROUND_TYPE,						// [in, ULONG]  //0:Left-right(default), 1:Top-down
	QCAP_DEVPROP_QUANTIZATION,						// [out, ULONG] 1:FULL, 2:Limited

	// for hisiv_base
	QCAP_DEVPROP_LINEIN_SOURCE = 20000,				// in,out: ULONG
	QCAP_DEVPROP_CLONE_WINDOW,						// in,out: HWND
	QCAP_DEVPROP_ROTATE,							// in,out: ULONG (in degrees, 0~360)
	QCAP_DEVPROP_COMPOSITE_SOURCE,					// in,out: ULONG
	QCAP_DEVPROP_PIPELINE_MODE,						// in,out: ULONG
	QCAP_DEVPROP_LOWDELAY_MODE,						// in,out: ULONG
	QCAP_DEVPROP_BIND_BS,							// in,out: PVOID (broadcast server)
	QCAP_DEVPROP_BIND_BS_0 = QCAP_DEVPROP_BIND_BS,	// in,out: PVOID (broadcast server)
	QCAP_DEVPROP_BIND_BS_1,							// in,out: PVOID (broadcast server)
	QCAP_DEVPROP_BIND_BS_2,							// in,out: PVOID (broadcast server)
	QCAP_DEVPROP_BIND_BS_3,							// in,out: PVOID (broadcast server)
	QCAP_DEVPROP_BIND_SR,							// in,out: UINT (share record number)
	QCAP_DEVPROP_BIND_SR_0 = QCAP_DEVPROP_BIND_SR,	// in,out: UINT (share record number)
	QCAP_DEVPROP_BIND_SR_1,							// in,out: UINT (share record number)
	QCAP_DEVPROP_BIND_SR_2,							// in,out: UINT (share record number)
	QCAP_DEVPROP_BIND_SR_3,							// in,out: UINT (share record number)
	QCAP_DEVPROP_AI_TRACK_MODE,						// in,out: ULONG (0:normal, 1:both_left, 2:both_right)
	QCAP_DEVPROP_CROP_RATIO,						// in: [x:LONG, y:LONG, w:LONG, h:LONG] (0~999)
	QCAP_DEVPROP_BIND_WND_0,						// in,out: HWND
	QCAP_DEVPROP_BIND_WND_1,						// in,out: HWND
	QCAP_DEVPROP_BIND_WND_2,						// in,out: HWND
	QCAP_DEVPROP_BIND_WND_3,						// in,out: HWND
	QCAP_DEVPROP_AUDIO_RENDERER_VOLUME,				// in,out: ULONG
	QCAP_DEVPROP_ISP_PUB,							// in,out: ISP_PUB_ATTR_S
	QCAP_DEVPROP_ISP_STATISTICS_CFG,				// in,out: ISP_STATISTICS_CFG_S
	QCAP_DEVPROP_ISP_VDTIMEOUT,						// out: ULONG[2] { ISP_VD_TYPE_E, HI_U32 }
	QCAP_DEVPROP_ISP_FOCUS_STATISTICS,				// out: ISP_AF_STATISTICS_S
	QCAP_DEVPROP_ISP_EXPOSURE,						// in,out: ISP_EXPOSURE_ATTR_S
	QCAP_DEVPROP_ISP_WB,							// in,out: ISP_WB_ATTR_S
	QCAP_DEVPROP_ISP_LIGHTBOXGAIN,					// out: ISP_AWB_Calibration_Gain_S
	QCAP_DEVPROP_ISP_EXPOSUREINFO,					// out: ISP_EXP_INFO_S
	QCAP_DEVPROP_VPSS_NR_ATTR,						// in: [HI_BOOL, VPSS_NR_ATTR_S]
	QCAP_DEVPROP_ISP_CSC,							// in,out: ISP_CSC_ATTR_S
	QCAP_DEVPROP_ISP_SATURATION,					// in: ISP_SATURATION_ATTR_S
	QCAP_DEVPROP_VI_LDC,							// in,out: VI_LDC_ATTR_S
	QCAP_DEVPROP_ISP_AWB_EX,						// in,out: ISP_AWB_ATTR_EX_S
	QCAP_DEVPROP_ISP_WB_INFO,						// out,ISP_WB_INFO_S
	QCAP_DEVPROP_VPSS_MIRROR_ATTR,					// in:[HI_BOOL]
	QCAP_DEVPROP_VPSS_FLIP_ATTR,					// in:[HI_BOOL]
	QCAP_DEVPROP_VPSS_LDC_ATTR,						// in: [HI_BOOL, LDC_ATTR_S]
	QCAP_DEVPROP_ISP_DRC_ATTR,						// in,out:ISP_DRC_ATTR_S
	QCAP_DEVPROP_ISP_LDCI_ATTR, 					// in,out:ISP_LDCI_ATTR_S
	QCAP_DEVPROP_ISP_DEHAZE_ATTR, 					// in,out:ISP_DEHAZE_ATTR_S
	QCAP_DEVPROP_ISP_GAMMA_ATTR, 					// in,out:ISP_GAMMA_ATTR_S
	QCAP_DEVPROP_ISP_COLORMATRIX_ATTR, 				// in,out:ISP_COLORMATRIX_ATTR_S
	QCAP_DEVPROP_ISP_NR_ATTR, 						// in,out:ISP_NR_ATTR_S
	QCAP_DEVPROP_ISP_SHARPEN_ATTR,					// in,out:ISP_SHARPEN_ATTR_S
	QCAP_DEVPROP_ISP_SHADING_ATTR,					// in,out:ISP_SHADING_ATTR_S
	QCAP_DEVPROP_ISP_SHADING_LUT_ATTR,				// in,out:ISP_SHADING_LUT_ATTR_S
	QCAP_DEVPROP_ISP_DEMOSAIC_ATTR,					// in,out:ISP_DEMOSAIC_ATTR_S
	QCAP_DEVPROP_ISP_DP_DYNAMIC_ATTR,				// in,out:ISP_DP_DYNAMIC_ATTR_S
	QCAP_DEVPROP_VPSS_NRX_PARAM,					// in: [VPSS_GRP_NRX_PARAM_S]
	QCAP_DEVPROP_VPSS_CHN_ATTR_0,					// in,out: VPSS_CHN_ATTR_S
	QCAP_DEVPROP_VPSS_CHN_ATTR_1,					// in,out: VPSS_CHN_ATTR_S
	QCAP_DEVPROP_VPSS_CHN_ATTR_2,					// in,out: VPSS_CHN_ATTR_S
	QCAP_DEVPROP_VPSS_CHN_ATTR_3,					// in,out: VPSS_CHN_ATTR_S
	QCAP_DEVPROP_VPSS_CHN_CROP_0,					// in,out: VPSS_CROP_INFO_S
	QCAP_DEVPROP_VPSS_CHN_CROP_1,					// in,out: VPSS_CROP_INFO_S
	QCAP_DEVPROP_VPSS_CHN_CROP_2,					// in,out: VPSS_CROP_INFO_S
	QCAP_DEVPROP_VPSS_CHN_CROP_3,					// in,out: VPSS_CROP_INFO_S

	// for both use
	QCAP_DEVPROP_IDEAL_PTS = 30000,					// [in/out, ULONG] boolean value
	QCAP_DEVPROP_SRCDET_ONLY,						// [in/out, ULONG] boolean value
	QCAP_DEVPROP_ERROR_MODE,						// [out, ULONG] current error mode
	QCAP_DEVPROP_GENLOCK_SOURCE,					// [in, ULONG] //0:free run, 1:GS12170, 2:Ext_Vsync

	// for private use
	QCAP_DEVPROP_VIDEO_FRAME_OFFSET = 40000,		// [in, ULONG] buffer index offset
};

// share record custom property
enum {
	// QCAP_SHARE_RECORD_PROPERTY_SOURCE_FRAME_RATE = 100, // in: double, DEPRECATED!

	QCAP_SRPROP_SOURCE_FRAME_RATE = 100,	// in: double
	QCAP_SRPROP_ROTATE,						// in,out: ULONG (in degrees, 0~360)
	QCAP_SRPROP_VO_BACKEND,					// [in/out, ULONG] 0:sdl, 1:gstreamer, 2:davmf, 3:vitis
	QCAP_SRPROP_VENC_OSD,					// [in/out, ULONG] boolean value
	QCAP_SRPROP_ENABLE_FF,					// [in/out, ULONG] boolean value
	QCAP_SRPROP_VENC_LOW_DELAY,				// [in/out, ULONG] boolean value
	QCAP_SRPROP_VENC_RTMP_COMPAT,			// [in/out, ULONG] boolean value
	QCAP_SRPROP_VDEC_LOW_LATENCY,		 	// [in/out: ULONG] boolean value
	QCAP_SRPROP_VDEC_REWIND,			 	// [in/out: ULONG] boolean value
	QCAP_SRPROP_VENC_TIME_SCALE_FACTOR,		// [in/out, ULONG] time scale factor
	QCAP_SRPROP_DRM_POS_X,					// [in/out: ULONG] boolean value
	QCAP_SRPROP_DRM_POS_Y,					// [in/out: ULONG] boolean value
	QCAP_SRPROP_DRM_WIDTH,					// [in/out: ULONG] boolean value
	QCAP_SRPROP_DRM_HEIGHT,					// [in/out: ULONG] boolean value
	QCAP_SRPROP_FB_RESET,					// [in/out: ULONG] boolean value
	QCAP_SRPROP_VENC_HIGH_PERF,				// [in/out, ULONG] boolean value
	QCAP_SRPROP_FMP4_LOW_LATENCY,			// [in/out, ULONG] boolean value

	// private use only
	QCAP_SRPROP_BINDING_VPSS = 10800,		// in: [ULONG, ULONG]
	QCAP_SRPROP_BINDING_AVS,				// in: [ULONG, ULONG]
};

// broadcast server custom property
enum {
	// QCAP_PROPERTY_NDI_CONFIG				= 100, // in,out: char*, DEPRECATED!

	QCAP_BSPROP_NDI_CONFIG = 100,			// in,out: char*
	QCAP_BSPROP_SENDING_IP,					// in,out: char*
	QCAP_BSPROP_SOURCE_FRAME_RATE,			// in: double
	QCAP_BSPROP_RECEIVING_IP,				// in,out: char*
	QCAP_BSPROP_MULTICAST_IP,				// in,out: char*
	QCAP_BSPROP_FRAME_RATE,					// in: [double, double]
	QCAP_BSPROP_NDI_TALLY_GET,				// out: QCAP_BPROP_NDI_TALLY_VALUE
	QCAP_BSPROP_NDI_TALLY_SET,				// in: QCAP_BPROP_NDI_TALLY_VALUE
	QCAP_BSPROP_NDI_TALLY_TIMEOUT,			// in/out: ULONG
	QCAP_BSPROP_ENABLE_FF,					// [in/out, ULONG] boolean value
	QCAP_BSPROP_ENABLE_LOW_DELAY,			// [in/out, ULONG] boolean value
	QCAP_BSPROP_ENABLE_RTMP_COMPAT,			// [in/out, ULONG] boolean value
	QCAP_BSPROP_ERROR_MODE,					// [out, LONG] error mode
	QCAP_BSPROP_TIME_SCALE_FACTOR,			// [in/out, ULONG] time scale factor
	QCAP_BSPROP_ENABLE_HIGH_PERF,			// [in/out, ULONG] boolean value
	QCAP_BSPROP_BACKCHANNEL,				// [in/out, QCAP_BPROP_BACKCHANNEL_VALUE]
	QCAP_BSPROP_SDP,						// out: char*
	QCAP_BSPROP_HLS_ID3,					// [in, ULONG] boolean value

	// private use only
	QCAP_BSPROP_BINDING_VPSS = 10800,		// in: [ULONG, ULONG]
	QCAP_BSPROP_BINDING_AVS,				// in: [ULONG, ULONG]
};

// broadcast client custom property
enum {
	QCAP_BCPROP_SENDING_IP = 100,				// in,out: char*
	QCAP_BCPROP_PIPELINE_MODE,					// in,out: ULONG
	QCAP_BCPROP_VIDEO_DECODE,					// in,out: BOOL
	QCAP_BCPROP_AUDIO_DECODE,					// in,out: BOOL
	QCAP_BCPROP_NDI_PTZ_IS_SUPPORTED,			// out: BOOL
	QCAP_BCPROP_NDI_PTZ_ZOOM,			 		// in: float 0.0 (zoomed in) ... 1.0 (zoomed out)
	QCAP_BCPROP_NDI_PTZ_ZOOM_SPEED,			 	// in: float -1.0 (zoom outwards) ... +1.0 (zoom inwards)
	QCAP_BCPROP_NDI_PTZ_PAN_TILT,			 	// in: [float -1.0 (left) ... 0.0 (centered) ... +1.0 (right), float -1.0 (bottom) ... 0.0 (centered) ... +1.0 (top)]
	QCAP_BCPROP_NDI_PTZ_PAN_TILT_SPEED,			// in: [float -1.0 (moving right) ... 0.0 (stopped) ... +1.0 (moving left), float -1.0 (down) ... 0.0 (stopped) ... +1.0 (moving up)]
	QCAP_BCPROP_NDI_PTZ_STORE_PRESET,			// in: int 0 ... 99
	QCAP_BCPROP_NDI_PTZ_RECALL_PRESET,			// in: [int 0 ... 99, float 0.0(as slow as possible) ... 1.0(as fast as possible) The speed at which to move to the new preset]
	QCAP_BCPROP_NDI_PTZ_AUTO_FOCUS,				// in: NULL
	QCAP_BCPROP_NDI_PTZ_FOCUS,					// in: float 0.0 (focused to infinity) ... 1.0 (focused as close as possible)
	QCAP_BCPROP_NDI_PTZ_FOCUS_SPEED,			// in: float -1.0 (focus outwards) ... +1.0 (focus inwards)
	QCAP_BCPROP_NDI_PTZ_WHITE_BALANCE_AUTO,		// in: NULL
	QCAP_BCPROP_NDI_PTZ_WHITE_BALANCE_INDOOR,	// in: NULL
	QCAP_BCPROP_NDI_PTZ_WHITE_BALANCE_OUTDOOR,	// in: NULL
	QCAP_BCPROP_NDI_PTZ_WHITE_BALANCE_ONESHOT,	// in: NULL
	QCAP_BCPROP_NDI_PTZ_WHITE_BALANCE_MANUAL,	// in: [float 0.0(not red) ... 1.0(very red), float 0.0(not blue) ... 1.0(very blue)]
	QCAP_BCPROP_NDI_PTZ_EXPOSURE_AUTO,			// in: NULL
	QCAP_BCPROP_NDI_PTZ_EXPOSURE_MANUAL,		// in: float 0.0(dark) ... 1.0(light)
	QCAP_BCPROP_NDI_KVM_IS_SUPPORTED,			// out: BOOL
	QCAP_BCPROP_NDI_KVM_SEND_LEFT_MOUSE,		// in: BOOL 0 (release), 1 (click)
	QCAP_BCPROP_NDI_KVM_SEND_MIDDLE_MOUSE,		// in: BOOL 0 (release), 1 (click)
	QCAP_BCPROP_NDI_KVM_SEND_RIGHT_MOUSE,		// in: BOOL 0 (release), 1 (click)
	QCAP_BCPROP_NDI_KVM_SEND_WHEEL_MOUSE,		// in: int 0 (vertical), 1 (horizontal)
	QCAP_BCPROP_NDI_KVM_SEND_MOUSE_POSITION,	// in: [float 0.0 (left of the screen) ... 1.0(right of the screen), float 0.0(top of the screen) ... 1.0(botton of the screen)]
	QCAP_BCPROP_NDI_KVM_SEND_KEYBOARD,			// in: BOOL 0 (release), 1 (click)   in: int (key_sym_value)
	QCAP_BCPROP_NDI_TALLY_SET,					// in: QCAP_BPROP_NDI_TALLY_VALUE
	QCAP_BCPROP_VIDEO_DECODE_FORMAT,			// out: ULONG
	QCAP_BCPROP_VIDEO_COLORSPACE_TYPE,			// out: ULONG
	QCAP_BCPROP_AUDIO_DECODE_FORMAT,			// out: ULONG
	QCAP_BCPROP_ENABLE_LOW_LATENCY,			 	// [in/out: ULONG] boolean value
	QCAP_BCPROP_ENABLE_REWIND,				 	// [in/out: ULONG] boolean value
	QCAP_BCPROP_DRM_POS_X,						// [in/out: ULONG] boolean value
	QCAP_BCPROP_DRM_POS_Y,						// [in/out: ULONG] boolean value
	QCAP_BCPROP_DRM_WIDTH,						// [in/out: ULONG] boolean value
	QCAP_BCPROP_DRM_HEIGHT,						// [in/out: ULONG] boolean value
	QCAP_BCPROP_VO_BACKEND,						// [in/out, ULONG] 0:sdl, 1:gstreamer, 2:davmf, 3:vitis
	QCAP_BCPROP_VC_IPCAM,						// in,out: BOOL
};

// file custom property
enum {
	// QCAP_FILEPROP_PIPELINE_MODE				= 804, // in,out: ULONG, DEPRECATED!
	QCAP_FILEPROP_DRM_POS_X = 100,				// [in/out: ULONG] boolean value
	QCAP_FILEPROP_DRM_POS_Y,					// [in/out: ULONG] boolean value
	QCAP_FILEPROP_DRM_WIDTH,					// [in/out: ULONG] boolean value
	QCAP_FILEPROP_DRM_HEIGHT,					// [in/out: ULONG] boolean value
};

// pat-gen custom property
enum {
	QCAP_PATGENPROP_VERSION = 0,				// [out, ULONG]
};


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif // __QCAP_EXT_PROPS_H__
