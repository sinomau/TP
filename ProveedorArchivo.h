#pragma once
#include "Proveedor.h"
#include <string>

class ProveedorArchivo {
public:
    ProveedorArchivo();
    ProveedorArchivo(std::string ruta);

    int getCantidadRegistros();
    bool guardar(Proveedor reg);
    bool guardar(Proveedor reg, int posicion);
    Proveedor leer(int nroRegistro);
    int buscar(int id);

private:
    std::string _ruta;
};
