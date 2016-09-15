/*
 * peer_player.c
 * Copyright (C) 2007-2009 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* DLNA peer player for WMP APIs.  */

#include <dlna_peer.h>

#ifdef DLNA_SUPPORT_RUIPL
# define MAX_PATH_LEN	(1024)
# include <dlna_memory.h>
# include <nflc_sxml.h>
#endif /* DLNA_SUPPORT_RUIPL */

#if defined(HAVE_DMR) || (defined(HAVE_DMC) && !defined(DLNA_NOT_SUPPORT_PLAYER_API))
#include <nflc_sxml.h>
#include <dlna_memory.h>
#include "peer_player_impl.h"
#include "peer_player.h"

player_data *__data__ = slim_nil;
peer_player_stream *__stream__ = slim_nil;

static dlna_player_channel supported_channels[] = {	DLNA_CHANNEL_MASTER };

slim_int volume_to_dB(slim_int vol)
{
	return
		((slim_int)(signed short)DLNA_VOLUME_DB_RANGE_MAX - (slim_int)(signed short)DLNA_VOLUME_DB_RANGE_MIN) *
		(vol - DLNA_VOLUME_RANGE_MIN) /	(DLNA_VOLUME_RANGE_MAX - DLNA_VOLUME_RANGE_MIN) + (slim_int)(signed short)DLNA_VOLUME_DB_RANGE_MIN;
}

slim_int dB_to_volume(slim_int dBvol)
{
	return
		(DLNA_VOLUME_RANGE_MAX - DLNA_VOLUME_RANGE_MIN) * (dBvol - (slim_int)(signed short)DLNA_VOLUME_DB_RANGE_MIN) /
		((slim_int)(signed short)DLNA_VOLUME_DB_RANGE_MAX - (slim_int)(signed short)DLNA_VOLUME_DB_RANGE_MIN) + DLNA_VOLUME_RANGE_MIN;
}

slim_bool is_channel_supported(dlna_player_channel channel)
{
	int i;
	for (i = 0; i < sizeof(supported_channels)/sizeof(dlna_player_channel); i ++)
		if(supported_channels[i] == channel)
			return 1;
	return 0;
}

slim_int player_event_callback(void *in_arg)
{
	peer_player_stream *stream = (peer_player_stream *)in_arg;
	player_data *data = 0;
	dlna_player_param param;
	slim_int ret;
	if (!stream) return SLIM_E_GENERIC;
	data = (player_data *)stream->data;
	if (!data) return SLIM_E_GENERIC;
	dlnaProgressLockPeer(data->player.progress);
	stream->events[stream->event] = DLNA_INVALID_PROGRESS_HANDLE;
	dlna_memset(&param, 0, sizeof(dlna_player_param));
	param.stream = (dlna_player_stream)stream;
	param.path = stream->uri;
	ret = data->player.callback(stream->event, data->player.arg, &param);
	dlnaProgressUnlockPeer(data->player.progress);
	return ret;
}

slim_int peer_player_event_add(peer_player_stream *stream, dlna_player_event e)
{
	player_data *data = 0;
	if (!stream) return SLIM_E_GENERIC;
	data = (player_data *)stream->data;
	if (!data) return SLIM_E_GENERIC;
	dlnaProgressLockPeer(data->player.progress);
	stream->event = e;
	if (stream->events[stream->event] != DLNA_INVALID_PROGRESS_HANDLE) {
		dlnaProgressUnlockPeer(data->player.progress);
		return SLIM_E_GENERIC;
	}
	EVENT_ADD_EVENT(stream->events[stream->event], data->player.progress, (dlna_progress_callback)player_event_callback, stream);
	dlnaProgressUnlockPeer(data->player.progress);
	return SLIM_E_OK;
}

