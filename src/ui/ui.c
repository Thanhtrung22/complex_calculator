#include "ui/ui.h"


void UI_Constructor(ui_handle_t** p_ui_handler, const ui_config_t* p_ui_config) {
    ui_handle_t* p_ui_temp = NULL;

    /* Cap phat dong 1 memory block cho bien p_ui_temp. Su dung ham UI_MemAlloc() (dinh nghia trong ui.h)*/
    p_ui_temp  = (ui_handle_t *)UI_MemAlloc(sizeof(ui_handle_t));
    if (p_ui_temp == NULL) return;

    *p_ui_handler = p_ui_temp;
    (*p_ui_handler)->window_main_launch = p_ui_config->window_main_launch;
    (*p_ui_handler)->window_standard_calculation_launch = p_ui_config->window_standard_calculation_launch;
    (*p_ui_handler)->window_module_launch = p_ui_config->window_module_launch;
    (*p_ui_handler)->window_exit_launch = p_ui_config->window_exit_launch;
}

void UI_Destructor(ui_handle_t* p_ui_handler) {
    UI_MemFree(p_ui_handler);
}

void UI_MAIN_WINDOW_Launch(ui_handle_t* p_ui_handler) {
    p_ui_handler->window_main_launch();
}

void UI_STANDARD_CALCULATION_WINDOW_Launch(ui_handle_t* p_ui_handler) {
    p_ui_handler->window_standard_calculation_launch();
}

void UI_MODULE_WINDOW_Launch(ui_handle_t* p_ui_handler) {
    p_ui_handler->window_module_launch();
}

void UI_EXIT_WINDOW_Launch(ui_handle_t* p_ui_handler) {
    p_ui_handler->window_exit_launch();
}
