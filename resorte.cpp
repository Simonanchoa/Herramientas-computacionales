#include <iostream>
#include <array>
#include <string>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

double dv(double x){
    double k=50;
    double m=0.2;
    return (-k/m)*x;
}

void newton(double h, double t, string filename){
    ofstream datos_new(filename);
    int n=t/h;
    double y[n];
    y[0]=0.1;
    datos_new << fixed << setprecision(3);
    datos_new << "t\tposición\n"; 
    
    for (int i=0; i<=n; i++){
        datos_new << i*h << "\t" << y[i] << "\n";
        
        y[i+1]=y[i] +h*dv(y[i]) ;
    }
    datos_new.close();

}

void lf(double h,double t, string datos){
    ofstream datos_lf(datos);
    int n=t/h;
    double y[n];
    double v[n];
    y[0]=0.1;
    v[0]=1/2*h*dv(y[0]);
    datos_lf << fixed << setprecision(3);
    datos_lf << "t\tvelocidad\tposición\n";
    for (int i=0; i<= n; i++) {
        datos_lf << i*h << "\t" << v[i] << "\t" << y[i] << "\n";
        y[i+1]=y[i]+h*v[i];
        v[i+1]=v[i]+h*dv(y[i+1]);
    }
    datos_lf.close();
}

int main() {
    double t=10.0;
    double h=0.1;
    
    lf(h,t, "resultados_leap_frog.txt");
    newton(h, t, "resultados_newton.txt");
    
    cout << "Los resultados se generaron en los archivos correspondientes"<< endl;
    
    return 0;

}