/*
* ca_dms.h
* Copyright (C) 2015 ACCESS CO.,LTD.
* All rights are reserved by ACCESS CO.,LTD.,
* whether the whole or part of the source code
* including any modifications is concerned.
*
* This is an unpublished source code of ACCESS CO.,LTD., and must be
* treated as confidential material.  The above copyright notice does
* not evidence any actual or intended publication of this source code.
*/

#include <dlna_peer.h>

#ifndef CA_DMS_H
#define CA_DMS_H

struct dlna_object;

enum ca_dms_event {
  CA_DMS_EVENT_STATE_CHANGED,
  CA_DMS_EVENT_DB_UPDATE,
  CA_DMS_EVENT_DB_CHECKPOINT
};
typedef enum ca_dms_event ca_dms_event_t;

enum ca_dms_state {
  CA_DMS_NEW,
  CA_DMS_PROCESSING,
  CA_DMS_FINISHED,
  CA_DMS_ERROR,
  CA_DMS_NEEDS_UPDATE,
  CA_DMS_PAUSED,
  CA_DMS_INVALID
};
typedef enum ca_dms_state ca_dms_state_t;

typedef void *ca_dms_t;
typedef slim_int (*ca_dms_callback_t)(void *in_arg, ca_dms_event_t in_event);

ca_dms_t*
ca_dms_alloc(dlna_progress em, struct dlna_object *in_device_obj,
             ca_dms_callback_t in_callback, void *in_callback_arg,
             slim_char *db_folder_path, slim_int in_index, slim_int in_rescan);

void
ca_dms_free(ca_dms_t* in_dms);

slim_int
ca_dms_proc(ca_dms_t* in_dms);

slim_int
ca_dms_stop(ca_dms_t *in_dms);

slim_int
ca_dms_pause(ca_dms_t *in_dms);

slim_int
ca_dms_resume(ca_dms_t *in_dms);

ca_dms_state_t
ca_dms_get_state(ca_dms_t* in_dms);

slim_char *
ca_dms_get_uuid(ca_dms_t* in_dms);

struct dlna_object *
ca_dms_get_device_obj(ca_dms_t* in_dms);

slim_int
ca_dms_update_suid(ca_dms_t* in_dms, slim_int in_suid);

slim_int
ca_dms_update_cuid(ca_dms_t* in_dms, slim_char *in_cuid);

slim_int
ca_dms_update_indexing(ca_dms_t * in_dms, slim_int in_indexing);

slim_int
ca_dms_update_rescan_time(ca_dms_t* in_dms, slim_int in_interval);

#endif /* CA_DMS_H */
