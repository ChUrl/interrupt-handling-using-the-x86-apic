// Excerpt from System::initializeSystem(). Located before interrupts
// are enabled and any devices have registered their handlers.
if (Apic::isSupported()) {
    Apic::enable();

    if (Apic::isSmpSupported()) {
        Apic::startupSmp();
    }
}