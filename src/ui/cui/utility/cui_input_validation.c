#include "ui/cui/utility/cui_input_validation.h"

#include <stdio.h>
#include <stdbool.h>


int CUI_INPUT_VALIDATION_GetModeFromUser(void) {
    int mode;
    int number_of_received_input = 0;
    bool input_is_valid = true;

    do {
        input_is_valid = true;
        printf("\nSelect mode [1-3]: ");
        number_of_received_input = scanf("%d", &mode);
        while(getchar() != '\n');
        printf("Current received input: %d", mode);

        if (!((mode >= 1 && mode <= 3) && (number_of_received_input == 1))) {
            input_is_valid = false;
            printf("\n\nSorry, try again!");
        }
    } while (!input_is_valid);

    return mode;
}

double CUI_INPUT_VALIDATION_GetDoubleFromUser(const char* input_prompt_msg) {
    double number;
    int number_of_received_input = 0;
    bool input_is_valid = true;

    do {
        input_is_valid = true;
        printf("\n%s: ", input_prompt_msg);
        number_of_received_input = scanf("%lf", &number);
        while(getchar() != '\n');
        printf("Current received input: %.15g", number);

        if (!(number_of_received_input == 1)) {
            input_is_valid = false;
            printf("\n\nSorry, try again!");
        }
    } while (!input_is_valid);

    return number;
}

math_operator_t CUI_INPUT_VALIDATION_GetOperatorFromUser(const char* input_prompt_msg) {
    char op;
    bool input_is_valid = true;

    do {
        input_is_valid = true;
        printf("\n%s: ", input_prompt_msg);
        scanf("%c", &op);
        while(getchar() != '\n');
        printf("Current received input: %c", op);

        if (!(op == '+' || op == '-' || op == '*' || op == '/')) {
            input_is_valid = false;
            printf("\n\nSorry, try again!");
        }
    } while (!input_is_valid);

    return (math_operator_t) op;
}