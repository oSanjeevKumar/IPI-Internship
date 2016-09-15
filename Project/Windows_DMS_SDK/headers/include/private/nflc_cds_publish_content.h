
/*
 * \file nflc_cds_publish_content.h
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

#ifndef NFLC_CDS_PUBLISH_CONTENT_H
#define NFLC_CDS_PUBLISH_CONTENT_H

#include <dlna_peer.h>
#include <nflc_contents.h>
#include <dms_publish_storage_api.h>
#include <nflc_cds_contents_index.h>

/**
 * @cond DEV_DOXYGEN_ENA
 * @addtogroup PublishContentAPIDev Publish Content API Development
 * @{
 */

/** Premium content has three (3) sub folders in virtual folders' hierarchy. */
#define CDS_VCONTAINER_LIVE_CONTENT_ID     "lc_id"  /**< Premium content > Live Content */
#define CDS_VCONTAINER_ONLINE_CONTENT_ID   "oc_id"  /**< Premium content > Online Content */
#define CDS_VCONTAINER_RECORDED_CONTENT_ID "rc_id"  /**< Premium content > Recorded Content */

/** Specifies unlimited number of devices allowed for distribution of the content in home network. */
#define CDS_PUBLISHER_DEVICES_ALLOWED_UNLIMITED DLNA_DEVICES_ALLOWED_UNLIMITED

/** List of references for a media item from external API. */
typedef List(TDMSPublishContentRef*) publish_references_list_t;

/** List of references for a media item. */
typedef List(cres_t*) cds_publisher_ref_list_t;

/**
 * \brief CDS publisher error codes.
 *
 * Further information on an error is provided via standard error stream.
 */
enum cds_publisher_return {
	CDS_PUBLISHER_ERROR_OK,             /**< All went OK. */
	CDS_PUBLISHER_ERROR_ITEM_EXISTS,    /**< Attempt to insert an item more then once. */
	CDS_PUBLISHER_ERROR_OUT_OF_MEMORY,  /**< Memory allocation failed. */
	CDS_PUBLISHER_ERROR_DATABASE,       /**< Database call returned an error. */
	CDS_PUBLISHER_ERROR_INVALID_PARAM   /**< Invalid parameter was passed to a function. */
};
typedef enum cds_publisher_return cds_publisher_return_t;

/**
 *  \brief CDS publisher structure will contain a database link for all published content via the publisher API.
 */
typedef struct cds_publisher_online
{
	cds_database_info* main_db;   /**< Main database link */
	cds_database_info* index_db;  /**< Index database link - used only and ONLY while indexing the recorded readable content. */
	cds_db_get_content_storage_info* storage_info; /**< Storage info - mandatory for browse operations, backward compatibility. */
	slim_char *device_uuid;       /**< Device UUID - mandatory for browse operations, backward compatibility. */
} cds_publisher_online_t;

/**
 *  \brief CDS publisher stream object rights structure.
 */
#ifdef DEVELOPMENT_PUBLISH_CONTENT_OBJECT_RIGHTS_API
typedef struct {
	slim_bool is_drm_protected;
	slim_bool allow_dtcp_protection;
	dlna_time_t subscription_time;
#ifdef HAVE_DTCP
	slim_int cci;
	slim_int retention_state;
#endif
	slim_int concurrent_viewing;
	slim_int playcount;
	slim_bool allow_distribution;
	slim_int device_accessed_count; /**< The number of different devices which already accessed
	                                     a media item. Value can reach no_of_devices_allowed. */
	slim_int no_of_devices_allowed;
} stream_object_rights_t;
#endif

/**
 * \brief Allocate publisher object for CDS.
 * \param publisherDBLocation - location for the database to be used for the published content.
 * \return
 *         \li \c true - on success,
 *         \li \c false - on failure.
 * \note Further data on failure in std error output stream.
 */
slim_int
cds_alloc_publisher(slim_char* publisherDBLocation);

/**
 * \brief Free publisher object for CDS.
 */
void
cds_free_publisher();

/**
 * \brief Function creates a set of virtual folders for the published content.
 * The folders are as follows: Premium > LiveContent (id lc_id), Premium > OnlineContent (id oc_id) and Premium > RecordedContent (id rc_id).
 * \param cm - pointer to contents manager structure,
 * \param node_doc - XML node caring the exact folders structure from configuration file.
 * \return
 *         \li \c true - on success,
 *         \li \c false - on failure.
 * \note Further data on failure in std error output stream.
 */
slim_int
cds_add_predefined_published_virtual_containers(cm_t *cm, struct _sXML *node_doc);

/**
 * \brief Function adds a virtual container for the published content.
 * \param cm - pointer to contents manager structure,
 * \param parent_id - unique string id of the parent container already added,
 * \param id - unique string id to be given to the created container,
 * \param id - title to be given to the created container.
 * \return CDS_PUBLISHER_ERROR_ITEM_EXISTS or CDS_PUBLISHER_ERROR_DATABASE or CDS_PUBLISHER_ERROR_ITEM_OK.
 */
