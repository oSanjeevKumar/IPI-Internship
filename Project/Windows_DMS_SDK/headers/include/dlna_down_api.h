/*
 * dlna_down_api.h
 * Copyright (C) 2009 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2009 ACCESS CO., LTD. All Rights Reserved.  */

/* DOWNLOAD API.  */

#ifndef NFLC_DLNA_DN_API_H
#define NFLC_DLNA_DN_API_H

#include <dlna_peer.h>
#include <dlna_api.h>
#include <dmp_api.h>

#ifdef _DOXYGEN
#undef DLNA_API
#define DLNA_API
#endif

/* Prototypes.  */
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef DLNA_SUPPORT_DOWNLOADER

/**
 * @addtogroup apis
 */
/*@{*/

/*!
\par Function: 
Resumes download. 
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Download control information</td>
	</tr>
</table>

\return DLNA_E_OK Succeeded
\return DLNA_E_GENERIC Generic error
\return DLNA_E_INVAL Invalid argument 
\par Description:
This function resumes the download specified for self.

When the request to resume downloading is successfully accepted, it returns DLNA_E_OK.

The processing result of this function is notified asynchronously by the callback function specified for in_obj_eh in dlnaDNObjectDownload().

A DLNA_OBJECT_EV_DL_UPDATE event notification is given once the download is resumed.
*/
DLNA_API slim_int 
dlnaDNObjectResume (TDLNAObject self);

/*!
\par Function: 
Pauses download. 
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Download control information</td>
	</tr>
</table>

\return DLNA_E_OK Succeeded
\return DLNA_E_GENERIC Generic error
\return DLNA_E_INVAL Invalid argument 
\par Description: 
This function suspends the download specified for self.

When the request to suspend downloading is successfully accepted, it returns DLNA_E_OK.

The processing result of this function is notified asynchronously by the callback function specified for in_obj_eh in dlnaDNObjectDownload().

A DLNA_OBJECT_EV_DL_PAUSE event notification is given once download has been paused.
*/
DLNA_API slim_int 
dlnaDNObjectPause (TDLNAObject self);

/*!
\par Function: 
Cancels download.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Download control information</td>
	</tr>
</table>

\return DLNA_E_OK Succeeded
\return DLNA_E_GENERIC Generic error
\return DLNA_E_INVAL Invalid argument 
\par Description: 
This function cancels the download specified for self.

When the request to cancel download is successfully accepted, it returns DLNA_E_OK.

The processing result of this function is notified asynchronously by the callback function specified for in_obj_eh in dlnaDNObjectDownload().

A DLNA_OBJECT_EV_DL_CANCELED event notification is given once cancellation of the download is completed.

When the DLNA_OBJECT_EV_DL_CANCELED event is notified, the download control information must be discarded using the API for destroying objects retained by the associated device class.
*/
DLNA_API slim_int 
dlnaDNObjectCancel (TDLNAObject self);

/*!
\par Function: 
Starts downloading content file to local device.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Item information</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_obj_eh</td>
		<td>
			Pointer to callback function that notifies of individual API process results
		</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument of in_obj_eh</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_res_index</td>
		<td>
			>=0 Specifies resource index <br />
			-1 Specifies default resource
		</td>
	</tr>
</table>

\return != slim_nil Download control information
\return == slim_nil Failed in starting download 
\par Description: 
This function downloads the content file associated with the item information specified for self, to a local device. When the download process is successfully started, it returns the download control information.

The obtained download control information is used when calling the API that controls the download process.

A pointer to the callback function must be specified for in_obj_eh. The progress of download is notified asynchronously by in_obj_eh.

When download preparation is completed, the DLNA_OBJECT_EV_DL_OPEN event is notified by in_obj_eh, and once the download has been completed, the DLNA_OBJECT_EV_DL_CLOSE event is notified.

After the download is completed, the download control information must be discarded using the API for destroying objects retained by the associated device class. 
\note The item information to be specified for self in this function should be obtained using an API of the associated device class (if the associated device class is DMP, use dlnaDmpObjectBrowse() or dlnaDmpObjectSearch()).

And after the download is completed, the item information specified for self must be discarded using the API for destroying objects retained by the device class (if the associated device class is DMP, use dlnaDmpObjectClose()).

For more information about APIs and their usage, see the API specification of each device class.
*/
DLNA_API TDLNAObject
dlnaDNObjectDownload (TDLNAObject self, TDLNAObjectEventHandler in_obj_eh,
                      void *in_arg, slim_int in_res_index, slim_char *in_download_path);

