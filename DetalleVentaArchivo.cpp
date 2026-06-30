#include "DetalleVentaArchivo.h"
#include <cstdio>
#include <iostream>
using namespace std;

DetalleVentaArchivo::DetalleVentaArchivo() {
    _ruta = "DetallesVenta.dat";
}
DetalleVentaArchivo::DetalleVentaArchivo(string ruta) {
    _ruta = ruta;
}

int DetalleVentaArchivo::getCantidadRegistros() {
    FILE *p = fopen(_ruta.c_str(), "rb");
    if (p == NULL) return 0;
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(DetalleVenta);
}

bool DetalleVentaArchivo::guardar(DetalleVenta reg) {
    FILE *p = fopen(_ruta.c_str(), "ab");
    if (p == NULL) return false;
    bool ok = fwrite(&reg, sizeof(DetalleVenta), 1, p);
    fclose(p);
    return ok;
}

DetalleVenta DetalleVentaArchivo::leer(int nroRegistro) {
    DetalleVenta aux;
    FILE *p = fopen(_ruta.c_str(), "rb");
    if (p == NULL) return aux;
    fseek(p, nroRegistro * sizeof(DetalleVenta), SEEK_SET);
    fread(&aux, sizeof(DetalleVenta), 1, p);
    fclose(p);
    return aux;
}

void DetalleVentaArchivo::anularPorVenta(int idVenta) {
    int cant = getCantidadRegistros();
    for (int i = 0; i < cant; i++) {
        DetalleVenta dv = leer(i);
        if (dv.getIdVenta() == idVenta && !dv.getEliminado()) {
            dv.setEliminado(true);
            FILE* p = fopen(_ruta.c_str(), "rb+");
            if (p == NULL) return;
            fseek(p, i * sizeof(DetalleVenta), SEEK_SET);
            fwrite(&dv, sizeof(DetalleVenta), 1, p);
            fclose(p);
        }
    }
}

void DetalleVentaArchivo::listarPorVenta(int idVenta) {
    int cant = getCantidadRegistros();
    bool hay = false;
    for (int i = 0; i < cant; i++) {
        DetalleVenta dv = leer(i);
        if (dv.getIdVenta() == idVenta && !dv.getEliminado()) {
            dv.mostrar();
            hay = true;
        }
    }
    if (!hay) cout << "No hay detalles para esa venta." << endl;
}
