/*
 * twine_transport_manager.h
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

/* Twine transport manager.  */

#ifndef TWINE_TRANSPORT_MANAGER_H
#define TWINE_TRANSPORT_MANAGER_H

#include <dlna_peer.h>

#define TWINE_TRANSPORT_AUTH_TYPE_DEFAULT 0
#define TWINE_TRANSPORT_AUTH_TYPE_EXT 1
#define TWINE_TRANSPORT_AUTH_TYPE_GID 2
#define TWINE_TRANSPORT_AUTH_TYPE_IDAM 3


typedef slim_int (*TTWINEListenerCallback)( void *data, void *context ) ;

// common up/down stream
typedef struct {
	slim_int cmd ;
	slim_int status ;
} status_struct;

//upstream
typedef struct {
	slim_char *gateway_id;
} twine_msg_powerup;

typedef struct {
	slim_char *gateway_id;
} twine_msg_powerdown;

typedef struct {
	slim_char *gateway_id;
} twine_msg_register;

typedef struct {
	slim_char *update_id;
} twine_msg_subscribe;


typedef struct {
	slim_char *did;
	slim_char *cid;
	slim_char	*title ;
	slim_char	*ua ;
	slim_int	size ;
	slim_int	duration ;
	slim_int  protection_type ;

	slim_char	*mime ;
	slim_char	*parentid ;
	slim_int	content_class ;

	slim_char *userid;
	slim_char *genre;
} twine_msg_start;


typedef struct {
	slim_char *did;
	slim_char *cid;
	slim_char percent_consumed;
	slim_char *userid;
} twine_msg_finished;

typedef struct {
	slim_char *did;
	slim_char *ua;
  slim_char *type ;
  slim_char *name ;
  slim_char *mac ;
} twine_msg_join;

typedef struct {
	slim_char *did;
	slim_char *ua;
} twine_msg_hello;

typedef struct {
	slim_char *did;
} twine_msg_bye;

typedef struct {
	slim_char *did;
	slim_char *arg;
	slim_char *userid;
} twine_msg_browse;

typedef struct {
	slim_char *did;
	slim_char *name;
	slim_char *userid;
} twine_msg_share;


typedef struct {
	slim_char *did;
	slim_char *id;
	slim_char *arg;
	slim_char *method ;
	slim_char *userid;
} twine_msg_search;


typedef struct {
	slim_char *gid;
	slim_int length;
	slim_char *data;
} twine_msg_tunnel;


typedef struct {
	slim_char *cid;
	slim_char *title;
	slim_int	size ;
	slim_int	duration ;
	slim_int	bitrate ;
	slim_int	width ;
	slim_int	height ;
	slim_char	*mime ;
	slim_char	*parentid ;
	slim_int	content_class ;
	slim_int  protection_type ;
	slim_int  parental_level ;

	slim_char	*thumbnail_url ;
	slim_char	*thumbnail_data ;
	slim_char	*thumbnail_hash ;
	slim_int	thumbnail_size ;
	slim_int	thumbnail_width ;
	slim_int	thumbnail_height ;

	slim_char	*albumart_url ;
	slim_char	*albumart_data ;
	slim_char	*albumart_hash ;
	slim_int	albumart_size ;
	slim_int	albumart_width ;
	slim_int	albumart_height ;

	slim_char	*storage ;
	slim_char *genre ;
} twine_msg_publish_add;


typedef struct {
	slim_char *cid;
	slim_char	*thumbnail_url ;
	slim_char	*thumbnail_data ;
	slim_char	*thumbnail_hash ;
	slim_int	thumbnail_size ;
	slim_int	thumbnail_width ;
	slim_int	thumbnail_height ;

	slim_char	*albumart_url ;
	slim_char	*albumart_data ;
	slim_char	*albumart_hash ;
	slim_int	albumart_size ;
	slim_int	albumart_width ;
	slim_int	albumart_height ;

	slim_char *storage ;	
	slim_char *genre ;

} twine_msg_publish_thumb;

