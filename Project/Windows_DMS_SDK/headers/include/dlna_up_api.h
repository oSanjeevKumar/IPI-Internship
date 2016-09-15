/*
 * dlna_up_api.h
 * Copyright (C) 2008 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2008 ACCESS CO., LTD. All Rights Reserved.  */

/* UPLOAD API. */

#ifndef NFLC_DLNA_UP_API_H
#define NFLC_DLNA_UP_API_H

#include <dlna_peer.h>
#include <dlna_api.h>
#include <dmp_api.h>

#ifdef _DOXYGEN
#undef DLNA_API
#define DLNA_API
#endif

/**
 * @addtogroup macros
 */
/*@{*/

/* upload object event type */
#define UP_OBJECT_EV_UPLOAD_FILE          DLNA_OBJECT_EV_UPLOAD_FILE
#define UP_OBJECT_EV_UPLOAD_STREAM        DLNA_OBJECT_EV_UPLOAD_STREAM
#define UP_OBJECT_EV_CREATE_FOLDER        DLNA_OBJECT_EV_CREATE_FOLDER
#define UP_OBJECT_EV_DELETE_OBJECT        DLNA_OBJECT_EV_DELETE_OBJECT
#define UP_OBJECT_EV_UPDATE_OBJECT        DLNA_OBJECT_EV_UPDATE_OBJECT

/* upload object sub-event type */
#define	UP_OBJECT_EV_SUB_UPLOAD_CREATE    SUB_EVENT_CREATE_OBJECT_SUCCESS
/*!
Upload started.
*/
#define UP_OBJECT_EV_SUB_UPLOAD_BEGIN     SUB_EVENT_UPLOAD_BEGIN
/*!
Upload is completed.
*/
#define UP_OBJECT_EV_SUB_UPLOAD_END       SUB_EVENT_UPLOAD_END
/*!
Canceled while uploading.
*/
#define UP_OBJECT_EV_SUB_UPLOAD_CANCELED  SUB_EVENT_UPLOAD_CANCELED
/*!
Notify progress while uploading.
*/
#define UP_OBJECT_EV_SUB_UPLOAD_PROGRESS  SUB_EVENT_UPLOAD_PROGRESS
/*!
Error occurred while uploading
*/
#define UP_OBJECT_EV_SUB_UPLOAD_ERROR     SUB_EVENT_ERROR

/* upload API return code.  */
/*!
Succeeded (=0).
*/
#define UP_E_OK                           DLNA_E_UP_OK
/*!
Generic error occurred.
*/
#define UP_E_GENERIC                      DLNA_E_UP_GENERIC
#define UP_E_INVAL                        DLNA_E_UP_INVAL
/*!
No such object.
*/
#define UP_E_NO_SUCH_OBJ                  DLNA_E_UP_NO_SUCH_OBJ
/*!
Restricted object.
*/
#define UP_E_RESTRICTED_OBJ               DLNA_E_UP_RESTRICTED_OBJ
/*!
Restricted parent object.
*/
#define UP_E_RESTRICTED_PARENT_OBJ        DLNA_E_UP_RESTRICTED_PARENT_OBJ
/*!
No such resource.
*/
#define UP_E_NO_SUCH_RESOURCE             DLNA_E_UP_NO_SUCH_RESOURCE
/*!
Resource access denied.
*/
#define UP_E_RESOURCE_ACCESS_DENIED       DLNA_E_UP_RESOURCE_ACCESS_DENIED
/*!
No such container.
*/
#define UP_E_NO_SUCH_CONTAINER            DLNA_E_UP_NO_SUCH_CONTAINER
/*!
Bad meta data.
*/
#define UP_E_BAD_METADATA                 DLNA_E_UP_BAD_METADATA
/*!
HTTP timeout.
*/
#define UP_E_HTTP_TIMEOUT                 DLNA_E_UP_HTTP_TIMEOUT
/*!
HTTP error.
*/
#define UP_E_HTTP_ERROR                   DLNA_E_UP_HTTP_ERROR

/* upload capabilities */
#define UP_NOTHING_CAPABLE         (0x00000000)
/*!
Device supports audio upload.
*/
#define UP_AUDIO_CAPABLE           (0x00000001)
/*!
Device supports image upload.
*/
#define UP_IMAGE_CAPABLE           (0x00000002)
/*!
Device supports AV upload.
*/
#define UP_AV_CAPABLE              (0x00000004)
/*!
Device supports creating child container.
*/
#define UP_CHILD_CONTAINER_CAPABLE (0x00000008)

/*!
Device supports document upload.
*/
#define UP_DOC_CAPABLE              (0x00000010)

