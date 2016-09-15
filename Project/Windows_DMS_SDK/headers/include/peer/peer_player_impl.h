#ifndef PEER_PLAYER_IMPL_H
#define PEER_PLAYER_IMPL_H

#include "dlna_peer.h"

typedef struct _allowed_play_speed allowed_play_speed;

struct _allowed_play_speed
{
	slim_int in_buf_len;
	peer_play_speed_t *out_ps_buf;
	slim_int allow_speed;
};

#ifdef __cplusplus
extern "C" {
	bool PlayerEndOfMedia();

	bool PlayerImplOpen(slim_char *in_uri, slim_char *in_title);
	bool PlayerImplClose(slim_char *in_uri);
	bool PlayerImplPlay(slim_char *in_uri);
	bool PlayerImplStop();
	bool PlayerImplPause();
	bool PlayerImplFastForward();
	bool PlayerImplFastRewind();
	bool PlayerImplGetAllowedPlaySpeed(allowed_play_speed *p_ret);

	bool PlayerImplGetVolume(slim_int *p_ret);
	bool PlayerImplSetVolume(slim_int *p_ent);
	bool PlayerImplGetMuteState(dlna_volume_mute_state *p_ret);
	bool PlayerImplSetMuteState(dlna_volume_mute_state *p_ent);

	bool PlayerImplSeekTime(dlna_off_t *p_ent);
	bool PlayerImplGetDuration(slim_word *p_ret);
	bool PlayerImplGetTimePos(slim_word *p_ret);
};
#endif /* __cplusplus */

#endif /* PEER_PLAYER_IMPL_H */
