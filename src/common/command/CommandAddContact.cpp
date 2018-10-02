/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandAddContact.cpp
*/

#include "CommandAddContact.hpp"

babel::common::CommandAddContact::CommandAddContact(
	std::vector<std::string> args) :
	ACommand(ADD_CONTACT)
{
	if (args.size() < 1)
		throw CommandException(ADD_CONTACT, "Not enough arguments");
	_userId = (uint32_t)std::stoi(args[0]);
}

std::vector<std::string> babel::common::CommandAddContact::getArgs() const
{
	return {std::to_string(_userId)};
}

uint32_t babel::common::CommandAddContact::getUserId() const
{
	return _userId;
}

void babel::common::CommandAddContact::setUserId(uint32_t userId)
{
	_userId = userId;
}
