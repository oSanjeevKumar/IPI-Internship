/*
 * webui_interface.h
 * Copyright (C) 2011 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef __WEBUI_INTERFACE_H__
#define __WEBUI_INTERFACE_H__

#include <dlna_peer.h>

/*!
WebUI server listening port number.
*/

#define WEBUI_PORT_NUMBER 5566

/*!
WebUI server IP address.
*/

#define WEBUI_SERVER_ADDR "127.0.0.1"

/*!
Long path length.
*/

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

/*storage rebuild states*/
#define USB_STORAGE_REBUILD_CANCEL  -2
#define USB_STORAGE_REBUILD_ERR   -1
#define USB_STORAGE_REBUILDING  1
#define USB_STORAGE_REBUILD_OK  100

/* Indexing types */
#define INDEXING_NO_PARTIAL 0
#define INDEXING_PARTIAL_SIMPLE 1
#define INDEXING_PARTIAL_SHARE 2  /*Media Share */
#define INDEXING_PARTIAL_PC 4 /*Parental Control */
#define INDEXING_NONE 7

/* Indexing states */
#define INDEXING_STATE_INDEXING 0
#define INDEXING_STATE_DONE 1
#define INDEXING_STATE_ABORTED 2
#define INDEXING_STATE_UNKNOWN 3

#define IPC_ERR(x)   printf x
#define IPC_DP(x)    printf x
#define IPC_MSG(x)   printf x

/* ------- Until here ---------------------------------- */

typedef struct dlna_contents_child_obj
{
  char obj_id[OBJ_ID_LEN];  /* Object ID, same as for browse */
  char name[OBJ_ID_LEN];  /* Name of element */
  int type; /* Elements type */
  int shared; /* Element's shared flag */
  char uri[OBJ_ID_LEN]; /* Element's URI */
  int child_count;
#ifdef ENABLE_PARENTAL_GUIDANCE
  int pc_level; /* Parental control level of element */
#endif /*ENABLE_PARENTAL_GUIDANCE */
#ifdef DEVELOPMENT_DMS_STORAGE_LAST_INDEX_TIME
  char device_id[OBJ_ID_LEN];
#endif /* DEVELOPMENT_DMS_STORAGE_LAST_INDEX_TIME */
} dlna_contents_child_obj_t;

/*!	
dlna_contents_child_obj_t is the structure used to store content child object 
information.

\code

typedef struct dlna_contents_child_obj {
  char obj_id[OBJ_ID_LEN];
  char name[OBJ_ID_LEN];
  unsigned char type;
  unsigned char shared;
  char uri[OBJ_ID_LEN];
#ifdef ENABLE_PARENTAL_GUIDANCE
  unsigned char pc_level;
#endif
#ifdef DEVELOPMENT_DMS_STORAGE_LAST_INDEX_TIME
  char device_id[OBJ_ID_LEN];
#endif
} dlna_contents_child_obj_t;

\endcode

\par Member: 

<table>
	<tr>
		<td>obj_id</td>
		<td>Object ID, same as for browse</td>
	</tr>
	<tr>
		<td>name</td>
		<td>Name of element</td>
	</tr>
	<tr>
		<td>type</td>
		<td>Element's type</td>
	</tr>
	<tr>
		<td>shared</td>
		<td>Element's shared flag</td>
	</tr>
	<tr>
		<td>uri</td>
		<td>Element's URI</td>
	</tr>
	<tr>
		<td>pc_level</td>
		<td>Parental control level of element</td>
	</tr>
	<tr>
		<td>device_id</td>
		<td>Device id of the element</td>
	</tr>
</table>

*/

typedef struct dlna_contents_tree_request
{
  char obj_id[OBJ_ID_LEN];
  int sindex;
  int request_count;
} dlna_contents_tree_request_t;

/*!	
dlna_contents_tree_request_t is the structure used to store content tree request 
information.

\code

typedef struct dlna_contents_tree_request {
  char obj_id[OBJ_ID_LEN];
  int  sindex;
  int  request_count;
} dlna_contents_tree_request_t;

\endcode

\par Member: 

<table>
	<tr>
		<td>obj_id</td>
		<td>Object ID, same as for browse</td>
	</tr>
	<tr>
		<td>sindex</td>
		<td>Starting index</td>
	</tr>
	<tr>
		<td>request_count</td>
		<td>Number of elements requested</td>
	</tr>
</table>

*/

typedef struct dlna_contents_tree_response
{
  char parent_obj_id[OBJ_ID_LEN]; /* Current object's parent ID */
  char obj_id[OBJ_ID_LEN];  /* Current object ID */
  int response_count; /* Number of children on child_list */
  int child_count;  /* Overall number of selected element's children */
  dlna_contents_child_obj_t *child_list;  /* List of children */
  char mount_path[OBJ_ID_LEN];  /* TODO: obsolete, subject to remove */
  char relative_path[OBJ_ID_LEN]; /* Relative path of current selected element */
} dlna_contents_tree_response_t;

