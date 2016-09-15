/*
* storage_manager.h
* Copyright (C) 2009 ACCESS CO.,LTD.
* All rights are reserved by ACCESS CO.,LTD.,
* whether the whole or part of the source code
* including any modifications is concerned.
*
* This is an unpublished source code of ACCESS CO.,LTD., and must be
* treated as confidential material.  The above copyright notice does
* not evidence any actual or intended publication of this source code.
*/


#ifndef _STORAGE_MANAGER_H
#define _STORAGE_MANAGER_H

#include <nflc_cds_database.h>
#ifdef DEVELOPMENT_ENABLE_PUBLISH_CONTENT
#include <nflc_cds_publish.h>
#endif /*DEVELOPMENT_ENABLE_PUBLISH_CONTENT*/

struct upnp_server;

#define STORAGE_MANAGER_POLLING_PERIOD     (1)

#define IPC_MESSAGE_LEN             2048
#define IPC_MESSAGE_TYPE_ADD            "add"
#define IPC_MESSAGE_TYPE_REMOVE         "remove"
#define IPC_MESSAGE_LOCATION_CENTRAL    "central"
#define IPC_MESSAGE_LOCATION_LOCAL      "local"
#define STORAGE_MANAGER_UPDATE_DEL_RETRY  -9

#define STM_XML_TAG_STORAGEUPLOADPATH  "uploadPath"
#define STM_XML_TAG_STORAGELIST        "storageDeviceList"
#define STM_XML_TAG_STORAGEDEVICE      "storageDevice"
#define STM_XML_TAG_DEVICENAME         "deviceName"
#define STM_XML_TAG_DEVICEPATH         "devicePath"
#define STM_XML_TAG_DEVICEID           "deviceId"
#define STM_XML_TAG_READONLY           "readOnly"
#define STM_XML_TAG_AUTOINDEX          "autoIndex"
#define STM_XML_TAG_DATA_LOCATION_TYPE "dataLocationType"

#define STM_NEW_DEVICE_NAME_SEPARATOR "_"

typedef enum storage_manager_update_type
{
  STORAGE_MANAGER_UPDATE_ADD = 0x00,
  STORAGE_MANAGER_UPDATE_DEL
} storage_manager_update_type_t;

slim_int
storage_manager_update_event(slim_char *in_path, void *in_arg, dcn_reaction_type r_type);

typedef slim_int (*storage_manager_update_callback_t)(void *in_arg, slim_int in_type, slim_char *in_name, slim_char *in_id, slim_bool is_central, slim_char *in_full_path, slim_bool is_autoindex);

enum _storage_data_location
{
  STORAGE_DATA_LOCATION_CENTRAL,
  STORAGE_DATA_LOCATION_DEVICE
};
typedef enum _storage_data_location storage_data_location;

typedef struct storage_device {
  struct storage_device *next;
  struct storage_device *prev;
  slim_char* device_name;
  slim_char* device_path;
  slim_char* device_id;
  slim_char* device_data_location;
  slim_bool is_readOnly;
  slim_bool is_autoIndex;
  slim_int encryptionType;
} storage_device_t;


typedef struct storage_dcn {
  dlna_progress_handle e_timer;
  dlna_progress em;
  dlna_progress_callback pfn;
  void* in_arg;
  slim_word tWait;
} storage_dcn_t;

typedef struct storage_config {
  struct storage_config *next;
  struct storage_config *prev;

  slim_byte uuid[16];
  slim_char *device_name; /* device friendly name */
  slim_char *device_path; /* device path in operating system */
  slim_char *device_id;   /* device id set by the caller */
  slim_char *device_uuid; /* device uuid generated for each device */
  slim_int location_type; /* DATA Location Type */
  slim_char *data_dir;    /* DATA directory path */
  slim_int storage_device_db_id; /* DB index of storage entry */
  slim_bool readonly;     /* 1 if read only else 0 */
  slim_bool autoindex;    /* storage indexed automatically */
  slim_int rebuild_state;   /* 0: stop rebuilding, 1:rebuild, 2:rebuild ok, 3:rebuild error */
  storage_dcn_t dcn;
  slim_bool attached;
  slim_bool pending_delete;
  slim_bool pending_add;
  cds_database_info *main_database;
  cds_database_info *indexing_database;
  slim_bool database_wal_journal;
  struct storage_travel* st;
  slim_int indexing_ret_val;
  slim_bool is_upload;

#ifdef DEVELOPMENT_ENABLE_PUBLISH_CONTENT
  objectRights_t *storageObjectRights;
#endif /*DEVELOPMENT_ENABLE_PUBLISH_CONTENT*/

#ifdef ENABLE_DCN_INOTIFY

  dlna_dcn content_dcn;

  slim_word is_storage_registered_to_inotify;

#endif

} storage_config_t;

