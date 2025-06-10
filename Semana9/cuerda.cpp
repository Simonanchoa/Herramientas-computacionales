#include <iostream>
#include <cmath>
#include <array>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

double* cdin(double* array, string nombre){
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

double*  uinit(double* array, double* aray, string archivo){
    ofstream unicial(archivo);
    unicial << fixed << setprecision(6);
    unicial << "posición"<< endl ;
    array[0]=0;
    array[101]=0;
    unicial << array[0] << endl ;
    for (int i=1; i<100;i++){
        array[i]=aray[i]+0.125*(aray[i+1]-2*aray[i]+aray[i-1]);
        unicial << array[i] << endl ;
    }
    unicial << array[101] << endl ;
    unicial.close();
    return array;
}
double* paso(double* pasado,double* presente, double* futuro,string datos){
    futuro[0]=0;
    futuro[101]=0;
for (int i=1; i<100;i++){
    futuro[i]=2*presente[i]-pasado[i]+0.25*(presente[i+1]-2*presente[i]+presente[i-1]);
}
return futuro;
}

int main(){
    double Upasado[101];
    double Upresente[101];
    //double Ufuturo[101];
    cdin(Upasado, "posicioninicial.txt");
    uinit(Upresente, Upasado, "posicion1.txt");
    //ofstream final("resultado.txt");

    //for (int i; i<=300;i++){}

    
    cout << Upasado << Upresente;
    return 0;
}