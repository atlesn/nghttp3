/*
 * nghttp3
 *
 * Copyright (c) 2019 nghttp3 contributors
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#include "nghttp3_err.h"

const char *nghttp3_strerror(int liberr) {
  switch (liberr) {
  case NGHTTP3_ERR_INVALID_ARGUMENT:
    return "ERR_INVALID_ARGUMENT";
  case NGHTTP3_ERR_NOBUF:
    return "ERR_NOBUF";
  case NGHTTP3_ERR_INVALID_STATE:
    return "ERR_INVALID_STATE";
  case NGHTTP3_ERR_WOULDBLOCKED:
    return "ERR_WOULDBLOCK";
  case NGHTTP3_ERR_QPACK_FATAL:
    return "ERR_QPACK_FATAL";
  case NGHTTP3_ERR_QPACK_DECOMPRESSION_FAILED:
    return "ERR_QPACK_DECOMPRESSION_FAILED";
  case NGHTTP3_ERR_QPACK_ENCODER_STREAM_ERROR:
    return "ERR_QPACK_ENCODER_STREAM_ERROR";
  case NGHTTP3_ERR_QPACK_DECODER_STREAM_ERROR:
    return "ERR_QPACK_DECODER_STREAM_ERROR";
  case NGHTTP3_ERR_QPACK_HEADER_TOO_LARGE:
    return "ERR_QPACK_HEADER_TOO_LARGE";
  case NGHTTP3_ERR_HTTP_WRONG_STREAM_COUNT:
    return "ERR_HTTP_WRONG_STREAM_COUNT";
  case NGHTTP3_ERR_HTTP_UNKNOWN_STREAM_TYPE:
    return "ERR_HTTP_UNKNOWN_STREAM_TYPE";
  case NGHTTP3_ERR_HTTP_UNEXPECTED_FRAME:
    return "ERR_HTTP_UNEXPECTED_FRAME";
  case NGHTTP3_ERR_HTTP_MALFORMED_FRAME - NGHTTP3_FRAME_DATA:
    return "ERR_HTTP_MALFORMED_FRAME_DATA";
  case NGHTTP3_ERR_HTTP_MALFORMED_FRAME - NGHTTP3_FRAME_HEADERS:
    return "ERR_HTTP_MALFORMED_FRAME_HEADERS";
  case NGHTTP3_ERR_HTTP_MALFORMED_FRAME - NGHTTP3_FRAME_PRIORITY:
    return "ERR_HTTP_MALFORMED_FRAME_PRIORITY";
  case NGHTTP3_ERR_HTTP_MALFORMED_FRAME - NGHTTP3_FRAME_CANCEL_PUSH:
    return "ERR_HTTP_MALFORMED_FRAME_CANCEL_PUSH";
  case NGHTTP3_ERR_HTTP_MALFORMED_FRAME - NGHTTP3_FRAME_SETTINGS:
    return "ERR_HTTP_MALFORMED_FRAME_SETTINGS";
  case NGHTTP3_ERR_HTTP_MALFORMED_FRAME - NGHTTP3_FRAME_PUSH_PROMISE:
    return "ERR_HTTP_MALFORMED_FRAME_PUSH_PROMISE";
  case NGHTTP3_ERR_HTTP_MALFORMED_FRAME - NGHTTP3_FRAME_GOAWAY:
    return "ERR_HTTP_MALFORMED_FRAME_GOAWAY";
  case NGHTTP3_ERR_HTTP_MALFORMED_FRAME - NGHTTP3_FRAME_MAX_PUSH_ID:
    return "ERR_HTTP_MALFORMED_FRAME_MAX_PUSH_ID";
  case NGHTTP3_ERR_HTTP_MALFORMED_FRAME - NGHTTP3_FRAME_DUPLICATE_PUSH:
    return "ERR_HTTP_MALFORMED_FRAME_DUPLICATE_PUSH";
  case NGHTTP3_ERR_HTTP_MISSING_SETTINGS:
    return "ERR_HTTP_MISSING_SETTINGS";
  case NGHTTP3_ERR_HTTP_WRONG_STREAM:
    return "ERR_HTTP_WRONG_STREAM";
  case NGHTTP3_ERR_HTTP_INTERNAL_ERROR:
    return "ERR_HTTP_INTERNAL_ERROR";
  case NGHTTP3_ERR_HTTP_CLOSED_CRITICAL_STREAM:
    return "ERR_CLOSED_CRITICAL_STREAM";
  case NGHTTP3_ERR_HTTP_GENERAL_PROTOCOL_ERROR:
    return "ERR_HTTP_GENERAL_PROTOCOL_ERROR";
  case NGHTTP3_ERR_HTTP_LIMIT_EXCEEDED:
    return "ERR_HTTP_LIMIT_EXCEEDED";
  case NGHTTP3_ERR_NOMEM:
    return "ERR_NOMEM";
  case NGHTTP3_ERR_CALLBACK_FAILURE:
    return "ERR_CALLBACK_FAILURE";
  default:
    return "(unknown)";
  }
}

int nghttp3_err_malformed_frame(int64_t type) {
  if (type > 0xfe) {
    return NGHTTP3_ERR_HTTP_MALFORMED_FRAME - 0xff;
  }
  return NGHTTP3_ERR_HTTP_MALFORMED_FRAME - (int)type;
}
