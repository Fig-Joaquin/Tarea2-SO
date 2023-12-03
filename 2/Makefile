CC = g++
CFLAGS = -std=c++17 -Wall -Wextra -I/usr/include/opencv4
LIBS = -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs

TARGET = converter

all: $(TARGET)

$(TARGET): funcion_paralela.cpp
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f $(TARGET)
