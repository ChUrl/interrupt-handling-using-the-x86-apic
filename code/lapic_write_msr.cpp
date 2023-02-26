void LocalApic::writeBaseMSR(const MSREntry &msrEntry) {
    ModelSpecificRegister baseMSR = ModelSpecificRegister(0x1B);
    baseMSR.writeQuadWord(static_cast<uint64_t>(msrEntry)); // Atomic write
}