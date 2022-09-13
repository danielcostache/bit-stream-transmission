#include "bitStream.h"
#include <stdio.h>

FILE* file;

int main() {
    stream* buffer;
    uint32_t fileSize;
    size_t result;

    file = fopen("data.bin", "rb");

    fseek(file, 0, SEEK_END);
    fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    buffer = (stream*)malloc(sizeof(stream)*fileSize);
    if(buffer == NULL) {
        fputs("Memory error", stderr);
        exit(2);
    }

    result = fread(buffer, sizeof(stream), fileSize, file);
    if(result != fileSize) {
        fputs("Reading error", stderr);
        exit(3);
    }

    

    fclose(file);
    free(buffer);

    return 0;
}