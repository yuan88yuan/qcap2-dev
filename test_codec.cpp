#include <libavcodec/avcodec.h>
#include <iostream>
int main() {
    std::cout << AV_CODEC_ID_HEVC << std::endl;
    std::cout << AV_CODEC_ID_H264 << std::endl;
    std::cout << AV_CODEC_ID_MPEG2VIDEO << std::endl;
    std::cout << AV_CODEC_ID_AV1 << std::endl;
    return 0;
}
