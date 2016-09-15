/*
 * satip_api.h
 * Copyright (C) 2007-2013 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* vim: set tabstop=2:softtabstop=2:shiftwidth=2:expandtab */
/* SAT>IP API */

#ifndef NFLC_SATIP_API_H
#define NFLC_SATIP_API_H

#include <dlna_peer.h>
#include <dlna_api.h>

#ifdef _DOXYGEN
#undef DLNA_API
#define DLNA_API
#endif

/**
 * @addtogroup macros
 */
/*@{*/

/* SATIP events */
#define SATIP_EV_FOUND_DEVS                             DLNA_EV_FOUND_DEVS
#define SATIP_EV_BYEBYE                                 DLNA_EV_BYEBYE
#define SATIP_EV_UNAVAILABLE                            DLNA_EV_UNAVAILABLE
#define SATIP_EV_DEVICE_ID_CHG                          DLNA_EV_DEVICE_SUID_CHG
#define SATIP_EV_NETIF_ADDR_ADD                         DLNA_EV_NETIF_ADDR_ADD
#define SATIP_EV_NETIF_ADDR_DEL                         DLNA_EV_NETIF_ADDR_DEL

/*!
TSATIPEvent is a value that represents the type of event set for TSATIPEventHandler().

For more information, see "UPnP AV ContentDirectory:1 Service Template Version 1.01".

One of the following values is set for TSATIPEvent.

<table>
  <tr>
    <td><b>Definition</b></td>
    <td><b>Event details</b></td>
  </tr>
  <tr>
    <td>SATIP_EV_FOUND_DEVS</td>
    <td>SATIP detected device(s)</td>
  </tr>
  <tr>
    <td>SATIP_EV_BYEBYE</td>
    <td>Detected ssdp: byebye</td>
  </tr>
  <tr>
    <td>SATIP_EV_UNAVAILABLE</td>
    <td>Failed to receive ssdp: alive from a device</td>
  </tr>
  <tr>
    <td>SATIP_EV_DEVICE_SUID_CHG</td>
    <td>Received system update ID from a device</td>
  </tr>
  <tr>
    <td>SATIP_EV_NETIF_ADDR_ADD</td>
    <td>Add IP address.</td>
  </tr>
  <tr>
    <td>SATIP_EV_NETIF_ADDR_DEL</td>
    <td>Delete IP address.</td>
  </tr>
</table>
*/
  
#define TSATIPEvent                                     TDLNAEvent

/* SATIP device type.  */
#define SATIP_DEV_TYPE_UNKNOWN                          DLNA_DEV_TYPE_UNKNOWN
#define SATIP_DEV_TYPE_SATIP                            DLNA_DEV_TYPE_SATIP

/*!
TSATIPDeviceType is a value that represents the type of event set by
satipDeviceType().

One of the following DLNA device types is set for TSATIPCDeviceType.

<table>
  <tr>
    <td><b>Definition</b></td>
    <td><b>Device type details</b></td>
  </tr>
  <tr>
    <td>SATIP_DEV_TYPE_UNKNOWN</td>
    <td>Unknown device</td>
  </tr>
  <tr>
    <td>SATIP_DEV_TYPE_SATIP</td>
    <td>SATIP device</td>
  </tr>
</table>
*/

#define TSATIPDeviceType                                TDLNADeviceType

/* SATIP API return code.  */
#define SATIP_E_OK                                      DLNA_E_OK
#define SATIP_E_GENERIC                                 DLNA_E_GENERIC
#define SATIP_E_INVAL                                   DLNA_E_INVAL
#define SATIP_E_NOMEM                                   DLNA_E_NOMEM
#define SATIP_E_DEV                                     DLNA_E_DEV
#define SATIP_E_OBJ                                     DLNA_E_OBJ
#define SATIP_E_OBJ_INVAL                               DLNA_E_OBJ_INVAL
#define SATIP_E_URI                                     DLNA_E_URI
#define SATIP_E_COMM                                    DLNA_E_COMM
#define SATIP_E_NOFILE                                  DLNA_E_NOFILE
#define SATIP_E_FILE_IO                                 DLNA_E_FILE_IO
/* #define SATIP_E_NOTFOUND                                DLNA_E_NOTFOUND */
#define SATIP_API_ERROR                                 DLNA_API_ERROR

