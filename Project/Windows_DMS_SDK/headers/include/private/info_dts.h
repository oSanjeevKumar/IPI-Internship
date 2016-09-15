/*
 * info_dts.h
 * Copyright (C) 2008 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* DTS codec support for NFLC. */


#ifndef NFLC_INFO_DTS_H
#define NFLC_INFO_DTS_H

#define  DTS_PROFILE_AUDIO_SAMPS  20
#define  DTS_PROFILE_AUDIO_CHANS  20

typedef struct
{
  slim_int      samp_rates[DTS_PROFILE_AUDIO_SAMPS];
  slim_char *   chan_modes[DTS_PROFILE_AUDIO_CHANS];
  slim_int      min_bit_rate;
  slim_int      max_bit_rate;
} dts_profile_audio_t;

aud_prof_t
dts_profile_get(minfo_t *info);
slim_char*
dts_get_prof_str(slim_int profile_id) ;

#endif /* NFLC_INFO_DTS_H */
