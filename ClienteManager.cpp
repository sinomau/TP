#include "ClienteManager.h"
#include "Validaciones.h"
#include <iostream>
#include <cstring>
using namespace std;

int ClienteManager::generarId() {
    int maxId = 0;
    int cant = _arch.getCantidadRegistros();
    for (int i = 0; i < cant; i++) {
        Cliente c = _arch.leer(i);
        if (c.getIdCliente() > maxId) maxId = c.getIdCliente();
    }
    return maxId + 1;
}

void ClienteManager::cargar() {
    Cliente c;
    c.cargar();
    c.setIdCliente(generarId());
    _arch.guardar(c);
    cout << "Cliente dado de alta con ID: " << c.getIdCliente() << endl;
}

void ClienteManager::listar() {
    int cant = _arch.getCantidadRegistros();
    bool hay = false;
    for (int i = 0; i < cant; i++) {
        Cliente c = _arch.leer(i);
        if (!c.getEliminado()) {
            c.mostrar();
            hay = true;
        }
    }
    if (!hay) cout << "No hay clientes registrados." << endl;
}

void ClienteManager::listarPorId() {
    cout << "ID del cliente a buscar: ";
    int id = leerEntero(1, 99999);
    int pos = _arch.buscar(id);
    if (pos == -1 || _arch.leer(pos).getEliminado())
        cout << "Cliente no encontrado." << endl;
    else
        _arch.leer(pos).mostrar();
}

void ClienteManager::listarOrdenadoPorApellido() {
    int cant = _arch.getCantidadRegistros();
    if (cant == 0) {
        cout << "No hay clientes registrados." << endl;
        return;
    }

    Cliente* vec = new Cliente[cant];
    int idx = 0;
    for (int i = 0; i < cant; i++) {
        Cliente c = _arch.leer(i);
        if (!c.getEliminado()) vec[idx++] = c;
    }

    for (int i = 0; i < idx - 1; i++) {
        for (int j = 0; j < idx - 1 - i; j++) {
            if (strcmp(vec[j].getApellido(), vec[j+1].getApellido()) > 0) {
                Cliente tmp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = tmp;
            }
        }
    }

    for (int i = 0; i < idx; i++) vec[i].mostrar();
    delete[] vec;
}

void ClienteManager::listarPorTipo() {
    cout << "Tipo (1:particular / 2:empresa): ";
    int tipo = leerEntero(1, 2);

    int cant = _arch.getCantidadRegistros();
    bool hay = false;
    for (int i = 0; i < cant; i++) {
        Cliente c = _arch.leer(i);
        if (!c.getEliminado() && c.getTipoCliente() == tipo) {
            c.mostrar();
            hay = true;
        }
    }
    if (!hay) cout << "No hay clientes de ese tipo." << endl;
}

void ClienteManager::buscarPorCuil() {
    char cuil[14];
    cout << "CUIT/CUIL a buscar: ";
    cin.getline(cuil, 14);

    int cant = _arch.getCantidadRegistros();
    for (int i = 0; i < cant; i++) {
        Cliente c = _arch.leer(i);
        if (!c.getEliminado() && strcmp(c.getCuil(), cuil) == 0) {
            c.mostrar();
            return;
        }
    }
    cout << "Cliente no encontrado." << endl;
}

void ClienteManager::buscarPorNombre() {
    char busqueda[30];
    cout << "Nombre o apellido a buscar: ";
    cin.getline(busqueda, 30);

    int cant = _arch.getCantidadRegistros();
    bool hay = false;
    for (int i = 0; i < cant; i++) {
        Cliente c = _arch.leer(i);
        if (!c.getEliminado()) {
            if (strcmp(c.getNombre(), busqueda) == 0 ||
                strcmp(c.getApellido(), busqueda) == 0) {
                c.mostrar();
                hay = true;
            }
        }
    }
    if (!hay) cout << "No se encontraron clientes." << endl;
}

void ClienteManager::buscarPorTipo() {
    cout << "Tipo (1:particular / 2:empresa): ";
    int tipo = leerEntero(1, 2);

    int cant = _arch.getCantidadRegistros();
    bool hay = false;
    for (int i = 0; i < cant; i++) {
        Cliente c = _arch.leer(i);
        if (!c.getEliminado() && c.getTipoCliente() == tipo) {
            c.mostrar();
            hay = true;
        }
    }
    if (!hay) cout << "No hay clientes de ese tipo." << endl;
}

void ClienteManager::modificar() {
    cout << "ID del cliente a modificar: ";
    int id = leerEntero(1, 99999);
    int pos = _arch.buscar(id);
    if (pos == -1 || _arch.leer(pos).getEliminado()) {
        cout << "Cliente no encontrado." << endl;
        return;
    }
    Cliente c = _arch.leer(pos);

    int opc;
    do {
        system("cls");
        cout << "=== MODIFICAR CLIENTE (ID: " << id << ") ===" << endl;
        cout << "Datos actuales:" << endl;
        c.mostrar();
        cout << endl;
        cout << "Que campo desea modificar?" << endl;
        cout << "1 - CUIT/CUIL" << endl;
        cout << "2 - Nombre" << endl;
        cout << "3 - Apellido" << endl;
        cout << "4 - Telefono" << endl;
        cout << "5 - Email" << endl;
        cout << "6 - Direccion" << endl;
        cout << "7 - Tipo (particular/empresa)" << endl;
        cout << "0 - Guardar y salir" << endl;
        opc = leerEntero(0, 7);

        char buffer[80];
        int tipo;

        switch (opc) {
        case 1:
            cout << "Nuevo CUIT/CUIL: ";
            cin.getline(buffer, 14);
            c.setCuil(buffer);
            break;
        case 2:
            cout << "Nuevo nombre: ";
            cin.getline(buffer, 30);
            c.setNombre(buffer);
            break;
        case 3:
            cout << "Nuevo apellido: ";
            cin.getline(buffer, 30);
            c.setApellido(buffer);
            break;
        case 4:
            cout << "Nuevo telefono: ";
            cin.getline(buffer, 15);
            c.setTelefono(buffer);
            break;
        case 5:
            cout << "Nuevo email: ";
            cin.getline(buffer, 50);
            c.setEmail(buffer);
            break;
        case 6:
            cout << "Nueva direccion: ";
            cin.getline(buffer, 80);
            c.setDireccion(buffer);
            break;
        case 7:
            cout << "Nuevo tipo (1:particular / 2:empresa): ";
            tipo = leerEntero(1, 2);
            c.setTipoCliente(tipo);
            break;
        case 0:
            break;
        default:
            cout << "Opcion invalida." << endl;
        }

        if (opc != 0) {
            cout << "Campo modificado." << endl;
            system("pause");
        }
    } while (opc != 0);

    _arch.guardar(c, pos);
    cout << "Cliente modificado correctamente." << endl;
}

void ClienteManager::eliminar() {
    cout << "ID del cliente a eliminar: ";
    int id = leerEntero(1, 99999);
    int pos = _arch.buscar(id);
    if (pos == -1 || _arch.leer(pos).getEliminado()) {
        cout << "Cliente no encontrado." << endl;
        return;
    }
    Cliente c = _arch.leer(pos);
    c.setEliminado(true);
    _arch.guardar(c, pos);
    cout << "Cliente eliminado correctamente." << endl;
}
