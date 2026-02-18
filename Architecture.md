# Qtinar Kernel — Architecture

## 1. Overview

Qtinar is a minimal educational 32-bit x86 kernel.  
Its architecture is designed to be simple but modular, allowing expansion into:

- Interrupt handling
- Memory management
- Multitasking
- Device drivers

The kernel is Multiboot-compliant and loaded by GRUB.



## 2. Kernel Structure

```
Qtinar Kernel
├── src/
│ ├── boot.s # Multiboot header & entry point
│ └── kernel.c # Main kernel logic
├── linker.ld # Memory layout
├── iso/boot/grub/ # GRUB configuration
│ └── grub.cfg
├── README.md # Project overview
└── Architecture.md # Kernel architecture description
```


## 3. Components

### 3.1 Bootloader (`boot.s`)
- Contains Multiboot header
- Entry point `_start`
- Switches to 32-bit protected mode
- Calls `kernel_main()` in C

### 3.2 Kernel (`kernel.c`)
- Freestanding C environment
- Writes directly to VGA text memory
- Base for adding hardware interaction
- Currently prints "Hello, kernel World!"

### 3.3 Linker Script (`linker.ld`)
- Defines memory layout
- Sets load address at 1MB
- Organizes sections: `.text`, `.rodata`, `.data`, `.bss`

### 3.4 GRUB
- Loads kernel from ISO
- Multiboot compliant
- Provides boot menu for multiple kernels



## 4. Missing Modules / Future Plans

- Interrupt Descriptor Table (IDT)  
- Interrupt Service Routines (ISRs)  
- Programmable Interval Timer (PIT)  
- Keyboard input  
- Paging / Virtual memory  
- Process abstraction & scheduler  
- System calls  
- Driver model  



## 5. Flow Diagram (High-Level)

BIOS/Emulator
↓
GRUB Loader
↓
_start (boot.s)
↓
kernel_main() (kernel.c)
↓
VGA Output / Future Devices




## 6. Design Principles

- **Modularity**: Easy to add new components  
- **Simplicity**: Minimal dependencies, no standard library  
- **Educational focus**: Demonstrates real hardware interaction  
- **Stepwise development**: Start bare bones, gradually add features


