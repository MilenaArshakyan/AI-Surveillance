#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    cv::Mat img = cv::imread("../images/test.webp");
    if (img.empty()) {
        std::cerr << "Error: Could not open or read the image file." << std::endl;
        return 1;
    }

    cv::Mat img_rgb, img_hsv, img_lab, img_gray;
    cv::cvtColor(img, img_rgb, cv::COLOR_BGR2RGB);
    cv::cvtColor(img, img_hsv, cv::COLOR_BGR2HSV);
    cv::cvtColor(img, img_lab, cv::COLOR_BGR2Lab);
    cv::cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);

    cv::Mat img_blurr;
    cv::GaussianBlur(img, img_blurr, cv::Size(7, 7), 1.5);

    cv::Mat img_sharpened;
    cv::Mat kernel = (cv::Mat_<float>(3, 3) <<
        -1, -1, -1,
        -1, 9, -1,
        -1, -1, -1);
    cv::filter2D(img, img_sharpened, -1, kernel);

    cv::Mat img_median_filtered;
    cv::medianBlur(img, img_median_filtered, 5);

    cv::imshow("Original Image", img);
    cv::imshow("RGB Image", img_rgb);
    cv::imshow("HSV Image", img_hsv);
    cv::imshow("Lab Image", img_lab);
    cv::imshow("Grayscale Image", img_gray);
    cv::imshow("Gaussian Blur", img_blurr);
    cv::imshow("Sharpened Image", img_sharpened);
    cv::imshow("Median Filtered", img_median_filtered);

    cv::imwrite("image_rgb.jpg", img_rgb);
    cv::imwrite("image_hsv.jpg", img_hsv);
    cv::imwrite("image_lab.jpg", img_lab);
    cv::imwrite("image_gray.jpg", img_gray);
    cv::imwrite("image_blurred.jpg", img_blurr);
    cv::imwrite("image_sharpened.jpg", img_sharpened);
    cv::imwrite("image_median_filtered.jpg", img_median_filtered);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}