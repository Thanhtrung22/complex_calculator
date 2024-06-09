#ifndef NETWORK_H
#define NETWORK_H

#include "../server/server.h"
#include "../client/client.h"
#include "../network_data_structure.h"


server_t* NETWORK_SearchServer(const char* domain);
void NETWORK_Open(client_t* p_client, const char* domain);
void NETWORK_Connect(server_t* p_server, client_t* p_client);
void NETWORK_Close(client_t* p_client);

void NETWORK_ExchangeData(int network_id);

#endif