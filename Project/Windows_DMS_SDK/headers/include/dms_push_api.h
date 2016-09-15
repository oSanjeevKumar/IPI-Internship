/*
 * dms_push_api.h
 * Copyright (C) 2007-2009 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* DMS +PU+ API.  */

#ifndef NFLC_DMS_PUSH_API_H
#define NFLC_DMS_PUSH_API_H

#include <dlna_api.h>

/**
 * @addtogroup Macros
 */
/*@{*/

/* DMS events.  */
#define DMS_EV_FOUND_DEVS                             DLNA_EV_FOUND_DEVS
#define DMS_EV_BYEBYE                                 DLNA_EV_BYEBYE
#define DMS_EV_UNAVAILABLE                            DLNA_EV_UNAVAILABLE
#define DMS_EV_DEVICE_SUID_CHG                        DLNA_EV_DEVICE_SUID_CHG
#define DMS_EV_DEVICE_CUIDS_CHG                       DLNA_EV_DEVICE_CUIDS_CHG
#define DMS_EV_DEVICE_TIDS_CHG                        DLNA_EV_DEVICE_TIDS_CHG
#define DMS_EV_DEVICE_LAST_CHG                        DLNA_EV_DEVICE_LAST_CHG

#define TDMSEvent                                     TDLNAEvent

/* DMS object event.  */
#define DMS_OBJECT_EV_START                           DLNA_OBJECT_EV_START
#define DMS_OBJECT_EV_BROWSE_END                      DLNA_OBJECT_EV_BROWSE_END
#define DMS_OBJECT_EV_BROWSE_ERROR                    DLNA_OBJECT_EV_BROWSE_ERROR
#define DMS_OBJECT_EV_SEARCH_END                      DLNA_OBJECT_EV_SEARCH_END
#define DMS_OBJECT_EV_SEARCH_ERROR                    DLNA_OBJECT_EV_SEARCH_ERROR
#define DMS_OBJECT_EV_GET_SEARCH_CAPABILITIES_END     DLNA_OBJECT_EV_GET_SEARCH_CAPABILITIES_END
#define DMS_OBJECT_EV_GET_SEARCH_CAPABILITIES_ERROR   DLNA_OBJECT_EV_GET_SEARCH_CAPABILITIES_ERROR
#define DMS_OBJECT_EV_GET_SORT_CAPABILITIES_END       DLNA_OBJECT_EV_GET_SORT_CAPABILITIES_END
#define DMS_OBJECT_EV_GET_SORT_CAPABILITIES_ERROR     DLNA_OBJECT_EV_GET_SORT_CAPABILITIES_ERROR
#define DMS_OBJECT_EV_PLAY_OPEN_OK                    DLNA_OBJECT_EV_PLAY_OPEN_OK
#define DMS_OBJECT_EV_PLAY_OPEN_FAILED                DLNA_OBJECT_EV_PLAY_OPEN_FAILED
#define DMS_OBJECT_EV_PLAY_PLAY_OK                    DLNA_OBJECT_EV_PLAY_PLAY_OK
#define DMS_OBJECT_EV_PLAY_PLAY_FAILED                DLNA_OBJECT_EV_PLAY_PLAY_FAILED
#define DMS_OBJECT_EV_PLAY_STOP_OK                    DLNA_OBJECT_EV_PLAY_STOP_OK
#define DMS_OBJECT_EV_PLAY_STOP_FAILED                DLNA_OBJECT_EV_PLAY_STOP_FAILED
#define DMS_OBJECT_EV_PLAY_PAUSE_OK                   DLNA_OBJECT_EV_PLAY_PAUSE_OK
#define DMS_OBJECT_EV_PLAY_PAUSE_FAILED               DLNA_OBJECT_EV_PLAY_PAUSE_FAILED
#define DMS_OBJECT_EV_PLAY_JUMP_OK                    DLNA_OBJECT_EV_PLAY_JUMP_OK
#define DMS_OBJECT_EV_PLAY_JUMP_FAILED                DLNA_OBJECT_EV_PLAY_JUMP_FAILED
#define DMS_OBJECT_EV_PLAY_UPDATED                    DLNA_OBJECT_EV_PLAY_UPDATED
#define DMS_OBJECT_EV_PLAY_CLOSED                     DLNA_OBJECT_EV_PLAY_CLOSED
#define DMS_OBJECT_EV_PLAY_ERROR                      DLNA_OBJECT_EV_PLAY_ERROR
#define DMS_OBJECT_EV_DL_OPEN                         DLNA_OBJECT_EV_DL_OPEN
#define DMS_OBJECT_EV_DL_UPDATE                       DLNA_OBJECT_EV_DL_UPDATE
#define DMS_OBJECT_EV_DL_CLOSE                        DLNA_OBJECT_EV_DL_CLOSE
#define DMS_OBJECT_EV_DL_ERROR                        DLNA_OBJECT_EV_DL_ERROR
#define DMS_OBJECT_EV_AUTOTEST_FINISHED               DLNA_OBJECT_EV_AUTOTEST_FINISHED

