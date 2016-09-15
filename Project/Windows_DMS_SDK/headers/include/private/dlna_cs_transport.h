/*
 * dlna_cs_transport.h
 * Copyright (C) 2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* content sync, meida data transport process including upload and download. */

#ifndef _DLNA_CS_TRANSPORT_H
#define _DLNA_CS_TRANSPORT_H

#ifdef DLNA_SUPPORT_CSYNC

typedef struct csync_transport_param
{
  slim_byte percent; 
  slim_word current_bytes;
  slim_word total_bytes;
  dlna_object_t *source;
  dlna_object_t *target;
  dlna_object_t *result;  
} csync_transport_param_t;


typedef enum {
  CSYNC_TRANSPORT_TYPE_UPLOAD = 0,
  CSYNC_TRANSPORT_TYPE_DOWNLOAD,
  CSYNC_TRANSPORT_TYPE_CREATE_CHILD_CONTAINER,
  CSYNC_TRANSPORT_TYPE_DELETE_OBJECT,
  CSYNC_TRANSPORT_TYPE_UPDATE_OBJECT,
} csync_transport_type_t;

typedef enum {
  CSYNC_TRANSPORT_STATE_CREATE_OBJ_ACTION = 0,
  CSYNC_TRANSPORT_STATE_DESTROY_OBJ_ACTION,
  CSYNC_TRANSPORT_STATE_UPDATE_OBJ_ACTION,
  CSYNC_TRANSPORT_STATE_COPY_FILE,
  CSYNC_TRANSPORT_STATE_BROWSE_METADATA,
  CSYNC_TRANSPORT_STATE_TRANSFER_DATA,
  CSYNC_TRANSPORT_STATE_DONE,
} csync_transport_state_t;

typedef enum {
  CSYNC_TRANSPORT_EVENT_DONE = 0,
  CSYNC_TRANSPORT_EVENT_PROGRESS,
  CSYNC_TRANSPORT_EVENT_CANCELLED,
  CSYNC_TRANSPORT_EVENT_CLOSE,
  CSYNC_TRANSPORT_EVENT_ERROR,
} csync_transport_event_t;

typedef struct csync_transport csync_transport_t;

typedef csync_return_t (*csync_transport_event_handler_t) (csync_transport_t *self, csync_transport_event_t in_event, void *in_arg, void *in_param);

struct csync_transport
{
  dlna_client_t *dc;

  csync_transport_type_t type;
  
  csync_transport_state_t state;

  dlna_object_t *source;
  
  dlna_object_t *target_device;

  dlna_object_t *target_parent;

  dlna_object_t *target;

  dlna_object_t *result;

  slim_char *target_id;
  contents_t *target_content;

  dlna_object_t *transport;

  dlna_file_t read_fp;
  dlna_file_t write_fp;

  slim_char *source_path;
  slim_char *target_path;
  slim_char *import_url;
  slim_byte *buf;
  slim_word buf_size;
  slim_word data_size;
  slim_word write_pos;  
  dlna_progress e_file_copy;
  
  dlna_progress e_close;
  csync_transport_event_handler_t callback;
  void *arg;
};

csync_return_t
dlna_csync_transport_create_object (dlna_object_t *obj, dlna_object_t *in_device, dlna_object_t *in_parent, 
                                               csync_transport_event_handler_t in_callback, void *in_arg, csync_transport_t **out_transport);

csync_return_t
dlna_csync_transport_destory_object (dlna_object_t *obj, csync_transport_event_handler_t in_callback, void *in_arg, csync_transport_t **out_transport);

csync_return_t
dlna_csync_transport_update_object (dlna_object_t *obj, csync_transport_event_handler_t in_callback, void *in_arg, csync_transport_t **out_transport);

csync_return_t
dlna_csync_transport_cancel (csync_transport_t *in_transport);

void
dlna_csync_transport_event_close (csync_transport_t *in_transport);

void
dlna_csync_transport_close (csync_transport_t *in_transport);

#endif /*DLNA_SUPPORT_CSYNC*/
#endif /*_DLNA_CS_TRANSPORT_H*/


