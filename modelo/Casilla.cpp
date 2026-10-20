#include "Casilla.h"

Casilla::Casilla()
    : revelada(false), bomba(false), numero(0) {}


void Casilla::aumentarNumero(int cantidad) {
    this->numero += cantidad;
}

int Casilla::getNumero() const {
    return numero;
}

void Casilla::setBomba(bool bomba) {
    this->bomba = bomba;
}

bool Casilla::esBomba() const {
    return bomba;
}

void Casilla::setRevelada(bool revelada) {
    this->revelada = revelada;
}

bool Casilla::esRevelada() const {
    return revelada;
}