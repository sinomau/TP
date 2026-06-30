#include "Menu.h"
#include "ClienteManager.h"
#include "EmpleadoManager.h"
#include "ProveedorManager.h"
#include "ProductoManager.h"
#include "VentaManager.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void Menu::menuPrincipal() {
    int op;
    do {
        system("cls");
        cout << "===== SISTEMA DE GESTION =====" << endl;
        cout << "1. Clientes"    << endl;
        cout << "2. Empleados"   << endl;
        cout << "3. Proveedores" << endl;
        cout << "4. Productos"   << endl;
        cout << "5. Ventas"      << endl;
        cout << "6. Listados"    << endl;
        cout << "7. Consultas"   << endl;
        cout << "8. Informes"    << endl;
        cout << "0. Salir"       << endl;
        cout << "Opcion: "; op = leerEntero(0, 8);

        switch (op) {
            case 1: menuClientes();    break;
            case 2: menuEmpleados();   break;
            case 3: menuProveedores(); break;
            case 4: menuProductos();   break;
            case 5: menuVentas();      break;
            case 6: menuListados();    break;
            case 7: menuConsultas();   break;
            case 8: menuInformes();    break;
            case 0: cout << "Hasta luego." << endl; break;
        }
    } while (op != 0);
}

void Menu::menuClientes() {
    ClienteManager mgr;
    int op;
    do {
        system("cls");
        cout << "--- CLIENTES ---" << endl;
        cout << "1. Alta"         << endl;
        cout << "2. Baja"         << endl;
        cout << "3. Modificacion" << endl;
        cout << "4. Listado"      << endl;
        cout << "0. Volver"       << endl;
        cout << "Opcion: "; op = leerEntero(0, 4);

        switch (op) {
            case 1: mgr.cargar();    system("pause"); break;
            case 2: mgr.eliminar();  system("pause"); break;
            case 3: mgr.modificar(); system("pause"); break;
            case 4: mgr.listar();    system("pause"); break;
            case 0: break;
        }
    } while (op != 0);
}

void Menu::menuEmpleados() {
    EmpleadoManager mgr;
    int op;
    do {
        system("cls");
        cout << "--- EMPLEADOS ---" << endl;
        cout << "1. Alta"         << endl;
        cout << "2. Baja"         << endl;
        cout << "3. Modificacion" << endl;
        cout << "4. Listado"      << endl;
        cout << "0. Volver"       << endl;
        cout << "Opcion: "; op = leerEntero(0, 4);

        switch (op) {
            case 1: mgr.cargar();    system("pause"); break;
            case 2: mgr.eliminar();  system("pause"); break;
            case 3: mgr.modificar(); system("pause"); break;
            case 4: mgr.listar();    system("pause"); break;
            case 0: break;
        }
    } while (op != 0);
}

void Menu::menuProveedores() {
    ProveedorManager mgr;
    int op;
    do {
        system("cls");
        cout << "--- PROVEEDORES ---" << endl;
        cout << "1. Alta"         << endl;
        cout << "2. Baja"         << endl;
        cout << "3. Modificacion" << endl;
        cout << "4. Listado"      << endl;
        cout << "0. Volver"       << endl;
        cout << "Opcion: "; op = leerEntero(0, 4);

        switch (op) {
            case 1: mgr.cargar();    system("pause"); break;
            case 2: mgr.eliminar();  system("pause"); break;
            case 3: mgr.modificar(); system("pause"); break;
            case 4: mgr.listar();    system("pause"); break;
            case 0: break;
        }
    } while (op != 0);
}

void Menu::menuProductos() {
    ProductoManager mgr;
    int op;
    do {
        system("cls");
        cout << "--- PRODUCTOS ---" << endl;
        cout << "1. Alta"         << endl;
        cout << "2. Baja"         << endl;
        cout << "3. Modificacion" << endl;
        cout << "4. Listado"      << endl;
        cout << "0. Volver"       << endl;
        cout << "Opcion: "; op = leerEntero(0, 4);

        switch (op) {
            case 1: mgr.cargar();    system("pause"); break;
            case 2: mgr.eliminar();  system("pause"); break;
            case 3: mgr.modificar(); system("pause"); break;
            case 4: mgr.listar();    system("pause"); break;
            case 0: break;
        }
    } while (op != 0);
}

