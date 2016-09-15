/*
 * rada_sync.h
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


#ifndef _RADA_SYNC_H
#define _RADA_SYNC_H

#include <nflc_ra_device.h>

#define RADA_SYNC_HEARTBEAT_INTERVAL 60

#define RA_GETSYSTEMINFO_RESPONSE_HEADER    \
	"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"       \
	"<dads xmlns=\"urn:schema-upnp-org:ra:dads\" "   \
	"xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" "   \
	"xsi:schemaLocation=\"urn:schemas-upnp-org:ra:dads "   \
	"http://www.upnp.org/schemas/ra/dads-v1.xsd\">"   


/* RADASync:1 Service Template Version 1.01.  */


typedef struct rada_sync_system_info_device_info 
{
	struct rada_sync_system_info_device_info	*next ;
	struct rada_sync_system_info_device_info *prev ;

  slim_char *rada_uuid ;     
	slim_int cache_control ;

	slim_char *uuid ;
	slim_char *description_document ;
	slim_char *server ;
	slim_char *credentialID ;
//	slim_int visible ;
	slim_char *nt ;
}rada_sync_system_info_device_info_t ;


typedef struct rada_sync_system_info
{
	slim_int update_id ;
//	slim_char *local_rada_uuid ;
	List(rada_sync_system_info_device_info_t *) local_system_info_list;

	slim_char *remote_rata_credential_id ;
	slim_int remote_rata_is_connected ;

	slim_char *remote_rada_uuid;
	slim_char *remote_rada_ddd_location ;
	slim_int *remote_rada_heartbeat;

	List(rada_sync_system_info_device_info_t *) remote_system_info_list;

}rada_sync_system_info_t ;


typedef List(rada_sync_system_info_device_info_t *) local_system_info_list_t ;
typedef List(rada_sync_system_info_device_info_t *) remote_system_info_list_t ;


/* RADASync service.  */
struct rada_sync
{
  /* RADA service base structure.  */
    struct rada_service base;

	struct sbuf SystemInfo ;
	struct sbuf A_ARG_TYPE_DDDLocation ;
	struct sbuf A_ARG_TYPE_DeviceInfoList ;
	slim_char *A_ARG_TYPE_UUID;
	
	rada_sync_system_info_t	sysInfo ;

	struct upnp_device *remote_rada_device ;
//	struct upnp_device *remote_ras_device ;
//	List(rada_sync_system_info_t  *) local_system_info_list;
//	List(rada_sync_system_info_t  *) remote_system_info_list;

	dlna_timeval heartbeat_time;
	dlna_progress_handle heartbeat_timer;
	dlna_progress_handle notify_event;
	slim_int fl_is_connected ;
	slim_int fl_is_ras ;
	struct dynDNS_client *dc ; 	

  slim_int fl_is_started ;
};


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct rada_service *
rada_sync_alloc (struct rada *top, slim_int in_fl_is_ras);
//rada_sync_alloc (struct ra_device *top, slim_int in_fl_is_ras);

slim_int
rada_sync_init (struct rada_service *service) ;

slim_int
rada_sync_free (struct rada_sync *service);

void
rada_listener_apply_filter(struct ra_device *top, rada_config_filter_list_t *filter_list);

slim_bool
is_same_uuid( slim_char *uuid_a, slim_char *uuid_b);

//
void
ra_build_vardata_system_info(struct rada_sync *rds) ;

void
rada_sync_notify_connected(struct rada *top, dlna_ip_addr *addr, slim_int port, slim_char *uuid);
void
rada_sync_notify_disconnected (struct rada *top, dlna_ip_addr * addr, slim_int port, slim_char * uuid) ;

filter_list_t  *RAGetFilterList(struct ra_device *top) ;
local_system_info_list_t  *RAGetLocalSystemInfoList(struct ra_device *top) ;
remote_system_info_list_t  *RAGetRemoteSystemInfoList(struct ra_device *top) ;

slim_int
ra_read_xml_file( slim_char *path, struct sbuf *out_buf ) ;
slim_int
ra_write_xml_file( slim_char *path, slim_char *in_buf ) ;

slim_int
rada_relay_set_privacy (struct ra_device *top, slim_bool in_flag);

slim_int
rada_relay_get_privacy (struct ra_device *top, slim_bool *out_flag);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _RADA_SYNC_H */
