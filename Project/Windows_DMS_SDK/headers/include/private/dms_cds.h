/*
 * dms_cds.h
 * Copyright (C) 2007-2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2005 IP Infusion, Inc. All Rights Reserved.  */

#ifndef NFLC_DMS_CDS_H
#define NFLC_DMS_CDS_H

#include <upnp_cds.h>


/*
 * UPNP CDS 1.0 - 2.6. Eventing and Moderation, Table 8:
 * Max EventRate for ContainerUpdateIDs and SystemUpdateID is equal: 1 event per 2 seconds
 *
 * UPNP CDS 2.0 - 2.4 Eventing and Moderation, Table 2-5:
 * Max EventRate for ContainerUpdateIDs and SystemUpdateID is equal: 1 event per 0.2 seconds
 *
 * UPNP CDS 3.0 - 2.4 Eventing and Moderation, Table 2-7:
 * Max EventRate for ContainerUpdateIDs and SystemUpdateID is equal: 1 event per 0.2 seconds
 */

#define SYSTEM_UPDATE_ID_EVENT_TIMEVAL {2, 0}


typedef struct subscribe_info
{
  struct subscribe_info *next;
  struct subscribe_info *prev;

  upnp_sid_t sid;
  slim_word  update_id;
} subscribe_info_t;



/* ContentDirectory service.  */
struct dms_cds
{
  /* DMS service base structure.  */
  struct dms_service base;

  upnp_cds *upnp_cds;

  List(subscribe_info_t *) subscribe_info_list;

  dlna_progress_handle e_system_update_id_timer;

  dlna_progress_handle e_partial_rebuild_timer;

#if defined (ENABLE_CDS_1_0_CONTAINER_UPDATE_IDS)

  struct sbuf * container_update_ids_doc;

#endif /* ENABLE_CDS_1_0_CONTAINER_UPDATE_IDS */


  /* Current contents ID.  */
  slim_char *current_cid;
};



#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

contents_t *
dms_cds_current_content (struct dms *top);

struct dms_service *
dms_cds_alloc (struct dms *top);

int
dms_cds_free (struct dms_service *s);

slim_int
dms_cds_init (struct dms_cds *s);

void
dms_cds_contents_update (struct dms_cds *s);

#ifdef HAVE_DTCP
slim_int
dms_cds_set_drm_entry (struct dms_service *service, drm_entry_t *in_dtcp_entry);

void
dms_cds_set_drm_proc (struct dms_service *service, get_drm_info in_proc);

void
dms_cds_delete_drm_entry (struct dms_service *service, slim_int in_type);

void
dms_cds_delete_drm_proc (struct dms_service *service);

#endif /* HAVE_DTCP */


#if defined (RA_USE_RID_HEADER)
slim_int
dms_cds_rid_permission_add(struct dms_cds *service, slim_char *rid, slim_word permission) ;
slim_int
dms_cds_rid_permission_remove(struct dms_cds *service, slim_char *rid) ;
#endif //#if defined (RA_USE_RID_HEADER)

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_DMS_CDS_H */
