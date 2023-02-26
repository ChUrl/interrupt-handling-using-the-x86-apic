void InterruptService::allowHardwareInterrupt(InterruptRequest interrupt) {
    if (Apic::isEnabled()) {
        Apic::allow(interrupt);
    } else {
        Pic::allow(interrupt);
    }
}