"""
    This program receives streams of bits via a text file and decodes them into 
    usable variables, and can then print or plot said data structure. The program 
    checks for faults in the bit transmission and signals the user whether the 
    120-bit expressions are valid or not. 
"""

import pandas as pd
import matplotlib.pyplot as plt 
import time

size1 = 12
size2 = 8
size3 = 32
size4 = 48
size5 = 4
size6 = 16

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
    buffer = []
    with open('output.txt', 'r') as inFile:
        with open('log.txt', 'w') as log:
            for counter, line in enumerate(inFile, start = 0):
                line = line.rstrip()
                if len(line) < 120:
                    log.write(f"ERROR! Incomplete expression at line: {counter + 1}")
                    raise BitLossError
                elif len(line) > 120:
                    log.write(f"ERROR! Excess bits in expression at line: {counter + 1}")
                    raise BitExcessError
                buffer.append(line)     
            log.write("OK!\n")
    return buffer
    
    
# Splits the 120-bit expressions into usable variables and appends them 
# to corresponding lists
def splitBuffer(buffer):
    temp = []
        
    bin1 = buffer[:size1]
    buffer = buffer[size1:]
    temp.append(int(bin1, 2))
    
    bin2 = buffer[:size2]
    buffer = buffer[size2:]
    temp.append(int(bin2, 2))
    
    bin3 = buffer[:size3]
    buffer = buffer[size3:]
    temp.append(int(bin3, 2))
    
    bin4 = buffer[:size4]
    buffer = buffer[size4:]
    temp.append(int(bin4, 2))
    
    bin5 = buffer[:size5]
    buffer = buffer[size5:]
    temp.append(int(bin5, 2))
    
    bin6 = buffer[:size6]
    buffer = buffer[size6:]
    temp.append(int(bin6, 2))
    
    return temp


def main() -> None:
    decDF = pd.DataFrame({"Variable 1" : [], "Variable 2" : [], "Variable 3" : [],
                          "Variable 4" : [], "Variable 5" : [], "Variable 6" : []})
    
    t = time.time()

    buffer = readCheckLines()
    
    print("Reading:", time.time() - t)
    t = time.time()

    for tempBuffer in buffer:
        decDF.loc[len(decDF)] = splitBuffer(tempBuffer)
        buffer.pop(buffer.index(tempBuffer))
    
    print("Splitting data:", time.time() - t)
    
    if input("Do you want to read the data or plot the data? [1/2]\n") == '1':
        print(decDF)
    else:
        hist = decDF.hist(edgecolor='black', figsize=(10, 10))
        plt.show()
    

if __name__ == '__main__':
    main()