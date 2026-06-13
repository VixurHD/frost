#include "commands.h"
#include "files.h"
#include "env.h"

#include <stdio.h>
#include <string.h>

#define SPACE 10

Command commands[] = {
    { "help",   "Show this text",           cmdUsage },
    { "create", "Create a new frost workspace",           cmdCreate },
    { "pick",   "Create workspace and unpack snapshot in",     cmdPick   },
    { "snap",   "Save workspace state as a snapshot",     cmdSnap   },
    { "drop",   "Unmount and remove a workspace",         cmdDrop   },
    { "delete", "Permanently delete a saved snapshot",    cmdDelete },
    { NULL,      NULL,                                    NULL      }
};


void cmdUsage() {
    int space = 0;
    for (int i = 0; commands[i].name != NULL; ++i) {
        space = SPACE - strlen(commands[i].name);
        for (int j = 0; j < space; ++j) { printf(" "); };
        printf("%s\n", commands[i].name);
        for (int j = 0; j < SPACE; ++j) { printf(" "); };
        printf("%s\n\n", commands[i].desc);
    }
}

void cmdCreate(const char *name) {
    const char* file_name = envCreateWorkspace(name);
    if (file_name) {
        printf("Workspace %s successfully created", file_name);
    }
}
void cmdPick(const char *name) {
    printf("cmd_pick");
}

void cmdSnap(const char *name) {
    printf("cmd_snap");
}

void cmdDrop(const char *name) {
    printf("cmd_drop");
}

void cmdDelete(const char *name) {
    printf("cmd_delete");
}

