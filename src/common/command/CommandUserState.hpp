/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandUserState.hpp
*/

#ifndef CPP_BABEL_2018_COMMANDUSERSTATE_HPP
#define CPP_BABEL_2018_COMMANDUSERSTATE_HPP

#include <src/common/exception/CommandException.hpp>
#include <src/common/command/ACommand.hpp>

namespace babel {
	namespace common {
		class CommandUserState : public ACommand {
		public:
			CommandUserState(std::vector<std::string>);
			std::vector<std::string> getArgs() const override;
			uint32_t getUserId() const;
			void setUserId(uint32_t userId);
			bool isConnected() const;
			void setConnected(bool connected);

		private:
			uint32_t _userId;
			bool _connected;
		};
	}
}
#endif //CPP_BABEL_2018_COMMANDUSERSTATE_HPP
