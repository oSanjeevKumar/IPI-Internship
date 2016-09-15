/*
 * progress_event.c
 * Copyright (C) 2007-2009 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2005 IP Infusion, Inc. All Rights Reserved.  */

/* Generic event manager using select() system call.  */

#include <dlna_peer.h>
#include "cp_thread.h"
#include "progress_event.h"

/* 1 second = TIMER_SECOND_MICRO micro seconds.  */
static const long TIMER_SECOND_MICRO = 1000000L;

static int
gettimeofday(struct timeval *tv, struct timezone *tz)
{
  long t_ms;
  
  /* Get the time in milli-seconds since PC starting time.  */
#if (_WIN32_WINNT >= 0x0603 /*_WIN32_WINNT_WIN8*/)
  t_ms = (slim_int)GetTickCount64();
#else
  t_ms = GetTickCount();
#endif
 
  tv->tv_sec = t_ms/1000;
  tv->tv_usec = (t_ms % 1000) * 1000;
        
  return 0;
}

/* Time value compare utility function.  */
static int
timeval_cmp (struct timeval a, struct timeval b)
{
	return
		a.tv_sec == b.tv_sec ?
		a.tv_usec - b.tv_usec :
		a.tv_sec - b.tv_sec;
}

/* Time adjust utility function.  */
static struct timeval
timeval_adjust (struct timeval a)
{
  while (a.tv_usec >= TIMER_SECOND_MICRO) {
    a.tv_usec -= TIMER_SECOND_MICRO;
    a.tv_sec++;
  }

  while (a.tv_usec < 0) {
    a.tv_usec += TIMER_SECOND_MICRO;
    a.tv_sec--;
  }

  if (a.tv_sec < 0) {
    a.tv_sec = 0;
    a.tv_usec = 10;
  }

  if (a.tv_sec > TIMER_SECOND_MICRO) {
    a.tv_sec = TIMER_SECOND_MICRO;
  }

  return a;
}

/* Time value subtract utility function.  */
static struct timeval
timeval_subtract (struct timeval a, struct timeval b)
{
  struct timeval ret;

  ret.tv_usec = a.tv_usec - b.tv_usec;
  ret.tv_sec = a.tv_sec - b.tv_sec;

  return timeval_adjust (ret);
}

void
event_signal_wakeloop (struct event_manager *em)
{
  if ( em->t_loop ) {
    int nThreadID = GetCurrentThreadId();
  // Do not wake up myself
    if ( nThreadID == em->t_loop->id ) {
      return;
    }
  }

  if (CHECK_FLAG (em->flags, EVENT_FLAG_INTRACOM)) {
    char *buf = "wake";
    DLNA_LOG(DLNA_LOG_PEER_EVENT, DLNA_LOG_LEVEL_DEBUG, "event_signal_wakeloop->Wake up thread id:%d. and currentThread:%d", em->t_loop->id, GetCurrentThreadId());
    send (em->sock_write, buf, (int) dlna_strlen (buf), MSG_DONTROUTE);
  }
}

/* Keep track of the maximum file descriptor for read/write. */
static void
event_update_max_sock (struct event_manager *em, slim_int sock)
{
  if(!em){
    DLNA_LOG(DLNA_LOG_PEER_EVENT, DLNA_LOG_LEVEL_ERROR, "event_update_max_sock->null_pointer.");
    return;
  }

  if (em->max_sock < sock) {
    em->max_sock = sock;
  }
}

static void
event_set_sockread (struct event_manager *em, fd_set * pReadFD)
{
  if (CHECK_FLAG (em->flags, EVENT_FLAG_INTRACOM)) {
    FD_SET (em->sock_read, pReadFD);
    event_update_max_sock (em, em->sock_read);
  }
}

