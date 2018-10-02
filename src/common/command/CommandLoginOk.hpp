/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandLoginOk.hpp
*/

#ifndef CPP_BABEL_2018_COMMANDLOGINOK_HPP
#define CPP_BABEL_2018_COMMANDLOGINOK_HPP

#include <src/common/exception/CommandException.hpp>
#include <src/common/command/ACommand.hpp>

namespace babel {
	namespace common {
		class CommandLoginOk : public ACommand {
		public:
			CommandLoginOk(std::vector<std::string> args);
			std::vector<std::string> getArgs() const override;
			uint32_t getUserId() const;
			void setUserId(uint32_t userId);
			const std::string &getUsername() const;
			void setUsername(const std::string &username);

		private:
			uint32_t _userId;
			std::string _username;
		};
	}
}

#endif //CPP_BABEL_2018_COMMANDLOGINOK_HPP
