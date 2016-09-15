/*
 * dlna_ss.h
 * Copyright (C) 2008-2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */

/* DLNA sub-string functions.  */

#ifndef NFLC_DLNA_SS_H
#define NFLC_DLNA_SS_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void
strpnt_assign(dlna_split_ss *p, slim_char *s);

slim_char*
strpnt_dup(dlna_split_ss *p);

slim_int
strpnt_cmp(dlna_split_ss *p, slim_char *s);

slim_int
strpnt_cmp_nocase(dlna_split_ss *p, slim_char *s);

slim_int
strpnt_contain(dlna_split_ss *p, slim_char *s);

slim_bool
strpnt_contain2 (slim_char *s, dlna_split_ss *p);

slim_bool
strpnt_contain2_nocase(slim_char *s, dlna_split_ss *p);

slim_int
strpnt_derived(dlna_split_ss *p, slim_char *s);

slim_int
strpnt_search(dlna_split_ss *data, dlna_split_ss *key);

#ifdef DLNA_DEBUG
void
strpnt_print (dlna_split_ss *p);
#endif

slim_char*
strpnt_cat (slim_char *s, dlna_split_ss *p);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_DLNA_SS_H */
