/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Server.cpp
*/

#include "Server.hpp"

babel::server::Server::Server(uint16_t port) :
	_running(false), _cmdFactory(), _clients(),
	_tcpServer(_ioContext, port),
	_sockets(_tcpServer.getSockets()), _sqliteServer(),
	_commandHandler(_clients, _sockets, _sqliteServer)
{
	_sqliteServer.getUsers(_clients);
	for (babel::common::User &client : _clients) {
		std::vector<uint32_t> contacts;
		_sqliteServer.getUserContacts(client.getId(), contacts);
		client.setContacts(contacts);
	}
}

int babel::server::Server::start()
{
	_running = true;
	boost::thread TcpServerThread(
		boost::bind(&boost::asio::io_context::run, &_ioContext));
	while (_running) {
		printf("\b");
		for (auto &sock : _sockets) {
			if (sock.first.isConnect())
				handleClient(sock.first, sock.second);
			else if (sock.second != 0)
				_tcpServer.closeSocket(
					sock.first.getConnectionInfo());
		}
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
			_commandHandler.handleCommand(command, userId);
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
	auto position = std::find(_clients.begin(), _clients.end(), user);
	if (position != _clients.end())
		_clients.erase(position);
}