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
		private:
			ClientInfo &_infos;
			std::map<babel::common::CommandName,
				bool (babel::client::CommandHandler::*)
					(common::ACommand command)>
					_commandHandlers;
			bool commandLoginOkHandler(common::ACommand command);
			bool commandDeleteHandler(common::ACommand command);
			bool commandCallHandler(common::ACommand command);
			bool commandCallAnswerHandler(common::ACommand command);
			bool commandCallEndHandler(common::ACommand command);
			bool commandContactHandler(common::ACommand command);
			bool commandMessageHandler(common::ACommand command);
			void sendToAllClients(
				babel::common::DataPacket packet);
			bool createUser(common::CommandLogin &cmd,
					uint32_t userId);
			bool connectUser(common::User &user, uint32_t userId);
			void disconnectUser(uint32_t userId);
			bool isConnected(uint32_t userId);
			bool sendOk(uint32_t userId, common::CommandName cmd,
				    const std::string &msg);
			void tryToHandle();
		};
	}
}

#endif //CPP_BABEL_2018_SERVERCOMMANDHANDLER_HPP