/*!
One of the following value is returned from SATIP APIs.

<table>
  <tr>
    <td><b>Definition</b></td>
    <td><b>Return value details</b></td>
  </tr>
  <tr>
    <td>SATIP_E_OK</td>
    <td>Succeeded (=0)</td>
  </tr>
  <tr>
    <td>SATIP_E_GENERIC</td>
    <td>Generic error occurred</td>
  </tr>
  <tr>
    <td>SATIP_E_INVAL</td>
    <td>Invalid argument(s) specified</td>
  </tr>
  <tr>
    <td>SATIP_E_NOMEM</td>
    <td>Insufficient memory</td>
  </tr>
  <tr>
    <td>SATIP_E_DEV</td>
    <td>Device not available</td>
  </tr>
  <tr>
    <td>SATIP_E_OBJ</td>
    <td>Invalid object</td>
  </tr>
  <tr>
    <td>SATIP_E_OBJ_INVAL</td>
    <td>Invalid object</td>
  </tr>
  <tr>
    <td>SATIP_E_URI</td>
    <td>Invalid URI</td>
  </tr>
  <tr>
    <td>SATIP_E_COMM</td>
    <td>Communication error</td>
  </tr>
  <tr>
    <td>SATIP_E_NOFILE</td>
    <td>File not found</td>
  </tr>
  <tr>
    <td>SATIP_E_FILE_IO</td>
    <td>File I/O error</td>
  </tr>
  <tr>
    <td>SATIP_API_ERROR</td>
    <td>SAT>IP API error</td>
  </tr>
</table>
*/


#define TSATIPEventHandler TDLNAEventHandler

/*@}*/

/**
 * @addtogroup datatypes
 */
/*@{*/

/* SATIP API types.  */

/*!
TSATIP is a SATIP library instance.

SATIP applications must not access the TSATIP.
*/

typedef void * TSATIP;

/*!
TSATIPObject is a pointer to a generic object that allows the SATIP library to handle data internally.

SATIP applications must not access the TSATIPObject (hereafter, SATIP object).
*/

typedef void * TSATIPObject;

/*@}*/

/**
 * @addtogroup structures
 */
/*@{*/

/* satipNew parameter.  */
struct _TSATIPNewParam
{
  /* DLNA progress */
  dlna_progress progress;

  /* Device ID */
  slim_short deviceID; 

  /* SATIP UPnP server port number */
  slim_half port;

  /* Directory path in which SATIP configuration XML file is located */
  slim_char *config_dir;

  /* Name of SATIP device description file */
  slim_char *device_file; 
};

/*!
TSATIPNewParam is a structure for setting the parameters of the SATIP library.

\code
  struct _TSATIPNewParam
  {
    // DLNA progress. 
    dlna_progress progress;

    // Device ID. 
    slim_short deviceID;
 
    // SATIP UPnP server port number
    slim_half port;

    // Directory path in which SATIP configuration XML file is located
    slim_char *config_dir;

    // Name of SATIP device description file
    slim_char *device_file; 
  };

  typedef struct _TSATIPNewParam TSATIPNewParam;
\endcode

\par Member:

<table>
  <tr>
    <td>progress</td>
    <td>
      DLNA progress handle <br />
      For information about the dlna_progress type, see the description of
      "Basic Data Types" in "NetFront Living Connect v2.0 Porting Guide", and how to get the DLNA progress, see "Progress Function" of the guide.
    </td>
  </tr>
  <tr>
    <td>deviceID</td>
    <td>
      Start up SAT>IP device ID, default is 1 if not assigned (0)
    </td>
  </tr>
  <tr>
    <td>port</td>
    <td>
      DMR UPnP server port number, default is 1900 if not assigned (0)
    </td>
  </tr>
  <tr>
    <td>config_dir</td>
    <td>
      Directory path in which DMR configuration XML file is located, default is xml/ if not assigned (slim_nil)
    </td>
  </tr>
  <tr>
    <td>device_file</td>
    <td>
      Name of SATIP device description file, default is satip.xml if not assigned (slim_nil)
    </td>
  </tr>
</table>
*/

