/*
 * dlna_cs_obj_manager.h
 * Copyright (C) 2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* content sync obj manager. */
#ifndef _DLNA_CS_OBJ_MANAGER_H
#define _DLNA_CS_OBJ_MANAGER_H

#ifdef DLNA_SUPPORT_CSYNC

/*UPnP property name flags*/
#define CSYNC_OBJ_PROP_FLAG_ITEM_MASK                   (0x00000001)
#define CSYNC_OBJ_PROP_FLAG_CONTAINER_MASK              (0x0000003f)
#define CSYNC_OBJ_PROP_FLAG_ITEM_MANDATORY_MASK         (0x00000001)
#define CSYNC_OBJ_PROP_FLAG_CONTAINER_MANDATORY_MASK    (0x00000001)

#define CSYNC_OBJ_PROP_FLAG_ITEM                        (0x00000001)
#define CSYNC_OBJ_PROP_FLAG_CONTAINER                   (0x00000002)
#define CSYNC_OBJ_PROP_FLAG_OBJECT_UPDATE_ID            (0x00000004)
#define CSYNC_OBJ_PROP_FLAG_CONTAINER_UPDATE_ID         (0x00000008)
#define CSYNC_OBJ_PROP_FLAG_TOTAL_DELETED_CHILD_COUNT   (0x00000010)
#define CSYNC_OBJ_PROP_FLAG_UPNP_CLASS                  (0x00000020)
#define CSYNC_OBJ_PROP_FLAG_DC_TITLE                    (0x00000040)
#define CSYNC_OBJ_PROP_FLAG_DC_CREATOR                  (0x00000080)
#define CSYNC_OBJ_PROP_FLAG_UPNP_ARTIST                 (0x00000100)
#define CSYNC_OBJ_PROP_FLAG_UPNP_ACTOR                  (0x00000200)
#define CSYNC_OBJ_PROP_FLAG_UPNP_AUTHOR                 (0x00000400)
#define CSYNC_OBJ_PROP_FLAG_RES                         (0x00000800)

/*UPnP attribute name flags*/
#define CSYNC_OBJ_PROP_ATTR_NOT_AVAILBALE               (0x00000000)
#define CSYNC_OBJ_PROP_ATTR_ROLE_MASK                   (0x00000100)
#define CSYNC_OBJ_PROP_ATTR_RES_MASK                    (0x03ff0000)

#define CSYNC_OBJ_PROP_ATTR_FLAG_ID                     (0x00000001)
#define CSYNC_OBJ_PROP_ATTR_FLAG_PARENT_ID              (0x00000002)
#define CSYNC_OBJ_PROP_ATTR_FLAG_REF_ID                 (0x00000004)
#define CSYNC_OBJ_PROP_ATTR_FLAG_RESTRICT               (0x00000008)
#define CSYNC_OBJ_PROP_ATTR_FLAG_SEACHABLE              (0x00000010)
#define CSYNC_OBJ_PROP_ATTR_FLAG_CHILDCOUNT             (0x00000020)
#define CSYNC_OBJ_PROP_ATTR_FLAG_NAME                   (0x00000040)
#define CSYNC_OBJ_PROP_ATTR_FLAG_INCLUDE_DERIVED        (0x00000080)
#define CSYNC_OBJ_PROP_ATTR_FLAG_ROLE                   (0x00000100)
#define CSYNC_OBJ_PROP_ATTR_FLAG_EXTENDED               (0x00000200)
#define CSYNC_OBJ_PROP_ATTR_FLAG_UPNP_DAYLIGHT_SAVING   (0x00000400)
#define CSYNC_OBJ_PROP_ATTR_FLAG_DAYLIGHT_SAVING        (0x00000800)
#define CSYNC_OBJ_PROP_ATTR_FLAG_TYPE                   (0x00001000)
#define CSYNC_OBJ_PROP_ATTR_FLAG_RES_PINFO              (0x00010000)
#define CSYNC_OBJ_PROP_ATTR_FLAG_RES_SIZE               (0x00020000)
#define CSYNC_OBJ_PROP_ATTR_FLAG_RES_DURATION           (0x00040000)
#define CSYNC_OBJ_PROP_ATTR_FLAG_RES_PROTECTION         (0x00080000)
#define CSYNC_OBJ_PROP_ATTR_FLAG_RES_BITRATE            (0x00100000)
#define CSYNC_OBJ_PROP_ATTR_FLAG_RES_BITS_PER_SAMPLE    (0x00200000)
#define CSYNC_OBJ_PROP_ATTR_FLAG_RES_SAMPLE_FREQUENCY   (0x00400000)
#define CSYNC_OBJ_PROP_ATTR_FLAG_RES_NR_AUDIO_CHANNELS  (0x00800000)
#define CSYNC_OBJ_PROP_ATTR_FLAG_RES_RESOLUTION         (0x01000000)
#define CSYNC_OBJ_PROP_ATTR_FLAG_RES_COLOR_DEPTH        (0x02000000)
#define CSYNC_OBJ_PROP_ATTR_FLAG_RES_UPDATE_COIUNT      (0x04000000)

