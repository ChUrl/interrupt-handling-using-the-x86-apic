void LocalApic::issueINIT(uint8_t cpuId, ICREntry::Level level) {
    ICREntry icrEntry{};
    icrEntry.vector               = 0;
    icrEntry.deliveryMode         = ICREntry::DeliveryMode::INIT;
    icrEntry.destinationMode      = ICREntry::DestinationMode::PHYSICAL;
    icrEntry.level                = level; // ASSERT or DEASSERT
    icrEntry.triggerMode          = ICREntry::TriggerMode::LEVEL;
    icrEntry.destinationShorthand = ICREntry::DestinationShorthand::NO;
    icrEntry.destination          = cpuId;
    writeICR(icrEntry); // Writing the ICR issues IPI
}