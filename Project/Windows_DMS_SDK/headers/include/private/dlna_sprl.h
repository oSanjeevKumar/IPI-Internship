/*
 * dlna_sprl.h
 * Copyright (C) 2009 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_DLNA_SPRL_H
#define NFLC_DLNA_SPRL_H

#if defined (DLNA_SUPPORT_SPRL)

#ifdef __cpluscplus
extern "C" {
#endif /* __cpluscplus */

slim_bool
dlna_sprl_check_cap (dlna_object_t *self, slim_char *cap);
slim_int
dlna_sprl_get_next_ready_time (dlna_object_t *self, slim_int *out_time);

#ifdef __cpluscplus
}
#endif /* __cpluscplus */

#endif /* (DLNA_SUPPORT_SPRL) */

#endif /* NFLC_DLNA_SPRL_H */

