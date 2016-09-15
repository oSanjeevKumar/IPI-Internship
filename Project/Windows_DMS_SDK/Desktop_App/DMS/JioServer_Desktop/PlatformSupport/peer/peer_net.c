/*
 * peer_net.c
 * Copyright (C) 2007-2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */

/* DLNA peer socket APIs.  */

#include <dlna_peer.h>
#include "progress_event.h"
#include <errno.h>

#define LOCALHOST_IP SLIM_T("127.0.0.1")
/* Lookup the MAC address binding with dlna_ip_addr */
#if (WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) && WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_PHONE_APP))|| (WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)&& !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP))
slim_int
dlna_inet_iptomac(dlna_ip_addr *in_addr, slim_char *out_mac) {
//TODO:SM: we need to define this method to get the MAC address.
  return 0;
}
#else
slim_int
dlna_inet_iptomac (dlna_ip_addr *in_addr, slim_char *out_mac)
{
	DWORD i;
	DWORD dwSize = 0;
	PMIB_IPNETTABLE pIpNetTable = 0;
	PIP_ADAPTER_INFO pAdapterInfo = 0;
	PIP_ADAPTER_INFO pTmpAdapterInfo = 0;
	slim_ulong mac_len = sizeof(ULONG) * 2;
	slim_byte byte_mac[sizeof(ULONG) * 2];

	if (dlna_strcmp(dlna_inet_ntoa(*in_addr), LOCALHOST_IP) == 0)
		return SLIM_E_OK;

	pAdapterInfo = (IP_ADAPTER_INFO *)dlna_memory_alloc(sizeof(IP_ADAPTER_INFO));
	if (pAdapterInfo == 0)
		goto get_ip_net_table;

	// get the size required for GetAdaptersInfo
	if (GetAdaptersInfo(pAdapterInfo, &dwSize) != ERROR_BUFFER_OVERFLOW)
		goto get_ip_net_table_free_pAdapterInfo;
	
	dlna_memory_free(pAdapterInfo);
	pAdapterInfo = (IP_ADAPTER_INFO *)dlna_memory_alloc((slim_int)dwSize);
	if (pAdapterInfo == 0)
		goto get_ip_net_table;

	if (GetAdaptersInfo(pAdapterInfo, &dwSize) != NO_ERROR)
		goto get_ip_net_table_free_pAdapterInfo;
	pTmpAdapterInfo = pAdapterInfo;
	do {
		if (dlna_strcmp(dlna_inet_ntoa(*in_addr), pTmpAdapterInfo->IpAddressList.IpAddress.String) == 0) {
			sprintf(out_mac, "%.2X:%.2X:%.2X:%.2X:%.2X:%.2X",
				pTmpAdapterInfo->Address[0], pTmpAdapterInfo->Address[1],
				pTmpAdapterInfo->Address[2], pTmpAdapterInfo->Address[3],
				pTmpAdapterInfo->Address[4], pTmpAdapterInfo->Address[5]);
			dlna_memory_free(pAdapterInfo);
			return SLIM_E_OK;
		}
		pTmpAdapterInfo = pTmpAdapterInfo->Next;
	} while(pTmpAdapterInfo);

get_ip_net_table_free_pAdapterInfo:
	dlna_memory_free(pAdapterInfo);
get_ip_net_table:
	dwSize = 0;
	// get the size required for GetIpNetTable
	if (GetIpNetTable(NULL, &dwSize, 0) != ERROR_INSUFFICIENT_BUFFER)
		goto send_arp;

	// alloc buff for GetIpNetTable and get results
	pIpNetTable = (MIB_IPNETTABLE *)dlna_memory_alloc((slim_int)dwSize);
	if (pAdapterInfo == 0)
		goto send_arp;
	if (GetIpNetTable(pIpNetTable, &dwSize, 0) != NO_ERROR)
		goto send_arp_free_pIpNetTable;

	for (i = 0; i < pIpNetTable->dwNumEntries; i ++) {
		if (((struct in_addr *)&pIpNetTable->table[i].dwAddr)->S_un.S_addr == ((struct in_addr *)in_addr->fAddr)->S_un.S_addr) {
			sprintf(out_mac, "%.2X:%.2X:%.2X:%.2X:%.2X:%.2X",
				pIpNetTable->table[i].bPhysAddr[0], pIpNetTable->table[i].bPhysAddr[1],
				pIpNetTable->table[i].bPhysAddr[2], pIpNetTable->table[i].bPhysAddr[3],
				pIpNetTable->table[i].bPhysAddr[4], pIpNetTable->table[i].bPhysAddr[5]);
			dlna_memory_free(pIpNetTable);
			return SLIM_E_OK;
		}
	}

send_arp_free_pIpNetTable:
	dlna_memory_free(pIpNetTable);
send_arp:
	return SLIM_E_OK;
	// send ARP request to get a MAC for specified IP
	if (SendARP((*(PULONG)in_addr->fAddr),
		0, (PULONG)byte_mac, (PULONG)&mac_len) != NO_ERROR)
		return SLIM_E_GENERIC;
	sprintf(out_mac, "%.2X:%.2X:%.2X:%.2X:%.2X:%.2X",
		byte_mac[0], byte_mac[1],
		byte_mac[2], byte_mac[3],
		byte_mac[4], byte_mac[5]);
    return SLIM_E_OK;
}
#endif

