/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** ServerCommandHandler.hpp
*/

#ifndef CPP_BABEL_2018_SERVERCOMMANDHANDLER_HPP
#define CPP_BABEL_2018_SERVERCOMMANDHANDLER_HPP

#include <map>
#include <utility>
#include <src/common/User.hpp>
#include <src/common/command/ACommand.hpp>
#include <src/common/command/CommandLogin.hpp>
#include <src/common/exception/CommandException.hpp>
#include <src/server/network/BoostTcpSocket.hpp>

namespace babel {
	namespace server {
		class ServerCommandHandler {
		public:
			ServerCommandHandler(
				std::vector<babel::common::User> &client,
				std::vector<std::pair<BoostTcpSocket,
					uint32_t>> &_sockets);
			bool handleCommand(common::ACommand command,
					   uint32_t userId);
		private:
			std::vector<babel::common::User> &_clients;
			std::vector<std::pair<babel::server::BoostTcpSocket,
				uint32_t>> &_sockets;
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
			void sendToAllClients(
				babel::common::DataPacket packet);
			bool CreateUser(common::CommandLogin &cmd,
					uint32_t userId);
			bool ConnectUser(common::User &user, uint32_t userId);
			std::pair<babel::server::BoostTcpSocket,
				uint32_t> &getSocket(uint32_t userId);
			uint32_t getNextId();
			bool sendOk(uint32_t userId, common::CommandName cmd,
				    const std::string &msg);
		};
	}
}

#endif //CPP_BABEL_2018_SERVERCOMMANDHANDLER_HPP
