/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandOk.hpp
*/

#ifndef CPP_BABEL_2018_COMMANDOK_HPP
#define CPP_BABEL_2018_COMMANDOK_HPP

#include <src/common/exception/CommandException.hpp>
#include <src/common/command/ACommand.hpp>

namespace babel {
	namespace common {
		class CommandOk : public ACommand {
		public:
			CommandOk(std::vector<std::string> args);
			std::vector<std::string> getArgs() const override;
			CommandName getOkCommandId() const;
			void setOkCommandId(CommandName okCommandId);
			const std::string &getMessage() const;
			void setMessage(const std::string &password);

		private:
			CommandName _okCommandId;
			std::string _message;
		};
	}
}

#endif //CPP_BABEL_2018_COMMANDOK_HPP
