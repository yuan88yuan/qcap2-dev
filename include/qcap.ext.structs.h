#ifndef __QCAP_COMMON_STRUCTS_H__
#define __QCAP_COMMON_STRUCTS_H__

#include "qcap.types.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#pragma pack(push)
#pragma pack(1)

typedef struct QCAP_PROPERTY_HDMI_VO_PARAM_VALUE QCAP_PROPERTY_HDMI_VO_PARAM_VALUE;
struct QCAP_PROPERTY_HDMI_VO_PARAM_VALUE
{
	int width;
	int height;
	int fps;
};

typedef struct QCAP_PROPERTY_COLOR_RANGE_VALUE QCAP_PROPERTY_COLOR_RANGE_VALUE;
struct QCAP_PROPERTY_COLOR_RANGE_VALUE
{
	ULONG color_range; // QCAP_COLORRANGE_TYPE_xxx
};

typedef struct QCAP_PROPERTY_COLOR_RANGE_RESPONSE QCAP_PROPERTY_COLOR_RANGE_RESPONSE;
struct QCAP_PROPERTY_COLOR_RANGE_RESPONSE
{
	ULONG color_range; // QCAP_COLORRANGE_TYPE_xxx
};

typedef struct QCAP_PROPERTY_VO_PARAM_VALUE QCAP_PROPERTY_VO_PARAM_VALUE;
struct QCAP_PROPERTY_VO_PARAM_VALUE
{
	int id;
	int width;
	int height;
	int fps;
	int flags; // Bit0: progressive / interlaced, Bit1: 1000 / 1001
};

typedef struct QCAP_PROPERTY_VO_PARAM_RESPONSE QCAP_PROPERTY_VO_PARAM_RESPONSE;
struct QCAP_PROPERTY_VO_PARAM_RESPONSE
{
	int id; // in

	// output fields
	int width;
	int height;
	int fps;
	int flags; // Bit0: progressive / interlaced, Bit1: 1000 / 1001
};

typedef struct QCAP_PROPERTY_VO_CSC_PARAM_VALUE QCAP_PROPERTY_VO_CSC_PARAM_VALUE;
struct QCAP_PROPERTY_VO_CSC_PARAM_VALUE
{
	int id;
	uint32_t luma;
	uint32_t contrast;
	uint32_t hue;
	uint32_t saturation;
};

typedef struct QCAP_PROPERTY_MCU_VERSION_RESPONSE QCAP_PROPERTY_MCU_VERSION_RESPONSE;
struct QCAP_PROPERTY_MCU_VERSION_RESPONSE
{
	BYTE ver[4];
};

typedef struct QCAP_PROPERTY_COPY_PROTECT_KEY_VALUE QCAP_PROPERTY_COPY_PROTECT_KEY_VALUE;
struct QCAP_PROPERTY_COPY_PROTECT_KEY_VALUE
{
	uint32_t key;
};

typedef struct QCAP_PROPERTY_COPY_PROTECT_CHECK_RESPONSE QCAP_PROPERTY_COPY_PROTECT_CHECK_RESPONSE;
struct QCAP_PROPERTY_COPY_PROTECT_CHECK_RESPONSE
{
	int result;
};

typedef struct QCAP_PROPERTY_GPIO_OUTPUT_VALUE QCAP_PROPERTY_GPIO_OUTPUT_VALUE;
struct QCAP_PROPERTY_GPIO_OUTPUT_VALUE
{
	uint32_t port; // 0x90 = PORT A, 0x91 = PORT B, 0x92 = PORT C
	uint32_t pin; // 0x00 ~ 0x1F, pin number
	uint32_t value; // 0X00 = LOW, 0X01 = QCAP_RECORD_PROFILE_HIGH
};

typedef struct QCAP_PROPERTY_LED_VALUE QCAP_PROPERTY_LED_VALUE;
struct QCAP_PROPERTY_LED_VALUE
{
	int index;

	unsigned char period;
	unsigned char level;
	unsigned char start;
	unsigned char end;
};

typedef struct QCAP_PROPERTY_LED_EX_VALUE QCAP_PROPERTY_LED_EX_VALUE;
struct QCAP_PROPERTY_LED_EX_VALUE
{
	int index;

	int argc;
	unsigned char args[16];

	int async_mode;
};

typedef struct QCAP_PROPERTY_BUTTON_RESPONSE QCAP_PROPERTY_BUTTON_RESPONSE;
struct QCAP_PROPERTY_BUTTON_RESPONSE
{
	int size;

	uint32_t state[8];
};

