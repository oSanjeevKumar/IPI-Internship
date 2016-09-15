/*
 * dlna_cs_task.h
 * Copyright (C) 2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */


/* DLNA Content Sync Task */

#ifndef _DLNA_CS_TASK_H
#define _DLNA_CS_TASK_H

#ifdef DLNA_SUPPORT_CSYNC

/* content sync task running states.  */
typedef enum {
  CSYNC_TASK_STATE_NEW = 0,
  CSYNC_TASK_STATE_IDLE,
  CSYNC_TASK_STATE_CONSTRUCTING,  
  CSYNC_TASK_STATE_CHANGE_CHECKING,
  CSYNC_TASK_STATE_LAST_CHANGE_PROCESSING,
  CSYNC_TASK_STATE_SYNCING,
  CSYNC_TASK_STATE_LOADING,
  CSYNC_TASK_STATE_SAVING,
  CSYNC_TASK_STATE_MAX,
} csync_task_state_t;


/* content sync task asynchronous operation events.  */
typedef enum {
  CSYNC_TASK_EVENT_AOP_DONE = 0,
  CSYNC_TASK_EVENT_AOP_PROGRESS,
  CSYNC_TASK_EVENT_AOP_CANCELED,
  CSYNC_TASK_EVENT_AOP_ERROR,
  CSYNC_TASK_EVENT_AOP_TRANSPORT_ERROR,
  CSYNC_TASK_EVENT_SERVER_AVAILABLE,
  CSYNC_TASK_EVENT_SERVER_UNAVAILABLE,
  CSYNC_TASK_EVENT_MAX,
} csync_task_event_t;

/* content sync obj manager events.  */
typedef enum {
  CSYNC_TASK_AOP_TYPE_CONSTRUCT,
  CSYNC_TASK_AOP_TYPE_TRACK_CHANGE,
  CSYNC_TASK_AOP_TYPE_LAST_CHANGE,
  CSYNC_TASK_AOP_TYPE_SYNC,
  CSYNC_TASK_AOP_TYPE_SAVE,
  CSYNC_TASK_AOP_TYPE_LOAD,
  CSYNC_TASK_AOP_TYPE_MAX,
} csync_task_aop_type_t;
  
typedef enum {
  CSYNC_TASK_AOP_CXT_EVENT_GET_SYSTEM_UPDATE_ID = 0,
  CSYNC_TASK_AOP_CXT_EVENT_BROWSE_METADATA,
  CSYNC_TASK_AOP_CXT_EVENT_BROWSE_CHILDREN,
  CSYNC_TASK_AOP_CXT_EVENT_SEARCH,
  CSYNC_TASK_AOP_CXT_EVENT_SYNC,
  CSYNC_TASK_AOP_CXT_EVENT_LAST_CHANGE,
  CSYNC_TASK_AOP_CXT_EVENT_SAVING,
  CSYNC_TASK_AOP_CXT_EVENT_LOADING,
  CSYNC_TASK_AOP_CXT_EVENT_ERROR,
  CSYNC_TASK_AOP_CXT_EVENT_TRANSPORT_ERROR,
} csync_task_aop_ctx_event_t;

typedef enum {
  CSYNC_TASK_LAST_CHANGE_TYPE_ADD,
  CSYNC_TASK_LAST_CHANGE_TYPE_MOD,
  CSYNC_TASK_LAST_CHANGE_TYPE_DEL,
} csync_task_last_change_type_t;

typedef enum {
  CSYNC_TASK_SYNC_TYPE_ADD,
  CSYNC_TASK_SYNC_TYPE_MOD,
  CSYNC_TASK_SYNC_TYPE_DEL,
} csync_task_sync_type_t;

typedef enum {
  CSYNC_TASK_SAVE_TASK_INFO,
  CSYNC_TASK_SAVE_LOCAL_OBJ,
  CSYNC_TASK_SAVE_REMOTE_OBJ,
  CSYNC_TASK_LOAD_TASK_INFO,
  CSYNC_TASK_LOAD_LOCAL_OBJ,
  CSYNC_TASK_LOAD_REMOTE_OBJ,
} csync_task_save_load_type_t;

typedef struct csync_task_aop_ctx csync_task_aop_ctx_t;


typedef csync_return_t (*csync_task_aop_ctx_proc_t) (struct csync_task_aop_ctx *ctx, csync_task_aop_ctx_event_t in_event);

typedef csync_return_t (*csync_task_aop_notify_t) (struct csync_task_aop_ctx *ctx, csync_task_event_t in_event);

typedef struct csync_task_last_change
{
  struct csync_task_last_change *next;
  struct csync_task_last_change *prev;
  
  csync_task_last_change_type_t change_type;
  slim_char *obj_id;
  slim_word update_id;
  slim_char *parent_id;
  slim_char *upnp_class;
  slim_bool is_st_update;
}csync_task_last_change_t;

typedef struct csync_task csync_task_t;

typedef struct csync_task_stat
{
  slim_word total_obj_count;
  slim_word changed_obj_count;
  slim_word conflict_obj_count;
}csync_task_stat_t;

typedef struct csync_task_contents
{
  csync_task_t *task;

  slim_bool sync_is_forbidden;
  
  slim_char *device_udn;

  dlna_object_t *device;

  slim_word system_update_id;
  slim_word last_system_update_id;

  slim_char *top_object_id;

  struct csync_obj *tree;

  List(struct csync_obj *) objs;

  List (csync_task_last_change_t *) last_change;
}csync_task_contents_t;

