#ifndef FROST_ENV_H
#define FROST_ENV_H

typedef struct {
    char workspace[512];
    char archive[512];
    char symlink[512];
    char meta[512];
} WorkspacePaths;

typedef struct {
    char name[256];
    char created[32];
    char modified[32];
    bool autopick;
} WorkspaceMeta;

typedef struct {
    WorkspacePaths paths;
    WorkspaceMeta meta;
} Workspace;

const char* envCreateWorkspace(const char* name);

#endif
