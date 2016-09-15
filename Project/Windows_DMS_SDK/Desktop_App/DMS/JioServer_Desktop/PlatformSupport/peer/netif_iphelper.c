/* Copyright (C) 2011 ACCESS CO.,LTD.
* All rights are reserved by ACCESS CO.,LTD., whether the whole or part
* of the source code including any modifications is concerned.
*
* This is an unpublished source code of ACCESS CO.,LTD., and must be
* treated as confidential material.  The above copyright notice does
* not evidence any actual or intended publication of this source code.
*/

#include <dlna_peer.h>
#include "netif_kernel.h"
#include "netif_iphelper.h"

#define INTERFACE_LOOPBACK_INDEX_DEFAULT 1

// This function belongs somewhere else, unsure yet
// ( 20060127 - RFP )
static slim_byte pal_masklen(DWORD* netmask)
{
  slim_byte len;
  slim_byte *pnt;
  slim_byte *end;
  slim_byte val;

  len = 0;
  pnt = (slim_byte*)netmask;
  end = pnt + 4;

  while ((*pnt == 0xff) && pnt < end)
  {
	len += 8;
	pnt++;
  }

  if (pnt < end)
  {
	val = *pnt;
	while (val)
	{
	  len++;
	  val <<= 1;
	}
  }
  return len;
}

#if (_WIN32_WINNT <= 0x0602 /*_WIN32_WINNT_WIN8*/)
static void pal_iphelper_if_flags(dlna_interface *ifp, PIP_ADAPTER_INFO pAdapter)
{
  MIB_IFROW IFRow;
  IFRow.dwIndex = pAdapter->Index;

  if (GetIfEntry(&IFRow) == NO_ERROR)
  {
	/* Reset the flags.  */
	ifp->flags = 0;

	/* Interface flags.  */
	if (IFRow.dwOperStatus == MIB_IF_OPER_STATUS_OPERATIONAL)
	  ifp->flags |= DLNA_IF_UP | DLNA_IF_RUNNING;

	/* Interface types.  */
	if (IFRow.dwType == MIB_IF_TYPE_LOOPBACK)
	  ifp->flags |= DLNA_IF_LOOPBACK;
	/* else if (pIFRow->dwType == MIB_IF_???)
	ifp->flags |= DLNA_IF_BROADCAST; */
	else if (IFRow.dwType == MIB_IF_TYPE_PPP)
	  ifp->flags |= DLNA_IF_POINTOPOINT;
  }
}
#else
static void pal_iphelper_if_flags(dlna_interface *ifp, PIP_ADAPTER_INFO pAdapter)
{
  if (pAdapter->flags == MIB_IF_TYPE_LOOPBACK) {
	ifp->flags |= DLNA_IF_LOOPBACK;
  }
  else {
	ifp->flags |= DLNA_IF_UP | DLNA_IF_RUNNING;
  }
}
#endif
static void pal_iphelper_mac_address(dlna_interface *ifp, PIP_ADAPTER_INFO pAdapter)
{
  if (pAdapter->AddressLength != DLNA_ETHER_ADDR_LEN)
	dlna_memset(ifp->mac, 0, DLNA_ETHER_ADDR_LEN);
  else
#if (WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) && WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_PHONE_APP))|| (WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)&& !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP))
	dlna_memcpy(ifp->mac, (slim_byte*)(pAdapter->Address), MAX_ADAPTER_ADDRESS_LENGTH);
#else
	dlna_memcpy(ifp->mac, (char*)(pAdapter->Address), (size_t)(pAdapter->AddressLength));
#endif
}

int pal_iphelper_if_list_init(struct pal_if_list *pList)
{
  pList->pListAddresses = (prefix_list*)dlna_memory_alloc(sizeof(prefix_list));
  pList->pListInterfaces = (interface_list*)dlna_memory_alloc(sizeof(prefix_list));
  ListInit(pList->pListAddresses);
  ListInit(pList->pListInterfaces);

  return 0;
}

