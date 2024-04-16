#include <iostream>
#include <opencv2/opencv.hpp>

int main() {

	cv::VideoCapture webcam(0);

	if (!webcam.isOpened()) {
		std::cerr << "Error: Couldn't take input from webcam." << std::endl;
		return 1;
	}

	cv::namedWindow("webcam", cv::WINDOW_NORMAL);

	while(true) {
		cv::Mat frame;
		webcam >> frame;

		if (frame.empty()) {
			std::cerr << "Error: Couldn't read a frame." << std::endl;
			break;
		}

		cv::imshow("webcam", frame);

		if (cv::waitKey(1) == ' ') { // space
			break;
		}
	}

	webcam.release();
	cv::destroyAllWindows;

    return 0;
}