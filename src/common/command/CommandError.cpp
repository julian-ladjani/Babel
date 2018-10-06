/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandError.cpp
*/

#include "CommandError.hpp"

babel::common::CommandError::CommandError(std::vector<std::string> args) :
	ACommand(CMD_ERROR)
{
	if (args.size() < 2)
		throw CommandException(CMD_ERROR, "Not enough arguments.");
	_errorCommandId = (CommandName)stoi(args[0]);
	_message = args[1];
}

std::vector<std::string> babel::common::CommandError::getArgs() const
{
	return {std::to_string((int)_errorCommandId), _message};
}

babel::common::CommandName
babel::common::CommandError::getErrorCommandId() const
{
	return _errorCommandId;
}

void babel::common::CommandError::setErrorCommandId(CommandName errorCommandId)
{
	_errorCommandId = errorCommandId;
}

const std::string &babel::common::CommandError::getMessage() const
{
	return _message;
}

void babel::common::CommandError::setMessage(const std::string &message)
{
	_message = message;
}
