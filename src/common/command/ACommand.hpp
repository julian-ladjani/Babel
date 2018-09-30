/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** 	ACommand class
*/

#ifndef CPP_BABEL_2018_ACOMMAND_HPP
#define CPP_BABEL_2018_ACOMMAND_HPP

#include <src/common/network/DataPacket.hpp>

namespace babel
{
	namespace common
	{
		class ACommand {
		public:
			enum CommandName {
				LOGIN,
				LOGOUT,
			};
			ACommand(CommandName _commandId);
			CommandName get_commandId() const;
			virtual const DataPacket serialize() = 0;
		private:
			CommandName _commandId;
		};
	}
}
#endif //CPP_BABEL_2018_ACOMMAND_HPP
