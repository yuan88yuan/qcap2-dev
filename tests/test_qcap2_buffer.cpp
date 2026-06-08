#include "qcap2.buffer.h"
#include "qcap2.user.h"
#include "qcap2.dmabuf.h"
#include <stdio.h>
#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

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

void test_qcap2_av_frame_copy() {
    // Test 1: Null Arguments
    qcap2_av_frame_t frame;
    qcap2_av_frame_init(&frame);
    assert(qcap2_av_frame_copy(NULL, NULL) == QCAP_RS_ERROR_GENERAL);
    assert(qcap2_av_frame_copy(&frame, NULL) == QCAP_RS_ERROR_GENERAL);
    assert(qcap2_av_frame_copy(NULL, &frame) == QCAP_RS_ERROR_GENERAL);

    // Test 2: Basic Properties Copy
    qcap2_av_frame_t src;
    qcap2_av_frame_init(&src);
    qcap2_av_frame_set_video_property(&src, QCAP_COLORSPACE_TYPE_NV12, 1920, 1080);
    qcap2_av_frame_set_pts(&src, 54321);

    qcap2_av_frame_t dst;
    qcap2_av_frame_init(&dst);
    assert(qcap2_av_frame_copy(&src, &dst) == QCAP_RS_SUCCESSFUL);

    ULONG color, width, height;
    qcap2_av_frame_get_video_property(&dst, &color, &width, &height);
    assert(color == QCAP_COLORSPACE_TYPE_NV12);
    assert(width == 1920);
    assert(height == 1080);

    int64_t pts;
    qcap2_av_frame_get_pts(&dst, &pts);
    assert(pts == 54321);

    // Test 3: Deep Copy of Buffer
    qcap2_av_frame_t src_buf;
    qcap2_av_frame_init(&src_buf);
    qcap2_av_frame_set_video_property(&src_buf, QCAP_COLORSPACE_TYPE_NV12, 16, 16);
    assert(qcap2_av_frame_alloc_buffer(&src_buf, 16, 1));

    uint8_t* pSrcBuf;
    int srcStride;
    qcap2_av_frame_get_buffer(&src_buf, &pSrcBuf, &srcStride);
    assert(pSrcBuf != NULL);
    assert(srcStride > 0);

    // Fill with known pattern
    size_t size = srcStride * 16;
    memset(pSrcBuf, 0xAB, size);

    qcap2_av_frame_t dst_buf;
    qcap2_av_frame_init(&dst_buf);
    assert(qcap2_av_frame_copy(&src_buf, &dst_buf) == QCAP_RS_SUCCESSFUL);

    uint8_t* pDstBuf;
    int dstStride;
    qcap2_av_frame_get_buffer(&dst_buf, &pDstBuf, &dstStride);
    assert(pDstBuf != NULL);
    assert(dstStride == srcStride);
    assert(pDstBuf != pSrcBuf); // Verify deep copy
    assert(memcmp(pSrcBuf, pDstBuf, size) == 0); // Verify data identity

    qcap2_av_frame_free_buffer(&src_buf);
    qcap2_av_frame_free_buffer(&dst_buf);
}

