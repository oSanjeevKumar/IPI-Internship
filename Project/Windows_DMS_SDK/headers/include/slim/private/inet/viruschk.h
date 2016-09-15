/*
	viruschk.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/inet/viruschk.h 8     06/04/14 23:34 Yamabuti $ */

#ifndef SLIM_VIRUS_CHECKER_H_PRIVATE
#define SLIM_VIRUS_CHECKER_H_PRIVATE

SLIM_BEGIN_C_LINKAGE

#ifdef SLIM_CONFIG_USE_VIRUSCHECKER

/* Log */
#define TVirusCheckLog_Type(self) ((self)->fClass->fType)
#define TVirusCheckLog_UserData(self) ((self)->fUserData)
#define TVirusCheckLog_SetUserData(self, data) ((self)->fUserData = (data))


#define TContentVirusCheckLog_Class(self) ((TContentVirusCheckLogClass *)(self)->fBase.fClass)



#define TURLVirusCheckLog_Class(self) ((TURLVirusCheckLogClass *)(self)->fBase.fClass)

/* Checker */
#define TVirusChecker_Type(self) ((self)->fClass->fType)
#define TVirusChecker_UserData(self) ((self)->fUserData)
#define TVirusChecker_SetUserData(self, data) ((self)->fUserData = (data))


#define TContentVirusChecker_Class(self) ((TContentVirusCheckerClass *)(self)->fBase.fClass)


#define TURLVirusChecker_Class(self) ((TURLVirusCheckerClass *)(self)->fBase.fClass)

/* Factory */
#define TVirusCheckerFactory_NewContentChecker(self,oc) (TVirusCheckerFactory_NewChecker((self), SLIM_VIRUSCHK_TYPE_CONTENT,(TVirusChecker **)(oc)))
#define TVirusCheckerFactory_NewURLChecker(self,oc) (TVirusCheckerFactory_NewChecker((self), SLIM_VIRUSCHK_TYPE_URL,(TVirusChecker **)(oc)))

#endif

SLIM_END_C_LINKAGE
#endif /* SLIM_VIRUS_CHECKER_H */
