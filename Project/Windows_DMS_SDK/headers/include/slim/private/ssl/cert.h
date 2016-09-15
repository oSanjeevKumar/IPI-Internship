/*
	cert.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/ssl/cert.h 192   06/02/08 22:07 Nagamati $ */

#ifndef SLIM_CERT_H_PRIVATE
#define SLIM_CERT_H_PRIVATE

#include <slim/libcore.h>
#include <slim/private/crypt/crypt.h>

SLIM_BEGIN_C_LINKAGE

#ifdef SLIM_CONFIG_USE_SSL

/*================
	Certificate
 ================*/

#define TCert_Ptr(self)		((self)->fPtr)
#define TCert_Len(self)		((self)->fLen)

#define TCert_HasBasicConstraints(self)			((self)->fIsCA == SLIM_CERT_BC_NONE ? slim_false : slim_true)
#define TCert_IsCA(self)						((self)->fIsCA == SLIM_CERT_BC_CA ? slim_true : slim_false)
#define TCert_IsEndEntity(self)					((self)->fIsCA == SLIM_CERT_BC_NOT_CA)

#define TCert_PeekKeyUsage(self)				((self)->fKeyUsage)
#define TCert_PeekExtKeyUsage(self)				((self)->fExtKeyUsage)
#define TCert_CRLDistPoints(self)				((self)->fCRLDPNum)
#define TCert_PeekCRLDistPoint(self, i)			(&((self)->fCRLDistPoint[i]))
#define TCert_PeekPathLength(self)				((self)->fPathDepth)

#define TCertDN_IsSame(self, dn)			(TCertDN_IsSameSS((self), (dn)->fData, (dn)->fLen))
#define TCert_IsRoot(self)					(TCertDN_IsSame(&(self)->fIssuer, &(self)->fSubject))
#define TCert_IsSameIssuer(cert1, cert2)	(TCertDN_IsSame(&(cert1)->fIssuer, &(cert2)->fIssuer))
#define TCert_IsSameSubject(cert1, cert2)	(TCertDN_IsSame(&(cert1)->fSubject, &(cert2)->fSubject))
#define TCert_IsSame(cert1, cert2)			(TCert_IsSameIssuer(cert1, cert2) && TCert_IsSameSubject(cert1, cert2))


/*================================
	Certificate Revocation List
 ================================*/

#define TCRL_Ptr(self)		((self)->fPtr)
#define TCRL_Len(self)		((self)->fLen)

#define TCRL_PeekVersion(self)			((self)->fVersion)
#define TCRL_PeekSignAlgo(self)			((self)->fSignAlgo)
#define TCRL_PeekThisUpdate(self, time)	((*(time)) = (self)->fThisUpdate)
#define TCRL_PeekNextUpdate(self, time)	((*(time)) = (self)->fNextUpdate)


/*=====================
	Certificate List
 =====================*/

/*
	Order
		Array[0]     = Server (or Client) Cert,
		Array[1]     = CA Cert,
		...          = CA Cert,
		Array[len-1] = Root (or CA) Cert

	where len = TCertList_Length().
*/

struct TCertListItem_ {
	slim_int fFlag;
	slim_int fVerificationResults;
	union {
		struct {
			slim_int fStoreType;
			slim_opaque fID;
		} Rec;
		struct {
			slim_handle fHdl;
			slim_int fLen;
		} Hdl;
	} u;
};
typedef struct TCertListItem_ TCertListItem;

#define TCertList_Lock(self)		(iTCertList *)slim_handle_lock((slim_handle)self)
#define TCertList_Unlock(self)		slim_handle_unlock((slim_handle)self)
#define TCertList_Locate(self)		(iTCertList *)slim_handle_locate((slim_handle)self)
#define TCertList_Unlocate(self)	slim_handle_unlocate((slim_handle)self)


/*============================
	Client Certificate List
 ============================*/

struct TClientCertListItem_ {
	slim_int fVerificationResults;
	TCertList fCertPath;
};
typedef struct TClientCertListItem_ TClientCertListItem;

#define TClientCertList_CertPathDepth(self, index)	TCertList_Length(TClientCertList_CertPath(self, index))
#define TClientCertList_CertPathLength(self, index)	(TCertList_Length(TClientCertList_CertPath(self, index)))

