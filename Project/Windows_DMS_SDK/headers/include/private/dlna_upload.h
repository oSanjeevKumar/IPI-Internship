/*
 * dlna_upload.h
 * Copyright (C) 2007-2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_DLNA_UPLOAD_H
#define NFLC_DLNA_UPLOAD_H

#include <dlna_up_api.h>
#include <nflc_upnp.h>

#define UP_DLNA_MANAGED_UPLOAD_CONTENT          (0x000001)
#define UP_DLNA_MANAGED_CREATE_CHILD_CONTAINER  (0x000002)
#define UP_DLNA_MANAGED_DESTROY_ITEM            (0x000004)

/*
  CTT Document, 7.3.118.4:
    bit 0 - Indicates support for OCM: upload content
    bit 1 - Indicates support for OCM: create child container
    bit 2 - Indicates support for OCM: destroy item
    bit 3 - Indicates support for OCM: upload content with OCM: destroy item
*/
#define UP_DLNA_MANAGED_DESTORY_CONTAINER (0x000008)  /* ZZZ: bit3 is "destory container"? */

#define dlna_create_folder_param upnp_create_folder_param_t

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef DLNA_SUPPORT_UPLOADER

upnp_upload_param_t*
dlna_create_upload_stream_content_param (dlna_object_t *dms_device, TDLNAObjectEventHandler in_obj_eh, 
                                         void *in_arg, up_stream_param_t *in_param);

/* Add 'parent_id' argument */
slim_int
dlna_create_object_item_from_file (dlna_client_t *self, sXML *doc, slim_char *in_full_path, 
				                           TDLNAObjectEventHandler in_obj_eh, void *in_arg, 
                                   dlna_object_t *parent_container, slim_char *in_title,
                                   slim_int in_notify_kbsize, slim_int in_upload_cap, dlna_object_t **out_upload_obj);

dlna_object_t*
dlna_create_object_item_from_stream (dlna_client_t *self, sXML *doc, TDLNAObjectEventHandler in_obj_eh, 
                                     void *in_arg, dlna_object_t *dms_device, 
                                     up_stream_param_t *in_param, 
                                     slim_int in_notify_kbsize);

dlna_object_t *
dlna_create_object_item_from_object (dlna_client_t *self, sXML *in_device_doc, dlna_object_t * in_obj, 
                                            dlna_object_t *in_parent, slim_char *in_title,
                                            TDLNAObjectEventHandler in_obj_eh, void *in_arg, slim_int in_notify_kbsize);


/* create child container in specified dms device */
dlna_object_t *
dlna_create_object_container(dlna_client_t *self, sXML *doc, slim_char *in_folder_name,
                              TDLNAObjectEventHandler in_obj_eh, void *in_arg, 
                              dlna_object_t *dms_device, slim_char *parent_id);

slim_int
dlna_create_object_result (struct dlna_client_tag *top, struct upnp_param_action *param);

slim_int
dlna_upload_post_content (dlna_client_t *self, dlna_object_t *upload_obj);

slim_int
dlna_object_cancel_uploading (dlna_object_t *self);

slim_int
dlna_object_stop_uploading (dlna_object_t *self);

dlna_object_t*
dlna_update_object (dlna_object_t *self, slim_char *object_id,
                           up_stream_param_t *current_param, up_stream_param_t *new_param,
                           TDLNAObjectEventHandler in_obj_eh, void *in_arg);

void 
dlna_update_object_result (dlna_client_t *top, struct upnp_param_action *in_param);

dlna_object_t *
dlna_destroy_object (dlna_client_t *self, TDLNAObjectEventHandler in_obj_eh, 
                     void *in_arg, dlna_object_t *in_content);

slim_int
dlna_destroy_object_result (dlna_client_t *top, struct upnp_param_action *in_param);

slim_int
dlna_get_upload_profiles (dlna_client_t *self, TDLNAObjectEventHandler in_obj_eh,
                          void *in_arg, dlna_object_t *dms_device, slim_char *in_param);

void
dlna_free_upnp_upload_param (upnp_upload_param_t *in_param);

void
dlna_free_upnp_update_param (upnp_update_param_t *in_param);

upnp_upload_param_t*
dlna_create_upload_stream_param (TDLNAObjectEventHandler in_obj_eh, void *in_arg, up_stream_param_t *in_param);

#endif /* DLNA_SUPPORT_UPLOADER */

slim_int 
dlna_upload_capable (dlna_object_t *device);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* NFLC_DLNA_UPLOAD_H */
