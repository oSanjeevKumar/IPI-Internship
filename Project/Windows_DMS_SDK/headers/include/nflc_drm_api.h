/*
 * nflc_drm_api.h
 * Copyright (C) 2007 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_DRM_API_H
#define NFLC_DRM_API_H

#include <dlna_peer.h>

/**
 * @addtogroup enums
 */
/*@{*/

/** DRM types
 */
enum media_drm_type {
  MINFO_DRM_TYPE_UNKNOWN,      /**< Unknown DRM media type */
  MINFO_DRM_TYPE_NONE,         
  MINFO_DRM_TYPE_DTCP_IP_SRC,  /**< DTCP-IP Source type */
  MINFO_DRM_TYPE_DTCP_IP_SNK,  /**< DTCP-IP Sink type */
  MINFO_DRM_TYPE_enum_end
};

/*@}*/

/**
 * @addtogroup datatypes
 */
/*@{*/

/*! \var typedef enum media_drm_type media_drm_t
    \brief DRM type

    
*/

typedef enum media_drm_type media_drm_t;

/*@}*/

/* Mode */
enum media_drm_mode {
  MINFO_DRM_MODE_NORMAL,
  MINFO_DRM_MODE_MOVE,
  MINFO_DRM_MODE_RETENTION,
  MINFO_DRM_MODE_enum_end,
};
typedef enum media_drm_mode minfo_drm_mode;

/* Retention State(Time to retention) */
enum media_drm_retension_state {
  MINFO_DRM_RETENTION_FOREVER,
  MINFO_DRM_RETENTION_1WEEK,
  MINFO_DRM_RETENTION_2DAYS,
  MINFO_DRM_RETENTION_1DAYS,
  MINFO_DRM_RETENTION_12HOURS,
  MINFO_DRM_RETENTION_6HOURS,
  MINFO_DRM_RETENTION_3HOURS,
  MINFO_DRM_RETENTION_90MINUTES,
  MINFO_DRM_RETENTION_enum_end
};
typedef enum media_drm_retension_state minfo_drm_retension;

/* APS */
enum media_drm_aps {
  MINFO_DRM_APS_COPY_FREE,	/* Copy Free */
  MINFO_DRM_APS_TYPE1,		/* AGC */
  MINFO_DRM_APS_TYPE2,		/* AGC + 2L Colorstripe */
  MINFO_DRM_APS_TYPE3,		/* AGC + 4L Colorstripe */
  MINFO_DRM_APS_enum_end
};
typedef enum media_drm_aps minfo_drm_aps;

/* Image Constraint Token */
enum media_drm_ict {
  MINFO_DRM_ICT_HD_ANALOG_OUTPUT,
  MINFO_DRM_ICT_CONSTRAINTED_HD_ANALOG_OUTPUT,
  MINFO_DRM_ICT_enum_end
};
typedef enum media_drm_ict minfo_drm_ict;

/* EPN(Encryption Plus Non-assertion) */
enum media_drm_epn {
  MINFO_DRM_EPN_UNASSERTED,
  MINFO_DRM_EPN_ASSERTED,
  MINFO_DRM_EPN_enum_end
};
typedef enum media_drm_epn minfo_drm_epn;

/**
 * @addtogroup enums
 */
/*@{*/

/** Copy Control Information
 */

/* Copy Control Information */
enum media_drm_cci {
  MINFO_DRM_CCI_COPY_FREE,		/**< Copy freely with EPN unasserted */
  MINFO_DRM_CCI_COPY_FREE_EPN_ASSERTED,	/**< Copy freely with EPN asserted */
  MINFO_DRM_CCI_COPY_ONE_GEN,		/**< Copy-one-Generation */
  MINFO_DRM_CCI_NO_MORE_COPYS,	        /**< No More Copies */
  MINFO_DRM_CCI_COPY_NEVER,		/**< Copy Never */
  MINFO_DRM_CCI_enum_end
};

/*@}*/

/**
 * @addtogroup datatypes
 */
/*@{*/

/*! \var typedef enum media_drm_cci minfo_drm_cci
    \brief copy control information 

    
*/

typedef enum media_drm_cci minfo_drm_cci;

/*@}*/

/* Copy Control Information */
enum media_dtcp_cci {
  MINFO_DTCP_CCI_COPY_FREE       = 0x00,  /* Copy Free */
  MINFO_DTCP_CCI_NO_MORE_COPYS	 = 0x01,  /* No More Copies */  
  MINFO_DTCP_CCI_COPY_ONE_GEN	 = 0x02,  /* Copy-one-Generation */  
  MINFO_DTCP_CCI_COPY_NEVER      = 0x03,  /* Copy Never */
  MINFO_DTCP_CCI_COPY_FREE_EPN_ASSERTED = 0x04,/* Copy Free */
  MINFO_DTCP_CCI_COPY_ONCE_RADIO = 0x05,/* Copy Once Radio */  
  MINFO_DTCP_CCI_enum_end
};
typedef enum media_dtcp_cci minfo_dtcp_cci;

/**
 * @addtogroup structures
 */
/*@{*/

/* Dtcp Device Entry */
struct dtcp_device_entry
{
  media_drm_t type;
  slim_opaque device;
};

/*!	
Structure that stores parameters used for registering a DTCP-IP instance and 
a callback function in DRM Manager.

\code

struct dtcp_device_entry
{
  media_drm_t type;
  slim_opaque device;
};
typedef struct dtcp_device_entry dtcp_device_entry_t;

\endcode

\par Member: 

	<table>
	<tr>
		<td>type</td>
		<td>DRM media type</td>
	</tr>
	<tr>
		<td>device</td>
		<td>DTCP-IP device information</td>
	</tr>
</table>

*/

typedef struct dtcp_device_entry dtcp_device_entry_t;

/*@}*/

/* DRM Entry */
struct drm_entry
{
  struct drm_entry *next;	/* for list oparation */
  struct drm_entry *prev;	/* for list oparation */

  media_drm_t type;
  slim_opaque entity;
};
typedef struct drm_entry drm_entry_t;

/* DRM Manager */

/**
 * @addtogroup apis
 */
/*@{*/

/*!	
\par Function:
Callback function to get DRM copy control information.
\par Parameters: 

<table>
	<tr>
		<td>[in]</td>
		<td>in_fname</td>
		<td>Content file name</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>out_cci</td>
		<td>Copy control information</td>
	</tr>
</table>
 
\return DRM media information type
\return !=DTCP_E_OK  Failed
\par Description:
Not currently supported. Behavior of this function is not guaranteed. 
Schedule has not been determined. MINFO_DRM_TYPE_UNKNOWN must be returned as 
the return value under the current implementation.

*/

typedef media_drm_t (*get_drm_info) (slim_char *in_fname, minfo_drm_cci *out_cci);

/*@}*/

typedef get_drm_info TDLNADRMManagerCallback;

struct drm_manager
{
  get_drm_info get_info_proc;  /* Pointer to function to get CCI */
  List (drm_entry_t *) entries;
};
typedef struct drm_manager drm_manager_t;

/* DRM Information of content */
struct media_drm_information {
  media_drm_t type;
  minfo_drm_mode mode;
  minfo_drm_retension ret_state;
  minfo_drm_aps aps;
  minfo_drm_ict img_const;
  minfo_drm_epn epn;
  minfo_drm_cci cci;
  drm_manager_t *manager;

  dlna_uint64 pcp_encrypted_size;
};
typedef struct media_drm_information minfo_drm_t;


#endif /* NFLC_DRM_API_H */