typedef enum {
  CSYNC_OBJ_STATE_UNCHANGED = 0,
  CSYNC_OBJ_STATE_CHANGED,
  CSYNC_OBJ_STATE_CONFLICTED,
} csync_obj_state_t;

typedef enum {
  CSYNC_OBJ_CHANGE_TYPE_NONE = 0,
  CSYNC_OBJ_CHANGE_TYPE_ADD,
  CSYNC_OBJ_CHANGE_TYPE_MOD,
  CSYNC_OBJ_CHANGE_TYPE_DEL,
  CSYNC_OBJ_CHANGE_TYPE_NOTEXIST,
} csync_obj_change_type_t;

/*Content Sync action type*/
typedef enum {
  CSYNC_OBJ_ACTION_NOTHING_TO_DO = 0,
  CSYNC_OBJ_ACTION_TO_BE_DECIDED,
  CSYNC_OBJ_ACTION_BREAK_EVEN,  
  CSYNC_OBJ_ACTION_WIN,
  CSYNC_OBJ_ACTION_LOSE,
  CSYNC_OBJ_ACTION_IGNORE,
  /*
  CSYNC_OBJ_ACTION_ALWAYS_WIN,
  CSYNC_OBJ_ACTION_ALWAYS_LOSE,
  CSYNC_OBJ_ACTION_ALWAYS_IGNORE,
  */
} csync_obj_action_t;

#define CSYNC_OBJ_MOD_FLAG_METADATA   (0x01)
#define CSYNC_OBJ_MOD_FLAG_CHILD_ADD  (0x02)
#define CSYNC_OBJ_MOD_FLAG_CHILD_DEL  (0x04)

/* content sync obj events.  */
typedef enum {
  CSYNC_OBJ_EVENT_BROWSE_CHILDREN = 0,
  CSYNC_OBJ_EVENT_BROWSE_METADATA,
  CSYNC_OBJ_EVENT_SEARCH,
  CSYNC_OBJ_EVENT_CREATE_OBJECT,
  CSYNC_OBJ_EVENT_DESTORY_OBJECT,
  CSYNC_OBJ_EVENT_UPDATE_OBJECT,
  CSYNC_OBJ_EVENT_SYNC,
  CSYNC_OBJ_EVENT_ERROR,
  CSYNC_OBJ_EVENT_TRANSPORT_ERROR,
  CSYNC_OBJ_EVENT_MAX
} csync_obj_event_t;

typedef enum {
  CSYNC_OBJ_TYPE_ITEM = 0,
  CSYNC_OBJ_TYPE_CONTAINER,
  CSYNC_OBJ_TYPE_REFERENCE,
  CSYNC_OBJ_TYPE_OTHER,
  CSYNC_OBJ_TYPE_MAX,
}csync_obj_type_t;

typedef enum {
  CSYNC_OBJ_SYNC_TYPE_NOTHING_TO_DO = 0,
  CSYNC_OBJ_SYNC_TYPE_CREATE_OBJ,
  CSYNC_OBJ_SYNC_TYPE_DESTROY_OBJ,
  CSYNC_OBJ_SYNC_TYPE_UPDATE_OBJ,
}csync_obj_sync_type_t;

typedef struct csync_obj_browse_param
{
  dlna_object_t **objs;
  slim_word count;
}csync_obj_browse_param_t;

typedef struct csync_obj csync_obj_t;

typedef csync_return_t (*csync_obj_exec_t)(csync_obj_t *obj);

typedef csync_return_t (*csync_obj_event_handler_t) (csync_obj_t *obj, csync_obj_event_t in_event, void *in_arg, void *in_param);

typedef struct csync_obj_prop
{
  /* Linked list.  */
  struct csync_obj_prop *next;
  struct csync_obj_prop *prev;

  csync_obj_t *obj;
 
  slim_char *name;
  
  csync_obj_change_type_t change_type;

  slim_int prop_id;

  slim_int res_index;
  
  csync_action_t action;
}csync_obj_prop_t;

struct csync_obj
{
  /* Linked list.  */
  struct csync_obj *next;
  struct csync_obj *prev;