typedef struct _TSATIPNewParam TSATIPNewParam;

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
Generates DMR instance. 
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
    <td>in_param</td>
    <td>Initial parameter of SATIP library</td>
	</tr>
</table>

\return != slim_nil Succeeded (SATIP instance)
\return == slim_nil Initialization failed 
\par Description: 
This function generates and initializes a SATIP instance.

Specify the DLNA progress manager descriptor allocated by dlnaProgressAllocPeer() for the progress member of in_param.
(see dlnaProgressAllocPeer() in "NetFront Living Connect v2.0 Porting Guide").

Specify the device ID for the deviceID member of in_param.

Specify the UPnP port number for the port member of in_param.

Specify the configuration files directory for the config_dir member of in_param.

Specify the device description file name for the device_file member of in_param.

satipFree() is used to delete the SATIP instance generated by this function.

This function does not allow multiple SATIP instances to be generated.

This function must be called first among all the SATIP APIs.
*/
/* API: Allocate SATIP */
DLNA_API TSATIP
satipAlloc (TSATIPNewParam *in_param);

/*!
\par Function: 
Deletes SATIP instance.
\par Parameters:

<table> 
  <tr>
    <td>[in]</td>
    <td>self</td>
    <td>SATIP instance</td>
  </tr>
</table>

\return SATIP_E_OK        Succeeded
\return SATIP_E_GENERIC   Generic error
\par Description: 
This function deletes a SATIP instance.

When the SATIP library is started (after successful satipStart()), satipStop() must be
called to stop the SATIP library before calling this function.

After this function is called, delete the DLNA progress by calling dlnaProgressFreePeer() (see
the description of dlnaProgressFreePeer() in "NetFront Living Connect v2.0 Porting Guide").
*/
/* API: Free SATIP */
DLNA_API slim_int
satipFree (TSATIP self);

/*!
\par Function: 
Starts SATIP server library. 
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>SATIP instance</td>
	</tr>
  <tr>
    <td>[in]</td>
    <td>in_satip_eh</td>
    <td>Callback function that notifies of internally generated event</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_arg</td>
    <td>Argument of in_satip_eh </td>
  </tr>
</table>
 
\return SATIP_E_OK        Succeeded
\return SATIP_E_GENERIC   Generic error
\return SATIP_E_INVAL     Invalid parameter
\return SATIP_E_NOFILE    Failed to read SATIP configuration XML file
\return SATIP_E_FILE_IO   Invalid description in SATIP configuration XML file
\return SATIP_E_NOMEM     Insufficient memory
\par Description: 
This function prepares the SSDP used by a SATIP. After that, it registers an event to send an SSDP packet to notify every other device on the network that the SATIP device itself is available.

Calling dlnaProgressStartPeer() after this function call starts operation of the SATIP library (see the description of dlnaProgressStartPeer() in "NetFront Living Connect v2.0 Porting Guide").
*/
/* API: Start SATIP */
DLNA_API slim_int
satipStart (TSATIP self, TSATIPEventHandler in_satip_eh, void *in_arg);

/*!
\par Function: 
Stops SATIP server library.
\par Parameters:

<table> 
  <tr>
    <td>[in]</td>
    <td>self</td>
    <td>SATIP instance</td>
  </tr>
</table>

\return SATIP_E_OK        Succeeded
\return SATIP_E_GENERIC   Generic error
\par Description: 
This function stops the SSDP used by the SATIP for communication.

Calling this function will send an SSDP byebye packet to notify all devices that the SATIP device is no longer available to the network.

If the DLNA progress was started by dlnaProgressStartPeer(), then the DLNA progress must be stopped by dlnaProgressStopPeer(), before calling this function (see the description of dlnaProgressStopPeer() in "NetFront Living Connect v2.0 Porting Guide").
*/
DLNA_API slim_int
satipStop (TSATIP self);

