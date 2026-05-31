[en][ru](./README.ru.md)
# frost
> Temporary workspaces with snapshots. All the mess disappears on its own — save only what matters.

## Idea
`frost` is a utility designed to make creating temporary tmpfs directories fast and convenient. Everything inside frost directories exists only until reboot and won't clutter your home directory with junk. Everything is saved into neat snapshots: manually or automatically — fully configurable to your needs.

## Project Status
! Currently only a bash prototype exists, made purely to feel out whether this kind of workflow is actually convenient. The real implementation is being rewritten in `C`.

## How It Works

### Filesystem Layout
```
~/myproject -> ~/.frost/unpacked/myproject/  | Symlink to the snapshot directory
~/.frost/                                    |
       ./unpacked/                           | Directory for unpacked snapshots
               ./myproject/                  | tmpfs with the unpacked snapshot
               myproject.meta                | Metadata for the snapshot of the same name
       ./snapshots/                          | Directory for stored snapshots
                 ./myproject.tar.gz          | Saved snapshot
```
On reboot, all tmpfs mounts are unmounted, symlinks and frost workspaces are removed. Snapshots remain untouched.

### Commands
```bash
frost create [name]  # Create a new temporary workspace
frost pick [name]    # Unpack a snapshot (mounts tmpfs, creates symlink, copies metadata)
frost snap [name]    # Snapshot the current state of the frost workspace you're in
frost drop [name]    # Remove a workspace (current or by name) (NOT the snapshot)
```
When inside an unpacked workspace, `name` can be omitted.

### Metadata
Each frost workspace has an associated metadata file:
```json
{
    "name": "myproject",
    "created": "2026-01-01T12:37:37",
    "modified": "2026-01-01T15:37:37",
    "autopick": true
}
```
`autopick: true` — after reboot the daemon will not clean up the workspace and will automatically run `frost pick` for it instead.
