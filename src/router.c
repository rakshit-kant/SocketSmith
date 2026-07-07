#include "router.h"

#include <string.h>

Route route_request(const char *path) {
    Route route;

    if (strstr(path, "..") != NULL) {
        route.status = "403 Forbidden";
        route.filename = "public/404.html";
        return route;
    }

    if (strcmp(path, "/") == 0) {
        route.status = "200 OK";
        route.filename = "public/index.html";
    } else if (strcmp(path, "/about") == 0 || strcmp(path, "/about.html") == 0) {
        route.status = "200 OK";
        route.filename = "public/about.html";
    } else if (strcmp(path, "/style.css") == 0) {
        route.status = "200 OK";
        route.filename = "public/style.css";
    } else {
        route.status = "404 Not Found";
        route.filename = "public/404.html";
    }

    return route;
}
