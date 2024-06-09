/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef CUI_INPUT_VALIDATION_H
#define CUI_INPUT_VALIDATION_H

/* Includes ------------------------------------------------------------------*/
#include "data_structure.h"


/* Get And Process Input From User -------------------------------------------*/
int CUI_INPUT_VALIDATION_GetModeFromUser(void);
double CUI_INPUT_VALIDATION_GetDoubleFromUser(const char* input_prompt_msg);
math_operator_t CUI_INPUT_VALIDATION_GetOperatorFromUser(const char* input_prompt_msg);

#endif /* CUI_INPUT_VALIDATION_H */