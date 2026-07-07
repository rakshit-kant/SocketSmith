#include "file.h"

#include <stdio.h>

long read_file(const char *filename, char *buffer) {
    FILE *fp = fopen(filename, "rb");

    if (fp == NULL) {
        perror("File Open Failed!");
        return -1;
    }

    size_t bytes_read = fread(buffer, 1, MAX_FILE_SIZE, fp);

    if (ferror(fp)) {
        perror("File Read Failed!");
        fclose(fp);
        return -1;
    }

    fclose(fp);

    return (long)bytes_read;
}
