#include "commands.h"
#include "utils.h"

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    frostInit();

    if (argc < 2) {
        cmdUsage();
        return 0;
    }

    const char *cmd  = argv[1];
    const char *name = argc >= 3 ? argv[2] : NULL;

    for (int i = 0; commands[i].name != NULL; i++) {
        if (strcmp(cmd, commands[i].name) == 0) {
            commands[i].fn(name);
            return 0;
        }
    }

    fprintf(stderr, "frost: unknown command '%s'\n", cmd);

    return 1;
}
