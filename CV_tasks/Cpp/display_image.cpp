#include <iostream>
#include <opencv2/opencv.hpp>

int main() {

    std::string path = "/Users/milena/Desktop/images/test.png";
    cv::Mat img = cv::imread(path);

    if (img.empty()) {
        std::cerr << "Error: Could not open or read the image file." << std::endl;
        return 1;
    }

    cv::imshow("Image", img);
    cv::waitKey(3000);

    return 0;
}