/* Set socket to nonblocking.  */
slim_int
dlna_sock_nonblocking (slim_int in_sock)
{
  int iMode = 1;
  // set nonblocking flag
  ioctlsocket(in_sock, FIONBIO, (u_long FAR *) &iMode);
  return 0;
}

/* Bind the socket.  */
static slim_int
dlna_sock_bind (slim_int in_desc, dlna_ip_addr * in_addr, slim_int in_port)
{
  struct sockaddr_in sin;

  memset (&sin, 0, sizeof sin);

  sin.sin_family = AF_INET;
  memcpy (&sin.sin_addr, in_addr->fAddr, 4);
  sin.sin_port = htons ((slim_half) in_port);

  return (slim_int) bind (in_desc, (struct sockaddr *) &sin, sizeof sin);
}

/* Initialization of network peer.  */
slim_int
dlnaNetInitializePeer ()
{
	WSADATA wsaData;
	int iResult;
	
	/* Initialize Winsock 2.  */
	iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
	if (iResult != NO_ERROR)
		dlnaDebugPrintfPeer("Error at WSAStartup()\n");
	return SLIM_E_OK;
}

/* Finialize network peer.  */
slim_int
dlnaNetFinalizePeer ()
{
  /* Terminate use of the Winsock.  */
  WSACleanup();
  return SLIM_E_OK;
}

slim_int
dlnaSockSetPriority (slim_int sock, slim_int priority)
{
	// TODO: SO_PRIORITY - linux-specific, so no possible ???
	return -1;
}

/* TCP socket open.  */
slim_int
dlnaTCPOpenPeer (slim_int in_domain)
{
  int sock;
  // reject IPv6 for now
  if (in_domain == DLNA_IP_ADDR_TYPE_V6)
    return -1;
  // open socket
  sock = (slim_int) socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0)
    return -1;
  // nonblocking
  dlna_sock_nonblocking(sock);
  return sock;
}

/* TCP server socket open.  */
slim_int
dlnaTCPServerOpenPeer (slim_int in_domain)
{
  int sock, on = 1, alive;
  // reject IPv6 for now
  if (in_domain == DLNA_IP_ADDR_TYPE_V6)
    return -1;
  // open socket
  sock = (slim_int) socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0)
    return -1;
  // set socket options
  setsockopt (sock, SOL_SOCKET, SO_BROADCAST, (const char *) &on, sizeof on);
  setsockopt (sock, SOL_SOCKET, SO_REUSEADDR, (const char *) &on, sizeof on);
#ifdef SO_REUSEPORT
  setsockopt (sock, SOL_SOCKET, SO_REUSEPORT, (const char *) &on, sizeof on);
#endif /* SO_REUSEPORT */
  // nonblocking
  dlna_sock_nonblocking (sock);
  return sock;
}

