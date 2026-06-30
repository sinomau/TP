#include "Venta.h"
#include "Validaciones.h"
#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdio>
using namespace std;

int    Venta::getIdVenta()     { return idVenta; }
int    Venta::getIdCliente()   { return idCliente; }
int    Venta::getIdEmpleado()  { return idEmpleado; }
Fecha  Venta::getFecha()       { return fecha; }
char*  Venta::getHora()        { return hora; }
int    Venta::getTipoPago()    { return tipoPago; }
float  Venta::getTotal()       { return total; }
bool   Venta::getEliminado()   { return eliminado; }

void   Venta::setIdVenta(int valor)          { idVenta    = valor; }
void   Venta::setIdCliente(int valor)        { idCliente  = valor; }
void   Venta::setIdEmpleado(int valor)       { idEmpleado = valor; }
void   Venta::setFecha(Fecha valor)          { fecha      = valor; }
void   Venta::setHora(const char* valor)     { strncpy(hora, valor, 5); hora[5] = '\0'; }
void   Venta::setTipoPago(int valor)         { tipoPago   = valor; }
void   Venta::setTotal(float valor)          { if (valor < 0) valor = 0; total = valor; }
void   Venta::setEliminado(bool valor)       { eliminado  = valor; }

void Venta::cargar() {
    cout << "ID Cliente: ";  idCliente = leerEntero(1, 99999);
    cout << "ID Empleado: "; idEmpleado = leerEntero(1, 99999);
    fecha.setFechaActual();
    time_t t = time(NULL);
    tm* ahora = localtime(&t);
    sprintf(hora, "%02d:%02d", ahora->tm_hour, ahora->tm_min);
    hora[5] = '\0';
    cout << "Tipo pago (1:efectivo / 2:transferencia / 3:tarjeta): ";
    tipoPago = leerEntero(1, 3);
    // total se calcula al registrar venta (desde VentaManager)
    eliminado = false;
}

void Venta::mostrar() {
    cout << "ID Venta:   " << idVenta   << endl;
    cout << "Cliente:    " << idCliente << endl;
    cout << "Empleado:   " << idEmpleado << endl;
    cout << "Fecha:      "; fecha.mostrar(); cout << endl;
    cout << "Hora:       " << hora       << endl;
    cout << "Tipo pago:  ";
    switch (tipoPago) {
        case 1: cout << "Efectivo";      break;
        case 2: cout << "Transferencia"; break;
        case 3: cout << "Tarjeta";       break;
    }
    cout << endl;
    cout << "Total:     $" << total      << endl;
    cout << "----------------------------" << endl;
}
