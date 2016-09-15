/*
 * pluspr_api.h
 * Copyright (C) 2008-2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */
#ifndef _DMPr_API_H
#define _DMPr_API_H

#include <dlna_api.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus  */

#ifdef DEVELOPMENT_DLNA_SUPPORT_DMPR

/* DMPr API return code.  */
/*!
Succeeded (=0)
*/
#define DMPr_E_OK                                       DLNA_E_OK
/*!
Generic error
*/
#define DMPr_E_GENERIC                                  DLNA_E_GENERIC
/*!
Invalid argument (s) specified
*/
#define DMPr_E_INVAL                                    DLNA_E_INVAL
/*!
Insufficient memory
*/
#define DMPr_E_NOMEM                                    DLNA_E_NOMEM
#define DMPr_E_DEV                                      DLNA_E_DEV
#define DMPr_E_OBJ                                      DLNA_E_OBJ
#define DMPr_E_ITEM_EX                                  DLNA_E_ITEM_EX
#define DMPr_E_URI                                      DLNA_E_URI
#define DMPr_E_COMM                                     DLNA_E_COMM
#define DMPr_E_NOFILE                                   DLNA_E_NOFILE
#define DMPr_E_FILE_IO                                  DLNA_E_FILE_IO
#define DMPr_E_FILE_EX                                  DLNA_E_FILE_EX
#define DMPr_E_NOT_SUPPORT                              DLNA_E_NOT_SUPPORT
#define DMPr_API_ERROR                                  DLNA_API_ERROR

#define TDMPrObjectEventHandler TDLNAObjectEventHandler
/*!
Structure for setting the parameters of the dlnaDmprObjectPrint action.

\code
struct dlna_param_dmpr
{
	slim_int image_width ;
	slim_int image_height ;
	dlna_dmpr_orientation orientation;
	slim_char *jobname;
	slim_char *title;
	slim_char *mediatype;
	slim_char *mediasize;
	slim_int copies ;
	slim_int fontsize ;
	slim_int margins ;
	dlna_dmpr_quality quality;
};
typedef struct dlna_param_dmpr TDMPrObjectDmprParam;
\endcode

\par Member:

<table>
	<tr>
		<td>Image_width</td>
		<td>width in pixel of the image. This parameter is used internally<br/>
			and doesn't need to be set by the application</td>
	</tr>
	<tr>
		<td>Image_height</td>
		<td>height in pixel of the image. This parameter is used internally
			and doesn't need to be set by the application</td>
	</tr>
	<tr>
		<td>orientation</td>
		<td>print orientation such as landscape and portrait</td>
	</tr>
	<tr>
		<td>jobname</td>
		<td>name of the printjob</td>
	</tr>
	<tr>
		<td>title</td>
		<td>title of the printjob. If specified it will be printed on top of the image</td>
	</tr>
	<tr>
		<td>mediatype</td>
		<td>mediatype obtained by dlnaDmprGetMediaListItem</td>
	</tr>
	<tr>
		<td>mediasize</td>
		<td>mediasize obtained by dlnaDmprGetMediaListItem</td>
	</tr>
	<tr>
		<td>copies</td>
		<td>number of copies</td>
	</tr>
	<tr>
		<td>fontsize</td>
		<td>fontsize in pt used to print the title</td>
	</tr>
	<tr>
		<td>margins</td>
		<td>print margins in mm</td>
	</tr>
</table>

\code
enum dlna_dmpr_orientation_
{
	DLNA_DMPR_ORIENTATION_LANDSCAPE,
	DLNA_DMPR_ORIENTATION_PORTRAIT,
	DLNA_DMPR_ORIENTATION_REVERSE_LANDSCAPE,
	DLNA_DMPR_ORIENTATION_REVERSE_PORTRAIT,
	DLNA_DMPR_ORIENTATION_DEVICESETTING
};

enum dlna_dmpr_quality_
{
	DLNA_DMPR_PRINTQUALITY_NORMAL,
	DLNA_DMPR_PRINTQUALITY_DRAFT,
	DLNA_DMPR_PRINTQUALITY_HIGH,
	DLNA_DMPR_PRINTQUALITY_DEVICESETTING
};
\endcode
*/
#define TDMPrObjectDmprParam  TDLNAObjectDmprParam
#define TDMPrObjectDmprEHParam  TDLNAObjectDmprEHParam
#define TDMPrObjectDmprAttributesEHParam TDLNAObjectDmprAttributesEHParam
#define TDMPrObjectDmprJobAttributesEHParam TDLNAObjectDmprJobAttributesEHParam

