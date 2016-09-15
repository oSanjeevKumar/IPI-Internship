/*
 * webdiagc_interface_action.h
 * Copyright (C) 2014 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef __WEBDIAGC_INTERFACE_ACTION_H__
#define __WEBDIAGC_INTERFACE_ACTION_H__

#include <nflc_sxml.h>

slim_bool
webdiagc_action_init();

slim_bool
webdiagc_action_release();

slim_int
webdiagc_action_get_dms_count();

sXML *
webdiagc_action_get_response();

slim_int
webdiagc_action_handle_request(sXML *requestDoc);

slim_int
webdiagc_action_handle_getDmsPropByIndexId(slim_int indexId, slim_char* out_deviceName, slim_char* out_uuid, slim_int out_length);
#endif /* __WEBDIAGC_INTERFACE_ACTION_H__ */

