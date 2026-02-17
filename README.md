# Minimal Multiboot Kernel — Technical Overview

## 1. Introduction

This document describes a minimal 32-bit x86 kernel created by following the OSDev “Bare Bones” methodology.
The purpose of this kernel is educational: to demonstrate the complete boot flow from firmware to a custom kernel and to show how a kernel can directly interact with hardware without an underlying operating system.

The kernel is Multiboot-compliant and is loaded by the GRUB bootloader.
Its only runtime functionality is writing text directly to VGA text-mode memory.

---

## 2. System Architecture

The execution stack of the system is:

```
Hardware / Emulator (QEMU)
        ↓
Firmware (BIOS)
        ↓
Bootloader (GRUB)
        ↓
Custom Kernel (myos.bin)
```

The kernel operates in a freestanding environment:

* No standard library (libc)
* No runtime
* Direct hardware access

---

## 3. Boot Process

1. The BIOS initializes the system.
2. GRUB is loaded from the bootable ISO image.
3. GRUB scans the kernel binary for a Multiboot header.
4. If the header is valid, GRUB loads the kernel into memory.
5. Execution begins at the `_start` symbol.
6. `_start` calls `kernel_main()` implemented in C.

---

## 4. Boot Assembly (boot.s)

### Purpose

The assembly file provides:

* A Multiboot header
* The kernel entry point

### Multiboot Header

This header allows GRUB to recognize the binary as a valid kernel.

### Entry Routine

The `_start` symbol:

* Transfers execution to the C kernel
* Disables interrupts
* Halts the CPU in an infinite loop after return

This ensures deterministic behavior if the kernel exits.

---

## 5. Kernel Implementation (kernel.c)

### Function: `kernel_main()`

The kernel demonstrates direct memory-mapped I/O by writing a string to VGA text mode memory at address:

```
0xB8000
```

Each character cell consists of:

* 1 byte character
* 1 byte color attribute

The kernel iterates through the string and writes:

* ASCII character
* Attribute `0x07` (light grey on black)

This confirms that:

* The kernel is executing
* Hardware access is functional

---

## 6. Linker Script (linker.ld)

The linker script defines the memory layout of the kernel.

Key decision:

```
Kernel load address: 1 MB
```

Reasons:

* Traditional safe load address for x86 kernels
* Avoids low memory regions used by BIOS
* Compatible with bootloaders

Sections defined:

* `.text` (code + multiboot header)
* `.rodata`
* `.data`
* `.bss`

---

## 7. Build Environment

The kernel is compiled using a cross-compiler:

```
Target: i686-elf
```

This ensures:

* No host OS dependencies
* Correct ABI
* True freestanding compilation

Build tools:

* GCC cross-compiler
* GNU binutils
* GRUB utilities
* QEMU emulator

---

## 8. Kernel Characteristics

Current capabilities:

✔ Multiboot compliant
✔ Runs in 32-bit protected mode
✔ Direct hardware memory access
✔ Freestanding execution

Not yet implemented:

✘ Interrupt handling
✘ Memory management
✘ Drivers
✘ Scheduler
✘ System calls

This makes the kernel a **minimal proof-of-execution kernel**.

---

## 9. Educational Value

This kernel demonstrates fundamental OS concepts:

* Bootloader-kernel interaction
* Memory-mapped I/O
* Cross-compilation
* Binary layout and linking
* Bare-metal execution

It serves as the foundation for future development such as:

* GDT and IDT setup
* Interrupt handling
* Device drivers
* Virtual memory

---

## 10. Conclusion

The kernel successfully validates the complete pipeline required to run custom code directly on hardware:

```
Boot → Load → Execute → Hardware Output
```

While minimal, it represents the first milestone in operating system development and provides a solid base for expanding into a fully featured kernel.

---
