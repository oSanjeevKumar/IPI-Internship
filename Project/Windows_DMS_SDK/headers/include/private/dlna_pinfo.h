/*
 * dlna_pinfo.h
 * Copyright (C) 2007 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */

#ifndef NFLC_DLNA_PINFO_H
#define NFLC_DLNA_PINFO_H


/*
 * DLNA v1.5 7.3.37 MM flags-param (Flags Parameter)
 * Example: DLNA.ORG_FLAGS=03100000000000000000000000000000
 */
#define DLNA_PINFO_FLAGS_CTEXT_LIMIT    (1 << 14)  /* Cleartext Limited Data Seek Flag */
#define DLNA_PINFO_FLAGS_CTEXT_FULL     (1 << 15)  /* Cleartext Byte Full Data Seek Flag */
#define DLNA_PINFO_FLAGS_LP             (1 << 16)  /* Link Protected Content Flag */
#define DLNA_PINFO_FLAGS_DLNA_VERSION   (1 << 20)  /* DLNA v1.5 versioning flag */
#define DLNA_PINFO_FLAGS_HTTP_STALL     (1 << 21)  /* HTTP Connection Stalling Flag */
#define DLNA_PINFO_FLAGS_TR_BACKGROUND  (1 << 22)  /* Background Mode Flag */
#define DLNA_PINFO_FLAGS_TR_INTERACTIVE (1 << 23)  /* Interactive Mode Flag */
#define DLNA_PINFO_FLAGS_TM_STREAMING   (1 << 24)  /* Streaming Mode Flag */
#define DLNA_PINFO_FLAGS_RTSP_PAUSE     (1 << 25)  /* Pause support for RTP Serving Endpoints */
#define DLNA_PINFO_FLAGS_SN_INCREASE    (1 << 26)  /* UCDAM Sn Increasing Flag */
#define DLNA_PINFO_FLAGS_SZERO_INCREASE (1 << 27)  /* UCDAM s0 Increasing Flag */
#define DLNA_PINFO_FLAGS_PLAY_CONTAINER (1 << 28)  /* PlayContainer Flag */
#define DLNA_PINFO_FLAGS_LOP_BYTESEEK   (1 << 29)  /* Limited Operations Flags:Byte-Based Seek */
#define DLNA_PINFO_FLAGS_LOP_TIMESEEK   (1 << 30)  /* Limited Operations Flags:Time-Based Seek */
#define DLNA_PINFO_FLAGS_SP             (1 << 31)  /* Sender Paced Flag */


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus  */



slim_bool 
pinfo_is_dtcp(slim_char *in_pinfo);

slim_bool 
pinfo_get_dtcp_ip_port(slim_char *in_pinfo,
                            dlna_ip_addr *out_ip_addr,
                            slim_int *out_port);

slim_int
pinfo_dtcp_get_mime_type (slim_char *in_pinfo, slim_char **out_mime);

slim_int
pinfo_get_profile (slim_char *pinfo, slim_char **out_profile);

slim_int
pinfo_get_mime_type (slim_char *pinfo, slim_char **out_pinfo);

slim_bool
pinfo_is_content_type_image(slim_char *pinfo);

slim_bool
pinfo_is_support_info(slim_char *in_str, slim_int in_len);

slim_bool
pinfo_is_support_byte_seek(slim_char *in_info, slim_int in_len);
  
slim_bool
pinfo_is_support_time_seek(slim_char *in_info, slim_int in_len);

slim_bool
pinfo_is_support_playspeed(slim_char *in_info, slim_int in_len, slim_char* playspeed);

slim_bool
pinfo_check_playspeed(slim_char *in_info, slim_int in_len);

slim_bool
pinfo_set_byte_seek_value(slim_char *in_out_info, slim_bool in_supported);

slim_bool
pinfo_set_time_seek_value(slim_char *in_out_info, slim_bool in_supported);

slim_int
pinfo_get_protocol_offset (slim_char *in_pinfo_str, slim_char **out_start, slim_char **out_end);

slim_bool
pinfo_get_next_protocol (slim_char *in_protocol, slim_char **inout_start, slim_int *out_len);

slim_int
pinfo_get_mime_from_profile(slim_char *pinfo, slim_char **out_mine);

slim_bool
pinfo_get_dlna_attr(slim_char *in_pinfo, slim_char *name, dlna_split_ss *out_attr);

slim_int
pinfo_get_best_mime(slim_char *pinfo, slim_char **out_mime);

slim_int
pinfo_get_dlna_flags(slim_char *pinfo, slim_word *out_flags);

slim_char*
pinfo_create_dlna_flags(slim_word in_dlna_org_flags);

slim_int
pinfo_create_from_content_type(slim_char *content_type, slim_char**out_pinfo);

slim_int
pinfo_create_from_content_features(slim_char *content_features, slim_char *content_type, slim_char**out_pinfo);

void
ctt_7_3_40_1_2_check_pinfo_other_param(sXML* in_item);

slim_bool
pinfo_has_dlna_org_params(slim_char *pinfo);

slim_bool
pinfo_dlna_flag_is_set(slim_char *pinfo, slim_word in_flags);

#ifdef __cplusplus
}
#endif    /* __cplusplus */

#endif /* NFLC_DLNA_PINFO_H */
