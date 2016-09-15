/*
	asn1schm.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/ssl/asn1schm.h 6     06/03/07 18:16 Nagamati $ */

/* DO NOT EDIT! This file is generated automagically. */

#ifndef SLIM_ASN1SCHM_H
#define SLIM_ASN1SCHM_H

SLIM_BEGIN_C_LINKAGE

/*========== ASN1 ========== */
#define SLIM_ASN1SCHEMAID_ASN1_START 0

/* unknown */
#define SLIM_ASN1_UNKNOWN (SLIM_ASN1SCHEMAID_ASN1_START + 0)

/* primitives */
#define SLIM_ASN1_BOOLEAN (SLIM_ASN1SCHEMAID_ASN1_START + 1)
#define SLIM_ASN1_INTEGER (SLIM_ASN1SCHEMAID_ASN1_START + 2)
#define SLIM_ASN1_BIT_STRING (SLIM_ASN1SCHEMAID_ASN1_START + 3)
#define SLIM_ASN1_OCTET_STRING (SLIM_ASN1SCHEMAID_ASN1_START + 4)
#define SLIM_ASN1_NULL (SLIM_ASN1SCHEMAID_ASN1_START + 5)
#define SLIM_ASN1_OBJECT_IDENTIFIER (SLIM_ASN1SCHEMAID_ASN1_START + 6)
#define SLIM_ASN1_OBJECT_DESCRIPTOR (SLIM_ASN1SCHEMAID_ASN1_START + 7)
#define SLIM_ASN1_EXTERNAL (SLIM_ASN1SCHEMAID_ASN1_START + 8)
#define SLIM_ASN1_REAL (SLIM_ASN1SCHEMAID_ASN1_START + 9)
#define SLIM_ASN1_ENUM (SLIM_ASN1SCHEMAID_ASN1_START + 10)
#define SLIM_ASN1_UTF8_STRING (SLIM_ASN1SCHEMAID_ASN1_START + 11)
#define SLIM_ASN1_NUMERIC_STRING (SLIM_ASN1SCHEMAID_ASN1_START + 12)
#define SLIM_ASN1_PRINTABLE_STRING (SLIM_ASN1SCHEMAID_ASN1_START + 13)
#define SLIM_ASN1_T61_STRING (SLIM_ASN1SCHEMAID_ASN1_START + 14)
#define SLIM_ASN1_VIDEO_STRING (SLIM_ASN1SCHEMAID_ASN1_START + 15)
#define SLIM_ASN1_IA5_STRING (SLIM_ASN1SCHEMAID_ASN1_START + 16)
#define SLIM_ASN1_UTC_TIME (SLIM_ASN1SCHEMAID_ASN1_START + 17)
#define SLIM_ASN1_GENERAL_TIME (SLIM_ASN1SCHEMAID_ASN1_START + 18)
#define SLIM_ASN1_GRAPHIC_STRING (SLIM_ASN1SCHEMAID_ASN1_START + 19)
#define SLIM_ASN1_VISIBLE_STRING (SLIM_ASN1SCHEMAID_ASN1_START + 20)
#define SLIM_ASN1_GENERAL_STRING (SLIM_ASN1SCHEMAID_ASN1_START + 21)
#define SLIM_ASN1_UNIVERSAL_STRING (SLIM_ASN1SCHEMAID_ASN1_START + 22)
#define SLIM_ASN1_BMP_STRING (SLIM_ASN1SCHEMAID_ASN1_START + 23)

/*
	AlgorithmIdentifier ::= SEQUENCE {
	  algorithm   OBJECT IDENTIFIER,
	  parameters  ANY DEFINED BY algorithm OPTIONAL
	}
	-- contains a value of the type
	-- registered for use with the
	-- algorithm object identifier value
*/
struct TA1AlgoID_ {
	TASN1Object fSEQUENCE;
	TASN1Object fAlgorithm;
	TASN1Object fParameters;
};
typedef struct TA1AlgoID_ TA1AlgoID;
#define SLIM_ASN1_AlgorithmIdentifier (SLIM_ASN1SCHEMAID_ASN1_START + 25)

/*
	DigestInfo ::= SEQUENCE {
	  digestAlgorithm  AlgorithmIdentifier,
	  digest           OCTET STRING
	}
*/
struct TA1DigestInfo_ {
	TASN1Object fSEQUENCE;
	TA1AlgoID fDigestAlgorithm;
	TASN1Object fDigest;
};
typedef struct TA1DigestInfo_ TA1DigestInfo;
#define SLIM_ASN1_DigestInfo (SLIM_ASN1SCHEMAID_ASN1_START + 28)

/*
	Time ::= CHOICE {
	  uTCTime      UTCTime,
	  generalizedTime  GeneralizedTime
	}
*/
union TASN1Time_ {
	TASN1Object uCHOICE;
	TASN1Object uUTCTime;
	TASN1Object uGeneralizedTime;
};
typedef union TASN1Time_ TASN1Time;
#define SLIM_ASN1_Time (SLIM_ASN1SCHEMAID_ASN1_START + 31)

#define SLIM_ASN1SCHEMAID_ASN1_END (SLIM_ASN1SCHEMAID_ASN1_START + 34)

/*========== X501 ========== */
#define SLIM_ASN1SCHEMAID_X501_START SLIM_ASN1SCHEMAID_ASN1_END

/*
	Attribute ::= SEQUENCE {
	  type  AttributeType,
	  values  SET OF AttributeValue
	}

	AttributeType ::= OBJECT IDENTIFIER

	AttributeValue ::= ANY
*/
struct TX501Attribute_ {
	TASN1Object fSEQUENCE;
	TASN1Object fType;
	TASN1Object fValues;
};
typedef struct TX501Attribute_ TX501Attribute;
#define SLIM_X501_Attribute (SLIM_ASN1SCHEMAID_X501_START + 3)

/*
	AttributeTypeAndValue ::= SEQUENCE {
	  type  AttributeType,
	  value  AttributeValue
	}
*/
struct TX501AttributeTypeAndValue_ {
	TASN1Object fSEQUENCE;
	TASN1Object fType;
	TASN1Object fValue;
};
typedef struct TX501AttributeTypeAndValue_ TX501AttributeTypeAndValue;
#define SLIM_X501_AttributeTypeAndValue (SLIM_ASN1SCHEMAID_X501_START + 7)

/* Attributes ::= SET OF Attribute */
typedef TASN1Object TX501Attributes;
#define SLIM_X501_Attributes (SLIM_ASN1SCHEMAID_X501_START + 10)

/* RelativeDistinguishedName ::= SET SIZE (1 .. MAX) OF AttributeTypeAndValue */
typedef TASN1Object TX501RelativeDistinguishedName;
#define SLIM_X501_RelativeDistinguishedName (SLIM_ASN1SCHEMAID_X501_START + 12)

/* RDNSequence ::= SEQUENCE OF RelativeDistinguishedName */
typedef TASN1Object TX501RDNSequence;
#define SLIM_X501_RDNSequence (SLIM_ASN1SCHEMAID_X501_START + 14)

#define SLIM_ASN1SCHEMAID_X501_END (SLIM_ASN1SCHEMAID_X501_START + 16)

/*========== X509 ========== */
#define SLIM_ASN1SCHEMAID_X509_START SLIM_ASN1SCHEMAID_X501_END

/*
	X520Name ::= CHOICE {
	      teletexString     TeletexString   (SIZE (1..ub-name)),
	      printableString   PrintableString (SIZE (1..ub-name)),
	      universalString   UniversalString (SIZE (1..ub-name)),
	      utf8String        UTF8String      (SIZE (1..ub-name)),
	      bmpString         BMPString       (SIZE (1..ub-name)) }
*/
union TX520Name_ {
	TASN1Object uCHOICE;
	TASN1Object uTeletexString;
	TASN1Object uPrintableString;
	TASN1Object uUniversalString;
	TASN1Object uUTF8String;
	TASN1Object uBMPString;
};
typedef union TX520Name_ TX520Name;
#define SLIM_X509_X520Name (SLIM_ASN1SCHEMAID_X509_START + 0)

/*
	X520CommonName ::= CHOICE {
	       teletexString     TeletexString   (SIZE (1..ub-common-name)),
	       printableString   PrintableString (SIZE (1..ub-common-name)),
	       universalString   UniversalString (SIZE (1..ub-common-name)),
	       utf8String        UTF8String      (SIZE (1..ub-common-name)),
	       bmpString         BMPString       (SIZE (1..ub-common-name)) }
*/
union TX520CommonName_ {
	TASN1Object uCHOICE;
	TASN1Object uTeletexString;
	TASN1Object uPrintableString;
	TASN1Object uUniversalString;
	TASN1Object uUTF8String;
	TASN1Object uBMPString;
};
typedef union TX520CommonName_ TX520CommonName;
#define SLIM_X509_X520CommonName (SLIM_ASN1SCHEMAID_X509_START + 6)

/*
	X520LocalityName ::= CHOICE {
	       teletexString     TeletexString   (SIZE (1..ub-locality-name)),
	       printableString   PrintableString (SIZE (1..ub-locality-name)),
	       universalString   UniversalString (SIZE (1..ub-locality-name)),
	       utf8String        UTF8String      (SIZE (1..ub-locality-name)),
	       bmpString         BMPString       (SIZE (1..ub-locality-name)) }
*/
union TX520LocalityName_ {
	TASN1Object uCHOICE;
	TASN1Object uTeletexString;
	TASN1Object uPrintableString;
	TASN1Object uUniversalString;
	TASN1Object uUTF8String;
	TASN1Object uBMPString;
};
typedef union TX520LocalityName_ TX520LocalityName;
#define SLIM_X509_X520LocalityName (SLIM_ASN1SCHEMAID_X509_START + 12)

