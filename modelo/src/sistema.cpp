#include <iostream>

#include "../includes/tablero.h"
#include "../includes/sistema.h"

Sistema::Sistema() {}


bool Sistema::iniciarJuego(int filas, int columnas, int minas, int i, int j) {
    if (i < 0 || i >= filas || j < 0 || j >= columnas) {
        return false;
    }

    tablero = new Tablero(filas, columnas, minas);
    terminada = false;
    descubiertas = 0;

    tablero->colocarMinas(i, j);

    return tablero->click(i, j);
}

void Sistema::addDescubiertas(int numero) {
    descubiertas += numero;
}

bool Sistema::revelarCasilla(int i, int j) {
    if (tablero == nullptr) {
        return false;
    }

    if (i < 0 || i >= tablero->getFilas() || j < 0 || j >= tablero->getColumnas()) {
        return false;
    }

    return tablero->click(i, j);
}

bool Sistema::comprobarFinal() {
    if (tablero == nullptr) {
        return false;
    }

    if (tablero->getFilas()*tablero->getColumnas() == descubiertas + tablero->getMinas()) {
        return true;
    }

    return false;
}

bool Sistema::estaRevelada(int i, int j) const {
    return tablero != nullptr && tablero->estaRevelada(i, j);
}

bool Sistema::esBomba(int i, int j) const {
    return tablero != nullptr && tablero->esBomba(i, j);
}

int Sistema::getNumero(int i, int j) const {
    return tablero != nullptr ? tablero->getNumero(i, j) : 0;
}

bool Sistema::esBloqueada(int i, int j) const {
    if (tablero == nullptr) {
        return false;
    }

    return tablero->esBloqueada(i, j);
}

void Sistema::setBloqueada(int i, int j, bool bloqueada) {
    if (tablero == nullptr) {
        return;
    }

    tablero->setBloqueada(i, j, bloqueada);
}

void Sistema::reiniciar() {
    delete tablero;
    tablero = nullptr;

    terminada = false;
    descubiertas = 0;
}