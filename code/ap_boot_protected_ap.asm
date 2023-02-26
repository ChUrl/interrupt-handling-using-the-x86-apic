; Continuing boot_ap_32:
    ; Get the local APIC ID of this AP, to locate GDT and stack
    mov eax, 0x1
    cpuid
    shr ebx, 0x18
    mov edi, ebx ; Now the ID is in EDI

    ; Load the prepared AP GDT
    mov ebx, [boot_ap_gdts - boot_ap + startup_address]
    mov eax, [ebx + edi * 0x4]
    lgdt [eax]

    ; Load the TSS
    mov ax, 0x28
    ltr ax

    ; Load the correct stack for this AP
    mov ebx, [boot_ap_stacks - boot_ap + startup_address]
    mov esp, [ebx + edi * 0x4]
    add esp, stack_size ; Stack starts at the bottom
    mov ebp, esp

    ; Call the entry function
    push edi
    call [boot_ap_entry - boot_ap + startup_address]
