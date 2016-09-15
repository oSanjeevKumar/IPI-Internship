
/*
 * \file nflc_dms_publish_content.h
 *
 * Copyright (C) 2012 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 *
 *    __
 *  /    \
 * | STOP |
 *  \ __ /
 *    ||
 *    ||
 *    ||
 *    ||
 *    ||
 *  ~~~~~~ Before you put something here, please keep in mind the file organization:
 *  - Headers
 *  - Macros
 *  - Type definitions
 *  - Declarations for global functions
 *
 *  Help us fight against global warming, put your comments in d'oxygen.
 */

#ifndef NFLC_DMS_PUBLISH_CONTENT_H
#define NFLC_DMS_PUBLISH_CONTENT_H

#include <dms_api.h>

/**
 * @cond DEV_DOXYGEN_ENA
 * @addtogroup PublishContentAPIDev Publish Content API Development
 * @{
 */

TDMSReturn
dms_add_virtual_container(struct dms *self, TDMSPublishVirtualContainer *in_container_info);

TDMSReturn
dms_delete_virtual_container(struct dms *self, slim_char *in_folder_id);

#ifdef DEVELOPMENT_PUBLISH_CONTENT_OBJECT_RIGHTS_API
TDMSReturn
dms_add_live_content(struct dms *self, TDMSPublishContent *in_content_info, TDMSObjectRights *in_object_rights);
#else
TDMSReturn
dms_add_live_content(struct dms *self, TDMSPublishContent *in_content_info);
#endif

TDMSReturn
dms_delete_published_content(struct dms *self, slim_char *in_path);

#ifdef DEVELOPMENT_CONTENT_API
TDMSReturn
dms_getRecordingContent(TDMS self, TDMSContentProperty **out_properties, slim_word *number_returned, slim_word *total_count, slim_word start_index, slim_word request_count);
#endif /* DEVELOPMENT_CONTENT_API */

//#ifdef DEVELOPMENT_ENABLE_PUBLISH_CONTENT
#ifdef DEVELOPMENT_PUBLISH_ONLINE_RECORDED_CONTENT_API
TDMSReturn
dms_publish_content_set_database(struct dms *self, slim_char* in_databse_location);

TDMSReturn
dms_publish_content_delete_database(struct dms *self);
#endif /* DEVELOPMENT_PUBLISH_ONLINE_RECORDED_CONTENT_API */

/**
 * @}
 * @endcond
 */

#endif
