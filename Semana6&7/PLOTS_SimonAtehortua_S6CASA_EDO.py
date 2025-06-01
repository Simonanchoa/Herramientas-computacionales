import matplotlib.pyplot as plt
import numpy as np

def plot_results(method, h):
    data = np.loadtxt(f"{method}_h{h}.dat")
    t = data[:,0]
    y_num = data[:,1]
    y_exact = data[:,2]
    
    plt.figure(figsize=(10,6))
    plt.plot(t, y_num, 'o-', label='Numérico')
    plt.plot(t, y_exact, 'r-', label='Analítico')
    plt.title(f"Método {method.upper()} (h = {h})")
    plt.xlabel('t')
    plt.ylabel('y(t)')
    plt.legend()
    plt.grid()
    plt.savefig(f"{method}_h{h}.png")
    
    # Gráfico de error
    error = np.abs(y_num - y_exact)
    plt.figure(figsize=(10,6))
    plt.plot(t, error, 'm-', label='Error absoluto')
    plt.title(f"Error {method.upper()} (h = {h})")
    plt.xlabel('t')
    plt.ylabel('Error')
    plt.legend()
    plt.grid()
    plt.savefig(f"error_{method}_h{h}.png")

# Generar todos los gráficos
for method in ['euler', 'rk4']:
    for h in [0.1, 0.05]:
        plot_results(method, h)

plt.close('all')
