// Excerpt from the "InterruptHandler" class definition
public:
    virtual void plugin() = 0;                             // Register the handler
    virtual void trigger(const InterruptFrame &frame) = 0; // Handle an interrupt