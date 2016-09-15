/*
 * nflc_ipc.h
 * Copyright (C) 2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_ICP_PLUGIN_H
#define NFLC_ICP_PLUGIN_H

#ifdef HAVE_DTCP
#include <nflc_drm_api.h>
#endif /*HAVE_DTCP*/

// Types
typedef slim_int TICPReturn;

#define ICP_SUCCESS 0
#define ICP_GENERIC -1

enum icp_content_type_ {
 ICP_CONTENT_TYPE_CONTAINER = 0,//!< ICP_CONTENT_TYPE_CONTAINER
 ICP_CONTENT_TYPE_IMAGE,        //!< ICP_CONTENT_TYPE_IMAGE
 ICP_CONTENT_TYPE_AUDIO,        //!< ICP_CONTENT_TYPE_AUDIO
 ICP_CONTENT_TYPE_VIDEO,        //!< ICP_CONTENT_TYPE_VIDEO
 ICP_CONTENT_TYPE_PLAYLIST      //!< ICP_CONTENT_TYPE_PLAYLIST
};

typedef enum icp_content_type_ icp_content_type;

/**
 * \par Structure
 * Represents thumbnail
 *
 * \code
struct icp_thumbnail {
  slim_char * uri;
  slim_word width;
  slim_word height;
  slim_word time;
};
 * \endcode
 *
 * \par Members:
 * <table>
 *   <tr>
 *     <td>uri</td>
 *     <td>URI of thumbnail image</td>
 *   </tr>
 *   <tr>
 *     <td>width</td>
 *     <td>Width of thumbnail</td>
 *   </tr>
 *   <tr>
 *     <td>height</td>
 *     <td>Height of thumbnail</td>
 *   </tr>
 *   <tr>
 *     <td>time</td>
 *     <td>Time position of thumbnail</td>
 *   </tr>
 * </table>
 */
struct icp_thumbnail {
  slim_char * uri;
  slim_word width;
  slim_word height;
  slim_word time;
};

