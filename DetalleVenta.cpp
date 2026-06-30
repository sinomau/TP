#include "DetalleVenta.h"
#include <iostream>
using namespace std;

int    DetalleVenta::getIdDetalle()      { return idDetalle; }
int    DetalleVenta::getIdVenta()        { return idVenta; }
int    DetalleVenta::getIdProducto()     { return idProducto; }
int    DetalleVenta::getCantidad()       { return cantidad; }
float  DetalleVenta::getPrecioUnitario() { return precioUnitario; }
float  DetalleVenta::getSubtotal()       { return subtotal; }
bool   DetalleVenta::getEliminado()      { return eliminado; }

void   DetalleVenta::setIdDetalle(int valor)        { idDetalle      = valor; }
void   DetalleVenta::setIdVenta(int valor)          { idVenta        = valor; }
void   DetalleVenta::setIdProducto(int valor)       { idProducto     = valor; }
void   DetalleVenta::setCantidad(int valor)         { if (valor < 0) valor = 0; cantidad       = valor; }
void   DetalleVenta::setPrecioUnitario(float valor) { if (valor < 0) valor = 0; precioUnitario = valor; }
void   DetalleVenta::setSubtotal(float valor)        { if (valor < 0) valor = 0; subtotal      = valor; }
void   DetalleVenta::setEliminado(bool valor)       { eliminado      = valor; }

void DetalleVenta::mostrar() {
    cout << "ID Detalle: " << idDetalle      << endl;
    cout << "Venta:      " << idVenta        << endl;
    cout << "Producto:   " << idProducto     << endl;
    cout << "Cantidad:   " << cantidad       << endl;
    cout << "P.Unitario: $" << precioUnitario<< endl;
    cout << "Subtotal:   $" << subtotal      << endl;
    cout << "----------------------------" << endl;
}
