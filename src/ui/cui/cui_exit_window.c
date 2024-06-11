#include "ui/cui/cui_exit_window.h"

static cui_exit_window_data_t cui_exit_window_data;

cui_exit_window_data_t CUI_EXIT_WINDOW_GetData()
{
    return cui_exit_window_data;
}

void CUI_EXIT_WINDOW_SetData(cui_exit_window_data_t data)
{
    cui_exit_window_data = data;
}
void CUI_EXIT_WINDOW_Launch(void) {
    CUI_EXIT_WINDOW_DisplayMenu();
    CUI_EXIT_WINDOW_GetInputFromUser();
    CUI_EXIT_WINDOW_HandleUserInput();
    if(cui_exit_window_data.flag_check)
    {
        EVENT_MANAGER_TriggerSignal_ExitWindow();
        printf("\nExitting Complex Calculator...");
        printf("\nSee you again!");
    }
    else
    {
        EVENT_MANAGER_TriggerSignal_MainWindow();
    }
}

void CUI_EXIT_WINDOW_DisplayMenu(void) {
    printf("\nBan co chac muon thoat?");
   
}

void CUI_EXIT_WINDOW_GetInputFromUser(void) {

    char answer = 0;
    answer = CUI_INPUT_VALIDATION_GetAnswer("Nhap cau tra loi y or n: ");
    cui_exit_window_data.answer = answer;

}

void CUI_EXIT_WINDOW_HandleUserInput(void) {
    
    switch(cui_exit_window_data.answer)
    {
        case 'y':
            cui_exit_window_data.flag_check = true;
            break;
        case 'n':
            cui_exit_window_data.flag_check = false;
            break;
    }
}