typedef struct storage_manager {

  /* Polling timer */
  dlna_progress_handle e_timer;

  struct upnp_server *us;
  
#ifdef ENABLE_STORAGE_LISTING
  slim_char* storage_list_filepath;
  slim_char* storage_list_upload_path;
  List(storage_device_t*) storage_published_list;
#endif /*ENABLE_STORAGE_LISTING*/


  List(storage_config_t *) storages;
  slim_char* central_location;

  storage_manager_update_callback_t  update_callback;

  void *callback_arg;

  slim_bool initialized;

  slim_int ipc_server_desc;
  dlna_progress_handle ipc_server_h;

  cds_database_info *central_database;
  slim_bool central_db_attached;
  slim_int central_db_ref_count;

} storage_manager_t;


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_bool storage_manager_tool_device_path_check(slim_char *in_path,slim_char *dev_path);
slim_int storage_manager_init(storage_manager_t *stm, struct upnp_server *us,
			      storage_manager_update_callback_t  update_callback, void *in_callback_arg);
void storage_manager_exit(storage_manager_t *stm);
slim_int storage_manager_register_poll_path(storage_manager_t *stm, slim_char *in_path);
slim_int storage_manager_unregister_poll_path(storage_manager_t *stm, slim_char *in_path);
slim_bool storage_manager_device_exists(storage_manager_t *stm, slim_char *in_name);
slim_bool storage_manager_is_initialized(storage_manager_t *stm);

#ifdef ENABLE_DCN_INOTIFY
  void storge_manager_stop_dcnInotify(storage_manager_t *stm);
#endif //ENABLE_DCN_INOTIFY

#ifdef ENABLE_STORAGE_LISTING
#ifdef DEVELOPMENT_ENABLE_PUBLISH_CONTENT
slim_int
storage_list_add_device(storage_manager_t *stm, storage_device_t* in_storage, objectRights_t *in_storageObjectRights);
slim_int
storage_list_update_device (storage_manager_t *stm, storage_device_t* in_storage, objectRights_t *in_storageObjectRights);
#else
slim_int
storage_list_add_device(storage_manager_t *stm, slim_char *in_path, slim_char* in_deviceId, slim_char* in_deviceName, slim_int in_locType, slim_bool in_readOnly, slim_bool in_autoIndex);
slim_int
storage_list_remove_device(storage_manager_t *stm, slim_char *in_path);
void
storage_manager_free_storage(storage_device_t *storage);
#endif //DEVELOPMENT_ENABLE_PUBLISH_CONTENT
#endif /*ENABLE_STORAGE_LISTING*/

slim_int
storageManager_setStorageCentralDir(struct dms* in_top, slim_char* in_central_dir);
void
storage_config_free(storage_manager_t *stm, storage_config_t* storage);
slim_int
storageManager_update_callback(void *in_arg, slim_int in_type, slim_char *in_name, slim_char *in_id, slim_bool is_central, slim_char *in_full_path, slim_bool is_autoindex);
slim_int
storageManager_storageDel(struct dms *top, slim_char *in_full_path);

slim_int
storage_manager_update_upload_path (storage_manager_t *stm, slim_char *in_path);

void
storage_manager_reset_upload_path(storage_manager_t *stm);

#ifdef DEVELOPMENT_ENABLE_PUBLISH_CONTENT
slim_int
storageManager_storageUpdate(struct dms* dms, storage_device_t *in_storage, objectRights_t *in_storageObjectRights);
slim_int
storageManager_storageAdd (struct dms *top, storage_device_t *in_storage, objectRights_t *in_storageObjectRights);
#else
slim_int
storageManager_storageAdd(struct dms *top, slim_char *in_full_path, slim_char *in_name, slim_char *in_id, slim_bool is_central, slim_bool is_auto_index);
#endif /*DEVELOPMENT_ENABLE_PUBLISH_CONTENT*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _STORAGE_MANAGER_H */