/*@}*/

/**
 * @addtogroup structures
 */
/*@{*/

struct _TDLNAUpEventHandleParam
{
  slim_int event_type;
  slim_int sub_event;
  slim_int err_code;
  void *info;
  slim_int info_len;
  slim_char *percent; 
  slim_char *current_bytes;
  slim_char *total_bytes;
};

typedef struct _TDLNAUpEventHandleParam TDLNAUpEventHandleParam;


struct up_stream_param_ {
  slim_char *title;
  slim_char *pinfo;
  slim_char *containerID;
  slim_char *full_path; /* TODO */

  slim_int upnp_channelNr;
  slim_char *upnp_class;
  slim_char *upnp_createClass;
  slim_char *upnp_channelName;
  slim_char *upnp_rating;
  slim_char *upnp_radioBand;
  slim_char **upnp_genre; /* array which is ended by null */
  slim_char *upnp_scheduledStartTime;
  slim_char *upnp_scheduledEndTime;
  slim_char *upnp_res_duration;
  slim_char *dc_date;
  slim_char *dc_description;  

#if defined (HAVE_DTCP) 
  slim_int drm_cci;
#endif /* defined (HAVE_DTCP) */
#if defined (DLNA_SUPPORT_UPLOAD_DTCP_MV)
  slim_word uploadInfo;
#endif
  slim_char *xsrs_reservationID;

  slim_char *arib_object_type;
  slim_char *arib_long_description;
  slim_char *arib_copy_control_info;
};
typedef struct up_stream_param_ up_stream_param_t;

struct upnp_upload_param_
{
  slim_char *full_path;
  slim_char *url;

  dlna_uint64 size;
  slim_char *title;
  slim_char *upnp_class;
  slim_char *date;
  slim_char *pinfo;
  slim_char *pinfo2;
  slim_char *import_uri;
  slim_char *parent_id;
  slim_int create_type;
  slim_word dlna_managed;
		
	slim_char *upnp_album;
	slim_char *dc_creator;
	slim_char *author;
	slim_char *genre;
	slim_word width;
	slim_word height;
	dlna_time_t time;

  void     *dms_device;

  slim_char *upnp_channelName;
  slim_int upnp_channelNr;
  slim_char *upnp_rating;
  slim_char *upnp_radioBand;
  slim_char **upnp_genre;
  slim_char *upnp_scheduledStartTime;
  slim_char *upnp_scheduledEndTime;
  slim_char *upnp_res_duration;

  slim_char *dc_date;
  slim_char *dc_description;  

  slim_char *arib_object_type;
  slim_char *arib_long_description;
  slim_char *arib_copy_control_info;

#if defined (HAVE_DTCP)
  slim_int drm_cci;
#endif /* defined (HAVE_DTCP) */
#if defined (DLNA_SUPPORT_UPLOADER_DTCP_MV)
  slim_word uploadInfo;
#endif
  slim_char *xsrs_reservationID;
  void     *object_eh;
  void *arg;
};
typedef struct upnp_upload_param_ upnp_upload_param_t;

/*@}*/


/* Prototypes.  */
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @addtogroup apis
 */
/*@{*/

/*!
\par Function:
Starts uploading content file to device.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Device information of device to which content file is uploaded</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_full_path</td>
		<td>Name of file to upload (including absolute path and extension)</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_obj_eh</td>
		<td>Pointer to callback function that notifies of API processing result</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument of in_obj_eh</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_notify_kbsize</td>
		<td>Callback call timing specified by transfer size (KB)</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_container_obj</td>
		<td>Container information of upload target</td>
	</tr>
    <tr>
        <td>[out]</td>
        <td>out_upload_obj</td>
        <td>Upload control information</td>
    </tr>
</table> 

\return slim_int DLNA_E_OK value if success
\return all other returns are fail

\par Description:
This function uploads a content file to the device specified for self. It returns the upload control
information once the upload is successfully started.

The file to upload is specified for in_full_path as an absolute path.

The container information of the upload destination is specified for in_container_obj. If null is specified
to in_container_obj, the file is stored in any given folder.

The pointer to the callback function must be specified for in_obj_eh. The progress of upload is notified
asynchronously by in_obj_eh.

The +UP+ library calls in_obj_eh every time content of the transfer size specified for in_notify_kbsize is
transmitted, and notifies the +UP+ application of the uploading progress. At that time,
UP_OBJECT_EV_UPLOAD_FILE and UP_OBJECT_EV_SUB_UPLOAD_PROGRESS is set for event type
and sub-event type respectively.

An UP_OBJECT_EV_UPLOAD_FILE event notification is given by in_obj_eh once the upload is
completed. At that time, UP_OBJECT_EV_SUB_UPLOAD_END is set for the sub-event type.

After the upload is completed, the upload control information must be discarded using the API for
destroying objects retained by the associated device class.
\note
The item information to be specified for self of this function should be obtained by the use of an API of
the associated device class (if the associated device class is DMP, use dlnaDmpObjectBrowse()).

And after the upload is completed, the item information specified for self must be discarded using the
API for destroying objects retained by the device class (if the associated device class is DMP, use
dlnaDmpObjectClose()).

For more information about APIs and their usage, see the API specification of each device class.
*/
/* Add argument 'container_id' */
DLNA_API slim_int
dlnaUPUploadFile (TDMPObject self, slim_char *in_full_path, 
                  TDMPObjectEventHandler in_obj_eh, void *in_arg, 
                  slim_int in_notify_kbsize,
                  TDMPObject in_container_obj,
                  TDMPObject *out_upload_obj);

