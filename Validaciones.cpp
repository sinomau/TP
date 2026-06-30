#include "Validaciones.h"
#include <iostream>
#include <limits>
using namespace std;

int leerEntero(int min, int max) {
    int valor;
    while (true) {
        cin >> valor;
        if (cin.fail() || valor < min || valor > max) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: ingrese un numero entre " << min << " y " << max << ": ";
        } else {
            cin.ignore(10000, '\n');
            return valor;
        }
    }
}
