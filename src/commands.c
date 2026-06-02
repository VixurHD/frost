#include "commands.h"

#include <stdio.h>

Command commands[] = {
    { "create", "Create a new frost workspace",           cmdCreate },
    { "pick",   "Create workspace and unpack snapshot in",     cmdPick   },
    { "snap",   "Save workspace state as a snapshot",     cmdSnap   },
    { "drop",   "Unmount and remove a workspace",         cmdDrop   },
    { "delete", "Permanently delete a saved snapshot",    cmdDelete },
    { NULL,      NULL,                                    NULL      }
};

void cmdCreate(const char *name) {
    printf("cmd_create");
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