static int
event_check_loop (struct event_manager *em, fd_set * pReadFD, int *pNum)
{
  if (CHECK_FLAG (em->flags, EVENT_FLAG_INTRACOM)) {
    char buf[4096];

    int nBytes;

    /* Check to see if our event sockets were triggered.  */
    if (FD_ISSET (em->sock_read, pReadFD)) {
      *pNum = *pNum - 1;
      FD_CLR (em->sock_read, pReadFD);

#ifdef MSG_NOSIGNAL
      nBytes = recv (em->sock_read, buf, sizeof (buf), MSG_NOSIGNAL);
#else
      nBytes = recv (em->sock_read, buf, sizeof (buf), 0);
#endif /* MSG_NOSIGNAL */

      if (nBytes > 0) {
        buf[nBytes] = '\0';
        if (strncmp (buf, "stop", 4) == 0) {
          DLNA_LOG(DLNA_LOG_PEER_EVENT, DLNA_LOG_LEVEL_DEBUG, "event_check_loop exit.");
          /* Tell the caller that we found a stop and they should
           * break out of the event loop.  */
          return 1;
        }
      }
    }
  }
  return 0;
}

/* Add a new event to the list.  */
void
event_list_add (struct event_list *list, struct event *e)
{
  if(!list || !e){
    DLNA_LOG(DLNA_LOG_PEER_EVENT, DLNA_LOG_LEVEL_ERROR, "event_list_add->null_pointer.");
    return;
  }

  e->next = NULL;
  e->prev = list->tail;
  if (list->tail) {
    list->tail->next = e;
  } else {
    list->head = e;
  }
  list->tail = e;
  list->count++;
}

/* Add a new event just after the point. If point is NULL, add to top. */
static void
event_list_add_after (struct event_list *list,
                      struct event *point, struct event *event)
{
  if(!list || !event){
    DLNA_LOG(DLNA_LOG_PEER_EVENT, DLNA_LOG_LEVEL_ERROR, "event_list_add_after->null_pointer.");
    return;
  }

  event->prev = point;
  if (point) {
    if (point->next) {
      point->next->prev = event;
    } else {
      list->tail = event;
    }
    event->next = point->next;
    point->next = event;
  } else {
    if (list->head) {
      list->head->prev = event;
    } else {
      list->tail = event;
    }
    event->next = list->head;
    list->head = event;
  }
  list->count++;
}

/* Delete a event from the list. */
static struct event *
event_list_delete (struct event_list *list, struct event *event)
{
  if(!list || !event){
    DLNA_LOG(DLNA_LOG_PEER_EVENT, DLNA_LOG_LEVEL_ERROR, "event_list_delete->null_pointer.");
    return slim_nil;
  }

  if (event->next) {
    event->next->prev = event->prev;
  } else {
    list->tail = event->prev;
  }
  if (event->prev) {
    event->prev->next = event->next;
  } else {
    list->head = event->next;
  }
  event->next = NULL;
  event->prev = NULL;
  list->count--;

  return event;
}

/* Free all unused event. */
void
event_list_free (struct event_list *list)
{
  struct event *e;
  struct event *next;

  if(!list){
    DLNA_LOG(DLNA_LOG_PEER_EVENT, DLNA_LOG_LEVEL_ERROR, "event_list_free->null_pointer.");
    return;
  }

  for (e = list->head; e != NULL; e = next) {
    next = e->next;
    free (e);
    e = NULL;
    list->count--;
  }
}

/* Return true when the list is empty.  */
int
event_list_empty (struct event_list *list)
{
  if(!list){
    DLNA_LOG(DLNA_LOG_PEER_EVENT, DLNA_LOG_LEVEL_ERROR, "event_list_empty->null_pointer.");
    return -1;
  }

  return list->count == 0;
}

/* Delete top of the list and return it. */
struct event *
event_pop_front (struct event_list *list)
{
  if(!list){
    DLNA_LOG(DLNA_LOG_PEER_EVENT, DLNA_LOG_LEVEL_ERROR, "event_pop_front->null_pointer.");
    return slim_nil;
  }

  return event_list_delete (list, list->head);
}

