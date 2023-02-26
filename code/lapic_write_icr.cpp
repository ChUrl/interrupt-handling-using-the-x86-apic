void LocalApic::writeICR(const ICREntry &icrEntry) {
    auto val = static_cast<uint64_t>(icrEntry);
    icrLock.acquire(); // Synchronized in case of multiple APs
    writeDoubleWord(0x310, val >> 32);
    writeDoubleWord(0x300, val & 0xFFFFFFFF); // Writing the low DW sends the IPI
    icrLock.release();
}