/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandPing.hpp
*/

#ifndef CPP_BABEL_2018_COMMANDPING_HPP
#define CPP_BABEL_2018_COMMANDPING_HPP

#include <src/common/command/ACommand.hpp>

namespace babel {
	namespace common {
		class CommandPing : public ACommand {
		public:
			CommandPing(std::vector<std::string> args);
		};
	}
}

#endif //CPP_BABEL_2018_COMMANDPING_HPP
