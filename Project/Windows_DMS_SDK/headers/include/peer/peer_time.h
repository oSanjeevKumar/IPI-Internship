#ifndef PEER_TIME_H
#define PEER_TIME_H

#define COPY_TM_TO_DD(dd, tm) {	\
	(dd)->year = (tm)->tm_year;	\
	(dd)->mon = (tm)->tm_mon;	\
	(dd)->mday = (tm)->tm_mday;	\
	(dd)->wday = (tm)->tm_wday;	\
	(dd)->yday = (tm)->tm_yday;	\
	(dd)->hour = (tm)->tm_hour;	\
	(dd)->min = (tm)->tm_min;	\
	(dd)->sec = (tm)->tm_sec;	\
	(dd)->msec = 0; }

#endif /* PEER_TIME_H */
