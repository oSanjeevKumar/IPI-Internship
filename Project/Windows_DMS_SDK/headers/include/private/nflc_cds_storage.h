/*
 * nflc_cds_storage_utils.h
 * Copyright (C) 2007-2009 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2011. Access Company All Rights Reserved.  */
#ifndef NFLC_CDS_STORAGE_UTILS_H
#define NFLC_CDS_STORAGE_UTILS_H

void
storage_device_clear_unplugged_usb_config(cm_t* cm);

void
storage_device_remove_from_index_manager_list(cm_t* cm, storage_config_t* usb_cfg);

slim_bool
storage_device_is_first(cm_t *cm, storage_config_t* usb_cfg);

storage_config_t*
storage_device_get_first_device(cm_t *cm);

cds_database_info*
storage_device_get_first_database(cm_t *cm, slim_bool use_aggregated);

slim_int
storage_device_get_connected_databases_count(cm_t *cm, slim_bool use_aggregated);

slim_int
storage_device_get_connected_devices_count(cm_t *cm);

storage_config_t*
storage_device_get_by_id(cm_t *cm, slim_char* device_id);

storage_config_t*
storage_device_get_by_path(cm_t *cm, slim_char* device_path);

storage_config_t*
storage_device_get_usb_config_for_path(cm_t *cm, slim_char* path);

contents_t*
storage_device_get_device_content_central(cm_t* cm, storage_config_t* usb_cfg, slim_int db_id);

contents_t*
storage_device_get_device_content_local(cm_t* cm, storage_config_t* usb_cfg);

contents_t*
storage_device_alloc_device_content(cm_t* cm, storage_config_t* uconf);

contents_t*
storage_device_get_device_content_by_id(cm_t* cm, slim_char* usb_id);

slim_int 
storage_device_open_database_connection(storage_config_t* usb_cfg, slim_bool is_indexing, void* top);

slim_int
storage_device_create_database(storage_config_t* usb_cfg, slim_bool is_central);

void
storage_device_close_database_connection(storage_config_t* usb_cfg, slim_bool is_indexing);

slim_bool
storage_device_attach_database(cm_t* cm, storage_config_t* uconf);

slim_bool
storage_device_detach_database(cm_t* cm, storage_config_t* uconf);

void
storage_device_reattach_databases(cm_t *cm, storage_manager_t *stm);

#ifdef DEVELOPMENT_CONTENT_AGGREGATION
void
storage_device_attach_ca_db(cm_t *cm);

void
storage_device_detach_ca_db(cm_t *cm);
#endif /* DEVELOPMENT_CONTENT_AGGREGATION */

slim_int
storage_device_read_uuid_from_file(storage_config_t* usb_cfg);

slim_int
storage_device_save_uuid_file(storage_config_t* usb_cfg);

#ifdef ENABLE_IGNORE_FILE_IF_CRASH
slim_int
storage_device_read_ignored_from_file(storage_config_t* usb_cfg, slim_char* content_path, slim_int* count, slim_char* read_path);
slim_int
storage_device_save_ignored_file(storage_config_t* usb_cfg, slim_char* content_path);
slim_int
storage_device_clean_ignored_file(storage_config_t* usb_cfg);
#endif /* ENABLE_IGNORE_FILE_IF_CRASH */

slim_int
storage_device_central_validate_for_device_uuid(cds_database_info *db, slim_char *device_uuid);

slim_int
storage_device_central_invalidate_for_device_uuid(cds_database_info *db, slim_char *device_uuid);

slim_int
storage_device_central_invalidate_for_all(cds_database_info *db);

void
storage_device_fill_db_info(storage_config_t* usb_cfg,
    cds_db_get_content_storage_info *storage_info);

#endif /*NFLC_CDS_STORAGE_UTILS_H*/
