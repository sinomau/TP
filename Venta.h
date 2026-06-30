#pragma once
#include "Fecha.h"

class Venta {
private:
    int   idVenta;
    int   idCliente;
    int   idEmpleado;
    Fecha fecha;
    char  hora[6];        // HH:MM
    int   tipoPago;       // 1:efectivo / 2:transferencia / 3:tarjeta
    float total;
    bool  eliminado;

public:
    int    getIdVenta();
    int    getIdCliente();
    int    getIdEmpleado();
    Fecha  getFecha();
    char*  getHora();
    int    getTipoPago();
    float  getTotal();
    bool   getEliminado();

    void   setIdVenta(int valor);
    void   setIdCliente(int valor);
    void   setIdEmpleado(int valor);
    void   setFecha(Fecha valor);
    void   setHora(const char* valor);
    void   setTipoPago(int valor);
    void   setTotal(float valor);
    void   setEliminado(bool valor);

    void   cargar();
    void   mostrar();
};
