
#include <iostream>
#include <vector>

#include "modelo/includes/tablero.h"

using namespace std;

int main() {
    Tablero tablero(9, 9, 10);

    tablero.imprimirTablero();

    return 0;
}