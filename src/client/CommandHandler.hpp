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
#include <QObject>
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
#include <src/common/exception/CommandException.hpp>
#include <src/client/network/QtTcpSocket.hpp>
#include "ClientInfo.hpp"

namespace babel {
	namespace client {
		class CommandHandler : public QObject {
		Q_OBJECT
		public:
			CommandHandler(ClientInfo &info);
			bool handleCommand(std::unique_ptr<common::ACommand>
					   &command);
		Q_SIGNALS:
			void changePage(std::string pageName);
			void newContact();
		private:
			ClientInfo &_infos;
			std::map<babel::common::CommandName,
				bool (babel::client::CommandHandler::*)
					(std::unique_ptr<common::ACommand>
					 &command)> _commandHandlers;
			bool commandLoginOkHandler(
				std::unique_ptr<common::ACommand> &command);
			bool commandDeleteHandler(
				std::unique_ptr<common::ACommand> &command);
			bool commandUserHandler(
				std::unique_ptr<common::ACommand> &command);
			bool commandCallHandler(
				std::unique_ptr<common::ACommand> &command);
			bool commandCallAnswerHandler(
				std::unique_ptr<common::ACommand> &command);
			bool commandCallEndHandler(
				std::unique_ptr<common::ACommand> &command);
			bool commandContactHandler(
				std::unique_ptr<common::ACommand> &command);
			bool commandMessageHandler(
				std::unique_ptr<common::ACommand> &command);
			void tryToHandle();
		};
	}
}

#endif //CPP_BABEL_2018_SERVERCOMMANDHANDLER_HPP
