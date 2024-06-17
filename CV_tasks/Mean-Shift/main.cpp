#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open camera" << std::endl;
        return -1;
    }

    cv::Mat frame;
    cap >> frame;
    if (frame.empty()) {
        std::cerr << "Error: Could not read frame" << std::endl;
        return -1;
    }

    cv::Rect2d roi = cv::selectROI("Select ROI", frame);

    if (roi.width == 0 || roi.height == 0) {
        std::cerr << "Error: No ROI selected" << std::endl;
        return -1;
    }

    cv::Mat hsv_roi, mask;
    cv::cvtColor(frame(roi), hsv_roi, cv::COLOR_BGR2HSV);

    int histSize[] = { 180 }; 
    float range[] = { 0, 180 };
    const float* ranges[] = { range };
    cv::Mat roi_hist;

    cv::inRange(hsv_roi, cv::Scalar(0, 30, 60), cv::Scalar(180, 255, 255), mask);

    int channels[] = { 0 };
    cv::calcHist(&hsv_roi, 1, channels, mask, roi_hist, 1, histSize, ranges);
    cv::normalize(roi_hist, roi_hist, 0, 255, cv::NORM_MINMAX);

    cv::TermCriteria term_crit(cv::TermCriteria::EPS | cv::TermCriteria::COUNT, 10, 1);

    while (true) {
        cap >> frame;
        if (frame.empty())
            break;

        cv::Mat hsv, dst;
        cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV);

        cv::calcBackProject(&hsv, 1, channels, roi_hist, dst, ranges);

        cv::Rect roi_int(roi);

        cv::meanShift(dst, roi_int, term_crit);

        roi = roi_int;

        cv::rectangle(frame, roi, cv::Scalar(0, 255, 0), 2);

        cv::imshow("Tracking", frame);

        char c = (char)cv::waitKey(30);
        if (c == 27) 
            break;
    }

    return 0;
}