int pal_iphelper_if_list_delete(struct pal_if_list *pList)
{
  dlna_prefix_container* pAddC, *ptAddC;
  dlna_interface_container* pIfC, *ptIfC;

  // Clear out the lists
  ListLoopForDel(pList->pListAddresses, pAddC, ptAddC)
  {
	// remove the container from the list and free it
	ListDelete(pList->pListAddresses, pAddC);
	pal_iphelper_address_free(pAddC);
  }

  ListLoopForDel(pList->pListInterfaces, pIfC, ptIfC)
  {
	// remove the container from the list and free it
	ListDelete(pList->pListInterfaces, pIfC);
	pal_iphelper_if_free(pIfC);
  }

  dlna_memory_free(pList->pListAddresses);
  dlna_memory_free(pList->pListInterfaces);

  return 0;
}

/////////////////////////////////////////////////////////////////////////////////////
// Address functions (add, delete, extract, create)
void pal_iphelper_address_free(dlna_prefix_container *pC)
{
  if (!(pC->bKeepContents))
  {
	dlna_memory_free(pC->self);
  }
  dlna_memory_free(pC);
}

int pal_iphelper_address_del(struct pal_kernel *pk, dlna_prefix* pAdd)
{
  /* Callback.  */
  if (pk->callback)
	(*pk->callback) (DLNA_NETIF_ADDRESS_DELETE, pk->arg, pAdd);

  return 0;
}
#if (WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) && WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_PHONE_APP))|| (WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)&& !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP))
// Change the MIB_IPADDRROW into a dlna_prefix structure
static dlna_prefix* pal_iphelper_address_create(slim_int in_ifIndex, dlna_ip_addr* in_ipAddr)
{
  dlna_prefix* pA = NULL;
  // Do not add 0.0.0.0 addresses, as these are invalid
  if (in_ipAddr)
  {
	pA = (dlna_prefix*)dlna_memory_alloc(sizeof(dlna_prefix));
	dlna_memset(pA, 0, sizeof(dlna_prefix));
	pA->ifindex = in_ifIndex;
	memcpy(pA->addr.fAddr, &(in_ipAddr->fAddr), 4);
  }
  return pA;
}

#else
static void pal_iphelper_address_extract(MIB_IPADDRROW* pAddr, dlna_prefix* pA)
{
  if (pA)
  {
	pA->ifindex = pAddr->dwIndex;
	pA->prefixlen = pal_masklen(&(pAddr->dwMask));
	memcpy(pA->addr.fAddr, &(pAddr->dwAddr), 4);
  }
}

static dlna_prefix* pal_iphelper_address_create(MIB_IPADDRROW* pAddr)
{
  dlna_prefix* pA = NULL;
  // Do not add 0.0.0.0 addresses, as these are invalid
  if (0 != pAddr->dwAddr)
  {
	pA = (dlna_prefix*)dlna_memory_alloc(sizeof(dlna_prefix));
	dlna_memset(pA, 0, sizeof(dlna_prefix));
	pal_iphelper_address_extract(pAddr, pA);
  }
  return pA;
}
#endif

static int pal_iphelper_address_list_add(prefix_list *pListAdd, dlna_prefix* pA)
{
  //Add this dlna_prefix to our list so we can keep track of it
  CREATE_CONTAINER(pC, pA, dlna_prefix);
  ListAdd(pListAdd, pC);

  return 0;
}


static int pal_iphelper_address_add(struct pal_kernel *pk, dlna_prefix* pA)
{
  /* Callback.  */
  if (pk->callback)
	(*pk->callback) (DLNA_NETIF_ADDRESS_ADD, pk->arg, pA);

  return 0;
}

/////////////////////////////////////////////////////////////////////////////////////
// Interface functions (add, delete, extract, create)
void pal_iphelper_if_free(dlna_interface_container* pC)
{
  dlna_interface* pIf = pC->self;
  if (!(pC->bKeepContents))
  {
	dlna_memory_free(pIf->name);
	dlna_memory_free(pIf->desc);
	dlna_memory_free(pIf);
  }
  dlna_memory_free(pC);
}

int pal_iphelper_if_del(struct pal_kernel *pk, dlna_interface* pIf)
{
  /* Callback.  */
  if (pk->callback)
	(*pk->callback) (DLNA_NETIF_IF_DELETE, pk->arg, pIf);

  return 0;
}

