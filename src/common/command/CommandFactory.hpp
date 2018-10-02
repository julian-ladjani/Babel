/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandFactory.hpp
*/

#ifndef CPP_BABEL_2018_COMMANDFACTORY_HPP
#define CPP_BABEL_2018_COMMANDFACTORY_HPP

#include <map>
#include <src/common/network/DataPacket.hpp>
#include <src/common/command/ACommand.hpp>
#include <src/common/command/CommandError.hpp>
#include <src/common/command/CommandLogin.hpp>
#include <src/common/command/CommandLoginOk.hpp>
#include <src/common/command/CommandLogout.hpp>
#include <src/common/command/CommandUser.hpp>
#include <src/common/command/CommandUserState.hpp>
#include <src/common/command/CommandCall.hpp>
#include <src/common/command/CommandCallAnswer.hpp>
#include <src/common/command/CommandCallEnd.hpp>
#include <src/common/command/CommandAddContact.hpp>
#include <src/common/command/CommandMessage.hpp>

namespace babel {
	namespace common {
		class CommandFactory {
		public:
		public:
			CommandFactory();
			std::unique_ptr<ACommand> deserialize(
				DataPacket packet);

		private:
			template<class T>
			std::unique_ptr<ACommand> createCommand(
				std::vector<std::string> args);
			std::map<babel::common::CommandName,
				std::unique_ptr<babel::common::ACommand>
				(babel::common::CommandFactory::*)
					(std::vector<std::string>)> _commands;
		};
	}
}


#endif //CPP_BABEL_2018_COMMANDFACTORY_HPP
