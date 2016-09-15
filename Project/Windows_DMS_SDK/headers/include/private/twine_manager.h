/*
 * twine_manager.h
 * Copyright (C) 2007-2015 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */

/* Twine manager.  */

#ifndef TWINE_MANAGER_H
#define TWINE_MANAGER_H

#include <twine_transport_manager.h>


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

//typedef slim_int (*TTwineManagerUpdateCb)(struct twine_listener_data *data, void *arg) ;

#define CLIENT_CERT_FILE "/certs/client.pem"

void*
twine_manager_alloc( void *top, dlna_progress em, slim_char *config_dir, slim_char *twine_path);
void
twine_manager_free( void *ctx);
slim_int
twine_manager_start (void *ctx);
slim_int
twine_manager_stop (void *ctx);

void*
twine_manager_get_transport(void *ctx);
slim_int
twine_manager_log_error(void *ctx, slim_int module, slim_int severity, slim_char *msg);
slim_int
twine_manager_log(void *ctx, slim_char *event, slim_char *event_data, slim_int ack_required );
slim_int
twine_manager_submit(void *context, struct twine_listener_data *data);
slim_int
twine_manager_send(void *context, struct twine_listener_data *data,	 TTWINEListenerCallback in_cb, void *in_context);
slim_int
twine_manager_register_update_callback(void *ctx,TTWINEListenerCallback cb,void *arg);
slim_int
twine_manager_unregister_update_callback(void *ctx) ;
slim_int
twine_manager_set_auth (void *ctx, slim_int auth_type, slim_char *uid,  slim_char *pwd ,  slim_char *cookie ) ;

slim_int
twine_manager_start (void *ctx) ;

slim_int
twine_manager_stop (void *ctx) ;


#ifdef __cplusplus
}
#endif /* __cplusplus */




#endif /* DMS_TWINE_MANAGER_H */