#define TDMSObjectEvent                               TDLNAObjectEvent

/* DMP device type.  */
#define DMS_DEV_TYPE_START                            DLNA_DEV_TYPE_START
#define DMS_DEV_TYPE_UNKNOWN                          DLNA_DEV_TYPE_UNKNOWN
#define DMS_DEV_TYPE_DMS                              DLNA_DEV_TYPE_DMS
#define DMS_DEV_TYPE_M_DMS                            DLNA_DEV_TYPE_M_DMS
#define DMS_DEV_TYPE_DMR                              DLNA_DEV_TYPE_DMR
#define DMS_DEV_TYPE_DMPr                             DLNA_DEV_TYPE_DMPr
#define DMS_DEV_TYPE_DMP                              DLNA_DEV_TYPE_DMP
#define DMS_DEV_TYPE_M_DMP                            DLNA_DEV_TYPE_M_DMP
#define DMS_DEV_TYPE_DMC                              DLNA_DEV_TYPE_DMC
#define DMS_DEV_TYPE_M_DMC                            DLNA_DEV_TYPE_M_DMC


#define TDMSDeviceType TDLNADeviceType

/* DMP API return code.  */
#define DMS_E_OK                                      DLNA_E_OK
#define DMS_E_GENERIC                                 DLNA_E_GENERIC
#define DMS_E_INVAL                                   DLNA_E_INVAL
#define DMS_E_NOMEM                                   DLNA_E_NOMEM
#define DMS_E_DEV                                     DLNA_E_DEV
#define DMS_E_OBJ                                     DLNA_E_OBJ
#define DMS_E_ITEM_EX                                 DLNA_E_ITEM_EX
#define DMS_E_URI                                     DLNA_E_URI
#define DMS_E_COMM                                    DLNA_E_COMM
#define DMS_E_NOFILE                                  DLNA_E_NOFILE
#define DMS_E_FILE_IO                                 DLNA_E_FILE_IO
#define DMS_E_FILE_EX                                 DLNA_E_FILE_EX

#define DMS_API_ERROR DLNA_API_ERROR

/* DMS Jump Mode */
#define DMS_JUMP_MODE_TRACK_NR      DLNA_JUMP_MODE_TRACK_NR
#define DMS_JUMP_MODE_ABS_TIME      DLNA_JUMP_MODE_ABS_TIME
#define DMS_JUMP_MODE_REL_TIME      DLNA_JUMP_MODE_REL_TIME
#define DMS_JUMP_MODE_ABS_COUNT     DLNA_JUMP_MODE_ABS_COUNT
#define DMS_JUMP_MODE_REL_COUNT     DLNA_JUMP_MODE_REL_COUNT
#define DMS_JUMP_MODE_CHANNEL_FREQ  DLNA_JUMP_MODE_CHANNEL_FREQ
#define DMS_JUMP_MODE_TAPE_INDEX    DLNA_JUMP_MODE_TAPE_INDEX

/* DMS API types.  */
#define TDMSObject TDLNAObject
#define TDMSPlayStat TDLNAPlayStat

/* DMS event handler.  */
#define TDMSEventHandler TDLNAEventHandler
#define TDMSObjectEventHandler TDLNAObjectEventHandler

/* dlnaObjectBrowse callback parameter.  */
#define TDMSObjectParam TDLNAObjectParam

#define TDMSObjectJumpParam  TDLNAObjectJumpParam

/*@}*/

/* Prototypes.  */
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* TDMSDevice */