/*!
\par Function: 
Starts SATIP client library.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>SATIP instance</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_satip_eh</td>
		<td>Callback function that notifies of internally generated event</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument of in_satip_eh </td>
	</tr>
</table>

\return SATIP_E_OK Succeeded 
\return Other Failed
\par Description: 
This function prepares the protocols to be used for communication by  SATIP (SSDP).

Then, it registers an event to send an SSDP packet to seek available SATIP device(s) on the network.

Calling dlnaProgressStartPeer() after this function call starts operation of the SATIP library.

Specify a pointer to the callback function that notifies when internal events occur, for in_satip_eh. Null cannot be specified for it.
*/
DLNA_API slim_int
satipOpen (TSATIP self, TSATIPEventHandler in_satip_eh, void *in_arg);

/*!
\par Function: 
Stops SATIP client library.
\par Parameters:

<table>	
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>SATIP instance</td>
	</tr>
</table>

\return None 
\par Description: 
This function stops the SSDP used by the SATIP for communication.

If the DLNA progress was started by dlnaProgressStartPeer(), then the DLNA progress must be stopped by dlnaProgressStopPeer(), before calling this function (see the description of dlnaProgressStopPeer() in "NetFront Living Connect v2.0 Porting Guide").
*/
DLNA_API void
satipClose (TSATIP self);

/*!
\par Function: 
Gets number of detected devices. 
\par Parameters:

<table> 
  <tr>
    <td>[in]</td>
    <td>self</td>
    <td>SATIP instance</td>
  </tr>
</table>

\return >= 0 Number of detected devices
\return <0 Failed 
\par Description: 
This function returns the number of detected devices.

When TSATIPEvent is notified as SATIP_EV_FOUND_DEVS, it is recommended to call this function within
TSATIPEventHandler(), and get the total number of devices.
*/
DLNA_API slim_int
satipDeviceCount (TSATIP self);

/*!
\par Function: 
Gets detected device information.
\par Parameters:

<table> 
  <tr>
    <td>[in]</td>
    <td>self</td>
    <td>SATIP instance</td>
  </tr>
  <tr>
    <td>[out]</td>
    <td>out_devs</td>
    <td>Buffer for detected device information (NULL terminated) </td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_beg</td>
    <td>Position to start getting device information (>=0)</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_num</td>
    <td>Number of devices for which to get device information</td>
  </tr>
</table>

\return SATIP_E_OK Succeeded 
\return SATIP_E_INVAL Invalid argument 
\par Description: 
This function returns detected device information.

It sets in_num number of pointers to detected device information for out_devs[], starting from the position in_beg.

out_devs[] must be prepared with a size of in_num+1 or more. It is necessary to initialize out_devs[] with null.

If the number of devices that can be obtained is less than in_num, then the number of devices that can be obtained is specified.

When TSATIPEvent is notified as SATIP_EV_FOUND_DEVS, it is recommended to call this function within TSATIPEventHandler(), and get the device information.

When SATIP is terminated, the device information must be released  satipObjectClose().
*/
DLNA_API slim_int
satipDeviceList (TSATIP self, TSATIPObject out_devs[], slim_int in_beg,
                   slim_int in_num);

/*!
\par Function: 
Gets device information corresponding to specified UDN.
\par Parameters:

<table> 
  <tr>
    <td>[in]</td>
    <td>self</td>
    <td>SATIP instance</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_udn</td>
    <td>UDN of device information to be obtained</td>
  </tr>
</table>

\return != slim_nil Pointer to device information that matches specified UDN
\return == slim_nil Failed, or corresponding device does not exist 
\par Description: 
This function returns device information matching the specified UDN (Unique Device Name).

Specify a string starting with "uuid:" for in_udn. 
\par Example: 
\code
uuid:xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx
\endcode
*/
DLNA_API TSATIPObject
satipDeviceLookupByUDN(TSATIP self, slim_char *in_udn);

