# Lecture 24/5/24

# Topic: Cloud Storage

## Types

![storage types](assets/storage_types.png)

### Block storage

- Data stored in fixed-size blocks. 
- It's raw and fast. 
- It's the foundation of the other storage solutions

### File storage

- Data is stored as structured files. 
- It uses a file system that controls how data is stored and retrieved. 
- file system can be local or distributed.
  - local: `ext4`
  - distributed: `NFS`(Network File System)

### Object storage

- Different paradigm. 
- Object: collection of data and its metadata.
- no hierarchy.
- fast access to objects

## Block storage

### 2024

Why do we still need block storage ?

Because other storage types are built on top of it.

Block storage is usually used in Storage Area Networks (SAN).

A SAN is a network that connects storage devices.

![SAN](assets/san.png)

### OpenStack Cinder

Block storage service

- abstract the storage technology
- virtualize the management
- unified API to attach storage to VMs

![Cinder architecture](assets/cinder_arch.png)

## File storage

A file is a logical thing. It's not guaranteed that the file is continuos in memory. The file system connects the logical and real view.

file system:

- logical, hierarchical view of the files
- provides mechanism for accessing the files
- local or distributed

### File system types

#### Local file systems

Run on single machine

#### Distributed file systems

Manage resources across different machines

- fault-tolerance
- store access sharing
- concurrent fast access

##### NFS Network File System

Provides file system access over a network

- based on the client-server paradigm
- caching to improve performance

![NFS architecture](assets/nfs_arch.png)

Flow

- To retrieve a file, the client interacts with the local vnode layer
- The vnode layer then sends the request via the NFS client
- The server passes it to the vnode layer on the remote host
- Finally, the remote vnode layer directs it to the remote file system

Cons:

- cache
  - size
  - location
  - writing policy
  - synchronization
- consistency

##### GPFS General Parallel File System

Focus on concurrency control.
Supports parallel I/O operations.

How it works:

- write-ahead log file
  - fast crash recovery
- data striping (striping segments data on different physical storage device)
  - 2 minimum replicas to guarantee consistency

##### GFS Google File System

custom built in house for google needs

key features:

- scalability and reliability
- relaxed consistency model
- push files in batch

key assumptions:

- reads are large and sequential or small and random
- write are sequential and append only, by multiple clients (log file is an example)

gfs is designed to run on commodity hardware. it's designed to run on hardware that continuously fails

how it works ?

- files are segment in very large chunks (64MB)
  - reduces chunk location requests
  - improve performance on large files
  - persistent network location to server location
- chunk are replicated on a minimum of 3 servers
- no cache at all. not in the client and not on the server

**master** in charge of the cluster state

control plane and data plane are separated.

slide 37 good pictures showing how the master works. arrow are logical connections. black lines are actual connections ?

GFS is an abstraction over the linux file system

## Object Storage

mix of block storage and file storage

every cloud provider has its own flavour.

we can call it software defined storage.

we take swift as an example.

slide 43 is a comparison of swift and classic file storage.

hierarchy: your account is the top level of hierarchy

- containers: namespace for objects. it's some kind of a folder
- storage policy: defines how data is stored
  - ex: a container should use only ssd
  - applied at container level
- ring
  - mapping data partitions and storage location
  - uses hash
  - i combine account, container and policy mapped to a particular location


Servers:

- proxy: front-end of the swift architecture
  - api endpoint
  - stuff...
- storage
  - object
    - serves binary data
  - container
    - handles listing of objects
  - account
    - list contents rather than objects
- consistency
  - replicator
    - ensure all replicas are in sync
  - updater
    - manages the replication process
  - auditors
    - craws local server checking integrity

Operations:

slide 59 for visual representation

- PUT
  - use the ring to get the hash and know which storage server to contact
  - replicator contacts object server and copies data to replicas

slide 62 is a recap on which storage you should use