/* Get new event.  */
struct event *
event_get (struct event_manager *em, char type, EVENT_CALLBACK func,
           void *arg)
{
  struct event *e;

  if (event_list_empty (&em->unuse)) {
    e = malloc (sizeof (struct event));
    if (!e) {
      return NULL;
    }
  } else {
    e = event_pop_front (&em->unuse);
  }
  e->manager = em;
  e->type = type;
  if (type == EVENT_TYPE_READ || type == EVENT_TYPE_WRITE) {
    e->f.func_io = (EVENT_IO_CALLBACK) func;
  } else {
    e->f.func = func;
  }
  e->arg = arg;

  return e;
}

/* Add simple event event. */
struct event *
event_add_event (struct event_manager *em, EVENT_CALLBACK func, void *arg)
{
  struct event *e;

  if(!em){
    DLNA_LOG(DLNA_LOG_PEER_EVENT, DLNA_LOG_LEVEL_ERROR, "event_add_event->null_pointer.");
    return slim_nil;
  }

  e = event_get (em, EVENT_TYPE_EVENT, func, arg);
  if (!e) {
    return NULL;
  }
  event_list_add (&em->event, e);

  /* Wake up the loop.  */
  event_signal_wakeloop (em);

  return e;
}

/* Add new read event. */
struct event *
event_add_read (struct event_manager *em,
                EVENT_IO_CALLBACK func, void *arg, slim_int sock)
{
  struct event *e;

  if(!em){
    DLNA_LOG(DLNA_LOG_PEER_EVENT, DLNA_LOG_LEVEL_ERROR, "event_add_read->null_pointer.");
    return slim_nil;
  }

  if (sock < 0) {
    return NULL;
  }
  e = event_get (em, EVENT_TYPE_READ, (EVENT_CALLBACK) func, arg);
  if (!e) {
    return NULL;
  }
  event_update_max_sock (em, sock);

  FD_SET (sock, &em->readfd);
  e->u.sock = sock;

  event_list_add (&em->read, e);

  /* Wake up the loop.  */
  event_signal_wakeloop (em);

  return e;
}

/* Add new write event. */
struct event *
event_add_write (struct event_manager *em,
                 EVENT_IO_CALLBACK func, void *arg, slim_int sock)
{
  struct event *e;

  if(!em){
    DLNA_LOG(DLNA_LOG_PEER_EVENT, DLNA_LOG_LEVEL_ERROR, "event_add_write->null_pointer.");
    return slim_nil;
  }

  if (sock < 0) {
    return NULL;
  }
  e = event_get (em, EVENT_TYPE_WRITE, (EVENT_CALLBACK) func, arg);
  if (!e) {
    return NULL;
  }
  event_update_max_sock (em, sock);

  FD_SET (sock, &em->writefd);
  e->u.sock = sock;

  event_list_add (&em->write, e);

  /* Wake up the loop.  */
  event_signal_wakeloop (em);

  return e;
}

/* Add timer event. */
struct event *
event_add_timer (struct event_manager *em,
                 EVENT_CALLBACK func, void *arg, dlna_timeval * timer)
{
  struct event *e;
  struct event *pp;

  struct timeval timer_now;

  e = event_get (em, EVENT_TYPE_TIMER, func, arg);
  if (!e) {
    return NULL;
  }
  /* Set timer value.   */
  gettimeofday (&timer_now, NULL);
  timer_now.tv_sec += timer->tv_sec;
  timer_now.tv_usec += timer->tv_usec;
  if (timer_now.tv_usec >= 1000000) {
    timer_now.tv_usec -= 1000000;
    timer_now.tv_sec++;
  }

  e->u.sands = timer_now;

  /* Set timer slot index.  */
  e->timer_index = em->timer_index;

  /* Sort by timeval. */
  for (pp = em->timer[em->timer_index].tail; pp; pp = pp->prev) {
    if (timeval_cmp (e->u.sands, pp->u.sands) >= 0) {
      break;
    }
  }

  event_list_add_after (&em->timer[em->timer_index], pp, e);

  /* Increment timer slot index.  */
  em->timer_index++;
  em->timer_index %= EVENT_TIMER_SLOT;

  /* Wake up the loop.  */
  event_signal_wakeloop (em);

  return e;
}

