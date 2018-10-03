/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** ServerCommandHandler.cpp
*/

#include "ServerCommandHandler.hpp"

babel::server::ServerCommandHandler::ServerCommandHandler(
	std::vector<babel::common::User> &_clients) :
	_clients(_clients),
	_commandHandlers({{babel::common::CommandName::CMD_LOGIN,
				  &babel::server::ServerCommandHandler
				  ::commandLoginHandler},
			  {babel::common::CommandName::CMD_LOGOUT,
				  &babel::server::ServerCommandHandler
				  ::commandLogoutHandler},
			  {babel::common::CommandName::CMD_DELETE,
				  &babel::server::ServerCommandHandler
				  ::commandDeleteHandler},
			  {babel::common::CommandName::CMD_CALL,
				  &babel::server::ServerCommandHandler
				  ::commandCallHandler},
			  {babel::common::CommandName::CMD_CALL_ANSWER,
				  &babel::server::ServerCommandHandler
				  ::commandCallAnswerHandler},
			  {babel::common::CommandName::CMD_CALL_END,
				  &babel::server::ServerCommandHandler
				  ::commandCallEndHandler},
			  {babel::common::CommandName::CMD_CONTACT,
				  &babel::server::ServerCommandHandler
				  ::commandContactHandler},
			  {babel::common::CommandName::CMD_MESSAGE,
				  &babel::server::ServerCommandHandler
				  ::commandMessageHandler}})
{}

bool babel::server::ServerCommandHandler::handleCommand(
	babel::common::ACommand command, uint32_t userId)
{
	if (_commandHandlers.find(command.getCommandId())
	    != _commandHandlers.end())
		return (this->*_commandHandlers[command.getCommandId()])
			(command, userId);
	throw common::CommandException(command.getCommandId(),
				       "Command not supported");
}


void babel::server::ServerCommandHandler::sendToAllClients(
	babel::common::ACommand command)
{
	(void)command;
	for (babel::common::User &client : _clients) {
		std::cout << client.getId() << std::endl;
	}
}

bool babel::server::ServerCommandHandler::commandLoginHandler(
	babel::common::ACommand command, uint32_t userId)
{
	(void)command;
	(void)userId;
	return true;
}

bool babel::server::ServerCommandHandler::commandLogoutHandler(
	babel::common::ACommand command, uint32_t userId)
{
	(void)command;
	(void)userId;
	return true;
}

bool babel::server::ServerCommandHandler::commandDeleteHandler(
	babel::common::ACommand command, uint32_t userId)
{
	(void)command;
	(void)userId;
	return true;
}

bool babel::server::ServerCommandHandler::commandCallHandler(
	babel::common::ACommand command, uint32_t userId)
{
	(void)command;
	(void)userId;
	return true;
}

bool babel::server::ServerCommandHandler::commandCallAnswerHandler(
	babel::common::ACommand command, uint32_t userId)
{
	(void)command;
	(void)userId;
	return true;
}

bool babel::server::ServerCommandHandler::commandCallEndHandler(
	babel::common::ACommand command, uint32_t userId)
{
	(void)command;
	(void)userId;
	return true;
}

bool babel::server::ServerCommandHandler::commandContactHandler(
	babel::common::ACommand command, uint32_t userId)
{
	(void)command;
	(void)userId;
	return true;
}

bool babel::server::ServerCommandHandler::commandMessageHandler(
	babel::common::ACommand command, uint32_t userId)
{
	(void)command;
	(void)userId;
	return true;
}