/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** 	DataPacket class
*/

#include "DataPacket.hpp"

babel::common::DataPacket::CommandName
babel::common::DataPacket::getCommandId() const
{
	return _commandId;
}

unsigned long babel::common::DataPacket::getNbArgs() const
{
	return _args.size();
}

void babel::common::DataPacket::setCommandId(
	babel::common::DataPacket::CommandName _commandId)
{
	DataPacket::_commandId = _commandId;
}

void babel::common::DataPacket::addArg(std::string arg)
{
	_args.push_back(arg);
}

void babel::common::DataPacket::removeArg(std::string)
{
}

const std::vector<std::string> &babel::common::DataPacket::getArgs() const
{
	return _args;
}

void
babel::common::DataPacket::setArgs(const std::vector<std::string> &_args)
{
	DataPacket::_args = _args;
}

const std::string babel::common::DataPacket::serialize() const
{
	std::string serialization;
	std::string argSerialization = serializeArgs();
	serialization += std::to_string(_commandId) + ":" + argSerialization;
	return serialization;
}

const std::string &babel::common::DataPacket::serializeArgs() const
{
	std::ostringstream vts;
	if (!_args.empty()) {
		std::copy(_args.begin(), _args.end() - 1,
			std::ostream_iterator<std::string>(vts, ":"));
		vts << _args.back();
	}
	return vts.str();
}
