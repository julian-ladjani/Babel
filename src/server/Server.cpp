/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Server.cpp
*/

#include "Server.hpp"

babel::server::Server::Server() :
	_clients(),
	_commandHandler({{babel::common::CommandName::CMD_LOGIN,
				 &babel::server::Server::commandLoginHandler},
			 {babel::common::CommandName::CMD_LOGOUT,
				 &babel::server::Server::commandLogoutHandler},
			 {babel::common::CommandName::CMD_DELETE,
				 &babel::server::Server::commandDeleteHandler},
			 {babel::common::CommandName::CMD_CALL,
				 &babel::server::Server::commandCallHandler},
			 {babel::common::CommandName::CMD_CALL_ANSWER,
				 &babel::server::Server
				 ::commandCallAnswerHandler},
			 {babel::common::CommandName::CMD_CALL_END,
				 &babel::server::Server::commandCallEndHandler},
			 {babel::common::CommandName::CMD_CONTACT,
				 &babel::server::Server::commandContactHandler},
			 {babel::common::CommandName::CMD_MESSAGE,
				 &babel::server::Server::commandMessageHandler},
			})
{}

int babel::server::Server::start()
{
	std::cout << "Bonjour, je suis un server !" << std::endl;
	return 0;
}

bool babel::server::Server::handleCommand(babel::common::ACommand command,
					  uint32_t userId)
{
	if (_commandHandler.find(command.getCommandId())
	    != _commandHandler.end())
		return (this->*_commandHandler[command.getCommandId()])
			(command, userId);
	throw common::CommandException(command.getCommandId(),
				       "Command not supported");
}

void babel::server::Server::addClient(common::User user)
{
	if (std::find(_clients.begin(), _clients.end(), user) == _clients.end())
		_clients.push_back(user);
}

void babel::server::Server::removeClient(common::User user)
{
	auto position =	std::find(_clients.begin(), _clients.end(), user);
	if (position != _clients.end())
		_clients.erase(position);
}

void babel::server::Server::sendToAllClients(babel::common::ACommand command)
{
	(void)command;
	for (babel::common::User &client : _clients) {
		std::cout << client.getId() << std::endl;
	}
}

bool babel::server::Server::commandLoginHandler(
	babel::common::ACommand command, uint32_t userId)
{
	(void)command;
	(void)userId;
	return true;
}

bool babel::server::Server::commandLogoutHandler(
	babel::common::ACommand command, uint32_t userId)
{
	(void)command;
	(void)userId;
	return true;
}

bool babel::server::Server::commandDeleteHandler(
	babel::common::ACommand command, uint32_t userId)
{
	(void)command;
	(void)userId;
	return true;
}

bool babel::server::Server::commandCallHandler(
	babel::common::ACommand command, uint32_t userId)
{
	(void)command;
	(void)userId;
	return true;
}

bool babel::server::Server::commandCallAnswerHandler(
	babel::common::ACommand command, uint32_t userId)
{
	(void)command;
	(void)userId;
	return true;
}

bool babel::server::Server::commandCallEndHandler(
	babel::common::ACommand command, uint32_t userId)
{
	(void)command;
	(void)userId;
	return true;
}

bool babel::server::Server::commandContactHandler(
	babel::common::ACommand command, uint32_t userId)
{
	(void)command;
	(void)userId;
	return true;
}

bool babel::server::Server::commandMessageHandler(
	babel::common::ACommand command, uint32_t userId)
{
	(void)command;
	(void)userId;
	return true;
}