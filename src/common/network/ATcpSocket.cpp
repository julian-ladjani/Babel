#include "ConnectionInfo.hpp"
#include "ATcpSocket.hpp"

/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** 	ATcpSocket source file
*/

babel::common::ATcpSocket::ATcpSocket(
	babel::common::ConnectionInfo &_connectionInfo)
	: _connectionInfo(_connectionInfo), _isConnect(false)
{

}

const babel::common::ConnectionInfo
babel::common::ATcpSocket::getConnectionInfo() const
{
	return babel::common::ConnectionInfo();
}

const babel::common::DataPacket
babel::common::ATcpSocket::getPacketFromQueue()
{
	if (_receiveQueue.empty())
		return babel::common::DataPacket();
	babel::common::DataPacket packet = _receiveQueue.at(0);
	_receiveQueue.erase(_receiveQueue.begin());
	return (packet);
}

bool babel::common::ATcpSocket::isConnect() const
{
	return _isConnect;
}
