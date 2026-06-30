#include <cstdio>
#include <cstring>
#include "Cliente.h"
#include "Empleado.h"
#include "Proveedor.h"
#include "Producto.h"
#include "Venta.h"
#include "DetalleVenta.h"
#include "Fecha.h"

void generarClientes() {
    FILE* f = fopen("Clientes.dat", "wb");
    struct { int id; char cuil[14]; char nombre[30]; char apellido[30]; char tel[15]; char email[50]; char dir[80]; int tipo; } datos[] = {
        {1, "20-12345678-9", "Juan",     "Perez",     "1145678901", "juanperez@gmail.com",    "Av. Corrientes 1234", 1},
        {2, "30-98765432-1", "Maria",    "Garcia",    "1156789012", "mariagarcia@hotmail.com", "Calle Florida 567",   2},
        {3, "20-45678901-2", "Carlos",   "Lopez",     "1167890123", "carloslopez@yahoo.com",   "Belgrano 890",        1},
        {4, "27-78901234-5", "Ana",      "Martinez",  "1178901234", "anamartinez@gmail.com",   "San Martin 345",      2},
        {5, "20-34567890-1", "Pedro",    "Rodriguez", "1189012345", "pedrorodriguez@outlook.com","Rivadavia 678",      1},
    };
    for (int i = 0; i < 5; i++) {
        Cliente c;
        c.setIdCliente(datos[i].id);
        c.setCuil(datos[i].cuil);
        c.setNombre(datos[i].nombre);
        c.setApellido(datos[i].apellido);
        c.setTelefono(datos[i].tel);
        c.setEmail(datos[i].email);
        c.setDireccion(datos[i].dir);
        c.setTipoCliente(datos[i].tipo);
        c.setEliminado(false);
        fwrite(&c, sizeof(Cliente), 1, f);
    }
    fclose(f);
    printf("Clientes.dat generado (5 clientes).\n");
}

void generarEmpleados() {
    FILE* f = fopen("Empleados.dat", "wb");
    struct { int id; char nombre[30]; char apellido[30]; char dni[10]; int cargo; char tel[15]; } datos[] = {
        {1, "Laura",    "Fernandez", "40123456", 2, "1145671234"},
        {2, "Martin",   "Gonzalez",  "41234567", 1, "1156782345"},
        {3, "Sofia",    "Diaz",      "42345678", 3, "1167893456"},
        {4, "Diego",    "Torres",    "43456789", 4, "1178904567"},
    };
    for (int i = 0; i < 4; i++) {
        Empleado e;
        e.setIdEmpleado(datos[i].id);
        e.setNombre(datos[i].nombre);
        e.setApellido(datos[i].apellido);
        e.setDni(datos[i].dni);
        e.setCargo(datos[i].cargo);
        e.setTelefono(datos[i].tel);
        e.setEliminado(false);
        fwrite(&e, sizeof(Empleado), 1, f);
    }
    fclose(f);
    printf("Empleados.dat generado (4 empleados).\n");
}

void generarProveedores() {
    FILE* f = fopen("Proveedores.dat", "wb");
    struct { int id; char rs[60]; char cuit[14]; char tel[15]; char email[50]; float cc; } datos[] = {
        {1, "TecnoSur S.A.",          "30-12345678-9", "1145678901", "ventas@tecnosur.com",   15000.50f},
        {2, "InfoNova S.R.L.",        "30-87654321-0", "1156789012", "info@infonova.com",     25000.00f},
        {3, "DigiWorld Argentina",    "30-45678901-2", "1167890123", "contacto@digiworld.com", 8000.75f},
    };
    for (int i = 0; i < 3; i++) {
        Proveedor p;
        p.setIdProveedor(datos[i].id);
        p.setRazonSocial(datos[i].rs);
        p.setCuit(datos[i].cuit);
        p.setNombre("");
        p.setApellido("");
        p.setTelefono(datos[i].tel);
        p.setEmail(datos[i].email);
        p.setCuentaCorriente(datos[i].cc);
        p.setEliminado(false);
        fwrite(&p, sizeof(Proveedor), 1, f);
    }
    fclose(f);
    printf("Proveedores.dat generado (3 proveedores).\n");
}

