#include "server.h"

#include "backend/standard_calculation.h"
#include "backend/module_complex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static server_t server_list[] = {
    {.domain_name = "server.us.com"},
    {.domain_name = "server.uk.com",
     .handler[0] = {.command = "plus",
                    .standard_calculation_handle =
                        STANDARD_CALCULATION_CalculatePlus,
                    .module_complex = NULL},
     .handler[1] = {.command = "subtract",
                    .standard_calculation_handle =
                        STANDARD_CALCULATION_CalculateSubtract,
                    .module_complex = NULL},
     .handler[2] = {.command = "multiply",
                    .standard_calculation_handle =
                        STANDARD_CALCULATION_CalculateMultiply,
                    .module_complex = NULL

     },
     .handler[3] = {.command = "divide",
                    .standard_calculation_handle =
                        STANDARD_CALCULATION_CalculateDivide,
                    .module_complex = NULL},
     .handler[4] = {.command = "module",
                    .standard_calculation_handle = NULL,
                    .module_complex = MODULE_COMPLEX_Calculate_Result}

    },
    {.domain_name = "server.vn.com"}};

static int server_list_size = sizeof(server_list) / sizeof(server_list[0]);

server_t *SERVER_GetServerList(void) { return server_list; }

int SERVER_GetServerListSize(void) { return server_list_size; }

void SERVER_HandleRequest_StandardCalculation(server_t *p_server,
                                              const char *request,
                                              char *response)
{
    char req[200];
    complex_t z1, z2;
    sscanf(request, "{request:%[^,],value:{%lf + %lfi,%lf + %lfi}}", req,
           &z1.real, &z1.imagine, &z2.real, &z2.imagine);

    complex_t result;
        printf("\nre: %s", req);

    for (int i = 0; i < server_list_size; i++)
    {
        /* Kiem tra req co trung voi command nao co san trong p_server khong,
         * neu co thi thuc hien tinh toan dua tren handler da co san trong
         * p_server */

        if (strcmp(req, p_server->handler[i].command) == 0 &&
            (p_server->handler[i].standard_calculation_handle != NULL))
        {

            result = p_server->handler[i].standard_calculation_handle(z1, z2);
        }
    }
    sprintf(response, "{domain:%s,value:{%.15g + %.15gi}}",
            p_server->domain_name, result.real, result.imagine);
}

void SERVER_HandleRequest_ModuleCalculation(server_t *p_server,
                                            const char *request, char *response)
{
    char req[200];
    complex_t z1;
    printf("\nRequest: %s", request);
    sscanf(request, "{request:%[^,],value:{%lf + %lfi}}", req, &z1.real,
           &z1.imagine);
    printf("\nre: %s", req);
    double result = 0;
    result = p_server->handler[4].module_complex(z1);
    // for (int i = 0; i < server_list_size; i++)
    // {
    //     /* Kiem tra req co trung voi command nao co san trong p_server khong,
    //      * neu co thi thuc hien tinh toan dua tren handler da co san trong
    //      * p_server */

    //     if (strcmp(req, p_server->handler[i].command) == 0)
    //     {
    //         result = p_server->handler[i].module_complex(z1);
    //     }
    // }
    sprintf(response, "{domain:%s,value:{%.15g}}", p_server->domain_name,
            result);
}
