/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** ConnectionInfo.cpp
*/

#include "ConnectionInfo.hpp"

babel::common::ConnectionInfo::ConnectionInfo(
	unsigned short port, std::array<unsigned char, 4> ip) :
	_port(port), _ip(ip)
{
}

unsigned short babel::common::ConnectionInfo::getPort() const
{
	return _port;
}

void babel::common::ConnectionInfo::setPort(unsigned short port)
{
	_port = port;
}

const std::array<unsigned char, 4> &
babel::common::ConnectionInfo::getIp() const
{
	return _ip;
}

void
babel::common::ConnectionInfo::setIp(const std::array<unsigned char, 4> &ip)
{
	_ip = ip;
}
