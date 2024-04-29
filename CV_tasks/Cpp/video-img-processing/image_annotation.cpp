#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
	cv::Mat img = cv::imread("../images/test.webp");

	if (img.empty()) {
		std::cerr << "Error: Could not open or read the image file." << std::endl;
		return 1;
	}

	std::string text = "text";
    cv::Point point(40, 40);
    int font = cv::FONT_HERSHEY_COMPLEX_SMALL;
    double font_size = 1.0;
    cv::Scalar color(45, 120, 165);
    int thickness = 2;
	cv::putText(img, text, point, font, font_size, color, thickness);

    cv::Point center(60, 40);
	int radius = 40;
	cv::circle(img, center, radius, color, thickness);

    cv::Point top_left_point(50, 100);
    cv::Point bottom_right_point(100, 200);
	cv::rectangle(img, top_left_point, bottom_right_point, color, thickness);

	cv::line(image, line_start, line_end, line_color, thickness);

    cv::Point rect_top_left(100, 150);
    cv::Point rect_bottom_right(300, 300);
    cv::Scalar rect_color(255, 0, 0);

	cv::imshow("Image", img);
	cv::waitKey(0);
	cv::destroyAllWindows();
}