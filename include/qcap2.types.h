#ifndef __QCAP2_TYPES_H__
#define __QCAP2_TYPES_H__

#include "qcap.common.core.h"

#include <stdint.h>
#include <stddef.h>

#define qcap2_container_of(ptr, type, member) ({ \
	void* __mptr = (void*)(ptr); \
	((type *)((char *)__mptr - offsetof(type, member))); \
})

struct qcap2_av_frame_t;
struct qcap2_av_packet_t;
struct qcap2_input_format_t;
struct qcap2_video_format_t;
struct qcap2_audio_format_t;
struct qcap2_video_encoder_property_t;
struct qcap2_audio_encoder_property_t;
struct qcap2_video_encoder_dynamic_property_t;
struct qcap2_media_info_t;
struct qcap2_program_info_t;
struct qcap2_benaphore_lock_t;

struct qcap2_video_scaler_t;
struct qcap2_audio_resampler_t;
struct qcap2_video_encoder_t;
struct qcap2_video_decoder_t;
struct qcap2_audio_encoder_t;
struct qcap2_audio_decoder_t;
struct qcap2_frame_pool_t;
struct qcap2_packet_pool_t;
struct qcap2_event_t;
struct qcap2_event_handlers_t;
struct qcap2_rcbuffer_t;
struct qcap2_rcbuffer_queue_t;
struct qcap2_timer_t;
struct qcap2_window_t;
struct qcap2_block_lock_t;
struct qcap2_binder_t;

struct qcap2_qdev_enum_t;
struct qcap2_qdev_info_t;
struct qcap2_qdev_t;
struct qcap2_video_source_t;
struct qcap2_video_sink_t;
struct qcap2_audio_source_t;
struct qcap2_audio_sink_t;
struct qcap2_demuxer_t;
struct qcap2_muxer_t;
struct qcap2_video_matte_t;
struct qcap2_video_blender_t;
struct qcap2_bitstream_filter_t;
struct qcap2_dns_source_t;
struct qcap2_clock_source_t;

// graphics
struct qcap2_font_atlas_t;
struct qcap2_graphics_t;

struct qcap2_build_config_t {
	int major, minor, patch;
	int qcap_major, qcap_minor, qcap_patch;
	const char* build_date;
	const char* build_time;
	const char* branch;
	const char* commit;
	const char* mods;
};

struct qcap2_av_frame_t {
	uint8_t padding[512];
};

struct qcap2_av_packet_t {
	uint8_t padding[128];
};

struct qcap2_dns_event_t {
	int error;
	uint8_t sockaddr[32];
	char name[256];
};

struct qcap2_clock_event_t {
	int error;
	int64_t diff;
};

struct qcap2_rational_t {
	int num;
	int den;
};

// enum values
enum qcap2_test_pattern_type_t {
	QCAP2_TEST_PATTERN_0,
	QCAP2_TEST_PATTERN_1,

	QCAP2_TEST_PATTERN_RED = 256, // Y: [16,235], CbCr: [16,240]
	QCAP2_TEST_PATTERN_GREEN,
	QCAP2_TEST_PATTERN_BLUE,
	QCAP2_TEST_PATTERN_WHITE,
	QCAP2_TEST_PATTERN_BLACK,
};

enum qcap2_frame_pool_backend_type_t {
	QCAP2_FRAME_POOL_BACKEND_TYPE_UNKNOWN,

	QCAP2_FRAME_POOL_BACKEND_TYPE_DEFAULT,
	QCAP2_FRAME_POOL_BACKEND_TYPE_RKMPP,
	QCAP2_FRAME_POOL_BACKEND_TYPE_QDMABUF,
};

enum qcap2_video_scaler_backend_type_t {
	QCAP2_VIDEO_SCALER_BACKEND_TYPE_UNKNOWN,

	QCAP2_VIDEO_SCALER_BACKEND_TYPE_DEFAULT,
	QCAP2_VIDEO_SCALER_BACKEND_TYPE_NPP,
	QCAP2_VIDEO_SCALER_BACKEND_TYPE_LBL_COPY,
	QCAP2_VIDEO_SCALER_BACKEND_TYPE_NVT_HDAL,
	QCAP2_VIDEO_SCALER_BACKEND_TYPE_FF_FILTER_GRAPH,

	QCAP2_VIDEO_SCALER_BACKEND_TYPE_EXPERIMENTAL = 9999,
};

enum qcap2_qdev_type_t {
	QCAP2_QDEV_TYPE_UNKNOWN,