/*!
\par Function:
Function removes all devices from self.
\par Parameters:
<table>
  <tr>
    <td>[in]</td>
    <td>self</td>
    <td>DLNA .</td>
  </tr>
</table>
\return slim_int error code value
\par Return Values:

<table>
  <tr>
    <td> \b SATIP_E_OK</td>
    <td> \b All \b devices \b removal \b succed</td>
  </tr>
  <tr>
    <td>SATIP_E_GENERIC</td>
    <td>Some error occured and all or part of devices may not be removed</td>
  </tr>
</table>
\par Description:
This function removes all devices upnp client devices queue and dlna client devices queue.
*/
DLNA_API slim_int
satipDeviceRemoveAll(TSATIP self);

/*!
\par Function:
Updates device information.
\par Parameters:

<table> 
  <tr>
    <td>[in]</td>
    <td>self</td>
    <td>SATIP instance</td>
  </tr>
</table>

\return None
\par Description:
This function updates the device information with the latest information. The result is notified by TSATIPEventHandler().

Updating of device information is performed regularly by the SATIP library. It is not necessary to call this function for getting device information. Call this function only to force the updating of device information.
*/
DLNA_API void
satipDeviceSearch(TSATIP self);

/*!
\par Function: 
Gets DLNA device type.
\par Parameters:

<table> 
  <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to device information obtained by satipDeviceList()</td>
  </tr>
</table>
\return TSATIPDeviceType SATIP device type
\par Return Values:
<table>
  <tr>
    <td> \b SATIP_DEV_TYPE_SATIP</td>
    <td> \b SATIP \b devices</td>
  </tr>
  <tr>
    <td>SATIP_DEV_TYPE_UNKNOWN</td>
    <td>Non-SATIP devices</td>
  </tr>
</table>
\par Description: 
This function returns the device type of the specified device.

When TSATIPEvent is notified as SATIP_EV_FOUND_DEVS, it is recommended to call this function within TSATIPEventHandler(), and get the device types.
*/
DLNA_API TSATIPDeviceType
satipDeviceType(TSATIPObject self);

/*!
\par Function:
Allocates and returns string with device base URL in order: "http://address:port" .
\par Parameters:
<table>
  <tr>
    <td>[in]</td>
    <td>self</td>
    <td>SATIP device type object.</td>
  </tr>
</table>
\return slim_char* pointer to device base url
\par Return Values:

<table>
  <tr>
    <td> \b != slim_nil</td>
    <td> \b Pointer \b to \b device \b base \b URL</td>
  </tr>
  <tr>
    <td>slim_nil</td>
    <td>During getting device error occured or self was not a device type object</td>
  </tr>
</table>
\par Description:
This function allocates and returns string with device base URL.

\par Example:
Returned value looks like: "http://address:port"
*/
DLNA_API slim_char *
satipDeviceBaseURL (TSATIPObject self);

/*!
\par Function:
Function return device IP address.
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>self</td>
    <td>DLNA device type object.</td>
  </tr>
  <tr>
    <td>[out]</td>
    <td>out_ip</td>
    <td>pointer to allocated place in memory to store ip.</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_len</td>
    <td>size of out_ip allocation.</td>
  </tr>
</table>
\return slim_int error code
\par Return Values:

<table>
  <tr>
    <td> \b SATIP_E_OK</td>
    <td> \b Success</td>
  </tr>
  <tr>
    <td>SATIP_E_GENERIC</td>
    <td> Generic error</td>
  </tr>
  <tr>
    <td>SATIP_E_DEV</td>
    <td> Slef is not a device type object</td>
  </tr>
  <tr>
    <td>SATIP_E_URI</td>
    <td>Error in URI</td>
  </tr>
</table>
\par Description:
This function gets device IP address
remember that to store all IPv4 address allocation size of \b out_ip should be for 16 characters.
*/
DLNA_API slim_int
satipDeviceIP (TSATIPObject self, slim_char *out_ip, slim_int in_len);

