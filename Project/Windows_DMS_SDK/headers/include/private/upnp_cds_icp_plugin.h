/*
 * upnp_cds_icp_plugin.h
 * Copyright (C) 2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef UPNP_CDS_ICP_PLUGIN_H
#define UPNP_CDS_ICP_PLUGIN_H

#include <nflc_icp.h>
#include <upnp_cds.h>




//Forward declarations

struct contents_manager;
struct upnp_cds_;
struct upnp_cds_browse_param;
struct upnp_cds_search_param;
struct upnp_action_request;



//Types

typedef TICPReturn (*ICP_Initialize) (void);
typedef TICPReturn (*ICP_Terminate) (void);
typedef TICPReturn (*ICP_Start) (void);
typedef TICPReturn (*ICP_Stop) (void);
typedef TICPReturn (*ICP_RegisterCallback) (TICPCB in_callback, void *in_callback_arg);
typedef TICPReturn (*ICP_Browse) (slim_char *in_parent, slim_char *in_browse_option,
    slim_char *in_filter, slim_char *in_start_index, slim_char *in_requested_count,
    slim_char *in_sort_criteria);
typedef TICPReturn (*ICP_Search) (slim_char *in_parent, slim_char *in_search_criteria,
    slim_char *in_filter, slim_char *in_start_index, slim_char *in_requested_count,
    slim_char *in_sort_criteria);



/**
 * \par Enumeration
 * State of ICP plugin
 *
 * \par Values
 *
 * <table>
 *  <tr>
 *   <td>UPNP_CDS_ICP_STATE_NOT_READY</td>
 *   <td>Plugin is not ready to work</td>
 *  </tr>
 *  <tr>
 *   <td>UPNP_CDS_ICP_STATE_READY</td>
 *   <td>Plugin is ready to work</td>
 *  </tr>
 *  <tr>
 *   <td>UPNP_CDS_ICP_STATE_BUSY</td>
 *   <td>Plugin is currently working</td>
 *  </tr>
 * </table>
 */
enum upnp_cds_icp_plugin_state
{
  UPNP_CDS_ICP_STATE_NOT_READY = 0,
  UPNP_CDS_ICP_STATE_READY = 0x01010101,
  UPNP_CDS_ICP_STATE_BUSY,
};




/**
 * \par Enumeration
 * Kind of request to ICP plugin
 *
 * \par Values
 *
 * <table>
 *  <tr>
 *   <td>UPNP_CDS_ICP_BROWSE</td>
 *   <td>Request to browse content</td>
 *  </tr>
 *  <tr>
 *   <td>UPNP_CDS_ICP_SEARCH</td>
 *   <td>Request to search</td>
 *  </tr>
 * </table>
 */
enum upnp_cds_icp_plugin_request_type
{
  UPNP_CDS_ICP_BROWSE,
  UPNP_CDS_ICP_SEARCH,
};




/**
 * \par Union
 * Contains request parameters
 *
 * \par Members
 *
 * <table>
 *  <tr>
 *   <td>search</td>
 *   <td>Parameters for search request</td>
 *  </tr>
 *  <tr>
 *   <td>browse</td>
 *   <td>Parameters for browse request</td>
 *  </tr>
 * </table>
 */
union _upnp_cds_icp_plugin_action_param
{
  struct upnp_cds_search_param search;
  struct upnp_cds_browse_param browse;
};





struct _upnp_cds_icp_plugin_desc
{
  //List
  struct _upnp_cds_icp_plugin_desc * next;
  struct _upnp_cds_icp_plugin_desc * prev;

  //Data
  slim_char * plugin_path;
  slim_char * virtual_folder_name;
  slim_char * title;
  slim_int virtual_folder_name_length;

  slim_bool is_search_enabled;
};

