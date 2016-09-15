/*
 * dmpr_api.h
 *
 Copyright (C) 2011 ACCESS CO.,LTD.
 Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.
 */

#ifndef DMPR_API_H_
#define DMPR_API_H_

#ifdef _DOXYGEN
#undef DLNA_API
#define DLNA_API
#endif

/**
 * @addtogroup enums
 */
/*@{*/

/* DMPr return value.  */
/*!
The return values for the DMPr API are shown below.
<table>
  <tr>
    <td><b>Definition</b></td>
    <td><b>Meaning</b></td>
  </tr>
  <tr>
    <td>DMPR_SUCCESS</td>
    <td>Succeeded</td>
  </tr>
  <tr>
    <td>DMPR_GENEREIC_ERROR</td>
    <td>Generic error occurred</td>
  </tr>
  <tr>
    <td>DMPR_INVALID_PARAM</td>
    <td>Invalid parameter</td>
  </tr>
  <tr>
    <td>DMPR_INVALID_ACTION</td>
    <td>Invalid action</td>
  </tr>
  <tr>
    <td>DMPR_INVALID_DESC</td>
    <td>Invalid dms configuration XML file description</td>
  </tr>
  <tr>
    <td>DMPR_OUT_OF_MEMORY</td>
    <td>Insufficient memory</td>
  </tr>
  <tr>
    <td>DMPR_SOCKET_ERROR</td>
    <td>Socket creation error</td>
  </tr>
  <tr>
    <td>DMPR_INIT_FAILED</td>
    <td>Initialization error</td>
  </tr>
  <tr>
    <td>DMPR_WOULDBLOCK</td>
    <td>Defer content access permission response</td>
  </tr>
  <tr>
    <td>DMPR_FILE_NOT_EXISTS</td>
    <td>File does not exist.</td>
  </tr>
</table>
*/
enum {
  DMPR_GENERIC_ERROR = UPNP_GENERIC_ERROR,
  DMPR_SUCCESS = UPNP_SUCCESS,
  DMPR_INVALID_PARAM = UPNP_INVALID_PARAM,
  DMPR_INVALID_ACTION = UPNP_INVALID_ACTION,
  DMPR_INVALID_DESC = UPNP_INVALID_DESC,
  DMPR_OUT_OF_MEMORY = UPNP_OUT_OF_MEMORY,
  DMPR_SOCKET_ERROR = UPNP_SOCKET_ERROR,
  DMPR_INIT_FAILED = UPNP_INIT_FAILED,
  DMPR_WOULDBLOCK = UPNP_WOULDBLOCK,
  DMPR_FILE_NOT_EXIST = UPNP_FILE_NOT_EXIST
};

/*@}*/

/**
 * @addtogroup datatypes
 */
/*@{*/

/*!
TDMPrReturn is the DMPr API return value type.

The return values for the DMPr API are shown below.
<table>
  <tr>
    <td><b>Definition</b></td>
    <td><b>Meaning</b></td>
  </tr>
  <tr>
    <td>DMPR_SUCCESS</td>
    <td>Succeeded</td>
  </tr>
  <tr>
    <td>DMPR_GENEREIC_ERROR</td>
    <td>Generic error occurred</td>
  </tr>
  <tr>
    <td>DMPR_INVALID_PARAM</td>
    <td>Invalid parameter</td>
  </tr>
  <tr>
    <td>DMPR_INVALID_ACTION</td>
    <td>Invalid action</td>
  </tr>
  <tr>
    <td>DMPR_INVALID_DESC</td>
    <td>Invalid DMPr configuration XML file description</td>
  </tr>
  <tr>
    <td>DMPR_OUT_OF_MEMORY</td>
    <td>Insufficient memory</td>
  </tr>
  <tr>
    <td>DMPR_SOCKET_ERROR</td>
    <td>Socket creation error</td>
  </tr>
  <tr>
    <td>DMPR_INIT_FAILED</td>
    <td>Initialization error</td>
  </tr>
  <tr>
    <td>DMPR_WOULDBLOCK</td>
    <td>Defer content access permission response</td>
  </tr>
  <tr>
    <td>DMPR_FILE_NOT_EXISTS</td>
    <td>File does not exist.</td>
  </tr>
</table>
*/
typedef slim_int TDMPrReturn;

typedef void* TDMPr;

/*@}*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*----------------------------------------------*/
/* prototype declaration                        */
/*----------------------------------------------*/

/**
 * @addtogroup apis
 */
/*@{*/

/*!
\par Function:
Initializes and allocates DMPr.
\par Parameters:
<table>
  <tr>
    <td>[in]</td>
    <td>progress</td>
    <td>Handler to DLNA progress</td>
  </tr>
    <tr>
    <td>[out]</td>
    <td>self</td>
    <td>DMPr structure to allocate</td>
  </tr>
</table>
\return TDMPrReturn error value;
\par Return Values:
<table>
  <tr>
    <td> \b Definition</td>
    <td> \b Meaning</td>
  </tr>
  <tr>
    <td>DMPR_SUCCESS</td>
    <td>Successful initialization</td>
  </tr>
    <tr>
    <td>DMPR_GENERIC_ERROR</td>
    <td>Generic error occurred during starting DMPr</td>
  </tr>
    <tr>
    <td>DMPR_INIT_FAILED</td>
    <td>Allocation of DLNA progress failed</td>
  </tr>
  <tr>
    <td>DMPR_OUT_OF_MEMORY</td>
    <td>Out of memory</td>
  </tr>
   <tr>
    <td>DMPR_INVALID_PARAM</td>
    <td>One of given parameters was a NULL pointer</td>
  </tr>
</table>
\par Description:
Function allocates DLNA progress and DMPr and initialize it and after successful initialization starts DMPr
*/

TDMPrReturn
dlnaDMPrInitialize(struct dmpr**  self,dlna_progress *progress);

/*!
\par Function:
Finalize DMPr.
\par Parameters:
<table>
  <tr>
    <td>[in]</td>
    <td>self</td>
    <td>DMPr instance</td>
  </tr>
    <tr>
    <td>[in]</td>
    <td>progress</td>
    <td>Handler to DLNA progress</td>
  </tr>
</table>
\return none
\par Description:
Function stops DLNA progress and DMPr and after that frees DMPr instance and progress.
*/

void
dlnaDMPrFinalize(struct dmpr*  self,dlna_progress progress);

/*@}*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* DMPR_API_H_ */
