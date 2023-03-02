// Excerpt from the "assign" function
void InterruptDispatcher::assign(InterruptVector vec, InterruptHandler &handler) {
    if (handlers[vec] == nullptr) {
        // Make space for multiple possible interrupt handlers
        handlers[vec] = new Util::ArrayList<InterruptHandler *>;
    }

    handlers[vec]->add(&handler); // Register a handler to a vector
}
