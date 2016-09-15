/*
 * nflc_cds_contents_index.h
 * Copyright (C) 2007-2014 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_CDS_CONTENTS_INDEX_H
#define NFLC_CDS_CONTENTS_INDEX_H

#include <dlna_vector.h>
#include "dlna_config.h"
#include <nflc_contents.h>

#define INDEX_TREE_ERROR          -1
#define INDEX_TREE_NO_SUCH_OBJECT -2
#define INDEX_TREE_OUT_OF_MEMORY  -65535
#define INDEX_TREE_OK              0
#define INDEX_TREE_NOT_FOUND       1       /* index file not found */
#define INDEX_TREE_BAD             2       /* index file bad */
#define INDEX_TREE_NODE_EXIST      3       /* node exist in index file */
#define INDEX_TREE_NODE_INVALID    4       /* node is invalid */
#define INDEX_TREE_NODE_NOT_FIND   5       /* node was not find in file */
#define INDEX_TREE_CANCELLED       6       /* operation cancelled */

#define IS_DEBUG_CTI          1

#define REBUILDING_CONTENT_TREE_INVALID    -1
#define REBUILDING_CONTENT_TREE_INIT        0
#define REBUILDING_CONTENT_TREE_END         1
#define REBUILDING_CONTENT_TREE_ERROR       2

#define CONTENTS_ITEM_EXISTS          0
#define CONTENTS_ITEM_INSERT          1
#define CONTENTS_ITEM_UPDATE          2
#ifdef ENABLE_SUBTITLE_SUPPORT
#define CONTENTS_ITEM_UPDATE_SUBTITLE 3
#endif /* ENABLE_SUBTITLE_SUPPORT */

#define REINDEX_STATE_FILE "/reindex_state.bin"

#define SUBSTRING_OF_THUMBNAIL_NAME DMS_THUMBNAIL_PATH"/.dms.scale.usb"

#ifdef DEVELOPMENT_ENABLE_CVP_SERVER_PLAYSPEED
#define DLNA_DMS_PLAYSPEED_PRE_SCALED_DIR SLIM_T("Scaled Files")
#endif /* DEVELOPMENT_ENABLE_CVP_SERVER_PLAYSPEED */

#define NFLC_CDS_REINDEXING_STATE_READWRITE_ERROR -1
#define NFLC_CDS_REINDEXING_STATE_READWRITE_OK     0

enum {
  NFLC_CDS_INDEXING_REBUILD_STARTED,
  NFLC_CDS_INDEXING_REBUILD_FINISHED,
  NFLC_CDS_INDEXING_REBUILD_CANCELLED,
  NFLC_CDS_INDEXING_REBUILD_NO_SPACE_ABORTED,
  NFLC_CDS_INDEXING_REBUILD_ERROR
};

typedef enum {
  NO_PARTIAL_INDEXING,
  PARTIAL_INDEXING_SIMPLE,
  PARTIAL_INDEXING_SHARE,
  PARTIAL_INDEXING_THUMBNAIL, 
#ifdef ENABLE_PARENTAL_GUIDANCE
  PARTIAL_INDEXING_PC,
#endif /* ENABLE_PARENTAL_GUIDANCE*/
  INDEXING_PARTIAL_THUMBNAILS_ALL,
  PARTIAL_INDEXING_DELETE
} contents_storage_indexing_type;

enum {
  NFLC_CDS_INDEXING_NOT_SUPPORTED = -3,
  NFLC_CDS_INDEXING_CONTENT_INVALID = -2,
  NFLC_CDS_INDEXING_ERROR = -1,
  NFLC_CDS_INDEXING_OK = 0,
  NFLC_CDS_INDEXING_CANCEL = 1,
  NFLC_CDS_INDEXING_END = 2,
  NFLC_CDS_INDEXING_DATABASE_ERROR = 3,
  NFLC_CDS_INDEXING_STORAGE_OUT_OF_MEMORY = 4
};

typedef slim_int contents_indexing_state;

enum contents_storage_indexing_state_type_{
  NFLC_CDS_STORAGE_INDEXING_UPNP,
  NFLC_CDS_STORAGE_INDEXING_METADATA,
  NFLC_CDS_STORAGE_INDEXING_REFERENCES,
#ifdef ENABLE_SUBTITLE_SUPPORT
  NFLC_CDS_STORAGE_INDEXING_SUBTITLE,
#endif
#ifdef DEVELOPMENT_ENABLE_PLAYLIST_CONTAINER
  NFLC_CDS_STORAGE_INDEXING_PLAYLIST,
#endif
  NFLC_CDS_STORAGE_INDEXING_NONE
};
typedef enum contents_storage_indexing_state_type_ contents_storage_indexing_state_type;

