/*
 * info_dab.h
 * Copyright (C) 2008 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* VC-1 codec support for NFLC. */


#ifndef NFLC_INFO_DAB_H
#define NFLC_INFO_DAB_H

slim_bool
register_media_info_dab(media_manager_t *mim);

dlna_profile_t
dab_profile_get(minfo_t *info);

slim_char*
dab_get_prof_str(minfo_t *info);

#endif /* NFLC_INFO_DAB_H */