typedef struct {
	slim_char *cid;
	slim_char *storage ;
	slim_int	content_class ;

} twine_msg_publish_delete;

typedef struct {
	slim_char *cid;
} twine_msg_storage_add_del;


typedef struct {
	slim_char *event;	
	slim_char *data;
	slim_int 	ack_required ;
} twine_msg_log;

typedef struct {
	slim_int 	module;	
	slim_char *msg;
} twine_msg_error;


typedef struct {
	slim_char *did;
	slim_char *cid;
	slim_char	*ua ;
	slim_char	*title ;	// just tetntative
	slim_int  playout_limit ;
	slim_char *userid;
} twine_msg_playout_request;

typedef struct {
	slim_char *did;
	slim_char *cid;
	slim_char *ua;
	slim_int	percent_consumed ;
} twine_msg_playout_report;

typedef struct {
	slim_char *did;
	slim_char *cid;
} twine_msg_playout_report_finish;


typedef struct {
	slim_char *updid;
	slim_int status;
} twine_msg_update_applied;

typedef struct {
	slim_char *did;
	slim_char *cid;
	slim_int	position ;
	slim_int	operation ;
	slim_char *userid;
} twine_msg_pause_resumed;

typedef struct {
	slim_char *did;
	slim_char *cid;
	slim_int	from ;
	slim_int	to ;
	slim_char *userid;
} twine_msg_seek;


typedef struct {
	slim_char *did;
	slim_char *cid;
	slim_int	from ;
	slim_int	speed ;
	slim_char *userid;
} twine_msg_ffw;

typedef struct {
	slim_char *did;
	slim_char *cid;
	slim_int	from ;
	slim_int	speed ;
	slim_char *userid;
} twine_msg_rw;


// app only
typedef struct {
	slim_char *did;
	slim_char *cid;
	slim_char	*ua ;
	slim_int	volume ;
	slim_int	direction ;
	slim_int	mute ;
	slim_char *userid;
} twine_msg_volume;

typedef struct {
	slim_char *did;
	slim_char *cid;
	slim_char	*title ;
	slim_char	*ua ;
	slim_int	size ;
	slim_int	duration ;
	slim_int  protection_type ;
	slim_char *userid;
} twine_msg_preview;

typedef struct {
	slim_char *did;
	slim_char *from;
	slim_char	*to ;
	slim_char	*ua ;
	slim_char *userid;
} twine_msg_navigate;

typedef struct {
	slim_char *did;
	slim_char *filter;
	slim_char	*ua ;
	slim_char *userid;
} twine_msg_filter;

typedef struct {
	slim_char *did;
	slim_char *order;
	slim_int	direction ;
	slim_char	*ua ;
	slim_char *userid;
} twine_msg_order;

typedef struct {
	slim_char *did;
	slim_char *ua;
	slim_char *userid;
	slim_char *pwd;
} twine_msg_login;

typedef struct {
	slim_char *did;
	slim_char *ua;
	slim_char *userid;
	slim_char *session_token;
} twine_msg_logout;

typedef struct {
	slim_char *did;
	slim_char *id;
	slim_char *from;
	slim_char *to;
	slim_char *ua;
	slim_char *userid;
} twine_msg_change_settings;

typedef struct {
	slim_char *did;
	slim_char *userid;
} twine_msg_reset_pwd;

typedef struct {
	slim_char *did;
	slim_char *userid;
} twine_msg_user_add_del;

typedef struct {
	slim_char *did;
	slim_char *session_token;  // in case of token auth session_token is not used
	slim_char *friendly_name ;
} twine_msg_create_app;

typedef struct {
	slim_char *target;
} twine_msg_get_ip;

typedef struct {
	slim_char *target;
	slim_char *address;
	slim_char *friendly_name;
	slim_char *uuid;
} twine_msg_set_ip;

typedef struct {
	slim_char *remote_id;
} twine_msg_get_token;

