import mysql.connector
import random
import numpy as np
import datetime
import pandas as pd

try:
  #tengo que poner mi contraseña y host es la noexion de nuestr compu
  #aqui se guarda la conexion con tu base de datos de sql
    cnx = mysql.connector.connect(user='root', password='Iyzkw3927', host='127.0.0.1', database='covidDetector', auth_plugin='mysql_native_password')
    cursor = cnx.cursor()

    #estas indicando la condicion para crear una tupla c
    #query_data = (1,)
    #va a tomar una table de data base con %s estas llamando a query data
    # %s es una referencia generica que lo invocas abajo en .execute
   # query = (f"SELECT idPersona FROM persona  ;")

    #estas llamando al query se ejecute con la condicion de query data
    #cursor.execute(query)

    #------operaciones a hacer en la base de datos de sql---
    #agregar a luz, id's de 7 a 18 con valores 0

  #list comprenhension, vas a guardar el ultimo id de luz para de ahí insertar más
    #lastID = [result[0] for result in cursor][-1]

    
    

    #obtener el idPersona para ponerlo en historial
    queryID = (f"select idPersona from persona;")
    cursor.execute(queryID)

    #list comprenhension, vas a guardar el ultimo id de luz para de ahí insertar más
    idsPersona =  [result[0] for result in cursor]
    cantidadPersonas = len(idsPersona)+1
    idControlOXi = [range(0,cantidadPersonas)]

    #(idPerson, oxigeno, fecha, hora, idControlOximetro)
    for x in idsPersona:
      for j in range(0,1000):
        oxigeno = random.randint(95,100)
        ritmo = random.randint(60,100)

        fecha = datetime.datetime(2020,11,11) + datetime.timedelta(days = random.randint(1,30)) 
        hora = datetime.time()
        query_Oxigeno = (x, oxigeno, fecha, hora)
        queryDataOXi = (f"insert into controlOximetro  values( %s, %s, %s, %s) ;")
        
        cursor.execute(queryDataOXi,query_Oxigeno)

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