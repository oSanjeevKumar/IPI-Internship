/*
 * nflc_contents.h
 * Copyright (C) 2007-2014 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */


#ifndef NFLC_CONTENTS_H
#define NFLC_CONTENTS_H

#include <info_media.h>
#include <dlna_int64.h>
#include <dlna_cds_search.h>
#include <info_jpeg_scale.h>
#include <dlna_vector.h>
#include <access_conf.h>
#include <storage_manager.h>
#include <progress_event.h>
#ifdef ENABLE_MOVIEDB_MOVIECOVER
#include <moviedb_client.h>
#endif /*ENABLE_MOVIEDB_MOVIECOVER*/

#define CONTENTS_AUTO_DELETE_TIMER  (30)

#define  C_DC_TITLE_MAX_LENGTH         (256)
#define  C_DC_CREATOR_MAX_LENGTH       (256)
#define  C_UPNP_ALBUM_MAX_LENGTH       (256)
#define  C_UPNP_GENRE_MAX_LENGTH       (256)
#define  C_UPNP_ARTIST_MAX_LENGTH      (256)
#define  C_UPNP_RATING_MAX_LENGTH      (256)
#define  C_PARENTID_MAX_LENGTH         (256)
#define  C_PINFO_MAX_LENGTH            (1024)
#define  C_IMAGE_FULL_PATH_MAX_LENGTH  (1024)
#define  C_VIDEO_FULL_PATH_MAX_LENGTH  (1024)
#define  C_AUDIO_FULL_PATH_MAX_LENGTH  (1024)
#define  C_DOCUMENT_FULL_PATH_MAX_LENGTH  (1024)
#define  C_PLAYLIST_FULL_PATH_MAX_LENGTH  (1024)
#define  C_CONTAINER_FULL_PATH_MAX_LENGTH (1024)

#define CTI_PATH_LEN          (1024)     /* ZZZ */

#define CONTENTS_ALBUM_RESERVATION_FILENAME_0 "_album_art.jpg"
#define CONTENTS_ALBUM_RESERVATION_FILENAME_1 "Folder.jpg" /* Microsoft Windows 7 Logo Program NETMEDIA-0029 */
#define CONTENTS_ALBUM_RESERVATION_FILENAME_2 "AlbumArtSmall.jpg" /* Microsoft Windows 7 Logo Program NETMEDIA-0029 */
#define CONTENTS_ALBUM_RESERVATION_LARGE_JPG "}_Large.jpg" /* Microsoft Windows 7 Logo Program NETMEDIA-0029 */
#define CONTENTS_ALBUM_RESERVATION_SMALL_JPG "}_Small.jpg" /* Microsoft Windows 7 Logo Program NETMEDIA-0029 */
#define CONTENTS_ALBUM_RESERVATION_ALBUM_ART "AlbumArt_{" /* Microsoft Windows 7 Logo Program NETMEDIA-0029 */

#define CONTENTS_DEFAULT_ALBUM_ART_PREFIX       "/defaultalbumart" DEFAULT_DMSCONFIG_ID_DELIM
#define CONTENTS_DEFAULT_THUMBNAIL_PREFIX       "/defaultthumbnail" DEFAULT_DMSCONFIG_ID_DELIM

#define CONTENTS_STORAGE_FILTER_CONTENT            -2
#define CONTENTS_STORAGE_ERROR                     -1
#define CONTENTS_STORAGE_OK                         0
#define CONTENTS_STORAGE_CONTINUE                   1
#define CONTENTS_STORAGE_CANCEL_REBUILD             2
#define CONTENTS_STORAGE_END                        3
#define CONTENTS_STORAGE_REINDEXING_NOT_NEEDED      4
#define CONTENTS_STORAGE_INVALID                    5
#define CONTENTS_STORAGE_OUT_OF_MEMORY              6

enum {
  CONTENT_STORAGE_MEMCHECK_INDEX_FIRST_TIME,
  CONTENT_STORAGE_MEMCHECK_INDEX_REBUILD,
  CONTENT_STORAGE_MEMCHECK_INDEX_PARTIAL,
  CONTENT_STORAGE_MEMCHECK_INDEX_TN,
  CONTENT_STORAGE_MEMCHECK_INDEX_SM,
  CONTENT_STORAGE_MEMCHECK_INDEX_GPS
};
typedef slim_int contet_indexing_type;

#ifdef ENABLE_MOVIEDB_MOVIECOVER
#define MOVIEDB_MOVIESEARCH_URL "http://api.themoviedb.org/2.1/Movie.search/en/xml"
#define MOVIEDB_APIKEY "85639be77afb7dfdf1deae744054646b"
#endif /*ENABLE_MOVIEDB_MOVIECOVERs*/

#define NFLC_CDS_CONTENTS_UPNP_CLASS_OBJECT_ITEM                                "object.item"
#define NFLC_CDS_CONTENTS_UPNP_CLASS_OBJECT_ITEM_IMAGE_ITEM                     "object.item.imageItem"
#define NFLC_CDS_CONTENTS_UPNP_CLASS_OBJECT_ITEM_IMAGE_PHOTO                    "object.item.imageItem.photo"
#define NFLC_CDS_CONTENTS_UPNP_CLASS_OBJECT_ITEM_AUDIO_ITEM                     "object.item.audioItem"
#define NFLC_CDS_CONTENTS_UPNP_CLASS_OBJECT_ITEM_AUDIO_ITEM_MUSIC_TRACK         "object.item.audioItem.musicTrack"
#define NFLC_CDS_CONTENTS_UPNP_CLASS_OBJECT_ITEM_VIDEO_ITEM                     "object.item.videoItem"
#define NFLC_CDS_CONTENTS_UPNP_CLASS_OBJECT_ITEM_VIDEO_ITEM_MOVIE               "object.item.videoItem.movie"
#define NFLC_CDS_CONTENTS_UPNP_CLASS_OBJECT_ITEM_MUSIC_VIDEO_CLIP               "object.item.videoItem.musicVideoClip"
#define NFLC_CDS_CONTENTS_UPNP_CLASS_OBJECT_ITEM_PLAYLIST_ITEM                  "object.item.playlistItem"
#define NFLC_CDS_CONTENTS_UPNP_CLASS_OBJECT_ITEM_TEXT_ITEM                      "object.item.textItem"
#define NFLC_CDS_CONTENTS_UPNP_CLASS_OBJECT_CONTAINER                           "object.container"
#define NFLC_CDS_CONTENTS_UPNP_CLASS_OBJECT_CONTAINER_PERSON                    "object.container.person"
#define NFLC_CDS_CONTENTS_UPNP_CLASS_OBJECT_CONTAINER_PERSON_MUSIC_ARTIST       "object.container.person.musicArtist"
#define NFLC_CDS_CONTENTS_UPNP_CLASS_OBJECT_CONTAINER_PLAYLIST_CONTAINER        "object.container.playlistContainer"
#define NFLC_CDS_CONTENTS_UPNP_CLASS_OBJECT_CONTAINER_ALBUM                     "object.container.album"
#define NFLC_CDS_CONTENTS_UPNP_CLASS_OBJECT_CONTAINER_ALBUM_MUSIC_ALBUM         "object.container.album.musicAlbum"
#define NFLC_CDS_CONTENTS_UPNP_CLASS_OBJECT_CONTAINER_ALBUM_PHOTO_ALBUM         "object.container.album.photoAlbum"
#define NFLC_CDS_CONTENTS_UPNP_CLASS_OBJECT_CONTAINER_GENRE                     "object.container.genre"
#define NFLC_CDS_CONTENTS_UPNP_CLASS_OBJECT_CONTAINER_GENRE_MUSIC_GENRE         "object.container.genre.musicGenre"
#define NFLC_CDS_CONTENTS_UPNP_CLASS_OBJECT_CONTAINER_GENRE_MOVIE_GENRE         "object.container.genre.movieGenre"
#define NFLC_CDS_CONTENTS_UPNP_CLASS_OBJECT_CONTAINER_STORAGE_FOLDER            "object.container.storageFolder"


#define NFLC_CDS_CONTENTS_UPNP_RESTRICTED       "1"
#define NFLC_CDS_CONTENTS_UPNP_UN_RESTRICTED    "0"
#define NFLC_CDS_CONTENTS_UPNP_RESTRICTED_TRUE  "TRUE"
#define NFLC_CDS_CONTENTS_UPNP_RESTRICTED_FALSE "FALSE"

