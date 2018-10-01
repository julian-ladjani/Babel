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
#include <src/common/command/ACommand.hpp>
#include <src/common/command/CommandFactory.hpp>

int main(int argc, char *argv[])
{
	try {
		babel::common::CommandFactory factory;
		babel::common::DataPacket dataPacket(
			babel::common::CommandName::LOGIN,
			{"username", "password"});
		std::unique_ptr<babel::common::ACommand> command
			= factory.deserialize(dataPacket);
		std::cout << dataPacket.serialize() << std::endl;
		std::cout << command->serialize().serialize() << std::endl;

		babel::server::Server server;
		server.start();
	} catch (babel::common::Exception &e) {
		std::cout << e.what() << std::endl;
		return 84;
	}
	return 0;
}