static dlna_interface* pal_iphelper_if_alloc()
{
  dlna_interface* pIf = (dlna_interface*)dlna_memory_alloc(sizeof(dlna_interface));
  dlna_memset(pIf, 0, sizeof(dlna_interface));
  return pIf;
}
#if (WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) && WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_PHONE_APP))|| (WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)&& !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP))
/*Generate random unique MAC address of 00:00:rr:rr:rr:rr*/
static slim_int ifIndex = 1;

static slim_word generateRandomMAC()
{
  slim_word fixNum = 429496729;
  ifIndex++;
  return dlna_random(fixNum) & 0x0000FFFFFFFF;
}
#else
static void pal_iphelper_if_create_mac_from_guid(dlna_interface* pIf)
{
  static slim_char strDelim[] = "{}-";
  HW_PROFILE_INFOA hpi;

  slim_char strStripped[HW_PROFILE_GUIDLEN];
  slim_char* p;
  size_t nLen = 0;
  slim_char* token;
  slim_char c[3];
  slim_char* strGUID = hpi.szHwProfileGuid;

  int i = 0;
  if (NULL == strGUID)
	return;

  if (!GetCurrentHwProfileA(&hpi))
	return;

  p = strStripped;
  token = strtok(strGUID, strDelim);

  while (NULL != token)
  {
	nLen = strlen(token);
	strncpy(p, token, nLen);
	p += nLen;
	token = strtok(NULL, strDelim);
  }

  *p = '\0';
  p = strStripped;
  nLen = strlen(strStripped);
  c[2] = '\0';

  while (i < DLNA_ETHER_ADDR_LEN && (p < strStripped + nLen))
  {
	// read each pair of hexidecimal characters and turn them into a number (byte)
	int nRead;
	c[0] = *(p++);
	c[1] = *(p++);
	sscanf(c, "%x", &nRead);
	pIf->mac[i++] = nRead;
  }
}
#endif

static dlna_interface* pal_iphelper_if_create_loopback()
{
  static slim_char s_szName[] = "Loopback";
  static slim_char s_szDesc[] = "Loopback Interface";

  dlna_interface* pIf = pal_iphelper_if_alloc();
  pIf->name = _strdup(s_szName);
  pIf->ifindex = INTERFACE_LOOPBACK_INDEX_DEFAULT;
  pIf->desc = _strdup(s_szDesc);

  // Need to generate a unique-ish mac id based on the hardware profile
#if (_WIN32_WINNT <= 0x0602 /*_WIN32_WINNT_WIN8*/)
  pal_iphelper_if_create_mac_from_guid(pIf);
#else
  slim_word randomMAC = generateRandomMAC();
  dlna_snprintf(pIf->mac, MAX_ADAPTER_ADDRESS_LENGTH, SLIM_T("%d"), randomMAC);
#endif
  pIf->flags = DLNA_IF_LOOPBACK;

  return pIf;
}

// Change the PIP_ADAPTER_INFO into a dlna_interface structure
static void pal_iphelper_if_extract(PIP_ADAPTER_INFO pAdapter, dlna_interface* pIf)
{
  if (pIf)
  {
	pIf->name = _strdup(pAdapter->AdapterName);
	pIf->ifindex = (int)pAdapter->Index;
	pIf->desc = _strdup(pAdapter->Description);
	pal_iphelper_mac_address(pIf, pAdapter);
	pal_iphelper_if_flags(pIf, pAdapter);
	DLNA_LOG(DLNA_LOG_PEER_NETIF, DLNA_LOG_LEVEL_DEBUG, "--name:%s, ifindex:%d, desc:%s, pAdapter->Address:%s, mac:%s--------", pIf->name, pIf->ifindex, pIf->desc, pAdapter->Address, pIf->mac);
  }
}

static dlna_interface* pal_iphelper_if_create(PIP_ADAPTER_INFO pAdapter)
{
  dlna_interface* pIf = pal_iphelper_if_alloc();
  pal_iphelper_if_extract(pAdapter, pIf);
  return pIf;
}

