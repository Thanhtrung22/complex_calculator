#include "event_manager.h"


static event_manager_event_t event_manager_event;

void EVENT_MANAGER_Constructor(void) {
    event_manager_event = (event_manager_event_t) { false };
}

void EVENT_MANAGER_Destructor(void) {
    /* Do nothing */
}

bool EVENT_MANAGER_GetSignal_MainWindow(void) {
    bool signal = event_manager_event.signal_main_window;
    event_manager_event.signal_main_window = false;
    return signal;
}

void EVENT_MANAGER_TriggerSignal_MainWindow(void) {
    event_manager_event.signal_main_window = true;
}

bool EVENT_MANAGER_GetSignal_Exit(void) {
    bool signal = event_manager_event.signal_exit_window;
    event_manager_event.signal_exit_window = false;
    return signal;
}

void EVENT_MANAGER_TriggerSignal_ExitWindow(void) {
    event_manager_event.signal_exit_window = true;
}

bool EVENT_MANAGER_GetSignal_StandardCalculationWindow(void) {
    bool signal = event_manager_event.signal_standard_calculation_window;
    event_manager_event.signal_standard_calculation_window = false;
    return signal;
}

void EVENT_MANAGER_TriggerSignal_StandardCalculationWindow(void) {
    event_manager_event.signal_standard_calculation_window = true;
}