/**
 * @addtogroup Functions
 */
/*@{*/

slim_int
dlnaDmsSetEventHandler (dms_push_t *self, TDLNAEventHandler in_proc, void *in_arg);

TDMSObject 
dlnaDmsGetObject (dms_push_t *self, slim_char *in_full_path);

TDMSObject 
dlnaDmsGetTopContainer(dms_push_t *self);

TDMSObject 
dlnaDmsGetSelfDevice(dms_push_t *self);

slim_int
dlnaDmsDeviceCount (dms_push_t *self);

slim_int
dlnaDmsDeviceList (dms_push_t *self, TDMSObject out_devs[], slim_int in_beg,
                   slim_int in_num);

void
dlnaDmsDeviceSearch (dms_push_t *self);

slim_char *
dlnaDmsDeviceName (TDMSObject self);

TDMSDeviceType
dlnaDmsDeviceType (TDMSObject self);

void
dlnaDmsObjectCancel (TDMSObject self);

void
dlnaDmsObjectClose (TDMSObject self);

/*@}*/

/**
 * @addtogroup Macros
 */
/*@{*/

#define DMS_SORT_CRITERIA_TITLE DLNA_SORT_CRITERIA_TITLE

#define DMS_SORT_CRITERIA_ARTIST DLNA_SORT_CRITERIA_ARTIST

#define DMS_SORT_CRITERIA_DATE DLNA_SORT_CRITERIA_DATE

#define DMS_SORT_CRITERIA_TITLE_ARTIST DLNA_SORT_CRITERIA_TITLE_ARTIST

/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/

slim_int
dlnaDmsObjectBrowse (TDMSObject self, TDMSObjectEventHandler in_obj_eh,
                     void *in_arg, slim_int in_beg, slim_int in_num,
                     slim_char *in_sort_crt);

/*@}*/

/**
 * @addtogroup macros
 */
/*@{*/

#define DMS_SEARCH_CRITERIA_VIDEO  DLNA_SEARCH_CRITERIA_VIDEO

#define DMS_SEARCH_CRITERIA_AUDIO  DLNA_SEARCH_CRITERIA_AUDIO

#define DMS_SEARCH_CRITERIA_IMAGE  DLNA_SEARCH_CRITERIA_IMAGE

#define DMS_SEARCH_FILTER_VIDEO  DLNA_SEARCH_FILTER_VIDEO

#define DMS_SEARCH_FILTER_AUDIO  DLNA_SEARCH_FILTER_AUDIO

#define DMS_SEARCH_FILTER_IMAGE  DLNA_SEARCH_FILTER_IMAGE

/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/

slim_int
dlnaDmsObjectSearch (TDMSObject self, TDMSObjectEventHandler in_obj_eh,
                     void *in_arg, slim_int in_beg, slim_int in_num,
                     slim_char *in_criteria, slim_char *in_filter, slim_char *in_sort_crt);

slim_int
dlnaDmsDeviceIsSearchCapable (TDMSObject self, TDMSObjectEventHandler in_obj_eh, void *in_arg);

slim_int
dlnaDmsDeviceIsSortCapable (TDMSObject self, TDMSObjectEventHandler in_obj_eh, void *in_arg);

#ifdef DLNA_SUPPORT_DOWNLOADER
TDMSObject
dlnaDmsObjectDownload (TDMSObject self, TDMSObjectEventHandler in_obj_eh,
                       void *in_arg);
#endif

TDMSObject
dlnaDmsObjectUploadFile (slim_char *in_full_path, TDMSObjectEventHandler in_obj_eh,
                         void *in_arg, TDMSObject in_dms);

slim_int
dlnaDmsThumbnailOpen (TDMSObject self, TDMSObjectEventHandler in_obj_eh,
                      void *in_arg);

slim_bool
dlnaDmsObjectIsPlayable (TDMSObject self, TDMSObject in_dmr);

TDMSObject
dlnaDmsPlayOpen (TDMSObject self, TDMSObjectEventHandler in_obj_eh,
                 void *in_arg, TDMSObject in_dmr);

slim_int
dlnaDmsPlayPlay (TDMSObject self, slim_char *in_speed);

slim_int
dlnaDmsPlayPause (TDMSObject self);

slim_int
dlnaDmsPlayJump (TDMSObject self, TDMSObjectJumpParam *in_jump);

