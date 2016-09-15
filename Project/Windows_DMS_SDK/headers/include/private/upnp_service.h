/*
 * upnp_service.h
 * Copyright (C) 2007 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2005 IP Infusion, Inc. All Rights Reserved.  */

#ifndef NFLC_UPNP_SERVICE_H
#define NFLC_UPNP_SERVICE_H

/* Service information.  */
struct upnp_service_info
{
  /* Linked list.  */
  struct upnp_service_info *next;
  struct upnp_service_info *prev;

  /* Event manager.  */
  dlna_progress progress;

  /* UDN.  */
  slim_char *udn;

  /* Service type.  */
  slim_char *type;

  /* Service ID.  */
  slim_char *service_id;

  /* SCPDURL.  */
  slim_char *scpd_url;

  /* Control URL.  */
  slim_char *control_url;

  /* Event sub URL.  */
  slim_char *event_url;

  /* Number of subscription.  */
  slim_int subscribe_num;

  /* Subscription list.  */
  List(struct gena_subscribe *) subscribe_list;
  
  /* event cached */
  slim_bool b_cached;

  /* frequency event */
  dlna_progress_handle e_frequency;
};
typedef struct upnp_service_info upnp_service_info_t;

/* Service table.  */
struct upnp_service_table
{
  /* URL base in service description.  */
  slim_char *url_base;

  /* Service list.  */
  List(upnp_service_info_t *) service_list;
};

typedef struct upnp_service_table upnp_service_table_t;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void
upnp_service_subscribe_add(upnp_service_info_t *self, struct gena_subscribe *in_gena_subscribe);

void
upnp_service_subscribe_remove(upnp_service_info_t *self, struct gena_subscribe *in_gena_subscribe);

struct gena_subscribe *
upnp_service_subscribe_lookup(upnp_service_info_t *self, upnp_sid_t in_subscription_id);

struct gena_subscribe *
upnp_service_subscribe_lookup_by_delivery_url(upnp_service_info_t *self, slim_char *in_url);

slim_int
upnp_service_subscribe_count(upnp_service_info_t *self);

slim_int
upnp_service_table_init (upnp_service_table_t *table, sXML *doc, dlna_progress em);

void
upnp_service_table_free (upnp_service_table_t * table);

void
upnp_service_table_subscribe_remove_all(upnp_service_table_t *self);

upnp_service_info_t *
upnp_service_lookup_by_id (upnp_service_table_t *table, slim_char *service_id);

slim_int
upnp_service_lookup_by_event_url (upnp_service_table_t *in_table, slim_char *in_event_url, upnp_service_info_t **out_service);

slim_int
upnp_service_lookup_by_control_url (upnp_service_table_t *in_table, slim_char *in_control_url, upnp_service_info_t **out_service);

#ifdef __cplusplus
}
#endif	/* __cplusplus */

#endif /* NFLC_UPNP_SERVICE_H */
