void IoApic::writeIndirectRegister(uint32_t reg, uint32_t val) {
    writeMMIORegister<uint8_t>(0x00, reg);  // Write the index register
    writeMMIORegister<uint32_t>(0x10, val); // Write the data register
}
