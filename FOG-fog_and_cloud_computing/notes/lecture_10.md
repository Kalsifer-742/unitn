# Lecture 03/04/23

# Topic: Cloud virtualisation

## Cloud Virtualization

Difference in disk space between full isolation and lightweight isolation is not huge.
This is because the kernel is the only part that is reused. And the kernel is not something huge(the linux kernel is about 100Mb)

## Docker

Important change of perspective. Docker focuses on applications.
It aims to be easy for the user.

It's different from LXC which is a user for system administrators.

### Union File System

It's a file system that works on top of other file-systems.
It is more of a mounting mechanism than a file system (it mounts multiple directories to a singel root)

As an example think of `/mnt` where you can have and `ext3` usb and a `ext4` disk mounted at the same time.

### Docker layered file system

Docker uses a layered file system.

### Properties

- Copy on Write (CoW)
- Simulation of removal by whiteout file
- Only diffs are stored

### Automatic build by Dockerfile

### Docker compose

Automatic setup for multi-container Docker applications

### Orchestration

Kubernetes