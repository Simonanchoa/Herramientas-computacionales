import numpy as np
import matplotlib.pyplot as plt

def leer_datos(filename):
    data = np.loadtxt(filename, comments="#", skiprows=1)

    t = data[:, 0]
    x = data[:, 1]
    v = data[:, 2]

    return t, x, v

def graficar(t, x, v, metodo):
    # Posición
    plt.figure(figsize=(10, 5))
    plt.plot(t, x, 'b-', label=f'{metodo} - Numérica')
    plt.title(f'Posición vs Tiempo ({metodo})')
    plt.xlabel('Tiempo (s)')
    plt.ylabel('Posición (m)')
    plt.legend()
    plt.grid(True)
    plt.savefig(f'posicion_{metodo}.png')

    # Velocidad
    plt.figure(figsize=(10, 5))
    plt.plot(t, v, 'g-', label=f'{metodo} - Numérica')
    plt.title(f'Velocidad vs Tiempo ({metodo})')
    plt.xlabel('Tiempo (s)')
    plt.ylabel('Velocidad (m/s)')
    plt.legend()
    plt.grid(True)
    plt.savefig(f'velocidad_{metodo}.png')

    plt.close('all')

# Leer y graficar métodos
for archivo, metodo in [('resultados_euler.txt', 'Euler'), ('resultados_leap_frog.txt', 'Leapfrog')]:
    t, x, v= leer_datos(archivo)
    graficar(t, x, v, metodo)
