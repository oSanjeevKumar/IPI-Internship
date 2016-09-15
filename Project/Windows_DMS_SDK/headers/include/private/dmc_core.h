/*
 * dmc_core.h
 * Copyright (C) 2007-2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_DMC_CORE_H
#define NFLC_DMC_CORE_H

#include <dmc_api.h>

/* Struct for single global variable for the DMP client.  */
struct dmc
{
  /* UPnP client back pointer.  */
  struct upnp_client *uc;

  struct dlna_client_tag dlna_client;

  TDMCEventHandler callback;  
  void *arg;  
};

typedef struct dmc dmc_t;

/* Prototypes.  */
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

dmc_t *
dmc_alloc(dlna_progress in_p, slim_char* in_config_dir);

slim_int
dmc_free(dmc_t *top);

slim_int
dmc_start (dmc_t *top, TDMCEventHandler in_dmc_eh, void *in_arg);

slim_int
dmc_stop(dmc_t *top);

dlna_progress
dmc_get_progress(dmc_t *top);

slim_int
dmc_object_get_pi_thum (dlna_object_t *obj, slim_int *out_value_len);

slim_int
dmc_object_get_ci_nth (dlna_object_t *obj, slim_int in_res_index);

slim_int
dmc_object_get_default_res_index(dlna_object_t *in_obj);

slim_int
dmc_object_get_mime_type (dlna_object_t *obj, slim_int res_index, slim_char **out_ResMimeType);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_DMC_CORE_H */
