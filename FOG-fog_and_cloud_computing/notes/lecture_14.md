# Lecture 17/04/24

# Topic: Cloud networking

Slides: 35 - 57

## Topologies

### Clos Network

Multistage switching network

`k >= n`: math rule that ensures that the network is non blocking

### Fat tree

Imagine to fold a clos network -> fat tree

Proposed ip addressing. It can be a good way to organize IPs.

Suffix table is an additional routing table. It's used to do some spreading/load balancing 

il suffix table regola le connessioni verso l'alto. fa una specie di spreading/load balancing upward.

Congestions are a problem. Congestions are common.
It's difficult to exploit the available capacity of your network.

### Workloads

Flows

- small: 55%
- medium: 40%
- large: 5%

How to balance workloads ?

#### Solutions

##### Hedera

I assume that small flows don't saturate the network.
I Consider only elephant flows. For each elephant flow I search a free path to be used only for that flow.

##### CONGA

##### DRILL

There are even more solutions. Every solution has pros and cons.

