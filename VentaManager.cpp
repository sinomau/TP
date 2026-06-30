#include "VentaManager.h"
#include "ClienteArchivo.h"
#include "EmpleadoArchivo.h"
#include "Validaciones.h"
#include <iostream>
#include <cstring>
using namespace std;

int VentaManager::generarId() {
    int maxId = 0;
    int cant = _arch.getCantidadRegistros();
    for (int i = 0; i < cant; i++) {
        Venta v = _arch.leer(i);
        if (v.getIdVenta() > maxId) maxId = v.getIdVenta();
    }
    return maxId + 1;
}

void VentaManager::nuevaVenta() {
    Venta v;
    v.cargar();
    v.setIdVenta(generarId());

    float totalVenta = 0;
    int idProd, cant;
    char seguir = 's';

    while (seguir == 's' || seguir == 'S') {
        idProd = leerEntero(1, 99999);
        int pos = _prodArch.buscar(idProd);
        if (pos == -1) {
            cout << "Producto no encontrado." << endl;
        } else {
            Producto prod = _prodArch.leer(pos);
            if (prod.getEliminado()) {
                cout << "Producto no disponible." << endl;
            } else {
                cout << "Cantidad: "; cant = leerEntero(1, 99999);
                if (cant > prod.getStock()) {
                    cout << "Stock insuficiente (disponible: "
                         << prod.getStock() << ")." << endl;
                } else {
                    DetalleVenta dv;
                    dv.setIdDetalle(_detArch.getCantidadRegistros() + 1);
                    dv.setIdVenta(v.getIdVenta());
                    dv.setIdProducto(idProd);
                    dv.setCantidad(cant);
                    dv.setPrecioUnitario(prod.getPrecioVenta());
                    dv.setSubtotal(prod.getPrecioVenta() * cant);
                    dv.setEliminado(false);
                    _detArch.guardar(dv);
                    _prodArch.actualizarStock(idProd, cant);
                    totalVenta += dv.getSubtotal();
                }
            }
        }
        cout << "Agregar otro producto? (s/n): "; cin >> seguir;
    }

    v.setTotal(totalVenta);
    _arch.guardar(v);
    cout << "Venta registrada. Total: $" << totalVenta << endl;
}

void VentaManager::listar() {
    int cant = _arch.getCantidadRegistros();
    bool hay = false;
    for (int i = 0; i < cant; i++) {
        Venta v = _arch.leer(i);
        if (!v.getEliminado()) {
            v.mostrar();
            hay = true;
        }
    }
    if (!hay) cout << "No hay ventas registradas." << endl;
}

void VentaManager::listarPorId() {
    cout << "ID de venta: ";
    int id = leerEntero(1, 99999);
    int pos = _arch.buscar(id);
    if (pos == -1) {
        cout << "Venta no encontrada." << endl;
        return;
    }
    Venta v = _arch.leer(pos);
    v.mostrar();
    _detArch.listarPorVenta(id);
}

void VentaManager::listarOrdenadoPorFecha() {
    int cant = _arch.getCantidadRegistros();
    if (cant == 0) {
        cout << "No hay ventas registradas." << endl;
        return;
    }

    Venta* vec = new Venta[cant];
    int idx = 0;
    for (int i = 0; i < cant; i++) {
        Venta v = _arch.leer(i);
        if (!v.getEliminado()) vec[idx++] = v;
    }

    for (int i = 0; i < idx - 1; i++) {
        for (int j = 0; j < idx - 1 - i; j++) {
            Fecha f1 = vec[j].getFecha();
            Fecha f2 = vec[j+1].getFecha();
            int fecha1 = f1.getAnio() * 10000 + f1.getMes() * 100 + f1.getDia();
            int fecha2 = f2.getAnio() * 10000 + f2.getMes() * 100 + f2.getDia();
            if (fecha1 > fecha2) {
                Venta tmp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = tmp;
            }
        }
    }

    for (int i = 0; i < idx; i++) vec[i].mostrar();
    delete[] vec;
}

void VentaManager::listarPorCliente() {
    cout << "ID Cliente: ";
    int idClie = leerEntero(1, 99999);
    int cant = _arch.getCantidadRegistros();
    bool hay = false;
    for (int i = 0; i < cant; i++) {
        Venta v = _arch.leer(i);
        if (!v.getEliminado() && v.getIdCliente() == idClie) {
            v.mostrar();
            hay = true;
        }
    }
    if (!hay) cout << "No se encontraron ventas para ese cliente." << endl;
}

void VentaManager::listarPorEmpleado() {
    cout << "ID Empleado: ";
    int idEmp = leerEntero(1, 99999);
    int cant = _arch.getCantidadRegistros();
    bool hay = false;
    for (int i = 0; i < cant; i++) {
        Venta v = _arch.leer(i);
        if (!v.getEliminado() && v.getIdEmpleado() == idEmp) {
            v.mostrar();
            hay = true;
        }
    }
    if (!hay) cout << "No se encontraron ventas para ese empleado." << endl;
}