/*!
\par Function:
Function return device mac address.
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>self</td>
    <td>DLNA device object.</td>
  </tr>
  <tr>
    <td>[out]</td>
    <td>out_mac</td>
    <td>pointer to allocated place in memory to store mac address.</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_len</td>
    <td>size of out_mac allocation.</td>
  </tr>
</table>
\return slim_int error code
\par Return Values:

<table>
  <tr>
    <td> \b SATIP_E_OK</td>
    <td> \b Success</td>
  </tr>
  <tr>
    <td>SATIP_E_GENERIC</td>
    <td> Generic error</td>
  </tr>
  <tr>
    <td>SATIP_E_DEV</td>
    <td> Slef is not a device type object</td>
  </tr>
  <tr>
    <td>SATIP_E_URI</td>
    <td>Error in URI</td>
  </tr>
  <tr>
    <td>SATIP_E_NOMEM</td>
    <td>Out of memory</td>
  </tr>
</table>
\par Description:
This function gets device MAC address
remember that to store all MAC address allocation size of \b out_mac should be for 16 characters.
*/
DLNA_API slim_int
satipDeviceMACAddress (TSATIPObject self, slim_char *out_mac, slim_int in_len);

/*!
\par Function:
Deletes device/container/item information.
\par Parameters:

<table> 
  <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to device, container, or item information to delete</td>
  </tr>
</table>

\return None 
\par Description: 
This function deletes the information of the device, container, or item that is specified for self.

API processing using self will be canceled.

The following are the trigger events for using this function from a SATIP application:

<b>(1)  When TSATIPEventHandler is notified of an event</b>

<table>
  <tr>
    <td><b>Event name</b></td><td> <b>Description</b></td>
  </tr>
  <tr>
    <td>SATIP_EV_BYEBYE</td>
    <td>
      This event notification is given when a device on the network stops, so 
      the device information allocated by the SATIP is deleted
    </td>
  </tr>
  <tr>
    <td>SATIP_EV_UNAVAILABLE</td>
    <td>
      This event notification is given when a device on the network gets disabled, 
      so the device information allocated by the SATIP is deleted
    </td>
  </tr>
</table>

<b>(2) When deleting obtained device, container, or item information </b>

Device information that is obtained by satipDeviceList() cannot be deleted until this function executes.

The SATIP application must delete the device, container, or item information using this function when
the information is no longer needed.
*/
DLNA_API void
satipObjectClose (TSATIPObject self);

/*!
\par Function: 
Determines whether SATIP object is device.
\par Parameters:

<table> 
  <tr>
    <td>[in]</td>
    <td>self</td>
    <td>SATIP object</td>
  </tr>
</table>

\return slim_true Object type is device
\return slim_false Object type is not device 
\par Description: 
This function returns whether the object type is device.
*/
DLNA_API slim_bool
satipObjectTypeIsDevice (TSATIPObject self);

/*!
\par Function:
Gets property value by name.
\par Parameters:

<table> 
  <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to device, container, or item information for which to get property value</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_prop</td>
    <td>Property name</td>
  </tr>
</table>

\return URI (string) Property value 
\return Null Specified object has no property value 
\par Description: 
This function searches for the property specified by in_prop, and returns the property value string.

This function searches the XML document of the object and returns the property value.

Since this function returns the address to an area allocated in a SATIP object as the return value, the
property value can be referenced until the SATIP object is deleted by satipObjectClose().
*/
DLNA_API slim_char *
satipObjectPropGet (TSATIPObject self, slim_char* in_prop);

/*!
\par Function:
Gets device icon URL.
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to device type object for which to get property icon URL</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_icon_device_type</td>
    <td>icon type to get property URL.</td>
  </tr>
</table>

\return pointer to specyfied icon relative path if Succeeded
\return slim_nil if it cannot find specyfied icon for item or self is a slim_nil or if self is not a device type object
\par Description:
This function returns device icon relative path.
To get icon url you need concatenation of returned value of satipDeviceBaseURL function and this function.
*/
DLNA_API slim_char *
satipObjectPropIconURL (TSATIPObject self, dlna_device_icon_type in_icon);

/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/