/**
 * \par Structure
 * upnp_cds_icp_plugin_desc is the structure that stores information about available ICP plugins
 *
 * \code
struct _upnp_cds_icp_plugin_desc
{
  //List
  struct _upnp_cds_icp_plugin_desc * next;
  struct _upnp_cds_icp_plugin_desc * prev;

  //Data
  slim_char * plugin_path;
  slim_char * virtual_folder_name;
  slim_char * title;
  slim_int virtual_folder_name_length;
};
typedef struct _upnp_cds_icp_plugin_desc upnp_cds_plugin_desc;
 * \endcode
 *
 * \par Member:
 *
<table>
  <tr>
    <td>next</td>
    <td>Next description on the list</td>
  </tr>
  <tr>
    <td>prev</td>
    <td>Previous description on the list</td>
  </tr>
  <tr>
    <td>plugin_path</td>
    <td>Path to file with plugin</td>
  </tr>
  <tr>
    <td>virtual_folder_name</td>
    <td>Virtual container id that will be related to plugin</td>
  </tr>
  <tr>
    <td>title</td>
    <td>dc:title field</td>
  </tr>
  <tr>
    <td>virtual_folder_name_length</td>
    <td>Length of virtual path string</td>
  </tr>
</table>
 */
typedef struct _upnp_cds_icp_plugin_desc upnp_cds_plugin_desc;
typedef ListNamed(struct _upnp_cds_icp_plugin_desc *,
    _upnp_cds_icp_plugin_desc_list) upnp_cds_icp_plugin_desc_list;






struct _upnp_cds_icp_plugin
{
  //List
  struct _upnp_cds_icp_plugin * next;
  struct _upnp_cds_icp_plugin * prev;

  //Data
  ICP_Initialize initialize;
  ICP_Terminate terminate;

  ICP_Start start;
  ICP_Stop stop;

  ICP_RegisterCallback register_callback;

  ICP_Browse browse;
  ICP_Search search;

  void * module;
  struct _upnp_cds_icp_plugin_desc * description;
  enum upnp_cds_icp_plugin_state state;
};

/**
 * \par Structure
 * upnp_cds_icp_plugin is the structure that stores information about loaded ICP plugins
 *
 * \code
struct _upnp_cds_icp_plugin
{
  //List
  struct _upnp_cds_icp_plugin * next;
  struct _upnp_cds_icp_plugin * prev;

  //Data
  ICP_Initialize initialize;
  ICP_Terminate terminate;

  ICP_Start start;
  ICP_Stop stop;

  ICP_RegisterCallback register_callback;

  ICP_Browse browse;
  ICP_Search search;

  void * module;
  struct _upnp_cds_icp_plugin_desc * description;
  enum upnp_cds_icp_plugin_state state;
};

typedef struct _upnp_cds_icp_plugin upnp_cds_icp_plugin;
typedef List(struct _upnp_cds_icp_plugin *) upnp_cds_icp_plugin_list;
 * \endcode
 *
 * \par Member:
 *
<table>
  <tr>
    <td>next</td>
    <td>Next plugin on the list</td>
  </tr>
  <tr>
    <td>prev</td>
    <td>Previous plugin on the list</td>
  </tr>
  <tr>
    <td>initialize</td>
    <td>Address of NFLC_ICP_Initialize routine loaded from dynamic link library</td>
  </tr>
  <tr>
    <td>terminate</td>
    <td>Address of NFLC_ICP_Terminate routine loaded from dynamic link library</td>
  </tr>
  <tr>
    <td>start</td>
    <td>Address of NFLC_ICP_Start routine loaded from dynamic link library</td>
  </tr>
  <tr>
    <td>stop</td>
    <td>Address of NFLC_ICP_Stop routine loaded from dynamic link library</td>
  </tr>
  <tr>
    <td>register_callback</td>
    <td>Address of NFLC_ICP_RegisterCallback routine loaded from dynamic link library</td>
  </tr>
  <tr>
    <td>browse</td>
    <tdAddress of NFLC_ICP_Browse routine loaded from dynamic link library></td>
  </tr>
  <tr>
    <td>search</td>
    <td>Address of NFLC_ICP_Search routine loaded from dynamic link library</td>
  </tr>
  <tr>
    <td>module</td>
    <td>Descriptor of loaded model</td>
  </tr>
  <tr>
    <td>description</td>
    <td>Description of plugin</td>
  </tr>
  <tr>
   <td>state</td>
   <td>Current state of plugin</td>
  </tr>
</table>
 */
typedef struct _upnp_cds_icp_plugin upnp_cds_icp_plugin;
typedef List(struct _upnp_cds_icp_plugin *) upnp_cds_icp_plugin_list;





