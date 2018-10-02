/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandCallEnd.hpp
*/

#ifndef CPP_BABEL_2018_COMMANDCALLEND_HPP
#define CPP_BABEL_2018_COMMANDCALLEND_HPP

#include <src/common/exception/CommandException.hpp>
#include <src/common/command/ACommand.hpp>

namespace babel {
	namespace common {
		class CommandCallEnd : public ACommand {
		public:
			CommandCallEnd(std::vector<std::string>);
			std::vector<std::string> getArgs() const override;
			uint32_t getUserId() const;
			void setUserId(uint32_t callEndId);

		private:
			uint32_t _userId;
		};
	}
}

#endif //CPP_BABEL_2018_COMMANDCALLEND_HPP
