/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandDelete.hpp
*/

#ifndef CPP_BABEL_2018_COMMANDDELETE_HPP
#define CPP_BABEL_2018_COMMANDDELETE_HPP

#include <src/common/exception/CommandException.hpp>
#include <src/common/command/ACommand.hpp>

namespace babel {
	namespace common {
		class CommandDelete : public ACommand {
		public:
			CommandDelete(std::vector<std::string> args);
			std::vector<std::string> getArgs() const override;
			uint32_t getUserId() const;
			void setUserId(uint32_t userId);

		private:
			uint32_t _userId;
		};
	}
}

#endif //CPP_BABEL_2018_COMMANDDELETE_HPP
