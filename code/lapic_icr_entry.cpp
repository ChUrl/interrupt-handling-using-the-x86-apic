struct ICREntry {
    InterruptVector      vector;
    DeliveryMode         deliveryMode;
    DestinationMode      destinationMode;
    DeliveryStatus       deliveryStatus;
    Level                level;
    TriggerMode          triggerMode;
    DestinationShorthand destinationShorthand;
    uint8_t              destination;

    explicit ICREntry(uint64_t registerValue);
    explicit operator uint64_t() const;
};
