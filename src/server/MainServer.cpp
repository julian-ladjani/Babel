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
#include "src/common/network/DataPacket.hpp"
#include "src/common/command/ACommand.hpp"
#include "src/server/network/BoostTcpSocket.hpp"

int main()
{
	babel::common::DataPacket dataPacket;
	babel::common::DataPacket newDataPacket;
	auto info = babel::common::ConnectionInfo(32444, "0.0.0.0");
	babel::server::BoostTcpSocket socket(info);

	std::string serialized;
	dataPacket.addArg("lol");
	dataPacket.setCommandId
		(babel::common::CommandName::CMD_LOGIN);
	dataPacket.addArg("lol");
	dataPacket.addArg("lil");
	serialized = dataPacket.serialize();
	std::cout << serialized << std::endl;
	newDataPacket = babel::common::DataPacket::deserialize(serialized);
	serialized = newDataPacket.serialize();
	std::cout << serialized << std::endl;
	socket.connect();
	socket.send(newDataPacket);
	while (socket.isConnect());

	try {
		babel::common::CommandFactory factory;
		babel::common::DataPacket dataPacket(
			babel::common::CommandName::CMD_LOGIN,
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