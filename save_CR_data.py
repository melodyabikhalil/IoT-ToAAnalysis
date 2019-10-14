import serial
import time

ser = serial.Serial("COM6",115200)
time.sleep(2) #wait for arduino
file = open("CR_data.txt","w")
i = 0
while (i<400):
    line = ser.readline()
    line = line.decode("utf-8") 
    file.write(line)
    i = i + 1
ser.close()
file.close()