struct icp_content {
  struct icp_content *prev;
  struct icp_content *next;

/* Mandatory */
  icp_content_type  content_type;  /* content type */
  slim_char *parent_id;        /* parent ID */
  slim_char *id;               /* Must be unique */
  slim_char *uri;            /* content URI */
  slim_char *uri2;            /* content URI */
  slim_char *title;          /* dc:title */
  slim_char *mime_type;        /* mime type of content */

/* Optional */
  slim_char *creator;          /* dc:creator */
  slim_char *genre;            /* Genre */
  slim_char *artist;           /* Artist */
  dlna_uint64 file_size;       /* File Size */
  slim_word width;             /* Width */
  slim_word height;            /* Height */
  slim_word bitrate;           /* Bitrate  */
  slim_word sample_rate;       /* Sample rate */
  slim_byte channels;          /* Number of channels, 1=mono 2=stereo … */
  slim_word duration;          /* Duration */
  slim_word upnp_child_count;    /* upnp:childCount for container */
  slim_bool is_protected;       /*is content needs DTCP-IP pinfo*/
  slim_bool is_streaming_type;  /*Set this flag to slim_true, if the content is streaming type and DMS should act as Proxy to fetch this content*/
#ifdef HAVE_DTCP
  minfo_drm_cci cci;
#endif /*HAVE_DTCP*/
  struct icp_thumbnail thumbnail;
};
/**
 * Represents single content
 *
 * \code
struct icp_content {
  struct icp_content *prev;
  struct icp_content *next;

  icp_content_type  content_type;
  slim_char *parent_id;
  slim_char *id;
  slim_char *uri;
  slim_char *title;
  slim_char *mime_type;

  slim_char *creator;
  slim_char *genre;
  slim_char *artist;
  dlna_uint64 file_size;
  slim_word width;
  slim_word height;
  slim_word bitrate;
  slim_word sample_rate;
  slim_byte channels;
  slim_word duration;
  slim_word upnp_child_count;

  slim_char * thumbnail_uri;
};
typedef struct icp_content icp_contnet_t;
 * \endcode
 *
 * \par Members:
 * <b>Mandatory members (Must be filled)</b>
 * <table>
 *   <tr>
 *     <td>prev</td>
 *     <td>Pointer to previous content struct</td>
 *   </tr>
 *   <tr>
 *     <td>next</td>
 *     <td>Pointer to next content struct</td>
 *   </tr>
 *   <tr>
 *     <td>content_type</td>
 *     <td>Type of the content</td>
 *   </tr>
 *   <tr>
 *     <td>parent_id</td>
 *     <td>ID of parent</td>
 *   </tr>
 *   <tr>
 *     <td>id</td>
 *     <td>Content ID. Must be unique inside IPC module</td>
 *   </tr>
 *   <tr>
 *     <td>uri</td>
 *     <td>Content URI</td>
 *   </tr>
 *   <tr>
 *     <td>title</td>
 *     <td>Title of the content</td>
 *   </tr>
 *   <tr>
 *     <td>mime_type</td>
 *     <td>Content mime type</td>
 *   </tr>
 * </table>
 *
 * <b>Optional members (Default value if cannot be determined):</b>
 * <table>
 *   <tr>
 *     <td>creator</td>
 *     <td>Creator of content. Default  = slim_nil</td>
 *   </tr>
 *   <tr>
 *     <td>genre</td>
 *     <td>Content genre. Default = slim_nil</td>
 *   </tr>
 *   <tr>
 *     <td>artist</td>
 *     <td>Content artist. Default = slim_nil</td>
 *   </tr>
 *   <tr>
 *     <td>file_size</td>
 *     <td>Content file size. Default = 0</td>
 *   </tr>
 *   <tr>
 *     <td>width</td>
 *     <td>Content width. Default = 0</td>
 *   </tr>
 *   <tr>
 *     <td>height</td>
 *     <td>Content height. Default = 0</td>
 *   </tr>
 *   <tr>
 *     <td>bitrate</td>
 *     <td>Content bitrate. Default = 0</td>
 *   </tr>
 *   <tr>
 *     <td>sample_rate</td>
 *     <td>Contente sample rate. Default = 0</td>
 *   </tr>
 *   <tr>
 *     <td>channels</td>
 *     <td>Number of channels, 1=mono 2=stereo. Default = 0</td>
 *   </tr>
 *   <tr>
 *     <td>duration</td>
 *     <td>Content duration. Default = 0</td>
 *   </tr>
 *   <tr>
 *     <td>upnp_child_count</td>
 *     <td>Number of children (Only applicable for container). Default = -1</td>
 *   </tr>
 *   <tr>
 *     <td>thumbnail_uri</td>
 *     <td>Representation of thumbnail image</td>
 *   </tr>
 * </table>
 */
typedef struct icp_content icp_contnet_t;


//Function prototypes

/**
 * \par:
 * Updates the CDS with content
 *
 * \par Parameters:
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_content</td>
 *     <td>Updates the CDS with data according to the Browse/Search SOAP action response. The data (structure and all member) MUST be allocated and disposed by the caller of the function.</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_content_count</td>
 *     <td>Number of items in “in_content” list</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_status</td>
 *     <td>When used within the asynchronous Browse/Search operation by a module the function is used as well to supply status information. On success the status has to be set to DMS_SUCCESS and in_data will point to valid response data, In case of an error the module will report the error code to the NFLC framework and set’s the in_data pointer to NULL.
 *       <ul>
 *         <li>DMS_INVALID_PARAM
 *         <li>DMS_SOCKET_ERROR
 *         <li>DMS_ACCESS_DENY
 *         <li>DMS_OUT_OF_MEMORY
 *         <li>DMS_GENERIC_ERROR
 *       </ul>
 *     </td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_callback_arg</td>
 *     <td>Callback argument passed by the framework to function NFLC_ICP_RegisterCallback()</td>
 *   </tr>
 *   <tr>
 *     <td>[out]</td>
 *     <td>None</td>
 * </table>
 */
