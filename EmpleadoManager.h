#pragma once
#include "Empleado.h"
#include "EmpleadoArchivo.h"

class EmpleadoManager {
public:
    void cargar();
    void listar();
    void listarPorId();
    void listarPorCargo();
    void rankingVendedores();
    void modificar();
    void eliminar();

private:
    EmpleadoArchivo _arch;
    int generarId();
};
