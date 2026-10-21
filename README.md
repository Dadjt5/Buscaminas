# Buscaminas en C++ con SFML

Implementación del clásico **Buscaminas** en C++ utilizando la biblioteca gráfica SFML. El proyecto separa la lógica del juego de su representación gráfica, permitiendo gestionar el tablero, las casillas, las minas y las interacciones del jugador.

## Características

- Tablero de 8 × 8 casillas.
- 10 minas distribuidas aleatoriamente.
- Primer clic seguro: la primera casilla seleccionada no contiene una mina y se evita colocar minas en su entorno inmediato.
- Revelado de casillas y expansión automática de las casillas vacías.
- Números que indican cuántas minas hay alrededor de cada casilla.
- Marcado y desmarcado de casillas mediante el botón derecho del ratón.
- Detección del final de la partida.
- Reinicio de la partida mediante el teclado.
- Interfaz gráfica personalizada con SFML.

## Controles

| Acción | Control |
|---|---|
| Revelar una casilla | Clic izquierdo |
| Marcar o desmarcar una casilla | Clic derecho |
| Reiniciar la partida | Tecla `R` |
| Cerrar el juego | Cerrar la ventana |

## Tecnologías utilizadas

- **C++17**
- **SFML** para la ventana, los gráficos, los textos y los eventos.
- **Make** para automatizar la compilación.
- **g++** como compilador de C++.

## Estructura del proyecto

```text
buscaminas/
├── assets/
│   └── DejaVuSans.ttf       # Recurso local, no incluido en el repositorio
├── modelo/
│   ├── includes/            # Archivos de cabecera
│   ├── src/                 # Implementación de las clases
│   └── obj/                 # Archivos objeto generados al compilar
├── main.cpp                 # Interfaz gráfica y bucle principal
├── Makefile                 # Reglas de compilación
├── .gitignore
└── README.md
```

La estructura puede variar ligeramente según la configuración local del proyecto.

## Requisitos

Antes de compilar, necesitas:

- Un compilador compatible con C++17, como `g++`.
- GNU Make.
- SFML instalada y compatible con la versión utilizada por el código.
- Una fuente TrueType para mostrar los textos de la interfaz.

### Instalar las dependencias en Ubuntu

Si utilizas Ubuntu o una distribución basada en Debian, puedes instalar las herramientas necesarias con:

```bash
sudo apt update
sudo apt install build-essential libsfml-dev fonts-dejavu-core
```

**Nota:** comprueba la versión de SFML instalada. El código debe utilizar una API compatible con esa versión; SFML 2 y SFML 3 presentan diferencias en la gestión de eventos y otras interfaces.

## Fuente de texto

Por motivos relacionados con el tamaño del repositorio y la distribución de recursos, el archivo `DejaVuSans.ttf` no está incluido.

La interfaz espera encontrar la fuente en esta ruta relativa al directorio desde el que se ejecuta el programa:

```text
assets/DejaVuSans.ttf
```

Tienes dos opciones:

### Opción 1: utilizar DejaVu Sans

En Ubuntu, instala el paquete de fuentes:

```bash
sudo apt install fonts-dejavu-core
```

Crea la carpeta de recursos y copia la fuente al proyecto:

```bash
mkdir -p assets
cp /usr/share/fonts/truetype/dejavu/DejaVuSans.ttf assets/
```

La fuente quedará en la ubicación que espera el programa. El archivo se mantiene local y no necesitas añadirlo al repositorio.

Si la fuente no está en esa ruta en tu distribución, puedes localizarla con:

```bash
fc-match -f '%{file}\n' DejaVuSans
```

Comprueba que el resultado corresponde al archivo de fuente deseado antes de copiarlo.

### Opción 2: utilizar otra fuente

Puedes utilizar otra fuente TrueType (`.ttf`) que tengas permiso para usar y redistribuir, si corresponde.

1. Crea la carpeta `assets/`.
2. Copia la fuente elegida dentro de ella.
3. Actualiza la ruta de `loadFromFile()` en `main.cpp` para que coincida con el nombre del archivo.

Por ejemplo:

```cpp
sf::Font fuente;

if (!fuente.loadFromFile("assets/MiFuente.ttf")) {
    std::cerr << "No se pudo cargar la fuente.\n";
    return 1;
}
```

Si tu versión de SFML utiliza una API diferente para cargar fuentes, adapta esa llamada a la versión instalada.

## 🔨 Compilación

Desde la raíz del repositorio, ejecuta:

```bash
make
```

Para borrar los archivos generados y compilar de nuevo:

```bash
make clean
make
```

Si la compilación termina correctamente, ejecuta el juego desde la raíz del proyecto:

```bash
./buscaminas
```

Es importante ejecutarlo desde el directorio raíz si las rutas de los recursos son relativas, como `assets/DejaVuSans.ttf`.

## Organización del código

El proyecto separa la lógica del juego de la interfaz gráfica:

- **`Casilla`**: representa una casilla del tablero y almacena su estado, si contiene una mina, su número de minas adyacentes y si está revelada o marcada.
- **`Tablero`**: gestiona la matriz de casillas, la colocación de minas, el cálculo de los números y la lógica de revelado.
- **`Sistema`**: coordina el estado de la partida y las operaciones sobre el tablero.
- **`main.cpp`**: gestiona la ventana de SFML, los eventos del ratón y el teclado, y el dibujo de los elementos gráficos.

Esta separación facilita el mantenimiento del código y permite modificar la interfaz sin tener que concentrar toda la lógica del juego en el bucle principal.

## Posibles mejoras futuras

- Mostrar un contador de minas restantes.
- Añadir una pantalla de victoria y otra de derrota.
- Mejorar el diseño de las banderas y las minas.
- Añadir un botón de reinicio en la interfaz.
- Incorporar distintos niveles de dificultad.
- Guardar récords y tiempos de las partidas.
- Mejorar a una version pvp.

## Licencia

Este proyecto es de carácter educativo y personal.
Los recursos externos, como las fuentes, conservan sus propias licencias y condiciones de uso.

---

**Proyecto desarrollado en C++ con SFML como ejercicio de programación y desarrollo de interfaces gráficas.**
