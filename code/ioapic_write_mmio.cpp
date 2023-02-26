template<typename T>
void IoApic::writeMMIORegister(uint32_t reg, T val) {
    *reinterpret_cast<volatile T *>(mmioAddress + reg) = val;
}
