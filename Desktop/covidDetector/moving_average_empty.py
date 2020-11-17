import matplotlib.pyplot as plt
import random

def smooth_curve_average(points, sample_size):
    smoothed_points = []

    return smoothed_points

def smooth_curve_exponential(points, factor=0.9):
    smoothed_points = []

    return smoothed_points

sample_size = 20
data_series = []
peaks = []

random.seed(0)

while len(data_series) < 1000:
    data_series.append(random.uniform(360, 380))

data_series_smooth_ex = smooth_curve_exponential(data_series, 0.95)
data_series_smooth_av = smooth_curve_average(data_series, 20)

plt.plot(data_series)
plt.plot(data_series_smooth_ex)
plt.plot(data_series_smooth_av)
plt.plot()
plt.ylabel("Data")

plt.show()


