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
const int size1 = 12, size2 = 8, size3 = 32, size4 = 48, size5 = 4, size6 = 16, flushLimit = 100;
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
    std::vector<std::vector<bool>> buffer; // Variable that holds a number of 120-bit buffers to print at once
    std::vector<bool> tempBuffer; // Temporary buffer written into the main buffer at the end of each iteration
    int flushCounter = 0; // Counter that manages the flushing of the main buffer

    for(int iterations = 0; iterations < 10; iterations++) {
        tempBuffer.clear();

        // On every iteration, each variable is generated and then added to the temporary buffer
        generateNumberToBinary(size1, bin1);
        for(int i = 0; i < size1; i++)
            tempBuffer.push_back(bin1[i]);
        outDec << " ";
        generateNumberToBinary(size2, bin2);
        for(int i = 0; i < size2; i++)
            tempBuffer.push_back(bin2[i]);
        outDec << " ";
        generateNumberToBinary(size3, bin3);
        for(int i = 0; i < size3; i++)
            tempBuffer.push_back(bin3[i]);
        outDec << " ";
        generateNumberToBinary(size4, bin4);
        for(int i = 0; i < size4; i++)
            tempBuffer.push_back(bin4[i]);
        outDec << " ";
        generateNumberToBinary(size5, bin5);
        for(int i = 0; i < size5; i++)
            tempBuffer.push_back(bin5[i]);
        outDec << " ";
        generateNumberToBinary(size6, bin6);
        for(int i = 0; i < size6; i++)
            tempBuffer.push_back(bin6[i]);

        // At the end of each iteration, the temporary buffer is added to the main buffer 
        // and the flush condition is checked and if met, the main buffer is printed to 
        // the output file and then flushed
        buffer.push_back(tempBuffer);
        flushCounter++;
        if(flushCounter >= flushLimit) {
            flushCounter = 0;
            for(auto row = buffer.begin(); row != buffer.end(); row++) {
                for(auto col = row -> begin(); col != row -> end(); col++)
                    out << *col;
                out << '\n';            
            }
            buffer.clear();
        }
        
        outDec << '\n';
    }
    // At the end of all the iterations, the leftover buffer is printed to the output file
    for(auto row = buffer.begin(); row != buffer.end(); row++) {
        for(auto col = row -> begin(); col != row -> end(); col++)
            out << *col;
        out << '\n';            
    }
    buffer.clear();

    out.close();
    outDec.close();
    return 0;
}