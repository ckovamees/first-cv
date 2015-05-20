project(FirstCV)
cmake_minimum_required(VERSION 2.8)

find_package(OpenCV REQUIRED)
find_package(Boost COMPONENTS program_options system filesystem REQUIRED)

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${OpenCV_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#subdirs(src)
set(FirstCV_SRCS rendervideo.cpp scanimage.cpp renderimage.cpp firstgreyscale.cpp basecv.cpp main.cpp)
#qt4_automoc(${FirstCV_SRCS})
add_executable(FirstCV ${FirstCV_SRCS})
target_link_libraries(FirstCV ${OpenCV_LIBS} ${Boost_PROGRAM_OPTIONS_LIBRARY} ${Boost_LIBRARIES} )
install(TARGETS FirstCV RUNTIME DESTINATION bin)
