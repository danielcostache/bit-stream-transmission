#include <stdlib.h>
#include <random>

const int size1 = 12, size2 = 8, size3 = 32, size4 = 48, size5 = 4, size6 = 16;
const char* IO_FORMAT = "%u %u %u %lu %u %u \n";

struct stream {
    uint16_t var1:size1;
    uint16_t var2:size2;
    uint32_t var3:size3;
    uint64_t var4:size4;
    uint16_t var5:size5;
    uint16_t var6:size6;
};

auto generateNumber(int size) {
    uint64_t maxNo = pow(2, size);

    std::random_device randDev;
    std::mt19937_64 engine(randDev());
    std::uniform_int_distribution<unsigned long long> distribution;
    
    return distribution(engine) % maxNo;
}

stream generateStream() {
    stream temp = {
        .var1 = generateNumber(size1),
        .var2 = generateNumber(size2),
        .var3 = generateNumber(size3),
        .var4 = generateNumber(size4),
        .var5 = generateNumber(size5),
        .var6 = generateNumber(size6),
    };
    return temp;
}