/*!
\par Function:
Creates folder on device.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Device information of device where folder is created</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_folder_name</td>
		<td>Name of folder to create</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_obj_eh</td>
		<td>Pointer to callback function that notifies of API processing result</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument of in_obj_eh</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_container_id</td>
		<td>Parent folder ID of folder to create</td>
	</tr>
</table>

\return != slim_nil Upload control information
\return == slim_nil Failed
\par Description:
This function creates a folder on the device specified for self. It returns the upload control information
when creation of the folder is started successfully. A sub-folder can be created by specifying
in_container_id. If null is specified to in_container_id, the folder is created in any given folder.

The pointer to the callback function must be specified for in_obj_eh. The file creation progress is
notified asynchronously by in_obj_eh.

UP_OBJECT_EV_CREATE_FOLDER event notification is given by in_obj_eh once creation of the folder
is completed. At that time, DLNA_E_UP_OK is set for the sub-event type.

After the folder is created, the upload control information must be discarded using the API for
destroying objects retained by the associated device class.

\note
The item information to be specified for self in this function should be obtained using an API of the
associated device class (if the associated device class is DMP, use dlnaDmpObjectBrowse()).

And, after the folder is created, the item information specified for self must be discarded using the API
for destroying objects retained by the device class (if the associated device class is DMP, use
dlnaDmpObjectClose()).

For more information about APIs and their usage, see the API specification of each device class.
*/
DLNA_API TDMPObject
dlnaUPCreateFolder(TDMPObject self, slim_char *in_folder_name,
			    TDMPObjectEventHandler in_obj_eh, void *in_arg, slim_char *in_container_id);

/*!
\par Function:
Deletes file/folder from device.
\par Parameters: 

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Device information of device from which file/folder is deleted</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_obj_eh</td>
		<td>Pointer to callback function that notifies of API processing result</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument of in_obj_eh</td>
	</tr>
</table>

\return != slim_nil Upload control information
\return == slim_nil Failed
\par Description:
This function deletes a file or folder from the device specified for self. It returns the upload control
information when file/folder deletion is started successfully.

The pointer to the callback function must be specified for in_obj_eh. The progress of file/folder deletion
is notified asynchronously by in_obj_eh.

An UP_OBJECT_EV_DELETE_OBJECT event notification is given once deletion of the file/folder is
completed. At that time, DLNA_E_UP_OK is set for the sub-event type.

After the file/folder is deleted, the upload control information must be discarded using the API for
destroying objects retained by the associated device class.
\note 
The item information to be specified for self in this function should be obtained using an API of the
associated device class (if the associated device class is DMP, use dlnaDmpObjectBrowse()).

And, after file/folder deletion, the item information specified for self must be discarded using the API for
destroying objects retained by the device class (if the associated device class is DMP, use
dlnaDmpObjectClose()).

For more information about APIs and their usage, see the API specification of each device class.
*/
DLNA_API TDMPObject
dlnaUPDestroyObject (TDMPObject self, TDMPObjectEventHandler in_obj_eh, void *in_arg);

/*!
\par Function:
Function gets the upload profiles
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA DMS device object.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_obj_eh</td>
		<td>Callback function that notifies of internally generated event.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Callback argument</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_param</td>
		<td></td>
	</tr>
</table>
\return slim_int DLNA_E_OK value if success
\return all other returns are fail
*/

DLNA_API slim_int
dlnaGetUploadProfiles (TDMPObject self, TDMPObjectEventHandler in_obj_eh, 
                       void *in_arg, slim_char *in_param);

