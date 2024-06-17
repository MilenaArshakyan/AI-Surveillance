cmake_minimum_required(VERSION 3.10)
project(MeanShift)

find_package(OpenCV REQUIRED)

add_executable(meanShift main.cpp)
target_link_libraries(meanShift ${OpenCV_LIBS})