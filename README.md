# Qtinar Kernel — Project Analysis

## 1. Overview

Qtinar is a minimal educational operating system kernel built for the x86 architecture.  
The project follows the OSDev Bare Bones tutorial and serves as the foundation for a more advanced experimental OS.

The main goal of Qtinar is to gradually evolve from a simple bootable kernel into a modular operating system with basic hardware interaction, memory management, and multitasking.



## 2. Current State

The kernel currently:

- Boots successfully using GRUB (Multiboot compliant)
- Runs in 32-bit protected mode
- Executes C code from the entry point
- Writes text directly to VGA memory
- Displays a simple message on screen

This confirms that the toolchain, linker, and boot process are working correctly.



## 3. Architecture

Qtinar currently uses a **monolithic kernel design**.

### Components

- Boot assembly entry (`boot.s`)
- C kernel entry (`kernel.c`)
- Linker script defining memory layout
- GRUB bootloader
- VGA text output



## 4. Missing Core Features

The kernel is still minimal and lacks most OS subsystems:

### Hardware & Low-level
- Interrupt Descriptor Table (IDT)
- Interrupt Service Routines (ISR)
- Programmable Interval Timer (PIT)
- Keyboard input driver

### Memory
- Physical memory detection
- Paging / virtual memory
- Memory allocator (heap)

### Kernel Systems
- Process abstraction
- Task scheduler
- System calls
- Driver model



## 5. Next Milestones

Short-term goals:

1. Implement IDT and basic interrupts
2. Add keyboard input
3. Implement timer interrupts
4. Create a simple kernel logging system

Mid-term goals:

- Memory management (paging + heap)
- Basic multitasking
- User mode support

Long-term vision:

Qtinar aims to become a research-oriented operating system focused on:

- Kernel architecture experimentation
- Concurrency models
- Low-level performance optimization



## 6. Learning Goals

This project is designed to deepen understanding of:

- Computer architecture
- Boot process and firmware interaction
- Low-level C and assembly integration
- Operating system design principles



## 7. Status

🚧 Early Development — Bare Bones stage complete

