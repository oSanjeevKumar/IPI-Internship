/*
 * info_aac.h
 * Copyright (C) 2015 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* AAC codec support for NFLC. */


#ifndef NFLC_INFO_AAC_H
#define NFLC_INFO_AAC_H

#ifdef MEDIA_PROCESSING_EXTENSION
dlna_ret_t
aac_adts_profile_get(minfo_t *info);
dlna_ret_t
aac_profile_get(minfo_t *info);
#else /* MEDIA_PROCESSING_EXTENSION */
slim_bool
register_media_info_aac(media_manager_t *mim);
#endif /* MEDIA_PROCESSING_EXTENSION */

#endif /* NFLC_INFO_AAC_H */
