// Excerpt from the "Pit" interrupt handler
void Pit::trigger(const InterruptFrame &frame) {
    time.addNanoseconds(timerInterval); // Increase system time

    if (time.toMilliseconds() % yieldInterval == 0) {
        System::getService<SchedulerService>().yield(); // Trigger preemption
    }
}
