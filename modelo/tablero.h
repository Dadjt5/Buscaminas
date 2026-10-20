#ifndef TABLERO_H
#define TABLERO_H

class Tablero {
private:
    int filas;
    int columnas;
    int minas;
    std::vector<Casilla> casillas;

    void recalcularNumeros(int i, int j);

public:
    Tablero(int filas, int columnas, int minas);

    int getFilas() const;
    int getColumnas() const;
    int getMinas() const;
    void colocarMinas();
    void imprimirTablero() const;
};

#endif