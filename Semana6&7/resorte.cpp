#include <iostream>
#include <array>
#include <string>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

double dv(double x){
    double k=50;
    double m=0.2;
    return -k/m*x;
}

void euler(double h, double t, string filename){
    int n=t/h;
    double y[n];
    double v[n];
    
    y[0]=0.1;
    v[0]=0;
    
    ofstream datos_eu(filename);
    datos_eu << fixed << setprecision(3);
    datos_eu << "t\tposición\tvelocidad\n"; 
    
    for (int i=0; i<=n; ++i){
        double tiempo=i*h;
        datos_eu << tiempo << "\t"<< y[i] <<"\t" << v[i] << "\n";
        y[i+1]=y[i] +h*v[i] ;
        v[i+1]=v[i]+h*dv(y[i]);
    }
    datos_eu.close();

}

void lf(double h,double t, string datos){
    ofstream datos_lf(datos);
    int n=t/h;
    double y[n+1];
    double v_medios[n+1];
    y[0]=0.1;
    v_medios[0]=0.5*h*dv(y[0]);
    datos_lf << fixed << setprecision(3);
    datos_lf << "t\tposición\tvelocidad\n";
    for (int i=0; i<= n; ++i) {
        datos_lf << i*h << "\t" << y[i] << "\t" << v_medios[i] - 0.5 * h * dv(y[i])<< "\n";
        y[i+1]=y[i]+h*v_medios[i];
        v_medios[i+1]=v_medios[i]+h*dv(y[i+1]);
    }
    datos_lf.close();
}

int main() {
    double t=10.0;
    double h=0.01;
    
    lf(h,t, "resultados_leap_frog.txt");
    euler(h, t, "resultados_euler.txt");
    
    cout << "Los resultados se generaron en los archivos correspondientes"<< endl;
    
    return 0;

}
