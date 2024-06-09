#ifndef CLIENT_H
#define CLIENT_H

#include <stdbool.h>
#include "../network_data_structure.h"

bool CLIENT_OpenNetwork(client_t* p_client, const char* domain);
void CLIENT_Request(client_t* p_client, const char* request, char* response);
bool CLIENT_CloseNetwork(client_t* p_client);


#endif