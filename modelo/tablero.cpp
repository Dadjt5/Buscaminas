#include <random>

#include "Tablero.h"
#include "Casilla.h"

Tablero::Tablero(int filas, int columnas, int minas)
        : filas(filas),
          columnas(columnas),
          minas(minas),
          casillas(filas, std::vector<Casilla>(columnas)) {
    
    colocarMinas();
}

int Tablero::getFilas() const {
    return filas;
}

int Tablero::getColumnas() const {
    return columnas;
}

int Tablero::getMinas() const {
    return minas;
}

void Tablero::colocarMinas() {
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
        
        i = distFila(generador);
        j = distColumna(generador);

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
            if (i+x >= 0 || i+x < filas || j+y >= 0 || j+y < columnas) {
                if (!casillas[i+x][i+j].esBomba()) {
                    casillas[i+x][i+j].aumentarNumero(1);
                }
            }
        }
    }
}

void Tablero::imprimirTablero() const {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            
        }
    }
}