dlna_player dlnaPlayerAllocPeer(dlna_progress in_p, dlna_player_display_param *in_param,
								dlna_player_callback in_callback, void *in_arg)
{
	player_data *data = (player_data *)dlna_memory_zeroalloc(sizeof(player_data));
	if (!data) return slim_nil;
	data->player.progress = in_p;
	if (in_param) {
		data->player.display = *in_param;
	} else {
		data->player.display.xpos = 0;
		data->player.display.ypos = 0;
		data->player.display.width = 640;
		data->player.display.height = 480;
	}
	data->player.callback = in_callback;
	data->player.arg = in_arg;
	__data__ = data;
	return (dlna_player)data;
}

slim_int dlnaPlayerDisplayResizePeer(dlna_player in_player, dlna_player_display_param *in_param)
{
	return SLIM_E_GENERIC;
}

slim_int dlnaPlayerFreePeer(dlna_player in_player)
{
	player_data *data = (player_data *)in_player;
	if (!data) return SLIM_E_GENERIC;
	if (data->stream) {
		dlna_memory_free(data->stream->uri);
		dlna_memory_free(data->stream->mime_type);
		dlna_memory_free(data->stream->pinfo);
		dlna_memory_free(data->stream->title);
	}
	dlna_memory_free(data->stream);
	dlna_memory_free(data);
	__data__ = slim_nil;
	return SLIM_E_OK;
}

dlna_player_stream dlnaPlayerOpenPeer(dlna_player in_player, slim_char *in_uri,
									  slim_char *in_mime_type, slim_char *in_pinfo,
									  slim_char *in_title, slim_word in_flags,
									  slim_word *out_flags, void *in_arg)
{
	player_data *data = (player_data *)in_player;
	peer_player_stream *stream = 0;
	if (!in_uri || !in_pinfo || !data) return slim_nil;	
	if (!PlayerImplOpen(in_uri, in_title)) return slim_nil;
	stream = (peer_player_stream *)dlna_memory_zeroalloc(sizeof(peer_player_stream));
	if (!stream) return slim_nil;
	stream->data = data;
	stream->flags = in_flags | DLNA_PLAYER_FLAG_STREAM;
	data->stream = stream;
	if (in_uri) stream->uri = dlna_strdup(in_uri);
	if (in_mime_type) stream->mime_type = dlna_strdup(in_mime_type);
	if (in_pinfo) stream->pinfo = dlna_strdup(in_pinfo);
	if (in_title) stream->title = dlna_strdup(in_title);
	if (peer_player_event_add(stream, DLNA_PLAYER_OPEN) != SLIM_E_OK) {
		dlna_memory_free(stream->title);
		dlna_memory_free(stream->pinfo);
		dlna_memory_free(stream->mime_type);
		dlna_memory_free(stream->uri);
		dlna_memory_free(stream);
		return slim_nil;
	}
	*out_flags = stream->flags;
	__stream__ = stream;
	return stream;
}

slim_int dlnaPlayerClosePeer(dlna_player_stream in_stream)
{
	peer_player_stream *stream = (peer_player_stream *)in_stream;
	player_data *data = 0;
	int i;
	if (!stream) return SLIM_E_GENERIC;
	data = (player_data *)stream->data;
	if (!data) return slim_nil;
	if (!PlayerImplClose(stream->uri)) return SLIM_E_GENERIC;
	if (peer_player_event_add(stream, DLNA_PLAYER_CLOSE) != SLIM_E_OK) return SLIM_E_GENERIC;
	for (i = 0; i < DLNA_PLAYER_EVENT_MAX; i ++) {
		dlnaProgressLockPeer(data->player.progress);
		EVENT_CANCEL(stream->events[i], data->player.progress);
		dlnaProgressUnlockPeer(data->player.progress);
	}
	dlna_memory_free(data->stream->uri);
	dlna_memory_free(data->stream->mime_type);
	dlna_memory_free(data->stream->pinfo);
	dlna_memory_free(data->stream->title);
	dlna_memory_free(data->stream);
	data->stream = 0;
	__stream__ = slim_nil;
	return SLIM_E_OK;
}

