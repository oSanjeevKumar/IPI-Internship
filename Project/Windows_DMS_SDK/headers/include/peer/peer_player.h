#ifndef PEER_PLAYER_H
#define PEER_PLAYER_H

#define MAX_SINK_PATH_LEN			(1024)
#define DLNA_VOLUME_CONTROL_HANDLE	(3)
// range of volume db - the range is determined in upnp av-v3 as 2 bytes
#define DLNA_VOLUME_DB_RANGE_MIN	(0x8001) // -32767
#define DLNA_VOLUME_DB_RANGE_MAX	(0x7FFF) // 32767
#define DLNA_VOLUME_RANGE_MIN		(0)
#define DLNA_VOLUME_RANGE_MAX		(100)

typedef struct _peer_player peer_player;
typedef struct _peer_player_stream peer_player_stream;
typedef struct _player_data player_data;

struct _peer_player
{
	dlna_progress progress;
	dlna_player_display_param display;
	dlna_player_callback callback;
	void *arg;
};

struct _peer_player_stream
{
	player_data *data;
	slim_char *uri;
	slim_char *mime_type;
	slim_char *pinfo;
	slim_char *title;
	slim_word flags;
	dlna_player_event event;
	dlna_progress_handle events[DLNA_PLAYER_EVENT_MAX];
};

struct _player_data
{
	peer_player player;
	peer_player_stream *stream;
};

#endif /* PEER_PLAYER_H */
