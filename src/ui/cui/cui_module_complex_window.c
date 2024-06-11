#include "ui/cui/cui_module_complex_window.h"
#include "../../../module/client/client.h"

static cui_module_complex_window_data_t cui_module_complex_window_data;

void CUI_MODULE_COMPLEX_WINDOW_SetData(cui_module_complex_window_data_t data)
{
    cui_module_complex_window_data = data;
}

cui_module_complex_window_data_t CUI_MODULE_COMPLEX_WINDOW_GetData(void)
{
    return cui_module_complex_window_data;
}

void CUI_MODULE_COMPLEX_WINDOW_SetComplex(complex_t z)
{
    cui_module_complex_window_data.z = z;
}

complex_t CUI_MODULE_COMPLEX_GetComplex(void)
{
    return cui_module_complex_window_data.z;
}

void CUI_MODULE_COMPLEX_WINDOW_Launch(void) {

    CUI_MODULE_COMPLEX_WINDOW_DisplayMenu();
    CUI_MODULE_COMPLEX_WINDOW_GetInputFromUser();
    CUI_MODULE_COMPLEX_WINDOW_HandleUserInput();
    EVENT_MANAGER_TriggerSignal_MainWindow();

}

void CUI_MODULE_COMPLEX_WINDOW_DisplayMenu(void)
{
    printf("\n\nWELCOME TO COMPLEX CALCULATOR");
    printf("\n-----------------------------");
    printf("\nMODE: MODULE CALCULATION");
    printf("\nz = a + b.i");
    printf("\n");
}

void CUI_MODULE_COMPLEX_WINDOW_GetInputFromUser(void)
{
    complex_t z;
    z.real = CUI_INPUT_VALIDATION_GetDoubleFromUser("a");
    z.imagine = CUI_INPUT_VALIDATION_GetDoubleFromUser("b");
    CUI_MODULE_COMPLEX_WINDOW_SetComplex(z);
}

void CUI_MODULE_COMPLEX_WINDOW_HandleUserInput(void)
{
    cui_module_complex_window_data_t data = CUI_MODULE_COMPLEX_WINDOW_GetData();
    client_t client;
    char request[NETWORK_MAX_STREAM_SIZE];
    char response[NETWORK_MAX_STREAM_SIZE];
    sprintf(request, "{request:%s,value:{%.15g + %.15gi}}",
            "module", data.z.real, data.z.imagine);
    CLIENT_OpenNetwork(&client, "server.uk.com");
    CLIENT_Request(&client, request, response, "module");
    cui_module_complex_window_data.result =
        CUI_MODULE_COMPLEX_WINDOW_ExtractData(response);
    CUI_MODULE_COMPLEX_WINDOW_DisplayResult();
}

void CUI_MODULE_COMPLEX_WINDOW_DisplayResult(void)
{
    printf("\nModule cua so phuc vua nhap la: %.15g",
           cui_module_complex_window_data.result);
}

double CUI_MODULE_COMPLEX_WINDOW_ExtractData(const char *data_stream)
{
    double result = 0;
    char domain[30];
    sscanf(data_stream, "{domain:%[^,],value:{%lf}}", domain, &result);
    return result;
}