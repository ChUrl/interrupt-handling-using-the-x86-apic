SVREntry svrEntry{};
svrEntry.vector      = InterruptVector::SPURIOUS;
svrEntry.isSWEnabled = true; // Keep the APIC software enabled
writeSVR(svrEntry);
