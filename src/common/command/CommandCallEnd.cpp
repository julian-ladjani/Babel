/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandCallEnd.cpp
*/

#include "CommandCallEnd.hpp"

babel::common::CommandCallEnd::CommandCallEnd(std::vector<std::string> args) :
	ACommand(CMD_CALL_END)
{
	if (args.size() < 1)
		throw CommandException(CMD_CALL_END, "Not enough arguments");
	_userId = (uint32_t)std::stoi(args[0]);
}

std::vector<std::string> babel::common::CommandCallEnd::getArgs() const
{
	return {std::to_string(_userId)};
}

uint32_t babel::common::CommandCallEnd::getUserId() const
{
	return _userId;
}

void babel::common::CommandCallEnd::setUserId(uint32_t userId)
{
	_userId = userId;
}