slim_int
cds_add_published_virtual_container(cm_t *cm, slim_char *parent_id, slim_char *id, slim_char *title);

/**
 * \brief Function adds media item.
 * \param parent_id - unique string id of the parent container already added,
 * \param cinfo - infomation structure on the media item to be added.
 * \return CDS_PUBLISHER_ERROR_INVALID_PARAM or CDS_PUBLISHER_ERROR_ITEM_EXISTS
 *  or CDS_PUBLISHER_ERROR_DATABASE or CDS_PUBLISHER_ERROR_OUT_OF_MEMORY or CDS_PUBLISHER_ERROR_ITEM_OK.
 */
cds_publisher_return_t
cds_add_published_media_item(slim_char *parent_id, content_index_object_info *cinfo, slim_int flags);

#ifdef DEVELOPMENT_PUBLISH_CONTENT_OBJECT_RIGHTS_API
/**
 * \brief Function adds media item - readable recorded content to be indexed.
 * \param parent_id - unique string id of the parent container already added,
 * \param cinfo - infomation structure on the media item to be added.
 * \return CDS_PUBLISHER_ERROR_INVALID_PARAM or CDS_PUBLISHER_ERROR_ITEM_EXISTS
 *  or CDS_PUBLISHER_ERROR_DATABASE or CDS_PUBLISHER_ERROR_OUT_OF_MEMORY or CDS_PUBLISHER_ERROR_ITEM_OK.
 */
cds_publisher_return_t
cds_index_add_published_media_item(slim_char *parent_id, content_index_object_info *cinfo, slim_int flags,
		publish_references_list_t *ref_list, stream_object_rights_t *obj_rights);
#else
cds_publisher_return_t
cds_index_add_published_media_item(slim_char *parent_id, content_index_object_info *cinfo, slim_int flags,
		publish_references_list_t *ref_list);
#endif

cds_publisher_return_t
cds_add_published_media_item_reference(content_index_object_info *cinfo, cres_t *res_item);

cds_publisher_ref_list_t*
cds_alloc_publisher_reference_list(publish_references_list_t *list);

void
cds_free_publisher_reference_list(cds_publisher_ref_list_t *list);

cds_publisher_return_t
cds_add_published_media_item_reference_list(content_index_object_info *cinfo,
		publish_references_list_t *res_item_list);

#ifdef HAVE_DTCP
cds_publisher_return_t
cds_add_published_media_item_cci(slim_char *ext_id, slim_int cci);
#endif

#ifdef DEVELOPMENT_PUBLISH_CONTENT_OBJECT_RIGHTS_API
cds_publisher_return_t
cds_add_published_media_item_object_rights(slim_int meta_id, stream_object_rights_t *in_object_rights);

cds_publisher_return_t
cds_get_published_media_item_object_rights(slim_char *id, stream_object_rights_t *out_object_rights);

cds_publisher_return_t
cds_update_published_media_item_object_rights(slim_char *id, stream_object_rights_t *in_object_rights);

slim_int
cds_published_media_item_current_dev_viewers(slim_char *uri);

slim_int
cds_published_media_item_allowed_dev_viewers(slim_char *uri);

slim_int
cds_published_media_item_update_dev_viewers(slim_char *uri, slim_int in_viewers_count);
#endif /* DEVELOPMENT_PUBLISH_CONTENT_OBJECT_RIGHTS_API */

contents_t *
cds_published_media_item_get_content(cm_t *cm, slim_char *uri, slim_int id);

cds_publisher_return_t
cds_delete_published_media_item(slim_char *path);

cds_publisher_return_t
cds_delete_published_virtual_container(slim_char *folder_id);

/**
 * \brief Sets up publish content database location.
 * \param publisherDBLocation - location for the database to be used for the published content.
 * \return
 *         \li \c true - on success,
 *         \li \c false - on failure.
 * \note Further data on failure in std error output stream.
 */
slim_int
cds_publish_content_set_database(slim_char* in_databse_location);

/**
 * \brief Deletes database file a the current location which is then set to null pointer.
 * \return
 *         \li \c true - on success,
 *         \li \c false - on failure.
 * \note Further data on failure in std error output stream.
 */
slim_int
cds_publish_content_delete_database();

slim_int
cds_probe_published_root_container(slim_char* container_id, slim_bool from_top);

slim_int
cds_probe_managed_containers(slim_char* container_id);

slim_int
cds_probe_published_device(slim_char* device_id);

slim_int
cds_browse_published_container(cm_t *cm, slim_char* container_id, slim_word sindex,
							   slim_word rcount, slim_word *matches, slim_word *total_matches,
							   TCDSSortParam *sort_param, vector results, slim_int device_access_level);

slim_int
cds_browse_get_premium_childs_count(cm_t *cm, slim_char* container_id);

contents_t*
cds_publisher_get_managed_container(cm_t* cm, slim_char* id);

/**
 * @}
 * @endcond
 */

#endif
