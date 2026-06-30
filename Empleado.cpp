#include "Empleado.h"
#include <iostream>
#include <cstring>
using namespace std;

int    Empleado::getIdEmpleado() { return idEmpleado; }
char*  Empleado::getDni()        { return dni; }
int    Empleado::getCargo()      { return cargo; }
bool   Empleado::getEliminado()  { return eliminado; }

void   Empleado::setIdEmpleado(int valor) { idEmpleado = valor; }
void   Empleado::setDni(const char* valor) { strncpy(dni, valor, 9); dni[9] = '\0'; }
void   Empleado::setCargo(int valor)       { cargo = valor; }
void   Empleado::setEliminado(bool valor)  { eliminado = valor; }

void Empleado::cargar() {
    cargarDatosPersona();
    cout << "DNI:   "; cin.getline(dni, 10);
    do {
        cout << "Cargo (1:Vendedor tel / 2:Vendedor salon / 3:Cajero / 4:Gerente): ";
        cin >> cargo;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cargo = 0;
        }
        if (cargo < 1 || cargo > 4) cout << "Error: ingrese un cargo valido." << endl;
    } while (cargo < 1 || cargo > 4);
    eliminado = false;
}

void Empleado::mostrar() {
    cout << "ID:    " << idEmpleado << endl;
    mostrarDatosPersona();
    cout << "DNI:   " << dni << endl;
    cout << "Cargo: ";
    switch (cargo) {
        case 1: cout << "Vendedor telefonico"; break;
        case 2: cout << "Vendedor de salon";   break;
        case 3: cout << "Cajero";              break;
        case 4: cout << "Gerente";             break;
    }
    cout << endl;
    cout << "----------------------------" << endl;
}
