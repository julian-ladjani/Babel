/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** 	ACommand class
*/

#include "ACommand.hpp"

babel::common::ACommand::CommandName
babel::common::ACommand::get_commandId() const
{
	return _commandId;
}

babel::common::ACommand::ACommand(
	babel::common::ACommand::CommandName _commandId) : _commandId(
	_commandId)
{
}
