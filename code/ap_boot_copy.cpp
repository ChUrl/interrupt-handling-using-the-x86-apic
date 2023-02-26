// Allocate physical memory for copying the startup routine
auto &memoryService = System::getService<MemoryService>();
void *startupCodeMemory = memoryService.mapIO(0x8000, Util::PAGESIZE);

// Identity map the allocated physical memory to the kernel address space
memoryService.unmap(reinterpret_cast<uint32_t>(startupCodeMemory));
memoryService.mapPhysicalAddress(0x8000, 0x8000,
                                 Kernel::Paging::PRESENT | Kernel::Paging::READ_WRITE);

// Copy the startup routine and prepared variables to the identity mapped page
auto startupCode = Util::Address<uint32_t>(reinterpret_cast<uint32_t>(&boot_ap));
auto destination = Util::Address<uint32_t>(0x8000);
destination.copyRange(startupCode, boot_ap_size);