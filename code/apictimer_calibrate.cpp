// Excerpt from the ApicTimer::calibrate function
uint32_t ApicTimer::calibrate() {
    // Start the timer with a large counter
    LocalApic::writeDoubleWord(LocalApic::TIMER_INITIAL, 0xFFFFFFFF);

    // Wait a little
    Pit::earlyDelay(10'000);

    // Calculate how often the timer ticked in one millisecond
    return (0xFFFFFFFF - LocalApic::readDoubleWord(LocalApic::TIMER_CURRENT)) / 10;
}