static int pal_iphelper_if_list_add(interface_list *pListIf, dlna_interface* pIf)
{
  //Add this dlna_interface to our list so we can keep track of it
  CREATE_CONTAINER(pC, pIf, dlna_interface);
  ListAdd(pListIf, pC);

  return 0;
}

static dlna_interface* pal_iphelper_if_get_byindex(interface_list* pListIf, slim_int nIndex)
{
  dlna_interface_container* pIfC = NULL;
  dlna_interface* pIf = NULL;
  ListLoop(pListIf, pIfC)
  {
	if (nIndex == pIfC->self->ifindex)
	{
	  pIf = pIfC->self;
	  break;
	}
  }

  return pIf;
}

static void pal_iphelper_if_check_loopback(dlna_interface* pIf, dlna_prefix* pA)
{
  if (NULL == pIf || NULL == pA)
	return;

  //Check if this is a loopback interface
  if (INADDR_LOOPBACK == ntohl(*(u_long*)(pA->addr.fAddr)))
  {
	pIf->ifindex = pA->ifindex;
	pIf->flags = DLNA_IF_UP | DLNA_IF_RUNNING | DLNA_IF_LOOPBACK | DLNA_IF_MULTICAST;
  }
}



static int pal_iphelper_if_add(struct pal_kernel *pk, dlna_interface* pIf)
{
  /* Callback.  */
  if (pk->callback)
	(*pk->callback) (DLNA_NETIF_IF_ADD, pk->arg, pIf);

  return 0;
}

#if (WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) && WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_PHONE_APP))|| (WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)&& !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP))
slim_int pal_iphelper_run_scan(struct pal_if_list *pList)
{
  PIP_ADAPTER_INFO pAdapterInfo;
  DWORD ulOutBufLen;
  slim_char hostName[MAX_ADAPTER_DESCRIPTION_LENGTH] = "";
  WSADATA wsaData;
  WSAStartup(MAKEWORD(2, 2), &wsaData);
  slim_int dwError = 0;
  slim_int index = 0;
  struct in_addr addr;
  dlna_interface* pIf = NULL;
  dlna_interface_container* pIfC = NULL;
  dlna_ip_addr outAddr;
  dlna_prefix* pA = NULL;
   
  dwError = gethostname(hostName, MAX_ADAPTER_DESCRIPTION_LENGTH);
  HOSTENT *remoteHost = gethostbyname(hostName);
  if (remoteHost == NULL) {
	dwError = WSAGetLastError();
	if (dwError != 0) {
	  DLNA_LOG(DLNA_LOG_PEER_NETIF, DLNA_LOG_LEVEL_ERROR, "Function failed with error: %ld", dwError);
	 }
  }
  else {
	DLNA_LOG(DLNA_LOG_PEER_NETIF, DLNA_LOG_LEVEL_DEBUG, "host name :%s", remoteHost->h_name);
		
	if (remoteHost->h_addrtype == AF_INET)
	{
	  //For each IP create one MAC
	  while (remoteHost->h_addr_list[index] != 0) {
		addr.s_addr = *(u_long *)remoteHost->h_addr_list[index++];
		slim_word randomMAC = generateRandomMAC();
		ulOutBufLen = sizeof(IP_ADAPTER_INFO);
		pAdapterInfo = (IP_ADAPTER_INFO *)malloc(ulOutBufLen);

		dlna_memset(pAdapterInfo->Address, 0, MAX_ADAPTER_ADDRESS_LENGTH);
		dlna_snprintf(pAdapterInfo->Address, MAX_ADAPTER_ADDRESS_LENGTH, SLIM_T("%d"), randomMAC);
		pAdapterInfo->AddressLength = MAX_ADAPTER_ADDRESS_LENGTH;

		dlna_memset(pAdapterInfo->AdapterName, 0, MAX_ADAPTER_NAME_LENGTH);
		dlna_strcpy(pAdapterInfo->AdapterName, remoteHost->h_name);

		slim_char *ipAddress = inet_ntoa(addr);
		dlna_memset(pAdapterInfo->Description, 0, MAX_ADAPTER_DESCRIPTION_LENGTH);
		dlna_strcpy(pAdapterInfo->Description, ipAddress);
		DLNA_LOG(DLNA_LOG_PEER_NETIF, DLNA_LOG_LEVEL_DEBUG, "pAdapter->AdapterName:%s, IpAddress :%s", pAdapterInfo->AdapterName, pAdapterInfo->Description);
		pAdapterInfo->Index = ifIndex;
		pIf = pal_iphelper_if_create(pAdapterInfo);
		pal_iphelper_if_list_add(pList->pListInterfaces, pIf);
		if (pAdapterInfo) {
		  free(pAdapterInfo);
		  pAdapterInfo = slim_nil;
		}
	  }
	}
	
	// Now check for a loopback interface, if not, add one.
	pIf = pal_iphelper_if_get_byindex(pList->pListInterfaces, INTERFACE_LOOPBACK_INDEX_DEFAULT);
	if (NULL == pIf)
	{
	  pIf = pal_iphelper_if_create_loopback();
	  pal_iphelper_if_list_add(pList->pListInterfaces, pIf);
	}
    // Now add address interface 
	if (pList->pListInterfaces) {
	  ListLoop(pList->pListInterfaces, pIfC) {
		dwError = dlna_inet_aton(pIfC->self->desc, &outAddr);
		if (dwError == 0) {
		  DLNA_LOG(DLNA_LOG_PEER_NETIF, DLNA_LOG_LEVEL_ERROR, "Interface createion error for window phone");
		}
		pA = pal_iphelper_address_create(pIfC->self->ifindex, &outAddr);
		pal_iphelper_address_list_add(pList->pListAddresses, pA);
		DLNA_LOG(DLNA_LOG_PEER_NETIF, DLNA_LOG_LEVEL_DEBUG, "New Address Interface:%s added at index:%d", pA->addr.fAddr, pA->ifindex);
	  }
	}
  }
  return dwError;

}

