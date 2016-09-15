/*
 * rui_interface.h
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

#ifndef __RUI_INTERFACE_H__
#define __RUI_INTERFACE_H__

#include "rui_defines.h"

#ifdef ENABLE_DMS_RUNTIME_CONFIGURATION
#include <nflc_sxml.h>
rui_result_t 
ruisrc_getdevdescr(sXML *dev_doc);
#else /* ENABLE_DMS_RUNTIME_CONFIGURATION */
rui_result_t 
ruisrc_getdevdescr(slim_char *in_dev_descr_dir, 
                        slim_char **inout_dev_descr_file);
#endif /* ENABLE_DMS_RUNTIME_CONFIGURATION */

rui_result_t 

ruisrc_is_post_msg(const slim_char * url);

rui_result_t
ruisrc_handle_post_msg(const slim_char * url, const slim_char * msg_buf,
    const slim_char * in_config_dir);

rui_result_t
ruisrc_add_ui(const slim_char * ui, const slim_char * in_config_dir,
    const slim_char * in_ruisrc_uilist_file);

rui_result_t
ruisrc_remove_ui(const slim_char * ui_id, const slim_char * in_config_dir,
    const slim_char * in_ruisrc_uilist_file);

rui_result_t
ruisrc_update_ui(const slim_char * ui, const slim_char * in_config_dir,
    const slim_char * in_ruisrc_uilist_file);

#endif /* __RUI_INTERFACE_H__ */

#endif /* DLNA_SUPPORT_RUISRC */

