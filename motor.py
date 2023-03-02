import time
import serial
import matplotlib.pyplot as plt
import numpy as np

ser = serial.Serial("COM7", 115200)       

module = 80
module_ = 30

# while(1):

#     ser.write(bytes(str(module)+'\n', 'ascii'))
#     time.sleep(10)

#     ser.write(bytes(str(module)+'\n', 'ascii'))
#     time.sleep(10)


for _ in range(1000):
    ser.write(bytes(str(module)+'\n', 'ascii'))
    time.sleep(0.5)

for _ in range(1000):
    ser.write(bytes(str(module_)+'\n', 'ascii'))
    time.sleep(0.5)

    # ser.write(bytes(str(0)+'\n', 'ascii'))
    # time.sleep(0.1)

    # ser.write(bytes(str(volta)+'\n', 'ascii'))
    # time.sleep(1)

    # ser.write(bytes(str(0)+'\n', 'ascii'))
    # time.sleep(0.1)

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