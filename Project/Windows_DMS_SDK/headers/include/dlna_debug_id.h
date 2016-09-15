/*
 * dlna_debug_id.h
 * Copyright (C) 2015 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2005 IP Infusion, Inc. All Rights Reserved.  */

#ifndef DLNA_DEBUG_ID_H
#define DLNA_DEBUG_ID_H

#include <peer_log_utility.h>

/* Use DISABLE_LEVEL and DISABLE_MODULE to disable logging.
 * Use ENABLE_LEVEL and ENABLE_MODULE to enable logging.
 * This setting is only available in compile time mode (#define DLNA_LOG_COMPILE_TIME_ONLY).
 * In case of compile time only both values are set to max to enable and 0 to disable logging.
 * In case of runtime both values are set to max. Only runtime setting will be possible.
 *
 */
typedef enum _dlnaLogIDs
{
  DLNA_LOG_PEER=0,                    /* Peer debug.  */
  DLNA_LOG_APP,                       /* App debug.  */
  DLNA_LOG_UPNP_CORE_SSDP,            /* SSDP debug.  */
  DLNA_LOG_UPNP_CORE_GENA,            /* GENA debug.  */
  DLNA_LOG_UPNP_CORE_SOAP,            /* SOAP debug.  */
  DLNA_LOG_UPNP_CORE_HTTP,            /* HTTP debug.  */
  DLNA_LOG_UPNP_COMMON,               /* UPnP debug.  */
  DLNA_LOG_UPNP_CORE_INTERFACE,       /*UPnP interface debug.  */
  DLNA_LOG_UPNP_TRANSPORT,            /* UPnP Transport.  */
  DLNA_LOG_UPNP_SERVICE_RCS,          /* RCS */
  DLNA_LOG_UPNP_SERVICE_AVTS,         /* AVTS */
  DLNA_LOG_UPNP_SERVICE_CMS,          /* CMS */
  DLNA_LOG_UPNP_SERVICE_CP,           /* UPnP Service CP */
  DLNA_LOG_UPNP_SERVICE_CDS,          /* UPnP Service CDS */
  DLNA_LOG_UPNP_SERVICE_BMS,          /* BMS */
  DLNA_LOG_UPNP_SERVICE_EMS,          /* EMS */
  DLNA_LOG_DEVICECLASS_DEVICE,        /* Device Class*/
  DLNA_LOG_MEDIA,                     /* Media debug */
  DLNA_LOG_DTCP,                      /* DTCP debug */
  DLNA_LOG_DEVICECLASS_COMMON,        /* Dlna Device class common */
  DLNA_LOG_DEVICECLASS_DEVCAP_RUI,    /* DLNA_SUPPORT_RUIPL */
  DLNA_LOG_DEVICECLASS_DEVCAP_DN,     /* +DN+ */
  DLNA_LOG_DEVICECLASS_DEVCAP_UP,     /* +UP+ */
  DLNA_LOG_DEVICECLASS_DEVCAP_DIAG,   
  DLNA_LOG_DEVICECLASS_DEVCAP_LP,     /* Device Class Devcap */
  DLNA_LOG_DEVICECLASS_DEVCAP_PR,
  DLNA_LOG_WEBINTERFACE,              /* WEBUI */
  DLNA_LOG_DB,                        /* Database  */
  DLNA_LOG_MPE,                       /* media processing extension */
  DLNA_LOG_UTIL,                      /* Utility  */
  DLNA_LOG_MEMORY,                    /* Memory debug.  */
  DLNA_LOG_MEDIALINK,                 /* Medialink debug.  */
  DLNA_LOG_TWINE,                     /* Twine debug.  */
  DLNA_LOG_RA,                        /* RA debug.  */
  DLNA_LOG_RA_ALG,                    /* RA application layer gateway debug.  */
  DLNA_LOG_RA_CHANNEL,                /* RA channel management.  */
  DLNA_LOG_RA_CO_CHANNEL,             /* RA connector channel.  */
  DLNA_LOG_RA_LI_CHANNEL,             /* RA listener channel.  */
  DLNA_LOG_DEVMAN,                    /* device_manager.c  */
  DLNA_LOG_API,                       /* device class NFLC SDK API  */
  DLNA_LOG_JNI,                       /* device class JNI API  */
  DLNA_LOG_PEER_AUTOIP,
  DLNA_LOG_PEER_DHCPC,
  DLNA_LOG_PEER_NETIF,
  DLNA_LOG_PEER_NETLINK,
  DLNA_LOG_PEER_SYSCTL,
  DLNA_LOG_PEER_CAS,
  DLNA_LOG_PEER_CERT,
  DLNA_LOG_PEER_DB,
  DLNA_LOG_PEER_DIAG,
  DLNA_LOG_PEER_DIR,
  DLNA_LOG_PEER_DOWNLOADER,
  DLNA_LOG_PEER_FILE,
  DLNA_LOG_PEER_HTTP,
  DLNA_LOG_PEER_IMAGE,
  DLNA_LOG_PEER_JUMP,
  DLNA_LOG_PEER_LIVE,
  DLNA_LOG_PEER_LP,
  DLNA_LOG_PEER_MEMORY,
  DLNA_LOG_PEER_MPE,
  DLNA_LOG_PEER_NET,
  DLNA_LOG_PEER_OBJECT_RIGHTS_MANAGER,
  DLNA_LOG_PEER_PLAYER,
  DLNA_LOG_PEER_PRINT,                 /* peer_print.c  */
  DLNA_LOG_PEER_PROGRESS,
  DLNA_LOG_PEER_PUSH_SERVER,
  DLNA_LOG_PEER_RANDOM,
  DLNA_LOG_PEER_STREAM,
  DLNA_LOG_PEER_STRING,
  DLNA_LOG_PEER_SYSTEM,
  DLNA_LOG_PEER_THREAD,
  DLNA_LOG_PEER_TR69,
  DLNA_LOG_PEER_UPLOADER,
  DLNA_LOG_PEER_EVENT,
  DLNA_LOG_PEER_CRYPT,
  DLNA_LOG_PEER_IO,
  DLNA_LOG_ENDOFIDS                   /* Last item */
} dlnaLogIds ;


#endif /* DLNA_DEBUG_ID_H */