#define NFLC_CDS_CONTENTS_INTERNET_CONTENTS_TITLE "Internet Contents"
#define NFLC_CDS_CONTENTS_XML_IMPORT_TITLE "XML Import"

#define NFLC_CDS_CONTENTS_REFERENCE_THUMBNAIL_TAG "TN"
#define NFLC_CDS_CONTENTS_REFERENCE_SMALL_TAG "SM"
#define NFLC_CDS_CONTENTS_REFERENCE_MEDIUM_TAG "MED"
#define NFLC_CDS_CONTENTS_REFERENCE_LARGE_TAG "LRG"
#define NFLC_CDS_CONTENTS_REFERENCE_ALBUM_ART_TN_TAG "ATN"
#define NFLC_CDS_CONTENTS_REFERENCE_EMBEDDED_ALBUM_ART_TN_TAG "EMB"
#define NFLC_CDS_CONTENTS_REFERENCE_FILENAME_SEPARATOR "_"

#define NFLC_CDS_CONTENTS_FLAG_VALID    1
#define NFLC_CDS_CONTENTS_FLAG_INVALID  0
#ifdef ENABLE_IGNORE_FILE_IF_CRASH
#define NFLC_CDS_CONTENTS_FLAG_VALID_IGNORE  2
#endif /* ENABLE_IGNORE_FILE_IF_CRASH */
#define NFLC_CDS_CONTENTS_FLAG_SHARE    1
#define NFLC_CDS_CONTENTS_FLAG_UNSHARE  0
#define NFLC_CDS_CONTENTS_FLAG_REMOTE   1
#define NFLC_CDS_CONTENTS_FLAG_LOCAL    0

#define NFLC_CDS_CONTENTS_ERROR          -1
#define NFLC_CDS_CONTENTS_NO_SUCH_OBJECT -2
#define NFLC_CDS_CONTENTS_OUT_OF_MEMORY  -65535
#define NFLC_CDS_CONTENTS_OK              0

#define NFLC_CONTENTS_URI_PN_TOKEN    (SLIM_T("?pn="))

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus  */

typedef struct _extended_flags {
  slim_word  flags;
  slim_word  flags_ext1;

#ifdef DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION

  struct _upnp_cds_user_agent_customizations * customizations;

#endif /* DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION */
} extended_flags_t;

/* contents manager error codes.  */
enum contents_manager_return_ {
  CM_SUCCESS           = 0,
  CM_WOULDBLOCK = -2,
  CM_GENERIC_ERROR = -1,
  CM_OUT_OF_MEMORY     = -65535,
  CM_INVALID_PARAM,
  CM_INVALID_ACTION,
  CM_METADATA_SIGNATURE_INVALID,
  CM_FILE_NOT_EXIST
};

typedef enum contents_manager_return_  contents_manager_return_t;

typedef enum {
  CM_DATA_TRANS_START = 0,
  CM_DATA_TRANS_IN_PROGRESS,
  CM_DATA_TRANS_ERROR,
  CM_DATA_TRANS_DONE
}cm_data_trans_stat;

enum
{
  NFLC_CDS_OBJECT_ID_TYPE_METADATA = 1,
  NFLC_CDS_OBJECT_ID_TYPE_REFERENCE = 2,
  NFLC_CDS_OBJECT_ID_TYPE_SUBTITLE = 3,
  NFLC_CDS_OBJECT_ID_TYPE_EXTENDED_METADATA = 4,
  NFLC_CDS_OBJECT_ID_TYPE_USER_METADATA =5
};
typedef slim_int content_object_id_type;

enum
{
  NFLC_CDS_OBJECT_TYPE_CONTAINER,
  NFLC_CDS_OBJECT_TYPE_ITEM_IMAGE,
  NFLC_CDS_OBJECT_TYPE_ITEM_AUDIO,
  NFLC_CDS_OBJECT_TYPE_ITEM_VIDEO,
  NFLC_CDS_OBJECT_TYPE_ITEM_PLAYLIST,
  NFLC_CDS_OBJECT_TYPE_ITEM_SUBTITLE,
  NFLC_CDS_OBJECT_TYPE_ITEM_TEXT,
  NFLC_CDS_OBJECT_TYPE_ITEM_UNKNOWN
};
typedef slim_int content_item_type;

enum
{
  NFLC_CDS_REFERENCE_TYPE_THUMBNAIL,
  NFLC_CDS_REFERENCE_TYPE_SMALL,
  NFLC_CDS_REFERENCE_TYPE_MEDIUM,
  NFLC_CDS_REFERENCE_TYPE_LARGE,
  NFLC_CDS_REFERENCE_TYPE_ALBUM_ART_TN,
  NFLC_CDS_REFERENCE_TYPE_EMBEDDED_ALBUM_ART_TN
};
typedef slim_int content_reference_type;

typedef enum
{
  CM_CONTENT_CHANGE_ADD,
  CM_CONTENT_CHANGE_DELETE,
  CM_CONTENT_CHANGE_OTHER
}cm_content_change_t;


/* Contents message callback.  */
struct contents;

/* Time seek query parameter.  */
struct upnp_seek_param
{
  dlna_timeval start_time;
  dlna_timeval end_time;
  dlna_timeval full_time;

  dlna_uint64 start_bytes;
  dlna_uint64 end_bytes;
  dlna_uint64 full_bytes;
};

/* Time seek return code */
typedef enum time_seek_ret
{
  TIME_SEEK_SUCCESS,
  TIME_SEEK_INVALID_RANGE,
  TIME_SEEK_NOT_SUPPORTED,
  TIME_SEEK_ERROR
} time_seek_ret_t;

enum item_field_type_tag
{
  ITEM_FIELD_TYPE_TITLE = 1,
  ITEM_FIELD_TYPE_UPNP_ARTIST,
  ITEM_FIELD_TYPE_DC_DATE,
  ITEM_FIELD_TYPE_UPNP_GENRE,
  ITEM_FIELD_TYPE_UPNP_TRACK_NUMBER
};

typedef enum item_field_type_tag item_field_type_t;

typedef enum search_match_result (*contents_match_t) (cds_search_exp_t *exp,
                                                      void *arg);
typedef slim_int (*contents_seek_t) (struct contents *c,
                                     struct upnp_seek_param *p);

typedef dlna_time_t (*contents_get_field_time_t) (struct contents *c, item_field_type_t in_field_type);

typedef slim_char* (*contents_get_field_str_t) (struct contents *c, item_field_type_t in_field_type);

struct peer_directory_change_notification;

struct user_metadata_
{
  struct user_metadata_ *next;
  struct user_metadata_ *prev;
  slim_char *property;
  slim_char *value;
};
typedef struct user_metadata_ user_metadata;

struct user_metadata_info_
{
  struct user_metadata_info_ * next;
  struct user_metadata_info_ * prev;
  slim_char * property;
  slim_char * value;
  slim_int id;
  slim_int content_id;
};
typedef struct user_metadata_info_ user_metadata_info;
typedef List(user_metadata_info *) user_metadata_info_list;

#if defined (DEVELOPMENT_ENABLE_PUBLISH_STREAMING_CONTENT) || defined(DEVELOPMENT_CONTENT_AGGREGATION)
enum {
  CONTENT_RES_TYPE_THUMBNAIL,
  CONTENT_RES_TYPE_SUBTITLE,
  CONTENT_RES_TYPE_COVER,
  CONTENT_RES_TYPE_TRANSCODED
};
typedef slim_int content_res_type;

struct contents_res
{
  struct contents_res *prev;
  struct contents_res *next;

  slim_int metadata_id;
  slim_int res_type;
  slim_char *file_path;
  slim_char *uri;
  slim_word width;
  slim_word height;
  dlna_uint64 size;
  slim_word bitrate;
  slim_word samplingrate;
  slim_word nr_audio_channels;
  slim_char *duration_str;
  slim_char *pinfo_str;
  slim_bool is_proxy_url;
};
typedef struct contents_res cres_t;
#endif /* (DEVELOPMENT_ENABLE_PUBLISH_STREAMING_CONTENT) || (DEVELOPMENT_CONTENT_AGGREGATION) */

/* Base structure for all contents.  */
struct contents
{
  struct contents *next;
  struct contents *prev;

  /* Contents manager back pointer.  */
  struct contents_manager *cm;

