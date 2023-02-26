void LocalApic::writeLVT(uint32_t reg, const LVTEntry &lvtEntry) {
    writeDoubleWord(reg, static_cast<uint32_t>(lvtEntry));
}
