/*
 * Copyright (C) 2011 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD., whether the whole or part
 * of the source code including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef _NFLC_WEBUI_CONTENTS_BROWSE_H_
#define _NFLC_WEBUI_CONTENTS_BROWSE_H_

typedef struct content_object_info_ {
  slim_char* parent_id;
  slim_char* id;
  slim_char* file_name; /* file name with relative path */
  slim_int   type;
  slim_int   shared_flag;
  slim_int   valid_flag;
  slim_int   child_count;
#ifdef ENABLE_PARENTAL_GUIDANCE
  slim_int   pg_value;
#endif
} content_object_info_t;


content_object_info_t*
content_object_info_alloc(void);
/* Free memory associated with structure content_object_info_t members. */
void
content_object_info_free(content_object_info_t* cinfo);


slim_int
contents_webUI_get_direct_children(storage_config_t* uconf, slim_int parent_id, slim_word limit, slim_word offset, content_object_info_t*** out_childern, slim_word* out_children_num, slim_word* total_matches);

slim_int
contents_webUI_get_content_info(storage_config_t* uconf, slim_int id, content_object_info_t** in_cinfo);

slim_int
contents_webUI_get_content_full_path(storage_config_t* uconf, slim_int id, slim_char** in_path);

#endif /* _NFLC_WEBUI_CONTENTS_BROWSE_H_ */
