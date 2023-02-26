; Continuing boot_ap:
    ; Enable Protected Mode, executed from an identity mapped page.
    mov eax, cr0
    or al, 0x1 ; Set PE bit
    mov cr0, eax

    ; Setup the protected mode segments
    mov ax, 0x10
    mov ds, ax ; Data segment register
    mov es, ax ; Extra segment register
    mov ss, ax ; Stack segment register
    mov fs, ax ; General purpose segment register
    mov gs, ax ; General purpose segment register

    ; Far jump to protected mode, set code segment register
    jmp dword 0x8:boot_ap_32 - boot_ap + 0x8000
