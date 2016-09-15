/*
* ca_ctl.h
* Copyright (C) 2015 ACCESS CO.,LTD.
* All rights are reserved by ACCESS CO.,LTD.,
* whether the whole or part of the source code
* including any modifications is concerned.
*
* This is an unpublished source code of ACCESS CO.,LTD., and must be
* treated as confidential material.  The above copyright notice does
* not evidence any actual or intended publication of this source code.
*/

#include <dlna_peer.h>
#include <content_aggregation.h>

#ifndef CA_CTL_H
#define CA_CTL_H

/* TODO
 * Similar constants appear in parental_guidance.h
 * To be unified later.
 */
#define CA_MAX_DESCRIPTION_LEN          256

#define CA_XML_TAG_DEVICELIST           "contentAggregationDeviceList"
#define CA_XML_TAG_DEVICEITEM           "device"
#define CA_XML_TAG_ID                   "uuid"
#define CA_XML_TAG_DEVICEINDEX          "index"
#define CA_XML_TAG_DEVICEFRIENDLYNAME   "friendlyName"
#define CA_XML_ATTR_DEVICEINDEX         "defaultDeviceIndexValue"

#define CA_DEVICE_INDEX_ENABLED         1
#define CA_DEVICE_INDEX_DISABLED        0
#define CA_DEFAULT_DEVICE_INDEX_VALUE   CA_DEVICE_INDEX_ENABLED

#define CA_XML_HEADER "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"

#define DMS_CA_DEVICES_LIST_FILE        "ca_device_list.xml"

/* Example XML
 * <?xml version="1.0" encoding="utf-8"?>
 * <contentAggregationDeviceList defaultDeviceIndexValue="1">
 *   <device>
 *     <uuid>0622707c-da97-4286-cafe-001ff3590148</uuid>
 *     <friendlyName>1st server</friendlyName>
 *     <deviceDescription>some description</deviceDescription>
 *     <index>0</index>
 *   </device>
 * </contentAggregationDeviceList>
 */

/* Structure holding information about one device from internal list in CA control.
 * Structure is designed to be used from stack.
 */
typedef struct _ca_dev
{
  struct _ca_dev *prev;
  struct _ca_dev *next;

  slim_int  index;    /*! device indexing value */
  slim_char *name;    /*! device friendly name */
  slim_char *uuid;    /*! device uuid */

  /* TODO
   * Add support for deleting not used device on list.
   * 1 = delete the device entry, 0 = don't delete
   */
  /* slim_int  dev_delete; */
} ca_dev_t;

/*
 * This structure holds some basic info about the CA.
 * Can be used to check default index value, newly connected device and dms.
 */
typedef struct _ca_ctl
{
  ca_t ca; /* Handle to CA structure */

  List(ca_dev_t *)  dev_list;
  slim_int          index;              /* Slave DMS default indexing mode */
  slim_char         *xml_path;          /* Path where xml is write */
} ca_ctl_t;

ca_ctl_t *
ca_ctl_alloc (ca_t in_ca);

void
ca_ctl_free (ca_ctl_t *in_ctl);

slim_int
ca_read_ctl_file (ca_ctl_t *inout_ctl, slim_char *in_path,
                  slim_char *in_name);

slim_int
ca_write_ctl_file (ca_ctl_t *in_ctl, slim_char *in_path);

ca_dev_t *
ca_ctl_dev_alloc (void);

slim_int
ca_ctl_dev_add (ca_ctl_t *in_ctl, ca_dev_t *in_dev);

#endif /* CA_CTL_H */
