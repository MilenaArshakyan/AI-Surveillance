cmake_minimum_required(VERSION 3.10)
project(YOLOv8FaceDetection)

find_package(OpenCV REQUIRED)

add_executable(detection main.cpp)
target_link_libraries(detection ${OpenCV_LIBS})