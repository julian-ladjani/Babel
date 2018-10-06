/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandMessage.cpp
*/

#include "CommandMessage.hpp"

babel::common::CommandMessage::CommandMessage(std::vector<std::string> args) :
	ACommand(CMD_MESSAGE)
{
	if (args.size() < 3)
		throw CommandException(CMD_MESSAGE, "Not enough arguments.");
	_userId = (uint32_t)std::stoi(args[0]);
	_message = args[1];
}

std::vector<std::string> babel::common::CommandMessage::getArgs() const
{
	return {std::to_string(_userId), _message};
}

uint32_t babel::common::CommandMessage::getUserId() const
{
	return _userId;
}

void babel::common::CommandMessage::setUserId(uint32_t userId)
{
	_userId = userId;
}

const std::string &babel::common::CommandMessage::getMessage() const
{
	return _message;
}

void babel::common::CommandMessage::setMessage(const std::string &message)
{
	_message = message;
}