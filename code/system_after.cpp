// Excerpt from the "initializeSystem" function
void System::initializeSystem() {
    if (Apic::isSupported()) {
        Apic::enable();

        if (Apic::isSmpSupported()) {
            Apic::startupSmp();
        }
    }

    Cpu::enableInterrupts();
}
