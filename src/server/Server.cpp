/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Server.cpp
*/

#include "Server.hpp"

babel::server::Server::Server(uint16_t port) :
	_running(false), _cmdFactory(), _clients(), _tcpServer(port),
	_commandHandler(_clients, _tcpServer.getSockets()),
	_sockets(_tcpServer.getSockets())
{
}

int babel::server::Server::start()
{
	_running = true;
	while (_running) {
		for (auto &sock : _sockets)
			handleClient(sock.first, sock.second);
	}
	return 0;
}

void babel::server::Server::handleClient(babel::server::BoostTcpSocket &sock,
					 int32_t userId)
{
	try {
		common::DataPacket packet = sock.receive();
		if (packet.getCommandId() != common::CMD_UNDEFINED) {
			std::unique_ptr<common::ACommand> command
				= _cmdFactory.deserialize(packet);
			_commandHandler.handleCommand(*command, userId);
		}

	} catch (babel::common::CommandException &e) {
		sock.send(common::CommandError(
			{std::to_string(e.getCommandId()),
			 e.what()}).serialize());
	}

}

void babel::server::Server::addClient(common::User user)
{
	if (std::find(_clients.begin(), _clients.end(), user) ==
	    _clients.end())
		_clients.push_back(user);
}

void babel::server::Server::removeClient(common::User user)
{
	auto position =	std::find(_clients.begin(), _clients.end(), user);
	if (position != _clients.end())
		_clients.erase(position);
}