  csync_obj_event_handler_t callback;
  void *arg;

  csync_obj_change_type_t change_type;
  
  csync_obj_action_t action;
  
  slim_char *partner_id;
  csync_obj_t *partner;
  slim_char *parent_id;
  csync_obj_t *parent;

  csync_obj_type_t type;

  csync_obj_state_t state;
  
  /*dlna object. */
  dlna_object_t *dlna_obj;
  slim_char *id;
  slim_char *title;
  slim_word update_id;

  slim_word prop_flag;
  List(csync_obj_prop_t *) prop_list;

  /*Res is just available for item*/
  csync_obj_prop_t *res;
  /*Child vector. just available for container */
  struct _vector *child;
  /*Child count. just available for container */
  slim_word child_count;
  /*Child add count. just available for container */
  slim_word child_add_count;
  /*Child delete count. just available for container */
  slim_word child_del_count;
  slim_word container_update_id;
  slim_word total_deleted_child_count;

  /*browse_result vector. just available for container */
  struct _vector *browse_result;
  slim_char *search_criteria;
  
  struct csync_transport *transport;
};


csync_obj_t *
dlna_csync_obj_new (dlna_object_t *in_dlna_obj, csync_obj_t *in_parent);

void
dlna_csync_obj_free (csync_obj_t *obj);

csync_return_t
dlna_csync_obj_map (csync_obj_t *obj1, csync_obj_t *obj2);

csync_return_t
dlna_csync_obj_is_pair (csync_obj_t *obj1, csync_obj_t *obj2);

slim_char *
dlna_csync_obj_id (csync_obj_t *obj);

/*get first child with type*/
csync_obj_t *
dlna_csync_obj_first (csync_obj_t *obj, csync_obj_type_t type);

/*get next sibling with type*/
csync_obj_t *
dlna_csync_obj_next (csync_obj_t *obj, csync_obj_type_t type);

/*get next sibling with type*/
csync_obj_t *
dlna_csync_obj_parent (csync_obj_t *obj);

csync_obj_t *
dlna_csync_obj_partner (csync_obj_t *obj);

csync_obj_action_t
dlna_csync_obj_get_action (csync_obj_t *obj);

csync_return_t
dlna_csync_obj_set_action (csync_obj_t *obj, csync_obj_action_t in_action);

csync_obj_change_type_t
dlna_csync_obj_get_change_type (csync_obj_t *obj);

csync_return_t
dlna_csync_obj_set_change_type (csync_obj_t *obj, csync_obj_change_type_t in_change_type);

csync_obj_state_t
dlna_csync_obj_get_state (csync_obj_t *obj);

csync_return_t
dlna_csync_obj_get_title (csync_obj_t *obj, slim_char **out_title);

csync_obj_type_t
dlna_csync_obj_type (csync_obj_t *obj);

csync_obj_t *
dlna_csync_obj_traversal (csync_obj_t *root, csync_obj_t *current, csync_obj_type_t type);

csync_return_t
dlna_csync_obj_browse (csync_obj_t *obj, csync_obj_event_handler_t in_callback, void *in_arg);

csync_return_t
dlna_csync_obj_browse_metadata (csync_obj_t *obj, slim_char *in_id, csync_obj_event_handler_t in_callback, void *in_arg, dlna_object_t **out_dlna_obj);

csync_return_t
dlna_csync_obj_search (csync_obj_t *obj, slim_char *in_criteria, csync_obj_event_handler_t in_callback, void *in_arg);

csync_obj_sync_type_t
dlna_csync_obj_sync_type (csync_obj_t *obj);

csync_return_t
dlna_csync_obj_change_add (csync_obj_t *obj);

csync_return_t
dlna_csync_obj_change_mod (csync_obj_t *obj, dlna_object_t *new_dlna_obj);

csync_return_t
dlna_csync_obj_change_del (csync_obj_t *obj);

csync_return_t
dlna_csync_obj_change_reconcile (csync_obj_t *obj, slim_bool in_is_local, 
                                        csync_direction_t in_direction, csync_crp_t in_crp);

csync_return_t
dlna_csync_obj_change_synced (csync_obj_t *obj);

csync_return_t
dlna_csync_obj_sync (csync_obj_t *obj, csync_obj_event_handler_t in_callback, void *in_arg);

csync_obj_t *
dlna_csync_obj_lookup_by_id (csync_obj_t *in_root, slim_char *in_id);


#endif /*DLNA_SUPPORT_CSYNC*/
#endif /*_DLNA_CS_OBJ_MANAGER_H*/

