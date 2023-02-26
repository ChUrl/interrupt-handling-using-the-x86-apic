void LocalApic::synchronizeArbitrationIds() {
    ICREntry icrEntry{};
    icrEntry.vector               = 0;
    icrEntry.deliveryMode         = ICREntry::DeliveryMode::INIT;
    icrEntry.destinationMode      = ICREntry::DestinationMode::PHYSICAL;
    icrEntry.level                = ICREntry::Level::DEASSERT;
    icrEntry.triggerMode          = ICREntry::TriggerMode::LEVEL;
    icrEntry.destinationShorthand = ICREntry::DestinationShorthand::ALL;
    icrEntry.destination          = 0;
    writeICR(icrEntry);
    waitForIpiDispatch();
}