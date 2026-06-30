#pragma once
#include <cstring>

class Persona {
protected:
    char nombre[30];
    char apellido[30];
    char telefono[15];
    char email[50];

public:
    char* getNombre();
    char* getApellido();
    char* getTelefono();
    char* getEmail();

    void  setNombre(const char* valor);
    void  setApellido(const char* valor);
    void  setTelefono(const char* valor);
    void  setEmail(const char* valor);

    void  cargarDatosPersona();
    void  mostrarDatosPersona();
};
