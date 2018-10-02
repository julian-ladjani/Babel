/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandException.cpp
*/

#include "CommandException.hpp"

babel::common::CommandException::CommandException(CommandName commandId,
						  const std::string &message) :
	Exception("Command Error", message), _commandId(commandId)
{}

babel::common::CommandName babel::common::CommandException::getCommandId()
{
	return _commandId;
}
