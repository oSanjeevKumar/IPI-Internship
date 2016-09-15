/*
 * proxy.h
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


#ifndef _PROXY_H
#define _PROXY_H

#define RATA_PROXY_STACK_SIZE 64*1024
#define RATA_PROXY_BUF_SIZE 256*1024

#define RATA_PROXY_CONNECT_SLEEP 50*1000
#define RATA_PROXY_CONNECT_MAX_RETRY 200

#define RATA_PROXY_HEADER_SIZE 15


#define RATA_CHANNEL_TYPE_CONNECT_CLIENT 0
#define RATA_CHANNEL_TYPE_CONNECT_SERVER 1
#define RATA_CHANNEL_TYPE_LISTEN_CLIENT 2
#define RATA_CHANNEL_TYPE_LISTEN_SERVER 3


#define RATA_PARSE_TYPE_NONE 0
#define RATA_PARSE_TYPE_BROWSE 1
#define RATA_PARSE_TYPE_SUBSCRIBE 2
#define RATA_PARSE_TYPE_SETAVT 3
#define RATA_PARSE_TYPE_CREATEURIJOB 4
#define RATA_PARSE_TYPE_UNSUBSCRIBE 5
#define RATA_PARSE_TYPE_GETMEDIAINFO 6
#define RATA_PARSE_TYPE_SETNEXTAVT 7
#define RATA_PARSE_TYPE_GETPOSITIONINFO 8
#define RATA_PARSE_TYPE_PRINTDATA 9
#define RATA_PARSE_TYPE_GETDD 10
#define RATA_PARSE_TYPE_PRINT_REQUEST 11
#define RATA_PARSE_TYPE_WEB_UI 12
#define RATA_PARSE_TYPE_GENA 13
#define RATA_PARSE_TYPE_CREATEOBJECT 14


// failed attemps due to wrong encryption, to tale preventive action
#define PROXY_FAILED_ATTEMPS_THRESHOLD 3
// clear "intrudor" from list until xx seconds
#define PROXY_FAILED_ATTEMPS_CLEAR_THRESHOLD 120

typedef enum _proxy_parse_state {
  RATA_PARSE_STATE_IDLE = 0,
  RATA_PARSE_STATE_HEADER = 1,
  RATA_PARSE_STATE_BODY = 2, 
  RATA_PARSE_STATE_DONE = 3 
 
} proxy_parse_state ;


// we limit the strstr to a max. it should conver the expected header length
#define ALG_MAX_PARSE_LEN 512


struct  proxy_crypt_ctx {
  slim_char *key ;
  slim_char *iv ;
  void	*crypto ;
} ;

struct	proxy_parser {
  struct sbuf	sb ;
  slim_int size ;
  slim_int received;
  slim_int content_length;
  slim_int state;

  slim_int fl_rid_header_injected;
  slim_int fl_is_chunked ;
  slim_char *p_end_of_header ;
  slim_char *p_chunk ;
  struct sbuf	sbtemp ;

} ;

struct	proxy_session {
  struct proxy_session  *next ;
  struct proxy_session  *prev ;

  struct proxy_channel  *channel ;

  slim_int len ;
  slim_char *buf ;

  slim_int	channel_sock ;
  slim_int	local_sock ;

  dlna_ip_addr client_addr;
  slim_int	client_port ;

  dlna_ip_addr local_addr;
  slim_int	local_port ;

  dlna_ip_addr channel_addr;
  slim_int	channel_port ;

  dlna_ip_addr src_addr;
  slim_int	src_port ;
  dlna_ip_addr dst_addr;
  slim_int	dst_port ;

  dlna_thread thread_id ; 
  dlna_thread channel_thread_id ; 
  slim_int	parse_type ;

  slim_int	client_sock ;
  slim_int	shutdown ;
  struct proxy_parser	request_parser ;
  struct proxy_parser	reply_parser ;
  slim_int received ;
  struct proxy_channel  *sub_channel ; // temp reference to the subscription channel  
  slim_int channel_receiver_is_running ;

} ;	

struct	proxy_subscription {
  struct proxy_subscription  *next ;
  struct proxy_subscription  *prev ;
  slim_char *sub_uuid ;
} ;

struct	proxy_channel {
  struct proxy_channel  *next ;
  struct proxy_channel  *prev ;
	
  slim_int	listen_sock ;
  slim_int	dst_sock ;
  slim_int	src_sock ;
  slim_int	dst_listen_sock ;	// for outbound

  slim_int	channel_sock ;

  dlna_ip_addr src_addr;
  dlna_ip_addr dst_addr;
  slim_int	src_port ;
  slim_int	dst_port ;

  dlna_ip_addr	proxy_addr;
  slim_int	proxy_port ;

  dlna_ip_addr channel_addr;
  slim_int	channel_port ;

  dlna_ip_addr client_addr;
  slim_int	client_port ;
  slim_char	*remote_uuid ;

  dlna_thread src_channel_receive_thread_id ; 
  dlna_thread dst_channel_receive_thread_id ; 
  dlna_thread listen_thread_id ; 

  struct _proxy *proxy ;
  slim_int len ;
  slim_char *buf ;

  List( struct proxy_session *)sessions ;
  dlna_mutex	session_list_mutex ;

  slim_int type ;	// listening or connecting channel
  slim_int	shutdown ;

  dlna_mutex	mutex ;
  slim_int busy ;
  struct  proxy_crypt_ctx crypt_ctx ;

  List( struct proxy_subscription *)subscriptions ;
  dlna_mutex	subscription_mutex ;
  slim_int fl_is_subscription_channel ;
  slim_int fl_is_print_data_channel ;

  slim_word permission ;
} ;

struct	proxy_device {
  struct proxy_device  *next ;
  struct proxy_device  *prev ;
  dlna_ip_addr addr ;
  slim_int port ;
  slim_char *dd ;
};

struct	proxy_abnormal_device {
  struct proxy_abnormal_device  *next ;
  struct proxy_abnormal_device  *prev ;
  dlna_ip_addr addr ;
  slim_int ports[PROXY_FAILED_ATTEMPS_THRESHOLD+1] ;
  slim_int count ;
  dlna_time_t	first_time ;
  dlna_time_t	last_time ;
};

struct	_proxy {
  struct _rata 	*rata ;
  dlna_ip_addr	addr;				// my ip
  slim_int	port;			// RAS master port
  slim_int	port_min;	// client ports min
  slim_int 	port_max;	// client ports max
  slim_char	*netif;		// the wan interface nic
  slim_int	listen_sock ;
  dlna_thread listen_thread_id;
  dlna_ip_addr public_addr;
  slim_int public_port ;

  List( struct proxy_channel *) channels;
  slim_int shutdown;

  List( struct proxy_device *)devices;
  dlna_mutex conchan_setup_mutex;
  dlna_mutex listenchan_setup_mutex;
  dlna_mutex channel_list_mutex ;
  slim_int master_thread_is_running;

  dlna_mutex	channel_remover_mutex ;

  dlna_mutex	con_discon_mutex;

  List( struct proxy_pending_connects *) pending_connects;
  dlna_mutex	pending_connects_mutex;


  List( struct proxy_abnormal_device *)abnormal_devices;
  dlna_progress abnormal_device_check_timer ;

};

struct proxy_pending_connects
{
  struct proxy_pending_connects *next;
  struct proxy_pending_connects *prev;
  slim_char *uuid ;
  slim_int sock ;
  slim_int fl_cancel ;
  slim_int fl_timeout ;
  struct	_proxy *proxy ;

  dlna_progress_handle pending_timer;

};


typedef List( struct proxy_session *) proxy_sessions_t ;
typedef List( struct proxy_channel *) proxy_channels_t ;
typedef List( struct proxy_device *) proxy_devices_t ;



#ifdef __cplusplus

extern "C" {
#endif /* __cplusplus */


