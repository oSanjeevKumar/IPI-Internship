/*
 * upnp_cds.h
 * Copyright (C) 2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */
 
#ifndef NFLC_UPNP_CDS_H
#define NFLC_UPNP_CDS_H

#include <dlna_cds_search.h>
#include <nflc_contents.h>
#ifdef HAVE_DMS
#include <dlna_peer_list.h>
#include <access_conf.h>
#endif /* HAVE_DMS */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* ContentDirectory:1 2.7.1 SearchCapabilities.  */
#define UPNP_CDS_SEARCH_CAPS_DEFAULT                                           \
  "@refID"

#ifdef DEVELOPMENT_ENABLE_SEARCH_PROTOCOL_INFO
#define UPNP_CDS_SEARCH_CAPS_RES                                               \
  "res@protocolInfo,res@size"
#else /* DEVELOPMENT_ENABLE_SEARCH_PROTOCOL_INFO */
#define UPNP_CDS_SEARCH_CAPS_RES                                               \
  "res@size"  
#endif /* DEVELOPMENT_ENABLE_SEARCH_PROTOCOL_INFO */

#define UPNP_CDS_SEARCH_CAPS_DC                                                \
  "dc:title,dc:creator,dc:date"

#define UPNP_CDS_SEARCH_CAPS_UPNP                                              \
  "upnp:class,upnp:album,upnp:artist,upnp:genre"

#define UPNP_CDS_SORT_CAPS_DEFAULT                                   \
  "dc:date,dc:creator,dc:title,upnp:album,upnp:genre,upnp:class,upnp:artist,upnp:originalTrackNumber,res@size"
  /*(nflc-1123 AV1-MS:1-CD:1-4.2 Browse() action - SortCriteria),res@protocolInfo*/

#define UPNP_CDS_SORT_CAPS (slim_char *)                           \
  UPNP_CDS_SORT_CAPS_DEFAULT

#define UPNP_CDS_SEARCH_CAPS (slim_char *)                                     \
  UPNP_CDS_SEARCH_CAPS_DEFAULT ","                                             \
  UPNP_CDS_SEARCH_CAPS_DC ","                                                  \
  UPNP_CDS_SEARCH_CAPS_UPNP


#define UPNP_CDS_HDLNKGETRECORDDESTINATIONS_RESPONSE                            \
"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"                                   \
"<RecordDestinations xmlns=\"urn:schemas-hdlnk-org\">"                        \
  "<RecordDestination version=\"1\" destID=\"101\">"                           \
    "HDD1"                                                                     \
  "</RecordDestination>"                                                      \
  "<RecordDestination version=\"1\" destID=\"102\">"                           \
    "HDD2"                                                                     \
  "</RecordDestination>"                                                      \
"</RecordDestinations>"

#define UPNP_CDS_HDLNKGETRECORDDESTINATIONINFO_RESPONSE                                                \
"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"                                                          \
"<RecordDestinationInfo xmlns=\"urn:schemas-hdlnk-org\""                                             \
" version=\"1\" allowedTypes=\"BD, DVD+RW, DVD-R, NONE\" recordable=\"1\""                            \
" totalCapacity=\"2684354560\" availableCapacity=\"10484510\">"                                      \
"BD"                                                                                                  \
"</RecordDestinationInfo>"                                            



/********************************************************** Forward declarations **************************/


#ifdef DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION

  struct _upnp_cds_user_agent_customizations;

#endif /* DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION */







#ifdef HAVE_DMS
#define MAX_BROWSE_REQUEST_LIST_ITEMS    20

//Forward declarations
#ifdef DEVELOPMENT_ICP_PLUGIN
  struct _upnp_cds_icp_plugin_desc;
  struct _upnp_cds_icp_plugin;
  struct _upnp_cds_icp_plugin_desc_list;
#endif /* DEVELOPMENT_ICP_PLUGIN */

typedef struct browse_request_list_item {
  struct browse_request_list_item* next;
  struct browse_request_list_item* prev;

  slim_char *ObjectID;
  extended_flags_t flags_ext;
  slim_int total_matches;
} browse_item_t;

