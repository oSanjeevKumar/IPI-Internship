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

#ifndef TWINE_TRANSPORT_MANAGER_IMPL_H
#define TWINE_TRANSPORT_MANAGER_IMPL_H


#define	TWINE_TRANSPORT_DEFAULT_TRCS_URL 	"rjil.accesstwine.com:7681"
#define	TWINE_TRANSPORT_DEFAULT_TLS_URL		"rjil.accesstwine.com:5001"
#define	TWINE_TRANSPORT_DEFAULT_TGS_URL 	"rjil.accesstwine.com:5002"
#define	TWINE_TRANSPORT_DEFAULT_TCGS_URL 	"rjil.accesstwine.com:5006"
#define	TWINE_TRANSPORT_DEFAULT_TCUS_URL 	"rjil.accesstwine.com:5004"


#define	TWINE_TRANSPORT_DEFAULT_MAX_LOGS  1000
#define	TWINE_TRANSPORT_DEFAULT_LOGS_DELAY  10
#define	TWINE_TRANSPORT_DEFAULT_MAX_LOGS_BUNDLE  10
#define	TWINE_TRANSPORT_DEFAULT_FLUSH_LOGS_THRESHOLD  10


struct bulk_logs_id {
  struct bulk_logs_id  *next ;
  struct bulk_logs_id  *prev ;
  slim_int seq_number ;
} ;

struct twine_transport{
	void	*ws_context ;			// hook to ws
  List( struct twine_listener *)twine_listeners ;
  List( struct twine_ra_listener *)ra_callback ;

	dlna_thread transport_thread ; 
	slim_int	shutdown ;
	slim_int	isRunning;

	dlna_progress	em ;
	dlna_progress_handle startup_timer;
	dlna_progress_handle read_db_progress;
	dlna_progress_handle connect_progress;
	dlna_progress_handle update_progress;
	dlna_mutex	db_mutex ;
	dlna_mutex	db_scheduler_mutex ;
	dlna_mutex	send_mutex ;
	dlna_db_handle dbhandle ;

//	slim_char 	*logs_db_path ;
	void *top ;
	slim_int	use_ssl;
	slim_int sequence_number;

	enum {
		TWINE_TRANSPORT_STATE_IDLE = 0,
		TWINE_TRANSPORT_STATE_WAIT_FOR_ACK,
		TWINE_TRANSPORT_STATE_PENDING_NOTIFY
	} transport_state;

	enum {
		TWINE_TRANSPORT_STATE_CONNECTING,
		TWINE_TRANSPORT_STATE_CONNECTED,
		TWINE_TRANSPORT_STATE_DISCONNECTING,
		TWINE_TRANSPORT_STATE_DISCONNECTED	
	} connection_state;
/*
	enum {
		TWINE_TRANSPORT_STATE_PROVISIONING,
		TWINE_TRANSPORT_STATE_PROVISIONING_CONNECT,
		TWINE_TRANSPORT_STATE_PROVISIONED
	} provisioning_state;
*/
	dlna_thread read_db_thread_id ; 
	dlna_mutex	mutex_read_db ;
	dlna_conditional_variable cv_read_db ;
	slim_int db_thread_busy ;
	slim_int db_thread_sending ;

	slim_char	*trcs_url ;					// ws base url 
	slim_int	ws_port ;

	slim_char *tls_url ;			
	slim_char *tgs_url ;			
	slim_char *tcgs_url ;			
	slim_char *tcus_url ;			

	slim_int filter ;
	slim_int has_signaling ;

	slim_char *key_file ;
	slim_char *cert_file ;
	slim_char *ca_file ;
	slim_char	*certs_path ;
  slim_char *config_dir ;
  struct sbuf sauth ;

  slim_int startup_delay ;
  slim_int update_delay ;
  slim_int fl_is_startup ;
  slim_int fl_is_provisioned ;
  slim_int update_mask ;
  slim_int timeout ;

  slim_int logs_max_num ;
  slim_int logs_num ;

  // bulk handling
  slim_int forward_delay ;
  slim_int bulk_logs_max_num ;
  slim_int bulk_logs_num ;
  slim_int bulk_logs_flush_num ;
  struct sbuf slogs ;

  List( struct bulk_logs_id *) bulk_logs_ids;

} ;



#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* DMS_TWINE_TRANSPORT_MANAGER_IMPL_H */
