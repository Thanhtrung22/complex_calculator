#ifndef NETWORK_DATA_STRUCTURE_H
#define NETWORK_DATA_STRUCTURE_H

#include "data_structure.h"

#define NETWORK_MAX_STREAM_SIZE     200
#define SERVER_REQUEST_MAX_CMD_SIZE     20

typedef struct {
    char command[SERVER_REQUEST_MAX_CMD_SIZE];
    complex_t (*standard_calculation_handle) (complex_t z1, complex_t z2);
} server_request_handle_t;

typedef struct {
    char* network_stream;
    int network_id;
} client_t;

typedef struct {
    char* domain_name;
    const char* network_stream;
    int network_id;
    server_request_handle_t handler[10];
} server_t;

typedef struct {
    server_t* p_server;
    client_t* p_client;
    char network_stream[NETWORK_MAX_STREAM_SIZE];
} network_t;

#endif