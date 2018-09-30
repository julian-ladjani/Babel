/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandLogin.hpp
*/

#ifndef CPP_BABEL_2018_COMMANDLOGIN_HPP
#define CPP_BABEL_2018_COMMANDLOGIN_HPP

#include <src/common/exception/CommandException.hpp>
#include <src/common/command/ACommand.hpp>

namespace babel {
	namespace common {
		class CommandLogin : public ACommand {
		public:
			CommandLogin(std::vector<std::string>);
			std::vector<std::string> getArgs() override;

		private:
			std::string _username;
			std::string _password;
		};
	}
}

#endif //CPP_BABEL_2018_COMMANDLOGIN_HPP
