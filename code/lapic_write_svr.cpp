void LocalApic::writeSVR(const SVREntry &svrEntry) {
    writeDoubleWord(0xF0, static_cast<uint32_t>(svrEntry));
}