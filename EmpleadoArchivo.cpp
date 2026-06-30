#include "EmpleadoArchivo.h"
#include <cstdio>
#include <iostream>
using namespace std;

EmpleadoArchivo::EmpleadoArchivo() {
    _ruta = "Empleados.dat";
}
EmpleadoArchivo::EmpleadoArchivo(string ruta) {
    _ruta = ruta;
}

int EmpleadoArchivo::getCantidadRegistros() {
    FILE *p = fopen(_ruta.c_str(), "rb");
    if (p == NULL) return 0;
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Empleado);
}

bool EmpleadoArchivo::guardar(Empleado reg) {
    FILE *p = fopen(_ruta.c_str(), "ab");
    if (p == NULL) return false;
    bool ok = fwrite(&reg, sizeof(Empleado), 1, p);
    fclose(p);
    return ok;
}

bool EmpleadoArchivo::guardar(Empleado reg, int posicion) {
    FILE *p = fopen(_ruta.c_str(), "rb+");
    if (p == NULL) return false;
    fseek(p, posicion * sizeof(Empleado), SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Empleado), 1, p);
    fclose(p);
    return ok;
}

Empleado EmpleadoArchivo::leer(int nroRegistro) {
    Empleado aux;
    FILE *p = fopen(_ruta.c_str(), "rb");
    if (p == NULL) return aux;
    fseek(p, nroRegistro * sizeof(Empleado), SEEK_SET);
    fread(&aux, sizeof(Empleado), 1, p);
    fclose(p);
    return aux;
}

int EmpleadoArchivo::buscar(int id) {
    int cant = getCantidadRegistros();
    for (int i = 0; i < cant; i++) {
        Empleado aux = leer(i);
        if (aux.getIdEmpleado() == id && !aux.getEliminado())
            return i;
    }
    return -1;
}
