/*
 * nflc_uri.h
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

#ifndef NFLC_URI_H
#define NFLC_URI_H

#define URI_SUCCESS          (0)
#define URI_OUT_OF_MEMORY    (-1)
#define URI_INVALID_URL      (-2)

enum pathType
{
  ABS_PATH,
  REL_PATH,
  OPAQUE_PART
};

enum uriType
{
  _cp_ABSOLUTE,
  _cp_RELATIVE
};

struct HOSTPORT
{
  dlna_split_ss text;
  dlna_ip_addr addr;
  slim_int port;
};
typedef struct HOSTPORT hostport_type;

struct URI
{
  enum uriType type;
  dlna_split_ss scheme;
  enum pathType path_type;
  dlna_split_ss pathquery;
  dlna_split_ss fragment;
  hostport_type hostport;
};
typedef struct URI uri_type;

struct URL_LIST
{
  slim_int size;
  slim_char **urls;
  uri_type *parsedURLs;
};
typedef struct URL_LIST URL_list;

#ifdef __cplusplus
extern "C" {
#endif

/* Server side.  */
slim_int
url_list_alloc(slim_char *url_val, slim_int url_length, URL_list *out);

void
url_list_free(URL_list *list);

slim_int
uri_token_cmp(dlna_split_ss *in1, dlna_split_ss *in2);

slim_int 
resolve_rel_url(slim_char * base_url, slim_char * rel_url, slim_char ** out_url);

slim_int
uri_parse_escaped_chars(slim_char *in, slim_int *size);

slim_int
uri_parse_dots(slim_char *in, slim_int size);

slim_int
resolve_url(slim_char *base, slim_char *rel, slim_char *abs);

slim_int
url_fix(uri_type *url, uri_type *fixed_url);

slim_int
url_str_fix(slim_char *urlstr, slim_int urlstrlen, uri_type * fixed_url);

slim_int
uri_parse_uri(slim_char *in, slim_int max, uri_type *out);

slim_int
uri_special_chars_to_hex(slim_char **in, slim_int *size);

slim_char *
uri_special_char_to_hex_2(const slim_char *in_uri, slim_int *size);

slim_int  
uri_hex_to_space(slim_char* in_uri, slim_char** out_fullpath);

void
uri_free(slim_char* in_string);

slim_char *
uri_resolve_uri(slim_char *in_uri) ;

#ifdef DLNA_SUPPORT_RUISRC
slim_int
ruis_adjust_ip_address(sXML *in_doc,slim_int in_sock);
#endif /* DLNA_SUPPORT_RUISRC */


#ifdef __cplusplus
}
#endif

#endif /* NFLC_URI_H */
