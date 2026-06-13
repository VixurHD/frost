#include "utils.h"

#include <stdio.h>
#include <string.h>

#include <sys/stat.h>
#include <unistd.h>

#include <stdlib.h>
const char* getHome() {
    char *home = getenv("HOME");
    if (!home) {
        fprintf(stderr, "frost: the environment variable HOME could not be found");
        exit(1);
    }   return home;
}

void frostInit() {
    char* home = getHome();

    char path[512];

    snprintf(path, sizeof(path), "%s/.frost", home);
    mkdir(path, 0775);

    snprintf(path, sizeof(path), "%s/.frost/unpaked", home);
    mkdir(path, 0775);

    snprintf(path, sizeof(path), "%s/.frost/snapshots", home);
    mkdir(path, 0775);
}

void uniqueFileName(const char *path, void *userdata) {
    UniqueFileName *ctx = (UniqueFileName *)userdata;
    const char* name = ctx->name;
    int* counter = ctx->counter;
    const char* base_name_ptr_on_path = strrchr(path, '/');
    if (base_name_ptr_on_path != NULL) {
        base_name_ptr_on_path += 1;
    } else {
        base_name_ptr_on_path = path;
    }

    char* base_name = malloc(255);
    snprintf(base_name, 255, base_name_ptr_on_path);

    char* dot = strrchr(base_name, '.');
    if (dot != NULL) { *dot = '\0'; }

    char *dest = malloc(255);
    if (*counter == 0) { snprintf(dest, 255, "%s", name); }
    else { snprintf(dest, 255, "%s%02d", name, *counter); }

    if (strcmp(dest, base_name) == 0) {
        *counter += 1;
    }
    free(dest);
    free(base_name);
}