  /* Contents flags.  */
  slim_word flags;
  slim_bool storage_flag;
  slim_bool is_aggregated;
  slim_char* storage_id;
  slim_char* refID;

//#ifdef DEVELOPMENT_ENABLE_PUBLISH_CONTENT
#ifdef DEVELOPMENT_PUBLISH_ONLINE_RECORDED_CONTENT_API
  slim_char* ext_id;
#endif /* DEVELOPMENT_PUBLISH_ONLINE_RECORDED_CONTENT_API */

  List(user_metadata*) user_metadata_list;

#define CONTENTS_FLAG_CONTAINER               (1 << 0)
#define CONTENTS_FLAG_REFERENCE               (1 << 1)
#define CONTENTS_FLAG_IMAGE                   (1 << 2)
#define CONTENTS_FLAG_AUDIO                   (1 << 3)
#define CONTENTS_FLAG_VIDEO                   (1 << 4)
#define CONTENTS_FLAG_UPLOAD                  (1 << 5)
#define CONTENTS_FLAG_DELETE                  (1 << 7)
#define CONTENTS_FLAG_PLAYLIST                (1 << 8)
#define CONTENTS_FLAG_CONTAINER_ALBUM         (1 << 9)
#define CONTENTS_FLAG_SUBTITLE                (1 << 10)
#define CONTENTS_FLAG_STREAMING_LIVE_ITEM     (1 << 11)
#define CONTENTS_FLAG_STREAMING_RECORDED_ITEM (1 << 12)
#define CONTENTS_FLAG_DTCP_PROTECTED          (1 << 13)
#define CONTENTS_FLAG_CADRM_PROTECTED         (1 << 14)
#define CONTENTS_FLAG_LRADA_LIVE_CONTENT      (1 << 15) /* LRADA LiveContent */
#define CONTENTS_FLAG_DOCUMENT                (1 << 16)

  /* Contents type.  */
  contents_type_t ctype;

  /* DLNA Memory type.  */
  dlna_mtype_t mtype;

  struct contents *parent;  /* Parent contents.            */
  slim_char *parent_id;
  slim_char *id;            /* @id.                        */
  slim_word res_id;         /* Resource ID.  */
  slim_word dlnaManaged;   /* @dlna:dlnaManaged           */

  slim_char *uri;           /* URI.                        */
  slim_char *restricted;    /* @restricted.                */
  slim_char *full_path;     /* Full path of the contents.  */

  /* dc: namespace.  */
  slim_char *title;         /* dc:title.                   */
  slim_char *creator;       /* dc:creator.                 */

  /* upnp: namespace.  */
  slim_char *upnp_class;    /* upnp:class.                 */
  slim_char *upnp_album;    /* upnp:album.                 */
  slim_word upnp_createClass; /* upnp:createClass.         */
  slim_char *upnp_rating; /* SM+: Added upnp:rating */
  slim_char *upnp_rating_type;
#define CONTENTS_UPNP_CREATECLASS_OBJECT_ITEM           (1 << 0)
#define CONTENTS_UPNP_CREATECLASS_OBJECT_ITEM_IMAGE     (1 << 1)
#define CONTENTS_UPNP_CREATECLASS_OBJECT_ITEM_VIDEO     (1 << 2)
#define CONTENTS_UPNP_CREATECLASS_OBJECT_ITEM_AUDIO     (1 << 3)
#define CONTENTS_UPNP_CREATECLASS_OBJECT_CONTAINER      (1 << 4)
#define CONTENTS_UPNP_CREATECLASS_OBJECT_ITEM_DOCUMENT  (1 << 5)


  /* DLNA.ORG_FLAG (DLNA_PINFO_FLAGS_XXX) */
  slim_word dlna_org_flags;

  /* ProtocolInfo type extracted from pinfo member.  */
  List(pinfo_t*) pinfo_list;


#ifdef DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION_SONY_BRAVIA_PROFILING

  /* Pinfo relaxed is a version of pinfo expected by some devices (not constrained much) */
  slim_char * pinfo_relaxed;

#endif /* DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION_SONY_BRAVIA_PROFILING */


#ifdef HAVE_DTCP
  /* DRM Information */
  minfo_drm_t drm_info;
#endif /* HVE_DTCP */

  /* Callbacks.  */
  contents_match_t match;
  contents_seek_t seek;
  contents_get_field_time_t get_field_time_proc;
  contents_get_field_str_t  get_field_str_proc;

  /* Events.  */
  dlna_progress_handle e_delete;

#ifdef DEVELOPMENT_CONTENT_AGGREGATION
  List(cres_t*) aggregated_res_list;
#endif /* DEVELOPMENT_CONTENT_AGGREGATION */

#ifdef ENABLE_PARENTAL_GUIDANCE
  slim_int  access_level;
#endif /* ENABLE_PARENTAL_GUIDANCE */
#if defined(DEVELOPMENT_ENABLE_PUBLISH_STREAMING_CONTENT) || defined(DEVELOPMENT_ENABLE_PUBLISH_CONTENT)
  List(cres_t*) res_list;
#endif /*DEVELOPMENT_ENABLE_PUBLISH_STREAMING_CONTENT*/
  slim_word change_wav; /* If content is wav and there is get for lpcm we must change byte order of stream*/
#ifdef DEVELOPMENT_ENABLE_PUBLISH_CONTENT
  streamType stream_type;
  contentEncryptionType content_encryption;
  slim_char *extension;
  slim_char *mime;
  objectRights_t *objectRights;
  slim_char *x_contentId;
  slim_char *x_url;
  contentSource source;
  List(contentResource_t*) resourceslist;
#endif /*DEVELOPMENT_ENABLE_PUBLISH_CONTENT*/
};

typedef struct contents contents_t;

#ifdef DLNA_SUPPORT_UPLOADER
struct contentId {
  struct contentId *next;
  struct contentId *prev;

  slim_char *id;            /* @id.                        */
  slim_char *full_path;     /* Full path of the contents.  */
	dlna_mutex uploadMutex;
};

typedef struct contentId contentId_t;

#endif


/*! \struct contents_info
 * \brief Structure holding basic information about content.
 *
 * This structure holds some basic info about the content. Can be used to check some basic
 * data of content. This is a small struct and does not require any dynamic memory allocation.
 */
typedef struct contents_info {
  slim_int object_id;       /*! unique object id, assigned by database when content is added */
  slim_byte shared;         /*! share flag, 0 - content is not shared and can't be seen by the player, 1 - shared and can be seen */
  slim_byte valid;          /*! 1 means metadata in database is valid, 0 means metadata is invalid and shouldn't be used*/
  slim_byte type;           /*! container/image/video/audio */
  slim_int parent_id;       /*! id of parent container */
  dlna_time_t time;         /*! modification time od file/directory */
#ifdef ENABLE_PARENTAL_GUIDANCE
  slim_int  access_level;   /*! parental control access level */
#endif
} contents_info_t;

/* Container class.  */
struct contents_container
{
  contents_t base;

  /* upnp: namespace.  */
  slim_char *upnp_album_art_tn;       /* AlbumArt thumbnail */
  slim_char *upnp_album_art_original; /* AlbumArt original */
  slim_int upnp_album_art_profile;    /* DLNA profile of album art */
  slim_word item_count;                         /*Playable Media Count*/

  slim_word upnp_child_count;                   /* upnp:childCount */
  slim_word upnp_container_update_id;           /* upnp:containerUpdateID */

  /* Child vector.  */
  struct _vector *child;

  /* Peer directory change notification */
  dlna_dcn dcn;

  slim_bool is_top_virtual_dir; /*set for Audio, Video, Photo and for their child containers Playlist/Slideshow and for those containers shouldn't be send container update id because they children never changes*/
  slim_char *genre;         /* Genre.  */
  dlna_time_t time;         /* Modification time.  */
};

typedef struct contents_container ccont_t;


/* Contents reference.  */
struct contents_reference
{
  contents_t base;

  /* Reference contents.  */
  contents_t *ref;
};

typedef struct contents_reference cref_t;

struct contents_reference_
{
  slim_int id;
  slim_int media_id;
  slim_int type;
  slim_char* fullpath;
  slim_char* title;
  slim_char* uri;
  slim_int width;
  slim_int height;
  dlna_uint64 filesize;
  slim_char* pInfo_string;
  slim_int profile;
  slim_int scaletype;
  slim_int permillage;
  slim_char* mime;
  slim_char* param_pn;
  slim_char* param_ci;
  slim_char* param_op;
};
typedef struct contents_reference_ creference_t;

