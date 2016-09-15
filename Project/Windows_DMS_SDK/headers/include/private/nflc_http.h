/*
 * nflc_http.h
 * Copyright (C) 2007-2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2005 IP Infusion, Inc. All Rights Reserved.  */

#ifndef NFLC_HTTP_H
#define NFLC_HTTP_H

#include <http_parser.h>
/* HTTP/1.1 implementation.  */

#define HTTP_DEFAULT_TIMEOUT (30 + MINIMUM_DELAY)

/* HTTP build format.  */
#define HTTP_FORMAT_STRING                's'
#define HTTP_FORMAT_CHUNKED_HEADER        'K'
#define HTTP_FORMAT_STRING_BUFFER         'b'
#define HTTP_FORMAT_CRLF                  'c'
#define HTTP_FORMAT_INTEGER               'd'
#define HTTP_FORMAT_UNSIGNED              'u'
#define HTTP_FORMAT_TIME                  't'
#define HTTP_FORMAT_DATE                  'D'
#define HTTP_FORMAT_CONNECTION            'C'
#define HTTP_FORMAT_CONNECTION_CLOSE      'X'
#define HTTP_FORMAT_CONTENT_LENGTH        'N'
#define HTTP_FORMAT_SERVER                'S'
#define HTTP_FORMAT_USER_AGENT            'U'
#define HTTP_FORMAT_RESPONSE_LINE         'R'
#define HTTP_FORMAT_BODY                  'B'
#define HTTP_FORMAT_REQUEST_LINE          'Q'
#define HTTP_FORMAT_REQUEST_AND_HOST      'q'
#define HTTP_FORMAT_CONTENT_TYPE          'T'
#define HTTP_FORMAT_CONTENT_TYPE_DTCP     'E'
#define HTTP_FORMAT_UINT64                'L'
#define HTTP_FORMAT_CONTENT_LENGTH_64     'G'
#define HTTP_FORMAT_EXPECT                'e'
#define HTTP_FORMAT_GET_CONTENT_FEATURES  'f'
#define HTTP_FORMAT_FRIENDLY_NAME		  'F'

#define ALBUM_ART_URI_PREFIX_STR	"/albumArtURI"DEFAULT_DMSCONFIG_ID_DELIM
#define MIME_JPEG_STR							"jpeg"

#define THUMBNAIL_URI_PREFIX_STR        "/thumbnailURI"DEFAULT_DMSCONFIG_ID_DELIM

enum http_transfer_mode_ {
  HTTP_TRANSFER_MODE_NONE = 0,
  HTTP_TRANSFER_MODE_INTERACTIVE,
  HTTP_TRANSFER_MODE_STREAMING,
  HTTP_TRANSFER_MODE_BACKGROUND
};

typedef enum http_transfer_mode_ http_transfer_mode_t;

/* for byte seek */
struct http_range
{
  slim_bool range_request;
  dlna_uint64 first_byte_pos;
  dlna_uint64 last_byte_pos;
};

typedef struct http_range http_range_t;

#ifdef DEVELOPMENT_ENABLE_HTTP_CLIENT_PLAYSPEED
struct http_playspeed
{
  slim_bool ps_request;
  slim_char *speed;
};
typedef struct http_playspeed http_playspeed_t;
#endif /*DEVELOPMENT_ENABLE_HTTP_CLIENT_PLAYSPEED*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_bool
http_persistent_check(http_message_t *in_http_message);

slim_int
http_content_type_xml(http_message_t *in_http_message);

slim_int
http_build(struct sbuf *in_buf, slim_char *in_format, ...);

slim_int
http_transfer_mode_set(struct sbuf *in_headers, http_transfer_mode_t in_mode);

/* for byte seek */
slim_int 
http_transfer_range_set(struct sbuf *in_headers, http_range_t *in_range);

#ifdef DEVELOPMENT_ENABLE_HTTP_CLIENT_PLAYSPEED
slim_int
http_transfer_playspeed_set (struct sbuf *headers, http_playspeed_t *ps);
#endif /*DEVELOPMENT_ENABLE_HTTP_CLIENT_PLAYSPEED*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_HTTP_H */
