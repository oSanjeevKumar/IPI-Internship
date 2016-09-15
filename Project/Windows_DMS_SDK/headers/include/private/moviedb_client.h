/*
 * moviedb_client.h
 * Copyright (C) 2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */


#ifndef NFLC_MOVIEDB_CLIENT_H
#define NFLC_MOVIEDB_CLIENT_H

#include <nflc_sxml.h>

typedef void (*moviedb_response_callback) (void *info, sXML *response_doc);
/* MOVIEDB client structure.  */
typedef struct moviedb_client_
{
	struct dms *top;
	moviedb_response_callback moviedb_response_cb;
	void* movideb_cb_arg;
} moviedb_client;

typedef struct callback_arg_
{
	moviedb_client* mdbc;
	struct http_client *hc;
	slim_char* movie_id;
} callback_arg_t;
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus  */

/* Prototypes.  */

moviedb_client *
moviedb_client_alloc (void *arg, moviedb_response_callback cb_func, void* cb_arg);

void
moviedb_client_free(moviedb_client *mdbc);

/* uiList description download.  */
void
moviedb_client_moviesearch_download(moviedb_client *mdbc, slim_char *in_url, slim_char* id);

#ifdef __cplusplus
}
#endif    /* __cplusplus */

#endif /* NFLC_RUI_CLIENT_H */