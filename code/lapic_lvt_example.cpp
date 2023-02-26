LVTEntry lvtEntry{};
lvtEntry.deliveryMode = LVTEntry::DeliveryMode::FIXED;
lvtEntry.pinPolarity  = LVTEntry::PinPolarity::HIGH;
lvtEntry.triggerMode  = LVTEntry::TriggerMode::EDGE;
lvtEntry.isMasked     = true;
lvtEntry.vector       = InterruptVector::LINT0;
writeLVT(LINT0, lvtEntry);
