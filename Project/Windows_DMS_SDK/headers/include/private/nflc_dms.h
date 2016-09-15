/*
 * nflc_dms.h
 * Copyright (C) 2007-2014 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */


#ifndef NFLC_DMS_H
#define NFLC_DMS_H

#include <dms_api.h>
#ifndef DEVELOPMENT_ENABLE_PUBLISH_CONTENT
#include <dms_publish_storage_api.h>
#endif /*DEVELOPMENT_ENABLE_PUBLISH_CONTENT*/
#include <upnp_server.h>
#include <gena_server.h>
#include <soap_server.h>
#include <storage_manager.h>

#ifdef DEVELOPMENT_CONTENT_AGGREGATION
#include <content_aggregation.h>
#endif

#if defined(DLNA_SUPPORT_DMSCP) || defined(DEVELOPMENT_CONTENT_AGGREGATION)
#include <dlna_client.h>
#include <upnp_client.h>
#endif /* DLNA_SUPPORT_DMSCP || DEVELOPMENT_CONTENT_AGGREGATION */

#ifdef DLNA_SUPPORT_DMSCP
#include <dms_api_csync.h>
#include <dlna_cs.h>
#endif /* DLNA_SUPPORT_DMSCP */

/* DMS services.  */
#define DMS_SERVICE_CDS         (0)     /* 5.1.1 ContentDirectory.  */
#define DMS_SERVICE_CMS         (1)     /* 5.1.2 ConnectionManager.  */

/* C.K.20130806: rewrite this for better maintainance */

/* 5.1.3 Scheduled Recording.  */
#ifdef  DLNA_SUPPORT_SRS
  #define DMS_SERVICE_SRS       (DMS_SERVICE_CMS + 1)
#else
  #define DMS_SERVICE_SRS       (DMS_SERVICE_CMS)
#endif /* DLNA_SUPPORT_SRS */

#ifdef DLNA_SUPPORT_RUISRC
  #define DMS_SERVICE_RUIS      (DMS_SERVICE_SRS + 1)
#else
  #define DMS_SERVICE_RUIS      (DMS_SERVICE_SRS)
#endif /* DLNA_SUPPORT_RUISRC */

#ifdef DLNA_SUPPORT_XMMRR
  #define DMS_SERVICE_XMMRR     (DMS_SERVICE_RUIS + 1)
#else
  #define DMS_SERVICE_XMMRR     (DMS_SERVICE_RUIS)
#endif /* DLNA_SUPPORT_XMMRR */

#ifdef DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2
  #define DMS_SERVICE_BMS       (DMS_SERVICE_XMMRR + 1)
#else
  #define DMS_SERVICE_BMS       (DMS_SERVICE_XMMRR)
#endif /* DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2 */

#ifdef DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_1
  #define DMS_SERVICE_EMS       (DMS_SERVICE_BMS + 1)
#else
  #define DMS_SERVICE_EMS       (DMS_SERVICE_BMS)
#endif /* DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_1 */

#define DMS_SERVICE_MAX         (DMS_SERVICE_EMS + 1)

#if 0
#ifdef  DLNA_SUPPORT_SRS
#define DMS_SERVICE_SRS         (2)     /* 5.1.3 Scheduled Recording.  */
	#ifdef DLNA_SUPPORT_RUISRC
		#define DMS_SERVICE_RUIS         (3)     /*   */
			#ifdef  DLNA_SUPPORT_XMMRR
				#define DMS_SERVICE_XMMRR      (4)
				#ifdef DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2
					#define DMS_SERVICE_BMS		(5)
				#endif /* DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2 */
				#define DMS_SERVICE_MAX        (6)
			#else /* DLNA_SUPPORT_XMMRR */
				#ifdef DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2
					#define DMS_SERVICE_BMS		(4)
				#endif /* DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2 */
				#define DMS_SERVICE_MAX        (5)
			#endif /* DLNA_SUPPORT_XMMRR */
	#else /* DLNA_SUPPORT_RUISRC */
			#ifdef  DLNA_SUPPORT_XMMRR
				#define DMS_SERVICE_XMMRR      (3)
				#ifdef DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2
					#define DMS_SERVICE_BMS		(4)
				#endif /* DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2 */
				#define DMS_SERVICE_MAX        (5)
			#else /* DLNA_SUPPORT_XMMRR */
				#ifdef DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2
					#define DMS_SERVICE_BMS		(3)
				#endif /* DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2 */
				#define DMS_SERVICE_MAX        (4)
			#endif /* DLNA_SUPPORT_XMMRR */
	#endif /* DLNA_SUPPORT_RUISRC */
