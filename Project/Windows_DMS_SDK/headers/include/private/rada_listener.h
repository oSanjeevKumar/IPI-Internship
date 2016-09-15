/*
 * rada_listener.h
 * Copyright (C) 2015 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */


#ifndef _RADA_LISTENER_H
#define _RADA_LISTENER_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_int
rada_listener_remove_all_devices(struct rada_sync *s) ;
slim_bool
rada_listener_sysinfo_device_add(struct ra_device *top, slim_char *in_uuid) ;
slim_bool
rada_listener_sysinfo_device_remove(struct ra_device *top, slim_char *in_uuid) ;
slim_int
rada_listener_device_is_visible(struct ra_device *top, slim_char *usn) ;
void
rada_listener_apply_filter(struct ra_device *top, rada_config_filter_list_t *filter);
slim_int
rada_listener_remove_device(struct rada_sync *s, slim_char *usn) ;
slim_int
rada_listener_forward_device(struct rada_sync *s, slim_char *usn, slim_char *rada_usn) ;
slim_int
rada_listener_forward_all_devices(struct rada_sync *s, slim_char *rada_usn) ;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _RADA_LISTENER_H */
