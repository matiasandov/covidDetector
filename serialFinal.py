import serial
import mysql.connector
import matplotlib.pyplot as plt
import random
from scipy.signal import find_peaks
import numpy as np
import datetime

# 25 samples per second (in algorithm.h)
SAMPLE_FREQ = 25
# taking moving average of 4 samples when calculating HR
# in algorithm.h, "DONOT CHANGE" comment is attached
MA_SIZE = 4
# sampling frequency * 4 (in algorithm.h)
BUFFER_SIZE = 100

#hr es points
def smooth_curve_average(points,miliseconds, sample_size):

    smoothed_points = []
    smoothed_time = []

    #recuerda que rango es (inicio, stop, step)
    for x in range(0, len(points), sample_size):
        #guardar en una lista los elementos del subconjunto
        subconjunto = points[x:x+sample_size] 
        promedioSubconjunto = sum(subconjunto) / len(subconjunto)
        #se regresa lista con promedios 
        smoothed_points.append(promedioSubconjunto)

        #lo mismo para el tiempo
        subconjuntoTiempo = miliseconds[x:x+sample_size]
        promedioSubTiempo = sum(subconjuntoTiempo) / len(subconjuntoTiempo)
        smoothed_time.append(promedioSubTiempo)

    return smoothed_points, smoothed_time




ser=serial.Serial("/dev/cu.usbmodem14101", 9600)
hrValues=[]
miliValues=[]

    

while(1):
    try:
        lineBytes=ser.readline()
        line=lineBytes.decode("ascii")
        line=line.rstrip();#HR:118;ML:1704
        print(line)
        medidas=line.split(";") #["HR:118", "ML:1704"]
        hr=int(medidas[0].split(":")[1]) #["HR", "118"], toma el 118, lo convierte a int y lo guarda
        milis=int(medidas[1].split(":")[1]) #["ML", "1704"]
        
        #red=int(medidas[2].split(":")[1])
        #ir=int(medidas[3].split(":")[1])
        hrValues.append(hr)
        miliValues.append(milis)
        #redValues.append(red)
        #irValues.append(ir)
    except:
        #continue
        if(len(hrValues)==1000):
                #print(hrValues)
                
                #quita primeros 25 
                hrValues=hrValues[25:]
                miliValues=miliValues[25:]
                
                #creo que si lo estoy pasando de 25 en 25 no necesito sample size o no sé
                HrResultado,tiempoR = smooth_curve_average(hrValues,miliValues,100)

                HrPromedio = np.average(HrResultado)
                tiempoPromedio = np.average(tiempoR)

                plt.plot(tiempoR,HrResultado)
                plt.show()

                pulsoFinal = HrPromedio/tiempoPromedio
                print(HrPromedio)
                #redValues=redValues[25:]
                #irValues=irValues[25:]

                try:
    
                    cnx = mysql.connector.connect(user='root', password='Iyzkw3927', host='127.0.0.1', database='covidDetector', auth_plugin='mysql_native_password')
                    cursor = cnx.cursor()

                    #(idPerson, oxigeno, fecha, hora, idControlOximetro)
                    persona = 1
                    idPulsooo = 1
                    fecha = datetime.datetime(2020,11,26) 
                    hora = datetime.time()
                    queryPulso = (persona, idPulsooo, fecha, hora, pulsoFinal)
                    queryDataPulso = (f"insert into controlPulso (idPersona, idControlPulso,fecha, hora, pulso) values( %s, %s, %s, %s, %s) ;")
                            
                    cursor.execute(queryDataPulso,queryPulso)

                            #para hacer cambios en database 
                    cnx.commit()

                except mysql.connector.Error as err:
                #si hay un error ocurrira esto
                #en caso de que se niegue el acceso a la base de datos
                    if err.errno == mysql.connector.errorcode.ER_ACCESS_DENIED_ERROR:
                        print("Something is wrong with your user name or password")
                        #si no existe la base de datos
                    elif err.errno == mysql.connector.errorcode.ER_BAD_DB_ERROR:
                        print("Database does not exist")
                    else:
                        print(err)
                    
                finally:
                #esto se hará si o sí 
                    if 'cnx' in locals() or 'cnx' in globals():
                        cnx.close()