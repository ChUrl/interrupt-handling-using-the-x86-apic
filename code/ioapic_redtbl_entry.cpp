struct REDTBLEntry {
    InterruptVector vector;
    DeliveryMode    deliveryMode;
    DestinationMode destinationMode;
    DeliveryStatus  deliveryStatus;
    PinPolarity     pinPolarity;
    TriggerMode     triggerMode;
    bool            isMasked;
    uint8_t         destination;

    explicit REDTBLEntry(uint64_t registerValue);
    explicit operator uint64_t() const;
};
