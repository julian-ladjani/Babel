/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandCallAnswer.hpp
*/

#ifndef CPP_BABEL_2018_COMMANDCALLANSWER_HPP
#define CPP_BABEL_2018_COMMANDCALLANSWER_HPP

#include <src/common/exception/CommandException.hpp>
#include <src/common/command/ACommand.hpp>

namespace babel {
	namespace common {
		class CommandCallAnswer : public ACommand {
		public:
			CommandCallAnswer(std::vector<std::string> args);
			std::vector<std::string> getArgs() const override;
			uint32_t getUserId() const;
			void setUserId(uint32_t userId);
			const std::string &getIp() const;
			void setIp(const std::string &ip);
			uint16_t getPort() const;
			void setPort(uint16_t _port);

		private:
			uint32_t _userId;
			std::string _ip;
			uint16_t _port;
		};
	}
}

#endif //CPP_BABEL_2018_COMMANDCALLANSWER_HPP
