/*
 * upnp_client.h
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

#ifndef NFLC_UPNP_CLIENT_H
#define NFLC_UPNP_CLIENT_H

/* UPnP client.  */

#include <nflc_sxml.h>
#include <nflc_sbuf.h>
#include <nflc_uri.h>
#include <dlna_cds_search.h>
#include <nflc_contents.h>
#include <nflc_http.h>
#include <nflc_upnp.h>
#include <upnp_device.h>
#include <upnp_interface.h>
#include <http_code.h>
#include <http_parser.h>
#include <http_session.h>
#include <http_ring.h>
#include <ssdp_client.h>
#include <gena_client.h>

#ifdef DLNA_SUPPORT_UPLOADER
#include <dlna_up_api.h>
#else /* DLNA_SUPPORT_UPLOADER */
#include <dlna_api.h>
#endif /* DLNA_SUPPORT_UPLOADER */
#ifdef DLNA_SUPPORT_RUIPL
#include <rui_client.h>
#endif /* DLNA_SUPPORT_RUIPL */
#ifdef DLNA_SUPPORT_HDRL
#include <nflc_upnp_hdrl.h>
#endif

/* UPnP client contents play flags.  */
#define UPNP_PLAYER_FLAG_PLAY        (1 << 0)
#define UPNP_PLAYER_FLAG_THUMBNAIL   (1 << 1)
#define UPNP_PLAYER_FLAG_DOWNLOAD    (1 << 2)
#define UPNP_PLAYER_FLAG_UPLOAD      (1 << 3)
#define UPNP_PLAYER_FLAG_UP_LOCAL    (1 << 4)  /* for upload local file */
#define UPNP_PLAYER_FLAG_UP_STREAM   (1 << 5)  /* for upload broadcast stream */
#if defined (HAVE_DTCP) && defined (DLNA_SUPPORT_UPLOADER)
#define UPNP_PLAYER_FLAG_DTCP        (1 << 6)
#define UPNP_PLAYER_FLAG_RADIO       (1 << 7)
#endif /* defined (HAVE_DTCP) && defined (DLNA_SUPPORT_UPLOADER) */

/* UPnP client role flags.  */
#define UPNP_CLIENT_ROLE_DMC       0x00
#define UPNP_CLIENT_ROLE_RAC_RADA  0x01
#define UPNP_CLIENT_ROLE_RAS_RADA  0x02
#define UPNP_CLIENT_ROLE_CA        0x04


struct upnp_client_session {
  struct upnp_client_session *prev;
  struct upnp_client_session *next;

  void *uc; 
  slim_word id;
  upnp_callback_t session_callback;
  void *session_arg;
};
typedef struct upnp_client_session upnp_client_session_t;



#ifdef DLNA_SUPPORT_RUIPL
/* UPnP parameter for rui update. */
struct upnp_param_rui
{
  sXML *ruilist_doc;
  void *info;
};
#endif /* DLNA_SUPPORT_RUIPL */

/* UPnP parameter for device update.  */
struct upnp_param_device
{
  /* Device information.  */
  struct upnp_device *device;

  /* Device document.  */
  sXML *device_doc;

  /* Result device document.  */
  sXML *result_doc;
};

/* UPnP parameter for action.  */
struct upnp_param_action
{
  /* Name of the action.  */
  slim_char *name;

  /* Action document.  */
  sXML *doc;

  /* Result action document.  */
  sXML *result_doc;

  /* Devie type.  */
  slim_char *device_type;

  /* Device UDN.  */
  slim_char *udn;

  /*transport id*/
  slim_int tid;
  
  /* Browse ID.  */
  slim_char *browse_id;
  
  /* Session Data */
  void *session_data;

  /* Action Error code.(SOAP error code) */
  slim_int soap_error_code;

    /* HTTP Error code.(HTTP error code) */
  slim_int http_error_code;
};

/* UPnP parameter for variable.  GENA notification will use this structure for callback.  */
struct upnp_param_variable
{
  struct gena_client_sub *sub;

  /* Notification key.  */
  slim_int key;

  /* Variable XML.  */
  sXML *doc;
};

