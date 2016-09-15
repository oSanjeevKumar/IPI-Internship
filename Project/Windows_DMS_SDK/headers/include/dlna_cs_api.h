/*
* dlna_cs_api.h
* Copyright (C) 2010 ACCESS CO.,LTD.
* All rights are reserved by ACCESS CO.,LTD.,
* whether the whole or part of the source code
* including any modifications is concerned.
*
* This is an unpublished source code of ACCESS CO.,LTD., and must be
* treated as confidential material.  The above copyright notice does
* not evidence any actual or intended publication of this source code.
*/

/* Content Sync API.  */

#ifndef _DLNA_CS_API_H
#define _DLNA_CS_API_H
#include <dlna_peer.h>
#include <dlna_api.h>

/*Content Sync instance handle*/
typedef void * TDLNACSync;

/*Content Sync task instance handle*/
typedef void * TDLNACSyncTask;

/*Content Sync object instance handle*/
typedef void * TDLNACSyncObj;

/*Content Sync object property instance handle*/
typedef void * TDLNACSyncObjProp;

/*Content Sync API return code*/
typedef enum {
  DLNA_CSYNC_E_SUCCESS        = 0,   
  DLNA_CSYNC_E_GENERIC        = -1,
  DLNA_CSYNC_E_WOULDBLOCK     = -2,
  DLNA_CSYNC_E_INVALID_ARG    = -65535,
  DLNA_CSYNC_E_FATAL,
} TDLNACSyncReturn;

/*Content Sync event type*/
typedef enum {
  DLNA_CSYNC_EVENT_TASK_READY,
  DLNA_CSYNC_EVENT_SERVER_UNAVAILABLE,
  DLNA_CSYNC_EVENT_SERVER_AVAILABLE,
  DLNA_CSYNC_EVENT_CHANGED,
  DLNA_CSYNC_EVENT_SYNCED,
  DLNA_CSYNC_EVENT_CANCELLED,
  DLNA_CSYNC_EVENT_PROGRESS,
  DLNA_CSYNC_EVENT_ERROR,
  DLNA_CSYNC_EVENT_TRANSPORT_ERROR,
} TDLNACSyncEvent;

/*Content Sync error code, for callback parameter*/
typedef enum {
  DLNA_CSYNC_EH_SUCCESS = 0,   
  DLNA_CSYNC_EH_SERVER_NOT_FOUND,
  DLNA_CSYNC_EH_SERVER_INTERNAL_ERROR,
  DLNA_CSYNC_EH_SERVER_TIME_OUT,
  DLNA_CSYNC_EH_UNKNOWN,
} TDLNACSyncError;

typedef enum {
  DLNA_CSYNC_OBJ_STATE_UNKNOWN,
  DLNA_CSYNC_OBJ_STATE_UNCHANGED,
  DLNA_CSYNC_OBJ_STATE_CHANGED,
  DLNA_CSYNC_OBJ_STATE_CONFLICTING,
} TDLNACSyncObjState;

typedef enum {
  DLNA_CSYNC_OBJ_CHANGE_TYPE_NOT_EXIST,  
  DLNA_CSYNC_OBJ_CHANGE_TYPE_UNCHANGED,
  DLNA_CSYNC_OBJ_CHANGE_TYPE_ADD,
  DLNA_CSYNC_OBJ_CHANGE_TYPE_MOD,
  DLNA_CSYNC_OBJ_CHANGE_TYPE_DEL,
} TDLNACSyncChangeType;

/*Content Sync action type*/
typedef enum {
  DLNA_CSYNC_ACTION_NOTHING_TO_DO = 0,
  DLNA_CSYNC_ACTION_TO_BE_DECIDED,
  DLNA_CSYNC_ACTION_BREAK_EVEN,  
  DLNA_CSYNC_ACTION_SERVER_WINS,
  DLNA_CSYNC_ACTION_LOCAL_WINS,
  DLNA_CSYNC_ACTION_IGNORE,
} TDLNACSyncAction;

/*Content Sync mode*/
typedef enum {
  DLNA_CSYNC_DIRECTION_UPLOAD_ONLY,
  DLNA_CSYNC_DIRECTION_DOWNLOAD_ONLY,
  DLNA_CSYNC_DIRECTION_TWO_WAY, 
} TDLNACSyncDirection;

/*Content Sync mode*/
typedef enum {
  DLNA_CSYNC_MODE_AUTOMATIC,
  DLNA_CSYNC_MODE_MANUAL,
} TDLNACSyncMode;

/*Content Sync conflict resolution policy*/
typedef enum {
  DLNA_CSYNC_CONFLICT_POLICY_SERVER_WINS,
  DLNA_CSYNC_CONFLICT_POLICY_LOCAL_WINS,
  DLNA_CSYNC_CONFLICT_POLICY_USER_DECIDED,
  DLNA_CSYNC_CONFLICT_POLICY_IGNORE, 
} TDLNACSyncConflictPolicy;

/*Content Sync event handler parameter*/
typedef struct _TDLNACSyncParam {
  TDLNACSyncError  err; /*DLNA_CSYNC_EVENT_ERROR*/
  TDLNACSyncObj obj;   /*DLNA_CSYNC_EVENT_PROGRESS*/
}TDLNACSyncParam;

typedef struct _TDLNACSyncTaskStat {
  slim_word total_obj_count;
  slim_word changed_obj_count;
  slim_word conflicted_obj_count;
} TDLNACSyncTaskStat;


