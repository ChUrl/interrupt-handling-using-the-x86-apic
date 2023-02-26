struct SVREntry {
    InterruptVector vector;
    bool            isSWEnabled;
    bool            hasFocusProcessorChecking;
    bool            suppressEoiBroadcasting;

    explicit SVREntry(uint32_t registerValue);
    explicit operator uint32_t() const;
};
