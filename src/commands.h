#ifndef FROST_COMMANDS_H
#define FROST_COMMANDS_H

typedef struct {
    const char *name;
    const char *description;
    void (*fn)(const char*);
} Command;

extern Command commands[];

void cmdCreate(const char *name); // Create frost-env
void cmdPick(const char *name);   // Pick and init frost-env in saves snapshots
void cmdSnap(const char *name);   // Save snapshot
void cmdDrop(const char *name);   // Drop frost-env (onmount and delete simlinks)
void cmdDelete(const char *name); // Delete snapshot(s)

#endif
