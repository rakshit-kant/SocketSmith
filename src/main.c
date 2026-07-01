#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd == -1) {
        perror("Bad Socket");
        return 1;
    }

    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    printf("Socket Created!\nFD = %d\n", server_fd);

    int result = bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    if (result == -1) {
        perror("Bind Failed!");
        return 1;
    }

    printf("Bind Successful!\n");

    int backlog = 5;

    int request = listen(server_fd, backlog);

    if (request == -1) {
        perror("Listen Failed!");
        close(server_fd);
        return 1;
    }

    while (1) {
        struct sockaddr_in client_addr = {0};
        socklen_t client_len = sizeof(client_addr);

        int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);

        if (client_fd == -1) {
            perror("Accept Failed!");
            continue;
        }

        printf("Client Connected!\n");

        char buffer[4097];

        ssize_t bytes_read = read(client_fd, buffer, sizeof(buffer));

        if (bytes_read == -1) {
            perror("Read Failed!");
        } else if (bytes_read == 0) {
            printf("Client Disconnected!\n");
        } else {
            buffer[bytes_read] = '\0';
            printf("%s\n", buffer);
        }

        const char *body = "<!DOCTYPE html>"
                           "<html>"
                           "	<head>"
                           "		<title>SocketSmith</title>"
                           "	</head>"

                           "	<body>"
                           "		<h1> Hello from SocketSmith!</h1>"
                           "		<p> My first HTTP Server in C</p>"
                           "	</body>"
                           "</html>";
        size_t body_len = strlen(body);
        char response[8192];
        snprintf(response, sizeof(response),
                 "HTTP/1.1 200 OK\r\n"
                 "Content-Type: text/html\r\n"
                 "Content-Length: %zu\r\n"
                 "\r\n"
                 "%s",
                 body_len, body);

        ssize_t bytes_sent = send(client_fd, response, strlen(response), 0);

        if (bytes_sent == -1) {
            perror("Send Failed!");
        }

        close(client_fd);
    }

    close(server_fd);
    return 0;
}
