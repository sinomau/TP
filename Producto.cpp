#include "Producto.h"
#include "Validaciones.h"
#include <iostream>
#include <cstring>
using namespace std;

int    Producto::getIdProducto()   { return idProducto; }
char*  Producto::getNombre()        { return nombre; }
char*  Producto::getDescripcion()   { return descripcion; }
char*  Producto::getMarca()         { return marca; }
int    Producto::getTipoEquipo()    { return tipoEquipo; }
int    Producto::getIdProveedor()   { return idProveedor; }
float  Producto::getPrecioCompra()  { return precioCompra; }
float  Producto::getPrecioVenta()   { return precioVenta; }
int    Producto::getStock()         { return stock; }
int    Producto::getStockMinimo()   { return stockMinimo; }
bool   Producto::getEliminado()     { return eliminado; }

void   Producto::setIdProducto(int valor)         { idProducto   = valor; }
void   Producto::setNombre(const char* valor)     { strncpy(nombre,      valor, 59); nombre[59]      = '\0'; }
void   Producto::setDescripcion(const char* valor){ strncpy(descripcion, valor, 79); descripcion[79] = '\0'; }
void   Producto::setMarca(const char* valor)      { strncpy(marca,       valor, 29); marca[29]       = '\0'; }
void   Producto::setTipoEquipo(int valor)         { tipoEquipo   = valor; }
void   Producto::setIdProveedor(int valor)        { idProveedor  = valor; }
void   Producto::setPrecioCompra(float valor)     { if (valor < 0) valor = 0; precioCompra = valor; }
void   Producto::setPrecioVenta(float valor)      { if (valor < 0) valor = 0; precioVenta  = valor; }
void   Producto::setStock(int valor)              { if (valor < 0) valor = 0; stock        = valor; }
void   Producto::setStockMinimo(int valor)        { if (valor < 0) valor = 0; stockMinimo  = valor; }
void   Producto::setEliminado(bool valor)         { eliminado    = valor; }

void Producto::cargar() {
    cout << "Nombre: ";        cin.getline(nombre, 60);
    cout << "Descripcion: ";   cin.getline(descripcion, 80);
    cout << "Marca: ";         cin.getline(marca, 30);
    do {
        cout << "Tipo equipo (1:PC escritorio / 2:Notebook / 3:Impresora / 4:Periferico): ";
        cin >> tipoEquipo;
        if (cin.fail()) { cin.clear(); cin.ignore(10000, '\n'); tipoEquipo = 0; }
        if (tipoEquipo < 1 || tipoEquipo > 4) cout << "Error: ingrese 1-4." << endl;
    } while (tipoEquipo < 1 || tipoEquipo > 4);
    cout << "ID Proveedor: ";  idProveedor = leerEntero(1, 99999);
    cout << "Precio compra: "; cin >> precioCompra;
    cout << "Precio venta: ";  cin >> precioVenta;
    cout << "Stock: ";         stock = leerEntero(0, 99999);
    cout << "Stock minimo: ";  stockMinimo = leerEntero(0, 99999);
    eliminado = false;
}

void Producto::mostrar() {
    cout << "ID:         " << idProducto   << endl;
    cout << "Nombre:     " << nombre       << endl;
    cout << "Descripcion:" << descripcion  << endl;
    cout << "Marca:      " << marca        << endl;
    cout << "Tipo:       ";
    switch (tipoEquipo) {
        case 1: cout << "PC escritorio"; break;
        case 2: cout << "Notebook";      break;
        case 3: cout << "Impresora";     break;
        case 4: cout << "Periferico";    break;
    }
    cout << endl;
    cout << "ID Proveedor: " << idProveedor  << endl;
    cout << "P. compra:   $" << precioCompra << endl;
    cout << "P. venta:    $" << precioVenta  << endl;
    cout << "Stock:        " << stock        << endl;
    cout << "Stock min:    " << stockMinimo  << endl;
    cout << "----------------------------" << endl;
}
