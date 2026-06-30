#include "ProveedorManager.h"
#include "Validaciones.h"
#include <iostream>
#include <cstring>
using namespace std;

int ProveedorManager::generarId() {
    int maxId = 0;
    int cant = _arch.getCantidadRegistros();
    for (int i = 0; i < cant; i++) {
        Proveedor p = _arch.leer(i);
        if (p.getIdProveedor() > maxId) maxId = p.getIdProveedor();
    }
    return maxId + 1;
}

void ProveedorManager::cargar() {
    Proveedor p;
    p.cargar();
    p.setIdProveedor(generarId());
    _arch.guardar(p);
    cout << "Proveedor dado de alta con ID: " << p.getIdProveedor() << endl;
}

void ProveedorManager::listar() {
    int cant = _arch.getCantidadRegistros();
    bool hay = false;
    for (int i = 0; i < cant; i++) {
        Proveedor p = _arch.leer(i);
        if (!p.getEliminado()) {
            p.mostrar();
            hay = true;
        }
    }
    if (!hay) cout << "No hay proveedores registrados." << endl;
}

void ProveedorManager::listarPorId() {
    cout << "ID del proveedor a buscar: ";
    int id = leerEntero(1, 99999);
    int pos = _arch.buscar(id);
    if (pos == -1)
        cout << "Proveedor no encontrado." << endl;
    else
        _arch.leer(pos).mostrar();
}

void ProveedorManager::modificar() {
    cout << "ID del proveedor a modificar: ";
    int id = leerEntero(1, 99999);
    int pos = _arch.buscar(id);
    if (pos == -1) {
        cout << "Proveedor no encontrado." << endl;
        return;
    }
    Proveedor p = _arch.leer(pos);
    cout << "Datos actuales:" << endl;
    p.mostrar();
    cout << "Ingrese nuevos datos:" << endl;
    p.cargar();
    _arch.guardar(p, pos);
    cout << "Proveedor modificado correctamente." << endl;
}

void ProveedorManager::eliminar() {
    cout << "ID del proveedor a eliminar: ";
    int id = leerEntero(1, 99999);
    int pos = _arch.buscar(id);
    if (pos == -1) {
        cout << "Proveedor no encontrado." << endl;
        return;
    }
    Proveedor p = _arch.leer(pos);
    p.setEliminado(true);
    _arch.guardar(p, pos);
    cout << "Proveedor eliminado correctamente." << endl;
}
