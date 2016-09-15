/*
 * dlna_client.h
 * Copyright (C) 2007-2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_DLNA_CLIENT_H
#define NFLC_DLNA_CLIENT_H

#include <dlna_api.h>
#include <upnp_client.h>
#include <gena_client.h>
#ifdef DEVELOPMENT_UPNP_LOCAL_PLAY
#include <upnp_player.h>
#endif

/* dlnaDmpNew parameter.  */
struct TDLNANewParam_
{
  /* DLNA progress.  */
  dlna_progress progress;

  /* Display parameter.  */
  dlna_player_display_param *display;

  /* Flags.  */
  slim_word flags;
#define DMP_FLAG_RENDERER_CTRL   (1 << 0)
};
typedef struct TDLNANewParam_ TDLNANewParam;

/* GENA DLNA Client */
struct dlna_gena_client {
  struct dlna_gena_client *next;
  struct dlna_gena_client *prev;

  struct dlna_client_tag *top;
  struct dlna_object *device;

  slim_int timeout_sec;
  TGenaEventHandler gena_eh;
  void *gena_eh_arg;
};

typedef struct dlna_gena_client dlna_gena_client_t;

/* DLNA object device.  */
struct dlna_object_device
{
  /* Device type.  */
  TDLNADeviceType type;

  /* Base URI */
  slim_char *base_url;

  /* Beginning number for browsing.  */
  slim_int beg;

  /* Requested number for browsing.  */
  slim_int num;

/* information of the device*/
#define DEVICE_SORT_CAPS_READY        (0x01) /* sort capabilities has been got */
#define DEVICE_SEARCH_CAPS_READY      (0x02) /* search capabilities has been got */
#define DEVICE_PINFO_READY            (0x04) /* pinfo information is ok */
#define DEVICE_WAIT_NOTIFY            (0x08) /* the device is wait to notify */
#define DEVICE_SUID_READY             (0x10) /* initial suid value has been got */
/* all the information about the DMS device has been prepared */
#define DEVICE_DMS_READY              (DEVICE_SORT_CAPS_READY | DEVICE_SEARCH_CAPS_READY \
                                       | DEVICE_WAIT_NOTIFY | DEVICE_SUID_READY | DEVICE_PINFO_READY)
/* all the information about the DMR device has been prepared */
#define DEVICE_DMR_READY              (DEVICE_WAIT_NOTIFY | DEVICE_PINFO_READY)

  slim_int device_info_flag;

  /* Sort criteria supported by DMS. */
  upnp_csv_list_t sort_criteria_list;
  
  /* search capability supported by DMS. */
  upnp_csv_list_t search_capability_list;

  /* system update id of DMS on device discovery. */
  slim_word init_suid;

#ifdef DLNA_SUPPORT_RUIPL
  slim_bool have_uilist;
  /* rui_level indicates whether device have RUI capability, and
     which level device have. 0:level 0, 1:level 1, 2:level 2.   */
  TDLNADeviceRUILevel rui_level;
#endif /* DLNA_SUPPORT_RUIPL */

#ifdef DEVELOPMENT_DLNA_SUPPORT_DMPR
#define DEVICE_DMPr_MEDIALIST_READY        (0x01) /* medialist has been got */
#define DEVICE_DMPr_READY              (DEVICE_DMPr_MEDIALIST_READY | DEVICE_WAIT_NOTIFY )

	List	(TDMPrMediaList*)media_list;
#endif /* DEVELOPMENT_DLNA_SUPPORT_DMPR */

  /* Object search event handler.  */
  TDLNAObjectEventHandler search_eh;

  /*
   * Object event handler argument.  This is passed by the user through
   * the dlnaObjectSearch API.
   */
  void *in_arg;
};

typedef struct dlna_object_device dlna_object_device_t;

#ifdef DLNA_SUPPORT_RUIPL
/* DLNA object rui.  */
struct dlna_object_rui
{
  /* All UIList Info in network */
  TDLNARUIUIInfo *ui_info;

  slim_char *device_udn;
};

typedef struct dlna_object_rui dlna_object_rui_t;

#endif /* DLNA_SUPPORT_RUIPL */

/* DLNA object container.  */
struct dlna_object_container
{
  /* Device the object belongs to.  */
  struct dlna_object *device;

  /* Beginning number for browsing.  */
  slim_int beg;

  /* Number of objects for browsing.  */
  slim_int num;
};

typedef struct dlna_object_container dlna_object_container_t;

/* DLNA object item.  */
struct dlna_object_item
{
  /* Device the object belongs to.  */
  struct dlna_object *device;
};

typedef struct dlna_object_item dlna_object_item_t;

/* DLNA client contents transport types.  */
#define DLNA_OBJECT_TRANSPORT_TYPE_PLAY    (1 << 0)
#define DLNA_OBJECT_TRANSPORT_TYPE_DN      (1 << 1)
#define DLNA_OBJECT_TRANSPORT_TYPE_UP      (1 << 2)

#define DLNA_OBJECT_TRANSPORT_PS_SIZE 512