/* UPnP control point base structure.  */
struct upnp_cp
{
  /* For linked-list.  */
  struct upnp_cp *next;
  struct upnp_cp *prev;

  /* Back pointer.  */
  struct upnp_client *uc;

  /* Control point type.  */
  upnp_cp_t type;

  /* Device type by which is controlled.  */
  slim_char *device_type;

  /* Device lists.  */
  List (struct upnp_device *) devices;

  /* Device documents.  */
  sXML *device_list_doc;

  /* Current device.  */
  struct upnp_device *current_device;

  /* APIs.  */
  slim_int (*start) (struct upnp_cp *cp);
  slim_int (*stop) (struct upnp_cp *cp);
  slim_int (*service_alloc) (struct upnp_device *device);
  slim_int (*service_free) (struct upnp_device *device);
  slim_int (*select_device) (struct upnp_client *uc, struct upnp_device *device);
};

/* UPnP client structure.  */
struct upnp_client
{
  /* Progress.  */
  dlna_progress em;

  /* Network interface.  */
  dlna_netif netif;

  /* temperary/work path */
  slim_char *work_path;

  /* Default UPnP Callback Function */
  /* Point to UC owner */
  upnp_callback_t upnp_client_callback_0;

  /* info to upnp_client_callback_0 */
  void *info_0;

  /* UPnP callback function pointer.  */
  /* Point to UC self */
  upnp_callback_t upnp_client_callback;

  /* Device specific information.  */
  void *info;

  /* Search device.  */
  slim_char *search_type;

  /* Interface manager.  */
  struct upnp_if_manager *ifm;

  /* Transport manager.  */
  struct upnp_transport_manager *tm;

  /* SSDP client.  */
  struct ssdp_client *sc;

  /* GENA client.  */
  struct gena_client *gc;

  /* SOAP client.  */
  struct soap_client *soap;

#ifdef DLNA_SUPPORT_RUIPL
 /* notify client.  */
  struct notify_client *nc;
 /* rui client.  */
  struct rui_client *rc;
#endif /* DLNA_SUPPORT_RUIPL */

  /* Control Points.  */
  List (struct upnp_cp *) cp_list;
  struct upnp_cp *default_cp;

  /* APIs.  */
  slim_int (*if_start) (struct upnp_client *uc, slim_int ifindex);
  slim_int (*if_stop) (struct upnp_client *uc, slim_int ifindex);

  /* HTTP master.  */
  http_master_t *hm;

  /* UPnP Client Sessions */
  List(upnp_client_session_t *)session_list;

  slim_int role_flags ;
  slim_int fl_is_started ;
#ifdef DEVELOPMENT_CONTENT_AGGREGATION
  struct dms *top;
#endif /* DEVELOPMENT_CONTENT_AGGREGATION */
};

struct upnp_csv {
  struct upnp_csv *next;
  struct upnp_csv *prev;
  dlna_split_ss data;
};

typedef struct upnp_csv upnp_csv_t;

struct upnp_csv_list {
  upnp_csv_t *head;
  upnp_csv_t *tail;
  slim_int count;
};

typedef struct upnp_csv_list upnp_csv_list_t;

/* UPNP seek mode */
enum upnp_seek_mode_
{
  UPNP_SEEK_MODE_TRACK_NR,
  UPNP_SEEK_MODE_ABS_TIME,
  UPNP_SEEK_MODE_REL_TIME,
  UPNP_SEEK_MODE_ABS_COUNT,
  UPNP_SEEK_MODE_REL_COUNT,
  UPNP_SEEK_MODE_CHANNEL_FREQ,
  UPNP_SEEK_MODE_TAPE_INDEX,
  UPNP_SEEK_MODE_FRAME
};

typedef enum upnp_seek_mode_ upnp_seek_mode;

/* AVTransport:1 Service Template Version 1.01  Page15
 * However, depending on the actual seek mode used, it must contains string
 * representations of values of UPnP types 'ui4' (ABS_COUNT, REL_COUNT, TRACK_NR,
 * TAPE-INDEX, FRAME),'time' (ABS_TIME, REL_TIME) or float (CHANNEL_FREQ, in Hz). 
 */
