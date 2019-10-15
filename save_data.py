#SF 3 values
#PS 4 values
#CR 4 values
#BW 10 values

import serial
import time

def save_data(path,iterations):
    ser = serial.Serial("COM6",115200)
    time.sleep(2) #wait for arduino
    file = open(path,"w")
    i = 0
    while (i<iterations):
        line = ser.readline()
        line = line.decode("utf-8") 
        file.write(line)
        i = i + 1
    ser.close()
    file.close()