/*!
Print succeeded
*/
#define DMPr_OBJECT_EV_PRINT_OK                         DLNA_OBJECT_EV_DMPr_PRINT_OK
/*!
Print failed
*/
#define DMPr_OBJECT_EV_PRINT_FAILED                     DLNA_OBJECT_EV_DMPr_PRINT_FAILED
#define DMPr_OBJECT_EV_DMPr_GET_PRINTER_ATTRIBUTES      DLNA_OBJECT_EV_DMPr_GET_PRINTER_ATTRIBUTES
#define DMPr_OBJECT_EV_DMPr_CANCEL_JOB                  DLNA_OBJECT_EV_DMPr_CANCEL_JOB
#define DMPr_OBJECT_EV_DMPr_PRINT_FILE_SUCCESS          DLNA_OBJECT_EV_DMPr_PRINT_FILE_SUCCESS
#define DMPr_OBJECT_EV_DMPr_PRINT_FILE_FAILED           DLNA_OBJECT_EV_DMPr_PRINT_FILE_FAILED
#define DMPr_OBJECT_EV_DMPr_PRINT_URI_SUCCESS           DLNA_OBJECT_EV_DMPr_PRINT_URI_SUCCESS
#define DMPr_OBJECT_EV_DMPr_PRINT_URI_FAILED            DLNA_OBJECT_EV_DMPr_PRINT_URI_FAILED

/* gena events */
/*!
Print state has changed
*/
#define DMPr_EV_GENA_DMPR_PRINTER_STATE								DLNA_EV_GENA_DMPR_PRINTER_STATE
/*!
Print state reasons	
*/
#define DMPr_EV_GENA_DMPR_PRINTER_STATE_REASONS				DLNA_EV_GENA_DMPR_PRINTER_STATE_REASONS
/*!
List of job ids
*/
#define DMPr_EV_GENA_DMPR_JOB_ID_LIST									DLNA_EV_GENA_DMPR_JOB_ID_LIST
/*!
MediaSheetsCompleted
*/
#define DMPr_EV_GENA_DMPR_JOB_MEDIA_SHEETS_COMPLETED	DLNA_EV_GENA_DMPR_JOB_MEDIA_SHEETS_COMPLETED
/*!
Content complete list
*/
#define DMPr_EV_GENA_DMPR_CONTENT_COMPLETE_LIST				DLNA_EV_GENA_DMPR_CONTENT_COMPLETE_LIST
/*!
Job abortion state
*/
#define DMPr_EV_GENA_DMPR_JOB_ABORT_STATE							DLNA_EV_GENA_DMPR_JOB_ABORT_STATE
/*!
Job completion state
*/
#define DMPr_EV_GENA_DMPR_JOB_END_STATE								DLNA_EV_GENA_DMPR_JOB_END_STATE
	
/* DMPt Object types.  */
typedef void * TDMPrObject;

