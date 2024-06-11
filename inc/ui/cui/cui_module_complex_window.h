#ifndef CUI_MODULE_COMPLEX_WINDOW_H
#define CUI_MODULE_COMPLEX_WINDOW_H

#include "ui/cui/cui_common.h"

typedef struct
{
    complex_t z;
    double result;
} cui_module_complex_window_data_t;

cui_module_complex_window_data_t CUI_MODULE_COMPLEX_WINDOW_GetData(void);
void CUI_MODULE_COMPLEX_WINDOW_SetData(cui_module_complex_window_data_t data);
void CUI_MODULE_COMPLEX_WINDOW_SetComplex(complex_t z1);
complex_t CUI_MODULE_COMPLEX_GetComplex(void);

void CUI_MODULE_COMPLEX_WINDOW_Launch(void);
void CUI_MODULE_COMPLEX_WINDOW_DisplayMenu(void);
void CUI_MODULE_COMPLEX_WINDOW_GetInputFromUser(void);
void CUI_MODULE_COMPLEX_WINDOW_HandleUserInput(void);

double CUI_MODULE_COMPLEX_WINDOW_ExtractData(const char *data_stream);
void CUI_MODULE_COMPLEX_WINDOW_DisplayResult(void);
#endif
