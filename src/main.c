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
        close(server_fd);
        return 1;
    }

    printf("Bind Successful!\n");

    if (listen(server_fd, 5) == -1) {
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

        ssize_t bytes_read = read(client_fd, buffer, sizeof(buffer) - 1);

        if (bytes_read <= 0) {
            if (bytes_read == 0) {
                printf("Client Disconnected!\n");
            } else {
                perror("Read Failed!");
            }
            close(client_fd);
            continue;
        }

        buffer[bytes_read] = '\0';

        char *first_line = strtok(buffer, "\r\n");

        char method[16];
        char path[256];
        char version[16];

        if (first_line != NULL) {
            sscanf(first_line, "%15s %255s %15s", method, path, version);

            printf("Method: %s\n", method);
            printf("Path: %s\n", path);
            printf("Version: %s\n", version);
        }

        const char *status;
        const char *filename;

        if (strcmp(path, "/") == 0 || strcmp(path, "/home") == 0) {
            status = "200 OK";
            filename = "public/index.html";
        } else if (strcmp(path, "/about") == 0) {
            status = "200 OK";
            filename = "public/about.html";
        } else {
            status = "404 Not Found";
            filename = "public/404.html";
        }

        FILE *file = fopen(filename, "r");

        if (file == NULL) {
            perror("fopen");
            close(client_fd);
        }

        fseek(file, 0, SEEK_END);
        long file_size = ftell(file);
        rewind(file);

        char body[8192];

        fread(body, 1, file_size, file);
        body[file_size] = '\0';

        fclose(file);

        char response[8192];

        snprintf(response, sizeof(response),
                 "HTTP/1.1 %s\r\n"
                 "Content-Type: text/html\r\n"
                 "Content-Length: %ld\r\n"
                 "Connection: close\r\n"
                 "\r\n"
                 "%s",
                 status, file_size, body);

        ssize_t bytes_sent = send(client_fd, response, strlen(response), MSG_NOSIGNAL);

        if (bytes_sent == -1) {
            perror("Send Failed!");
        }

        close(client_fd);
    }

    close(server_fd);
    return 0;
}