/*!
\par Function:
Prints a media object.
\par Parameters: 

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Printer device object</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_obj_eh</td>
		<td>DMPr object event handler</td>
	</tr>
		<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument of dlnaDmprObjectPrint action that identifies exclusive call of the action and is returned in DMPrObjectEventHandler function</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_obj</td>
		<td>The media object to print</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_res_index</td>
		<td>The media object resource index used to print</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_param</td>
		<td>Printer parameter structure</td>
	</tr>
</table> 

\return DMPr_E_OK Succeeded
\return Other Error
\par Description:
This function prints a media object. This function returns immediately, and notifies caller with a
DMPr_OBJECT_EV_PRINT_OK or DMPr_OBJECT_EV_PRINT_FAILED event.
\par Example:

\code
void foo
{
	TDMPrObjectDmprParam parm;
	slim_int ret;
	TDMPrObject printer ;
	TDMPrObject obj ;
	....
	ret = dlnaDmprGetMediaListItem (printer, 0, &parm. mediatype,
	&parm. mediasize);
	parm.jobname = SLIM_T("The jobname ") ;
	parm.title = SLIM_T("Text to print") ;);
	parm.orientation = DLNA_DMPR_ORIENTATION_LANDSCAPE ;
	parm.copies = 1 ;
	parm.fontsize = 36 ;
	parm.margins = 5 ;
	ret = dlnaDmprObjectPrint (printer, dmpr_object_eh,
	(void *)0, obj,-1,&parm);
	if (ret != DMPr_E_OK) 
	{
		fprintf (stderr, "Start to print failed, error: %d\n", ret);
		return;
	}
}

static void
dmpr_object_eh (TDMPObject self, TDMPObjectEvent in_event, void *in_arg,void *in_param)
{
	TDMPrObjectDmprEHParam *parm ;
	parm = (TDMPrObjectDmprEHParam *)in_param ;
	switch (in_event) {
		case DMPr_OBJECT_EV_PRINT_OK:
			fprintf (stderr, "Print succeeded JOBID=%d \n",parm->jobID ) ;
			break ;
		case DMPr_OBJECT_EV_PRINT_FAILED:
			fprintf (stderr, "Print failed! SOAP=%d HTTP:%d\n",parm->soap_error_code, parm->http_error_code);
			break;
}
\endcode
*/
DLNA_API slim_int
dlnaDmprObjectPrint (TDMPrObject self, TDMPrObjectEventHandler in_obj_eh,
                                                 void *in_arg,TDMPrObject in_obj,slim_int in_res_index,TDMPrObjectDmprParam *param);

/*!
\par Function:
Retrieve the number of Media types supported by the printer.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>The printer device object</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_count</td>
		<td>Number of Media types</td>
	</tr>
</table>
	
\return DMPr_E_OK Succeeded
\return Other Error
\par Description:
This function returns the number of Media Types supported by the selected printer.
\par Example:

\code
void foo
{
	TDMPrObject printer;
	slim_int ret;
	slim_int count ;
	ret = dlnaDmprGetMediaListItemCount (printer, &count);
	if (ret == DMPr_E_OK) 
	{
		fprintf (stderr, "Number of media types = %d \n", count);
	}
}
\endcode
*/
DLNA_API slim_int
dlnaDmprGetMediaListItemCount(TDMPrObject self,slim_int *out_count) ;

/*!
\par Function:
Retrieves the media type description from the list.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>printer object handle</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>index</td>
		<td>Index of the media type description</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_name</td>
		<td>Desciptive name of the paper slot</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_value</td>
		<td>The media type of the paper slot</td>
	</tr>
</table>

\return	DMPr_E_OK Succeeded
\return Other Error
\par Description:
This function retrieves a printer media type description out of the list of available media types.
\par Example:

\code
void foo
{
	TDMPrObject printer;
	slim_int ret;
	slim_char *name ;
	slim_char *value ;
	slim_int count ;
	slim_int i ;
	ret = dlnaDmprGetMediaListItemCount (printer, &count);
	if (ret == DMPr_E_OK) 
	{
		for(i=0;i<count;i++)
		{
			ret = dlnaDmprGetMediaListItem (printer, i, &name, &value);
			if (ret == DMPr_E_OK) 
			{
				fprintf (stderr, "Paper slot name: %s size: %s \n", name, value);
			}
		}
	}
}
\endcode
*/
DLNA_API slim_int
dlnaDmprGetMediaListItem(TDMPrObject self,slim_int index, slim_char **out_name, slim_char **out_value) ;

/*!
\par Function:
Cancel a Printjob.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>Printer device object</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_obj_eh</td>
		<td>DMPr object event handler</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument of dlnaDmprCancelJob action that identifies exclusive call of the
action and is returned in DMPrObjectEventHandler function</td>
	</tr>
		<tr>
		<td>[in]</td>
		<td>in_job_id</td>
		<td>ID of a print job.</td>
	</tr>
</table>
	

\return	DMPr_E_OK Succeeded
\return Other Error
\par Description:
This function prints a media object. This function returns immediately, and notifies caller with a DMPr_
DMPr_OBJECT_EV_DMPr_CANCEL_JOB event.
\par Example:

\code
void foo
{
	TDMPrObject printer ;
	slim_int JobID ;
	.........
	ret = dlnaDmprCancelJob (printer, dmpr_object_eh,(void *)0,JobID);
	if (ret != DMPr_E_OK) 
	{
		fprintf (stderr, " error: %d\n", ret);
		return;
	}
}
	
static void
dmpr_object_eh (TDMPObject self, TDMPObjectEvent in_event, void *in_arg,void *in_param)
{
	TDMPrObjectDmprEHParam *parm ;
	parm = (TDMPrObjectDmprEHParam *)in_param ;
	switch (in_event) {
		case DLNA_OBJECT_EV_DMPr_CANCEL_JOB:
		{
			fprintf (stderr,"JOBID=%d Err:%d\n",parm->jobID,parm->soap_error_code ) ;
		}
		
		break ;
}
\endcode
*/
DLNA_API slim_int
dlnaDmprCancelJob(TDMPrObject self, TDMPrObjectEventHandler in_obj_eh, void *in_arg, slim_int in_job_id) ;

