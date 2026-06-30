#pragma once
#include "Proveedor.h"
#include "ProveedorArchivo.h"

class ProveedorManager {
public:
    void cargar();
    void listar();
    void listarPorId();
    void modificar();
    void eliminar();

private:
    ProveedorArchivo _arch;
    int generarId();
};
