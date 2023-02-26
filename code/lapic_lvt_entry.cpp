struct LVTEntry {
    InterruptVector vector;
    DeliveryMode    deliveryMode;
    DeliveryStatus  deliveryStatus;
    PinPolarity     pinPolarity;
    TriggerMode     triggerMode;
    bool            isMasked;
    TimerMode       timerMode;

    explicit LVTEntry(uint32_t registerValue);
    explicit operator uint32_t() const;
};