struct upnp_param_seek
{
  upnp_seek_mode seek_mode;
  union {
    slim_word track_nr;
    dlna_duration abs_time; 
    dlna_duration rel_time; 
    slim_word abs_count;           
    slim_word rel_count;           
    slim_char *channel_freq;
    slim_word tape_index;
    slim_word frame;
  }u;
};
typedef struct upnp_param_seek TUPNPObjectSeekParam;

typedef enum {
  UPNP_CLIENT_DATA_TRANS_START = CM_DATA_TRANS_START,
  UPNP_CLIENT_DATA_TRANS_ERROR = CM_DATA_TRANS_ERROR,
  UPNP_CLIENT_DATA_TRANS_IN_PROGRESS = CM_DATA_TRANS_IN_PROGRESS,
  UPNP_CLIENT_DATA_TRANS_DONE = CM_DATA_TRANS_DONE
}uc_data_trans_stat;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Allocate the control point.  */
struct upnp_cp *
upnp_client_cp_alloc (struct upnp_client *uc,
             dlna_size_t size, upnp_cp_t type, slim_char *device_type);

/* Lookup the control point.  */
struct upnp_cp *
upnp_client_cp_lookup (struct upnp_client *uc, slim_char *device_type);

/* Lookup the control point via type.  */
struct upnp_cp *
upnp_client_cp_lookup_type (struct upnp_client *uc, upnp_cp_t cp_type);

/* UPnP client allocation.  */
slim_int 
upnp_client_alloc (dlna_progress in_p, slim_char *in_search_type, 
                   upnp_callback_t in_callback, void *in_info,
                   dlna_player_display_param *p, dlna_ssdp_t *in_ssdp, slim_char *in_work_path, struct upnp_client **out_uc, slim_int in_role_flags);

slim_int
upnp_client_startup_local_renderer(struct upnp_client *uc);


/* UPnP client free.  */
void
upnp_client_free (struct upnp_client *uc);

/* UPnP start client.  */
slim_int
upnp_client_start (struct upnp_client *uc);

/* UPnP stop client.  */
slim_int
upnp_client_stop (struct upnp_client *uc);

/* UPnP search devices.  */
slim_int
upnp_client_search_device (struct upnp_client *uc);

/* API: Search contents.  */
slim_int
upnp_client_search_contents (struct upnp_client *uc,
           struct upnp_device *device, slim_char *in_id,
           slim_int in_start, slim_int in_count,
           slim_char *in_criteria, slim_char *in_filter, slim_char *in_sort_crt,
           void *in_session_data);

/* API: Request without parameter.  */
slim_int
upnp_client_request_without_parameter (struct upnp_client *uc,
                   struct upnp_device *device, slim_char *action,
                   void *in_session_data);

slim_int
upnp_client_request_service_without_parameter (struct upnp_client *uc,
                        struct upnp_device *device, slim_char *in_service_type, slim_char *action,
                        void *in_session_data) ;

/* UPnP client select device.  */
slim_int
upnp_client_select_device (struct upnp_client *uc, sXML *doc);

/* API: cancel request for browse or search. */
slim_int
upnp_client_cancel_request (struct upnp_client *uc,
                            void *in_session_data);

/* UPnP client lookup device.  */
struct upnp_device *
upnp_client_lookup_device (struct upnp_client *uc, sXML *doc);

slim_int
upnp_client_browse_device (struct upnp_client *uc, sXML *in_device_doc, slim_char *in_filter,
                           slim_int in_start, slim_int in_count,
                           slim_char *in_sort_crt, void *in_session_data);

/* UPnP client browse container.  */
slim_int
upnp_client_browse_container (struct upnp_client *uc, sXML *in_device_doc, sXML *item,
                              slim_char *in_filter, slim_int in_start, slim_int in_count,
                              slim_char *in_sort_crt, void *in_session_data);