enum {
  NFLC_CDS_INDEXING_NO_PARTIAL,
  NFLC_CDS_INDEXING_PARTIAL_SIMPLE,
  NFLC_CDS_INDEXING_PARTIAL_SHARE,
  NFLC_CDS_INDEXING_PARTIAL_THUMBNAIL,
#ifdef ENABLE_PARENTAL_GUIDANCE
  NFLC_CDS_INDEXING_PARTIAL_PC,         /*Parental Control*/
#endif /* ENABLE_PARENTAL_GUIDANCE*/
  NFLC_CDS_INDEXING_PARTIAL_THUMBNAILS_ALL, /*triggering thumbnails creation after all partial indexing actions*/
  NFLC_CDS_INDEXING_PARTIAL_DELETE,
  NFLC_CDS_INDEXING_NONE
};
typedef slim_int contents_indexing_type;

enum {
  NFLC_CDS_CONTENTS_OBJECT_STATE_EXISTS,
  NFLC_CDS_CONTENTS_OBJECT_STATE_NEW_FOR_METADATA,
  NFLC_CDS_CONTENTS_OBJECT_STATE_NEEDS_UPDATE,
  NFLC_CDS_CONTENTS_OBJECT_STATE_UPDATE_SUBTITLE,
  NFLC_CDS_CONTENTS_OBJECT_STATE_NONE
};
typedef slim_int contents_item_state;

#if 0
typedef struct index_manager_index_list_item {
  struct index_manager_index_list_item *next;
  struct index_manager_index_list_item *prev;

  struct usb_config *usb_cfg;
  slim_byte partial_indexing_mode;
  slim_char *path_to_index;
  slim_int partial_indexing_share;
#ifdef ENABLE_PARENTAL_GUIDANCE
  slim_int partial_indexing_pc;
#endif /* ENABLE_PARENTAL_GUIDANCE */
} index_manager_index_list_item_t;
#endif

typedef struct content_index_object_info_ {
  slim_int object_id;
  slim_int parent_id;
  slim_char* storage_device_id;

//#ifdef DEVELOPMENT_ENABLE_PUBLISH_CONTENT
#ifdef DEVELOPMENT_PUBLISH_ONLINE_RECORDED_CONTENT_API
  slim_char* ext_id;
#endif /* DEVELOPMENT_PUBLISH_ONLINE_RECORDED_CONTENT_API */

  slim_int valid_flag;
  slim_int shared_flag;
  slim_int pg_value;
  slim_int media_class_type;
  slim_int media_type;
  slim_char* media_mime_type;
  dlna_time_t date;
  slim_word modtime;
  dlna_uint64 file_size;
  slim_char* path;
  slim_char* upnp_class;
  slim_char* dc_title;
  slim_char* dc_creator;
  slim_char* upnp_album;
  slim_char* upnp_genre;
  slim_char* upnp_artist;
  slim_char* res_uri;
  slim_char* res_pInfo;
  slim_char* restricted;
  slim_word  child_count;
  slim_bool reference_invalid;
  slim_bool is_container;
  slim_char* upnp_albumart_original;
  slim_int upnp_albumart_profile;
  slim_char* upnp_albumart_tn;
  slim_word width;
  slim_word height;
  slim_word lastPlayDate;
  slim_word playCount;
} content_index_object_info;


#ifdef DEVELOPMENT_CONTENT_AGGREGATION
typedef struct ca_content_object_info {
  content_index_object_info base;
  slim_char* refID;
  slim_char* track_no;
  slim_char* upnp_albumArtURI;
  slim_int   upnp_albumArtURI_profile;
  slim_word  dlnaManaged;
  slim_word  dlna_org_flags;
  slim_word  dlna_org_ifo_flag;
  slim_int   image_profile;
  cres_t*    res_original;
  List(cres_t*) converted_res_list;
} ca_content_object_info_t;
#endif /* DEVELOPMENT_CONTENT_AGGREGATION */

struct content_index_subtitle_
{
  slim_int id;
  slim_int video_id;
  slim_int folder_id;
  slim_int type;
  slim_int streamNo;
  slim_char* title;
  slim_char* language;
  slim_char* fullpath;
};
typedef struct content_index_subtitle_ content_index_subtitle;

/*! \struct storage_travel
 * \brief Structure holding all data needed for indexing
 *
 * This structure holds all data needed for indexing, pointer to usb config of device that should be indexed,
 * info about partial indexing if needed and so on.
 */