typedef struct {
	slim_char *uid;
	slim_word  permission;
} twine_msg_create_update_friend;

typedef struct {
	slim_char *uid;
} twine_msg_delete_friend;

typedef struct {
	slim_char *uuid;
	slim_char *name;
	slim_char *type;
	slim_char *address;
  slim_char *mac ;
} twine_msg_update;


typedef struct {
	slim_char *evt;
	slim_char *data;
} twine_msg_app_log;

typedef struct {
	slim_char *gid;
} twine_msg_get_properties;

typedef struct {
	slim_char *api;
	slim_char *data;
} twine_msg_extprop;



// downstream

typedef struct {
	slim_int status;
	slim_char *token;
	slim_word permission;
} twine_msg_notify_token;
/*
typedef struct {
	slim_int status;
	slim_char *targets;
} twine_msg_notify_targets;

typedef struct {
	slim_int status;
	slim_char *friends;
} twine_msg_notify_friends;
*/

typedef struct {
	slim_char *did;
	slim_char *mac;
	slim_int mask;
	slim_int parental_rating ;
} twine_dcl;


typedef struct twine_target {
  struct twine_target  *next ;
  struct twine_target  *prev ;
  slim_char *domid ;
  slim_char *gid ;
  slim_char *name ;
  slim_char *uuid ;
  slim_char *addr ;
  slim_char *token ;
  slim_int port ;
  slim_word permission ;
} twine_target_t ;

typedef struct {
  slim_int        status ;
  List( twine_target_t *)targets;
} twine_msg_notify_targets; ;

typedef struct twine_friend {
  struct twine_friend  *next ;
  struct twine_friend  *prev ;
  slim_char *uid ;
  slim_word permission ;
} twine_friend_t ;


typedef struct {
  slim_int        status ;
  List( twine_friend_t *)friends;
}twine_msg_notify_friends; ;



typedef struct {
	slim_char *update_id;
	slim_char *domid;
} notify_register_struct;


typedef struct {
	slim_char *update_id;
	slim_int num_elems;
	twine_dcl *dcl[];
} notify_dcl_struct;

typedef struct {
	slim_char *update_id;
	slim_int	ts ;	
	slim_char	*gid ;
	slim_char *did;
	slim_char *cid;
	slim_char *title;			
	slim_char *ua;
	slim_int 	size;				
	slim_int 	duration;	
} notify_playout_start_struct;

typedef struct {
	slim_char *update_id;
	slim_int	ts ;	
	slim_char	*gid ;
	slim_char *did;
	slim_char *cid;
	slim_char percent_consumed;
} notify_playout_finished_struct;

typedef struct {
	slim_char *update_id;
	slim_char *did;
	slim_char cue_point;
	slim_char *url;
} notify_adprovider_struct;

typedef struct {
	slim_char *update_id;
	slim_char *url;
	slim_int	port ;
} notify_provision_stun_struct;

typedef struct {
	slim_char *update_id;
	slim_char *url;
	slim_int	port ;
} notify_provision_turn_struct;

typedef struct {
	slim_char *update_id;
	slim_char *uid;
	slim_char *pwd;
} notify_provision_turn_cred_struct;

typedef struct {
	slim_char *update_id;
} notify_reset_struct;

typedef struct {
	slim_char *did;
	slim_char *cid;
	slim_int	status ;
} notify_playout_reply_struct ;

typedef struct {
	slim_char *update_id;
	slim_char *url;
} notify_portal_struct;

typedef struct {
  slim_int  status ;
  slim_char *session_token;
} notify_session_token_struct;

typedef struct {
  slim_int  status ;
	slim_char *cert;
	slim_char *key;
	slim_char *ca;
} notify_create_app_struct;

typedef struct {
  slim_int status ;
	slim_char *update_id;
	slim_char *str;
} notify_provison_str_struct;

typedef struct {
  slim_int status ;
	slim_char *update_id;
	slim_int num;
} notify_provison_num_struct;

