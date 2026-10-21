#ifndef TABLERO_H
#define TABLERO_H

#include <vector>
#include "casilla.h"

class Tablero {
private:
    int filas;
    int columnas;
    int minas;
    std::vector<std::vector<Casilla>> casillas;

    void recalcularNumeros(int i, int j);

public:
    Tablero(int filas, int columnas, int minas);

    int getFilas() const;
    int getColumnas() const;
    int getMinas() const;
    void colocarMinas(int fila, int columna);
    void imprimirTablero() const;
    bool click(int i, int j);
    bool estaRevelada(int i, int j) const;
    bool esBomba(int i, int j) const;
    int getNumero(int i, int j) const;
};

#endif