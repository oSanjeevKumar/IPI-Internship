/* -------------------------------------------------------------------------------- */
/*! @file info_mp4_mobile.h
 *  @brief 2009/12/4 i-motion (Mobile MP4) contents
 *
 *  Copyright(c) 2009 OKI ACCESS Technologies Co.,Ltd.
 *  All rights are reserved by OKI ACCESS Technologies Co.,Ltd.,
 *  whether the whole or part of the source code including any modifications.
 *
 *  $Rev: 7 $
 */
/* -------------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------------- */
#ifndef info_mp4_mobile_h_200912070949
#define info_mp4_mobile_h_200912070949
#include <dlna_peer.h>
/* -------------------------------------------------------------------------------- */
#define MMP4_INFO_MP4_DEBUG_LEVEL  (0)

/* -------------------------------------------------------------------------------- */
#define MMP4_PRINT_BIN_LEN 24

/* -------------------------------------------------------------------------------- */
#if ( MMP4_INFO_MP4_DEBUG_LEVEL > 2 )
/*! @brief (for debug) */
static const char*
mmp4_printable_bin( const unsigned char* bin , int len )
{
	static char buf[256];
	int  i;
	char* p = buf;

	dlna_memset( buf , 0 , 256 );

	for( i=0; i<len; ++i ){
		int byte = bin[i];
		int byteL , byteH;
		byteL =  byte & 0x0000000F;
		byteH = (byte & 0x000000F0) >>4;
		*p = (char)( byteH + ( (byteH < 10) ? '0' : ('A' -10) ) );  ++p;
		*p = (char)( byteL + ( (byteL < 10) ? '0' : ('A' -10) ) );  ++p;
		if( i >= (MMP4_PRINT_BIN_LEN -1) ){ break; }
		if( ((i+1) &0x03) ==0 ){ *p = '-';  ++p; }
	}

	if( len >= MMP4_PRINT_BIN_LEN  ){
		*p = '.';  ++p;
		*p = '.';  ++p;
		*p = '.';  ++p;
	}

	{ *p = '(';  ++p; }
	for( i=0; i<len; ++i ){
		int byte = bin[i];
		if( dlna_isprint(byte)
			&& (byte != '\t')
			&& (byte != '\n')
			){
			*p = (char)byte;
		}else{
			*p = '.';
		}
		++p;
		if( i >= (MMP4_PRINT_BIN_LEN -1) ){ break; }
	}
	{ *p = ')';  ++p; }

	*p = '\0';
	return buf;
}
#endif


#if ( MMP4_INFO_MP4_DEBUG_LEVEL > 1 )
/*! @brief (for debug) */
static void
mmp4_print_filePos( dlna_file_t fileDesc , const char* comment , int arg1 , void* arg2 )
{
	int  retBytes;
	dlna_off_t  curOffset;
	unsigned char  binBuffer[32];
	assert( sizeof(dlna_off_t) == 4 );

	curOffset = dlnaFileSeekPeer( fileDesc , 0 , DLNA_SEEK_CUR );

	retBytes = dlnaFileReadPeer( fileDesc , binBuffer , 32 );

	DLNA_DP((
		"[mmp4]<%s> arg1=%d, arg2=%p : file-offset=%08X\n"
		"[mmp4]    %s\n"
		, comment , arg1 , arg2 , (unsigned int)curOffset
		, mmp4_printable_bin( &binBuffer[0] , retBytes )
		));

	curOffset = dlnaFileSeekPeer( fileDesc , ( - retBytes) , DLNA_SEEK_CUR );
}
#endif


/*! @brief (for debug) */
#if ( MMP4_INFO_MP4_DEBUG_LEVEL > 0 )
#  define mmp4_printf(arg)  { DLNA_DP(("[m-mp4]")); DLNA_DP( arg );}
#else
#  define mmp4_printf(arg)
#endif


#if ( MMP4_INFO_MP4_DEBUG_LEVEL > 1 )
/*! @brief (for debug) */
static void
mmp4_print_audio_strema_information( const mp4info_t* pMp4Info )
{
	minfo_aud_t* pAudio = &pMp4Info->minfo->aud;
	mmp4_printf(( "  <minfo_aud_t>\n" ));
	mmp4_printf(( "    aveBitrate=%d , maxBitrate=%d\n" , (int)pAudio->aveBitrate , (int)pAudio->maxBitrate ));
	mmp4_printf(( "    format=%d , chans=%d\n" , pAudio->format , pAudio->chans ));
	mmp4_printf(( "    samps=%d , aveBps=%d\n" , pAudio->samps , pAudio->aveBps ));
	mmp4_printf(( "    block_align=%d , bitsPerSamp=%d\n" , pAudio->block_align , pAudio->bitsPerSamp ));
	mmp4_printf(( "    chanprof=%d , version=%d\n" , pAudio->chanprof , pAudio->version ));
	mmp4_printf(( "    layer=%d , protection=%d\n" , pAudio->layer , pAudio->protection ));
	mmp4_printf(( "    data_length=%d\n" , pAudio->data_length ));
}