void VentaManager::buscarPorRangoFecha() {
    Fecha desde, hasta;
    cout << "Desde:" << endl;
    desde.cargar();
    cout << "Hasta:" << endl;
    hasta.cargar();

    int cant = _arch.getCantidadRegistros();
    bool hay = false;
    for (int i = 0; i < cant; i++) {
        Venta v = _arch.leer(i);
        if (v.getEliminado()) continue;
        Fecha f = v.getFecha();
        int fVal = f.getAnio() * 10000 + f.getMes() * 100 + f.getDia();
        int desdeVal = desde.getAnio() * 10000 + desde.getMes() * 100 + desde.getDia();
        int hastaVal = hasta.getAnio() * 10000 + hasta.getMes() * 100 + hasta.getDia();
        if (fVal >= desdeVal && fVal <= hastaVal) {
            v.mostrar();
            hay = true;
        }
    }
    if (!hay) cout << "No hay ventas en ese rango de fechas." << endl;
}

void VentaManager::recaudacionTotal() {
    float total = 0;
    int cant = _arch.getCantidadRegistros();
    for (int i = 0; i < cant; i++) {
        Venta v = _arch.leer(i);
        if (!v.getEliminado()) total += v.getTotal();
    }
    cout << "Recaudacion total: $" << total << endl;
}

void VentaManager::recaudacionPorPeriodo() {
    cout << "Recaudacion por: 1. Dia  2. Mes  3. Anio" << endl;
    cout << "Opcion: ";
    int opcion = leerEntero(1, 3);

    int cant = _arch.getCantidadRegistros();
    if (cant == 0) {
        cout << "No hay ventas registradas." << endl;
        return;
    }

    int* periodos = new int[cant];
    float* montos = new float[cant];
    int cantPeriodos = 0;

    for (int i = 0; i < cant; i++) {
        Venta v = _arch.leer(i);
        if (v.getEliminado()) continue;
        Fecha f = v.getFecha();
        int periodo;
        if (opcion == 1)      periodo = f.getAnio() * 10000 + f.getMes() * 100 + f.getDia();
        else if (opcion == 2) periodo = f.getAnio() * 100 + f.getMes();
        else                  periodo = f.getAnio();

        int j;
        for (j = 0; j < cantPeriodos; j++) {
            if (periodos[j] == periodo) {
                montos[j] += v.getTotal();
                break;
            }
        }
        if (j == cantPeriodos) {
            periodos[cantPeriodos] = periodo;
            montos[cantPeriodos] = v.getTotal();
            cantPeriodos++;
        }
    }

    const char* etiqueta = (opcion == 1) ? "Dia" : (opcion == 2) ? "Mes" : "Anio";
    cout << "\n--- Recaudacion por " << etiqueta << " ---" << endl;
    for (int i = 0; i < cantPeriodos; i++) {
        cout << etiqueta << ": " << periodos[i] << " - $ " << montos[i] << endl;
    }

    delete[] periodos;
    delete[] montos;
}

void VentaManager::recaudacionPorTipoPago() {
    float efectivo = 0, transferencia = 0, tarjeta = 0;
    int cantEf = 0, cantTr = 0, cantTa = 0;
    int cant = _arch.getCantidadRegistros();
    for (int i = 0; i < cant; i++) {
        Venta v = _arch.leer(i);
        if (v.getEliminado()) continue;
        if (v.getTipoPago() == 1)         { efectivo      += v.getTotal(); cantEf++; }
        else if (v.getTipoPago() == 2)    { transferencia += v.getTotal(); cantTr++; }
        else if (v.getTipoPago() == 3)    { tarjeta       += v.getTotal(); cantTa++; }
    }
    cout << "Efectivo:      " << cantEf << " ventas - $" << efectivo      << endl;
    cout << "Transferencia: " << cantTr << " ventas - $" << transferencia << endl;
    cout << "Tarjeta:       " << cantTa << " ventas - $" << tarjeta       << endl;
}

void VentaManager::rankingClientes() {
    ClienteArchivo clieArch;
    int cantV = _arch.getCantidadRegistros();
    int cantC = clieArch.getCantidadRegistros();

    float* gastos = new float[cantC + 1]();
    for (int i = 0; i < cantV; i++) {
        Venta v = _arch.leer(i);
        if (!v.getEliminado() && v.getIdCliente() <= cantC)
            gastos[v.getIdCliente()] += v.getTotal();
    }

    int* idx = new int[cantC];
    for (int i = 0; i < cantC; i++) idx[i] = i + 1;
    for (int i = 0; i < cantC - 1; i++)
        for (int j = 0; j < cantC - 1 - i; j++)
            if (gastos[idx[j]] < gastos[idx[j+1]]) {
                int tmp = idx[j]; idx[j] = idx[j+1]; idx[j+1] = tmp;
            }

    cout << "\n--- Ranking de Clientes ---" << endl;
    for (int i = 0; i < cantC; i++) {
        if (gastos[idx[i]] == 0) break;
        int pos = clieArch.buscar(idx[i]);
        if (pos != -1) {
            Cliente c = clieArch.leer(pos);
            cout << (i+1) << ". ";
            c.mostrar();
            cout << "   Total gastado: $" << gastos[idx[i]] << endl;
        }
    }
    delete[] gastos;
    delete[] idx;
}

void VentaManager::anular() {
    cout << "ID de venta a anular: ";
    int id = leerEntero(1, 99999);
    int pos = _arch.buscar(id);
    if (pos == -1) {
        cout << "Venta no encontrada." << endl;
        return;
    }
    Venta v = _arch.leer(pos);
    v.setEliminado(true);
    _arch.guardar(v, pos);
    _detArch.anularPorVenta(id);
    cout << "Venta anulada correctamente (detalles incluidos)." << endl;
}
