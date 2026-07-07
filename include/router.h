#ifndef ROUTER_H
#define ROUTER_H

typedef struct {
    const char *status;
    const char *filename;
} Route;

Route route_request(const char *path);

#endif
