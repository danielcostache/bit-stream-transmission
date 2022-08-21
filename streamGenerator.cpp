#include <bits/stdc++.h>
#include <random>
#include <time.h>

std::ofstream out("output.txt");
std::ofstream outDec("outputDec.txt");
const int size1 = 12, size2 = 8, size3 = 32, size4 = 48, size5 = 4, size6 = 16;
bool bin1[size1], bin2[size2], bin3[size3], bin4[size4], bin5[size5], bin6[size6];

void generateNumberToBinary(int size, bool bin[]){
    long long int dec;
    int i = size;
    dec = rand() % int(pow(2, size));
    outDec << dec << " ";
    // std::cout << dec << '\n';
    while(dec) {
        bin[--i] = dec % 2; 
        dec /= 2;
    }
}

int main() {
    srand(time(NULL));
    for(int count = 0; count < 50; count++) {
        generateNumberToBinary(size1, bin1);
        for(int i = 0; i < size1; i++) 
            out << bin1[i];
        out << " ";
        outDec << " ";
        generateNumberToBinary(size2, bin2);
        for(int i = 0; i < size2; i++)
            out << bin2[i];
        out << " ";
        outDec << " ";
        generateNumberToBinary(size3, bin3);
        for(int i = 0; i < size3; i++)
            out << bin3[i];
        out << " ";
        outDec << " ";
        generateNumberToBinary(size4, bin4);
        for(int i = 0; i < size4; i++)
            out << bin4[i];
        out << " ";
        outDec << " ";
        generateNumberToBinary(size5, bin5);
        for(int i = 0; i < size5; i++)
            out << bin5[i];
        out << " ";
        outDec << " ";
        generateNumberToBinary(size6, bin6);
        for(int i = 0; i < size6; i++)
            out << bin6[i];
        out << '\n';
        outDec << '\n';
    }
    out.close();
    outDec.close();
    return 0;
}