/*
	X520StateOrProvinceName ::= CHOICE {
	       teletexString     TeletexString   (SIZE (1..ub-state-name)),
	       printableString   PrintableString (SIZE (1..ub-state-name)),
	       universalString   UniversalString (SIZE (1..ub-state-name)),
	       utf8String        UTF8String      (SIZE (1..ub-state-name)),
	       bmpString         BMPString       (SIZE(1..ub-state-name)) }
*/
union TX520StateOrProvinceName_ {
	TASN1Object uCHOICE;
	TASN1Object uTeletexString;
	TASN1Object uPrintableString;
	TASN1Object uUniversalString;
	TASN1Object uUTF8String;
	TASN1Object uBMPString;
};
typedef union TX520StateOrProvinceName_ TX520StateOrProvinceName;
#define SLIM_X509_X520StateOrProvinceName (SLIM_ASN1SCHEMAID_X509_START + 18)

/*
	X520OrganizationName ::= CHOICE {
	       teletexString     TeletexString
	                           (SIZE (1..ub-organization-name)),
	       printableString   PrintableString
	                           (SIZE (1..ub-organization-name)),
	       universalString   UniversalString
	                           (SIZE (1..ub-organization-name)),
	       utf8String        UTF8String
	                           (SIZE (1..ub-organization-name)),
	       bmpString         BMPString
	                           (SIZE (1..ub-organization-name))  }
*/
union TX520OrganizationName_ {
	TASN1Object uCHOICE;
	TASN1Object uTeletexString;
	TASN1Object uPrintableString;
	TASN1Object uUniversalString;
	TASN1Object uUTF8String;
	TASN1Object uBMPString;
};
typedef union TX520OrganizationName_ TX520OrganizationName;
#define SLIM_X509_X520OrganizationName (SLIM_ASN1SCHEMAID_X509_START + 24)

/*
	X520OrganizationalUnitName ::= CHOICE {
	       teletexString     TeletexString
	                           (SIZE (1..ub-organizational-unit-name)),
	       printableString   PrintableString
	                           (SIZE (1..ub-organizational-unit-name)),
	       universalString   UniversalString
	                           (SIZE (1..ub-organizational-unit-name)),
	       utf8String        UTF8String
	                           (SIZE (1..ub-organizational-unit-name)),
	       bmpString         BMPString
	                           (SIZE (1..ub-organizational-unit-name)) }
*/
union TX520OrganizationalUnitName_ {
	TASN1Object uCHOICE;
	TASN1Object uTeletexString;
	TASN1Object uPrintableString;
	TASN1Object uUniversalString;
	TASN1Object uUTF8String;
	TASN1Object uBMPString;
};
typedef union TX520OrganizationalUnitName_ TX520OrganizationalUnitName;
#define SLIM_X509_X520OrganizationalUnitName (SLIM_ASN1SCHEMAID_X509_START + 30)

/*
	X520Title ::= CHOICE {
	       teletexString     TeletexString   (SIZE (1..ub-title)),
	       printableString   PrintableString (SIZE (1..ub-title)),
	       universalString   UniversalString (SIZE (1..ub-title)),
	       utf8String        UTF8String      (SIZE (1..ub-title)),
	       bmpString         BMPString       (SIZE (1..ub-title)) }
*/
union TX520Title_ {
	TASN1Object uCHOICE;
	TASN1Object uTeletexString;
	TASN1Object uPrintableString;
	TASN1Object uUniversalString;
	TASN1Object uUTF8String;
	TASN1Object uBMPString;
};
typedef union TX520Title_ TX520Title;
#define SLIM_X509_X520Title (SLIM_ASN1SCHEMAID_X509_START + 36)

/* X520dnQualifier ::=     PrintableString */
typedef TASN1Object TX520dnQualifier;
#define SLIM_X509_X520dnQualifier (SLIM_ASN1SCHEMAID_X509_START + 42)

/* X520countryName ::=     PrintableString (SIZE (2)) */
typedef TASN1Object TX520CountryName;
#define SLIM_X509_X520CountryName (SLIM_ASN1SCHEMAID_X509_START + 43)

/* X520SerialNumber ::=    PrintableString (SIZE (1..ub-serial-number)) */
typedef TASN1Object TX520SerialNumber;
#define SLIM_X509_X520SerialNumber (SLIM_ASN1SCHEMAID_X509_START + 44)

/*
	X520Pseudonym ::= CHOICE {
	    teletexString     TeletexString   (SIZE (1..ub-pseudonym)),
	    printableString   PrintableString (SIZE (1..ub-pseudonym)),
	    universalString   UniversalString (SIZE (1..ub-pseudonym)),
	    utf8String        UTF8String      (SIZE (1..ub-pseudonym)),
	    bmpString         BMPString       (SIZE (1..ub-pseudonym)) }
*/
union TX520Pseudonym_ {
	TASN1Object uCHOICE;
	TASN1Object uTeletexString;
	TASN1Object uPrintableString;
	TASN1Object uUniversalString;
	TASN1Object uUTF8String;
	TASN1Object uBMPString;
};
typedef union TX520Pseudonym_ TX520Pseudonym;
#define SLIM_X509_X520Pseudonym (SLIM_ASN1SCHEMAID_X509_START + 45)

/* DomainComponent ::=     IA5String */
typedef TASN1Object TX509DomainComponent;
#define SLIM_X509_DomainComponent (SLIM_ASN1SCHEMAID_X509_START + 51)

/*
	Name ::= CHOICE {
	  rdnSequence  RDNSequence
	  -- only one possibility for now
	}
*/
union TX509Name_ {
	TASN1Object uCHOICE;
	TX501RDNSequence uRdnSequence;
};
typedef union TX509Name_ TX509Name;
#define SLIM_X509_Name (SLIM_ASN1SCHEMAID_X509_START + 52)

/*
	DirectoryString ::= CHOICE { 
	  teletexString    TeletexString (SIZE (1..MAX)), 
	  printableString  PrintableString (SIZE (1..MAX)), 
	  universalString  UniversalString (SIZE (1..MAX)), 
	  utf8String       UTF8String (SIZE (1.. MAX)), 
	  bmpString        BMPString (SIZE (1..MAX))
	} 
*/
union TX509DirectoryString_ {
	TASN1Object uCHOICE;
	TASN1Object uTeletexString;
	TASN1Object uPrintableString;
	TASN1Object uUniversalString;
	TASN1Object uUTF8String;
	TASN1Object uBMPString;
};
typedef union TX509DirectoryString_ TX509DirectoryString;
#define SLIM_X509_DirectoryString (SLIM_ASN1SCHEMAID_X509_START + 54)

/*
	OtherName ::= SEQUENCE { 
	  type-id  OBJECT IDENTIFIER, 
	  value    [0] EXPLICIT ANY DEFINED BY type-id
	} 
*/
struct TX509OtherName_ {
	TASN1Object fSEQUENCE;
	TASN1Object fTypeId;
	TASN1Object fValue;
};
typedef struct TX509OtherName_ TX509OtherName;
#define SLIM_X509_OtherName (SLIM_ASN1SCHEMAID_X509_START + 62)

/*
	EDIPartyName ::= SEQUENCE { 
	  nameAssigner  [0] DirectoryString OPTIONAL, 
	  partyName     [1] DirectoryString 
	} 
*/
struct TX509EDIPartyName_ {
	TASN1Object fSEQUENCE;
	TX509DirectoryString fNameAssigner;
	TX509DirectoryString fPartyName;
};
typedef struct TX509EDIPartyName_ TX509EDIPartyName;
#define SLIM_X509_EDIPartyName (SLIM_ASN1SCHEMAID_X509_START + 67)

/*
	GeneralName ::= CHOICE { 
	  otherName                  [0] OtherName, 
	  rfc822Name                 [1] IA5String, 
	  dNSName                    [2] IA5String, 
	  x400Address                [3] ORAddress, 
	  directoryName              [4] Name, 
	  ediPartyName               [5] EDIPartyName, 
	  uniformResourceIdentifier  [6] IA5String, 
	  iPAddress                  [7] OCTET STRING, 
	  registeredID               [8] OBJECT IDENTIFIER
	} 
*/
union TX509GeneralName_ {
	TASN1Object uCHOICE;
	TX509OtherName uOtherName;
	TASN1Object uRfc822Name;
	TASN1Object uDNSName;
	TASN1Object uX400Address;
	TX509Name uDirectoryName;
	TX509EDIPartyName uEdiPartyName;
	TASN1Object uUniformResourceIdentifier;
	TASN1Object uIPAddress;
	TASN1Object uRegisteredID;
};
typedef union TX509GeneralName_ TX509GeneralName;
#define SLIM_X509_GeneralName (SLIM_ASN1SCHEMAID_X509_START + 79)

/* GeneralNames ::= SEQUENCE SIZE (1..MAX) OF GeneralName  */
typedef TASN1Object TX509GeneralNames;
#define SLIM_X509_GeneralNames (SLIM_ASN1SCHEMAID_X509_START + 89)

/* Version ::= INTEGER { v1(0), v2(1), v3(2) } */
typedef TASN1Object TX509Version;
#define SLIM_X509_Version (SLIM_ASN1SCHEMAID_X509_START + 91)

/* CertificateSerialNumber ::= INTEGER */
typedef TASN1Object TX509CertSerialNumber;
#define SLIM_X509_CertificateSerialNumber (SLIM_ASN1SCHEMAID_X509_START + 92)

/*
	Validity ::= SEQUENCE {
	  notBefore  Time,
	  notAfter   Time
	}
*/
struct TX509Validity_ {
	TASN1Object fSEQUENCE;
	TASN1Time fNotBefore;
	TASN1Time fNotAfter;
};
typedef struct TX509Validity_ TX509Validity;
#define SLIM_X509_Validity (SLIM_ASN1SCHEMAID_X509_START + 93)