// update mask
enum twine_update_mask {
	TWINE_UPD_MASK_NONE        = 0x0000,
	TWINE_UPD_MASK_PROVISION   = 0x0001,
	TWINE_UPD_MASK_STARTUP     = 0x0002,
	TWINE_UPD_MASK_BASE_URL    = 0x0004,
	TWINE_UPD_MASK_URLS        = 0x0008,
	TWINE_UPD_MASK_NAME        = 0x0010,
	TWINE_UPD_MASK_TRANSPORT   = 0x0020,
	TWINE_UPD_MASK_APP         = 0x0040
} ;

struct twine_listener_data{
	enum twine_listener_token {
	TWINE_MSG_STATUS = 0,
//	TWINE_MSG_GENERIC_ERROR = 1,					
	TWINE_MSG_POWERUP = 2,
	TWINE_MSG_POWERDOWN = 3,
	TWINE_MSG_BROWSE = 4,
	TWINE_MSG_SEARCH = 5,
	TWINE_MSG_GETDATA = 6,
	TWINE_MSG_FINISH = 7,
	TWINE_MSG_SUBSCRIBE = 8,
	TWINE_MSG_JOIN = 9,
	TWINE_MSG_REGISTER = 10,


	TWINE_MSG_TUNNEL = 11,
	TWINE_MSG_HELLO = 12,
	TWINE_MSG_BYE = 13,
	TWINE_MSG_PROVISION = 14,
	TWINE_MSG_PUBLISH_ADD = 15,
	TWINE_MSG_PUBLISH_DELETE = 16,
	TWINE_MSG_QUERY_TURN_CREDENTIALS = 17,

	TWINE_MSG_LOG = 18,

	TWINE_MSG_PLAYOUT_REQUEST = 19,
	TWINE_MSG_PLAYOUT_REPORT = 20,

	TWINE_MSG_UPDATES_APPLIED = 21,

	TWINE_MSG_PAUSE_RESUME = 22,
	TWINE_MSG_SEEK = 23,
	TWINE_MSG_FFW = 24,
	TWINE_MSG_RW = 25,
// app generated
	TWINE_MSG_VOLUME = 26,
	TWINE_MSG_PREVIEW = 27,
	TWINE_MSG_NAVIGATE = 28,
	TWINE_MSG_FILTER = 29,
	TWINE_MSG_ORDER = 30,
	TWINE_MSG_USER_LOGIN = 31,
	TWINE_MSG_USER_LOGOUT = 32,
	TWINE_MSG_CHANGE_SETTINGS = 33,
	TWINE_MSG_RESET_PASSWORD = 34,
	TWINE_MSG_ADD_USER = 35,
	TWINE_MSG_REMOVE_USER = 36,	
//
	TWINE_MSG_STORAGE_ADD = 37,	
	TWINE_MSG_STORAGE_DEL = 38,	
	TWINE_MSG_PUBLISH_THUMB = 39,	
	TWINE_MSG_CREATE_APP = 40,	

	TWINE_MSG_PLAYOUT_REPORT_FINISH = 41,
	TWINE_MSG_GET_IP = 42,
	TWINE_MSG_SET_IP = 43,
	TWINE_MSG_GET_TARGETS = 44,
	TWINE_MSG_GET_TOKEN = 45,
	TWINE_MSG_GET_FRIENDS = 46,
	TWINE_MSG_CREATE_FRIEND = 47,
	TWINE_MSG_UPDATE_FRIEND = 48,
	TWINE_MSG_DELETE_FRIEND = 49,
	TWINE_MSG_AUTHENTICATE = 50,
	TWINE_MSG_EXTPROP_GET = 51,
	TWINE_MSG_EXTPROP_SET = 52,
	TWINE_MSG_BULK_LOG = 53,

	TWINE_MSG_EVENT_DISCONNECTED = 100,
	TWINE_MSG_EVENT_CONNECTED = 101,
	TWINE_MSG_EVENT_PROVISIONED = 102,

