/*
	peer.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/basis/peer.h 59    06/07/31 8:59 Someya $ */

#ifndef SLIM_PEER_H
#define SLIM_PEER_H

#ifndef SLIM_BASE_H
#include <slim/basis/base.h>
#endif

#ifndef SLIM_DNS_H
#include <slim/inet/dns.h>
#endif

#undef SLIM_API
#define SLIM_API SLIM_DLLIMPORT

SLIM_BEGIN_C_LINKAGE

/* system */

SLIM_API void slimSystemInitializePeer(void);
SLIM_API void slimSystemFinalizePeer(void);
SLIM_API slim_int slimGetTickCountPeer(void);
#ifdef SLIM_CONFIG_USE_IS_YIELDING_PEER
SLIM_API slim_bool slimIsYieldingPeer(void);
#endif

#ifdef SLIM_CONFIG_USE_SMIL
SLIM_API void slimSuspendTickCountPeer(void);
SLIM_API void slimResumeTickCountPeer(void);
#endif

/* net */

SLIM_API slim_int slimNetInitializePeer(void);
SLIM_API slim_int slimNetFinalizePeer(void);

/* tcp */

enum{
  SLIM_TCP_OP_DELAY		= 0,
  SLIM_TCP_OP_LINGER	= 1,
  SLIM_TCP_OP_KEEPALIVE = 2,
  SLIM_TCP_OP_RCVBUF	= 3,
  SLIM_TCP_OP_SNDBUF	= 4,
  SLIM_TCP_OPTIONS		= 5
};

SLIM_API slim_int slimTCPOpenPeer(slim_int in_domain);
SLIM_API void slimTCPClosePeer(slim_int in_desc);
SLIM_API slim_int slimTCPIsConnectedPeer(slim_int in_desc);
SLIM_API slim_int slimTCPCanReadWritePeer(slim_int in_desc, slim_int in_rw);
SLIM_API slim_int slimTCPConnectPeer(slim_int in_desc, slim_ip_addr *in_addr, slim_int in_port);
SLIM_API slim_int slimTCPReadPeer(slim_int in_desc, slim_byte *out_buf, slim_int in_len);
SLIM_API slim_int slimTCPWritePeer(slim_int in_desc, slim_byte *in_buf, slim_int in_len);
SLIM_API slim_int slimTCPGetLocalAddrPortPeer(slim_int in_desc, slim_ip_addr *out_addr, slim_int *out_port);
SLIM_API slim_int slimTCPGetOptionPeer(slim_int in_desc, slim_int in_opt);
SLIM_API slim_int slimTCPSetOptionPeer(slim_int in_desc, slim_int in_opt, slim_int in_value);
SLIM_API slim_int slimTCPIsBoundPeer(slim_int in_desc);

/* udp */

enum{
  SLIM_UDP_OP_SNDBUF	= 0,
  SLIM_UDP_OPTIONS		= 1
};

SLIM_API slim_int slimUDPOpenPeer(slim_int in_domain);
SLIM_API slim_int slimUDPCanReadWritePeer(slim_int in_desc, slim_int in_rw);
SLIM_API slim_int slimUDPClosePeer(slim_int in_desc);
SLIM_API slim_int slimUDPSendToPeer(slim_int in_desc, void *in_buf, slim_int in_len, slim_ip_addr *in_addr, slim_int in_port);
SLIM_API slim_int slimUDPRecvFromPeer(slim_int in_desc, void *out_buf, slim_int in_len, slim_ip_addr *out_addr, slim_int *out_port);
SLIM_API slim_int slimUDPGetLocalAddrPortPeer(slim_int in_desc, slim_ip_addr *out_addr, slim_int *out_port);
SLIM_API slim_int slimUDPGetOptionPeer(slim_int in_desc, slim_int in_opt);
SLIM_API slim_int slimUDPBindPeer(slim_int in_desc, slim_ip_addr *in_addr, slim_int in_port);
SLIM_API slim_int slimUDPIsBoundPeer(slim_int in_desc);

#ifdef SLIM_CONFIG_USE_DNS
/* dns */

typedef slim_opaque TDNSPeer;
typedef void (*TDNSWakeUpCallbackProc)(slim_opaque in_callback_aux, slim_int in_ticket_id);

SLIM_API slim_int slimDNSInitializePeer(TDNSWakeUpCallbackProc in_callback, slim_opaque in_callback_aux, TDNSPeer *out_obj);
SLIM_API void slimDNSFinalizePeer(TDNSPeer self);
SLIM_API void slimDNSSetServerPeer(TDNSPeer self, slim_ip_addr* in_prim_svr, slim_ip_addr* in_sec_svr);
SLIM_API slim_int slimDNSRequestResolvePeer(TDNSPeer self, slim_char* in_domain, slim_int in_len);
SLIM_API void slimDNSRequestCancelPeer(TDNSPeer self, slim_int in_ticket_id);
SLIM_API slim_int slimDNSIsResolvedPeer(TDNSPeer self, slim_int in_ticket_id);
SLIM_API slim_int slimDNSGetAddressPeer(TDNSPeer self, slim_int in_ticket_id, slim_ip_addr* out_addr, slim_int in_n, slim_word *out_ttl);
SLIM_API slim_int slimDNSSetModePeer(TDNSPeer self, slim_int in_mode);
SLIM_API void slimDNSSetDNSPortPeer(TDNSPeer self, slim_int in_port);
SLIM_API void slimDNSSetMaxRetryPeer(TDNSPeer self, slim_int in_retry);
SLIM_API void slimDNSSetRetryIntervalPeer(TDNSPeer self, slim_int in_interval);

