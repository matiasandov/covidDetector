import matplotlib.pyplot as plt
import random

datos = [ random.randint(50,100) for _ in range(1000)]

plt.plot(datos)
#es con parentesis
plt.show()