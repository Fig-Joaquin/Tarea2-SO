# Nombre del ejecutable
TARGET = funcion_secuencial.exe

# Archivos fuente
SOURCES = funcion_secuencial.cpp

# Compilador
CXX = g++

# Opciones de compilación
CXXFLAGS = -std=c++17 -Wall -Wextra

# Bibliotecas de OpenCV
LIBS = `pkg-config --cflags --libs opencv4`

# Reglas
all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LIBS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
	rm -f NuevaImagen.png