/* Image contents.  */
struct contents_image
{
  contents_t base;

  dlna_uint64 file_size;   /* File Size.  */
  dlna_time_t time;        /* Modification time.  */
  dlna_time_t exif_time;   /* Time from exif.  */
  slim_char  *exif_keywords;
  slim_word width;         /* Width and height.   */
  slim_word height;
  slim_word permillage;
  slim_int image_profile;

  /* Scaling.  */
  slim_byte scale_type;
#define CONTENTS_IMAGE_SCALE_TYPE_SCALE     (0)
#define CONTENTS_IMAGE_SCALE_TYPE_HALF      (1)
#define CONTENTS_IMAGE_SCALE_TYPE_QUAD      (2)
#define CONTENTS_IMAGE_SCALE_TYPE_THUMBNAIL (3)
#ifdef ENABLE_GPS_SUPPORT
  slim_bool gps_flag;
  slim_double gps_latitude;
  slim_double gps_longitude;
#endif /* ENABLE_GPS_SUPPORT */
  struct contents_image *ref; /* Image reference.  */
};

typedef struct contents_image cimage_t;

/* Audio contents.  */
struct contents_audio
{
  contents_t base;

  dlna_uint64 file_size;   /* File Size.  */
#ifdef HAVE_DTCP
  dlna_uint64 pcp_encrypted_size;   /* PCP encrypted File Size.  */
#endif /* HAVE_DTCP */
  dlna_time_t time;         /* Modification time.  */
  slim_word bitrate;        /* Bitrate.  */
  slim_word sample_rate;    /* Sample rate.     */
  slim_byte channels;       /* Num of channels, 1=mono 2=stereo  */
  slim_word duration;       /* Duration.  */ /* Duration is not to be Negative value so change type from slim_long */
  slim_char *artist;        /* Artist.  */
  slim_char *genre;         /* Genre.  */
  slim_char *track_num;     /* Track number.  */
  slim_char *duration_str;
  slim_char *upnp_album_art_tn;       /* AlbumArt thumbnail */
  slim_char *upnp_album_art_original; /* AlbumArt original */
  slim_int upnp_album_art_profile;    /* DLNA profile of album art */
  contents_t *ref;     /* LPCM baseline profile    */
  slim_char *ext_comment;
  slim_char *composer;
  slim_int   year;
  slim_word upnp_channelNr;      /* upnp:chnnelNr */


#ifdef DEVELOPMENT_MATROSKA_EMBEDED_ALBUM_ART

  slim_bool embeded_album_art_is_available;
  slim_word embeded_album_art_stream_index;

#endif /* DEVELOPMENT_MATROSKA_EMBEDED_ALBUM_ART */

#ifdef  DEVELOPMENT_ENABLE_PUBLISH_CONTENT
  slim_word avg_bitrate;
  slim_word level;
  slim_word profile;
  slim_char *codec_name;
#endif /*DEVELOPMENT_ENABLE_PUBLISH_CONTENT*/

};

typedef struct contents_audio caudio_t;

#ifdef ENABLE_SUBTITLE_SUPPORT
struct video_subtitle
{
  struct video_subtitle *next;
  struct video_subtitle *prev;
  slim_char *st_id;
  slim_int st_type;
  slim_char *st_lang;
  slim_int streamNo;
  slim_char *st_filepath;
  slim_char *st_uri;
};

typedef struct video_subtitle video_subtitle_t;
#endif /*ENABLE_SUBTITLE_SUPPORT*/

/* Video contents.  */
struct contents_video
{
  contents_t base;

  slim_char *artist;       /* Artist.  */
  slim_char *genre;        /* Genre.  */
  slim_char *track_num;    /* Track number.  */
  slim_char *duration_str;
  dlna_uint64 file_size;   /* File Size.  */
#ifdef HAVE_DTCP
  dlna_uint64 pcp_encrypted_size;   /* PCP encrypted File Size.  */
#endif /* HAVE_DTCP */
  dlna_time_t time;        /* Modification time.  */
  slim_half width;         /* Width.  */
  slim_half height;        /* Height.  */
  slim_word bitrate;       /* Bitrate.  */
  slim_word duration;      /* Duration.  */ /* Duration is not to be Negative value so change type from slim_long */
  slim_word sample_rate;   /* Sample rate.  */
  slim_byte channels;      /* Num of channels, 1=mono 2=stereo. */
  slim_int ifo_flg;         /* Discontinuous File */
  slim_char *upnp_album_art_tn;       /* AlbumArt thumbnail */
  slim_char *upnp_album_art_original; /* AlbumArt original */
  slim_int upnp_album_art_profile;    /* DLNA profile of album art */
  slim_word upnp_channelNr;      /* upnp:chnnelNr */
  slim_int frame_rate;    /* frame rate */
#ifdef ENABLE_SUBTITLE_SUPPORT
  slim_bool if_subtitle_flag;
  List(video_subtitle_t*) subtitle_list;
#endif /* ENABLE_SUBTITLE_SUPPORT */
#ifdef ENABLE_THUMBNAIL
  struct contents_image* ref; /*Thumbnail Reference*/
#endif /*ENABLE_THUMBNAIL*/
#ifdef ENABLE_MOVIEDB_MOVIECOVER
  slim_int if_coverurl;
  slim_char* coverurl;
  slim_int cover_width;
  slim_int cover_height;
#endif /*ENABLE_MOVIEDB_MOVIECOVER*/


#ifdef DEVELOPMENT_MATROSKA_EMBEDED_ALBUM_ART

	struct _media_attachment_info embeded_album_art;

#endif /* DEVELOPMENT_MATROSKA_EMBEDED_ALBUM_ART */

#ifdef DEVELOPMENT_ENABLE_PUBLISH_CONTENT
  struct cAudioRes *audioInfo;
  slim_word avgBitrate;
  slim_char *frameRate;
  slim_char *par;
  slim_char *dar;
  slim_char *region;
  slim_word profile;
  slim_word level;
  slim_char *codecName;
#endif /*DEVELOPMENT_ENABLE_PUBLISH_CONTENT*/
};

typedef struct contents_video cvideo_t;

/* Document contents.  */
struct contents_document
{
  contents_t base;
  dlna_uint64 file_size;   /* File Size.  */
  dlna_time_t time;        /* Modification time.  */
};

typedef struct contents_document cdocument_t;

/* Playlist contents.  */
/* ContentDirectory1.0 7.4. playlistItem : item */
struct contents_playlist
{
  contents_t base;

  slim_char *artist;       /* Artist.  */
  slim_char *genre;        /* Genre.  */
  dlna_time_t date;        /* Creation date of the playlist file. */

#ifdef DEVELOPMENT_ENABLE_PLAYLIST_CONTAINER
  slim_word upnp_child_count;                   /* upnp:childCount */

  /* Child vector.  */
  struct _vector * child;
#endif /* DEVELOPMENT_ENABLE_PLAYLIST_CONTAINER */
};

typedef struct contents_playlist cplaylist_t;


struct dtcp_contents
{
  /* AKE IP Address */
  dlna_ip_addr dtcp_ip_addr;

  /* AKE Port */
  slim_half dtcp_port;

  /* Pointer to function to resolve protocol info */
  void (*res_proto_info) (slim_char *info, dlna_ip_addr *ip_addr,
                          slim_char *str);

  /* Pointer to function to set URI */
  void (*set_uri) (dlna_ip_addr *ip_addr, slim_half http_port,
                   slim_char *id, slim_char *suffix, slim_char *buf);
};

typedef struct dtcp_contents dtcp_contents_t;

struct flist
{
  struct flist *next;
  struct flist *prev;
  slim_char *full_path;
  slim_char *name;
  slim_bool new_directory;
  slim_int id;
};

typedef struct flist dlna_flist_t;


typedef void (*contents_update_ids_proc)(void * info,
    const slim_char * parent_id,
    const slim_word parent_update_id,
    const slim_char * content_id,
    const slim_word content_update_id);
typedef slim_half (*contents_port_value)(void * info);


#ifdef DEVELOPMENT_ENABLE_PUBLISH_STREAMING_CONTENT
#define STREAMING_INFO_FLAG_NONE                        (1 << 0)
#define STREAMING_INFO_FLAG_DTCP_PROTECTED              (1 << 1)
#define STREAMING_INFO_FLAG_CADRM_PROTECTED             (1 << 2)