typedef struct storage_travel {
  struct contents_manager* cm;      /*! content manager */
  struct storage_config* usb_cfg;   /*! usb config of device that should be indexed */
  dlna_dir_t desc;                  /*! file descriptor that is processed at the moment */
  struct flist* curr_dir;           /*! current directory is processed at the moment */
  slim_int curr_dir_id;             /*! id of this directory, assigned after dir is already added to database, used as parent id for content inside this dir */
  List(struct flist *) dir_list;    /*! list of directories to be processed */
  slim_byte storage_indexing_state;  /*! if whole device, or just one item should be indexed */
  slim_byte partial_indexing_mode;  /*! if whole device, or just one item should be indexed */
  slim_char *path_to_index;         /*! path to be indexed, valid only with partial indexing */
  slim_int partial_indexing_share;  /*! share mode to be set with partial indexing */
#ifdef ENABLE_PARENTAL_GUIDANCE
  slim_int partial_indexing_pc;     /*! parental control value to be set with partial indexing */
#endif /* ENABLE_PARENTAL_GUIDANCE */
#ifdef DEVELOPMENT_ENABLE_PUBLISH_STREAMING_CONTENT
  streaming_info partial_indexing_streaming;
#endif /* DEVELOPMENT_ENABLE_PUBLISH_STREAMING_CONTENT */
  slim_int partial_indexing_id;
}storage_travel_t;

void
contents_index_add_item_to_idx_manager_list(cm_t* cm, index_manager_index_list_item_t* im_list_item);

slim_int
contents_index_storage_reindex(cm_t* cm, storage_config_t* usb_cfg);

slim_int
contents_index_start_index_manager(cm_t* cm);

slim_bool
contents_index_is_indexing_in_progress(cm_t* cm);

#ifdef MPE_ENABLE_EMBEDDED_SUBTITLE_SUPPORT
void
contents_index_free_subtitle_object(content_index_subtitle *subtitle);
#endif /* MPE_ENABLE_EMBEDDED_SUBTITLE_SUPPORT */

slim_int
contents_index_partial_reindex(cm_t* cm, storage_config_t* usb_cfg, slim_char* path_to_reindex, partial_indexing_data_t* partial_index);

void
contents_index_storage_travel_free(struct storage_travel* st);

slim_int
content_index_get_uploading_content_id(cm_t* cm, slim_char* fullpath, slim_char* parent_id, slim_int content_type);

slim_int
contents_index_storage_create_single_reference(cm_t* cm, storage_config_t *usb_cfg, slim_char* media_path, slim_bool is_indexing);

slim_int
contents_index_set_contents_share_info_by_fullpath(cm_t* cm, storage_config_t* usb_cfg, slim_char* full_path, slim_int id, slim_byte shared);

slim_int
contents_sqlite_to_upnp_error_code(slim_int database_error);

#ifdef ENABLE_PARENTAL_GUIDANCE
slim_int
contents_index_set_contents_pc_info_by_fullpath(cm_t* cm, storage_config_t* usb_cfg, slim_char* full_path, slim_int id, slim_byte parental_control);
#endif /*ENABLE_PARENTAL_GUIDANCE*/

#ifdef DEVELOPEMENT_PLAYED_UPDATE_ID
void
contents_handle_update_id_for_playlist_played(contents_t *c, cm_content_change_t ev_type);
#endif /* DEVELOPEMENT_PLAYED_UPDATE_ID */

#ifdef ENABLE_DCN_INOTIFY
slim_int
contents_index_delete_content_by_fullpath(cm_t* cm, storage_config_t* uconf, slim_char* content_path);

slim_int
contents_index_delete_content_by_id(cm_t* cm, storage_config_t* uconf, slim_int id);
#endif /*ENABLE_DCN_INOTIFY*/

slim_int
contents_index_partial_delete_content_by_id(cm_t* cm, storage_config_t* uconf, slim_int id, cds_database_info* database);

void
contents_index_normalize_string(slim_char *str);

void
contents_index_remove_if_control_chars(slim_char *in_str);

#ifdef DEVELOPMENT_ENABLE_INDEXING_OF_SHARES
slim_int
contents_index_usb_config(cm_t* cm, storage_config_t* usb_cfg);
#endif /*DEVELOPMENT_ENABLE_INDEXING_OF_SHARES*/

#ifdef MPE_ENABLE_EMBEDDED_SUBTITLE_SUPPORT
content_index_subtitle*
contents_index_alloc_subtitle_object(storage_travel_t* st, slim_char* full_path, slim_char* content_name, slim_int content_type, slim_int parent_id, video_subtitle_t* contents_subt, slim_int video_id);
#endif /*MPE_ENABLE_EMBEDDED_SUBTITLE_SUPPORT*/

slim_int
contents_index_prepare_playlist(cm_t * cm,
    cds_database_info * in_database,
    slim_char * in_device_path,
    slim_word in_device_path_length,
    slim_char * in_playlist_path,
    slim_int playlist_id);

/* The function frees the object data and the object itself */
void
contents_index_free_indexing_object(content_index_object_info* object);

#endif /*NFLC_CDS_CONTENTS_INDEX_H*/
