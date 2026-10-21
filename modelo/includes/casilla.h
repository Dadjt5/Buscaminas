#ifndef CASILLA_H
#define CASILLA_H

class Casilla {
private:
    int numero;
    bool bomba;
    bool revelada;
    bool bloqueada;

public:
    Casilla();

    void aumentarNumero(int cantidad);
    int getNumero() const;

    void setBomba(bool bomba);
    bool esBomba() const;

    void setRevelada(bool revelada);
    bool esRevelada() const;

    void setBloqueada(bool bloqueada);
    bool esBloqueada() const;
};

#endif