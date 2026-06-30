#pragma once

class DetalleVenta {
private:
    int   idDetalle;
    int   idVenta;
    int   idProducto;
    int   cantidad;
    float precioUnitario;
    float subtotal;
    bool  eliminado;

public:
    int    getIdDetalle();
    int    getIdVenta();
    int    getIdProducto();
    int    getCantidad();
    float  getPrecioUnitario();
    float  getSubtotal();
    bool   getEliminado();

    void   setIdDetalle(int valor);
    void   setIdVenta(int valor);
    void   setIdProducto(int valor);
    void   setCantidad(int valor);
    void   setPrecioUnitario(float valor);
    void   setSubtotal(float valor);
    void   setEliminado(bool valor);

    void   mostrar();
};
