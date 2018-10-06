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
#include <src/server/ServerCommandHandler.hpp>

namespace babel {
	namespace server {
		class Server {
		public:
			Server();
			int start();
			void addClient(common::User user);
			void removeClient(common::User user);

		private:
			std::vector<babel::common::User> _clients;
			std::vector<std::pair<babel::server::BoostTcpSocket,
				uint32_t>> _sockets;
			ServerCommandHandler _commandHandler;

		};
	}
}


#endif //CPP_BABEL_2018_SERVER_HPP
