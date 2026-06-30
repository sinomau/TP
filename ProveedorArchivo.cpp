#include "ProveedorArchivo.h"
#include <cstdio>
#include <iostream>
using namespace std;

ProveedorArchivo::ProveedorArchivo() {
    _ruta = "Proveedores.dat";
}
ProveedorArchivo::ProveedorArchivo(string ruta) {
    _ruta = ruta;
}

int ProveedorArchivo::getCantidadRegistros() {
    FILE *p = fopen(_ruta.c_str(), "rb");
    if (p == NULL) return 0;
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Proveedor);
}

bool ProveedorArchivo::guardar(Proveedor reg) {
    FILE *p = fopen(_ruta.c_str(), "ab");
    if (p == NULL) return false;
    bool ok = fwrite(&reg, sizeof(Proveedor), 1, p);
    fclose(p);
    return ok;
}

bool ProveedorArchivo::guardar(Proveedor reg, int posicion) {
    FILE *p = fopen(_ruta.c_str(), "rb+");
    if (p == NULL) return false;
    fseek(p, posicion * sizeof(Proveedor), SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Proveedor), 1, p);
    fclose(p);
    return ok;
}

Proveedor ProveedorArchivo::leer(int nroRegistro) {
    Proveedor aux;
    FILE *p = fopen(_ruta.c_str(), "rb");
    if (p == NULL) return aux;
    fseek(p, nroRegistro * sizeof(Proveedor), SEEK_SET);
    fread(&aux, sizeof(Proveedor), 1, p);
    fclose(p);
    return aux;
}

int ProveedorArchivo::buscar(int id) {
    int cant = getCantidadRegistros();
    for (int i = 0; i < cant; i++) {
        Proveedor aux = leer(i);
        if (aux.getIdProveedor() == id && !aux.getEliminado())
            return i;
    }
    return -1;
}