typedef struct streaming_info_ {
  slim_bool is_streaming;
  slim_word streaming_flags;
  slim_int stream_cci;
} streaming_info;
#endif /*DEVELOPMENT_ENABLE_PUBLISH_STREAMING_CONTENT*/

typedef struct index_manager_index_list_item {
  struct index_manager_index_list_item *next;
  struct index_manager_index_list_item *prev;
  struct storage_config *usb_cfg;
  slim_byte storage_indexing_state;
  slim_byte partial_indexing_mode;
  slim_char *path_to_index;
  slim_int partial_indexing_share;
#ifdef ENABLE_PARENTAL_GUIDANCE
  slim_int partial_indexing_pc;
#endif /* ENABLE_PARENTAL_GUIDANCE */
#ifdef DEVELOPMENT_ENABLE_PUBLISH_STREAMING_CONTENT
  streaming_info partial_indexing_streaming;
#endif /* DEVELOPMENT_ENABLE_PUBLISH_STREAMING_CONTENT */
  slim_int partial_indexing_id;
} index_manager_index_list_item_t;

struct _exlcude_file_list_entry
{
  struct _exlcude_file_list_entry * next;
  struct _exlcude_file_list_entry * prev;

  slim_char * file_path;
};

ListNamed(struct _exlcude_file_list_entry *, _exlcude_file_list);

typedef slim_bool (* _exclude_file_routine)(void * cm, slim_char * file_name, slim_bool is_dir);

#ifdef HAVE_DTCP
struct _drm_file_list_entry
{
  struct _drm_file_list_entry * next;
  struct _drm_file_list_entry * prev;

  slim_char * path;
  slim_char * cci;
};

ListNamed(struct _drm_file_list_entry *, _drm_file_list);
#endif/* HAVE_DTCP */

/* Contents manager.  */
struct contents_manager
{
  /* Interface manager.  */
  struct upnp_if_manager *ifm;

    /* Event manager.  */
  dlna_progress em;

  /* Contents manager root directory.  */
  slim_char *contents_work_dir;

  /* Additional directories to monitoring. (besides root dir) */
  List(dlna_flist_t *) monitoring_dir_list;

  /* Contents tree.  */
  contents_t *tree;

  /* Upload container.  */
  contents_t *upload;

  List(contents_t *) contents_list;
#ifdef DEVELOPMENT_ENABLE_PUBLISH_STREAMING_CONTENT
  slim_int max_id;
#endif /*DEVELOPMENT_ENABLE_PUBLISH_STREAMING_CONTENT*/

  /* Contents list.  */
  List(contents_t *) list;

  /* String buffer used for the XML generation.  */
  struct sbuf *sbuf;

  /* Incomming interface index used for the XML resources.  */
  slim_int ifindex;

  /* Local port of the HTTP server used for the XML resources.  */
  contents_port_value port_callback;

  /* Information pointer.  */
  void *info;

  /* Media manager */
  media_manager_t *mim;


  /*
   * UPNP CDS 1.0 - 2.5.20. SystemUpdateID & 2.5.21. ContainerUpdateIDs
   * UPNP CDS 2.0 - 2.3.5 SystemUpdateID & 2.3.6 ContainerUpdateIDs
   * UPNP CDS 3.0 - 2.3.5 SystemUpdateID & 2.3.6 ContainerUpdateIDs & 2.3.8 LastChange
   */
  contents_update_ids_proc update_ids_callback;

  struct _exlcude_file_list exclude_files_list;
  _exclude_file_routine is_file_excluded;

#ifdef HAVE_DTCP
  struct _drm_file_list drm_files_list;
#endif/* HAVE_DTCP */

#ifdef HAVE_DTCP
  drm_manager_t drm_manager;
#endif /* HAVE_DTCP */


  /* Method.  */
  /* Frequentry used containers.  */
  contents_t *video_all;
  contents_t *video_genre;
  contents_t *video_actor;
  contents_t *video_album;
#ifdef ENABLE_MOVIEDB_MOVIECOVER
  contents_t *video_coverArt;
#endif /*ENABLE_MOVIEDB_MOVIECOVER*/
  contents_t *music_all;
  contents_t *music_artist;
  contents_t *music_genre;
  contents_t *music_album;
  contents_t *pictures_all;
  contents_t *pictures_album;
#ifdef ENABLE_GPS_SUPPORT
  contents_t *pictures_geotagged;
  contents_t *pictures_geoarea;
#endif /*ENABLE_GPS_SUPPORT*/
  contents_t *video_rating;
  contents_t *video_date;
  contents_t *video_year;
  contents_t *video_folder;
  contents_t *music_artistalbum;
  contents_t *music_artistindex;
  contents_t *music_genrealbum;
  contents_t *music_genreartist;
  contents_t *music_rating;
#if 0
  contents_t *music_date;
  contents_t *music_year;
#endif
  contents_t *music_folder;
  contents_t *pictures_date;
  contents_t *pictures_year;
  contents_t *pictures_folder;
  contents_t *music_playlist;
  contents_t *document_all;
#ifdef DEVELOPMENT_ENABLE_VIRTUAL_PLAYLISTS
#define CDS_CM_VIRTUAL_PLAYLIST_INDEX_VIDEO_LAST_PLAYED 0
#define CDS_CM_VIRTUAL_PLAYLIST_INDEX_VIDEO_MOST_PLAYED 1
#define CDS_CM_VIRTUAL_PLAYLIST_INDEX_VIDEO_RECENTLY_ADDED 2
  contents_t *video_playlist;
  contents_t *video_lastPlayed;
  contents_t *video_mostPlayed;
  contents_t *video_recentlyAdded;
#define CDS_CM_VIRTUAL_PLAYLIST_INDEX_MUSIC_LAST_PLAYED 0
#define CDS_CM_VIRTUAL_PLAYLIST_INDEX_MUSIC_MOST_PLAYED 1
#define CDS_CM_VIRTUAL_PLAYLIST_INDEX_MUSIC_RECENTLY_ADDED 2
  contents_t *music_lastPlayed;
  contents_t *music_mostPlayed;
  contents_t *music_recentlyAdded;
#define CDS_CM_VIRTUAL_PLAYLIST_INDEX_PICTURE_LAST_PLAYED 0
#define CDS_CM_VIRTUAL_PLAYLIST_INDEX_PICTURE_MOST_PLAYED 1
#define CDS_CM_VIRTUAL_PLAYLIST_INDEX_PICTURE_RECENTLY_ADDED 2
  contents_t *pictures_slideshow;
  contents_t *pictures_lastPlayed;
  contents_t *pictures_mostPlayed;
  contents_t *pictures_recentlyAdded;
#endif /* DEVELOPMENT_ENABLE_VIRTUAL_PLAYLISTS */

//#ifdef DEVELOPMENT_ENABLE_PUBLISH_CONTENT
#ifdef DEVELOPMENT_PUBLISH_ONLINE_RECORDED_CONTENT_API
  contents_t *premium_liveContent;
  contents_t *premium_onlineContent;
  contents_t *premium_recordedContent;
#endif /* DEVELOPMENT_PUBLISH_ONLINE_RECORDED_CONTENT_API */

  contents_t *user_file;


#ifdef DEVELOPMENT_ICP_PLUGIN

  //These two fields are set by upnp_cds_alloc, but release is done in contents_manager_free
  slim_char * icp_plugin_container_name;
  slim_int icp_plugin_container_name_length;

#endif /* DEVELOPMENT_ICP_PLUGIN */


 /* Events.  */

  void *reservation_for_uploaded;
  access_config_t* access_cfg;
  dlna_thread indexing_thread;
  dlna_mutex indexing_thread_mutex;
  enum dlna_thread_policy indexing_thread_policy;
  slim_int indexing_thread_priority;
  slim_bool indexing_in_progress;
  slim_bool device_indexing_just_finished;
  storage_config_t* device_indexing_in_progress;
  slim_int indexing_type;
  slim_bool stop_indexing;     /* used when exiting the application to first stop indexing
                                  and free all memory used by indexing thread */
  slim_bool stop_dms;
  dlna_mutex index_manager_list_mutex;
  List(index_manager_index_list_item_t *) index_manager_list;
#ifdef ENABLE_MOVIEDB_MOVIECOVER
  moviedb_client *mdbc;
#endif /*ENABLE_MOVIEDB_MOVIECOVER*/

