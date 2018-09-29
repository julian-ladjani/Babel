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
