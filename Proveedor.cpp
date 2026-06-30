#include "Proveedor.h"
#include <iostream>
#include <cstring>
using namespace std;

int    Proveedor::getIdProveedor()    { return idProveedor; }
char*  Proveedor::getRazonSocial()    { return razonSocial; }
char*  Proveedor::getCuit()           { return cuit; }
float  Proveedor::getCuentaCorriente(){ return cuentaCorriente; }
bool   Proveedor::getEliminado()      { return eliminado; }

void   Proveedor::setIdProveedor(int valor)          { idProveedor    = valor; }
void   Proveedor::setRazonSocial(const char* valor)  { strncpy(razonSocial, valor, 59); razonSocial[59] = '\0'; }
void   Proveedor::setCuit(const char* valor)         { strncpy(cuit,  valor, 13); cuit[13]  = '\0'; }
void   Proveedor::setCuentaCorriente(float valor)    { cuentaCorriente = valor; }
void   Proveedor::setEliminado(bool valor)           { eliminado = valor; }

void Proveedor::cargar() {
    cout << "Razon social: "; cin.getline(razonSocial, 60);
    cout << "CUIT: ";         cin.getline(cuit, 14);
    cargarDatosPersona();    // telefono y email
    cout << "Cuenta corriente: "; cin >> cuentaCorriente;
    eliminado = false;
}

void Proveedor::mostrar() {
    cout << "ID:              " << idProveedor    << endl;
    cout << "Razon social:    " << razonSocial    << endl;
    cout << "CUIT:            " << cuit           << endl;
    cout << "Telefono:        " << getTelefono()  << endl;
    cout << "Email:           " << getEmail()     << endl;
    cout << "Cuenta corriente: $" << cuentaCorriente << endl;
    cout << "----------------------------" << endl;
}