#ifdef _DOXYGEN

/*!
\par Function:
Get the device name.
\par Parameters:

<table> 
  <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to device information obtained by satipDeviceList()</td>
  </tr>
</table>

\return !=slim_nil Device name (NULL terminated)
\return == slim_nil Failed
\par Description:
This function returns the device name of the specified device.

The device name is searched for in the following order.

-# FriendlyName in XML (if it exists, value is returned even if it is empty)
-# ModelName in XML (if it exists, value is returned even if it is empty)

If not found for both 1 and 2, then it returns an empty string.

When TSATIPEvent is notified as SATIP_EV_FOUND_DEVS, it is recommended to call this function within TSATIPEventHandler(), and get the device names.
*/
slim_char * satipDeviceName (TSATIPObject self);


/*!
\par Function:
Gets the device UUID.
\par Parameters:
     
<table> 
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to device information obtained by satipDeviceList()</td>
 </tr>
</table>
     
\return Device UUID (NULL terminated)
\par Description:
This function returns the device name of the specified device.
     
When notification of TSATIPEvent is given by SATIP_EV_FOUND_DEVS, it is recommended to call this
function within TSATIPEventHandler() to get the device name.
*/
slim_char * satipDeviceUuid (TSATIPObject self);


/*!
\par Function:
Gets the manufacturer name.
\par Parameters:
     
<table> 
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to device information obtained by satipDeviceList()</td>
 </tr>
</table>
     
\return manufacturer name (NULL terminated)
\par Description:
This function returns the device name of the specified device.
     
When notification of TSATIPEvent is given by SATIP_EV_FOUND_DEVS, it is recommended to call this
function within TSATIPEventHandler() to get the device name.
*/
slim_char * satipManufacturerName (TSATIPObject self);

/*!
\par Function:
Gets the manufacturer URL.
\par Parameters:
     
<table> 
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to device information obtained by satipDeviceList()</td>
 </tr>
</table>
     
\return manufacturer URL (NULL terminated)
\par Description:
This function returns the device name of the specified device.
     
When notification of TSATIPEvent is given by SATIP_EV_FOUND_DEVS, it is recommended to call this 
function within TSATIPEventHandler() to get the device name.
*/
slim_char * satipManufacturerURL (TSATIPObject self);


/*!
\par Function:
Gets the model name.
\par Parameters:
     
<table> 
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to device information obtained by satipDeviceList()</td>
 </tr>
</table>
     
\return model name (NULL terminated)
\par Description:
This function returns the device name of the specified device.
     
When notification of TSATIPEvent is given by SATIP_EV_FOUND_DEVS, it is recommended to call this 
function within TSATIPEventHandler() to get the device name.
*/
slim_char * satipModelName (TSATIPObject self);

/*!
\par Function:
Gets the model URL.
\par Parameters:
     
<table> 
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to device information obtained by satipDeviceList()</td>
 </tr>
</table>
     
\return model URL (NULL terminated)
\par Description:
This function returns the device name of the specified device.
     
When notification of TSATIPEvent is given by SATIP_EV_FOUND_DEVS, it is recommended to call this 
function within TSATIPEventHandler() to get the device name.
*/
slim_char * satipModelURL (TSATIPObject self);


/*!
\par Function:
Gets the model description.
\par Parameters:
     
<table> 
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to device information obtained by satipDeviceList()</td>
 </tr>
</table>
     
\return model description (NULL terminated)
\par Description:
This function returns the device name of the specified device.
     
When notification of TSATIPEvent is given by SATIP_EV_FOUND_DEVS, it is recommended to call this 
function within TSATIPEventHandler() to get the device name.
*/
slim_char * satipModelDescription (TSATIPObject self);

/*!
\par Function:
Gets the model number.
\par Parameters:
     
<table> 
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to device information obtained by satipDeviceList()</td>
 </tr>
</table>
     
\return model number (NULL terminated)
\par Description:
This function returns the device name of the specified device.
     
When notification of TSATIPEvent is given by SATIP_EV_FOUND_DEVS, it is recommended to call this 
function within TSATIPEventHandler() to get the device name.
*/
slim_char * satipModelNumber (TSATIPObject self);


