### Multiboot Header ###
.set ALIGN,    1<<0
.set MEMINFO,  1<<1
.set FLAGS,    ALIGN | MEMINFO
.set MAGIC,    0x1BADB002
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM


# Reserve a stack for the initial thread
.section .bss
.align 16
stack_bottom:
.skip 16384 # 16 KB
stack_top:


# Kernel entry point
.section .text
.global _start
.type _start, @function
_start:
    movl $stack_top, %esp

    # Set up global constructors for C++ stuff
    call _init

    # Transfer control to the kernel main function (in C)
    call mos_k_main

    # Extra hang
    cli
1:
    hlt
    jmp 1b

.size _start, . - _start
