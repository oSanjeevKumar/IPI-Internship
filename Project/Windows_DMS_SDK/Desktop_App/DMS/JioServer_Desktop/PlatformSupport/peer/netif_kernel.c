/*Copyright (C) 2011 ACCESS CO.,LTD.
* All rights are reserved by ACCESS CO.,LTD., whether the whole or part
* of the source code including any modifications is concerned.
*
* This is an unpublished source code of ACCESS CO.,LTD., and must be
* treated as confidential material.  The above copyright notice does
* not evidence any actual or intended publication of this source code.
*/
#include <dlna_peer.h>
#include "netif_iphelper.h"
#include "netif_kernel.h"

static int
pal_kernel_start (struct pal_kernel *pk)
{
	struct pal_kernel_info *info = pk->info;
	DWORD ret;

	/* Scan the interface.  */
	ret = pal_iphelper_scan( pk, &(INFO(pk)->if_list) );

  if ( 0 == ret )
    ret = pal_iphelper_register_notify_event( pk );

  if ( 0 == ret )
    pal_iphelper_register_timer_event(pk);

	return ret;
}

static int
pal_kernel_stop (struct pal_kernel *pk)
{
  /* Cancel events.  */
  pal_iphelper_cancel_timer_event( pk );
  return 0;
}

static int
pal_kernel_if_start (struct pal_kernel *pk, int ifindex)
{
  return 0;
}

static int
pal_kernel_if_stop (struct pal_kernel *pk, int ifindex)
{
  return 0;
}

static struct pal_kernel *
pal_kernel_alloc (dlna_progress in_p, dlna_netif_callback in_callback,
		  void *in_arg, slim_word in_flags)
{
  struct pal_kernel_info *info;
  struct pal_kernel *pk;

  pk = dlna_memory_alloc (sizeof (struct pal_kernel));
  if (! pk)
    return 0;

  /* Set the kernel information.  */
  dlna_memset (pk, 0, sizeof (struct pal_kernel));

  info = dlna_memory_alloc (sizeof (struct pal_kernel_info));
  if (! info)
    {
      dlna_memory_free (pk);
      return 0;
    }
  dlna_memset (info, 0, sizeof (struct pal_kernel_info));
  info->pk = pk;
  pal_iphelper_if_list_init( &(info->if_list) );

  pk->info = info;
  pk->em = in_p;
  pk->flags = in_flags;
  pk->callback = in_callback;
  pk->arg = in_arg;

  return pk;
}

static void
pal_kernel_free (struct pal_kernel *pk)
{
  struct pal_kernel_info *info = pk->info;

  pal_kernel_stop (pk);

  // Clear out the lists
  pk->callback = NULL;
  pal_iphelper_if_list_delete( &(info->if_list) );

  dlna_memory_free (pk->info);
  dlna_memory_free (pk);
}

/* Network interface open.  */
dlna_netif
dlnaNetIfAllocPeer (dlna_progress in_p, dlna_netif_callback in_callback,
                    void *in_arg)
{
  struct pal_kernel *pk;

  pk = pal_kernel_alloc (in_p, in_callback, in_arg, 0);
  if (! pk) {
    return NULL;
  }
  return (dlna_netif) pk;
}

slim_int
dlnaNetIfStartPeer (dlna_netif in_netif)
{
  struct pal_kernel *pk;

  pk = (struct pal_kernel *) in_netif;

  return pal_kernel_start (pk);
}

void
dlnaNetIfStopPeer (dlna_netif in_netif)
{
  struct pal_kernel *pk;

  pk = (struct pal_kernel *) in_netif;

  pal_kernel_stop (pk);
}

/* Network interface close.  */
void
dlnaNetIfFreePeer (dlna_netif in_netif)
{
  struct pal_kernel *pk;

  pk = (struct pal_kernel *) in_netif;

  pal_kernel_free (pk);
}

int
dlnaNetIfInterfaceStartPeer (dlna_netif in_netif, slim_int in_ifindex)
{
  struct pal_kernel *pk;

  pk = (struct pal_kernel *) in_netif;

  return pal_kernel_if_start (pk, in_ifindex);
}

int
dlnaNetIfInterfaceStopPeer (dlna_netif in_netif, slim_int in_ifindex)
{
  struct pal_kernel *pk;

  pk = (struct pal_kernel *) in_netif;

  return pal_kernel_if_stop (pk, in_ifindex);
}
