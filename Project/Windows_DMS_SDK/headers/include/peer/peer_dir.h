#ifndef PEER_DIR_H
#define PEER_DIR_H

#define PEER_DIR_DIR_WILD_CARD	_T("\\*\0")
#define PEER_DIR_FILE_WILD_CARD	_T("\\\0")
#define PEER_DIR_PATH_BUFSIZE	1024

// directory entry structure
struct peer_dirent {
	long d_ino;								// inode number
	unsigned long d_off;					// offset to this dirent
	unsigned char d_type;
	char d_name[PEER_DIR_PATH_BUFSIZE];		// file name (null-terminated)
};

// DIR structure
typedef struct _PEER_DIR {
	HANDLE hFindFile;
	int nReadCount;
	struct peer_dirent rDirEnt;
} PEER_DIR;

// utility function to allocate a PEER_DIR struct
PEER_DIR *peer_dir_alloc(void);

// utility function to clean up a PEER_DIR struct
void peer_dir_free(PEER_DIR *dir);

// utility function to copy information from the WIN32_FIND_DATA to the dirent struct
void peer_dirent_extract(struct peer_dirent *prDirEnt, WIN32_FIND_DATA *pFindFileData);

slim_bool is_dots(const TCHAR *str);

#endif /* PEER_DIR_H */
