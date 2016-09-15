/*
 * rata.h
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


#ifndef _RATA_H
#define _RATA_H

#include <twine_device_manager.h>
#include <rata_backend.h>
#include <proxy.h>
#include <upnp_interface.h>

// we limit the strstr to a max. it should conver the expected header length
//#define ALG_MAX_PARSE_LEN 512


typedef slim_int (*TRATAListenerCallback)( slim_int msg, void *context, void *data ) ;


struct rata_listener
{
  struct rata_listener *next;
  struct rata_listener *prev;
  TRATAListenerCallback	callback ;
  void	*context ;
  slim_int msg ;
};

struct rata_remote_peer
{
  struct rata_remote_peer *next;
  struct rata_remote_peer *prev;
  struct  proxy_crypt_ctx crypt_ctx ;
  slim_char *domid ;
  slim_char *gid ;
  slim_char *uuid ;
  slim_char *name ;
  slim_char *remote_id ;
  slim_char *device_id ;
  dlna_ip_addr	addr;
  slim_int port ;
  slim_word permission ;
};

struct rata_target {
  struct rata_target  *next ;
  struct rata_target  *prev ;
  slim_char *domid ;
  slim_char *gid ;
  slim_char *name ;
  slim_char *uuid ;
  slim_char *token ;
  dlna_ip_addr	addr;
  slim_int port ;
  slim_word permission ;
  slim_int state ;

} ;

struct rata_friend {
  struct rata_friend  *next ;
  struct rata_friend  *prev ;
  slim_char *uid ;
  slim_word permission ;
} ;

struct	_rata {
  struct	_proxy	*proxy;
  struct rada *rada_device;

  slim_int fl_is_ras;

  dlna_progress em;
  dlna_progress_handle startup_event;
  dlna_progress_handle update_event;
  slim_char *config_dir;
  slim_char *config_file;
  slim_char *path ;

  HDEVMAN device_manager;
 // void *twine_manager;

  slim_char	*remote_id;	      // user id 
  slim_char	*device_id;				// GID
  slim_char	*uuid;						// DD uuid of the rada
  slim_char *device_serial ;  

  List( struct rata_listener *)listeners;
  struct  proxy_crypt_ctx crypt_ctx;
  List( struct rata_remote_peer *)remote_peers;
  dlna_mutex	remotes_list_mutex;

  List( struct rata_target *)targets;
  dlna_mutex	targets_list_mutex;

  List( struct rata_friend *)friends;
  dlna_mutex	friends_list_mutex;

  slim_char *token ;                               

  struct rata_backend backend ;
  slim_int fl_is_provisioning ;
  slim_int fl_is_backend_running ;
  slim_int fl_is_upnp_running ;
  slim_int fl_is_address_available ;

  slim_int fl_is_config_changed ;
};

struct rata_notify_result {
  slim_int status ;
	slim_char *str;
	slim_int num;
} ;

typedef List( struct rata_remote_peer *)rata_remote_peers_t ;
typedef List( struct rata_target *) rata_targets_t;
typedef List( struct rata_friend *) rata_friends_t;




#ifdef __cplusplus

extern "C" {
#endif /* __cplusplus */


// helper can go out
void PrintAddr(slim_int dbg_flag, slim_char *text, dlna_ip_addr *addr, slim_int port) ;

/* Prototypes.  */
struct _rata *
rata_alloc ( struct rada *top, slim_int fl_is_ras, dlna_progress em, slim_char *config_dir, slim_char *config_file, slim_char *certs_path ) ;
void
rata_free (struct _rata *rata) ;
slim_int
rata_start (struct _rata *rata) ;
slim_int
rata_stop (struct _rata *rata) ;

/* API: Start ra service  */
slim_int
rata_start_ra_service (struct _rata *self) ;
/* API: Stop ra service */
slim_int
rata_stop_ra_service (struct _rata *self) ;

slim_int
rata_notify_if_address_up (struct _rata *rata,
                           struct upnp_address * addr);
slim_int
rata_notify_if_address_down (struct _rata *rata,
                           struct upnp_address * addr);

slim_int
rata_notify_upnp_initialized (struct _rata *rata);
slim_int
rata_notify_upnp_finalized (struct _rata *rata);

#ifdef RA_USE_RID_HEADER
slim_int
rata_propagate_permission (struct _rata *rata, slim_char *in_rid, slim_word in_permission) ;
slim_int
rata_propagate_all_permissions (struct _rata *rata) ;
#endif //#ifdef RA_USE_RID_HEADER

#ifdef DLNA_SUPPORT_PROVISIONING
slim_int
rata_propagate_all_properties (struct _rata *rata) ;
#endif //#ifdef DLNA_SUPPORT_PROVISIONING

#ifdef DLNA_SUPPORT_LOGGING
slim_int
rata_log_alive (struct _rata *rata) ;
#endif //#ifdef DLNA_SUPPORT_LOGGING

slim_int
rata_get_public_ip(struct _rata *rata, dlna_ip_addr *public_addr) ;
slim_int
rata_get_local_ip(struct _rata *rata, dlna_ip_addr *local_addr) ;
slim_int
rata_get_public_port(struct _rata *rata, slim_int *public_port) ;
slim_int
rata_get_local_port(struct _rata *rata, slim_int *local_port) ;


void
rata_set_remote_identity( struct _rata *rata, slim_char *remote_identity) ;

void
rata_set_device_id( struct _rata *rata, slim_char *device_id) ;

void
rata_set_uuid( struct _rata *rata, slim_char *uuid) ;

void
rata_set_device_serial (struct _rata *rata, slim_char * device_serial) ;

slim_int 
rata_set_privacy(struct ra_device *top, slim_bool in_privacy_flag) ;

