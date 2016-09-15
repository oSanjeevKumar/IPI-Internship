/*
 * hnso_api.h
 * Copyright (C) 2007-2011 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */
  
/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */

/* HNSO API.  */

#ifndef NFLC_HNSO_API_H
#define NFLC_HNSO_API_H

#ifdef __WIN32__
  #ifndef slim_int 
  #define slim_int int
  #endif
  #ifndef slim_char 
  #error
  #define slim_char char
  #endif
  #ifndef slim_bool 
  #define slim_bool unsigned int
  #endif
  #ifndef slim_long
  #define slim_long long
  #endif
#endif /* __WIN32__ */

#ifdef __WIN32__
  #ifdef HNSO_EXPORTS
  #define HNSO_API __declspec(dllexport)
  #else
  #define HNSO_API __declspec(dllimport)
  #endif
#else /* __WIN32__ */
  #define HNSO_API
#endif /* __WIN32__ */

typedef enum {
    HNSO_PLAYER_OPEN = 0,
    HNSO_PLAYER_CLOSE,
    HNSO_PLAYER_PLAY,
    HNSO_PLAYER_PAUSE,
    HNSO_PLAYER_STOP,
    HNSO_PLAYER_PREVIOUS,
    HNSO_PLAYER_NEXT,
    HNSO_PLAYER_UPDATE,
    HNSO_PLAYER_READ_READY,
    HNSO_PLAYER_WRITE_READY,
    HNSO_PLAYER_FF,
    HNSO_PLAYER_SF,
    HNSO_PLAYER_FR,
    HNSO_PLAYER_SR,
    HNSO_PLAYER_ERROR,
    HNSO_PLAYER_ENGINE_ERROR,
    HNSO_PLAYER_END_OF_MEDIA,
    HNSO_PLAYER_SEEKTIME,
    HNSO_PLAYER_SEEKBYTES,
    HNSO_PLAYER_TRANSITIONING,
    HNSO_VC_EVENT_VOLUME_CHANGED,
    HNSO_PLAYER_COMMAND_GETDURATION,
    HNSO_PLAYER_COMMAND_GETVOLUME,
    HNSO_PLAYER_COMMAND_GETTIMEPOS,
    HNSO_PLAYER_EVENT_MAX
} HNSO_PLAYER_EVENT;

typedef void (*THNSODiscoveryEventHandler) (slim_char *in_device);
typedef void (*THNSOActionResultEventHandler) (slim_char *in_user_cookie, slim_int in_error_code, slim_char *in_soap_xml_result);
typedef void (*THNSOStateVariableChangeEventHandler) (slim_char *device, slim_char *service, slim_char *in_variable);
typedef void (*THNSODeviceNotifyChangeEventHandler) (slim_char *in_device);
typedef void (*THNSODMREventHandler) (HNSO_PLAYER_EVENT in_event, void *in_parameters);

/* Prototypes.  */
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_int HNSO_API HNSO_New (slim_char* in_config_dir) ;
void HNSO_API HNSO_Delete() ;

HNSO_API void HNSO_SetHandler_onDiscoveryNewDevice (THNSODiscoveryEventHandler p);
HNSO_API void HNSO_SetHandler_onDiscoveryRemoveDevice (THNSODiscoveryEventHandler p);
HNSO_API void HNSO_SetHandler_onActionResult (THNSOActionResultEventHandler p);
HNSO_API void HNSO_SetHandler_onStateVariableChange (THNSOStateVariableChangeEventHandler p);
HNSO_API void HNSO_SetHandler_onDeviceNotifyChange (THNSODeviceNotifyChangeEventHandler p);
HNSO_API void HNSO_SetHandler_onDMREvent (THNSODMREventHandler p);

HNSO_API void HNSO_SetHandler() ;

slim_bool HNSO_onDMREvent (HNSO_PLAYER_EVENT in_event, void* in_params);
HNSO_API slim_bool HNSO_ScanDeviceList() ;
HNSO_API slim_bool HNSO_ScanLocalDeviceList() ;

HNSO_API slim_char* HNSO_getDeviceDescription(slim_char *in_device_handle) ;
HNSO_API slim_char* HNSO_getDescriptionProperty(slim_char *in_device_handle, slim_char *in_property_name) ;
HNSO_API slim_char* HNSO_getDeviceProperty(slim_char *in_device_handle, slim_char *in_property_name);

HNSO_API slim_char* HNSO_scanServiceList(slim_char *in_device_handle);
HNSO_API slim_char* HNSO_getServiceName(slim_char *in_device_handle, slim_char *in_service_handle);
HNSO_API slim_char** HNSO_getServiceStateVars(slim_char *in_device_handle, slim_char *in_service_handle) ;
HNSO_API slim_char** HNSO_getServiceStateVarInfo(slim_char *in_device_handle, slim_char *in_service_handle, slim_char *in_var_name);
HNSO_API slim_char** HNSO_getServiceStateAllowedValues(slim_char *in_device_handle, slim_char *in_service_handle, slim_char *in_var_name);
HNSO_API slim_char* HNSO_getServiceStateVarValue(slim_char *in_device_handle, slim_char *in_service_handle, slim_char *in_var_name) ;

HNSO_API slim_char** HNSO_getServiceActions(slim_char *in_device_handle, slim_char *in_service_handle);
HNSO_API slim_char** HNSO_getActionParametersNames(slim_char *in_device_handle, slim_char *in_service_handle, slim_char *in_action_name) ;
HNSO_API slim_char** HNSO_getActionParameterInfo(slim_char *in_device_handle, slim_char *in_service_handle, slim_char *in_action_name, slim_char *in_parameter_name);

HNSO_API slim_bool HNSO_hnAction(slim_char *in_device_handle, slim_char *in_service_handle, slim_char *in_action_name, slim_char *in_action_parms, slim_char *in_user_cookie );
HNSO_API slim_char* HNSO_parseSoapResponse(slim_char *in_soap_response_xml, slim_char *in_variable_name) ;

HNSO_API slim_char* HNSO_getBrowserSecurityMode(slim_char *in_device_handle, slim_char *in_service_handle);
HNSO_API slim_bool HNSO_loginToDevice(slim_char *in_device_handle, slim_char *in_password);
HNSO_API slim_int HNSO_getLoginTimeRemeining(slim_char *in_device_handle);

HNSO_API slim_char* HNSO_findService(slim_char *in_device_handle, slim_char *in_service_name) ;
HNSO_API slim_char* HNSO_getBaseURL(slim_char *in_device_handle, slim_char *out_uri, slim_int in_buf_len) ;
HNSO_API slim_bool HNSO_notifyNflcCore(slim_char *event_name);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_HNSO_API_H */
