/*
 * dlna_memory.h
 * Copyright (C) 2007-2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2005, 2006 IP Infusion, Inc. All Rights Reserved.  */

/* DLNA memory manager.  */

#ifndef NFLC_DLNA_MEMORY_H
#define NFLC_DLNA_MEMORY_H
/* Memory allocation related macros.  */
/* #define MEMORY_DEBUG */

#ifdef NLC_UNIT_TEST
#define MEMORY_DEBUG
#endif /* NLC_UNIT_TEST */

#ifdef MEMORY_DEBUG
/* Memory debug enabled version.  */
#define XMALLOC(TYPE,SIZE)      xmalloc(TYPE,SIZE,__LINE__,(slim_char *)__FILE__)
#define XCALLOC(TYPE,SIZE)      xcalloc(TYPE,SIZE,__LINE__,(slim_char *)__FILE__)
#define XREALLOC(TYPE,PTR,SIZE) xrealloc(TYPE,PTR,SIZE,__LINE__,(slim_char *)__FILE__)
#define XSTRDUP(TYPE,STR)       xstrdup(TYPE,STR,__LINE__,(slim_char *)__FILE__)
#define XFREE(TYPE,PTR)         xfree(TYPE,PTR)
#else
/* Memory debug disabled version.  */
#define XMALLOC(TYPE,SIZE)      dlna_memory_alloc(SIZE)
#define XCALLOC(TYPE,SIZE)      dlna_memory_zeroalloc(SIZE)
#define XREALLOC(TYPE,PTR,SIZE) dlna_memory_realloc(PTR,SIZE)
#define XSTRDUP(TYPE,STR)       dlna_strdup(STR)
#define XFREE(TYPE,PTR)         dlna_memory_free(PTR)
#endif /* MEMORY_DEBUG */

#define XFREE_IF(MTYPE, x) \
          do { \
            if (x) { \
              XFREE((MTYPE), (x));\
              (x) = slim_nil; \
            } \
          } while (0)

