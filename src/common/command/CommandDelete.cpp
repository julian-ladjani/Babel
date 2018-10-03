/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandDelete.cpp
*/

#include "CommandDelete.hpp"

babel::common::CommandDelete::CommandDelete(
	std::vector<std::string> args) :
	ACommand(CMD_DELETE), _userId(0)
{
	if (!args.empty())
		_userId = (uint32_t)std::stoi(args[0]);
}

std::vector<std::string> babel::common::CommandDelete::getArgs() const
{
	return {std::to_string(_userId)};
}

uint32_t babel::common::CommandDelete::getUserId() const
{
	return _userId;
}

void babel::common::CommandDelete::setUserId(uint32_t userId)
{
	_userId = userId;
}