#include "../includes/casilla.h"

Casilla::Casilla(): revelada(false), bomba(false), numero(0), bloqueada(false) {}


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

void Casilla::setBloqueada(bool bloqueada) {
    this->bloqueada = bloqueada;
}

bool Casilla::esBloqueada() const {
    return bloqueada;
}