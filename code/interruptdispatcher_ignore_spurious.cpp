// Excerpt from the "dispatch" function
void InterruptDispatcher::dispatch(InterruptVector vec) {
    if (interruptService.checkSpuriousInterrupt(slot)) {
        spuriousCounterWrapper.inc();
        return; // Early return to skip the calling of any handlers
    }
}
