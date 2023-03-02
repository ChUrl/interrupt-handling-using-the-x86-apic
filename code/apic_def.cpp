// Excerpt from the Apic class definition
class Apic {
public:
    // Enabling the APIC subsystem
    static bool      isSupported();
    static bool      isEnabled();
    static void      enable();

    // Enabling SMP
    static bool      isSmpSupported();
    static void      startupSmp();

    // Controlling the current core's local APIC
    static void      initializeCurrentLocalApic();
    static uint8_t   getCpuCount();
    static LocalApic &getCurrentLocalApic();
    static void      enableCurrentErrorHandler();

    // Controlling the current core's APIC timer
    static bool      isCurrentTimerRunning();
    static void      startCurrentTimer();
    static ApicTimer &getCurrentTimer();

    // Controlling the current core's interrupts
    static void      allow(InterruptRequest interruptRequest);
    static void      forbid(InterruptRequest interruptRequest);
    static bool      status(InterruptRequest interruptRequest);
    static void      sendEndOfInterrupt(InterruptVector vector);
    static bool      isLocalInterrupt(InterruptVector vector);
    static bool      isExternalInterrupt(InterruptVector vector);

    // Tracking interrupt statistics
    static void      mountVirtualFilesystemNodes();
    static void      countInterrupt(InterruptVector vector);
}