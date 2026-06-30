#include "ProductoArchivo.h"
#include <cstdio>
#include <iostream>
using namespace std;

ProductoArchivo::ProductoArchivo() {
    _ruta = "Productos.dat";
}
ProductoArchivo::ProductoArchivo(string ruta) {
    _ruta = ruta;
}

int ProductoArchivo::getCantidadRegistros() {
    FILE *p = fopen(_ruta.c_str(), "rb");
    if (p == NULL) return 0;
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Producto);
}

bool ProductoArchivo::guardar(Producto reg) {
    FILE *p = fopen(_ruta.c_str(), "ab");
    if (p == NULL) return false;
    bool ok = fwrite(&reg, sizeof(Producto), 1, p);
    fclose(p);
    return ok;
}

bool ProductoArchivo::guardar(Producto reg, int posicion) {
    FILE *p = fopen(_ruta.c_str(), "rb+");
    if (p == NULL) return false;
    fseek(p, posicion * sizeof(Producto), SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Producto), 1, p);
    fclose(p);
    return ok;
}

Producto ProductoArchivo::leer(int nroRegistro) {
    Producto aux;
    FILE *p = fopen(_ruta.c_str(), "rb");
    if (p == NULL) return aux;
    fseek(p, nroRegistro * sizeof(Producto), SEEK_SET);
    fread(&aux, sizeof(Producto), 1, p);
    fclose(p);
    return aux;
}

int ProductoArchivo::buscar(int id) {
    int cant = getCantidadRegistros();
    for (int i = 0; i < cant; i++) {
        Producto aux = leer(i);
        if (aux.getIdProducto() == id && !aux.getEliminado())
            return i;
    }
    return -1;
}

void ProductoArchivo::actualizarStock(int idProducto, int cantidad) {
    int pos = buscar(idProducto);
    if (pos == -1) return;
    Producto p = leer(pos);
    p.setStock(p.getStock() - cantidad);
    guardar(p, pos);
}
