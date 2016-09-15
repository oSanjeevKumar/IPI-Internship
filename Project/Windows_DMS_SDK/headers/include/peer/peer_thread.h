#ifndef PEER_THREAD_H
#define PEER_THREAD_H

typedef struct thread_info_win_ {
	DWORD id;
	HANDLE handle;
	dlna_thread_proc thread_proc;
	void *thread_proc_param;
} thread_info;

HANDLE get_current_thread();

#endif /* PEER_THREAD_H */
