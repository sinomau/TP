#pragma once
#include "Producto.h"
#include "ProductoArchivo.h"

class ProductoManager {
public:
    void cargar();
    void listar();
    void listarPorId();
    void listarPorTipoEquipo();
    void listarPorMarca();
    void listarPorProveedor();
    void listarStockCritico();
    void buscarPorTipo();
    void buscarPorMarca();
    void buscarPorProveedor();
    void rankingMasVendidos();
    void modificar();
    void eliminar();

private:
    ProductoArchivo _arch;
    int generarId();
};
