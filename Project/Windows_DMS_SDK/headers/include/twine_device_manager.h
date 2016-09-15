/*
 * twine_device_manager.h
 * Copyright (C) 2015 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */

/* DMS device manager.  */

#ifndef TWINE_DEVICE_MANAGER_H
#define TWINE_DEVICE_MANAGER_H

	
typedef void *HDEVMAN ;

enum TWINE_DEVICE_CONSTRAINTS_MASK {
	DENY = 0,					// invisible
	ALLOW = 1,				// full access
	RESTRICT = 2			// trailer only
};

struct dms_dcl{
	slim_char *mac ;
	slim_char *id ;
	slim_int	mask ;
	slim_int	parental_level ;
}; 

struct dms_dcl_list{
	slim_int	count;
	struct dms_dcl	dcl[100] ;
} ;


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define DEVMAN_PROP_GID             SLIM_T("GID")
#define DEVMAN_PROP_DOMID           SLIM_T("DOMID")
#define DEVMAN_PROP_UPDID           SLIM_T("UID")
#define DEVMAN_PROP_CUE             SLIM_T("CUE")
#define DEVMAN_PROP_STUN            SLIM_T("STUN")
#define DEVMAN_PROP_TURN            SLIM_T("TURN")
#define DEVMAN_PROP_PORTAL          SLIM_T("PORTAL")
#define DEVMAN_PROP_SESSION_LIMIT   SLIM_T("SL")
#define DEVMAN_PROP_RA              SLIM_T("RA")
#define DEVMAN_PROP_UPDATE_INTERVAL SLIM_T("UI")
#define DEVMAN_PROP_SESSION_TOKEN   SLIM_T("ST")
#define DEVMAN_PROP_NAME            SLIM_T("NAME")
#define DEVMAN_PROP_LOGFILTER       SLIM_T("LF")
#define DEVMAN_PROP_ACTIVE          SLIM_T("ACT")
#define DEVMAN_PROP_REPORT_INTERVAL SLIM_T("RI")
#define DEVMAN_PROP_REQUEST_TIMEOUT SLIM_T("RT")
#define DEVMAN_PROP_STARTUP_DELAY   SLIM_T("STUD")
#define DEVMAN_PROP_AUTH_TOKEN      SLIM_T("ATOK")
#define DEVMAN_PROP_RID             SLIM_T("RID")
#define DEVMAN_PROP_AUTH_TOKEN_TYPE SLIM_T("ATOKT")

#define DEVMAN_PROP_TRCSURL         SLIM_T("TRCSURL")
#define DEVMAN_PROP_TLSURL          SLIM_T("TLSURL")
#define DEVMAN_PROP_TGSURL          SLIM_T("TGSURL")
#define DEVMAN_PROP_TCGSURL         SLIM_T("TCGSURL")
#define DEVMAN_PROP_TCUSURL         SLIM_T("TCUSURL")

#define DEVMAN_PROP_TARGETS         SLIM_T("TARGETS")
#define DEVMAN_PROP_PROPERTIES      SLIM_T("PROPERTIES") 

#define DEVMAN_PROP_CA              SLIM_T("CA")
#define DEVMAN_PROP_UL              SLIM_T("UL")
#define DEVMAN_PROP_DL              SLIM_T("DL")
#define DEVMAN_PROP_MS              SLIM_T("MS")

#define DEVMAN_PROP_TP_DEVICES      SLIM_T("TPD")
#define DEVMAN_PROP_TP_APPS         SLIM_T("TPA")
#define DEVMAN_PROP_MAX_USER        SLIM_T("MU")
#define DEVMAN_PROP_MAX_DEVICES     SLIM_T("MD")
#define DEVMAN_PROP_DEVICE_TYPE     SLIM_T("DT")
#define DEVMAN_PROP_DEVICE_UA       SLIM_T("UA")
#define DEVMAN_PROP_DEVICE_MAC      SLIM_T("MAC")
#define DEVMAN_PROP_DEVICE_UUID     SLIM_T("UUID")
#define DEVMAN_PROP_FRIENDS         SLIM_T("FRIENDS")

HDEVMAN
device_manager_alloc( void *top, slim_char *db_path) ;
void
device_manager_free(HDEVMAN ctx) ;
slim_int
device_manager_set_key(HDEVMAN ctx, slim_char *in_key, slim_char *in_iv) ;
slim_char*
device_manager_compute_id(slim_char *mac) ;
slim_int
device_manager_device_list_get(HDEVMAN ctx,  struct dms_dcl_list *dcl) ;
slim_int
device_manager_device_list_delete(HDEVMAN ctx) ;
slim_int
device_manager_device_get(HDEVMAN ctx, slim_char *mac, struct dms_dcl *dcl) ;
slim_int
device_manager_device_set(HDEVMAN ctx, slim_char *mac, struct dms_dcl *dcl) ;
slim_int
device_manager_device_get_byid(HDEVMAN ctx, slim_char *id, struct dms_dcl *dcl) ;
slim_int
device_manager_device_add(HDEVMAN ctx, slim_char *mac) ;
slim_int
device_manager_device_delete(HDEVMAN ctx, slim_char *mac) ;
slim_int
device_manager_delete_records (HDEVMAN ctx);

slim_int
device_manager_device_mask_get(HDEVMAN ctx, slim_char *mac) ;
slim_int
device_manager_device_parental_level_get(HDEVMAN ctx, slim_char *mac) ;
slim_char*
device_manager_device_mac_get(HDEVMAN ctx, slim_char *did) ;



HDEVMAN	device_manager_instance_get() ;
slim_char*
device_manager_property_get( HDEVMAN ctx, slim_char *key);
slim_int
device_manager_property_get_num( HDEVMAN ctx, slim_char *key);
slim_int
device_manager_property_set( HDEVMAN ctx, slim_char *key, slim_char *value );
slim_int
device_manager_property_set_num( HDEVMAN ctx, slim_char *key, slim_int value );


#ifdef __cplusplus
}
#endif /* __cplusplus */




#endif /* TWINE_DEVICE_MANAGER_H */
