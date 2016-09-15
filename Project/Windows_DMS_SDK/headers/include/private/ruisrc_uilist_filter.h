/*
 * ruisrc_uilist_filter.h
 * Copyright (C) 2009-2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#include <dlna_peer.h>

#ifdef DLNA_SUPPORT_RUISRC

#ifndef __RUISRC_UILIST_FILTER_H__
#define __RUISRC_UILIST_FILTER_H__

#include <rui_defines.h>
#include <nflc_sxml.h>
#include <ruisrc_service.h>

#define RUISRC_GET_COMPT_UIS_FILTER_LEN        4096
#define RUISRC_GET_COMPT_UIS_FILTER_DELIMITER  ","
#define RUISRC_FILTER_VALUE_ELEM               "internal_filter_value"

typedef struct {
  sXML      * in_ruipl_profile_doc;
  slim_char * in_filter;
  sXML      * internal_filter_doc;
  slim_char * out_ruisrc_uilist;
} ruisrc_uilist_filter_t;

rui_result_t 
ruisrc_uilist_filter_get_uilist(struct ruis_service *s,ruisrc_uilist_filter_t * data);

#endif /* __RUISRC_UILIST_FILTER_H__ */

#endif /* DLNA_SUPPORT_RUISRC */



