cmake_minimum_required(VERSION 2.8)

project(cell_aut)
find_package(OpenCV REQUIRED)

set(SOURCES 
    src/rule_bin.cpp
    src/rule_tct.cpp
    src/rule_cont.cpp
    src/rule_2d.cpp
    src/visualizer.cpp)
include_directories(cell_aut "include/" ${OpenCV_INCLUDE_DIRS})

add_executable(cell_single src/main_single.cpp ${SOURCES})
target_link_libraries(cell_single LINK_PUBLIC ${OpenCV_LIBS})

add_executable(cell_all src/main_all_tct.cpp ${SOURCES})
target_link_libraries(cell_all LINK_PUBLIC ${OpenCV_LIBS})

add_executable(cell_cont src/main_cont.cpp ${SOURCES})
target_link_libraries(cell_cont LINK_PUBLIC ${OpenCV_LIBS})

add_executable(cell_2d src/main_2d.cpp ${SOURCES})
target_link_libraries(cell_2d LINK_PUBLIC ${OpenCV_LIBS})