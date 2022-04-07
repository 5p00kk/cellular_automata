cmake_minimum_required(VERSION 2.8)

project(cell_aut)
find_package(OpenCV REQUIRED)

file(GLOB SOURCES src/*.cpp)
include_directories(cell_aut "include/" ${OpenCV_INCLUDE_DIRS})

add_executable(cell_aut ${SOURCES})
target_link_libraries(cell_aut LINK_PUBLIC ${OpenCV_LIBS})