/*
	SubjectPublicKeyInfo ::= SEQUENCE {
	  algorithm         AlgorithmIdentifier,
	  subjectPublicKey  BIT STRING
	}
*/
struct TX509SubjectPublicKeyInfo_ {
	TASN1Object fSEQUENCE;
	TA1AlgoID fAlgorithm;
	TASN1Object fSubjectPublicKey;
};
typedef struct TX509SubjectPublicKeyInfo_ TX509SubjectPublicKeyInfo;
#define SLIM_X509_SubjectPublicKeyInfo (SLIM_ASN1SCHEMAID_X509_START + 96)

/* UniqueIdentifier ::= BIT STRING */
typedef TASN1Object TX509UniqueID;
#define SLIM_X509_UniqueIdentifier (SLIM_ASN1SCHEMAID_X509_START + 99)

/*
	Extension ::= SEQUENCE {
	  extnID     OBJECT IDENTIFIER,
	  critical   BOOLEAN DEFAULT FALSE,
	  extnValue  OCTET STRING
	}
*/
struct TX509Extension_ {
	TASN1Object fSEQUENCE;
	TASN1Object fExtnID;
	TASN1Object fCritical;
	TASN1Object fExtnValue;
};
typedef struct TX509Extension_ TX509Extension;
#define SLIM_X509_Extension (SLIM_ASN1SCHEMAID_X509_START + 100)

/* Extensions ::= SEQUENCE SIZE (1..MAX) OF Extension */
typedef TASN1Object TX509Extensions;
#define SLIM_X509_Extensions (SLIM_ASN1SCHEMAID_X509_START + 104)

/*
	TBSCertificate  ::=  SEQUENCE  {
	  version               [0] Version DEFAULT v1,
	  serialNumber          CertificateSerialNumber,
	  signature             AlgorithmIdentifier,
	  issuer                Name,
	  validity              Validity,
	  subject               Name,
	  subjectPublicKeyInfo  SubjectPublicKeyInfo,
	  issuerUniqueID        [1] IMPLICIT UniqueIdentifier OPTIONAL, -- If present, version shall be v2 or v3
	  subjectUniqueID       [2] IMPLICIT UniqueIdentifier OPTIONAL, -- If present, version shall be v2 or v3
	  extensions            [3] Extensions OPTIONAL                 -- If present, version shall be v3
	}
*/
struct TX509TBSCertificate_ {
	TASN1Object fSEQUENCE;
	TX509Version fVersion;
	TX509CertSerialNumber fSerialNumber;
	TA1AlgoID fSignature;
	TX509Name fIssuer;
	TX509Validity fValidity;
	TX509Name fSubject;
	TX509SubjectPublicKeyInfo fSubjectPublicKeyInfo;
	TX509UniqueID fIssuerUniqueID;
	TX509UniqueID fSubjectUniqueID;
	TX509Extensions fExtensions;
};
typedef struct TX509TBSCertificate_ TX509TBSCertificate;
#define SLIM_X509_TBSCertificate (SLIM_ASN1SCHEMAID_X509_START + 110)

/*
	Certificate ::= SEQUENCE {
	  tbsCertificate      TBSCertificate,
	  signatureAlgorithm	AlgorithmIdentifier,
	  signature           BIT STRING
	}
*/
struct TX509Certificate_ {
	TASN1Object fSEQUENCE;
	TX509TBSCertificate fTBSCertificate;
	TA1AlgoID fSignatureAlgorithm;
	TASN1Object fSignature;
};
typedef struct TX509Certificate_ TX509Certificate;
#define SLIM_X509_Certificate (SLIM_ASN1SCHEMAID_X509_START + 121)

/*
	TBSCertList ::= SEQUENCE {
	  version              Version OPTIONAL, -- if present, shall be v2
	  signature            AlgorithmIdentifier, 
	  issuer               Name, 
	  thisUpdate           Time, 
	  nextUpdate           Time OPTIONAL, 
	  revokedCertificates  SEQUENCE OF SEQUENCE { 
	    userCertificate     CertificateSerialNumber, 
	    revocationDate      Time, 
	    crlEntryExtensions  Extensions OPTIONAL -- if present, shall be v2
	  } OPTIONAL, 
	  crlExtensions        [0] EXPLICIT Extensions OPTIONAL -- if present, shall be v2
	}
*/
struct TX509RevokedCert_ {
	TASN1Object fSEQUENCE;
	TX509CertSerialNumber fUserCertificate;
	TASN1Time fRevocationDate;
	TX509Extensions fCRLEntryExtensions;
};
typedef struct TX509RevokedCert_ TX509RevokedCert;

typedef TASN1Object TX509RevokedCerts;

struct TX509TBSCertList_ {
	TASN1Object fSEQUENCE;
	TASN1Object fVersion;
	TA1AlgoID fSignature;
	TX509Name fIssuer;
	TASN1Time fThisUpdate;
	TASN1Time fNextUpdate;
	TX509RevokedCerts fRevokedCertificates;
	TX509Extensions fCRLExtensions;
};
typedef struct TX509TBSCertList_ TX509TBSCertList;
#define SLIM_X509_RevokedCertificate (SLIM_ASN1SCHEMAID_X509_START + 126)
#define SLIM_X509_RevokedCertificates (SLIM_ASN1SCHEMAID_X509_START + 130)
#define SLIM_X509_TBSCertList (SLIM_ASN1SCHEMAID_X509_START + 132)

/*
	CertificateList ::= SEQUENCE { 
	  tbsCertList         TBSCertList, 
	  signatureAlgorithm  AlgorithmIdentifier, 
	  signatureValue      BIT STRING
	} 
*/
struct TX509CRL_ {
	TASN1Object fSEQUENCE;
	TX509TBSCertList fTBSCertList;
	TA1AlgoID fSignatureAlgorithm;
	TASN1Object fSignatureValue;
};
typedef struct TX509CRL_ TX509CRL;
#define SLIM_X509_CRL (SLIM_ASN1SCHEMAID_X509_START + 140)

/* KeyIdentifier ::= OCTET STRING */
typedef TASN1Object TX509KeyID;
#define SLIM_X509_KeyIdentifier (SLIM_ASN1SCHEMAID_X509_START + 144)

/*
	AuthorityKeyIdentifier ::= SEQUENCE {
	  keyIdentifier              [0] KeyIdentifier OPTIONAL, 
	  authorityCertIssuer        [1] GeneralNames OPTIONAL, 
	  authorityCertSerialNumber  [2] CertificateSerialNumber OPTIONAL
	}
*/
struct TX509AuthorityKeyID_ {
	TASN1Object fSEQUENCE;
	TX509KeyID fKeyIdentifier;
	TX509GeneralNames fAuthorityCertIssuer;
	TX509CertSerialNumber fAuthorityCertSerialNumber;
};
typedef struct TX509AuthorityKeyID_ TX509AuthorityKeyID;
#define SLIM_X509_AuthorityKeyIdentifier (SLIM_ASN1SCHEMAID_X509_START + 148)

/* SubjectKeyIdentifier ::= KeyIdentifier */
typedef TX509KeyID TX509SubjectKeyID;
#define SLIM_X509_SubjectKeyIdentifier (SLIM_ASN1SCHEMAID_X509_START + 152)

/* KeyUsage ::= BIT STRING */
typedef TASN1Object TX509KeyUsage;
#define SLIM_X509_KeyUsage (SLIM_ASN1SCHEMAID_X509_START + 153)

/*
	PrivateKeyUsagePeriod ::= SEQUENCE {
	  notBefore  [0] GeneralizedTime OPTIONAL,
	  notAfter   [1] GeneralizedTime OPTIONAL
	}
*/
struct TX509PrKeyUsagePeriod_ {
	TASN1Object fSEQUENCE;
	TASN1Object fNotBefore;
	TASN1Object fNotAfter;
};
typedef struct TX509PrKeyUsagePeriod_ TX509PrKeyUsagePeriod;
#define SLIM_X509_PrivateKeyUsagePeriod (SLIM_ASN1SCHEMAID_X509_START + 156)

/*
	id-qt OBJECT IDENTIFIER ::= { id-pkix 2 }
	id-qt-cps OBJECT IDENTIFIER ::= { id-qt 1 }
	id-qt-unotice OBJECT IDENTIFIER ::= { id-qt 2 } 

	PolicyQualifierId ::= OBJECT IDENTIFIER ( id-qt-cps | id-qt-unotice ) 
*/
typedef TASN1Object TX509PolicyQualifierID;
#define SLIM_X509_PolicyQualifierId (SLIM_ASN1SCHEMAID_X509_START + 159)

/* CPSuri ::= IA5String  */
typedef TASN1Object TX509CPSuri;
#define SLIM_X509_CPSuri (SLIM_ASN1SCHEMAID_X509_START + 160)

/*
	DisplayText ::= CHOICE { 
	  visibleString  VisibleString (SIZE (1..200)), 
	  bmpString      BMPString (SIZE (1..200)), 
	  utf8String     UTF8String (SIZE (1..200))
	}
*/
union TX509DisplayText_ {
	TASN1Object uCHOICE;
	TASN1Object uVisibleString;
	TASN1Object uBmpString;
	TASN1Object uUtf8String;
};
typedef union TX509DisplayText_ TX509DisplayText;
#define SLIM_X509_DisplayText (SLIM_ASN1SCHEMAID_X509_START + 161)

/*
	NoticeReference ::= SEQUENCE { 
	  organization   DisplayText, 
	  noticeNumbers  SEQUENCE OF INTEGER
	} 
*/
typedef TASN1Object TX509NoticeNumbers;

struct TX509NoticeReference_ {
	TASN1Object fSEQUENCE;
	TX509DisplayText fOrganization;
	TX509NoticeNumbers fNoticeNumbers;
};
typedef struct TX509NoticeReference_ TX509NoticeReference;
#define SLIM_X509_NoticeNumbers (SLIM_ASN1SCHEMAID_X509_START + 165)
#define SLIM_X509_NoticeReference (SLIM_ASN1SCHEMAID_X509_START + 167)

