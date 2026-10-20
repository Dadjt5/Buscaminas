#ifndef CASILLA_H
#define CASILLA_H

class Casilla {
private:
    int numero;
    bool bomba;
    bool revelada;

public:
    Casilla(int numero, int bomba);

    void aumentarNumero(int cantidad);
    int getNumero() const;

    void setBomba(bool bomba);
    bool esBomba() const;

    void setRevelada(bool revelada);
    bool esRevelada() const;
};

#endif