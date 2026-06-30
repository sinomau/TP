#pragma once
#include "Cliente.h"
#include <string>

class ClienteArchivo {
public:
    ClienteArchivo();
    ClienteArchivo(std::string ruta);

    int getCantidadRegistros();
    bool guardar(Cliente reg);
    bool guardar(Cliente reg, int posicion);
    Cliente leer(int nroRegistro);
    int buscar(int id);

private:
    std::string _ruta;
};
