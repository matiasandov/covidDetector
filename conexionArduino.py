import serial
import numpy as np

ser = serial.Serial("/dev/cu.usbmodem14101",9600)
#while true, mientras se reciban datos
while(1):
    
    lineBytes=ser.readline()
    line=lineBytes.decode("ascii")
    line=line.rstrip()
    partes=line.split(";")
    print(partes)
    hr=int(partes[0].split(":")[1])
    milis=int(partes[1].split(":")[1])
    print(hr, "milis",milis)
    
    

