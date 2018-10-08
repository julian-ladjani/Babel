/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** 	TcpServer class
*/

#include "TcpServer.hpp"

babel::server::TcpServer::TcpServer(boost::asio::io_context &ioContext,
				    uint16_t port) :
	_ioContext(ioContext),
	_tcpAcceptor(_ioContext, boost::asio::ip::tcp::endpoint(
		boost::asio::ip::tcp::v4(), port))
{
	std::cout << "Server created on port "
		  << _tcpAcceptor.local_endpoint().port() << std::endl;
	startAccept();
}

std::vector<babel::server::BoostTcpSocket::pointer> &
babel::server::TcpServer::getSockets()
{
	return _sockets;
}

bool babel::server::TcpServer::startAccept()
{
	babel::common::ConnectionInfo connectionInfo;
	BoostTcpSocket::pointer newConnection =
		BoostTcpSocket::create(connectionInfo, _ioContext);
	_tcpAcceptor.async_accept(
		newConnection->getSocket(),
		boost::bind(&TcpServer::handleAccept, this, newConnection,
			    boost::asio::placeholders::error));
	return false;
}

void
babel::server::TcpServer::handleAccept(
	BoostTcpSocket::pointer newSocket,
	const boost::system::error_code &ec)
{
	if (ec)
		return;
	newSocket->setId(_minId);
	_minId--;
	newSocket->mustBeConnected();
	_sockets.push_back(newSocket);
	startAccept();
}

void babel::server::TcpServer::closeSocket(
	babel::common::ConnectionInfo connectionInfo)
{
	for (uint32_t i = 0; i < _sockets.size(); ++i) {
		if (*_sockets[i] == connectionInfo) {
			sendDisconnectionMessage(_sockets[i]->getId());
			_sockets[i]->disconnect();
			_sockets[i]->setId(0);
		}
	}
}

void babel::server::TcpServer::sendDisconnectionMessage(int32_t socketId)
{
	common::DataPacket packet = common::CommandUserState(
		{std::to_string(socketId), "0"}).serialize();
	for (auto sock : _sockets) {
		if (sock->getId() > 0)
			sock->send(packet);
	}
}
