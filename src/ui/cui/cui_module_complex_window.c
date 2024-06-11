#include "ui/cui/cui_module_complex_window.h"

static cui_module_complex_window_data_t cui_module_complex_window_data;

void CUI_MODULE_COMPLEX_WINDOW_SetData(cui_module_complex_window_data_t data)
{
    cui_module_complex_window_data = data;
}

cui_module_complex_window_data_t CUI_MODULE_COMPLEX_WINDOW_GetData(void)
{
    return cui_module_complex_window_data;
}

void CUI_MODULE_COMPLEX_WINDOW_lSetComplex(complex_t z1)
{
    cui_module_complex_window_data.z = z1;
}

complex_t CUI_MODULE_COMPLEX_GetComplex(void)
{
    return cui_module_complex_window_data.z;
}