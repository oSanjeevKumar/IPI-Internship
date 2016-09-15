/*
 * rui_client.h
 * Copyright (C) 2009 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2005 IP Infusion, Inc. All Rights Reserved.  */

#ifndef NFLC_RUI_CLIENT_H
#define NFLC_RUI_CLIENT_H


/* RUI client structure.  */
struct rui_client
{
  /* UPnP client structure.  */
  struct upnp_client *uc;

  struct http_client *hc;
	slim_char *client_capability ;
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus  */

/* Prototypes.  */

struct rui_client *
rui_client_alloc(struct upnp_client *uc);

void
rui_client_free(struct rui_client *sc);

/* uiList description download.  */
void
rui_client_uilist_download(struct upnp_client *in_uc, void *in_arg, slim_char *in_url);

#ifdef __cplusplus
}
#endif    /* __cplusplus */

#endif /* NFLC_RUI_CLIENT_H */
