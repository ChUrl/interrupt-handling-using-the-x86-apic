// Excerpt from the "Pit" interrupt handler
void Pit::trigger() {
    time.addNanoseconds(timerInterval); // Increase system time

    // Trigger preemption
    if (time.toMilliseconds() % yieldInterval == 0) {
        System::getService<SchedulerService>().yield(); // Trigger preemption
    }
}
