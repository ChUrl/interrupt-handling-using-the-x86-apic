// Excerpt from the "checkSpuriousInterrupt" function
bool InterruptService::checkSpuriousInterrupt(InterruptVector interrupt) {
    return interrupt == InterruptVector::SPURIOUS;
}
