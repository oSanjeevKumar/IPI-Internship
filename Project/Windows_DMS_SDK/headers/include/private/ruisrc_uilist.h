/*
 * ruisrc_uilist.h
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

#ifndef __RUISRC_UILIST_H__
#define __RUISRC_UILIST_H__

#include "rui_defines.h"
#include "ruisrc_uilist_filter.h"

typedef struct {
  slim_char ui_id_list[RUISRC_UPDATED_UI_ID_LIST_MAX_LEN + 1];
} ruisrc_uilist_result_t;

rui_result_t
ruisrc_uilist_is_post_msg(const slim_char *url);

rui_result_t
ruisrc_uilist_update(const ruisrc_ui_oper_t oper, const slim_char *input,
    const slim_char * in_config_dir, const slim_char * in_ruisrc_uilist_file);

rui_result_t
ruisrc_uilist_get_compatible_uis(struct ruis_service *s,
    ruisrc_uilist_filter_t * data);

#endif /* __RUISRC_UILIST_H__ */

#endif /* DLNA_SUPPORT_RUISRC */