slim_int 
rata_get_privacy(struct ra_device *top, slim_bool *in_privacy_flag) ;

slim_int
rata_mac_get(struct _rata * rata) ;
slim_int
rata_devtype_get(struct _rata * rata) ;


struct rata_client *
rata_client_get(struct _rata *rata, dlna_ip_addr *addr) ;
slim_int
rata_client_remove(struct _rata *rata, dlna_ip_addr *addr) ;

// remote peers
struct rata_remote_peer *
rata_remote_peer_get(struct _rata *rata, dlna_ip_addr *addr, slim_char *uuid) ;
slim_int 
rata_remote_peer_remove(struct _rata *rata, slim_char *uuid) ;
slim_int 
rata_remotes_list_lock(struct _rata * rata) ;
slim_int
rata_remotes_list_unlock(struct _rata * rata) ;
slim_int 
rata_remote_peer_add_friendly_name(struct _rata *rata, slim_char *uuid, slim_char *name) ;
slim_int 
rata_remote_peer_add_domid_and_gid(struct _rata *rata, slim_char *uuid, slim_char *domid, slim_char *gid) ;

struct rata_remote_peer *
rata_remote_peer_add(struct _rata *rata, slim_char *uuid,  dlna_ip_addr *addr, slim_int port, slim_word permission, slim_char *device_id) ;

// application interface to catch events from embedded twinelib 

slim_int
rata_add_listener (struct _rata *rata, slim_int msg, TRATAListenerCallback cb, void *arg) ;
slim_int
rata_remove_listener ( struct _rata *rata, slim_int msg) ;
slim_int 
rata_remove_all_listeners(struct _rata *rata) ;

slim_int
rata_connect_ras (struct _rata *rata, slim_char *target) ;

slim_int
rata_disconnect_ras (struct _rata *rata, slim_char *target) ;
slim_int
rata_disconnect_all (struct _rata *rata) ;

slim_int
rata_cancel (struct _rata *rata, slim_char *target) ;

slim_int
rata_ras_start (struct _rata *rata) ;
slim_int
rata_rac_start (struct _rata *rata) ;


slim_int
rata_notify_location (struct _rata *rata, slim_char *gid, slim_int event) ;

void
rata_app_notify_connected (struct _rata *rata, slim_char * uuid) ;
void
rata_app_notify_disconnected (struct _rata *rata, slim_char * uuid, slim_int status) ;
void
rata_app_notify_error (struct _rata *rata, slim_int error) ;
void
rata_app_notify (struct _rata *rata, slim_int event, void *data) ;


// info apis
proxy_channels_t *rata_get_proxy_channels(struct _rata *rata);
proxy_devices_t *rata_get_proxy_devices(struct _rata *rata);
rata_remote_peers_t *rata_get_remote_peers(struct _rata *rata);


//backend bindings
slim_int
rata_twine_get_public_ip (struct _rata *rata, slim_char *uid, slim_char *pwd, slim_char *target) ;
slim_int
rata_backend_provision ( struct _rata *rata, slim_char *uid, slim_char *pwd, slim_char *serial);
slim_int
rata_backend_authenticate ( struct _rata *rata, slim_char *serial, slim_char *token, slim_char *cookie);
slim_int
rata_backend_set_public_ip (struct _rata *rata,  slim_char *address, slim_char *uuid, slim_char *friendly_name);
slim_int
rata_backend_set_url (struct _rata *rata, slim_char *in_url);

slim_int
rata_backend_set_properties (struct _rata *rata,  slim_char *address, slim_char *uuid, slim_char *friendly_name, slim_char *device_type, slim_char *mac);
slim_int
rata_backend_get_properties ( struct _rata *rata, slim_char *gid);

slim_int
rata_backend_get_targets ( struct _rata *rata, slim_char *uid, slim_char *pwd);
slim_int
rata_backend_get_token (struct _rata *rata, slim_char *remote_id, TRATAListenerCallback cb, void *arg);
slim_int
rata_backend_get_url (struct _rata *rata, slim_char **out_url);


slim_int
rata_backend_get_friends (struct _rata *rata);
slim_int
rata_backend_create_friend (struct _rata *rata, slim_char *uid, slim_word permission);
slim_int
rata_backend_update_friend (struct _rata *rata, slim_char *uid, slim_word permission);
slim_int
rata_backend_delete_friend (struct _rata *rata, slim_char *uid) ;


//helpers should go to common module
slim_char *
dlna_strnstr_nocase(slim_char *buf, slim_char *search, slim_int len );
slim_char *
dlna_strstr_nocase(slim_char *buf, slim_char *search) ;


//targets
slim_int
rata_target_list_free(struct _rata *rata);
struct rata_target *
rata_target_list_get_target(struct _rata *rata, slim_char *uuid);
slim_int
rata_target_free(struct rata_target *in_target) ;



slim_int
rata_friend_list_free(struct _rata *rata);

slim_int 
rata_backend_app_log ( struct _rata *rata, slim_char *in_evt, slim_char *in_data );

slim_int
rata_backend_share (struct _rata *rata, slim_char *name, slim_char *uid)  ;

slim_int
rata_get_settings (struct _rata *rata, slim_char **out_settings)  ;


//log
slim_int 
rata_log ( struct _rata *rata, slim_int module,slim_int level, slim_int status );

slim_int 
rata_backend_log_device (struct _rata *rata, slim_char *type, slim_char *id, slim_char *name, slim_char *ua, slim_char *mac, slim_int event) ;
slim_int 
rata_backend_log_alive (struct _rata *rata, slim_char *data) ;

slim_int
rata_backend_extprop_get (struct _rata *rata, slim_char *api_name) ;
slim_int
rata_backend_extprop_set (struct _rata *rata, slim_char *api_name, slim_char *data) ;


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _RATA_H */