	QCAP2_QDEV_TYPE_UB3300,
	QCAP2_QDEV_TYPE_MZ0380,
	QCAP2_QDEV_TYPE_SC440N2_GMSL,
	QCAP2_QDEV_TYPE_CV0830,
};

enum qcap2_window_backend_type_t {
	QCAP2_WINDOW_BACKEND_TYPE_UNKNOWN,

	QCAP2_WINDOW_BACKEND_TYPE_NULL,
	QCAP2_WINDOW_BACKEND_TYPE_FAKE,
	QCAP2_WINDOW_BACKEND_TYPE_X11,
};

enum qcap2_video_source_backend_type_t {
	QCAP2_VIDEO_SOURCE_BACKEND_TYPE_UNKNOWN,

	QCAP2_VIDEO_SOURCE_BACKEND_TYPE_USER,
	QCAP2_VIDEO_SOURCE_BACKEND_TYPE_V4L2,
	QCAP2_VIDEO_SOURCE_BACKEND_TYPE_PYLON,
	QCAP2_VIDEO_SOURCE_BACKEND_TYPE_VITIS,
	QCAP2_VIDEO_SOURCE_BACKEND_TYPE_XLNX,
	QCAP2_VIDEO_SOURCE_BACKEND_TYPE_V4L2_SG,
	QCAP2_VIDEO_SOURCE_BACKEND_TYPE_LBLWR,
	QCAP2_VIDEO_SOURCE_BACKEND_TYPE_NVT_HDAL,
	QCAP2_VIDEO_SOURCE_BACKEND_TYPE_HSB,
	QCAP2_VIDEO_SOURCE_BACKEND_TYPE_TPG,
	QCAP2_VIDEO_SOURCE_BACKEND_TYPE_LT6911,
	QCAP2_VIDEO_SOURCE_BACKEND_TYPE_IMX585,
	QCAP2_VIDEO_SOURCE_BACKEND_TYPE_COE,
};

enum qcap2_video_sink_backend_type_t {
	QCAP2_VIDEO_SINK_BACKEND_TYPE_UNKNOWN,

	QCAP2_VIDEO_SINK_BACKEND_TYPE_DAVMF,
	QCAP2_VIDEO_SINK_BACKEND_TYPE_GSTREAMER,
	QCAP2_VIDEO_SINK_BACKEND_TYPE_VITIS,
	QCAP2_VIDEO_SINK_BACKEND_TYPE_V4L2CAP,
	QCAP2_VIDEO_SINK_BACKEND_TYPE_XLNX,
	QCAP2_VIDEO_SINK_BACKEND_TYPE_L4T,
	QCAP2_VIDEO_SINK_BACKEND_TYPE_LBLRD,
	QCAP2_VIDEO_SINK_BACKEND_TYPE_NVT_HDAL,

	QCAP2_VIDEO_SINK_BACKEND_TYPE_EXPERIMENTAL = 9999,
};

enum qcap2_audio_source_backend_type_t {
	QCAP2_AUDIO_SOURCE_BACKEND_TYPE_UNKNOWN,

	QCAP2_AUDIO_SOURCE_BACKEND_TYPE_ALSA,
	QCAP2_AUDIO_SOURCE_BACKEND_TYPE_VITIS,
	QCAP2_AUDIO_SOURCE_BACKEND_TYPE_V4L2,
	QCAP2_AUDIO_SOURCE_BACKEND_TYPE_NVT_HDAL,
	QCAP2_AUDIO_SOURCE_BACKEND_TYPE_TPG,
};

enum qcap2_audio_sink_backend_type_t {
	QCAP2_AUDIO_SINK_BACKEND_TYPE_UNKNOWN,

	QCAP2_AUDIO_SINK_BACKEND_TYPE_ALSA,
	QCAP2_AUDIO_SINK_BACKEND_TYPE_VITIS,
	QCAP2_AUDIO_SINK_BACKEND_TYPE_V4L2CAP,
	QCAP2_AUDIO_SINK_BACKEND_TYPE_NVT_HDAL,
};

enum qcap2_demuxer_type_t {
	QCAP2_DEMUXER_TYPE_UNKNOWN,

	QCAP2_DEMUXER_TYPE_DEFAULT,
	QCAP2_DEMUXER_TYPE_PYLON,
	QCAP2_DEMUXER_TYPE_USBCAM,
	QCAP2_DEMUXER_TYPE_FIFO,
	QCAP2_DEMUXER_TYPE_RTP,
	QCAP2_DEMUXER_TYPE_JSRTSP,
	QCAP2_DEMUXER_TYPE_VITIS,
	QCAP2_DEMUXER_TYPE_YUANCAP,
	QCAP2_DEMUXER_TYPE_NVT_HDAL,
	QCAP2_DEMUXER_TYPE_SC6F0,

