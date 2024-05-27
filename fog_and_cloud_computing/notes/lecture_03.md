# Lecture 08/03/2024

## Layering

layering is a common approach to manage system complexity.

Each subsystem is abstracted.

Subsystems exposes interfaces to be used by upper layer. Subsystems are trated like black boxes

Example:

1. Libraries
2. Operating system
3. Hardware

Remember of ISA, ABI and API

## Definitions

- Host OS
  - Os running on the actual hardware
  - The Hypervisor can reside here
- Virtual Machine
  - Software emulation of a physical machine
- Guest OS
  - Os running inside the VM. Not aware of running in a VM

---

- Hypervisor or VMM(Virtual Machine Monitor)
  - Software in charge of the virtualization process
  - Isolation
  - Managing shared resources

Provides virtual hardware to the VM

If the virtualized cpu has the same ISA of the real one we don't encounter any special problems. If we virtualize a cpu with a different ISA we have to relay on Emulation and not Virtualization. We need to translate the ISA from one architecture to another
Virtual Machine: "A virtual machine is an efficient, isolated duplicate of the real machine"

VMM:

- applications and os can run unmodified
- efficient
  - as much as possible instructions of the virtual processor should be executed by the real processor
- control of the real system resources
  - each VM should be able to access hardware resources only under the authorization fo the VMM

## Types of virtualization

- Full Virtualization
  - Guest OS can run unsupervised in the hypervisor
- Paravirtualization
  - Guest OS need to be modified in order to be excuted
- Hardware assisted virtualization
  - Hypervisor uses hardware features included in the CPU/chipset

## Hardware privilege ring

x86 defines 3 rings of privileges

- 0: most privileged part of the code: Kernel
- 1-3: application and services with different levels of privilege

Modern OSes only use ring 0 and 3

virtualization models:

- 0/1/3: Guest os runs in ring 1/2 and has some memory access. VMM runs in ring 3. In this way the guest OS can get in the way of the VMM. Not very good.
- 0/3/3: Also called ring compression. Everything but the kernel runs in ring 3. In this way we solve the privilege problem but the Guest OS becomes more vulnerable to malicious applications which runes on the same level.

## Privileged Instruction

CPU instruction that needs to be executed in a privileged hardware context. It generates a trap if called when the CPU is running in the wrong context.

Example: user-level application cannot do this things
- HALT instruction
  - a random application cannot halt a computer from running
- I/O instructions
  - no direct interaction is allowed

## Sensitive Instruction

Instruction which leaks information about the internal status of a processor.

To virtualize all sensitive instructions of a CPU must be privileged.

## Traps

When the CPU is running in user mode it happens that something needs to be handled in kernel mode. The CPU jumps to the hardware exception handler vector and executes operations in kernel mode.

When it happens:

- Exception
- System Call
- Hardware Interrupts

### System call implementation

Application invokes system call:
  - CPU traps to interrupt handler vector in OS
  - CPU switch to kernel mode and execute instructions

Hardware Event:
- Hardware interrupt CPU execution and jump to interrupt handler in OS

Traditional Way:
- userland code generates software interrupt
- generic interrupt routine of the OS is started. jump in the OS code to serve the above interrupt
- kernel jumps to the requested code and then returns to the caller

Modern Way:

use of SYSENTER and SYSEXIT
- userland code writes the register of the target kernel routine in a special address and then calls SYSENTER. Then the Kernel runs ina a very fast transition.

## Trap and Emulate paradigm

When guest OS launches a TRAP the VMM intercepts it and it emulates the effect of the priviledged instruction.

What VMM do:
- if trap is cause by application -> pass trap to the guest OS
- if trap is caused by guest OS -> handle the trap adjusting the state of the VM

All of this requires extra steps that can make system calls take very long. A lot of context switches.

Slide 27-29 (Cloud Virtualizatio PDF) provide good explanatory pictures.

### Problems

x86 is not really virtualizabile

- each privileged instruction has to genereate a time-consuming trap detectable by the hypervisor
- x86 is very minimalistico. some sensitive instructions that are not privileged

## Solutions

- Binary translation
  - No need to edit OS. Performance overhead. (VMWare, QEMU)
- Paravirtualization
  - Change the OS. Near native performance
- Make all sensitive instructions privileged
  - Hardware supported virtualization (Xen, KVM, VMWare)

### Dynamic Binary Translation (DBT)

- Dynamic: translation is done on the fly during execution
- Binary: VMM translates the binary code

Compatibility is great because id doesn't require any special modification to HW or SW

Performance: pretty slow. big overhead. we can use caching to improve speed.

### Hardware asssisted virtualization

Solve problems of the other two methods.

It's a trap end emulate paradigm support by hardware.

Registers and address space swapped in a single
atomic operation.

CPU has a new running mode called VMX (Virtual machine eXtensions).
New commands: VMENTRY and VMEXIT

VMM runs in ring 0 aka root mode and the guest OS runs in non-root mode where the 4 ring structure is replicated. So guest OS runs in non-root ring 0 and guest OS applications in non-root ring 3.

#### VMCS

New memory structure, Virtual Machine Control Structure.

Mirrors all register modifications needed for a certain configuration in the guest OS.

It rapresentes the control panel of the VM storing:

- Guest state
- Host processor information
- Control data, ex: trapping conditions

#### Recap

- Trasparent way to make Full virtualization.
- no trap for system call triggered by user applications
- reduced roundtrip time

## Memory Virtualization

Memory paging, MMU

OS use virtual addresses:

- addresses start at 0
- OS use pages

MMU (Memory managament unit)

- translates virtual to physical addresses (in hardware)
- manteins page table (big hash table)

- TLB: (Translation lookaside buffer): cache of recently used page translations

Virtual Memory:
- Ease of use. Each process gets illussion of whole address space
- Isolation
- Optimization
  - Fitting processes in memory

### Shadow Page Table

Guest virtual address -> Guest physical address -> Machine physical address

To avoid a double translation: Shadow Page Table

Guest logical address -> Machine physical pages

This is invisible to the guest and it's used only by the cpu when the guest is active

Slide 56 has a good visualization

All of this cause an overhead of having to keep updated an additional table.
Page faults are very expensive.

In order to avoid Shadow Page Table overhead, Intel/AMD introduces Extended
Page Table / Rapid Virtualisation Indexing

So when we can we use hardware support: Both the traditional (guest) page tables and the nested page tables are exposed to the CPU. The hardware can do double-level page walk.

The TLB becomes critical to mantein good performance.

#### Tagged TLB

Each TBL line has an ID (Virtual Processor ID)

When a line has to be accessed we can check the ID to prevent wrong access.

In this way multiple processor can coexist in the same TLB.

Thi eliminates the need to flush the TLB at every VMEntry and VMExit

## Summary

- Shadow Page Table technique used only in absence of EPT/RVI support
- EPT/RVI used whenever is possible
  - Bigger pages could be used in order to limit the pressure on the TLB cache