slim_int dlnaPlayerPlayPeer(dlna_player_stream in_stream)
{
	peer_player_stream *stream = (peer_player_stream *)in_stream;
	if (!stream) return SLIM_E_GENERIC;
	if (!PlayerImplPlay(stream->uri)) return SLIM_E_GENERIC;
	if (peer_player_event_add(stream, DLNA_PLAYER_PLAY) != SLIM_E_OK) return SLIM_E_GENERIC;
	return SLIM_E_OK;
}

slim_int dlnaPlayerPausePeer(dlna_player_stream in_stream)
{
	if (!PlayerImplPause()) return SLIM_E_GENERIC;
	if (peer_player_event_add((peer_player_stream *)in_stream, DLNA_PLAYER_PAUSE) != SLIM_E_OK) return SLIM_E_GENERIC;
	return SLIM_E_OK;
}

slim_int dlnaPlayerPauseByPeer(dlna_player_stream in_stream, dlna_player_trickmode in_mode)
{
	dlnaPlayerPausePeer(in_stream);
	return SLIM_E_OK;
}


slim_int dlnaPlayerStopPeer(dlna_player_stream in_stream)
{
	if (!PlayerImplStop()) return SLIM_E_GENERIC;
	if (peer_player_event_add((peer_player_stream *)in_stream, DLNA_PLAYER_STOP) != SLIM_E_OK) return SLIM_E_GENERIC;
	return SLIM_E_OK;
}

slim_int
dlnaPlayerOpenNextPeer(dlna_player in_player,
slim_char *in_uri,
slim_char *in_mime_type,
slim_char *in_pinfo,
slim_char *in_title,
slim_word in_flags)
{
	/* Dummy implementation, no prefetch for now */

	PARAMETER_NOT_USED(in_player);
	PARAMETER_NOT_USED(in_uri);
	PARAMETER_NOT_USED(in_mime_type);
	PARAMETER_NOT_USED(in_pinfo);
	PARAMETER_NOT_USED(in_title);
	PARAMETER_NOT_USED(in_flags);

	return SLIM_E_OK;
}

#ifdef USE_TRICK_PLAY

slim_int dlnaPlayerFastForwardPeer(dlna_player_stream in_stream, slim_int in_speed)
{
	if (!PlayerImplFastForward()) return SLIM_E_GENERIC;
	if (peer_player_event_add((peer_player_stream *)in_stream, DLNA_PLAYER_FF) != SLIM_E_OK) return SLIM_E_GENERIC;
	return SLIM_E_OK;
}

slim_int dlnaPlayerSlowForwardPeer(dlna_player_stream in_stream, slim_int in_speed)
{
	return SLIM_E_GENERIC;
}

slim_int dlnaPlayerFastRewindPeer(dlna_player_stream in_stream, slim_int in_speed)
{
	if (!PlayerImplFastRewind()) return SLIM_E_GENERIC;
	if (peer_player_event_add((peer_player_stream *)in_stream, DLNA_PLAYER_FR) != SLIM_E_OK) return SLIM_E_GENERIC;
	return SLIM_E_OK;
}

slim_int dlnaPlayerSlowRewindPeer(dlna_player_stream in_stream, slim_int in_speed)
{
	return SLIM_E_GENERIC;
}

#endif /* USE_TRICK_PLAY */

slim_int dlnaPlayerSeekTrackPeer(dlna_player_stream in_stream, dlna_off_t in_offset)
{
	return SLIM_E_NOTSUPPORTED;
}

slim_int dlnaPlayerSeekBytesPeer(dlna_player_stream in_stream, dlna_uint64 in_offset)
{
	return SLIM_E_NOTSUPPORTED;
}