#else
/* Get the adapter info via IP Helper */
int pal_iphelper_run_scan(struct pal_if_list *pList)
{
  PIP_ADAPTER_INFO pAdapterInfo;
  PIP_ADAPTER_INFO pAdapter = NULL;
  DWORD dwRetVal = 0;
  DWORD ulOutBufLen;
  PMIB_IPADDRTABLE pIPAddrTable;
  unsigned int i, nEntries;
  int nRetVal = 0;

  dlna_interface* pIf = NULL;

  ulOutBufLen = sizeof(IP_ADAPTER_INFO);
  pAdapterInfo = (IP_ADAPTER_INFO *)malloc(ulOutBufLen);

  // Make an initial call to GetAdaptersInfo to get
  // the necessary size into the ulOutBufLen variable
  dwRetVal = GetAdaptersInfo(pAdapterInfo, &ulOutBufLen);
  if (dwRetVal == ERROR_BUFFER_OVERFLOW)
  {
	free(pAdapterInfo);
	pAdapterInfo = (IP_ADAPTER_INFO *)dlna_memory_alloc(ulOutBufLen);
	dwRetVal = GetAdaptersInfo(pAdapterInfo, &ulOutBufLen);
  }

  if (dwRetVal == ERROR_SUCCESS)
  {
	// Now add each adapter
	pAdapter = pAdapterInfo;
	while (pAdapter)
	{
	  pIf = pal_iphelper_if_create(pAdapter);
	  pal_iphelper_if_list_add(pList->pListInterfaces, pIf);
	  pAdapter = pAdapter->Next;
	}
  }

  // Now check for a loopback interface, if not, add one.
  pIf = pal_iphelper_if_get_byindex(pList->pListInterfaces, INTERFACE_LOOPBACK_INDEX_DEFAULT);
  if (NULL == pIf)
  {
	pIf = pal_iphelper_if_create_loopback();
	pal_iphelper_if_list_add(pList->pListInterfaces, pIf);
  }

  // Clean up memory
  free(pAdapterInfo);

  // Always scan the ip address table (loopback addresses dont have interfaces reported by Windows)
  if (TRUE)
  {
	// Now scan the IP Address Table and add those as well
	ulOutBufLen = sizeof(MIB_IPADDRTABLE);
	pIPAddrTable = (MIB_IPADDRTABLE*)malloc(ulOutBufLen);

	// Make an initial call to GetIpAddrTable to get the
	// necessary size into the dwSize variable
	dwRetVal = GetIpAddrTable(pIPAddrTable, &ulOutBufLen, 0);
	if (dwRetVal == ERROR_INSUFFICIENT_BUFFER) {
	  free(pIPAddrTable);
	  pIPAddrTable = (MIB_IPADDRTABLE *)malloc(ulOutBufLen);
	  dwRetVal = GetIpAddrTable(pIPAddrTable, &ulOutBufLen, 0);
	}

	if (dwRetVal == NO_ERROR)
	{
	  dlna_interface* pIfLoopback = pal_iphelper_if_get_byindex(pList->pListInterfaces, INTERFACE_LOOPBACK_INDEX_DEFAULT);

	  // Now add each IP address
	  nEntries = (unsigned int)(pIPAddrTable->dwNumEntries);
	  for (i = 0; i<nEntries; i++)
	  {
		dlna_prefix* pA = pal_iphelper_address_create(&(pIPAddrTable->table[i]));
		if (pA)
		{
		  pal_iphelper_if_check_loopback(pIfLoopback, pA);
		  pal_iphelper_address_list_add(pList->pListAddresses, pA);
		}
	  }
	}
	else
	{
	  DLNA_LOG(DLNA_LOG_PEER_NETIF, DLNA_LOG_LEVEL_ERROR, "Cannot get IP address table.");
	  nRetVal = -1;
	}

	free(pIPAddrTable);
  }
  return nRetVal;
}
#endif //WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) && WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_PHONE_APP)

