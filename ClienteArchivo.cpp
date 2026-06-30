#include "ClienteArchivo.h"
#include <cstdio>
#include <iostream>
using namespace std;

ClienteArchivo::ClienteArchivo() {
    _ruta = "Clientes.dat";
}
ClienteArchivo::ClienteArchivo(string ruta) {
    _ruta = ruta;
}

int ClienteArchivo::getCantidadRegistros() {
    FILE *p = fopen(_ruta.c_str(), "rb");
    if (p == NULL) return 0;
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Cliente);
}

bool ClienteArchivo::guardar(Cliente reg) {
    FILE *p = fopen(_ruta.c_str(), "ab");
    if (p == NULL) return false;
    bool ok = fwrite(&reg, sizeof(Cliente), 1, p);
    fclose(p);
    return ok;
}

bool ClienteArchivo::guardar(Cliente reg, int posicion) {
    FILE *p = fopen(_ruta.c_str(), "rb+");
    if (p == NULL) return false;
    fseek(p, posicion * sizeof(Cliente), SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Cliente), 1, p);
    fclose(p);
    return ok;
}

Cliente ClienteArchivo::leer(int nroRegistro) {
    Cliente aux;
    FILE *p = fopen(_ruta.c_str(), "rb");
    if (p == NULL) return aux;
    fseek(p, nroRegistro * sizeof(Cliente), SEEK_SET);
    fread(&aux, sizeof(Cliente), 1, p);
    fclose(p);
    return aux;
}

int ClienteArchivo::buscar(int id) {
    int cant = getCantidadRegistros();
    for (int i = 0; i < cant; i++) {
        Cliente aux = leer(i);
        if (aux.getIdCliente() == id && !aux.getEliminado())
            return i;
    }
    return -1;
}
