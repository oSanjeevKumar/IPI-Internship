#ifndef PEER_PROGRESS_H
#define PEER_PROGRESS_H

/* Linked list of event. */
struct event_list
{
  struct event *head;
  struct event *tail;
  slim_word count;
};

/* Event structure. */
struct event
{
  /* Linked list. */
  struct event *next;
  struct event *prev;

  /* Pointer to the event manager. */
  struct event_manager *manager;

  /* Event function. */
  union
  {
    int (*func) (void *in_arg);
    int (*func_io) (slim_int in_desc, void *in_arg);
  } f;

  /* Event argument. */
  void *arg;

  /* Event type. */
  char otype;
  char type;

  /* Event timer index. */
  char timer_index;

  /* Arguments. */
  union 
  {
    /* File descriptor in case of read/write. */
    slim_int sock;

    /* Rest of time sands value. */
    struct timeval sands;
  } u;
};

/* Event manager structure. */
struct event_manager
{
  /* Flags. */
  slim_word flags;
#define EVENT_FLAG_LOOP		(1 << 0)
#define EVENT_FLAG_INTRACOM	(1 << 1)

  /* Event lists. */
  struct event_list event;
  struct event_list read;
  struct event_list write;
  struct event_list ready;
  struct event_list unuse;
#define EVENT_TIMER_SLOT           4
  int timer_index;
  struct event_list timer[EVENT_TIMER_SLOT];

  /* FD sets for select system call. */
  fd_set readfd;
  fd_set writefd;
  fd_set exceptfd;
  int max_sock;

  /* Special sockets to facilitate intra-process communication in
     windows. */
  int sock_read;
  int sock_write;

  void (*loop) (struct event_manager *em);
  int (*init) (struct event_manager *em);
  void (*stop) (struct event_manager *em);

  /* Threads.  */
  struct cp_thread *t_loop;

  /* Synchronization objects */
  LPCRITICAL_SECTION pzCS;

  /* Synchronization objects for only event manager */
  LPCRITICAL_SECTION pzCS_em;

#ifdef HAVE_PTHREAD
  /* Event manager thread. */
  dlna_thread self;

  /* Current thread holding the recursive lock. */
  dlna_thread lock_thread;

  /* Mutex for the recursive lock. */
  dlna_mutex mutex;

  /* Condition variable for the recursive lock. */
  dlna_conditional_variable unlock_cv;

  /* Recursive lock counter. */
  slim_int lock_counter;

  /* Recursive mutex for event list. */
  dlna_recursive_mutex pmtx_evt_list;
#endif /* HAVE_PTHREAD */
};

/* Typedef for event callback fucntion. */
typedef int (*EVENT_CALLBACK) (void *in_arg);
typedef int (*EVENT_IO_CALLBACK) (int in_val, void *in_arg);

/* Event types. */
#define EVENT_TYPE_READ		0
#define EVENT_TYPE_WRITE	1
#define EVENT_TYPE_TIMER	2
#define EVENT_TYPE_EVENT	3
#define EVENT_TYPE_READY	4
#define EVENT_TYPE_UNUSED	5

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* Prototypes. */
struct event_manager *
event_manager_alloc (void); 

void
event_manager_free (struct event_manager *em);

void
event_list_free (struct event_list *list);

struct event *
event_add_event (struct event_manager *em,
		 EVENT_CALLBACK func, void *arg);

struct event *
event_add_read (struct event_manager *em,
		EVENT_IO_CALLBACK func, void *arg, int fd);

struct event *
event_add_write (struct event_manager *em,
		 EVENT_IO_CALLBACK func, void *arg, int fd);

struct event *
event_add_timer (struct event_manager *em,
		 EVENT_CALLBACK func, void *arg, dlna_timeval *timer);

void
event_cancel (struct event *e);

void
event_recursive_lock (struct event_manager *em);

void
event_recursive_unlock (struct event_manager *em);

int
event_loop_init (struct event_manager *em);

void
event_loop_start (struct event_manager *em);

void
event_loop_stop (struct event_manager *em);

void
event_remove_events_with_specific_arg_or_callback(struct event_manager *em, enum dlna_event_remove_mode remove_mode, void* arg, void* callback);

/* Recursive mutex. */
struct recursive_mutex *
recursive_mutex_alloc ();

void
recursive_mutex_free (struct recursive_mutex *pmtx);

void
recursive_mutex_lock (struct recursive_mutex *pmtx);

void
recursive_mutex_unlock (struct recursive_mutex *pmtx);

#ifdef __cplusplus
}
#endif	/* __cplusplus */

#endif /* PEER_PROGRESS_H */
