#include "ui/cui/cui_main_window.h"


static cui_main_window_data_t cui_main_window_data;

void CUI_MAIN_WINDOW_Data_SetMode(int mode) {
    cui_main_window_data.mode = mode;
}

int CUI_MAIN_WINDOW_Data_GetMode(void) {
    return cui_main_window_data.mode;
}

void CUI_MAIN_WINDOW_Launch(void) {
    CUI_MAIN_WINDOW_DisplayMenu();
    CUI_MAIN_WINDOW_GetInputFromUser();
    CUI_MAIN_WINDOW_HandleUserInput();
}

void CUI_MAIN_WINDOW_DisplayMenu(void) {
    printf("\n\nWELCOME TO COMPLEX CALCULATOR");
    printf("\n-----------------------------");
    printf("\nAvailable mode:");
    printf("\n\t1. Standard Calculation");
    printf("\n\t2. Module");
    printf("\n\t3. Exit");
    printf("\n");
}


void CUI_MAIN_WINDOW_GetInputFromUser(void) {
    int mode = CUI_INPUT_VALIDATION_GetModeFromUser();
    CUI_MAIN_WINDOW_Data_SetMode(mode);
}

void CUI_MAIN_WINDOW_HandleUserInput(void) {
    switch (cui_main_window_data.mode)
    {
    case 1:
        EVENT_MANAGER_TriggerSignal_StandardCalculationWindow();
        break;

    case 3:
        EVENT_MANAGER_TriggerSignal_ExitWindow();
        break;
    
    default:
        printf("\nThis mode is currently in development!");
        EVENT_MANAGER_TriggerSignal_MainWindow();
        break;
    }
}
