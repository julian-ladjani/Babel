/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Server.hpp
*/

#ifndef CPP_BABEL_2018_SERVER_HPP
#define CPP_BABEL_2018_SERVER_HPP

#include <iostream>
#include <algorithm>
#include <src/common/command/CommandError.hpp>
#include <src/common/command/CommandFactory.hpp>
#include <src/server/ServerCommandHandler.hpp>
#include "src/server/network/TcpServer.hpp"

namespace babel {
	namespace server {
		class Server {
		public:
			Server(uint16_t port = 53876);
			int start();
			void addClient(common::User user);
			void removeClient(common::User user);

		private:
			bool _running;
			common::CommandFactory _cmdFactory;
			std::vector<babel::common::User> _clients;
			TcpServer _tcpServer;
			ServerCommandHandler _commandHandler;
			std::vector<std::pair<babel::server::BoostTcpSocket &,
				int32_t>> _sockets;
			void handleClient(babel::server::BoostTcpSocket &sock,
					  int32_t userId);
		};
	}
}


#endif //CPP_BABEL_2018_SERVER_HPP
