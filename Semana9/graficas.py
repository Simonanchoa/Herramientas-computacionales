import matplotlib.pyplot as plt
import numpy as np

x=np.genfromtxt("posicioninicial.txt",skip_header=1) 

pt=np.linspace(0,100,101)

print("x:", x)
print("Shape of x:", x.shape)


plt.figure()
plt.plot(pt,x)
plt.show()