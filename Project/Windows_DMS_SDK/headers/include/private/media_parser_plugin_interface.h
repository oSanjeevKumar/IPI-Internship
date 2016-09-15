/*
 * media_parser_plugin_interface.h
 * Copyright (C) 2013 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef MEDIA_PARSER_PLUGIN_INTERFACE_H
#define MEDIA_PARSER_PLUGIN_INTERFACE_H

#include <dlna_peer.h>
#include <minfo.h> /* minfo_t */

enum {
  MPP_OK = 0,
  MPP_ALREADY_INITIALIZED,
  MPP_INVAL_STATE,
  MPP_INVAL_ARG,
  MPP_FILE_NOT_FOUND,
  MPP_GENERIC_ERROR
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @addtogroup apis
 */
/*@{*/

/*!
\par Function:
Initialize plugin module.

\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>in_xml_path</td>
		<td>Path to a directory where xml configurations stored at</td>
	</tr>
</table>

\return slim_int error code.

\par Return Values:
<table>
	<tr>
		<td> \b Error Code</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>MPP_OK</td>
		<td>Initialize succeeded</td>
	</tr>
	<tr>
		<td>MPP_INVAL_ARG</td>
		<td>Invalid arguments are specified</td>
	</tr>
	<tr>
		<td>MPP_ALREADY_INITIALIZED</td>
		<td>Plugin is already initialized</td>
	</tr>
	<tr>
		<td>MPP_GENERIC_ERROR</td>
		<td>Failed to initialize</td>
	</tr>
</table>

\par Descritpion:
This function initializes parser plugin module.<br>
This function is called when DMS starts to work.<br>
<br>
After initialization, plugin module must be ready to be called MediaParserPlugin_GetMetadata() <br>
while MediaParserPlugin_Terminate() is called.<br>
<br>
in_xml_dir is path to a directory where xml configuration files for DMS are stored at.<br>
If xml configuration files of media parser plugin module are stored at here, it can use this argument.<br>
In case media parser plugin doesn't use this argument, it can be ignore this.<br>
In case in_xml_path is slim_nil or invalid, this function may return MPP_INVAL_ARG.<br>
<br>
In case initialization succeeded, this function returns MPP_OK.<br>
In case initialization failed, this function returns MPP_GENERIC_ERROR.<br>
<br>
This function may be called multiple time. If the plugin is already initialized, this function can return MPP_ALREADY_INITIALIZED.
*/
slim_int
MediaParserPlugin_Initialize(slim_char *in_xml_dir);

/*!
\par Function:
Terminate plugin module.
\return slim_int error code.

\par Return Values:
<table>
	<tr>
		<td> \b Error Code</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>MPP_OK</td>
		<td>Terminate succeeded</td>
	</tr>
  <tr>
		<td>MPP_GENERIC_ERROR</td>
		<td>Failed to Terminate</td>
	</tr>
</table>

\par Descritpion:
This function terminates parser plugin module.<br>
This function is called when DMS terminates.<br>
<br>
After termination, DMS will unload corresponding dynamic library.<br>
Plugin's feature (e.g. MediaParserPlugin_GetMetadata()) never be called until MediaParserPlugin_Initialize() called again.<br>
<br>
In case termination succeeded, this function returns MPP_OK.<br>
In case termination failed, this function returns MPP_GENERIC_ERROR.<br>
If termination failed and returns MPP_GENERIC_ERROR, it is recommended to show the reason of failure via stdout (printf) or log file.
*/
slim_int
MediaParserPlugin_Terminate();

/*!
\par Function:
Allocate specified content's metadata

\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>in_filepath</td>
		<td>Path to a content</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_media_type</td>
		<td>Media type of content specified in in_fullpath</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_metadata</td>
		<td>Destination of metadata of content specified in in_fullpath</td>
	</tr>
</table>

\return slim_int error code.

\par Return Values:
<table>
	<tr>
		<td> \b Error Code</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>MPP_OK</td>
		<td>Metadata allocation succeeded</td>
	</tr>
	<tr>
		<td>MPP_INVAL_STATE</td>
		<td>Plugin module is not initialized</td>
	</tr>
	<tr>
		<td>MPP_INVAL_ARG</td>
		<td>Invalid arguments are specified</td>
	</tr>
	<tr>
		<td>MPP_FILE_NOT_FOUND</td>
		<td>file is not exist at the path specified in in_fullpath</td>
	</tr>
  <tr>
		<td>MPP_GENERIC_ERROR</td>
		<td>Metadata allocation failed</td>
	</tr>
</table>

\par Descritpion:
This function allocates specified content's metadata.<br>
<br>
This function must be called after MediaParserPlugin_Initialize().<br>
In case this function is called before initialization, this function returns MPP_INVAL_STATE.<br>
<br>
in_filepath specifies the path to a content to be parsed.<br>
In case in_fullpath is nil, this function returns MPP_INVAL_ARG.<br>
In case the content specified in in_fullpath is not exist, this function return MPP_FILE_NOT_FOUND.<br>
<br>
in_media_type specifies the contents's media type.<br>
In case in_media_type is nil, this function returns MPP_INVAL_ARG.<br>
<br>
Allowable values of media type are listed on parser_bindings.xml.<br>
parser_bindings.xml also indicates the relationship between extensions and media_types and its plugin modules.<br>
<br>
out_metadata is destination of parsed metadatas.<br>
In case out_metadata is nil, this function returns MPP_INVAL_ARG.<br>
<br>
The structure of minfo_t means media_info_structure.<br>
Values obtained by parsing content will be stored on this structure. This structure consists from a lot of members but <br>
this function does not need to fulfill all members. For example, the contents is still image like JPEG, this function needs <br>
to fulfill image related members, not need to do for video and audio.<br>
<br>
Error is occured in another reason, this function returns MPP_GENERIC_ERROR. 
*/
slim_int
MediaParserPlugin_GetMetadata(slim_char *in_filepath, slim_char *in_media_type, minfo_t *out_metadata);

/*@}*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MEDIA_PARSER_PLUGIN_INTERFACE_H */