#if defined(DLNA_SUPPORT_DMSCP) || defined(DEVELOPMENT_CONTENT_AGGREGATION)
slim_int
upnp_client_browse_container_by_id (struct upnp_client *uc, sXML *in_device_doc, slim_char *item_id,
                              slim_char *in_filter, slim_int in_start, slim_int in_count,
                              slim_char *in_sort_crt, void *in_session_data);
                              
#endif /* DLNA_SUPPORT_DMSCP || DEVELOPMENT_CONTENT_AGGREGATION */
#if defined (DLNA_SUPPORT_X_BROWSE)
/* UPnP client x browse container.  */
slim_int
upnp_client_x_browse_container (struct upnp_client *uc, sXML *item,
                                slim_int in_start, slim_int in_count,
                                slim_char *in_sort_crt, void *in_session_data);
#endif /* defined (DLNA_SUPPORT_X_BROWSE) */

slim_int
upnp_client_browse_metadata (struct upnp_client *uc, sXML *in_device_doc, 
                          slim_char *in_id, slim_char *in_filter, void *in_session_data);

slim_int
upnp_client_get_service_description (struct upnp_client *uc,
                                     struct upnp_device *in_device,
                                     slim_char *in_service_type);

slim_int
upnp_client_get_service_description_by_id (struct upnp_client *uc,
                                           struct upnp_device *in_device,
                                           slim_char *in_service_id);

slim_int
upnp_client_get_transport (struct upnp_client *uc, 
                           slim_word in_flags,
                           slim_int *tid);
                           
#if defined (HAVE_DTCP) && defined (DLNA_SUPPORT_UPLOADER)
slim_int
upnp_client_cci_set (struct upnp_client *uc, slim_int in_cci, slim_int in_tid);
#endif /* defined (HAVE_DTCP) && defined (DLNA_SUPPORT_UPLOADER) */
                           
/* UPnP client upload file.  */
slim_int
upnp_client_select_local_file (struct upnp_client *uc, 
                               slim_char *in_title, slim_char *in_uri, slim_char *in_pinfo,
                               slim_word in_flags, slim_int *out_tid);

/* UPnP client select item.  */
slim_int
upnp_client_select_item (struct upnp_client *uc, sXML *item, 
                         slim_int resource_index, slim_char *ms_udn, slim_word in_flags,
                         slim_int *in_out_tid, slim_int *out_res_index);

slim_int
upnp_client_select_download_item(struct upnp_client *uc, sXML *item, slim_int resource_index, slim_char* title, slim_int *out_tid);

#ifdef DEVELOPMENT_DIRECT_DLNA_OBJECT
/* UPnP client set item.  */
slim_int
upnp_client_set_item(struct upnp_client *uc, sXML *item, slim_char *in_uri, slim_char *in_album_art_uri,
                     slim_char *in_album_art_med_uri, slim_word in_flags, slim_int *in_out_tid);
#endif

/* UPnP play item.  */
slim_int
upnp_client_play_item (struct upnp_client *uc, slim_int tid, slim_char* speed);

#ifdef DEVELOPMENT_CLOCK_SYNC
slim_int
#ifdef DEVELOPMENT_ENABLE_CLIENT_PLAYSPEED
upnp_client_sync_play_item (struct upnp_client *uc, slim_int tid, slim_char *time, slim_char* speed);
#else /*DEVELOPMENT_ENABLE_CLIENT_PLAYSPEED*/
upnp_client_sync_play_item (struct upnp_client *uc, slim_int tid, slim_char *time);
#endif /*DEVELOPMENT_ENABLE_CLIENT_PLAYSPEED*/
#endif /* DEVELOPMENT_CLOCK_SYNC */

#ifdef DLNA_SUPPORT_DOWNLOADER
/* resume downloading. */
slim_int
upnp_client_download_resume (struct upnp_client *uc, slim_int tid);

/* pause downloading. */
slim_int
upnp_client_download_pause (struct upnp_client *uc, slim_int tid);

/* Cancel downloading. */
slim_int
upnp_client_download_cancel (struct upnp_client *uc, slim_int tid);


/* UPnP download item.  */
slim_int
upnp_client_download_item (struct upnp_client *uc, slim_int tid);
#endif

