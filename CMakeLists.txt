cmake_minimum_required(VERSION 3.10)
project(CPP_babel_2018)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/")
set(CMAKE_CXX_STANDARD 11)

add_executable(babel src/main.cpp src/client/windows/Window.cpp src/client/windows/Window.hpp)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Widgets CONFIG REQUIRED)
target_link_libraries(babel Qt5::Widgets)