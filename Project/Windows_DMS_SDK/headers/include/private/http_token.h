/*
 * http_token.h
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

#ifndef NFLC_HTTP_TOKEN_H
#define NFLC_HTTP_TOKEN_H

/* Used to represent different types of tokens in input.  */
enum token_type_
{
  TOKEN_IDENTIFIER, 
  TOKEN_WHITESPACE, 
  TOKEN_CRLF, 
  _cp_TOKEN_CONTROL,
  TOKEN_SEPARATOR,
  TOKEN_QUOTEDSTRING
};

typedef enum token_type_ token_type_t;

/* HTTP parse status.  */
enum parse_status_
{
  PARSE_SUCCESS = 0,
  PARSE_FAILURE,
  PARSE_TOKEN,
  PARSE_INCOMPLETE,
  PARSE_INCOMPLETE_ENTITY,
  PARSE_NO_MATCH,
  PARSE_CONTINUE,
  PARSE_OUT_OF_MEMORY,
  PARSE_METHOD_FAILURE,
};

typedef enum parse_status_ parse_status_t;


/* HTTP message walker.  */
struct walker
{
  /* String buffer.  */
  struct sbuf *msg;

  /* Current position.  */
  dlna_size_t cp;

  /* The packet is fully loaded or not.  */
  slim_int full;
};

typedef struct walker walker_t;

#ifdef __cplusplus
extern "C" {
#endif

void
walker_init(walker_t *walker, struct sbuf *sbuf);

slim_char *
walker_pointer(walker_t *walker);

parse_status_t
http_token_get(walker_t *walker, dlna_split_ss *token,
               token_type_t *token_type);

parse_status_t
http_value_get(walker_t *walker, dlna_split_ss *token,
               token_type_t *token_type);

parse_status_t
http_whitespace_skip(walker_t *walker);

slim_int
http_match(walker_t *walker, slim_char *format, ...);

slim_int
http_match_string(slim_char *str, dlna_size_t slen, slim_char *format, ...);

#ifdef __cplusplus
}
#endif

#endif /* NFLC_HTTP_TOKEN_H */
