#include "VentaArchivo.h"
#include <cstdio>
#include <iostream>
using namespace std;

VentaArchivo::VentaArchivo() {
    _ruta = "Ventas.dat";
}
VentaArchivo::VentaArchivo(string ruta) {
    _ruta = ruta;
}

int VentaArchivo::getCantidadRegistros() {
    FILE *p = fopen(_ruta.c_str(), "rb");
    if (p == NULL) return 0;
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Venta);
}

bool VentaArchivo::guardar(Venta reg) {
    FILE *p = fopen(_ruta.c_str(), "ab");
    if (p == NULL) return false;
    bool ok = fwrite(&reg, sizeof(Venta), 1, p);
    fclose(p);
    return ok;
}

bool VentaArchivo::guardar(Venta reg, int posicion) {
    FILE *p = fopen(_ruta.c_str(), "rb+");
    if (p == NULL) return false;
    fseek(p, posicion * sizeof(Venta), SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Venta), 1, p);
    fclose(p);
    return ok;
}

Venta VentaArchivo::leer(int nroRegistro) {
    Venta aux;
    FILE *p = fopen(_ruta.c_str(), "rb");
    if (p == NULL) return aux;
    fseek(p, nroRegistro * sizeof(Venta), SEEK_SET);
    fread(&aux, sizeof(Venta), 1, p);
    fclose(p);
    return aux;
}

int VentaArchivo::buscar(int id) {
    int cant = getCantidadRegistros();
    for (int i = 0; i < cant; i++) {
        Venta aux = leer(i);
        if (aux.getIdVenta() == id && !aux.getEliminado())
            return i;
    }
    return -1;
}
