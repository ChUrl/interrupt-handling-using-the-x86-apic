struct IrqOverride {
    InterruptRequest         source;
    GlobalSystemInterrupt    target;
    REDTBLEntry::PinPolarity polarity;
    REDTBLEntry::TriggerMode trigger;
};
