/*
 * upnp_device.h
 * Copyright (C) 2007-2009 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */

#ifndef NFLC_UPNP_DEVICE_H
#define NFLC_UPNP_DEVICE_H

/* Time out for subscription.  */
#define UPNP_SUBSCRIBE_TIME_OUT CP_MINIMUM_SUBSCRIPTION_TIME

/* UPnP service variables.  */
struct upnp_service_variable
{
  struct upnp_service_variable *next;
  struct upnp_service_variable *prev;

  /* Variable string.  */
  slim_char *str;

  /* Variable value.  */
  slim_char *value;
};

/* UPnP service.  */
struct upnp_service
{
  struct upnp_service *next;
  struct upnp_service *prev;

  /* Service type string.  This is pre-defined.  */
  slim_char *type;

  /* UDN of the device.  */
  slim_char *udn;

  /* Service ID, control URL and event URL.  These are given at
     UPnP registration stage.  */
  slim_char *service_id;
  slim_char *scpd_url;
  slim_char *control_url;
  slim_char *event_url;

  /* Service variable count and it's value. */
  List (struct upnp_service_variable *) var_list;

  /* Service description advertised by device */
  sXML *doc;
  slim_bool doc_updating;

  /* HTTP client connection for the service description file. */
  struct http_client *hc;

  /* pinfo */
  slim_char *source_protocol_info;
  slim_char *sink_protocol_info;

};

/* UPnP device.  */
struct upnp_device
{
  /* Linked list.  */
  struct upnp_device *next;
  struct upnp_device *prev;

  /* UPnP client backpointer.  */
  struct upnp_cp *cp;

#ifdef DEVELOPMENT_ENABLE_DIAGC
  struct upnp_cp *dmcp;
#endif /* DEVELOPMENT_ENABLE_DIAGC */

#ifdef DEVELOPMENT_ENABLE_LPC
  struct upnp_cp *lpcp;
#endif /* DEVELOPMENT_ENABLE_LPC */

  /* UDN of the device.  */
  slim_char *udn;

  /* Device type.  */
  slim_char *type;
	/* SERVER in SSDP NOTIFY header */
	slim_char *server;
	slim_bool is_root;
    /* revise: Klaus to review this */
	slim_bool was_reported;
#ifdef DLNA_SUPPORT_RUIPL
  /* rui_level indicates whether device have RUI capability, and
     which level device have.                                     */
  upnp_rui_level_type rui_level;
#endif /* DLNA_SUPPORT_RUIPL */

  /* Device document.  */
  sXML *doc;

  slim_int seek_mode_support;

  /* Location of the device.  */
  slim_char *url;

  /*candidate url*/
  slim_char *candidate_url;
  
  /* Device base url. */
  slim_char *base_url;
  
  /* Description is read.  */
  slim_bool have_description;

  /* HTTP client connection for the device description file.  */
  struct http_client *hc;

  /* Max-age in CACHE-CONTROL header. */
  slim_int max_age;

  /* Incomming interface. */
  slim_int ifindex;

  /* Time out. */
  dlna_progress_handle e_timeout;

  /* device update */
  dlna_progress_handle e_device_update_timer;

  dlna_progress_handle e_device_free_timer;

  /* Services.  */
  List (struct upnp_service *) services;
};

struct upnp_client;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus  */

struct upnp_device *
upnp_device_lookup_by_udn (struct upnp_client *uc, 
                           slim_char *in_device_udn);
struct upnp_service *
upnp_device_service_lookup (struct upnp_device *device,
                            slim_char *service_type);

struct upnp_service *
upnp_device_service_lookup_by_id (struct upnp_device *device,
                                   slim_char *service_id);

struct upnp_service_variable *
upnp_service_variable_alloc (struct upnp_service *service);

slim_int
upnp_service_variable_free (struct upnp_service *service,
                            struct upnp_service_variable *var);

struct upnp_service *
upnp_service_alloc (struct upnp_device *device);

slim_int
upnp_service_free (struct upnp_device *device, struct upnp_service *service);

struct upnp_service *
upnp_service_lookup_by_udn (struct upnp_client *uc, 
                            slim_char *in_device_udn, slim_char *in_service_type);

struct upnp_service *
upnp_service_lookup_by_service(struct upnp_client *in_uc, struct upnp_service *in_service);

struct upnp_device *
upnp_device_lookup (struct upnp_client *uc,
                    slim_char *device_type, slim_char *udn);

struct upnp_device *
upnp_device_lookup_by_device (struct upnp_client *in_uc, struct upnp_device *in_device);

struct upnp_device *
upnp_device_get (struct upnp_client *uc, slim_char *device_type,
                 slim_char *udn);

slim_int
upnp_avts_update_device_capabilies(struct upnp_device *in_device, sXML *in_serviceDoc);

slim_int
upnp_device_update (struct upnp_client *uc, sXML *doc, slim_char *url,
                    slim_int max_age, slim_int ifindex);

slim_int
upnp_device_free (struct upnp_client *uc, struct upnp_device *device);

slim_int
upnp_device_delete_all (struct upnp_client *uc);

struct upnp_device *
upnp_device_alloc (struct upnp_client *uc, slim_char *in_device_type, slim_char *in_udn);

slim_int
upnp_device_is_soap_action_supported (struct upnp_device *device, slim_char *in_service_type, slim_char *in_soap_action);

slim_int
upnp_service_parse_state_vars (struct upnp_client *uc, struct upnp_service *service);


#ifdef __cplusplus
}
#endif    /* __cplusplus */

#endif /* NFLC_UPNP_DEVICE_H */