/*!
\par Function:
Checks whether device supports upload function.
\par Parameters: 

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Device information of device to check whether it supports upload function</td>
	</tr>
</table>

\return 0 Not supported
\return Other Supports upload function.<br/>Logical OR of the following flags is returned<br /> UP_AUDIO_CAPABLE "audio" upload is supported<br/>
		UP_IMAGE_CAPABLE "image" upload is supported<br/>
		UP_AV_CAPABLE "AV" upload is supported<br/>
		UP_CHILD_CONTAINER_CAPABLE "child container" upload is supported
\par Description:
This function returns whether the device specified for self supports the upload functions.

The uploader application determines the upload capabilities supported by the device based on the
return value.

*/
DLNA_API slim_int
dlnaUPIsCapable (TDMPObject self);

/*!
\par Function:
Function create stream to upload.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA DMS device object.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_obj_eh</td>
		<td>Callback function that notifies of internally generated event.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Callback argument</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_notify_kbsize</td>
		<td>Size of notification</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_param</td>
		<td>Upload stream parameter</td>
	</tr>
</table>
\return DLNA object witch represents upload stream object
\return slim_nil if failed
*/

DLNA_API TDMPObject
dlnaUPUploadStream (TDMPObject self, TDMPObjectEventHandler in_obj_eh, void *in_arg, 
                    slim_int in_notify_kbsize,
                    up_stream_param_t *in_param);

/*!
\par Function:
Function upload specyfied transport object
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA transport object to upload.</td>
	</tr>
</table>
\return slim_int error value UPNP_SUCCESS if succed
\par Return Values:
<table>
	<tr>
		<td> \b DLNA_E_UP_OK</td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td>DLNA_E_UP_GENERIC</td>
		<td>Fail or invalid parameter</td>
	</tr>
	<tr>
		<td>UPNP_GENERIC_ERROR</td>
		<td>Fail</td>
	</tr>
	<tr>
		<td>UPNP_INVALID_PARAM</td>
		<td>Invalid parameter</td>
	</tr>
	<tr>
		<td>UPNP_INVALID_STATE</td>
		<td>Fail</td>
	</tr>
	<tr>
		<td>UPNP_OUT_OF_MEMORY</td>
		<td>Fail</td>
	</tr>
</table>
*/

DLNA_API slim_int
dlnaUPUploadContent (TDMPObject self);

/*!
\par Function:
Function stop uploading specyfied transport object
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA transport object during upload to stop.</td>
	</tr>
</table>
\return slim_int error value
\par Return Values:
<table>
	<tr>
		<td> \b DLNA_E_OK</td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td>DLNA_E_UP_GENERIC</td>
		<td>Fail</td>
	</tr>
	<tr>
		<td>DLNA_E_UP_INVAL</td>
		<td>Invalid parameter</td>
	</tr>
</table>
*/

DLNA_API slim_int
dlnaUPStopUploading (TDMPObject self);

/*!
\par Function:
Cancels file uploading.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Upload control information</td>
	</tr>
</table>

\return UP_E_OK Succeeded 
\return Other than UP_E_OK Failed
\par Description:
This function cancels the upload specified for self.

When the request to cancel upload is successfully accepted, it returns UP_E_OK.

The processing result of this function is notified asynchronously by the callback function specified for
in_obj_eh in dlnaUPUploadFile().

An UP_OBJECT_EV_SUB_UPLOAD_CANCELED event notification is given once cancellation of the
upload is completed.

When the UP_OBJECT_EV_SUB_UPLOAD_CANCELED event is notified, the upload control information
must be discarded using the API for object destruction retained by the associated device class.
*/
DLNA_API slim_int
dlnaUPCancelUploading (TDMPObject self);

/*!
\par Function:
Function update stream parameters of specyfied object
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA object to update.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_object_id</td>
		<td>Object id to update.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_current_param</td>
		<td>Current parameter.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_new_param</td>
		<td>New parameter.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_obj_eh</td>
		<td>Callback function that notifies result of each API process.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>DLNA callback argument.</td>
	</tr>
</table>
\return updated TDMPObject
\par Return Values:
<table>
	<tr>
		<td> \b != slim_nil</td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td>slim_nil</td>
		<td>Fail</td>
	</tr>
</table>
*/

DLNA_API TDMPObject
dlnaUPUpdateObject (TDMPObject self, slim_char *in_object_id,
                    up_stream_param_t *in_current_param, up_stream_param_t *in_new_parami,
                    TDMPObjectEventHandler in_obj_eh, void *in_arg);

/*@}*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_DLNA_UP_API_H */
