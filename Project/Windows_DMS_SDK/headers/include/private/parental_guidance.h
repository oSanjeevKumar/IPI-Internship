/*
* parental_control.h
* Copyright (C) 2009 ACCESS CO.,LTD.
* All rights are reserved by ACCESS CO.,LTD.,
* whether the whole or part of the source code
* including any modifications is concerned.
*
* This is an unpublished source code of ACCESS CO.,LTD., and must be
* treated as confidential material.  The above copyright notice does
* not evidence any actual or intended publication of this source code.
*/

#ifndef _PARENTAL_GUIDANCE_H
#define _PARENTAL_GUIDANCE_H

#include <dlna_config.h>
#include <dlna_app_config.h>
#include <peer_plat.h>
#include <dlna_peer.h>
#include <dlna_api.h>
#include <dlna_peer_list.h>


#define PC_MAX_DESCRIPTION_LEN       256
#define PC_MAX_MAC_ADDRESS_LEN        24

#define PC_XML_TAG_DEVICELIST           "parentalGuidanceDeviceList"
#define PC_XML_TAG_DEVICEITEM           "device"
#define PC_XML_TAG_DEVICEMACADDR        "mac_address"
#define PC_XML_TAG_DEVICEIPADDR         "ip_address"
#define PC_XML_TAG_DEVICEFRIENDLYNAME   "friendly_name"
#define PC_XML_TAG_DEVICEUSERAGENT      "user_agent"
#define PC_XML_TAG_DEVICELEVEL          "level"
#define PC_XML_TAG_DEVICEDESCRIPTION    "device_description"
#define PC_XML_TAG_DEVICELOCATIONURL    "device_locationURL"
#define PC_XML_TAG_DEVICELOCATIONUSN    "usn"
#define PC_XML_TAG_LEVELLIST            "parentalGuidanceLevelList"
#define PC_XML_TAG_LEVEL                "level"
#define PC_XML_TAG_ID                   "id"
#define PC_XML_TAG_NAME                 "name"
#define PC_XML_TAG_DESCRIPTION          "description"

#define PC_XML_ATTR_DEVICELEVEL  "defaultDeviceLevel"
#define PC_XML_ATTR_CONTENTLEVEL "defaultContentLevel"

#define PARENTAL_GUIDANCE_BLOCK_LEVEL 0
#define PARENTAL_GUIDANCE_DEFAULT_BLOCK_LEVEL_NAME "Disable"
#define PARENTAL_GUIDANCE_DEFAULT_BLOCK_LEVEL_DESCRIPTION "Block this device"

#define PARENTAL_GUIDANCE_LOWEST_LEVEL 1
#define PARENTAL_GUIDANCE_DEFAULT_LOWEST_LEVEL_NAME "Enable"
#define PARENTAL_GUIDANCE_DEFAULT_LOWEST_LEVEL_DESCRIPTION "Unblock this device"

#define XML_HEADER "<?xml version=\"1.0\" encoding=\"utf-8\"?>\r\n"

#ifndef DEFAULT_PARENTAL_GUIDANCE_DEVICE_LEVEL
#define DEFAULT_PARENTAL_GUIDANCE_DEVICE_LEVEL	PARENTAL_GUIDANCE_LOWEST_LEVEL
#endif /* DEFAULT_PARENTAL_GUIDANCE_DEVICE_LEVEL */

#ifndef DEFAULT_PARENTAL_GUIDANCE_CONTENT_LEVEL
#define DEFAULT_PARENTAL_GUIDANCE_CONTENT_LEVEL	PARENTAL_GUIDANCE_LOWEST_LEVEL
#endif /* DEFAULT_PARENTAL_GUIDANCE_CONTENT_LEVEL */

struct upnp_server;
struct _sXML;
struct _dlna_ip_addr;

/*! \struct sub_device_info
 * \brief Structure holding device information that can occur multiple times.
 *
 * Structure is designed to be used from stack.
 */