struct _proxy *
proxy_alloc (struct _rata *rata) ;
void
proxy_free (struct _proxy * proxy);

slim_int
proxy_start (struct _proxy * proxy) ;
slim_int
proxy_stop (struct _proxy * proxy) ;
slim_int
proxy_parse_ip( slim_char *in_buf, dlna_ip_addr *addr, slim_int *port ) ;


slim_int		
proxy_conchan_client_add (struct _proxy *proxy,  dlna_ip_addr *dst_addr, slim_int dst_port ,dlna_ip_addr *proxy_addr, slim_int *proxy_port, slim_char *uuid) ;
slim_int		
proxy_conchan_srv_add (struct _proxy *proxy,  dlna_ip_addr *dst_addr, slim_int dst_port, slim_int sock, struct  proxy_crypt_ctx *crypt_ctx, dlna_ip_addr *client_addr, slim_char *uuid) ;
void
proxy_conchan_src_channel_free(struct proxy_channel *channel);

slim_int
proxy_listenchan_client_add (struct _proxy *proxy,  dlna_ip_addr *src_addr, slim_int src_port,  dlna_ip_addr *proxy_addr, slim_int *proxy_port, slim_char *uuid, struct proxy_channel **out_channel) ;

slim_int
proxy_listenchannel_srv_add (struct _proxy *proxy, dlna_ip_addr *src_addr, slim_int src_port, slim_int *proxy_port, slim_int sock, struct  proxy_crypt_ctx *crypt_ctx, dlna_ip_addr *client_addr, slim_char *uuid) ;


