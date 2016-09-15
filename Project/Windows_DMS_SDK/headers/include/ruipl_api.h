/*
 * ruipl_api.h
 * Copyright (C) 2009 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */


#ifndef NFLC_RUIPL_API_H
#define NFLC_RUIPL_API_H

#include <dlna_api.h>

#ifdef _DOXYGEN
#undef DLNA_API
#define DLNA_API
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus  */

#ifdef DLNA_SUPPORT_RUIPL
/* Support RUI */

/**
 * @addtogroup macros
 */
/*@{*/

/*!
UI list, which is available on +RUIPL+, was found
*/

#define RUI_EV_FOUND_UI DLNA_EV_FOUND_UI

/*!
3rd party notification was received
*/

#define RUI_EV_NOTIFY DLNA_EV_RUI_NOTIFY

/* upload API return code.  */

/*!
Succeeded (=0)
*/

#define RUI_E_OK                           DLNA_E_UP_OK

/*!
Generic error occurred
*/

#define RUI_E_GENERIC                      DLNA_E_UP_GENERIC
#define RUI_E_NO_SUCH_OBJ                  DLNA_E_UP_NO_SUCH_OBJ
#define RUI_E_RESTRICTED_OBJ               DLNA_E_UP_RESTRICTED_OBJ
#define RUI_E_RESTRICTED_PARENT_OBJ        DLNA_E_UP_RESTRICTED_PARENT_OBJ
#define RUI_E_NO_SUCH_RESOURCE             DLNA_E_UP_NO_SUCH_RESOURCE
#define RUI_E_RESOURCE_ACCESS_DENIED       DLNA_E_UP_RESOURCE_ACCESS_DENIED
#define RUI_E_NO_SUCH_CONTAINER            DLNA_E_UP_NO_SUCH_CONTAINER
#define RUI_E_BAD_METADATA                 DLNA_E_UP_BAD_METADATA
#define RUI_E_HTTP_TIMEOUT                 DLNA_E_UP_HTTP_TIMEOUT
#define RUI_E_HTTP_ERROR                   DLNA_E_UP_HTTP_ERROR

	
#define RUI_DEV_TYPE_RUIS_IBOX                               DLNA_DEV_TYPE_RUIS_IBOX

/*!
Level 1 RUI server device
*/

#define RUI_DEV_TYPE_RUIS_LEVEL1                             DLNA_DEV_TYPE_RUIS_LEVEL1

/*!
Level 2 RUI server device
*/

#define RUI_DEV_TYPE_RUIS_LEVEL2                             DLNA_DEV_TYPE_RUIS_LEVEL2
/* RUI Level. */

/*!
RUI device level is unknown.
*/

#define RUI_DEV_RUI_LEVEL_UNKNOWN                     DLNA_DEV_RUI_LEVEL_UNKNOWN

/*!
RUI device level is Level 0.
*/

#define RUI_DEV_RUI_LEVEL0                            DLNA_DEV_RUI_LEVEL0

/*!
RUI device level is Level 1.
*/

#define RUI_DEV_RUI_LEVEL1                            DLNA_DEV_RUI_LEVEL1

/*!
RUI device level is Level 2.
*/

#define RUI_DEV_RUI_LEVEL2                            DLNA_DEV_RUI_LEVEL2

/*!
This value indicates the type of device level.

Both the RUI client and the server device can be assigned one of these types.

<table>
	<tr>
		<td><b>Definition</b></td>
		<td><b>Event details</b></td>
	</tr>
	<tr>
		<td>RUI_DEV_RUI_LEVEL_UNKNOWN</td>
		<td>RUI device level is unknown.</td>
	</tr>
	<tr>
		<td>RUI_DEV_RUI_LEVEL0</td>
		<td>RUI device level is Level 0.</td>
	</tr>
	<tr>
		<td>RUI_DEV_RUI_LEVEL1</td>
		<td>RUI device level is Level 1.</td>
	</tr>
	<tr>
		<td>RUI_DEV_RUI_LEVEL2</td>
		<td>RUI device level is Level 2.</td>
	</tr>
</table>
*/

#define TRUIDeviceRUILevel                            TDLNADeviceRUILevel

#define TRUIObjectEventHandler TDLNAObjectEventHandler