/* TCP socket close.  */
void
dlnaTCPClosePeer (slim_int in_desc)
{
  shutdown(in_desc, SD_BOTH);
  closesocket(in_desc);
}

/* Check TCP socket is connected or not.  */
slim_int
dlnaTCPIsConnectedPeer (slim_int in_desc)
{
  int ret;
  int status;
  socklen_t len;
  // set length
  len = sizeof status;
  ret = getsockopt (in_desc, SOL_SOCKET, SO_ERROR, (char *)&status, &len);
  if (ret < 0)
    return SLIM_E_GENERIC;
  // it is not conntected
  if (status != 0)
    return 0;
  // connected
  return 1;
}

slim_int
dlnaTCPConnectPeer (slim_int in_desc, dlna_ip_addr * in_addr,
                    slim_int in_port)
{
  int ret;
  struct sockaddr_in sin;
  // prepare address
  memset (&sin, 0, sizeof sin);
  sin.sin_family = AF_INET;
  memcpy (&sin.sin_addr, in_addr->fAddr, 4);
  sin.sin_port = htons ((slim_half) in_port);
  // connect
  ret = connect (in_desc, (struct sockaddr *) &sin, sizeof sin);
  if (ret < 0) {
	  int error = WSAGetLastError();
	  if (error == WSAEWOULDBLOCK || 
		  error == WSAEINPROGRESS ||
		  error == WSAEISCONN)
		  return SLIM_E_WOULDBLOCK;
	  else
		  return SLIM_E_GENERIC;
  }
  return ret;
}

slim_int
dlnaTCPReadPeer (slim_int in_desc, slim_byte * out_buf, slim_int in_len)
{
  int ret = recv(in_desc, out_buf, in_len, 0);
  if (ret < 0) {
      if (WSAGetLastError() == WSAEWOULDBLOCK)
		  return SLIM_E_WOULDBLOCK;
	  else
		  return SLIM_E_GENERIC;
  }
  return ret;
}

slim_int
dlnaTCPWritePeer (slim_int in_desc, slim_byte * in_buf, slim_int in_len)
{
  int ret = send(in_desc, in_buf, (size_t) in_len, 0);
  if (ret < 0) {
	  if (WSAGetLastError() == WSAEWOULDBLOCK)
		  return SLIM_E_WOULDBLOCK;
	  else
		  return SLIM_E_GENERIC;
  }
  return ret;
}

slim_int
dlnaTCPBindPeer (slim_int in_desc, dlna_ip_addr * in_addr, slim_int in_port)
{
  return dlna_sock_bind (in_desc, in_addr, in_port);
}

slim_int
dlnaTCPListenPeer (slim_int in_desc, slim_int in_queuelen)
{
  return (slim_int) listen (in_desc, in_queuelen);
}

slim_int
dlnaTCPAcceptPeer (slim_int in_desc, dlna_ip_addr * out_addr,
                   slim_int * out_port)
{
  struct sockaddr_in sin;
  socklen_t addrlen = sizeof sin;
  // accept the socket
  int ret = (slim_int) accept (in_desc, (struct sockaddr *) &sin, &addrlen);
  // set return value when accept() success
  if (ret >= 0)
  {
	  if (out_addr)
	  {
		  out_addr->fType = DLNA_IP_ADDR_TYPE_V4;
		  memcpy (out_addr->fAddr, &sin.sin_addr, 4);
	  }
	  if (out_port)
		  (*out_port) = (slim_int) ntohs (sin.sin_port);
  }
  return ret;
}

slim_int
dlnaTCPGetLocalAddrPortPeer (slim_int in_desc, dlna_ip_addr * out_addr,
                             slim_int * out_port)
{
  int ret;
  struct sockaddr_in sin;
  socklen_t sinlen;

  memset (&sin, 0, sizeof sin);
  sinlen = sizeof sin;

  ret = getsockname (in_desc, (struct sockaddr *) &sin, &sinlen);
  if (ret < 0) {
    return -1;
  }
  
  if (out_addr) {
    out_addr->fType = DLNA_IP_ADDR_TYPE_V4;
    memcpy (out_addr->fAddr, &sin.sin_addr, 4);
  }

  if (out_port) {
    (*out_port) = (slim_int) ntohs (sin.sin_port);
  }
  return 0;
}

