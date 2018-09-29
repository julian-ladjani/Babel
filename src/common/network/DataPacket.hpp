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
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

namespace babel
{
	namespace common
	{
		class DataPacket {
		public:
			enum CommandName {
				LOGIN,
				LOGOUT,
			};
			const std::vector<std::string> &getArgs() const;
			void setArgs(const std::vector<std::string> &_args);
			void addArg(std::string);
			void removeArg(std::string);
			CommandName getCommandId() const;
			unsigned long getNbArgs() const;
			void setCommandId(CommandName _commandId);
			const std::string serialize() const;
			static std::unique_ptr<DataPacket>
			deserialize(std::string);
		private:
			const std::string &serializeArgs() const;
			CommandName _commandId;
			std::vector<std::string> _args;
		};
	}
}

#endif //CPP_BABEL_2018_DATAPACKET_HPP