/*!
TRUINotifyEHParam is the structure for 3rd party notification message.

\code
struct _TDLNARuiNotifyEHParam
{
	 slim_char *usn;
	 slim_int event_type;
	 slim_char *url;
	 slim_int seq;
	 slim_int window_type;
	 slim_int window_width;
	 slim_int window_height;
};
typedef struct _TDLNARuiNotifyEHParam TDLNARuiNotifyEHParam;
#define TRUINotifyEHParam TDLNARuiNotifyEHParam
\endcode

\par Member:

<table>
	<tr>
		<td>usn</td>
		<td>UDN (Unique Device Name) in SSDP packet</td>
	</tr>
	<tr>
		<td>event_type</td>
		<td>3rd party notification type</td>
	</tr>
	<tr>
		<td>url</td>
		<td>Notification URL from which the +RUIPL+ the notification document</td>
	</tr>
	<tr>
		<td>seq</td>
		<td>Notification ID</td>
	</tr>
	<tr>
		<td>window_type</td>
		<td>Notification window type</td>
	</tr>
	<tr>
		<td>window_width</td>
		<td>Width of the notification window</td>
	</tr>
	<tr>
		<td>window_height</td>
		<td>Height of the notification window</td>
	</tr>
</table>		
*/

#define TRUINotifyEHParam TDLNARuiNotifyEHParam

	/* gena events */

/*!
Gena notification was received
*/

#define RUI_EV_GENA_UI_LISTING_UPDATE			DLNA_EV_GENA_UI_LISTING_UPDATE

/*@}*/

/**
 * @addtogroup datatypes
 */
/*@{*/

/*!
TRUI is a pointer to a device class instance to which the +RUIPL+ device capability has been added.

For example, if the +RUIPL+ device capability is added to a DMP, then the TDMP instance (see the
description of "TDMP" in "NetFront Living Connect v2.0 DMP API Specification") is specified as this
type.
*/

typedef void * TRUI;

/*!
TUIObject represents two types of objects. One is a UI object exposed by a RUI server, the other is
the RUI server device object itself.

If the object represents a UI object, +RUIPL+ can get the UI object by executing
dlnaRUIGetUIList() after +RUIPL+ detects the RUI server and notifies the application layer of the
UI information.
*/

typedef void * TUIObject;

/*@}*/

//KKRUI added explicit request for i-BOX use case

/**
 * @addtogroup apis
 */
/*@{*/

/*!
\par Function:
Gets UI list from specified URL for i-Box use case. 
\par Parameters: 

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Device class instance that has +RUIPL+ device capability</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>udn</td>
		<td>
			UDN (Unique Device Name) string that represents a RUI server deviceString must start with 
			"uuid:" (Example: uuid:xxxxxxxx-xxxx-xxxxxxxx-xxxxxxxxxxxx)
		</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>url</td>
		<td>URL string that points to a UI list</td>
	</tr>
</table> 

\return 1 Succeeded
\return 0 Failed  
\par Description:
This function gets the UI list from the specified URL directly; notification of the result is given
asynchronously via callback function with a RUI_EV_FOUND_UI event.

If the device class is DMP, the callback function is defined as TDMPEventHandler(). If the device
class is not DMP, then the device class-dependent callback function (e.g. TDMCEventHandler())
must be called with a RUI_EV_FOUND_UI event.

This function is defined for the i-Box use case. In that use case, +RUIPL+ can know the URL of the UI
list exposed by the RUI server in advance and specify it for url.

In the 2-Box and 3-Box use cases, notification of the UI list should be given through the UPnP device
discovery function. Therefore, it is not necessary to call this API in such use cases.

After notification of a RUI_EV_FOUND_UI event is given, the application can create the i-Box device
object with dlnaRuiCreateIBoxDevice().
*/

slim_int
dlnaRUIGetUIListByUrl(TRUI self,void *udn, slim_char *url);

/*!
\par Function:
Creates i-Box device object. 
\par Parameters: 

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Device class that has +RUIPL+ device capability</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_udn</td>
		<td>UDN string that represents the i-Box device object</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>url</td>
		<td>URL string that indicates a UI list exposed by the i-Box device object</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_name</td>
		<td>i-Box server device name string</td>
	</tr>
</table> 

\return != slim_nil Pointer to created i-Box device object
\return == slim_nil Failed 
\par Description:
This function creates and returns an i-Box device object. It is recommended to call this function when
the application receives a RUI_EV_FOUND_UI event as a result of dlnaRUIGetUIListByUri().

The type of device created is set to RUI_DEV_TYPE_RUI_IBOX and the RUI level is set to
RUI_DEV_RUI_LEVEL0 internally.

For more information about i-Box, see "CEA-2014 revision A" specification.
*/