/*!	
dlna_contents_tree_response_t is the structure used to store content tree 
response information.

\code

typedef struct dlna_contents_tree_response {
  char parent_obj_id[OBJ_ID_LEN];
  char obj_id[OBJ_ID_LEN];
  int response_count;
  int child_count;
  dlna_contents_child_obj_t* child_list;
  char mount_path[OBJ_ID_LEN];
  char relative_path[OBJ_ID_LEN];
} dlna_contents_tree_response_t;

\endcode

\par Member: 

<table>
	<tr>
		<td>parent_obj_id</td>
		<td>Current object's parent ID</td>
	</tr>
	<tr>
		<td>obj_id</td>
		<td>Current object ID</td>
	</tr>
	<tr>
		<td>response_count</td>
		<td>Number of children on child_list</td>
	</tr>
	<tr>
		<td>child_count</td>
		<td>Overall number of selected element's children</td>
	</tr>
	<tr>
		<td>child_list</td>
		<td>List of children</td>
	</tr>
	<tr>
		<td>mount_path</td>
		<td>deprecated</td>
	</tr>
	<tr>
		<td>relative_path</td>
		<td>Relative path of current selected element</td>
	</tr>
</table>

*/

#ifdef ENABLE_PARENTAL_GUIDANCE

typedef struct dlna_contents_pg_obj
{
  char obj_id[OBJ_ID_LEN];
  unsigned char pc_level;
} dlna_contents_pg_obj_t;

/*!	
dlna_contents_pg_obj_t is the structure used to store content PG level information.

\code

typedef struct dlna_contents_pg_obj {
  char obj_id[OBJ_ID_LEN];
  unsigned char pc_level;
} dlna_contents_pg_obj_t;

\endcode

\par Member: 

<table>
	<tr>
		<td>obj_id</td>
		<td>Content object ID</td>
	</tr>
	<tr>
		<td>pc_level</td>
		<td>PG level of the content</td>
	</tr>
</table>

*/

#endif /* ENABLE_PARENTAL_GUIDANCE */

typedef struct dlna_dms_content_obj
{
  char obj_id[OBJ_ID_LEN];
  unsigned char shared;
  unsigned char recursive;
} dlna_dms_content_obj_t;

/*!	
dlna_dms_content_obj_t is the structure used to store content sharing information.

\code

typedef struct dlna_dms_content_obj {
  char obj_id[OBJ_ID_LEN];
  unsigned char shared;
  unsigned char recursive;
} dlna_dms_content_obj_t;

\endcode

\par Member: 

<table>
	<tr>
		<td>obj_id</td>
		<td>Content object ID</td>
	</tr>
	<tr>
		<td>shared</td>
		<td>Content share flag</td>
	</tr>
	<tr>
		<td>recursive</td>
		<td>Content share recursive flag</td>
	</tr>
</table>

*/

typedef struct parental_guidance_level_info_ext
{
  struct parental_guidance_level_info_ext *next;
  struct parental_guidance_level_info_ext *prev;
  int parental_guidance_level;  /*! parental guidance level */
  char *name; /*! level name */
  char *description;  /*! level description */
} parental_guidance_level_info_ext_t;

/*!	
parental_guidance_level_info_ext_t is the structure used to store PG information.

\code

typedef struct parental_guidance_level_info_ext {
  struct parental_guidance_level_info_ext* next;
  struct parental_guidance_level_info_ext* prev;
  int parental_guidance_level;
  char *name;
  char *description;
} parental_guidance_level_info_ext_t;

\endcode

\par Member: 

<table>
	<tr>
		<td>next</td>
		<td>Pointer to next PG level</td>
	</tr>
	<tr>
		<td>prev</td>
		<td>Pointer to previous PG level</td>
	</tr>
	<tr>
		<td>parental_guidance_level</td>
		<td>PG level</td>
	</tr>
	<tr>
		<td>name</td>
		<td>PG level name</td>
	</tr>
	<tr>
		<td>description</td>
		<td>PG level description</td>
	</tr>
</table>

*/

typedef struct parental_control_device_ext
{
  struct parental_control_device_ext *next;
  struct parental_control_device_ext *prev;
  char *desc; /*! device description */
  char *mac_addr; /*! device MAC address */
  int access_level; /*! device access level */
  int dev_delete; /*! 1 = delete the device entry, 0 = don't delete */
  int socket_descriptor;
} parental_control_device_ext_t;

/*!	
parental_control_device_ext_t is the structure used to store PG device information.

\code

typedef struct parental_control_device_ext
{
  struct parental_control_device_ext* next;
  struct parental_control_device_ext* prev;
  char * desc;
  char * mac_addr;
  int access_level;
  int dev_delete;
  int socket_descriptor;
} parental_control_device_ext_t;

\endcode

\par Member: 

<table>
	<tr>
		<td>next</td>
		<td>Pointer to next PG device</td>
	</tr>
	<tr>
		<td>prev</td>
		<td>Pointer to previous PG device</td>
	</tr>
	<tr>
		<td>desc</td>
		<td>PG device description</td>
	</tr>
	<tr>
		<td>mac_addr</td>
		<td>PG device mac address</td>
	</tr>
	<tr>
		<td>access_level</td>
		<td>PG device access level</td>
	</tr>
	<tr>
		<td>dev_delete</td>
		<td>PG device deletion flag</td>
	</tr>
	<tr>
		<td>socket_descriptor</td>
		<td>PG device connected socket descriptor</td>
	</tr>
</table>

*/

