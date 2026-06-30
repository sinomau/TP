#pragma once
#include "Persona.h"

class Proveedor : public Persona {
private:
    int   idProveedor;
    char  razonSocial[60];
    char  cuit[14];
    float cuentaCorriente;
    bool  eliminado;

public:
    int    getIdProveedor();
    char*  getRazonSocial();
    char*  getCuit();
    float  getCuentaCorriente();
    bool   getEliminado();

    void   setIdProveedor(int valor);
    void   setRazonSocial(const char* valor);
    void   setCuit(const char* valor);
    void   setCuentaCorriente(float valor);
    void   setEliminado(bool valor);

    void   cargar();
    void   mostrar();
};
