#pragma once
#include "Cliente.h"
#include "ClienteArchivo.h"

class ClienteManager {
public:
    void cargar();
    void listar();
    void listarPorId();
    void listarOrdenadoPorApellido();
    void listarPorTipo();
    void buscarPorCuil();
    void buscarPorNombre();
    void buscarPorTipo();
    void modificar();
    void eliminar();

private:
    ClienteArchivo _arch;
    int generarId();
};
