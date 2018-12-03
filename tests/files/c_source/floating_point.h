/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2018 Erik Moqvist
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * This file was generated by cantools version 30.0.0 Mon Dec  3 08:37:13 2018.
 */

#ifndef FLOATING_POINT_H
#define FLOATING_POINT_H

#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>

#ifndef EINVAL
#    define EINVAL -22
#endif

#define FLOATING_POINT_MESSAGE1_FRAME_ID (0x400u)
#define FLOATING_POINT_MESSAGE2_FRAME_ID (0x401u)



/**
 * Signals in message Message1.
 *
 * @param signal1 Value as on the CAN bus.
 *            Range: -
 *            Scale: 1
 *            Offset: 0
 */
struct floating_point_message1_t {
    double signal1;
};

/**
 * Signals in message Message2.
 *
 * @param signal1 Value as on the CAN bus.
 *            Range: -
 *            Scale: 1
 *            Offset: 0
 * @param signal2 Value as on the CAN bus.
 *            Range: -
 *            Scale: 1
 *            Offset: 0
 */
struct floating_point_message2_t {
    float signal1;
    float signal2;
};

/**
 * Encode message Message1.
 *
 * @param[out] dst_p Buffer to encode the message into.
 * @param[in] src_p Data to encode.
 * @param[in] size Size of dst_p.
 *
 * @return Size of encoded data, or negative error code.
 */
ssize_t floating_point_message1_encode(
    uint8_t *dst_p,
    const struct floating_point_message1_t *src_p,
    size_t size);

/**
 * Decode message Message1.
 *
 * @param[out] dst_p Object to decode the message into.
 * @param[in] src_p Message to decode.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int floating_point_message1_decode(
    struct floating_point_message1_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool floating_point_message1_signal1_is_in_range(double value);

/**
 * Encode message Message2.
 *
 * @param[out] dst_p Buffer to encode the message into.
 * @param[in] src_p Data to encode.
 * @param[in] size Size of dst_p.
 *
 * @return Size of encoded data, or negative error code.
 */
ssize_t floating_point_message2_encode(
    uint8_t *dst_p,
    const struct floating_point_message2_t *src_p,
    size_t size);

/**
 * Decode message Message2.
 *
 * @param[out] dst_p Object to decode the message into.
 * @param[in] src_p Message to decode.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int floating_point_message2_decode(
    struct floating_point_message2_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool floating_point_message2_signal1_is_in_range(float value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool floating_point_message2_signal2_is_in_range(float value);

#endif
