/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** 	QtTcpSocket class
*/

#include "QtTcpSocket.hpp"

babel::client::QtTcpSocket::QtTcpSocket(
	babel::common::ConnectionInfo &connectionInfo) : ATcpSocket(
	connectionInfo)
{
	QObject::connect(&_socket, &QTcpSocket::connected,
			this, &QtTcpSocket::onSuccessConnection);
}

void babel::client::QtTcpSocket::onSuccessConnection()
{
	_isConnect = true;
	emit connectionSuccess();
}

bool babel::client::QtTcpSocket::connect()
{
	if (_isConnect)
		return false;
	_socket.connectToHost(QString::fromStdString(_connectionInfo.getIp()),
		(quint16) _connectionInfo.getPort());
	startRead();
	return true;
}

bool babel::client::QtTcpSocket::disconnect()
{
	if (!_isConnect)
		return false;
	_socket.disconnectFromHost();
	_isConnect = false;
	return true;
}

bool babel::client::QtTcpSocket::send(babel::common::DataPacket packet)
{
	if (!_isConnect)
		return false;
	std::string serializedPacket = packet.serialize() + PACKET_SEPARATOR;
	_socket.write(serializedPacket.c_str());
	return false;
}

const babel::common::DataPacket babel::client::QtTcpSocket::receive()
{
	std::cout << getPacketFromQueue().serialize() << std::endl;
	return getPacketFromQueue();

}

void babel::client::QtTcpSocket::startRead()
{
	QDialog::connect(&_socket, &QIODevice::readyRead,
		this, &QtTcpSocket::handleRead);
}

void babel::client::QtTcpSocket::handleRead()
{
	std::string stdTmpBuffer;
	stdTmpBuffer = _socket.readAll().toStdString();
	_uncompletePacket = addPacketsToQueue(stdTmpBuffer,
		_uncompletePacket);
	std::cout << "Uncomplete : " <<_uncompletePacket << std::endl;
}
