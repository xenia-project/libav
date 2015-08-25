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
 * @param invalid_frame_ptr Set to 1 if the frame header == 0x7FFF
 * @param packet_header Does the packer have a valid header?
 * @param bit_offset is from the beginning of the block
 *
 * Sometimes the frame may span multiple packets. If it does, this function will
 * automatically detect and load data from the next packet over. This assumes
 * we're supplied with the input necessary to do this. If you don't have it,
 * wait until you do to call the decoder!
 *
 * @returns num bits read, 0 if end of block, or negative for error.
 */
int xma2_decode_frame(AVCodecContext* avctx, AVPacket* packet, AVFrame* frame,
                      int* got_frame_ptr, int* invalid_frame_ptr,
                      int* frame_size, int packet_header, size_t bit_offset);

/**
 * @brief Fixes up a frame offset, if any fixup needed.
 */
size_t xma2_correct_frame_offset(uint8_t* block, size_t len,
                                 size_t frame_bit_offset);

#endif  /* AVCODEC_XMA2DEC_H */