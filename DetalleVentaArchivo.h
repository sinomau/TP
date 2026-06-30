#pragma once
#include "DetalleVenta.h"
#include <string>

class DetalleVentaArchivo {
public:
    DetalleVentaArchivo();
    DetalleVentaArchivo(std::string ruta);

    int getCantidadRegistros();
    bool guardar(DetalleVenta reg);
    DetalleVenta leer(int nroRegistro);
    void listarPorVenta(int idVenta);
    void anularPorVenta(int idVenta);

private:
    std::string _ruta;
};
