/*
 * info_asf.h
 * Copyright (C) 2007 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */

#ifndef NFLC_INFO_ASF_H
#define NFLC_INFO_ASF_H

#define EMBEDDED_ALBUM_ART_URI_PREFIX_WMA  "/embeddedWMA"DEFAULT_DMSCONFIG_ID_DELIM

/* ISO/IEC 14496-14:2003.
   Coding of audio-visual objects - Part 14: ASF File Format.  */

enum info_asf_object_types
{
  ASF_Unknown,                         /* first in list, unknown code. */
  ASF_Advanced_Cont_Encrpt_Obj,        /*43058533698149E69B74AD12CB86D58C*/
  ASF_Advanced_Mutual_Excl_Obj,        /*A08649CF477546708A166E35357566CD*/
  ASF_Audio_Media,                     /*F8699E405B4D11CFA8FD00805F5C442B*/
  ASF_Audio_Spread,                    /*BFC3CD50618F11CF8BB200AA00B4E220*/
  ASF_Bandwidth_Sharing_Exclusive,     /*AF6060AA519711D2B6AF00C04FD908E9*/
  ASF_Bandwidth_Sharing_Obj,           /*A69609E6517B11D2B6AF00C04FD908E9*/
  ASF_Bandwidth_Sharing_Partial,       /*AF6060AB519711D2B6AF00C04FD908E9*/
  ASF_Binary_Media,                    /*3AFB65E247EF40F2AC2C70A90D71D343*/
  ASF_Btrt_Mutual_Excl_Obj,            /*D6E229DC35DA11D1903400A0C90349BE*/
  ASF_Codec_List_Obj,                  /*86D15240311D11D0A3A400A0C90348F6*/
  ASF_Command_Media,                   /*59DACFC059E611D0A3AC00A0C90348F6*/
  ASF_Compatibility_Obj,               /*75B22630668E11CFA6D900AA0062CE6C*/
  ASF_Compatibility2_Obj,              /*26F18B5D458447EC9F5F0E651F0452C9*/
  ASF_Cont_Branding_Obj,               /*2211B3FABD2311D2B4B700A0C955FC6E*/
  ASF_Cont_Desc_Obj,                   /*75B22633668E11CFA6D900AA0062CE6C*/
  ASF_Cont_Encrpt_Obj,                 /*2211B3FBBD2311D2B4B700A0C955FC6E*/
  ASF_Data_Obj,                        /*75B22636668E11CFA6D900AA0062CE6C*/
  ASF_Degradable_JPEG_Media,           /*35907DE0E41511CFA91700805F5C442B*/
  ASF_Digital_Signature_Obj,           /*2211B3FCBD2311D2B4B700A0C955FC6E*/
  ASF_Error_Correction_Obj,            /*75B22635668E11CFA6D900AA0062CE6C*/
  ASF_Extd_Cont_Desc_Obj,              /*D2D0A440E30711D297F000A0C95EA850*/
  ASF_Extd_Cont_Encrpt_Obj,            /*298AE61426224C17B935DAE07EE9289C*/
  ASF_Extd_Stream_Props_Obj,           /*14E6A5CBC67243328399A96952065B5A*/
  ASF_File_Props_Obj,                  /*8CABDCA1A94711CF8EE400C00C205365*/
  ASF_File_Transfer_Media,             /*91BD222CF21C497A8B6D5AA86BFC0185*/
  ASF_Group_Mutual_Excl_Obj,           /*D1465A405A794338B71BE36B8FD6C249*/
  ASF_Header_Extn_Obj,                 /*5FBF03B5A92E11CF8EE300C00C205365*/
  ASF_Header_Obj,                      /*75B22630668E11CFA6D900AA0062CE6C*/
  ASF_Index_Obj,                       /*D6E229D335DA11D1903400A0C90349BE*/
  ASF_Index_Parms_Obj,                 /*D6E229DF35DA11D1903400A0C90349BE*/
  ASF_Index_Params_Placeholder_Obj,    /*D9AADE207C174F9CBC288555DD98E2A2*/
  ASF_JFIF_Media,                      /*B61BE1005B4E11CFA8FD00805F5C442B*/
  ASF_Language_List_Obj,               /*7C4346A9EFE04BFCB229393EDE415C85*/
  ASF_Marker_Obj,                      /*F487CD01A95111CF8EE600C00C205365*/
  ASF_Media_Obj_Index_Obj,             /*FEB103F812AD4C64840F2A1D2F7AD48C*/
  ASF_Media_Obj_Index_Parms_Obj,       /*6B203BAD3F1148E4ACA8D7613DE2CFA7*/
  ASF_Metadata_Library_Obj,            /*44231C94949849D1A1411D134E457054*/
  ASF_Metadata_Obj,                    /*C5F8CBEA5BAF48778467AA8C44FA4CCA*/
  ASF_Mutex_Btr,                       /*D6E22A0135DA11D1903400A0C90349BE*/
  ASF_Mutex_Language,                  /*D6E22A0035DA11D1903400A0C90349BE*/
  ASF_Mutex_Unknown,                   /*D6E22A0235DA11D1903400A0C90349BE*/
  ASF_No_Error_Correction,             /*20FB57005B5511CFA8FD00805F5C442B*/
  ASF_Padding_Obj,                     /*1806D474CADF4509A4BA9AABCB96AAE8*/
  ASF_Pay_Extn_Sys_Cont_Type,          /*D590DC2007BC436C9CF7F3BBFBF1A4DC*/
  ASF_Pay_Extn_Sys_Encrpt_Sample_ID,   /*6698B84E0AFA4330AEB21C0A98D7A44D*/
  ASF_Pay_Extn_Sys_File_Name,          /*E165EC0E19ED45D7B4A725CBD1E28E9B*/
  ASF_Pay_Extn_Sys_Pixel_Aspect_Ratio, /*1B1EE554F9EA4BC8821A376B74E4C4B8*/
  ASF_Pay_Extn_Sys_Sample_Duration,    /*C6BD9450867F490783A3C77921B733AD*/
  ASF_Pay_Extn_Sys_Timecode,           /*399595EC86674E2D8FDB98814CE76C1E*/
  ASF_Reserved_1,                      /*ABD3D211A9BA11cf8EE600C00C205365*/
  ASF_Reserved_2,                      /*86D15241311D11D0A3A400A0C90348F6*/
  ASF_Reserved_3,                      /*4B1ACBE3100B11D0A39B00A0C90348F6*/
  ASF_Reserved_4,                      /*4CFEDB2075F611CF9C0F00A0C90349CB*/
  ASF_Script_Command_Obj,              /*1EFB1A300B6211D0A39B00A0C90348F6*/
  ASF_Simple_Index_Obj,                /*33000890E5B111CF89F400A0C90349CB*/
  ASF_Stream_Btrt_Props_Obj,           /*7BF875CE468D11D18D82006097C9A2B2*/
  ASF_Stream_Prioritization_Obj,       /*D4FED15B88D3454F81F0ED5C45999E24*/
  ASF_Stream_Props_Obj,                /*B7DC0791A9B711CF8EE600C00C205365*/
  ASF_Timecode_Index_Obj,              /*3CB73FD00C4A4803953DEDF7B6228F0C*/
  ASF_Timecode_Index_Parms_Obj,        /*F55E496D97974B5D8C8B604DFE9BFB24*/
  ASF_Video_Media,                     /*BC19EFC05B4D11CFA8FD00805F5C442B*/
  ASF_Web_Stream_Format,               /*DA1E6B1383594050B398388E965BF00C*/
  ASF_Web_Stream_Media_Subtype,        /*776257D4C62741CB8F817AC7FF1C40CC*/