typedef struct sub_device_info {
	struct sub_device_info* next;
	struct sub_device_info* prev;

    slim_char *location_url;	/*! device location url */
    slim_char *usn;				/*! device location usn */
} sub_device_info_t;

/*! \struct parental_guidance_level_info
 * \brief Structure holding information about one device from internal list in parental control.
 *
 * This structure creates interface to Http server, allows to exchange infromation between web UI and dms.
 * Structure is designed to be used from stack.
 */
typedef struct parental_guidance_level_info {
	struct parental_guidance_level_info* next;
	struct parental_guidance_level_info* prev;

	slim_int  parental_guidance_level;	/*! parental guidance level */
    slim_char *name;     	/*! level name */
    slim_char *description;	/*! level description */
} parental_guidance_level_info_t;

/*! \struct parental_control_device
 * \brief Structure holding information about one device from internal list in parental control.
 *
 * This structure creates interface to Http server, allows to exchange infromation between web UI and dms.
 * Structure is designed to be used from stack.
 */
typedef struct parental_control_device
{
	struct parental_control_device* next;
	struct parental_control_device* prev;

    slim_char *desc;		/*! device description */
    slim_char *mac_addr;	/*! device MAC address */
    slim_int  access_level;	/*! device access level */
    slim_int  dev_delete;	/*! 1 = delete the device entry, 0 = don't delete */
    slim_int socket_descriptor;
    slim_char *ip_addr;         /*! device IP address */
    slim_char *friendly_name;   /*! device friendly name */
    slim_char *user_agent;      /*! device user agent */
    List(sub_device_info_t *) sub_device_info;	/*! sub device information */
} parental_control_device_t;

/*! \struct parental_control
 * \brief Structure holding internal parental control information.
 *
 * This structure holds some basic info about the parental control. Can be used to check default
 * levels assigned to content, newly connected device and dms.
 * This is a struct is allocated, it's assigned to UPnP server by us->pc pointer.
 */
typedef struct parental_control
{
    struct upnp_server *us; // handle to parent structure

    List(parental_guidance_level_info_t *) level_list;
    List(parental_control_device_t *) connected_device_list;

    slim_int default_client_level; /*! default client acces level */
    slim_int default_content_level; /*! default content access level */
} parental_control_t;




/*! \fn parental_control_t* parental_guidance_alloc(struct upnp_server* us);
 * \par FUNCTION
 *
 * Initializes Memory allocations for parental control.
 *
 * \par INPUT ARGUMENTS
 *
 * \param us UPNP server structure
 *
 * \par OUTPUT ARGUMENTS
 *
 * None
 *
 * \par RETURN VALUES
 *
 * parental_control_t*       Succeeded, 
 *                           pointer to initialized parental control structure
 *                           is returned
 *
 * slim_nil                  Failed
 *
 * \par DESCRIPTION
 *
 * All the parental control related initialzations are done here. It initializes memory,
 * reads xml files related to parental control and fills parental control structures.
 *
 */
parental_control_t*
parental_guidance_alloc(struct upnp_server* us);

/*! \fn void parental_guidance_free(struct parental_control *pc);
 * \par FUNCTION
 *
 * Releaes memory allocated for parental control.
 *
 * \par INPUT ARGUMENTS
 *
 * \param pc Pointer to parental control structure
 *
 * \par OUTPUT ARGUMENTS
 *
 * None
 *
 * \par RETURN VALUES
 *
 * None
 *
 * \par DESCRIPTION
 *
 * All parental control related memory is released here.
 *
 */
void 
parental_guidance_free(struct parental_control *pc);

