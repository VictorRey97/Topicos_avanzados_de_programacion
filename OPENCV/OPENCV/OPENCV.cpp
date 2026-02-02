#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    VideoCapture cap(0, CAP_DSHOW); // Windows: CAP_DSHOW suele funcionar mejor
    if (!cap.isOpened()) {
        cout << "No se pudo abrir la camara" << endl;
        return -1;
    }

    Mat frame, frame_gray;

    cout << "Presiona ESC para salir..." << endl;

    while (true) {
        bool ok = cap.read(frame);
        if (!ok || frame.empty()) continue;

        cvtColor(frame, frame_gray, COLOR_BGR2GRAY);

        imshow("Camara - Color", frame);
        imshow("Camara - Gris", frame_gray);

        int key = waitKey(30);
        if (key == 27) break; // ESC
    }

    cap.release();
    destroyAllWindows();
    return 0;
}
