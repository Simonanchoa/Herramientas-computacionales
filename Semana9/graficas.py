import matplotlib.pyplot as plt
import numpy as np

x=np.genfromtxt("resultado.txt")
pt=np.linspace(0,100,101)

plt.figure()
for i in range(300):
  xi=x[i]
  plt.plot(pt,xi)
plt.show()