static BOOLEAN pal_iphelper_interface_contains_address(dlna_interface_container* pIfC, dlna_prefix_container* pAddC)
{
  dlna_interface* pIf = pIfC->self;
  dlna_prefix* pAdd = pAddC->self;

  if (pAdd->ifindex == pIf->ifindex)
	return TRUE;

  return FALSE;
}


static BOOLEAN pal_iphelper_compare_interfaces(dlna_interface_container* pIfC1, dlna_interface_container* pIfC2)
{
  dlna_interface* pIf1 = pIfC1->self;
  dlna_interface* pIf2 = pIfC2->self;

  // Verify each component (except description) of the interface. If anything is not the same, return FALSE

  // Check index
  if (pIf1->ifindex != pIf2->ifindex)
	return FALSE;

  // Check flags
  if (pIf1->flags != pIf2->flags)
	return FALSE;

  // Check mac address
  if (strcmp(pIf1->mac, pIf2->mac) != 0)
	return FALSE;

  // Check name
  if (strcmp(pIf1->name, pIf2->name) != 0)
	return FALSE;

  return TRUE;
}

static BOOLEAN pal_iphelper_compare_addresses(dlna_prefix_container* pAddC1, dlna_prefix_container* pAddC2)
{
  dlna_prefix* pAdd1 = pAddC1->self;
  dlna_prefix* pAdd2 = pAddC2->self;

  // Verify each component of the address. If anything is not the same, return FALSE

  // Check index
  if (pAdd1->ifindex != pAdd2->ifindex)
	return FALSE;

  // Check prefix length
  if (pAdd1->prefixlen != pAdd2->prefixlen)
	return FALSE;

  // Check address type
  if (pAdd1->addr.fType != pAdd2->addr.fType)
	return FALSE;

  // Check address
  if (strcmp(pAdd1->addr.fAddr, pAdd2->addr.fAddr) != 0)
	return FALSE;

  return TRUE;
}

