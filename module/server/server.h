#ifndef SERVER_H
#define SERVER_H

#include "../network_data_structure.h"

server_t *SERVER_GetServerList(void);
int SERVER_GetServerListSize(void);

void SERVER_HandleRequest_StandardCalculation(server_t *p_server,
                                              const char *request,
                                              char *response);
void SERVER_HandleRequest_ModuleCalculation(server_t *p_server,
                                            const char *request,
                                            char *response);
#endif