/*! @brief (for debug) */
static void
mmp4_print_video_strema_information( const mp4info_t* pMp4Info )
{
	minfo_vid_t* pVideo = &pMp4Info->minfo->vid;
	mmp4_printf(( "  <minfo_vid_t>\n" ));
	mmp4_printf(( "    width=%d , height=%d\n" , pVideo->width , pVideo->height ));
	mmp4_printf(( "    aveBitrate=%d , maxBitrate=%d\n" , (int)pVideo->aveBitrate , (int)pVideo->maxBitrate ));
	mmp4_printf(( "    video_format=%d\n" , pVideo->video_format ));
	mmp4_printf(( "    framerate=%f , framerate_code=%d\n" , pVideo->framerate , pVideo->framerate_code ));
	mmp4_printf(( "    aspect_code=%d , video_flags=%d\n" , pVideo->aspect_code , pVideo->video_flags ));
	mmp4_printf(( "    have_ifo=%d\n" , pVideo->have_ifo ));
}

/*! @brief (for debug) */
static void
mmp4_print_mp4_specific_infomation( const mp4info_t* pMp4Info )
{
	mp4_data_t* pMp4Data = pMp4Info->mp4;
	mmp4_printf(( "  <mp4_data_t>\n" ));
	mmp4_printf(( "    isMdatMoovSeq=%d, iHasVideo=%d\n" , pMp4Data->isMdatMoovSeq , pMp4Data->iHasVideo ));
	mmp4_printf(( "    iHasMP4P2Video=%d , iMP4VidProf=%d\n" , pMp4Data->iHasMP4P2Video , pMp4Data->iMP4VidProf ));
	mmp4_printf(( "    iH263Type=%d , iH263Profile=%d , iH263Level=%d\n" , pMp4Data->iH263Type, pMp4Data->iH263Profile , pMp4Data->iH263Level ));
	mmp4_printf(( "    iAVCFile=%d , iAVCProfile=%d , iAVCLevel=%d\n" , pMp4Data->iAVCFile, pMp4Data->iAVCProfile , pMp4Data->iAVCLevel ));
	mmp4_printf(( "    iHasAudio=%d , iHasAmrAudio=%d , aud_profile=%d\n" , pMp4Data->iHasAudio , pMp4Data->iHasAmrAudio , pMp4Data->aud_profile ));
	mmp4_printf(( "    audobjtype=%d , vid_simpObj=%d\n" , pMp4Data->audobjtype , pMp4Data->vid_simpObj ));
	mmp4_printf(( "    iHas3gpp=%d , ftype_major=[%c%c%c%c]\n"
			, pMp4Data->iHas3gpp
			, pMp4Data->ftyp_major[0] , pMp4Data->ftyp_major[1] , pMp4Data->ftyp_major[2] , pMp4Data->ftyp_major[3]
			));
	mmp4_printf(( "    iVidStreamSz=%d , iAudStreamSz=%d\n" , (int)pMp4Data->iVidStreamSz , (int)pMp4Data->iAudStreamSz ));
	mmp4_printf(( "    iStreamTotal=%d , iStreamType=%d\n" , (int)pMp4Data->iStreamTotal , pMp4Data->iStreamType ));
}

/*! @brief (for debug) */
static void
mmp4_print_mp4info( const mp4info_t* pMp4Info )
{
	mmp4_printf(( "<mp4info_t> [%s]\n" , pMp4Info->minfo->file.full_path ));
	mmp4_print_mp4_specific_infomation( pMp4Info );
	if( pMp4Info->mp4->iHasVideo ){
		mmp4_print_video_strema_information( pMp4Info );
	}
	mmp4_print_audio_strema_information( pMp4Info );
}

#else
#ifndef DEVELOPMENT_NFLC_PROFILER
static void
mmp4_print_mp4info( const mp4info_t* pMp4Info )
{}
#endif /* !DEVELOPMENT_NFLC_PROFILER */
#endif

/* -------------------------------------------------------------------------------- */
#endif /* info_mp4_mobile_debug_h_200912070949 */
/* -------------------------------------------------------------------------------- */




