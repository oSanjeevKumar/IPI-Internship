/*
 * dms_srs.h
 * Copyright (C) 2008 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2005 IP Infusion, Inc. All Rights Reserved.  */

#ifndef NFLC_DMS_SRS_H
#define NFLC_DMS_SRS_H

#include <upnp_srs.h>

#ifdef DLNA_SUPPORT_SRS

#define DMS_SRS_CREATERECORDSCHEDULED_RESPONSE    \
	                          "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" \
                               "<srs"                                     \
                                " xmlns=\"urn:schemas-xsrs-org:av:srs\""  \
                                " xmlns:xsi="          \
                                "\"http://www.w3.org/2001/XMLSchema-instance\""   \
                                " xsi:schemaLocation=\""   \
                                     "urn:schemas-xsrs-org:av:srs"              \
                                     "http://www.upnp.org/schemas/av/srs-v1-20060531.xsd\">"    \
                             "<item id=\"s101\">"  \
                            "<title>BBC News at 7pm</title>"       \
                            "<mediaRemainAlertID>1</mediaRemainAlertID>"   \
                            "<scheduledStartDateTime>T19:00:00</scheduledStartDateTime>"          \
                            "<scheduledDuration>P01:00:00</scheduledDuration>"           \
                            "<scheduledChannelID broadcastingType=\"1\" channelType=\"2\">CCTV-1</scheduledChannelID>"  \
                            "<priorityFlag>1</priorityFlag>"  \
                         "</item> "  \
                         "</srs>"   

 
#define DMS_SRS_BROWSERECORDSCHEDULED_RESPONSE   \
"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"  \
"<srs "  \
" xmlns=\"urn:schemas-xsrs-org:av:srs\"" \
" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\""   \
" xsi:schemaLocation=\""   \
"urn:schemas-xsrs-org:av:srs"  \
"http://www.upnp.org/schemas/av/srs-v1-20060531.xsd\">"  \
"<item id=\"s101\">"   \
"<title>About SRS</title>"  \
"<scheduledStartDateTime>T19:00:00</scheduledStartDateTime>"          \
"<scheduledDuration>P01:00:00</scheduledDuration>"           \
"<scheduledChannelID broadcastingType=\"1\" channelType=\"2\">CCTV-1</scheduledChannelID>"  \
"<desiredQualityMode>L1</desiredQualityMode>"  \
"<recordDestinationID>2100</recordDestinationID>" \
"</item>"  \
"<item id=\"s102\">"  \
"<title>BBC News at 7pm</title>"  \
"<scheduledStartDateTime>T21:00:00</scheduledStartDateTime>"          \
"<scheduledDuration>P01:00:00</scheduledDuration>"           \
"<scheduledChannelID broadcastingType=\"3\" channelType=\"4\">JSWS</scheduledChannelID>"  \
"<desiredQualityMode>L2</desiredQualityMode>"  \
"<recordDestinationID>2101</recordDestinationID>" \
"</item>" \
"</srs>"   


/* Scheduled Recording service.  */
struct dms_srs
{
  /* DMS service base structure.  */
  struct dms_service base;
	
	upnp_srs* upnp_srs;

};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus__ */

struct dms_service *
dms_srs_alloc (struct dms *top);

void
dms_srs_free (struct dms_service *s);

#endif /* DLNA_SUPPORT_SRS */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_DMS_SRS_H */
