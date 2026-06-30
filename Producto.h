#pragma once

class Producto {
private:
    int   idProducto;
    char  nombre[60];
    char  descripcion[80];
    char  marca[30];
    int   tipoEquipo;      // 1:PC escritorio / 2:Notebook / 3:Impresora / 4:Periferico
    int   idProveedor;
    float precioCompra;
    float precioVenta;
    int   stock;
    int   stockMinimo;
    bool  eliminado;

public:
    int    getIdProducto();
    char*  getNombre();
    char*  getDescripcion();
    char*  getMarca();
    int    getTipoEquipo();
    int    getIdProveedor();
    float  getPrecioCompra();
    float  getPrecioVenta();
    int    getStock();
    int    getStockMinimo();
    bool   getEliminado();

    void   setIdProducto(int valor);
    void   setNombre(const char* valor);
    void   setDescripcion(const char* valor);
    void   setMarca(const char* valor);
    void   setTipoEquipo(int valor);
    void   setIdProveedor(int valor);
    void   setPrecioCompra(float valor);
    void   setPrecioVenta(float valor);
    void   setStock(int valor);
    void   setStockMinimo(int valor);
    void   setEliminado(bool valor);

    void   cargar();
    void   mostrar();
};
