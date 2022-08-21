"""
    This program receives streams of bits via a text file and decodes them into 
    usable variables, and then plots them. The program checks for faults in the 
    bit transmission and signals the user whether the 120-bit expressions are 
    valid or not. 
"""

from asyncore import read
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt 

size1 = 12
size2 = 8
size3 = 32
size4 = 48
size5 = 4
size6 = 16
dec1 = []
dec2 = []
dec3 = []
dec4 = []
dec5 = []
dec6 = []


# Default Error Class
class Error(Exception):
    pass

# Raised when the expression is less than 120-bit long
class BitLossError(Error):
    pass

# Raised when the expression is more than 120-bit long
class BitExcessError(Error):
    pass

# Reads the incoming data and checks whether it is valid
def readCheckLines():
    with open('output.txt', 'r') as inFile:
        buffer = inFile.readlines()
        buffer = [line.rstrip() for line in buffer]
    with open('log.txt', 'w') as log:
        for line in buffer:
            if len(line) < 120:
                log.write("ERROR! Incomplete expression!")
                raise BitLossError
            elif len(line) > 120:
                log.write("ERROR! Excess bits in expression!")
                raise BitExcessError
            else:
                log.write(line + "\n")
        log.write("OK!\n")
    return buffer
    
    

def splitBuffer(buffer):
    bin1 = buffer[:size1]
    buffer = buffer[size1:]
    dec1.append(int(bin1, 2))
    
    bin2 = buffer[:size2]
    buffer = buffer[size2:]
    dec2.append(int(bin2, 2))
    
    bin3 = buffer[:size3]
    buffer = buffer[size3:]
    dec3.append(int(bin3, 2))
    
    bin4 = buffer[:size4]
    buffer = buffer[size4:]
    dec4.append(int(bin4, 2))
    
    bin5 = buffer[:size5]
    buffer = buffer[size5:]
    dec5.append(int(bin5, 2))
    
    bin6 = buffer[:size6]
    buffer = buffer[size6:]
    dec6.append(int(bin6, 2))


def main() -> None:
    buffer = readCheckLines()
    for tempBuffer in buffer:
        splitBuffer(tempBuffer)
    print(dec1)
    print(dec2)
    print(dec3)
    print(dec4)
    print(dec5)
    print(dec6)
    



if __name__ == '__main__':
    main()