/*
 * upnp_bms.h
 * Copyright (C) 2013 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_UPNP_BMS_H
#define NFLC_UPNP_BMS_H

#include <dlna_peer.h>
#include <nflc_sxml.h>
#include <nflc_contents.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef PARAMETER_NOT_USED
#define PARAMETER_NOT_USED(p) ((void)(p))
#endif /* PARAMETER_NOT_USED */

/* UPnP BasicManagement:2 2.3.14 A_ARG_TYPE_TestType */
typedef enum upnp_bms_test_type_
{
  E_UPNP_BMS_TEST_TYPE_INVALID = 0,
  E_UPNP_BMS_TEST_TYPE_BANDWIDTH,
  E_UPNP_BMS_TEST_TYPE_INTERFACE_RESET,
  E_UPNP_BMS_TEST_TYPE_NSLOOKUP,
  E_UPNP_BMS_TEST_TYPE_PING,
  E_UPNP_BMS_TEST_TYPE_SELF_TEST,
  E_UPNP_BMS_TEST_TYPE_TRACEROUTE,
  E_UPNP_BMS_TEST_TYPE_MAX
} upnp_bms_test_type;

/* UPnP BasicManagement:2 2.3.15 A_ARG_TYPE_TestState */
typedef enum upnp_bms_test_state_
{
  E_UPNP_BMS_TEST_STATE_INVALID = 0,
  E_UPNP_BMS_TEST_STATE_REQUESTED,
  E_UPNP_BMS_TEST_STATE_IN_PROGRESS,
  E_UPNP_BMS_TEST_STATE_CANCELED,
  E_UPNP_BMS_TEST_STATE_COMPLETED,
  E_UPNP_BMS_TEST_STATE_MAX
} upnp_bms_test_state;

/* UPnP BasicManagement:2 2.3.23 A_ARG_TYPE_PingStatus */
typedef enum upnp_bms_ping_status_
{
  E_UPNP_BMS_TEST_PING_STATUS_SUCCESS = 0,
  E_UPNP_BMS_TEST_PING_STATUS_ERROR_CANNOT_RESOLVE_HOSTNAME,
  E_UPNP_BMS_TEST_PING_STATUS_ERROR_INTERNAL,
  E_UPNP_BMS_TEST_PING_STATUS_ERROR_OTHER
} upnp_bms_ping_status;

typedef void  (*upnp_bms_update_proc)(void *info);

/* UPnP BasicManagement:2 2.5.6 Ping Parameters */
typedef struct upnp_bms_ping_param_
{
  slim_char *host;
  slim_char *numberOfRepetitions;
  slim_char *timeout;
  slim_char *dataBlockSize;
  slim_char *dscp;
} upnp_bms_ping_param;

/* UPnP BasicManagement:2 2.5.7 GetPingResult */
typedef struct upnp_bms_ping_result_
{
  upnp_bms_ping_status   status;
  slim_char              *additionalInfo;
  slim_word              successCount;
  slim_word              failureCount;
  slim_word              averageResponseTime;
  slim_word              minimumResponseTime;
  slim_word              maximumResponseTime;
} upnp_bms_ping_result;


typedef enum upnp_bms_nslookup_status_
{
  E_UPNP_BMS_TEST_NSLOOKUP_STATUS_SUCCESS = 0,
  E_UPNP_BMS_TEST_NSLOOKUP_STATUS_ERROR_DNS_SERVER_NOT_RESOLVED,
  E_UPNP_BMS_TEST_NSLOOKUP_STATUS_ERROR_INTERNAL,
  E_UPNP_BMS_TEST_NSLOOKUP_STATUS_ERROR_OTHER
} upnp_bms_nslookup_status;

/* UPnP BasicManagement:2 2.5.8 NSLookup Parameters */
typedef struct upnp_bms_nslookup_param_
{
  slim_char *hostName;
  slim_char *dnsServer;
  slim_char *numberOfRepetitions;
  slim_char *timeout;
} upnp_bms_nslookup_param;

/* UPnP BasicManagement:2 2.5.9 GetNSLookupResult */
typedef struct upnp_bms_nslookup_result_
{
  dlna_diag_status   status;
  slim_char          *additionalInfo;
  slim_word          successCount;
  sXML               *result;
} upnp_bms_nslookup_result;

/* UPnP BasicManagement:2 2.3.26 A_ARG_TYPE_TracerouteStatus */
typedef enum upnp_bms_traceroute_status_
{
  E_UPNP_BMS_TEST_TRACEROUTE_STATUS_SUCCESS = 0,
  E_UPNP_BMS_TEST_TRACEROUTE_STATUS_ERROR_CANNOT_RESOLVE_HOSTNAME,
  E_UPNP_BMS_TEST_TRACEROUTE_STATUS_ERROR_MAX_HOP_COUNT_EXCEEDED,
  E_UPNP_BMS_TEST_TRACEROUTE_STATUS_ERROR_INTERNAL,
  E_UPNP_BMS_TEST_TRACEROUTE_STATUS_ERROR_OTHER
} upnp_bms_traceroute_status;

/* UPnP BasicManagement:2 2.5.10 Traceroute Parameters */
typedef struct upnp_bms_traceroute_param_
{
  slim_char *host;
  slim_char *timeout;
  slim_char *dataBlockSize;
  slim_char *maxHopCount;
  slim_char *dscp;
} upnp_bms_traceroute_param;

