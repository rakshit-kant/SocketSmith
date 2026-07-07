#ifndef RESPONSE_H
#define RESPONSE_H

int send_response(int client_fd, const char *status, const char *content_type, const char *body,
                  long body_size);

#endif