slim_int dlnaPlayerSeekTimePeer(dlna_player_stream in_stream, dlna_off_t in_sec)
{
	if (!PlayerImplSeekTime(&in_sec)) return SLIM_E_GENERIC;
	return SLIM_E_OK;
}

slim_int dlnaPlayerWritePeer(dlna_player_stream in_stream,
							 slim_byte *in_buf, dlna_size_t in_length)
{
	return SLIM_E_GENERIC;
}

slim_int dlnaPlayerReadPeer(dlna_player_stream in_stream,
							slim_byte *in_buf, dlna_size_t in_length)
{
	return SLIM_E_GENERIC;
}

#if defined (HAVE_DTCP) && defined (DLNA_SUPPORT_UPLOADER)

slim_bool dlnaPlayerCheckCCIPeer(slim_int *in_cci)
{
	return false;
}

#endif /* HAVE_DTCP && DLNA_SUPPORT_UPLOADER */

slim_int dlnaPlayerSetItemGroupPeer(dlna_player in_player, void *itemgroup)
{
	return SLIM_E_GENERIC;
}

void *dlnaPlayerGetItemGroupPeer(dlna_player in_player)
{
	return slim_nil;
}

//typedef void (*dlna_volume_control_event_callback)(dlna_volume_control_handle in_handle, dlna_volume_control_event in_event, void *in_param);

dlna_player_channel *dlnaPlayerGetSupportedChannelsPeer(dlna_volume_control_handle in_handle, slim_int* out_num)
{
	if (out_num) *out_num = sizeof(supported_channels)/sizeof(dlna_player_channel);
	return supported_channels;
}

dlna_volume_control_handle dlnaPlayerVolumeControlOpenPeer(dlna_progress in_p, dlna_volume_control_event_callback in_callback, void* in_param)
{
	return (dlna_volume_control_handle)DLNA_VOLUME_CONTROL_HANDLE;
}

void dlnaPlayerVolumeControlClosePeer(dlna_volume_control_handle in_handle)
{
}

slim_int dlnaPlayerGetVolumePeer(dlna_volume_control_handle in_handle, dlna_player_channel in_channel)
{
	slim_int vol = 0;
	if (!is_channel_supported(in_channel)) return 0;
	if (!PlayerImplGetVolume(&vol)) return 0;
	return vol;
}

slim_int dlnaPlayerSetVolumePeer(dlna_volume_control_handle in_handle, slim_int in_channel, slim_int in_volume)
{
	if (!is_channel_supported(in_channel)) return SLIM_E_NOTSUPPORTED;
	if (!PlayerImplSetVolume(&in_volume)) return SLIM_E_GENERIC;
	return SLIM_E_OK;
}

dlna_volume_mute_state dlnaPlayerGetMuteStatePeer(dlna_volume_control_handle in_handle, dlna_player_channel in_channel)
{
	dlna_volume_mute_state mute_state = MUTE_STATE_ERROR;
	if (!is_channel_supported(in_channel)) return MUTE_STATE_ERROR;
	if (!PlayerImplGetMuteState(&mute_state)) return MUTE_STATE_ERROR;
	return mute_state;
}

slim_int dlnaPlayerSetMuteStatePeer(dlna_volume_control_handle in_handle, dlna_player_channel in_channel, dlna_volume_mute_state in_mute)
{
	if (!is_channel_supported(in_channel)) return SLIM_E_NOTSUPPORTED;
	if (!PlayerImplSetMuteState(&in_mute)) return SLIM_E_GENERIC;
	return SLIM_E_OK;
}

slim_int dlnaPlayerGetVolumeDBPeer(dlna_volume_control_handle in_handle, dlna_player_channel in_channel, slim_int *out_volume_db)
{
	slim_int vol = 0;
	if (!is_channel_supported(in_channel)) return SLIM_E_NOTSUPPORTED;
	if (!PlayerImplGetVolume(&vol)) return SLIM_E_GENERIC;
	*out_volume_db = volume_to_dB(vol);
	return SLIM_E_OK;
}

