/*
 * info_mp4.h
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

#ifndef NFLC_INFO_MP4_H
#define NFLC_INFO_MP4_H

#define EMBEDED_ALBUM_ART_URI_PREFIX_MP4 "/embeddedMP4"DEFAULT_DMSCONFIG_ID_DELIM

struct mp4_specific_information
{
  slim_int    iHasData;       /* Set to non-zero if struct used             */
  slim_char   ftyp_major[4];  /* has ftyp info                              */
  slim_long   iAudStreamSz;   /* size of the largest audio stream in bytes  */
  slim_long   iVidStreamSz;   /* size of the largest video stream in bytes  */
  slim_long   iStreamTotal;   /* total size of all the streams              */
  slim_byte   iStreamType;    /* Current context: vid, aud, other.          */
  slim_byte   iHasVideo;      /* set to a positive if any video is found    */
  slim_byte   iHasAudio;      /* set to a positive if mp4 audio is found    */
  slim_byte   iHasMP4P2Video; /* Positive if 14496-2 (mpeg4) video found    */
  slim_byte   iHasMP2Video;   /* Positive if 13818 (mpeg2) video found      */
  slim_byte   iHasMP2Audio;   /* Positive if 13818 (mpeg2) audio found      */
  slim_byte   iHasMP1Video;   /* Positive if 11172 (mpeg1) video found      */
  slim_byte   iHasMP1Audio;   /* Positive if 11172 (mpeg1) audio found      */
  slim_byte   iHasJPEG;       /* Positive if 10918 (jpeg) content is found  */
  slim_byte   iH263Type;      /* Positive if H263 content is found (3gp)    */
  slim_byte   iH263Profile;   /* Set to the H263 Profile                    */
  slim_byte   iH263Level;     /* Set to the H263 Level                      */
  slim_byte   iHas3gpp;       /* Non-zero if 3gpp specific data is present  */
  slim_byte   iAVCFile;       /* non-zero on AVC file types                 */
  slim_byte   iAVCProfile;    /* AVC Profile (Base:66, Main:77, Extended:88, High:100; 122, 244, 44) */
  slim_byte   iAVCLevel;      /* AVC Level                                  */
  slim_byte   iConstSet0;     /* non-zero if the constraint_set1_flag set   */
  slim_byte   iConstSet1;     /* non-zero if the constraint_set1_flag set   */
  slim_byte   iConstSet2;     /* non-zero if the constraint_set1_flag set   */
  slim_byte   iConstSet3;     /* non-zero if the constraint_set1_flag set   */
  slim_byte   vid_simpObj;    /* non-zero if non-simple Objs are in MP4P2   */
  slim_byte   aud_profile;    /* Aud Prof of aud type 14496-3 Tab 1.12 p35  */
  mp4_audio_obj_type_t audobjtype;     /* Audio Object Type  14496-3 Tab 1.15 p40    */
  slim_byte   iMP4VidProf;    /* "highest" prof/lvl info for MP4P2 files    */
  dlna_uint64 mdatsize;       /* Media data size.                           */

  slim_int  iHasAmrAudio;         /* set to a positive if AMR audio is found */
  slim_int  iCurContexType;       /* 0:unknown , 1:Video , 2:Aduio (set by "hdlr" atom.) */
  slim_int  iCurContextTimescale; /* timescale */
  slim_int  isMobileMP4Profile;   /* is Mobile-MP4  */
  slim_int  isAlreadyFoundMdat;   /* parsing state : Already mdat box was found. */
  slim_int  isMdatMoovSeq;        /* is mdat->moov sequence contents  */
};

typedef struct mp4_specific_information mp4_data_t;

struct mp4_minfo_variant
{
  minfo_t    *minfo;
  mp4_data_t *mp4;

  slim_ulong  bufSize;     /* set to the size of the general buffer */
  slim_byte  *cBuff;       /* Pointer to a buffer guaranteed to be freed */

};

typedef struct mp4_minfo_variant mp4info_t;

/* 14496-1 7.2.6.6.1 */
struct mp4_Decoder_Config_Descriptor
{
  slim_byte     objectType;
  slim_byte     streamType;
  slim_byte     upStream;
  slim_ulong    bufSizeDB;
  slim_ulong    maxBitRate;
  slim_ulong    aveBitRate;

  /* Decoder Specific Info left for other structures */
  /* Profile and Level Indication index descriptors left for other structs */
};

typedef struct mp4_Decoder_Config_Descriptor mp4_DecCD_t;


/* 14496-1 7.2.6.4.1. */
struct mp4_Initial_Object_Descriptor
{
  slim_word     ObjDesc_ID;
  slim_byte     URL_Flag;
  slim_byte     Incl_Prof_Lvl;
  slim_byte     URLLen;
  slim_byte     URLStr[256];
  slim_byte     OD_PLI;
  slim_byte     scene_PLI; 
  slim_byte     audio_PLI;
  slim_byte     visual_PLI; 
  slim_byte     graphics_PLI;
};

typedef struct mp4_Initial_Object_Descriptor mp4_InitOD_t;

/* 14496-1 7.2.6.5.1. */
struct mp4_ES_Descriptor
{
  slim_word     ES_ID;
  slim_byte     streamDepFlag;
  slim_byte     URL_Flag;
  slim_byte     OCRstreamFlag;
  slim_byte     streamPrio;
  slim_byte     dependsOn_ES_ID; 
  slim_byte     URLLen;
  slim_byte     OCR_ES_ID;
  slim_byte     URLStr[256];
};