struct _upnp_cds_icp_plugin_callback_arg
{
  struct contents_manager * cm;
  struct upnp_cds_ * upnp_cds;
  union _upnp_cds_icp_plugin_action_param * param;
  struct upnp_action_request * request;
  void * extended_flags;
  enum upnp_cds_icp_plugin_request_type type;
  slim_int session_id;
};
/**
 * \par Structure
 * Contains data necessary for ICP callback routine
 *
 * \par Membres
 *
 * <table>
 *  <tr>
 *   <td>cm</td>
 *   <td>Content manager</td>
 *  </tr>
 *  <tr>
 *   <td>upnp_cds</td>
 *   <td>Upnp content directory service</td>
 *  </tr>
 *  <tr>
 *   <td>param</td>
 *   <td>Request parameter</td>
 *  </tr>
 *  <tr>
 *   <td>request</td>
 *   <td>Request</td>
 *  </tr>
 *  <tr>
 *   <td>extended_flags</td>
 *   <td>Extended flags</td>
 *  </tr>
 *  <tr>
 *   <td>type</td>
 *   <td>Type of request</td>
 *  </tr>
 * </table>
 */
typedef struct _upnp_cds_icp_plugin_callback_arg upnp_cds_icp_plugin_callback_arg;




//Functions




/**
 * \par Function
 * Returns ICP search results to search_response routine
 *
 * \par
 * Parameters
 *
 * <table>
 *  <tr>
 *   <td>[in]</td>
 *   <td>service</td>
 *   <td>Upnp content directory service</td>
 *  </tr>
 *  <tr>
 *   <td>[in]</td>
 *   <td>parent</td>
 *   <td>Parent container</td>
 *  </tr>
 *  <tr>
 *   <td>[in]</td>
 *   <td>param</td>
 *   <td>Search parameters</td>
 *  </tr>
 *  <tr>
 *   <td>[in]</td>
 *   <td>ext_flags</td>
 *   <td>Extended flags</td>
 *  </tr>
 *  <tr>
 *   <td>[in]</td>
 *   <td>rcount</td>
 *   <td>Requested count</td>
 *  </tr>
 *  <tr>
 *   <td>[in]</td>
 *   <td>sindex</td>
 *   <td>Starting index</td>
 *  </tr>
 *  <tr>
 *   <td>[out]</td>
 *   <td>matches</td>
 *   <td>Number of selected contents</td>
 *  </tr>
 *  <tr>
 *   <td>[out]</td>
 *   <td>total_matches</td>
 *   <td>Number of contents matching request</td>
 *  </tr>
 *  <tr>
 *   <td>[in/out]</td>
 *   <td>in_results</td>
 *   <td>Selected contents</td>
 *  </tr>
 * </table>
 *
 * \return UPNP_GENERIC_ERROR Any error
 * \return UPNP_SUCCESS Success
 *
 * \par Description
 * This function search parent for Search container (parent_id$Search).
 * When everything is fine it fills in_results with contents of Search container.
 *
 * \par Note
 * When success in_results must be freed by caller
 */
slim_int
upnp_cds_search_icp(upnp_cds * service, struct contents *parent,
                      struct upnp_cds_search_param *p, extended_flags_t ext_flags,
                      slim_word rcount, slim_word sindex,
                      slim_word *matches, slim_word *total_matches, vector in_results);






/**
 * \par Function
 * Clean after search action
 *
 * \par Parameters
 *
 * <table>
 *  <tr>
 *   <td>[in]</td>
 *   <td>s</td>
 *   <td>Upnp content directory service</td>
 *  </tr>
 *  <tr>
 *   <td>[in]</td>
 *   <td>in_desc</td>
 *   <td>Plugin description</td>
 *  </tr>
 * </table>
 *
 * \par Description
 * After responding to search request results are no longer needed.
 * Therefore all created content is removed.
 */
void
upnp_cds_icp_clean_search(upnp_cds *s,
    struct _upnp_cds_icp_plugin_desc * in_desc);





/**
 * \par Function
 * Process data received from ICP plugin
 *
 * \par Parameters
 *
 * <table>
 *  <tr>
 *   <td>[in]</td>
 *   <td>in_cm</td>
 *   <td>Content manager</td>
 *  </tr>
 *  <tr>
 *   <td>[in]</td>
 *   <td>in_desc</td>
 *   <td>Description of ICP plugin</td>
 *  </tr>
 *  <tr>
 *   <td>[in]</td>
 *   <td>in_content</td>
 *   <td>List of content</td>
 *  </tr>
 *  <tr>
 *   <td>[in]</td>
 *   <td>request_type</td>
 *   <td>Type of request</td>
 *  </tr>
 * </table>
 *
 * \return UPNP_GENERIC_ERROR Any error
 * \return UPNP_SUCCESS Success
 *
 * \par Description
 * Stores in_content in content manager.
 *
 * If request was Search, results are stored in plugin_virtual_id$Search.
 * This container is removed just after sending the response.
 */
