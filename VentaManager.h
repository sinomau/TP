#pragma once
#include "Venta.h"
#include "VentaArchivo.h"
#include "DetalleVentaArchivo.h"
#include "ProductoArchivo.h"

class VentaManager {
public:
    void nuevaVenta();
    void listar();
    void listarPorId();
    void listarOrdenadoPorFecha();
    void listarPorCliente();
    void listarPorEmpleado();
    void buscarPorRangoFecha();
    void recaudacionTotal();
    void recaudacionPorPeriodo();
    void recaudacionPorTipoPago();
    void rankingClientes();
    void anular();

private:
    VentaArchivo _arch;
    DetalleVentaArchivo _detArch;
    ProductoArchivo _prodArch;
    int generarId();
};
