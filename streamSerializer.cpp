#include "bitStream.h"
#include <stdio.h>

const int iterations = 100, bufferSize = 20;

FILE* file;

int main() {
    stream flux;
    
    file = fopen("data.bin", "wb");

    for(int _ = 0; _ < iterations; _++) {
        flux = generateStream();
        fwrite(&flux, sizeof(stream), 1, file);
        printf(IO_FORMAT, flux.var1, flux.var2, flux.var3, flux.var4, flux.var5, flux.var6);
    }

    fclose(file);
    
    return 0;
}