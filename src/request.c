#include "request.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int read_request(int client_fd, Request *request) {
    char buffer[4097];

    ssize_t bytes_read = read(client_fd, buffer, sizeof(buffer) - 1);

    if (bytes_read <= 0) {
        if (bytes_read == 0) {
            printf("Client Disconnected!\n");
        } else {
            perror("Read Failed!");
        }

        return -1;
    }

    buffer[bytes_read] = '\0';

    char *first_line = strtok(buffer, "\r\n");

    if (first_line == NULL) {
        return -1;
    }

    sscanf(first_line, "%15s %255s %15s", request->method, request->path, request->version);

    return 0;
}