slim_int
dlnaTCPGetRemoteAddrPortPeer (slim_int in_desc, dlna_ip_addr * out_addr,
                              slim_int * out_port)
{
  int ret;
  struct sockaddr_in sin;
  socklen_t sinlen;

  memset (&sin, 0, sizeof sin);
  sinlen = sizeof sin;

  ret = getpeername (in_desc, (struct sockaddr *) &sin, &sinlen);
  if (ret < 0) {
    return -1;
  }
  
  if (out_addr) {
    out_addr->fType = DLNA_IP_ADDR_TYPE_V4;
    memcpy (out_addr->fAddr, &sin.sin_addr, 4);
  }

  if (out_port) {
    (*out_port) = (slim_int) ntohs (sin.sin_port);
  }
  return 0;
}

/* UDP socket open.  */
slim_int
dlnaUDPOpenPeer (slim_int in_domain)
{
  int sock;
  int on = 1;

  /* Reject IPv6 for now.  */
  if (in_domain == DLNA_IP_ADDR_TYPE_V6) {
    return -1;
  }
  
  /* Open socket.  */
  sock = (slim_int) socket (AF_INET, SOCK_DGRAM, 0);
  if (sock < 0) {
    return -1;
  }
  
  /* This should be removed.  */
  setsockopt (sock, SOL_SOCKET, SO_REUSEADDR, (const char *) &on, sizeof on);
#ifdef SO_REUSEPORT
  setsockopt (sock, SOL_SOCKET, SO_REUSEPORT, (const char *) &on, sizeof on);
#endif /* SO_REUSEPORT */

  /* Making the socket non blocking.  */
  dlna_sock_nonblocking (sock);

  return sock;
}

/* Close UDP socket.  */
void
dlnaUDPClosePeer (slim_int in_desc)
{
  shutdown(in_desc, SD_BOTH);
  closesocket (in_desc);
}

/* UDP sendto().  */
slim_int
dlnaUDPSendToPeer (slim_int in_desc, void *in_buf, slim_int in_len,
                   dlna_ip_addr * in_addr, slim_int in_port)
{
  int ret;
  struct sockaddr_in sin;
  memset(&sin, 0, sizeof sin);
  sin.sin_family = AF_INET;
  memcpy(&sin.sin_addr, in_addr->fAddr, 4);
  sin.sin_port = htons((slim_half) in_port);
  ret = sendto(in_desc, in_buf, in_len, 0, (struct sockaddr *)&sin, sizeof sin);
  if (ret < 0) {
      if (WSAGetLastError() == WSAEWOULDBLOCK)
		  return SLIM_E_WOULDBLOCK;
	  else
		  return SLIM_E_GENERIC;
  }
  return ret;
}

/* UDP recvfrom().  */
slim_int
dlnaUDPRecvFromPeer (slim_int in_desc, void *out_buf, slim_int in_len,
                     dlna_ip_addr * out_addr, slim_int * out_port)
{
  int ret;
  struct sockaddr_in sin;
  socklen_t sinlen = sizeof sin;
  ret = recvfrom(in_desc, out_buf, in_len, 0, (struct sockaddr *) &sin, &sinlen);
  if (ret < 0) {
      if (WSAGetLastError() == WSAEWOULDBLOCK)
		  return SLIM_E_WOULDBLOCK;
	  else
		  return SLIM_E_GENERIC;
  }
  if (out_addr) {
    out_addr->fType = DLNA_IP_ADDR_TYPE_V4;
    memcpy (out_addr->fAddr, &sin.sin_addr, 4);
  }
  if (out_port) {
    *out_port = (slim_int) ntohs (sin.sin_port);
  }
  return ret;
}

/* Bind UDP socket.  */
slim_int
dlnaUDPBindPeer (slim_int in_desc, dlna_ip_addr * in_addr, slim_int in_port)
{
  return dlna_sock_bind (in_desc, in_addr, in_port);
}

