#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    cv::Mat image = cv::imread("../images/test.webp");

    if (image.empty()) {
        std::cerr << "Error: Couldn't load the image." << std::endl;
        return -1;
    }

    //---resizing---
    cv::Mat resized_image;
    cv::resize(image, resized_image, cv::Size(400, 300));
    cv::imshow("Resized Image", resized_image);
    cv::waitKey(0);
    cv::destroyAllWindows();
    cv::imwrite("resized_image.jpg", resized_image);

    //flipping vertical
    cv::Mat flipped_vertical;
    cv::flip(image, flipped_vertical, 0);
    cv::imshow("Flipped Vertical Image", flipped_vertical);
    cv::waitKey(0);
    cv::destroyAllWindows();
    cv::imwrite("flipped_vertical_image.jpg", flipped_vertical);

    //flipping horizontal
    cv::Mat flipped_horizontal;
    cv::flip(image, flipped_horizontal, 1);
    cv::imshow("Flipped Horizontal Image", flipped_horizontal);
    cv::waitKey(0);
    cv::destroyAllWindows();
    cv::imwrite("flipped_horizontal_image.jpg", flipped_horizontal);

    //cropping
    cv::Rect roi(100, 100, 40, 40);
    cv::Mat cropped_image = image(roi);
    cv::imshow("Original Image", image);
    cv::waitKey(0);
    cv::imshow("Cropped Image", cropped_image);
    cv::waitKey(0);
    cv::imwrite("cropped_image.jpg", cropped_image);
    cv::destroyAllWindows();

    //rotating
    double angle = 45;
    cv::Point2f center(image.cols / 2.0, image.rows / 2.0);
    cv::Mat rotation_matrix = cv::getRotationMatrix2D(center, angle, 1.0);
    cv::Mat rotated_image;
    cv::warpAffine(image, rotated_image, rotation_matrix, image.size()); 
    cv::imshow("Rotated Image", rotated_image);
    cv::waitKey(0);
    cv::destroyAllWindows();
    cv::imwrite("rotated_image.jpg", rotated_image);

    return 0;
}
