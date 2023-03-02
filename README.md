<div align="center">
  <img src="https://coconucos.cs.hhu.de/lehre/bigdata/resources/img/hhu-logo.svg" width=300>

  [![Download](https://img.shields.io/static/v1?label=&message=pdf&color=EE3F24&style=for-the-badge&logo=adobe-acrobat-reader&logoColor=FFFFFF)](/../-/jobs/artifacts/main/file/thesis.pdf?job=latex)
</div>

# :notebook: &nbsp; Aufgabenbeschreibung

In this thesis, support for the Intel APIC (Advanced Programmable Interrupt Controller) will be integrated into [hhuOS](https://github.com/hhuOS/hhuOS/tree/experimental), a "small operating system for learning purposes", which currently uses the Intel PIC (Programmable Interrupt Controller) to handle interrupts.

The following features will be implemented, while still retaining the possibility to handle interrupts using the PIC:

1. Using the local APIC to handle local interrupts
2. Using the I/O APIC to handle external interrupts
3. Using the APIC timer for scheduling
4. Using the local APIC to initialize additional application processors in a symmetric multiprocessing system

All of these features are developed using an emulated hardware environment (QEMU), but targeted to run on real hardware aswell.

Things out of scope for this thesis:

1. Running in x2Apic mode or with a discrete local APIC
2. Meaningful SMP operation:
   1. All external interrupts will be handled by the boot processor
   2. Additional processors are initialized to a looping state

## Using the local APIC to handle local interrupts

This is a prerequisite for all of the following tasks: The APIC system is spread over multiple components, communication with the CPU runs through the local APIC, it is required to enable and initialize the local APIC hardware before anything else can be done.

The local APIC also is responsible for handling "local interrupts", for example the APIC error interrupt and the APIC timer interrupt, and "interprocessor interrupts", used for multiprocessor system startup.
These will be setup and handled aswell.

To gather required system information, ACPI will be used.

## Using the I/O APIC to handle external interrupts

The local APIC alone can't replace the PIC, so in this thesis the I/O APIC will be used in addition to the local APIC to handle external interrupts. It has to be implemented in a way that is compatible to the previous PIC implementation, by gathering information about connected PC/AT compatible interrupts using ACPI.

I/O APIC support should be integrated seamlessly, without the need to change existing devices that use external interrupts.

## Using the APIC timer for scheduling

The current implementation, which uses the PIT to trigger hhuOS' scheduler, should be changed to use the local APIC's integrated timer instead. This is advantageous in multicore operation, because every application processor contains its own APIC timer that it can use for core-local scheduling.

Because the APIC timer's frequency is "unknown" (bus dependent), it has to be calibrated at runtime by using the PIT as calibration source.

## Using the local APIC to initialize additional application processors in a symmetric multiprocessing system

On system startup, only a single CPU core is active. This core's local APIC can be used to trigger the startup routine of additional application processors, by issuing interprocessor interrupts to the APs' local APICs.

This and a prepared boot routine will be used to start up additional CPUs in a multiprocessor system.

# How to run

- The modified version of hhuOS can be built like the unmodified version, as described [here](https://github.com/hhuOS/hhuOS/tree/experimental#user-content-usage).
- To use the APIC and SMP features, it is required to run hhuOS with BIOS using GRUB, as the ACPI subsystem is not available yet with UEFI
- To run hhuOS in QEMU with APIC support, the `+apic` flag has to be added to QEMU's CPU features in the hhuOS `run.sh` script:
```sh
readonly CONST_QEMU_CPU_I386="base,+fpu,+tsc,+cmov,+fxsr,+mmx,+sse,+apic"
```
- To run hhuOS in QEMU with SMP, APIC has to be enabled and the `-smp <procn>` argument has to be added to QEMU's run configuration in the hhuOS `run.sh` script:
```sh
readonly CONST_QEMU_ARGS="-boot d -vga std -monitor stdio -rtc base=localtime -device isa-debug-exit -smp 2"
```

Example usage:

```sh
$ cd hhuOS
$ ./build.sh --target grub
$ ./run.sh --bios true --file hhuOS.iso
```

# List of notable new files

- `src/device/interrupt/apic/*`
- `src/device/time/ApicTimer.*`
- `src/device/cpu/smp_*`

# Commit history

Accessible [here](https://github.com/ChUrl/hhuOS).
