/*
 * ruisrc_connhdlr.h
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

#ifndef __RUISRC_CONNHDLR_H__
#define __RUISRC_CONNHDLR_H__

#include "rui_defines.h"

#ifdef ENABLE_DMS_RUNTIME_CONFIGURATION
#include <nflc_sxml.h>
rui_result_t
ruisrc_prepdevdescrdoc(sXML *dev_doc);
#endif /* ENABLE_DMS_RUNTIME_CONFIGURATION */

rui_result_t 
ruisrc_getdevdescr_int(slim_char *in_dev_descr_dir, 
                            slim_char **inout_dev_descr_file);

#if 0
ruisrc_getuilist(client_profilelist);
#endif
#endif /* __RUISRC_CONNHDLR_H__ */

#endif /* DLNA_SUPPORT_RUISRC */

