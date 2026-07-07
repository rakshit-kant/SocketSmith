#ifndef REQUEST_H
#define REQUEST_H

typedef struct {
    char method[16];
    char path[256];
    char version[16];
} Request;

int read_request(int client_fd, Request *request);

#endif
