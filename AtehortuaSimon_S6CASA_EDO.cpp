#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

double f(double t, double y) {
    return -y;
}

double solucion_analitica(double t) {
    return exp(-t);
}

void euler(double t0, double y0, double h, int n, string filename) {
    ofstream file(filename);
    double t = t0;
    double y = y0;
    
    file << fixed << setprecision(6);
    file << "t\tEuler\tAnalitica\tError\n";
    
    for (int i = 0; i <= n; i++) {
        double y_analitica = solucion_analitica(t);
        file << t << "\t" << y << "\t" << y_analitica << "\t" << fabs(y - y_analitica) << endl;
        
        y = y + h * f(t, y);
        t = t + h;
    }
    
    file.close();
}

void rungeKutta4(double t0, double y0, double h, int n, string filename) {
    ofstream file(filename);
    double t = t0;
    double y = y0;
    
    file << fixed << setprecision(6);
    file << "t\tRK4\tAnalitica\tError\n";
    
    for (int i = 0; i <= n; i++) {
        double y_analitica = solucion_analitica(t);
        file << t << "\t" << y << "\t" << y_analitica << "\t" << fabs(y - y_analitica) << endl;
        
        double k1 = h * f(t, y);
        double k2 = h * f(t + h/2, y + k1/2);
        double k3 = h * f(t + h/2, y + k2/2);
        double k4 = h * f(t + h, y + k3);
        
        y = y + (k1 + 2*k2 + 2*k3 + k4)/6;
        t = t + h;
    }
    
    file.close();
}

int main() {
    double t0 = 0.0;    
    double y0 = 1.0;    
    double h = 0.1;      
    int n = 100;        
    
    euler(t0, y0, h, n, "euler_results.txt");
    rungeKutta4(t0, y0, h, n, "rk4_results.txt");
    
    cout << "Resultados generados en euler_results.txt y rk4_results.txt" << endl;
    
    return 0;
}