  cds_database_info *ca_database;

#ifdef DLNA_SUPPORT_UPLOADER
	List(contentId_t *) uploaded_contents_list;
	dlna_mutex uploaded_contents_listMutex;
#endif
#ifdef DEVELOPMENT_DATABASE_CHECKPOINT_TRIGGER_VIA_ACCESS_CONF
  slim_word database_items_since_checkpoint;
#endif /* DEVELOPMENT_DATABASE_CHECKPOINT_TRIGGER_VIA_ACCESS_CONF */

#ifdef DEVELOPEMENT_ENABLE_UPLOAD_TO_VIRTUAL_FOLDER_TREE
  slim_bool is_storage_switched_off;
#endif /*DEVELOPEMENT_ENABLE_UPLOAD_TO_VIRTUAL_FOLDER_TREE*/
};

typedef struct contents_manager cm_t;

/*! \struct partial_indexing_data
 * \brief Structure holding information about partial indexing.
 *
 * This structure holds info about the type of partial indexing - no partial indexing,
 * simple partial indexing, partial indexing with changing the share option or
 * (when parental control enabled on dms) partial indexing with parental control option
 * update. In simple mode default share and parental control values are used.
 */

typedef struct partial_indexing_data {
  slim_byte partial_indexing_mode;  /*! partial indexing mode (no partial indexing, simple,
                                    share or parental control) */
  slim_int partial_indexing_share;  /*! share mode to be set with partial indexing in share mode */
#ifdef ENABLE_PARENTAL_GUIDANCE
  slim_int partial_indexing_pc;     /*! parental control value to be set with partial indexing
                                    in parental control mode */
#endif /* ENABLE_PARENTAL_GUIDANCE */
#ifdef DEVELOPMENT_ENABLE_PUBLISH_STREAMING_CONTENT
  streaming_info partial_indexing_stream;
#endif /*DEVELOPMENT_ENABLE_PUBLISH_STREAMING_CONTENT*/
  slim_int partial_indexing_id;
} partial_indexing_data_t;

typedef slim_int (*CDSSortCompareFunc)(contents_t *in_c1, contents_t *in_c2, slim_int in_direction) ;

struct TCDSSortParam_ {
  struct TCDSSortParam_ *fNext;
  slim_char *fFieldName;
  slim_int fDirection;
  CDSSortCompareFunc fCompareFunc;
};
typedef struct TCDSSortParam_ TCDSSortParam;


#ifdef ENABLE_MOVIEDB_MOVIECOVER
typedef struct moviedb_cb_params_
{
	cm_t* cm;
	slim_char* movie_item_id;
} moviedb_cb_params_t;
#endif /*ENABLE_MOVIEDB_MOVIECOVER*/

typedef struct
{
  slim_char  in_char;
  slim_char  *out_char;
} artist_index_t;

/* Lookup the contents type based on the protocol info.  */
contents_type_t
contents_ctype_get_by_pinfo (pinfo_t *pinfo);

/* Allocate image contents.  */
cimage_t *
contents_image_alloc (cm_t *cm, contents_t *parent, minfo_t *info);

/* Allocate audio contents.  */
caudio_t *
contents_audio_alloc (cm_t *cm, contents_t *parent, minfo_t *info);

/* Allocate video contents.  */
cvideo_t *
contents_video_alloc (cm_t *cm, contents_t *parent, minfo_t *info);

/* Allocate playlist contents.  */
cplaylist_t *
contents_playlist_alloc (cm_t *cm, contents_t *parent, minfo_t *info);

slim_int
contents_album_playlist_open (struct sbuf *sbuf, contents_t *c, slim_int ifindex);

/* Add item.  */
contents_t *
contents_item_add (cm_t *cm, contents_t *parent, contents_t *c);

/* Get the MIME type.  */
slim_char *
contents_get_mime_type (contents_t *c);

/* Set the contents URI.  */
slim_bool
contents_set_uri (cm_t *cm, contents_t *c, slim_int ifindex, slim_word flags);

#ifdef ENABLE_SUBTITLE_SUPPORT
slim_char *
contents_get_subtitle_language(slim_char *in_string);
slim_bool
contents_set_video_subtitle_uri (cm_t *cm, video_subtitle_t *video_srt,	slim_int ifindex, slim_word flags);
slim_char*
contents_get_subtitle_ext(slim_int st_type);
#endif /*ENABLE_SUBTITLE_SUPPORT*/

contents_t *
contents_alloc(cm_t *cm, contents_t *parent, minfo_t *info);

contents_t *
contents_container_init (cm_t *cm, contents_t *parent,
                             slim_char *id, slim_char *title, slim_char* upnp_class);

contents_t *
contents_container_add(cm_t *cm, contents_t *parent, slim_char *title, slim_char *full_path);

slim_bool
contents_init (contents_t *c, slim_int id, slim_char *title,
               slim_char *upnp_class, slim_char *full_path,
               contents_match_t match, contents_seek_t seek,
               contents_get_field_str_t  in_get_field_str_proc,
               contents_get_field_time_t in_get_field_time_proc);

dlna_time_t
contents_dummy_get_field_time(contents_t *in_c, item_field_type_t in_field_type);

slim_char*
contents_dummy_get_field_str(contents_t *in_c, item_field_type_t in_field_type);

dlna_time_t
contents_image_get_field_time(contents_t *in_c, item_field_type_t in_field_type);

slim_char*
contents_image_get_field_str(contents_t *in_c, item_field_type_t in_field_type);

dlna_time_t
contents_audio_get_field_time(contents_t *in_c, item_field_type_t in_field_type);

slim_char*
contents_audio_get_field_str(contents_t *in_c, item_field_type_t in_field_type);

dlna_time_t
contents_video_get_field_time(contents_t *in_c, item_field_type_t in_field_type);

slim_char*
contents_video_get_field_str(contents_t *in_c, item_field_type_t in_field_type);

dlna_time_t
contents_playlist_get_field_time(contents_t *in_c, item_field_type_t in_field_type);

slim_char*
contents_playlist_get_field_str(contents_t *in_c, item_field_type_t in_field_type);

slim_int
contents_audio_seek (contents_t *contents, struct upnp_seek_param *param);

slim_int
contents_video_seek (contents_t *contents, struct upnp_seek_param *param);

slim_int
contents_metadata_check_truncation (slim_char **string, dlna_mtype_t mtype, slim_word length);

slim_bool
contents_image_meta_update (cimage_t *c, minfo_t *info);

slim_bool
contents_audio_meta_update (caudio_t *c, minfo_t *info);

slim_bool
contents_video_meta_update (cvideo_t *c, minfo_t *info);

slim_bool
contents_document_meta_update (cdocument_t *c, minfo_t *info);

slim_bool
contents_playlist_meta_update (cplaylist_t *c, minfo_t *info);

slim_bool
contents_image_update (cm_t *cm, cimage_t *c, contents_t *parent, minfo_t *info);

slim_bool
contents_audio_update (cm_t *cm, caudio_t *c, contents_t *parent, minfo_t *info);

slim_bool
contents_video_update (cm_t *cm, cvideo_t *c, contents_t *parent, minfo_t *info);

#ifdef ENABLE_PLAYLIST_SUPPORT
slim_bool
contents_playlist_update (cm_t *cm, cplaylist_t *c, contents_t *parent, minfo_t *info);
#endif /* ENABLE_PLAYLIST_SUPPORT */

slim_int
contents_image_add (cm_t *cm, cimage_t *c, contents_t *parent, minfo_t *info);

#ifdef USE_RESIZE_IMAGE_PEER
void
contents_image_ref_alloc(cimage_t *c, minfo_t *info);
#else
cimage_t *
contents_image_ref_alloc(cimage_t *c, minfo_t *info,
                             slim_byte scale_type, slim_word res_id);
#endif /*USE_RESIZE_IMAGE_PEER*/

ccont_t *
contents_container_alloc(cm_t *cm, slim_char *id, slim_char *title,
                             slim_char *upnp_class, slim_char *full_path);

void
contents_image_ref_pinfo(cimage_t *inout_ref, minfo_t *in_minfo, slim_char *in_pinfo);

void
contents_jpeg_scale_calc (slim_word width, slim_word height,
                              struct jpeg_scale *scale, slim_int profile);

