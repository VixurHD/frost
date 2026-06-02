#include "utils.h"

#include <stdio.h>
#include <string.h>

#include <sys/stat.h>
#include <unistd.h>

#include <stdlib.h>

const char* get_home() {
    char *home = getenv("HOME");
    if (!home) {
        fprintf(stderr, "frost: the environment variable HOME could not be found");
        exit(1);
    }   return home;
}

void frost_init() {
    char* home = get_home();

    char path[512];

    snprintf(path, sizeof(path), "%s/.frost", home);
    mkdir(path, 0775);

    snprintf(path, sizeof(path), "%s/.frost/unpaked", home);
    mkdir(path, 0775);

    snprintf(path, sizeof(path), "%s/.frost/snapshots", home);
    mkdir(path, 0775);
}