/* UPnP BasicManagement:2 2.5.11 GetTracerouteResult */
typedef struct upnp_bms_traceroute_result_
{
  upnp_bms_traceroute_status   status;
  slim_char                    *additionalInfo;
  slim_word                    responseTime;
  slim_char                    *hopHosts;
} upnp_bms_traceroute_result;

/* Test manager for UPnP BasicManagement:2 */
typedef struct upnp_bms_test_
{
  slim_word             id;
  upnp_bms_test_type    type;
  upnp_bms_test_state   state;
  dlna_diag_test handle;
  /* Union for action parameters */
  union {
    upnp_bms_ping_param         param_ping;
    upnp_bms_nslookup_param     param_nslookup;
    upnp_bms_traceroute_param   param_traceroute;
  } param;
  /* Union for action results */
  union {
    upnp_bms_ping_result        result_ping;
    upnp_bms_nslookup_result    result_nslookup;
    upnp_bms_traceroute_result  result_traceroute;
  } result;
} upnp_bms_test;

struct _upnp_bms_devicestatus
{
  struct _upnp_bms_devicestatus * next;
  struct _upnp_bms_devicestatus * prev;
  slim_char *device_status;
};

typedef struct _upnp_bms_devicestatus upnp_bms_devicestatus;
//ListNamed(struct _upnp_bms_device_status *, _upnp_bms_device_status_list);

struct _upnp_testids
{
  struct _upnp_testids * next;
  struct _upnp_testids * prev;
  slim_word test_id;
  upnp_bms_test_type type;
};

typedef struct _upnp_testids upnp_testids;

struct _upnp_active_testids
{
  struct _upnp_active_testids * next;
  struct _upnp_active_testids * prev;
  slim_word active_test_id;
};

typedef struct _upnp_active_testids upnp_active_testids;

typedef struct upnp_bms_
{
#ifdef HAVE_DMS
  /* Back-pointer to the top.  */
  struct dms *top;
#endif /* HAVE_DMS */
#ifdef HAVE_DMR
  struct dmr *top;
#endif /*HAVE_DMR*/

  struct upnp_action_request *action_request;
  /* SOAP action.  */
  sXML *action_doc;

  /* SOAP result document.  */
  sXML *result_doc;

  void *info;

  /* Incomming interface index used for the XML resources.  */
  slim_int ifindex;

  /* Directory where to store XMLs for action result */
  slim_char *xml_dir;

  /* Global TestID of A_ARG_TYPE_TestID with type ui4.
   * Valid from 1 or above. */
  slim_word testId;

  /* Global Device Status of DeviceStatus with type CSV */
  slim_char* device_status;

  /* Global test manager. */
  upnp_bms_test tests[E_UPNP_BMS_TEST_TYPE_MAX];

  upnp_bms_update_proc update_callback;
  List(upnp_testids*) testids_list;
  List(upnp_active_testids*) active_testids_list;
} upnp_bms;

/* memory alloc, free */
upnp_bms*
upnp_bms_alloc(struct upnp_if_manager *ifm, slim_char *xml_dir, void *info, upnp_bms_update_proc in_update_callback);

slim_int
upnp_bms_free (upnp_bms *s);


/* UPnP BasicManagement:2 2.5 Actions */
slim_int
upnp_bms_get_device_status (upnp_bms *s);

slim_int
upnp_bms_get_test_ids (upnp_bms *s);

slim_int
upnp_bms_get_active_test_ids (upnp_bms *s);

slim_int
upnp_bms_get_test_info (upnp_bms *s);

slim_int
upnp_bms_cancel_test (upnp_bms *s);

slim_int
upnp_bms_ping (upnp_bms *s);

slim_int
upnp_bms_get_ping_result (upnp_bms *s);

slim_int
upnp_bms_nslookup (upnp_bms *s);

slim_int
upnp_bms_get_nslookup_result (upnp_bms *s);

slim_int
upnp_bms_traceroute (upnp_bms *s);

slim_int
upnp_bms_get_traceroute_result (upnp_bms *s);

/* UPnP BasicManagement:2 2.3 State Variables */
slim_char*
upnp_bms_device_status (upnp_bms *s);

slim_char *
upnp_bms_test_ids (upnp_bms *s);

slim_char *
upnp_bms_active_test_ids (upnp_bms *s);

slim_char *
upnp_bms_a_arg_type_test_id (upnp_bms *s);

slim_char *
upnp_bms_a_arg_type_test_type (upnp_bms *s);

slim_char *
upnp_bms_a_arg_type_test_state (upnp_bms *s);

slim_char *
upnp_bms_a_arg_type_dscp (upnp_bms *s);

slim_char *
upnp_bms_a_arg_type_host (upnp_bms *s);

slim_char *
upnp_bms_a_arg_type_hosts (upnp_bms *s);

slim_char *
upnp_bms_a_arg_type_hostname (upnp_bms *s);

slim_char *
upnp_bms_a_arg_type_ping_status (upnp_bms *s);

slim_char *
upnp_bms_a_arg_type_nslookup_status (upnp_bms *s);

slim_char *
upnp_bms_a_arg_type_nslookup_result (upnp_bms *s);

slim_char *
upnp_bms_a_arg_type_traceroute_status (upnp_bms *s);

#if 0
void
upnp_bms_device_status_list_clear(upnp_bms *s);
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_UPNP_BMS_H */