/* Move event to unuse list. */
static void
event_add_unuse (struct event_manager *em, struct event *e)
{
  if(!em || !e){
    DLNA_LOG(DLNA_LOG_PEER_EVENT, DLNA_LOG_LEVEL_ERROR, "event_add_unuse->null_pointer.");
    return;
  }

  e->type = EVENT_TYPE_UNUSED;
  event_list_add (&em->unuse, e);
}

/* Cancel event from scheduler. */
void
event_cancel (struct event *e)
{
  switch (e->type) {
  case EVENT_TYPE_READ:
    FD_CLR (e->u.sock, &e->manager->readfd);
    event_list_delete (&e->manager->read, e);
    event_add_unuse (e->manager, e);
    break;
  case EVENT_TYPE_WRITE:
    FD_CLR (e->u.sock, &e->manager->writefd);
    event_list_delete (&e->manager->write, e);
    event_add_unuse (e->manager, e);
    break;
  case EVENT_TYPE_TIMER:
    event_list_delete (&e->manager->timer[(int) e->timer_index], e);
    event_add_unuse (e->manager, e);
    break;
  case EVENT_TYPE_EVENT:
    event_list_delete (&e->manager->event, e);
    event_add_unuse (e->manager, e);
    break;
  case EVENT_TYPE_READY:
    event_list_delete (&e->manager->ready, e);
    event_add_unuse (e->manager, e);
    break;
  default:
	  /* do nothing */
    break;
  }
}

/* Delete all events which has argument value arg. */
/*When interface will go down the upnp server stops the SSDP server and all event manager's 
event and sockets needs to be cleaned.*/
void
event_cancel_event (struct event_manager *em, void *arg)
{
  struct event *e;
  struct event *t;
  int i = 0;

  if(!em){
    DLNA_LOG(DLNA_LOG_PEER_EVENT, DLNA_LOG_LEVEL_ERROR, "event_cancel_event->null_pointer.");
    return;
  }

  e = em->event.head;
  while (e) {
    t = e;
    e = t->next;

    if (t->arg == arg) {
      event_list_delete (&em->event, t);
      event_add_unuse (em, t);
    }
  }
  e = em->ready.head;
  while (e) {
    t = e;
    e = t->next;
    if (t->arg == arg) {
      event_list_delete (&em->ready, t);
      event_add_unuse (em, t);
    }
  }
  e = em->read.head;
  while (e) {
    t = e;
    e = t->next;
    if (t->arg == arg) {
      FD_CLR (t->u.sock, &t->manager->readfd);
      event_list_delete (&em->read, t);
      event_add_unuse (em, t);
    }
  }
  e = em->write.head;
  while (e) {
    t = e;
    e = t->next;
    if (t->arg == arg) {
      FD_CLR (t->u.sock, &t->manager->writefd);
      event_list_delete (&em->write, t);
      event_add_unuse (em, t);
    }
  }
  for (i=0; i < EVENT_TIMER_SLOT; i++) {
    e = em->timer[i].head;
    while (e) {
      t = e;
      e = t->next;
      if (t->arg == arg) {
        event_list_delete (&em->timer[i], t);
        event_add_unuse (em, t);
      }
    }
  }
}

