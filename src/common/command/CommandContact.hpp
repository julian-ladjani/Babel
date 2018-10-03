/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandContact.hpp
*/

#ifndef CPP_BABEL_2018_COMMANDCONTACT_HPP
#define CPP_BABEL_2018_COMMANDCONTACT_HPP

#include <src/common/exception/CommandException.hpp>
#include <src/common/command/ACommand.hpp>

namespace babel {
	namespace common {
		class CommandContact : public ACommand {
		public:
			CommandContact(std::vector<std::string> args);
			std::vector<std::string> getArgs() const override;
			uint32_t getUserId() const;
			void setUserId(uint32_t userId);
			bool isContact() const;
			void setContact(bool connected);

		private:
			uint32_t _userId;
			bool _contact;
		};
	}
}

#endif //CPP_BABEL_2018_COMMANDCONTACT_HPP
