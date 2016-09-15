#ifndef NETIF_KERNEL_H
#define NETIF_KERNEL_H

struct pal_kernel
{
  /* Progress.  */
  dlna_progress em;

  /* Flags.  */
  slim_word flags;

  /* Platform dependent information.  */
  void *info;

  /* Callback.  */
  int (*callback) (dlna_netif_event in_event, void *in_arg, void *in_param);

  /* Argument for callback.  */
  void *arg;
};

#endif /* NETIF_KERNEL_H */
