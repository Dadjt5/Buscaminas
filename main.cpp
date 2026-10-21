#include <iostream>
#include <SFML/Graphics.hpp>

#include "modelo/includes/sistema.h"

constexpr int FILAS = 8;
constexpr int COLUMNAS = 8;
constexpr int TAM = 50;
constexpr int MINAS = 10;

int main() {
    Sistema sistema;
    bool primera = true;
    bool final = false;

    sf::RenderWindow ventana(
        sf::VideoMode(400, 450),
        "Buscaminas en C++"
    );

    ventana.setFramerateLimit(60);

    while (ventana.isOpen()) {
        sf::Event evento;

        while (ventana.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                ventana.close();
            }

            if (evento.type == sf::Event::MouseButtonPressed &&
                evento.mouseButton.button == sf::Mouse::Left) {

                int columna = evento.mouseButton.x / TAM;
                int fila = evento.mouseButton.y / TAM;

                if (fila >= 0 && fila < FILAS &&
                    columna >= 0 && columna < COLUMNAS) {

                    if (primera) {
                        final = sistema.iniciarJuego(
                            FILAS, COLUMNAS, MINAS, fila, columna
                        );
                        primera = false;
                    } else {
                        final = sistema.revelarCasilla(fila, columna);
                    }
                }
            }

            if (final) {
                ventana.close();
                break;
            }
        }

        if (!ventana.isOpen()) {
            break;
        }

        ventana.clear(sf::Color(40, 40, 40));

        for (int fila = 0; fila < FILAS; fila++) {
            for (int columna = 0; columna < COLUMNAS; columna++) {
                sf::RectangleShape casilla(
                    sf::Vector2f(TAM - 2.f, TAM - 2.f)
                );

                casilla.setPosition(sf::Vector2f(
                    columna * TAM,
                    fila * TAM
                ));

                casilla.setFillColor(sf::Color(150, 150, 150));
                ventana.draw(casilla);
            }
        }

        ventana.display();
    }

    return 0;
}