/* Pick up smallest timer.  */
static struct timeval *
event_timer_wait (struct event_manager *em, struct timeval *timer_val)
{
  struct timeval timer_now;
  struct timeval timer_min;
  struct timeval *timer_wait;
  struct event *event;
  int i;

  timer_wait = NULL;

  for (i = 0; i < EVENT_TIMER_SLOT; i++) {
    if ((event = em->timer[i].head) != NULL) {
      if (!timer_wait) {
        timer_wait = &event->u.sands;
      } else if (timeval_cmp (event->u.sands, *timer_wait) < 0) {
        timer_wait = &event->u.sands;
      }
    }
  }

  if (timer_wait) {
    timer_min = *timer_wait;

    gettimeofday (&timer_now, NULL);
    timer_min = timeval_subtract (timer_min, timer_now);

    if (timer_min.tv_sec < 0) {
      timer_min.tv_sec = 0;
      timer_min.tv_usec = 10;
    }

    *timer_val = timer_min;
   }
  else{
    timer_val->tv_sec = 0;
    timer_val->tv_usec = 50;
 }
  return timer_val;
}

static void
event_add_to_ready (struct event_manager *em, struct event *e)
{
  e->otype = e->type;
  e->type = EVENT_TYPE_READY;
  event_list_add (&em->ready, e);
}

/* When the file is ready move to queueu.  */
static void
event_process_sock (struct event_manager *em, struct event_list *list,
                    fd_set * fdset, fd_set * mfdset)
{
  struct event *e;
  struct event *next;

  for (e = list->head; e; e = next) {
    next = e->next;

    if (FD_ISSET (e->u.sock, fdset)) {
      FD_CLR (e->u.sock, mfdset);
      event_list_delete (list, e);
      event_add_to_ready (em, e);
    }
  }
}

/* Execute the event.  */
static void
event_run (struct event *e)
{
  if(!e){
    DLNA_LOG(DLNA_LOG_PEER_EVENT, DLNA_LOG_LEVEL_ERROR, "event_run->null_pointer.");
    return;
  }

  event_add_unuse (e->manager, e);
  if (e->otype == EVENT_TYPE_READ || e->otype == EVENT_TYPE_WRITE) {
    e->f.func_io (e->u.sock, e->arg);
  } else {
    e->f.func (e->arg);
  }
}

/* Intra-thread communication mechanism.  */
static int
event_loop_init (struct event_manager *em)
{
  struct sockaddr_in addr;
  int port = 30000;
  int ret;
  int i;
  dlna_ip_addr tmp_addr;

  if (CHECK_FLAG (em->flags, EVENT_FLAG_INTRACOM)) {
    DLNA_LOG(DLNA_LOG_PEER_EVENT, DLNA_LOG_LEVEL_DEBUG, "EVENT_FLAG_INTRACOM is set in event_loop_init()");
    return -1;
  }

  /* This self-socket connection is created to facilitate
   * communication with the input thread and the event loop thread
   * that blocks on select.  */
  em->sock_read = socket (AF_INET, SOCK_DGRAM, 0);
  em->sock_write = socket (AF_INET, SOCK_DGRAM, 0);

  if (em->sock_read < 0 || em->sock_write < 0) {
    DLNA_LOG(DLNA_LOG_PEER_EVENT, DLNA_LOG_LEVEL_DEBUG, "em->sock_read < 0 || em->sock_write < 0 in event_loop_init()");
    return -1;
  }
  /*
  Make the scoket non blocking socket because in some cases send
  block the thread.
  */
  dlna_sock_nonblocking(em->sock_write);
  dlna_sock_nonblocking(em->sock_read);

  dlna_memset (&addr, 0, sizeof (struct sockaddr_in));
  addr.sin_family = AF_INET;
  dlna_inet_aton("127.0.0.1", &tmp_addr);
  dlna_memcpy(&addr.sin_addr, &tmp_addr.fAddr, 4);

  /* Find out a free port.  */
  for (i = 0; i < 1000; i++) {
    addr.sin_port = htons (port + i);
    ret = bind (em->sock_read, (struct sockaddr *) &addr, sizeof (addr));
    if (ret == 0) {
      break;
    }
  }
  if (ret != 0) {
    DLNA_LOG(DLNA_LOG_PEER_EVENT, DLNA_LOG_LEVEL_ERROR, "Can't find out a free port.");
    goto failed;
  }

  ret = connect (em->sock_write, (struct sockaddr *) &addr, sizeof (addr));
  if (ret != 0) {
    DLNA_LOG(DLNA_LOG_PEER_EVENT, DLNA_LOG_LEVEL_ERROR, "connect() ->%d.", ret);
    goto failed;
  }

  /* Set the boolean flag to tell the event loop that the intracom
   * sockets have been setup successfully.  */
  SET_FLAG (em->flags, EVENT_FLAG_INTRACOM);

  return 0;

failed:
  if (em->sock_read != -1) {
    closesocket(em->sock_read);
    em->sock_read = -1;
  }

  if (em->sock_write != -1) {
    closesocket(em->sock_write);
    em->sock_write = -1;
  }

  DLNA_LOG(DLNA_LOG_PEER_EVENT, DLNA_LOG_LEVEL_ERROR, "Failed in event_loop_init()");

  return -1;
}

