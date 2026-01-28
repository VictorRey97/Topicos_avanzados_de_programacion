#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat img = imread("../img/logo.png");  // ojo con la ruta
    if (img.empty()) {
        cout << "No se pudo cargar la imagen" << endl;
        return -1;
    }

    // Convertir a escala de grises
    Mat img_gray;
    cvtColor(img, img_gray, COLOR_BGR2GRAY);

    // Redimensionar
    Mat img_resized;
    resize(img_gray, img_resized, Size(636, 316));

    imshow("Imagen Original", img);
    imshow("Imagen en escala de grises", img_resized);
    waitKey(0);

    return 0;
}
