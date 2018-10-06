/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandCall.cpp
*/

#include "CommandCall.hpp"

babel::common::CommandCall::CommandCall(std::vector<std::string> args) :
	ACommand(CMD_CALL)
{
	if (args.size() < 3)
		throw CommandException(CMD_CALL, "Not enough arguments.");
	_userId = (uint32_t)std::stoi(args[0]);
	_ip = args[1];
	_port = (uint16_t)std::stoi(args[2]);
}

std::vector<std::string> babel::common::CommandCall::getArgs() const
{
	return {std::to_string(_userId), _ip, std::to_string(_port)};
}

uint32_t babel::common::CommandCall::getUserId() const
{
	return _userId;
}

void babel::common::CommandCall::setUserId(uint32_t userId)
{
	_userId = userId;
}

const std::string &babel::common::CommandCall::getIp() const
{
	return _ip;
}

void babel::common::CommandCall::setIp(const std::string &ip)
{
	_ip = ip;
}

uint16_t babel::common::CommandCall::getPort() const
{
	return _port;
}

void babel::common::CommandCall::setPort(uint16_t port)
{
	_port = port;
}