/*@}*/

DLNA_API TDLNAObject
dlnaDNObjectDownloadFile(TDLNAObject self, TDLNAEventHandler in_object, void *in_arg,
                         slim_char *item, slim_char *url, slim_char *destinationPath);

#ifdef NFLC_OLD_API_COMPATIBLE

/**
 * @addtogroup apis
 */
/*@{*/

/* Old API wrapper. */

/*!
\par Function:
Resumes download.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Download control information</td>
	</tr>
</table>
\return A slim_int error code.
\par Return Values:
<table>
	<tr>
		<td> \b DLNA_E_OK </td>
		<td> \b Succeeded </td>
	</tr>
	<tr>
		<td> \b DLNA_E_GENERIC </td>
		<td> \b Generic error </td>
	</tr>
	<tr>
		<td> \b DLNA_E_INVAL </td>
		<td> \b Invalid argument </td>
	</tr>
</table>
\par Description:
This function resumes the download specified for self.

When the request to resume downloading is successfully accepted, it returns DLNA_E_OK.

The processing result of this function is notified asynchronously by the callback function specified for in_obj_eh in dlnaDNObjectDownload().

A DLNA_OBJECT_EV_DL_UPDATE event notification is given once the download is resumed.
*/

DLNA_API slim_int 
dlnaDmpObjectDNResume (TDMPObject self);

/*!
\par Function:

\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>A pointer to object representing the a download</td>
	</tr>
</table>
\return A slim_int error code.
\par Return Values:
<table>
	<tr>
		<td> \b Definition</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>DLNA_E_INVAL</td>
		<td>Invalid arguments</td>
	</tr>
	<tr>
		<td>DLNA_E_GENERIC</td>
		<td>Generic Error</td>
	</tr>
	<tr>
		<td>UPNP_GENERIC_ERROR</td>
		<td>Generic Error at UpnP level</td>
	</tr>
	<tr>
		<td>UPNP_INVALID_PARAM</td>
		<td>Invalid parameters at UpnP level</td>
	</tr>
</table>
*/

DLNA_API slim_int 
dlnaDmpObjectDNPause (TDMPObject self);

/*!
\par Function:

\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>A pointer to object representing the a download</td>
	</tr>
</table>
\return A slim_int error code.
\par Return Values:
<table>
	<tr>
		<td> \b DLNA_E_OK </td>
		<td> \b Succeeded </td>
	</tr>
	<tr>
		<td> \b DLNA_E_GENERIC </td>
		<td> \b Generic error </td>
	</tr>
	<tr>
		<td> \b DLNA_E_INVAL </td>
		<td> \b Invalid argument </td>
	</tr>
	<tr>
		<td> \b UPNP_INVALID_PARAM </td>
		<td> \b Invalid argument </td>
	</tr>
	<tr>
		<td> \b UPNP_GENERIC_ERROR </td>
		<td> \b Invalid argument or upnp error </td>
	</tr>
</table>
\par Description:
This function cancels the download specified for self.

When the request to cancel download is successfully accepted, it returns DLNA_E_OK.

The processing result of this function is notified asynchronously by the callback function specified for in_obj_eh in dlnaDNObjectDownload().

A DLNA_OBJECT_EV_DL_CANCELED event notification is given once cancellation of the download is completed.

When the DLNA_OBJECT_EV_DL_CANCELED event is notified, the download control information must be discarded using the API for destroying objects retained by the associated device class.
*/

DLNA_API slim_int 
dlnaDmpObjectDNCancel (TDMPObject self);

/*!
\par Function:
Initiates download of indicated resource.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>DLNA object which initiates the download</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_obj_eh</td>
		<td>A pointer to an object event handler function</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>An argument for the object event handler function</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_res_index</td>
		<td>Index number of the resource. e.g. when downloading an image, it can indicate that a small version is to be downloaded.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_download_path</td>
		<td>path to the resource to be downloaded</td>
	</tr>
</table>
\return Object representing the download.
*/

DLNA_API TDMPObject
dlnaDmpObjectDownload (TDMPObject self, TDMPObjectEventHandler in_obj_eh,
                       void *in_arg, slim_int in_res_index, slim_char *in_download_path);

/*@}*/

#endif /* NFLC_OLD_API_COMPATIBLE */

#endif /* DLNA_SUPPORT_DOWNLOADER */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_DLNA_UP_API_H */