/* DLNA object transport.  */
struct dlna_object_transport
{
  /* Remote device.  */
  struct dlna_object *device;

  /* Transport ID.  */
  slim_int tid;

#define DLNA_OBJECT_TRANSPORT_FLAG_BUSY     (1 << 0)
  slim_int flags;
  
 /* DLNA client contents transport type.  */
  slim_int type;

  /* Item the object belongs to.  */
  struct dlna_object *item;

  slim_int current_res_index;

  slim_int state;

#ifdef DLNA_CLIENT_POLL_TRANSPORT_STATE
  /* Event for state refresh.  */
  dlna_progress_handle e_poll_state;
#endif /* DLNA_CLIENT_POLL_TRANSPORT_STATE */

  /* used on upload. */
  void *upload_param;
#ifdef DEVELOPMENT_DIRECT_DLNA_OBJECT
  slim_opaque local_server_content;
#endif
  slim_char dlna_ps[DLNA_OBJECT_TRANSPORT_PS_SIZE];
};

typedef struct dlna_object_transport dlna_object_transport_t;


#ifdef DEVELOPMENT_UPNP_LOCAL_PLAY
/* DLNA object transport.  */
struct dlna_object_local
{
    uplayer_stream_handle   stream_handle;
    slim_int                state;
    upnp_player_event_t     wait_event;
    slim_char*              stream_pinfo;
};
typedef struct dlna_object_local dlna_object_local_t;

#endif /*DEVELOPMENT_UPNP_LOCAL_PLAY*/


/* DLNA object.  */
struct dlna_object
{
  /* Linked list.  */
  struct dlna_object *next;
  struct dlna_object *prev;

  /* Lock counter.  */
  slim_int lock;

  /* Object type.  */
  slim_word type;
#define DLNA_OBJECT_TYPE_DEVICE    (1)
#define DLNA_OBJECT_TYPE_CONTAINER (2)
#define DLNA_OBJECT_TYPE_ITEM      (3)
#define DLNA_OBJECT_TYPE_TRANSPORT (4)

#ifdef DLNA_SUPPORT_RUIPL
#define DLNA_OBJECT_TYPE_UI       (5)
#endif /* DLNA_SUPPORT_RUIPL */

#ifdef DEVELOPMENT_UPNP_LOCAL_PLAY
#define DLNA_OBJECT_TYPE_LOCAL     (6)
#endif
    
  /* Object DRM type */
  TDLNAObjectDRMType drm_type;

  /* Pointer to top.  */
  struct dlna_client_tag *top;

  /* Object XML.  */
  struct _sXML *doc;

  /* Object event handler.  */
  TDLNAObjectEventHandler object_eh;

  /*
   * Object event handler argument.  This is passed by the user through
   * the dlnaObjectBrowse API.
   */
  void *in_arg;

#ifdef DLNA_SUPPORT_HDRL
  TDLNAObjectEventHandler object_hdrl_eh;
#endif
#ifdef DLNA_SUPPORT_SRS
  TDLNAObjectEventHandler object_xsrs_eh;
  void *in_xsrs_arg;
#endif

  /* transport cancel proc */
  void (*object_cancel_proc)(struct dlna_client_tag *top, struct dlna_object *obj);

#ifdef DLNA_DEBUG
  slim_int debug_id;
#endif /* DLNA_DEBUG */

  /* Specific member type.  */
  union {
    /* Device specific member.  */
    dlna_object_device_t device;

    /* Container specific member.  */
    dlna_object_container_t container;

    /* Item specific member.  */
    dlna_object_item_t item;

    /* Transport specific member.  */
    dlna_object_transport_t transport;

#ifdef DLNA_SUPPORT_RUIPL
    /* Remote ui member. */
    dlna_object_rui_t rui;
#endif /* DLNA_SUPPORT_RUIPL */

#ifdef DEVELOPMENT_UPNP_LOCAL_PLAY
    dlna_object_local_t local;
#endif
  } u;
#ifdef DEVELOPMENT_DLNA_SUPPORT_DMPR
		slim_char  *in_dmpr_data ;
#endif /* DEVELOPMENT_DLNA_SUPPORT_DMPR */

  slim_int upload;
#ifdef DLNA_SUPPORT_HDRL
  slim_int hdrl_dev_type;
#endif /* DLNA_SUPPORT_HDRL */
#ifdef DLNA_SUPPORT_UPLOADER
  slim_bool cancel;
  slim_bool stop;
  slim_int notify_kbsize;
  /* bytes previous notification */
  dlna_uint64 previous_bytes;  
#endif /* DLNA_SUPPORT_UPLOADER */
};

typedef struct dlna_object dlna_object_t;

/* Struct for single global variable for the DLNA client.  */
struct dlna_client_tag
{
  /* UPnP client back pointer.  */
  dlna_progress em;

  /* UPnP client back pointer.  */
  struct upnp_client *uc;

  /* TDMP, TDMC, TDMS, etc... */
  void *app;

  /* DLNA event handler.  */
  TDLNAEventHandler dlna_eh;

