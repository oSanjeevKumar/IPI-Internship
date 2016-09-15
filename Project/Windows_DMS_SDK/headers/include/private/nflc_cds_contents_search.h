#ifndef _NFLC_CDS_CONTENTS_SEARCH_H_
#define _NFLC_CDS_CONTENTS_SEARCH_H_

enum {
  SEARCH_QUERY_TYPE_COUNT,
  SEARCH_QUERY_TYPE_CONTENT
};
typedef slim_int search_query_type;

#if 0
typedef struct metadata_property_map_
{
  slim_char* virtual_id;
  slim_char* property;
} metadata_property_map;
#endif 

slim_int
contents_search_get_all_searched_content(cm_t *cm, struct search_exp *s_exp,
    slim_word sindex, slim_word rcount, slim_word *matches, slim_word *total,
    TCDSSortParam *sort_param, vector results, slim_int client_access_level,
    extended_flags_t * ext_flags);

slim_int
contents_search_virtual_update(cm_t * cm, struct contents * parent,
    storage_manager_t * stm, extended_flags_t * ext_flags);

#endif /* _NFLC_CDS_CONTENTS_SEARCH_H_ */