/* UPnP upload item.  */
slim_int
upnp_client_upload_item_to_device (struct upnp_client *uc, slim_int tid,
                                   slim_char *dms_udn);

/* Suspend SSDP.  */
slim_int
upnp_client_suspend(struct upnp_client *uc);

/* Resume SSDP. */
slim_int
upnp_client_resume(struct upnp_client *uc);

#ifdef DLNA_SUPPORT_UPLOADER
slim_int
upnp_client_upload_item_to_importUri (struct upnp_client *uc, slim_int tid,
                                      slim_char *import_uri);

slim_int
upnp_client_create_object (struct upnp_client *uc,
                           sXML *in_device_doc,
                           upnp_callback_t in_callback,
                           void *in_arg,
                           void *in_up_param,
                           slim_char *in_parent_id, 
                           slim_int in_create_type);

slim_int
upnp_client_destroy_object(struct upnp_client *uc, sXML *in_device_doc, void * in_session_param, slim_char *in_objectid);

slim_int
upnp_client_get_upload_profiles(struct upnp_client *uc, void *session_param, slim_char *in_profiles);

slim_int
upnp_client_update_object (struct upnp_client *uc, slim_char *object_id, 
                           upnp_update_param_t *upnp_current_param, upnp_update_param_t *upnp_new_param,
                           void *session_data);

#endif /* DLNA_SUPPORT_UPLOADER */


/* UPnP pause item.  */
slim_int
upnp_client_pause_item (struct upnp_client *uc, slim_int tid);

#ifdef DEVELOPMENT_CLOCK_SYNC
/* UPnP pause item at desired time. */
slim_int
upnp_client_sync_pause_item (struct upnp_client *uc, slim_int tid, slim_char *time);
#endif /* DEVELOPMENT_CLOCK_SYNC */

/* UPnP jmp item.  */
slim_int
upnp_client_jump_item (struct upnp_client *uc, slim_int tid, TUPNPObjectSeekParam *jump);

/* UPnP stop item.  */
slim_int
upnp_client_stop_item (struct upnp_client *uc, slim_int tid);

#ifdef DEVELOPMENT_CLOCK_SYNC
/* UPnP stop item at desired time. */
slim_int
upnp_client_sync_stop_item (struct upnp_client *uc, slim_int tid, slim_char *time);
#endif /* DEVELOPMENT_CLOCK_SYNC */

/* Play the specified item's next item.  */
slim_int
upnp_client_play_next_item (struct upnp_client *uc, slim_int tid);

/* Play the specified item's previous item.  */
slim_int
upnp_client_play_previous_item (struct upnp_client *uc, slim_int tid);

slim_int
upnp_client_set_transport_uri (struct upnp_client *uc, slim_int tid, sXML *item, slim_int in_res_index);

slim_int
upnp_client_set_next_transport_uri (struct upnp_client *uc, slim_int tid, sXML *item, slim_int in_res_index);

slim_int
upnp_client_get_position_info (struct upnp_client *uc, slim_int tid);

slim_int
upnp_client_get_transport_info (struct upnp_client *uc, slim_int tid);

slim_int
upnp_client_get_media_info (struct upnp_client *uc, slim_int tid);

/* UPnP fastfoward event */
slim_int
upnp_client_fastforward_item(struct upnp_client *uc, slim_int tid, slim_int in_speed);

/* UPnP rewind event */
slim_int
upnp_client_rewind_item(struct upnp_client *uc, slim_int tid, slim_int in_speed);

#ifdef HAVE_WMDRM
slim_int
upnp_client_seektime_item (struct upnp_client *uc, slim_int tid, slim_word seektime);
#endif /* HAVE_WMDRM */

slim_int
upnp_client_avts_query (struct upnp_client *uc, slim_int tid, slim_char *in_var_name);

/* close the transport by the transport ID.  */
slim_int
upnp_client_close_item (struct upnp_client *uc, slim_int tid);

/* UPnP free item.  */
slim_int
upnp_client_free_item (struct upnp_client *uc, slim_int tid);

