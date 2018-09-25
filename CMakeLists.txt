cmake_minimum_required(VERSION 3.5)
project(CPP_babel_2018)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/")
set(RUNTIME_OUTPUT_DIRECTORY build)
set(CMAKE_CXX_STANDARD 11)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
conan_basic_setup(KEEP_RPATHS)

set(COMMON
        src/common/User.cpp
        src/common/User.hpp
        src/common/ConnectionInfo.hpp
        src/common/ConnectionInfo.cpp
        src/common/network/ITcpSocket.h
        src/common/network/IUdpSocket.h)

set(CLIENT
        src/client/windows/Window.cpp
        src/client/windows/Window.hpp
		src/client/Components/Button.cpp
        src/client/Components/Button.hpp
        src/client/ClientInfo.hpp
        src/client/ClientInfo.cpp
		src/client/sound/AudioManager.cpp
		src/client/sound/AudioManager.hpp)

set(SERVER
        src/server/Server.cpp
        src/server/Server.hpp)

add_executable(babel_client src/client/MainClient.cpp ${CLIENT} ${COMMON})

add_executable(babel_server src/server/MainServer.cpp ${SERVER} ${COMMON})

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)

target_link_libraries(babel_client Qt5::Widgets Qt5::Network pthread portaudio)
if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    target_link_libraries(babel_client jack asound)
endif()

file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/bin/qt.conf "[Paths]\nPrefix = ")
file(APPEND ${CMAKE_CURRENT_BINARY_DIR}/bin/qt.conf ${CONAN_QT_ROOT})