#endif /* SLIM_CONFIG_USE_DNS */

#ifdef SLIM_CONFIG_USE_TCP_SERVER

SLIM_API slim_int slimTCPServerOpenPeer(slim_int in_domain);
SLIM_API slim_int slimTCPAcceptPeer(slim_int in_desc, slim_ip_addr *out_addr, slim_int *out_port);
SLIM_API slim_int slimTCPBindPeer(slim_int in_desc, slim_ip_addr *in_addr, slim_int in_port);
SLIM_API slim_int slimTCPListenPeer(slim_int in_desc, slim_int in_queuelen);

#endif /* SLIM_CONFIG_USE_TCP_SERVER */



/* file */
SLIM_API slim_iaddr_word slimFileOpenPeer(slim_char *in_fname, slim_int in_flag);
SLIM_API void slimFileClosePeer(slim_iaddr_word in_desc);
SLIM_API slim_int slimFileReadPeer(slim_iaddr_word in_desc, void *out_buf, slim_int in_len);
SLIM_API slim_int slimFileWritePeer(slim_iaddr_word in_desc, void *in_buf, slim_int in_len);
SLIM_API slim_int slimFileSeekPeer(slim_iaddr_word in_desc, slim_int in_offset, slim_int in_origin);
SLIM_API slim_int slimFileDeletePeer(slim_char *in_fname);

#ifdef SLIM_CONFIG_ENABLE_FILESYSTEM_PEER
/* file system */
SLIM_API slim_int slimFileSystemGetCWDPeer(void *out_path, slim_int in_buf_len);
SLIM_API slim_int slimFileSystemChDirPeer(slim_char *in_path);
SLIM_API slim_int slimFileSystemOpenDirPeer(slim_char *in_path);
SLIM_API void slimFileSystemCloseDirPeer(slim_int in_desc);
SLIM_API slim_dirent * slimFileSystemReadDirPeer(slim_int in_desc);
SLIM_API void slimFileSystemRewindDirPeer(slim_int in_desc);
SLIM_API slim_int slimFileSystemStatPeer(slim_char *in_path, slim_stat *out_stat);
SLIM_API slim_int slimFileSystemMkDirPeer(slim_char *in_path);
SLIM_API slim_int slimFileSystemRmDirPeer(slim_char *in_path);
#endif /* SLIM_CONFIG_ENABLE_FILESYSTEM_PEER */



/* time */

SLIM_API slim_int slimGetCurrentDatePeer(slim_int *out_year, slim_int *out_mon, slim_int *out_mday,
		slim_int *out_hour, slim_int *out_min, slim_int *out_sec, slim_int *out_msec);
SLIM_API slim_int slimGetTZOffsetPeer(void);

/* memory */

#ifdef SLIM_CONFIG_USE_ALT_MEMORY_PEER
SLIM_API void *slimMemoryAltMallocPeer(slim_int in_size);
SLIM_API void *slimMemoryAltReallocPeer(void *in_p, slim_int in_size);
SLIM_API void slimMemoryAltFreePeer(void *in_p);
#endif

#ifdef SLIM_CONFIG_MULTITHREAD
SLIM_API void slimMemoryMutexLockPeer(slim_opaque);
SLIM_API void slimMemoryMutexUnlockPeer(slim_opaque);

/* mutex */

#define slimMutexLockPeer(mutex)	slimMemoryMutexLockPeer(mutex)
#define slimMutexUnlockPeer(mutex)	slimMemoryMutexUnlockPeer(mutex)
#endif

/* pixelmap */

#ifdef SLIM_CONFIG_PIXMAP_USE_SPECIAL
SLIM_API void slimPixelMapOptimizePeer(slim_int in_src_type, slim_int in_width, slim_int in_height,
	slim_byte *in_pixels, slim_byte *in_mask, slim_byte *in_palette, slim_int in_dest_type);
#endif

/* debug */
#ifdef SLIM_CONFIG_DEBUG
SLIM_API void slimDebugPrintfPeer(char *in_format, ...);
SLIM_API void slimDebugPrintfWPeer(char *in_format, ...);
SLIM_API void slimDebugAssertFailPeer(char *in_condition, char *in_filename, int in_lineno, int in_verbosity, char *in_msg);
#endif

#ifdef SLIM_CONFIG_DEBUG_LOG
SLIM_API slim_bool slimLogInitializePeer(void);
SLIM_API void slimLogFinalizePeer(void);
SLIM_API void slimLogEnterFunctionPeer(char *in_obj, char *in_method, int in_id);
SLIM_API void slimLogExitFunctionPeer(void);
SLIM_API void slimLogSignalPeer(int in_signal);
SLIM_API void slimLogMessagePeer(char *in_format, ...);
#endif

SLIM_END_C_LINKAGE

#undef SLIM_API
#define SLIM_API SLIM_DLLEXPORT

#endif
