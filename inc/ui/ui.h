/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef UI_H
#define UI_H

/* Includes ------------------------------------------------------------------*/
#include <stdlib.h>
#include "ui/cui/cui.h"


/* Exported macros -----------------------------------------------------------*/
#define UI_MemAlloc(p_ui_component)  malloc((p_ui_component))
#define UI_MemFree(p_ui_component)   free((p_ui_component))

/* Structure Declaration -----------------------------------------------------*/
// Structure to hold the data for ui
typedef struct {
    struct {
        void (*window_main_launch) (void);
        void (*window_standard_calculation_launch) (void);
        void (*window_module_launch) (void);
        void (*window_exit_launch) (void);
    };
} ui_handle_t;

// Structure to hold the configuration information for ui
typedef struct {
    void (*window_main_launch) (void);
    void (*window_standard_calculation_launch) (void);
    void (*window_module_launch) (void);
    void (*window_exit_launch) (void);
} ui_config_t;


/* Constructor and Destructor Functions --------------------------------------*/
void UI_Constructor(ui_handle_t** p_ui_handler, const ui_config_t* p_ui_config);
void UI_Destructor(ui_handle_t* p_ui_handler);

/* Window Management Functions -----------------------------------------------*/
void UI_MAIN_WINDOW_Launch(ui_handle_t* p_ui_handler);
void UI_STANDARD_CALCULATION_WINDOW_Launch(ui_handle_t* p_ui_handler);
void UI_MODULE_WINDOW_Launch(ui_handle_t* p_ui_handler);
void UI_EXIT_WINDOW_Launch(ui_handle_t* p_ui_handler);

#endif