	TWINE_MSG_ERROR_ERROR = 103,					
	TWINE_MSG_ERROR_FATAL = 104,					
	TWINE_MSG_ERROR_DEBUG = 105,					
	TWINE_MSG_ERROR_INFO = 106,					
	TWINE_MSG_ERROR_TRACE = 107,					
	TWINE_MSG_ERROR_WARNING = 108,					
	TWINE_MSG_UPDATE = 109,					
	TWINE_MSG_APP_LOG = 110,					
	TWINE_MSG_GET_PROPERTIES = 111,					
	TWINE_MSG_SHARE = 112,					
	TWINE_MSG_ALIVE = 113,					

	TWINE_MSG_NOTIFY_REGISTER = 254,
	TWINE_MSG_NOTIFY_DCL = 253,
	TWINE_MSG_NOTIFY_PLAYOUT_START = 252,
	TWINE_MSG_NOTIFY_PLAYOUT_FINISH = 251,
	TWINE_MSG_NOTIFY_PROVISION_SESSION_LIMIT = 250,
	TWINE_MSG_NOTIFY_PROVISION_LOGFILTER = 249,
	TWINE_MSG_NOTIFY_PROVISION_ADPROVIDER = 248,
	TWINE_MSG_NOTIFY_CONTENT_PUBLISH = 247,
	TWINE_MSG_NOTIFY_CONTENT_REMOVE = 246,


	TWINE_MSG_NOTIFY_TUNNEL = 245,
	TWINE_MSG_NOTIFY_TUNNEL_STATUS = 244,

	TWINE_MSG_NOTIFY_PROVISION_STUN = 243,
	TWINE_MSG_NOTIFY_PROVISION_TURN = 242,
	TWINE_MSG_NOTIFY_PROVISION_TURN_CREDENTIALS = 241,
	TWINE_MSG_NOTIFY_RESET = 240,
	TWINE_MSG_NOTIFY_PROVISION_PORTAL = 239,
	TWINE_MSG_NOTIFY_PROVISION_UPDATE_INTERVAL = 238,

	TWINE_MSG_NOTIFY_PROVISION_ACTIVE = 237,

	TWINE_MSG_NOTIFY_PLAYOUT_REPLY = 236,
	TWINE_MSG_NOTIFY_SESSION_TOKEN = 235,
	TWINE_MSG_NOTIFY_CREATE_APP = 234,
	TWINE_MSG_NOTIFY_PROVISION_FRIENDLY_NAME = 233,

	TWINE_MSG_NOTIFY_PROVISION_TRCS_URL = 232,
	TWINE_MSG_NOTIFY_PROVISION_TLS_URL = 231,
	TWINE_MSG_NOTIFY_PROVISION_TGS_URL = 230,
	TWINE_MSG_NOTIFY_PROVISION_TCGS_URL = 229,
	TWINE_MSG_NOTIFY_PROVISION_TCUS_URL = 228,

	TWINE_MSG_NOTIFY_PROVISION_RA = 227,
	TWINE_MSG_NOTIFY_PROVISION_REPORT_INTERVAL = 226,
	TWINE_MSG_NOTIFY_PROVISION_REQUEST_TIMEOUT = 225,
	
