#include "backend/standard_calculation.h"

static standard_calculation_data_t standard_calculation_data;

void STANDARD_CALCULATION_SetZ1(complex_t z) {
    standard_calculation_data.z1 = z;
}

void STANDARD_CALCULATION_SetZ2(complex_t z) {
    standard_calculation_data.z2 = z;
}

void STANDARD_CALCULATION_SetOperator(math_operator_t op) {
    standard_calculation_data.op = op;
}

complex_t STANDARD_CALCULATION_CalculatePlus(complex_t z1, complex_t z2) {
    complex_t result;
    result.real = z1.real + z2.real;
    result.imagine = z1.imagine + z2.imagine;
    return result;
}

complex_t STANDARD_CALCULATION_CalculateSubtract(complex_t z1, complex_t z2) {
    complex_t result;
    result.real = z1.real - z2.real;
    result.imagine = z1.imagine - z2.imagine;
    return result;
}

complex_t STANDARD_CALCULATION_CalculateMultiply(complex_t z1, complex_t z2) {

}

complex_t STANDARD_CALCULATION_CalculateDivide(complex_t z1, complex_t z2) {

}


void STANDARD_CALCULATION_UpdateResult(void) {
    complex_t z1 = standard_calculation_data.z1;
    complex_t z2 = standard_calculation_data.z2;
    math_operator_t op = standard_calculation_data.op;
    complex_t result;
    
    switch (op)
    {
    case CHAR_PLUS:
        result = STANDARD_CALCULATION_CalculatePlus(z1, z2);
        standard_calculation_data.result = result;
        break;

    case CHAR_SUBTRACT:
        result = STANDARD_CALCULATION_CalculateSubtract(z1, z2);
        standard_calculation_data.result = result;
        break;
    
    default:
        break;
    }
}

complex_t STANDARD_CALCULATION_GetResult(void) {
    return standard_calculation_data.result;
}