/*!
\par Function:
Gets the serial number.
\par Parameters:
     
<table> 
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to device information obtained by satipDeviceList()</td>
 </tr>
</table>
     
\return serial number (NULL terminated)
\par Description:
This function returns the device name of the specified device.
     
When notification of TSATIPEvent is given by SATIP_EV_FOUND_DEVS, it is recommended to call this 
function within TSATIPEventHandler() to get the device name.
*/
slim_char * satipSerialNumber (TSATIPObject self);

/*!
\par Function:
Gets the TXT version.
\par Parameters:
     
<table> 
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to device information obtained by dlnaDmcDeviceList()</td>
 </tr>
</table>
     
\return TXT version (NULL terminated)
\par Description:
This function returns the device name of the specified device.
     
When notification of TSATIPEvent is given by SATIP_EV_FOUND_DEVS, it is recommended to call this 
function within TSATIPEventHandler() to get the device name.
*/
slim_char * satipTXTVersion (TSATIPObject self); 

/*!
\par Function:
Gets the presentation URL.
\par Parameters:
     
<table> 
 <tr>
    <td>[in]</td>
    <td>self</td>
    <td>Pointer to device information obtained by satipDeviceList()</td>
 </tr>
</table>
     
\return presentation URL (NULL terminated)
\par Description:
This function returns the presentation URL of the specified device.
     
When notification of TSATIPEvent is given by SATIP_EV_FOUND_DEVS, it is recommended to call this 
function within TSATIPEventHandler() to get the device name.
*/
slim_char * satipPresentationURL (TSATIPObject self);

#endif

/*@}*/

/**
 * @addtogroup macros
 */
/*@{*/

#ifndef _DOXYGEN

#define satipDeviceName(self)                     satipObjectPropGet (self, SLIM_T("friendlyName"))
#define satipDeviceUuid(self)                     satipObjectPropGet (self, SLIM_T("UDN"))
#define satipManufacturerName(self)               satipObjectPropGet (self, SLIM_T("manufacturer"))
#define satipManufacturerURL(self)                satipObjectPropGet (self, SLIM_T("manufacturerURL"))
#define satipModelName(self)                      satipObjectPropGet (self, SLIM_T("modelName"))
#define satipModelURL(self)                       satipObjectPropGet (self, SLIM_T("modelURL"))
#define satipModelDescription(self)               satipObjectPropGet (self, SLIM_T("modelDescription"))
#define satipModelNumber(self)                    satipObjectPropGet (self, SLIM_T("modelNumber"))
#define satipSerialNumber(self)                   satipObjectPropGet (self, SLIM_T("serialNumber"))
#define satipTXTVersion(self)                     satipObjectPropGet (self, SLIM_T("TXTVersion"))
#define satipPresentationURL(self)                satipObjectPropGet (self, SLIM_T("presentationURL"))

#endif

/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/

/*!
\par Function:
Function sets friendly name on SATIP device.
\par Parameters:
<table>
  <tr>
    <td>[in]</td>
    <td>self</td>
    <td>SATIP instance</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_home_path</td>
    <td>New friendly name to set</td>
  </tr>
</table>

\return SATIP_E_OK Succeeded
\return SATIP_E_INVAL Invalid argument(s) specified
\return SATIP_E_GENERIC Generic error occurred
\par Description:
Function sets friendly name on SATIP device.
*/
DLNA_API slim_int
satipSetFriendlyName (TSATIP self, slim_char *in_friendly_name);

/*!
\par Function:
Function gets friendly name of device.
\par Parameters:
<table>
  <tr>
    <td>[in]</td>
    <td>self</td>
    <td>SATIP instance</td>
  </tr>
</table>

\return pointer to string containing device friendly name
\return slim_nil if failed
\par Description:
Function gets friendly name of device specyfied by self.
*/
DLNA_API slim_char *
satipGetFriendlyName (TSATIP self);

/*@}*/
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_SATIP_API_H */
