cmake_minimum_required(VERSION 3.8)
project(CPP_babel_2018)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/")
set(RUNTIME_OUTPUT_DIRECTORY build)
set(CMAKE_CXX_STANDARD 17)
if (WIN32)
    add_definitions("")
else()
    add_definitions("-fPIC -g -Wextra -Wall")
endif()

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
		src/common/command/CommandError.cpp
		src/common/command/CommandError.hpp
		src/common/command/CommandOk.cpp
		src/common/command/CommandOk.hpp
		src/common/command/CommandLogin.hpp
		src/common/command/CommandLogin.cpp
		src/common/command/CommandLoginOk.cpp
		src/common/command/CommandLoginOk.hpp
		src/common/command/CommandLogout.hpp
		src/common/command/CommandLogout.cpp
		src/common/command/CommandDelete.cpp
		src/common/command/CommandDelete.hpp
		src/common/command/CommandUser.hpp
		src/common/command/CommandUser.cpp
		src/common/command/CommandUserState.cpp
		src/common/command/CommandUserState.hpp
		src/common/command/CommandCall.cpp
		src/common/command/CommandCall.hpp
		src/common/command/CommandCallAnswer.cpp
		src/common/command/CommandCallAnswer.hpp
		src/common/command/CommandCallEnd.cpp
		src/common/command/CommandCallEnd.hpp
        src/common/command/CommandContact.cpp
        src/common/command/CommandContact.hpp
		src/common/command/CommandMessage.cpp
		src/common/command/CommandMessage.hpp
		src/common/command/CommandPing.cpp
		src/common/command/CommandPing.hpp
		src/common/command/CommandPong.cpp
		src/common/command/CommandPong.hpp)

set(CLIENT
		src/client/Babel.cpp
		src/client/Babel.hpp
		src/client/ClientInfo.cpp
		src/client/ClientInfo.hpp
		src/client/CommandHandler.cpp
		src/client/CommandHandler.hpp
		src/client/gui/components/Button.cpp
		src/client/gui/components/Button.hpp
		src/client/gui/components/GroupBox.cpp
		src/client/gui/components/GroupBox.hpp
		src/client/gui/components/Image.cpp
		src/client/gui/components/Image.hpp
		src/client/gui/components/Input.cpp
		src/client/gui/components/Input.hpp
		src/client/gui/components/Label.cpp
		src/client/gui/components/Label.hpp
		src/client/gui/components/ListWidget.cpp
		src/client/gui/components/ListWidget.hpp
		src/client/gui/components/Size.cpp
		src/client/gui/components/Size.hpp
		src/client/gui/components/Style.cpp
		src/client/gui/components/Style.hpp
		src/client/gui/components/StyleManager.cpp
		src/client/gui/components/StyleManager.hpp
		src/client/gui/components/TMicro.cpp
		src/client/gui/components/TMicro.hpp
		src/client/gui/MainWindow.cpp
		src/client/gui/MainWindow.hpp
		src/client/gui/pages/ABabelPage.cpp
		src/client/gui/pages/ABabelPage.hpp
		src/client/gui/pages/ConnectionPage.cpp
		src/client/gui/pages/ConnectionPage.hpp
		src/client/gui/pages/EchoSoundTestServicePage.cpp
		src/client/gui/pages/EchoSoundTestServicePage.hpp
		src/client/gui/pages/MainPage.cpp
		src/client/gui/pages/MainPage.hpp
		src/client/gui/pages/PageManager.cpp
		src/client/gui/pages/PageManager.hpp
        	src/client/network/QtTcpSocket.cpp
        	src/client/network/QtTcpSocket.hpp
		src/client/gui/components/TConversation.cpp
		src/client/gui/components/TConversation.hpp
		src/client/sound/AudioEncoder.cpp
		src/client/sound/AudioEncoder.hpp
		src/client/sound/AudioManager.cpp
		src/client/sound/AudioManager.hpp)

set(SERVER
        src/server/Server.cpp
        src/server/Server.hpp
        src/server/ServerCommandHandler.cpp
		src/server/ServerCommandHandler.hpp
        src/server/network/BoostTcpSocket.cpp
        src/server/network/BoostTcpSocket.hpp)

add_executable(babel_client src/client/MainClient.cpp ${CLIENT} ${COMMON})

add_executable(babel_server src/server/MainServer.cpp ${SERVER} ${COMMON})

find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Network CONFIG REQUIRED)
find_package(Qt5Core CONFIG REQUIRED)
find_package(Qt5Gui CONFIG REQUIRED)
find_package(portaudio REQUIRED)
find_package(Boost REQUIRED)

target_link_libraries(babel_server boost_system Threads::Threads)
target_link_libraries(babel_client Qt5::Widgets Qt5::Network Qt5::Core Qt5::Gui)
target_link_libraries(babel_client Threads::Threads opus)
if (WIN32)
    target_link_libraries(babel_client portaudio_x64)
else()
    target_link_libraries(babel_client portaudio)
endif()

if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
	target_link_libraries(babel_client jack asound)
endif()

#if bug serverPropertiesSwitcher
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/bin/qt.conf "[Paths]\nPrefix = ")
file(APPEND ${CMAKE_CURRENT_BINARY_DIR}/bin/qt.conf ${CONAN_QT_ROOT})
