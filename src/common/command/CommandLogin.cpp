/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandLogin.cpp
*/

#include "CommandLogin.hpp"

babel::common::CommandLogin::CommandLogin(std::vector<std::string> args) :
	ACommand(LOGIN)
{
	if (args.size() < 2)
		throw CommandException("Not enough arguments");
	_username = args[0];
	_password = args[1];
}

std::vector<std::string> babel::common::CommandLogin::getArgs()
{
	return {_username, _password};
}