/*!
\par Function:
Prints a media object.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>printer device object</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_obj_eh</td>
		<td>DMPr object event handler</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument of dlnaDmprObjectPrint action that identifies exclusive call of the
		action and is returned in DMPrObjectEventHandler function</td>
	</tr>
</table>

\return DMPr_E_OK Succeeded
\return Other Error
\par Description:
This function prints a media object. This function returns immediately, and notifies caller with a DMPr_
DMPr_OBJECT_EV_DMPr_GET_PRINTER_ATTRIBUTES event.
\par Example:

\code
void foo
{
	TDMPrObject printer ;
	...
	ret = dlnaDmprGetPrinterAttributes (printer, dmpr_object_eh,
	(void *)0);
	if (ret != DMPr_E_OK) 
	{
		fprintf (stderr, " error: %d\n", ret);
		return;
	}
}
	
static void
dmpr_object_eh (TDMPObject self, TDMPObjectEvent in_event, void *in_arg,
void *in_param)
{
	TDMPrObjectDmprAttributesEHParam *parm ;
	parm = (TDMPrObjectDmprAttributesEHParam *)in_param ;
	switch (in_event) {
		case DLNA_OBJECT_EV_DMPr_GET_PRINTER_ATTRIBUTES:
		{
			TDMPrObjectDmprAttributesEHParam *parm =
			(TDMPrObjectDmprAttributesEHParam *)pData->in_param ;
			printf("err_code:%d\n",parm->soap_error_code);
			printf("err_Description:%s\n",parm->err_description) ;
			printf("printer_state:%s\n",parm->printer_state) ;
			printf("printer_state_reasons:%s\n",parm->printer_state_reasons) ;
			printf("job_id_list:%s\n",parm->job_id_list) ;
			printf("job_id:%s\n",parm->job_id) ;
			printf("internet_connect_state:%s\n",parm->internet_connect_state) ;
		}
		break ;
}
\endcode
*/
DLNA_API slim_int
dlnaDmprGetPrinterAttributes(TDMPrObject self, TDMPrObjectEventHandler in_obj_eh, void *in_arg) ;

/*!
\par Function:
Gets DMPr job attributes.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>printer device object</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_obj_eh</td>
		<td>DMPr object event handle</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument of dlnaDmprObjectPrint action that identifies exclusive call of the action and is returned in DMPrObjectEventHandler function</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_job_id</td>
		<td>job identifier</td>
	</tr>
</table>
\return slim_int error code value
\par Return Values:
<table>
	<tr>
		<td> \b DMPr_E_OK</td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td>DMPr_E_INVAL</td>
		<td>Invalid value(s) specified</td>
	</tr>
	<tr>
		<td>DMPr_E_GENERIC</td>
		<td>Generic error</td>
	</tr>
</table>
\par Description:
This function gets DMPr job attributes for job specified by in_job_id.
*/
DLNA_API slim_int
dlnaDmprGetJobAttributes(TDMPrObject self, TDMPrObjectEventHandler in_obj_eh, void *in_arg, slim_int in_job_id) ;

