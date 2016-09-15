/*
 * publish_xml_content.h
 * Copyright (C) 2009-2014 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2012 Access Company, All Rights Reserved.  */

#ifndef PUBLISH_XML_CONTENT_H
#define PUBLISH_XML_CONTENT_H

struct _PublishContentThreadParam {
  void *dms;
  slim_char *v_local_xml_path;
  slim_char *v_online_xml_path;
  slim_char *live_content_xml_path;
};

typedef struct _PublishContentThreadParam PublishContentThreadParam;

typedef struct _ConvertParamsTable {
  slim_int from;
  slim_int to;
} convert_params_table;

slim_int
publish_content_by_xml (struct dms *self, slim_char* xml_path);

slim_int
publish_content_thread (void *argv);

#endif /* PUBLISH_XML_CONTENT_H */
