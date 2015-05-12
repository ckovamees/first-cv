project(FirstCV)
cmake_minimum_required(VERSION 2.8)

find_package(OpenCV REQUIRED)

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${OpenCV_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(FirstCV_SRCS renderimage.cpp firstgreyscale.cpp firstcv.cpp main.cpp)
#qt4_automoc(${FirstCV_SRCS})
add_executable(FirstCV ${FirstCV_SRCS})
target_link_libraries(FirstCV ${OpenCV_LIBS})
install(TARGETS FirstCV RUNTIME DESTINATION bin)
