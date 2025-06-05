#include <iostream>
#include <cmath>
#include <array>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

double Upasado[101];

double condinicial(double array){
    for (int i=0; i<=101;i++){
        if (i<51){
            array[i]=0.02*i;
        }else{
            array[i]=-0.02*i+0.1;

            }

        

    }
}