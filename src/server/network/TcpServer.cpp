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

std::vector<std::pair<babel::server::BoostTcpSocket &, int32_t>> &
babel::server::TcpServer::getSockets()
{
	return _sockets;
}

bool babel::server::TcpServer::startAccept()
{
	try {
		babel::common::ConnectionInfo connectionInfo;
		_tcpSockets.push_back(
			std::make_unique<BoostTcpSocket>(connectionInfo,
							 _ioContext));
		_tcpAcceptor.async_accept(
			_tcpSockets[_tcpSockets.size() - 1]->getSocket(),
			boost::bind(&TcpServer::handleAccept, this, _1));
	} catch (babel::common::TcpSocketException &e) {
		closeSocket(e.getConnectionInfo());
	}
	return false;
}

void
babel::server::TcpServer::handleAccept(const boost::system::error_code &ec)
{
	std::cout << "testaccept" << std::endl;
	if (ec)
		throw TcpServerException(ec.message());
	auto idSocketPair = std::pair<babel::server::BoostTcpSocket &, int32_t>
		(*_tcpSockets[_tcpSockets.size() - 1], _minId);
	_minId--;
	idSocketPair.first.mustBeConnected();
	_sockets.push_back(idSocketPair);
	startAccept();
}

void babel::server::TcpServer::closeSocket(
	babel::common::ConnectionInfo connectionInfo)
{
	for (uint32_t i = 0; i < _sockets.size(); ++i) {
		if (_sockets[i].first == connectionInfo) {
			sendDisconnectionMessage(_sockets[i].second);
			_sockets[i].second = 0;
		}
	}
	for (uint32_t i = 0; i < _tcpSockets.size(); ++i) {
		if (*(_tcpSockets[i]) == connectionInfo) {
			_tcpSockets[i]->disconnect();
			_tcpSockets.erase(_tcpSockets.begin() + i);
		}
	}
}

void babel::server::TcpServer::sendDisconnectionMessage(int32_t socketId)
{
	common::DataPacket packet = common::CommandUserState(
		{std::to_string(socketId), "0"}).serialize();
	for (auto sock : _sockets) {
		if (sock.second > 0)
			sock.first.send(packet);
	}
}
