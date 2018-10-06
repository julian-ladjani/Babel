/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandHandler.cpp
*/

#include "ServerCommandHandler.hpp"

babel::server::CommandHandler::CommandHandler(
	std::vector<babel::common::User> &clients,
	std::vector<std::pair<BoostTcpSocket, uint32_t>> &sockets) :
	_clients(clients), _sockets(sockets),
	_commandHandlers({{babel::common::CommandName::CMD_LOGIN,
				  &babel::server::CommandHandler
				  ::commandLoginHandler},
			  {babel::common::CommandName::CMD_LOGOUT,
				  &babel::server::CommandHandler
				  ::commandLogoutHandler},
			  {babel::common::CommandName::CMD_DELETE,
				  &babel::server::CommandHandler
				  ::commandDeleteHandler},
			  {babel::common::CommandName::CMD_CALL,
				  &babel::server::CommandHandler
				  ::commandCallHandler},
			  {babel::common::CommandName::CMD_CALL_ANSWER,
				  &babel::server::CommandHandler
				  ::commandCallAnswerHandler},
			  {babel::common::CommandName::CMD_CALL_END,
				  &babel::server::CommandHandler
				  ::commandCallEndHandler},
			  {babel::common::CommandName::CMD_CONTACT,
				  &babel::server::CommandHandler
				  ::commandContactHandler},
			  {babel::common::CommandName::CMD_MESSAGE,
				  &babel::server::CommandHandler
				  ::commandMessageHandler}})
{}

bool babel::server::CommandHandler::handleCommand(
	babel::common::ACommand command, uint32_t userId)
{
	if (_commandHandlers.find(command.getCommandId())
	    != _commandHandlers.end())
		return (this->*_commandHandlers[command.getCommandId()])
			(command, userId);
	throw common::CommandException(command.getCommandId(),
				       "Command not supported.");
}

void babel::server::CommandHandler::sendToAllClients(
	babel::common::DataPacket packet)
{
	for (std::pair<babel::server::BoostTcpSocket,
			uint32_t> &sock : _sockets) {
		if (sock.second > 0)
			sock.first.send(packet);
	}
}

bool babel::server::CommandHandler::commandLoginHandler(
	babel::common::ACommand command, uint32_t userId)
{
	common::CommandLogin &cmd = (common::CommandLogin &) command;
	for (common::User &user : _clients) {
		if (!cmd.getUsername().compare(user.getLogin())) {
			if (!cmd.getPassword().compare(user.getPassword()))
				throw common::CommandException(
					common::CMD_LOGIN, "Correct password.");
			return connectUser(user, userId);
		}
	}
	return createUser(cmd, userId);
}

bool babel::server::CommandHandler::createUser(
	babel::common::CommandLogin &cmd, uint32_t userId)
{

	common::User user(userId, cmd.getUsername(), cmd.getPassword());
	user.setConnected(true);
	_clients.push_back(user);
	sendToAllClients(common::CommandUser(
		{std::to_string(user.getId()),
		 cmd.getUsername(), "1"}).serialize());
	sendOk(userId, common::CMD_LOGIN, "Account created.");
	return connectUser(user, userId);
}

bool babel::server::CommandHandler::connectUser(
	common::User &user, uint32_t userId)
{
	auto &sock = getSocket(userId);
	sock.second = user.getId();
	user.setConnected(true);
	for (uint32_t contactId: user.getContacts())
		sock.first.send(common::CommandContact(
			{std::to_string(contactId), "1"}).serialize());
	sendToAllClients(common::CommandUserState(
		{std::to_string(user.getId()), "1"}).serialize());
	sock.first.send(common::CommandLoginOk({std::to_string(user.getId()),
						user.getLogin()}).serialize());
	return sendOk(sock.second, common::CMD_LOGIN, "Login ok.");
}

bool babel::server::CommandHandler::commandLogoutHandler(
	babel::common::ACommand command, uint32_t userId)
{
	if (!isConnected(userId))
		throw common::CommandException(
			common::CMD_LOGOUT, "You need to login first.");
	disconnectUser(userId);
	return sendOk(userId, common::CMD_LOGOUT, "Logout ok.");
	(void)command;
}

void babel::server::CommandHandler::disconnectUser(uint32_t userId)
{
	common::User &user = getUser(userId);
	user.setConnected(false);
	sendToAllClients(common::CommandUserState(
		{std::to_string(userId), "0"}).serialize());
}

bool babel::server::CommandHandler::commandDeleteHandler(
	babel::common::ACommand command, uint32_t userId)
{
	if (!isConnected(userId))
		throw common::CommandException(
			common::CMD_DELETE, "You need to login first.");
	auto position =	std::find(_clients.begin(), _clients.end(), userId);
	if (position != _clients.end())
		_clients.erase(position);
	sendToAllClients(common::CommandUserState(
		{std::to_string(userId), "0"}).serialize());
	return sendOk(userId, common::CMD_DELETE, "Delete ok.");
	(void)command;
}

