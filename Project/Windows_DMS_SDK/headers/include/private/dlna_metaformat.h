/*
 * dlna_metaformat.h
 * Copyright (C) 2008 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_DLNA_METAFORMAT_H
#define NFLC_DLNA_METAFORMAT_H

#include <dlna_mime.h>
#include <minfo.h>
#include <nflc_sxml.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_bool
dlna_validate_date_format_for_7_3_21_1 (slim_char* in_date);

slim_bool
dlna_validate_format_for_7_3_22_1 (slim_char* in_duration);

void
dlna_generate_duration_format (slim_char *out_buf, slim_int in_buf_len, minfo_dur_t *in_duration);

void
upnp_mrcp_avts_metadata_revise_for_7_3_17_1(sXML *res);

void
upnp_mrcp_avts_metadata_revise_for_7_3_17_2(sXML *res);

void
upnp_mrcp_avts_metadata_revise_for_7_3_17_3(sXML *res);

void
upnp_mrcp_avts_metadata_revise_for_7_3_17_4(sXML *res);

void
upnp_mrcp_avts_metadata_revise_for_7_3_21_1(sXML *res);

void
upnp_mrcp_avts_metadata_revise_for_7_3_22_1(sXML *res);

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif /* NFLC_DLNA_METAFORMAT_H */

