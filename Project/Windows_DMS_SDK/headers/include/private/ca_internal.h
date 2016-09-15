/*
* ca_internal.h
* Copyright (C) 2015 ACCESS CO.,LTD.
* All rights are reserved by ACCESS CO.,LTD.,
* whether the whole or part of the source code
* including any modifications is concerned.
*
* This is an unpublished source code of ACCESS CO.,LTD., and must be
* treated as confidential material.  The above copyright notice does
* not evidence any actual or intended publication of this source code.
*/

#ifndef CA_INTERNAL_H
#define CA_INTERNAL_H

#define content_aggregation_prop_title(obj)         \
  dlna_object_prop_get (obj, SLIM_T("dc:title"), slim_nil)
#define content_aggregation_prop_creator(obj)       \
  dlna_object_prop_get (obj, SLIM_T("dc:creator"), slim_nil)
#define content_aggregation_prop_date(obj)          \
  dlna_object_prop_get (obj, SLIM_T("dc:date"), slim_nil)
#define content_aggregation_prop_class(obj)         \
  dlna_object_prop_get (obj, SLIM_T("upnp:class"), slim_nil)
#define content_aggregation_prop_artist(obj)        \
  dlna_object_prop_get (obj, SLIM_T("upnp:artist"), slim_nil)
#define content_aggregation_prop_album(obj)         \
  dlna_object_prop_get (obj, SLIM_T("upnp:album"), slim_nil)
#define content_aggregation_prop_genre(obj)         \
  dlna_object_prop_get (obj, SLIM_T("upnp:genre"), slim_nil)
#define content_aggregation_prop_albumArtURI(obj)   \
  dlna_object_prop_get (obj, SLIM_T("upnp:albumArtURI"), slim_nil)
#define content_aggregation_prop_uuid(obj)          \
  dlna_object_prop_get (obj, SLIM_T("UDN"), slim_nil)
#define content_aggregation_prop_name(obj)          \
  dlna_object_prop_get (obj, SLIM_T("friendlyName"), slim_nil)
#define content_aggregation_prop_id(obj)            \
  dlna_object_prop_get (obj, slim_nil, SLIM_T("id"));
#define content_aggregation_prop_refID(obj)         \
  dlna_object_prop_get (obj, slim_nil, SLIM_T("refID"));
#define content_aggregation_prop_parentID(obj)      \
  dlna_object_prop_get (obj, slim_nil, SLIM_T("parentID"));
#define content_aggregation_prop_restricted(obj)    \
  dlna_object_prop_get (obj, slim_nil, SLIM_T("restricted"));
#define content_aggregation_prop_child_count(obj)   \
  dlna_object_prop_get (obj, slim_nil, SLIM_T("childCount"));
#define content_aggregation_prop_searchable(obj)    \
  dlna_object_prop_get (obj, slim_nil, SLIM_T("searchable"));
#define content_aggregation_prop_dlna_managed(obj)  \
  dlna_object_prop_get (obj, slim_nil, SLIM_T("dlna:dlnaManaged"));
#define content_aggregation_prop_device_model_name(obj)  \
  dlna_object_prop_get (obj, SLIM_T("modelName"), slim_nil);

#define MAX_ERR_COUNT_PER_DMS   3
#define CONTENT_AGGREGATION_RCOUNT (250)

#define CA_SEARCH_CRITERIA_ALL "upnp:class derivedfrom \"object.item\" and @refID exists false"
#define CA_SEARCH_CRITERIA_CLASS "upnp:class derivedfrom \"object.item\""
#define CA_SEARCH_CRITERIA_REFID "@refID exists false"

#define CA_DATABASE_NAME  "content_aggregation.db"

#define DC_DATE_FORMAT "%d-%d-%dT%d:%d:%d"

#define DMS_EXCEPTION_WDMYCLOUD "WDMyCloud"

#endif /* CA_INTERNAL_H */
