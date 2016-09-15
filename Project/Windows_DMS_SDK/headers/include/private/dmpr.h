/* Copyright (C) 2005 IP Infusion, Inc. All Rights Reserved.  */

#ifndef _DMPR_H
#define _DMPR_H

#define DMPR_SERVICE_PES	0 /* PrintEnhanced.  */
#define DMPR_SERVICE_PBS	1 /* PrintBasic.  */
#define DMPR_SERVICE_PELS	2 /* PrintEnhancedLayout.  */
#define DMPR_SERVICE_MAX	3

#define DMPR_SERVICE_ID_PES   "PrintEnhanced"
#define DMPR_SERVICE_ID_PBS   "PrintBasic"
#define DMPR_SERVICE_ID_PELS  "PrintEnhancedLayout"

#if 0
struct dmpr_service_request {
  struct dmpr_service_request *prev;
  struct dmpr_service_request *next;
  struct upnp_action_request base;
  slim_int rid; /* Unique Request ID */
};
#endif

struct dmpr;

/* UI callback function type.  */
typedef slim_int (*dmpr_callback_t)(struct dmpr *top, sXML *doc);

/* DMPr service base structure.  */
struct dmpr_service {
  /* Backpoiner to the top.  */
  struct dmpr *top;

  /* Sercie ID.  */
  slim_char *id;
  struct http_client *hc;

  /* state variables */

  /* Member functions.  */
  slim_int (*start)(struct dmpr_service *);
  slim_int (*stop)(struct dmpr_service *);
  /*Subscribe for notification*/
  slim_int (*subscribe)(struct dmpr_service *, struct upnp_subscribe_request *);
  slim_int (*get_var)(struct dmpr_service *, struct upnp_query_variable *);
  slim_int (*action)(struct dmpr_service *, struct upnp_action_request *);
  /*Subscribe for notification*/
  slim_int (*subscription_end)(struct dmpr_service *,
      struct upnp_action_request *);
  slim_int (*subscription_update)(struct dmpr_service *,
      struct upnp_action_request *);


  slim_int printer_state_changed;
  slim_int job_end_state_changed;
  slim_int job_abort_state_changed;
  slim_int job_list_changed;
 
  slim_int media_sheets_completed_changed ;
  slim_int content_complete_list_changed ;

};

/* DMPr structure.  */
struct dmpr {
  /* UPnP server pointer.  */
  struct upnp_server *us;

  /* UI callback function.  */
  dmpr_callback_t async_callback;

  /* String buffer.  */
  struct sbuf *sbuf;

  /* Callbacks.  */
  struct dmpr_service *(*service_lookup)(struct dmpr *, int);

  /* DMPr services.  */
  struct dmpr_service *service[DMPR_SERVICE_MAX];

  /* ssdp common module */
  struct dlna_ssdp_tag *ssdp_common;

  /* printer peer event handler */
  DMPrNotifyCallback notify_callback;
  /* instance */
  TDMPrContext *context;
  /* user space pointer */
  void *arg;

  struct sbuf Var_A_ARG_TYPE_CriticalAttributeList;
  struct sbuf Var_A_ARG_TYPE_MediaList;
  struct sbuf Var_A_ARG_TYPE_PrinterAbortReasons;
  struct sbuf Var_CharRepSupported;
  struct sbuf Var_ColorSupported;
  struct sbuf Var_ContentCompleteList ;
  struct sbuf Var_Copies;
  struct sbuf Var_CriticalAttributesSupported;
  struct sbuf Var_DataSink;
  struct sbuf Var_DeviceId;
  struct sbuf Var_DocumentFormat;
  struct sbuf Var_DocumentUTF16Supported;
  struct sbuf Var_FullBleedSupported;
  struct sbuf Var_InternetConnectState ;
  struct sbuf Var_JobAbortState ;
  struct sbuf Var_JobEndState ;
  struct sbuf Var_JobId ;
  struct sbuf Var_JobIdList ;
  struct sbuf Var_JobMediaSheetsCompleted ;
  struct sbuf Var_JobName ;
  struct sbuf Var_JobOriginatingUserName ;
  struct sbuf Var_MediaSize;
  struct sbuf Var_MediaType;
  struct sbuf Var_NumberUp;
  struct sbuf Var_OrientationRequested;
  struct sbuf Var_PageMargins;
  struct sbuf Var_PrinterLocation ;
  struct sbuf Var_PrinterName;
  struct sbuf Var_PrintQuality ;
  struct sbuf Var_PrinterState ;
  struct sbuf Var_PrinterStateReasons ;
  struct sbuf Var_Sides;
  struct sbuf Var_SourceURI;
  struct sbuf Var_XHTMLImageSupported;


//  TDMPrDeviceFeatures device_features;

  List (TDMPrJob *) jobs ;
// List(struct dmpr_service_request*) req_list;

 };

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Prototypes.  */

/* API: Allocate DMPr.  */
struct dmpr *
dmpr_alloc(dlna_progress in_p, dmpr_callback_t callback, slim_half port,
    slim_char *root_dir, slim_char *config_dir, slim_char *device_file);

/* API: Free DMPr.  */
slim_int
dmpr_free(struct dmpr *top);

/* API: Start DMPr.  */
slim_int
dmpr_start(struct dmpr *top);

/* API: Stop DMPr.  */
slim_int
dmpr_stop(struct dmpr *top);

/* API: Update DMPr.  */
slim_int
dmpr_update(struct dmpr *top);

/* API: Start DMPr for the interface.  */
slim_int
dmpr_if_start(struct dmpr *top, slim_int ifindex);

/* API: Stop DMPr for the interface.  */
slim_int
dmpr_if_stop(struct dmpr *top, slim_int ifindex);

struct dmpr_service *
dmpr_service_lookup(struct dmpr *top, slim_int id) ;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _DMPR_H */
