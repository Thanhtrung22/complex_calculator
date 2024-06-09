/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H


/* Structure Declaration -----------------------------------------------------*/
// Structure definition for a complex number
typedef struct {
    double real;            // Real part of a complex number
    double imagine;         // Imaginary part of a complex number
} complex_t;

// Enumeration for math operators
typedef enum {
    CHAR_PLUS = '+',        // Math operator: addition
    CHAR_SUBTRACT = '-',    // Math operator: subtraction
    CHAR_MULTIPLY = '*',    // Math operator: multiplication
    CHAR_DIVIDE = '/'       // Math operator: division
} math_operator_t;

#endif