// Excerpt from the "dispatch" function
if (interruptService.checkSpuriousInterrupt(slot)) {
    spuriousCounterWrapper.inc();
    return; // Early return to skip the calling of any handlers
}