/*! \fn slim_bool parental_control_new_client(parental_control_t* pc, dlna_ip_addr *in_addr);
 * \par FUNCTION
 *
 * Manages incomming connection from client, does authorization on TPC/IP level.
 *
 * \par INPUT ARGUMENTS
 *
 * \param pc Pointer to parental control structure
 * \param in_addr Pointer to incomming client IP
 *
 * \par OUTPUT ARGUMENTS
 *
 * None
 *
 * \par RETURN VALUES
 *
 * slim_true        Succeeded
 *
 * slim_false       Failed
 *
 * \par DESCRIPTION
 *
 * Function is responsible for a filtering incomming connections on TCP/IP
 * level. If connected client is unknown to dms, it's added pc_devices.xml
 * with default client level.
 *
 */
slim_bool 
parental_control_new_client(parental_control_t* pc, struct _dlna_ip_addr *in_addr);

/*! \fn slim_int parental_control_get_client_level(parental_control_t* pc, slim_int socket_id);
 * \par FUNCTION
 *
 * Retrieves access level assigned to connected client.
 *
 * \par INPUT ARGUMENTS
 *
 * \param pc Pointer to parental control structure
 * \param socket_id Socket used to communication
 *
 * \par OUTPUT ARGUMENTS
 *
 * None
 *
 * \par RETURN VALUES
 *
 * any value >= 0 is valid access_level for connected 
 *
 * value < 0 means error (usualy (-1))
 *
 * \par DESCRIPTION
 *
 * Function performs search in devices list and retrives 
 * level. If connected client is unknown to dms, it's added pc_devices.xml
 * with default client level.
 *
 */
slim_int 
parental_control_get_client_level(parental_control_t* pc, slim_int socket_id);

/*! \fn slim_bool parental_control_get_first_entry(parental_control_t* pc, parental_control_device_t* pc_device);
 * \par FUNCTION
 *
 * Retrieves first entry from connected device list.
 *
 * \par INPUT ARGUMENTS
 *
 * \param pc Pointer to parental control structure
 *
 * \par OUTPUT ARGUMENTS
 *
 * \param pc_device pointer to structure describing device
 *
 * \par RETURN VALUES
 *
 * slim_true        Succeed, pc_device is filled with list entry data
 * 
 * slim_false       Failed, pc_device is undefined
 *
 * \par DESCRIPTION
 *
 * Function creates a interface to web server server facility.
 * Structure pc_devices is filled with data retrived from 
 * first entry of parental control internal devices list.
 * Next extries could be retrived using parental_control_get_next_entry()
 * All error conditions are returned as slim_false. If slim_false is retruned,
 * parental_control_get_next_entry() function shouldn't be used.
 *
 */
slim_bool
parental_control_get_first_entry(parental_control_t* pc, parental_control_device_t* pc_device);

/*! \fn slim_bool parental_control_get_next_entry(parental_control_t* pc, parental_control_device_t* prev_device, parental_control_device_t* pc_device);
 * \par FUNCTION
 *
 * Retrieves first entry from connected device list.
 *
 * \par INPUT ARGUMENTS
 *
 * \param pc Pointer to parental control structure
 * \param prev_device pointer to structure describing  previously retrived device entry
 *
 * \par OUTPUT ARGUMENTS
 *
 * \param pc_device pointer to structure describing device
 *
 * \par RETURN VALUES
 *
 * slim_true        Succeed, pc_device is filled with list entry data
 * 
 * slim_false       Failed, pc_device is undefined, it's last entry or error occured
 *
 * \par DESCRIPTION
 *
 * Function creates a interface to web server server facility.
 * Structure pc_devices is filled with data retrived from 
 * entry next to prev_device entry on parental control internal devices list.
 * Next extries could be retrived using subsequent calls to parental_control_get_next_entry()
 * All error conditions return slim_false. If slim_false is retruned in prevoius call,
 * parental_control_get_next_entry() function shouldn't be called anymore.
 *
 */
slim_bool
parental_control_get_next_entry(parental_control_t* pc, const parental_control_device_t* prev_device, parental_control_device_t* pc_device);

