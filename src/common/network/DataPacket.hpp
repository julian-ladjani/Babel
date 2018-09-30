/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** 	DataPacket class
*/

#ifndef CPP_BABEL_2018_DATAPACKET_HPP
#define CPP_BABEL_2018_DATAPACKET_HPP

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include "../command/ACommand.hpp"

namespace babel
{
	namespace common
	{
		class DataPacket {
		public:
			const std::vector<std::string> &getArgs() const;
			void setArgs(const std::vector<std::string> &_args);
			void addArg(std::string);
			void removeArg(std::string);
			babel::common::ACommand::CommandName
			getCommandId() const;
			unsigned long getNbArgs() const;
			void setCommandId(babel::common::ACommand::CommandName
			_commandId);
			const std::string serialize() const;
			static DataPacket deserialize(std::string);

		private:
			static constexpr char ARG_SEPARATOR[] = "\x1f";
			const std::string serializeArgs() const;
			babel::common::ACommand::CommandName _commandId;
			std::vector<std::string> _args;
		};
	}
}

#endif //CPP_BABEL_2018_DATAPACKET_HPP