#endif /* HAVE_DMS */
/* Browse parameter.  */
struct upnp_cds_browse_param
{
  slim_char *ObjectID;
  slim_char *BrowseFlag;
  slim_char *Filter;
  slim_char *StartingIndex;
  slim_char *RequestedCount;
  slim_char *SortCriteria;

#ifdef DLNA_DMS_SUPPORT_IF_STORAGE_FILTER
  slim_int ifindex;
#endif /* DLNA_DMS_SUPPORT_IF_STORAGE_FILTER */  

#ifdef ENABLE_PARENTAL_GUIDANCE
  slim_int deviceParentalGuidanceLevel;
#endif /* ENABLE_PARENTAL_GUIDANCE */


#ifdef DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION

  struct _upnp_cds_user_agent_customizations * customizations;

#endif /* DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION */
};

/* Search parameter.  */
struct upnp_cds_search_param
{
  slim_char *ContainerID;
  slim_char *SearchCriteria;
  slim_char *Filter;
  slim_char *StartingIndex;
  slim_char *RequestedCount;
  slim_char *SortCriteria;
  cds_search_exp_t *s_exp;
#ifdef ENABLE_PARENTAL_GUIDANCE
  slim_int deviceParentalGuidanceLevel;
#endif /* ENABLE_PARENTAL_GUIDANCE */


#ifdef DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION

  struct _upnp_cds_user_agent_customizations * customizations;

#endif /* DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION */
};

/* CreateObject parameter.  */
struct upnp_cds_create_object_param
{
  slim_char *ContainerID;
  sXML *Elements;
  slim_char *ObjectID;
  sXML *Result;
  contents_t *c;
#ifdef DLNA_DMS_SUPPORT_IF_STORAGE_FILTER
  slim_int ifindex;
#endif /* DLNA_DMS_SUPPORT_IF_STORAGE_FILTER */


#ifdef DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION

  struct _upnp_cds_user_agent_customizations * customizations;

#endif /* DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION */
};

/* UpdateObject parameter. */
struct upnp_cds_update_object_param
{
  slim_char *ObjectID;
  sXML *CurrentTagValue;
  sXML *NewTagValue;
};

struct upnp_cds_update_attribute_param
{
  slim_char *dc_title;
  slim_char *dc_date;
  slim_char *upnp_artist;
  slim_char *pinfo;
  slim_char *containerID;
  slim_char *full_path;
  slim_int upnp_channelNr;
  slim_char *upnp_class;
  slim_char *upnp_createClass;
  slim_char *upnp_channelName;
  slim_char *upnp_rating;
  slim_char *upnp_radioBand;
  slim_char **upnp_genre; /* array which is ended by null */
  slim_char *upnp_scheduledStartTime;
  slim_char *upnp_scheduledEndTime;
  slim_char *upnp_res_duration;
  slim_char *dc_description;  
};

/* X_HDLnkGetRecordContainer parameter.  */
struct upnp_cds_x_hdlnk_get_record_container_param
{
  slim_char *RecordDestinationID;
  sXML *Elements;
  slim_char *ContainerID;
};

typedef void  (*upnp_cds_contents_update_proc)(void *info);

#ifdef ENABLE_CDS_1_0_CONTAINER_UPDATE_IDS
//CDS 1.0 - comma separated pair {string,ui4}
struct _upnp_cds_container_update_id
{
  //list
  struct _upnp_cds_container_update_id * next;
  struct _upnp_cds_container_update_id * prev;

  //data
  slim_char * container_id;
  slim_word container_update_id;
};

typedef struct _upnp_cds_container_update_id upnp_cds_container_update_id;
ListNamed(struct _upnp_cds_container_update_id *, _upnp_cds_container_update_id_list);

#endif /* ENABLE_CDS_1_0_CONTAINER_UPDATE_IDS */


#ifdef DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION

//user agent map
enum _upnp_cds_user_agent_device_map_condition_type
{
  UPNP_CDS_USER_AGENT_DEVICE_MAP_CONDITION_NONE = 0,
  UPNP_CDS_USER_AGENT_DEVICE_MAP_CONDITION_SAMSUNG,
  UPNP_CDS_USER_AGENT_DEVICE_MAP_CONDITION_PLAYSTATION_3,
  UPNP_CDS_USER_AGENT_DEVICE_MAP_CONDITION_SONY_BRAVIA,
  UPNP_CDS_USER_AGENT_DEVICE_MAP_CONDITION_WD_TV_LIVE_HUB,
};

struct _upnp_cds_user_agent_device_map_entry
{
  slim_char * user_agent;
  slim_word device_id;
  enum _upnp_cds_user_agent_device_map_condition_type condition;
};

struct _upnp_cds_user_agent_device_map
{
  struct _upnp_cds_user_agent_device_map_entry * entries;
  slim_word size;
};


// Customization array
struct _upnp_cds_user_agent_customization_array
{
  struct _upnp_cds_user_agent_customizations ** customizations;
  slim_word size;
};


typedef slim_word
(*_user_agent_get_device_id)(void * obj, const slim_char * user_agent);

#endif /* DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION */

#if defined (RA_USE_RID_HEADER)

#define X_RID_TIMER_VALUE (60*60*24)

typedef struct  _x_rid_permission
{
  struct _x_rid_permission * next;
  struct _x_rid_permission * prev;
  slim_char *rid ;
  slim_word permission ;
  dlna_time_t	mtime ;
} x_rid_permission_t ;
#endif //#if defined (RA_USE_RID_HEADER)


typedef struct upnp_cds_
{
  /* Contents manager.  */
  cm_t *cm;

  /* Maximum allowed requested count.  */
  slim_word max_rcount;
#define UPNP_CDS_MAX_REQUESTED_COUNT    (250)

  /* SOAP action.  */
  sXML *action_doc;

  /* SOAP result document.  */
  sXML *result_doc;

   upnp_cds_contents_update_proc update_callback;
   void *info;
   
  /* Incomming interface index used for the XML resources.  */
  slim_int ifindex;
  /* Back-pointer to the top.  */
  struct dms *top;
#ifdef HAVE_DMS
  List(browse_item_t*) request_list;
  struct upnp_action_request *action_request;
#endif /* HAVE_DMS */


#ifdef DEVELOPMENT_ICP_PLUGIN

  struct _upnp_cds_icp_plugin_desc_list * icp_plugin_desc_list;
  struct _upnp_cds_icp_plugin * icp_plugin;
  struct _upnp_cds_icp_plugin_callback_arg * icp_plugin_callback_arg;

#endif /* DEVELOPMENT_ICP_PLUGIN */


#ifdef DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION

  struct _upnp_cds_user_agent_customization_array user_agent_customizations;
  struct _upnp_cds_user_agent_device_map          user_agent_device_map;
  _user_agent_get_device_id                       user_agent_get_device_id;

#endif /* DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION */


  //UPNP CDS 1.0 $ 2.5.20. SystemUpdateID
  slim_word system_update_id;


  /*
   * UPNP CDS 1.0 $ 2.5.21. ContainerUpdateIDs
   * UPNP CDS 2.0 $ 2.3.6 ContainerUpdateIDs
   */

#if defined (ENABLE_CDS_1_0_CONTAINER_UPDATE_IDS)

  struct _upnp_cds_container_update_id_list * container_update_ids;
  dlna_mutex container_update_ids_mutex;

#endif /* ENABLE_CDS_1_0_CONTAINER_UPDATE_IDS */

#if defined (RA_USE_RID_HEADER)
  dlna_progress x_rid_monitor_timer ;
  List(x_rid_permission_t *) x_rid_permission_list;
#endif //#if defined (RA_USE_RID_HEADER)

} upnp_cds;



/* Contents timer interval.   */
#define UPNP_CDS_TIMER_INTERVAL         (10)