	TWINE_MSG_NOTIFY_3RD_PARTY = 224 ,
	TWINE_MSG_NOTIFY_PROVISION_STARTUP_DELAY = 223, 
	TWINE_MSG_NOTIFY_PROVISION_PUBLIC_IP = 222,
	TWINE_MSG_NOTIFY_PROVISION_DOMID = 221,
	TWINE_MSG_NOTIFY_PROVISION_GID = 220,
	TWINE_MSG_NOTIFY_PROVISION_AUTH_TOKEN = 219,
	TWINE_MSG_NOTIFY_TARGETS = 218,
	TWINE_MSG_NOTIFY_PROVISION_RID = 217, 
	TWINE_MSG_NOTIFY_TOKEN = 216,
	TWINE_MSG_NOTIFY_FRIENDS = 215,
	TWINE_MSG_NOTIFY_CREATE_FRIEND = 214,
	TWINE_MSG_NOTIFY_UPDATE_FRIEND = 213,
	TWINE_MSG_NOTIFY_DELETE_FRIEND = 212,
	TWINE_MSG_NOTIFY_CONNECT = 211,
	TWINE_MSG_NOTIFY_DISCONNECT = 210,
	TWINE_EVT_NOTIFY_UPDATE = 209,
	TWINE_EVT_NOTIFY_UPDATE_ID = 208,
	TWINE_EVT_NOTIFY_INITIALIZED = 207,
	TWINE_EVT_NOTIFY_FINALIZED = 206,
	TWINE_MSG_NOTIFY_PROPERTIES = 205,
	TWINE_MSG_NOTIFY_SHARE = 204,
	TWINE_MSG_NOTIFY_DEFAULT_TARGETS = 203,
	TWINE_MSG_NOTIFY_AUTHENTICATE = 202,
	TWINE_MSG_NOTIFY_EXTPROP_GET = 201,
	TWINE_MSG_NOTIFY_EXTPROP_SET = 200,
	TWINE_MSG_NOTIFY_DEFAULT_FRIENDS = 199,
  TWINE_EVT_PROVISION_REQUIRED = 198,
  TWINE_EVT_AUTH_REQUIRED = 197



	}token  ;

  void *callback ;
  void *callback_arg ;

	union{
		// upstream
		twine_msg_powerup 	powerup;
		twine_msg_powerdown powerdown;
		twine_msg_register 	register_gateway;
		twine_msg_subscribe	subscribe ;
		twine_msg_join		  join;

		twine_msg_start			start ;
	 	twine_msg_finished	finish;
		twine_msg_browse		browse;
		twine_msg_share		  share;
		twine_msg_search		search;

		twine_msg_hello							hello;
		twine_msg_bye								bye;
		twine_msg_publish_add				publish_add;
		twine_msg_publish_delete		publish_delete;
		twine_msg_publish_thumb			publish_thumb;

		twine_msg_log								log;
		twine_msg_playout_request		play_request;
		twine_msg_playout_report		play_report;
		twine_msg_playout_report_finish		report_finish;

		twine_msg_update_applied  	update_applied;

		twine_msg_pause_resumed		pause_resume;
	 	twine_msg_seek						seek ;
 		twine_msg_ffw							ffw ;
		twine_msg_rw							rw ;


// app only
 		twine_msg_volume					volume;
 		twine_msg_preview					preview;
 		twine_msg_navigate				navigate;
 		twine_msg_filter					filter;
 		twine_msg_order						order;
 		twine_msg_login						login;
 		twine_msg_logout					logout;
 		twine_msg_change_settings change_settings;
 		twine_msg_reset_pwd 			reset_pwd;
 		twine_msg_user_add_del 		user_add_del;
		twine_msg_storage_add_del	storage_add_del;
		twine_msg_create_app			create_app;
		twine_msg_error						error ;
		twine_msg_get_ip					get_ip;
        twine_msg_set_ip					set_ip;	
        twine_msg_get_token			  get_token;	
        twine_msg_create_update_friend  create_update_friend;
        twine_msg_delete_friend         delete_friend ;
         twine_msg_update          update ;
  twine_msg_app_log            app_log ;
  twine_msg_get_properties       get_properties;
  twine_msg_extprop           extprop;

		//downstream
		notify_register_struct notify_register;
		notify_playout_start_struct notify_start;
		notify_playout_finished_struct notify_finished;
	//	notify_session_limit_struct notify_limit;
//		notify_logfilter_struct notify_logfilter;
		notify_adprovider_struct notify_adprovider;
		notify_dcl_struct notify_dcl;
//		reply_provision_struct	provision ;	
		notify_provision_stun_struct notify_stun;
		notify_provision_turn_struct	notify_turn ;
		notify_provision_turn_cred_struct notify_turn_credentials ;
	 	notify_reset_struct notify_reset ;


//	 	notify_active_struct notify_active ;
//		notify_portal_struct notify_portal;

//		notify_update_interval_struct notify_update_interval;
		notify_playout_reply_struct		notify_playout_reply;
		notify_session_token_struct		notify_session_token;
		notify_create_app_struct			notify_create_app;
//		notify_provison_friendly_name_struct	notify_friendly_name;

