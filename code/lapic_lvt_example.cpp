// Excerpt from the initializeLVT function
void LocalApic::initializeLVT() {
    LVTEntry lvtEntry{};
    lvtEntry.deliveryMode = LVTEntry::DeliveryMode::FIXED;
    lvtEntry.pinPolarity  = LVTEntry::PinPolarity::HIGH;
    lvtEntry.triggerMode  = LVTEntry::TriggerMode::EDGE;
    lvtEntry.isMasked     = true;
    lvtEntry.vector       = InterruptVector::ERROR;
    writeLVT(ERROR, lvtEntry);
}