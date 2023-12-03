# Variables
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I /usr/include/opencv4
LDFLAGS = -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs

# Objetivo predeterminado
all: funcion_secuencial

# Regla de compilación
funcion_secuencial: funcion_secuencial.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Regla para limpiar archivos generados
clean:
	rm -f funcion_secuencial NuevaImagen.png

# Regla para ejecutar el programa
run: funcion_secuencial
	./funcion_secuencial