  /* DLNA event handler argument.  This is passed by the user through
     the dlnaDmpOpen API.  */
  void *in_arg;

  /* DLNA client device lists.  */
  List (dlna_object_t *) devlist;

#ifdef DLNA_SUPPORT_RUIPL
  /* DLNA client rui object lists.  */
  List (dlna_object_t *) ruilist;
#endif /* DLNA_SUPPORT_RUIPL */

#ifdef DEVELOPMENT_DLNA_SUPPORT_DMPR
  void *dmpr;
#endif

#ifdef DEVELOPMENT_DIRECT_DLNA_OBJECT
  dlna_progress local_server_progress;
  slim_opaque local_server_context;
#endif /*DEVELOPMENT_DIRECT_DLNA_OBJECT*/

  List (dlna_gena_client_t *) dlna_gena_client_list;

  /* Play list.  */
  struct _vector *transports;

  slim_int local_tid;

#ifdef HAVE_DTCP
  drm_manager_t drm_manager;
#endif /* HAVE_DTCP */
    
#ifdef DEVELOPMENT_UPNP_LOCAL_PLAY
    upnp_player_manager_t *upm;
#endif /* DEVELOPMENT_UPNP_LOCAL_PLAY */

};

typedef struct dlna_client_tag dlna_client_t;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct dlna_object *
dlna_object_alloc(struct dlna_client_tag *top, sXML *doc);

dlna_object_t *
dlna_object_lock(dlna_object_t *obj);

slim_int
dlna_object_unlock(dlna_object_t *obj);

slim_int
dlna_object_close (dlna_object_t *obj);

dlna_progress
dlna_object_get_progress(dlna_object_t *obj);

void
dlna_object_free(dlna_object_t *obj);

void
dlna_object_cancel (struct dlna_object *obj);

slim_int
dlna_get_seek_param (TDLNAObjectJumpParam *in_jump_param, TUPNPObjectSeekParam *out_seek_param);

slim_int
dlna_client_handler(upnp_event_t type, void *event, void *info);

slim_int
dlna_client_initialize(dlna_client_t *self, dlna_progress in_p, 
                       void *in_app, struct upnp_client *in_uc);

slim_int
dlna_client_finalize(dlna_client_t *self);

void
dlna_client_set_handler(dlna_client_t *self, TDLNAEventHandler in_dlna_eh, void *in_arg);
    
slim_int
dlna_soap_to_event_error(slim_int soap_error);
    
slim_int
dlna_http_to_event_error(slim_int http_error);

void
dlna_client_unset_handler(dlna_client_t *self);

slim_int
dlna_gena_close_all(dlna_client_t *top);

slim_int
dlna_error_from_upnp(slim_int in_error);

#ifdef HAVE_DTCP
slim_int
dlna_client_drm_manager_initialize(dlna_client_t *self);

void
dlna_client_drm_manager_finalize(dlna_client_t *self);

slim_int
dlna_client_drm_manager_set_drm_entry(dlna_client_t *self, drm_entry_t *dtcp_entry);

drm_entry_t *
dlna_client_drm_manager_find_drm_entry(dlna_client_t *self, media_drm_t in_type);

void
dlna_client_drm_manager_set_drm_proc(dlna_client_t *self, get_drm_info in_proc);
#endif /* HAVE_DTCP */

#ifdef __cplusplus
}
#endif /* __cplusplus */

/*
 * TDLNAObject avairable check macro
 */
#if 0

#define DLNA_OBJECT_CHECK

#define DLNA_OBJECT_CHECK_RET_ERROR(x,y) do { if (!dlna_item_object_is_valid(x)) { dlnaProgressUnlockPeer(y);DLNA_DP(("*** Object Invalid A (%p) ***\n", (y)));return DLNA_E_OBJ_INVAL; } } while (0)

#define DLNA_OBJECT_CHECK_RET_NULL(x,y) do { if (!dlna_item_object_is_valid(x)) { dlnaProgressUnlockPeer(y);DLNA_DP(("*** Object Invalid B (%p) ***\n", (y)));return slim_nil; } } while (0)

#define DLNA_OBJECT_CHECK_RET_FALSE(x,y) do { if (!dlna_item_object_is_valid(x)) { dlnaProgressUnlockPeer(y);DLNA_DP(("*** Object Invalid C (%p) ***\n", (y)));return slim_false; } } while (0)

#define DLNA_OBJECT_CHECK_RET_VOID(x,y) do { if (!dlna_item_object_is_valid(x)) { dlnaProgressUnlockPeer(y);DLNA_DP(("*** Object Invalid D (%p) ***\n", (y)));return; } } while (0)

#else  /* 0 */

#define DLNA_OBJECT_CHECK_RET_ERROR(x,y)

#define DLNA_OBJECT_CHECK_RET_NULL(x,y)

#define DLNA_OBJECT_CHECK_RET_FALSE(x,y)

#define DLNA_OBJECT_CHECK_RET_VOID(x,y)

#endif /* 0 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_bool
dlna_item_object_is_valid(dlna_object_t *in_obj);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* _DLNA_CLIENT_H */
