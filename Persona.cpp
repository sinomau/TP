#include "Persona.h"
#include <iostream>
#include <cstring>
using namespace std;

char* Persona::getNombre()   { return nombre; }
char* Persona::getApellido() { return apellido; }
char* Persona::getTelefono() { return telefono; }
char* Persona::getEmail()    { return email; }

void Persona::setNombre(const char* valor)   { strncpy(nombre,   valor, 29); nombre[29]   = '\0'; }
void Persona::setApellido(const char* valor) { strncpy(apellido, valor, 29); apellido[29] = '\0'; }
void Persona::setTelefono(const char* valor) { strncpy(telefono, valor, 14); telefono[14] = '\0'; }
void Persona::setEmail(const char* valor)    { strncpy(email,    valor, 49); email[49]    = '\0'; }

void Persona::cargarDatosPersona() {
    cout << "Nombre:   "; cin.getline(nombre,   30);
    cout << "Apellido: "; cin.getline(apellido, 30);
    cout << "Telefono: "; cin.getline(telefono, 15);
    cout << "Email:    "; cin.getline(email,    50);
}

void Persona::mostrarDatosPersona() {
    cout << "Nombre:   " << nombre << " " << apellido << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Email:    " << email    << endl;
}
