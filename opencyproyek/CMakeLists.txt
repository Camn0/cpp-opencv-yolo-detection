cmake_minimum_required(VERSION 3.10)
project(ObjectDetection)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable target (the program name is object_detection)
add_executable(object_detection main.cpp)

# Link the OpenCV libraries to the project
target_link_libraries(object_detection ${OpenCV_LIBS})