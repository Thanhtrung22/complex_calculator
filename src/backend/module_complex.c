#include "backend/module_complex.h"
#include <math.h>
static module_complex_data_t module_complex_data;

void MODULE_COMPLEX_Set_Complex(complex_t z1)
{
    module_complex_data.z = z1;
}

complex_t MODULE_COMPLEX_Get_Complex()
{
    return module_complex_data.z;
}

double MODULE_COMPLEX_Get_Result(void)
{
    return module_complex_data.result;
}


double MODULE_COMPLEX_Calculate_Result(complex_t z1)
{
    double result = 0;
    result = sqrt(z1.real * z1.real + z1.imagine * z1.imagine);
    return result;
}

void MODULE_COMPLEX_Update_Result(void)
{
    double result = MODULE_COMPLEX_Calculate_Result(module_complex_data.z);
    module_complex_data.result = result;
}