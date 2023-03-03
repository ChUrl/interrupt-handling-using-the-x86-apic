// Excerpt from the "earlyDelay" function
void Pit::earlyDelay(uint16_t us) {
    uint32_t counter = (static_cast<double>(BASE_FREQUENCY) / 1'000'000) * us;

    controlPort.writeByte(0b110000); // Channel 0, mode 0
    dataPort0.writeByte(static_cast<uint8_t>(counter & 0xFF));        // Low byte
    dataPort0.writeByte(static_cast<uint8_t>((counter >> 8) & 0xFF)); // High byte

    do {
        controlPort.writeByte(0b11100010);        // Readback channel 0
    } while (!(dataPort0.readByte() & (1 << 7))); // Bit 7 is the output pin state
}