// Excerpt from the IoAPic::initializeREDTBL function
void IoApic::initializeREDTBL() {
    // GSI2 belongs to the PIT in many systems
    auto gsi = GlobalSystemInterrupt(2);
    IrqOverride *override = getOverride(gsi);

    REDTBLEntry redtblEntry{};
    redtblEntry.deliveryMode    = REDTBLEntry::DeliveryMode::FIXED;
    redtblEntry.destinationMode = REDTBLEntry::DestinationMode::PHYSICAL;
    redtblEntry.isMasked        = true;
    redtblEntry.destination     = LocalApic::getId(); // Redirect to BSP

    if (override != nullptr) {
        // Apply any information provided by an interrupt override
        redtblEntry.vector      = override->source + 32;
        redtblEntry.pinPolarity = override->polarity;
        redtblEntry.triggerMode = override->trigger;
    } else {
        // Apply PC/AT compatible ISA bus defaults
        redtblEntry.vector      = gsi + 32;
        redtblEntry.pinPolarity = REDTBLEntry::PinPolarity::HIGH;
        redtblEntry.triggerMode = REDTBLEntry::TriggerMode::EDGE;
    }

    writeREDTBL(gsi, redtblEntry);
}