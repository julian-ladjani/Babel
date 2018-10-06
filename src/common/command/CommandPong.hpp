/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandPong.hpp
*/

#ifndef CPP_BABEL_2018_COMMANDPONG_HPP
#define CPP_BABEL_2018_COMMANDPONG_HPP

#include <src/common/command/ACommand.hpp>

namespace babel {
	namespace common {
		class CommandPong : public ACommand {
		public:
			CommandPong(std::vector<std::string> args);
		};
	}
}

#endif //CPP_BABEL_2018_COMMANDPONG_HPP
