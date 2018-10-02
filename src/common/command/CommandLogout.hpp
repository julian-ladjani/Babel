/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandLogout.hpp
*/

#ifndef CPP_BABEL_2018_COMMANDLOGOUT_HPP
#define CPP_BABEL_2018_COMMANDLOGOUT_HPP

#include <src/common/command/ACommand.hpp>

namespace babel {
	namespace common {
		class CommandLogout : public ACommand {
		public:
			CommandLogout(std::vector<std::string> args);
		};
	}
}

#endif //CPP_BABEL_2018_COMMANDLOGOUT_HPP
