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

double newton(double h, double t, string dadatos){
    ofstream datos_new(dadatos.txt);
    int n=t/h;
    double y0=0.1;
    datos_new << fixed << setprecision(3);
    datos_new << "t\tposición\n"; 
    for (int i=0; i<=n; i++){
        datos_new << i/h << "\t" << y0 << "\n";
        y0=y0 +h*dv(y0) ;
    }
    datos_new.close()
    return dadatos.txt

}

double lf(double h,double t, string datos){
    ofstream datos_lf(datos.txt);
    int n=t/h;
    double y[n];
    double v[n];
    y[0]=0.1;
    v[0]=1/2*h*dv(y[0]);
    datos_lf << fixed << setprecision(3);
    datos_lf << "t\tvelocidad\tposición\n";
    for (int i=0; i<= n; i++) {
        datos_lf << i/h << "\t" << v[i] << "\t" << y[i] << "\n";
        y[i+1]=y[i]+h*v[i];
        v[i+1]=v[i]+h*dv(y[i+1]);
    }
    datos_lf.close();
    return datos.txt
}

int main() {
    double t=10.0;
    double h=0.1;
 lf(h,t);
    return 0;

}