  /* 7A079BB6DAA44e12A5CA91D38DC11A8D */
  ASF_Cont_Encrpt_Sys_Win_Media_DRM_Network_Devices,
};

typedef enum info_asf_object_types asf_objtype_t;

/* Audio Codec code translaztions */
enum asf_audio_codecs
{
  asf_WMv1        = 0x0160, /* Windows Media v1            */
  asf_WMv2        = 0x0161, /* Windows Media v2            */
  asf_WMvPro      = 0x0162, /* Windows Media 9 Pro         */
  asf_WMvLossless = 0x0163, /* Windows Media 9 Lossless    */
  asf_wma_mp3     = 0x0055, /* MP3 Audio                   */
#ifdef MEDIA_PROCESSING_EXTENSION
  asf_Unknown,				/* e.g. Windows Media Voice    */
#endif /* MEDIA_PROCESSING_EXTENSION */
};

typedef enum asf_audio_codecs  asf_audcode_t;

struct obj_information_structure
{
  slim_byte     GUID[16];        /* raw ASF GUID value. */
  slim_byte     guid_string[33]; /* String value oif the GUID hex */
  asf_objtype_t obj_type;        /* the asf_objtype_t for this object's GUID */
  slim_char     cSize[8];        /* the real length of the obj as read. */
  dlna_uint64   size;            /* the integer value of the cSize[8] */
};

typedef struct obj_information_structure asf_obj_t;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_bool
register_media_info_asf(media_manager_t *mim);
#ifdef MEDIA_PROCESSING_EXTENSION
dlna_profile_t
asf_get_profile(minfo_t *asf);
slim_char *
asf_get_profile_string(dlna_profile_t profile);
asf_audcode_t
wma_get_audio_format(slim_char* wma_codec);
dlna_profile_t
wma_get_profile(minfo_t *wma);
dlna_profile_t
wmv_get_profile(minfo_t *asf);
#endif /* MEDIA_PROCESSING_EXTENSION */
#ifdef DEVELOPMENT_NFLC_PROFILER
slim_char *
asf_pinfo_get (minfo_t *asf);
#endif /* DEVELOPMENT_NFLC_PROFILER */
dlna_ret_t
asf_info_get(minfo_t *asf);

slim_char*
asf_get_embedded_album_art_uri(slim_char* full_path, albumArtImage **embedded_image);
albumArtImage*
asf_get_embedded_album_art_image(slim_char* full_path);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_INFO_ASF_H */
