/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** 	DataPacket class
*/

#include "DataPacket.hpp"

babel::common::DataPacket::DataPacket(CommandName commandId,
				      const std::vector<std::string> &args) :
	_commandId(commandId), _args(args)
{}

babel::common::CommandName
babel::common::DataPacket::getCommandId() const
{
	return _commandId;
}

unsigned long babel::common::DataPacket::getNbArgs() const
{
	return _args.size();
}

void babel::common::DataPacket::setCommandId(
	babel::common::CommandName commandId)
{
	_commandId = commandId;
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
	serialization += std::to_string(_commandId) + ARG_SEPARATOR +
			 argSerialization;
	return serialization;
}

const std::string babel::common::DataPacket::serializeArgs() const
{
	std::ostringstream vts;
	if (!_args.empty()) {
		std::copy(_args.begin(), _args.end() - 1,
			  std::ostream_iterator<std::string>(vts,
							     ARG_SEPARATOR));
		vts << _args.back();
	}
	return vts.str();
}

babel::common::DataPacket
babel::common::DataPacket::deserialize(std::string serialized)
{
	babel::common::DataPacket dataPacket;
	std::vector<std::string> argVec;

	boost::split(argVec, serialized, boost::is_any_of(ARG_SEPARATOR));
	if (argVec.empty())
		return dataPacket;
	dataPacket.setCommandId(
		(babel::common::CommandName) std::stoi(argVec[0]));
	argVec.erase(argVec.begin());
	dataPacket.setArgs(argVec);
	return dataPacket;
}