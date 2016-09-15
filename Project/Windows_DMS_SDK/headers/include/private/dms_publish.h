/*
 * dms_publish.h
 * DMS Publish Header (Private header)
 * Copyright (C) 2014 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef DMS_PUBLISH_H_
#define DMS_PUBLISH_H_

#include <dms_api.h>

slim_int
dms_publish_storage_add(TDMS dms, TDMSPublishStorage *in_storage, TDMSObjectRights *in_objectrights);

slim_int
dms_publish_storage_update(TDMS dms, TDMSPublishStorage *in_storage, TDMSObjectRights *in_objectrights);

slim_int
dms_publish_storage_del(TDMS dms, slim_char *in_storagePath);

slim_int
dms_publish_content_add(TDMS self, TDMSPublishContent *in_contentInfo);

slim_int
dms_publish_content_delete(TDMS self, slim_char *in_contentId);

slim_int
dms_publish_virtual_folder_add(TDMS self, TDMSPublishVirtualContainer *in_containerInfo);

slim_int
dms_publish_virtual_folder_delete(TDMS self, slim_char *in_containerId);

contents_type_t
dms_publish_content_map_ctype(TDMSContentType in_type);

#endif /* DMS_PUBLISH_H_ */
