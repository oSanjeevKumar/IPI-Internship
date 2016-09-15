/*
 * mpe_client.h
 * Copyright (C) 2014 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef MPE_CLIENT_H
#define MPE_CLIENT_H

#ifdef MEDIA_PROCESSING_EXTENSION

#include <info_media.h>
/*
 * <?xml version="1.0" encoding="utf-8"?>  
 * <command>
 *   <name>SOME COMMAND</name>
 *   <param>1</param>
 *   <param>2</param>
 *       ...
 *   <param>n-th</param>
 * 
 * </command>
 */

#define PROFILE_COMMAND_SEND                      \
SLIM_T(                                           \
"<?xml version=\"1.0\" encoding=\"utf-8\"?>\r\n"  \
"<command>\n"                                     \
"</command>")                                     

/* internal SMDM client structure */
typedef struct 
{
  int s_client;
} SMDMC;

typedef enum 
{
  SMDMC_OK = 0,
  SMDMC_ERROR,
  SMDMC_IO_ERR,
  SMDMC_CONNECT_ERR,
  SMDMC_EMPTY_METADATA_ERR,
  
 // left this element unchanged
  SMDMC_ERROR_LEN,
} SMDMC_error;

#define SMDMC_INVALID_FILE      (-1)

typedef enum {
  SMDMC_CMD_GET_METADATA,
  SMDMC_CMD_CREATE_THUMBNAIL,


#ifdef DEVELOPMENT_MATROSKA_EMBEDED_ALBUM_ART

  SMDMC_CMD_EXTRACT_ATTACHMENT,

#endif /* DEVELOPMENT_MATROSKA_EMBEDED_ALBUM_ART */


  SMDMC_CMD_TIME_SEEK,
	SMDMC_CMD_GET_GPSDATA,
	SMDMC_CMD_CHANGE_SCHEDULING,
	SMDMC_CMD_TRANSCODE_IMAGE,
	SMDMC_CMD_TRANSCODE_AV,
  
 // left this element unchanged
  SMDMC_COMMAND_LEN
} SMDMC_command;

typedef enum {
	SMDMC_MEDIA_TYPE_IMAGE = 0,
  SMDMC_MEDIA_TYPE_VIDEO,
	SMDMC_MEDIA_TYPE_UNKNOWN
} SMDMC_mediatype;

/*Union containing SMDMC command parameters*/
typedef union {
  struct {
    slim_char *path;
    minfo_t   *info;
    slim_char *source_pinfo_str;
  } get_metadata;
 
  struct {
    slim_char *media_path;
		slim_char *thumbnail_path;
		SMDMC_mediatype media_type;
		slim_word minimum_time;
		slim_word minimum_percentage;
  } create_thumbnail;
  

#ifdef DEVELOPMENT_MATROSKA_EMBEDED_ALBUM_ART

  struct {
    slim_char * media_path;
    slim_char * attachment_path;
    slim_word stream_index;
  } extract_attachment;

#endif /* DEVELOPMENT_MATROSKA_EMBEDED_ALBUM_ART */


  struct {
    slim_char *path;
    slim_int  start_time;
    slim_int  end_time;
    dlna_uint64 *start_bytes;
    dlna_uint64 *end_bytes;
  } time_seek;

  struct {
    enum dlna_thread_policy policy;
    slim_int priority;
  } change_scheduling;

  #ifdef ENABLE_MPE_IMAGE_TRANSCODING
    struct {
      slim_char *path;
      slim_char *output;
      slim_char *profile;
      slim_int width;
      slim_int height;
    } transcode_image;
  #endif /* ENABLE_MPE_IMAGE_TRANSCODING */

  #ifdef ENABLE_MPE_AUDIO_VIDEO_TRANSCODING
    struct {
      slim_char *path;
      slim_char *output;
      slim_char *type;
      slim_char *norm;
    } transcode_av;
  #endif /* ENABLE_MPE_AUDIO_VIDEO_TRANSCODING */

}SMDMC_command_type;

/*SMDMC parameter containing defined port number and specified by command type argument*/
typedef struct{
	/*MPE server communication port*/
	slim_int mpe_port;
	/*Main command parameter*/
	SMDMC_command_type type;
} SMDMC_command_param;


SMDMC_error
SMDM_client_query(SMDMC_command cmd, SMDMC_command_param *param, media_manager_t *mim);

slim_int MPEClient_parse_rcvd(slim_char* buf, minfo_t* info);

#endif /* MEDIA_PROCESSING_EXTENSION */

#endif /*MPE_CLIENT_H*/
