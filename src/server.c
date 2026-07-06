#include "server.h"

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

int create_server(int port) {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd == -1) {
        perror("Bad Socket");
        return -1;
    }

    printf("Socket Created!\n");
    printf("FD = %d\n", server_fd);

    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Bind Failed!");
        close(server_fd);
        return -1;
    }

    printf("Bind Successful!\n");

    if (listen(server_fd, 5) == -1) {
        perror("Listen Failed");
        close(server_fd);
    }

    return server_fd;
}