// Compare both lists and update the old one to match the new one
static BOOLEAN pal_iphelper_compare_update_lists(struct pal_kernel *pk, struct pal_if_list *pNewList)
{
  BOOLEAN bSame = TRUE;

  // Compare each element of each list to see what was added or removed
  prefix_list* pOldAddrL = ADDRESSES(pk);
  prefix_list* pNewAddrL = pNewList->pListAddresses;
  interface_list* pOldIfL = INTERFACES(pk);
  interface_list* pNewIfL = pNewList->pListInterfaces;

  dlna_prefix_container *pOldAddC, *pNewAddC, *ptmpAdd;
  dlna_interface_container *pOldIfC, *pNewIfC, *ptmpIf;

  BOOLEAN bFound = FALSE;

  // Sanity check
  if (&(INFO(pk)->if_list) == pNewList)
	return TRUE;

  // First remove any interface from the list that is in the old but not the new
  ListLoopForDel(pOldIfL, pOldIfC, ptmpIf)
  {
	bFound = FALSE;
	//Now check to see if the old interface is found in the list of new interfaces
	ListLoop(pNewIfL, pNewIfC)
	{
	  if (pal_iphelper_compare_interfaces(pOldIfC, pNewIfC))
	  {
		bFound = TRUE;
		break;
	  }
	}

	if (!bFound)
	{
	  bSame = FALSE;
	  // In this case, the interface was not found and should be deleted.
	  // We must delete all addresses associated with this interface first.
	  ListLoopForDel(pOldAddrL, pOldAddC, ptmpAdd)
	  {
		if (pal_iphelper_interface_contains_address(pOldIfC, pOldAddC))
		{
		  ListDelete(pOldAddrL, pOldAddC);
		  pal_iphelper_address_del(pk, pOldAddC->self);
		  pal_iphelper_address_free(pOldAddC);
		}
	  }

	  // Now delete the interface and tell the api about it.
	  ListDelete(pOldIfL, pOldIfC);
	  pal_iphelper_if_del(pk, pOldIfC->self);
	  pal_iphelper_if_free(pOldIfC);
	}
  }

  // Now go through the list of old addresses to see if any need to be deleted
  ListLoopForDel(pOldAddrL, pOldAddC, ptmpAdd)
  {
	bFound = FALSE;
	ListLoop(pNewAddrL, pNewAddC)
	{
	  if (pal_iphelper_compare_addresses(pOldAddC, pNewAddC))
	  {
		bFound = TRUE;
		break;
	  }
	}

	if (!bFound)
	{
	  bSame = FALSE;
	  // In this case, the address was not found and should be deleted.
	  ListDelete(pOldAddrL, pOldAddC);
	  pal_iphelper_address_del(pk, pOldAddC->self);
	  pal_iphelper_address_free(pOldAddC);
	}
  }

  // Now go through the list of new interfaces and add any new ones
  ListLoop(pNewIfL, pNewIfC)
  {
	bFound = FALSE;
	ListLoop(pOldIfL, pOldIfC)
	{
	  if (pal_iphelper_compare_interfaces(pNewIfC, pOldIfC))
	  {
		bFound = TRUE;
		break;
	  }
	}

	if (!bFound)
	{
	  bSame = FALSE;
	  // Not found, add this interface
	  pal_iphelper_if_add(pk, pNewIfC->self);
	  pal_iphelper_if_list_add(pOldIfL, pNewIfC->self);

	  // Remember to keep this contents since they were added to the pal_kernel list
	  pNewIfC->bKeepContents = TRUE;
	}
  }

  // Now go through the list of new addresses and add any new ones
  ListLoop(pNewAddrL, pNewAddC)
  {
	bFound = FALSE;
	ListLoop(pOldAddrL, pOldAddC)
	{
	  if (pal_iphelper_compare_addresses(pNewAddC, pOldAddC))
	  {
		bFound = TRUE;
		break;
	  }
	}

	if (!bFound)
	{
	  bSame = FALSE;
	  // Not found, add this interface
	  pal_iphelper_address_add(pk, pNewAddC->self);
	  pal_iphelper_address_list_add(pOldAddrL, pNewAddC->self);

	  // Remember to keep this contents since they were added to the pal_kernel list
	  pNewAddC->bKeepContents = TRUE;
	}
  }

  return bSame;
}

