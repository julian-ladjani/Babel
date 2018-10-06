/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandLogin.cpp
*/

#include "CommandLogin.hpp"

babel::common::CommandLogin::CommandLogin(std::vector<std::string> args) :
	ACommand(CMD_LOGIN)
{
	if (args.size() < 2)
		throw CommandException(CMD_LOGIN, "Not enough arguments.");
	_username = args[0];
	_password = args[1];
}

std::vector<std::string> babel::common::CommandLogin::getArgs() const
{
	return {_username, _password};
}

const std::string &babel::common::CommandLogin::getUsername() const
{
	return _username;
}

void babel::common::CommandLogin::setUsername(const std::string &username)
{
	_username = username;
}

const std::string &babel::common::CommandLogin::getPassword() const
{
	return _password;
}

void babel::common::CommandLogin::setPassword(const std::string &password)
{
	_password = password;
}
