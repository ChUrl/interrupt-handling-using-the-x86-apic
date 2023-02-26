void Apic::allow(InterruptRequest interruptRequest) {
    IoApic::IrqOverride *override = IoApic::getOverride(interruptRequest);
    if (override == nullptr) {
        // If no override is specified, the IRQ is identity mapped to the GSI
        IoApic::allow(static_cast<GlobalSystemInterrupt>(interruptRequest));
    } else {
        // If an override is specified, lookup which GSI the IRQ is mapped to
        IoApic::allow(override->target);
    }
}
