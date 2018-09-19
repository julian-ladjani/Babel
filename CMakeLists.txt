cmake_minimum_required(VERSION 3.10)
project(CPP_babel_2018)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/")
set(CMAKE_CXX_STANDARD 11)

set(COMMON
        src/common/User.cpp
        src/common/User.hpp
        src/common/ConnectionInfos.hpp
        src/common/ConnectionInfos.cpp
        )

set(CLIENT
        src/client/windows/Window.cpp
        src/client/windows/Window.hpp
        )

set(SERVER
        )

add_executable(babel_client src/client/main_client.cpp ${CLIENT} ${COMMON})

add_executable(babel_server src/server/main_server.cpp ${SERVER} ${COMMON})

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Widgets CONFIG REQUIRED)
target_link_libraries(babel_client Qt5::Widgets)