/*!
\par Function:
Gets friendly name.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>in_max_str_size</td>
		<td>Size of the buffer 'out_friendly_name'</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_friendly_name</td>
		<td>On success, friendly name will be available in this buffer</td>
	</tr>
</table>
\return Error code.
\par Return Values:
<table>
	<tr>
		<td> \b Error Code</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>Lessthan 0</td>
		<td>Failed to get friendly name</td>
	</tr>
	<tr>
		<td>Is equal to 0</td>
		<td>Successfully got friendly name</td>
	</tr>
</table>
*/

int HTTPSRV_PEER_DMS_GetFriendlyName (char *out_friendly_name, int in_max_str_size);

/*!
\par Function:
Sets friendly name.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>in_friendly_name</td>
		<td>friendly name</td>
	</tr>
</table>
\return Error code.
\par Return Values:
<table>
	<tr>
		<td> \b Error Code</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>Lessthan 0</td>
		<td>Friendly name set failed</td>
	</tr>
	<tr>
		<td>Is equal to 0</td>
		<td>Friendly name set success</td>
	</tr>
</table>
*/

int HTTPSRV_PEER_DMS_SetFriendlyName (char *in_friendly_name);

int HTTPSRV_PEER_DMS_GetStorages (char *out_path, int in_max_str_size);
/*!
browse request information

\code

typedef struct browse_request_info
{
  char *id;
  char *startIndex;
  char *requestedCount;
} browse_request_info_t;

\endcode

\par Member:

<table>
	<tr>
		<td>id</td>
		<td>Object ID to browse</td>
	</tr>
	<tr>
		<td>startIndex</td>
		<td>Start index of browse command</td>
	</tr>
	<tr>
		<td>requestedCount</td>
		<td>Number of elements in browse answer</td>
	</tr>
</table>

*/

typedef struct browse_request_info
{
  char *id;
  char *startIndex;
  char *requestedCount;
} browse_request_info_t;

typedef struct search_request_info
{
  char *id;
  char *startIndex;
  char *requestedCount;
  char *requestedTitle;
} search_request_info_t;

/*!
\par Function:
Execute cds browse.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>browse_request_info_t</td>
		<td>Browse request information</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_result</td>
		<td>On success, browse result will be available in this buffer</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_max_str_size</td>
		<td>Size of out_result</td>
	</tr>
</table>
\return Error code.
\par Return Values:
<table>
	<tr>
		<td> \b Error Code</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>Lessthan 0</td>
		<td>Browse failed</td>
	</tr>
	<tr>
		<td>Is equal to 0</td>
		<td>Browse success</td>
	</tr>
</table>
*/
int HTTPSRV_PEER_DMS_cdsBrowse (browse_request_info_t * browse_request, char **out_result, int in_max_str_size);
int HTTPSRV_PEER_DMS_cdsSearch (search_request_info_t * search_request, char **out_result, int in_max_str_size);

/*!
\par Function:
Gets number of image files shared.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>in_max_str_size</td>
		<td>Size of the buffer 'out_result'</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_result</td>
		<td>On success, number of image files shared will be available in this buffer</td>
	</tr>
</table>
\return Error code.
\par Return Values:
<table>
	<tr>
		<td> \b Error Code</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>Lessthan 0</td>
		<td>Failed</td>
	</tr>
	<tr>
		<td>Is equal to 0</td>
		<td>Success</td>
	</tr>
</table>
*/
slim_int HTTPSRV_PEER_DMS_GetImagesShared (slim_char * out_result, slim_int in_max_str_size);

/*!
\par Function:
Gets number of audio files shared.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>in_max_str_size</td>
		<td>Size of the buffer 'out_result'</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_result</td>
		<td>On success, number of audio files shared will be available in this buffer</td>
	</tr>
</table>
\return Error code.
\par Return Values:
<table>
	<tr>
		<td> \b Error Code</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>Lessthan 0</td>
		<td>Failed</td>
	</tr>
	<tr>
		<td>Is equal to 0</td>
		<td>Success</td>
	</tr>
</table>
*/
slim_int HTTPSRV_PEER_DMS_GetAudiosShared (slim_char * out_result, slim_int in_max_str_size);

/*!
\par Function:
Gets number of video files shared.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>in_max_str_size</td>
		<td>Size of the buffer 'out_result'</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_result</td>
		<td>On success, number of video files shared will be available in this buffer</td>
	</tr>
</table>
\return Error code.
\par Return Values:
<table>
	<tr>
		<td> \b Error Code</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>Lessthan 0</td>
		<td>Failed</td>
	</tr>
	<tr>
		<td>Is equal to 0</td>
		<td>Success</td>
	</tr>
</table>
*/
slim_int HTTPSRV_PEER_DMS_GetVideosShared (slim_char * out_result, slim_int in_max_str_size);

