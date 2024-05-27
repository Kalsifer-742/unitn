# Cloud storage

## Types

### Block storage

data stored in fixed-size blocks. it's raw and fast. it's the foundation of the other storage solutions

### File storage

data is stored as structured files. it uses a file system. file system can be local or distributed

### Object storage

completely different paradigm. an object is a collection of data and its metadata. no hierarchy.

## 2024

why do we still need block storage ? because other storage types are built on top of it.

Block storage is usually used in Storage Area Networks (SAN).

## OpenStack Cinder

block storage service

slide 18 architecture image

## File storage

a file is a logical things. it's not garanteed that the file is continuos in memory. the file system connects the logical and real view.

they provide a hierarchical view of the files

### File system types

#### Distributed file systems

##### NFS

based on the client-server paradigm.

slide 27 shows how it works.

obviously there are limitations due to network.

##### GPFS General Parallel File System

focus on concurrency control

parallel I/O operations

how it works ?

write ahead log file

data striping

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