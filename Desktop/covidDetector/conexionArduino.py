import serial

ser = serial.Serial("/dev/cu.usbmodem14101",9600)
while(1):
    lineBytes=ser.readline();
    line=lineBytes.decode("ascii")
    if line[0:2]!="HR":
        continue
    #quitas enter
    line=line.rstrip();
    #separas los datos de HR y milisegundos
    medidas=line.split(";")
    #aqui esta HR en la foto se explica el rpoceso pero se toma 
    #el string del elemento 0, y se hace cast a INT
    hr=int(medidas[0].split(":")[1])
    #aquí esta Milisegundos
    milis=int(medidas[1].split(":")[1])
    print(hr)