#include "bitStream.h"
#include <stdio.h>

FILE* file;
FILE* test;

int main() {
    stream* buffer = new stream();
    
    file = fopen("data.bin", "wb");
    test = fopen("test.txt", "w");

    buffer = (stream*)malloc(sizeof(stream)*iterations + 1);

    for(int i = 0; i < iterations; i++) {
        *(buffer + i) = generateStream();
        fprintf(test, IO_FORMAT, (buffer + i) -> var1, (buffer + i) -> var2, (buffer + i) -> var3,
                           (buffer + i) -> var4, (buffer + i) -> var5, (buffer + i) -> var6);
    }
    fwrite(buffer, sizeof(stream), iterations, file);
    free(buffer);

    fclose(file);
    fclose(test);
    
    return 0;
}