slim_int
upnp_cds_icp_plugin_process_content(struct contents_manager * in_cm,
    struct _upnp_cds_icp_plugin_desc * in_desc,
    const struct icp_content * in_content,
    enum upnp_cds_icp_plugin_request_type request_type);


#ifdef DEVELOPMENT_ENABLE_WEBUI_BROWSE_SYNCRON_CALL_WORKAROUND
slim_int
upnp_cds_icp_plugin_process_content_custom(struct contents_manager * in_cm,
    const struct icp_content * in_content,
    enum upnp_cds_icp_plugin_request_type request_type);
#endif /* DEVELOPMENT_ENABLE_WEBUI_BROWSE_SYNCRON_CALL_WORKAROUND */


/**
 * \par Function:
 * Updates the CDS with content, sends response
 *
 * \par Parameters:
 *
 * <table>
 *  <tr>
 *    <td>[in]</td>
 *    <td>in_content</td>
 *    <td>Updates the CDS with data according to the Browse/Search SOAP action response. The data (structure and all member) MUST be allocated and disposed by the caller of the function.</td>
 *  </tr>
 *  <tr>
 *    <td>[in]</td>
 *    <td>in_content_count</td>
 *    <td>Number of items in “in_content” list.</td>
 *  </tr>
 *  <tr>
 *    <td>[in]</td>
 *    <td>in_status</td>
 *    <td>When used within the asynchronous Browse/Search operation by a module the function is used as well to supply status information. On success the status has to be set to DMS_SUCCESS and in_data will point to valid response data, In case of an error the module will report the error code to the NFLC framework and set’s the in_data pointer to NULL.
        <ul>
          <li>DMS_INVALID_PARAM
          <li>DMS_SOCKET_ERROR
          <li>DMS_ACCESS_DENY
          <li>DMS_OUT_OF_MEMORY
          <li>DMS_GENERIC_ERROR
        </ul>
 *    </td>
 *  </tr>
 *  <tr>
 *    <td>[in]</td>
 *    <td>in_callback_arg</td>
 *    <td>Callback argument passed by the framework to function NFLC_ICP_RegisterCallback()</td>
 *  </tr>
 * </table>
 *
 * \return DMS_SUCCESS Contents update request accepted.
 * \return DMS_INVALID_PARAM Request data format error
 *
 * \par Description:
 * This function updates the content list under the parent folder providing the response of ICP Browse/Search action.
If the content list update request is accepted successfully by the nflc framework, then DMS_SUCCESS is returned. Each Browse/Search result will replace corresponding existing content in the CDS.
 *
 * \par Warning
 * in_content must be freed by caller.
 */
TICPReturn
dlnaDmsICPResponse (struct icp_content * in_content,
    slim_int in_content_count,
    slim_int in_status,
    void * in_callback_arg);







/**
 * \par Function:
 * Allocates upnp_cds_icp_plugin_desc.
 *
 * \return Allocated object on success
 * \return slim_nil on failure
 *
 * \par Description:
 * Function allocates new instance of upnp_cds_icp_plugin_desc and sets all members to zero.
 */
struct _upnp_cds_icp_plugin_desc *
upnp_cds_icp_plugin_desc_alloc();







/**
 * \par Function:
 * Frees upnp_cds_icp_plugin_desc.
 *
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of upnp_cds_icp_plugin_desc</td>
 *   </tr>
 * </table>
 *
 * \par Description:
 * Function frees all members and upnp_cds_icp_plugin_desc object.
 */
void
upnp_cds_icp_plugin_desc_free(struct _upnp_cds_icp_plugin_desc * self);







/**
 * \par Function:
 * Clear upnp_cds_icp_plugin_desc_list.
 *
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Instance of upnp_cds_icp_plugin_desc_list</td>
 *   </tr>
 * </table>
 *
 * \par Description:
 * Function frees all objects on the list. It does not free list.
 */
void
upnp_cds_icp_plugin_desc_list_clear(struct _upnp_cds_icp_plugin_desc_list * self);