	QCAP2_DEMUXER_TYPE_EXPERIMENTAL = 9999,
};

enum qcap2_muxer_type_t {
	QCAP2_MUXER_TYPE_UNKNOWN,

	QCAP2_MUXER_TYPE_DEFAULT,
	QCAP2_MUXER_TYPE_JSRTSP,
	QCAP2_MUXER_TYPE_RTSP,

	QCAP2_MUXER_TYPE_EXPERIMENTAL = 9999,
};

enum qcap2_video_matte_backend_type_t {
	QCAP2_VIDEO_MATTE_BACKEND_TYPE_UNKNOWN,

	QCAP2_VIDEO_MATTE_BACKEND_TYPE_OPMATTING,
};

enum qcap2_video_blender_backend_type_t {
	QCAP2_VIDEO_BLENDER_BACKEND_TYPE_UNKNOWN,

	QCAP2_VIDEO_BLENDER_BACKEND_TYPE_CUDA,
};

enum qcap2_color_space_t {
	QCAP2_COLOR_SPACE_UNKNOWN,

	QCAP2_COLOR_SPACE_JPEG, // YCbCr: [0,255]
	QCAP2_COLOR_SPACE_BT601, // Y: [16,235], CbCr: [16,240]
	QCAP2_COLOR_SPACE_BT709, // Y: [16,235], CbCr: [16,240]
	QCAP2_COLOR_SPACE_BT601_FULL, // YCbCr: [0,255]
	QCAP2_COLOR_SPACE_BT709_FULL, // YCbCr: [0,255]
	QCAP2_COLOR_SPACE_BT2020, // Y: [16,235], CbCr: [16,240]
	QCAP2_COLOR_SPACE_BT2020_FULL, // YCbCr: [0,255]
};

enum qcap2_color_range_t {
	QCAP2_COLOR_RANGE_UNKNOWN,

	QCAP2_COLOR_RANGE_LIMITED, // [16,235]
	QCAP2_COLOR_RANGE_FULL, // [0,255]
};

enum qcap2_stereoscopic_type_t {
	QCAP2_STEREOSCOPIC_TYPE_UNKNOWN,

	QCAP2_STEREOSCOPIC_TYPE_LINE_BY_LINE,
	QCAP2_STEREOSCOPIC_TYPE_TOP_BOTTOM,
	QCAP2_STEREOSCOPIC_TYPE_LEFT_RIGHT,
};

enum qcap2_bitstream_filter_backend_type_t {
	QCAP2_BITSTREAM_FILTER_BACKEND_TYPE_UNKNOWN,

	QCAP2_BITSTREAM_FILTER_BACKEND_TYPE_NOOP,
	QCAP2_BITSTREAM_FILTER_BACKEND_TYPE_DATA_APPEND,
	QCAP2_BITSTREAM_FILTER_BACKEND_TYPE_DATA_EXTRACT,
	QCAP2_BITSTREAM_FILTER_BACKEND_TYPE_DATA_REMOVE,
};

enum qcap2_field_type_t {
	QCAP2_FIELD_NONE,
	QCAP2_FIELD_TOP, // odd
	QCAP2_FIELD_BOTTOM, // even
	QCAP2_FIELD_INTERLACED,
};

enum qcap2_buffer_hint_t {
	QCAP2_BUFFER_HINT_DEFAULT,

	QCAP2_BUFFER_HINT_CUDA,
	QCAP2_BUFFER_HINT_CUDAHOST,
	QCAP2_BUFFER_HINT_CUDA_MANAGED,

	QCAP2_BUFFER_HINT_CUDA_HOST = QCAP2_BUFFER_HINT_CUDAHOST,
};

enum qcap2_graphics_backend_type_t {
	QCAP2_GRAPHICS_BACKEND_TYPE_UNKNOWN,

	QCAP2_GRAPHICS_BACKEND_TYPE_DEFAULT,

	QCAP2_GRAPHICS_BACKEND_TYPE_EXPERIMENTAL = 9999,
};

// callbacks
typedef void (*qcap2_on_free_resource_t)(PVOID pData);
typedef QRETURN (*qcap2_on_event_t)(PVOID pUserData);

#endif // __QCAP2_TYPES_H__