slim_int dlnaPlayerSetVolumeDBPeer(dlna_volume_control_handle in_handle, dlna_player_channel in_channel, slim_int in_volume_db)
{
	slim_int vol = dB_to_volume(in_volume_db);
	if (!is_channel_supported(in_channel)) return SLIM_E_NOTSUPPORTED;
	if (!PlayerImplSetVolume(&vol)) return SLIM_E_GENERIC;
	return SLIM_E_OK;
}

slim_int dlnaPlayerGetVolumeDBRangePeer(dlna_volume_control_handle in_handle, dlna_player_channel in_channel, slim_int *out_min_vol_db, slim_int *out_max_vol_db)
{
	*out_min_vol_db = (slim_int)(signed short)DLNA_VOLUME_DB_RANGE_MIN;
	*out_max_vol_db = (slim_int)(signed short)DLNA_VOLUME_DB_RANGE_MAX;
	return SLIM_E_OK;
}

#if defined (HAVE_DTCP) && defined (DLNA_SUPPORT_UPLOADER)

slim_bool dlnaPlayerCheckEMIPeer(slim_int *in_emi)
{
	return false;
}

#endif /* HAVE_DTCP && DLNA_SUPPORT_UPLOADER */

slim_int dlnaPlayerGetDurationPeer(dlna_player_stream *in_stream, slim_word *out_duration)
{
	if (!PlayerImplGetDuration(out_duration)) return SLIM_E_NOTSUPPORTED;
	return SLIM_E_OK;
}

slim_int dlnaPlayerGetTimePosPeer(dlna_player_stream *in_stream, slim_word *out_timepos)
{
	if (!PlayerImplGetTimePos(out_timepos)) return SLIM_E_GENERIC;
	return SLIM_E_OK;
}

slim_int dlnaPlayerGetCounterPosPeer(dlna_player_stream *in_stream, dlna_uint64 *out_counterpos)
{
	return SLIM_E_NOTSUPPORTED;
}

slim_int dlnaPlayerGetCounterSizePeer(dlna_player_stream *in_stream, dlna_uint64 *out_size)
{
	return SLIM_E_NOTSUPPORTED;
}

slim_int dlnaPlayerGetSeekCapabilityPeer(dlna_player_stream *in_stream, slim_word *out_seek_capability_flag)
{
	if (!out_seek_capability_flag) return SLIM_E_GENERIC;
	*out_seek_capability_flag = PEER_DLNA_PLAYER_SUPPORT_TIME_SEEK;
	return SLIM_E_OK;
}

slim_int dlnaPlayerGetAllowedPlaySpeedPeer(dlna_player_stream in_stream, peer_play_speed_t *out_ps_buf, slim_int in_buf_len)
{
	peer_player_stream *stream = (peer_player_stream *)in_stream;
	player_data *data = 0;
	allowed_play_speed aps;
	if (!stream) return SLIM_E_GENERIC;
	data = (player_data *)stream->data;
	if (!data) return slim_nil;
	aps.in_buf_len = in_buf_len;
	aps.out_ps_buf = out_ps_buf;
	aps.allow_speed = 0;
	if (!PlayerImplGetAllowedPlaySpeed(&aps)) return SLIM_E_GENERIC;
	if (aps.allow_speed == 0) return SLIM_E_GENERIC;
	return aps.allow_speed;
}