/*!
\par Function:
Initializes DMPr controller.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>in_device</td>
		<td>The device (DMC/DMP) pointer</td>
	</tr>
</table>
\return slim_int error code value
\par Return Values:
<table>
	<tr>
		<td> \b DMPr_E_OK</td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td>DMPr_E_INVAL</td>
		<td>Invalid value(s) specified</td>
	</tr>
	<tr>
		<td>DMPr_E_GENERIC</td>
		<td></td>
	</tr>
</table>
\par Description:
This function allocates and initializes DMPr controller for printer device object.
*/
DLNA_API slim_int
dlnaDmprInitialize (void *in_device);
/*!
\par Function:
Finalizes DMPr controller.
\par Parameters:
none
</table>
\return none
\par Description:
This function finalizes and frees DMPr controller for printer device object.
*/
DLNA_API void
dlnaDmprFinalize ();

/*!
\par Function:
Prints resource on DMPr printer.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>printer device object</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_obj_eh</td>
		<td>DMPr object event handle</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument of dlnaDmprObjectPrint action that identifies exclusive call of the action and is returned in DMPrObjectEventHandler function</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>object</td>
		<td>Object witch store resources</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_res_index</td>
		<td>resource index</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_param</td>
		<td>resource parameter</td>
	</tr>
</table>
\return slim_int error code value
\par Return Values:
<table>
	<tr>
		<td> \b DMPr_E_OK</td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td>DMPr_E_INVAL</td>
		<td>Invalid value(s) specified</td>
	</tr>
	<tr>
		<td>DMPr_E_GENERIC</td>
		<td>Generic error occurred</td>
	</tr>
	<tr>
		<td>DMPr_E_DEV</td>
		<td>Given device pointer is slim_nil</td>
	</tr>
</table>
\par Description:
This function prints resource from object specified by in_res_index with object parameter given in in_param.
*/
DLNA_API slim_int
dlnaDmprObjectPrint2 (TDMPrObject self, TDMPrObjectEventHandler in_obj_eh,
                                                 void *in_arg, TDMPrObject object,slim_int in_res_index,TDMPrObjectDmprParam  *in_param);

/*!
\par Function:
Prints file on DMPr printer.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>printer device object</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_obj_eh</td>
		<td>DMPr object event handle</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument of dlnaDmprObjectPrint action that identifies exclusive call of the action and is returned in DMPrObjectEventHandler function</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_file_path</td>
		<td>File path to print</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_param</td>
		<td>File parameter</td>
	</tr>
</table>
\return slim_int error code value
\par Return Values:
<table>
	<tr>
		<td> \b DMPr_E_OK</td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td>DMPr_E_INVAL</td>
		<td>Invalid value(s) specified</td>
	</tr>
	<tr>
		<td>DMPr_E_GENERIC</td>
		<td>Generic error occurred</td>
	</tr>
	<tr>
		<td>DMPr_E_DEV</td>
		<td>Given device pointer is slim_nil</td>
	</tr>
</table>
\par Description:
This function prints file specified by in_file_path with object parameter given in in_param.
*/
DLNA_API slim_int
dlnaDmprObjectPrintFile (TDMPrObject self, TDMPrObjectEventHandler in_obj_eh,
                                                 void *in_arg, slim_char *in_file_path,TDMPrObjectDmprParam  *in_param);

/*!
\par Function:
Performs query on DMPr printer.
\par Parameters:
<table>
	<tr>
		<td>[in]</td>
		<td>self</td>
		<td>printer device object</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_obj_eh</td>
		<td>DMPr object event handle</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_arg</td>
		<td>Argument of dlnaDmprObjectPrint action that identifies exclusive call of the action and is returned in DMPrObjectEventHandler function</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>in_var_name</td>
		<td>File path to print</td>
	</tr>
</table>
\return slim_int error code value
\par Return Values:
<table>
	<tr>
		<td> \b DMPr_E_OK</td>
		<td> \b Success</td>
	</tr>
	<tr>
		<td>DMPr_E_INVAL</td>
		<td>Invalid value(s) specified</td>
	</tr>
	<tr>
		<td>DMPr_E_GENERIC</td>
		<td>Error occurred during performing query or at least one given parameter was a slim_nil</td>
	</tr>
</table>
\par Description:
This function performs query with variable specified in in_var_name.
*/
slim_int
dlnaDmprQueryValue (TDMPrObject self,  TDMPrObjectEventHandler in_obj_eh,
                                                 void *in_arg, slim_char *in_var_name);
#endif /* DEVELOPMENT_DLNA_SUPPORT_DMPR */ 
#ifdef __cplusplus
}
#endif /* __cplusplus  */
#endif /* _DMPr_API_H */

