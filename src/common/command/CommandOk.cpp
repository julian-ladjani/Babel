/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandOk.cpp
*/

#include "CommandOk.hpp"

babel::common::CommandOk::CommandOk(std::vector<std::string> args) :
	ACommand(CMD_OK)
{
	if (args.size() < 2)
		throw CommandException(CMD_OK, "Not enough arguments");
	_okCommandId = (CommandName)stoi(args[0]);
	_message = args[1];
}

std::vector<std::string> babel::common::CommandOk::getArgs() const
{
	return {std::to_string((int)_okCommandId), _message};
}

babel::common::CommandName
babel::common::CommandOk::getOkCommandId() const
{
	return _okCommandId;
}

void babel::common::CommandOk::setOkCommandId(CommandName okCommandId)
{
	_okCommandId = okCommandId;
}

const std::string &babel::common::CommandOk::getMessage() const
{
	return _message;
}

void babel::common::CommandOk::setMessage(const std::string &message)
{
	_message = message;
}
