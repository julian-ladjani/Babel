/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandUserState.cpp
*/

#include "CommandUserState.hpp"

babel::common::CommandUserState::CommandUserState(std::vector<std::string> args) :
	ACommand(USER_STATE)
{
	if (args.size() < 2)
		throw CommandException(USER_STATE, "Not enough arguments");
	_userId = (uint32_t)stoi(args[0]);
	_connected = (bool)stoi(args[1]);
}

std::vector<std::string> babel::common::CommandUserState::getArgs() const
{
	return {std::to_string(_userId), std::to_string(_connected)};
}

uint32_t babel::common::CommandUserState::getUserId() const
{
	return _userId;
}

void babel::common::CommandUserState::setUserId(uint32_t userId)
{
	_userId = userId;
}

bool babel::common::CommandUserState::isConnected() const
{
	return _connected;
}

void babel::common::CommandUserState::setConnected(bool connected)
{
	_connected = connected;
}