void
event_loop_fini(struct event_manager *em)
{
  if(!em){
    DLNA_LOG(DLNA_LOG_PEER_EVENT, DLNA_LOG_LEVEL_ERROR, "event_loop_fini->null_pointer.");
    return;
  }

  if (em->sock_read != -1) {
    closesocket(em->sock_read);
    DLNA_LOG(DLNA_LOG_PEER_EVENT, DLNA_LOG_LEVEL_DEBUG, "closesocket(em->sock_read);.");
    em->sock_read = -1;
  }

  if (em->sock_write != -1) {
    closesocket(em->sock_write);
    DLNA_LOG(DLNA_LOG_PEER_EVENT, DLNA_LOG_LEVEL_DEBUG, "closesocket(em->sock_write);.");
    em->sock_write = -1;
  }
  UNSET_FLAG (em->flags, EVENT_FLAG_INTRACOM);
}
/* Main loop of event manager. */
static void
event_loop (struct event_manager *em)
{
  int num;
  struct event *e;
  struct event *next;
  fd_set readfd;
  fd_set writefd;
  fd_set exceptfd;
  struct timeval timer_now;
  struct timeval timer_val;
  struct timeval *timer_wait;
  struct timeval timer_nowait = { 0, 0 };
  int i;
  DLNA_LOG(DLNA_LOG_PEER_EVENT, DLNA_LOG_LEVEL_DEBUG, "Enter event_loop.");
  while (1) {
    /* Protect the progress.  */
    dlnaProgressLockPeer (em);

    /* Lock Event Manager */
    dlnaEventManagerLockPeer(em);
    
    /*  Execute ready events.  */
    while (! event_list_empty (&em->ready)) {
      e = event_pop_front (&em->ready);
      
      dlnaEventManagerUnlockPeer(em);
      event_run (e);
      dlnaEventManagerLockPeer(em);
    }

    /* Move all events to ready events.  */
    while (! event_list_empty (&em->event)) {
      e = event_pop_front (&em->event);
      event_add_to_ready (em, e);
    }

    /* Get current time.  */
    gettimeofday (&timer_now, NULL);

    /* Move expired timer to ready events.  */
    for (i = 0; i < EVENT_TIMER_SLOT; i++) {
      for (e = em->timer[i].head; e; e = next) {
        next = e->next;

        if (timeval_cmp (timer_now, e->u.sands) >= 0) {
          event_list_delete (&em->timer[i], e);
          event_add_to_ready (em, e);
        }
      }
    }
    
    /* Structure copy.  */
    readfd = em->readfd;
    writefd = em->writefd;
    exceptfd = em->exceptfd;

    /* Calculate select wait timer.  */
    if (! event_list_empty (&em->ready)) {
      timer_val.tv_sec = 0;
      timer_val.tv_usec = 50;
      timer_nowait = timer_val;
      timer_wait = &timer_nowait;
    } else {
      timer_wait = event_timer_wait (em, &timer_val);
    }
    /* This will usually do nothing unless run on windows client.  */
    event_set_sockread (em, &readfd);

    /* Unlock Event Manager */
    dlnaEventManagerUnlockPeer(em);
    
    /* Unlock the progress.  */
    dlnaProgressUnlockPeer (em);

    /* Call select system call.  */
    num = select (em->max_sock + 1,
                    &readfd, &writefd, &exceptfd, timer_wait);

    /* Error handling.  */
    if (num < 0) {
      int error;

      error = WSAGetLastError ();
      if (error == 0) {
        continue;
      }
      DLNA_LOG(DLNA_LOG_PEER_EVENT, DLNA_LOG_LEVEL_ERROR, "select Error:%d, lastError%d.", num, error);
      break;
    }

    /* This will usually return false (0) unless run on windows
       client.  */
    dlnaProgressLockPeer(em);
    if (event_check_loop (em, &readfd, &num)) {
      DLNA_LOG(DLNA_LOG_PEER_EVENT, DLNA_LOG_LEVEL_DEBUG, "event_loop break.");
      dlnaProgressUnlockPeer(em);
      break;
    }
    dlnaProgressUnlockPeer(em);

    /* File descriptor is ready.  */
    if (num > 0) {

      dlnaProgressLockPeer(em);
      /* Check read. */
      event_process_sock (em, &em->read, &readfd, &em->readfd);

      /* Check write. */
      event_process_sock (em, &em->write, &writefd, &em->writefd);

      dlnaProgressUnlockPeer(em);
    }
   
  }
  //event_loop_fini(em);
  DLNA_LOG(DLNA_LOG_PEER_EVENT, DLNA_LOG_LEVEL_DEBUG, "exit event_loop.");
}

