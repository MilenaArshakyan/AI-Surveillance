#include <opencv2/opencv.hpp>

int main() {
    cv::CascadeClassifier faceCascade;
    faceCascade.load(cv::samples::findFile("../haarcascade_frontalface_alt.xml"));

    if (faceCascade.empty()) {
        std::cerr << "Error loading face cascade\n";
        return -1;
    }

    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "Error opening webcam\n";
        return -1;
    }

    while (true) {
        cv::Mat frame;
        cap >> frame;

        if (frame.empty()) {
            std::cerr << "Error reading frame\n";
            break;
        }

        cv::Mat grayFrame;
        cv::cvtColor(frame, grayFrame, cv::COLOR_BGR2GRAY);

        std::vector<cv::Rect> faces;
        faceCascade.detectMultiScale(grayFrame, faces);

        for (const auto& face : faces) {
            cv::rectangle(frame, face, cv::Scalar(0, 255, 0), 2);
        }

        cv::imshow("Face Detection", frame);

        if (cv::waitKey(10) == 'q') {
            break;
        }
    }

    cap.release();
    cv::destroyAllWindows();

    return 0;
}