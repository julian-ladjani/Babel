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

void babel::common::ATcpSocket::addPacketToQueue(std::string strPacket)
{
	if (strPacket.empty())
		return;
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
	std::vector<std::string> vecPackets;
	boost::split(vecPackets, packets, boost::is_any_of(PACKET_SEPARATOR));
	if (!notFinishedPacket.empty())
		*vecPackets.begin() += notFinishedPacket;
	if (packets[packets.size() - 2] != PACKET_SEPARATOR[0]) {
		notFinishedPacket = *vecPackets.end();
		vecPackets.erase(vecPackets.end());
	}
	addPacketToQueue(vecPackets);
	return notFinishedPacket;
}
