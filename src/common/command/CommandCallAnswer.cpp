/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandCallAnswer.cpp
*/

#include "CommandCallAnswer.hpp"

babel::common::CommandCallAnswer::CommandCallAnswer(
	std::vector<std::string> args) : ACommand(CMD_CALL_ANSWER)
{
	if (args.size() < 3)
		throw CommandException(CMD_CALL_ANSWER,
				       "Not enough arguments.");
	_userId = (uint32_t)std::stoi(args[0]);
	_ip = args[1];
	_port = (uint16_t)std::stoi(args[2]);
}

std::vector<std::string> babel::common::CommandCallAnswer::getArgs() const
{
	return {std::to_string(_userId), _ip, std::to_string(_port)};
}

uint32_t babel::common::CommandCallAnswer::getUserId() const
{
	return _userId;
}

void babel::common::CommandCallAnswer::setUserId(uint32_t userId)
{
	_userId = userId;
}

const std::string &babel::common::CommandCallAnswer::getIp() const
{
	return _ip;
}

void babel::common::CommandCallAnswer::setIp(const std::string &ip)
{
	_ip = ip;
}

uint16_t babel::common::CommandCallAnswer::getPort() const
{
	return _port;
}

void babel::common::CommandCallAnswer::setPort(uint16_t port)
{
	_port = port;
}