typedef TICPReturn (*TICPCB) (icp_contnet_t *in_content, slim_int in_content_count,
    slim_int in_status,  void *in_callback_arg);


/**
 * \par Function:
 * Initialize an ICP module.
 *
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>None</td>
 *   </tr>
 *   <tr>
 *     <td>[out]<td>
 *     <td>None<td>
 *   </tr>
 * </table>
 *
 * @return ICP_SUCCESS ICP module successfully initialized
 * \return ICP_GENERIC Any other error
 *
 * \par Description:
 * This function will be implemented by an ICP module. The NFLC ICP framework obtains the function pointer during initialization after loading the dynamic link module and calls it during initialization. The implementer of an ICP module will add proper module initialization code such as required memory allocation etc...

 *
 * \par Note:
 * Functions need to follow C language calling conventions.
 */
TICPReturn NFLC_ICP_Initialize(void);

/**
 * \par Function:
 * Terminates an ICP module.
 *
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>None</td>
 *   </tr>
 *   <tr>
 *     <td>[out]<td>
 *     <td>None<td>
 *   </tr>
 * </table>
 *
 * @return ICP_SUCCESS ICP module successfully terminated
 * \return ICP_GENERIC Any other error
 *
 * \par Description:
 * This function will be implemented by an ICP module. The NFLC ICP framework obtains the function pointer during initialization after loading the dynamic link module and calls it when terminating the NFLC framework. The implementer of an ICP module will add proper module de-initialization code such as freeing allocated memory etc...

 *
 * \par Note:
 * Functions need to follow C language calling conventions.
 */
TICPReturn NFLC_ICP_Terminate(void);

/**
 * \par Function:
 * Starts an ICP module.
 *
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>None</td>
 *   </tr>
 *   <tr>
 *     <td>[out]</td>
 *     <td>None</td>
 *   </tr>
 * </table>
 *
 * @return ICP_SUCCESS ICP module successfully started
 * \return ICP_GENERIC Any other error
 *
 * \par Description:
 * This function will be implemented by an ICP module. The NFLC ICP framework obtains the function pointer during initialization after loading the dynamic link module and calls it during initialization once all other depended modules are successfully initialized and started. The implementer of an ICP module will add proper module initialization code such as starting threads etc...

 *
 * \par Note:
 * Functions need to follow C language calling conventions.
 */
TICPReturn NFLC_ICP_Start(void);

/**
 * \par Function:
 * Stops an ICP module.
 *
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>None</td>
 *   </tr>
 *   <tr>
 *     <td>[out]</td>
 *     <td>None</td>
 *   </tr>
 * </table>
 *
 * @return ICP_SUCCESS ICP module successfully stopped
 * \return ICP_GENERIC Any other error
 *
 * \par Description:
 * This function will be implemented by an ICP module. The NFLC ICP framework obtains the function pointer during initialization after loading the dynamic link module and calls it during termination before other depended modules are successfully stopped. The implementer of an ICP module will add proper module de-initialization code such as stopping threads etc...

 *
 * \par Note:
 * Functions need to follow C language calling conventions.
 */
TICPReturn NFLC_ICP_Stop(void);

/**
 * \par Function:
 * Register callback function for browse and search response
 *
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_callback</td>
 *     <td>Callback function to the NFLC framework API dlnaDmsImportUpdate(…)</td>
 *   </tr>
 *   <tr>
 *     <td>[in]<td>
 *     <td>in_callback_arg<td>
 *     <td>Argument must be passed back when calling  function dlnaDmsICPResponse().<td>
 *   </tr>
 *   <tr>
 *     <td>[out]</td>
 *     <td>None</td>
 *   </tr>
 * </table>
 *
 * @return ICP_SUCCESS Callback function successfully registered
 * \return ICP_GENERIC Any other error
 *
 * \par Description:
 * This function will be implemented by an ICP module. The NFLC ICP framework obtains the function pointer during initialization after loading the dynamic link module and calls it after the call of NFLC_ICP_Initialize(…).
 *
 * \par Note:
 * Functions need to follow C language calling conventions
 */
