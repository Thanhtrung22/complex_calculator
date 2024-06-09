#include "ui/cui/cui_exit_window.h"


void CUI_EXIT_WINDOW_Launch(void) {
    CUI_EXIT_WINDOW_DisplayMenu();
    CUI_EXIT_WINDOW_GetInputFromUser();
    CUI_EXIT_WINDOW_HandleUserInput();
}

void CUI_EXIT_WINDOW_DisplayMenu(void) {
    printf("\nExitting Complex Calculator...");
    printf("\nSee you again!");
}

void CUI_EXIT_WINDOW_GetInputFromUser(void) {
    /* Do something */
}

void CUI_EXIT_WINDOW_HandleUserInput(void) {
    /* Do something */
}
