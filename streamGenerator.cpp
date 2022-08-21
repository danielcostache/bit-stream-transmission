/*  
    This program randomly generates variables of a certain significance for an event and 
    then encodes them into 120-bit long expressions. The program does this for a certain 
    number of events and outputs each expression into a text file for further analysis.
    The variables in the expression have dimensions as such:
        - 12-bit 
        - 8-bit
        - 32-bit
        - 48-bit
        - 4-bit
        - 16-bit
*/

#include <bits/stdc++.h>
#include <random>
#include <time.h>

std::ofstream out("output.txt");
std::ofstream outDec("outputDec.txt");
const int size1 = 12, size2 = 8, size3 = 32, size4 = 48, size5 = 4, size6 = 16;
bool bin1[size1], bin2[size2], bin3[size3], bin4[size4], bin5[size5], bin6[size6];

// Generates a number in decimal using the Mersenne Twister engine and then converts it 
// to binary, placing it in an array of boolean type.
void generateNumberToBinary(int size, bool bin[]) {

    long long int dec, maxNo = pow(2, size), i = size;

    std::random_device randDev;
    std::mt19937_64 engine(randDev());
    std::uniform_int_distribution<unsigned long long> distribution;

    dec = distribution(engine) % maxNo;
    outDec << dec << " ";
    while(dec) {
        bin[--i] = dec % 2; 
        dec /= 2;
    }
}

int main() {
    std::vector<bool> buffer;
    for(int count = 0; count < 50; count++) {
        generateNumberToBinary(size1, bin1);
        for(int i = 0; i < size1; i++)
            buffer.push_back(bin1[i]);
        outDec << " ";
        generateNumberToBinary(size2, bin2);
        for(int i = 0; i < size2; i++)
            buffer.push_back(bin2[i]);
        outDec << " ";
        generateNumberToBinary(size3, bin3);
        for(int i = 0; i < size3; i++)
            buffer.push_back(bin3[i]);
        outDec << " ";
        generateNumberToBinary(size4, bin4);
        for(int i = 0; i < size4; i++)
            buffer.push_back(bin4[i]);
        outDec << " ";
        generateNumberToBinary(size5, bin5);
        for(int i = 0; i < size5; i++)
            buffer.push_back(bin5[i]);
        outDec << " ";
        generateNumberToBinary(size6, bin6);
        for(int i = 0; i < size6; i++)
            buffer.push_back(bin6[i]);
        for(bool i : buffer)
            out << i;
        out << '\n';
        outDec << '\n';
        buffer.clear();
    }
    out.close();
    outDec.close();
    return 0;
}