/*!
\par Function:
Gets number of document files shared.
\par Parameters:
<table>
  <tr>
    <td>[in]</td>
    <td>in_max_str_size</td>
    <td>Size of the buffer 'out_result'</td>
  </tr>
  <tr>
    <td>[out]</td>
    <td>out_result</td>
    <td>On success, number of document files shared will be available in this buffer</td>
  </tr>
</table>
\return Error code.
\par Return Values:
<table>
  <tr>
    <td> \b Error Code</td>
    <td> \b Meaning</td>
  </tr>
  <tr>
    <td>Lessthan 0</td>
    <td>Failed</td>
  </tr>
  <tr>
    <td>Is equal to 0</td>
    <td>Success</td>
  </tr>
</table>
*/
int HTTPSRV_PEER_DMS_GetDocumentsShared (slim_char * out_result, slim_int in_max_str_size);

/*!
\par Function:
Gets number of play lists shared.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>in_max_str_size</td>
		<td>Size of the buffer 'out_result'</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_result</td>
		<td>On success, number of play lists shared will be available in this buffer</td>
	</tr>
</table>
\return Error code.
\par Return Values:
<table>
	<tr>
		<td> \b Error Code</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>Lessthan 0</td>
		<td>Failed</td>
	</tr>
	<tr>
		<td>Is equal to 0</td>
		<td>Success</td>
	</tr>
</table>
*/
slim_int HTTPSRV_PEER_DMS_GetPlaylistsShared (slim_char * out_result, slim_int in_max_str_size);

/*!
\par Function:
Gets manufacturer name.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>in_max_str_size</td>
		<td>Size of the buffer 'out_manufacturer'</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_manufacturer</td>
		<td>On success, manufacturer name will be available in this buffer</td>
	</tr>
</table>
\return Error code.
\par Return Values:
<table>
	<tr>
		<td> \b Error Code</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>Lessthan 0</td>
		<td>Manufacturer name get failed</td>
	</tr>
	<tr>
		<td>Is equal to 0</td>
		<td>Manufacturer name get success</td>
	</tr>
</table>
*/

int HTTPSRV_PEER_DMS_GetManufacturer (char *out_manufacturer, int in_max_str_size);

/*!
\par Function:
Gets model name.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>in_max_str_size</td>
		<td>Size of the buffer 'out_model_name'</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_model_name</td>
		<td>On success, model name will be available in this buffer</td>
	</tr>
</table>
\return Error code.
\par Return Values:
<table>
	<tr>
		<td> \b Error Code</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>Lessthan 0</td>
		<td>Model name get failed</td>
	</tr>
	<tr>
		<td>Is equal to 0</td>
		<td>Model name get success</td>
	</tr>
</table>
*/

int HTTPSRV_PEER_DMS_GetModelName (char *out_model_name, int in_max_str_size);

/*!
\par Function:
Gets model number.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>out_model_number_size</td>
		<td>Size of the buffer 'out_model_number'</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_model_number</td>
		<td>On success, model number will be available in this buffer</td>
	</tr>
</table>
\return Error code.
\par Return Values:
<table>
	<tr>
		<td> \b Error Code</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>Lessthan 0</td>
		<td>Model number get failed</td>
	</tr>
	<tr>
		<td>Is equal to 0</td>
		<td>Model number get success</td>
	</tr>
</table>
*/

int HTTPSRV_PEER_DMS_GetModelNumber (char *out_model_number, int out_model_number_size);

/*!
\par Function:
Gets model URL.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>out_model_url_size</td>
		<td>Size of the buffer 'out_model_url'</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_model_url</td>
		<td>On success, model URL will be available in this buffer</td>
	</tr>
</table>
\return Error code.
\par Return Values:
<table>
	<tr>
		<td> \b Error Code</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>Lessthan 0</td>
		<td>Model URL get failed</td>
	</tr>
	<tr>
		<td>Is equal to 0</td>
		<td>Model URL get success</td>
	</tr>
</table>
*/

int HTTPSRV_PEER_DMS_GetModelUrl (char *out_model_url, int out_model_url_size);

/*!
\par Function:
Gets server state.
\par Parameters:
<table>
	<tr>
		<td>[out]</td>
		<td>out_server_state</td>
		<td>On success, server state is available here</td>
	</tr>
</table>
\return Error code.
\par Return Values:
<table>
	<tr>
		<td> \b Error Code</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>Lessthan 0</td>
		<td>Fail</td>
	</tr>
	<tr>
		<td>Is equal to 0</td>
		<td>Success</td>
	</tr>
</table>
*/

int HTTPSRV_PEER_DMS_GetServerState (int *out_server_state);

