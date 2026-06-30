#pragma once
#include "Empleado.h"
#include <string>

class EmpleadoArchivo {
public:
    EmpleadoArchivo();
    EmpleadoArchivo(std::string ruta);

    int getCantidadRegistros();
    bool guardar(Empleado reg);
    bool guardar(Empleado reg, int posicion);
    Empleado leer(int nroRegistro);
    int buscar(int id);

private:
    std::string _ruta;
};
