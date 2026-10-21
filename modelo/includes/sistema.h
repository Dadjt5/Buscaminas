#ifndef SISTEMA_H
#define SISTEMA_H

#include "tablero.h"

class Sistema {
private:
    Tablero* tablero = nullptr;
    bool terminada;
    bool descubiertas;

public:
    Sistema();

    bool iniciarJuego(int filas, int columnas, int minas, int i, int j);
    bool comprobarFinal();
    void addDescubiertas(int numero);
    bool revelarCasilla(int i, int j);
    bool estaRevelada(int i, int j) const;
    bool esBomba(int i, int j) const;
    int getNumero(int i, int j) const;
    bool esBloqueada(int i, int j) const;
    void setBloqueada(int i, int j, bool bloqueada);
    void reiniciar();
};

#endif