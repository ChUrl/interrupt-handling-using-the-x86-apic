// Excerpt from the "dispatch" function
void InterruptDispatcher::dispatch(InterruptVector vec) {
    interruptService.sendEndOfInterrupt(vec); // Signal interrupt servicing
    asm volatile("sti");                      // Allow cascaded interrupts

    auto *handlerList = handlers[vec];
    for (uint32_t i = 0; i < handlerList->size(); i++) {
        handlerList->get(i)->trigger(); // Call registered interrupt handlers
    }

    asm volatile("cli");
}