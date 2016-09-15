/*
 * Copyright (C) 2011 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD., whether the whole or part
 * of the source code including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef _NFLC_CDS_CONTENTS_BROWSE_H_
#define _NFLC_CDS_CONTENTS_BROWSE_H_

enum {
  BROWSE_QUERY_TYPE_COUNT,
  BROWSE_QUERY_TYPE_CONTENT
};
typedef slim_int browse_query_type;

typedef struct metadata_property_map_
{
  slim_char* virtual_id;
  slim_char* property;
} metadata_property_map;


slim_int
contents_browse_direct_children(cm_t *cm, storage_config_t* uconf,
    slim_int parent_id, slim_word sindex, slim_word rcount, slim_word *matches,
    slim_word *total_matches, vector results, TCDSSortParam *sort_param,
    slim_int device_access_level, slim_int content_type,
#ifdef DEVELOPMENT_ENABLE_PLAYLIST_CONTAINER
    slim_int parent_flags,
#endif /* DEVELOPMENT_ENABLE_PLAYLIST_CONTAINER */
    extended_flags_t * ext_flags);

slim_int
contents_browse_get_content_from_stmt(dlna_db_stmt database_stmt,
    cm_t *cm, slim_int content_type,
    slim_word *matches, slim_word *total_matches, vector results,
    extended_flags_t * ext_flags, slim_bool is_search);

slim_int
contents_browse_virtual_by_type_count(cm_t *cm, slim_int content_type, slim_word *total_matches, TCDSSortParam *sort_param,
        slim_int device_access_level);

slim_int
contents_browse_virtual_by_metadata_count(cm_t *cm, contents_t* parent, slim_int type, slim_char** id_segment, slim_int num, slim_word *total_matches, slim_int pg_value);

slim_int
contents_browse_virtual_storage_count(cds_database_info *database, contents_t *parent);

slim_int
contents_browse_storage_container_count(cds_database_info *database, contents_t *parent);

slim_int
contents_browse_virtual_by_type(cm_t *cm, slim_int content_type,
    slim_word sindex, slim_word rcount, slim_word *matches,
    slim_word *total_matches, TCDSSortParam *sort_param, vector results,
    slim_int device_access_level, extended_flags_t * ext_flags);

slim_int
contents_browse_virtual_by_metadata(cm_t* cm, contents_t* parent,
    slim_int content_type, slim_char** id_segment, slim_int num,
    TCDSSortParam *sort_param, slim_word sindex, slim_word rcount,
    slim_word *matches, slim_word *total_matches, vector results,
    slim_int pg_value, extended_flags_t * ext_flags);

slim_int
contents_browse_virtual_by_folder(cm_t* cm, contents_t* parent, slim_int type,
    slim_word sindex, slim_word rcount, slim_word *matches,
    slim_word *total_matches, TCDSSortParam *sort_param, vector results,
    slim_int pg_value, extended_flags_t * ext_flags);

slim_int
contents_get_children_common_album_properties(cm_t* cm, contents_t* c, slim_int pg_value, slim_char **genre, slim_char **creator, extended_flags_t * ext_flags);

slim_int
content_browse_get_content_count_by_type_by_device(storage_config_t* uconf, slim_int type, slim_int pg_value);

#ifdef DEVELOPMENT_ENABLE_VIRTUAL_PLAYLISTS
slim_int
contents_browse_virtual_playlist_count(cm_t *cm, slim_int type, slim_char** id_segment,
                                       slim_int num, slim_word *total_matches, slim_int pg_value);

slim_int
contents_browse_virtual_playlist(cm_t *cm, slim_int content_type,
    slim_char** id_segment, slim_int num, slim_word sindex, slim_word rcount,
    slim_word *matches, slim_word *total_matches, vector results,
    slim_int device_access_level, extended_flags_t * ext_flags);
#endif /* DEVELOPMENT_ENABLE_VIRTUAL_PLAYLISTS */

slim_int
contents_browse_get_shared_content_count_by_type(cm_t* cm, slim_int content_type);

#ifdef DEVELOPMENT_ENABLE_PUBLISH_STREAMING_CONTENT
slim_int
contents_browse_virtual_pvr_content(cm_t *cm, slim_word sindex, slim_word rcount, slim_word *matches, slim_word *total_matches,
                                    TCDSSortParam *sort_param, vector results, slim_int device_access_level);
slim_int
contents_browse_virtual_pvr_content_count(cm_t *cm, TCDSSortParam *sort_param, slim_int device_access_level);
slim_int
contents_browse_virtual_pvr_content_query(cm_t* cm, slim_char **out_query, slim_int query_type, TCDSSortParam *sort_param, slim_int pg_value);
#endif /*DEVELOPMENT_ENABLE_PUBLISH_STREAMING_CONTENT*/

#ifdef ENABLE_GPS_SUPPORT
slim_int
contents_browse_virtual_gps(cm_t *cm, slim_int content_type,
    slim_word sindex, slim_word rcount, slim_word *matches,
    slim_word *total_matches, TCDSSortParam *sort_param, vector results,
    slim_int device_access_level, extended_flags_t * ext_flags,
    browse_query_type query_type);

slim_int
contents_browse_virtual_gps_count(cm_t* cm, slim_int content_type,
    slim_word *total_matches, slim_int device_access_level);
#endif /* ENABLE_GPS_SUPPORT */

#endif /*_NFLC_CDS_CONTENTS_BROWSE_H_ */
