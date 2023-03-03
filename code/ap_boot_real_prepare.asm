; This section has to be compiled for 16-bit real mode
[SECTION .text]
bits 16
boot_ap:
    ; Disable interrupts
    cli

    ; Enable A20 address line
    in al, 0x92
    or al, 2
    out 0x92, al

    ; Load the temporary GDT required for the far jump into protected mode.
    lgdt [tmp_gdt_desc - boot_ap + 0x8000]

