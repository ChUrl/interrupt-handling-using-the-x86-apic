void LocalApic::disablePicMode() {
    IoPort registerSelectorPort = IoPort(0x22);
    IoPort registerDataPort = IoPort(0x23);

    registerSelectorPort.writeByte(0x70); // IMCR address is 0x70
    registerDataPort.writeByte(0x01);     // 0x01 disconnects PIC
}
