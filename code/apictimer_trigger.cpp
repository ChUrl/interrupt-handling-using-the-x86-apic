// Excerpt from the ApicTimer interrupt handler
void ApicTimer::trigger(const InterruptFrame &frame) {
    if (cpuId != LocalApic::getId()) {
        // Abort if the handler doesn't belong to the current CPU
        return;
    }

    // Increase the "core-local" time
    time.addNanoseconds(timerInterval * 1'000'000); // Interval is in milliseconds

    // Only the BSP may continue
    if (cpuId != 0) {
        return;
    }

    // Trigger preemption
    if (time.toMilliseconds() % yieldInterval == 0) {
        System::getService<SchedulerService>().yield();
    }
}
