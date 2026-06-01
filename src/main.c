#include "commands.h"

#include <stdio.h>
#include <string.h>

typedef struct {
    const char *name;
    const char *description;
    void (*fn)(const char*);
} Command;

static Command commands[] = {
    { "create", "desc", cmd_create },
    { "pick",   "desc", cmd_pick },
    { "snap",   "desc", cmd_snap },
    { "drop",   "desc", cmd_drop },
    { "delete", "desc", cmd_delete },
    { NULL,     NULL,   NULL }
};

int main(int argc, char *argv[]) {

    const char *cmd  = argv[1];
    const char *name = argc >= 3 ? argv[2] : NULL;

    for (int i = 0; commands[i].name != NULL; i++) {
        if (strcmp(cmd, commands[i].name) == 0) {
            commands[i].fn(name);
            return 0;
        }
    }
    fprintf(stderr, "frost: unknown command '%s'\n", cmd);

    return 0;
}
