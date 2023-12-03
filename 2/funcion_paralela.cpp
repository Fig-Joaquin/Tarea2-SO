// Programa usando threads

#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <thread>
#include <vector>

using namespace cv;
using namespace std;
using namespace chrono;

void convertToGrayscaleThreaded(const Mat& input, Mat& output, int startRow, int endRow) {
    for (int i = startRow; i < endRow; ++i) {
        for (int j = 0; j < input.cols; ++j) {
            Vec3b pixel = input.at<Vec3b>(i, j);
            uchar grayValue = 0.299 * pixel[2] + 0.587 * pixel[1] + 0.114 * pixel[0];
            output.at<uchar>(i, j) = grayValue;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Uso: " << argv[0] << " <imagen_a_color> <imagen_gris_salida> <num_hebras>" << endl;
        return -1;
    }

    auto start_time = high_resolution_clock::now();

    Mat image = imread(argv[1], IMREAD_COLOR);

    if (image.empty()) {
        cerr << "Error al cargar la imagen." << endl;
        return -1;
    }

    int rows = image.rows;
    int cols = image.cols;

    Mat grayImageThreaded(rows, cols, CV_8UC1);

    // Número de hilos
    int num_threads = stoi(argv[3]);

    // Vector para almacenar los hilos
    vector<thread> threads;

    // Dividir el trabajo entre los hilos
    int rows_per_thread = rows / num_threads;
    int remaining_rows = rows % num_threads;
    int startRow = 0;

    for (int i = 0; i < num_threads; ++i) {
        int endRow = startRow + rows_per_thread + (i < remaining_rows ? 1 : 0);
        threads.emplace_back(convertToGrayscaleThreaded, ref(image), ref(grayImageThreaded), startRow, endRow);
        startRow = endRow;
    }

    // Esperar a que todos los hilos terminen
    for (auto& thread : threads) {
        thread.join();
    }

    imwrite(argv[2], grayImageThreaded);

    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end_time - start_time);

    cout << "Se ha creado una NuevaImagen en escala de grises (paralela con thread). Tiempo de ejecución: " << duration.count() / 1e6 << " segundos" << endl;

    return 0;
}
