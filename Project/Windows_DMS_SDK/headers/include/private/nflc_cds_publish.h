/*
 * nflc_cds_publish.h
 * Copyright (C) 2014 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */


#ifndef NFLC_CDS_PUBLISH_API_H_
#define NFLC_CDS_PUBLISH_API_H_

#include <dlna_peer.h>
#include <nflc_drm_api.h>
#include <info_media.h>

#define URI_SPECIFIER "$stream"

#define CONTENT_ALLOWED_OUTPUT_TYPE_CLEAR           0
#define CONTENT_ALLOWED_OUTPUT_TYPE_DTCP            (1 << 0)
#define CONTENT_ALLOWED_OUTPUT_TYPE_DRM             (1 << 1)
#define CONTENT_ALLOWED_OUTPUT_TYPE_CA              (1 << 2)
#define CONTENT_ALLOWED_OUTPUT_TYPE_DHCP            (1 << 3)


enum {
  CONTENT_ENCRYPTION_TYPE_NONE,
  CONTENT_ENCRYPTION_TYPE_DRM,
  CONTENT_ENCRYPTION_TYPE_CA
};
typedef slim_int contentEncryptionType;

enum {
  STREAM_TYPE_LOCAL,
  STREAM_TYPE_LIVE,
  STREAM_TYPE_RECORDED,
  STREAM_TYPE_ONLINE
};
typedef slim_int streamType;

enum {
  CONTENT_RESOURCE_TYPE_ORIGINAL,
  CONTENT_RESOURCE_TYPE_SUBTITLE,
  CONTENT_RESOURCE_TYPE_THUMBNAIL,
  CONTENT_RESOURCE_TYPE_TRANSCODED
};
typedef slim_int contentResType;

enum {
  CONTENT_SOURCE_BUFFER_WRITE = 1,
  CONTENT_SOURCE_HTTP_READ,
  CONTENT_SOURCE_FILE_READ
};
typedef slim_int contentSource;

struct objectRights {
  slim_int allowedOutputType;
  minfo_drm_cci dtcpcci;
  slim_word concurrentViewingCount;
  slim_word playCount;
  slim_word noOfDevicesAllowed;
};
typedef struct objectRights objectRights_t;


struct cImgRes {
  slim_word width;
  slim_word height;
};
typedef struct cImgRes cImgRes_t;

struct cAudioRes {
  slim_word maxBitrate;
  slim_word avgBitrate;
  slim_word nrChannels;
  slim_word samplingRate;
  slim_word profile;
  slim_word level;
  slim_char *codecName;
  slim_char *durationString;

};
typedef struct cAudioRes cAudioRes_t;

struct cVideoRes {
  slim_word width;
  slim_word height;
  slim_word avgBitrate;
  slim_word maxBitrate;
  slim_char *frameRate;
  slim_char *par;
  slim_char *dar;
  slim_char *region;
  slim_bool have_ifo;
  slim_word profile;
  slim_word level;
  slim_char *codecName;
  slim_char *durationString;
};
typedef struct cVideoRes cVideoRes_t;

struct contentResource {
  struct contentResource *prev;
  struct contentResource *next;
  slim_char *resId;
  contentResType resType;
  contents_type_t resContentType;
  contentSource source;
  slim_char *mime;
  slim_char *resUrl;
  slim_char *x_url;
  slim_char *extension;
  slim_char *pinfo_str;
  objectRights_t *objectRights;
  cImgRes_t *imageInfo;
  cAudioRes_t *audioInfo;
  cVideoRes_t *videoInfo;
};
typedef struct contentResource contentResource_t;

typedef struct contents_manager cm_t;
typedef struct contents contents_t;

void
contents_publish_content_free(contents_t *c);

slim_bool
contents_set_non_local_stream_uri(contents_t *c, slim_int ifindex, slim_word flags);

slim_bool
contents_publish_set_resource_uri(contents_t *c, slim_int ifindex, slim_word flags, contentResource_t* res);

slim_char*
contents_publish_get_stream_type(contents_t *c);

contents_t *
contents_publish_lookup_by_name(cm_t *cm, slim_char *name);

contents_t *
contents_lookup_by_ext_id(cm_t *cm, slim_char *id);

slim_char*
contents_publish_get_mime_by_url(contents_t *c, slim_char *url);

slim_char*
contents_publish_get_x_url_by_url(contents_t *c, slim_char *url);

dlna_time_t
contents_publish_get_mtime(contents_t *c);

void
contents_publish_get_filesize(contents_t *c, dlna_uint64 *out_size);

slim_int
contents_publish_get_source_by_url(contents_t *c, slim_char *url);

slim_char*
contents_publish_get_segment_url(contents_t *c, slim_char* http_url);

#endif /*NFLC_CDS_PUBLISH_API_H_*/
