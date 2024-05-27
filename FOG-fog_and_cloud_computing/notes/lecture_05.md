# Lecture 20/03/24

## Clarification of some concepts

## Trapping

Both applications and operatin systems can cause traps. How do i distinguish them ? I don't.

The machanism of trapping works at very low level. It reads the cpu instructions and in what ring it needs to execute.

## DBT

This mechanism translates the sensitive instructions into privileged instructions. This happens at runtime.

## Hardware assisted Virtualization

- Introduces a new memory structure to define wich instructions have to trap. In this way things are much more flexible.
- At a high level it's good old "trap and emulate" but this time with hardware support.
- I can now avoid trapping if not necessary because I can figure out if the guest can perform the operation on it's own.
    - I can 2 checks:
        - Can i execute this operation in this ring ?
        - Can i exectue this operation in non root mode ?
    - If both answers are YES than i don't need to to a VMEXIT because it's an operation that the guest os can carry out by itself.

## Memory Virtualization

The VMM can partecipate in writing entries into the TLB.
In this way translations saved in the Shadow Paga Table can be cached in the TLB.

I manage to keep the Shadow Table updated thaks to page faults.
A page fault generates a trap that allow me to updates the mapping in the shadow table.

**Intel/AMD introduces Extended Page Table / Rapid Virtualisation Indexing**

I have 2 nested page table: one for the VM and one for the machine. I need to do a double walk but it's in hardware so it's really fast.

The TLB works as a cache for the logical to physical page translations.
It can also cache translations for the guest OS because I flush it at every context switch. So the translations always refer to something meaningful.

Usually I would need to flush the TLB at every VMEXIT and VMENTRY. Hardware assisted Virtualization introduces tags to the TLB entries so I don't have to flush everything everytime.