/* Set UDP option.  */
slim_int
dlnaUDPSetOptionPeer (slim_int in_desc, slim_int in_opt, slim_int in_value)
{
  unsigned char val = in_value;

  if (in_opt != DLNA_UDP_OP_MULTICAST_TTL) {
    return SLIM_E_GENERIC;
  }
  return setsockopt (in_desc, IPPROTO_IP, IP_MULTICAST_TTL, (const char *)&val, sizeof val);
}

struct ip_mreqn {
	struct in_addr imr_multiaddr; // IP multicast group address
	struct in_addr imr_address;   // IP address of local interface
	int            imr_ifindex;   // interface index
};

/* Set interface multicast capable.  */
slim_int
dlnaMulticastInterfacePeer (slim_int in_desc, dlna_ip_addr * in_ifaddr,
                            slim_int in_ifindex)
{
  struct ip_mreqn mr;

  memset (&mr, 0, sizeof (mr));

  if (in_ifindex)
    mr.imr_ifindex = in_ifindex;
  else
    memcpy (&mr.imr_address, in_ifaddr->fAddr, 4);

  return setsockopt (in_desc, IPPROTO_IP, IP_MULTICAST_IF, (const char *)&mr, sizeof mr);
}

/* Utility function for join and leave multicast group.  */
static slim_int
dlna_multicast_util (slim_int in_desc, dlna_ip_addr * in_maddr,
                     dlna_ip_addr * in_ifaddr, slim_int in_ifindex,
                     slim_int in_cmd)
{
  struct ip_mreqn mr;

  memset (&mr, 0, sizeof (mr));

  memcpy (&mr.imr_multiaddr, in_maddr->fAddr, 4);

  mr.imr_ifindex = in_ifindex;
  memcpy (&mr.imr_address, in_ifaddr->fAddr, 4);

  return setsockopt (in_desc, IPPROTO_IP, in_cmd,
		     (const char *) &mr, sizeof (mr));
}

/* Join to the multicast group.  */
slim_int
dlnaMulticastJoinPeer (slim_int in_desc, dlna_ip_addr * in_maddr,
                       dlna_ip_addr * in_ifaddr, slim_int in_ifindex)
{
  return dlna_multicast_util (in_desc, in_maddr, in_ifaddr, in_ifindex,
                              IP_ADD_MEMBERSHIP);
}

/* Leave from the multicast group.  */
slim_int
dlnaMulticastLeavePeer (slim_int in_desc, dlna_ip_addr * in_maddr,
                        dlna_ip_addr * in_ifaddr, slim_int in_ifindex)
{
  return dlna_multicast_util (in_desc, in_maddr, in_ifaddr, in_ifindex,
                              IP_DROP_MEMBERSHIP);
}

/* DLNA network utility API.  */
slim_int
dlna_inet_aton (slim_char * in_cp, dlna_ip_addr * out_addr)
{
  unsigned long lval;
  struct in_addr addr;
  // set to IPv4
  out_addr->fType = DLNA_IP_ADDR_TYPE_V4;
  lval = inet_addr(in_cp);
  DLNA_LOG(DLNA_LOG_PEER, DLNA_LOG_LEVEL_DEBUG, "input addr:%s -- output addr:%d", in_cp, lval);
  if (lval == INADDR_NONE && strcmp(in_cp, "255.255.255.255"))
    return 0;
  addr.s_addr = lval;
  dlna_memcpy(out_addr->fAddr, &addr, 4);
  return 1;
}

slim_char *
dlna_inet_ntoa (dlna_ip_addr in_addr)
{
  struct in_addr addr;

  /* Copy address.  */
  memcpy (&addr, in_addr.fAddr, 4);

  return (slim_char *) inet_ntoa (addr);
}

slim_int
dlnaTCPGetHostByNamePeer (slim_char *in_desc, dlna_ip_addr *out_addr)
{
	struct hostent *host;
	host = gethostbyname((char *)in_desc);
	if( host > 0 ) {
      dlna_memcpy(out_addr->fAddr, host->h_addr_list[0], 4);
	   return 1 ;
	} else {
      return 0 ;
    }
}

slim_int
dlnaGetErrnoPeer()
{
  return errno;
}