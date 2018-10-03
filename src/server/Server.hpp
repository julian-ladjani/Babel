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
#include <map>
#include <src/common/User.hpp>
#include <src/common/command/ACommand.hpp>
#include <src/common/exception/CommandException.hpp>

namespace babel {
	namespace server {
		class Server {
		public:
			Server();
			int start();
			bool handleCommand(common::ACommand command,
					   uint32_t userId);
			void addClient(common::User user);
			void removeClient(common::User user);

		private:
			bool commandLoginHandler(common::ACommand command,
						 uint32_t userId);
			bool commandLogoutHandler(common::ACommand command,
						  uint32_t userId);
			bool commandDeleteHandler(common::ACommand command,
						  uint32_t userId);
			bool commandCallHandler(common::ACommand command,
						uint32_t userId);
			bool commandCallAnswerHandler(common::ACommand command,
						      uint32_t userId);
			bool commandCallEndHandler(common::ACommand command,
						   uint32_t userId);
			bool commandContactHandler(common::ACommand command,
						   uint32_t userId);
			bool commandMessageHandler(common::ACommand command,
						   uint32_t userId);
			void sendToAllClients(common::ACommand command);
			std::vector<babel::common::User> _clients;
			std::map<babel::common::CommandName,
				bool (babel::server::Server::*)(
					common::ACommand command,
					uint32_t userId)> _commandHandler;
		};
	}
}


#endif //CPP_BABEL_2018_SERVER_HPP
