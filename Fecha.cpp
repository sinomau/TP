#include "Fecha.h"
#include "Validaciones.h"
#include <iostream>
#include <ctime>
#include <limits>
using namespace std;

int  Fecha::getDia()  { return dia; }
int  Fecha::getMes()  { return mes; }
int  Fecha::getAnio() { return anio; }

void Fecha::setFecha(int d, int m, int a) {
    dia  = d;
    mes  = m;
    anio = a;
}

void Fecha::setFechaActual() {
    time_t t = time(NULL);
    struct tm* ahora = localtime(&t);
    dia  = ahora->tm_mday;
    mes  = ahora->tm_mon + 1;
    anio = ahora->tm_year + 1900;
}

bool Fecha::esValida() {
    if (anio < 1900 || mes < 1 || mes > 12 || dia < 1) return false;
    int diasPorMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0)
        diasPorMes[2] = 29;
    return dia <= diasPorMes[mes];
}

void Fecha::cargar() {
    bool ok;
    do {
        cout << "Dia:  "; cin >> dia;
        if (cin.fail()) { cin.clear(); cin.ignore(10000, '\n'); dia = 0; }
        cout << "Mes:  "; mes = leerEntero(1, 12);
        cout << "Anio: "; anio = leerEntero(1900, 2100);

        ok = esValida();
        if (!ok) cout << "Fecha invalida. Intente nuevamente." << endl;
    } while (!ok);
}

void Fecha::mostrar() {
    cout << dia << "/" << mes << "/" << anio;
}