/*! \fn slim_bool parental_control_set_entry(parental_control_t* pc, parental_control_device_t* pc_device);
 * \par FUNCTION
 *
 * Updates entries on internal parental control list with provided data  
 *
 * \par INPUT ARGUMENTS
 *
 * \param pc Pointer to parental control structure
 * \param pc_device pointer to structure describing updated device entry, mac_addr field should contain valid MAC address
 *
 * \par OUTPUT ARGUMENTS
 *
 * None
 *
 * \par RETURN VALUES
 *
 * slim_true        Succeed, entry has been updated
 * 
 * slim_false       Failed, entry hasn't been changed
 *
 * \par DESCRIPTION
 *
 * Function creates a interface to web server server facility.
 * Structure pc_devices contains data to update entry described by MAC address.
 * Next extries could be updated using subsequent calls to parental_control_set_entry()
 * with approperiate data.
 * All error conditions return slim_false. If slim_false is retruned,
 * parental_control_set_entry() function shouldn't be called anymore.
 *
 */
slim_bool
parental_control_set_entry(parental_control_t* pc, const parental_control_device_t* pc_device);

/*! \fn slim_bool parental_control_update_entries(parental_control_t *pc);

 * \par FUNCTION
 *
 * Does synchronization between parental control and pc_devices.xml 
 *
 * \par INPUT ARGUMENTS
 *
 * \param pc Pointer to parental control structure
 *
 * \par OUTPUT ARGUMENTS
 *
 * None
 *
 * \par RETURN VALUES
 *
 * slim_true        Succeed
 * 
 * slim_false       Failed
 *
 * \par DESCRIPTION
 *
 * Function creates a interface to web server server facility.
 * It updates pc_device.xml file with data from internal parental control
 * structures. Call to this function is neccessery to make changes
 * from web interface persistent.
 *
 */
slim_bool
parental_control_update_entries(parental_control_t *pc);

slim_int
parental_guidance_get_device_level_by_socket_descriptor(parental_control_t* in_parental_guidance, slim_int in_socket_decriptor);

parental_guidance_level_info_t *
parental_guidance_get_first_level(const parental_control_t *in_parental_guidance);

parental_guidance_level_info_t *
parental_guidance_get_next_level(parental_control_t *in_parental_guidance, const parental_guidance_level_info_t* in_level_info);

slim_int
parental_guidance_get_level_count(parental_control_t *in_parental_guidance);

parental_control_device_t *
parental_guidance_get_first_connected_device(parental_control_t *in_parental_guidance);

parental_control_device_t *
parental_guidance_get_next_connected_device(parental_control_t *in_parental_guidance, const parental_control_device_t *in_level_info);

slim_int
parental_guidance_get_connected_device_count(parental_control_t *in_parental_guidance);

slim_int
parental_guidance_device_authentication_by_ip_address(parental_control_t* in_parental_guidance, dlna_ip_addr *in_address, slim_int in_socket_descriptor, slim_char *in_mac_addr);

slim_bool
parental_guidance_device_authentication_by_socket_descriptor(parental_control_t* in_parental_guidance, slim_int in_socket_descriptor);


slim_bool
parental_guidance_set_connected_device(parental_control_t *in_parental_guidance, const parental_control_device_t *in_connected_device_info);

slim_int
parental_guidance_get_default_client_level(parental_control_t *in_parental_guidance);

slim_bool
parental_guidance_set_default_client_level(parental_control_t *in_parental_guidance, slim_int in_new_default_level);

slim_int
parental_guidance_get_default_content_level(parental_control_t *in_parental_guidance);

slim_bool
parental_guidance_set_default_content_level(parental_control_t *in_parental_guidance, slim_int in_new_default_level);

parental_control_device_t *
parental_guidance_get_connected_device_by_mac_address(parental_control_t *in_parental_guidance, const slim_char *in_device_mac_address);

parental_control_device_t *
parental_guidance_get_connected_device_by_socket_descriptor(parental_control_t *in_parental_guidance, const slim_int in_socket_descriptor);

