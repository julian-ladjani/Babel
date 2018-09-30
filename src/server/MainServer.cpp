/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** MainServer.cpp
*/

#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <iostream>
#include <src/server/Server.hpp>
#include <src/common/exception/Exception.hpp>
#include <src/common/network/DataPacket.hpp>
#include <src/common/command/CommandName.hpp>

int main(int argc, char *argv[])
{
	babel::common::DataPacket dataPacket;
	babel::common::DataPacket newDataPacket;
	std::string serialized;
	dataPacket.addArg("lol");
	dataPacket.setCommandId
		(babel::common::CommandName::LOGIN);
	dataPacket.addArg("lol");
	dataPacket.addArg("lil");
	serialized = dataPacket.serialize();
	std::cout << serialized << std::endl;
	newDataPacket = babel::common::DataPacket::deserialize(serialized);
	serialized = newDataPacket.serialize();
	std::cout << serialized << std::endl;

	try {
		babel::server::Server server;
		server.start();
	} catch (babel::common::Exception &e) {
		std::cout << e.what() << std::endl;
		return 84;
	}
	return 0;
}