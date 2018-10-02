/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandAddContact.hpp
*/

#ifndef CPP_BABEL_2018_COMMANDADDCONTACT_HPP
#define CPP_BABEL_2018_COMMANDADDCONTACT_HPP

#include <src/common/exception/CommandException.hpp>
#include <src/common/command/ACommand.hpp>

namespace babel {
	namespace common {
		class CommandAddContact : public ACommand {
		public:
			CommandAddContact(std::vector<std::string>);
			std::vector<std::string> getArgs() const override;
			uint32_t getUserId() const;
			void setUserId(uint32_t addContactId);

		private:
			uint32_t _userId;
		};
	}
}

#endif //CPP_BABEL_2018_COMMANDADDCONTACT_HPP
