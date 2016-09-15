/*
 * rui_defines.h
 * Copyright (C) 2009-2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifdef DLNA_SUPPORT_RUISRC

#ifndef __RUI_DEFINES_H__
#define __RUI_DEFINES_H__

#include <nflc_upnp_api.h>
/* they should be in dlna_debug.h
#define IS_DEBUG_RUISRC_VERBOSE    0
#define IS_DEBUG_RUISRC_EVENT      0
#define IS_DEBUG_RUISRC_ERROR      1
*/
#ifdef DEVELOPMENT_DLNA_SUPPORT_RUIHSRC
#ifdef  DLNA_RUISRC_SERVER_LEVEL_2
#define RUISRC_DEV_DESCR_FILE  "ruihsrc_devdescr_l2.xml"
#else   /* !DLNA_RUISRC_SERVER_LEVEL_2 */
#define RUISRC_DEV_DESCR_FILE  "ruihsrc_devdescr_l1.xml"
#endif  /* DLNA_RUISRC_SERVER_LEVEL_2 */
#else
#ifdef  DLNA_RUISRC_SERVER_LEVEL_2
#define RUISRC_DEV_DESCR_FILE  "ruisrc_devdescr_l2.xml"
#else   /* !DLNA_RUISRC_SERVER_LEVEL_2 */
#define RUISRC_DEV_DESCR_FILE  "ruisrc_devdescr_l1.xml"
#endif  /* DLNA_RUISRC_SERVER_LEVEL_2 */
#endif  /* DEVELOPMENT_DLNA_SUPPORT_RUIHSRC */

#define RUISRC_UILIST_FILE     "ruisrc_uilist.xml"
#define RUISRC_UILIST_FILTER_TEMPLATE_FILE  "ruisrc_uilist_filter_template.xml"

#define RUISRC_ELNAME_FRIENDLY_NAME   "friendlyName"
#define RUISRC_ELNAME_MANUFACTURER    "manufacturer"
#define RUISRC_ELNAME_MANUFACTURERURL "manufacturerURL"
#define RUISRC_ELNAME_MODELNAME       "modelName"
#define RUISRC_ELNAME_MODELNUMBER     "modelNumber"
#define RUISRC_ELNAME_MODELURL        "modelURL"
#define RUISRC_ELNAME_UDN             "UDN"
#define RUISRC_ELNAME_NULL            ""

#define RUISRC_UDN_DEFAULT           "uuid:00000000-0000-0000-0000-000000000000"

#define RUISRC_UI_ID_LEN_MAX                256
#define RUISRC_UI_ID_DEFAULT                "0000-0000-0000-0000"
#define RUISRC_UI_DESCR_LEN_MAX             2048
#define RUISRC_UI_PROT_SHORT_NAME_LEN_MAX   256
#define RUISRC_UI_PROT_URI_LEN_MAX          1024
#define RUISRC_UI_PROT_URI_PI_HTTP          "http://"
#define RUISRC_UI_PROT_URI_PI_HTTPS         "https://"

#define RUISRC_UILIST_UI_ADD_URI      "/ruisrc_uilist_add_ui"
#define RUISRC_UILIST_UI_REMOVE_URI   "/ruisrc_uilist_remove_ui"
#define RUISRC_UILIST_UI_UPDATE_URI   "/ruisrc_uilist_update_ui"

#define RUISRC_UPDATED_UI_ID_LIST_MAX_LEN   2048
#define RUISRC_UILISITING_UPDATE_LINE_FMT   "<uiID>%s</uiID>\r\n"

typedef enum {
  RUI_RESULT_FAIL = UPNP_GENERIC_ERROR,
  RUI_RESULT_SUCCESS = UPNP_SUCCESS,
  RUI_RESULT_OPERATION_REJECTED = 701,
  RUI_RESULT_INVALID_FILTER = 702,
  RUI_RESULT_UNSUPPORTED_LIFETIME = 703
} rui_result_t;

typedef enum {
  RUISRC_UI_OPER_ADD = 1,
  RUISRC_UI_OPER_REMOVE,
  RUISRC_UI_OPER_UPDATE
} ruisrc_ui_oper_t;

#endif /* __RUI_DEFINES_H__ */

#endif /* DLNA_SUPPORT_RUISRC */

