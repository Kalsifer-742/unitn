# Lecture 29/5/24

## Topic: Cloud Storage (1 hour)

## Distributed databases

Relational databases

Object oriented databases

NoSQL databases now more like not only SQL

Database properties ACID:

- atomicity
- consistency
- isolation
- durability

ACID not applicable when network is involved

so we use BASE

- basically available
  - consistency is sacrificed for availability
- soft state
  - data is allowed to be out of sync for some time
- eventually consistent
  - after a write is performed at a certain point the system will converge

we always make a tradeoff for performance and availability. we want to always be able to answer the queries

### Locks and consesus

- Locks
  - ex: student taking a seat in the library
- Consesus
  - mechanism to ensure that all nodes agree on the same state
  - ex: friends deciding where to go for dinner

### CAP theorem

distributed systems cannot guarantee

- consistency
- availability
- partition tolerance
  - nodi che vengono tagliati fuori dalla rete di nodi
  - network error o chissà cosa
  - il master può rimanere isolato e quindi i nodi rimasti eleggono un nuovo master

grafo insiemi pag 77

### Google Bigtable GBT

- sparse (sparse matrix)
- distributed
- multi-dimensional sorted map
  - key-value store

explanation:

- data model
- tablets
- tablet servers and master
- ecc...

#### Table

- key is unique
- we dont'need to insert null
- multiple values on the same cell with an history

tables can grow without limit

#### Tablet

collection of rows of a table

physical rapresentation of a row in page 82

each tablet goes into a block (logic block not actual block on the disk)

ex: block 0 rows 1 to 3

tablets need to be localized in the cluster

hierarchy of tablets to find all the tablet like a tree

root -> metadata tablets -> tablets

commit log tablets to store uncommitted tablets

data is store using the GFS

#### Tablet server

handle tablets

- read and write
- split tablets
- stateless

clients communicate with tablet server

there is a master tablet server

#### Chubby

distribute lock service

chubby ensures that there is only one master at a time

#### "DNS"

dns like tablet retrieve

- contact tablet server
- find root tablet
- go to metadata tablet
- go to tablet

#### Master startup and locks

#### Tablets merging and splitting

master server -> merging

tablet server -> splitting

write ahead commit log

merge read because in memory we could have newer informations

merging is periodic

- minor compaction
- major compaction
  - deframmentazione