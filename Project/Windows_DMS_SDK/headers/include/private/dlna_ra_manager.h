/*
 * dlna_ra_manager.h
 * Copyright (C) 2009 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_DLNA_RA_MANAGER_H
#define NFLC_DLNA_RA_MANAGER_H

#ifdef DEVELOPMENT_DLNA_SUPPORT_RA
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* RADASync */
/* RADAConfig */
slim_int 
dlna_rada_config_get_system_info_result (dlna_client_t *top, struct upnp_param_action *in_param) ;
slim_int 
dlna_rada_config_edit_filter_result (dlna_client_t *top, struct upnp_param_action *in_param) ;
/* RATAConfig */
slim_int 
dlna_rata_config_get_transport_agent_capabilities_result (dlna_client_t *top, struct upnp_param_action *in_param) ;
slim_int 
dlna_rata_config_get_supported_credential_delivery_result (dlna_client_t *top, struct upnp_param_action *in_param) ;
slim_int 
dlna_rata_config_get_credentials_list_result (dlna_client_t *top, struct upnp_param_action *in_param) ;
slim_int 
dlna_rata_config_get_profile_list_result (dlna_client_t *top, struct upnp_param_action *in_param) ;
slim_int 
dlna_rata_config_add_profile_result (dlna_client_t *top, struct upnp_param_action *in_param) ;
slim_int 
dlna_rata_config_edit_profile_result (dlna_client_t *top, struct upnp_param_action *in_param) ;
slim_int 
dlna_rata_config_delete_profile_result (dlna_client_t *top, struct upnp_param_action *in_param) ;
slim_int 
dlna_rata_config_get_profile_config_info_result (dlna_client_t *top, struct upnp_param_action *in_param) ;
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* DEVELOPMENT_DLNA_SUPPORT_RA */
#endif /* NFLC_DLNA_RA_MANAGER_H */