/*!
\par Function:
Sets server state.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>in_server_state</td>
		<td>Server state: 1 = Enable, 0 = Disable</td>
	</tr>
</table>
\return Error code.
\par Return Values:
<table>
	<tr>
		<td> \b Error Code</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>Lessthan 0</td>
		<td>Failed</td>
	</tr>
	<tr>
		<td>Is equal to 0</td>
		<td>Success</td>
	</tr>
</table>
*/

int HTTPSRV_PEER_DMS_SetServerState (int in_server_state);

/*!
\par Function:
Gets indexing mode.
\par Parameters:
<table>
	<tr>
		<td>[out]</td>
		<td>out_index_mode</td>
		<td>On success, indexing mode will be available here</td>
	</tr>
</table>
\return Error code.
\par Return Values:
<table>
	<tr>
		<td> \b Error Code</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>Lessthan 0</td>
		<td>Failed</td>
	</tr>
	<tr>
		<td>Is equal to 0</td>
		<td>Success</td>
	</tr>
</table>
*/

int HTTPSRV_PEER_DMS_GetIndexMode (int *out_index_mode);

/*!
\par Function:
Sets indexing mode.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>in_index_mode	</td>
		<td>New index mode</td>
	</tr>
</table>
\return Error code.
\par Return Values:
<table>
	<tr>
		<td> \b Error Code</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>Lessthan 0</td>
		<td>Failed</td>
	</tr>
	<tr>
		<td>Is equal to 0</td>
		<td>Success</td>
	</tr>
</table>
*/

int HTTPSRV_PEER_DMS_SetIndexMode (int in_index_mode);

/*!
\par Function:
Triggers indexing.
\par Parameters:
<table>
</table>
\return Error code.
\par Return Values:
<table>
	<tr>
		<td> \b Error Code</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>Lessthan 0</td>
		<td>Failed</td>
	</tr>
	<tr>
		<td>Is equal to 0</td>
		<td>Success</td>
	</tr>
</table>
*/

int HTTPSRV_PEER_DMS_RefreshContents (void);

/*!
\par Function:
Cancels triggered indexing.
\par Parameters:
<table>
</table>
\return Error code.
\par Return Values:
<table>
	<tr>
		<td> \b Error Code</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>Lessthan 0</td>
		<td>Failed</td>
	</tr>
	<tr>
		<td>Is equal to 0</td>
		<td>Success</td>
	</tr>
</table>
*/

int HTTPSRV_PEER_DMS_CancelRefreshContents (void);

int HTTPSRV_PEER_DMS_GetRefreshState (void);

/*!
\par Function:
Sets content sharing or non-sharing.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>in_content_obj</td>
		<td>Object id, share/no-share, recursive values are supplied</td>
	</tr>
</table>
\return Error code.
\par Return Values:
<table>
	<tr>
		<td> \b Error Code</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>Lessthan 0</td>
		<td>Failed</td>
	</tr>
	<tr>
		<td>Is equal to 0</td>
		<td>Success</td>
	</tr>
</table>
*/

int HTTPSRV_PEER_DMS_SetContentShare (dlna_dms_content_obj_t * in_content_obj);

int HTTPSRV_PEER_DMS_GetStreamingSessionsLimit (int *out_session_count);

int HTTPSRV_PEER_DMS_SetStreamingSessionsLimit (int in_session_count);

#ifdef DEVELOPMENT_CONTENT_AGGREGATION

typedef struct ca_device_obj
{
  struct ca_device_obj *prev;
  struct ca_device_obj *next;
  char *name; /*! device friendly name */
  char *uuid; /*! device uuid */
  int index;  /*! device indexing mode */
} ca_device_obj_t;

int HTTPSRV_PEER_DMS_IsCAEnabled (int * out_ca_enabled);

int HTTPSRV_PEER_DMS_SetCAEnabled (int in_ca_enable);

int HTTPSRV_PEER_DMS_GetCADatabaseMode (int * out_val);

int HTTPSRV_PEER_DMS_SetCADatabaseMode (int in_val);

int HTTPSRV_PEER_DMS_GetCADatabasePath (char * out_path, int in_max_str_size);

int HTTPSRV_PEER_DMS_SetCADatabasePath (char * in_path);

int HTTPSRV_PEER_DMS_GetCAIndexMode (int * out_val);

int HTTPSRV_PEER_DMS_SetCAIndexMode (int in_val);

int HTTPSRV_PEER_DMS_GetCADeviceList (ca_device_obj_t ** out_list);

int HTTPSRV_PEER_DMS_SetCADeviceIndexMode (char * in_uuid, int in_val);

int HTTPSRV_PEER_DMS_GetCADatabaseSizeLimit (int * out_val);

int HTTPSRV_PEER_DMS_SetCADatabaseSizeLimit (int in_val);

int HTTPSRV_PEER_DMS_GetCARescanInterval (int * out_val);

int HTTPSRV_PEER_DMS_SetCARescanInterval (int in_val);

#endif /* DEVELOPMENT_CONTENT_AGGREGATION */

