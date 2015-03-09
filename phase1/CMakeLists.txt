cmake_minimum_required(VERSION 2.8)
project( build_dataset )
find_package( OpenCV 2.4 REQUIRED )
add_executable( project1 	main.cpp 
							cvtool.cpp)
target_link_libraries( project1 ${OpenCV_LIBS} )

