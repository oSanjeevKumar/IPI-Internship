/*
 * http_parser.h
 * Copyright (C) 2007 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2005 IP Infusion, Inc. All Rights Reserved.  */

#ifndef NFLC_HTTP_PARSER_H
#define NFLC_HTTP_PARSER_H

#include <nflc_sxml.h>
#include <nflc_uri.h>
#include <nflc_sbuf.h>

#include <http_map.h>
#include <http_code.h>
#include <http_token.h>

/* HTTP header.  */
struct http_header
{
  /* Linked list.  */
  struct http_header *prev;
  struct http_header *next;

  /* ID for the header.  */
  slim_int id;

  /* Name of the header.  */
  slim_char *name;

  /* Value of the header.  */
  slim_char *val;

};

typedef struct http_header http_header_t;

/* HTTP version.  */
struct http_version
{
  slim_int major;
  slim_int minor;
};

typedef struct http_version http_version_t;

/* HTTP message.  */
struct http_message
{
  /* This is request message.  */
  slim_char is_request;

  /* Response method.  */
  http_method_t method;

  /* URI type.  */
  uri_type uri;
  slim_char *url;

  /* Request method.  */
  http_method_t request_method;

  /* HTTP status code.  */
  slim_int status_code;

  /* HTTP status message.  */
  struct sbuf status_msg;

  /* HTTP major and minor versions.  */
  http_version_t version;

  /* Message buffer.  */
  struct sbuf sbuf;

  /* Linked list of HTTP header.  */
  List(struct http_header *) headers;

  /* Entity position.  */
  dlna_split_ss entity;

};

typedef struct http_message http_message_t;

/* HTTP parser position.  */
typedef enum
{
  POSITION_REQUEST_LINE,
  POSITION_RESPONSE_LINE,
  POSITION_HEADER,
  POSITION_ENTITY,
  POSITION_COMPLETE,
} parser_position_t;

/* HTTP parser entity position.  */
typedef enum
{
  EPOSITION_GET_METHOD,
  EPOSITION_USING_CLEN,
  EPOSITION_USING_CHUNKED,
  EPOSITION_UNTIL_END,
  EPOSITION_CHUNK_BODY,
  EPOSITION_CHUNK_HEADERS,
  EPOSITION_USING_DTCP
} entity_position_t;

/* HTTP parser.  */
struct http_parser
{
  /* HTTP message.  */
  http_message_t msg;

  /* Message walker.  */
  walker_t walker;

  /* HTTP error code when parse is failed.  */
  slim_int error_code;

  /*
   * This is set to true if a NOTIFY request has no content-length.
   * used to read valid sspd notify msg.
   */
  slim_char valid_ssdp_notify_hack;

  /* HTTP parser position.  */
  parser_position_t position;

  /* HTTP parser entity position.  */
  entity_position_t entity_position;

  /* Content-length.  */
  dlna_size_t content_length; /* NOTE: This field can't change to 64bit. */

  /* Chunk entity size.  */
  dlna_size_t chunk_size;

  /* Entity start point.  */
  dlna_size_t entity_sp;

};

typedef struct http_parser http_parser_t;

/* Prototypes.  */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* HTTP message.  */
void
http_message_init(http_message_t *message);

void
http_message_clean(http_message_t *msg);

/* HTTP header utilitiy functions.  */
http_header_t *
http_header_lookup(http_message_t *message, slim_int id);

http_header_t *
http_header_lookup_str(http_message_t *message, slim_char *name);

/* HTTP parser init.  */
void
http_parser_request_init(http_parser_t *p);

void
http_parser_response_init(http_parser_t *p, http_method_t method);

parse_status_t
http_parse (http_parser_t *p);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_HTT_PPARSER_H */
