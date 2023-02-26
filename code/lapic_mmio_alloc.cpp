uint32_t allocateMMIORegion() {
    // The apicBaseAddress is obtained via ACPI
    auto &memoryService = System::getService<MemoryService>();
    void *virtAddressPtr = memoryService.mapIO(apicBaseAddress, Util::PAGESIZE);

    // Account for possible misalignment, as mapIO returns a page-aligned pointer
    uint32_t pageOffset = apicBaseAddress % Util::PAGESIZE;
    return reinterpret_cast<uint32_t>(virtAddressPtr) + pageOffset;
}
