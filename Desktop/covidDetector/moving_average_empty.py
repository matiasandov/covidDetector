import matplotlib.pyplot as plt
import random
import pandas as pd
import statistics as ss

#sample size = tamaño de la ventana o del periodo sobre el cual sera el promedio 
def smooth_curve_average(points, sample_size):

    smoothed_points = []

    #recuerda que rango es (inicio, stop, step)
    for x in range(0, len(points), sample_size):
        #guardar en una lista los elementos del subconjunto
        subconjunto = points[x:x+sample_size] 
        promedioSubconjunto = sum(subconjunto) / len(subconjunto)
        #se regresa lista con promedios 
        smoothed_points.append(promedioSubconjunto)
    return smoothed_points

def smooth_curve_exponential(points, factor=0.9):
    smoothed_points = []

    for x in range(1, len(points)):
        linea = points[x-1]*factor + points[x]*(1-factor)
        smoothed_points.append(linea)

    return smoothed_points

sample_size = 20
data_series = []
peaks = []

random.seed(0)

while len(data_series) < 1000:
    data_series.append(random.uniform(360, 380))

data_series_smooth_ex = smooth_curve_exponential(data_series, 0.95)
data_series_smooth_av = smooth_curve_average(data_series, 20)

#plt.plot(data_series)
plt.plot(data_series_smooth_ex)
plt.plot(data_series_smooth_av)
plt.plot()
plt.ylabel("Data")

plt.show()