#else /* DLNA_SUPPORT_SRS */
	#ifdef DLNA_SUPPORT_RUISRC
		#define DMS_SERVICE_RUIS         (2)     /*   */
                    #ifdef  DLNA_SUPPORT_XMMRR
                        #define DMS_SERVICE_XMMRR      (3)
						#ifdef DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2
							#define DMS_SERVICE_BMS		(4)
						#endif /* DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2 */
                        #define DMS_SERVICE_MAX        (5)
                    #else /* DLNA_SUPPORT_XMMRR */
						#ifdef DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2
							#define DMS_SERVICE_BMS		(3)
						#endif /* DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2 */
                        #define DMS_SERVICE_MAX        (4)
                    #endif /* DLNA_SUPPORT_XMMRR */
	#else /* DLNA_SUPPORT_RUISRC */
                    #ifdef  DLNA_SUPPORT_XMMRR
                        #define DMS_SERVICE_XMMRR      (2)
						#ifdef DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2
							#define DMS_SERVICE_BMS		(3)
						#endif /* DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2 */
                        #define DMS_SERVICE_MAX        (4)
                    #else /* DLNA_SUPPORT_XMMRR */
						#ifdef DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2
							#define DMS_SERVICE_BMS		(2)
						#endif /* DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2 */
                        #define DMS_SERVICE_MAX        (3)
                    #endif /* DLNA_SUPPORT_XMMRR */
	#endif /* DLNA_SUPPORT_RUISRC */
#endif /* DLNA_SUPPORT_SRS */
#endif /* 0 */

/* DMS services string.  */
#define DMS_SERVICE_ID_CDS      ((slim_char *) "ContentDirectory")
#define DMS_SERVICE_ID_CMS      ((slim_char *) "ConnectionManager")

#ifdef  DLNA_SUPPORT_SRS
#define DMS_SERVICE_ID_SRS      ((slim_char *) "ScheduledRecording")
#endif /*DLNA_SUPPORT_SRS*/

#ifdef  DLNA_SUPPORT_XSRS
#define DMS_SERVICE_ID_XSRS      ((slim_char *) "X_ScheduledRecording")
#endif /*DLNA_SUPPORT_XSRS*/

#ifdef  DLNA_SUPPORT_RUISRC
#define RUIS_SERVICE_ID_RUIS      ((slim_char *) "RemoteUIServer1")
#endif /* DLNA_SUPPORT_RUISRC */

#ifdef  DLNA_SUPPORT_XMMRR
#define DMS_SERVICE_ID_XMMRR      ((slim_char *) "X_MS_MediaReceiverRegistrar")
#endif /* DLNA_SUPPORT_XMMRR */

#ifdef DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2
#define DMS_SERVICE_ID_BMS      ((slim_char *) "BasicManagement")
#endif /* DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2 */

#ifdef DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_1
#define DMS_SERVICE_ID_EMS      ((slim_char *) "EnergyManagement")
#endif /* DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_1 */


//Forward declarations
struct upnp_subscribe_request;
struct upnp_subscribe_event;

struct service_property
{
  /* Linked list.  */
  struct service_property *next;
  struct service_property *prev;

  slim_char *name;
  slim_char *value;
};
typedef struct service_property service_property_t;

typedef List(service_property_t*) service_property_list;

/* DMS service base structure.  */
struct dms_service
{
  /* Backpoiner to the top.  */
  struct dms *top;

  /* Sercie ID.  */
  slim_char *id;

  service_property_list property_list;

  /* Member functions.  */
  slim_int (*start_proc) (struct dms_service *);
  slim_int (*stop_proc) (struct dms_service *);
  slim_int (*subscribe_proc) (struct dms_service *, struct upnp_subscribe_request *);
  slim_int (*get_var_proc) (struct dms_service *, struct upnp_query_variable *);
  slim_int (*action_proc) (struct dms_service *, struct upnp_action_request *);
  slim_int (*subscription_event_proc) (struct dms_service *, struct upnp_subscribe_event*);
};

/*This structure shall be used further by DMS to store the directory paths*/
typedef struct dms_configuration
{
	slim_char* data_dir;
	slim_char* xml_dir;
#ifdef DLNA_SUPPORT_SRS
	slim_char* srs_dir;
#endif /*DLNA_SUPPORT_SRS*/
} dms_config_t;

struct dms
{
  /* UPnP server pointer.  */
  struct upnp_server *us;

  /* UI callback function.  */
  TDMSEventCallback async_callback;

