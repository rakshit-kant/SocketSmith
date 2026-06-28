#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd == -1) {
        perror("Bad Socket\n");
        return 1;
    }

    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    printf("Socket Created!\nFD = %d\n", server_fd);

    // while (1) {
    //     printf("Waiting for Request...\n");
    //     sleep(1);
    // }
    return 0;
}
