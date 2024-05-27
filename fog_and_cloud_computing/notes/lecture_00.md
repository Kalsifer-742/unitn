# Lecture 28/02/24

## General introduction

No business stuff this year. Past me was lying. No dedicated slides but still present.

Need for different environments, cpu isolation and spatial isolation

spatial isolation: if A crashes it doesn't have to affect B

## Definitions:

- Virtual Machine
  - software emulation of the physical machine
- Host OS
  - running on physical hardware 
- Guest OS
  - running on host os

- Hypervisor
  - virtualize stuff
  - assign set of resources
  - manage shared resources (arbitrating)
  - stripped down operating system. 99% linux based.
    - basic drivers
    - small attack surface

## Advantages of virtualization:

- isolation
- agility: control on the state of the app
  - run, restart, stop, snapshot ecc...
- replication
- assign different resources

## Disadvantages:

- overhead
  - multiple layers to go through

## Common of the shelf hardware (COTS)

- hardware is not important (within reason)
  - just buy the cheapest

## Lightweight virtualization, Containers:

- docker
- micro vms
- ecc...

less isolation, less security

## Cloud native

stuff already developed to be packaged and executed in containers. no more monolithic software.

## DevOps

Develop and Operate. Person which knows ho to do both things

TODO: read about DevOps

development strategy:
  - continuos loop development
  - continuos testing in the production environment

## Datacenter

IPS. Innovation -> Product -> Service

- economy of scale
- pay someone to do handle the infrastructure for you
- Big requirements

> Spoiler: On friday: Infrastructure as Code

ISP didn't sail the boat when it was time. They could have conquered the market.

## What is the course about

proceed to yap about what the course is about