  /* Callbacks.  */
  struct dms_service *(*service_lookup) (struct dms *, slim_int);

  /* DMS services.  */
  struct dms_service *service[DMS_SERVICE_MAX];

  /* push module (+PU+) */
  struct dms_push_tag *dms_push;

  /* ssdp common module */
  struct dlna_ssdp_tag *ssdp_common;

  /* usb storage manager */
  storage_manager_t storage_manager;

  /* publish folder update handle */
  void *update_handle;

  /* publish folder update handle */
  void *load_handle;

  /* publish folder update handle */
  void *save_handle;

  /* */
  void *access_callback_arg;

#ifdef DEVELOPMENT_CONTENT_AGGREGATION
  ca_t ca;
#endif /* DEVELOPMENT_CONTENT_AGGREGATION */

#if defined(DLNA_SUPPORT_DMSCP) || defined(DEVELOPMENT_CONTENT_AGGREGATION)
  struct upnp_client *uc;
  struct dlna_client_tag dlna_client;
#endif /* DMS_CSYNC_APPS || DEVELOPMENT_CONTENT_AGGREGATION */

#ifdef DLNA_SUPPORT_DMSCP
  TDLNAEventHandler callback;
  void *arg;
  csync_t*  cs;
#endif /* DLNA_SUPPORT_DMSCP */
  dms_config_t dms_dir_config;
  TDMSStorageContentRescanCallback storageContentRescanCallback;

