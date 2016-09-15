/*
	dns.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/inet/dns.h 31    05/12/28 12:08 Someya $ */

#ifndef SLIM_DNS_H_PRIVATE
#define SLIM_DNS_H_PRIVATE

SLIM_BEGIN_C_LINKAGE

/*     */
/* DNS */
/*     */
#define SLIM_DNS_PORT 53
#define SLIM_DNS_MAX_RETRY 2
	/* constants above are based on RFC 883 */
#define SLIM_DNS_RETRY_INTERVAL	5000	/* 5 sec */

#ifdef SLIM_CONFIG_USE_DNS
#else
#define TDNS_Initialize(self, in_callback, in_callback_aux) (SLIM_E_OK)
#define TDNS_Finalize(self) ((void)0)
#define TDNS_SetServer(self, in_prim_svr, in_sec_svr) ((void)0)
#define TDNS_GetTicket(self, in_domain, in_len) (SLIM_E_GENERIC)
#define TDNS_ReleaseTicket(self, in_ticket_id) ((void)0)
#define TDNS_LookUp(self, in_ticket_id) (SLIM_E_GENERIC)
#define TDNS_GetAddress(self, in_ticket_id, out_addr, in_n, out_ttl) (SLIM_E_GENERIC)
#define TDNS_SetMode(self, in_mode) ((void)0)
#define TDNS_SetDNSPort(self, in_port) ((void)0)
#define TDNS_SetMaxRetry(self, in_retry) ((void)0)
#define TDNS_SetRetryInterval(self, in_interval) ((void)0)
#endif

SLIM_END_C_LINKAGE

#endif