#define TClientCertList_BeginDecodeCert(self, index, depth, cert)	TCertList_BeginDecode(TClientCertList_CertPath(self, index), depth, cert)
#define TClientCertList_EndDecodeCert(self, index, cert)			TCertList_EndDecode(TClientCertList_CertPath(self, index), cert)
#define TClientCertList_BeginDecodeClientCert(self, index, cert)	TClientCertList_BeginDecodeCert(self, index, 0, cert)
#define TClientCertList_EndDecodeClientCert(self, index, cert)		TClientCertList_EndDecodeCert(self, index, cert)
#define TClientCertList_BeginDecodeRootCert(self, index, cert)		TClientCertList_BeginDecodeCert(self, index, TClientCertList_CertPathLength(self, index)-1, cert)
#define TClientCertList_EndDecodeRootCert(self, index, cert)		TClientCertList_EndDecodeCert(self, index, cert)


/*=========================
	Certificate Database
 =========================*/

/* dummy functinos */
#else
#define TCert_Ptr(self)							(slim_nil)
#define TCert_Len(self)							(0)
#define TCertDN_PeekName(self, out_name)		(SLIM_E_GENERIC)
#define TCert_HasBasicConstraints(self)			(slim_false)
#define TCert_IsCA(self)						(slim_false)
#define TCert_IsEndEntity(self)					(slim_false)
#define TCert_PeekKeyUsage(self)				(0)
#define TCert_PeekExtKeyUsage(self)				(0)
#define TCert_CRLDistPoints(self)				(0)
#define TCert_PeekCRLDistPoint(self, i)			(slim_nil)
#define TCert_PeekPathLength(self)				(0)
#define TCert_BeginPeekSubjAltName(self, cookie, type)		((void)0)
#define TCert_PeekSubjAltName(self, cookie, str)			(-1)
#define TCert_EndPeekSubjAltName(self, cookie)				((void)0)
#define TCert_IsRoot(self)						(slim_false)
#define TCert_IsSameIssuer(cert1, cert2)		(slim_false)
#define TCert_IsSameSubject(cert1, cert2)		(slim_false)
#define TCert_IsSame(cert1, cert2)				(slim_false)
#define TCert_Verify(self, in_issuer, in_flag)	(SLIM_CERT_E_VERIFY)
#define TCert_Check(self, in_rec_flag, in_check_flags, in_depth, in_name, in_match_len, in_time)	(SLIM_CERT_E_VERIFY)
#define CRL_New()														(slim_nil)
#define TCRL_Delete(self)												((void)0)
#define TCRL_Ptr(self)													(slim_nil)
#define TCRL_Len(sefl)													(0)
#define TCRL_PeekVersion(self)											(1)
#define TCRL_PeekSignAlgo(self)											(SLIM_BER_OID_ALGO_UNKNOWN)
#define TCRL_PeekIssuerRDN(self, in_attr, inout_offset, out_str)		(-1)
#define TCRL_PeekThisUpdate(self, time)									((void)0)
#define TCRL_PeekNextUpdate(self, time)									((void)0)
#define TCRL_Decode(self, in_der, in_len)								(SLIM_CRL_E_DECODE)
#define TCRL_Verify(self, in_cert, in_time)								(SLIM_CRL_E_VERIFY)
#define TCRL_IsCertRevoked(self, in_ser_no, out_time)					(slim_false)
#define TCertList_SerializeSize(self)									(0)
#define TCertList_Serialize(self)										(slim_nil)
#define TCertList_Deserialize(self, in_handle)							(slim_false)
#define TCertList_Unserialize(self, in_handle)							TCertList_Deserialize((self),(in_hendle))
#define TCertList_ConstructChain(self, prkey)							(slim_false)
#define TCertList_VerificationResults(self, in_index)					(SLIM_CERT_E_OK)
#define TCertList_SetVerificationResults(self, in_index, in_results)	((void)0)
#define TClientCertList_BeginDecodeCert(self, index, depth, cert)		TCertList_BeginDecode(TClientCertList_CertPath(self, index), depth, cert)
#define TClientCertList_EndDecodeCert(self, index, cert)				TCertList_EndDecode(TClientCertList_CertPath(self, index), cert)
#define TClientCertList_BeginDecodeClientCert(self, index, cert)		TClientCertList_BeginDecodeCert(self, index, 0, cert)
#define TClientCertList_EndDecodeClientCert(self, index, cert)			TClientCertList_EndDecodeCert(self, index, cert)
#define TClientCertList_BeginDecodeRootCert(self, index, cert)			TClientCertList_BeginDecodeCert(self, index, TClientCertList_CertPathLength(self, index)-1, cert)
#define TClientCertList_EndDecodeRootCert(self, index, cert)			TClientCertList_EndDecodeCert(self, index, cert)
#endif /* SLIM_CONFIG_USE_SSL */

SLIM_END_C_LINKAGE

#endif /* SLIM_CERT_H_PRIVATE */
