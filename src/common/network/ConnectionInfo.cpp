/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** ConnectionInfo.cpp
*/

#include "ConnectionInfo.hpp"

babel::common::ConnectionInfo::ConnectionInfo(
	uint16_t port, std::string ip) :
	_port(port), _ip(ip)
{
}

uint16_t babel::common::ConnectionInfo::getPort() const
{
	return _port;
}

void babel::common::ConnectionInfo::setPort(uint16_t port)
{
	_port = port;
}

const std::string &babel::common::ConnectionInfo::getIp() const
{
	return _ip;
}

void babel::common::ConnectionInfo::setIp(const std::string &Ip)
{
	ConnectionInfo::_ip = Ip;
}

bool babel::common::ConnectionInfo::operator==(
	const babel::common::ConnectionInfo &connectionInfo) const
{
	return connectionInfo.getPort() == this->getPort()
	       && connectionInfo.getIp() == this->getIp();
}
