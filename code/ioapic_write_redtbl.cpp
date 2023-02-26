void IoApic::writeREDTBL(GlobalSystemInterrupt gsi, const REDTBLEntry &redtbl) {
    auto val = static_cast<uint64_t>(redtbl);
    redtblLock.acquire(); // Synchronized in case of multiple APs
    writeIndirectRegister(0x10 + 2 * gsi, val & 0xFFFFFFFF); // Low DW
    writeIndirectRegister(0x10 + 2 * gsi + 1, val >> 32);    // High DW
    redtblLock.release();
}