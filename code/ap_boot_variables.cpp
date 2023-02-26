// These variables are located in the startup routine's TEXT section
// and exported from smp_boot.asm.

// Use IDTR from the BSP
asm volatile("sidt %0" : "=m"(boot_ap_idtr));

// Use cr0, cr3 and cr4 from the BSP
asm volatile("mov %%cr0, %%eax;" : "=a"(boot_ap_cr0));
asm volatile("mov %%cr3, %%eax;" : "=a"(boot_ap_cr3));
asm volatile("mov %%cr4, %%eax;" : "=a"(boot_ap_cr4));

// Set the address of the pre-allocated GDTs, stacks and the entry function
boot_ap_gdts = reinterpret_cast<uint32_t>(apGdts);
boot_ap_stacks = reinterpret_cast<uint32_t>(apStacks);
boot_ap_entry = reinterpret_cast<uint32_t>(&smpEntry);
