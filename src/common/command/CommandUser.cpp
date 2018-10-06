/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandUser.cpp
*/

#include "CommandUser.hpp"

babel::common::CommandUser::CommandUser(std::vector<std::string> args) :
	ACommand(CMD_USER)
{
	if (args.size() < 3)
		throw CommandException(CMD_USER, "Not enough arguments.");
	_userId = (uint32_t)std::stoi(args[0]);
	_username = args[1];
	_connected = (bool)std::stoi(args[2]);
}

std::vector<std::string> babel::common::CommandUser::getArgs() const
{
	return {std::to_string(_userId), _username,
		std::to_string(_connected)};
}

uint32_t babel::common::CommandUser::getUserId() const
{
	return _userId;
}

void babel::common::CommandUser::setUserId(uint32_t userId)
{
	_userId = userId;
}

const std::string &babel::common::CommandUser::getUsername() const
{
	return _username;
}

void babel::common::CommandUser::setUsername(const std::string &username)
{
	_username = username;
}

bool babel::common::CommandUser::isConnected() const
{
	return _connected;
}

void babel::common::CommandUser::setConnected(bool connected)
{
	_connected = connected;
}
