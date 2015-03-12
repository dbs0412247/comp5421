cmake_minimum_required(VERSION 2.8.11)

project( comp5421-p1 )

find_package( OpenCV 2.4.11 REQUIRED )
find_package( Qt5Core REQUIRED )
find_package( Qt5Widgets REQUIRED)
find_package( Qt5Gui REQUIRED ) 

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

set(PROJECT_SRC_FILES
  main.cpp
  cvtool.cpp
  ui/mainwindow.cpp
)

qt5_wrap_ui( UI_HEADERS
  ui/mainwindow.ui
)

include_directories(${PROJECT_SOURCE_DIR}/ui)
 
add_executable( project1   
  ${PROJECT_SRC_FILES}
  ${UI_HEADERS}
)

target_link_libraries( project1  
  ${OpenCV_LIBS} 
  Qt5::Widgets                                  
)

