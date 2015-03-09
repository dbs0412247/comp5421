cmake_minimum_required(VERSION 2.8)
project( build_dataset )
find_package( OpenCV 2.4.11 REQUIRED )
add_executable( build_dataset test_opencv.cpp )
target_link_libraries( build_dataset ${OpenCV_LIBS} )