slim_bool
parental_guidance_delete_device_by_mac_address(parental_control_t *in_parental_guidance, const slim_char *in_device_mac_address);

slim_bool
parental_guidance_delete_device(parental_control_t *in_parental_guidance, parental_control_device_t *in_parental_guidance_device);

parental_control_device_t *
parental_guidance_alloc_device(void);

slim_bool
parental_guidance_free_device(parental_control_device_t *in_device);

parental_guidance_level_info_t *
parental_guidance_alloc_level(void);

slim_bool
parental_guidance_free_level(parental_guidance_level_info_t *in_level);

slim_char *
parental_guidance_device_get_description(parental_control_device_t *in_parental_guidance_device);

slim_bool
parental_guidance_device_set_description(parental_control_t *in_parental_guidance, parental_control_device_t *in_parental_guidance_device, slim_char *in_description);

slim_char *
parental_guidance_device_get_ip_address(parental_control_device_t *in_parental_guidance_device);

slim_bool
parental_guidance_device_set_ip_address(parental_control_t *in_parental_guidance, parental_control_device_t *in_parental_guidance_device, slim_char *in_ip_address);

slim_char *
parental_guidance_device_get_friendly_name(parental_control_device_t *in_parental_guidance_device);

slim_bool
parental_guidance_device_set_friendly_name(parental_control_t *in_parental_guidance, parental_control_device_t *in_parental_guidance_device, slim_char *in_friendly_name);

slim_char *
parental_guidance_device_get_user_agent(parental_control_device_t *in_parental_guidance_device);

slim_bool
parental_guidance_device_set_user_agent(parental_control_t *in_parental_guidance, parental_control_device_t *in_parental_guidance_device, slim_char *in_user_agent);

slim_int
parental_guidance_device_get_level(parental_control_device_t *in_parental_guidance_device);

slim_bool
parental_guidance_device_set_level(parental_control_t *in_parental_guidance, parental_control_device_t *in_parental_guidance_device, slim_int in_level);

slim_bool
parental_guidance_device_set_location_url(parental_control_t *in_parental_guidance, parental_control_device_t *in_parental_guidance_device, slim_char *in_location_url, slim_char *in_usn);

slim_int
parental_guidance_get_location_url_count(parental_control_device_t *in_parental_guidance_device);

sub_device_info_t *
parental_guidance_device_get_fist_location_url(parental_control_device_t *in_parental_guidance_device );

sub_device_info_t *
parental_guidance_device_get_next_location_url(parental_control_device_t *in_parental_guidance_device, const sub_device_info_t *in_parental_guidance_sub_device);

slim_bool
parental_guidance_device_append(parental_control_t *in_parental_guidance, parental_control_device_t *in_parental_guidance_device);

slim_char *
parental_guidance_device_get_mac_address(parental_control_device_t *in_parental_guidance_device);

slim_bool
parental_guidance_device_set_mac_address(parental_control_t *in_parental_guidance, parental_control_device_t *in_parental_guidance_device, slim_char *in_mac_address);

slim_int
parental_guidance_level_get_id(parental_guidance_level_info_t *in_parental_guidance_level);

slim_bool
parental_guidance_level_set_id(parental_control_t *in_parental_guidance, parental_guidance_level_info_t *in_parental_guidance_level, slim_int in_level);

slim_char *
parental_guidance_level_get_name(parental_guidance_level_info_t *in_parental_guidance_level);

slim_bool
parental_guidance_level_set_name(parental_control_t *in_parental_guidance, parental_guidance_level_info_t *in_parental_guidance_level, slim_char *in_name);

slim_char *
parental_guidance_level_get_description(parental_guidance_level_info_t *in_parental_guidance_level);

slim_bool
parental_guidance_level_set_description(parental_control_t *in_parental_guidance, parental_guidance_level_info_t *in_parental_guidance_level, slim_char *in_description);
#endif /* _PARENTAL_GUIDANCE_H */

