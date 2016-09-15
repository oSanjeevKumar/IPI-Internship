/*
 * nflc_dmr.h
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

#ifndef NFLC_DMR_H
#define NFLC_DMR_H

#include <dlna_peer.h>
#include <dmr_api.h>
#include <upnp_server.h>

#define DMR_SERVICE_CMS		0 /* ConnecitonManager.  */
#define DMR_SERVICE_RCS		1 /* RenderingControl.  */
#define DMR_SERVICE_AVTS	2 /* AVTransport.  */
#ifdef DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2
  #define DMR_SERVICE_BMS       (DMR_SERVICE_AVTS + 1)
#else
  #define DMR_SERVICE_BMS       (DMR_SERVICE_AVTS)
#endif /* DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2 */

#ifdef DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_1
  #define DMR_SERVICE_EMS       (DMR_SERVICE_BMS + 1)
#else
  #define DMR_SERVICE_EMS       (DMR_SERVICE_BMS)
#endif /* DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_1 */

#define DMR_SERVICE_MAX       (DMR_SERVICE_EMS + 1)

#define DMR_SERVICE_ID_CMS	((slim_char *) "ConnectionManager")
#define DMR_SERVICE_ID_RCS	((slim_char *) "RenderingControl")
#define DMR_SERVICE_ID_AVTS	((slim_char *) "AVTransport")

#ifdef DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2
#define DMR_SERVICE_ID_BMS      ((slim_char *) "BasicManagement")
#endif /* DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2 */

#ifdef DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_1
#define DMR_SERVICE_ID_EMS      ((slim_char *) "EnergyManagement")
#endif /* DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_1 */


struct dmr;

//Forward declarations
struct upnp_subscribe_request;
struct upnp_subscribe_event;

/** \brief DMR configuration structure
 */
struct dmr_configuration
{
  /** \brief Path to configuration directory */
  slim_char * configuration_directory;

  /** \brief Name of file containing DMR description
   * It should be stored in configuration directory
   */
  slim_char * description_file;
};

/* DMR service base structure.  */
struct dmr_service
{
  /* Backpoiner to the top.  */
  struct dmr *top;

  /* Sercie ID.  */
  slim_char *id;

  /* Member functions.  */
  slim_int (*start_proc) (struct dmr_service *);
  slim_int (*stop_proc) (struct dmr_service *);
  slim_int (*subscribe_stop) (struct dmr_service *, struct upnp_subscribe_event *);
  slim_int (*subscribe_proc) (struct dmr_service *, struct upnp_subscribe_request *);
  slim_int (*get_var_proc) (struct dmr_service *, struct upnp_query_variable *);
  slim_int (*action_proc) (struct dmr_service *, struct upnp_action_request *);
  slim_int (*action_reply_proc) (struct dmr_service *, struct upnp_action_response *);
};

/* DMR structure.  */
struct dmr
{
  /* UPnP server pointer.  */
  struct upnp_server *us;

  /* Different callback for DMR and DMR_AHL target.
   * For DMR target is to inform media player status to UI.
   * For DMR_AHL target is for media player in application layer integration.
   */ 
#ifndef ENABLE_AHL
  /* UI callback function.  */
  TDMREventCallback cb;
#else
  /*AHL Callback*/
  dmr_ahl_callback cb;

  slim_opaque ahl_cb_arg;

  slim_char *playerInfo;
  slim_char *sinkProtocolInfo;
  slim_char *presets; /* For RCS:Resets, there is another copy in RCS */
  slim_int volume;
  slim_int mute;
  slim_int channel;
  slim_int volumeDb;
#endif /*ENABLE_AHL*/

  /* String buffer.  */
  struct sbuf *sbuf;

  /* UPnP transport manager.  */
  struct upnp_transport_manager *tm;

  /* Callbacks.  */
  struct dmr_service *(*service_lookup) (struct dmr *, slim_int);

  /* DMR services.  */
  struct dmr_service *service[DMR_SERVICE_MAX];

  struct dmr_configuration dmr_config;

  /* C.K.20111109: Metadata information of DLNA object from DMS.  */
  sXML *metadata;
};

/**
 * @addtogroup structures
 */
/*@{*/

/*! DMR notify playstate callback parameter.  */
struct dmr_notify_playstate_param
{
  dlna_progress em;
  upnp_avts_t *avts;
  slim_int in_event;
  dlna_player_param *player_param;
};

typedef struct dmr_notify_playstate_param dmr_notify_playstate_param_t;

/*! DMR notify volumestate callback parameter.  */
struct dmr_notify_volumestate_param
{
  dlna_progress em;
  slim_int volume_control_event;
  slim_opaque volume_state_callback_arg;
  slim_int in_channel;
  slim_int in_volume;
#ifdef ENABLE_AHL
  slim_int in_volumeDB;
#endif /* ENABLE_AHL */
  slim_int in_mutestate;
};
typedef struct dmr_notify_volumestate_param dmr_notify_volumestate_param_t;
/*@}*/

typedef slim_int dmr_return_t;

struct dmr_notify_play_position_param
{
  struct dmr *top;
  slim_int timePosition;
  slim_int bytePosition;
};
typedef struct dmr_notify_play_position_param dmr_notify_play_position_param_t;

struct dmr_notify_content_info_param
{
  struct dmr *top;
  slim_char *contentInfo;
};
typedef struct dmr_notify_content_info_param dmr_notify_content_info_param_t;

struct dmr_notify_player_error_param
{
  struct dmr *top;
  slim_char *errorInfo;
};
typedef struct dmr_notify_player_error_param dmr_notify_player_error_param_t;
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Prototypes.  */

/* API: Allocate DMR.  */
#ifdef ENABLE_AHL
struct dmr *
dmr_alloc(dlna_progress in_progress, dmr_ahl_callback in_callback, slim_opaque in_ahl_callback_arg, slim_half in_port,
          slim_char *in_config_dir, slim_char *in_device_file);
#else
struct dmr *
dmr_alloc(dlna_progress in_progress, TDMREventCallback in_callback, slim_half in_port,
          slim_char *in_config_dir, slim_char *in_device_file);
#endif /*ENABLE_AHL*/

/* API: Free DMR.  */
void
dmr_free (struct dmr *top);

/* API: Start DMR.  */
dmr_return_t
dmr_start (struct dmr *top);

/* API: Stop DMR.  */
dmr_return_t
dmr_stop (struct dmr *top);

/* API  Show DMR - effectively stops SSDP server, only */
slim_int
dmr_server_start_advertisement(TDMR self);

/* API  Hide DMR - effectively starts SSDP server, only */
slim_int
dmr_server_stop_advertisement(TDMR self);

slim_int
dmr_set_friendly_name(struct dmr *dmr, slim_char *in_friendly_name);

slim_char *
dmr_get_friendly_name(struct dmr *dmr);

void
dmr_notify_play_state(struct dmr *top, slim_int in_event);

void
#ifdef ENABLE_AHL
dmr_notify_volume_state(struct dmr *top, slim_int channel, slim_int volume, slim_int volumeDB);
#else /* ENABLE_AHL */
dmr_notify_volume_state(struct dmr *top, slim_int channel, slim_int volume);
#endif /* ENABLE_AHL */

void
dmr_notify_mute_state(struct dmr *top, slim_int channel, slim_int state);

#ifdef ENABLE_AHL
slim_int
dmr_set_player_info(struct dmr *top, slim_char *in_player_info);
#endif /* ENABLE_AHL */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_DMR_H */
