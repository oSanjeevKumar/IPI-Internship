/*
 * upnp_server.h
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

#ifndef NFLC_UPNP_SERVER_H
#define NFLC_UPNP_SERVER_H

#include <nflc_upnp.h>
#include <upnp_service.h>
#include <http_parser.h>
#include <http_session.h>
#include <contents_xml.h>
#include <nflc_ssdp.h>
#ifdef DLNA_DMS_SUPPORT_IF_STORAGE_FILTER
#include <upnp_interface.h>
#endif /* DLNA_DMS_SUPPORT_IF_STORAGE_FILTER */

#ifdef ENABLE_PARENTAL_GUIDANCE
#include <parental_guidance.h>
#endif /* ENABLE_PARENTAL_GUIDANCE */

#if defined ENABLE_DMS_RUNTIME_CONFIGURATION || defined DEVELOPMENT_ENABLE_DMR_RUNTIME_CONFIGURATION

typedef struct _serviceStruct {
  slim_char *mServiceType;
  slim_char *mServiceID;
  slim_char *mSCPDURL;
  slim_char *mControlURL;
  slim_char *mEventSubURL;
  slim_char *mDescription;
}serviceStruct;

typedef struct _iconStruct {
  slim_char *mMimeType;
  slim_char *mWidth;
  slim_char *mHeight;
  slim_char *mDepth;
  slim_char *mUrl;
}iconStruct;

extern serviceStruct serviceTab[];

#endif /* ENABLE_DMS_RUNTIME_CONFIGURATION || DEVELOPMENT_ENABLE_DMR_RUNTIME_CONFIGURATION */


/* General.  */
#define UPNP_NUM_MEDIA_TYPES (12)
/* According to UDA 1.1, section 2.3 Device Description.
 * friendlyName SHOULD be < 64 characters.
 * In Unicode case it could be 128 bytes at most/
 */
#define UPNP_FRIENDLY_NAME_LEN_MAX  (128)

/* Mapping of file extension to content-type of document.  */
struct upnp_document_type_t
{
  slim_char *file_ext;
  slim_char *content_type;
  slim_char *content_subtype;
};

#ifdef DLNA_DMS_SUPPORT_IF_STORAGE_FILTER
/* UPnP Server Socket List */
typedef struct upnp_socks
{
  struct upnp_socks *next;
  struct upnp_socks *prev;
  /* socket */
  slim_int sock;
  
  /* IP address */
  dlna_ip_addr addr;

  /* UPnP read event for the socket. */
  dlna_progress_handle e_read;
  
} upnp_socks_t;
#endif /* DLNA_DMS_SUPPORT_IF_STORAGE_FILTER */

/* UPnP server.  */
struct upnp_server
{
  /* Event manager.  */
  dlna_progress em;

  /* Network interface.  */
  dlna_netif netif;

  /* Flags.  */
  slim_byte flags;
#define UPNP_SERVER_UP      (1 << 0)

  /* Service Flags.  */
  slim_byte protocol_flags;
#define UPNP_SERVICE_SSDP   (1 << 0)
#define UPNP_SERVICE_GENA   (1 << 1)
#if defined (DLNA_SUPPORT_SATIP)
#define UPNP_SERVER_SATIP   (1 << 2)
#endif /* DLNA_SUPPORT_SATIP */


  /* Call back function.  */
  upnp_callback_t upnp_server_callback;

  /* Device specific information.  */
  void *info;

#ifdef DLNA_DMS_SUPPORT_IF_STORAGE_FILTER
  /* UPnP server socket.  */  
  List (upnp_socks_t *) sock_list;  
#else /* DLNA_DMS_SUPPORT_IF_STORAGE_FILTER */
  /* UPnP server socket.  */
  slim_int sock;
#endif /* DLNA_DMS_SUPPORT_IF_STORAGE_FILTER */  

  /* Unique Device Name.  */
  slim_char *root_dev_udn;

  /* Local port of the HTTP server.  */
  slim_half port;

  /* Configuration root dir.  This directory is used for XML
     files.  */
  slim_char *config_dir;

  /* Device configuration file.  */
  slim_char *device_file;

#if (defined ENABLE_DMS_RUNTIME_CONFIGURATION || defined DEVELOPMENT_ENABLE_DMR_RUNTIME_CONFIGURATION)
  /** \brief If server use default configuration
   * This field is set to zero during zero alloc. It is set by upnp_config_read when file is unavailable.
   */
  slim_bool using_default_configuration;
#endif /* (defined ENABLE_DMS_RUNTIME_CONFIGURATION || defined DEVELOPMENT_ENABLE_DMR_RUNTIME_CONFIGURATION) */

#ifdef HAVE_DMS
  /* access config directory */
  slim_char*  access_cfg_dir;

