/*
 * upnp_dmpr_docsvr.h
 * Copyright (C) 2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Doc Server for UPnP DMPr Control Point.  */

#ifndef UPNP_DMPR_DOCSVR_H
#define UPNP_DMPR_DOCSVR_H

#define UPNP_DMPR_DOCSVR_PORT(docsvr) ((docsvr)->port)


typedef struct _upnp_dmpr_docsvr upnp_dmpr_docsvr;

enum {
  UPNP_DMPR_JOB_FLAG_XHTML_DOC = 0x01,
  UPNP_DMPR_JOB_FLAG_MTS = 0x02,
  UPNP_DMPR_JOB_FLAG_enum_end
};

enum upnp_dmpr_docsvr_event{
  DOCSVR_EVT_NONE = 0,
  /* Add necessary event id here */
  DOCSVR_EVT_enum_end
};

typedef slim_int (*upnp_dmpr_docsvr_callback)(upnp_dmpr_docsvr* self, void *in_arg, slim_int in_event, slim_int in_job_id);


struct _upnp_dmpr_doc
{
  struct _upnp_dmpr_doc *prev;
  struct _upnp_dmpr_doc *next;

  upnp_dmpr_docsvr *docsvr;

  slim_int job_flag;
  
  slim_int jobid;
  slim_char *doc_uri;  /* like /abcd/doc */
  slim_char *xhtml_doc;
  slim_char *content_uri;
  slim_char *content_file_path;  /* full pathname */
  slim_char *content_pinfo;
  slim_int timeout; /* in seconds */

  dlna_progress_handle expire_timer;
};
typedef struct _upnp_dmpr_doc upnp_dmpr_doc;

struct _upnp_dmpr_docsvr {
  slim_bool brunning;
  slim_int port;
  dlna_progress em;
  http_master_t *hm;
  struct upnp_if_manager *ifm;
  slim_int sock;
  dlna_progress_handle e_accept_hdl;
  List(upnp_dmpr_doc*) doc_list;
  vector v_sessions;
  
  upnp_dmpr_docsvr_callback callback;
  void *callback_arg;
};


upnp_dmpr_docsvr*
upnp_dmpr_docsvr_alloc (dlna_progress em, struct upnp_if_manager *ifm,
                                                  upnp_dmpr_docsvr_callback in_callback, void *in_arg);
void
upnp_dmpr_docsvr_free (upnp_dmpr_docsvr *self);

slim_int
upnp_dmpr_docsvr_start (upnp_dmpr_docsvr *self, slim_int in_port);

slim_int
upnp_dmpr_docsvr_stop (upnp_dmpr_docsvr *self);

/* 
  *  Returned job id is generated locally, 
  *  It's not got from DMPR Service
  */
slim_int
upnp_dmpr_docsvr_doc_add (upnp_dmpr_docsvr *self, 
                                                         slim_char *in_doc_uri, slim_char *in_xhtml, 
                                                         slim_char *in_content_uri, slim_char *in_content_file_path,
                                                         slim_char *in_content_pinfo, slim_int in_timeout, slim_int *out_job_id);

slim_int
upnp_dmpr_docsvr_doc_remove (upnp_dmpr_docsvr *self, slim_int in_job_id);

slim_bool
upnp_dmpr_docsvr_doc_check (upnp_dmpr_docsvr *self, slim_int in_job_id);


#endif /* UPNP_DMPR_DOCSVR_H */
