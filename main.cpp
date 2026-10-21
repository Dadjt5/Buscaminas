
#include <iostream>
#include <SFML/Graphics.hpp>
#include "modelo/includes/sistema.h"

constexpr int FILAS = 8;
constexpr int COLUMNAS = 8;
constexpr int TAM = 48;
constexpr int MINAS = 10;
constexpr int MARGEN_X = 8;
constexpr int MARGEN_Y = 88;
constexpr int ANCHO = COLUMNAS * TAM + 2 * MARGEN_X;
constexpr int ALTO = FILAS * TAM + MARGEN_Y + 12;

sf::Color colorNumero(int numero) {
    switch (numero) {
        case 1: return sf::Color(55, 125, 235);
        case 2: return sf::Color(40, 155, 100);
        case 3: return sf::Color(225, 75, 75);
        case 4: return sf::Color(125, 80, 205);
        case 5: return sf::Color(180, 85, 45);
        case 6: return sf::Color(35, 160, 175);
        case 7: return sf::Color(40, 40, 45);
        case 8: return sf::Color(110, 110, 110);
        default: return sf::Color::Black;
    }
}

int main() {
    Sistema sistema;
    bool primera = true;
    bool final = false;

    sf::RenderWindow ventana(
        sf::VideoMode(ANCHO, ALTO),
        "Buscaminas"
    );

    ventana.setFramerateLimit(60);

    sf::Font fuente;
    if (!fuente.loadFromFile("assets/DejaVuSans.ttf")) {
        std::cerr << "No se pudo cargar la fuente.\n";
        return 1;
    }

    sf::Text titulo("BUSCAMINAS", fuente, 24);
    titulo.setFillColor(sf::Color(240, 243, 250));
    titulo.setStyle(sf::Text::Bold);
    titulo.setPosition(12.f, 10.f);

    sf::Text subtitulo("Encuentra las casillas seguras", fuente, 12);
    subtitulo.setFillColor(sf::Color(165, 178, 200));
    subtitulo.setPosition(14.f, 43.f);

    sf::Text estado("", fuente, 13);
    estado.setPosition(14.f, 62.f);

    while (ventana.isOpen()) {
        sf::Event evento;

        while (ventana.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                ventana.close();
            }

            if (evento.type == sf::Event::MouseButtonPressed &&
                evento.mouseButton.button == sf::Mouse::Left &&
                !final) {

                int x = evento.mouseButton.x - MARGEN_X;
                int y = evento.mouseButton.y - MARGEN_Y;

                if (x >= 0 && x < COLUMNAS * TAM &&
                    y >= 0 && y < FILAS * TAM) {

                    int columna = x / TAM;
                    int fila = y / TAM;

                    if (!sistema.esBloqueada(fila, columna)) {
                        if (primera) {
                            final = sistema.iniciarJuego(
                                FILAS, COLUMNAS, MINAS, fila, columna
                            );
                            primera = false;
                        } else {
                            final = sistema.revelarCasilla(fila, columna);
                        }

                        if (!final) {
                            final = sistema.comprobarFinal();
                        }
                    }
                }
            } else if (evento.type == sf::Event::MouseButtonPressed &&
                evento.mouseButton.button == sf::Mouse::Right &&
                !final) {

                int x = evento.mouseButton.x - MARGEN_X;
                int y = evento.mouseButton.y - MARGEN_Y;

                if (x >= 0 && x < COLUMNAS * TAM &&
                    y >= 0 && y < FILAS * TAM) {

                    int columna = x / TAM;
                    int fila = y / TAM;

                    if (!sistema.estaRevelada(fila, columna)) {
                        if (sistema.esBloqueada(fila, columna)) {
                            sistema.setBloqueada(fila, columna, false);
                        } else {
                            sistema.setBloqueada(fila, columna, true);
                        }
                    }
                }
            } else if (evento.type == sf::Event::KeyPressed) {
                if (evento.key.code == sf::Keyboard::R) {
                    sistema.reiniciar();

                    primera = true;
                    final = false;
                }
            }
        }

        ventana.clear(sf::Color(24, 30, 43));

        // Encabezado
        ventana.draw(titulo);
        ventana.draw(subtitulo);

        if (final) {
            estado.setString("Partida terminada");
            estado.setFillColor(sf::Color(255, 125, 115));
        } else {
            estado.setString("Minas: " + std::to_string(MINAS));
            estado.setFillColor(sf::Color(220, 225, 235));
        }

        ventana.draw(estado);

        // Fondo del tablero
        sf::RectangleShape fondo(sf::Vector2f(COLUMNAS * TAM + 4.f, FILAS * TAM + 4.f));
        fondo.setPosition(static_cast<float>(MARGEN_X - 2), static_cast<float>(MARGEN_Y - 2));
        fondo.setFillColor(sf::Color(50, 61, 79));
        ventana.draw(fondo);

        for (int fila = 0; fila < FILAS; fila++) {
            for (int columna = 0; columna < COLUMNAS; columna++) {
                float px = static_cast<float>(MARGEN_X + columna * TAM);
                float py = static_cast<float>(MARGEN_Y + fila * TAM);

                bool revelada = sistema.estaRevelada(fila, columna);
                bool bloqueada = sistema.esBloqueada(fila, columna);

                sf::RectangleShape casilla(sf::Vector2f(TAM - 3.f, TAM - 3.f));
                casilla.setPosition(px + 1.f, py + 1.f);

                if (revelada) {
                    casilla.setFillColor(sf::Color(218, 225, 235));
                } else if (bloqueada) {
                    casilla.setFillColor(sf::Color(255, 50, 50));
                } else {
                    casilla.setFillColor(sf::Color(100, 124, 157));
                }

                ventana.draw(casilla);

                if (revelada && sistema.esBomba(fila, columna)) {
                    sf::CircleShape bomba(10.f);
                    bomba.setFillColor(sf::Color(210, 55, 65));
                    bomba.setPosition(px + 13.f, py + 13.f);
                    ventana.draw(bomba);
                } else if (revelada) {
                    int numero = sistema.getNumero(fila, columna);

                    if (numero > 0) {
                        sf::Text texto(std::to_string(numero), fuente, 23);
                        texto.setStyle(sf::Text::Bold);
                        texto.setFillColor(colorNumero(numero));

                        sf::FloatRect limites = texto.getLocalBounds();

                        texto.setPosition(
                            px + (TAM - limites.width) / 2.f
                                - limites.left,
                            py + (TAM - limites.height) / 2.f
                                - limites.top - 1.f
                        );

                        ventana.draw(texto);
                    }
                }
            }
        }

        ventana.display();
    }

    return 0;
}