#ifdef HAVE_DMS
upnp_cds*
upnp_cds_alloc(struct upnp_if_manager *ifm, slim_char *contents_root_dir,
               slim_char *xml_dir, void *info,
               upnp_cds_contents_update_proc in_update_callback);
#else
upnp_cds*
upnp_cds_alloc(struct upnp_if_manager *ifm, slim_char *contents_root_dir, void *info,
               upnp_cds_contents_update_proc in_update_callback);
#endif

slim_int
upnp_cds_start (upnp_cds *s);

slim_int
upnp_cds_stop (upnp_cds *s);

slim_int
upnp_cds_free (upnp_cds *s);
    
slim_int
upnp_cds_get_search_capabilities (upnp_cds *s);

slim_int
upnp_cds_get_sort_capabilities (upnp_cds *s);

slim_int
upnp_cds_browse (upnp_cds *s);

slim_int
upnp_cds_search (upnp_cds *s);

slim_int
upnp_cds_create_object (upnp_cds *s);

slim_int
upnp_cds_destroy_object (upnp_cds *s);

slim_int
upnp_cds_update_object (upnp_cds *s);

slim_int
upnp_cds_import_resource (upnp_cds *s);

slim_int
upnp_cds_export_resource (upnp_cds *s);

slim_int
upnp_cds_stop_transfer_resource (upnp_cds *s);

slim_int
upnp_cds_get_transfer_progress (upnp_cds *s);

slim_int
upnp_cds_delete_resource (upnp_cds *s);

slim_int
upnp_cds_create_reference (upnp_cds *s);

/* UPnP ContentDirectory:3 2.5.4 GetFeatureList. */
slim_int
upnp_cds_get_feature_list (upnp_cds *s);

/* DMS Content Directory state variables.  */

slim_char *
upnp_cds_transfer_id (upnp_cds *s);

#ifdef DEVELOPMENT_CDS2
slim_char *
upnp_cds_feature_list (upnp_cds *s);
#endif /* DEVELOPMENT_CDS2 */

slim_char *
upnp_cds_a_arg_type_object_id (upnp_cds *s);

slim_char *
upnp_cds_a_arg_type_browse_flag (upnp_cds *s);

slim_char *
upnp_cds_a_arg_type_result (upnp_cds *s);

slim_char *
upnp_cds_a_arg_type_search_criteria (upnp_cds *s);

slim_char *
upnp_cds_a_arg_type_sort_criteria (upnp_cds *s);

slim_char *
upnp_cds_a_arg_type_filter (upnp_cds *s);

slim_char *
upnp_cds_a_arg_type_index (upnp_cds *s);

slim_char *
upnp_cds_a_arg_type_count (upnp_cds *s);

slim_char *
upnp_cds_a_arg_type_update_id (upnp_cds *s);

slim_char *
upnp_cds_search_capabilities (upnp_cds *s);

slim_char *
upnp_cds_sort_capabilities (upnp_cds *s);

slim_char *
upnp_cds_container_update_ids (upnp_cds *s);

#ifdef DLNA_SUPPORT_HDRL
slim_char *
upnp_cds_x_a_arg_type_record_destination_id (upnp_cds *s);



slim_char *
upnp_cds_x_a_arg_type_record_destination_info (upnp_cds *s);

slim_char *
upnp_cds_x_record_destination_list (upnp_cds *s);
#endif /* ifdef DLNA_SUPPORT_HDRL */

void 
upnp_cds_service_reset (upnp_cds *s);

/* SystemUpdateID.  */
slim_char *
upnp_cds_system_update_id (upnp_cds *s);

void
upnp_cds_contents_update (upnp_cds *s);

#ifdef HAVE_DMS
slim_int
upnp_cds_contents_storage_update(upnp_cds *s, storage_config_t* usb_cfg);

slim_int 
upnp_cds_contents_storage_delete(upnp_cds *s, storage_config_t* usb_cfg);