struct proxy_channel *
proxy_channel_get_src_channel (struct _proxy *proxy, dlna_ip_addr *src_addr, slim_int src_port ) ;

struct proxy_channel *
proxy_channel_get_dst_channel (struct _proxy *proxy, dlna_ip_addr *dst_addr, slim_int dst_port ) ;

struct proxy_channel *
proxy_channel_get_src_channel_for_uuid (struct _proxy *proxy, dlna_ip_addr * src_addr, slim_int src_port, slim_char *uuid) ;

struct proxy_channel *
proxy_channel_get_dst_channel_for_uuid (struct _proxy *proxy, dlna_ip_addr * dst_addr, slim_int dst_port, slim_char *uuid) ;

slim_int 
proxy_channel_get_dst_mapping (struct _proxy *proxy, dlna_ip_addr *dst_addr, slim_int dst_port , dlna_ip_addr *proxy_addr, slim_int *proxy_port ) ;

slim_int 
proxy_channel_get_src_mapping (struct _proxy *proxy, dlna_ip_addr *src_addr, slim_int src_port , dlna_ip_addr *proxy_addr, slim_int *proxy_port ) ;

slim_int 
proxy_channel_get_proxy_mapping (struct _proxy *proxy, dlna_ip_addr *src_addr, slim_int src_port , dlna_ip_addr *proxy_addr, slim_int *proxy_port ) ;

slim_int 
proxy_channel_get_local_proxy_mapping (struct _proxy *proxy, dlna_ip_addr *src_addr, slim_int src_port , dlna_ip_addr *proxy_addr, slim_int *proxy_port ) ;

struct proxy_session *
proxy_channel_get_session_from_client_sock (struct proxy_channel *channel, slim_int client_sock) ;

slim_int
proxy_channel_subscription_add (struct proxy_channel *channel, slim_char *sub_uuid) ;
slim_int
proxy_channel_subscription_remove (struct proxy_channel *channel, slim_char *sub_uuid) ;
slim_int
proxy_channel_subscription_remove_all (struct proxy_channel *channel) ;
slim_int
proxy_channel_get_subscription_count (struct proxy_channel *channel) ;
struct proxy_channel *
proxy_channel_get_subscription_channel (struct _proxy *proxy, slim_char *sub_uuid) ;


slim_int 
proxy_remove_channels (struct _proxy *proxy, slim_char *uuid ) ;

slim_int 
proxy_remove_rada_channel (struct _proxy *proxy, slim_char *uuid ) ;

slim_int
proxy_handshake_connect_client(struct proxy_session *session);
slim_int
proxy_handshake_listen_client(struct proxy_channel *channel);

slim_int
proxy_handshake_register_client (struct _rata * rata, slim_char **ras_uuid, slim_char **iv, dlna_ip_addr *addr, slim_int port , slim_char *in_uuid) ;


slim_int
proxy_channel_list_lock(struct _proxy * proxy) ;
slim_int
proxy_channel_list_unlock(struct _proxy * proxy) ;