slim_char *dlnaDMRSinkProtocolInfoPeer(slim_char *in_protocol_info_path)
{
	dlna_size_t ret;
	dlna_file_t desc;
	dlna_size_t file_size;
	slim_char path[MAX_SINK_PATH_LEN];
	slim_char *buf;
	dlna_stat st;
	sXML *doc;
	sXML *sink = slim_nil;
	sXML_Node *pinfo_list = slim_nil;
	sXML_Element *pinfo_element = slim_nil;
	slim_char *pinfo_val;
	slim_int i;

	if (!in_protocol_info_path) {
		DLNA_LOG(DLNA_LOG_PEER_PLAYER, DLNA_LOG_LEVEL_ERROR, "dlnaDMRSinkProtocolInfoPeer->null_pointer.");
		return slim_nil;
	}

	DLNA_LOG(DLNA_LOG_PEER_PLAYER, DLNA_LOG_LEVEL_ERROR,"[dlnaDMRSinkProtocolInfoPeer]: PROCESSING!!!");

	dlna_snprintf(path, MAX_SINK_PATH_LEN, SLIM_T("%s%c%s"), in_protocol_info_path, PATH_SEPARATOR_CHAR, DLNA_SINK_PROTOCOL_INFO_XML);

	// get file size
	ret = dlnaFileSystemStatPeer(path, &st);
	if (ret != 0) {
		DLNA_LOG(DLNA_LOG_PEER_PLAYER, DLNA_LOG_LEVEL_ERROR, "[dlnaDMRSinkProtocolInfo] Cannot stat file %s", path);
		return slim_nil;
	}
	if (st.size.high != 0) {
		DLNA_LOG(DLNA_LOG_PEER_PLAYER, DLNA_LOG_LEVEL_ERROR, "dlnaDMRSinkProtocolInfoPeer->wrong_value.");
		return slim_nil;
	}
	file_size = st.size.low;

	// open the file
	desc = dlnaFileOpenPeer(path, DLNA_STREAM_READ);
	if (desc == DLNA_INVALID_FILE_HANDLE) {
		DLNA_LOG(DLNA_LOG_PEER_PLAYER, DLNA_LOG_LEVEL_ERROR, "[dlnaDMRSinkProtocolInfo] Cannot open file %s", path);
		return slim_nil;
	}

	// allocate buffer for file, file size plus one
	buf = (slim_char *)XCALLOC (MTYPE_TMP, file_size + 1);
	if (!buf) return slim_nil;

	// read entire file
	ret = dlnaFileReadPeer(desc, buf, file_size);
	if (ret < 0 || ret != file_size) {
		DLNA_LOG(DLNA_LOG_PEER_PLAYER, DLNA_LOG_LEVEL_ERROR, "[dlnaDMRSinkProtocolInfo] Cannot read file %s", path);
		XFREE(MTYPE_TMP, buf);
		dlnaFileClosePeer(desc);
		return slim_nil;
	}
	buf[file_size] = '\0'; // NULL terminate

	dlnaFileClosePeer(desc);

	// parse device file
	ret = sXML_ParseStr(buf, &doc);
	if (SXML_SUCCESS == ret) {
		buf[0] = '\0';
		sink = sXML_getFirstElementByTagName(doc, SLIM_T("SinkProtocolInfo"));
		if (sink) {
			if ((sXML_getElementsByTagName(doc, SLIM_T("protocolInfo"), &pinfo_list) == 0)) {
				for (i = 0; i < sXML_NodeLength(pinfo_list); i ++) {
					pinfo_element = (sXML_Element *)sXML_NodeItem(pinfo_list, i);
					if (!pinfo_element)
						continue;
					pinfo_val = sXML_Value(pinfo_element);
					if (pinfo_val) {
						dlna_strcat(buf, pinfo_val);
						dlna_strcat(buf, SLIM_T(","));
					} else {
						DLNA_LOG(DLNA_LOG_PEER_PLAYER, DLNA_LOG_LEVEL_ERROR, "[dlnaDMRSinkProtocolInfo] No XML Value for element %d", i);
					}
				}
			} else {
				XFREE(MTYPE_TMP, buf);
				buf = slim_nil;
			}
		} else {
			XFREE(MTYPE_TMP, buf);
			buf = slim_nil;
		}
		if(pinfo_list)
			sXML_NodeFree(pinfo_list);
		sXML_Unlock(doc);
	} else {
		XFREE(MTYPE_TMP, buf);
		buf = slim_nil;
	}
	return buf;
}

