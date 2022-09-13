#include "bitStream.h"
#include <stdio.h>

FILE* file;
FILE* test;

int main() {
    stream flux;
    
    file = fopen("data.bin", "wb");
    test = fopen("test.txt", "w");

    for(int _ = 0; _ < iterations; _++) {
        flux = generateStream();
        fwrite(&flux, sizeof(stream), 1, file);
        fprintf(test, IO_FORMAT, flux.var1, flux.var2, flux.var3, flux.var4, flux.var5, flux.var6);
    }

    fclose(file);
    fclose(test);
    
    return 0;
}