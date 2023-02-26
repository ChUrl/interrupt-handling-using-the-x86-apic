// Excerpt from the "InterruptDispatcher" class
void InterruptDispatcher::assign(uint8_t slot, InterruptHandler &isr) {
    if (handler[slot] == nullptr) {
        handler[slot] = new Util::ArrayList<InterruptHandler*>;
    }

    handler[slot]->add(&isr); // Register an interrupt handler to an interrupt vector
}
