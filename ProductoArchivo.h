#pragma once
#include "Producto.h"
#include <string>

class ProductoArchivo {
public:
    ProductoArchivo();
    ProductoArchivo(std::string ruta);

    int getCantidadRegistros();
    bool guardar(Producto reg);
    bool guardar(Producto reg, int posicion);
    Producto leer(int nroRegistro);
    int buscar(int id);
    void actualizarStock(int idProducto, int cantidad);

private:
    std::string _ruta;
};
