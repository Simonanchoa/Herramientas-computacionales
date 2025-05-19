#include <iostream>
#include <vector>
#include <cstdlib>  // rand, srand
#include <ctime>    // time
#include <algorithm> // min_element

using namespace std;

// 1. Variables globales
int miEntera = 5;
float miFlotante = 17.5;

// 8. Función que divide flotante entre entera
float dividirVariables(float miflotante, int mientera) {
    return miflotante / mientera;
}

// 10. Función que retorna el mínimo del arreglo
int encontrarMinimo(const vector<int> &arr) {
    return *min_element(arr.begin(), arr.end());
}

// 11. Función que imprime los impares y detecta si hay mayor a 800
void imprimirImparesYMayorA800(const vector<int> &arr) {
    for (int num : arr) {
        if (num % 2 != 0) {
            cout << "Impar: " << num << endl;
        }
        if (num > 800) {
            cout << "Número mayor a 800 encontrado: " << num << endl;
        }
    }
}

int main() {
    // 2. Imprimir valores
    cout << "La primera tiene un valor de " << miEntera
         << " y la segunda variable tiene un valor de " << miFlotante << endl;

    // 3. División
    float resultado = miFlotante / miEntera;
    cout << "El resultado es " << resultado << endl;

    // 4. Arreglo con 300 números aleatorios
    srand(time(0));
    vector<int> numeros;
    for (int i = 0; i < 300; ++i) {
        numeros.push_back(rand() % 901); // 0 a 900
    }

    // 5. Iterar y mostrar
    for (int num : numeros) {
        cout << num << " ";
    }
    cout << endl;

    // 6. Quinto elemento
    cout << "El quinto elemento es: " << numeros[4] << endl;

    // 7. Longitud
    cout << "La longitud del arreglo es " << numeros.size() << endl;

    // 9. Llamar a la función dividir con valores fijos
    float division = dividirVariables(17.5, 5);
    cout << "Resultado de dividir 17.5 / 5 usando función: " << division << endl;

    // 10. Mínimo
    int minimo = encontrarMinimo(numeros);
    cout << "El valor mínimo en el arreglo es: " << minimo << endl;

    // 11. Impares y mayores a 800
    imprimirImparesYMayorA800(numeros);

    return 0;
}
