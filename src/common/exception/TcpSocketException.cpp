/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** 	TcpSocketException class
*/

#include "TcpSocketException.hpp"
#include <utility>

babel::common::TcpSocketException::TcpSocketException(
	babel::common::ConnectionInfo connectionInfo,
	const std::string &message) :
	Exception("Tcp Socket Error", message), _connectionInfo(
	std::move(connectionInfo))
{
}

babel::common::ConnectionInfo
babel::common::TcpSocketException::getConnectionInfo()
{
	return babel::common::ConnectionInfo();
}
