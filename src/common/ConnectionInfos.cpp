//
// EPITECH PROJECT, 2018
// CPP_babel_2018 - ConnectionInfos.cpp
// File description:
// Created by Gregory EPLE
//

#include "ConnectionInfos.hpp"

babel::common::ConnectionInfos::ConnectionInfos(
	unsigned short port, std::array<unsigned char, 4> ip) :
	_port(port), _ip(ip)
{
}

unsigned short babel::common::ConnectionInfos::getPort() const
{
	return _port;
}

void babel::common::ConnectionInfos::setPort(unsigned short port)
{
	_port = port;
}

const std::array<unsigned char, 4> &
babel::common::ConnectionInfos::getIp() const
{
	return _ip;
}

void
babel::common::ConnectionInfos::setIp(const std::array<unsigned char, 4> &ip)
{
	_ip = ip;
}
