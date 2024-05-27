# Lecture 27/03/24

# Topic: Cloud virtualisation

## I/O Virtualization

- Device emulation
  - multiple vm can be on the same network interface. The VMM emulate stuff in some ways internally.
- Para-virtualized device
- Direct assignment

### Device Emulation

It's similar to Full Virtualisation for the CPU.
- The VMM traps everytime the guest OS tries to access the peripheral.
- Easy for the user but pretty slow.
- The VMM can expose whatever driver it wants.

## Para Virtualization

It's the same as Paravirtualisation for the CPU. In this mode we have less context switches.

It allows the process of memory ballonning. With this method the VMM is able allocate only the memory that it is actually used by the guest and in need increase the amount of memory reserved to that guest.

### Direct assignment

Example: PCI passthrough.

#### IOMMU

Basically it's a MMU but for IO.
It's needed because when using DMA we have to translate from guest-physical address to host-physical address.

#### SR-IOV

PCI standard that enables multiplexing of a single device between multiple VMS (It doesn't work for everything).
It enables the device to present multiple virtual devices.
Example: Network card shared among 2 VMS

## Hypervisor

- Type 1
  - Bare metal.
  - You need the correct drivers.
  - It's a stripped down OS.
- Type 2
  - Run as a normal application on the Host.
  - Virtualbox
- Hybrid
  - Hypervisor implemented in the host kernel. It runs alongside the host OS.
  - Drivers are provided by the mainstream OS
  - KVM

## Lightweight Virtualization

### How ?

- Linux cgroups
  - Limit and isolate and/or deny resources to a process or a group of processes. Example: limit the cpu quota
  - They also give you accounting. Useful to see how many resources are used by a specific group
- Linux namespaces
  - similar in concept to cgroups.
  But the focus is on isolation, managing what a process can see.
  Example: network namespace.