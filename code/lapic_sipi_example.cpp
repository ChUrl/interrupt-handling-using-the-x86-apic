void LocalApic::issueSIPI(uint8_t cpuId, uint32_t page) {
    ICREntry icrEntry{};
    icrEntry.vector               = page;
    icrEntry.deliveryMode         = ICREntry::DeliveryMode::STARTUP;
    icrEntry.destinationMode      = ICREntry::DestinationMode::PHYSICAL;
    icrEntry.level                = ICREntry::Level::ASSERT;
    icrEntry.triggerMode          = ICREntry::TriggerMode::EDGE;
    icrEntry.destinationShorthand = ICREntry::DestinationShorthand::NO;
    icrEntry.destination          = cpuId;
    writeICR(icrEntry); // Writing the ICR issues an IPI
}
