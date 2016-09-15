/*
 * soap_client.h
 * Copyright (C) 2007-2009 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2005 IP Infusion, Inc. All Rights Reserved.  */

#ifndef NFLC_SOAP_CLIENT_H
#define NFLC_SOAP_CLIENT_H

#include <http_session.h>

struct soap_client_param;
struct upnp_device;

/* DLNA Requirement [7.2.9.4]: A UPnP control point may terminate the TCP
   connection for a SOAP response transmission that exceeds 30 seconds.  */
#define SOAP_CLIENT_SESSION_TIMEOUT  (30)

typedef slim_int (*soap_client_func_t) (struct soap_client_param *sp,
                                        sXML *doc);

struct soap_client_param
{
  /* SOAP client ID.  */
  slim_word id;

  /* Transport ID.  */
  slim_int tid;

  /* Session Data for application.  */
  void *session_data;

  /* UPnP client back pointer.  */
  struct upnp_client *uc;

  /* HTTP client connection.  */
  struct http_client *hc;

  /* SOAP type.  */
  slim_word type;
#define SOAP_CLIENT_ACTION  (1 << 0)
#define SOAP_CLIENT_GET_VAR (1 << 1)

  /* HTTP evnet.  */
  http_event_t http_event;

  /* SOAP error.  */
  slim_int error;

  /* Server URI.  */
  slim_char *uri;

  /* SOAP service type.  */
  slim_char *service_type;

  /* SOAP XML document.  */
  sXML *action_doc;

  /* SOAP XML document.  */
  sXML *result_doc;

  /* Pointer to the action name.  */
  slim_char *name;

  /* UPnP device.  */
  slim_char *device_type;
  slim_char *udn;

  /* ID for browse.  */
  slim_char *browse_id;

  /* Callback.  */
  soap_client_func_t soap_client_callback;

  /* slim_true: event HTTP_EVENT_RECEIVE_DONE is alreay received */
  slim_bool response_done;
  
  /* Delayed soap client cancel event.  */
  dlna_progress_handle e_soap_client_delay_cancel;

#if defined (DLNA_SUPPORT_X_BROWSE)
  /* With X-ParentLock */
  slim_bool with_x_parentallock;
#endif /* defined (DLNA_SUPPORT_X_BROWSE) */

  slim_bool no_timeout;

};

typedef struct soap_client_param soap_client_param_t;

struct soap_client
{
  /* SOAP client parameter vector.  */
  struct _vector *sp_vec;
};

typedef struct soap_client soap_client_t;


#define soap_client_action_param_alloc soap_client_param_alloc

#ifdef __cplusplus
extern "C" {
#endif

slim_int
soap_client_action_param_alloc (struct upnp_client *uc, slim_char *in_action,
                                slim_char *in_browse_id, struct upnp_device *in_device,
                                struct upnp_service *in_service,
                                soap_client_func_t in_callback, soap_client_param_t **out_sp);

slim_int
soap_client_query_param_alloc (struct upnp_client *uc, slim_char *in_var_name,
                                slim_char *in_browse_id, struct upnp_device *in_device,
                                struct upnp_service *in_service,
                                soap_client_func_t in_callback, soap_client_param_t ** out_sp);

void
soap_client_param_free (soap_client_param_t *sp);

slim_int
soap_client_action (soap_client_param_t *sp);

slim_int
soap_client_get_var (soap_client_param_t *sp);

slim_int
soap_client_cancel (soap_client_param_t *sp);

slim_int
soap_client_delay_cancel(soap_client_param_t *sp);

soap_client_param_t *
soap_client_get_by_session_data (soap_client_t *soap, void *in_session_data);

soap_client_t *
soap_client_alloc (struct upnp_client *uc);

void
soap_client_free (soap_client_t *soap);

#ifdef __cplusplus
}
#endif

#endif /* NFLC_SOAP_CLIENT_H */
