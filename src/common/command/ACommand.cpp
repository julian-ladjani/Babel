/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** 	ACommand class
*/

#include "ACommand.hpp"

babel::common::ACommand::ACommand(
	babel::common::CommandName commandId) : _commandId(
	commandId)
{
}

babel::common::CommandName babel::common::ACommand::getCommandId() const
{
	return _commandId;
}

const babel::common::DataPacket babel::common::ACommand::serialize() const
{
	return babel::common::DataPacket(_commandId, getArgs());
}

std::vector<std::string> babel::common::ACommand::getArgs() const
{
	return std::vector<std::string>();
}
