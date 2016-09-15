/*
 * dlna_dmpr.h
 * Copyright (C) 2007-2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef _DLNA_DMPr_H
#define _DLNA_DMPr_H

#include <dlna_client.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef DEVELOPMENT_DLNA_SUPPORT_DMPR

/**
 * @addtogroup macros
 */
/*@{*/

/* DMPr API  error */
#define DMPr_SOAP_INVALID_SYNTAX								(801)
#define DMPr_SOAP_INSUFFICIENT_PROPERTIES						(802)
#define DMPr_SOAP_INVALID_VALUE								(803)
#define DMPr_SOAP_CANNOT_PROCESS_REQUEST						(820)
#define DMPr_SOAP_CONFLICT										(830)
#define DMPr_SOAP_HTTP_TIMEOUT									(901)
#define DMPr_SOAP_HTTP_SESSION_ERROR							(902)

/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/

slim_int
dlna_dmpr_create_jobv2 (dlna_object_t *obj,slim_char *in_buf, TDLNAObjectDmprParamPrivate *in_param );

slim_int
dlna_dmpr_print (dlna_object_t *dev,TDLNAObjectDmprParamPrivate *in_param);

slim_int
dlna_dmpr_print_print (dlna_object_t *dev, TDLNAObjectEventHandler in_obj_eh, void *in_arg,
                                                                  slim_char *in_uri, TDLNAObjectDmprParamPrivate *in_param) ;

slim_int
dlna_dmpr_create_jobv2_result (dlna_client_t *top, struct upnp_param_action *param) ;

slim_int
dlna_dmpr_get_media_list_result (dlna_client_t *top, struct upnp_param_action *param) ;

slim_int
dlna_dmpr_get_margins_result (dlna_client_t *top, struct upnp_param_action *param) ;

slim_int
dlna_dmpr_cancel_job_result (dlna_client_t *top, struct upnp_param_action *param) ;

slim_int
dlna_dmpr_get_printer_attributes_result (dlna_client_t *top, struct upnp_param_action *param) ;


void 
dlna_dmpr_post_buffer(dlna_client_t *top, slim_char *in_datasink_uri,dlna_object_t *in_obj, slim_int in_job_id) ;

slim_int
dlna_dmpr_cancel_job (dlna_object_t *obj, TDLNAObjectEventHandler in_obj_eh, void *in_arg, slim_int in_job_id) ;

slim_int
dlna_dmpr_get_printer_attributes (dlna_object_t *obj, TDLNAObjectEventHandler in_obj_eh, void *in_arg) ;

TDLNAObjectDmprParamPrivate *
dlna_dmpr_param_alloc(TDLNAObjectDmprParam *in_param, slim_char *in_image_uri, slim_int in_width, slim_int in_height);

void
dlna_dmpr_param_free(TDLNAObjectDmprParamPrivate *in_param);


typedef void* dlna_dmpr_controller_t;

dlna_dmpr_controller_t
dlna_dmpr_controller_alloc (dlna_client_t *in_dlna_client);

void
dlna_dmpr_controller_free (dlna_dmpr_controller_t self);

slim_int
dlna_dmpr_controller_start (dlna_dmpr_controller_t self);

slim_int
dlna_dmpr_controller_stop (dlna_dmpr_controller_t self);

slim_int
dlna_dmpr_gena_update (dlna_dmpr_controller_t in_dmpr, dlna_client_t *in_dc, gena_notify_param_t *in_param);

slim_int
dlna_dmpr_device_notify_byebye (dlna_dmpr_controller_t in_dmpr, dlna_client_t *in_dc, slim_char *in_udn);

slim_int
dlna_dmpr_print_file (dlna_dmpr_controller_t self, dlna_object_t *in_dev, slim_char *in_fname, 
                      slim_char *in_pr_mediatype, slim_char *in_pr_mediasize,
                      slim_char *in_jobname, slim_char *in_jobtitle, dlna_dmpr_orientation in_orientation,
                      slim_int in_copies, slim_int in_fontsize, dlna_dmpr_quality in_quality);

slim_int
dlna_dmpr_print_uri (dlna_dmpr_controller_t self, dlna_object_t *in_dev, slim_char *in_uri, slim_char *in_pinfo,
                     slim_char *in_mediatype, slim_char *in_mediasize,
                     slim_char *in_jobname, slim_char *in_jobtitle, dlna_dmpr_orientation in_orientation,
                     slim_int in_width, slim_int in_height,
                     slim_int in_copies, slim_int in_fontsize, dlna_dmpr_quality in_quality);

/*@}*/

#endif /* DEVELOPMENT_DLNA_SUPPORT_DMPR */

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* _DLNA_DMPr_H */
