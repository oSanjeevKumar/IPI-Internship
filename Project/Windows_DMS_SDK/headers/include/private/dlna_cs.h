/*
 * dlna_cs.h
 * Copyright (C) 2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */


/* content sync entry. */

#ifndef _DLNA_CS_H
#define _DLNA_CS_H

#ifdef DLNA_SUPPORT_CSYNC

/*Content Sync return code*/
typedef enum {
  CSYNC_E_SUCCESS       = 0,
  CSYNC_E_GENERIC       = -1,
  CSYNC_E_WOULDBLOCK    = -2,
  CSYNC_E_INVALID_ARG   = -65535,
  CSYNC_E_IGNORE,
  CSYNC_E_NOT_FOUND,
  CSYNC_E_NOT_MATCH,
  CSYNC_E_EMPTY,
  CSYNC_E_EXIST,
  CSYNC_E_BUSY,
  CSYNC_E_SERVER_UNAVAILABLE,
  CSYNC_E_FATAL,
} csync_return_t;


/*Content Sync event type*/
typedef enum {
  CSYNC_EVENT_TASK_READY,
  CSYNC_EVENT_SYNCED,
  CSYNC_EVENT_CHANGED,
  CSYNC_EVENT_CONFLICTED,
  CSYNC_EVENT_PROGRESS,
  CSYNC_EVENT_ERROR,
} csync_event_t;

/*Content Sync error code, for callback parameter*/
typedef enum {
  CSYNC_EH_SUCCESS = 0,   
  CSYNC_EH_SERVER_NOT_FOUND,
  CSYNC_EH_SERVER_INTERNAL_ERROR,
  CSYNC_EH_SERVER_TIME_OUT,
  CSYNC_EH_UNKNOWN,
} csync_error_t;

typedef enum
{
  CSYNC_STATUS_IDENTICAL,
  CSYNC_STATUS_DIFFERENT,
  CSYNC_STATUS_CONFLICTING,
} csync_status_t;

/*Content Sync action type*/
typedef enum {
  CSYNC_ACTION_NOTHING_TO_DO,
  CSYNC_ACTION_TO_BE_DECIDED,
  CSYNC_ACTION_SERVER_WINS,
  CSYNC_ACTION_CLIENT_WINS,
  CSYNC_ACTION_IGNORE,
} csync_action_t;

/*Content Sync mode*/
typedef enum {
  CSYNC_MODE_AUTOMATIC,
  CSYNC_MODE_MANUAL,
} csync_mode_t;

/*Content Sync direction*/
typedef enum {
  CSYNC_DIRECTION_UPLOAD_ONLY,
  CSYNC_DIRECTION_DOWNLOAD_ONLY,
  CSYNC_DIRECTION_TWO_WAY, 
} csync_direction_t;

/*Content Sync conflict resolution policy*/
typedef enum {
  CSYNC_CRP_SERVER_WINS,
  CSYNC_CRP_CLIENT_WINS,
  CSYNC_CRP_USER_DECIDED,
  CSYNC_CRP_IGNORE, 
} csync_crp_t;

/* DLNA Content Sync.  */
typedef struct csync {
  dlna_client_t *dc;
  
  dlna_progress em;

  TDLNACSyncEventHandler eh;

  void * in_arg;

  slim_char *home_path;
  
  slim_char *data_full_path;

  /* sync task lists.  */
  List (struct csync_task *) task_list;
} csync_t;

csync_t *
dlna_csync_new ();

void
dlna_csync_free(csync_t * cs);

csync_return_t
dlna_csync_initialize (csync_t *cs, dlna_client_t *in_dc, dlna_progress in_em, slim_char* in_home_path, TDLNACSyncEventHandler in_eh, void *in_arg);

void
dlna_csync_finalize (csync_t *cs);

csync_return_t
dlna_csync_startup (csync_t *cs);

csync_return_t
dlna_csync_finishup (csync_t *cs);

csync_return_t
dlna_csync_register_event_handler (csync_t *cs, TDLNACSyncEventHandler in_eh, void *in_arg);

struct csync_task *
dlna_csync_create_task (csync_t *cs, slim_char *in_title, slim_char *in_home_dir, 
                               dlna_object_t *in_local_obj, dlna_object_t *in_remote_obj, 
                               csync_direction_t in_direction, csync_mode_t in_mode, csync_crp_t in_crp,
                               TDLNACSyncEventHandler in_eh, void *in_arg);

csync_return_t
dlna_csync_delete_task (csync_t *cs, struct csync_task *in_task);

struct csync_task *
dlna_csync_get_first_task(csync_t *cs);

struct csync_task *
dlna_csync_get_next_task (csync_t *cs, struct csync_task *in_task);

#ifdef DLNA_SUPPORT_DMSCP
slim_int
dlna_csync_get_tasks_number (csync_t *cs);
#endif /* DLNA_SUPPORT_DMSCP */

csync_return_t
dlna_csync_device_update_proc (csync_t *cs, dlna_client_t *in_dc, TDLNAEvent event);

csync_return_t
dlna_csync_content_update_proc (csync_t *cs, TDLNAEvent event, void *in_param);

csync_return_t
dlna_csync_retcode_from_dlna (slim_int in_dlna_error_code);


#endif /*DLNA_SUPPORT_CSYNC*/
#endif /*_DLNA_CS_H*/