/*
	UserNotice ::= SEQUENCE {
	  noticeRef     NoticeReference OPTIONAL, 
	  explicitText  DisplayText OPTIONAL
	}
*/
struct TX509UserNotice_ {
	TASN1Object fSEQUENCE;
	TX509NoticeReference fNoticeRef;
	TX509DisplayText fExplicitText;
};
typedef struct TX509UserNotice_ TX509UserNotice;
#define SLIM_X509_UserNotice (SLIM_ASN1SCHEMAID_X509_START + 170)

/*
	Qualifier ::= CHOICE { 
	  cPSuri      CPSuri,
	  userNotice  UserNotice
	} 
*/
union TX509Qualifier_ {
	TASN1Object uCHOICE;
	TX509CPSuri uCPSuri;
	TX509UserNotice uUserNotice;
};
typedef union TX509Qualifier_ TX509Qualifier;
#define SLIM_X509_Qualifier (SLIM_ASN1SCHEMAID_X509_START + 173)

/*
	PolicyQualifierInfo ::= SEQUENCE { 
	  policyQualifierId  PolicyQualifierId, 
	  qualifier          ANY DEFINED BY policyQualifierId
	} 
*/
struct TX509PolicyQualifierInfo_ {
	TASN1Object fSEQUENCE;
	TX509PolicyQualifierID fPolicyQualifierId;
	TX509PolicyQualifierID fQualifier;
};
typedef struct TX509PolicyQualifierInfo_ TX509PolicyQualifierInfo;
#define SLIM_X509_PolicyQualifierInfo (SLIM_ASN1SCHEMAID_X509_START + 177)

/* PolicyQualifiers ::= SEQUENCE SIZE (1..MAX) OF PolicyQualifierInfo */
typedef TASN1Object TX509PolicyQualifiers;
#define SLIM_X509_PolicyQualifiers (SLIM_ASN1SCHEMAID_X509_START + 180)

/* CertPolicyId ::= OBJECT IDENTIFIER */
typedef TASN1Object TX509CertPolicyID;
#define SLIM_X509_CertPolicyId (SLIM_ASN1SCHEMAID_X509_START + 182)

/*
	PolicyInformation ::= SEQUENCE { 
	  policyIdentifier  CertPolicyId, 
	  policyQualifiers  PolicyQualifiers OPTIONAL
	} 
*/
struct TX509PolicyInfo_ {
	TASN1Object fSEQUENCE;
	TX509CertPolicyID fPolicyIdentifier;
	TX509PolicyQualifiers fPolicyQualifiers;
};
typedef struct TX509PolicyInfo_ TX509PolicyInfo;
#define SLIM_X509_PolicyInformation (SLIM_ASN1SCHEMAID_X509_START + 183)

/* CertificatePolicies ::= SEQUENCE SIZE (1..MAX) OF PolicyInformation */
typedef TASN1Object TX509CertPolicies;
#define SLIM_X509_CertificatePolicies (SLIM_ASN1SCHEMAID_X509_START + 186)

/*
	PolicyMappings ::= SEQUENCE SIZE (1..MAX) OF SEQUENCE { 
	  issuerDomainPolicy   CertPolicyId, 
	  subjectDomainPolicy  CertPolicyId
	} 
*/
struct TX509PolicyMapping_ {
	TASN1Object fSEQUENCE;
	TX509CertPolicyID fIssuerDomainPolicy;
	TX509CertPolicyID fSubjectDomainPolicy;
};
typedef struct TX509PolicyMapping_ TX509PolicyMapping;

typedef TASN1Object TX509PolicyMappings;
#define SLIM_X509_PolicyMapping (SLIM_ASN1SCHEMAID_X509_START + 188)
#define SLIM_X509_PolicyMappings (SLIM_ASN1SCHEMAID_X509_START + 191)

/* SubjectAltName ::= GeneralNames */
typedef TX509GeneralNames TX509SubjectAltName;
#define SLIM_X509_SubjectAltName (SLIM_ASN1SCHEMAID_X509_START + 193)

/* IssuerAltName ::= GeneralNames */
typedef TX509GeneralNames TX509IssuerAltName;
#define SLIM_X509_IssuerAltName (SLIM_ASN1SCHEMAID_X509_START + 194)

/* SubjectDirectoryAttributes ::= SEQUENCE SIZE (1..MAX) OF Attribute */
typedef TASN1Object TX509SubjectDirectoryAttributs;
#define SLIM_X509_SubjectDirectoryAttributes (SLIM_ASN1SCHEMAID_X509_START + 195)

/*
	BasicConstraints ::= SEQUENCE { 
	  cA                 BOOLEAN DEFAULT FALSE, 
	  pathLenConstraint  INTEGER (0..MAX) OPTIONAL
	} 
*/
struct TX509BasicConstraints_ {
	TASN1Object fSEQUENCE;
	TASN1Object fCA;
	TASN1Object fPathLenConstraint;
};
typedef struct TX509BasicConstraints_ TX509BasicConstraints;
#define SLIM_X509_BasicConstraints (SLIM_ASN1SCHEMAID_X509_START + 197)

/* BaseDistance ::= INTEGER (0..MAX) */
typedef TASN1Object TX509BaseDistance;
#define SLIM_X509_BaseDistance (SLIM_ASN1SCHEMAID_X509_START + 200)

/*
	GeneralSubtree ::= SEQUENCE { 
	  base     GeneralName, 
	  minimum  [0] BaseDistance DEFAULT 0, 
	  maximum  [1] BaseDistance OPTIONAL
	} 
*/
struct TX509GeneralSubtree_ {
	TASN1Object fSEQUENCE;
	TX509GeneralName fBase;
	TX509BaseDistance fMinimum;
	TX509BaseDistance fMaximum;
};
typedef struct TX509GeneralSubtree_ TX509GeneralSubtree;
#define SLIM_X509_GeneralSubtree (SLIM_ASN1SCHEMAID_X509_START + 203)

/* GeneralSubtrees ::= SEQUENCE SIZE (1..MAX) OF GeneralSubtree  */
typedef TASN1Object TX509GeneralSubtrees;
#define SLIM_X509_GeneralSubtrees (SLIM_ASN1SCHEMAID_X509_START + 207)

/*
	NameConstraints ::= SEQUENCE { 
	  permittedSubtrees  [0] GeneralSubtrees OPTIONAL, 
	  excludedSubtrees   [1] GeneralSubtrees OPTIONAL
	} 
*/
struct TX509NameConstraints_ {
	TASN1Object fSEQUENCE;
	TX509GeneralSubtrees fPermittedSubtrees;
	TX509GeneralSubtrees fExcludedSubtrees;
};
typedef struct TX509NameConstraints_ TX509NameConstraints;
#define SLIM_X509_NameConstraints (SLIM_ASN1SCHEMAID_X509_START + 211)

/* SkipCerts ::= INTEGER (0..MAX) */
typedef TASN1Object TX509SkipCerts;
#define SLIM_X509_SkipCerts (SLIM_ASN1SCHEMAID_X509_START + 214)

/*
	PolicyConstraints ::= SEQUENCE { 
	  requireExplicitPolicy [0] SkipCerts OPTIONAL, 
	  inhibitPolicyMapping [1] SkipCerts OPTIONAL
	} 
*/
struct TX509PolicyConstraints_ {
	TASN1Object fSEQUENCE;
	TX509SkipCerts fRequireExplicitPolicy;
	TX509SkipCerts fInhibitPolicyMapping;
};
typedef struct TX509PolicyConstraints_ TX509PolicyConstraints;
#define SLIM_X509_PolicyConstraints (SLIM_ASN1SCHEMAID_X509_START + 217)

/* KeyPurposeId ::= OBJECT IDENTIFIER */
typedef TASN1Object TX509KeyPurposeId;
#define SLIM_X509_KeyPurposeId (SLIM_ASN1SCHEMAID_X509_START + 220)

/* ExtKeyUsageSyntax ::= SEQUENCE SIZE (1..MAX) OF KeyPurposeId */
typedef TASN1Object TX509ExtKeyUsageSyntax;
#define SLIM_X509_ExtKeyUsageSyntax (SLIM_ASN1SCHEMAID_X509_START + 221)

/*
	DistributionPointName ::= CHOICE { 
	  fullName                 [0] GeneralNames, 
	  nameRelativeToCRLIssuer  [1] RelativeDistinguishedName
	}
*/
union TX509DistPointName_ {
	TASN1Object uCHOICE;
	TX509GeneralNames uFullName;
	TX501RelativeDistinguishedName uNameRelativeToCRLIssuer;
};
typedef union TX509DistPointName_ TX509DistPointName;
#define SLIM_X509_DistributionPointName (SLIM_ASN1SCHEMAID_X509_START + 225)

/*
	ReasonFlags ::= BIT STRING { 
	  unused (0), 
	  keyCompromise (1), 
	  cACompromise (2), 
	  affiliationChanged (3), 
	  superseded (4), 
	  cessationOfOperation (5), 
	  certificateHold (6)
	}
*/
typedef TASN1Object TX509ReasonFlags;
#define SLIM_X509_ReasonFlags (SLIM_ASN1SCHEMAID_X509_START + 228)

/*
	DistributionPoint ::= SEQUENCE { 
	  distributionPoint  [0] DistributionPointName OPTIONAL, 
	  reasons            [1] ReasonFlags OPTIONAL, 
	  cRLIssuer          [2] GeneralNames OPTIONAL
	} 
*/
struct TX509DistPoint_ {
	TASN1Object fSEQUENCE;
	TX509DistPointName fDistributionPoint;
	TX509ReasonFlags fReasons;
	TX509GeneralNames fCRLIssuer;
};
typedef struct TX509DistPoint_ TX509DistPoint;
#define SLIM_X509_DistributionPoint (SLIM_ASN1SCHEMAID_X509_START + 232)

/* CRLDistributionPoints ::= SEQUENCE SIZE (1..MAX) OF DistributionPoint */
typedef TASN1Object TX509CRLDistPoints;
#define SLIM_X509_CRLDistributionPoints (SLIM_ASN1SCHEMAID_X509_START + 236)

