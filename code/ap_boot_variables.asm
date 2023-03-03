; Export the variables to allow initialization by C++ code
global boot_ap_idtr
global boot_ap_cr0
global boot_ap_cr3
global boot_ap_cr4
global boot_ap_gdts
global boot_ap_stacks
global boot_ap_entry

[SECTION .text]
align 8
bits 16
boot_ap:
; [...] boot_ap 16-bit

; The variables initialized during runtime
align 8
boot_ap_idtr:
    dw 0x0
    dd 0x0
align 8
boot_ap_cr0:
    dd 0x0
align 8
boot_ap_cr3:
    dd 0x0
align 8
boot_ap_cr4:
    dd 0x0
align 8
boot_ap_gdts:
    dd 0x0
align 8
boot_ap_stacks:
    dd 0x0
align 8
boot_ap_entry:
    dd 0x0

bits 32
align 8
boot_ap_32:
; [...] boot_ap_32 32-bit