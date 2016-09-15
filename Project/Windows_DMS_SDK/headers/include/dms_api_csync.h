/*
 * dms_api_csync.h
 * Copyright (C) 2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_DMS_API_CSYNC_H
#define NFLC_DMS_API_CSYNC_H

/* This file should be included, only if you want use CSYNC feature in DMS */

/* Include basic structures for DMS */
#include <dms_api.h>

/* if you don't want CSYNC client in DMS, please don't use this file. I will have same
   effect as #include <dms_api.h> */

#ifdef DLNA_SUPPORT_DMSCP

/**
 * @addtogroup Macros
 */
/*@{*/

#define DMSCLIENT_SORT_CRITERIA_TITLE               "+dc:title"

/* DMS CSYNC Client API return code.  */

#define DMSCLIENT_E_OK                              DLNA_E_OK
#define DMSCLIENT_E_GENERIC                         DLNA_E_GENERIC
#define DMSCLIENT_E_INVAL                           DLNA_E_INVAL
#define DMSCLIENT_E_NOMEM                           DLNA_E_NOMEM

#define DMSCLIENT_CSYNC_OBJ_CHANGE_TYPE_NOT_EXIST   DLNA_CSYNC_OBJ_CHANGE_TYPE_NOT_EXIST
#define DMSCLIENT_CSYNC_OBJ_CHANGE_TYPE_UNCHANGED   DLNA_CSYNC_OBJ_CHANGE_TYPE_UNCHANGED
#define DMSCLIENT_CSYNC_OBJ_CHANGE_TYPE_ADD         DLNA_CSYNC_OBJ_CHANGE_TYPE_ADD
#define DMSCLIENT_CSYNC_OBJ_CHANGE_TYPE_MOD         DLNA_CSYNC_OBJ_CHANGE_TYPE_MOD
#define DMSCLIENT_CSYNC_OBJ_CHANGE_TYPE_DEL         DLNA_CSYNC_OBJ_CHANGE_TYPE_DEL

#define DMSCLIENT_OBJECT_EV_BROWSE_END              DLNA_OBJECT_EV_BROWSE_END
#define DMSCLIENT_OBJECT_EV_BROWSE_ERROR            DLNA_OBJECT_EV_BROWSE_ERROR

/* DMS CSYNC Client devices types. */

#define DMSCLIENT_DEV_TYPE_START                    DLNA_DEV_TYPE_START
#define DMSCLIENT_DEV_TYPE_UNKNOWN                  DLNA_DEV_TYPE_UNKNOWN
#define DMSCLIENT_DEV_TYPE_DMS                      DLNA_DEV_TYPE_DMS
#define DMSCLIENT_DEV_TYPE_M_DMS                    DLNA_DEV_TYPE_M_DMS
#define DMSCLIENT_DEV_TYPE_DMR                      DLNA_DEV_TYPE_DMR
#define DMSCLIENT_DEV_TYPE_DMPr                     DLNA_DEV_TYPE_DMPr
#define DMSCLIENT_DEV_TYPE_DMP                      DLNA_DEV_TYPE_DMP
#define DMSCLIENT_DEV_TYPE_M_DMP                    DLNA_DEV_TYPE_M_DMP
#define DMSCLIENT_DEV_TYPE_DMC                      DLNA_DEV_TYPE_DMC
#define DMSCLIENT_DEV_TYPE_M_DMC                    DLNA_DEV_TYPE_M_DMC

#define DMSCLIENT_OBJECT_TYPE_DEVICE                (1)
#define DMSCLIENT_OBJECT_TYPE_CONTAINER             (2)
#define DMSCLIENT_OBJECT_TYPE_ITEM                  (3)
#define DMSCLIENT_OBJECT_TYPE_TRANSPORT             (4)


#define DMSCLIENT_CSYNC_EVENT_TASK_READY            DLNA_CSYNC_EVENT_TASK_READY
#define DMSCLIENT_CSYNC_EVENT_SERVER_UNAVAILABLE    DLNA_CSYNC_EVENT_SERVER_UNAVAILABLE
#define DMSCLIENT_CSYNC_EVENT_SERVER_AVAILABLE      DLNA_CSYNC_EVENT_SERVER_AVAILABLE
#define DMSCLIENT_CSYNC_EVENT_SYNCED                DLNA_CSYNC_EVENT_SYNCED
#define DMSCLIENT_CSYNC_EVENT_CANCELLED             DLNA_CSYNC_EVENT_CANCELLED
#define DMSCLIENT_CSYNC_EVENT_PROGRESS              DLNA_CSYNC_EVENT_PROGRESS
#define DMSCLIENT_CSYNC_EVENT_CHANGED               DLNA_CSYNC_EVENT_CHANGED
#define DMSCLIENT_CSYNC_EVENT_ERROR                 DLNA_CSYNC_EVENT_ERROR
#define DMSCLIENT_CSYNC_EVENT_TRANSPORT_ERROR       DLNA_CSYNC_EVENT_TRANSPORT_ERROR

