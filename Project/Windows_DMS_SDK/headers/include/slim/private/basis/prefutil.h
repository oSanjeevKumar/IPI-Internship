/*
	prefutil.c
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/basis/prefutil.h 11    06/07/11 15:44 Yamabuti $ */

#ifndef SLIM_UTIL_PREF_H_PRIVATE
#define SLIM_UTIL_PREF_H_PRIVATE

#define SLIM_PREF_TEST_AND_SET_SCALAR(self,set,attr) { \
	if ((set)->fFlag. attr) { \
		(self)-> attr = (set)->fPref. attr; \
 	} \
}

#define SLIM_PREF_TEST_AND_SET_STRING(self,set,attr) { \
	if ((set)->fFlag. attr) { \
		if ((set)->fPref. attr == slim_nil) { \
			if ((self)-> attr) TString_Delete((self)-> attr); \
			(self)-> attr = slim_nil; \
		} else { \
			TString str; \
			str = String_NewTS((set)->fPref. attr); \
			if (str) { \
				if ((self)-> attr) TString_Delete((self)-> attr); \
				(self)-> attr = str; \
			} \
		} \
 	} \
}

#define SLIM_PREF_TEST_AND_SET_FIXEDSTRING(self,set,attr) { \
	if ((set)->fFlag. attr) { \
		if ((set)->fPref. attr == slim_nil) { \
			if ((self)-> attr) TFixedString_Delete((self)-> attr); \
			(self)-> attr = slim_nil; \
		} else { \
			TFixedString str; \
			str = FixedString_NewFS((set)->fPref. attr); \
			if (str) { \
				if ((self)-> attr) TFixedString_Delete((self)-> attr); \
				(self)-> attr = str; \
			} \
		} \
 	} \
}

#define SLIM_PREF_TEST_AND_SET_URLSTRING(self,set,attr) { \
	if ((set)->fFlag. attr) { \
		if ((set)->fPref. attr == slim_nil) { \
			if ((self)-> attr) TURLString_Delete((self)-> attr); \
			(self)-> attr = slim_nil; \
		} else { \
			TURLString str; \
			str = URLString_NewUS((set)->fPref. attr); \
			if (str) { \
				if ((self)-> attr) TURLString_Delete((self)-> attr); \
				(self)-> attr = str; \
			} \
		} \
 	} \
}

#endif