void generarProductos() {
    FILE* f = fopen("Productos.dat", "wb");
    struct {
        int id; char nombre[60]; char desc[80]; char marca[30]; int tipo; int idProv;
        float pCompra; float pVenta; int stock; int stockMin;
    } datos[] = {
        {1,  "PC Desktop i5",        "PC escritorio Intel i5 16GB 512SSD",       "Dell",       1, 1, 450.0f, 650.0f, 10, 3},
        {2,  "Notebook Ultra",       "Notebook 15.6 AMD Ryzen 5 8GB 256SSD",     "HP",         2, 1, 580.0f, 820.0f, 5,  2},
        {3,  "Impresora Laser",      "Impresora laser monocromatica 28ppm",       "Brother",    3, 2, 120.0f, 190.0f, 8,  2},
        {4,  "Mouse Inalambrico",    "Mouse ergonomico inalambrico USB",          "Logitech",   4, 3, 25.0f,  45.0f,  20, 5},
        {5,  "Teclado Mecanico",     "Teclado mecanico retroiluminado RGB",      "Redragon",   4, 3, 55.0f,  90.0f,  15, 3},
        {6,  "Monitor 27\"",         "Monitor IPS 27 pulgadas 4K",                "Samsung",    4, 1, 280.0f, 420.0f, 0,  2},
        {7,  "Notebook Gamer",       "Notebook i7 16GB RTX3060 1TB",              "MSI",        2, 1, 1200.0f,1650.0f, 3,  1},
        {8,  "PC Desktop i3",        "PC escritorio i3 8GB 240SSD",               "Lenovo",     1, 2, 320.0f, 480.0f, 7,  3},
        {9,  "Pendrive 64GB",        "Pendrive USB 3.0 64GB",                    "Kingston",   4, 2, 12.0f,  22.0f,  30, 10},
        {10, "Impresora Tinta",      "Impresora multifuncion color WiFi",         "Epson",      3, 1, 95.0f,  160.0f, 4,  2},
    };
    for (int i = 0; i < 10; i++) {
        Producto p;
        p.setIdProducto(datos[i].id);
        p.setNombre(datos[i].nombre);
        p.setDescripcion(datos[i].desc);
        p.setMarca(datos[i].marca);
        p.setTipoEquipo(datos[i].tipo);
        p.setIdProveedor(datos[i].idProv);
        p.setPrecioCompra(datos[i].pCompra);
        p.setPrecioVenta(datos[i].pVenta);
        p.setStock(datos[i].stock);
        p.setStockMinimo(datos[i].stockMin);
        p.setEliminado(false);
        fwrite(&p, sizeof(Producto), 1, f);
    }
    fclose(f);
    printf("Productos.dat generado (10 productos).\n");
}

