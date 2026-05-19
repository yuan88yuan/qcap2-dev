#include "qcap2.buffer.h"
#include <stdio.h>
#include <assert.h>

void test_qcap2_av_frame() {
    qcap2_av_frame_t frame;
    qcap2_av_frame_init(&frame);

    qcap2_av_frame_set_video_property(&frame, 1, 1920, 1080);
    ULONG color, width, height;
    qcap2_av_frame_get_video_property(&frame, &color, &width, &height);
    assert(color == 1);
    assert(width == 1920);
    assert(height == 1080);

    qcap2_av_frame_set_pts(&frame, 12345);
    int64_t pts;
    qcap2_av_frame_get_pts(&frame, &pts);
    assert(pts == 12345);

    qcap2_av_frame_set_buffer(&frame, (uint8_t*)0x1234, 1920*2);
    uint8_t* pBuf;
    int stride;
    qcap2_av_frame_get_buffer(&frame, &pBuf, &stride);
    assert(pBuf == (uint8_t*)0x1234);
    assert(stride == 1920*2);

    bool alloc_res = qcap2_av_frame_alloc_buffer(&frame, 1, 1);
    assert(alloc_res);
    qcap2_av_frame_get_buffer(&frame, &pBuf, &stride);
    assert(pBuf != NULL);
    qcap2_av_frame_free_buffer(&frame);
}

void test_qcap2_av_packet() {
    qcap2_av_packet_t packet;
    qcap2_av_packet_init(&packet);

    qcap2_av_packet_set_property(&packet, 2, TRUE);
    int streamIndex;
    BOOL isKeyFrame;
    qcap2_av_packet_get_property(&packet, &streamIndex, &isKeyFrame);
    assert(streamIndex == 2);
    assert(isKeyFrame == TRUE);

    bool alloc_res = qcap2_av_packet_alloc_buffer(&packet, 1024);
    assert(alloc_res);
    uint8_t* pBuf;
    int size;
    qcap2_av_packet_get_buffer(&packet, &pBuf, &size);
    assert(pBuf != NULL);
    assert(size == 1024);
    qcap2_av_packet_free_buffer(&packet);
}

void test_qcap2_rcbuffer() {
    int data = 42;
    qcap2_rcbuffer_t* rcbuf = qcap2_rcbuffer_new(&data, NULL);
    assert(rcbuf != NULL);
    assert(qcap2_rcbuffer_use_count(rcbuf) == 1);

    qcap2_rcbuffer_add_ref(rcbuf);
    assert(qcap2_rcbuffer_use_count(rcbuf) == 2);

    qcap2_rcbuffer_release(rcbuf);
    assert(qcap2_rcbuffer_use_count(rcbuf) == 1);

    qcap2_rcbuffer_release(rcbuf);
}

int main() {
    test_qcap2_av_frame();
    test_qcap2_av_packet();
    test_qcap2_rcbuffer();
    printf("All tests passed!\n");
    return 0;
}
