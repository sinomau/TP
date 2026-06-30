#include "ProductoManager.h"
#include "Validaciones.h"
#include "DetalleVentaArchivo.h"
#include <iostream>
#include <cstring>
using namespace std;

int ProductoManager::generarId() {
    int maxId = 0;
    int cant = _arch.getCantidadRegistros();
    for (int i = 0; i < cant; i++) {
        Producto p = _arch.leer(i);
        if (p.getIdProducto() > maxId) maxId = p.getIdProducto();
    }
    return maxId + 1;
}

void ProductoManager::cargar() {
    Producto p;
    p.cargar();
    p.setIdProducto(generarId());
    _arch.guardar(p);
    cout << "Producto dado de alta con ID: " << p.getIdProducto() << endl;
}

void ProductoManager::listar() {
    int cant = _arch.getCantidadRegistros();
    bool hay = false;
    for (int i = 0; i < cant; i++) {
        Producto p = _arch.leer(i);
        if (!p.getEliminado()) {
            p.mostrar();
            hay = true;
        }
    }
    if (!hay) cout << "No hay productos registrados." << endl;
}

void ProductoManager::listarPorId() {
    cout << "ID del producto a buscar: ";
    int id = leerEntero(1, 99999);
    int pos = _arch.buscar(id);
    if (pos == -1)
        cout << "Producto no encontrado." << endl;
    else
        _arch.leer(pos).mostrar();
}

void ProductoManager::listarPorTipoEquipo() {
    cout << "Tipo (1:PC escritorio / 2:Notebook / 3:Impresora / 4:Periferico): ";
    int tipo = leerEntero(1, 4);

    int cant = _arch.getCantidadRegistros();
    bool hay = false;
    for (int i = 0; i < cant; i++) {
        Producto p = _arch.leer(i);
        if (!p.getEliminado() && p.getTipoEquipo() == tipo) {
            p.mostrar();
            hay = true;
        }
    }
    if (!hay) cout << "No hay productos de ese tipo." << endl;
}

void ProductoManager::listarPorMarca() {
    char marca[30];
    cout << "Marca a buscar: ";
    cin.getline(marca, 30);

    int cant = _arch.getCantidadRegistros();
    bool hay = false;
    for (int i = 0; i < cant; i++) {
        Producto p = _arch.leer(i);
        if (!p.getEliminado() && strcmp(p.getMarca(), marca) == 0) {
            p.mostrar();
            hay = true;
        }
    }
    if (!hay) cout << "No hay productos de esa marca." << endl;
}

void ProductoManager::listarPorProveedor() {
    cout << "ID del proveedor: ";
    int idProv = leerEntero(1, 99999);

    int cant = _arch.getCantidadRegistros();
    bool hay = false;
    for (int i = 0; i < cant; i++) {
        Producto p = _arch.leer(i);
        if (!p.getEliminado() && p.getIdProveedor() == idProv) {
            p.mostrar();
            hay = true;
        }
    }
    if (!hay) cout << "No hay productos de ese proveedor." << endl;
}

void ProductoManager::listarStockCritico() {
    int cant = _arch.getCantidadRegistros();
    bool hay = false;
    for (int i = 0; i < cant; i++) {
        Producto p = _arch.leer(i);
        if (!p.getEliminado() && p.getStock() < p.getStockMinimo()) {
            p.mostrar();
            hay = true;
        }
    }
    if (!hay) cout << "No hay productos con stock critico." << endl;
}

void ProductoManager::buscarPorTipo() {
    cout << "Tipo (1:PC escritorio / 2:Notebook / 3:Impresora / 4:Periferico): ";
    int tipo = leerEntero(1, 4);

    int cant = _arch.getCantidadRegistros();
    bool hay = false;
    for (int i = 0; i < cant; i++) {
        Producto p = _arch.leer(i);
        if (!p.getEliminado() && p.getTipoEquipo() == tipo) {
            p.mostrar();
            hay = true;
        }
    }
    if (!hay) cout << "No hay productos de ese tipo." << endl;
}

void ProductoManager::buscarPorMarca() {
    char marca[30];
    cout << "Marca a buscar: ";
    cin.getline(marca, 30);

    int cant = _arch.getCantidadRegistros();
    bool hay = false;
    for (int i = 0; i < cant; i++) {
        Producto p = _arch.leer(i);
        if (!p.getEliminado() && strcmp(p.getMarca(), marca) == 0) {
            p.mostrar();
            hay = true;
        }
    }
    if (!hay) cout << "No hay productos de esa marca." << endl;
}

void ProductoManager::buscarPorProveedor() {
    cout << "ID del proveedor: ";
    int idProv = leerEntero(1, 99999);

    int cant = _arch.getCantidadRegistros();
    bool hay = false;
    for (int i = 0; i < cant; i++) {
        Producto p = _arch.leer(i);
        if (!p.getEliminado() && p.getIdProveedor() == idProv) {
            p.mostrar();
            hay = true;
        }
    }
    if (!hay) cout << "No hay productos de ese proveedor." << endl;
}

void ProductoManager::rankingMasVendidos() {
    DetalleVentaArchivo detArch;
    int cantDet = detArch.getCantidadRegistros();
    int cantProd = _arch.getCantidadRegistros();

    int* cantidades = new int[cantProd + 1]();
    for (int i = 0; i < cantDet; i++) {
        DetalleVenta dv = detArch.leer(i);
        if (!dv.getEliminado() && dv.getIdProducto() <= cantProd)
            cantidades[dv.getIdProducto()] += dv.getCantidad();
    }

    int* idx = new int[cantProd];
    for (int i = 0; i < cantProd; i++) idx[i] = i + 1;
    for (int i = 0; i < cantProd - 1; i++)
        for (int j = 0; j < cantProd - 1 - i; j++)
            if (cantidades[idx[j]] < cantidades[idx[j+1]]) {
                int tmp = idx[j]; idx[j] = idx[j+1]; idx[j+1] = tmp;
            }

    cout << "\n--- Ranking de Productos mas vendidos ---" << endl;
    int top = (cantProd < 10) ? cantProd : 10;
    for (int i = 0; i < top; i++) {
        if (cantidades[idx[i]] == 0) break;
        int pos = _arch.buscar(idx[i]);
        if (pos != -1) {
            Producto p = _arch.leer(pos);
            cout << (i+1) << ". ";
            p.mostrar();
            cout << "   Unidades vendidas: " << cantidades[idx[i]] << endl;
        }
    }
    delete[] cantidades;
    delete[] idx;
}

void ProductoManager::modificar() {
    cout << "ID del producto a modificar: ";
    int id = leerEntero(1, 99999);
    int pos = _arch.buscar(id);
    if (pos == -1) {
        cout << "Producto no encontrado." << endl;
        return;
    }
    Producto p = _arch.leer(pos);
    cout << "Datos actuales:" << endl;
    p.mostrar();
    cout << "Ingrese nuevos datos:" << endl;
    p.cargar();
    _arch.guardar(p, pos);
    cout << "Producto modificado correctamente." << endl;
}

void ProductoManager::eliminar() {
    cout << "ID del producto a eliminar: ";
    int id = leerEntero(1, 99999);
    int pos = _arch.buscar(id);
    if (pos == -1) {
        cout << "Producto no encontrado." << endl;
        return;
    }
    Producto p = _arch.leer(pos);
    p.setEliminado(true);
    _arch.guardar(p, pos);
    cout << "Producto eliminado correctamente." << endl;
}
