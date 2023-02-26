void LocalApic::writeDoubleWord(uint32_t reg, uint32_t val) {
    // Use volatile to prevent compiletime caching and code elimination
    *reinterpret_cast<volatile uint32_t *>(virtAddress + reg) = val;
}