/**
 * \par Function:
 * Load ICP plugins configuration file.
 *
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_path</td>
 *     <td>Path to configuration file</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_file_name</td>
 *     <td>Configuration file name</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_container_name</td>
 *     <td>Name of container that will keep all plugins</td>
 *   </tr>
 *   <tr>
 *     <td>[out]</td>
 *     <td>out_desc_list</td>
 *     <td>List of plugins descriptions</td>
 *   </tr>
 * </table>
 *
 * \return UPNP_SUCCESS On success
 * \return UPNP_GENERIC_ERROR Null pointers, memory failures, corrupted file.
 * \return UPNP_XML_ERROR Failed to parse xml
 * \return UPNP_FILE_NOT_EXIST Unable to locate or open file
 *
 * \par Description:
 * Function read and parse xml file. It looks for icp_list tag. Found desriptions are stored on the list
 */
slim_int
upnp_cds_icp_plugin_load_configuration(const slim_char * in_path,
    const slim_char * in_file_name,
    const slim_char * in_container_name,
    struct _upnp_cds_icp_plugin_desc_list * out_desc_list);





/**
 * \par Function
 * Add virtual conatiners for each plugin
 *
 * \par Parameters
 *
 * <table>
 *  <tr>
 *   <td>[in]</td>
 *   <td>in_cm</td>
 *   <td>Content manager</td>
 *  </tr>
 *  <tr>
 *   <td>[in]</td>
 *   <td>in_desc_list</td>
 *   <td>List of plugins decriptions</td>
 *  </tr>
 * </table>
 *
 * \return UPNP_GENERIC_ERROR Any error
 * \return UPNP_SUCCESS Success
 */
slim_int
upnp_cds_icp_plugin_prepare_containers(struct contents_manager * in_cm,
    struct _upnp_cds_icp_plugin_desc_list * in_desc_list);





/**
 * \par Function
 * Search plugin descritions list for one iwth given virtual folder
 *
 * \par Parameters
 *
 * <table>
 *  <tr>
 *   <td>[in]</td>
 *   <td>in_virtual_folder</td>
 *   <td>Virtual folder name</td>
 *  </tr>
 *  <tr>
 *   <td>[in]</td>
 *   <td>in_desc_list</td>
 *   <td>List of descriptions</td>
 *  </tr>
 * </table>
 *
 * \return slim_nil Failure
 * \return Plugin description when found
 */
struct _upnp_cds_icp_plugin_desc *
upnp_cds_icp_plugin_search_desc(const slim_char * in_virtual_folder,
    struct _upnp_cds_icp_plugin_desc_list * in_desc_list);






/**
 * \par Function:
 * Allocate ICP plugin object
 *
 * \return Allocated and initialized object on success
 * \return 0 on failure
 *
 * \par Description:
 * Function allocate memory and fill it with null.
 */
struct _upnp_cds_icp_plugin *
upnp_cds_icp_plugin_alloc();







/**
 * \par Function:
 * Frees ICP plugin object
 *
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>self</td>
 *     <td>Object that will be freed</td>
 *   </tr>
 * </table>
 *
 *
 * \par Description:
 * Function unloads dynamic link library and free object.
 */
void
upnp_cds_icp_plugin_free(struct _upnp_cds_icp_plugin * self);





/**
 * \par Function:
 * Load plugin from dynamic link library
 *
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>virtual_path</td>
 *     <td>Virtual path related to requested plugin</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_desc_list</td>
 *     <td>List of ICP plugins descriptions</td>
 *   </tr>
 *   <tr>
 *     <td>[out]</td>
 *     <td>out_plugin</td>
 *     <td>Object that will be used to store plugin</td>
 *   </tr>
 * </table>
 *
 * \return UPNP_GENERIC_ERROR Null pointers, failed dll loading
 * \return UPNP_FILE_NOT_EXIST Unable to locate description for given virtual path.
 * \return UPNP_SUCCESS on success
 *
 * \par Description:
 * Function search list for ICP plugin description which correspond to virtual path. If good description exist it is used to load plugin from dynamic link library.
 */
slim_int
upnp_cds_icp_plugin_load_plugin(const slim_char * virtual_path,
    const struct _upnp_cds_icp_plugin_desc_list * in_desc_list,
    struct _upnp_cds_icp_plugin * out_plugin);

#endif /* UPNP_CDS_ICP_PLUGIN_H */

