/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandAddContact.cpp
*/

#include "CommandContact.hpp"

babel::common::CommandContact::CommandContact(
	std::vector<std::string> args) :
	ACommand(CMD_CONTACT)
{
	if (args.size() < 2)
		throw CommandException(CMD_CONTACT, "Not enough arguments");
	_userId = (uint32_t)std::stoi(args[0]);
	_contact = (bool)stoi(args[1]);
}

std::vector<std::string> babel::common::CommandContact::getArgs() const
{
	return {std::to_string(_userId), std::to_string(_contact)};
}

uint32_t babel::common::CommandContact::getUserId() const
{
	return _userId;
}

void babel::common::CommandContact::setUserId(uint32_t userId)
{
	_userId = userId;
}

bool babel::common::CommandContact::isContact() const
{
	return _contact;
}

void babel::common::CommandContact::setContact(bool contact)
{
	_contact = contact;
}