/*get active transport*/
slim_int 
upnp_client_lookup_transport_by_udn(struct upnp_client *uc, slim_char *dmr_udn, slim_word in_flag);

/* Get DMR supported presets */
slim_int
upnp_client_list_presets (struct upnp_device *in_device,
                          slim_int in_id);

/* Select DMR preset */
slim_int
upnp_client_select_preset (struct upnp_device *in_device,
                           slim_int in_id,
                           slim_char *in_preset);

/* Get DMR current volume */
slim_int
upnp_client_get_volume(struct upnp_device *in_device, 
                       slim_int in_id, 
                       slim_char *in_channel);

/* Set DMR current volume */
slim_int
upnp_client_set_volume(struct upnp_device *in_device, 
                       slim_int in_id, 
                       slim_char *in_channel, 
                       slim_int in_volume);

/* Get DMR current volume DB*/
slim_int
upnp_client_get_volume_db(struct upnp_device *in_device,
                       slim_int in_id, 
                       slim_char *in_channel);

/* Get DMR current volume DB Range*/
slim_int
upnp_client_get_volume_db_range(struct upnp_device *in_device,
                       slim_int in_id,
                       slim_char *in_channel);

/* Set DMR current volume DB */
slim_int
upnp_client_set_volume_db(struct upnp_device *in_device,
                       slim_int in_id,
                       slim_char *in_channel, 
                       slim_int in_volume_db);

/* Get DMR current mute state */
slim_int
upnp_client_get_mutestate(struct upnp_device *in_device, 
                          slim_int in_id,
                          slim_char *in_channel);

/* Set DMR current mute state */
slim_int
upnp_client_set_mutestate(struct upnp_device *in_device, 
                          slim_int in_id, 
                          slim_char* in_channel, 
                          slim_bool in_mute);

slim_int
upnp_client_get_protocol_info_list(struct upnp_device *in_device);

slim_int
upnp_client_get_current_connections_ids(struct upnp_device *in_device);

/* Get dlna player */
dlna_player
upnp_client_get_player (struct upnp_client *uc);

#ifdef DLNA_SUPPORT_SRS
/*
  X_CreateRecordSchedule action
*/
slim_int
upnp_client_create_record_schedule (struct upnp_device *device, xsrs_create_rec_param_t *in_param, void *session_data);

/*
  X_GetConflictList action
*/
slim_int
upnp_client_get_conflict_list (struct upnp_device *device, xsrs_get_cnflist_param_t *in_param, void *session_data);

/*
  X_DeleteRecordSchedule action
*/
slim_int
upnp_client_delete_schedule (struct upnp_device *device, xsrs_del_rec_param_t *in_param, void *session_data);

/*
  X_GetRecordScheduleList action
*/                  
slim_int
upnp_client_get_record_schedule_list (struct upnp_device *device, xsrs_get_reclist_param_t *in_param, void *session_data);

/*
  X_UpdateRecordSchedule action
*/
slim_int
upnp_client_update_record_schedule (struct upnp_device *device, xsrs_update_rec_param_t *in_param, void *session_data);

/*
  X_GetTitleList action
*/
slim_int
upnp_client_get_title_list (struct upnp_device *device, xsrs_get_tlist_param_t *in_param, void *session_data);

/*
  X_DeleteTitle action
*/
slim_int
upnp_client_delete_title (struct upnp_device *device, xsrs_del_title_param_t *in_param, void *session_data);

/*
  X_UpdateTitle action
*/
slim_int
upnp_client_update_title (struct upnp_device *device, xsrs_update_title_param_t *in_param, void *session_data);

#if 0
slim_int
upnp_client_get_schedule (struct upnp_device *device, xsrs_get_reclist_param_t *in_param, void *session_data);
#endif

#endif /* DLNA_SUPPORT_SRS */

#ifdef DLNA_SUPPORT_HDRL
slim_int
upnp_client_get_record_destinations (struct upnp_device *device, void *session_param);

slim_int
upnp_client_get_record_destinationInfo (struct upnp_device *device, void *session_param, slim_char *des_id);

