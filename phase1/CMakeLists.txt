cmake_minimum_required(VERSION 2.8.11)

project( comp5421-p1 )

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

find_package( 
  OpenCV 2.4.11 REQUIRED 
  Qt5Widgets 
  Qt5Core
)
 
add_executable( project1   
  main.cpp 
  cvtool.cpp
)

target_link_libraries( project1  
  ${OpenCV_LIBS} 
  Qt5::Core
  Qt5::Widgets                                  
)

