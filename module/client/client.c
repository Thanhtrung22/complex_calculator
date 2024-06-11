#include "client.h"

#include <stdlib.h>
#include <string.h>

#include "../network/network.h"

bool CLIENT_OpenNetwork(client_t* p_client, const char* domain) {
    NETWORK_Open(p_client, domain);

    return true;
}

void CLIENT_Request(client_t* p_client, const char* request, char* response, char* command) {
    /* Copy request vao network_stream duoc luu tru trong p_client */
    p_client->network_stream = (char*) request;

    NETWORK_ExchangeData(p_client->network_id, command);
    strcpy(response, p_client->network_stream);
}

bool CLIENT_CloseNetwork(client_t* p_client) {
    p_client->network_stream = NULL;
    NETWORK_Close(p_client);
    return true;
}

