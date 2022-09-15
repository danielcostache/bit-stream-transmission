#include "bitStream.h"
#include <stdio.h>
#include <iostream>

FILE* file;
FILE* check;

int main() {
    stream* buffer = new stream();
    uint32_t fileSize;
    size_t result;

    file = fopen("data.bin", "rb");
    check = fopen("check.txt", "w");

    fseek(file, 0, SEEK_END);
    fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    buffer = (stream*)malloc(sizeof(stream)*fileSize);

    result = fread(buffer, 1, fileSize, file);
    if(result != fileSize) {
        fputs("Reading error", stderr);
        exit(3);
    }

    std::cout << result << '\n';
    std::cout << sizeof(stream) << '\n';
    

    for(int i = 0; i < iterations; i++) {
        fprintf(check, IO_FORMAT, (buffer + i) -> var1, (buffer + i) -> var2, (buffer + i) -> var3,
                          (buffer + i) -> var4, (buffer + i) -> var5, (buffer + i) -> var6);
    }
    free(buffer);

    fclose(file);
    fclose(check);

    return 0;
}