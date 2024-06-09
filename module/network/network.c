#include "network.h"

#include <stdlib.h>
#include <string.h>

#define ACTIVE_NETWORK_ID   0

static network_t network[5] = { 0 };

server_t* NETWORK_SearchServer(const char* domain) {
    server_t* server_list = SERVER_GetServerList();
    int server_list_size = SERVER_GetServerListSize();
    
    server_t* p_server = NULL;
    for (int i = 0; i < server_list_size; i++) {
        /* Dien dieu kien tim kiem server dua tren ten mien */
        // Bo comment va dien dieu kien vao if()
        // if (...) {
        //     p_server = &server_list[i];
        //     break;
        // }
    }

    return p_server;
}

void NETWORK_Open(client_t* p_client, const char* domain) {
    server_t* p_server = NETWORK_SearchServer(domain);
    NETWORK_Connect(p_server, p_client);
}

void NETWORK_Connect(server_t* p_server, client_t* p_client) {
    p_client->network_id = ACTIVE_NETWORK_ID;
    p_client->network_stream = network[ACTIVE_NETWORK_ID].network_stream;
    network[ACTIVE_NETWORK_ID].p_server = p_server;
    network[ACTIVE_NETWORK_ID].p_client = p_client;
}

void NETWORK_Close(client_t* p_client) {
    int network_id = p_client->network_id;
    /* Dua tren network_id mà p_client dang so huu, dat gia tri client va server trong netwwork ve NULL*/
    // Dien code tai day

    network[network_id].network_stream[0] = '\0';
}

void NETWORK_ExchangeData(int network_id) {
    char response[NETWORK_MAX_STREAM_SIZE];
    SERVER_HandleRequest(network[network_id].p_server, network[network_id].network_stream, response);
    /* Copy lai response vao trong network_stream cua network[network_id]*/
    // Dien code tai day
}
