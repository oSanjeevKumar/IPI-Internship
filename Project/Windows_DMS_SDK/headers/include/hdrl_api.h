/*
 * hdrl_api.h
 * Copyright (C) 2008 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_HDRL_API_H
#define NFLC_HDRL_API_H

#include <dlna_api.h>

typedef void* THDRLObject;

struct hdrl_del_result {
   slim_int err_code;
};
typedef struct hdrl_del_result hdrl_del_result_t;

struct hdrl_rec_des_item {
  /* Required */
  slim_char *recordDesID;
  slim_char *recordDesName;
  slim_char *recordDesVersion;
  /* Optional */
  slim_char *updateID;
};
typedef struct hdrl_rec_des_item hdrl_rec_des_item_t;

struct hdrl_rec_deslist_result {
  hdrl_rec_des_item_t * deslist;
  slim_int des_num;
  slim_int err_code;
};
typedef struct hdrl_rec_deslist_result hdrl_rec_deslist_result_t;

struct hdrl_rec_desinfo_result {
  /* Required */
  slim_char *version;
  slim_char *recordDesInfo;
  slim_char *allowedTypes;
  slim_bool  recordable;

  /* Optional */
  slim_char * totalCapacity;
  slim_char * availCapacity;
  slim_int err_code;
};
typedef struct hdrl_rec_desinfo_result hdrl_rec_desinfo_result_t;
  
struct hdrl_containerID_result {
  slim_char *container_id;
  slim_int err_code;
};
typedef struct hdrl_containerID_result hdrl_containerID_result_t;

/* Parameter for hdrl common action */
struct hdrl_action_param {
  slim_char *des_id;
  upnp_upload_param_t *element_param;
};
typedef struct hdrl_action_param hdrl_action_param_t;

/* HDRL object event handler */
#define THDRLObjectEventHandler TDLNAObjectEventHandler

#ifdef DLNA_SUPPORT_HDRL

/* HDRL Object event code */
#define HDRL_OBJECT_EV_GETRECDESLIST_END  DLNA_OBJECT_EV_GETRECDESLIST_END
#define HDRL_OBJECT_EV_GETRECDESINFO_END  DLNA_OBJECT_EV_GETRECDESINFO_END
#define HDRL_OBJECT_EV_GETCONTAINERID_END  DLNA_OBJECT_EV_GETCONTAINERID_END

/* HDRL Object event error code */
#define HDRL_E_UP_HTTP_TIMEOUT  DLNA_E_UP_HTTP_TIMEOUT
#define HDRL_E_UP_HTTP_ERROR  DLNA_E_UP_HTTP_ERROR
#define HDRL_E_UP_NO_SUCH_OBJ  DLNA_E_UP_NO_SUCH_OBJ
#define HDRL_E_UP_RESTRICTED_OBJ  DLNA_E_UP_RESTRICTED_OBJ
#define HDRL_E_UP_RESTRICTED_PARENT_OBJ  DLNA_E_UP_RESTRICTED_PARENT_OBJ
#define HDRL_E_UP_NO_SUCH_RESOURCE  DLNA_E_UP_NO_SUCH_RESOURCE
#define HDRL_E_UP_NO_RESOURCE_ACCESS_DENIED  DLNA_E_UP_RESOURCE_ACCESS_DENIED
#define HDRL_E_UP_NO_SUCH_CONTAINER  DLNA_E_UP_NO_SUCH_CONTAINER
#define HDRL_E_UP_BAD_METADATA  DLNA_E_UP_BAD_METADATA
#define HDRL_E_UP_GENERIC  DLNA_E_UP_GENERIC
#define HDRL_E_UP_HTTP_SESSION_ERROR DLNA_E_UP_HTTP_SESSION_ERROR

/* HDRL API return value */
#define HDRL_E_OK   DLNA_E_OK
#define HDRL_E_NOT_SUPPORT DLNA_E_NOT_SUPPORT
#define HDRL_E_INVAL   DLNA_E_INVAL
#define HDRL_E_GENERIC   DLNA_E_GENERIC

slim_bool
HDRL_IsRCVDevice (THDRLObject self);

slim_bool
HDRL_IsRECDevice (THDRLObject self);

slim_int
HDRL_HDLnkGetRecordDestinations (THDRLObject self, THDRLObjectEventHandler in_obj_eh, void *in_arg);

slim_int
HDRL_HDLnkGetRecordDestinationInfo (THDRLObject self, slim_char *des_id, THDRLObjectEventHandler in_obj_eh, void *in_arg);

slim_int
HDRL_HDLnkGetRecordContainerID (THDRLObject self, slim_char *des_id, THDRLObjectEventHandler in_obj_eh, void *in_arg, up_stream_param_t *in_param);

#endif /* DLNA_SUPPORT_HDRL */

#endif /* NFLC_HDRL_API_H */