/* FreshestCRL ::= CRLDistributionPoints */
typedef TX509CRLDistPoints TX509FreshestCRL;
#define SLIM_X509_FreshestCRL (SLIM_ASN1SCHEMAID_X509_START + 238)

/*
	AccessDescription ::= SEQUENCE { 
	  accessMethod    OBJECT IDENTIFIER, 
	  accessLocation  GeneralName
	}
*/
struct TX509AccessDescription_ {
	TASN1Object fSEQUENCE;
	TASN1Object fAccessMethod;
	TX509GeneralName fAccessLocation;
};
typedef struct TX509AccessDescription_ TX509AccessDescription;
#define SLIM_X509_AccessDescription (SLIM_ASN1SCHEMAID_X509_START + 239)

/*
	AuthorityInfoAccess EXTENSION ::= {
	  SYNTAX  AuthorityInfoAccessSyntax
	    IDENTIFIED BY id-pe-authorityInfoAccess
	}

	AuthorityInfoAccessSyntax ::= SEQUENCE SIZE (1..MAX) OF AccessDescription
*/
typedef TASN1Object TX509AuthorityInfoAccess;
#define SLIM_X509_AuthorityInfoAccess (SLIM_ASN1SCHEMAID_X509_START + 242)

/*
	SubjectInfoAccess EXTENSION ::= {
	  SYNTAX  SubjectInfoAccessSyntax
	    IDENTIFIED BY id-pe-subjectInfoAccess
	}

	SubjectInfoAccessSyntax ::= SEQUENCE SIZE (1..MAX) OF AccessDescription
*/
typedef TASN1Object TX509SubjectInfoAccess;
#define SLIM_X509_SubjectInfoAccess (SLIM_ASN1SCHEMAID_X509_START + 244)

/* CRLNumber ::= INTEGER (0..MAX) */
typedef TASN1Object TX509CRLNumber;
#define SLIM_X509_CRLNumber (SLIM_ASN1SCHEMAID_X509_START + 246)

/* BaseCRLNumber ::= CRLNumber */
typedef TX509CRLNumber TX509BaseCRLNumber;
#define SLIM_X509_BaseCRLNumber (SLIM_ASN1SCHEMAID_X509_START + 247)

/* DeltaCRLIndicator ::= BaseCRLNumber */
typedef TX509BaseCRLNumber TX509DeltaCRLIndicator;
#define SLIM_X509_DeltaCRLIndicator (SLIM_ASN1SCHEMAID_X509_START + 248)

/*
	IssuingDistributionPoint ::= SEQUENCE { 
	  distributionPoint      [0] DistributionPointName OPTIONAL, 
	  onlyContainsUserCerts  [1] BOOLEAN DEFAULT FALSE, 
	  onlyContainsCACerts    [2] BOOLEAN DEFAULT FALSE, 
	  onlySomeReasons        [3] ReasonFlags OPTIONAL, 
	  indirectCRL            [4] BOOLEAN DEFAULT FALSE
	} 
*/
struct TX509IssuingDistPoint_ {
	TASN1Object fSEQUENCE;
	TX509DistPointName fDistributionPoint;
	TASN1Object fOnlyContainsUserCerts;
	TASN1Object fOnlyContainsCACerts;
	TX509ReasonFlags fOnlySomeReasons;
	TASN1Object fIndirectCRL;
};
typedef struct TX509IssuingDistPoint_ TX509IssuingDistPoint;
#define SLIM_X509_IssuingDistributionPoint (SLIM_ASN1SCHEMAID_X509_START + 254)

/*
	CRLReason ::= ENUMERATED { 
	  unspecified (0), 
	  keyCompromise (1), 
	  cACompromise (2), 
	  affiliationChanged (3), 
	  superseded (4), 
	  cessationOfOperation (5), 
	  certificateHold (6), 
	  removeFromCRL (8)
	} 
*/
typedef TASN1Object TX509CRLReason;
#define SLIM_X509_CRLReason (SLIM_ASN1SCHEMAID_X509_START + 260)

/* HoldInstructionCode ::= OBJECT IDENTIFIER */
typedef TASN1Object TX509HoldInstructionCode;
#define SLIM_X509_HoldInstructionCode (SLIM_ASN1SCHEMAID_X509_START + 261)

/* InvalidityDate ::= GeneralizedTime */
typedef TASN1Object TX509InvalidityDate;
#define SLIM_X509_InvalidityDate (SLIM_ASN1SCHEMAID_X509_START + 262)

/* CertificateIssuer ::= GeneralNames */
typedef TX509GeneralNames TX509CertIssuer;
#define SLIM_X509_CertificateIssuer (SLIM_ASN1SCHEMAID_X509_START + 263)

#define SLIM_ASN1SCHEMAID_X509_END (SLIM_ASN1SCHEMAID_X509_START + 264)

/*========== PKCS1 ========== */
#define SLIM_ASN1SCHEMAID_PKCS1_START SLIM_ASN1SCHEMAID_X509_END

/*
	RSAPublicKey ::= SEQUENCE {
	  modulus         INTEGER,  -- n
	  publicExponent  INTEGER   -- e
	}
*/
struct TP1RSAPublicKey_ {
	TASN1Object fSEQUENCE;
	TASN1Object fModulus;
	TASN1Object fPublicExponent;
};
typedef struct TP1RSAPublicKey_ TP1RSAPublicKey;
#define SLIM_PKCS1_RSAPublicKey (SLIM_ASN1SCHEMAID_PKCS1_START + 0)

/*
	Version ::= INTEGER { two-prime(0), multi(1) }
	  (CONSTRAINED BY {
	     -- version must be multi if otherPrimeInfos present
	   })
*/
typedef TASN1Object TP1Version;
#define SLIM_PKCS1_Version (SLIM_ASN1SCHEMAID_PKCS1_START + 3)

/*
	OtherPrimeInfo ::= SEQUENCE {
	  prime        INTEGER,  -- ri
	  exponent     INTEGER,  -- di
	  coefficient  INTEGER   -- ti
	}
*/
struct TP1OtherPrimeInfo_ {
	TASN1Object fSEQUENCE;
	TASN1Object fPrime;
	TASN1Object fExponent;
	TASN1Object fCoefficient;
};
typedef struct TP1OtherPrimeInfo_ TP1OtherPrimeInfo;
#define SLIM_PKCS1_OtherPrimeInfo (SLIM_ASN1SCHEMAID_PKCS1_START + 4)

/* OtherPrimeInfos ::= SEQUENCE SIZE(1..MAX) OF OtherPrimeInfo */
typedef TASN1Object TP1OtherPrimeInfos;
#define SLIM_PKCS1_OtherPrimeInfos (SLIM_ASN1SCHEMAID_PKCS1_START + 8)

/*
	RSAPrivateKey ::= SEQUENCE {
	  version          Version,
	  modulus          INTEGER,  -- n
	  publicExponent   INTEGER,  -- e
	  privateExponent  INTEGER,  -- d
	  prime1           INTEGER,  -- p
	  prime2           INTEGER,  -- q
	  exponent1        INTEGER,  -- d mod (p-1)
	  exponent2        INTEGER,  -- d mod (q-1)
	  coefficient      INTEGER,  -- (inverse of q) mod p
	  otherPrimeInfos  OtherPrimeInfos OPTIONAL
	}
*/
struct TP1RSAPrivateKey_ {
	TASN1Object fSEQUENCE;
	TP1Version fVersion;
	TASN1Object fModulus;
	TASN1Object fPublicExponent;
	TASN1Object fPrivateExponent;
	TASN1Object fPrime1;
	TASN1Object fPrime2;
	TASN1Object fExponent1;
	TASN1Object fExponent2;
	TASN1Object fCoefficient;
	TP1OtherPrimeInfos fOtherPrimeInfos;
};
typedef struct TP1RSAPrivateKey_ TP1RSAPrivateKey;
#define SLIM_PKCS1_RSAPrivateKey (SLIM_ASN1SCHEMAID_PKCS1_START + 10)

#define SLIM_ASN1SCHEMAID_PKCS1_END (SLIM_ASN1SCHEMAID_PKCS1_START + 21)

/*========== PKCS5 ========== */
#ifdef SLIM_CONFIG_USE_PKCS5
#define SLIM_ASN1SCHEMAID_PKCS5_START SLIM_ASN1SCHEMAID_PKCS1_END

/*
	PBEParameter ::= SEQUENCE {
	  salt  OCTET STRING (SIZE(8)),
	  iterationCount  INTEGER
	}
*/
struct TP5PBEParameter_ {
	TASN1Object fSEQUENCE;
	TASN1Object fSalt;
	TASN1Object fIterationCount;
};
typedef struct TP5PBEParameter_ TP5PBEParameter;
#define SLIM_PKCS5_PBEParameter (SLIM_ASN1SCHEMAID_PKCS5_START + 0)

/*
	PBKDF2-params ::= SEQUENCE {
	  salt CHOICE {
	    specified OCTET STRING,
	    otherSource AlgorithmIdentifier {{PBKDF2-SaltSources}}
	  },
	  iterationCount INTEGER (1..MAX),
	  keyLength INTEGER (1..MAX) OPTIONAL,
	  prf AlgorithmIdentifier {{PBKDF2-PRFs}} DEFAULT algid-hmacWithSHA1
	}

	-- salt specifies the salt value, or the source of the salt value. 
	-- It shall either be an octet string or an algorithm ID 
	-- with an OID in the set PBKDF2-SaltSources, 
	-- which is reserved for future versions of PKCS #5.
*/
union TP5PBKDF2Salt_ {
	TASN1Object uCHOICE;
	TASN1Object uSpecified;
	TA1AlgoID uOtherSource;
};
typedef union TP5PBKDF2Salt_ TP5PBKDF2Salt;