void test_qcap2_av_frame_alloc_buffer_layout() {
    qcap2_av_frame_t frame;
    qcap2_av_frame_init(&frame);

    qcap2_av_frame_set_video_property(&frame, QCAP_COLORSPACE_TYPE_NV12, 13, 7);
    assert(qcap2_av_frame_alloc_buffer(&frame, 16, 4));

    uint8_t* buffer[4];
    int stride[4];
    qcap2_av_frame_get_buffer1(&frame, buffer, stride);
    assert(buffer[0] != NULL);
    assert(buffer[1] != NULL);
    assert(buffer[2] == NULL);
    assert(stride[0] == 16);
    assert(stride[1] == 16);
    assert(buffer[1] == buffer[0] + 16 * 8);
    qcap2_av_frame_free_buffer(&frame);

    qcap2_av_frame_set_video_property(&frame, QCAP_COLORSPACE_TYPE_YV12, 13, 7);
    assert(qcap2_av_frame_alloc_buffer(&frame, 16, 4));
    qcap2_av_frame_get_buffer1(&frame, buffer, stride);
    assert(buffer[0] != NULL);
    assert(buffer[1] != NULL);
    assert(buffer[2] != NULL);
    assert(stride[0] == 16);
    assert(stride[1] == 16);
    assert(stride[2] == 16);
    assert(buffer[1] == buffer[0] + 16 * 8);
    assert(buffer[2] == buffer[1] + 16 * 4);
    qcap2_av_frame_free_buffer(&frame);

    qcap2_av_frame_set_video_property(&frame, QCAP_COLORSPACE_TYPE_H264, 1920, 1080);
    assert(!qcap2_av_frame_alloc_buffer(&frame, 16, 4));
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

struct TestMyVideoFrame {
    int index;
    int free_resource_count;
    void* buffers[4];
    qcap2_av_frame_t av_frame;

    TestMyVideoFrame() : index(0), free_resource_count(0) {
        qcap2_av_frame_init(&av_frame);
        memset(buffers, 0, sizeof(buffers));
    }

    ~TestMyVideoFrame() {
        for (int i = 0; i < 4; ++i) {
            free(buffers[i]);
        }
    }
};

static TestMyVideoFrame* test_new_video_frame_with_buffers() {
    TestMyVideoFrame* video_frame = new TestMyVideoFrame();
    assert(posix_memalign(&video_frame->buffers[0], 16, 16 * 4) == 0);
    assert(posix_memalign(&video_frame->buffers[1], 16, 16 * 2) == 0);

    uint8_t* buffer[4] = { (uint8_t*)video_frame->buffers[0], (uint8_t*)video_frame->buffers[1], NULL, NULL };
    int stride[4] = { 16, 16, 0, 0 };
    qcap2_av_frame_set_buffer1(&video_frame->av_frame, buffer, stride);
    return video_frame;
}

void test_qcap2_rcbuffer() {
    TestMyVideoFrame* video_frame = test_new_video_frame_with_buffers();
    qcap2_rcbuffer_t* rcbuf = qcap2_rcbuffer_new_from_av_frame(
        &video_frame->av_frame,
        video_frame,
        [](void* owner, void* user_data) {
            (void)owner;
            TestMyVideoFrame* pThis = (TestMyVideoFrame*)user_data;
            pThis->free_resource_count++;
        }
    );
    assert(rcbuf != NULL);
    qcap2_rcbuffer_info_t info = { sizeof(info) };
    assert(qcap2_rcbuffer_query(rcbuf, &info) == QCAP_RS_SUCCESSFUL);
    assert(info.owner != NULL);
    assert(qcap2_rcbuffer_use_count(rcbuf) == 1);
    assert(qcap2_rcbuffer_res_count(rcbuf) == 1);

    qcap2_rcbuffer_add_ref(rcbuf);
    assert(qcap2_rcbuffer_use_count(rcbuf) == 2);

    qcap2_rcbuffer_release(rcbuf);
    assert(qcap2_rcbuffer_use_count(rcbuf) == 1);
    assert(video_frame->free_resource_count == 0);

    qcap2_rcbuffer_release(rcbuf);
    assert(video_frame->free_resource_count == 1);
    delete video_frame;
}

void test_qcap2_rcbuffer_lock_pins_resource() {
    TestMyVideoFrame* video_frame = test_new_video_frame_with_buffers();
    qcap2_rcbuffer_t* rcbuf = qcap2_rcbuffer_new_from_av_frame(
        &video_frame->av_frame,
        video_frame,
        [](void* owner, void* user_data) {
            (void)owner;
            TestMyVideoFrame* pThis = (TestMyVideoFrame*)user_data;
            pThis->free_resource_count++;
        }
    );
    assert(rcbuf != NULL);

    qcap2_rcbuffer_access_t access = { sizeof(access) };
    QRESULT r = qcap2_rcbuffer_begin_access(rcbuf, QCAP2_RCBUFFER_ACCESS_READ | QCAP2_RCBUFFER_ACCESS_CPU, &access);
    assert(r == QCAP_RS_SUCCESSFUL);
    assert(qcap2_rcbuffer_res_count(rcbuf) == 2);

    qcap2_rcbuffer_release(rcbuf);
    assert(video_frame->free_resource_count == 0);
    assert(qcap2_rcbuffer_use_count(rcbuf) == 0);
    assert(qcap2_rcbuffer_res_count(rcbuf) == 1);

    qcap2_rcbuffer_end_access(rcbuf, &access);
    assert(video_frame->free_resource_count == 1);
    delete video_frame;
}

void test_qcap2_rcbuffer_embedded_av_frame_free_callback() {
    TestMyVideoFrame* video_frame = test_new_video_frame_with_buffers();
    video_frame->index = 7;

    qcap2_rcbuffer_t* rcbuf = qcap2_rcbuffer_new_from_av_frame(
        &video_frame->av_frame,
        video_frame,
        [](void* owner, void* user_data) {
            (void)owner;
            TestMyVideoFrame* pThis = (TestMyVideoFrame*)user_data;
            pThis->free_resource_count++;
        }
    );
    assert(rcbuf != NULL);

    qcap2_rcbuffer_delete(rcbuf);
    assert(video_frame->free_resource_count == 1);
    delete video_frame;
}

void test_qcap2_av_frame_dmabuf() {
    qcap2_av_frame_t frame;
    qcap2_av_frame_init(&frame);

    QRESULT res = qcap2_av_frame_alloc_dmabuf(&frame, 1024, PROT_READ | PROT_WRITE);
    assert(res == QCAP_RS_SUCCESSFUL);

    qcap2_dmabuf_t* dmabuf = NULL;
    res = qcap2_av_frame_get_dmabuf(&frame, &dmabuf);
    assert(res == QCAP_RS_SUCCESSFUL);
    assert(dmabuf != NULL);
    assert(dmabuf->fd >= 0);
    assert(dmabuf->dmabuf_size == 1024);
    assert(dmabuf->nSize == 1024);
    assert(dmabuf->pVirAddr == NULL);

    res = qcap2_av_frame_map_dmabuf(&frame, PROT_READ | PROT_WRITE);
    assert(res == QCAP_RS_SUCCESSFUL);
    assert(dmabuf->pVirAddr != NULL);

    uint8_t* ptr = (uint8_t*)dmabuf->pVirAddr;
    ptr[0] = 0xAA;
    ptr[1023] = 0x55;
    assert(ptr[0] == 0xAA);
    assert(ptr[1023] == 0x55);

    res = qcap2_av_frame_unmap_dmabuf(&frame);
    assert(res == QCAP_RS_SUCCESSFUL);
    assert(dmabuf->pVirAddr == NULL);

    res = qcap2_av_frame_free_dmabuf(&frame);
    assert(res == QCAP_RS_SUCCESSFUL);

    res = qcap2_av_frame_alloc_mapped_dmabuf(&frame, 512, PROT_READ | PROT_WRITE);
    assert(res == QCAP_RS_SUCCESSFUL);
    res = qcap2_av_frame_get_dmabuf(&frame, &dmabuf);
    assert(res == QCAP_RS_SUCCESSFUL);
    assert(dmabuf != NULL);
    assert(dmabuf->pVirAddr != NULL);
    assert(dmabuf->dmabuf_size == 512);

    qcap2_av_frame_free_buffer(&frame);

    qcap2_av_frame_t frame2;
    qcap2_av_frame_init(&frame2);
    qcap2_dmabuf_t external_dmabuf;
    memset(&external_dmabuf, 0, sizeof(external_dmabuf));
    external_dmabuf.fd = 9999;
    external_dmabuf.dmabuf_size = 256;

    res = qcap2_av_frame_set_dmabuf(&frame2, &external_dmabuf);
    assert(res == QCAP_RS_SUCCESSFUL);

    qcap2_dmabuf_t* retrieved = NULL;
    res = qcap2_av_frame_get_dmabuf(&frame2, &retrieved);
    assert(res == QCAP_RS_SUCCESSFUL);
    assert(retrieved == &external_dmabuf);
    assert(retrieved->fd == 9999);

    qcap2_av_frame_free_buffer(&frame2);
}

struct MockV4L2Slot {
    int index;
    int dma_fd;
    bool bIsQueued;
    qcap2_av_frame_t frame;
    qcap2_rcbuffer_t* rcbuf;
    int requeue_count;

    MockV4L2Slot() : index(0), dma_fd(-1), bIsQueued(false), rcbuf(nullptr), requeue_count(0) {
        qcap2_av_frame_init(&frame);
    }
};

static void mock_requeue_slot(MockV4L2Slot* slot);

void mock_requeue_slot(MockV4L2Slot* slot) {
    if (!slot->bIsQueued) {
        slot->bIsQueued = true;
        slot->requeue_count++;
    }
    slot->rcbuf = qcap2_rcbuffer_new_from_av_frame(
        &slot->frame,
        slot,
        [](void* owner, void* user_data) {
            (void)owner;
            MockV4L2Slot* pSlot = (MockV4L2Slot*)user_data;
            mock_requeue_slot(pSlot);
        }
    );
}

void test_v4l2_reference_counting_and_pinning() {
    MockV4L2Slot slot;
    slot.index = 0;
    slot.dma_fd = 100;
    slot.bIsQueued = true;

    slot.rcbuf = qcap2_rcbuffer_new_from_av_frame(
        &slot.frame,
        &slot,
        [](void* owner, void* user_data) {
            (void)owner;
            MockV4L2Slot* pSlot = (MockV4L2Slot*)user_data;
            mock_requeue_slot(pSlot);
        }
    );
    assert(slot.rcbuf != nullptr);
    assert(qcap2_rcbuffer_use_count(slot.rcbuf) == 1);
    assert(qcap2_rcbuffer_res_count(slot.rcbuf) == 1);

    slot.bIsQueued = false; 

    qcap2_rcbuffer_release(slot.rcbuf);

    assert(slot.bIsQueued == true);
    assert(slot.requeue_count == 1);
    assert(slot.rcbuf != nullptr);
    assert(qcap2_rcbuffer_use_count(slot.rcbuf) == 1); 

    slot.bIsQueued = false;
    qcap2_rcbuffer_t* active_rcbuf = slot.rcbuf;

    qcap2_rcbuffer_access_t access = { sizeof(access) };
    QRESULT r = qcap2_rcbuffer_begin_access(active_rcbuf, QCAP2_RCBUFFER_ACCESS_READ | QCAP2_RCBUFFER_ACCESS_CPU, &access);
    assert(r == QCAP_RS_SUCCESSFUL);
    assert(qcap2_rcbuffer_use_count(active_rcbuf) == 1);
    assert(qcap2_rcbuffer_res_count(active_rcbuf) == 2);

    qcap2_rcbuffer_release(active_rcbuf);

    assert(slot.bIsQueued == false);
    assert(slot.requeue_count == 1);
    assert(qcap2_rcbuffer_use_count(active_rcbuf) == 0);
    assert(qcap2_rcbuffer_res_count(active_rcbuf) == 1);

    qcap2_rcbuffer_end_access(active_rcbuf, &access);

    assert(slot.bIsQueued == true);
    assert(slot.requeue_count == 2);
    assert(slot.rcbuf != active_rcbuf);
    assert(qcap2_rcbuffer_use_count(slot.rcbuf) == 1);

    qcap2_rcbuffer_release(slot.rcbuf);
}

struct CustomBufferOwner {
    int destroy_called;
    int begin_access_called;
    int end_access_called;
    CustomBufferOwner() : destroy_called(0), begin_access_called(0), end_access_called(0) {}
};

static void custom_destroy(void* owner, void* user_data) {
    (void)user_data;
    CustomBufferOwner* o = (CustomBufferOwner*)owner;
    o->destroy_called++;
}

static QRESULT custom_begin_access(void* owner, void* user_data, uint32_t flags, qcap2_rcbuffer_access_t* access) {
    (void)user_data;
    CustomBufferOwner* o = (CustomBufferOwner*)owner;
    o->begin_access_called++;
    access->granted_flags = flags;
    return QCAP_RS_SUCCESSFUL;
}

static void custom_end_access(void* owner, void* user_data, qcap2_rcbuffer_access_t* access) {
    (void)user_data;
    (void)access;
    CustomBufferOwner* o = (CustomBufferOwner*)owner;
    o->end_access_called++;
}

static QRESULT custom_query(void* owner, void* user_data, qcap2_rcbuffer_info_t* info) {
    (void)user_data;
    info->content_type = QCAP2_RCBUFFER_CONTENT_CUSTOM;
    info->memory_flags = QCAP2_RCBUFFER_MEMORY_CUSTOM;
    info->capability_flags = QCAP2_RCBUFFER_CAP_ZERO_COPY;
    info->owner = owner;
    return QCAP_RS_SUCCESSFUL;
}

static const qcap2_rcbuffer_ops_t custom_ops = {
    sizeof(qcap2_rcbuffer_ops_t),
    custom_begin_access,
    custom_end_access,
    custom_query,
    NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL
};

void test_new_rcbuffer_api_custom() {
    CustomBufferOwner owner;
    
    qcap2_rcbuffer_create_info_t create_info = {};
    create_info.cb = sizeof(create_info);
    create_info.owner = &owner;
    create_info.destroy = custom_destroy;
    create_info.ops = &custom_ops;
    create_info.content_type = QCAP2_RCBUFFER_CONTENT_CUSTOM;
    create_info.memory_flags = QCAP2_RCBUFFER_MEMORY_CUSTOM;
    create_info.capability_flags = QCAP2_RCBUFFER_CAP_ZERO_COPY;

    qcap2_rcbuffer_t* buf = qcap2_rcbuffer_new(&create_info);
    assert(buf != NULL);

    qcap2_rcbuffer_info_t info = { sizeof(info) };
    QRESULT r = qcap2_rcbuffer_query(buf, &info);
    assert(r == QCAP_RS_SUCCESSFUL);
    assert(info.content_type == QCAP2_RCBUFFER_CONTENT_CUSTOM);
    assert(info.memory_flags == QCAP2_RCBUFFER_MEMORY_CUSTOM);
    assert(info.capability_flags == QCAP2_RCBUFFER_CAP_ZERO_COPY);
    assert(info.owner == &owner);

    qcap2_rcbuffer_access_t access = { sizeof(access) };
    r = qcap2_rcbuffer_begin_access(buf, QCAP2_RCBUFFER_ACCESS_READ, &access);
    assert(r == QCAP_RS_SUCCESSFUL);
    assert(owner.begin_access_called == 1);
    assert(access.granted_flags == QCAP2_RCBUFFER_ACCESS_READ);
    assert(qcap2_rcbuffer_res_count(buf) == 2);

    qcap2_rcbuffer_end_access(buf, &access);
    assert(owner.end_access_called == 1);
    assert(qcap2_rcbuffer_res_count(buf) == 1);

    qcap2_rcbuffer_release(buf);
    assert(owner.destroy_called == 1);
}

void test_new_rcbuffer_api_system_video_frame() {
    qcap2_video_frame_create_info_t create_info = {};
    create_info.cb = sizeof(create_info);
    create_info.color_space_type = QCAP_COLORSPACE_TYPE_NV12;
    create_info.width = 1920;
    create_info.height = 1080;
    create_info.align = 16;
    create_info.valign = 1;

    qcap2_rcbuffer_t* buf = qcap2_rcbuffer_new_system_video_frame(&create_info);
    assert(buf != NULL);

    qcap2_rcbuffer_info_t info = { sizeof(info) };
    QRESULT r = qcap2_rcbuffer_query(buf, &info);
    assert(r == QCAP_RS_SUCCESSFUL);
    assert(info.content_type == QCAP2_RCBUFFER_CONTENT_VIDEO_FRAME);
    assert(info.memory_flags == QCAP2_RCBUFFER_MEMORY_SYSTEM);
    assert(info.capability_flags & QCAP2_RCBUFFER_CAP_VIDEO_PLANES);

    qcap2_rcbuffer_video_info_t vinfo = { sizeof(vinfo) };
    r = qcap2_rcbuffer_get_video_info(buf, &vinfo);
    assert(r == QCAP_RS_SUCCESSFUL);
    assert(vinfo.color_space_type == QCAP_COLORSPACE_TYPE_NV12);
    assert(vinfo.width == 1920);
    assert(vinfo.height == 1080);
    assert(vinfo.plane_count == 2);

    // Test access
    qcap2_rcbuffer_access_t access = { sizeof(access) };
    r = qcap2_rcbuffer_begin_access(buf, QCAP2_RCBUFFER_ACCESS_READ | QCAP2_RCBUFFER_ACCESS_CPU, &access);
    assert(r == QCAP_RS_SUCCESSFUL);

    qcap2_rcbuffer_plane_t plane0 = { sizeof(plane0) };
    r = qcap2_rcbuffer_get_plane(buf, 0, &plane0);
    assert(r == QCAP_RS_SUCCESSFUL);
    assert(plane0.data != NULL);
    assert(plane0.stride >= 1920);

    qcap2_rcbuffer_plane_t plane1 = { sizeof(plane1) };
    r = qcap2_rcbuffer_get_plane(buf, 1, &plane1);
    assert(r == QCAP_RS_SUCCESSFUL);
    assert(plane1.data != NULL);

    qcap2_rcbuffer_end_access(buf, &access);
    qcap2_rcbuffer_release(buf);
}

void test_new_rcbuffer_api_system_packet() {
    qcap2_rcbuffer_t* buf = qcap2_rcbuffer_new_system_packet(512);
    assert(buf != NULL);

    qcap2_rcbuffer_info_t info = { sizeof(info) };
    QRESULT r = qcap2_rcbuffer_query(buf, &info);
    assert(r == QCAP_RS_SUCCESSFUL);
    assert(info.content_type == QCAP2_RCBUFFER_CONTENT_PACKET);

    qcap2_rcbuffer_packet_info_t pinfo = { sizeof(pinfo) };
    r = qcap2_rcbuffer_get_packet_info(buf, &pinfo);
    assert(r == QCAP_RS_SUCCESSFUL);
    assert(pinfo.data != NULL);
    assert(pinfo.size == 512);

    pinfo.pts = 9999;
    pinfo.is_keyframe = TRUE;
    r = qcap2_rcbuffer_set_packet_info(buf, &pinfo);
    assert(r == QCAP_RS_SUCCESSFUL);

    qcap2_rcbuffer_packet_info_t pinfo2 = { sizeof(pinfo2) };
    r = qcap2_rcbuffer_get_packet_info(buf, &pinfo2);
    assert(r == QCAP_RS_SUCCESSFUL);
    assert(pinfo2.pts == 9999);
    assert(pinfo2.is_keyframe == TRUE);

    qcap2_rcbuffer_release(buf);
}

void test_new_rcbuffer_api_dmabuf_video_frame() {
    qcap2_dmabuf_frame_create_info_t create_info = {};
    create_info.cb = sizeof(create_info);
    create_info.color_space_type = QCAP_COLORSPACE_TYPE_NV12;
    create_info.width = 320;
    create_info.height = 240;
    create_info.align = 1;
    create_info.valign = 1;
    create_info.prot = PROT_READ | PROT_WRITE;

    qcap2_rcbuffer_t* buf = qcap2_rcbuffer_new_dmabuf_video_frame(&create_info);
    assert(buf != NULL);

    qcap2_rcbuffer_info_t info = { sizeof(info) };
    QRESULT r = qcap2_rcbuffer_query(buf, &info);
    assert(r == QCAP_RS_SUCCESSFUL);
    assert(info.content_type == QCAP2_RCBUFFER_CONTENT_VIDEO_FRAME);
    assert(info.memory_flags == QCAP2_RCBUFFER_MEMORY_DMABUF);

    qcap2_rcbuffer_handle_t handle = { sizeof(handle) };
    r = qcap2_rcbuffer_get_handle(buf, QCAP2_RCBUFFER_HANDLE_DMABUF_FD, &handle);
    assert(r == QCAP_RS_SUCCESSFUL);
    assert(handle.type == QCAP2_RCBUFFER_HANDLE_DMABUF_FD);
    assert(handle.u.fd >= 0);

    qcap2_rcbuffer_access_t access = { sizeof(access) };
    r = qcap2_rcbuffer_begin_access(buf, QCAP2_RCBUFFER_ACCESS_READ | QCAP2_RCBUFFER_ACCESS_CPU, &access);
    assert(r == QCAP_RS_SUCCESSFUL);

    qcap2_rcbuffer_plane_t plane0 = { sizeof(plane0) };
    r = qcap2_rcbuffer_get_plane(buf, 0, &plane0);
    assert(r == QCAP_RS_SUCCESSFUL);
    assert(plane0.data != NULL);

    qcap2_rcbuffer_end_access(buf, &access);
    qcap2_rcbuffer_release(buf);
}

void test_new_rcbuffer_api_cuda_video_frame() {
    qcap2_cuda_frame_create_info_t create_info = {};
    create_info.cb = sizeof(create_info);
    create_info.color_space_type = QCAP_COLORSPACE_TYPE_NV12;
    create_info.width = 640;
    create_info.height = 480;

    qcap2_rcbuffer_t* buf = qcap2_rcbuffer_new_cuda_video_frame(&create_info);
    assert(buf != NULL);

    qcap2_rcbuffer_info_t info = { sizeof(info) };
    QRESULT r = qcap2_rcbuffer_query(buf, &info);
    assert(r == QCAP_RS_SUCCESSFUL);
    assert(info.content_type == QCAP2_RCBUFFER_CONTENT_VIDEO_FRAME);
    assert(info.memory_flags == QCAP2_RCBUFFER_MEMORY_CUDA_DEVICE);

    qcap2_rcbuffer_handle_t handle = { sizeof(handle) };
    r = qcap2_rcbuffer_get_handle(buf, QCAP2_RCBUFFER_HANDLE_CUDA_DEVICE_PTR, &handle);
    assert(r == QCAP_RS_SUCCESSFUL);
    assert(handle.type == QCAP2_RCBUFFER_HANDLE_CUDA_DEVICE_PTR);
    assert(handle.u.value == 0xDEADE000);

    qcap2_rcbuffer_access_t cpu_access = { sizeof(cpu_access) };
    r = qcap2_rcbuffer_begin_access(buf, QCAP2_RCBUFFER_ACCESS_READ | QCAP2_RCBUFFER_ACCESS_CPU, &cpu_access);
    assert(r == QCAP_RS_ERROR_NON_SUPPORT);

    qcap2_rcbuffer_access_t device_access = { sizeof(device_access) };
    r = qcap2_rcbuffer_begin_access(buf, QCAP2_RCBUFFER_ACCESS_READ | QCAP2_RCBUFFER_ACCESS_DEVICE | QCAP2_RCBUFFER_ACCESS_ZERO_COPY, &device_access);
    assert(r == QCAP_RS_SUCCESSFUL);
    assert(device_access.granted_flags & QCAP2_RCBUFFER_ACCESS_DEVICE);
    qcap2_rcbuffer_end_access(buf, &device_access);

    qcap2_rcbuffer_release(buf);
}

int main() {
    test_qcap2_av_frame();
    test_qcap2_av_frame_copy();
    test_qcap2_av_frame_alloc_buffer_layout();
    test_qcap2_av_packet();
    test_qcap2_rcbuffer();
    test_qcap2_rcbuffer_lock_pins_resource();
    test_qcap2_rcbuffer_embedded_av_frame_free_callback();
    test_qcap2_av_frame_dmabuf();
    test_v4l2_reference_counting_and_pinning();
    
    // New API tests
    test_new_rcbuffer_api_custom();
    test_new_rcbuffer_api_system_video_frame();
    test_new_rcbuffer_api_system_packet();
    test_new_rcbuffer_api_dmabuf_video_frame();
    test_new_rcbuffer_api_cuda_video_frame();

    printf("All tests passed!\n");
    return 0;
}