  /* Generic callback */
  slim_int state_cb_cat;        /* state callback category */
  TDMSStateCallback state_cb;   /* state callback function */
  void *state_cb_arg;           /* state callback argument */
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Prototypes.  */

/* Allocate DMS.  */
TDMS
dms_alloc(dlna_progress in_p, TDMSEventCallback callback,
    slim_half in_port,
    slim_char * in_data_dir,
    slim_char * in_xml_dir,
    slim_word dms_flags);

/* Free DMS.  */
TDMSReturn
dms_free (TDMS self);

#if defined(DLNA_SUPPORT_DMSCP) || defined(DEVELOPMENT_CONTENT_AGGREGATION)
slim_int
dms_event_handler (TDMS self, TDLNAEvent event, void *in_arg, void *in_param);
#endif /* DLNA_SUPPORT_DMSCP || DEVELOPMENT_CONTENT_AGGREGATION */

/* Start DMS.  */
TDMSReturn
dms_start (TDMS self);

/* Stop DMS.  */
TDMSReturn
dms_stop (TDMS self);

slim_int
dms_server_stop_advertisement(TDMS self);

slim_int
dms_server_start_advertisement(TDMS self);

dlna_progress
dms_get_progress(TDMS self);

/* Update DMS.  */
TDMSReturn
dms_update (TDMS self);

TDMSReturn
dms_writeAccessConfServerState(TDMS self, slim_int in_state);

TDMSReturn
dms_register_callback(TDMS self, void *in_arg, slim_int in_cat, TDMSStateCallback in_callback);

slim_int
dms_call_callback(TDMS self, slim_int in_cat, slim_int in_code);

slim_int
dms_indexing_state_callback(TDMS self, slim_int in_level, slim_int in_state, slim_int in_errorCode, slim_char* in_storagePath);


slim_int
dms_partial_indexing_state_callback(TDMS self, slim_int in_mode, slim_int in_state, slim_int in_errorCode, slim_char* in_contentId);

#ifdef HAVE_DTCP
/* Set DTCP-IP DRM */
TDMSReturn
dms_set_drm_dtcp (TDMS self, drm_entry_t *in_dtcp_entry);

void
dms_set_drm_proc (TDMS self, get_drm_info in_proc);

void
dms_delete_drm_dtcp (TDMS self, slim_int in_type);

void
dms_delete_drm_proc (TDMS self);

TDMSReturn
dms_SCMAddContent(TDMS self, TDMSContentMetadata *in_metadata);

TDMSReturn
dms_SCMRemoveContent(TDMS self, slim_char *in_full_path);
#endif /* HAVE_DTCP */

/* Add folder in_path to DMS¡Çs search-for-content path. */
TDMSReturn
dms_publishFolder(TDMS self, slim_char *in_path);

/* Force DMS to update its content tree. */
TDMSReturn
dms_contentUpdate(TDMS self);

/* Change DMS's friendly name */
TDMSReturn
dms_changeFriendlyName(TDMS self, slim_char *in_new_friendly_name);
slim_char*
dms_getFriendlyName(TDMS self);

TDMSReturn
dms_getContentIdxState( TDMS self, slim_int *out_idx_type, slim_int *out_idx_state );

#ifdef DEVELOPMENT_DMS_STORAGE_LAST_INDEX_TIME
TDMSReturn
dms_getDeviceLastIdxTime( TDMS self, const slim_char *in_device_id, slim_char *out_last_idx_time );
TDMSReturn
dms_getDeviceTimeOrState( TDMS self, const slim_char *in_device_id, slim_char *out_time_or_state );
#endif /* DEVELOPMENT_DMS_STORAGE_LAST_INDEX_TIME */

/* Get DMS content IDs */
TDMSReturn
dms_getContentIds(TDMS self, slim_int **out_ids, slim_int *out_num);

/* Change DMS's friendly name */
TDMSReturn
dms_changefriendlyname(TDMS self, slim_char *in_new_friendly_name);

TDMSReturn
dms_storage_content_add_user_metadata(struct dms *self, TDMSPublishUserMetadataList *in_user_metalist, slim_char *in_path);

/* Get DMS content by ID */
#ifndef DEVELOPMENT_CONTENT_API
TDMSReturn
dms_getContentPropertyById(TDMS self, slim_int in_id, TDMSContentProperty *out_property);
#else /* DEVELOPMENT_CONTENT_API */
TDMSReturn
dms_getContentPropertyById(TDMS self, slim_char *in_id, TDMSContentProperty *out_property);

TDMSReturn
dms_getContentPropertyByIdDirectly(TDMS self, slim_char *id, TDMSContentProperty *out_property);

TDMSReturn
dms_getConnectedDevices(struct dms* top, TDMSContentProperty **out_properties, slim_word *number_returned, slim_word *total_count, slim_word start_index, slim_word request_count);

TDMSReturn
dms_getUsbContents(TDMS self, slim_char *device_id, TDMSContentProperty **out_properties, slim_word *number_returned, slim_word *total_count, slim_word start_index, slim_word request_count);

TDMSReturn
dms_getContentByType(TDMS self, TDMSContentBrowseType type, TDMSContentProperty **out_properties, slim_word *number_returned, slim_word *total_count, slim_word start_index, slim_word request_count);

TDMSReturn
dms_searchContent (TDMS self, slim_char *criteria, TDMSContentProperty **out_properties, slim_word *number_returned, slim_word *total_count, slim_word start_index, slim_word request_count);

DLNA_API TDMSReturn
dms_contentPropertyMetadaFree (TDMSContentProperty **out_property);

DLNA_API TDMSReturn
dms_contentPropertyFree (TDMSContentProperty *out_property);

DLNA_API TDMSReturn
dms_contentPropertiesSetFree (TDMSContentProperty **out_properties, slim_word count);
#endif /* DEVELOPMENT_CONTENT_API */

void
dms_service_property_clear_all (service_property_list *in_prop_list);

slim_int
dms_service_property_add (service_property_list *in_prop_list, slim_char *in_name, slim_char *in_value);

service_property_t*
dms_service_property_get (service_property_list *in_prop_list, slim_char *in_name);

void
dms_config_set (struct dms *top, TDMSConfig *in_config);

#if defined(ENABLE_WEBUI_SUPPORT) || defined(ENABLE_AHL)
TDMSReturn
dms_get_contents_tree(struct dms *top, dlna_contents_tree_request_t *in_request, dlna_contents_tree_response_t* out_response);

TDMSReturn
dms_get_contents_child_count(struct dms *top, slim_char *in_obj_id, slim_int *out_num);

TDMSReturn
dms_set_contents_share(struct dms *top, dlna_dms_content_obj_t *in_request);
#endif /* ENABLE_WEBUI_SUPPORT || ENABLE_AHL */

#if (defined(ENABLE_WEBUI_SUPPORT) || defined(ENABLE_AHL)) && defined ENABLE_PARENTAL_GUIDANCE
TDMSReturn
dms_set_contents_pc(struct dms *top, dlna_contents_pg_obj_t *in_request);
#endif /* (ENABLE_WEBUI_SUPPORT || ENABLE_AHL) && ENABLE_PARENTAL_GUIDANCE */

#ifdef DEVELOPMENT_ENABLE_IMPROVEMENT_INDEXING_CALLBACK
TDMSReturn
dms_register_rescan_callback(struct dms *top, TDMSStorageContentRescanCallback in_callback_func);

TDMSReturn
dms_rebuild_contents_storage(struct dms *top);
#else /* DEVELOPMENT_ENABLE_IMPROVEMENT_INDEXING_CALLBACK */
TDMSReturn
dms_rebuild_contents_storage(struct dms *top, TDMSStorageContentRescanCallback in_callback_func);
#endif /* DEVELOPMENT_ENABLE_IMPROVEMENT_INDEXING_CALLBACK */

TDMSReturn
dms_stop_rebuilding_contents_storage(struct dms* top);

slim_int
dms_storage_add(struct dms *top, slim_char *in_full_path, slim_char *in_name);

slim_int
dms_storage_del(struct dms *top, slim_char *in_full_path);

slim_int
dms_storage_update_callback(void *in_arg, slim_int in_type, slim_char *in_name, slim_char *in_full_path);

TDMSReturn
dms_streaming_sessions_set_limit (TDMS self, slim_int in_session_count);

#ifdef ENABLE_PARENTAL_GUIDANCE

/*! \fn slim_int dms_getDeviceLevel(struct dms* top);
 * \par FUNCTION
 *
 * Retrives access level for device
 *
 * \par INPUT ARGUMENTS
 *
 * \param top Pointer to dms structure
 *
 * \par OUTPUT ARGUMENTS
 *
 * None
 *
 * \par RETURN VALUES
 *
 * any value >= 0 is valid access_level for connected
 *
 * value < 0 means error (usualy (-1))
 *
 * \par DESCRIPTION
 *
 * Function creates an interface to web server server facility.
 * It retrives value of device access level from dms.
 *
 */
slim_int
dms_getDeviceLevel(struct dms* top);

/*! \fn slim_int dms_setDeviceLevel(struct dms* top, slim_int new_level);

 * \par FUNCTION
 *
 * Sets up new access level for device
 *
 * \par INPUT ARGUMENTS
 *
 * \param top Pointer to dms structure
 * \param new_level new access level value
 *
 * \par OUTPUT ARGUMENTS
 *
 * None
 *
 * \par RETURN VALUES
 *
 * DMS_SUCCESS   Succeed, new value was set up correctely
 *
 * any other     Failed,  old setting is stil valid
 *
 * \par DESCRIPTION
 *
 * Function creates a interface to web server server facility.
 * It updates access level for device in internal parental control structure
 *
 */
slim_int
dms_setDeviceLevel(struct dms* top, slim_int new_level);

/*! \fn slim_int dms_getDefaultContentLevel(struct dms* top);
 * \par FUNCTION
 *
 * Retrives access level for content stored in dms
 *
 * \par INPUT ARGUMENTS
 *
 * \param top Pointer to dms structure
 *
 * \par OUTPUT ARGUMENTS
 *
 * None
 *
 * \par RETURN VALUES
 *
 * any value >= 0 is valid access level for conntent
 *
 * value < 0 means error (usualy (-1))
 *
 * \par DESCRIPTION
 *
 * Function creates a interface to web server server facility.
 * It retrives value of dms content access level.
 *
 */
slim_int
dms_getDefaultContentLevel(struct dms* top);

/*! \fn slim_int dms_setDefaultContentLevel(struct dms* top, slim_int new_level);
 * \par FUNCTION
 *
 * Sets up new access level for dms content
 *
 * \par INPUT ARGUMENTS
 *
 * \param top Pointer to dms structure
 * \param new_level new access level value
 *
 * \par OUTPUT ARGUMENTS
 *
 * None
 *
 * \par RETURN VALUES
 *
 * DMS_SUCCESS   Succeed, new value was set up correctely
 *
 * any other     Failed,  old setting is stil valid
 *
 * \par DESCRIPTION
 *
 * Function creates a interface to web server server facility.
 * It updates access level to dms content in internal parental control structure
 *
 */
slim_int
dms_setDefaultContentLevel(struct dms* top, slim_int new_level);

/*! \fn slim_int dms_getDefaultClientLevel(struct dms* top);
 * \par FUNCTION
 *
 * Retrives access level assigned by default to newly connected clients
 *
 * \par INPUT ARGUMENTS
 *
 * \param top Pointer to dms structure
 *
 * \par OUTPUT ARGUMENTS
 *
 * None
 *
 * \par RETURN VALUES
 *
 * any value >= 0 is valid access level for conntent
 *
 * value < 0 means error (usualy (-1))
 *
 * \par DESCRIPTION
 *
 * Function creates an interface to web server server facility.
 * It retrives access level assigned by default to newly connected clients
 * from internal parental control structure.
 *
 */
slim_int
dms_getDefaultClientLevel(struct dms* top);

/*! \fn slim_int dms_setDefaultClientLevel(struct dms* top, slim_int new_level);
 * \par FUNCTION
 *
 * Sets up new access level for newly connected clients
 *
 * \par INPUT ARGUMENTS
 *
 * \param top Pointer to dms structure
 * \param new_level new access level value
 *
 * \par OUTPUT ARGUMENTS
 *
 * None
 *
 * \par RETURN VALUES
 *
 * DMS_SUCCESS   Succeed, new value was set up correctely
 *
 * any other     Failed,  old setting is stil valid
 *
 * \par DESCRIPTION
 *
 * Function creates a interface to web server server facility.
 * It updates access level to dms content in internal parental control structure.
 */
slim_int
dms_setDefaultClientLevel(struct dms* top, slim_int new_level);

/*! \fn slim_bool dms_getFirstDevicePC(struct dms *top, parental_control_device_t* pc_device);
 * \par FUNCTION
 *
 * Retrieves first entry from connected devices list.
 *
 * \par INPUT ARGUMENTS
 *
 * \param top Pointer to dms structure
 *
 * \par OUTPUT ARGUMENTS
 *
 * \param pc_device pointer to structure describing device
 *
 * \par RETURN VALUES
 *
 * slim_true        Succeed, pc_device is filled with list entry data
 *
 * slim_false       Failed, pc_device is undefined
 *
 * \par DESCRIPTION
 *
 * It retrieves the first device from the connected devices list and returns the pointer to the
 * structure describing the device.
 */
parental_control_device_t *
dms_getFirstParentalGuidanceConnectedDevice(struct dms *in_top);

/*! \fn slim_bool dms_getNextDevicePC(struct dms *top, const parental_control_device_t* prev_device, parental_control_device_t* pc_device)
 * \par FUNCTION
 *
 * Retrieves next device from connected devices list.
 *
 * \par INPUT ARGUMENTS
 *
 * \param top Pointer to dms structure
 * \param prev_device pointer to structure describing  previously retrived device entry
 *
 * \par OUTPUT ARGUMENTS
 *
 * \param pc_device pointer to structure describing device
 *
 * \par RETURN VALUES
 *
 * slim_true        Succeed, pc_device is filled with list entry data
 *
 * slim_false       Failed, pc_device is undefined, it's last entry or error occured
 *
 * \par DESCRIPTION
 *
 * It retrieves the next device from the connected devices list with reference to the previous device.
 * It returns the next device structure.
 */
parental_control_device_t *
dms_getNextParentalGuidanceConnectedDevice(struct dms *in_top, const parental_control_device_t* in_prev_device);

/*! \fn slim_bool dms_setDevicePC(struct dms *top, const parental_control_device_t* pc_device)
 * \par FUNCTION
 *
 * Updates entries on internal parental control list with provided data
 *
 * \par INPUT ARGUMENTS
 *
 * \param top Pointer to dms structure
 * \param pc_device pointer to structure describing updated device entry, mac_addr field should
 * contain valid MAC address
 *
 * \par OUTPUT ARGUMENTS
 *
 * None
 *
 * \par RETURN VALUES
 *
 * slim_true        Succeed, entry has been updated
 *
 * slim_false       Failed, entry hasn't been changed
 *
 */
slim_bool
dms_setDevicePC(struct dms *top, const parental_control_device_t* pc_device);

/*! \fn slim_bool dms_updateDevicePC(struct dms *top)
 * \par FUNCTION
 *
 * Does synchronization between parental control and pc_devices.xml
 *
 * \par INPUT ARGUMENTS
 *
 * \param top Pointer to dms structure
 *
 * \par OUTPUT ARGUMENTS
 *
 * None
 *
 * \par RETURN VALUES
 *
 * slim_true        Succeed
 *
 * slim_false       Failed
 */
slim_bool
dms_updateDevicePC(struct dms *top);

/*! \fn parental_guidance_level_info_t * dms_getFirstParentalGuidanceLevel(struct dms *top)
 * \par FUNCTION
 *
 * Returns the first parental guidance level from the list of parental guidance levels
 *
 * \par INPUT ARGUMENTS
 *
 * \param top Pointer to dms structure
 *
 * \par OUTPUT ARGUMENTS
 *
 * None
 *
 * \par RETURN VALUES
 *
 * pointer to parental_guidance_level_info_t structure.
 */
parental_guidance_level_info_t *
dms_getFirstParentalGuidanceLevel(struct dms *in_top);

/*! \fn parental_guidance_level_info_t * dms_getNextParentalGuidanceLevel(struct dms *top, parental_guidance_level_info_t* in_prev_level)
 * \par FUNCTION
 *
 * Returns next parental guidance level from the list of parental guidance levels
 *
 * \par INPUT ARGUMENTS
 *
 * \param top Pointer to dms structure
 *
 * \param in_prev_level Pointer to parental_guidance_level_info_t structure referring to previous level
 *
 * \par OUTPUT ARGUMENTS
 *
 * None
 *
 * \par RETURN VALUES
 *
 * pointer to the parental_guidance_level_info_t structure
 */
parental_guidance_level_info_t *
dms_getNextParentalGuidanceLevel(struct dms *in_top, parental_guidance_level_info_t* in_prev_level);

parental_guidance_level_info_t *
dms_getLastParentalGuidanceLevel(struct dms *in_top);


/*! \fn slim_int dms_getParentalGuidanceLevelCount(struct dms *top)
 * \par FUNCTION
 *
 * Retrieves the total Parental Guidance levels specified
 *
 * \par INPUT ARGUMENTS
 *
 * \param top Pointer to dms structure
 *
 * \par OUTPUT ARGUMENTS
 *
 * None
 *
 * \par RETURN VALUES
 *
 * slim_true        Succeed
 *
 * slim_false       Failed
 */
slim_int
dms_getParentalGuidanceLevelCount(struct dms *in_top);

slim_int
dms_getParentalGuidanceDeviceCount(struct dms *in_top);

slim_bool
dms_setParentalGuidanceDeviceLevelByMacAddress(struct dms *top, slim_char *in_mac_address, slim_int in_level);

#if 0 /* REMOVEME */
slim_bool
dms_setParentalGuidanceDeviceLocationURLByIPAddress(struct dms *top, dlna_ip_addr *in_ip_address, slim_char *in_location_url, slim_char *in_usn);
#endif

slim_int
dms_ParentalGuidanceDeviceGetLocationURLCount(parental_control_device_t *in_parental_guidance_device);

sub_device_info_t *
dms_ParentalGuidanceDeviceGetFirstLocationURL(parental_control_device_t *in_parental_guidance_device);

sub_device_info_t *
dms_ParentalGuidanceDeviceGetNextLocationURL(parental_control_device_t *in_parental_guidance_device, const sub_device_info_t *in_parental_guidance_sub_device);

sub_device_info_t *
dms_ParentalGuidanceDeviceGetNthLocationURL(parental_control_device_t *in_parental_guidance_device, slim_int in_location_url_number);

slim_bool
dms_ParentalGuidanceDeviceDeleteByMacAddress(struct dms *top,  const slim_char *in_device_mac_address);

slim_bool
dms_ParentalGuidanceDeviceDelete(struct dms *top, parental_control_device_t *in_parental_guidance_device);

slim_bool
dms_ParentalGuidanceDeviceSetDescription(struct dms *top, parental_control_device_t *in_parental_guidance_device, slim_char *in_description);

slim_char *
dms_ParentalGuidanceDeviceGetDescription(parental_control_device_t *in_parental_guidance_device);

slim_bool
dms_ParentalGuidanceDeviceSetIPAddress(struct dms *top, parental_control_device_t *in_parental_guidance_device, slim_char *in_ip_address);

slim_char *
dms_ParentalGuidanceDeviceGetIPAddress(parental_control_device_t *in_parental_guidance_device);

slim_bool
dms_ParentalGuidanceDeviceSetFriendlyName(struct dms *top, parental_control_device_t *in_parental_guidance_device, slim_char *in_friendly_name);

slim_char *
dms_ParentalGuidanceDeviceGetFriendlyName(parental_control_device_t *in_parental_guidance_device);

slim_char *
dms_ParentalGuidanceDeviceGetUserAgent(parental_control_device_t *in_parental_guidance_device);

slim_bool
dms_ParentalGuidanceDeviceSetLevel(struct dms *top, parental_control_device_t *in_parental_guidance_device, slim_int in_level);

slim_int
dms_ParentalGuidanceDeviceGetLevel(parental_control_device_t *in_parental_guidance_device);

slim_bool
dms_ParentalGuidanceDeviceSetMacAddress(struct dms *top, parental_control_device_t *in_parental_guidance_device, slim_char *in_mac_address);

slim_char *
dms_ParentalGuidanceDeviceGetMacAddress(parental_control_device_t *in_parental_guidance_device);

slim_int
dms_ParentalGuidanceLevelGetId(parental_guidance_level_info_t *in_parental_guidance_id);

slim_bool
dms_ParentalGuidanceLevelSetId(struct dms *top, parental_guidance_level_info_t *in_parental_guidance_level, slim_int in_id);

slim_char *
dms_ParentalGuidanceLevelGetName(parental_guidance_level_info_t *in_parental_guidance_level);

slim_bool
dms_ParentalGuidanceLevelSetName(struct dms *top, parental_guidance_level_info_t *in_parental_guidance_level, slim_char *in_name);

slim_char *
dms_ParentalGuidanceLevelGetDescription(parental_guidance_level_info_t *in_parental_guidance_level);

slim_bool
dms_ParentalGuidanceLevelSetDescription(struct dms *top, parental_guidance_level_info_t *in_parental_guidance_level, slim_char *in_description);

parental_control_device_t *
dms_ParentalGuidanceAllocDevice(void);

slim_bool
dms_ParentalGuidanceFreeDevice(parental_control_device_t *in_device);

parental_guidance_level_info_t *
dms_ParentalGuidanceAllocLevel(void);

slim_bool
dms_ParentalGuidanceFreeLevel(parental_guidance_level_info_t *in_level);

#endif /* ENABLE_PARENTAL_GUIDANCE */

slim_int
dms_getTotalSharedContentByType(struct dms* in_top, TDMSContentClassType in_class_type, slim_int* out_total);

slim_int
dms_setShareContentByType (struct dms* in_top, TDMSContentClassType in_class_type, slim_int in_sharedValue);

/**
 * \par Function:
 * Change priority of indexing thread
 * Change scheduling parameters of indexing thread
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of DMS</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>policy</td>
 *     <td>Requested policy</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>priority</td>
 *     <td>Requested priority</td>
 *   </tr>
 * </table>
 * \return DMS_SUCCESS Success
 * \return DMS_INVALID_PARAM Null pointer or not supported values of policy and/or priority
 * \return DMS_GENERIC_ERROR MPEServer returned failure.
 * \par Description
 * Change scheduling parameters of indexing thread. Change is applied to thread in progress and any future runs.
 */
TDMSReturn
dms_setIndexingThreadScheduling(TDMS self, enum dlna_thread_policy policy, slim_int priority);

#ifdef ENABLE_DMS_INDEXING_CALLBACK_ON_CHANGE

slim_int
dms_content_rescan_call_callback(struct dms * in_top, slim_int error_code);

#endif /* ENABLE_DMS_INDEXING_CALLBACK_ON_CHANGE */

#ifdef DEVELOPMENT_CONTENT_AGGREGATION
TDMSReturn
dms_ca_set_enabled(TDMS self, slim_bool in_enable);

TDMSReturn
dms_ca_get_enabled(TDMS self, slim_bool *out_enabled);

TDMSReturn
dms_ca_set_db_selection_mode(TDMS self, TDMSCADatabaseSelectionMode in_mode);

TDMSReturn
dms_ca_get_db_selection_mode(TDMS self, TDMSCADatabaseSelectionMode *out_mode);

TDMSReturn
dms_ca_set_db_location(TDMS self, slim_char *ca_folder_path);

slim_char *
dms_ca_get_db_location(TDMS self);

TDMSReturn
dms_ca_set_default_indexing (TDMS self, TDMSCAIndex in_index);

TDMSReturn
dms_ca_get_default_indexing (TDMS self, TDMSCAIndex *out_index);

TDMSReturn
dms_ca_get_first_device (TDMS self, TDMSCADeviceObject **out_dev);

TDMSReturn
dms_ca_set_device_indexing (TDMS self, slim_char *in_uuid, TDMSCAIndex in_index);

TDMSReturn
dms_ca_set_db_limit(TDMS self, slim_int in_size);

TDMSReturn
dms_ca_get_db_limit(TDMS self, slim_int *out_size);

TDMSReturn
dms_ca_set_purge_time (TDMS self, slim_int in_time);

TDMSReturn
dms_ca_get_purge_time (TDMS self, slim_int *out_time);

TDMSReturn
dms_ca_set_rescan_interval (TDMS self, slim_int in_interval);

TDMSReturn
dms_ca_get_rescan_interval (TDMS self, slim_int *out_interval);

TDMSReturn
dms_ca_execute_command(TDMS self, TDMSCACommand in_cmd);

TDMSReturn
dms_ca_get_state(TDMS self, TDMSCAState *out_state);

#endif /* DEVELOPMENT_CONTENT_AGGREGATION */

TDMSReturn
dms_get_serverState(TDMS self, slim_int *out_state);

TDMSReturn
dms_get_webUIPort(TDMS self, slim_int *out_port);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_DMS_H */