/*! \fn void dms_cds_stop_indexing(void *cds)
 * \par FUNCTION
 *
 * stops indexing process
 *
 * \par INPUT ARGUMENTS
 *
 * \param cds pointer pointing to dms_cds structure
 *
 * \par OUTPUT ARGUMENTS
 *
 * None
 *
 * \par RETURN VALUES
 *
 * None
 *
 * \par DESCRIPTION
 *
 * Stops indexing that is in progress.
 *
 * Function sets flag stop_indexing, joins with the indexing thread and waits until it stops.
 */
void
dms_cds_stop_indexing(void *cds);
#endif /* HAVE_DMS */

#ifdef HAVE_DMS
/*! \fn slim_int dms_cds_contents_storage_rebuild(void *s)
 * \par FUNCTION
 *
 * starts indexing process for all plugged devices
 *
 * \par INPUT ARGUMENTS
 *
 * \param s pointer pointing to dms_cds structure
 *
 * \par OUTPUT ARGUMENTS
 *
 * None
 *
 * \par RETURN VALUES
 *
 * 1                     Succeeded
 *
 * 0                     Failed
 *
 * \par DESCRIPTION
 *
 * Triggers indexing process for all plugged usb devices.
 */
slim_int 
dms_cds_contents_storage_rebuild(void *s);

void
dms_cds_free_request_cache (upnp_cds *s);

void
dms_cds_free_request_cache_dms (struct dms *top);
#endif /* HAVE_DMS */

slim_int
upnp_cds_get_system_update_id (upnp_cds *s);

#if (defined(ENABLE_PLAYLIST_SUPPORT) || defined(DEVELOPMENT_ENABLE_PLAYLIST_AUTOGENERATE))
slim_int
upnp_cds_playlist_generate(upnp_cds *s, struct sbuf* sbuf, contents_t *c, slim_int ifindex, contents_type_t ctype);
#endif /* (defined(ENABLE_PLAYLIST_SUPPORT) || defined(DEVELOPMENT_ENABLE_PLAYLIST_AUTOGENERATE)) */

TCDSSortParam*
upnp_cds_sortcriteria_parse(slim_char *in_sort_criteria);

void
upnp_cds_sortcriteria_free(TCDSSortParam *in_sort_param);

slim_int
upnp_cds_compare_content(contents_t *in_c1, contents_t *in_c2, TCDSSortParam *in_sort_param);

void
upnp_cds_qsort_contents(contents_t *in_contents_array[], slim_int in_array_size, TCDSSortParam *in_sort_param);





#ifdef ENABLE_CDS_1_0_CONTAINER_UPDATE_IDS

void
upnp_cds_insert_container_update_id(upnp_cds *s,
    const slim_char * container_id,
    const slim_word container_update_id);

void
upnp_cds_delete_container_update_id(upnp_cds *s, const slim_char * container_id);

void
upnp_cds_erase_container_update_id_list(upnp_cds *s);

#endif /* ENABLE_CDS_1_0_CONTAINER_UPDATE_IDS */


#ifdef DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION

slim_word
upnp_cds_contents_get_search_type(slim_char* id, struct upnp_cds_search_param *p);

slim_word
upnp_cds_contents_get_xbox_search_type(slim_char* id);


#ifdef DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION_MS_CERT_TOOL

slim_word
upnp_cds_contents_get_ms_cert_tool_search_type(contents_t * c, struct upnp_cds_search_param *p);

#endif /* DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION_MS_CERT_TOOL */


#endif /* DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION */

slim_int
upnp_cds_custom_browse (upnp_cds *s, sXML *in_request_doc, sXML **out_response_doc);

slim_int
upnp_cds_custom_search (upnp_cds *s, sXML *in_request_doc, sXML **out_response_doc);

#if defined (RA_USE_RID_HEADER)
slim_int
upnp_cds_rid_permission_lookup(upnp_cds *s, slim_char *in_rid, slim_word *out_permission) ;
slim_int
upnp_cds_rid_permission_add(upnp_cds *s, slim_char *rid, slim_word permission) ;
slim_int
upnp_cds_rid_permission_remove(upnp_cds *s, slim_char *rid) ;
#endif //#if defined (RA_USE_RID_HEADER)

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_UPNP_CDS_H */

