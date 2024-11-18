cmake_minimum_required(VERSION 3.10)
project(YOLODetection)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable target
add_executable(yolo_detection yolo_main.cpp)

# Link OpenCV libraries
target_link_libraries(yolo_detection ${OpenCV_LIBS})