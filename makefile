CXX = g++
CXXFLAGS = -Wall -std=c++17 -g
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

TARGET = buscaminas

OBJ_DIR = modelo/obj
INCLUDE_DIR = modelo/includes
SRC_DIR = modelo/src
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/sistema.o $(OBJ_DIR)/tablero.o $(OBJ_DIR)/casilla.o

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(SFML_LIBS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/main.o: main.cpp $(INCLUDE_DIR)/sistema.h $(INCLUDE_DIR)/tablero.h $(INCLUDE_DIR)/casilla.h | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c main.cpp -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/sistema.o: $(SRC_DIR)/sistema.cpp $(INCLUDE_DIR)/sistema.h $(INCLUDE_DIR)/tablero.h | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/sistema.cpp -o $(OBJ_DIR)/sistema.o

$(OBJ_DIR)/tablero.o: $(SRC_DIR)/tablero.cpp $(INCLUDE_DIR)/tablero.h $(INCLUDE_DIR)/casilla.h | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/tablero.cpp -o $(OBJ_DIR)/tablero.o

$(OBJ_DIR)/casilla.o: $(SRC_DIR)/casilla.cpp $(INCLUDE_DIR)/casilla.h | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/casilla.cpp -o $(OBJ_DIR)/casilla.o

clean:
	rm -rf modelo/obj $(TARGET)