typedef struct QCAP_PROPERTY_VOLUME_VALUE QCAP_PROPERTY_VOLUME_VALUE;
struct QCAP_PROPERTY_VOLUME_VALUE
{
	int index;
	int volume;

	int async_mode;
};

typedef struct QCAP_PROPERTY_VOLUME_RESPONSE QCAP_PROPERTY_VOLUME_RESPONSE;
struct QCAP_PROPERTY_VOLUME_RESPONSE
{
	int index; // in
	int volume[8]; // out
};

typedef struct QCAP_PROPERTY_NDI_MODE_RESPONSE QCAP_PROPERTY_NDI_MODE_RESPONSE;
struct QCAP_PROPERTY_NDI_MODE_RESPONSE
{
	int mode; // 0: no key; 1: yuan key; 2: custom key
};

typedef struct QCAP_PROPERTY_NOISE_GATE_VALUE QCAP_PROPERTY_NOISE_GATE_VALUE;
struct QCAP_PROPERTY_NOISE_GATE_VALUE
{
	// 0: LineIn1; 1: LineIn2; 2: LineIn3; 3: LineIn4; 4: LineOut1
	int index;

	// 0: Off
	// 1: -34; 2: -37; 3: -40; 4: -43; 5: -46; 6: -52; 7: -58dB
	// 8: -64; 9: -67; 10: -70; 11: -73; 12: -76; 13: -82dB
	int value;

	// 0: 50; 1: 100; 2: 150; 3: 200ms
	int delay;
};

typedef struct QCAP_PROPERTY_NDI_KEY_VALUE QCAP_PROPERTY_NDI_KEY_VALUE;
struct QCAP_PROPERTY_NDI_KEY_VALUE
{
	char* pszNDIKey;
};

typedef struct QCAP_PROPERTY_BUTTON_EX_RESPONSE QCAP_PROPERTY_BUTTON_EX_RESPONSE;
struct QCAP_PROPERTY_BUTTON_EX_RESPONSE
{
	uint32_t state[4]; // 128 button state
};

typedef struct QCAP_PROPERTY_TSENSOR_DETECT_RESPONSE QCAP_PROPERTY_TSENSOR_DETECT_RESPONSE;
struct QCAP_PROPERTY_TSENSOR_DETECT_RESPONSE
{
	double value;
};

typedef struct QCAP_PROPERTY_MENU_VALUE QCAP_PROPERTY_MENU_VALUE;
struct QCAP_PROPERTY_MENU_VALUE
{
	int index;
	int channel;
	int size;
	unsigned char data[64];
};

typedef struct QCAP_PROPERTY_BUTTON_EVENT_RESPONSE QCAP_PROPERTY_BUTTON_EVENT_RESPONSE;
struct QCAP_PROPERTY_BUTTON_EVENT_RESPONSE
{
	int scancode;
	int flags;
};

typedef struct QCAP_BCPROP_NDI_KVM_SEND_KEYBOARD_VALUE QCAP_BCPROP_NDI_KVM_SEND_KEYBOARD_VALUE;
struct QCAP_BCPROP_NDI_KVM_SEND_KEYBOARD_VALUE
{
	int type; // 0: release, 1: press
	int key;
};

typedef struct QCAP_BPROP_NDI_TALLY_VALUE QCAP_BPROP_NDI_TALLY_VALUE;
struct QCAP_BPROP_NDI_TALLY_VALUE
{
	BOOL on_program; // Is this currently on program output.
	BOOL on_preview; // Is this currently on preview output.
};

typedef struct QCAP_BPROP_BACKCHANNEL_VALUE QCAP_BPROP_BACKCHANNEL_VALUE;
struct QCAP_BPROP_BACKCHANNEL_VALUE
{
	ULONG nChannels;
	ULONG nBitsPerSample;
	ULONG nSampleFrequency;

	PF_BACKCHANNEL_BROADCAST_SERVER_PLAY_CALLBACK fnPlay;
	PF_BACKCHANNEL_BROADCAST_SERVER_STOP_CALLBACK fnStop;
	PF_BACKCHANNEL_BROADCAST_SERVER_AUDIO_DECODED_CALLBACK fnAudioDecoded;
	PVOID pUserData;
};

typedef struct QCAP_PTZ_COMMAND QCAP_PTZ_COMMAND;
struct QCAP_PTZ_COMMAND
{
    BYTE OnOff;
    BYTE Header;
    BYTE Address;
    BYTE Command;
    BYTE Data1;
    BYTE Data2;
    BYTE Data3;
    BYTE Data4;
};

#pragma pack(pop)

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif // __QCAP_COMMON_STRUCTS_H__
