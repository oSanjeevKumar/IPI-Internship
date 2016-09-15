/*
 * soap_server.h
 * Copyright (C) 2007 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2005, 2006 IP Infusion, Inc. All Rights Reserved.  */

/* SOAP server.  */

#ifndef NFLC_SOAP_SERVER_H
#define NFLC_SOAP_SERVER_H

//Forward declarations
struct upnp_server;
struct upnp_action_response;

/* UPnP SOAP action request parameter.  */
struct upnp_action_request
{
  /* Service ID.  */
  slim_char *id;

  /* Service type.  */
  slim_char *type;

  /* SOAP action name.  */
  slim_char *action_name;

  /* SOAP whole document.  */
  sXML *soap_doc;

  /* SOAP action.  */
  sXML *action_doc;

  /* SOAP result document.  */
  sXML *result_doc;

  /* on which the action request is received */
  http_session_t *session;

  /* indicate session is persistent or not */
  slim_bool is_persistent_session;
  
  /* Incoming interface.  */
  slim_int incoming_ifindex;

  /* SOAP action flag.  */
  slim_word soap_action_flags;
};

/* UPnP SOAP action response.  */
struct upnp_action_response
{
  struct upnp_action_request *r;
  slim_int retval;
};

/* UPnP SOAP query variable.  */
struct upnp_query_variable
{
  /* Service ID.  */
  slim_char *id;

  /* Service Type.  */
  slim_char *type;

  /* SOAP query variable name.  */
  slim_char *name;

  /* SOAP variable result.  */
  slim_char *result;

  /* Incoming interface.  */
  slim_int incoming_ifindex;

  /* Free or keep result.  */
  enum {
    UPNP_VAR_FREE_RESULT,
    UPNP_VAR_KEEP_RESULT
  } free_result;
};

/* Prototypes.  */
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Process SOAP message.  */
void
soap_server_process (http_session_t *in_session, http_message_t *in_http,
                     http_receiver_t *in_receiver);

sXML *
soap_get_action_doc(sXML *doc, slim_char *action_name);

slim_int
soap_action_reply(struct upnp_server *us, struct upnp_action_response *response);

slim_int
soap_action_reply_with_doc (struct upnp_server *us, struct upnp_action_response *in_response, sXML *in_doc);

sXML *
soap_action_response_header (struct upnp_action_request *in_action_request);
slim_int
soap_action_response(http_session_t *in_session, 
                     slim_bool in_persistent, sXML *in_doc);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_SOAP_SERVER_H */
