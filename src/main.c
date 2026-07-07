#include "client.h"
#include "file.h"
#include "mime.h"
#include "request.h"
#include "response.h"
#include "router.h"
#include "server.h"

#include <unistd.h>

int main(void) {
    int server_fd = create_server(8080);

    if (server_fd == -1) {
        return 1;
    }

    while (1) {
        int client_fd = accept_client(server_fd);

        if (client_fd == -1) {
            continue;
        }

        Request request;

        if (read_request(client_fd, &request) == -1) {
            close(client_fd);
            continue;
        }

        Route route = route_request(request.path);

        char body[MAX_FILE_SIZE];

        long body_size = read_file(route.filename, body);

        if (body_size == -1) {
            close(client_fd);
            continue;
        }

        const char *mime = get_mime_type(route.filename);

        send_response(client_fd, route.status, mime, body, body_size);

        close(client_fd);
    }

    close(server_fd);

    return 0;
}
