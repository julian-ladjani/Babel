/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandMessage.cpp
*/

#include "CommandMessage.hpp"

babel::common::CommandMessage::CommandMessage(std::vector<std::string> args) :
	ACommand(CMD_MESSAGE)
{
	if (args.size() < 3)
		throw CommandException(CMD_MESSAGE, "Not enough arguments");
	_messageId = (uint32_t)std::stoi(args[0]);
	_message = args[1];
}

std::vector<std::string> babel::common::CommandMessage::getArgs() const
{
	return {std::to_string(_messageId), _message};
}

uint32_t babel::common::CommandMessage::getMessageId() const
{
	return _messageId;
}

void babel::common::CommandMessage::setMessageId(uint32_t messageId)
{
	_messageId = messageId;
}

const std::string &babel::common::CommandMessage::getMessage() const
{
	return _message;
}

void babel::common::CommandMessage::setMessage(const std::string &message)
{
	_message = message;
}