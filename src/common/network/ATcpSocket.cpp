/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** 	ATcpSocket source file
*/

#include "ATcpSocket.hpp"

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

void babel::common::ATcpSocket::addPacketToQueue(std::string strPacket)
{
	if (strPacket.empty())
		return;
	auto dataPacket = DataPacket::deserialize(strPacket);
	if (dataPacket.getCommandId() != CommandName::CMD_UNDEFINED)
		_receiveQueue.push_back(DataPacket::deserialize(strPacket));
}

void babel::common::ATcpSocket::addPacketToQueue(
	std::vector<std::string> &vecPackets)
{
	if (vecPackets.empty())
		return;
	for (auto &vecPacket : vecPackets)
		addPacketToQueue(vecPacket);
}

std::string
babel::common::ATcpSocket::addPacketsToQueue(std::string &packets,
					     std::string notFinishedPacket)
{
	if (packets.empty())
		return (notFinishedPacket);
	std::vector<std::string> vecPackets;
	boost::split(vecPackets, packets, boost::is_any_of(PACKET_SEPARATOR));
	if (!vecPackets.empty() && vecPackets.back() == std::string("\0"))
		vecPackets.pop_back();
	if (!notFinishedPacket.empty()) {
		(*vecPackets.begin()).append(notFinishedPacket);
		notFinishedPacket.clear();
	}
	if (packets.back() != PACKET_SEPARATOR[0]) {
		std::cout << "test1" << std::endl;
		notFinishedPacket = vecPackets.back();
		vecPackets.pop_back();
	}
	std::cout << "test2" << std::endl;
	addPacketToQueue(vecPackets);
	std::cout << "test3" << std::endl;
	return notFinishedPacket;
}

bool babel::common::ATcpSocket::operator==(
	const babel::common::ATcpSocket &socket) const
{
	return getConnectionInfo() == socket.getConnectionInfo();
}

bool babel::common::ATcpSocket::operator==(
	const babel::common::ConnectionInfo &connectionInfo) const
{
	return getConnectionInfo() == connectionInfo;
}
