// Programa con OPENMP

#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <omp.h>

using namespace std;
using namespace chrono;

void convertToGrayscaleOpenMP(uchar* input, uchar* output, int rows, int cols) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int index = (i * cols + j) * 3;
            uchar blue = input[index];
            uchar green = input[index + 1];
            uchar red = input[index + 2];

            uchar grayValue = static_cast<uchar>(0.299 * red + 0.587 * green + 0.114 * blue);

            output[i * cols + j] = grayValue;
        }
    }
}

int main() {
    // Capturar el tiempo de inicio
    auto start_time = high_resolution_clock::now();

    // Solicitar al usuario el nombre de la imagen a convertir
    string input_filename;
    cout << "Ingrese el nombre de la imagen a convertir: ";
    cin >> input_filename;

    cv::Mat image = cv::imread(input_filename, cv::IMREAD_COLOR);

    if (!image.data) {
        cerr << "Error al cargar la imagen." << endl;
        return -1;
    }

    int rows = image.rows;
    int cols = image.cols;

    uchar* input_data = image.data;
    uchar* output_data = new uchar[rows * cols];

    // Número de hilos
    int num_threads;
    cout << "Ingrese el número de hebras a utilizar: ";
    cin >> num_threads;

    // Configurar el número de hilos
    omp_set_num_threads(num_threads);

    convertToGrayscaleOpenMP(input_data, output_data, rows, cols);

    cv::Mat grayImage(rows, cols, CV_8UC1, output_data);

    // Solicitar al usuario el nombre de la imagen de salida
    string output_filename;
    cout << "Ingrese el nombre de la imagen de salida: ";
    cin >> output_filename;

    cv::imwrite(output_filename, grayImage);

    delete[] output_data;

    // Capturar el tiempo de finalización
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end_time - start_time);

    cout << "Se ha creado una NuevaImagen en escala de grises (paralela con OpenMP). Tiempo de ejecución: " << duration.count() / 1e6 << " segundos" << endl;

    return 0;
}
