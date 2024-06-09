#include "server.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "backend/standard_calculation.h"
#include "data_structure.h"

static server_t server_list[] = {
    {
        .domain_name = "server.us.com"
    },
    {
        .domain_name = "server.uk.com",
        .handler[0] = {
            .command = "plus",
            .standard_calculation_handle = STANDARD_CALCULATION_CalculatePlus
        },
        .handler[1] = {
            .command = "subtract",
            .standard_calculation_handle = STANDARD_CALCULATION_CalculateSubtract
        },
        .handler[2] = {
            .command = "multiply",
            .standard_calculation_handle = STANDARD_CALCULATION_CalculateMultiply
        },
        .handler[3] = {
            .command = "divide",
            .standard_calculation_handle = STANDARD_CALCULATION_CalculateDivide
        }
    },
    {
        .domain_name = "server.vn.com"
    }
};

static int server_list_size = sizeof(server_list) / sizeof(server_list[0]);

server_t* SERVER_GetServerList(void) {
    return server_list;
}

int SERVER_GetServerListSize(void) {
    return server_list_size;
}

void SERVER_HandleRequest(server_t* p_server, const char* request, char* response) {
    char req[200];
    complex_t z1, z2;
    sscanf(request, "{request:%[^,],value:{%lf + %lfi,%lf + %lfi}}", req, &z1.real, &z1.imagine, &z2.real, &z2.imagine);

    complex_t result;
    for (int i = 0; p_server->handler[i].standard_calculation_handle != NULL; i++) {
        /* Kiem tra req co trung voi command nao co san trong p_server khong, neu co thi thuc hien tinh toan dua tren handler da co san trong p_server */
        // Bo comment va hoan thien not dieu kien if
        // if (...) {
        //     result = ...;
        // }
    }

    sprintf(response, "{domain:%s,value:{%.15g + %.15gi}}", p_server->domain_name, result.real, result.imagine);
}