slim_bool
contents_image_ref_create(cm_t *cm, contents_t *c, cimage_t *ref, storage_config_t *usb_cfg);

void
contents_image_jpeg_ref_alloc (cimage_t *c, minfo_t *info);

slim_int
contents_container_free (ccont_t *container);

slim_int
contents_image_free (cimage_t *c);

slim_int
contents_image_ref_free(cimage_t *ref);

slim_int
contents_audio_free (caudio_t *c);

slim_int
contents_video_free (cvideo_t *c);

slim_int
contents_reference_free (cref_t *r);

slim_int
contents_base_free (contents_t *c);

slim_int
contents_free (contents_t *c);

#if defined (DEVELOPMENT_ENABLE_PUBLISH_STREAMING_CONTENT) || defined(DEVELOPMENT_CONTENT_AGGREGATION)
void
contents_res_free(cres_t *res);
#endif /* (DEVELOPMENT_ENABLE_PUBLISH_STREAMING_CONTENT) || (DEVELOPMENT_CONTENT_AGGREGATION) */

slim_char *
contents_full_path(slim_char *path, slim_char *file_name);

slim_bool
is_under_upload_directory (cm_t *cm, slim_char *full_path);

slim_int
contents_parse_object_id(slim_char* object_id, slim_char **items, slim_word *number);

slim_int
contents_get_usb_object_id(slim_char* object_id, slim_char **usb_id, slim_int* obj_id);

slim_int
contents_get_object_id_type_from_string(slim_char *object_id);

slim_int
contents_get_object_id_value_from_string(slim_char *id_buf);

contents_t *
contents_lookup_virtual_by_id(cm_t *cm, slim_char *id);

contents_t*
content_alloc_by_type(cm_t *cm, slim_int type);

slim_int
contents_storage_start_runtime_polling(cm_t* cm, storage_config_t* usb_cfg);

void
contents_storage_stop_runtime_polling(storage_config_t* usb_cfg);

vector
contents_child_init (ccont_t *c);

contents_type_t
contents_storage_get_media_class_type_by_suffix(slim_char* full_path);

void
contents_storage_free(contents_t** c);

ccont_t*
contents_storage_alloc_container(cm_t* cm, storage_config_t* usb_cfg, slim_int id, slim_char* full_path);

contents_t*
contents_storage_alloc_content(cm_t* cm, storage_config_t* usb_cfg, slim_int id, slim_char* full_path, slim_char *upnp_album);

contents_t*
contents_get_usb_container_by_id(cm_t*cm, slim_char* usb_id);

slim_char *
contents_get_object_storage_id(slim_char* device_id, content_object_id_type id_type, slim_int db_id);

slim_int
contents_modify_content_objectid(cm_t *cm, slim_char* parent_id, contents_t* c);

slim_word
contents_get_sqlite_id(cm_t *cm, slim_char *in_full_path, slim_char *parent_id);

contents_t *
contents_device_container_add(cm_t *cm, contents_t *parent, slim_char *device_uuid, slim_char *title, slim_char *full_path);

contents_t*
contents_add_virtual_container(cm_t *cm, contents_t *parent, slim_char *id, slim_char *title, slim_int content_type, slim_bool is_published_content);

slim_bool
createThumbnailFolderAndDefaultFile(cm_t *cm, slim_char *in_thumbnailPath);

#if defined(ENABLE_MPE_IMAGE_TRANSCODING) || defined(ENABLE_MPE_AUDIO_VIDEO_TRANSCODING)
slim_bool
createTranscodedFolder(slim_char *in_transcodedPath);
#endif /* defined(ENABLE_MPE_IMAGE_TRANSCODING) || defined(ENABLE_MPE_AUDIO_VIDEO_TRANSCODING) */

slim_bool
createJpegScaledFolder(cm_t *cm, slim_char *in_thumbnailPath);

void
contents_reference_get_reference_filename(slim_int org_media_id, slim_char* storage_id, slim_int ref_type, slim_char* out_title);

slim_int
contents_storage_del(cm_t *cm, contents_t* c);

creference_t*
contents_reference_alloc_reference(minfo_t *info, slim_int media_width, slim_int media_height, slim_int scale_type, slim_int ref_profile);

void
contents_reference_free_reference(creference_t* cref);

void
dlna_filename_escape(slim_char * filename);

slim_char*
contents_get_relpath(slim_char *full_path, slim_char *base_path);

slim_char*
contents_get_fullpath_from_relpath(slim_char *rel_path, slim_char* storage_device_path);

slim_char*
contents_get_album_art_full_from_rel(slim_char *rel_uri, slim_char* storage_device_path);

contents_t *
contents_child_lookup_title (contents_t *parent, slim_char *title);

contents_t *
contents_child_lookup_fullpath (ccont_t *p, slim_char *full_path);

slim_bool
contents_child_add(ccont_t *p, contents_t *c);

void
contents_child_delete (contents_t *c);

slim_bool
contents_child_is_added(ccont_t *p, contents_t *c);

/* Lookup contents by ID.  */
contents_t *
contents_lookup_by_id (cm_t *cm, slim_char *id);

contents_t *
contents_lookup_storage_by_id(cm_t * cm,
    cds_database_info * in_database,
    cds_db_get_content_storage_info * in_storage_info,
    slim_int in_id);

slim_int
contents_lookup_fullpath_by_id(cm_t *cm, slim_char *id, slim_char **full_path);

/* Lookup contents by name.  */
contents_t *
contents_lookup_by_name (cm_t *cm, slim_char *name);

#ifdef HAVE_DMS
/* Lookup contents by full path.  */
contents_t *
contents_lookup_storage_by_fullpath(cm_t * cm,
    cds_database_info * in_database,
    cds_db_get_content_storage_info * in_storage_info,
    slim_char * in_relative_path);

contents_t *
contents_lookup_by_fullpath (cm_t *cm, slim_char *in_full_path);
#endif

void
contents_upnp_albumArt_path_by_content_path(slim_char *full_path, slim_char ** name);

void
contents_check_and_delete_album_art(cds_database_info* database, slim_char *fullpath, storage_config_t* usb_cfg);

slim_bool
contents_check_album_art_name(slim_char *in_fileName, slim_char *in_folderName, slim_char *in_fullPath);

/* Check if the content is the top container.  */
slim_bool
contents_is_top (contents_t *c);

slim_bool
contents_is_virtual(contents_t *c);

slim_bool
contents_is_virtual_id(slim_char *content_id);

/* Create and set virtual ids(id and parent id).
 * If virtual_parent is slim_nil then parent will be set depends on content type, e.g:
 * if content is audio then container music_all wil be selected.
 */
slim_int
contents_set_virtual_ids(contents_t *c, contents_t *virtual_parent);

slim_char*
contents_get_virtual_id(slim_char *item_id, slim_char *virtual_parent_id);

slim_char*
contents_get_virtual_parent_id(slim_char* object_id);

/* Check content if it's transcoded one.  */
slim_bool
contents_is_transcoded (contents_t *c);

dlna_uint64
contents_get_size (contents_t *c);

slim_bool
is_absolute_name(slim_char *in_dirname);

/* Add the contents to the contents manager for uploading file.  */
contents_t *
contents_add_upload (cm_t *cm, contents_t *parent, minfo_t *info, slim_int *out_result);

/* Add the contents to the contents manager for uploading create folder.  */
contents_t *
contents_container_add_upload (cm_t *cm, contents_t *parent, slim_char *title);

/* Add the contents to the contents manager.  */
contents_t *
contents_add (cm_t *cm, contents_t *parent, minfo_t *info);

/* Delete the contents from the contents manager.  */
slim_bool
contents_delete (contents_t *c);

void
contents_manager_set_upload_metadata(contents_t *c);

void
contents_manager_unset_upload_metadata(contents_t *c);

/* Update the contents.  */
slim_bool
contents_upload_update (contents_t *c);

slim_int
contents_add_auto_delete_timer(void *in_arg);

/* reset auto delete timer for upload. */
void
contents_reset_auto_delete_timer (contents_t *c, slim_int in_sec);

slim_int
contents_manager_contents_tree_update(struct contents_manager *cm,
                            slim_char *in_path);

cm_t *
contents_manager_alloc (struct upnp_if_manager *ifm,
    slim_char *root_dir,
    slim_char *xml_dir,
    contents_port_value port_callback,
    void *info,
    access_config_t* access_cfg,
    contents_update_ids_proc update_ids_callback);

