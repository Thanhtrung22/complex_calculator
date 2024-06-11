#ifndef MODULE_COMPLEX_H
#define MODULE_COMPLEX_H

#include "data_structure.h"

typedef struct
{
    complex_t z;
    double result;
}module_complex_data_t;

/* get and set */
void MODULE_COMPLEX_Set_Complex(complex_t z1);
complex_t MODULE_COMPLEX_Get_Complex(void);
double MODULE_COMPLEX_Get_Result(void);

/* calculate */
double MODULE_COMPLEX_Calculate_Result(complex_t z1);
void MODULE_COMPLEX_Update_Result(void);

#endif