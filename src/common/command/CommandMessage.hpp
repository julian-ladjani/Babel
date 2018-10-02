/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandMessage.hpp
*/

#ifndef CPP_BABEL_2018_COMMANDMESSAGE_HPP
#define CPP_BABEL_2018_COMMANDMESSAGE_HPP

#include <src/common/exception/CommandException.hpp>
#include <src/common/command/ACommand.hpp>

namespace babel {
	namespace common {
		class CommandMessage : public ACommand {
		public:
			CommandMessage(std::vector<std::string> args);
			std::vector<std::string> getArgs() const override;
			uint32_t getMessageId() const;
			void setMessageId(uint32_t messageId);
			const std::string &getMessage() const;
			void setMessage(const std::string &message);

		private:
			uint32_t _messageId;
			std::string _message;
		};
	}
}

#endif //CPP_BABEL_2018_COMMANDMESSAGE_HPP