slim_int
dlnaDmsPlayStop (TDMSObject self);

slim_int
dlnaDmsPlayGetStat (TDMSObject self, TDMSPlayStat out_stat);

slim_bool
dlnaDmsObjectTypeIsDevice (TDMSObject self);

slim_bool
dlnaDmsObjectTypeIsContainer (TDMSObject self);

slim_bool
dlnaDmsObjectTypeIsItem (TDMSObject self);

slim_bool
dlnaDmsObjectTypeIsStorageFolder (TDMSObject self);

slim_bool
dlnaDmsObjectTypeIsAlbum (TDMSObject self);

slim_bool
dlnaDmsObjectTypeIsMusicAlbum (TDMSObject self);

slim_bool
dlnaDmsObjectTypeIsPhotoAlbum (TDMSObject self);

slim_bool
dlnaDmsObjectTypeIsPlaylistContainer (TDMSObject self);

slim_bool
dlnaDmsObjectTypeIsImageItem (TDMSObject self);

slim_bool
dlnaDmsObjectTypeIsPhoto (TDMSObject self);

slim_bool
dlnaDmsObjectTypeIsAudioItem (TDMSObject self);

slim_bool
dlnaDmsObjectTypeIsMusicTrack (TDMSObject self);

slim_bool
dlnaDmsObjectTypeIsVideoItem (TDMSObject self);

slim_bool
dlnaDmsObjectTypeIsMovie (TDMSObject self);

slim_bool
dlnaDmsObjectTypeIsMusicVideoClip (TDMSObject self);

slim_bool
dlnaDmsObjectTypeIsPlayListItem (TDMSObject self);

slim_char *
dlnaDmsObjectPropId (TDMSObject self);

slim_char *
dlnaDmsObjectPropPath (TDMSObject self);

slim_char *
dlnaDmsObjectPropTitle (TDMSObject self);

slim_char *
dlnaDmsObjectPropCreator (TDMSObject self);

slim_char *
dlnaDmsObjectPropWriteStatus (TDMSObject self);

slim_char *
dlnaDmsObjectPropResURI (TDMSObject self);

slim_int
dlnaDmsObjectPropNthResURI (TDMSObject self, slim_int in_index, slim_char **out_NthResURI);

slim_char *
dlnaDmsObjectPropResSize (TDMSObject self);

slim_char *
dlnaDmsObjectPropResDuration (TDMSObject self);

slim_char *
dlnaDmsObjectPropResResolution (TDMSObject self);

slim_char *
dlnaDmsObjectPropLongDescription (TDMSObject self);

slim_char *
dlnaDmsObjectPropDescription (TDMSObject self);

slim_char *
dlnaDmsObjectPropPublisher (TDMSObject self);

slim_char *
dlnaDmsObjectPropContributor (TDMSObject self);

slim_char *
dlnaDmsObjectPropDate (TDMSObject self);

slim_char *
dlnaDmsObjectPropCopyrights (TDMSObject self);

slim_char *
dlnaDmsObjectPropArtist (TDMSObject self);

slim_char *
dlnaDmsObjectPropAlbum (TDMSObject self);

slim_char *
dlnaDmsObjectPropGenre (TDMSObject self);

slim_char *
dlnaDmsObjectPropProducer (TDMSObject self);

slim_char *
dlnaDmsObjectPropAlbumArtURI (TDMSObject self);

slim_char *
dlnaDmsObjectPropLanguage (TDMSObject self);

slim_char *
dlnaDmsObjectPropActor (TDMSObject self);

TDMSObject
dlnaDmsObjectGetDevice (TDMSObject self);

TDMSObject
dlnaDmsPlayTransportOpen (dms_push_t *self, TDMSObjectEventHandler in_obj_eh,
                 void *in_arg, TDMSObject in_dmr);

slim_int
dlnaDmsPlayGetTransportInfo (TDMSObject self);

slim_int
dlnaDmsPlayGetMediaInfo (TDMSObject self);

slim_int
dlnaDmsPlaySetTransportUri (TDMSObject self, TDMSObject item, slim_int in_res_index);

slim_int
dlnaDmsPlayQueryValue (TDMSObject self, slim_char *in_var_name);

/*@}*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_DMS_PUSH_API_H */