void generarVentas() {
    FILE* fV = fopen("Ventas.dat", "wb");
    FILE* fD = fopen("DetallesVenta.dat", "wb");

    // Venta 1: Cliente 1, Empleado 2, 3 productos
    {
        Venta v;
        v.setIdVenta(1);
        v.setIdCliente(1);
        v.setIdEmpleado(2);
        Fecha f; f.setFecha(10, 5, 2026);
        v.setFecha(f);
        v.setHora("10:30");
        v.setTipoPago(1);
        v.setTotal(785.0f);
        v.setEliminado(false);
        fwrite(&v, sizeof(Venta), 1, fV);

        DetalleVenta d;
        d.setIdDetalle(1); d.setIdVenta(1); d.setIdProducto(1); d.setCantidad(1); d.setPrecioUnitario(650.0f); d.setSubtotal(650.0f); d.setEliminado(false); fwrite(&d, sizeof(DetalleVenta), 1, fD);
        d.setIdDetalle(2); d.setIdVenta(1); d.setIdProducto(4); d.setCantidad(3); d.setPrecioUnitario(45.0f);  d.setSubtotal(135.0f); d.setEliminado(false); fwrite(&d, sizeof(DetalleVenta), 1, fD);
    }

    // Venta 2: Cliente 2, Empleado 1, 2 productos
    {
        Venta v;
        v.setIdVenta(2);
        v.setIdCliente(2);
        v.setIdEmpleado(1);
        Fecha f; f.setFecha(12, 5, 2026);
        v.setFecha(f);
        v.setHora("14:15");
        v.setTipoPago(3);
        v.setTotal(910.0f);
        v.setEliminado(false);
        fwrite(&v, sizeof(Venta), 1, fV);

        DetalleVenta d;
        d.setIdDetalle(3); d.setIdVenta(2); d.setIdProducto(2); d.setCantidad(1); d.setPrecioUnitario(820.0f); d.setSubtotal(820.0f); d.setEliminado(false); fwrite(&d, sizeof(DetalleVenta), 1, fD);
        d.setIdDetalle(4); d.setIdVenta(2); d.setIdProducto(9); d.setCantidad(5); d.setPrecioUnitario(18.0f);  d.setSubtotal(90.0f);  d.setEliminado(false); fwrite(&d, sizeof(DetalleVenta), 1, fD);
    }

    // Venta 3: Cliente 3, Empleado 3, 1 producto
    {
        Venta v;
        v.setIdVenta(3);
        v.setIdCliente(3);
        v.setIdEmpleado(3);
        Fecha f; f.setFecha(15, 5, 2026);
        v.setFecha(f);
        v.setHora("09:45");
        v.setTipoPago(2);
        v.setTotal(1650.0f);
        v.setEliminado(false);
        fwrite(&v, sizeof(Venta), 1, fV);

        DetalleVenta d;
        d.setIdDetalle(5); d.setIdVenta(3); d.setIdProducto(7); d.setCantidad(1); d.setPrecioUnitario(1650.0f); d.setSubtotal(1650.0f); d.setEliminado(false); fwrite(&d, sizeof(DetalleVenta), 1, fD);
    }

    // Venta 4: Cliente 1, Empleado 4, 2 productos
    {
        Venta v;
        v.setIdVenta(4);
        v.setIdCliente(1);
        v.setIdEmpleado(4);
        Fecha f; f.setFecha(20, 5, 2026);
        v.setFecha(f);
        v.setHora("11:00");
        v.setTipoPago(1);
        v.setTotal(240.0f);
        v.setEliminado(false);
        fwrite(&v, sizeof(Venta), 1, fV);

        DetalleVenta d;
        d.setIdDetalle(6); d.setIdVenta(4); d.setIdProducto(3); d.setCantidad(1); d.setPrecioUnitario(190.0f); d.setSubtotal(190.0f); d.setEliminado(false); fwrite(&d, sizeof(DetalleVenta), 1, fD);
        d.setIdDetalle(7); d.setIdVenta(4); d.setIdProducto(5); d.setCantidad(1); d.setPrecioUnitario(50.0f);  d.setSubtotal(50.0f);  d.setEliminado(false); fwrite(&d, sizeof(DetalleVenta), 1, fD);
    }

    // Venta 5: Cliente 4, Empleado 2, 3 productos (anulada)
    {
        Venta v;
        v.setIdVenta(5);
        v.setIdCliente(4);
        v.setIdEmpleado(2);
        Fecha f; f.setFecha(25, 5, 2026);
        v.setFecha(f);
        v.setHora("16:30");
        v.setTipoPago(2);
        v.setTotal(952.0f);
        v.setEliminado(true);  // Anulada
        fwrite(&v, sizeof(Venta), 1, fV);

        DetalleVenta d;
        d.setIdDetalle(8); d.setIdVenta(5); d.setIdProducto(8); d.setCantidad(1); d.setPrecioUnitario(480.0f); d.setSubtotal(480.0f); d.setEliminado(false); fwrite(&d, sizeof(DetalleVenta), 1, fD);
        d.setIdDetalle(9); d.setIdVenta(5); d.setIdProducto(10); d.setCantidad(2); d.setPrecioUnitario(160.0f); d.setSubtotal(320.0f); d.setEliminado(false); fwrite(&d, sizeof(DetalleVenta), 1, fD);
        d.setIdDetalle(10); d.setIdVenta(5); d.setIdProducto(9); d.setCantidad(8); d.setPrecioUnitario(19.0f); d.setSubtotal(152.0f); d.setEliminado(false); fwrite(&d, sizeof(DetalleVenta), 1, fD);
    }

    // Venta 6: Cliente 5, Empleado 1, 1 producto
    {
        Venta v;
        v.setIdVenta(6);
        v.setIdCliente(5);
        v.setIdEmpleado(1);
        Fecha f; f.setFecha(28, 5, 2026);
        v.setFecha(f);
        v.setHora("17:45");
        v.setTipoPago(1);
        v.setTotal(45.0f);
        v.setEliminado(false);
        fwrite(&v, sizeof(Venta), 1, fV);

        DetalleVenta d;
        d.setIdDetalle(11); d.setIdVenta(6); d.setIdProducto(4); d.setCantidad(1); d.setPrecioUnitario(45.0f); d.setSubtotal(45.0f); d.setEliminado(false); fwrite(&d, sizeof(DetalleVenta), 1, fD);
    }

    fclose(fV);
    fclose(fD);
    printf("Ventas.dat generado (6 ventas, 1 anulada).\n");
    printf("DetallesVenta.dat generado (11 detalles).\n");
}

int main() {
    generarClientes();
    generarEmpleados();
    generarProveedores();
    generarProductos();
    generarVentas();
    printf("\nTodos los archivos .dat fueron generados correctamente.\n");
    return 0;
}
