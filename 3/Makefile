CC = g++
CFLAGS = -std=c++17 -Wall -Wextra -fopenmp
LIBS = -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs
INCLUDES = -I/usr/include/opencv4

TARGET = converterOpenMP

all: $(TARGET)

$(TARGET): ProgramaParalelo_Openmp.cpp
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS) $(INCLUDES)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
