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

    struct sockaddr_in {
        short int sin_family;
        unsigned short int sin_port;
        struct in_addr sin_addr;
        unsigned char sin_zero[8];
    };

    struct in_addr {
        uint32_t s_addr;
    };

    printf("Socket Created!\nFD = %d\n", server_fd);

    // while (1) {
    //     printf("Waiting for Request...\n");
    //     sleep(1);
    // }
    return 0;
}
