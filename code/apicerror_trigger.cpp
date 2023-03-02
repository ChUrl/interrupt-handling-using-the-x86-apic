void ApicErrorHandler::trigger() {
    // Writing the ESR updates its contents and arms the interrupt again
    LocalApic::writeDoubleWord(LocalApic::ESR, 0);
    uint32_t errors = LocalApic::readDoubleWord(LocalApic::ESR);

    log.error("APIC error on core [%d]: [0x%x]!", LocalApic::getId(), errors);
}