#ifdef ENABLE_PARENTAL_GUIDANCE

/*!
\par Function:
Sets content PG level.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>in_request</td>
		<td>Object id and PG level are supplied</td>
	</tr>
</table>
\return Error code.
\par Return Values:
<table>
	<tr>
		<td> \b Error Code</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>Lessthan 0</td>
		<td>Failed</td>
	</tr>
	<tr>
		<td>Is equal to 0</td>
		<td>Success</td>
	</tr>
</table>
*/

int HTTPSRV_PEER_DMS_SetContentPcLevel (dlna_contents_pg_obj_t * in_request);

/*!
\par Function:
Gets default device PG level.
\par Parameters:
<table>
	<tr>
		<td>[out]</td>
		<td>out_default_pc_client_val</td>
		<td>On success, default PG level of devices will be available here</td>
	</tr>
</table>
\return Error code.
\par Return Values:
<table>
	<tr>
		<td> \b Error Code</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>Lessthan 0</td>
		<td>Failed</td>
	</tr>
	<tr>
		<td>Is equal to 0</td>
		<td>Sucess</td>
	</tr>
</table>
*/

int HTTPSRV_PEER_DMS_GetDevicePgLevel (int *out_default_pc_client_val);

/*!
\par Function:
Sets default device PG level.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>in_device_pg_level</td>
		<td>Default PG level of the devices</td>
	</tr>
</table>
\return Error code.
\par Return Values:
<table>
	<tr>
		<td> \b Error Code</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>Lessthan 0</td>
		<td>Failed</td>
	</tr>
	<tr>
		<td>Is equal to 0</td>
		<td>Success</td>
	</tr>
</table>
*/

int HTTPSRV_PEER_DMS_SetDevicePgLevel (int in_device_pg_level);

/*!
\par Function:
Gets default content PG level.
\par Parameters:
<table>
	<tr>
		<td>[out]</td>
		<td>out_content_pg_level</td>
		<td>On success, content default PG level will be available here</td>
	</tr>
</table>
\return Error code.
\par Return Values:
<table>
	<tr>
		<td> \b Error Code</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>Lessthan 0</td>
		<td>Failed</td>
	</tr>
	<tr>
		<td>Is equal to 0</td>
		<td>Success</td>
	</tr>
</table>
*/

int HTTPSRV_PEER_DMS_GetContentPgLevel (int *out_content_pg_level);

/*!
\par Function:
Sets default content PG level.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>in_content_pg_level</td>
		<td>Content default PG level</td>
	</tr>
</table>
\return Error code.
\par Return Values:
<table>
	<tr>
		<td> \b Error Code</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>Lessthan 0</td>
		<td>Failed</td>
	</tr>
	<tr>
		<td>Is equal to 0</td>
		<td>Success</td>
	</tr>
</table>
*/

int HTTPSRV_PEER_DMS_SetContentDefPgLevel (int in_content_pg_level);

#endif

#ifdef DMS_HTTP_SRV_AUTH

/*!
\par Function:
Sets "Admin" password.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>in_WebUI_Admin_Passwd_Old</td>
		<td>Current "Admin" password</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_WebUI_Admin_Passwd_New</td>
		<td>New "Admin" password</td>
	</tr>
</table>
\return Error code.
\par Return Values:
<table>
	<tr>
		<td> \b Error Code</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>Lessthan 0</td>
		<td>New "Admin" password set failed</td>
	</tr>
	<tr>
		<td>Is equal to 0</td>
		<td>New "Admin" password set success</td>
	</tr>
</table>
*/

int HTTPSRV_PEER_DMS_Set_WebUI_Admin_Passwd (char *in_WebUI_Admin_Passwd_Old, char *in_WebUI_Admin_Passwd_New);

/*!
\par Function:
Validates the "Admin" password.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>in_Passwd</td>
		<td>Password to validate</td>
	</tr>
</table>
\return Error code.
\par Return Values:
<table>
	<tr>
		<td> \b Error Code</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>Lessthan 0</td>
		<td>Failed</td>
	</tr>
	<tr>
		<td>Is equal to 0</td>
		<td>Success</td>
	</tr>
</table>
*/

int HTTPSRV_PEER_DMS_Auth_WebUI_Admin (char *in_Passwd);

#endif /* DMS_HTTP_SRV_AUTH */

/*!
\par Function:
Sets number of items that can be displayed per page.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>in_share_pp_val</td>
		<td>Number of items that can be displayed per page</td>
	</tr>
</table>
\return Error code.
\par Return Values:
<table>
	<tr>
		<td> \b Error Code</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>Lessthan 0</td>
		<td>Failed</td>
	</tr>
	<tr>
		<td>Is equal to 0</td>
		<td>Success</td>
	</tr>
</table>
*/

int HTTPSRV_PEER_DMS_SetContentSharePerPage (int in_share_pp_val);

/*!
\par Function:
Gets currently configured number of items that can be displayed per page.
\par Parameters:
<table>
</table>
\return Currently configured number of items that can be displayed per page.
*/