struct TP5PBKDF2Params_ {
	TASN1Object fSEQUENCE;
	TASN1Object fSalt;
	TASN1Object fIterationCount;
	TASN1Object fKeyLength;
	TA1AlgoID fPRF;
};
typedef struct TP5PBKDF2Params_ TP5PBKDF2Params;
#define SLIM_PKCS5_PBKDF2Salt (SLIM_ASN1SCHEMAID_PKCS5_START + 3)
#define SLIM_PKCS5_PBKDF2Params (SLIM_ASN1SCHEMAID_PKCS5_START + 6)

#define SLIM_ASN1SCHEMAID_PKCS5_END (SLIM_ASN1SCHEMAID_PKCS5_START + 11)
#else
#define SLIM_ASN1SCHEMAID_PKCS5_END SLIM_ASN1SCHEMAID_PKCS1_END
#endif /* SLIM_CONFIG_USE_PKCS5 */

/*========== PKCS6 ========== */
#define SLIM_ASN1SCHEMAID_PKCS6_START SLIM_ASN1SCHEMAID_PKCS5_END

/* Version ::= INTEGER */
typedef TASN1Object TP6Version;
#define SLIM_PKCS6_Version (SLIM_ASN1SCHEMAID_PKCS6_START + 0)

/*
	ExtendedCertificateInfo ::= SEQUENCE {
	  version  Version,
	  certificate  Certificate,
	  attributes  Attributes
	}
*/
struct TP6ExtCertInfo_ {
	TASN1Object fSEQUENCE;
	TP6Version fVersion;
	TX509Certificate fCertificate;
	TX501Attributes fAttributes;
};
typedef struct TP6ExtCertInfo_ TP6ExtCertInfo;
#define SLIM_PKCS6_ExtendedCertificateInfo (SLIM_ASN1SCHEMAID_PKCS6_START + 1)

/* SignatureAlgorithmIdentifier ::= AlgorithmIdentifier */
typedef TA1AlgoID TP6SignatureAlgoID;
#define SLIM_PKCS6_SignatureAlgorithmIdentifier (SLIM_ASN1SCHEMAID_PKCS6_START + 5)

/* Signature ::= BIT STRING */
typedef TASN1Object TP6Signature;
#define SLIM_PKCS6_Signature (SLIM_ASN1SCHEMAID_PKCS6_START + 6)

/*
	ExtendedCertificate ::= SEQUENCE {
	  extendedCertificateInfo  ExtendedCertificateInfo,
	  signatureAlgorithm  SignatureAlgorithmIdentifier,
	  signature  Signature
	}
*/
struct TP6ExtCert_ {
	TASN1Object fSEQUENCE;
	TP6ExtCertInfo fExtendedCertificateInfo;
	TP6SignatureAlgoID fSignatureAlgorithm;
	TP6Signature fSignature;
};
typedef struct TP6ExtCert_ TP6ExtCert;
#define SLIM_PKCS6_ExtendedCertificate (SLIM_ASN1SCHEMAID_PKCS6_START + 7)

#define SLIM_ASN1SCHEMAID_PKCS6_END (SLIM_ASN1SCHEMAID_PKCS6_START + 11)

/*========== PKCS7 ========== */
#ifdef SLIM_CONFIG_USE_PKCS7
#define SLIM_ASN1SCHEMAID_PKCS7_START SLIM_ASN1SCHEMAID_PKCS6_END

/* CertificateRevocationLists ::= SET OF CertificateRevocationList */
typedef TASN1Object TP7CRLs;
#define SLIM_PKCS7_CRLs (SLIM_ASN1SCHEMAID_PKCS7_START + 0)

/* ContentEncryptionAlgorithmIdentifier ::= AlgorithmIdentifier */
typedef TA1AlgoID TP7ContentEncryptionAlgoID;
#define SLIM_PKCS7_ContentEncryptionAlgoID (SLIM_ASN1SCHEMAID_PKCS7_START + 2)

/* DigestAlgorithmIdentifier ::= AlgorithmIdentifier */
typedef TA1AlgoID TP7DigestAlgoID;
#define SLIM_PKCS7_DigestAlgoID (SLIM_ASN1SCHEMAID_PKCS7_START + 3)

/* DigestAlgorithmIdentifiers ::= SET OF DigestAlgorithmIdentifier */
typedef TASN1Object TP7DigestAlgoIDs;
#define SLIM_PKCS7_DigestAlgoIDs (SLIM_ASN1SCHEMAID_PKCS7_START + 4)

/* DigestEncryptionAlgorithmIdentifier ::= AlgorithmIdentifier */
typedef TA1AlgoID TP7DigestEncryptionAlgoID;
#define SLIM_PKCS7_DigestEncryptionAlgoID (SLIM_ASN1SCHEMAID_PKCS7_START + 6)

/*
	ExtendedCertificateOrCertificate ::= CHOICE {
	  certificate  Certificate, -- X.509
	  extendedCertificate  [0] IMPLICIT ExtendedCertificate
	}
*/
union TP7ExtCertOrCert_ {
	TASN1Object uCHOICE;
	TX509Certificate uCertificate;
	TP6ExtCert uExtendedCertificate;
};
typedef union TP7ExtCertOrCert_ TP7ExtCertOrCert;
#define SLIM_PKCS7_ExtCertOrCert (SLIM_ASN1SCHEMAID_PKCS7_START + 8)

/* ExtendedCertificatesOrCertificates ::= SET OF ExtendedCertificateOfCertificate */
typedef TASN1Object TP7ExtCertsOrCerts;
#define SLIM_PKCS7_ExtCertsOrCerts (SLIM_ASN1SCHEMAID_PKCS7_START + 11)

/*
	IssuerAndSerialNumber ::= SEQUENCE {
	  issuer  Name,
	  serialNumber  CertificateSerialNumber
	}
*/
struct TP7IssuerAndSerialNumber_ {
	TASN1Object fSEQUENCE;
	TX509Name fIssuer;
	TASN1Object fSerialNumber;
};
typedef struct TP7IssuerAndSerialNumber_ TP7IssuerAndSerialNumber;
#define SLIM_PKCS7_IssuerAndSerialNumber (SLIM_ASN1SCHEMAID_PKCS7_START + 13)

/* KeyEncryptionAlgorithmIdentifier ::= AlgorithmIdentifier */
typedef TA1AlgoID TP7KeyEncryptionAlgoID;
#define SLIM_PKCS7_KeyEncryptionAlgoID (SLIM_ASN1SCHEMAID_PKCS7_START + 16)

/* Version ::= INTEGER */
typedef TASN1Object TP7Version;
#define SLIM_PKCS7_Version (SLIM_ASN1SCHEMAID_PKCS7_START + 17)

/* ContentType ::= OBJECT IDENTIFIER */
typedef TASN1Object TP7ContentType;
#define SLIM_PKCS7_ContentType (SLIM_ASN1SCHEMAID_PKCS7_START + 18)

/*
	ContentInfo ::= SEQUENCE {
	  contentType  ContentType,
	  content  [0] EXPLICIT ANY DEFINED BY contentType OPTIONAL
	}
*/
struct TP7ContentInfo_ {
	TASN1Object fSEQUENCE;
	TP7ContentType fContentType;
	TASN1Object fContent;
};
typedef struct TP7ContentInfo_ TP7ContentInfo;
#define SLIM_PKCS7_ContentInfo (SLIM_ASN1SCHEMAID_PKCS7_START + 21)

/* Data ::= OCTET STRING */
typedef TASN1Object TP7Data;
#define SLIM_PKCS7_Data (SLIM_ASN1SCHEMAID_PKCS7_START + 24)

/* EncryptedDigest ::= OCTET STRING */
typedef TASN1Object TP7EncryptedDigest;
#define SLIM_PKCS7_EncryptedDigest (SLIM_ASN1SCHEMAID_PKCS7_START + 25)

/*
	SignerInfo ::= SEQUENCE {
	  version  Version,
	  issuerAndSerialNumber  IssuerAndSerialNumber,
	  digestAlgorithm  DigestAlgorithmIdentifier,
	  authenticatedAttributes  [0] IMPLICIT Attributes OPTIONAL,
	  digestEncryptionAlgorithm  DigestEncryptionAlgorithmIdentifier,
	  encryptedDigest  EncryptedDigest,
	  unauthenticatedAttributes  [1] IMPLICIT Attributes OPTIONAL
	}
*/
struct TP7SignerInfo_ {
	TASN1Object fSEQUENCE;
	TP7Version fVersion;
	TP7IssuerAndSerialNumber fIssuerAndSerialNumber;
	TP7DigestAlgoID fDigestAlgorithm;
	TX501Attributes fAuthenticatedAttributes;
	TP7DigestEncryptionAlgoID fDigestEncryptionAlgorithm;
	TP7EncryptedDigest fEncryptedDigest;
	TX501Attributes fUnauthenticatedAttributes;
};
typedef struct TP7SignerInfo_ TP7SignerInfo;
#define SLIM_PKCS7_SignerInfo (SLIM_ASN1SCHEMAID_PKCS7_START + 28)

/* SignerInfos ::= SET OF SignerInfo */
typedef TASN1Object TP7SignerInfos;
#define SLIM_PKCS7_SignerInfos (SLIM_ASN1SCHEMAID_PKCS7_START + 36)

/*
	SignedData ::= SEQUENCE {
	  version  Version,
	  digestAlgorithms  DigestAlgorithmIdentifiers,
	  contentInfo  ContentInfo,
	  certificates  [0] IMPLICIT ExtendedCertificatesOrCertificates OPTIONAL,
	  crls  [1] IMPLICIT CertificateRevocationLists OPTIONAL,
	  signerInfos  SignerInfos
	}
*/
struct TP7SignedData_ {
	TASN1Object fSEQUENCE;
	TP7Version fVersion;
	TP7DigestAlgoIDs fDigestAlgorithms;
	TP7ContentInfo fContentInfo;
	TP7ExtCertsOrCerts fCertificates;
	TP7CRLs fCRLs;
	TP7SignerInfos fSignerInfos;
};
typedef struct TP7SignedData_ TP7SignedData;
#define SLIM_PKCS7_SignedData (SLIM_ASN1SCHEMAID_PKCS7_START + 40)

