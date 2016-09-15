/*
 * ruipl_core.h
 * Copyright (C) 2009 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */


#ifndef NFLC_RUIPL_CORE_H
#define NFLC_RUIPL_CORE_H

#include <nflc_player.h>

#ifdef DLNA_SUPPORT_RUIPL

struct _ruipl
{
  dlna_client_t *dc;  
  nflc_player av_player;
};

typedef struct _ruipl ruipl_t;

/* Prototypes.  */
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_int
ruipl_start (ruipl_t *self);

/* Stop RUIPL.  */
slim_int
ruipl_stop (ruipl_t *self);

/* Allocate RUIPL.  */
ruipl_t *
ruipl_alloc (dlna_client_t *in_dc);

/* Free RUIPL.  */
slim_int
ruipl_free (ruipl_t *self);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* DLNA_SUPPORT_RUIPL */

#endif /* NFLC_RUIPL_CORE_H */
