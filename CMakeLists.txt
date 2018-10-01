cmake_minimum_required(VERSION 3.8)
project(CPP_babel_2018)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/")
set(RUNTIME_OUTPUT_DIRECTORY build)
set(CMAKE_CXX_STANDARD 17)
add_definitions("-fPIC -g")

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
set(CMAKE_INCLUDE_CURRENT_DIR TRUE)
set(CMAKE_AUTOMOC TRUE)
set(CMAKE_AUTOUIC TRUE)

include(build/conanbuildinfo.cmake)
include(build/conan_paths.cmake)
conan_basic_setup(KEEP_RPATHS)
include_directories(${CMAKE_INCLUDE_PATH})

set(COMMON
		src/common/User.cpp
		src/common/User.hpp
		src/common/network/ConnectionInfo.hpp
		src/common/network/ConnectionInfo.cpp
		src/common/network/ATcpSocket.hpp
		src/common/network/ATcpSocket.cpp
		src/common/exception/Exception.hpp
		src/common/exception/Exception.cpp
		src/common/exception/CommandException.hpp
		src/common/exception/CommandException.cpp
		src/common/network/DataPacket.cpp
		src/common/network/DataPacket.hpp
		src/common/command/CommandName.hpp
		src/common/command/ACommand.cpp
		src/common/command/ACommand.hpp
		src/common/command/CommandFactory.hpp
		src/common/command/CommandFactory.cpp
		src/common/command/CommandLogin.hpp
		src/common/command/CommandLogin.cpp
		src/common/command/CommandLogout.hpp
		src/common/command/CommandLogout.cpp
		src/common/command/CommandUser.hpp
		src/common/command/CommandUser.cpp)

set(CLIENT
		src/client/gui/MainWindow.cpp
		src/client/gui/MainWindow.hpp
		src/client/gui/components/Button.cpp
		src/client/gui/components/Button.hpp
		src/client/gui/components/CButton.cpp
		src/client/gui/components/CButton.hpp
		src/client/gui/components/Input.cpp
		src/client/gui/components/Input.hpp
		src/client/gui/components/Size.cpp
		src/client/gui/components/Size.hpp
		src/client/gui/components/Image.cpp
		src/client/gui/components/Image.hpp
		src/client/gui/pages/ABabelPage.hpp
		src/client/gui/pages/MainPage.cpp
		src/client/gui/pages/MainPage.hpp
		src/client/gui/pages/PageManager.cpp
		src/client/gui/pages/PageManager.hpp
		src/client/gui/pages/ConnectionPage.cpp
		src/client/gui/pages/ConnectionPage.hpp
		src/client/sound/AudioManager.cpp
		src/client/sound/AudioManager.hpp
		src/client/sound/AudioEncoder.hpp
		src/client/sound/AudioEncoder.cpp
		src/client/ClientInfo.hpp
		src/client/ClientInfo.cpp
		src/client/Babel.cpp
		src/client/Babel.hpp
		src/client/gui/pages/ABabelPage.cpp
		src/client/gui/pages/EchoSoundTestServicePage.cpp
		src/client/gui/pages/EchoSoundTestServicePage.hpp
		src/client/gui/components/Label.cpp
		src/client/gui/components/Label.hpp
		src/client/gui/components/ListWidget.cpp
		src/client/gui/components/ListWidget.hpp
		src/client/gui/components/GroupBox.cpp
		src/client/gui/components/GroupBox.hpp)

set(SERVER
        src/server/Server.cpp
        src/server/Server.hpp src/common/network/BoostTcpSocket.cpp
        src/common/network/BoostTcpSocket.hpp)

add_executable(babel_client src/client/MainClient.cpp ${CLIENT} ${COMMON})

add_executable(babel_server src/server/MainServer.cpp ${SERVER} ${COMMON})

find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Network CONFIG REQUIRED)
find_package(Qt5Core CONFIG REQUIRED)
find_package(Qt5Gui CONFIG REQUIRED)
find_package(Boost REQUIRED)

target_link_libraries(babel_server boost_system)
target_link_libraries(babel_client Qt5::Widgets Qt5::Network Qt5::Core Qt5::Gui)
target_link_libraries(babel_client Threads::Threads portaudio opus)

if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
	target_link_libraries(babel_client jack asound)
endif()

#if bug serverPropertiesSwitcher
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/bin/qt.conf "[Paths]\nPrefix = ")
file(APPEND ${CMAKE_CURRENT_BINARY_DIR}/bin/qt.conf ${CONAN_QT_ROOT})
