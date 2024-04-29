#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>
#include <ctime>

int main() {
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "Failed to open webcam" << std::endl;
        return -1;
    }

    bool flip_vertical = false;
    bool flip_horizontal = false;
    bool grayscale = false;
    bool hsv = false;
    bool lab = false;
    bool blur = false;
    bool median_filter = false;
    bool draw_shape = false;

    while (true) {
        cv::Mat frame;
        cap.read(frame);
        if (frame.empty()) {
            std::cerr << "Failed to capture frame" << std::endl;
            break;
        }

        if (flip_vertical) {
            cv::flip(frame, frame, 0);
        }
        if (flip_horizontal) {
            cv::flip(frame, frame, 1);
        }
        if (grayscale) {
            cv::cvtColor(frame, frame, cv::COLOR_BGR2GRAY);
        }
        if (hsv) {
            cv::cvtColor(frame, frame, cv::COLOR_BGR2HSV);
        }
        if (lab) {
            cv::cvtColor(frame, frame, cv::COLOR_BGR2Lab);
        }
        if (blur) {
            cv::GaussianBlur(frame, frame, cv::Size(7, 7), 1.5);
        }
        if (median_filter) {
            cv::medianBlur(frame, frame, 5);
        }
        if (draw_shape) {
            cv::rectangle(frame, cv::Point(50, 50), cv::Point(200, 200), cv::Scalar(0, 255, 0), 3);
        }

        auto now = std::chrono::system_clock::now();
        auto now_c = std::chrono::system_clock::to_time_t(now);
        std::string current_time = std::ctime(&now_c);
        current_time.pop_back();
        cv::putText(frame, current_time, cv::Point(10, 30), cv::FONT_HERSHEY_SIMPLEX, 0.7, cv::Scalar(0, 0, 255), 2);

        std::string active_effects;
        if (flip_vertical) {
            active_effects += "Flip Vertical, ";
        }
        if (flip_horizontal) {
            active_effects += "Flip Horizontal, ";
        }
        if (grayscale) {
            active_effects += "Grayscale, ";
        }
        if (hsv) {
            active_effects += "HSV, ";
        }
        if (lab) {
            active_effects += "Lab, ";
        }
        if (blur) {
            active_effects += "Gaussian Blur, ";
        }
        if (median_filter) {
            active_effects += "Median Filter, ";
        }
        if (draw_shape) {
            active_effects += "Shape, ";
        }

        if (!active_effects.empty()) {
            active_effects.pop_back(); 
            active_effects.pop_back();
            cv::putText(frame, "Effects: " + active_effects, cv::Point(10, 60), cv::FONT_HERSHEY_SIMPLEX, 0.7, cv::Scalar(0, 255, 0), 2);
        }

        cv::imshow("Webcam", frame);

        int key = cv::waitKey(30);
        if (key == 'q') {
            break; 
        } else if (key == 'v') {
            flip_vertical = !flip_vertical;
        } else if (key == 'h') {
            flip_horizontal = !flip_horizontal;
        } else if (key == 'g') {
            grayscale = !grayscale;
        } else if (key == 's') {
            hsv = !hsv;
        } else if (key == 'l') {
            lab = !lab;
        } else if (key == 'b') {
            blur = !blur;
        } else if (key == 'm') {
            median_filter = !median_filter;
        } else if (key == 'r') {
            draw_shape = !draw_shape;
        }
    }

    cap.release();
    cv::destroyAllWindows();
    return 0;
}