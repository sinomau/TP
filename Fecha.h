#pragma once

class Fecha {
private:
    int dia;
    int mes;
    int anio;

public:
    int  getDia();
    int  getMes();
    int  getAnio();

    void setFecha(int d, int m, int a);
    void setFechaActual();
    void cargar();
    void mostrar();
    bool esValida();
};
