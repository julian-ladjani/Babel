/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandException.hpp
*/

#ifndef CPP_BABEL_2018_COMMANDEXCEPTION_HPP
#define CPP_BABEL_2018_COMMANDEXCEPTION_HPP

#include "Exception.hpp"

namespace babel {
	namespace common {
		class CommandException : public Exception {
		public:
			explicit CommandException(
				const std::string &message = "Unknown Error");

			CommandException();
		};
	}
}


#endif //CPP_BABEL_2018_COMMANDEXCEPTION_HPP
