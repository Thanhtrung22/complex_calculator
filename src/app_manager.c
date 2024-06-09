#include "app_manager.h"

#include "utility.h"
#include "event_manager.h"
#include "ui/ui.h"

static ui_handle_t* p_ui_handler = NULL;

void APP_MANAGER_Init(void) {
    p_ui_handler = NULL;
    ui_config_t ui_config = {
        .window_main_launch = CUI_MAIN_WINDOW_Launch,
        .window_standard_calculation_launch = CUI_STANDARD_CALCULATION_WINDOW_Launch,
        .window_module_launch = NULL,
        .window_exit_launch = CUI_EXIT_WINDOW_Launch
    };

    EVENT_MANAGER_Constructor();
    UI_Constructor(&p_ui_handler, &ui_config);

    if (p_ui_handler == NULL) {
        LOG("\n\nFailed to initialize UI");
        APP_MANAGER_Exit();
        return;
    }

    EVENT_MANAGER_TriggerSignal_MainWindow();
}

void APP_MANAGER_Launch(void) {
    bool WindowShouldClose = false;

    while (!WindowShouldClose) {
        if (EVENT_MANAGER_GetSignal_MainWindow()) {
            UI_MAIN_WINDOW_Launch(p_ui_handler);
        }

        if (EVENT_MANAGER_GetSignal_StandardCalculationWindow()) {
            UI_STANDARD_CALCULATION_WINDOW_Launch(p_ui_handler);
        }
        
        if (EVENT_MANAGER_GetSignal_Exit()) {
            UI_EXIT_WINDOW_Launch(p_ui_handler);
            WindowShouldClose = true;
        }
    }
}

void APP_MANAGER_Exit(void) {
    UI_Destructor(p_ui_handler);
    EVENT_MANAGER_Destructor();
    LOG("\n\nComplex Calculator exitted!\n");
    exit(0);
}
