import time
import serial
import matplotlib.pyplot as plt
import numpy as np

ser = serial.Serial("COM14", 115200)       

ida = 90
volta = -90

while(1):

    ser.write(bytes(str(ida)+'\n', 'ascii'))
    time.sleep(0.6)

    ser.write(bytes(str(0)+'\n', 'ascii'))
    time.sleep(0.1)

    ser.write(bytes(str(volta)+'\n', 'ascii'))
    time.sleep(0.6)

    ser.write(bytes(str(0)+'\n', 'ascii'))
    time.sleep(0.1)

    #count = volta
    
    # while(count < ida):
    #     time.sleep(0.5)
    #     count = count + 30
    #     ser.write(bytes(str(count)+'\n', 'ascii'))
    
    # while(count > volta):
    #     time.sleep(0.5)
    #     count = count - 30
    #     ser.write(bytes(str(count)+'\n', 'ascii'))

ser.close()