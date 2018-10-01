/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** 	BoostTcpSocket class
*/

#include "BoostTcpSocket.hpp"

babel::common::BoostTcpSocket::BoostTcpSocket(
	babel::common::ConnectionInfo &connectionInfo) : ATcpSocket(
	connectionInfo), _socket(_ioService)
{
}

bool babel::common::BoostTcpSocket::connect()
{
	if (_isConnect)
		return false;
	boost::asio::ip::tcp::endpoint
		endpoint(boost::asio::ip::address::from_string
		(_connectionInfo.getIp()), _connectionInfo.getPort());
	_socket.connect(endpoint);
	_isConnect = true;
	startRead();
}

const babel::common::DataPacket &babel::common::BoostTcpSocket::receive()
{
	return getPacketFromQueue();
}

void
babel::common::BoostTcpSocket::handleRead(const boost::system::error_code &ec)
{
	std::cout << "Received: " << std::endl;
	if (!_isConnect)
		return;
	if (ec) {
		disconnect();
		return;
	}
	std::string line;
	std::istream is(&_input_buffer);
	std::getline(is, line);
	if (!line.empty())
	{
		std::cout << "Received: " << line << "\n";
	}
	startRead();
}

bool babel::common::BoostTcpSocket::disconnect()
{
	if (!_isConnect)
		return false;
	_socket.close();
	_isConnect = false;
	return true;
}

void babel::common::BoostTcpSocket::startRead()
{
	if (!_isConnect)
		return;
	std::cout << "test" << std::endl;
	boost::asio::async_read_until(_socket,
		_input_buffer, '\n',
		boost::bind(&BoostTcpSocket::handleRead, this, _1));
}

void babel::common::BoostTcpSocket::handleWrite(
	const boost::system::error_code &ec)
{
	if (!_isConnect)
		return;
	if (ec)
		disconnect();
}

bool babel::common::BoostTcpSocket::send(babel::common::DataPacket packet)
{
	if (!_isConnect)
		return false;
	std::string serializedPacket = packet.serialize() + PACKET_SEPARATOR;
	boost::asio::async_write(_socket, boost::asio::buffer(
		serializedPacket.c_str(), serializedPacket.size()),
		boost::bind(&BoostTcpSocket::handleWrite, this, _1));
	return (true);
}
