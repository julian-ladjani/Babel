/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** MainServer.cpp
*/

#include <src/server/Server.hpp>
#include <src/common/exception/Exception.hpp>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <iostream>
#include "src/common/network/DataPacket.hpp"

int main(int argc, char *argv[])
{
	babel::common::DataPacket dataPacket;
	dataPacket.addArg("lol");
	dataPacket.setCommandId
		(babel::common::DataPacket::CommandName::LOGIN);
	dataPacket.addArg("lol");
	dataPacket.addArg("lil");
	std::cout << dataPacket.serialize() << std::endl;

	try {
		babel::server::Server server;
		server.start();
	} catch (babel::common::Exception &e) {
		std::cout << e.what() << std::endl;
		return 84;
	}
	return 0;
}