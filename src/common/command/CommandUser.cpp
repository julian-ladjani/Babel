/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandUser.cpp
*/

#include "CommandUser.hpp"

babel::common::CommandUser::CommandUser(std::vector<std::string> args) :
	ACommand(USER)
{
	if (args.size() < 2)
		throw CommandException("Not enough arguments");
	_userId = (uint32_t)std::stoi(args[0]);
	_username = args[1];
}

std::vector<std::string> babel::common::CommandUser::getArgs() const
{
	return {std::to_string(_userId), _username};
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
