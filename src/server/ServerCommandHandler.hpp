/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** ServerCommandHandler.hpp
*/

#ifndef CPP_BABEL_2018_SERVERCOMMANDHANDLER_HPP
#define CPP_BABEL_2018_SERVERCOMMANDHANDLER_HPP

#include <map>
#include <src/common/User.hpp>
#include <src/common/command/ACommand.hpp>
#include <src/common/exception/CommandException.hpp>

namespace babel {
	namespace server {
		class ServerCommandHandler {
		public:
			ServerCommandHandler(
				std::vector<babel::common::User> &client);
			bool handleCommand(common::ACommand command,
					   uint32_t userId);
		private:
			std::vector<babel::common::User> &_clients;
			std::map<babel::common::CommandName,
				bool (babel::server::ServerCommandHandler::*)
					(common::ACommand command,
					 uint32_t userId)> _commandHandlers;
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
		};
	}
}

#endif //CPP_BABEL_2018_SERVERCOMMANDHANDLER_HPP
