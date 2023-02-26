struct BaseMSREntry {
    bool     isBSP;
    bool     isX2Apic;
    bool     isXApic;
    uint32_t baseField;

    explicit BaseMSREntry(uint64_t registerValue);
    explicit operator uint64_t() const;
};
