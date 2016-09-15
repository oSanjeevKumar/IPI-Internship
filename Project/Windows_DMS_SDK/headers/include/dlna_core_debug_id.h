#ifndef DLNA_CORE_DEBUG_ID_H
#define DLNA_CORE_DEBUG_ID_H

#include <peer_log_utility.h>

/* Use DISABLE_LEVEL and DISABLE_MODULE) to disable logging.
 * Use ENABLE_LEVEL and ENABLE_MODULE to enable logging.
 * This setting is only available in compile time mode (#define DLNA_LOG_COMPILE_TIME_ONLY).
 * In case of compile time only both values are set to max to enable and 0 to disable logging.
 * In case of runtime both values are set to max. Only runtime setting will be possible.
 *
 */
/* SSDP debug.  */
#define DLNA_LOG_UPNP_CORE_SSDP                (0x00000004 & DISABLE_MODULE)

/* GENA debug.  */
#define DLNA_LOG_UPNP_CORE_GENA                (0x00000008 & DISABLE_MODULE)

/* SOAP debug.  */
#define DLNA_LOG_UPNP_CORE_SOAP                (0x00000010 & DISABLE_MODULE)

/* HTTP debug.  */
#define DLNA_LOG_UPNP_CORE_HTTP                (0x00000020 & DISABLE_MODULE)

/* UPnP debug.  */
#define DLNA_LOG_UPNP_COMMON                   (0x00000040 & DISABLE_MODULE)

/*UPnP interface debug.  */
#define DLNA_LOG_UPNP_CORE_INTERFACE           (0x00000080 & DISABLE_MODULE)

/* UPnP Transport.  */
#define DLNA_LOG_UPNP_TRANSPORT                (0x00000100 & DISABLE_MODULE)

/* RCS */
#define DLNA_LOG_UPNP_SERVICE_RCS              (0x00000200 & DISABLE_MODULE)

/* AVTS */
#define DLNA_LOG_UPNP_SERVICE_AVTS             (0x00000400 & DISABLE_MODULE)

/* CMS */
#define DLNA_LOG_UPNP_SERVICE_CMS              (0x00000800 & DISABLE_MODULE)

/* UPnP Service CP */
#define DLNA_LOG_UPNP_SERVICE_CP               (0x00001000 & DISABLE_MODULE)

/* UPnP Service CDS */
#define DLNA_LOG_UPNP_SERVICE_CDS              (0x00002000 & DISABLE_MODULE)

/* BMS */
#define DLNA_LOG_UPNP_SERVICE_BMS              (0x00004000 & DISABLE_MODULE)

/* EMS */
#define DLNA_LOG_UPNP_SERVICE_EMS              (0x00008000 & DISABLE_MODULE)

/* Device Class*/
#define DLNA_LOG_DEVICECLASS_DEVICE            (0x00010000 & DISABLE_MODULE)

/* Media debug */
#define DLNA_LOG_MEDIA                         (0x00020000 & DISABLE_MODULE)

/* DTCP debug */
#define DLNA_LOG_DTCP                          (0x00040000 & DISABLE_MODULE)

/* Dlna Device class common */
#define DLNA_LOG_DEVICECLASS_COMMON            (0x00080000 & DISABLE_MODULE)

/* DLNA_SUPPORT_RUIPL */
#define DLNA_LOG_DEVICECLASS_DEVCAP_RUI        (0x00100000 & DISABLE_MODULE)

/* +DN+ */
#define DLNA_LOG_DEVICECLASS_DEVCAP_DN         (0x00200000 & DISABLE_MODULE)

/* +UP+ */
#define DLNA_LOG_DEVICECLASS_DEVCAP_UP         (0x00400000 & DISABLE_MODULE)

/* Device Class Devcap */
#define DLNA_LOG_DEVICECLASS_DEVCAP_DIAG       (0x00800000 & DISABLE_MODULE)

#define DLNA_LOG_DEVICECLASS_DEVCAP_LP         (0x01000000 & DISABLE_MODULE)

#define DLNA_LOG_DEVICECLASS_DEVCAP_PR         (0x02000000 & DISABLE_MODULE)

/* WEBUI */
#define DLNA_LOG_WEBINTERFACE                  (0x04000000 & DISABLE_MODULE)

/* Timeval */
#define DLNA_LOG_TIMEVAL                       (0x08000000 & DISABLE_MODULE)

/* Database  */
#define DLNA_LOG_DB                            (0x10000000 & DISABLE_MODULE)

#define DLNA_LOG_MPE                           (0x20000000 & DISABLE_MODULE)

/* Utility  */
#define DLNA_LOG_UTIL                          (0x40000000 & DISABLE_MODULE)

/* Memory debug.  */
#define DLNA_LOG_MEMORY                        (0x80000001 & DISABLE_MODULE)

/* Medialink debug.  */
#define DLNA_LOG_MEDIALINK                     (0x80000002 & DISABLE_MODULE)
#endif /* DLNA_DEBUG_ID_H */
