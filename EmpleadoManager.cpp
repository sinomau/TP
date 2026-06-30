#include "EmpleadoManager.h"
#include "Validaciones.h"
#include "VentaArchivo.h"
#include <iostream>
#include <cstring>
using namespace std;

int EmpleadoManager::generarId() {
    int maxId = 0;
    int cant = _arch.getCantidadRegistros();
    for (int i = 0; i < cant; i++) {
        Empleado e = _arch.leer(i);
        if (e.getIdEmpleado() > maxId) maxId = e.getIdEmpleado();
    }
    return maxId + 1;
}

void EmpleadoManager::cargar() {
    Empleado e;
    e.cargar();
    e.setIdEmpleado(generarId());
    _arch.guardar(e);
    cout << "Empleado dado de alta con ID: " << e.getIdEmpleado() << endl;
}

void EmpleadoManager::listar() {
    int cant = _arch.getCantidadRegistros();
    bool hay = false;
    for (int i = 0; i < cant; i++) {
        Empleado e = _arch.leer(i);
        if (!e.getEliminado()) {
            e.mostrar();
            hay = true;
        }
    }
    if (!hay) cout << "No hay empleados registrados." << endl;
}

void EmpleadoManager::listarPorId() {
    cout << "ID del empleado a buscar: ";
    int id = leerEntero(1, 99999);
    int pos = _arch.buscar(id);
    if (pos == -1)
        cout << "Empleado no encontrado." << endl;
    else
        _arch.leer(pos).mostrar();
}

void EmpleadoManager::listarPorCargo() {
    int cargo;
    cout << "Cargo (1:Vendedor tel / 2:Vendedor salon / 3:Cajero / 4:Gerente): ";
    cargo = leerEntero(1, 4);

    int cant = _arch.getCantidadRegistros();
    bool hay = false;
    for (int i = 0; i < cant; i++) {
        Empleado e = _arch.leer(i);
        if (!e.getEliminado() && e.getCargo() == cargo) {
            e.mostrar();
            hay = true;
        }
    }
    if (!hay) cout << "No hay empleados con ese cargo." << endl;
}

void EmpleadoManager::rankingVendedores() {
    VentaArchivo ventArch;
    int cantV = ventArch.getCantidadRegistros();
    int cantE = _arch.getCantidadRegistros();

    float* recaudado = new float[cantE + 1]();
    for (int i = 0; i < cantV; i++) {
        Venta v = ventArch.leer(i);
        if (!v.getEliminado() && v.getIdEmpleado() <= cantE)
            recaudado[v.getIdEmpleado()] += v.getTotal();
    }

    int* idx = new int[cantE];
    for (int i = 0; i < cantE; i++) idx[i] = i + 1;
    for (int i = 0; i < cantE - 1; i++)
        for (int j = 0; j < cantE - 1 - i; j++)
            if (recaudado[idx[j]] < recaudado[idx[j+1]]) {
                int tmp = idx[j]; idx[j] = idx[j+1]; idx[j+1] = tmp;
            }

    cout << "\n--- Ranking de Vendedores ---" << endl;
    for (int i = 0; i < cantE; i++) {
        if (recaudado[idx[i]] == 0) break;
        int pos = _arch.buscar(idx[i]);
        if (pos != -1) {
            Empleado e = _arch.leer(pos);
            cout << (i+1) << ". ";
            e.mostrar();
            cout << "   Total recaudado: $" << recaudado[idx[i]] << endl;
        }
    }
    delete[] recaudado;
    delete[] idx;
}

void EmpleadoManager::modificar() {
    cout << "ID del empleado a modificar: ";
    int id = leerEntero(1, 99999);
    int pos = _arch.buscar(id);
    if (pos == -1) {
        cout << "Empleado no encontrado." << endl;
        return;
    }
    Empleado e = _arch.leer(pos);
    cout << "Datos actuales:" << endl;
    e.mostrar();
    cout << "Ingrese nuevos datos:" << endl;
    e.cargar();
    _arch.guardar(e, pos);
    cout << "Empleado modificado correctamente." << endl;
}

void EmpleadoManager::eliminar() {
    cout << "ID del empleado a eliminar: ";
    int id = leerEntero(1, 99999);
    int pos = _arch.buscar(id);
    if (pos == -1) {
        cout << "Empleado no encontrado." << endl;
        return;
    }
    Empleado e = _arch.leer(pos);
    e.setEliminado(true);
    _arch.guardar(e, pos);
    cout << "Empleado eliminado correctamente." << endl;
}