struct csync_task_aop_ctx
{
  csync_task_t *task;
  
  csync_task_aop_type_t type;

  csync_task_aop_ctx_proc_t proc;

  csync_task_contents_t *contents;
  
  csync_obj_t *obj;

  csync_task_sync_type_t sync_type;

  csync_obj_t *created;

  slim_word get_system_update_id_result;

  slim_char *browse_metadata_id;

  struct _vector *browse_children_result;
  
  dlna_object_t *browse_metadata_result;

  csync_task_last_change_t *last_change;
  void *db_handle;  
  csync_task_save_load_type_t sl_type;

  slim_word added_count;
  slim_word deleted_count;
  slim_word modified_count;

  List (csync_obj_t *) sync_objs;
  dlna_progress_handle e_event;
};

struct csync_task
{
  /* Linked list.  */
  struct csync_task *next;
  struct csync_task *prev;

  csync_t *cs;
  
  dlna_progress em;

  csync_task_state_t state;

  slim_bool server_is_available;

  TDLNACSyncEventHandler eh;
  void * in_arg;

  slim_char *title;
  slim_char *home_dir;

  /*sync direction*/
  csync_direction_t direction;
  /*sync mode*/
  csync_mode_t mode;
  /*conflict resolution policy*/
  csync_crp_t crp;

  csync_task_contents_t *local_contents;
  csync_task_contents_t *remote_contents;

  slim_word total_count;
  slim_word changed_count;
  slim_word conflict_count;
  
  csync_task_aop_ctx_t *aop_ctx;
  
  dlna_progress_handle e_last_change;
  dlna_progress_handle e_track_change;
} ;

typedef struct csync_obj_pair
{
  csync_task_t *task;
  
  TDLNACSyncObjState state;

  TDLNACSyncAction action;
  
  csync_obj_t *local_obj;

  csync_obj_t *remote_obj;

  TDLNACSyncChangeType local_change_type;
  TDLNACSyncChangeType remote_change_type;
}csync_obj_pair_t ;


csync_task_t *
dlna_csync_task_create (csync_t *in_cs, dlna_progress in_p, slim_char *in_title, slim_char *in_home_dir,
                              dlna_object_t *in_local_obj, dlna_object_t *in_remote_obj, 
                              csync_direction_t in_direction, csync_mode_t in_mode, csync_crp_t in_crp,
                              TDLNACSyncEventHandler in_eh, void *in_arg);

csync_return_t
dlna_csync_task_delete (csync_task_t *cst);

csync_return_t
dlna_csync_task_dispose (csync_task_t *cst);

csync_return_t
dlna_csync_task_start_sync (csync_task_t *cst);

csync_return_t
dlna_csync_task_stop_sync (csync_task_t *cst);


csync_return_t
dlna_csync_task_run (csync_task_t *cst);

csync_return_t
dlna_csync_task_cancel (csync_task_t *cst);

csync_task_t *
dlna_csync_task_load (csync_t *in_cs, dlna_progress in_p, slim_char *in_name, slim_char *in_full_path, 
                             TDLNACSyncEventHandler in_eh, void *in_arg);

csync_return_t
dlna_csync_task_save(csync_task_t *cst, slim_char *in_full_path, slim_bool in_is_sync);

csync_return_t
dlna_csync_task_stat(csync_task_t *cst, csync_task_stat_t *out_stat);

csync_return_t
dlna_csync_task_decide (csync_task_t *cst, TDLNACSyncAction in_action);

slim_char *
dlna_csync_task_title(csync_task_t *cst);

csync_mode_t
dlna_csync_task_mode(csync_task_t *cst);

csync_direction_t
dlna_csync_task_direction (csync_task_t *cst);

csync_crp_t
dlna_csync_task_crp (csync_task_t *cst);

csync_return_t
dlna_csync_task_contents_update (csync_task_t *self, TDLNAEvent event, void *in_param);

csync_return_t
dlna_csync_task_device_update (csync_task_t *self, struct dlna_client_tag *dc);

TDLNACSyncObj 
dlna_csync_task_get_top_obj (csync_task_t *self);


TDLNACSyncObj 
dlna_csync_task_get_first_obj (TDLNACSyncObj in_obj);

TDLNACSyncObj 
dlna_csync_task_get_next_obj (TDLNACSyncObj in_obj);

TDLNACSyncObj 
dlna_csync_task_get_parent_obj (TDLNACSyncObj in_obj);

void 
dlna_csync_task_close_obj (TDLNACSyncObj in_obj);

csync_return_t 
dlna_csync_task_obj_title (TDLNACSyncObj in_obj, slim_char **out_remote_title, slim_char **out_local_title);


TDLNACSyncAction
dlna_csync_task_obj_get_action (TDLNACSyncObj obj);

csync_return_t
dlna_csync_task_obj_set_action (TDLNACSyncObj obj, csync_obj_action_t in_action);

csync_return_t
dlna_csync_task_obj_get_change_type (TDLNACSyncObj obj, TDLNACSyncChangeType *out_remote_change, TDLNACSyncChangeType *out_local_change);

csync_obj_state_t
dlna_csync_task_obj_get_state (TDLNACSyncObj obj);

slim_bool
dlna_csync_task_obj_is_container (TDLNACSyncObj obj);



#endif /*DLNA_SUPPORT_CSYNC*/
#endif /*_DLNA_CS_TASK_H*/

