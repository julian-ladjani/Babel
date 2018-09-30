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
#include <src/common/command/CommandLogin.hpp>

namespace babel {
	namespace common {
		class CommandFactory {
		public:
		private:
			std::map<babel::common::CommandName,
				babel::common::ACommand
				(babel::common::CommandFactory::*)
					(std::vector<std::string>)> _commands;
		public:
			CommandFactory();
			ACommand deserialize(DataPacket packet);

		private:
			template<class T>
			ACommand createCommand(std::vector<std::string> args);
		};
	}
}


#endif //CPP_BABEL_2018_COMMANDFACTORY_HPP
