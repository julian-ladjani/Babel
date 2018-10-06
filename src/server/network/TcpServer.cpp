/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** 	TcpServer class
*/

#include "TcpServer.hpp"

babel::server::TcpServer::TcpServer(uint16_t port) :
	_tcpAcceptor(_ioContext, boost::asio::ip::tcp::endpoint(
		boost::asio::ip::tcp::v4(), port))
{
	_ioContext.run();
}

std::vector<std::pair<babel::server::BoostTcpSocket &, int32_t>> &
babel::server::TcpServer::getSockets()
{
	return _sockets;
}

bool babel::server::TcpServer::startAccept()
{
	babel::common::ConnectionInfo connectionInfo;
	_tcpSockets.push_back(
		std::make_unique<BoostTcpSocket>(connectionInfo, _ioContext));
	_tcpAcceptor.async_accept(
		_tcpSockets[_tcpSockets.size() - 1]->getSocket(),
		boost::bind(&TcpServer::handleAccept, this, _1));
	return false;
}

void
babel::server::TcpServer::handleAccept(const boost::system::error_code &ec)
{
	if (ec)
		return;
	auto idSocketPair = std::pair<babel::server::BoostTcpSocket &, int32_t>
		(*_tcpSockets[_tcpSockets.size() - 1], _minId);
	_minId--;
	_sockets.push_back(idSocketPair);
	startAccept();
}
