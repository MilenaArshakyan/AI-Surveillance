#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    cv::Mat image = cv::imread("/Users/milena/Desktop/images/test.png");

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

    //flipping
    // cv::Mat flipped_vertical;
    // cv::flip(image, flipped_vertical, 0);

    // cv::imshow("Flipped Vertical Image", flipped_vertical);
    // cv::waitKey(0);
    // cv::destroyAllWindows();

    // cv::imwrite("flipped_vertical_image.jpg", flipped_vertical);

    // cv::Mat flipped_horizontal;
    // cv::flip(image, flipped_horizontal, 1);

    // cv::imshow("Flipped Horizontal Image", flipped_horizontal);
    // cv::waitKey(0);
    // cv::destroyAllWindows();

    // cv::imwrite("flipped_horizontal_image.jpg", flipped_horizontal);


    //cropping

    //rotating

   

    return 0;
}