TICPReturn NFLC_ICP_RegisterCallback(TICPCB in_callback, void *in_callback_arg);


/**
 * \par Function:
 * Issue a browse action to an import back-end
 *
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_parent</td>
 *     <td>Parent ID passed in by the framework as per client request. For the root folder it is “0” folder ID’s returned by the import back-end are concatenated to the string, separated by a dot</td>
 *   </tr>
 *   <tr>
 *     <td>[in]<td>
 *     <td>in_browse_option<td>
 *     <td>Browse option such as “BrowseDirectChildren” depending on client request<td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_filter</td>
 *     <td>Filter attribute from client request</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_start_index</td>
 *     <td>Starting count from “0”, clients can retrieve results in chunks setting the starting index and the in_requested_count</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_requested_count</td>
 *     <td>Number of elements requested by the client starting from in_start_index</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_sort_criteria</td>
 *     <td>List of return elements to be sorted by this criteria i.e. “+dc:title”</td>
 *   </tr>
 *   <tr>
 *     <td>[out]</td>
 *     <td>None</td>
 *   </tr>
 * </table>
 *
 * @return ICP_SUCCESS Request successfully understood
 * \return ICP_GENERIC Any other error
 *
 * \par Description:
 * This function will be implemented by an ICP module. The NFLC ICP framework calls it during a CDS Browse action to the designated virtual folder specified within the corresponding ICP section of the NFLC config file.
 *
 * \par Note:
 * Further details of the in_browse_option and the in_sort_critera parameters are defined by the Browse SOAP action within the UpnP-av-CDS-v1 specification
 */
TICPReturn NFLC_ICP_Browse(slim_char *in_parent, slim_char *in_browse_option,
    slim_char *in_filter, slim_char *in_start_index, slim_char *in_requested_count,
    slim_char *in_sort_criteria);

/**
 * \par Function:
 * Issue a CDS search action to an import back-end
 *
 * \par Parameters:
 *
 * <table>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_parent</td>
 *     <td>Parent ID passed in by the framework as per client request. For the root folder it is “0” folder ID’s returned by the import back-end are concatenated to the string, separated by a dot</td>
 *   </tr>
 *   <tr>
 *     <td>[in]<td>
 *     <td>in_search_criteria<td>
 *     <td>Search criteria such as “dc:creator=”Sting”” depending on client request<td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_filter</td>
 *     <td>Filter attribute from client request</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_start_index</td>
 *     <td>Starting count from “0”, clients can retrieve results in chunks setting the starting index and the in_requested_count</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_requested_count</td>
 *     <td>Number of elements requested by the client starting from in_start_index</td>
 *   </tr>
 *   <tr>
 *     <td>[in]</td>
 *     <td>in_sort_criteria</td>
 *     <td>List of return elements to be sorted by this criteria i.e. “+dc:title”</td>
 *   </tr>
 *   <tr>
 *     <td>[out]</td>
 *     <td>None</td>
 *   </tr>
 * </table>
 *
 * @return ICP_SUCCESS Request successfully understood
 * \return ICP_GENERIC Any other error
 *
 * \par Descriptio:
 * This function will be implemented by an ICP module. The NFLC ICP framework calls it during a CDS Search action to the designated virtual folder specified within the corresponding ICP section of the NFLC config file
 *
 * \par Note:
 * Further details of the parameters are defined by the Search SOAP action within the UpnP-av-CDS-v1 specification
 */
TICPReturn NFLC_ICP_Search(slim_char *in_parent, slim_char *in_search_criteria,
    slim_char *in_filter, slim_char *in_start_index, slim_char *in_requested_count,
    slim_char *in_sort_criteria);


#endif /* NFLC_ICP_PLUGIN_H */