typedef struct mp4_ES_Descriptor mp4_ESDesc_t;


/* ISO/IEC 14496-14:2003.
   Coding of audio-visual objects - Part 14: MP4 File Format.  */

/* Return Types used by this code. This should be changed to a universal set later.*/
enum info_mp4_return_types {
    /* non-specific atom Types */
    MP4RC_DATA,             /* Generic Data Atom(Box)*/
    MP4RC_CONTAIN,          /* Generic Container */

    /* Specific Atom Types */
    MP4RC_DATA_NAM,         /*'0xA9'nam    - Title                */
    MP4RC_DATA_GEN,         /*'0xA9'gen    - Genre of the media        */
    MP4RC_DATA_TRKN,        /*    trkn     - Track number            */
    MP4RC_DATA_ART,         /*'0xA9'art    - Artist            */
    MP4RC_DATA_ALB,         /*'0xA9'alb    - Album name            */
    MP4RC_DATA_DAY,         /*'0xA9'day    - Date                */
    MP4RC_DATA_GRP,         /*'0xA9'grp    - Group                */
    MP4RC_DATA_CMT,         /*'0xA9'cmt    - Comment            */
    MP4RC_DATA_WRT,         /*'0xA9'wrt    - Writer             */
    MP4RC_DATA_FTYP,        /*    FTYP    - File Type            */
    MP4RC_DATA_MOOV,        /*    MOOV */
    MP4RC_DATA_IODS,        /*    IODS    - Object Descriptor box        */
    MP4RC_DATA_MVHD,        /*    MVHD    - Movie Header            */
    MP4RC_DATA_TKHD,        /*    TKHD    - Track Header            */
    MP4RC_DATA_MDAT,        /*    MDAT    - Media Data.            */
    MP4RC_DATA_VMHD,        /*    VMHD    - Video Media Header        */
    MP4RC_DATA_SMHD,        /*    SMHD    - Sound Media Header        */
    MP4RC_DATA_STSD,        /*    STSD    - sample descriptions        */
    MP4RC_DATA_STSZ,        /*    STSD    - sample descriptions        */
    MP4RC_DATA_MP4A,        /*    mp4a    - sample desc sub box        */
    MP4RC_DATA_MP4V,        /*    mp4v    - sample desc sub box        */
    MP4RC_DATA_MP4S,        /*    mp4s    - sample desc sub box        */
    MP4RC_DATA_S263,        /*    S263    - s263 descriptor box type    */
    MP4RC_DATA_SAMR,        /*    samr    -  */
    MP4RC_DATA_STTS,        /*    stts    -  */
    MP4RC_DATA_MDHD,        /*    mdhd    -  */
    MP4RC_DATA_HDLR,        /*    hdlr    -  */
    MP4RC_DATA_AVC1,        /*    avc1    - avc1 sample table box ext    */
    MP4RC_DATA_AVCC,        /*    avcC    - avcC sample table box ext    */
    MP4RC_DATA_M4DS,        /*    m4ds    - m4ds sample table box ext    */
    MP4RC_DATA_BTRT,        /*    btrt    - bitrate data box (AVC)    */
    MP4RC_DATA_ESDS,        /*    ESDS    - Extended sample desc box    */
    MP4RC_DATA_COVR,        /*    covr    - album ART cover image    */
    MP4RC_DATA_META,
    MP4RC_DATA_GNRE,				/*    gnre    - genre    */

    /* Special atom types. */
    MP4RC_HAS_DATABOX,      /* Box contains a data box with the data desired*/
    MP4RC_HAS_DATA,         /* Box contains desired data */

    /* AVC values */
    MP4RC_AVC_MP4,

    /* Other distinct Values used in info_mp4 */
    MP4RC_32BIT_BOX,        /* 32-bit size box */
    MP4RC_64BIT_BOX,        /* 64-bit size box */
    MP4RC_OK,               /* OK return value */
    MP4RC_ERROR,            /* Error Return Value */
    MP4RC_LAST_TYPE         /* Last type placeholder. */
};

typedef enum info_mp4_return_types mp4_ret_t;


struct box_information_structure
{
  slim_word    iBitSize;    /* MP4RC_32BIT_BOX MP4RC_64BIT_BOX*/
  dlna_uint64  otBoxLength; /* length of the box. This can be very large. */
  slim_byte    sBoxType[5]; /* The box type. ftyp, moov, etc...*/
  slim_byte    version;     /* MP4 box version */
  slim_ulong   flags;       /* MP4 box flags */
  dlna_uint64  iBytesRead;  /* The number of bytes processed thus far. */
  
  slim_ulong   descrLen;    /* Length of a descriptor */
  slim_ulong   bit_cnt;     /* number of remaining bits in the descriptor */
  mp4_ESDesc_t ESDesc;
  mp4_InitOD_t InitOD;
  mp4_DecCD_t  DecCD;

};

typedef struct box_information_structure box_info;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_char*
getEmbeddedAlbumArtUrifromAtom(slim_char* full_path, albumArtImage **embedded_image);

albumArtImage*
getEmbeddedAlbumArtUriImagefromAtom(slim_char* full_path);

slim_bool
register_media_info_mp4(media_manager_t *mim);

#ifdef MEDIA_PROCESSING_EXTENSION
dlna_ret_t
MPE_mpeg4_info_get (minfo_t *in_minfo, video_info_t *dinfo);
#endif /* MEDIA_PROCESSING_EXTENSION */

dlna_ret_t
mp4_info_get(minfo_t * minfo);

void
mp4_pinfo_get(minfo_t *);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_INFO_MP4_H */
