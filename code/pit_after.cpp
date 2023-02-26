void Pit::trigger(const InterruptFrame &frame) {
    time.addNanoseconds(timerInterval); // Increase system time

    // Don't use PIT for scheduling when the APIC timer is enabled
    if (Apic::isEnabled()) {
        return;
    }

    if (time.toMilliseconds() % yieldInterval == 0) {
        System::getService<SchedulerService>().yield(); // Trigger preemption
    }
}
