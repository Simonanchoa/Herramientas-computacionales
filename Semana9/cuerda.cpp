#include <iostream>
#include <cmath>
#include <array>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

double* condinicial(double* array, string nombre){
    ofstream datos(nombre);
    datos << fixed << setprecision(3);
    datos << "posición"<< endl ;
    for (int i=0; i<101;i++){
        if (i<51){
            array[i]=0.002*i;

        }else{
            array[i]=(-0.002*i)+0.2;


            }
        datos << array[i] << endl ;

        

    }
    datos.close();
    return array;
}

int main(){
    double Upasado[101];
    condinicial(Upasado, "posicioninicial.txt");
    cout << Upasado;
    
}