bool babel::server::CommandHandler::commandCallHandler(
	babel::common::ACommand command, uint32_t userId)
{
	common::CommandCall &cmd = (common::CommandCall &) command;
	if (!isConnected(userId))
		throw common::CommandException(
			common::CMD_CALL, "You need to login first.");
	if (!isConnected(cmd.getUserId()))
		throw common::CommandException(
			common::CMD_CALL, "User is not connected.");
	getSocket(cmd.getUserId()).first.send(common::CommandCall(
		{std::to_string(userId), cmd.getIp(),
		 std::to_string(cmd.getPort())}).serialize());
	return sendOk(userId, common::CMD_CALL, "Call ok.");
}

bool babel::server::CommandHandler::commandCallAnswerHandler(
	babel::common::ACommand command, uint32_t userId)
{
	common::CommandCallAnswer &cmd = (common::CommandCallAnswer &) command;
	if (!isConnected(userId))
		throw common::CommandException(
			common::CMD_CALL_ANSWER, "You need to login first.");
	if (!isConnected(cmd.getUserId()))
		throw common::CommandException(
			common::CMD_CALL, "User is not connected.");
	getSocket(cmd.getUserId()).first.send(common::CommandCallAnswer(
		{std::to_string(userId), cmd.getIp(),
		 std::to_string(cmd.getPort())}).serialize());
	return sendOk(userId, common::CMD_CALL_ANSWER, "Call answer ok.");
}

bool babel::server::CommandHandler::commandCallEndHandler(
	babel::common::ACommand command, uint32_t userId)
{
	common::CommandCallEnd &cmd = (common::CommandCallEnd &) command;
	if (!isConnected(userId))
		throw common::CommandException(
			common::CMD_CALL_END, "You need to login first.");
	if (!isConnected(cmd.getUserId()))
		throw common::CommandException(
			common::CMD_CALL, "User is not connected.");
	getSocket(cmd.getUserId()).first.send(common::CommandCall(
		{std::to_string(userId)}).serialize());
	return sendOk(userId, common::CMD_CALL_END, "Call end ok.");
}

bool babel::server::CommandHandler::commandContactHandler(
	babel::common::ACommand command, uint32_t userId)
{
	common::CommandContact &cmd = (common::CommandContact &) command;
	if (!isConnected(userId))
		throw common::CommandException(
			common::CMD_CONTACT, "You need to login first.");
	common::User &user = getUser(userId);
	if ((cmd.isContact() && !user.addContact(cmd.getUserId())) ||
	    (!cmd.isContact() && !user.removeContact(cmd.getUserId())))
		throw common::CommandException(
			common::CMD_CONTACT,
			cmd.isContact() ? "User is already a contact."
					: "User isn't a contact.");
	getSocket(cmd.getUserId()).first.send(common::CommandContact(
		{std::to_string(cmd.getUserId()),
		 std::to_string(cmd.isContact())}).serialize());
	return sendOk(userId, common::CMD_CONTACT, "Contact ok.");
}

bool babel::server::CommandHandler::commandMessageHandler(
	babel::common::ACommand command, uint32_t userId)
{
	common::CommandMessage &cmd = (common::CommandMessage &) command;
	if (!isConnected(userId))
		throw common::CommandException(
			common::CMD_MESSAGE, "You need to login first.");
	if (!isConnected(cmd.getUserId()))
		throw common::CommandException(
			common::CMD_CALL, "User is not connected.");
	getSocket(cmd.getUserId()).first.send(common::CommandContact(
		{std::to_string(userId), cmd.getMessage()}).serialize());
	return sendOk(userId, common::CMD_MESSAGE, "Message ok.");
}

std::pair<babel::server::BoostTcpSocket, uint32_t> &
babel::server::CommandHandler::getSocket(uint32_t userId)
{
	for (auto &sock : _sockets) {
		if (sock.second == userId)
			return sock;
	}
	return _sockets[0];
}

babel::common::User &
babel::server::CommandHandler::getUser(uint32_t userId)
{
	for (common::User &user : _clients) {
		if (user.getId() == userId)
			return user;
	}
	return _clients[0];
}

bool babel::server::CommandHandler::isConnected(uint32_t userId)
{
	for (common::User &user : _clients) {
		if (user.getId() == userId)
			return user.isConnected();
	}
	return false;
}

uint32_t babel::server::CommandHandler::getNextId()
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

bool babel::server::CommandHandler::sendOk(
	uint32_t userId, babel::common::CommandName cmd, const std::string &msg)
{
	auto &sock = getSocket(userId);
	sock.first.send(common::CommandOk(
		{std::to_string(cmd), msg}).serialize());
	return true;
}
