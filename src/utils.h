#ifndef FROST_UTILS_H
#define FROST_UTILS_H

const char *getHome();

void frostInit();

typedef struct {
    const char *name;
    int *counter;
} UniqueFileName;

void uniqueFileName(const char *path, void *userdata);

#endif