		notify_provison_str_struct		notify_str;
		notify_provison_num_struct		notify_num;

    twine_msg_notify_token    notify_token;
    twine_msg_notify_targets  notify_targets;
    twine_msg_notify_friends  notify_friends;


		// bi-directional		
		twine_msg_tunnel		tunnel ;
		status_struct status ;
	}data ;
} ;



struct twine_listener
{
	struct twine_listener *next;
	struct twine_listener *prev;
	TTWINEListenerCallback	callback ;
	void	*context ;
} ;

typedef slim_int (*TRAListenerCallback)( void *context, slim_char *source, slim_char *action, slim_int stream_id, slim_char *data ) ;

struct twine_ra_listener
{
	struct twine_ra_listener *next;
	struct twine_ra_listener *prev;
	TRAListenerCallback	callback ;
	void	*context ;
	slim_char *msg ;
} ;


//



#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void*
twine_transport_manager_alloc( void *top, dlna_progress	em, slim_int has_signaling, slim_char *config_dir, slim_char *twine_path) ;
void
twine_transport_manager_free( void *context) ;
slim_int
twine_transport_manager_start (void *ctx) ;
slim_int
twine_transport_manager_stop (void *ctx) ;

void*
twine_transport_manager_get_instance() ;

void
twine_transport_manager_set_logfilter( void *context, slim_int filter) ;
slim_int
twine_transport_manager_add_listener(void *context, void *listener, void *ctx) ;
slim_int
twine_transport_manager_remove_listener(void *context, void *listener) ;
slim_int
twine_transport_manager_submit(void *context,struct twine_listener_data *data) ;

// RA support
void
twine_transport_manager_signaling_start(void *context) ;
void
twine_transport_manager_signaling_stop(void *context) ;
void
dlna_hex_sprintf(slim_char* buf, slim_char* data, slim_int len);

slim_int
twine_transport_manager_signaling_register_callback(void *ctx, TRAListenerCallback cb, void *context, slim_char *msg);
slim_int
twine_transport_manager_signaling_unregister_callback(void *ctx, slim_char *msg);
slim_int
twine_transport_manager_signaling_submit(void *context, slim_char *target, slim_char *msg);

slim_int
twine_transport_manager_send (void *ctx, struct twine_listener_data * data, void	*in_cb, void *in_context);

slim_int
twine_transport_manager_set_auth (void *ctx, slim_int auth_type, slim_char *uid,  slim_char *pwd ,  slim_char *cookie ) ;

slim_int
twine_transport_manager_start (void *ctx) ;

slim_int
twine_transport_manager_stop (void *ctx) ;

slim_int
twine_transport_set_startup_delay (void *ctx, slim_int delay) ;

slim_int
twine_transport_set_update_delay (void *ctx, slim_int delay) ;

slim_int
twine_transport_set_forward_delay (void *ctx, slim_int delay) ;

void
twine_transport_set_tgs_url( void *ctx, slim_char *url) ;
void
twine_transport_set_tls_url( void *ctx, slim_char *url) ;
void
twine_transport_set_tcgs_url( void *ctx, slim_char *url) ;
void
twine_transport_set_tcus_url( void *ctx, slim_char *url) ;
void
twine_transport_set_trcs_url( void *ctx, slim_char *url) ;

slim_int
twine_transport_manager_is_running (void *ctx) ;


#ifdef __cplusplus
}
#endif /* __cplusplus */




#endif /* DMS_TWINE_TRANSPORT_MANAGER_H */
