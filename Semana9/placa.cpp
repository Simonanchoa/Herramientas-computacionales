#include <iostream>
#include <cmath>
#include <array>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

double** cond_inicial(double** placa){
    for (int i=0; i<100; i++ ){
        for (int j=0; j<100; j++){
            placa[i][j]=50;
        }
    }
    for (int i=39; i<60;i++){
        for (int j=19;j<40; j++){
            placa[i][j]=100;

        }
    }
    ofstream archivo("condicioninicial.txt");
    archivo << fixed << setprecision(3);
    for (int i=0; i<100; i++ ){

        for (int j=0; j<100; j++){
            archivo << placa[j][i];
        }
        archivo << endl;
    }
 return placa;
}

 double** paso(double** presente, double** futuro, double dt, double dx, double v){
    for(int i=0;i<100;i++){
        for (int j=0;j<100;j++){
            futuro[i][j]=presente[i][j];
        }
    }
    for(int i=1;i<99;i++){
        for (int j=1;j<99;j++){
            futuro[i][j]=presente[i][j]+(v*dt/(dx*dx)*(presente[i+1][j]-2*presente[i][j]+presente[i-1][j]))+(v*dt/(dx*dx)*(presente[i][j+1]-2*presente[i][j]+presente[i][j-1]));
        }
    }
    return futuro
 }

int main (){
    double placa[100][100];
    double plate[100][100];
    cond_inicial(placa);
    paso(placa, plate, 1, 0.01,0.0001);
    return 0;
}