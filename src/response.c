#include "response.h"

#include <stdio.h>
#include <unistd.h>

int send_response(int client_fd, const char *status, const char *content_type, const char *body,
                  long body_size) {
    char header[512];

    int header_len = snprintf(header, sizeof(header),
                               "HTTP/1.1 %s\r\n"
                               "Content-Type: %s\r\n"
                               "Content-Length: %ld\r\n"
                               "Connection: close\r\n"
                               "\r\n",
                               status, content_type, body_size);

    if (header_len < 0 || (size_t)header_len >= sizeof(header)) {
        return -1;
    }

    if (write(client_fd, header, header_len) == -1) {
        perror("Write Header Failed!");
        return -1;
    }

    if (body_size > 0 && write(client_fd, body, body_size) == -1) {
        perror("Write Body Failed!");
        return -1;
    }

    return 0;
}
