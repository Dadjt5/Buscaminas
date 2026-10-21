#include <iostream>
#include <random>
#include <cmath>

#include "../includes/tablero.h"
#include "../includes/casilla.h"

Tablero::Tablero(int filas, int columnas, int minas)
        : filas(filas),
          columnas(columnas),
          minas(minas),
          casillas(filas, std::vector<Casilla>(columnas)) {}

int Tablero::getFilas() const {
    return filas;
}

int Tablero::getColumnas() const {
    return columnas;
}

int Tablero::getMinas() const {
    return minas;
}

bool Tablero::estaRevelada(int i, int j) const {
    return casillas[i][j].esRevelada();
}

bool Tablero::esBomba(int i, int j) const {
    return casillas[i][j].esBomba();
}

int Tablero::getNumero(int i, int j) const {
    return casillas[i][j].getNumero();
}

bool Tablero::click(int i, int j) {
    if (casillas[i][j].esRevelada()) {
        return false;
    }

    if (!casillas[i][j].esBomba()) {
        casillas[i][j].setRevelada(true);
        if (casillas[i][j].getNumero() == 0) {
            for (int x = -1; x < 2; x++) {
                for (int y = -1; y < 2; y++) {
                    if (i+x >= 0 && i+x < filas && j+y >= 0 && j+y < columnas) {
                        if (x == 0 && y == 0) {
                            continue;
                        }
                
                        click(i+x, j+y);
                    }
                }
            }
        }
    } else {
        return true;
    }

    return false;
}

void Tablero::colocarMinas(int fila, int columna) {
    if (filas*columnas <= minas) {
        return;
    }

    std::random_device rd;
    std::mt19937 generador(rd());

    int i, j;
    int controlador_minas = 0;
    while (controlador_minas < minas) {
        std::uniform_int_distribution<int> distFila(0, filas - 1);
        std::uniform_int_distribution<int> distColumna(0, columnas - 1);
        
        do {
            i = distFila(generador);
            j = distColumna(generador);
        } while (std::abs(i - fila) <= 1 && std::abs(j - columna) <= 1);

        if (!casillas[i][j].esBomba()) {
            casillas[i][j].setBomba(true);
            controlador_minas++;
            recalcularNumeros(i, j);
        }
    }
}

void Tablero::recalcularNumeros(int i, int j) {
    if (i < 0 || i >= filas || j < 0 || j >= columnas) {
        return;
    }

    for (int x = -1; x < 2; x++) {
        for (int y = -1; y < 2; y++) {
            if (i+x >= 0 && i+x < filas && j+y >= 0 && j+y < columnas) {
                if (x == 0 && y == 0) {
                    continue;
                }

                if (!casillas[i+x][j+y].esBomba()) {
                    casillas[i+x][j+y].aumentarNumero(1);
                }
            }
        }
    }
}

void Tablero::imprimirTablero() const {
    std::cout << " ";
    for (int e = 0; e < columnas*2-1; e++) {
        std::cout << "_";
    }

    std::cout << std::endl;
    for (int i = 0; i < filas; i++) {
        std::cout << "|";
        for (int j = 0; j < columnas; j++) {
            if (casillas[i][j].esBomba()) {
                std::cout << "b ";
            } else {
                std::cout << casillas[i][j].getNumero() << " ";
            }
        }
        std::cout << std::endl;
    }
}

bool Tablero::esBloqueada(int i, int j) const {
    if (i < 0 || i >= filas || j < 0 || j >= columnas) {
        return false;
    }

    return casillas[i][j].esBloqueada();
}

void Tablero::setBloqueada(int i, int j, bool bloqueada) {
    if (i < 0 || i >= filas || j < 0 || j >= columnas) {
        return;
    }

    casillas[i][j].setBloqueada(bloqueada);
}