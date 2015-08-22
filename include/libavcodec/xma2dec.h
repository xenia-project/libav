// TODO: License!

#ifndef AVCODEC_XMA2DEC_H
#define AVCODEC_XMA2DEC_H

#include "libavcodec/avcodec.h"

/**
 * @brief Decode a single frame.
 * @param avctx av context
 * @param packet needs to point to the first packet in the block.
 * @param frame is the output frame
 * @param got_frame_ptr
 * @param bit_offset is from the beginning of the block
 * 
 * Sometimes the frame may span multiple packets. If it does, this function will
 * automatically detect and load data from the next packet over.
 *
 * @returns num bits read
 */
int xma2_decode_frame(AVCodecContext* avctx, AVPacket* packet, AVFrame* frame, int* got_frame_ptr, int* block_last_frame_ptr, size_t bit_offset);

#endif // AVCODEC_XMA2DEC_H