int HTTPSRV_PEER_DMS_GetContentSharePerPage (int *out_share_pp_val);

#ifdef BUGFIX_CONTENTS_PER_PAGE

/*!
\par Function:
Gets maximum allowed number of items that can be displayed per page.
\par Parameters:
<table>
	<tr>
		<td>[out]</td>
		<td>out_list_max_val</td>
		<td>On success, contains maximum number of items that can be displayed per page</td>
	</tr>
</table>
\return Error code.
\par Return Values:
<table>
	<tr>
		<td> \b Error Code</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>Lessthan 0</td>
		<td>Failed</td>
	</tr>
	<tr>
		<td>Is equal to 0</td>
		<td>Success</td>
	</tr>
</table>
*/

int HTTPSRV_PEER_DMS_GetContentListMaxValue (int *out_list_max_val);

#endif /* BUGFIX_CONTENTS_PER_PAGE */

/*!
\par Function:
Gets content tree.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>in_request</td>
		<td>Content tree request</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_result</td>
		<td>On success, content tree will be available here</td>
	</tr>
</table>
\return Error code.
\par Return Values:
<table>
	<tr>
		<td> \b Error Code</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>Lessthan 0</td>
		<td>Failed</td>
	</tr>
	<tr>
		<td>Is equal to 0</td>
		<td>Success</td>
	</tr>
</table>
*/
int
HTTPSRV_PEER_DMS_GetContentTree (dlna_contents_tree_request_t * in_request, dlna_contents_tree_response_t * out_result);

/*!
\par Function:
Gets number of child of specified object
\par Parameters:
<table>
  <tr>
    <td>[in]</td>
    <td>in_obj_id</td>
    <td>Object to be queried</td>
  </tr>
  <tr>
    <td>[out]</td>
    <td>out_num</td>
    <td>On success, number of child will be stored here</td>
  </tr>
</table>
\return Error code.
\par Return Values:
<table>
  <tr>
    <td> \b Error Code</td>
    <td> \b Meaning</td>
  </tr>
  <tr>
    <td>slim_false</td>
    <td>Failure</td>
  </tr>
  <tr>
    <td>slim_true</td>
    <td>Success</td>
  </tr>
</table>
*/
slim_bool HTTPSRV_PEER_DMS_GetContentChildCount (slim_char * in_obj_id, slim_int * out_num);

int HTTPSRV_PEER_DMS_GetContentIdxState (int *out_idx_type, int *out_idx_state);

#ifdef DEVELOPMENT_DMS_STORAGE_LAST_INDEX_TIME
int HTTPSRV_PEER_DMS_GetDeviceLastIdxTime (char *device_id, char *out_last_idx_time);
int HTTPSRV_PEER_DMS_GetDeviceTimeOrState (char *device_id, char *out_time_state);
#endif /* DEVELOPMENT_DMS_STORAGE_LAST_INDEX_TIME */

int HTTPSRV_PEER_DMS_GetSelectedLanguage (char *out_write_buf, int buf_size);
int HTTPSRV_PEER_DMS_GetLanguages (char *out_write_buf, int buf_size);
int HTTPSRV_PEER_DMS_SetLanguage (const char *language);

#ifdef DMS_CSYNC_APPS

int HTTPSRV_PEER_DMS_GetDmsList (dlna_csync_dmslist_request_t ** list, int *list_num);

void HTTPSRV_PEER_DMS_FreeDMSList (dlna_csync_dmslist_request_t * list, int items_num);

int HTTPSRV_PEER_DMS_GetLocalDMSServer (dlna_csync_dmslist_request_t * server);

int HTTPSRV_PEER_DMS_ObjectBrowse (char *id);

int HTTPSRV_PEER_DMS_ObjectBrowseRange (char *id, int start_index, int num);

int HTTPSRV_PEER_DMS_ObjectBrowseResult (dlna_csync_browse_response_t * inout_items);

void HTTPSRV_PEER_DMS_ObjectBrowseResultFree (dlna_csync_browse_response_t * inout_response);

int HTTPSRV_PEER_DMS_GetObjectParentID (char *id);

int HTTPSRV_PEER_DMS_GetParentIDResponse (dlna_csync_browse_metadata_response_t * inout_rsp);

void HTTPSRV_PEER_DMS_GetParentIDResponseFree (dlna_csync_browse_metadata_response_t * in_rsp);

int HTTPSRV_PEER_DMS_CS_SetRemoteObject (char *id);

int HTTPSRV_PEER_DMS_CS_SetLocalObject (char *id);

int HTTPSRV_PEER_DMS_CS_IsSetRemoteObject (void);

int HTTPSRV_PEER_DMS_CS_IsSetLocalObject (void);

int HTTPSRV_PEER_DMS_CS_CreateTask (dlna_cs_task_params_t * params);

int HTTPSRV_PEER_DMS_CS_TaskList (dlna_cs_task_params_t ** list, int *list_num);

void HTTPSRV_PEER_DMS_CS_FreeTaskList (dlna_cs_task_params_t * list, int list_num);

