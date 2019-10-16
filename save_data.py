#SF 3 values
#PS 4 values
#CR 4 values
#BW 10 values

import serial
import time

def save_data(path,iterations):
    ser = serial.Serial("COM6",115200)
    print('1')
    time.sleep(2) #wait for arduino
    print('finish waiting')
    file = open(path,"w")
    i = 0
    while (i<iterations):
        print('before readline')
        line = ser.readline()
        line = line.decode("utf-8")
        print(line)
        file.write(line)
        i = i + 1
    ser.close()
    file.close()

save_data('./SF/SF_data.txt',300)
