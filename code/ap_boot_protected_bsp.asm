; This section has to be compiled for 32-bit protected mode
bits 32
boot_ap_32:
    ; Set cr3, cr0 and cr4 to the BSP's values for paging
    mov eax, [boot_ap_cr3 - boot_ap + 0x8000]
    mov cr3, eax
    mov eax, [boot_ap_cr0 - boot_ap + 0x8000]
    mov cr0, eax
    mov eax, [boot_ap_cr4 - boot_ap + 0x8000]
    mov cr4, eax

    ; Load the system IDT
    lidt [boot_ap_idtr - boot_ap + 0x8000]