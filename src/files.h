
int filesOpenFR  (const char* path); // Open file for only read
int filesOpenFRW (const char* path); // Open file for read end write
int filesClose(int fd); //return errors or 0

char *filesReadFd(int fd);

typedef void (*FileCallback)(const char *path, void *userdata);
void filesListByType(const char *dirpath, const char *type, FileCallback cb, void *userdata);
