/*
* nflc_ra_def.h
* Copyright (C) 2016 ACCESS CO.,LTD.
* All rights are reserved by ACCESS CO.,LTD.,
* whether the whole or part of the source code
* including any modifications is concerned.
*
* This is an unpublished source code of ACCESS CO.,LTD., and must be
* treated as confidential material.  The above copyright notice does
* not evidence any actual or intended publication of this source code.
*/

#ifndef NFLC_RA_DEF_H
#define NFLC_RA_DEF_H

#define RA_SUCCESS  0

/* UI callback function type.  */
typedef slim_int (*ra_device_callback_t) ( slim_int in_msg, void *in_arg, void *in_evt_data);

/* enum for RA related core events*/
typedef enum raEvent_ {
  RA_EVENT_CONNECT_RESULT = 0,
  RA_EVENT_DISCONNECT_RESULT,
  RA_EVENT_GET_TARGETS_RESULT, 
  RA_EVENT_GET_FRIENDS_RESULT,
  RA_EVENT_CREATE_FRIEND_RESULT,
  RA_EVENT_UPDATE_FRIEND_RESULT,
  RA_EVENT_DELETE_FRIEND_RESULT,
  RA_EVENT_PROVISION_RESULT,
  RA_EVENT_CONNECTED,             
  RA_EVENT_DISCONNECTED,          
  RA_EVENT_UPDATE,
  RA_EVENT_STATUS,
  RA_EVENT_INITIALIZED,           
  RA_EVENT_FINALIZED,            
  RA_EVENT_PROVISION_REQUIRED,   
  RA_EVENT_AUTH_REQUIRED,
  RA_EVENT_LOCATION_CHANGED,         
  RA_EVENT_GET_PROPERTIES_RESULT,   
  RA_EVENT_AUTH_RESULT,
  RA_EVENT_SHARE_RESULT,

} raEvent;

typedef enum raReturnValue_ {
  RA_ERR_OK = 0,
  RA_ERR_NO_MEM = -1,
  RA_ERR_NO_TARGET = -2,
  RA_ERR_NO_PEER = -3,
  RA_ERR_WRG_FORMAT = -4,
  RA_ERR_CON_RESET = -5,
  RA_ERR_WRG_CRYPT = -6,
  RA_ERR_REMOTE_ERROR = -100,
 // errors < 100 are errors on RAS propagated to RAC and added to -100
 // For instance i RAS fails fetching p2p key from the Backend, RAC API will throw -152
  RA_ERR_THREAD = -8,
  RA_ERR_CONFIG = -9,
  RA_ERR_CON_TIMEOUT = -10,
  RA_ERR_CONNECT = -11,
  RA_ERR_IO = -12,
  RA_ERR_ALREADY_CONNECTED = -13,
  RA_ERR_CANCELED = -14,
  RA_ERR_GENERIC = -15,
  RA_ERR_INVALID_PARAM = -16,

 // errors > 0 are "external" and could be either cURL or HTTP status

  //RAS only
  RA_ERR_WRG_DEVICE = -50,
  RA_ERR_WRG_IDENTITY = -51,
  RA_ERR_BACKEND = -52
} raReturnValue;

struct RAPeer {
  struct RAPeer *next;
  struct RAPeer *prev;
  slim_char *domid;
  slim_char *gid;
  slim_char *name;
  slim_char *uuid;
  slim_char *addr;
  slim_int  state;
  slim_word  permission;
};

typedef List( struct RAPeer *) RAPeers_t;

#endif /* NFLC_RA_DEF_H */