/* EncryptedKey ::= OCTET STRING */
typedef TASN1Object TP7EncryptedKey;
#define SLIM_PKCS7_EncryptedKey (SLIM_ASN1SCHEMAID_PKCS7_START + 47)

/*
	RecipientInfo ::= SEQUENCE {
	  version  Version,
	  issuerAndSerialNumber  IssuerAndSerialNumber,
	  keyEncryptionAlgorithm  KeyEncryptionAlgorithmIdentifier,
	  encryptedKey  EncryptedKey
	}
*/
struct TP7RecipientInfo_ {
	TASN1Object fSEQUENCE;
	TP7Version fVersion;
	TP7IssuerAndSerialNumber fIssuerAndSerialNumber;
	TP7KeyEncryptionAlgoID fKeyEncryptionAlgorithm;
	TP7EncryptedKey fEncryptedKey;
};
typedef struct TP7RecipientInfo_ TP7RecipientInfo;
#define SLIM_PKCS7_RecipientInfo (SLIM_ASN1SCHEMAID_PKCS7_START + 48)

/* RecipientInfos ::= SET OF RecipientInfo */
typedef TASN1Object TP7RecipientInfos;
#define SLIM_PKCS7_RecipientInfos (SLIM_ASN1SCHEMAID_PKCS7_START + 53)

/* EncryptedContent ::= OCTET STRING */
typedef TASN1Object TP7EncryptedContent;
#define SLIM_PKCS7_EncryptedContent (SLIM_ASN1SCHEMAID_PKCS7_START + 55)

/*
	EncryptedContentInfo ::= SEQUENCE {
	  contentType  ContentType,
	  contentEncryptionAlgorithm  ContentEncryptionAlgorithmIdentifier,
	  encryptedContent  [0] IMPLICIT EncryptedContent OPTIONAL
	}
*/
struct TP7EncryptedContentInfo_ {
	TASN1Object fSEQUENCE;
	TP7ContentType fContentType;
	TP7ContentEncryptionAlgoID fContentEncryptionAlgorithm;
	TP7EncryptedContent fEncryptedContent;
};
typedef struct TP7EncryptedContentInfo_ TP7EncryptedContentInfo;
#define SLIM_PKCS7_EncryptedContentInfo (SLIM_ASN1SCHEMAID_PKCS7_START + 57)

/*
	EnvelopedData ::= SEQUENCE {
	  version  Version,
	  recipientInfos  RecipientInfos,
	  encryptedContentInfo  EncryptedContentInfo
	}
*/
struct TP7EnvelopedData_ {
	TASN1Object fSEQUENCE;
	TP7Version fVersion;
	TP7RecipientInfos fRecipientInfos;
	TP7EncryptedContentInfo fEncryptedContentInfo;
};
typedef struct TP7EnvelopedData_ TP7EnvelopedData;
#define SLIM_PKCS7_EnvelopedData (SLIM_ASN1SCHEMAID_PKCS7_START + 61)

/*
	SignedAndEnvelopedData ::= SEQUENCE {
	  version  Version,
	  recipientInfos  RecipientInfos,
	  digestAlgorithms  DigestAlgorithmIdentifiers,
	  encryptedContentInfo  EncryptedContentInfo,
	  certificates  [0] IMPLICIT ExtendedCertificatesOrCertificates OPTIONAL,
	  crls  [1] IMPLICIT CertificateRevocationLists OPTIONAL,
	  signerInfos  SignerInfos
	}
*/
struct TP7SignedAndEnvelopedData_ {
	TASN1Object fSEQUENCE;
	TP7Version fVersion;
	TP7RecipientInfos fRecipientInfos;
	TP7DigestAlgoIDs fDigestAlgorithms;
	TP7EncryptedContentInfo fEncryptedContentInfo;
	TP7ExtCertsOrCerts fCertificates;
	TP7CRLs fCRLs;
	TP7SignerInfos fSignerInfos;
};
typedef struct TP7SignedAndEnvelopedData_ TP7SignedAndEnvelopedData;
#define SLIM_PKCS7_SignedAndEnvelopedData (SLIM_ASN1SCHEMAID_PKCS7_START + 67)

/* Digest ::= OCTET STRING */
typedef TASN1Object TP7Digest;
#define SLIM_PKCS7_Digest (SLIM_ASN1SCHEMAID_PKCS7_START + 75)

/*
	DigestedData ::= SEQUENCE {
	  version  Version,
	  digestAlgorithm  DigestAlgorithmIdentifier,
	  contentInfo  ContentInfo,
	  digest  Digest
	}
*/
struct TP7DigestedData_ {
	TASN1Object fSEQUENCE;
	TP7Version fVersion;
	TP7DigestAlgoID fDigestAlgorithm;
	TP7ContentInfo fContentInfo;
	TP7Digest fDigest;
};
typedef struct TP7DigestedData_ TP7DigestedData;
#define SLIM_PKCS7_DigestedData (SLIM_ASN1SCHEMAID_PKCS7_START + 76)

/*
	EncryptedData ::= SEQUENCE {
	  version  Version,
	  encryptedContentInfo  EncryptedContentInfo
	}
*/
struct TP7EncryptedData_ {
	TASN1Object fSEQUENCE;
	TP7Version fVersion;
	TP7EncryptedContentInfo fEncryptedContentInfo;
};
typedef struct TP7EncryptedData_ TP7EncryptedData;
#define SLIM_PKCS7_EncryptedData (SLIM_ASN1SCHEMAID_PKCS7_START + 81)

#define SLIM_ASN1SCHEMAID_PKCS7_END (SLIM_ASN1SCHEMAID_PKCS7_START + 84)
#else
#define SLIM_ASN1SCHEMAID_PKCS7_END SLIM_ASN1SCHEMAID_PKCS6_END
#endif /* SLIM_CONFIG_USE_PKCS7 */

/*========== PKCS8 ========== */
#define SLIM_ASN1SCHEMAID_PKCS8_START SLIM_ASN1SCHEMAID_PKCS7_END

/* Version ::= INTEGER */
typedef TASN1Object TP8Version;
#define SLIM_PKCS8_Version (SLIM_ASN1SCHEMAID_PKCS8_START + 0)

/* PrivateKeyAlgorithmIdentifier ::= AlgorithmIdentifier */
typedef TA1AlgoID TP8PrivateKeyAlgoID;
#define SLIM_PKCS8_PrivateKeyAlgoID (SLIM_ASN1SCHEMAID_PKCS8_START + 1)

/* PrivateKey ::= OCTET STRING */
typedef TASN1Object TP8PrivateKey;
#define SLIM_PKCS8_PrivateKey (SLIM_ASN1SCHEMAID_PKCS8_START + 2)

/*
	PrivateKeyInfo ::= SEQUENCE {
	  version  Version,
	  privateKeyAlgorithm  PrivateKeyAlgorithmIdentifier,
	  privateKey  PrivateKey,
	  attributes  [0] IMPLICIT Attributes OPTIONAL
	}
*/
struct TP8PrivateKeyInfo_ {
	TASN1Object fSEQUENCE;
	TP8Version fVersion;
	TP8PrivateKeyAlgoID fPrivateKeyAlgorithm;
	TP8PrivateKey fPrivateKey;
	TX501Attributes fAttributes;
};
typedef struct TP8PrivateKeyInfo_ TP8PrivateKeyInfo;
#define SLIM_PKCS8_PrivateKeyInfo (SLIM_ASN1SCHEMAID_PKCS8_START + 4)

/* EncryptionAlgorithmIdentifier ::= AlgorithmIdentifier */
typedef TA1AlgoID TP8EncryptionAlgoID;
#define SLIM_PKCS8_EncryptionAlgoID (SLIM_ASN1SCHEMAID_PKCS8_START + 9)

/* EncryptedData ::= OCTET STRING */
typedef TASN1Object TP8EncryptedData;
#define SLIM_PKCS8_EncryptedData (SLIM_ASN1SCHEMAID_PKCS8_START + 10)

/*
	EncryptedPrivateKeyInfo ::= SEQUENCE {
	  encryptionAlgorithm  EncryptionAlgorithmIdentifier,
	  encryptedData  EncryptedData
	}
*/
struct TP8EncryptedPrivateKeyInfo_ {
	TASN1Object fSEQUENCE;
	TP8EncryptionAlgoID fEncryptionAlgorithm;
	TP8EncryptedData fEncryptedData;
};
typedef struct TP8EncryptedPrivateKeyInfo_ TP8EncryptedPrivateKeyInfo;
#define SLIM_PKCS8_EncryptedPrivateKeyInfo (SLIM_ASN1SCHEMAID_PKCS8_START + 11)

#define SLIM_ASN1SCHEMAID_PKCS8_END (SLIM_ASN1SCHEMAID_PKCS8_START + 14)

/*========== PKCS9 ========== */
#define SLIM_ASN1SCHEMAID_PKCS9_START SLIM_ASN1SCHEMAID_PKCS8_END

/*
	emailAddress ATTRIBUTE ::= {
	  WITH SYNTAX IA5String (SIZE(1..pkcs-9-ub-emailAddress))
	  EQUALITY MATCHING RULE pkcs9CaseIgnoreMatch
	  ID pkcs-9-at-emailAdress
	}
*/
typedef TASN1Object TP9EmailAddress;
#define SLIM_PKCS9_EmailAddress (SLIM_ASN1SCHEMAID_PKCS9_START + 0)

/*
	contentType ATTRIBUTE ::= {
	  WITH SYNTAX ContentType
	  EQUALITY MATCHING RULE objectIdentifierMatch
	  SINGLE VALUE TRUE
	  ID pkcs-9-at-contentType
	}

	ContentType ::= OBJECT IDENTIFIER
*/
typedef TASN1Object TP9ContentType;
#define SLIM_PKCS9_ContentType (SLIM_ASN1SCHEMAID_PKCS9_START + 1)