slim_int
upnp_client_get_record_containerID (struct upnp_device *device, void *session_param, slim_char *des_id, upnp_upload_param_t *in_param);
#endif /* DLNA_SUPPORT_HDRL */

slim_int
upnp_client_pinfo_match(struct upnp_device *device, slim_char *pinfo);

slim_int
upnp_client_pinfo_sinkinfo_match (slim_char *pinfo, slim_char *sink_pinfos); 

slim_int
upnp_client_csv_parsestr (slim_char *in_csv_string, upnp_csv_list_t *out_csv_list);

slim_int
upnp_client_urltoip (slim_char *in_url, slim_char *out_ip, slim_int in_len);

slim_int
upnp_client_iptomac (slim_char *in_ip, slim_char *out_mac, slim_int in_len);

#ifdef DEVELOPMENT_DIRECT_DLNA_OBJECT
slim_int
upnp_client_urltoipddr (slim_char *in_url, dlna_ip_addr *out_ip);
#endif

#ifdef DLNA_SUPPORT_RUIPL
slim_int
upnp_client_get_compatible_uis (struct upnp_device *devicec, slim_char *profile,
                            void *in_session_data);
#endif /* DLNA_SUPPORT_RUIPL */

#ifdef DEVELOPMENT_DLNA_SUPPORT_DMPR

enum _upnp_dmpr_orientation
{
  UPNP_DMPR_ORIENTATION_PORTRAIT,  /* 0 deg */
  UPNP_DMPR_ORIENTATION_LANDSCAPE, /* 90 deg */
  UPNP_DMPR_ORIENTATION_REVERSE_PORTRAIT, /* 180 deg */
  UPNP_DMPR_ORIENTATION_REVERSE_LANDSCAPE, /* 270 deg */
  UPNP_DMPR_ORIENTATION_DEVICESETTING 
};

enum _upnp_dmpr_quality
{
  UPNP_DMPR_QUALITY_NORMAL,
  UPNP_DMPR_QUALITY_DRAFT,
  UPNP_DMPR_QUALITY_HIGH,
  UPNP_DMPR_QUALITY_DEVICESETTING
};

typedef enum _upnp_dmpr_orientation upnp_dmpr_orientation;

typedef enum _upnp_dmpr_quality upnp_dmpr_quality;

slim_int
upnp_client_create_uri_job (struct upnp_device *device, 
                slim_char *in_job_name, slim_char *in_doc_format, slim_int in_copies,
                upnp_dmpr_orientation in_orientation, slim_char *in_media_size,
                slim_char *in_media_type, slim_char *in_source_uri, upnp_dmpr_quality in_quality, upnp_callback_t in_callback, void *in_arg);

slim_int
upnp_client_create_jobv2 (struct upnp_device *device,TDLNAObjectDmprParam *param ,void *in_session_data) ;

slim_int
upnp_client_get_media_list (struct upnp_device *device, slim_char *in_media_size, slim_char *in_media_type, void *in_session_data) ;

slim_int
upnp_client_get_margins (struct upnp_device *device, slim_char *in_media_size, slim_char *in_media_type,
                                                  upnp_callback_t in_callback, void *in_arg);

slim_int
upnp_client_cancel_job (struct upnp_device *device, slim_int in_job_id, void *in_session_data);

slim_int
upnp_client_get_printer_attributes (struct upnp_device *device,void *in_session_data);
#endif /*  DEVELOPMENT_DLNA_SUPPORT_DMPR */

#ifdef DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2
slim_int
upnp_client_bms_get_test_info(struct upnp_device *device, slim_char* in_testId);

slim_int
upnp_client_bms_nslookup(struct upnp_device *device, slim_char* in_host, slim_char* in_server, slim_char* in_count, slim_char* in_timeout);

slim_int
upnp_client_bms_get_nslookup_result(struct upnp_device *device, slim_char* in_testId);

slim_int
upnp_client_bms_get_device_status(struct upnp_device *device);

slim_int
upnp_client_bms_ping(struct upnp_device *device,
                            slim_char *in_host,
                            slim_char *in_numberOfRepetitions,
                            slim_char *in_timeout,
                            slim_char *in_dataBlockSize,
                            slim_char *in_dscp);

