/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandLoginOk.cpp
*/

#include "CommandLoginOk.hpp"

babel::common::CommandLoginOk::CommandLoginOk(std::vector<std::string> args) :
	ACommand(CMD_LOGIN_OK)
{
	if (args.size() < 2)
		throw CommandException(CMD_LOGIN_OK, "Not enough arguments.");
	_userId = (uint32_t)stoi(args[0]);
	_username = args[1];
}

std::vector<std::string> babel::common::CommandLoginOk::getArgs() const
{
	return {std::to_string(_userId), _username};
}

uint32_t babel::common::CommandLoginOk::getUserId() const
{
	return _userId;
}

void babel::common::CommandLoginOk::setUserId(uint32_t userId)
{
	_userId = userId;
}

const std::string &babel::common::CommandLoginOk::getUsername() const
{
	return _username;
}

void babel::common::CommandLoginOk::setUsername(const std::string &username)
{
	_username = username;
}
