#include "files.h"
#include <sys/file.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int filesOpenFR  (const char* path) {
    int fd = open(path, O_RDONLY);
    if (fd < 0) { return -1; };
    if (flock(fd, LOCK_SH) < 0) { close(fd); return -1; };
    return fd;
}

int filesOpenFRW (const char* path) {
    int fd = open(path, O_RDWR);
    if (fd < 0) { return -1; };
    if (flock(fd, LOCK_EX) < 0) { close(fd); return -1; };
    return fd;
}

int filesClose(int fd) {
    flock(fd, LOCK_UN);
    return close(fd);
}

char* filesReadFd(int fd) {
    off_t size = lseek(fd, 0, SEEK_END);
    if (size < 0) { return NULL; }
    lseek(fd, 0, SEEK_SET);

    char *buf = malloc(size + 1); if (!buf) { return NULL; }

    ssize_t i = read(fd, buf, size); if (i < 0) { free(buf); return NULL; }
    buf[i] = '\0';
    return buf;
}

void filesListByType(const char *dirpath, const char *type, FileCallback cd, void *userdata) {
    DIR *dir = opendir(dirpath);
    if (!dir) { perror("opendir"); return; }

    size_t type_len = strlen(type);

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        const char *name = entry->d_name;
        size_t len = strlen(name);

        if (len < type_len) { continue; }
        if (strcmp(name + len - type_len, type) == 0) {
            printf("%s", name);
            cd(name, userdata);
        }
    }
    closedir(dir);
}
