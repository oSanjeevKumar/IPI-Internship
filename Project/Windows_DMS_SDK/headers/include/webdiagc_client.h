/*
 * webdiagc_client.h
 * Copyright (C) 2014 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef __WEBDIAGC_CLIENT_H__
#define __WEBDIAGC_CLIENT_H__

#include <parental_guidance.h>

/** Action type */
typedef enum {
    GET_DEVICE_STATUS = 0,
    GET_DEVICE_TEST_IDS = 1,
    GET_DEVICE_ACTIVE_TEST_IDS = 2,
    GET_DEVICE_TEST_INFO = 3,
    ACTION_PING = 4,
    ACTION_TRACEROUTE = 5,
    ACTION_NSLOOKUP = 6,
    GET_ACTION_PING_RESULT = 7,
    GET_ACTION_TRACEROUTE_RESULT = 8,
    GET_ACTION_NSLOOKUP_RESULT = 9,
    GET_ACTION_GET_PING_RESULT = 10,
    GET_ACTION_GET_TRACEROUTE_RESULT = 11,
    GET_ACTION_GET_NSLOOKUP_RESULT = 12
}ACTIONTYPE;

slim_bool
webdiagc_client_init_dmc_diagc();

slim_bool
webdiagc_client_release_dmc_diagc();

slim_int
webdiagc_client_get_dms_count();

slim_int
webdiagc_client_action_get_test_info_response(slim_char *out_type, slim_char *out_state, slim_int in_max_str_size);

slim_int
webdiagc_client_action_get_ping_result_response(slim_char *out_status, slim_char *out_additionalInfo, slim_char *out_successCount, slim_char *out_failureCount, slim_char *out_averageResponseTime, slim_char *out_minimumResponseTime, slim_char *out_maximumResponseTime, slim_int in_max_str_size);

slim_int
webdiagc_client_action_get_traceroute_result_response(slim_char *out_status, slim_char *out_additionalInfo, slim_char *out_responseTime, slim_char *out_hopHosts, slim_int in_max_str_size);

slim_int
webdiagc_client_action_get_nslookup_result_response(slim_char *out_status, slim_char *out_additionalInfo, slim_char *out_successCount, slim_char *out_result, slim_int in_max_str_size);

slim_int
webdiagc_client_action_get_response(slim_char *out_response, slim_int in_max_str_size, ACTIONTYPE in_type);

slim_int
webdiagc_client_get_dms_prop_by_indexId(slim_int in_indexId, slim_char *out_device_name, slim_char *out_uuid, slim_int in_max_str_size);

slim_int
webdiagc_client_action_get_device_status(slim_char *in_uuid);

slim_int
webdiagc_client_action_get_test_ids(slim_char *in_uuid);

slim_int
webdiagc_client_action_get_active_test_ids(slim_char *in_uuid);

slim_int
webdiagc_client_action_get_test_info(slim_char *in_uuid, slim_int in_testId);

slim_int
webdiagc_client_action_get_ping_result(slim_char *in_uuid, slim_int in_testId);

slim_int
webdiagc_client_action_get_traceroute_result(slim_char *in_uuid, slim_int in_testId);

slim_int
webdiagc_client_action_get_nslookup_result(slim_char *in_uuid, slim_int in_testId);

slim_int
webdiagc_client_action_ping(slim_char *in_uuid, slim_char *in_host, slim_int in_numberOfRepetitions, slim_int in_timeOut, slim_int in_dataBlockSize, slim_int in_DSCP);

slim_int
webdiagc_client_action_trace_route(slim_char *in_uuid, slim_char *in_host, slim_int in_timeOut, slim_int in_dataBlockSize, slim_int in_count, slim_int in_DSCP);

slim_int
webdiagc_client_action_nslookup(slim_char *in_uuid, slim_char *in_host, slim_char *in_dns, slim_int in_numberOfRepetitions, slim_int in_timeOut);
#endif /* __WEBDIAGC_CLIENT_H__ */