void Menu::menuVentas() {
    VentaManager mgr;
    int op;
    do {
        system("cls");
        cout << "--- VENTAS ---"       << endl;
        cout << "1. Nueva venta"         << endl;
        cout << "2. Anular venta"        << endl;
        cout << "3. Listado de ventas"   << endl;
        cout << "4. Detalle de una venta"<< endl;
        cout << "0. Volver"             << endl;
        cout << "Opcion: "; op = leerEntero(0, 4);

        switch (op) {
            case 1: mgr.nuevaVenta();   system("pause"); break;
            case 2: mgr.anular();       system("pause"); break;
            case 3: mgr.listar();       system("pause"); break;
            case 4: mgr.listarPorId();  system("pause"); break;
            case 0: break;
        }
    } while (op != 0);
}

void Menu::menuListados() {
    int op;
    do {
        system("cls");
        cout << "--- LISTADOS ---"                  << endl;
        cout << "1. Listado de clientes"              << endl;
        cout << "2. Listado de empleados"             << endl;
        cout << "3. Listado de proveedores"           << endl;
        cout << "4. Listado de productos"             << endl;
        cout << "5. Productos con stock critico"      << endl;
        cout << "6. Listado de ventas"                << endl;
        cout << "0. Volver"                           << endl;
        cout << "Opcion: "; op = leerEntero(0, 6);

        ClienteManager  clieMgr;
        EmpleadoManager emplMgr;
        ProveedorManager provMgr;
        ProductoManager  prodMgr;
        VentaManager     ventMgr;

        switch (op) {
            case 1: clieMgr.listar();               system("pause"); break;
            case 2: emplMgr.listar();               system("pause"); break;
            case 3: provMgr.listar();               system("pause"); break;
            case 4: prodMgr.listar();               system("pause"); break;
            case 5: prodMgr.listarStockCritico();   system("pause"); break;
            case 6: ventMgr.listar();               system("pause"); break;
            case 0: break;
        }
    } while (op != 0);
}

void Menu::menuConsultas() {
    int op;
    do {
        system("cls");
        cout << "--- CONSULTAS ---"           << endl;
        cout << "1. Cliente por CUIT/CUIL"      << endl;
        cout << "2. Clientes por tipo"           << endl;
        cout << "3. Productos por tipo de equipo"<< endl;
        cout << "4. Productos por marca"         << endl;
        cout << "5. Ventas por cliente"          << endl;
        cout << "6. Ventas por empleado"         << endl;
        cout << "7. Ventas por rango de fecha"   << endl;
        cout << "0. Volver"                      << endl;
        cout << "Opcion: "; op = leerEntero(0, 7);

        ClienteManager  clieMgr;
        ProductoManager prodMgr;
        VentaManager    ventMgr;

        switch (op) {
            case 1: clieMgr.buscarPorCuil();    system("pause"); break;
            case 2: clieMgr.listarPorTipo();    system("pause"); break;
            case 3: prodMgr.buscarPorTipo();    system("pause"); break;
            case 4: prodMgr.buscarPorMarca();   system("pause"); break;
            case 5: ventMgr.listarPorCliente(); system("pause"); break;
            case 6: ventMgr.listarPorEmpleado();system("pause"); break;
            case 7: ventMgr.buscarPorRangoFecha();system("pause"); break;
            case 0: break;
        }
    } while (op != 0);
}

void Menu::menuInformes() {
    int op;
    do {
        system("cls");
        cout << "--- INFORMES ---"                  << endl;
        cout << "1. Recaudacion total"                << endl;
        cout << "2. Recaudacion por tipo de pago"     << endl;
        cout << "3. Ranking de clientes"              << endl;
        cout << "4. Ranking de vendedores"            << endl;
        cout << "5. Productos con stock critico"      << endl;
        cout << "0. Volver"                           << endl;
        cout << "Opcion: "; op = leerEntero(0, 5);

        VentaManager    ventMgr;
        EmpleadoManager emplMgr;
        ProductoManager prodMgr;

        switch (op) {
            case 1: ventMgr.recaudacionTotal();       system("pause"); break;
            case 2: ventMgr.recaudacionPorTipoPago();  system("pause"); break;
            case 3: ventMgr.rankingClientes();         system("pause"); break;
            case 4: emplMgr.rankingVendedores();       system("pause"); break;
            case 5: prodMgr.listarStockCritico();      system("pause"); break;
            case 0: break;
        }
    } while (op != 0);
}
