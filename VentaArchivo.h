#pragma once
#include "Venta.h"
#include <string>

class VentaArchivo {
public:
    VentaArchivo();
    VentaArchivo(std::string ruta);

    int getCantidadRegistros();
    bool guardar(Venta reg);
    bool guardar(Venta reg, int posicion);
    Venta leer(int nroRegistro);
    int buscar(int id);

private:
    std::string _ruta;
};