slim_bool PlayerEndOfMedia()
{
	return peer_player_event_add(__stream__, DLNA_PLAYER_END_OF_MEDIA) != SLIM_E_OK;
}

#endif /* defined(HAVE_DMR) || (defined(HAVE_DMC) && !defined(DLNA_NOT_SUPPORT_PLAYER_API)) */

#ifdef DLNA_SUPPORT_RUIPL

slim_char *dlnaRUIClientCapabilityPeer(slim_char *in_path)
{
	dlna_size_t ret;
	dlna_file_t desc;
	dlna_size_t file_size;
	slim_char path[MAX_PATH_LEN];
	slim_char *buf;
	dlna_stat st;
	slim_char *p, *px;
	struct _sXML *doc;

	dlna_snprintf(path, MAX_PATH_LEN, SLIM_T("%s%s"), in_path, RUI_CLIENT_CAPABILITY_XML);

	/* Get file size. */
	ret = dlnaFileSystemStatPeer (path, &st);
	if (ret != 0) {
		DLNA_LOG(DLNA_LOG_PEER_PLAYER, DLNA_LOG_LEVEL_ERROR, "[dlnaRUIClientCapabilityPeer] Cannot stat file %s", path);
		return slim_nil;
	}
	if(st.size.high != 0) {
		DLNA_LOG(DLNA_LOG_PEER_PLAYER, DLNA_LOG_LEVEL_ERROR, "ERROR: dlnaRUIClientCapabilityPeer->wrong_value.");
		return slim_nil;
	}
	file_size = st.size.low;

	/* Open the file. */
	desc = dlnaFileOpenPeer (path, DLNA_STREAM_READ);
	if (desc == DLNA_INVALID_FILE_HANDLE) {
		DLNA_LOG(DLNA_LOG_PEER_PLAYER, DLNA_LOG_LEVEL_ERROR, "[dlnaRUIClientCapabilityPeer] Cannot open file %s", path);
		return slim_nil;
	}

	/* Allocate buffer for file, file size plus one.  */
	buf = (slim_char *) XCALLOC (MTYPE_TMP, file_size + 1);
	if (! buf) {
		dlnaFileClosePeer (desc);
		return slim_nil;
	}
	/* Read entire file.  */
	ret = dlnaFileReadPeer (desc, buf, file_size);
	if (ret < 0 || ret != file_size) {
		DLNA_LOG(DLNA_LOG_PEER_PLAYER, DLNA_LOG_LEVEL_ERROR, "[dlnaRUIClientCapabilityPeer] Cannot read file %s", path);
		XFREE(MTYPE_TMP, buf);
		dlnaFileClosePeer (desc);
		return slim_nil;
	}

	/* NULL terminate. */
	buf[file_size] = '\0';

	/* Close the file.  */
	dlnaFileClosePeer (desc);
	/* Parse description file.  */
	ret = sXML_ParseStr (buf, &doc);
	if(SXML_SUCCESS == ret) {
		XFREE(MTYPE_TMP, buf);		
		buf = sXML_PrintDocument (doc);
		sXML_Unlock(doc) ;
		// the profile string is used within the user-agent, so we have to remove all 0x0a
		// that are generated by the sXML_PrintDocument()
		p = px = buf ;
		while(*px){
			if( *px != 0x0a ){
				*p = *px ;
				p++ ;
			}
			px++ ;
		}
		*p = 0;
		return buf ; 
	}

	DLNA_LOG(DLNA_LOG_PEER_PLAYER, DLNA_LOG_LEVEL_ERROR, "[dlnaRUIClientCapabilityPeer] parse error");

	XFREE(MTYPE_TMP, buf);		

	return slim_nil ;
}
#endif /* DLNA_SUPPORT_RUIPL */
