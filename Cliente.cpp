#include "Cliente.h"
#include <iostream>
#include <cstring>
using namespace std;

int    Cliente::getIdCliente()   { return idCliente; }
char*  Cliente::getCuil()        { return cuitCuil; }
char*  Cliente::getDireccion()   { return direccion; }
int    Cliente::getTipoCliente() { return tipoCliente; }
bool   Cliente::getEliminado()   { return eliminado; }

void   Cliente::setIdCliente(int valor)         { idCliente   = valor; }
void   Cliente::setCuil(const char* valor)      { strncpy(cuitCuil,  valor, 13); cuitCuil[13]  = '\0'; }
void   Cliente::setDireccion(const char* valor) { strncpy(direccion, valor, 79); direccion[79] = '\0'; }
void   Cliente::setTipoCliente(int valor)       { tipoCliente = valor; }
void   Cliente::setEliminado(bool valor)        { eliminado   = valor; }

void Cliente::cargar() {
    cout << "CUIT/CUIL: ";                       cin.getline(cuitCuil,  14);
    cargarDatosPersona();
    cout << "Direccion: ";                       cin.getline(direccion, 80);
    do {
        cout << "Tipo (1:particular / 2:empresa): "; cin >> tipoCliente;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            tipoCliente = 0;
        }
        if (tipoCliente < 1 || tipoCliente > 2) cout << "Error: ingrese 1 o 2." << endl;
    } while (tipoCliente < 1 || tipoCliente > 2);
    eliminado = false;
}

void Cliente::mostrar() {
    cout << "ID:        " << idCliente  << endl;
    cout << "CUIT/CUIL: " << cuitCuil  << endl;
    mostrarDatosPersona();
    cout << "Direccion: " << direccion  << endl;
    cout << "Tipo:      " << (tipoCliente == 1 ? "Particular" : "Empresa") << endl;
    cout << "----------------------------" << endl;
}
