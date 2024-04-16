#include <iostream>
#include "opencv2/opencv.hpp"

int main() {

    std::string path = "../../images/test.png";
    cv::Mat img = cv::imread(path);
    cv::imshow("Image", img);
    cv::waitKey(3000);

    return 0;
}