typedef void (*TDLNACSyncEventHandler) (TDLNACSyncTask self, TDLNACSyncEvent in_event, void *in_arg, TDLNACSyncParam *in_param);

/* Prototypes.  */
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

TDLNACSync
dlnaCSyncNew (TDLNA in_dc, dlna_progress in_progress, slim_char *in_home_path, TDLNACSyncEventHandler in_eh, void *in_arg);

void
dlnaCSyncFree(TDLNACSync self);

TDLNACSyncReturn
dlnaCSyncStart (TDLNACSync self);

TDLNACSyncReturn
dlnaCSyncStop (TDLNACSync self);

TDLNACSyncTask
dlnaCSyncGetFirstTask (TDLNACSync self);

TDLNACSyncTask
dlnaCSyncGetNextTask (TDLNACSync self, TDLNACSyncTask in_task);

#ifdef DLNA_SUPPORT_DMSCP
slim_int
dlnaCSyncGetTasksNumber (TDLNACSync self);
#endif /* DLNA_SUPPORT_DMSCP */

TDLNACSyncTask
dlnaCSyncTaskCreate (TDLNACSync self, slim_char *in_title, TDLNAObject in_local_obj, TDLNAObject in_remote_obj, 
                             TDLNACSyncDirection in_direction, TDLNACSyncMode in_mode, TDLNACSyncConflictPolicy in_policy);

void
dlnaCSyncTaskDelete(TDLNACSyncTask self);

TDLNACSyncReturn
dlnaCSyncTaskStartSync (TDLNACSyncTask self);

TDLNACSyncReturn
dlnaCSyncTaskStopSync (TDLNACSyncTask self);

DLNA_API slim_int
dlnaCSyncTaskStat (TDLNACSyncTask self, TDLNACSyncTaskStat *out_stat);

DLNA_API slim_int
dlnaCSyncTaskDecide (TDLNACSyncTask self, TDLNACSyncAction in_action);

TDLNACSyncReturn
dlnaCSyncTaskTitle(TDLNACSyncTask self, slim_char **out_title);

TDLNACSyncReturn
dlnaCSyncTaskRename(TDLNACSyncTask self, slim_char *in_title);

TDLNACSyncReturn
dlnaCSyncTaskGetMode(TDLNACSyncTask self, TDLNACSyncMode *out_mode);

TDLNACSyncReturn
dlnaCSyncTaskSetMode (TDLNACSyncTask self, TDLNACSyncMode in_mode);

TDLNACSyncReturn
dlnaCSyncTaskGetDirection (TDLNACSyncTask self, TDLNACSyncDirection *out_direction);

TDLNACSyncReturn
dlnaCSyncTaskGetConflictPolicy(TDLNACSyncTask self, TDLNACSyncConflictPolicy *out_policy);

TDLNACSyncReturn
dlnaCSyncTaskSetConflictPolicy(TDLNACSyncTask self, TDLNACSyncConflictPolicy in_policy);

TDLNACSyncObj
dlnaCSyncTaskObjTop (TDLNACSyncTask self);

TDLNACSyncObj 
dlnaCSyncTaskObjFirst (TDLNACSyncObj in_obj);

TDLNACSyncObj
dlnaCSyncTaskObjNext (TDLNACSyncObj in_obj);

TDLNACSyncObj
dlnaCSyncTaskObjParent (TDLNACSyncObj in_obj);

void
dlnaCSyncTaskObjClose (TDLNACSyncObj in_obj);

slim_bool
dlnaCSyncTaskObjIsContainer(TDLNACSyncObj in_obj);

TDLNACSyncReturn
dlnaCSyncTaskObjState(TDLNACSyncObj in_obj, TDLNACSyncObjState *out_state);

TDLNACSyncReturn
dlnaCSyncTaskObjGetAction (TDLNACSyncObj in_obj, TDLNACSyncAction *out_action);

TDLNACSyncReturn
dlnaCSyncTaskObjSetAction (TDLNACSyncObj in_obj, TDLNACSyncAction in_action);

TDLNACSyncReturn
dlnaCSyncTaskObjGetChangeType (TDLNACSyncObj in_obj, TDLNACSyncChangeType *out_server_side_change, TDLNACSyncChangeType *out_local_side_change);

TDLNACSyncReturn
dlnaCSyncTaskObjDecide(TDLNACSyncTask self, TDLNACSyncObj in_obj, TDLNACSyncAction in_action);


TDLNACSyncReturn
dlnaCSyncTaskObjTitle (TDLNACSyncObj in_obj, slim_char **out_service_side_title, slim_char **out_local_side_title);

#if 0
TDLNACSyncReturn
dlnaCSyncTaskObjProp (TDLNACSyncTask self, TDLNACSyncObj in_obj, TDLNACSyncObjProp in_prop, TDLNACSyncObjProp *out_prop_list, slim_word *inout_prop_count);

TDLNACSyncReturn
dlnaCSyncTaskObjPropValue (TDLNACSyncTask self, TDLNACSyncObj in_obj, TDLNACSyncObjProp in_prop, slim_char *out_value, slim_word *inout_value_size);

TDLNACSyncReturn 
dlnaCSyncTaskObjPropState (TDLNACSyncTask self, TDLNACSyncObj in_obj, TDLNACSyncObjProp in_prop, TDLNACSyncObjState out_state);

TDLNACSyncReturn 
dlnaCSyncTaskObjPropDecide(TDLNACSyncTask self, TDLNACSyncObj in_obj, TDLNACSyncObjProp in_prop, TDLNACSyncAction in_action);
#endif
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _DLNA_CS_API_H */
