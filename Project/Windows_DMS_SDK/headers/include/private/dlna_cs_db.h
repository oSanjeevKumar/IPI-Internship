/*
 * dlna_cs_db.h
 * Copyright (C) 2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */


/* content sync db entry. */

#ifndef _DLNA_CS_DB_H
#define _DLNA_CS_DB_H

#ifdef DLNA_SUPPORT_CSYNC

typedef enum {
  CSYNC_DB_OP_TYPE_SAVE,
  CSYNC_DB_OP_TYPE_LOAD
}csync_db_op_type_t;

typedef struct csync_db_index_header {
  slim_int signature;
  slim_int block_count;     /* total block count */
  unsigned char md5_digest[16];
}csync_db_header_t;

typedef struct csync_db_block_header {
  slim_int signature;
  slim_int size;
}csync_db_block_header_t;

typedef struct csync_db_ctx {
  dlna_file_t fp;
  slim_char *full_path;
  slim_int next_available;  /* next save block offset in file */
  csync_db_header_t  idx_header;
}csync_db_ctx_t;

typedef struct csync_db {
  csync_db_ctx_t common;
  csync_db_ctx_t local;
  csync_db_ctx_t remote;
}csync_db_t;

typedef struct csync_db_task_info {
  slim_char *title;
  slim_char *id;
  slim_char *home_dir;
  slim_int mode;
  slim_int direction;
  slim_int crp;
}csync_db_task_info_t;

typedef struct csync_db_task_contents_info {
  slim_word system_update_id;
  slim_char *udn;
}csync_db_task_contents_info_t;


void *
dlna_csync_db_alloc ();

void
dlna_csync_db_free (void *in_handle);

csync_return_t
dlna_csync_db_open (void *in_handle,  slim_char *in_name, slim_char *in_full_path, csync_db_op_type_t in_type);

void
dlna_csync_db_close(void *in_handle);

void 
dlna_csync_db_delete (slim_char *in_full_path, slim_char *in_name);

csync_return_t
dlna_csync_db_saving_task_contents_info (void *in_handle, csync_db_task_contents_info_t *in_info, slim_bool in_is_local);

csync_return_t
dlna_csync_db_saving_obj_info (void *in_handle, csync_obj_t *obj, slim_bool in_is_local);

csync_return_t
dlna_csync_db_saving_task_info (void *in_handle, csync_db_task_info_t *in_info);

csync_return_t
dlna_csync_db_loading_obj_info (void *in_handle, csync_obj_t **out_obj, slim_bool is_local);

csync_return_t
dlna_csync_db_loading_task_contents_info (void *in_handle, csync_db_task_contents_info_t *out_info, slim_bool in_is_local);

csync_return_t
dlna_csync_db_loading_task_info (void *in_handle, csync_db_task_info_t *out_info);

#endif /*DLNA_SUPPORT_CSYNC*/
#endif /*_DLNA_CS_DB_H*/
