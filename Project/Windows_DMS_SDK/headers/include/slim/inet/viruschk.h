/*
	viruschk.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/inet/viruschk.h 6     06/04/14 23:34 Yamabuti $ */

#ifndef SLIM_VIRUS_CHECKER_H
#define SLIM_VIRUS_CHECKER_H

SLIM_BEGIN_C_LINKAGE

#ifdef SLIM_CONFIG_USE_VIRUSCHECKER

enum {
	SLIM_VIRUSCHK_E_OBSOLETE_DB = SLIM_E_enum_tail - 1,
	SLIM_VIRUSCHK_E_LV1 = 1,
	SLIM_VIRUSCHK_E_LV2,
	SLIM_VIRUSCHK_E_LV3,
	SLIM_VIRUSCHK_E_LV4,
	SLIM_VIRUSCHK_E_LV5,
	SLIM_VIRUSCHK_E_LV6,
	SLIM_VIRUSCHK_E_LV7,
	SLIM_VIRUSCHK_E_LV8,
	SLIM_VIRUSCHK_E_LV9,
	SLIM_VIRUSCHK_E_LV10,
	SLIM_VIRUSCHK_E_end
};

enum {
	SLIM_VIRUSCHK_IGNORE_NONE = -2,
	SLIM_VIRUSCHK_IGNORE_ALL = -1,
	SLIM_VIRUSCHK_IGNORE_NEXT = 0,
	SLIM_VIRUSCHK_IGNORE_LV1,
	SLIM_VIRUSCHK_IGNORE_LV2,
	SLIM_VIRUSCHK_IGNORE_LV3,
	SLIM_VIRUSCHK_IGNORE_LV4,
	SLIM_VIRUSCHK_IGNORE_LV5,
	SLIM_VIRUSCHK_IGNORE_LV6,
	SLIM_VIRUSCHK_IGNORE_LV7,
	SLIM_VIRUSCHK_IGNORE_LV8,
	SLIM_VIRUSCHK_IGNORE_LV9,
	SLIM_VIRUSCHK_IGNORE_LV10,
	SLIM_VIRUSCHK_IGNOREs
};

enum {
	SLIM_VIRUSCHK_TYPE_CONTENT = 0,
	SLIM_VIRUSCHK_TYPE_URL,
	SLIM_VIRUSCHK_TYPEs
};


/* declare */
typedef struct TVirusChecker_ TVirusChecker;

/*
 * Log
 */
typedef struct TVirusCheckLog_ TVirusCheckLog;
typedef struct TVirusCheckLogClass_ TVirusCheckLogClass;
struct TVirusCheckLogClass_ {
	slim_int fType;
	slim_int (*fLength)(TVirusCheckLog *self);
	slim_bool (*fGetRawData)(TVirusCheckLog *self, slim_opaque *out_rawdata);
	slim_int (*fInit)(TVirusCheckLog *self, TVirusChecker *in_checker);
	void (*fTidy)(TVirusCheckLog *self);
};

struct TVirusCheckLog_ {
	TVirusCheckLogClass *fClass;
	slim_opaque fUserData;
};

/* content */
typedef struct TContentVirusCheckLogClass_ TContentVirusCheckLogClass;
struct TContentVirusCheckLogClass_ {
	TVirusCheckLogClass fBase;
};

typedef struct TContentVirusCheckLog_ TContentVirusCheckLog;
struct TContentVirusCheckLog_ {
	TVirusCheckLog fBase;
};

/* URL */
typedef struct TURLVirusCheckLogClass_ TURLVirusCheckLogClass;
struct TURLVirusCheckLogClass_ {
	TVirusCheckLogClass fBase;
};

typedef struct TURLVirusCheckLog_ TURLVirusCheckLog;
struct TURLVirusCheckLog_ {
	TVirusCheckLog fBase;
};

/*
 * Checker
 */

typedef struct TVirusCheckerClass_ TVirusCheckerClass;
struct TVirusCheckerClass_ {
	slim_int fType;
	TVirusCheckLogClass *fLogClass;
	slim_int (*fInit)(TVirusChecker *self);
	void (*fTidy)(TVirusChecker *self);
	void (*fIgnoreVirus)(TVirusChecker *self, slim_int in_method);
};

struct TVirusChecker_ {
	TVirusCheckerClass *fClass;
	slim_opaque fUserData;
};

/* content */
typedef struct TContentVirusChecker_ TContentVirusChecker;
typedef struct TContentVirusCheckerClass_ TContentVirusCheckerClass;
struct TContentVirusCheckerClass_ {
	TVirusCheckerClass fBase;
	void (*fSetMIMEType)(TContentVirusChecker *self, slim_int in_mimetype);
	void (*fSetCharSet)(TContentVirusChecker *self, slim_int in_charset);
	slim_int (*fAnalyze)(TContentVirusChecker *self, slim_byte *in_data, slim_int in_len, slim_bool in_eof, slim_int *out_safelen);
	slim_int (*fSafeLength)(TContentVirusChecker *self);
};

struct TContentVirusChecker_ {
	TVirusChecker fBase;
};

/* URL */
typedef struct TURLVirusChecker_ TURLVirusChecker;
typedef struct TURLVirusCheckerClass_ TURLVirusCheckerClass;
struct TURLVirusCheckerClass_ {
	TVirusCheckerClass fBase;
	slim_int (*fAnalyze)(TURLVirusChecker *self, slim_char *in_url, slim_int in_len, slim_int in_charset);
};

struct TURLVirusChecker_ {
	TVirusChecker fBase;
};

/*
 * Factory
 */
typedef struct TVirusCheckerFactory_ TVirusCheckerFactory;
struct TVirusCheckerFactory_ {
	TContentVirusCheckerClass *fContentCheckerClass;
	TURLVirusCheckerClass *fURLCheckerClass;
};

#endif

SLIM_END_C_LINKAGE
#endif