// Compare the given list with the pk->info structure's list
static void pal_iphelper_push_lists(struct pal_kernel *pk, struct pal_if_list *pNewList)
{
  if (&(INFO(pk)->if_list) == pNewList)
  {
	// In this case, we are adding for the first time, add everything
	dlna_interface_container* pIfC;
	dlna_prefix_container* pAddC;

	ListLoop(INTERFACES(pk), pIfC)
	  pal_iphelper_if_add(pk, pIfC->self);
	ListLoop(ADDRESSES(pk), pAddC)
	  pal_iphelper_address_add(pk, pAddC->self);
  }
  else
  {
	BOOLEAN bSame = pal_iphelper_compare_update_lists(pk, pNewList);

	// Sanity check to see that the lists are the same if they were different originally
#ifdef _DEBUG
	if (!bSame && (pal_iphelper_compare_update_lists(pk, pNewList) == FALSE))
	{
	  //DebugBreak();
	  DLNA_LOG(DLNA_LOG_PEER_NETIF, DLNA_LOG_LEVEL_ERROR, "Old and New interface lists did not update properly!");
	}
#endif
  }
}

// Run the scan then push the lists to the API
int pal_iphelper_scan(struct pal_kernel *pk, struct pal_if_list* pList)
{
  int nRetVal = pal_iphelper_run_scan(pList);
  if (0 == nRetVal)
	pal_iphelper_push_lists(pk, pList);

  return nRetVal;
}

static int pal_iphelper_timer_notify_addr_change(void* in_arg);

void pal_iphelper_cancel_timer_event(struct pal_kernel* pk)
{
  EVENT_CANCEL(INFO(pk)->e_timer, pk->em);
}

void pal_iphelper_register_timer_event(struct pal_kernel* pk)
{
  //Add this function as a timer event again
  INFO(pk)->e_timer = DLNA_INVALID_PROGRESS_HANDLE;
#if (_WIN32_WINNT <= 0x0602 /*_WIN32_WINNT_WIN8*/)
  EVENT_ADD_TIMER(INFO(pk)->e_timer, pk->em, pal_iphelper_timer_notify_addr_change, pk, 5);
#else
  //For windows 8.1 address change notification is not handled for tablet and phone.
#endif
}

int pal_iphelper_reregister_notify_event(struct pal_kernel* pk, BOOLEAN bReReg)
{
  struct pal_kernel_info* info = INFO(pk);

  if (bReReg)
  {
	// Reset the event
#ifndef _WIN32_WCE
	WSAResetEvent(info->zOverlapped.hEvent);
#endif
  }
  else
  {
	// Create the events
	info->hNotify = WSACreateEvent();
#ifndef _WIN32_WCE
	info->zOverlapped.hEvent = WSACreateEvent();
#else
	info->zOverlapped.hEvent = NULL;
#endif
  }
#if (_WIN32_WINNT >= 0x0602 /*_WIN32_WINNT_WIN8*/)
  //For window 8.1 no address change notification, we are handling address i.e MAC hard coded.
#else
  if (NotifyAddrChange(&(info->hNotify), &(info->zOverlapped)) != NO_ERROR)
  {
	if (WSAGetLastError() != WSA_IO_PENDING)
	{
	  DLNA_LOG(DLNA_LOG_PEER_NETIF, DLNA_LOG_LEVEL_ERROR, "NotifyAddrChange error...%d", WSAGetLastError());
	  return -1;
	}
  }
#endif
  return 0;
}

int pal_iphelper_register_notify_event(struct pal_kernel* pk)
{
  return pal_iphelper_reregister_notify_event(pk, FALSE);
}


// Timer event to see if there was an interface or address change
static int pal_iphelper_timer_notify_addr_change(void* in_arg)
{
  struct pal_kernel* pk = (struct pal_kernel*) in_arg;
  struct pal_kernel_info* pInfo = INFO(pk);
  int nRetVal = 0;

#ifndef _WIN32_WCE
  if (WaitForSingleObject(pInfo->zOverlapped.hEvent, 0) == WAIT_OBJECT_0)
  {
	struct pal_if_list list;

	// Re register for address change notification
	pal_iphelper_reregister_notify_event(pk, TRUE);

	// Something changed if this occurs, run a scan and update the lists
	pal_iphelper_if_list_init(&list);
	nRetVal = pal_iphelper_scan(pk, &list);
	pal_iphelper_if_list_delete(&list);
  }

  //Add this function as a timer event again
  pal_iphelper_register_timer_event(pk);
#endif

  return nRetVal;
}