slim_int
proxy_session_list_lock(struct proxy_channel *channel) ;
slim_int
proxy_session_list_unlock(struct proxy_channel *channel) ;

slim_int
proxy_channel_is_same_address( dlna_ip_addr *src_addr, slim_int src_port, dlna_ip_addr *dst_addr, slim_int dst_port );
slim_int
proxy_channel_aquire (struct proxy_channel *channel);
slim_int
proxy_channel_release (struct proxy_channel *channel);
slim_int
proxy_shutdown_sessions (struct proxy_channel *channel);
slim_int
proxy_wait_sessions_shutdown (struct proxy_channel *channel);
slim_int
proxy_channel_remove (struct proxy_channel *channel);
slim_int
proxy_session_remove (struct proxy_session *session);
slim_int
proxy_channel_send(slim_int sock, slim_char *buf, slim_int len,  struct  proxy_crypt_ctx *crypt_ctx);
slim_int
proxy_local_send(slim_int sock, slim_char *buf, slim_int len);


slim_int
proxy_stream_parser_init (struct proxy_session * session) ;
slim_int
proxy_stream_parse_conchan_reply (struct proxy_session * session, slim_char ** buf,
                     slim_char * in_buf, slim_int received, slim_int * mapped) ;
slim_int
proxy_stream_parse_conchan_request (struct proxy_session * session, slim_char ** buf,
                     slim_char * in_buf, slim_int received, slim_int * mapped) ;
slim_int
proxy_stream_parse_lichan_reply (struct proxy_session * session, slim_char ** buf,
                     slim_char * in_buf, slim_int received, slim_int * mapped) ;
slim_int
proxy_stream_parse_lichan_request (struct proxy_session * session, slim_char ** buf,
                     slim_char * in_buf, slim_int received, slim_int * mapped) ;

slim_int
proxy_get_free_port (slim_int sock, dlna_ip_addr * in_addr, slim_int port, slim_int port_max, slim_int *out_port);



// proxy encrypt
slim_int 
proxy_crypt_set_key( struct  proxy_crypt_ctx *crypt_ctx,  slim_char *key, slim_char *iv) ;
slim_int 
proxy_crypt_release_key( struct  proxy_crypt_ctx *crypt_ctx) ;
slim_int
proxy_crypt_iv_generate( slim_char *iv) ;
slim_int
proxy_crypt_iv_rotate( struct  proxy_crypt_ctx *crypt_ctx) ;

slim_int
proxy_obfuscate_key( slim_char *key) ;

slim_int
proxy_encrypt( slim_char *in_buf, slim_int in_size, slim_char **out_buf, slim_int *out_size,  struct  proxy_crypt_ctx *crypt_ctx);
slim_int
proxy_decrypt( slim_char *in_buf, slim_int in_size, slim_char **out_buf, slim_int *out_size,  struct  proxy_crypt_ctx *crypt_ctx);

//proxy security
slim_int
proxy_device_register (struct _proxy * proxy, dlna_ip_addr *addr, slim_int port, slim_char *dd) ;
slim_int
proxy_device_unregister (struct _proxy * proxy, dlna_ip_addr *addr, slim_int port) ;
slim_int
proxy_device_is_registered (struct _proxy * proxy, dlna_ip_addr *addr, slim_int port) ;
slim_int 
proxy_device_remove_all(struct _proxy *proxy) ;

slim_int
proxy_hash_token(slim_char *token, slim_char *hash) ;


slim_int
proxy_add_pending(struct _proxy * proxy, slim_char *target) ;
slim_int
proxy_remove_pending(struct _proxy * proxy, slim_char *target) ;
slim_int
proxy_remove_all_pending(struct _proxy * proxy) ;
slim_int
proxy_is_pending_canceled(struct _proxy * proxy, slim_char *target) ;
slim_int
proxy_is_pending_timeout(struct _proxy * proxy, slim_char *target) ;

struct proxy_pending_connects *
proxy_get_pending(struct _proxy *proxy, slim_char *target) ;
 
slim_int
proxy_cancel (struct _proxy *proxy, slim_char *target)  ;


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _PROXY_H */
