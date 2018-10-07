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
#include "src/server/SqliteServer.hpp"

int main(int ac, char **av)
{
	try {
		try {
			babel::server::Server server(
				(uint16_t) (ac > 1 ? atoi(av[1]) : 53876));
			server.start();
		} catch (boost::system::system_error const &e) {
			babel::server::Server server(0);
			server.start();
		}
	} catch (babel::common::Exception &e) {
		std::cout << e.what() << std::endl;
		return 84;
	}
	return 0;
}
