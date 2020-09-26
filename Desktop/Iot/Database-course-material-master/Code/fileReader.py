import csv
import pandas as pd
import numpy as np

#se abre el archivo y se guarda en la variable csvFreader

poblacion = pd.read_csv("TextFiles/populationbycountry19802010millions.csv")

#ordenar por poblacion año 2010 en orden descendente 
by_yearP = poblacion.sort_values('2010',ascending=False)

#print(by_yearP.head(10))

#se abre el archivo y se guarda en la variable 

co2 = pd.read_csv("TextFiles/greenhouse_gas_inventory_data_data.csv")

#ordenar por poblacion año 2010 en orden ascendente checar
by_CO2 = co2.sort_values('value',ascending=False)  

byCO2_2010 = by_CO2[by_CO2.year == 2010]

print(byCO2_2010.head(10))







    