TDLNAObject
dlnaRuiCreateIBoxDevice (TRUI self, void *udn, slim_char *url, slim_char *in_name);

/* If "in_device" isn't slim_nil, it indicate to get the ui count of specified device;
   otherwise, it indicate to get ui count of all device. */

/*!
\par Function:
Gets number of UIs exposed by specified RUI server. 
\par Parameters: 

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Device class that has +RUIPL+ device capability</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_device</td>
		<td>Pointer to RUI server device object</td>
	</tr>
</table>

\return >0 Number of UIs
\return == 0 Generic error 
\par Description:
This function returns the number of UIs exposed by the specified RUI server.
*/

slim_int
dlnaRUIGetUICount (TRUI self, TUIObject in_device);

/* If "in_device" isn't slim_nil, it indicate to get the ui list of specified device;
   otherwise, it indicate to get ui list of all device. */

/*!
\par Function:
Gets UI list exposed by specified RUI server. 
\par Parameters: 

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Device class that has +RUIPL+ device capability</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_device</td>
		<td>Pointer to RUI server device object</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_ruis</td>
		<td>Buffer for detected UI object</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_beg</td>
		<td>Position to start getting UIs (>=0)</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_num</td>
		<td>Number of UIs to get</td>
	</tr>
</table>
 
\return RUI_E_OK Succeeded
\return RUI_E_GENERIC Generic error 
\par Description:
This function returns the UI list exposed by the specified RUI server.

The buffer size specified for out_ruis[] must be larger than in_num+1. It needs to be initialized in
advance.

To get all of the UIs, it is necessary to specify 0 for in_num and the return value of
dlnaRUIGetUICount()for in_beg.

The UI object must be released by dlnaDmpObjectClose() when the application is terminated.
*/

slim_int
dlnaRUIGetUIList (TRUI self, TUIObject in_device, TUIObject *out_ruis, slim_int in_beg,
                   slim_int in_num);

/*!
\par Function:
Gets UI title. 
\par Parameters: 

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to UI information obtained by dlnaRUIGetUIList()</td>
	</tr>
</table> 

\return != slim_nil UI title string
\return == slim_nil Failed 
\par Description:
This function returns the UI title included in the specified UI object.

The UI title indicates the value of the name element in the \<ui\> element of the UI list xml document
pointed to by the \<uiListURL\> element in the RUI server device description.

For more information about this value, see "CEA-2014 revision A" specification.
*/

slim_char*
dlnaRUIGetUITitle (TUIObject self);

/*!
\par Function:
Gets UI description. 
\par Parameters: 

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to UI information obtained by dlnaRUIGetUIList()</td>
	</tr>
</table> 

\return != slim_nil UI description string
\return == slim_nil Failed 
\par Description:
This function returns the UI description included in the specified UI object.

The UI description indicates the value of the \<description\> element in the \<ui\> element of the UI list
xml document pointed to by the \<uiListURL\> element in the RUI server device description.

For more information about this value, see "CEA-2014 revision A" specification.
*/

slim_char*
dlnaRUIGetUIDescription (TUIObject self);

/*!
\par Function:
Gets UI shortName. 
\par Parameters: 

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to UI information obtained by dlnaRUIGetUIList()</td>
	</tr>
</table> 

\return != slim_nil UI shortName string
\return == slim_nil Failed 
\par Description:
This function returns the UI shortName included in the specified UI object.

The UI shortName indicates the value of the "shortName" attribute of the \<protocol\> element in the
\<ui\> element of the UI list xml document pointed to by the \<uiListURL\> element in the RUI server
device description.

For more information about this value, see "CEA-2014 revision A" specification.
*/

slim_char*
dlnaRUIGetUIShortName (TUIObject self);

/*!
\par Function:
Gets number of UI profile lists. 
\par Parameters: 

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to UI information obtained by dlnaRUIGetUIList()</td>
	</tr>
</table>
 
\return >0 Number of UI profile lists
\return == 0 Generic error 
\par Description:
This function returns the number of profile lists included in the specified UI object.

The value indicates the number of \<profilelist\> elements in the \<ui\> element of the UI list xml
document pointed to by the \<uiListURL\> element in the RUI server device description.

For more information about this value, see "CEA-2014 revision A" specification.
*/

slim_int
dlnaRUIGetUIUriProfilelistCount (TUIObject self);