slim_int
upnp_client_bms_get_ping_result(struct upnp_device *device, slim_char* in_testId);

slim_int
upnp_client_bms_traceroute(struct upnp_device *device,
                            slim_char *in_host,
                            slim_char *in_timeout,
                            slim_char *in_block,
                            slim_char *in_count,
                            slim_char *in_dscp);

slim_int
upnp_client_bms_get_traceroute_result(struct upnp_device *device, slim_char* in_testId);

slim_int
upnp_client_bms_get_test_ids(struct upnp_device *device);

slim_int
upnp_client_bms_get_active_test_ids(struct upnp_device *device);

#endif /* DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2 */

#ifdef DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_1
slim_int
upnp_client_ems_get_interface_info(struct upnp_device *device);

slim_int
upnp_client_ems_service_subscription(struct upnp_device *device,
		                             slim_char *in_uniqueServiceName,
							         slim_char *in_resourceUri,
							         slim_char *in_durationRequest);
slim_int
upnp_client_ems_service_renewal(struct upnp_device *device,
						        slim_char *in_durationRequest,
		                        slim_char *in_serviceSubscriptionID);
slim_int
upnp_client_ems_service_release(struct upnp_device *device,
		                        slim_char *in_serviceSubscriptionID);
#endif /* DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_1 */

#ifdef DEVELOPMENT_DLNA_SUPPORT_RA
/* RADAConfig */
slim_int
upnp_client_raconfig_get_system_info (struct upnp_device *device, void *id, void *in_session_data);
slim_int
upnp_client_raconfig_edit_filter (struct upnp_device *device,  slim_char *in_uuid, slim_char *in_target, slim_char *in_control_mode, slim_char *in_update_type, slim_char *in_access_credential_id, void *in_session_data) ;

/* RATAConfig */
slim_int
upnp_client_ratacp_get_transport_agent_capabilities (struct upnp_device *device, void *in_session_data);
slim_int
upnp_client_ratacp_get_supported_credential_delivery (struct upnp_device *device, void *in_session_data);
slim_int
upnp_client_ratacp_get_credentials_list (struct upnp_device *device, void *in_session_data) ;
slim_int
upnp_client_ratacp_get_profile_list (struct upnp_device *device, void *in_session_data) ;
slim_int
upnp_client_ratacp_add_profile (struct upnp_device *device, slim_char *in_profile, void *in_session_data) ;
slim_int
upnp_client_ratacp_edit_profile (struct upnp_device *device, slim_char *in_profile_id, slim_char *in_profile, void *in_session_data) ;
slim_int
upnp_client_ratacp_delete_profile (struct upnp_device *device,  slim_char *in_profile_id, void *in_session_data) ;
slim_int
upnp_client_ratacp_get_profile_config_info (struct upnp_device *device, slim_char *in_profile_id, void *in_session_data) ;
slim_int
upnp_client_ratacp_query (struct upnp_device *device, slim_char *in_var_name, void *in_session_data);

/* RADASync */
slim_int
upnp_client_rasync_add_remote_devices (struct upnp_device *device, slim_char *in_uuid, TRADASyncDeviceInfo **in_infos, slim_int in_count, void *in_session_data);
slim_int
upnp_client_rasync_remove_remote_devices (struct upnp_device *device, slim_char *in_uuid, TRADASyncDeviceInfo **in_infos, slim_int in_count, void *in_session_data);
slim_int
upnp_client_rasync_set_ddd_location (struct upnp_device *device, slim_char *in_uuid, slim_char *in_url, void *in_session_data);
slim_int
upnp_client_rasync_heartbeat_update (struct upnp_device *device, slim_char *in_uuid, void *in_session_data);
slim_int
upnp_client_rasync_query_value (struct upnp_device *device, slim_char *in_var_name, void *in_session_data) ;

#endif /* DEVELOPMENT_DLNA_SUPPORT_RA */

#ifdef __cplusplus
}
#endif	/* __cplusplus */

#endif /* NFLC_UPNP_CLIENT_H */
