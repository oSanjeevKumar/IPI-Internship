/*
 * info_amr.h
 * Copyright (C) 2008 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* AMR codec support for NFLC. */


#ifndef NFLC_INFO_AMR_H
#define NFLC_INFO_AMR_H

aud_prof_t
amr_profile_get(minfo_t *info);

slim_char*
amr_get_prof_str(aud_prof_t profile_id) ;

#endif /* NFLC_INFO_AMR_H */
