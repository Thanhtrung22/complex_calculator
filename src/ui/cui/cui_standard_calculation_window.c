#include "ui/cui/cui_standard_calculation_window.h"

#include <string.h>
#include "../../../module/client/client.h"

static cui_standardcalculation_window_data_t cui_standardcalculation_window_data;

cui_standardcalculation_window_data_t CUI_STANDARD_CALCULATION_WINDOW_Data_GetWindowData(void) {
    return cui_standardcalculation_window_data;
}

void CUI_STANDARD_CALCULATION_WINDOW_Data_SetZ1(complex_t z) {
    cui_standardcalculation_window_data.z1 = z;
}

complex_t CUI_STANDARD_CALCULATION_WINDOW_Data_GetZ1(void) {
    return cui_standardcalculation_window_data.z1;
}

void CUI_STANDARD_CALCULATION_WINDOW_Data_SetZ2(complex_t z) {
    cui_standardcalculation_window_data.z2 = z;
}

complex_t CUI_STANDARD_CALCULATION_WINDOW_Data_GetZ2(void) {
    return cui_standardcalculation_window_data.z2;
}

void CUI_STANDARD_CALCULATION_WINDOW_Data_SetOperator(math_operator_t op) {
    cui_standardcalculation_window_data.op = op;
}

math_operator_t CUI_STANDARD_CALCULATION_WINDOW_Data_GetOperator(void) {
    return cui_standardcalculation_window_data.op;
}

void CUI_STANDARD_CALCULATION_WINDOW_Data_SetResult(complex_t result) {
    cui_standardcalculation_window_data.result = result;
}

complex_t CUI_STANDARD_CALCULATION_WINDOW_Data_GetResult(void) {
    return cui_standardcalculation_window_data.result;
}

void CUI_STANDARD_CALCULATION_WINDOW_Launch(void) {
    CUI_STANDARD_CALCULATION_WINDOW_DisplayMenu();
    CUI_STANDARD_CALCULATION_WINDOW_GetInputFromUser();
    CUI_STANDARD_CALCULATION_WINDOW_HandleUserInput();

    EVENT_MANAGER_TriggerSignal_MainWindow();
}

void CUI_STANDARD_CALCULATION_WINDOW_DisplayMenu(void) {
    printf("\n\nWELCOME TO COMPLEX CALCULATOR");
    printf("\n-----------------------------");
    printf("\nMODE: STANDARD CALCULATION");
    printf("\nAvailable math operation: z1 [+,-,*,/] z2");
    printf("\nz1 = a1 + b1.i");
    printf("\nz2 = a2 + b2.i");
    printf("\n");
}

void CUI_STANDARD_CALCULATION_WINDOW_GetInputFromUser(void) {
    complex_t z1;
    z1.real = CUI_INPUT_VALIDATION_GetDoubleFromUser("a1");
    z1.imagine = CUI_INPUT_VALIDATION_GetDoubleFromUser("b1");
    printf("\nReceived: z1 = %.15g + %.15g.i\n", z1.real, z1.imagine);

    complex_t z2;
    z2.real = CUI_INPUT_VALIDATION_GetDoubleFromUser("a2");
    z2.imagine = CUI_INPUT_VALIDATION_GetDoubleFromUser("b2");
    printf("\nReceived: z2 = %.15g + %.15g.i\n", z2.real, z2.imagine);

    math_operator_t op = CUI_INPUT_VALIDATION_GetOperatorFromUser("Operator [+,-,*,/]");
    printf("\nReceived: op = %c\n", op);

    CUI_STANDARD_CALCULATION_WINDOW_Data_SetZ1(z1);
    CUI_STANDARD_CALCULATION_WINDOW_Data_SetZ2(z2);
    CUI_STANDARD_CALCULATION_WINDOW_Data_SetOperator(op);
}

void CUI_STANDARD_CALCULATION_WINDOW_HandleUserInput(void) {
    cui_standardcalculation_window_data_t data = cui_standardcalculation_window_data;
    char command[10];

    switch (CUI_STANDARD_CALCULATION_WINDOW_Data_GetOperator())
    {
    case CHAR_PLUS:
        strcpy(command, "plus");
        break;
    
    case CHAR_SUBTRACT:
        strcpy(command, "subtract");
        break;
    
    default:
        break;
    }

    client_t client;
    char request[NETWORK_MAX_STREAM_SIZE];
    char response[NETWORK_MAX_STREAM_SIZE];
    /* Tao chuoi theo dung dinh dang va luu vao request, goi y su dung ham sprintf */
    // Dinh dang can luu: {request:<lenh>,value:{<r> + <i>i,<r> + <i>i}}  (xem them trong README.md muc 2.5.2)
    // Dien code tai day
    sprintf(request, "{request:%s,value:{%.15g + %.15gi,%.15g + %.15gi}}", command, data.z1.real, data.z1.imagine, data.z2.real, data.z2.imagine);
    
    /* Gui yeu cau ve may chu xu ly */
    // 1. Su dung ham CLIENT_OpenNetwork mo ket noi toi may chu da co cac ham xu ly cho backend. Danh sach may chu nam trong file server.c dong 9
    // 2. Su dung ham CLIENT_Request gui request va nhan lai phan hoi vao response
    // 3. Su dung hàm CLIENT_CloseNetwork de dong ket noi
    
    cui_standardcalculation_window_data.result = CUI_STANDARD_CALCULATION_WINDOW_ExtractData(response);
    CUI_STANDARD_CALCULATION_WINDOW_DisplayResult();
}

void CUI_STANDARD_CALCULATION_WINDOW_DisplayResult(void) {
    cui_standardcalculation_window_data_t data = CUI_STANDARD_CALCULATION_WINDOW_Data_GetWindowData();
    switch (data.op)
    {
    case CHAR_PLUS:
    case CHAR_SUBTRACT:
        printf("\nResult: (%.15g + %.15g.i) %c (%.15g + %.15g.i) = %.15g + %.15g.i\n", 
            data.z1.real, data.z1.imagine, 
            data.op, 
            data.z2.real, data.z2.imagine, 
            data.result.real, data.result.imagine);
        break;
    
    default:
        printf("\nThis math operation is currently in development!");
        break;
    }
}

complex_t CUI_STANDARD_CALCULATION_WINDOW_ExtractData(const char* data_stream) {
    complex_t number;
    
    /* Biet du lieu duoc tra vao vao data_stream. Tach cac truong du lieu va gan vao bien number */ 
    // Dinh dang data_stream: {domain:<ten mien>,value:{<r> + <i>i}}
    // VD: {domain:"server.vn.com",value:{1.234324 + -42895.2532i}}
    // Dien code tai day

    return number;
}
