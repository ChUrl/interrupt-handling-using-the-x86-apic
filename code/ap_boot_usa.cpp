// Excerpt from the Universal Startup Algorithm
for (uint8_t cpu = 0; cpu < cpuCount; ++cpu) {
    if (cpu == LocalApic::getId()) { continue; } // Skip the BSP

    LocalApic::clearErrors();
    LocalApic::sendInitIpi(cpu, ICREntry::Level::ASSERT);
    LocalApic::waitForIpiDispatch();
    LocalApic::sendInitIpi(cpu, ICREntry::Level::DEASSERT);
    LocalApic::waitForIpiDispatch();
    Pit::earlyDelay(10'000); // 10 milliseconds
    for (uint8_t i = 0; i < 2; ++i) {
        LocalApic::clearErrors();
        LocalApic::sendStartupIpi(cpu, apStartupAddress);
        LocalApic::waitForIpiDispatch();
        Pit::earlyDelay(200); // 200 microseconds
    }

    while (!(runningAPs & (1 << cpu))) {} // Wait until the AP is running
}