/*!
\par Function:
Gets UI URI.  
\par Parameters: 

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to UI information obtained by dlnaRUIGetUIList()</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_index</td>
		<td>0 (for future use) </td>
	</tr>
</table>
 
\return != slim_nil URI string
\return == slim_nil Failed
\par Description:
This function returns the URI string included in the specified UI object.

The URI indicates the value of the \<uri\> element in the \<ui\> element of the UI list xml document
pointed to by the \<uiListURL\> element in the RUI server device description.

For more information about this value, see "CEA-2014 revision A" specification.
*/

slim_char*
dlnaRUIGetUIUri (TUIObject self, slim_int in_index);

//KK

/*!
\par Function:
Gets UDN string. 
\par Parameters: 

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to UI information obtained by dlnaRUIGetUIList()</td>
	</tr>
</table>
 
\return != slim_nil UDN string
\return == slim_nil Failed 
\par Description:
This function returns the UDN string of the RUI server device that has the specified UI object.

The UDN indicates the value of the \<UDN\> element in the RUI server device description.
*/

slim_char*
dlnaRUIGetUDN (TUIObject self) ;

#ifdef DEVELOPMENT_DLNA_SUPPORT_RUIHPL
/*!
\par Function:
Sets UILifetime.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to DMP information </td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_udn</td>
		<td>UDN value string of Rui server </td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_url</td>
		<td>URL address string of Rui </td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_lifetime</td>
		<td>lifetime number string to set Rui </td>
	</tr>
</table>

\return RUI_E_OK Succeeded
\return RUI_E_GENERIC Generic Error
\par Description:
This function sets lifetime of RUI.
*/

slim_int
dlnaRUISetUILifetime (TDLNAObject self, slim_char *in_udn, slim_char *in_url, slim_char *in_lifetime) ;
#endif /* DEVELOPMENT_DLNA_SUPPORT_RUIHPL */

/*!
\par Function:
Gets UI profile list strings. 
\par Parameters: 

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Pointer to UI information obtained by dlnaRUIGetUIList()</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_prolist</td>
		<td>Buffer for detected profile lists </td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_buf_len</td>
		<td>Buffer length of out_prolist</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_index</td>
		<td>Position of profile list to get</td>
	</tr>
</table>
 
\return != slim_nil UI profile list strings
\return == slim_nil Failed 
\par Description: 
This function returns profile lists as strings.

The profile list indicates the value of the \<profilelist\> element pointed to by in_index in the \<ui\> element
of the UI list xml document pointed to by the \<uiListURL\> element in the RUI server device description.

An example of a profile list is shown below. 

\par Example:

\verbatim

UI Profile: SD_UIPROF
Audio Profile: MP3 audio/mpeg
Video Profile: MPEG_PS_PAL video/mpeg

\endverbatim 

"UI Profile" indicates the value of attribute "name" of the \<ui_profile\> element in the \<ui\> element.

"Audio Profile" indicates the "name" and "type" attribute values of the \<audio_profile\> element in the
\<ui\> element.

The "Video Profile" indicates the "name" and "type" attribute values of the \<video_profile\> element in
the \<ui\> element.

For more information about these values, see "CEA-2014 revision A" specification.
*/

slim_int
dlnaRUIGetUIProfilelist (TUIObject self, slim_char *out_prolist, slim_int in_buf_len, slim_int in_index);

/*!
\par Function:
Gets UI Icon URI.
\par Parameters:

<table>
        <tr>
                <td>[in]</td>
                <td>self</td>
                <td>Pointer to UI information obtained by dlnaRUIGetUIList()</td>
        </tr>
        <tr>
                <td>[in]</td>
                <td>in_index</td>
                <td>0 (for future use) </td>
        </tr>
</table>

\return != slim_nil icon URI string
\return == slim_nil Failed
\par Description:
This function allocates and returns the icon URI string included in the specified UI object.

The URI indicates the value of the \<url\> element in the \<icon\> element of the UI list xml document
pointed to by the \<uiListURL\> element in the RUI server device description.

For more information about this value, see "CEA-2014 revision A" specification.
*/

slim_char*
dlnaRUIGetUIIconURI (TUIObject self, slim_int in_index);

/*@}*/

#endif /* DLNA_SUPPORT_RUIPL */
#ifdef __cplusplus
}
#endif /* __cplusplus  */

#endif /* NFLC_RUIPL_API_H */
