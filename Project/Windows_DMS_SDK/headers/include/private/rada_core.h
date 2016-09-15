/*
 * rada_core.h
 * Copyright (C) 2007-2011 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_RADA_CORE_H
#define NFLC_RADA_CORE_H

#include <rada_api.h>

/* Struct for single global variable for the RADA CP.  */
struct rada
{
  /* UPnP client back pointer.  */
  struct upnp_client *uc;

  struct dlna_client_tag dlna_client;

  TRADAEventHandler callback;  
  void *arg;  
};

typedef struct rada rada_t;

/* Prototypes.  */
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

rada_t *
radacp_alloc(dlna_progress in_p);

slim_int
radacp_free(rada_t *top);

slim_int
radacp_start (rada_t *top, TRADAEventHandler in_rada_eh, void *in_arg);

slim_int
radacp_stop(rada_t *top);

dlna_progress
radacp_get_progress(rada_t *top);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_DMC_CORE_H */
