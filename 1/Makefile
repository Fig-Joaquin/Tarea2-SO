CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
LIBS = -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs

TARGET = funcion_secuencial
SRC = funcion_secuencial.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -I /usr/include/opencv4 $< -o $@ $(LIBS)

clean:
	rm -f $(TARGET)

.PHONY: all clean
