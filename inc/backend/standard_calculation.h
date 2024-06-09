/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STANDARD_CALCULATION_H
#define STANDARD_CALCULATION_H

/* Includes ------------------------------------------------------------------*/
#include "data_structure.h"


/* Structure Declaration -----------------------------------------------------*/
// Structure to hold data in backend module
typedef struct {
    complex_t z1;
    complex_t z2;
    math_operator_t op;
    complex_t result;
} standard_calculation_data_t;

/* Getter and Setter Functions -----------------------------------------------*/
void STANDARD_CALCULATION_SetZ1(complex_t z);
void STANDARD_CALCULATION_SetZ2(complex_t z);
void STANDARD_CALCULATION_SetOperator(math_operator_t op);
complex_t STANDARD_CALCULATION_GetResult(void);

/* Backend Processing Functions ----------------------------------------------*/
complex_t STANDARD_CALCULATION_CalculatePlus(complex_t z1, complex_t z2);
complex_t STANDARD_CALCULATION_CalculateSubtract(complex_t z1, complex_t z2);
complex_t STANDARD_CALCULATION_CalculateMultiply(complex_t z1, complex_t z2);
complex_t STANDARD_CALCULATION_CalculateDivide(complex_t z1, complex_t z2);
void STANDARD_CALCULATION_UpdateResult(void);

#endif