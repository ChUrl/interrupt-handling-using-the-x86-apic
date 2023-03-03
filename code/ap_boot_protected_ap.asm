; Continuing boot_ap_32:
    ; Get the local APIC ID of this AP, to locate GDT and stack
    mov eax, 0x1
    cpuid
    shr ebx, 0x18
    mov edi, ebx ; Now the ID is in EDI

    ; Load the AP's prepared GDT and TSS
    mov ebx, [boot_ap_gdts - boot_ap + 0x8000]
    mov eax, [ebx + edi * 0x4] ; Select the GDT
    lgdt [eax]
    mov ax, 0x28
    ltr ax

    ; Load the correct stack for this AP
    mov ebx, [boot_ap_stacks - boot_ap + 0x8000]
    mov esp, [ebx + edi * 0x4] ; Select the stack
    add esp, 0x1000 ; Stack starts at the bottom
    mov ebp, esp

    ; Call the entry function smpEntry(uint8_t cpuid)
    push edi
    call [boot_ap_entry - boot_ap + 0x8000]
