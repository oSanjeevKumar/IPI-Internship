/*
* rata_backend.h
* Copyright (C) 2015 ACCESS CO.,LTD.
* All rights are reserved by ACCESS CO.,LTD.,
* whether the whole or part of the source code
* including any modifications is concerned.
*
* This is an unpublished source code of ACCESS CO.,LTD., and must be
* treated as confidential material.  The above copyright notice does
* not evidence any actual or intended publication of this source code.
*/

#ifndef RATA_BACKEND_H
#define RATA_BACKEND_H

#include <nflc_ra_def.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef enum RAPermission_ {
// xxxxx   xxxxxxxxxxxxxxx   xxxx
// group   exclusive group    pg
  RA_PERMISSION_NONE   = 0,
  RA_PERMISSION_GUEST  = 0x00000000,
  RA_PERMISSION_ALIEN  = 0x10000000,
  RA_PERMISSION_FRIEND = 0x20000000,
  RA_PERMISSION_FAMILY = 0x40000000,
  RA_PERMISSION_OWNER  = 0x8000000f,
  RA_PERMISSION_ALL    = 0xffffffff
} RAPermission;

/* Callback function of application */
typedef slim_int (*rataBackendCallbackHandler) (raEvent in_event, void * in_arg,  void *in_param);

typedef struct {
	slim_int status;
	slim_char *token;
	slim_word permission;
} rata_backend_notify_token_t;

struct _rata ;

struct rata_backend
{
  void *top;
  void *impl ;
  rataBackendCallbackHandler callback;  //Callback function to inform application layer
  void *callbackArg;                   //Argument specified by application layer that is used to call callback function
   
	/* Member functions.  */
  slim_int (*alloc) (struct _rata *rata) ;
  slim_int (*free) (struct _rata *rata);
  slim_int (*start) (struct _rata *rata);
  slim_int (*stop) (struct _rata *rata);


  slim_int (*set_public_ip) (struct _rata *rata, slim_char *address, slim_char *uuid, slim_char *friendly_name) ;

  slim_int (*set_properties) (struct _rata *rata, slim_char *address, slim_char *uuid, slim_char *name, slim_char *type, slim_char *mac) ;
  slim_int (*get_token) (struct _rata *rata, slim_char *remote_id, void *cb, void *arg);

  slim_int (*provision) ( struct _rata *rata, slim_char *uid, slim_char *pwd, slim_char *serial) ;
  slim_int (*authenticate) ( struct _rata *rata, slim_char *serial, slim_char *token, slim_char *cookie) ;

  slim_int (*get_targets) ( struct _rata *rata, slim_char *uid, slim_char *pwd) ;


  slim_int (*get_friends) ( struct _rata *rata) ;
  slim_int (*create_friend) ( struct _rata *rata, slim_char *uid, slim_word permission) ;
  slim_int (*update_friend) ( struct _rata *rata, slim_char *uid, slim_word permission) ;
  slim_int (*delete_friend) ( struct _rata *rata, slim_char *uid) ;

  slim_int (*app_log) (struct _rata *rata, slim_char *in_evt, slim_char *in_data) ;

  slim_int (*log) ( struct _rata *rata, slim_int module, slim_int level, slim_int status) ;

  slim_int (*set_url) ( struct _rata *rata, slim_char *in_url) ;
  slim_int (*get_url) ( struct _rata *rata, slim_char **out_url) ;

  slim_int (*get_properties) ( struct _rata *rata, slim_char *gid) ;


  slim_int (*log_device) (struct _rata *rata, slim_char *type, slim_char *id, slim_char *name, slim_char *ua, slim_char *mac, slim_int event) ;
  slim_int (*log_alive) (struct _rata *rata, slim_char *data) ;

  slim_int (*share) (struct _rata *rata, slim_char *name, slim_char *uid) ;

  slim_int (*extprop_get) (struct _rata *rata, slim_char *api_name) ;
  slim_int (*extprop_set) (struct _rata *rata, slim_char *api_name, slim_char *data) ;

};

slim_int
rata_backend_setup(struct _rata *rata, rataBackendCallbackHandler callback,  void *callbackArg) ;

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif // #ifdef RATA_BACKEND

