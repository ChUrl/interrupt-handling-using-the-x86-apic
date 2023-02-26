// Excerpt from the smpEntry function
void smpEntry(uint8_t cpuId) {
    runningAPs |= (1 << cpuId); // Mark that this AP is running
}
