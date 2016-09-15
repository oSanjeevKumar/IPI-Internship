#ifndef NETIF_IPHELPER_H
#define NETIF_IPHELPER_H

#include <dlna_peer.h>

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) && !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

#define MAX_ADAPTER_DESCRIPTION_LENGTH  128 // arb.
#define MAX_ADAPTER_NAME_LENGTH         256 // arb.
#define MAX_ADAPTER_ADDRESS_LENGTH      6   // arb.
#define DEFAULT_MINIMUM_ENTITIES        32  // arb.
#define MAX_HOSTNAME_LEN                128 // arb.
#define MAX_DOMAIN_NAME_LEN             128 // arb.
#define MAX_SCOPE_ID_LEN                256 // arb.
#define MAX_DHCPV6_DUID_LENGTH          130 // RFC 3315.
#define MAX_DNS_SUFFIX_STRING_LENGTH    256

#define MAXLEN_PHYSADDR 8
#define MAXLEN_IFDESCR 256
#define MAX_INTERFACE_NAME_LEN 256

typedef struct IP_ADAPTER_INFO {
	struct IP_ADAPTER_INFO* Next;
	DWORD ComboIndex;
	char AdapterName[MAX_ADAPTER_NAME_LENGTH + 4];
	char Description[MAX_ADAPTER_DESCRIPTION_LENGTH + 4];
	UINT AddressLength;
	BYTE Address[MAX_ADAPTER_ADDRESS_LENGTH];
	DWORD Index;
	UINT Type;
	UINT DhcpEnabled;
	//PIP_ADDR_STRING CurrentIpAddress;
	//IP_ADDR_STRING IpAddressList;
	//IP_ADDR_STRING GatewayList;
	//IP_ADDR_STRING DhcpServer;
	//BOOL HaveWins;
	//IP_ADDR_STRING PrimaryWinsServer;
	//IP_ADDR_STRING SecondaryWinsServer;
	time_t LeaseObtained;
	time_t LeaseExpires;
	slim_word flags;
} IP_ADAPTER_INFO, *PIP_ADAPTER_INFO;

typedef enum _INTERNAL_IF_OPER_STATUS {
	IF_OPER_STATUS_NON_OPERATIONAL = 0,
	IF_OPER_STATUS_UNREACHABLE = 1,
	IF_OPER_STATUS_DISCONNECTED = 2,
	IF_OPER_STATUS_CONNECTING = 3,
	IF_OPER_STATUS_CONNECTED = 4,
	IF_OPER_STATUS_OPERATIONAL = 5,
} INTERNAL_IF_OPER_STATUS;

#define MIB_IF_OPER_STATUS_OPERATIONAL  IF_OPER_STATUS_OPERATIONAL
#define MIB_IF_TYPE_PPP                 23
#define MIB_IF_TYPE_LOOPBACK            24

typedef struct _MIB_IFROW {
	WCHAR wszName[MAX_INTERFACE_NAME_LEN];
	ULONG dwIndex;
	UINT16 dwType;
	DWORD dwMtu;
	DWORD dwSpeed;
	DWORD dwPhysAddrLen;
	UCHAR bPhysAddr[MAXLEN_PHYSADDR];
	DWORD dwAdminStatus;
	INTERNAL_IF_OPER_STATUS dwOperStatus;
	DWORD dwLastChange;
	DWORD dwInOctets;
	DWORD dwInUcastPkts;
	DWORD dwInNUcastPkts;
	DWORD dwInDiscards;
	DWORD dwInErrors;
	DWORD dwInUnknownProtos;
	DWORD dwOutOctets;
	DWORD dwOutUcastPkts;
	DWORD dwOutNUcastPkts;
	DWORD dwOutDiscards;
	DWORD dwOutErrors;
	DWORD dwOutQLen;
	DWORD dwDescrLen;
	UCHAR bDescr[MAXLEN_IFDESCR];
} MIB_IFROW, *PMIB_IFROW;

#endif //WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) && !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

struct _dlna_prefix_container
{
  dlna_prefix* self;
  struct _dlna_prefix_container* next;
  struct _dlna_prefix_container* prev;
  BOOLEAN bKeepContents;
};
typedef struct _dlna_prefix_container dlna_prefix_container;

struct _dlna_interface_container
{
  dlna_interface* self;
  struct _dlna_interface_container* next;
  struct _dlna_interface_container* prev;
  BOOLEAN bKeepContents;
};
typedef struct _dlna_interface_container dlna_interface_container;

#define CREATE_CONTAINER(P,Q,T) T##_container* P = ((T##_container*) dlna_memory_alloc(sizeof(T##_container))); P->self = Q; P->next = NULL; P->prev = NULL; P->bKeepContents = FALSE
#define INFO(P) ((struct pal_kernel_info*) (P->info))
#define ADDRESSES(P) (INFO(P)->if_list.pListAddresses)
#define INTERFACES(P) (INFO(P)->if_list.pListInterfaces)

typedef List(dlna_prefix_container*) prefix_list;
typedef List(dlna_interface_container*) interface_list;

struct pal_if_list
{
  /* Interface and address information */
  prefix_list* pListAddresses;
  interface_list* pListInterfaces;
};

struct pal_kernel_info
{
	/* PAL kernel back-pointer.  */
	struct pal_kernel *pk;

	/* PAL contents back-pointer.  */
	struct pal_contents_manager *pc;

  // Current list of interfaces and addresses
  struct pal_if_list if_list;

  // Handle to the timer event
  dlna_progress_handle e_timer;

	// Address/Interface change notification
	HANDLE		hNotify;
	OVERLAPPED	zOverlapped;
};



#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Prototype.  */
int pal_iphelper_if_list_init( struct pal_if_list *pList );
int pal_iphelper_if_list_delete( struct pal_if_list *pList );

void pal_iphelper_address_free( dlna_prefix_container *pC );
void pal_iphelper_if_free( dlna_interface_container* pC );

int pal_iphelper_scan ( struct pal_kernel *pk, struct pal_if_list *pList );
void pal_iphelper_cancel_timer_event( struct pal_kernel* pk );
void pal_iphelper_register_timer_event( struct pal_kernel* pk );
int pal_iphelper_register_notify_event( struct pal_kernel* pk );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NETIF_IPHELPER_H */
