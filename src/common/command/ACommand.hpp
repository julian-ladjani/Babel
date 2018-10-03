/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** 	ACommand class
*/

#ifndef CPP_BABEL_2018_ACOMMAND_HPP
#define CPP_BABEL_2018_ACOMMAND_HPP

#include <string>
#include <src/common/network/DataPacket.hpp>
#include <src/common/command/CommandName.hpp>

namespace babel
{
	namespace common
	{
		class ACommand {
		public:
			ACommand(babel::common::CommandName commandId);
			CommandName getCommandId() const;
			const DataPacket serialize() const;
			virtual std::vector<std::string> getArgs() const;
		private:
			CommandName _commandId;
		};
	}
}
#endif //CPP_BABEL_2018_ACOMMAND_HPP