  /* access config */
  access_config_t *access_cfg;
#endif /* HAVE_DMS */

  /* Device document.  */
  sXML *doc;

  /* Device list.  */
  sXML_Node *device_xml_list;

  /* Service list.  */
  sXML_Node *service_xml_list;

  /* UPnP read event for the socket. */
  dlna_progress_handle e_upnp_server_read;

  /* Interface manager.  */
  struct upnp_if_manager *ifm;

  /* SSDP server.  */
  struct ssdp_server *ss;
#ifdef DEVELOPMENT_DLNA_SUPPORT_RA
  struct ssdp_relay *sr;
  slim_int fl_privacy ;
#endif

  /* GENA server.  */
  struct gena_server *gs;

  /* UPNP services.  */
  upnp_service_table_t service_table;

  /* DMS CDS lookup callback.  */
  contents_t *(*contents_lookup) (void *info, slim_char *name);


#if(defined(ENABLE_PLAYLIST_SUPPORT) || defined(DEVELOPMENT_ENABLE_PLAYLIST_AUTOGENERATE))

  slim_int (*playlist_generate) (void *info, struct sbuf* sbuf,
      contents_t *c, slim_int ifindex, contents_type_t ctype);

#endif /* (defined(ENABLE_PLAYLIST_SUPPORT) || defined(DEVELOPMENT_ENABLE_PLAYLIST_AUTOGENERATE)) */


  slim_int (*time_seek) (void *info, slim_char *name,
                         struct upnp_seek_param *param);


#ifdef DEVELOPMENT_ENABLE_VIRTUAL_PLAYLISTS
  /* virtual playlists update */
  slim_int (*virtual_playlist_update) (contents_t *c);
#endif /* DEVELOPMENT_ENABLE_VIRTUAL_PLAYLISTS */

  /* HTTP master.  */
  http_master_t *hm;

  struct upnp_document_type_t media_map[UPNP_NUM_MEDIA_TYPES];

#ifdef ENABLE_PARENTAL_GUIDANCE
  parental_control_t *pc;
#endif /* ENABLE_PARENTAL_GUIDANCE */

  /* DMS Content Access callback */
  slim_int (*content_access_callback)(upnp_content_access_event_t in_event, upnp_content_access_param_t *in_param, void *in_arg);

  void * content_access_callback_arg;

  slim_int content_access_notify_update_size;

};

typedef struct upnp_server upnp_server_t;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef DLNA_DMS_SUPPORT_IF_STORAGE_FILTER  
slim_bool
upnp_server_discovery_filter_match(struct upnp_server *us, struct upnp_address *in_addr);
  
slim_bool
upnp_server_action_filter_match(struct upnp_server *us, slim_char *in_device_name, slim_int in_ifindex);

slim_bool
upnp_server_event_filter_match(struct upnp_server *us, slim_int in_ifindex);
#endif /* DLNA_DMS_SUPPORT_IF_STORAGE_FILTER */

/* API: Start UPnP server on the interface.  */
slim_int
upnp_server_if_start (struct upnp_server *us, slim_int ifindex);

/* API: Stop UPnP server on the interface.  */
slim_int
upnp_server_if_stop (struct upnp_server *us, slim_int ifindex);

/* API: Start UPnP server.  */
slim_int
upnp_server_start (struct upnp_server *us);

/* API: Stop UPnP server.  */
slim_int
upnp_server_stop (struct upnp_server *us);

struct upnp_server *
upnp_server_alloc (dlna_progress in_p, slim_half port,
                   slim_char *config_dir, slim_char *device_file,
                   slim_word protocol_flags, upnp_callback_t callback, void *info,
                   dlna_ssdp_t *in_ssdp);

/* API: Free UPnP server. */
slim_int
upnp_server_free (struct upnp_server *us);

/* force reset advertisment for upnp_server*/
slim_int
upnp_server_reset_advertisements(struct upnp_server *us);

/* API: Change UPnP server friendly name. */
slim_int
upnp_server_change_friendly_name (struct upnp_server *us, slim_char *in_new_name);

slim_int
upnp_server_getDevUdnBySvcId(struct upnp_server *us,
                                      const slim_char *in_service_id,
                                      slim_char *out_device_udn,
                                      slim_int in_udn_len);

slim_int
upnp_server_update_ddd_property (struct upnp_server *us, slim_char *in_name, slim_char *in_value) ;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_UPNP_SERVER_H */
