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

std::ofstream out("output.txt");
const int size1 = 12, size2 = 8, size3 = 32, size4 = 48, size5 = 4, size6 = 16, flushLimit = 200, iterations = 1000;
bool bin1[size1], bin2[size2], bin3[size3], bin4[size4], bin5[size5], bin6[size6];

// Generates a number in decimal using the Mersenne Twister engine and then converts it 
// to binary, placing it in an array of boolean type.
void generateNumberToBinary(int size, bool bin[]) {
    long long int dec, maxNo = pow(2, size), i = size;

    std::random_device randDev;
    std::mt19937_64 engine(randDev());
    std::uniform_int_distribution<unsigned long long> distribution;

    dec = distribution(engine) % maxNo;
    while(dec) {
        bin[--i] = dec % 2; 
        dec /= 2;
    }
}


int main() {
    std::vector<std::vector<bool>> buffer; // Variable that holds a number of 120-bit buffers to print at once
    std::vector<bool> tempBuffer; // Temporary buffer written into the main buffer at the end of each iteration
    int flushCounter = 0; // Counter that manages the flushing of the main buffer

    for(int _ = 0; _ < iterations; _++) {
        tempBuffer.clear();
        std::fill(bin1, bin1+size1, false);
        std::fill(bin2, bin2+size2, false);
        std::fill(bin3, bin3+size3, false);
        std::fill(bin4, bin4+size4, false);
        std::fill(bin5, bin5+size5, false);
        std::fill(bin6, bin6+size6, false);

        // On every iteration, each variable is generated and then added to the temporary buffer
        generateNumberToBinary(size1, bin1);
        tempBuffer.insert(tempBuffer.end(), bin1, bin1+size1);
        generateNumberToBinary(size2, bin2);
        tempBuffer.insert(tempBuffer.end(), bin2, bin2+size2);
        generateNumberToBinary(size3, bin3);
        tempBuffer.insert(tempBuffer.end(), bin3, bin3+size3);
        generateNumberToBinary(size4, bin4);
        tempBuffer.insert(tempBuffer.end(), bin4, bin4+size4);
        generateNumberToBinary(size5, bin5);
        tempBuffer.insert(tempBuffer.end(), bin5, bin5+size5);
        generateNumberToBinary(size6, bin6);
        tempBuffer.insert(tempBuffer.end(), bin6, bin6+size6);

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
    }
    
    // At the end of all the iterations, the leftover buffer is printed to the output file
    for(auto row = buffer.begin(); row != buffer.end(); row++) {
        for(auto col = row -> begin(); col != row -> end(); col++)
            out << *col;
        out << '\n';            
    }
    buffer.clear();

    out.close();
    return 0;
}