/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** ServerCommandHandler.cpp
*/

#include <src/common/command/CommandUserState.hpp>
#include <src/common/command/CommandUser.hpp>
#include <src/common/command/CommandOk.hpp>
#include "ServerCommandHandler.hpp"

babel::server::ServerCommandHandler::ServerCommandHandler(
	std::vector<babel::common::User> &clients,
	std::vector<std::pair<BoostTcpSocket, uint32_t>> &sockets) :
	_clients(clients), _sockets(sockets),
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
	babel::common::DataPacket packet)
{
	for (std::pair<babel::server::BoostTcpSocket,
			uint32_t> &sock : _sockets) {
		if (sock.second > 0)
			sock.first.send(packet);
	}
}

bool babel::server::ServerCommandHandler::commandLoginHandler(
	babel::common::ACommand command, uint32_t userId)
{
	common::CommandLogin &cmd = (common::CommandLogin &) command;
	for (common::User &user : _clients) {
		if (!cmd.getUsername().compare(user.getLogin())) {
			if (!cmd.getPassword().compare(user.getPassword()))
				throw common::CommandException(
					common::CMD_LOGIN, "Correct password");
			return ConnectUser(user, userId);
		}
	}
	return CreateUser(cmd, userId);
}

bool babel::server::ServerCommandHandler::CreateUser(
	babel::common::CommandLogin &cmd, uint32_t userId)
{

	common::User user(userId, cmd.getUsername(), cmd.getPassword());
	user.setConnected(true);
	_clients.push_back(user);
	sendToAllClients(common::CommandUser(
		{std::to_string(user.getId()),
		 cmd.getUsername(), "1"}).serialize());
	sendOk(userId, common::CMD_LOGIN, "Account created");
	return ConnectUser(user, userId);
}

bool babel::server::ServerCommandHandler::ConnectUser(
	common::User &user, uint32_t userId)
{
	auto &sock = getSocket(userId);
	sock.second = user.getId();
	user.setConnected(true);
	sendToAllClients(common::CommandUserState(
		{std::to_string(user.getId()), "1"}).serialize());
	return sendOk(sock.second, common::CMD_LOGIN, "Login ok");
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

std::pair<babel::server::BoostTcpSocket, uint32_t> &
babel::server::ServerCommandHandler::getSocket(uint32_t userId)
{
	for (auto &sock : _sockets) {
		if (sock.second == userId)
			return sock;
	}
	return _sockets[0];
}

uint32_t babel::server::ServerCommandHandler::getNextId()
{
	uint32_t id = 0;
	for (auto &sock : _sockets) {
		if (sock.second > id)
			id = sock.second;
	}
	for (common::User &user : _clients) {
		if (user.getId() > id)
			id = user.getId();
	}
	return ++id;
}

bool babel::server::ServerCommandHandler::sendOk(
	uint32_t userId, babel::common::CommandName cmd, const std::string &msg)
{
	auto &sock = getSocket(userId);
	sock.first.send(common::CommandOk(
		{std::to_string(cmd), msg}).serialize());
	return true;
}
