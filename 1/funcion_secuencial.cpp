#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>

using namespace cv;
using namespace std;
using namespace chrono;

int main() {
    // Capturar el tiempo de inicio
    auto start_time = high_resolution_clock::now();

    // Leer la imagen a color
    Mat image = imread("spider.png", IMREAD_COLOR);

    // Verificar si la imagen se cargó correctamente
    if (image.empty()) {
        cerr << "Un error ha ocurrido. Intentar con otra imagen." << endl;
        return -1;
    }

    // Crear la imagen en escala de grises
    Mat grayImage;

    // Convertir a escala de grises utilizando el método de luminosidad
    cvtColor(image, grayImage, COLOR_BGR2GRAY);

    // Guardar la imagen en escala de grises
    imwrite("NuevaImagen.png", grayImage);

    // Capturar el tiempo de finalización
    auto end_time = high_resolution_clock::now();

    // Calcular la duración en segundos
    auto duration = duration_cast<microseconds>(end_time - start_time);

    cout << "Se ha creado una NuevaImagen con escala de colores gris. El tiempo de ejecución ha sido: 0," << duration.count() << " segundos" << endl;

    return 0;
}



/*
    g++ -std=c++17 -Wall -Wextra -I /usr/include/opencv4 "/home/joaquin/Escritorio/tarea2/1/funcion_secuencial.cpp" -o "/home/joaquin/Escritorio/tarea2/1/funcion_secuencial.exe" -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs

*/