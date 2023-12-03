#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>

using namespace cv;
using namespace std;
using namespace chrono;

int main(int argc, char** argv) {
    // Verificar si se proporcionan suficientes argumentos
    if (argc != 4) {
        cerr << "Uso: " << argv[0] << " <nombre_imagen_a_color> <nombre_imagen_escala_de_grises> <escala_de_grises>" << endl;
        return -1;
    }

    // Capturar el tiempo de inicio
    auto start_time = high_resolution_clock::now();

    // Leer la imagen a color
    Mat image = imread(argv[1], IMREAD_COLOR);

    // Verificar si la imagen se cargó correctamente
    if (image.empty()) {
        cerr << "Error al cargar la imagen a color. Intentar con otra imagen." << endl;
        return -1;
    }

    // Obtener dimensiones de la imagen
    int rows = image.rows;
    int cols = image.cols;

    // Crear la imagen en escala de grises
    Mat grayImage(rows, cols, CV_8UC1);

    // Obtener el factor de escala de grises del tercer argumento
    double grayscaleFactor = stod(argv[3]);

    // Convertir a escala de grises utilizando el método de luminosidad y el factor proporcionado
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            Vec3b pixel = image.at<Vec3b>(i, j);
            uchar grayValue = grayscaleFactor * pixel[2] + grayscaleFactor * pixel[1] + grayscaleFactor * pixel[0];
            grayImage.at<uchar>(i, j) = grayValue;
        }
    }

    // Guardar la imagen en escala de grises
    imwrite(argv[2], grayImage);

    // Capturar el tiempo de finalización
    auto end_time = high_resolution_clock::now();

    // Calcular la duración en segundos
    auto duration = duration_cast<seconds>(end_time - start_time);

    cout << "Se ha creado una nueva imagen en escala de grises con factor " << grayscaleFactor << ". El tiempo de ejecución ha sido: " << duration.count() << " segundos" << endl;

    return 0;
}