slim_int
contents_manager_flist_member_del(void *flist_header , dlna_flist_t *in_curr);

slim_int
contents_manager_free (cm_t *cm);

slim_int
contents_manager_start (cm_t *in_cm);

slim_int
contents_manager_stop (cm_t *in_cm);

#ifdef HAVE_DTCP
slim_int
contents_manager_set_drm_entry (cm_t *cm, drm_entry_t *in_dtcp_entry);

void
contents_manager_set_drm_proc (cm_t *cm, get_drm_info in_proc);

void
contents_manager_delete_drm_entry (cm_t *cm, slim_int in_type);

void
contents_manager_delete_drm_proc (cm_t *cm);
#endif /* HAVE_DTCP */

/* Callback function for peer directory change notification */
slim_int
contents_directory_change_notification (void *in_arg);

slim_char*
contents_get_field_str(contents_t *in_c, item_field_type_t in_field_type);

dlna_time_t
contents_get_field_time(contents_t *in_c, item_field_type_t in_field_type);

slim_bool
contents_manager_append_dir_to_usr (cm_t *cm);

/* New API for Publish Folder. (added. 04.Dec.2009) */
slim_int
contents_manager_container_add (cm_t *in_cm, slim_char *in_path);

slim_int
contents_manager_container_del (cm_t *in_cm, slim_char *in_path);

slim_int
contents_manager_contents_add (cm_t *in_cm, slim_char *in_path);

slim_int
contents_manager_contents_del (cm_t *in_cm, slim_char *in_path);

slim_int
contents_manager_set_default_upload_container (cm_t *in_cm, contents_t *c);

slim_char *
contents_manager_get_default_upload_container (cm_t *in_cm);

slim_int
contents_manager_contents_count (cm_t *in_cm);

contents_t *
contents_get_next_content (cm_t *in_cm, contents_t * in_c);

slim_bool
contents_manager_init_top (struct contents_manager *cm);

struct _sXML;
slim_bool
contents_manager_init_image (struct contents_manager *cm, struct _sXML *info_about_image_virtual_folders);

slim_bool
contents_manager_init_audio (struct contents_manager *cm, struct _sXML *info_about_audio_virtual_folders);

slim_bool
contents_manager_init_video (struct contents_manager *cm, struct _sXML *info_about_video_virtual_folders);

slim_int
contents_manager_get_service_reset_token (cm_t *in_cm);

void
contents_manager_reset (cm_t *in_cm);

enum search_match_result
contents_match (cds_search_exp_t *s_exp, void *arg);

enum search_match_result
contents_match_func (cds_search_exp_t *s_exp, slim_char *val);

slim_int
contents_change_process (cm_t *in_cm, void * contents_chg_list, slim_bool is_res_chg,
    cm_content_change_t change_type, contents_t *in_c, ccont_t *in_parent);

slim_char*
contents_get_artist_index(const slim_char in_char);

slim_int
contents_get_children_count_by_type(storage_config_t* uconf, slim_int parent_id,
                                    slim_int content_type, slim_int device_access_level);

slim_int
contents_get_parent_id_by_id(storage_config_t* uconf, slim_int id);

contents_t *
contents_manager_tree_contents_get_next_sibling (contents_t *in_c);

contents_t *
contents_manager_tree_contents_get_parent_sibling (contents_t *in_c);

contents_t *
contents_manager_contents_get_next (contents_t *in_c);

slim_int
dlnaDCNAllocPeerCallbackProc(void *in_arg);

#ifdef ENABLE_MOVIEDB_MOVIECOVER
void
contents_storage_save_moviecover_cb(moviedb_cb_params_t* moviedb_cb_params, sXML* in_doc);
#endif /*ENABLE_MOVIEDB_MOVIECOVER*/

slim_int
contents_set_share_content_by_type(cm_t* cm, slim_int type, slim_int shared_value);

/**
 * \par Function:
 * Change priority of indexing thread
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>cm</td>
 *     <td>Instance of content manager</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>priority</td>
 *     <td>Requested priority</td>
 *   </tr>
 *   <tr>
 *     <td>[out]</td>
 *     <td>None</td>
 *   </tr>
 * </table>
 * \return slim_true Success
 * \return slim_false Failure
 * \par Description
 * Change priority of indexing thread. Change is applied to thread in progress and any future runs.
 * \par Warning
 * Requested priority will be invalidated when change to policy is requested.\n Requested value may be invalid for current policy.
 */
slim_bool
contents_manager_set_indexing_thread_priority(cm_t * cm, slim_int priority);

/**
 * \par Function:
 * Change policy of indexing thread
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>cm</td>
 *     <td>Instance of content manager</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>policy</td>
 *     <td>Requested policy</td>
 *   </tr>
 *   <tr>
 *     <td>[out]</td>
 *     <td>None</td>
 *   </tr>
 * </table>
 * \return slim_true Success
 * \return slim_false Failure
 * \par Description
 * Change policy of indexing thread. Change is applied to thread in progress and any future runs.
 * \par Warning
 * Requested policy will invalidate requested priority.
 */
slim_bool
contents_manager_set_indexing_thread_policy(cm_t * cm, enum dlna_thread_policy policy);

#ifdef DEVELOPMENT_CONTENT_AGGREGATION
slim_bool
contents_manager_open_ca_db(cm_t *cm, slim_char *base_path);

void
contents_manager_close_ca_db(cm_t *cm);
#endif /* DEVELOPMENT_CONTENT_AGGREGATION */

#ifdef __cplusplus
}
#endif    /* __cplusplus */

#if defined(ENABLE_MPE_IMAGE_TRANSCODING) || defined(ENABLE_MPE_AUDIO_VIDEO_TRANSCODING)
slim_char *
get_usb_id(slim_char *id);

slim_char *
get_usb_path(contents_t *c);
#endif /* defined(ENABLE_MPE_IMAGE_TRANSCODING) || defined(ENABLE_MPE_AUDIO_VIDEO_TRANSCODING) */

slim_bool
content_check_if_item_fullpath_exists(cm_t* cm, slim_char* parent_fullpath, slim_char* item_path);

#ifdef DEVELOPMENT_ENABLE_PUBLISH_STREAMING_CONTENT
slim_int
contents_id_get (cm_t *cm);
slim_bool
contents_modify_streaming_content_uri(cm_t* cm, contents_t* c, slim_int ifindex);
#endif /*DEVELOPMENT_ENABLE_PUBLISH_STREAMING_CONTENT*/
#ifdef DEVELOPMENT_ENABLE_HTTP_STREAMING
contents_t *
contents_lookup_streamingcontent_by_name(cm_t *cm, slim_char *name);
#endif /*DEVELOPMENT_ENABLE_HTTP_STREAMING*/

cimage_t*
contents_storage_alloc_image(cm_t* cm, slim_char* device_id, slim_int id,
                             slim_char* full_path, minfo_t* info, slim_char *upnp_album);

caudio_t*
contents_storage_alloc_audio(cm_t* cm, slim_char* device_id, slim_int id,
                             slim_char* full_path, minfo_t* info, slim_char *upnp_album);

cvideo_t*
contents_storage_alloc_video(cm_t* cm, slim_char* device_id, slim_int id,
                             slim_char* full_path, minfo_t* info, slim_char *upnp_album);

cdocument_t*
contents_storage_alloc_document(cm_t* cm, slim_char* device_id, slim_int id,
                                slim_char* full_path, minfo_t* info, slim_char *upnp_album);

cplaylist_t*
contents_storage_alloc_playlist(cm_t* cm, slim_char* device_id, slim_int id,
                                slim_char* full_path, minfo_t* info, slim_char *upnp_album);

#ifdef DEVELOPMENT_ENABLE_CVP_SERVER_PLAYSPEED
/* Lookup filepath of Pre-scaled contents by original resource ID and playspeed.  */
slim_char *
contents_lookup_by_original_id_and_playspeed(contents_t *c, slim_int in_id, slim_char *in_speed);
#endif /* DEVELOPMENT_ENABLE_CVP_SERVER_PLAYSPEED */

void
updateRestrictedParam(slim_int uploadDeviceOption, slim_char** restricted);

void
updateDlnaManagedParam(slim_int uploadDeviceOption, slim_word* dlna_managed, slim_word support_ocm_type);
#endif /* NFLC_CONTENTS_H */
