/*
 * rui_utils.h
 * Copyright (C) 2009-2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifdef DLNA_SUPPORT_RUISRC

#ifndef __RUI_UTILS_H__
#define __RUI_UTILS_H__

#include "rui_defines.h"
#include <dlna_peer.h>
#include <nflc_sxml.h>

rui_result_t 
rui_parsefile(slim_char *in_dir, slim_char *in_file, sXML ** doc);

rui_result_t 
rui_writefile(sXML * doc, slim_char *in_dir, slim_char *in_file);

rui_result_t 
rui_isfileexists(slim_char *in_dir, slim_char *in_file);

rui_result_t 
rui_getuuid(slim_char *out_uuid_str);

slim_char * 
rui_strip(slim_char *in_str);

slim_char * 
rui_quotes_rm(slim_char *in_str);

#endif /* __RUI_UTILS_H__ */

#endif /* DLNA_SUPPORT_RUISRC */

