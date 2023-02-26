// Excerpt from the "dispatch" function
interruptDepthWrapper.inc();
interruptService.sendEndOfInterrupt(slot); // Signal interrupt servicing
asm volatile("sti");                       // Allow cascaded interrupts

uint32_t size = handlerList->size();
for (uint32_t i = 0; i < size; i++) {
    handlerList->get(i)->trigger(frame);   // Call registered interrupt handlers
}

asm volatile("cli");
interruptDepthWrapper.dec();
