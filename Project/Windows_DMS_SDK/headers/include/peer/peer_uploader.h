#ifndef PEER_UPLOADER_H
#define PEER_UPLOADER_H

typedef struct _peer_uploader peer_uploader;
typedef struct _peer_uploader_stream peer_uploader_stream;

typedef slim_int(*peer_uploader_read_func)(
	peer_uploader_stream *in_upstream,
	slim_byte *in_buf,
	dlna_size_t in_length);

struct _peer_uploader
{
	dlna_progress progress;
	dlna_uploader_callback callback;
	void *arg;
};

struct _peer_uploader_stream
{
	peer_uploader *uploader;
	slim_int flags;
	FILE *src;
	peer_uploader_read_func read_func;
	dlna_progress_handle events[DLNA_UPLOADER_EVENT_MAX];
};

#endif /* PEER_UPLOADER_H */