int HTTPSRV_PEER_DMS_CS_StartTask (char *id);

int HTTPSRV_PEER_DMS_CS_DeleteTask (char *id);

#endif /* DMS_CSYNC_APPS */

/*!
\par Function:
Gets next PG level.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>in_prev_level</td>
		<td>Previous PG level</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_next_level</td>
		<td>Next PG level</td>
	</tr>
</table>
\return A slim_bool value.
\par Return Values:
<table>
	<tr>
		<td> \b slim_bool value</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>slim_false</td>
		<td>Failed</td>
	</tr>
	<tr>
		<td>slim_true</td>
		<td>Success</td>
	</tr>
</table>
*/

int
HTTPSRV_PEER_DMS_getNextParentalGuidanceLevel (parental_guidance_level_info_ext_t * in_prev_level,
                                               parental_guidance_level_info_ext_t * out_next_level);

/*!
\par Function:
Gets first PG level.
\par Parameters:
<table>
	<tr>
		<td>[out]</td>
		<td>out_first_level</td>
		<td>On success, First PG level info structure will be available here</td>
	</tr>
</table>
\return A slim_bool value.
\par Return Values:
<table>
	<tr>
		<td> \b Error Code</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>slim_false</td>
		<td>Failed</td>
	</tr>
	<tr>
		<td>slim_true</td>
		<td>Success</td>
	</tr>
</table>
*/

int HTTPSRV_PEER_DMS_getFirstParentalGuidanceLevel (parental_guidance_level_info_ext_t * out_first_level);

/*!
\par Function:
Gets first connected device monitored by PG module.
\par Parameters:
<table>
	<tr>
		<td>[out]</td>
		<td>out_first_device</td>
		<td>On success, first connected device monitored by PG module will be available here</td>
	</tr>
</table>
\return A slim_bool value.
\par Return Values:
<table>
	<tr>
		<td> \b Error Code</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>slim_false</td>
		<td>Failure</td>
	</tr>
	<tr>
		<td>slim_true</td>
		<td>Success</td>
	</tr>
</table>
*/

int HTTPSRV_PEER_DMS_getFirstParentalGuidanceConnectedDevice (parental_control_device_ext_t * out_first_device);

/*!
\par Function:
Gets next connected device monitored by PG module.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>in_prev_device</td>
		<td>Previous connected device monitored by PG module</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_next_device</td>
		<td>Next connected device monitored by PG module</td>
	</tr>
</table>
\return A slim_bool value.
\par Return Values:
<table>
	<tr>
		<td> \b Error Code</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>slim_false</td>
		<td>Failure</td>
	</tr>
	<tr>
		<td>slim_true</td>
		<td>Success</td>
	</tr>
</table>
*/

int
HTTPSRV_PEER_DMS_getNextParentalGuidanceConnectedDevice (const parental_control_device_ext_t * in_prev_device,
                                                         parental_control_device_ext_t * out_next_device);

/*!
\par Function:
Sets connected device attributes like description, PG level etc. Connected device entry can be deleted.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>pc_device</td>
		<td>Updated data of the connected device monitored by PG module</td>
	</tr>
</table>
\return A slim_bool value.
\par Return Values:
<table>
	<tr>
		<td> \b Error Code</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>slim_false</td>
		<td>Failure</td>
	</tr>
	<tr>
		<td>slim_true</td>
		<td>Success</td>
	</tr>
</table>
*/

int HTTPSRV_PEER_DMS_setDevicePC (const parental_control_device_ext_t * pc_device);
/*!
\par Function:
Add storage to be published by DMS with specified path.
\par Parameters:
<table>
  <tr>
    <td>[in]</td>
    <td>in_path</td>
    <td>Absolute path of storage to be shared</td>
  </tr>
</table>
\return A slim_bool value.
\par Return Values:
<table>
  <tr>
    <td> \b Error Code</td>
    <td> \b Meaning</td>
  </tr>
  <tr>
    <td>slim_false</td>
    <td>Failure</td>
  </tr>
  <tr>
    <td>slim_true</td>
    <td>Success</td>
  </tr>
</table>
*/
slim_bool HTTPSRV_PEER_DMS_AddPublishStorage (slim_char * in_path);

/*!
\par Function:
Delete storage published by DMS with specified path.
\par Parameters:
<table>
  <tr>
    <td>[in]</td>
    <td>in_path</td>
    <td>Absolute path of storage to be removed from DMS</td>
  </tr>
</table>
\return A slim_bool value.
\par Return Values:
<table>
  <tr>
    <td> \b Error Code</td>
    <td> \b Meaning</td>
  </tr>
  <tr>
    <td>slim_false</td>
    <td>Failure</td>
  </tr>
  <tr>
    <td>slim_true</td>
    <td>Success</td>
  </tr>
</table>
*/
slim_bool HTTPSRV_PEER_DMS_RemovePublishStorage (slim_char * in_path);

#endif /* __WEBUI_INTERFACE_H__ */