/*
	messageDigest ATTRIBUTE ::= {
	  WITH SYNTAX MessageDigest
	  EQUALITY MATCHING RULE octetStringMatch
	  SINGLE VALUE TRUE
	  ID pkcs-9-at-messageDigest
	}

	MessageDigest ::= OCTET STRING
*/
typedef TASN1Object TP9MessageDigest;
#define SLIM_PKCS9_MessageDigest (SLIM_ASN1SCHEMAID_PKCS9_START + 2)

/* 
	signingTime ATTRIBUTE ::= {
	  WITH SYNTAX SigningTime
	  EQUALITY MATCHING RULE signingTimeMatch
	  SINGLE VALUE TRUE
	  ID pkcs-9-at-signingTime
	}

	SigningTime ::= Time -- imported from ISO/IEC 9594-8
*/
typedef TASN1Time TP9SigningTime;
#define SLIM_PKCS9_SigningTime (SLIM_ASN1SCHEMAID_PKCS9_START + 3)

/*
	randomNonce ATTRIBUTE ::= {
	  WITH SYNTAX RandomNonce
	  EQUALITY MATCHING RULE octetStringMatch
	  SINGLE VALUE TRUE
	  ID pkcs-9-at-randomNonce
	}

	RandomNonce ::= OCTET STRING (SIZE(4..MAX)) -- At least four bytes long
*/
typedef TASN1Object TP9RandomNonce;
#define SLIM_PKCS9_RandomNonce (SLIM_ASN1SCHEMAID_PKCS9_START + 4)

/*
	sequenceNumber ATTRIBUTE ::= {
	  WITH SYNTAX SequenceNumber
	  EQUALITY MATCHING RULE integerMatch
	  SINGLE VALUE TRUE
	  ID pkcs-9-at-sequenceNumber
	}

	SequenceNumber ::= INTEGER (1..MAX)
*/
typedef TASN1Object TP9SequenceNumber;
#define SLIM_PKCS9_SequenceNumber (SLIM_ASN1SCHEMAID_PKCS9_START + 5)

/*
	friendlyName ATTRIBUTE ::= {
	  WITH SYNTAX BMPString (SIZE(1..pkcs-9-ub-friendlyName))
	  EQUALITY MATCHING RULE caseIgnoreMatch
	  SINGLE VALUE TRUE
	  ID pkcs-9-at-friendlyName
	}
*/
typedef TASN1Object TP9FriendlyName;
#define SLIM_PKCS9_FriendlyName (SLIM_ASN1SCHEMAID_PKCS9_START + 6)

/*
	localKeyId ATTRIBUTE ::= {
	  WITH SYNTAX OCTET STRING
	  EQUALITY MATCHING RULE octetStringMatch
	  SINGLE VALUE TRUE
	  ID pkcs-9-at-localKeyId
	}
*/
typedef TASN1Object TP9LocalKeyId;
#define SLIM_PKCS9_LocalKeyId (SLIM_ASN1SCHEMAID_PKCS9_START + 7)

#define SLIM_ASN1SCHEMAID_PKCS9_END (SLIM_ASN1SCHEMAID_PKCS9_START + 8)

/*========== PKCS12 ========== */
#ifdef SLIM_CONFIG_USE_PKCS12
#define SLIM_ASN1SCHEMAID_PKCS12_START SLIM_ASN1SCHEMAID_PKCS9_END

/*
	MacData ::= SEQUENCE {
	  mac         DigestInfo,
	  macSalt     OCTET STRING,
	  iterations  INTEGER DEFAULT 1
	  -- Note: The default is for historical reasons
	  --       and its use is deprecated. A higher
	  --       value, like 1024, is recommended.
	}
*/
struct TP12MacData_ {
	TASN1Object fSEQUENCE;
	TA1DigestInfo fMac;
	TASN1Object fMacSalt;
	TASN1Object fIterations;
};
typedef struct TP12MacData_ TP12MacData;
#define SLIM_PKCS12_MacData (SLIM_ASN1SCHEMAID_PKCS12_START + 0)

/*
	PFX ::= SEQUENCE {
	  version  INTEGER,
	  authSafe  ContentInfo,
	  macData  MacData OPTIONAL
	}

	-- The "version" is v3(3) for PKCS#12-v1.0.
	-- It's public-key integrity mode if "authSafe.ContentType" is PKCS#7.SignedData.
	-- It's password integrity mode if "authSafe.ContentType" is PKCS#7.Data.
	-- The "macData" is present oly in password integrity mode.
*/
struct TP12PFX_ {
	TASN1Object fSEQUENCE;
	TASN1Object fVersion;
	TP7ContentInfo fAuthSafe;
	TP12MacData fMacData;
};
typedef struct TP12PFX_ TP12PFX;
#define SLIM_PKCS12_PFX (SLIM_ASN1SCHEMAID_PKCS12_START + 4)

/*
	AuthenticatedSafe ::= SEQUENCE OF ContentInfo
	  -- Data if unencrypted
	  -- EncryptedData if password-encrypted
	  -- EnvelopedData if public key-encrypted
*/
typedef TASN1Object TP12AuthSafe;
#define SLIM_PKCS12_AuthenticatedSafe (SLIM_ASN1SCHEMAID_PKCS12_START + 8)

/* PKCS12Attribute ::= Attribute */
typedef TX501Attribute TP12Attribute;
#define SLIM_PKCS12_Attribute (SLIM_ASN1SCHEMAID_PKCS12_START + 10)

/*
	SafeBag ::= SEQUENCE {
	  bagId  OBJECT IDENTIFER,
	  bagValue  [0] EXPLICIT ANY DEFINED BY bagId,
	  bagAttributes  SET OF PKCS12Attribute OPTIONAL
	}
*/
typedef TASN1Object TP12BagAttributes;

struct TP12SafeBag_ {
	TASN1Object fSEQUENCE;
	TASN1Object fBagId;
	TASN1Object fBagValue;
	TP12BagAttributes fBagAttributes;
};
typedef struct TP12SafeBag_ TP12SafeBag;
#define SLIM_PKCS12_BagAttributes (SLIM_ASN1SCHEMAID_PKCS12_START + 11)
#define SLIM_PKCS12_SafeBag (SLIM_ASN1SCHEMAID_PKCS12_START + 15)

/* SafeContents ::= SEQUENCE OF SafeBag */
typedef TASN1Object TP12SafeContents;
#define SLIM_PKCS12_SafeContents (SLIM_ASN1SCHEMAID_PKCS12_START + 19)

/* KeyBag ::= PrivateKeyInfo */
typedef TP8PrivateKeyInfo TP12KeyBag;
#define SLIM_PKCS12_KeyBag (SLIM_ASN1SCHEMAID_PKCS12_START + 21)

/* PKCS8ShroudedKeyBag ::= EncryptedPrivateKeyInfo */
typedef TP8EncryptedPrivateKeyInfo TP12ShroudedKeyBag;
#define SLIM_PKCS12_ShroudedKeyBag (SLIM_ASN1SCHEMAID_PKCS12_START + 22)

/*
	CertBag ::= SEQUENCE {
	  certId  OBJECT IDENTIFIER,
	  certValue  [0] EXPLICIT ANY DEFINED BY certId
	}
*/
struct TP12CertBag_ {
	TASN1Object fSEQUENCE;
	TASN1Object fCertId;
	TASN1Object fCertValue;
};
typedef struct TP12CertBag_ TP12CertBag;
#define SLIM_PKCS12_CertBag (SLIM_ASN1SCHEMAID_PKCS12_START + 25)

/*
	CRLBag ::= SEQUENCE {
	  crlId  OBJECT IDENTIFIER,
	  crlValue  [0] EXPLICIT ANY DEFINED BY crlId
	}
*/
struct TP12CRLBag_ {
	TASN1Object fSEQUENCE;
	TASN1Object fCrlId;
	TASN1Object fCrlValue;
};
typedef struct TP12CRLBag_ TP12CRLBag;
#define SLIM_PKCS12_CRLBag (SLIM_ASN1SCHEMAID_PKCS12_START + 30)

/*
	SecretBag ::= SEQUENCE {
	  secretTypeId  OBJECT IDENTIFIER,
	  secretValue  [0] EXPLICIT ANY DEFINED BY secretTypeId
	}
*/
struct TP12SecretBag_ {
	TASN1Object fSEQUENCE;
	TASN1Object fSecretTypeId;
	TASN1Object fSecretValue;
};
typedef struct TP12SecretBag_ TP12SecretBag;
#define SLIM_PKCS12_SecretBag (SLIM_ASN1SCHEMAID_PKCS12_START + 35)

/* SafeContentsBag ::= SafeContents */
typedef TP12SafeContents TP12SafeContentsBag;
#define SLIM_PKCS12_SafeContentsBag (SLIM_ASN1SCHEMAID_PKCS12_START + 38)

/*
	pkcs-12PbeParams ::= SEQUENCE {
	  salt OCTET STRING,
	  iterations INTEGER
	}
*/
struct TP12PbeParams_ {
	TASN1Object fSEQUENCE;
	TASN1Object fSalt;
	TASN1Object fIterations;
};
typedef struct TP12PbeParams_ TP12PbeParams;
#define SLIM_PKCS12_PbeParams (SLIM_ASN1SCHEMAID_PKCS12_START + 39)

#define SLIM_ASN1SCHEMAID_PKCS12_END (SLIM_ASN1SCHEMAID_PKCS12_START + 42)
#else
#define SLIM_ASN1SCHEMAID_PKCS12_END SLIM_ASN1SCHEMAID_PKCS9_END
#endif /* SLIM_CONFIG_USE_PKCS12 */

SLIM_END_C_LINKAGE

#endif /* SLIM_ASN1SCHM_H */