/*@}*/

/* DMS CSYNC Client API object */

/**
 * @addtogroup DataTypes
 */
/*@{*/

typedef void* TDMSClientObject;

/*@}*/

/**
 * @addtogroup Macros
 */
/*@{*/

#define TDMSClientObjectEvent                       TDLNAObjectEvent
#define TDMSClientObjectParam                       TDLNAObjectParam
#define TDMSClientObjectEventHandler                TDLNAObjectEventHandler
#define TDMSClientDeviceType                        TDLNADeviceType

#define TDMSClientCSyncTask                         TDLNACSyncTask
#define TDMSClientCSyncTaskStat                     TDLNACSyncTaskStat
#define TDMSClientCSyncAction                       TDLNACSyncAction
#define TDMSClientCSyncParam                        TDLNACSyncParam

#define TDMSClientCSyncObj                          TDLNACSyncObj
#define TDMSClientCSyncObjProp                      TDLNACSyncObjProp
#define TDMSClientCSyncObjState                     TDLNACSyncObjState
#define TDMSClientCSyncChangeType                   TDLNACSyncChangeType
#define TDMSClientCSyncError                        TDLNACSyncError

#define TDMSClientCSyncEventHandler                 TDLNACSyncEventHandler
#define TDMSClientCSyncDirection                    TDLNACSyncDirection
#define TDMSClientCSyncMode                         TDLNACSyncMode
#define TDMSClientCSyncConflictPolicy               TDLNACSyncConflictPolicy
#define TDMSClientCSyncEvent                        TDLNACSyncEvent

/*@}*/


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* DMS CSYNC Client operation on TDMSClientObject */

/**
 * @addtogroup Functions
 */
/*@{*/

DLNA_API slim_int
dlnaDmsClientObjectBrowse (TDMSClientObject self, TDMSClientObjectEventHandler in_obj_eh,
                           void *in_arg, slim_int in_beg, slim_int in_num,
                           slim_char *in_sort_crt);

DLNA_API slim_int
dlnaDmsClientObjectBrowseById (TDMSClientObject self, slim_char *in_id, TDMSClientObjectEventHandler in_obj_eh,
                               void *in_arg, slim_int in_beg, slim_int in_num, slim_char *in_sort_crt);
                           
DLNA_API slim_int
dlnaDmsClientObjectBrowseMetadata (TDMSClientObject self, slim_char *in_id, TDMSClientObjectEventHandler in_obj_eh,
                     void *in_arg, TDMSClientObject* out_obj);
                               
DLNA_API void
dlnaDmsClientObjectClose (TDMSClientObject self);

DLNA_API slim_bool
dlnaDmsClientObjectTypeIsDevice (TDMSClientObject self);

DLNA_API slim_bool
dlnaDmsClientObjectTypeIsContainer (TDMSClientObject self);

slim_bool
dlnaDmsClientDeviceIsLocal (TDMSClientObject self);

DLNA_API slim_char *
dlnaDmsClientObjectPropGet (TDMSClientObject self, slim_char* in_prop);

DLNA_API slim_bool
dlnaDmsClientObjectTypeGet (TDMSClientObject self, slim_char *in_type);

DLNA_API slim_bool
dlnaDmsClientObjectTypeIsItem (TDMSClientObject self);

DLNA_API slim_char*
dlnaDmsClientObjectGetUpnpClass(TDMSClientObject self);

#define dlnaDmsClientObjectTypeIsStorageFolder(self)    dlnaDmsClientObjectTypeGet (self, SLIM_T("storageFolder"))
#define dlnaDmsClientObjectPropTitle(self)              dlnaDmsClientObjectPropGet (self, SLIM_T("dc:title"))

DLNA_API slim_char*
dlnaDmsClientObjectGetId(TDMSClientObject self);

DLNA_API slim_char*
dlnaDmsClientObjectGetParentId(TDMSClientObject self);

DLNA_API slim_char*
dlnaDmsClientObjectGetChildCount(TDMSClientObject self);

