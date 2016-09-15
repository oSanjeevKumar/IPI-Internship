#ifndef CP_THREAD_H
#define CP_THREAD_H

/* Thread function typedef.  */
typedef void * (*thread_func) (void *);

typedef struct thread_args
{
  thread_func func;
  void *args;
  int bContinue;
} thread_args_t;

struct cp_thread
{
  /* Thread ID.  */
  slim_word id;

  /* Thread argument.  */
  thread_args_t args;
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus  */

struct cp_thread *
cp_thread_start (thread_func func, void* args);

int
cp_thread_wait_exit (struct cp_thread *thread);

void
cp_thread_stop (struct cp_thread *thread);

#ifdef __cplusplus
}
#endif	/* __cplusplus */

#endif /* CP_THREAD_H */
