/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandError.hpp
*/

#ifndef CPP_BABEL_2018_COMMANDERROR_HPP
#define CPP_BABEL_2018_COMMANDERROR_HPP

#include <src/common/exception/CommandException.hpp>
#include <src/common/command/ACommand.hpp>

namespace babel {
	namespace common {
		class CommandError : public ACommand {
		public:
			CommandError(std::vector<std::string> args);
			std::vector<std::string> getArgs() const override;
			CommandName getErrorCommandId() const;
			void setErrorCommandId(CommandName errorCommandId);
			const std::string &getMessage() const;
			void setMessage(const std::string &password);

		private:
			CommandName _errorCommandId;
			std::string _message;
		};
	}
}

#endif //CPP_BABEL_2018_COMMANDERROR_HPP