static void
event_stop_loop (struct event_manager *em)
{
  if (CHECK_FLAG (em->flags, EVENT_FLAG_INTRACOM)) {
    char *buf = "stop";
    DLNA_FUNC_ENTER(event_stop_loop);
    send (em->sock_write, buf, (int) dlna_strlen (buf), MSG_DONTROUTE);
    DLNA_FUNC_EXIT(event_stop_loop);
  }
}

/* Create locking mechanism */
LPCRITICAL_SECTION
dlnaCreateLock()
{
	LPCRITICAL_SECTION pzCS = (LPCRITICAL_SECTION)malloc(sizeof(CRITICAL_SECTION));
	if (!pzCS) return NULL;
#if (_WIN32_WINNT >= 0x0603 /*_WIN32_WINNT_WIN8*/)
	InitializeCriticalSectionEx(pzCS, 0, 0);
#else
	InitializeCriticalSection(pzCS);
#endif
	return pzCS;
}

/* Free the lock */
void dlnaDestroyLock(LPCRITICAL_SECTION pzCriticalSection)
{
	assert(pzCriticalSection);
	DeleteCriticalSection(pzCriticalSection);
	free(pzCriticalSection);
}

/* Allocate new event manager.  */
struct event_manager *
event_manager_alloc ()
{
  struct event_manager *em = calloc (1, sizeof (struct event_manager));
  if (!em) return NULL;
  // event loop callback
  em->loop = event_loop;
  em->init = event_loop_init;
  em->stop = event_stop_loop;
  em->pzCS = dlnaCreateLock();
  em->pzCS_em = dlnaCreateLock();
  return em;
}

/* Free event manager.  */
void
event_manager_free (struct event_manager *em)
{
  int i;
  event_list_free(&em->event);
  event_list_free(&em->read);
  event_list_free(&em->write);
  event_list_free(&em->ready);
  event_list_free(&em->unuse);

  for (i = 0; i < EVENT_TIMER_SLOT; i++)
    event_list_free(&em->timer[i]);
	
  dlnaDestroyLock(em->pzCS_em);
  dlnaDestroyLock(em->pzCS);

  em->pzCS_em = NULL;
  em->pzCS = NULL;

  event_loop_fini(em);
  
  free(em);
  em = NULL;
}