DLNA_API TDMSClientDeviceType
dlnaDmsClientDeviceType (TDMSClientObject self);

slim_char*
dlnaDmsClientObjectGetRestricted (TDMSClientObject self);

/* DMS CSYNC Client operations on devices */

slim_int
dlnaDmsClientStartDiscoverDms(TDMS self, TDLNAEventHandler in_dms_client_eh, void *in_arg);

slim_int
dlnaDmsClientDeviceCount (TDMS self);

slim_int
dlnaDmsClientDeviceList (TDMS self, TDLNAObject out_devs[], slim_int in_beg, slim_int in_num);


slim_int
dlnaDmsClientStartDiscoverDms(TDMS self, TDLNAEventHandler in_dms_client_eh, void *in_arg);

slim_int
dlnaDmsClientDeviceCount (TDMS self);

slim_int
dlnaDmsClientDeviceList (TDMS self, TDLNAObject out_devs[], slim_int in_beg, slim_int in_num);

/*@}*/

/**
 * @addtogroup Macros
 */
/*@{*/

#define dlnaDmsClientDeviceName(self)               dlnaDmsClientObjectPropGet (self, SLIM_T("friendlyName"))
#define dlnaDmsClientDeviceUDN(self)                dlnaDmsClientObjectPropGet (self, SLIM_T("UDN"))

/*@}*/


/* DMS CSYNC Client CSYNC opertaions and  CSYNC tasks operations */ 

/**
 * @addtogroup apis
 */
/*@{*/

DLNA_API slim_int
dlnaDmsClientSyncStart (TDMS self, slim_char *in_home_path, TDMSClientCSyncEventHandler in_eh, 
                            void *in_arg);

DLNA_API void
dlnaDmsClientSyncStop (TDMS self);

DLNA_API TDMSClientCSyncTask
dlnaDmsClientSyncTaskCreate (TDMS self, slim_char *in_title, TDMSClientObject in_local_obj, 
            TDMSClientObject in_remote_obj, TDMSClientCSyncDirection in_direction,
            TDMSClientCSyncMode in_mode, TDMSClientCSyncConflictPolicy in_policy);

DLNA_API slim_int
dlnaDmsClientSyncTaskDelete (TDMS self, TDMSClientCSyncTask in_task);

DLNA_API void
dlnaDmsClientSyncObjClose(TDMSClientCSyncObj self);

DLNA_API slim_bool
dlnaDmsClientSyncObjIsContainer (TDMSClientCSyncObj self);

DLNA_API slim_int
dlnaDmsClientSyncObjGetAction (TDMSClientCSyncObj self, TDMSClientCSyncAction *out_action);

DLNA_API slim_char *
dlnaDmsClientSyncTaskGetTitle(TDMSClientCSyncTask self);

DLNA_API slim_int
dlnaDmsClientSyncTaskSyncStart (TDMSClientCSyncTask self);

DLNA_API slim_int
dlnaDmsClientSyncObjPropTitle (TDMSClientCSyncObj self, slim_char **out_server_side_title, 
            slim_char **out_local_side_title);

DLNA_API slim_int
dlnaDmsClientSyncObjGetChangeType (TDMSClientCSyncObj self, TDMSClientCSyncChangeType *out_server_side_change, TDMSClientCSyncChangeType *out_local_side_change);

DLNA_API TDLNACSyncTask
dlnaDmsClientSyncGetFirstSyncTask (TDMS self);

DLNA_API TDMSClientCSyncTask
dlnaDmsClientSyncGetNextSyncTask (TDMS self, TDMSClientCSyncTask in_task);

DLNA_API slim_int
dlnaDmsClientSyncGetSyncTasksNumber (TDMS self);

DLNA_API slim_int
dlnaDmsClientSyncTaskStat (TDLNACSyncTask self, TDLNACSyncTaskStat *out_stat);

DLNA_API slim_int
dlnaDmsClientSyncTaskGetMode (TDLNACSyncTask self, TDLNACSyncMode *out_mode);

DLNA_API slim_int
dlnaDmsClientSyncTaskGetDirection (TDLNACSyncTask self, TDLNACSyncDirection *out_direction);

DLNA_API slim_int
dlnaDmsClientSyncTaskGetConflictPolicy (TDLNACSyncTask self, TDLNACSyncConflictPolicy *out_policy);

/*@}*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* DLNA_SUPPORT_DMSCP */

#endif /* NFLC_DMS_API_CSYNC_H */