/* Memory types.  */
typedef enum memory_storage_type
  {
    MTYPE_BOGUS_FIRST,
    MTYPE_TMP,
    MTYPE_EVENT_MANAGER,            /* event.c */
    MTYPE_EVENT,
    MTYPE_VECTOR,                   /* vector.c */
    MTYPE_VECTOR_INDEX,
    MTYPE_SBUF,                     /* sbuf.c */
    MTYPE_SBUF_BUFFER,
    MTYPE_SXML_ELEMENT,             /* sxml.c */
    MTYPE_SXML_ATTRIBUTE,
    MTYPE_SXML_STRING,
    MTYPE_SXML_NODE,
    MTYPE_SXML_NODE_INDEX,
    MTYPE_SXML_DEQUE,
    MTYPE_DB,
    MTYPE_DB_STR,
    MTYPE_URL,                      /* uri.c */
    MTYPE_CONTENTS_MANAGER,         /* contents.c */
    MTYPE_SSDP_CLIENT,              /* ssdp_client.c */
    MTYPE_SSDP_BUFFER,
    MTYPE_GENA_CLIENT,              /* gena_client.c */
    MTYPE_GENA_VAL,
    MTYPE_GENA_CLIENT_SUB,
    MTYPE_SUBSCRIBE,
    MTYPE_SOAP_CLIENT,              /* soap_client.c */
    MTYPE_SOAP_CLIENT_PARAM,        /* SOAP client action name */
    MTYPE_SOAP_CLIENT_PARAM_STR,
    MTYPE_SOAP_RESULT_STR,
#ifdef DLNA_SUPPORT_RUIPL
    MTYPE_RUIS,
    MTYPE_RUI_CLIENT,               /* rui_client.c */
    MTYPE_RUIPL,                    /* ruipl_core.c */
    MTYPE_RUI_ABSTRACT,             /*Remote UI browser abstraction layer*/
    MTYPE_NOTIFY_CLIENT,
    MTYPE_NOTIFY_CLIENT_MSG,
    MTYPE_NOTIFY_CLIENT_MSG_URL,
#endif /* DLNA_SUPPORT_RUIPL */
#ifdef ENABLE_MOVIEDB_MOVIECOVER
    MTYPE_MDBC_CLIENT,              /*Movie DB Client*/
#endif /*ENABLE_MOVIEDB_MOVIECOVER*/
    MTYPE_HTTP_HEADER,              /* http_parser.c */
    MTYPE_HTTP_HEADER_STR,
    MTYPE_HTTP_CLIENT,              /* http_client.c */
    MTYPE_HTTP_RING_MASTER,         /* http_ring.c */
    MTYPE_HTTP_RING_BUFFER,         /* http_ring.c */
    MTYPE_UPNP_IF_MANAGER,          /* upnp_interface.c */
    MTYPE_UPNP_INTERFACE,
    MTYPE_UPNP_NETIF_EVENT,
    MTYPE_UPNP_IF_NAME,
    MTYPE_UPNP_IF_DESC,
#ifdef DEVELOPMENT_ENABLE_LPE
    MTYPE_UPNP_IF_WOP,              /* upnp_interface.c */
#endif
    MTYPE_UPNP_IF_ADDRESS, 
    MTYPE_UPNP_SERVER,              /* upnp_server.c */
    MTYPE_UPNP_SERVER_STR,
    MTYPE_UPNP_CLIENT,              /* upnp_client.c */
    MTYPE_UPNP_CLIENT_CP,
    MTYPE_UPNP_SEARCH_TYPE,
    MTYPE_UPNP_DEVICE,              /* upnp_device.c */
    MTYPE_UPNP_DEVICE_VALUE,
    MTYPE_UPNP_DEVICE_SERVICE,
    MTYPE_UPNP_DEVICE_SERVICE_STR,
    MTYPE_UPNP_DEVICE_SERVICE_VAR,
    MTYPE_UPNP_TRANSPORT_MANAGER,   /* upnp_contents.c */
    MTYPE_UPNP_TRANSPORT,
    MTYPE_UPNP_TRANSPORT_STR,
#ifdef DLNA_SUPPORT_UPLOADER
    MTYPE_UPNP_UPLOADER,
    MTYPE_DLNA_UPLOADER,
#endif
#ifdef DLNA_SUPPORT_DOWNLOADER
    MTYPE_UPNP_DOWNLOADER,
    MTYPE_UPNP_DOWNLOADER_STR,
#endif
    MTYPE_UPNP_PLAYER,
    MTYPE_UPNP_AVTS,
    MTYPE_SSDP_SERVER,              /* ssdp_server.c */
    MTYPE_SSDP_SERVER_INTERFACE,
    MTYPE_SSDP_SERVER_IF_DESC,
    MTYPE_SSDP_SERVER_CLIENT,
    MTYPE_GENA_SERVER,              /* gena_server.c */
    MTYPE_GENA_SERVER_HEADERS,
    MTYPE_UPNP_SERVICE,             /* UPnP service.  */
    MTYPE_UPNP_SERVICE_STR,
    MTYPE_UPNP_CONNECTION,          /* UPnP connection.  */
    MTYPE_HTTP_JOB,                 /* HTTP job.  */
    MTYPE_DMC,                      /* Digital Media Controller.  */
    MTYPE_DMS,                      /* Digital Media Server.  */
    MTYPE_DMS_CDS,
    MTYPE_DMS_CMS,
    MTYPE_DMS_XMMRR,
    MTYPE_CONTENTS,                 /* Contents.  */
    MTYPE_CONTENTS_STR,
    MTYPE_CONTENTS_URI,
    MTYPE_DMR,                      /* Digital Media Renderer.  */
    MTYPE_DMR_CMS,
    MTYPE_DMR_AVTS,
    MTYPE_DMR_RCS,
    MTYPE_DMR_CONNECTION,
    MTYPE_DMR_PINFO,
    MTYPE_DMPR,                     /* Digital Media Printer.  */
    MTYPE_DMPR_PES,
    MTYPE_DMPR_PBS,
    MTYPE_DMPR_PELS,
    MTYPE_SEARCH_EXP,               /* UPnP AV search expression.  */
    MTYPE_IDMAP,                    /* ID mapping. */
    MTYPE_IDMAP_ARRAY,
    MTYPE_HTTP_SESSION,             /* HTTP session.  */
    MTYPE_HTTP_SENDER,
    MTYPE_HTTP_RECEIVER,
    MTYPE_HTTP_MASTER,
    MTYPE_JPEG_STR,                 /* JPEG.  */
    MTYPE_LPCM_STR,                 /* LPCM.  */
    MTYPE_ID3_STR,                  /* ID3.  */
    MTYPE_MP3_STR,                  /* MP3.  */
    MTYPE_MPEG2_STR,                /* MPEG2.  */
    MTYPE_3GP_STR,                  /* 3GP.  */
    MTYPE_MP4_STR,                  /* MP4.  */
    MTYPE_ASF_STR,                  /* ASF.  */
    MTYPE_PNG_STR,                  /* PNG String Data  */
    MTYPE_PCX_STR,                  /* PCX String Data  */
    MTYPE_PPM_STR,                  /* PPM String Data  */
    MTYPE_BMP_STR,                  /* BMP String Data  */
    MTYPE_WAV_STR,                  /* WAV String Data  */
    MTYPE_RTML_STR,                 /* RTML Item. */
    MTYPE_AAC_ADTS_STR,             /* ADTS_AAC Item. */
    MTYPE_DAB_STR,
    MTYPE_QT_STR,
#ifdef DEVELOPMENT_DLNA_DMS_SUPPORT_AIFF
    MTYPE_AIFF_STR,                 /* AIFF/AIF Item */
#endif
    MTYPE_DMP,                      /* Digital Media Player.  */
    MTYPE_DMP_NODE,
    MTYPE_DMP_NODE_STR,
    MTYPE_DMP_OBJECT,
    MTYPE_DMP_OBJECT_ARRAY,

    MTYPE_ACCOUNTING,               /* Accounting data.  */
    MTYPE_ACCOUNTING_STR,

    MTYPE_DRM_MANAGER,
    MTYPE_AVI_STR,
#ifdef DLNA_DMS_SUPPORT_AC3
    MTYPE_AC3_STR,
#endif /* DLNA_DMS_SUPPORT_AC3 */
    MTYPE_OV_STR,
    MTYPE_TIFF_STR,
    MTYPE_FLV_STR,
    MTYPE_ATRAC_STR,

    MTYPE_HTTP_CONTENT_ACCESS,

#ifdef DLNA_SUPPORT_SRS
    MTYPE_DMS_SRS,
    MTYPE_SRS_STR,
    MTYPE_SRS_RECORDSCHEDULE,
    MTYPE_SRS_RECORDTASK,
#endif /* DLNA_SUPPORT_SRS */

    MTYPE_AUTH_PROFILE,
    MTYPE_CLINET_LIST,

#ifdef DLNA_SUPPORT_SATIP
    MTYPE_SATIP,
#endif /* DLNA_SUPPORT_SATIP */
#ifdef DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2
    MTYPE_DIAG_BMS,
    MTYPE_DIAG_BMS_STR,
#endif /*DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2*/
#ifdef DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_1
    MTYPE_LP_EMS,
#endif /*DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_1*/

#ifdef DEVELOPMENT_DLNA_SUPPORT_RA
    MTYPE_RAS,
    MTYPE_RAC,
    MTYPE_RADA,
    MTYPE_RADA_SYNC,
    MTYPE_RADA_CONFIG,
    MTYPE_RATA_CONFIG,
    MTYPE_INBOUND_CONNECTION_CONFIG,
#endif /* DEVELOPMENT_DLNA_SUPPORT_RA */

	MTYPE_MAX
  } dlna_mtype_t;

/* Prototypes.  */
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void *
xmalloc (slim_int type, slim_int size, slim_int in_line, slim_char *in_file);

void *
xcalloc (slim_int type, slim_int size, slim_int in_line, slim_char *in_file);

void *
xrealloc (slim_int type, void *ptr, slim_int size, slim_int in_line, slim_char *in_file);

slim_char *
xstrdup (slim_int type, const slim_char *s, slim_int in_line, slim_char *in_file);

void
xfree (slim_int type, void *ptr);

void
xmemory_show (void);

#ifdef IS_DEBUG_MEMORY_CHECK
void
xmemory_check_begin();

void
xmemory_check_end();
#endif 

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_DLNA_MEMORY_H */
