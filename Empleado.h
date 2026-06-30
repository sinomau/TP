#pragma once
#include "Persona.h"

class Empleado : public Persona {
private:
    int  idEmpleado;
    char dni[10];
    int  cargo;     // 1:Vendedor tel / 2:Vendedor salon / 3:Cajero / 4:Gerente
    bool eliminado;

public:
    int    getIdEmpleado();
    char*  getDni();
    int    getCargo();
    bool   getEliminado();

    void   setIdEmpleado(int valor);
    void   setDni(const char* valor);
    void   setCargo(int valor);
    void   setEliminado(bool valor);

    void   cargar();
    void   mostrar();
};
