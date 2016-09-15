/*!
 Long path length.
 */

#ifndef NFLC_CONTENT_H
#define NFLC_CONTENT_H

#define LONG_PATH_LEN   1024

/*!
 Short path length.
 */

#define SHORT_PATH_LEN  256

/*!
 Object ID length.
 */
#define OBJ_ID_LEN  LONG_PATH_LEN

/*Info: This has to match with DMS value*/
#define CONTENT_TYPE_CONTAINER    1
#define CONTENT_TYPE_VIDEO        4
#define CONTENT_TYPE_AUDIO        3
#define CONTENT_TYPE_IMAGE        2
/*### End*/

typedef struct dlna_contents_child_obj
{
  slim_char obj_id[OBJ_ID_LEN]; /* Object ID, same as for browse */
  slim_char name[OBJ_ID_LEN]; /* Name of element */
  slim_int type; /* Elements type */
  slim_int shared; /* Element's shared flag */
  slim_char uri[OBJ_ID_LEN]; /* Element's URI */
  slim_int child_count;
#ifdef ENABLE_PARENTAL_GUIDANCE
  slim_int pc_level; /* Parental control level of element */
#endif /*ENABLE_PARENTAL_GUIDANCE */
#ifdef DEVELOPMENT_DMS_STORAGE_LAST_INDEX_TIME
slim_char device_id[OBJ_ID_LEN];
#endif /* DEVELOPMENT_DMS_STORAGE_LAST_INDEX_TIME */
} dlna_contents_child_obj_t;

typedef struct dlna_contents_tree_request
{
  slim_char obj_id[OBJ_ID_LEN];
  slim_int sindex;
  slim_int request_count;
} dlna_contents_tree_request_t;

typedef struct dlna_contents_tree_response
{
  slim_char parent_obj_id[OBJ_ID_LEN]; /* Current object's parent ID */
  slim_char obj_id[OBJ_ID_LEN]; /* Current object ID */
  slim_int response_count; /* Number of children on child_list */
  slim_int child_count; /* Overall number of selected element's children */
  dlna_contents_child_obj_t *child_list; /* List of children */
  slim_char mount_path[OBJ_ID_LEN]; /* TODO: obsolete, subject to remove */
  slim_char relative_path[OBJ_ID_LEN]; /* Relative path of current selected element */
} dlna_contents_tree_response_t;

#ifdef ENABLE_PARENTAL_GUIDANCE

typedef struct dlna_contents_pg_obj
{
  slim_char obj_id[OBJ_ID_LEN];
  slim_char pc_level;
} dlna_contents_pg_obj_t;

#endif /* ENABLE_PARENTAL_GUIDANCE */

typedef struct dlna_dms_content_obj
{
  slim_char obj_id[OBJ_ID_LEN];
  slim_char shared;
  slim_char recursive;
} dlna_dms_content_obj_t;

typedef struct parental_guidance_level_info_ext
{
  struct parental_guidance_level_info_ext *next;
  struct parental_guidance_level_info_ext *prev;
  slim_int parental_guidance_level; /*! parental guidance level */
  slim_char *name; /*! level name */
  slim_char *description; /*! level description */
} parental_guidance_level_info_ext_t;

typedef struct parental_control_device_ext
{
  struct parental_control_device_ext *next;
  struct parental_control_device_ext *prev;
  slim_char *desc; /*! device description */
  slim_char *mac_addr; /*! device MAC address */
  slim_int access_level; /*! device access level */
  slim_int dev_delete; /*! 1 = delete the device entry, 0 = don't delete */
  slim_int socket_descriptor;
} parental_control_device_ext_t;

#endif /* NFLC_CONTENT_H */
