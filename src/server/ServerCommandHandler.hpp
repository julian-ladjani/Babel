/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandHandler.hpp
*/

#ifndef CPP_BABEL_2018_SERVERCOMMANDHANDLER_HPP
#define CPP_BABEL_2018_SERVERCOMMANDHANDLER_HPP

#include <map>
#include <utility>
#include <iostream>
#include <src/common/User.hpp>
#include <src/common/command/ACommand.hpp>
#include <src/common/command/CommandOk.hpp>
#include <src/common/command/CommandLogin.hpp>
#include <src/common/command/CommandLoginOk.hpp>
#include <src/common/command/CommandUser.hpp>
#include <src/common/command/CommandUserState.hpp>
#include <src/common/command/CommandContact.hpp>
#include <src/common/command/CommandCall.hpp>
#include <src/common/command/CommandCallAnswer.hpp>
#include <src/common/command/CommandCallEnd.hpp>
#include <src/common/command/CommandMessage.hpp>
#include <src/common/command/CommandPong.hpp>
#include <src/common/exception/CommandException.hpp>
#include <src/server/network/BoostTcpSocket.hpp>
#include "src/server/SqliteServer.hpp"

namespace babel {
	namespace server {
		class ServerCommandHandler {
		public:
			ServerCommandHandler(
				std::vector<babel::common::User> &client,
				std::vector<
					babel::server::BoostTcpSocket::pointer>
				&_sockets,
				SqliteServer &_sqliteServer);
			bool handleCommand(
				std::unique_ptr<common::ACommand> &command,
				uint32_t userId);
		private:
			std::vector<babel::common::User> &_clients;
			std::vector<babel::server::BoostTcpSocket::pointer>
				&_sockets;
			SqliteServer &_sqliteServer;
			std::map<babel::common::CommandName,
				bool (babel::server::ServerCommandHandler::*)
					(std::unique_ptr<common::ACommand> &
					command,
					 uint32_t userId)> _commandHandlers;
			void printCommand(
				std::unique_ptr<common::ACommand> &cmd,
				int32_t userId) const;
			bool commandLoginHandler(
				std::unique_ptr<common::ACommand> &command,
				uint32_t userId);
			bool commandLogoutHandler(
				std::unique_ptr<common::ACommand> &command,
				uint32_t userId);
			bool commandDeleteHandler(
				std::unique_ptr<common::ACommand> &command,
				uint32_t userId);
			bool commandCallHandler(
				std::unique_ptr<common::ACommand> &command,
				uint32_t userId);
			bool commandCallAnswerHandler(
				std::unique_ptr<common::ACommand> &command,
				uint32_t userId);
			bool commandCallEndHandler(
				std::unique_ptr<common::ACommand> &command,
				uint32_t userId);
			bool commandContactHandler(
				std::unique_ptr<common::ACommand> &command,
				uint32_t userId);
			bool commandMessageHandler(
				std::unique_ptr<common::ACommand> &command,
				uint32_t userId);
			bool commandPingHandler(
				std::unique_ptr<common::ACommand> &command,
				uint32_t userId);
			bool commandPongHandler(
				std::unique_ptr<common::ACommand> &command,
				uint32_t userId);
			void sendToAllClients(
				babel::common::DataPacket packet);
			bool createUser(common::CommandLogin &cmd,
					uint32_t userId);
			bool connectUser(common::User &user, uint32_t userId);
			void disconnectUser(uint32_t userId);
			babel::server::BoostTcpSocket::pointer
			&getSocket(int32_t userId);
			uint32_t getNextId() const;
			babel::common::User &getUser(int32_t userId);
			bool isConnected(uint32_t userId) const;
			bool sendOk(int32_t userId, common::CommandName cmd,
				    const std::string &msg);
		};
	}
}

#endif //CPP_BABEL_2018_SERVERCOMMANDHANDLER_HPP
