#pragma once
#include "Persona.h"

class Cliente : public Persona {
private:
    int  idCliente;
    char cuitCuil[14];
    char direccion[80];
    int  tipoCliente;   // 1:particular / 2:empresa
    bool eliminado;

public:
    int    getIdCliente();
    char*  getCuil();
    char*  getDireccion();
    int    getTipoCliente();
    bool   getEliminado();

    void   setIdCliente(int valor);
    void   setCuil(const char* valor);
    void   setDireccion(const char* valor);
    void   setTipoCliente(int valor);
    void   setEliminado(bool valor);

    void   cargar();
    void   mostrar();
};
