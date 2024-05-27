# Lecture 05/04/24

## Docker

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

## Data center networks

We distinguish 2 types of traffic in a datacenter:

- North-South traffic
    - this is the customer facing traffic
- East-West traffic
    - traffic between serveres in the datacenter

Machine to machine traffic is the most intensive and problematic.
Think about distributed workloads.

We need:

- Any-to-any communication
- Low latency

### _Datacenter network is a giant switch_

This is what we want to achieve. In reality we build a network of switches that we call fabric.

The network is gerarchical. We distinguish some layers:

- Layer 3
    - Core layer - Core router
    - Aggregation Layer - Access router
Layer 2
    - Edge Layer - Switch
    - Rack Layer - Rack of server with Top of Rack switch(ToR)

POD: Edge Layer + Racks

### Layer 2 vs Layer 3

- Ethernet switching (layer 2)
    - Pros
        - Fixed IP addresses and auto-configuration (plug & play)
    - Cons
        - Broadcast limit scale (ARP)
        - Spanning Tree Protocol
- IP routing (layer 3)
    - Pros
        - Scalability through hierarchical addressing
        - Multipath routing through equal-cost multipath
    - Cons
        - More complex configuration
        - Cannot migrate without changing IP address

### Biscetion bandwidth

[Alternative explanation](https://networkengineering.stackexchange.com/questions/29660/significance-of-bisection-bandwidth-full-bisection-bandwidth-subscription-and)

When you bisect a network, such as a data center, the bisection bandwidth is the bandwidth usable to get from one side of the bisection to the other.

Full bandwidth can be achieved with tree topology but it's to expensive.

#### Oversubscription

Needed to lower the cost. It consists on providing less than full bandwidth.

#### Topologies

We need to find alternatives to make things easier for us.

Examples:

- Fat Tree topology

##### interconnection netoworks

Core concepts:

- Network
    - nodes and links
- Interconnection network
    - non-blocking
        - it is possible to connect any permutation of sources and destinations at any time
    - blocking
        - you can't
- n-way node
    - n ports for n communication links
- node degree
    - number of connected links