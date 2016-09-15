/*
 * dms_push.h
 * Copyright (C) 2007 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_DMS_PUSH_H
#define NFLC_DMS_PUSH_H

#include <nflc_dms.h>
#include <dlna_client.h>

struct dms_push_tag {

  /* Back pointer */
  struct dms *dms;
  struct upnp_client *uc;
  dlna_progress em;
  
  /* DMS event handler.  */
  TDLNAEventHandler dms_push_eh;

  struct dlna_client_tag dlna_client;
};

typedef struct dms_push_tag dms_push_t;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus__ */



/* Internal function */
dms_push_t*
dms_push_alloc(dlna_progress in_progress, struct dms *top, dlna_ssdp_t *in_ssdp);

slim_int
dms_push_start(dms_push_t *in_dms_push);

slim_int
dms_push_stop(dms_push_t *in_dms_push);

void
dms_push_free(dms_push_t *in_dms_push);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_DMS_PUSH_H */
